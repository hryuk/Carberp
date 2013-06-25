#include "stdafx.h"

#include <windows.h>
#include <aclapi.h>
#include <shlwapi.h>

#include "fs.h"
#include "time.h"
#include "str.h"
#include "crypt.h"
#include "mem.h"

#define TEMPFILE_DEFAULT_PREFIX L"tmp"

void Fs::init(void)
{

}

void Fs::uninit(void)
{

}

bool Fs::_saveToFile(const LPWSTR fileName, const void *data, DWORD dataSize)
{
  bool r = false;
  HANDLE file = CreateFileW(fileName, GENERIC_WRITE, FILE_SHARE_READ, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
  if(file != INVALID_HANDLE_VALUE)
  {
    DWORD size;
    if(data == NULL || dataSize == 0 || WriteFile(file, data, dataSize, &size, NULL) != FALSE)r = true;
    CloseHandle(file);
    if(r != true)_removeFile(fileName);
  }
  return r;
}

DWORD Fs::_readFileToBuffer(const LPWSTR fileName, void *buffer, DWORD bufferSize)
{
  DWORD retVal = (DWORD)-1;
  HANDLE file = CreateFileW(fileName, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, 0, NULL);
  
  if(file != INVALID_HANDLE_VALUE)
  {
    if(ReadFile(file, buffer, bufferSize, &bufferSize, NULL) != FALSE)retVal = bufferSize;
    CloseHandle(file);
  }
  return retVal;
}

bool Fs::_fileToMem(LPWSTR fileName, MEMFILE *mem, DWORD flags)
{
  DWORD access = GENERIC_READ;
  #if(FS_ALLOW_FILEMAPPING > 0)
  if(flags & FTOMF_WRITE_ACCESS)access |= GENERIC_WRITE;
  #endif

  mem->file = CreateFileW(fileName, access,
                                         FILE_SHARE_READ | (flags & FTOMF_SHARE_WRITE  ? (FILE_SHARE_WRITE | FILE_SHARE_DELETE) : 0),
                                         NULL,
                                         OPEN_EXISTING,
                                         0,
                                         NULL);
  
  if(mem->file != INVALID_HANDLE_VALUE)
  {
    LARGE_INTEGER liSize;
    if(GetFileSizeEx(mem->file, &liSize) && liSize.HighPart == 0)
    {
      mem->size = liSize.LowPart;
      if(mem->size == 0)
      {
#       if(FS_ALLOW_FILEMAPPING > 0)      
        mem->map = NULL;
#       endif
        mem->data = NULL;
        return true;
      }
      
#     if(FS_ALLOW_FILEMAPPING > 0)      
      if((mem->map = CWA(kernel32, CreateFileMappingW)(mem->file, NULL, (flags & FTOMF_WRITE_ACCESS ? PAGE_READWRITE : PAGE_READONLY), 0, 0, NULL)) != NULL)
      {
        if((mem->data = (LPBYTE)CWA(kernel32, MapViewOfFile)(mem->map, (flags & FTOMF_WRITE_ACCESS ? FILE_MAP_WRITE : FILE_MAP_READ), 0, 0, 0)) != NULL)return true;
        CWA(kernel32, CloseHandle)(mem->map);
      }
#     else
      if((mem->data = (LPBYTE)VirtualAlloc(NULL, mem->size, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE)) != NULL)
      {
        DWORD readed;
        if(ReadFile(mem->file, mem->data, mem->size, &readed, NULL) != FALSE && readed == mem->size)
        {
          //FIXME: Менять протекцию на ReadOnly?
          return true;
        }
        VirtualFree(mem->data, 0, MEM_RELEASE);
      }
#     endif
    }
    CloseHandle(mem->file);
  }
  return false;
}

void Fs::_closeMemFile(MEMFILE *mem)
{
#if(FS_ALLOW_FILEMAPPING > 0)
  if(mem->data)CWA(kernel32, UnmapViewOfFile)(mem->data);
  if(mem->map)CWA(kernel32, CloseHandle)(mem->map);
#else
  if(mem->data)VirtualFree(mem->data, 0, MEM_RELEASE);
#endif
  if(mem->file)CloseHandle(mem->file);
}

bool Fs::_setFilePointer(HANDLE file, DWORD64 distanceToMove, DWORD moveMethod)
{
  LARGE_INTEGER li;
  li.QuadPart = (LONGLONG)distanceToMove;
  return SetFilePointerEx(file, li, NULL, moveMethod) ? true : false;
}

DWORD64 Fs::_getFilePointer(HANDLE file)
{
  LARGE_INTEGER li, rl;
#if defined _WIN64
  li.QuadPart = 0;
#else
  li.HighPart = li.LowPart = 0;
#endif
  if(SetFilePointerEx(file, li, &rl, FILE_CURRENT))return rl.QuadPart;
  return (DWORD64)(-1);
}

DWORD64 Fs::_getFileSize(HANDLE file)
{
  LARGE_INTEGER li;
  if(GetFileSizeEx(file, &li))return li.QuadPart;
  return (DWORD64)(-1);
}

DWORD64 Fs::_getFileSizeEx(LPWSTR file)
{
  DWORD64 size = (DWORD64)(-1);
  HANDLE handle = CreateFileW(file, GENERIC_READ, FILE_SHARE_DELETE | FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, NULL);

  if(handle != INVALID_HANDLE_VALUE)
  {
    size = _getFileSize(handle);
    CloseHandle(handle);
  }

  return size;
}

bool Fs::_removeFile(LPWSTR file)
{
  SetFileAttributesW(file, FILE_ATTRIBUTE_NORMAL);
  return DeleteFileW(file) ? true : false;
}

bool Fs::_createTempFile(const LPWSTR prefix, LPWSTR buffer)
{
  WCHAR path[MAX_PATH];
  DWORD i = GetTempPathW(MAX_PATH - 14/*требование GetTempFileName*/, path);
  
  if(i > 0 && i <= MAX_PATH - 14)
  {
    if(GetTempFileNameW(path, prefix == NULL ? TEMPFILE_DEFAULT_PREFIX : prefix, 0, buffer) > 0)return true;
  }
  
  return false;
}

bool Fs::_createTempFileEx(const LPWSTR prefix, const LPWSTR extension, LPWSTR buffer)
{
  WCHAR path[MAX_PATH];
  DWORD i = GetTempPathW(MAX_PATH - 14/*требование GetTempFileName*/, path);

  if(i > 0 && i <= MAX_PATH - 14)
  {
    WCHAR name[MAX_PATH];
    LPWSTR realPrefix = prefix == NULL ? TEMPFILE_DEFAULT_PREFIX : prefix;
    
    for(DWORD i = 0; i < 100; i++)
    {
      if(Str::_sprintfW(name, MAX_PATH, L"%s%08x.%s", realPrefix, Crypt::mtRand(), extension) == -1)break;
      if(_pathCombine(buffer, path, name) && _saveToFile(buffer, NULL, 0))return true;
    }
  }

  return false;
}

bool Fs::_createTempDirectory(const LPWSTR prefix, LPWSTR buffer)
{
  WCHAR path[MAX_PATH];
  DWORD i = GetTempPathW(MAX_PATH - 14/*требование GetTempFileName*/, path);

  if(i > 0 && i <= MAX_PATH - 14)
  {
    WCHAR name[MAX_PATH];
    LPWSTR realPrefix = prefix == NULL ? TEMPFILE_DEFAULT_PREFIX : prefix;

    for(DWORD i = 0; i < 100; i++)
    {
      if(Str::_sprintfW(name, MAX_PATH, L"%s%08x", realPrefix, Crypt::mtRand()) == -1)break;
      if(_pathCombine(buffer, path, name) && CreateDirectoryW(buffer, NULL) != FALSE)return true;
    }
  }

  return false;
}

bool Fs::_isDotsName(LPWSTR name)
{
  return (name && *name == '.' && (name[1] == 0 || (name[1] == '.' && name[2] == 0))) ? true : false;
}

bool Fs::_writeSizeAndData(HANDLE file, void *data, DWORD dataSize)
{
  DWORD64 curOffset = _getFilePointer(file);
  DWORD writed;

  if(WriteFile(file, &dataSize, sizeof(DWORD), &writed, NULL) && writed == sizeof(DWORD))
  {
    if(dataSize == 0 || (WriteFile(file, data, dataSize, &writed, NULL) && writed == dataSize))return true;
  }

  _setFilePointer(file, curOffset, FILE_BEGIN);
  return false;
}

bool Fs::_ReadFile(HANDLE hFile, void *pBuffer, DWORD dwNumberOfBytesToRead, LPDWORD pdwNumberOfBytesRead, HANDLE hOverlappedEvent)
{
  bool bRetVal = false;
  OVERLAPPED ov;
  
  Mem::_zero(&ov, sizeof(OVERLAPPED));
  ov.hEvent = hOverlappedEvent; 

  if(ReadFile(hFile, pBuffer, dwNumberOfBytesToRead, pdwNumberOfBytesRead, &ov))bRetVal = true;
  else
  {
    DWORD le = GetLastError();
    if(le == ERROR_HANDLE_EOF)
    {
      *pdwNumberOfBytesRead = 0;
      bRetVal = true;
    }
    else if(le == ERROR_IO_PENDING)
    {
      if(GetOverlappedResult(hFile, &ov, pdwNumberOfBytesRead, TRUE))bRetVal = true;
      else if(GetLastError() == ERROR_HANDLE_EOF)
      {
        *pdwNumberOfBytesRead = 0;
        bRetVal = true;
      }
    }
  }

  return bRetVal;
}

bool Fs::_WriteFile(HANDLE hFile, void *pBuffer, DWORD dwNumberOfBytesToWrite, LPDWORD pdwNumberOfBytesWritten, HANDLE hOverlappedEvent)
{
  bool bRetVal = false;
  OVERLAPPED ov;

  Mem::_zero(&ov, sizeof(OVERLAPPED));
  ov.hEvent = hOverlappedEvent; 

  if(WriteFile(hFile, pBuffer, dwNumberOfBytesToWrite, pdwNumberOfBytesWritten, &ov))bRetVal = true;
  else if(GetLastError() == ERROR_IO_PENDING)
  {
    if(GetOverlappedResult(hFile, &ov, pdwNumberOfBytesWritten, TRUE))bRetVal = true;
  }

  return bRetVal;
}

bool Fs::_WriteFileFormatA(HANDLE hFile, LPSTR pstrFormat, ...)
{
  LPSTR pBuf = NULL;
  int iSize;
  bool r = false;
  
  va_list list;
  va_start(list, pstrFormat);
  iSize = Str::_vsprintfExA(&pBuf, pstrFormat, list);
  va_end(list);

  if(iSize != -1)
  {
    int iResult; 
    if(WriteFile(hFile, pBuf, iSize, (LPDWORD)&iResult, NULL) && iSize == iResult)r = true;
    Mem::free(pBuf);
  }

  return r;
}

bool Fs::_setFileTime(bool isDir, LPWSTR file, FILETIME *creationTime, FILETIME *lastAccessTime, FILETIME *lastWriteTime)
{
  bool r = false;
  HANDLE fileHandle = CreateFileW(file, FILE_WRITE_ATTRIBUTES, FILE_SHARE_READ, NULL, OPEN_EXISTING, isDir ? FILE_FLAG_BACKUP_SEMANTICS : 0, NULL);

  if(fileHandle != INVALID_HANDLE_VALUE)
  {
    r = (SetFileTime(fileHandle, creationTime, lastAccessTime, lastWriteTime) != FALSE);
    CloseHandle(fileHandle);
  }

  return r;
}

bool Fs::_setRandomFileTime(DWORD startTime, DWORD reservedSeconds, LPWSTR fileName, DWORD upLevel)
{
  register DWORD currentTime = Time::_getTime();

  //Проверяем ошибки времени.
  if(currentTime <= reservedSeconds || currentTime < startTime || (currentTime -= reservedSeconds) < startTime)return false;

  //Генерируем время.
  currentTime = startTime + Crypt::mtRandRange(0, currentTime - startTime);
  if(currentTime < startTime)return false; /*параноя*/

  //Выставляем время.
  {
    bool ok = true;
    WCHAR path[MAX_PATH];
    FILETIME fileTime;

    Time::_timeToFileTime(currentTime, &fileTime);
    Str::_CopyW(path, fileName, -1);

    do
    {
      if(!_setFileTime(PathIsDirectoryW(path) == TRUE, path, &fileTime, &fileTime, &fileTime))ok = false;
    }
    while(upLevel-- && PathRemoveFileSpecW(path) != FALSE);
    return ok;
  }
}

bool Fs::_getFileTime(bool isDir, LPWSTR file, FILETIME *creationTime, FILETIME *lastAccessTime, FILETIME *lastWriteTime)
{
  bool r = false;
  HANDLE fileHandle = CreateFileW(file, GENERIC_READ, FILE_SHARE_READ | FILE_SHARE_WRITE | FILE_SHARE_DELETE, NULL, OPEN_EXISTING, isDir ? FILE_FLAG_BACKUP_SEMANTICS : 0, NULL);

  if(fileHandle != INVALID_HANDLE_VALUE)
  {
    r = (GetFileTime(fileHandle, creationTime, lastAccessTime, lastWriteTime) != FALSE);
    CloseHandle(fileHandle);
  }

  return r;
}

bool Fs::_copyFileTime(bool sourceIsDir, LPWSTR sourceFile, bool destIsDir, LPWSTR destFile)
{
  FILETIME cTime, aTime, mTime;
  return (Fs::_getFileTime(sourceIsDir, sourceFile, &cTime, &aTime, &mTime) && Fs::_setFileTime(destIsDir, destFile, &cTime, &aTime, &mTime)) ? true : false;
}

bool Fs::_createDirectoryTree(LPWSTR path, LPSECURITY_ATTRIBUTES securityAttributes)
{
  bool r = false;
  LPWSTR p = PathSkipRootW(path);

  //Непонятно, может ли оно вернуть NULL. Помня фокус индусов с wsprintf, защитимся от этого.
  if(p == NULL)p = path; 

  for(;; p++)if(*p == '\\' || *p == '/' || *p == 0)
  {
    WCHAR cold = *p;
    *p = 0;

    DWORD attr = GetFileAttributesW(path);
    
    //Не существует.
    if(attr == INVALID_FILE_ATTRIBUTES)
    {
      if(CreateDirectoryW(path, securityAttributes) == FALSE)break;
    }
    //Это не директория.
    else if((attr & FILE_ATTRIBUTE_DIRECTORY) == 0)break;

    //Если добрались до конца, то успешный выход.
    if(cold == 0){r = true; break;}

    *p = cold;
  }
  return r;
}

bool Fs::_removeDirectoryTree(LPWSTR path)
{
  WCHAR curPath[MAX_PATH];
  WIN32_FIND_DATAW wfd;
  HANDLE handle;

  if(_pathCombine(curPath, path, L"*") && (handle = FindFirstFileW(curPath, &wfd)) != INVALID_HANDLE_VALUE)
  {
    do if(!_isDotsName(wfd.cFileName) && _pathCombine(curPath, path, wfd.cFileName))
    {
      //Подпапка.
      if(wfd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)_removeDirectoryTree(curPath);
      //Файл
      else _removeFile(curPath);
    }
    while(FindNextFileW(handle, &wfd) != FALSE);
    FindClose(handle);
  }

  SetFileAttributesW(path, FILE_ATTRIBUTE_NORMAL);
  return RemoveDirectoryW(path) == FALSE ? false : true;
}

void Fs::_findFiles(LPWSTR path, const LPWSTR *fileMasks, DWORD fileMasksCount, DWORD flags, FINDFILEPROC findFileProc, void *data, HANDLE stopEvent, DWORD subfolderDelay, DWORD foundedDelay)
{
  WCHAR curPath[MAX_PATH];
  WIN32_FIND_DATAW wfd;
  HANDLE handle;

  if(_pathCombine(curPath, path, L"*") && (handle = FindFirstFileW(curPath, &wfd)) != INVALID_HANDLE_VALUE)
  {
    do 
    {
      if(stopEvent != NULL && WaitForSingleObject(stopEvent, 0) != WAIT_TIMEOUT)break;
      
      if(!_isDotsName(wfd.cFileName))
      {
        //Сравнение.
        if((wfd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY && flags & FFFLAG_SEARCH_FOLDERS) ||
          (!(wfd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) && flags & FFFLAG_SEARCH_FILES))
        {
          for(DWORD i = 0; i < fileMasksCount; i++)if(PathMatchSpecW(wfd.cFileName, fileMasks[i]) != FALSE)
          {
            if(!findFileProc(path, &wfd, data))goto END;
            if(foundedDelay != 0) Sleep(foundedDelay);
            break;
          }
        }
      
        //Вход в подпапку.
        if(wfd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY && flags & FFFLAG_RECURSIVE)
        {
          if(_pathCombine(curPath, path, wfd.cFileName))
          {
            if(subfolderDelay != 0) Sleep(subfolderDelay);
            _findFiles(curPath, fileMasks, fileMasksCount, flags, findFileProc, data, stopEvent, subfolderDelay, foundedDelay);
          }
        }
      }
    }
    while(FindNextFileW(handle, &wfd) != FALSE);
END:
    FindClose(handle);
  }
}

bool Fs::_unquoteAndExpandPath(LPWSTR path, LPWSTR buffer)
{
  PathUnquoteSpacesW(path);
  DWORD size = ExpandEnvironmentStringsW(path, buffer, MAX_PATH);
  if(size > 0 && size <= MAX_PATH)return true;
  return false;
}

bool Fs::_pathCombine(LPWSTR dest, const LPWSTR dir, const LPWSTR file)
{
  LPWSTR p = (LPWSTR)file;
  if(p != NULL)while(*p == '\\' || *p == '/')p++;
  return PathCombineW(dest, dir, p) == NULL ? false : true;
}

void Fs::_normalizeSlashes(LPWSTR path)
{
  while(*path != 0)
  {
    if(*path == '/')*path = '\\';
    path++;
  }
}

void Fs::_replaceSlashes(LPWSTR string, WCHAR c)
{
  while(*string != 0)
  {
    if(*string == '/' || *string == '\\')*string = c;
    string++;
  }
}
