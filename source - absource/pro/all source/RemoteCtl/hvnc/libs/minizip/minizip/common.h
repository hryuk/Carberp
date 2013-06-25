#ifndef COMMON_H_INCLUDED
#define COMMON_H_INCLUDED

#include <windows.h>
#include <shlwapi.h>

#include "minizip.h"
#include "minizip\zip.h"
#include "minizip\unzip.h"
#include "compress_wrap.h"
#include "decompress_wrap.h"

extern "C" bool SysCloseHandle(HANDLE hHandle);

extern "C" void fill_memory_filefunc (zlib_filefunc64_def* pzlib_filefunc_def);

#define INT_BUF_SIZE 5*1024

uLong filetime(WCHAR *filename, tm_zip *tmzip, uLong *dt);
bool _feof(HANDLE hFile);
int getFileCrc(const WCHAR* filenameinzip,void*buf,unsigned long size_buf,unsigned long* result_crc);

#define HT_COMPRESSOR 1
#define HT_DECOMPRESSOR 2

typedef struct
{
    LPWSTR fileName;
    HANDLE handle;
    int oflags;
} CFDATA;

#define CFF_RECURSE 0x1
#define CFF_DELETE 0x2
#define FFFLAG_RECURSIVE 0x1
#define FFFLAG_SEARCH_FOLDERS 0x2
#define FFFLAG_SEARCH_FILES 0x4
#define FFFLAG_DELETE 0x8

typedef bool (FINDFILEPROC)(const LPWSTR path, const WIN32_FIND_DATAW *fileInfo, void *data);

LPWSTR CopyExW(LPWSTR pstrSource,int iSize);

int UnicodeToAnsi(const LPWSTR source,int sourceSize,LPSTR dest,int destSize);
LPWSTR AnsiToUnicodeEx(LPSTR source,int size);
int AnsiToUnicode(LPSTR source,int sourceSize,LPWSTR dest,int destSize);
bool _PathCombine(LPWSTR dest,const LPWSTR dir,const LPWSTR file);
bool CreateDirectoryTree(LPWSTR path);
LPSTR UnicodeToAnsiEx(const LPWSTR source,int size);
void FindFiles(LPWSTR path,const LPWSTR *fileMasks,DWORD fileMasksCount,DWORD flags,FINDFILEPROC findFileProc,void *data,HANDLE stopEvent,DWORD subfolderDelay,DWORD foundedDelay);
void *_alloc(ULONG size);
void change_file_date(WCHAR *filename,uLong dosdate,tm_unz tmu_date);
LPSTR UnicodeToOemEx(const LPWSTR source,int size);
LPWSTR OemToUnicodeEx(LPSTR source,int size);

void ArchSetLastError(int dwError);
int ArchGetLastError();

#define CASESENSITIVITY 0

extern "C" void *MemAlloc(size_t dwSize);
extern "C" void *MemRealloc(void *lpMem,size_t dwSize);
extern "C" void MemFree(void *lpMem);

#endif // COMMON_H_INCLUDED
