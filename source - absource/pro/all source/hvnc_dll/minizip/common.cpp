#include "common.h"

int ArchLastError=0;

void ArchSetLastError(int dwError)
{
    ArchLastError=dwError;
    return;
}

extern "C" int ArchGetLastError()
{
    return ArchLastError;
}

void *_alloc(ULONG size)
{
    void *r=MemAlloc(size);
    if (!r)
        ArchSetLastError(ARCH_NO_MEM);
    return r;
}

bool _feof(HANDLE hFile)
{
    DWORD lowSize=GetFileSize(hFile,0);
    DWORD lowPos=SetFilePointer(hFile,0,0,FILE_CURRENT);
    bool r=true;
    if (lowPos!=lowSize)
        r=false;
    return r;
}

uLong filetime(WCHAR *filename,tm_zip *tmzip, uLong *dt)
{
    int ret=0;
    {
        FILETIME ftLocal;
        HANDLE hFind;
        WIN32_FIND_DATAW ff32;

        hFind=FindFirstFileW(filename,&ff32);
        if (hFind != INVALID_HANDLE_VALUE)
        {
            FileTimeToLocalFileTime(&(ff32.ftLastWriteTime),&ftLocal);
            FileTimeToDosDateTime(&ftLocal,((LPWORD)dt)+1,((LPWORD)dt)+0);
            FindClose(hFind);
            ret=1;
        }
    }
    return ret;
}

void change_file_date(WCHAR *filename,uLong dosdate,tm_unz tmu_date)
{
    FILETIME ftm,ftLocal,ftCreate,ftLastAcc,ftLastWrite;

    HANDLE hFile=CreateFileW(filename,GENERIC_READ | GENERIC_WRITE,0,NULL,OPEN_EXISTING,0,NULL);
    GetFileTime(hFile,&ftCreate,&ftLastAcc,&ftLastWrite);
    DosDateTimeToFileTime((WORD)(dosdate>>16),(WORD)dosdate,&ftLocal);
    LocalFileTimeToFileTime(&ftLocal,&ftm);
    SetFileTime(hFile,&ftm,&ftLastAcc,&ftm);
    SysCloseHandle(hFile);
    return;
}

int getFileCrc(const WCHAR* filenameinzip,void*buf,unsigned long size_buf,unsigned long* result_crc)
{
    unsigned long calculate_crc=0;
    int err=ZIP_OK;
    HANDLE fin=CreateFileW(filenameinzip,GENERIC_READ,0,NULL,OPEN_EXISTING,0,NULL);
    unsigned long size_read=0;
    unsigned long total_read=0;
    if (!fin)
        err=ZIP_ERRNO;
    if (err == ZIP_OK)
    {
        do
        {
            err=ZIP_OK;
            ReadFile(fin,buf,size_buf,&size_read,0);

            if (size_read < size_buf)
            {
                if (!_feof(fin))
                    err=ZIP_ERRNO;
            }

            if (size_read>0)
                calculate_crc=crc32(calculate_crc,(byte*)buf,size_read);
            total_read += size_read;
        }
        while ((err == ZIP_OK) && (size_read>0));
    }

    if (fin)
        SysCloseHandle(fin);

    *result_crc=calculate_crc;
    return err;
}

int UnicodeToX(DWORD codePage,const LPWSTR source,int sourceSize,LPSTR dest,int destSize)
{
    if (sourceSize == -1)
        sourceSize=lstrlenW(source);
    int size=WideCharToMultiByte(codePage,WC_COMPOSITECHECK,source,sourceSize,dest,destSize,NULL,NULL);
    if (destSize > 0)
    {
        if (size >= destSize)
            size=0;
        dest[size]=0;
    }
    return size;
}

int xToUnicode(DWORD codePage,const LPSTR source,int sourceSize,LPWSTR dest,int destSize)
{
    if (sourceSize == -1)
        sourceSize=lstrlenA(source);
    int size=MultiByteToWideChar(codePage,0,source,sourceSize,dest,destSize);
    if (destSize > 0)
    {
        if (size >= destSize)
            size=0;
        dest[size]=0;
    }
    return size;
}

LPWSTR xToUnicodeEx(DWORD codePage,LPSTR source,int size)
{
    if (size == -1)
        size=lstrlenA(source);
    int destSize=xToUnicode(codePage,source,size,NULL,0);
    if (destSize > 0)
    {
        destSize+=sizeof(BYTE);
        LPWSTR dest=(LPWSTR)_alloc(destSize*sizeof(WCHAR));
        if (dest)
        {
            xToUnicode(codePage,source,size,dest,destSize);
            return dest;
        }
    }
    return NULL;
}

int UnicodeToAnsi(const LPWSTR source,int sourceSize,LPSTR dest,int destSize)
{
    return UnicodeToX(1251,source,sourceSize,dest,destSize);
}

bool _PathCombine(LPWSTR dest,const LPWSTR dir,const LPWSTR file)
{
    LPWSTR p=(LPWSTR)file;
    if (p)
    {
        while ((*p == '\\') || (*p == '/'))
            p++;
    }
    return (!PathCombineW(dest,dir,p)) ? false:true;
}

int AnsiToUnicode(LPSTR source,int sourceSize,LPWSTR dest,int destSize)
{
    return xToUnicode(1251,source,sourceSize,dest,destSize);
}

LPWSTR AnsiToUnicodeEx(LPSTR source,int size)
{
    return xToUnicodeEx(1251,source,size);
}

LPWSTR OemToUnicodeEx(LPSTR source,int size)
{
    return xToUnicodeEx(CP_OEMCP,source,size);
}

LPSTR UnicodeToXEx(DWORD codePage,const LPWSTR source,int size)
{
    if (size == -1)
        size=lstrlenW(source);
    int destSize=UnicodeToX(codePage,source,size,NULL,0);
    if (destSize > 0)
    {
        destSize+=sizeof(BYTE);
        LPSTR dest=(LPSTR)_alloc(destSize*sizeof(BYTE));
        if (dest)
        {
            UnicodeToX(codePage,source,size,dest,destSize);
            return dest;
        }
    }
    return NULL;
}

LPSTR UnicodeToAnsiEx(const LPWSTR source,int size)
{
    return UnicodeToXEx(1251,source,size);
}

LPSTR UnicodeToOemEx(const LPWSTR source,int size)
{
    return UnicodeToXEx(CP_OEMCP,source,size);
}

bool CreateDirectoryTree(LPWSTR path)
{
    bool r=false;
    LPWSTR p=PathSkipRootW(path);

    if (!p)
        p=path;

    for (;; p++)
    {
        if ((*p == '\\') || (*p == '/') || (!*p))
        {
            WCHAR cold=*p;
            *p=0;

            DWORD attr=GetFileAttributesW(path);
            if (attr == INVALID_FILE_ATTRIBUTES)
            {
                if (CreateDirectoryW(path,0) == FALSE)
                    break;
            }
            else if (!(attr & FILE_ATTRIBUTE_DIRECTORY))
                break;

            if (!cold)
            {
                r=true;
                break;
            }
            *p=cold;
        }
    }
    return r;
}

bool IsDotsName(LPWSTR name)
{
  return ((name) && (*name == '.') && ((!name[1]) || ((name[1] == '.') && (!name[2])))) ? true : false;
}

void FindFiles(LPWSTR path,const LPWSTR *fileMasks,DWORD fileMasksCount,DWORD flags,FINDFILEPROC findFileProc,void *data,HANDLE stopEvent,DWORD subfolderDelay,DWORD foundedDelay)
{
    WCHAR curPath[MAX_PATH];
    WIN32_FIND_DATAW wfd;
    HANDLE handle;

    if ((_PathCombine(curPath,path,L"*")) && ((handle=FindFirstFileW(curPath,&wfd)) != INVALID_HANDLE_VALUE))
    {
        do
        {
            if ((stopEvent != NULL) && (WaitForSingleObject(stopEvent,0) != WAIT_TIMEOUT))
                break;

            if (!IsDotsName(wfd.cFileName))
            {
                if (((wfd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) && (flags & FFFLAG_SEARCH_FOLDERS)) || ((!(wfd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)) && (flags & FFFLAG_SEARCH_FILES)))
                {
                    for (DWORD i=0; i < fileMasksCount; i++)
                    {
                        if (PathMatchSpecW(wfd.cFileName,fileMasks[i]) != FALSE)
                        {
                            if (!findFileProc(path,&wfd,data))
                                goto END;
                            if (flags & FFFLAG_DELETE)
                            {
                                WCHAR filePath[MAX_PATH];
                                if (_PathCombine(filePath,path,wfd.cFileName))
                                {
                                    SetFileAttributesW(filePath,FILE_ATTRIBUTE_NORMAL);
                                    DeleteFileW(filePath);
                                }
                            }
                            if (foundedDelay)
                                Sleep(foundedDelay);
                            break;
                        }
                    }
                }

                if (wfd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY && flags & FFFLAG_RECURSIVE)
                {
                    if (_PathCombine(curPath,path,wfd.cFileName))
                    {
                        if (subfolderDelay)
                            Sleep(subfolderDelay);
                        FindFiles(curPath,fileMasks,fileMasksCount,flags,findFileProc,data,stopEvent,subfolderDelay,foundedDelay);
                    }
                }
            }
        }
        while (FindNextFileW(handle,&wfd) != FALSE);
END:    FindClose(handle);
    }
    return;
}
