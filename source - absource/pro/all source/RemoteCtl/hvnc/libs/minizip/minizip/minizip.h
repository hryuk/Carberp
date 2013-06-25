#ifndef MSCAB_H
#define MSCAB_H

#define HZIP void *

#ifdef __cplusplus
 extern "C" {
#endif

/// API для компрессии
HZIP CreateArchiveW(WCHAR *lpstrZipFile,char *lpPassword,int dwPasswordLen,int dwCompLevel);
HZIP CreateArchiveA(char *lpstrZipFile,char *lpPassword,int dwPasswordLen,int dwCompLevel);

bool ArchAddFileW(HZIP hZip,WCHAR *pstrSourceFile,WCHAR *pstrDestFile);
bool ArchAddFileA(HZIP hZip,char *pstrSourceFile,char *pstrDestFile);

bool ArchCompressMemoryW(HZIP hZip,void *lpMem,int dwSize,WCHAR *pstrFile);
bool ArchCompressMemoryA(HZIP hZip,void *lpMem,int dwSize,char *pstrFile);

#define CFF_RECURSE 0x1
#define CFF_DELETE 0x2

bool ArchiveFolderW(HZIP hZip,WCHAR *sourceFolder,LPWSTR *fileMask,DWORD fileMaskCount,DWORD flags);
bool ArchiveFolderA(HZIP hZip,char *sourceFolder,LPSTR *fileMask,DWORD fileMaskCount,DWORD flags);

bool ArchCreateFromFolderW(WCHAR *lpstrZipFile,WCHAR *sourceFolder,LPWSTR *fileMask,DWORD fileMaskCount,DWORD flags,char *lpPassword,int dwPasswordLen,int dwCompLevel);
bool ArchCreateFromFolderA(char *lpstrZipFile,char *sourceFolder,LPSTR *fileMask,DWORD fileMaskCount,DWORD flags,char *lpPassword,int dwPasswordLen,int dwCompLevel);

#ifdef UNICODE
#define CreateArchive        CreateArchiveW
#define ArchAddFile          ArchAddFileW
#define ArchCompressMemory   ArchCompressMemoryW
#define ArchiveFolder        ArchiveFolderW
#define ArchCreateFromFolder ArchCreateFromFolderW
#else
#define CreateArchive        CreateArchiveA
#define ArchAddFile          ArchAddFileA
#define ArchCompressMemory   ArchCompressMemoryA
#define ArchiveFolder        ArchiveFolderA
#define ArchCreateFromFolder ArchCreateFromFolderA
#endif


/// API для декомпрессии
typedef BOOL WINAPI ARCHENUMNAMESCALLBACKW(WCHAR *lpstrFile);
typedef BOOL WINAPI ARCHENUMNAMESCALLBACKA(char *lpstrFile);

HZIP OpenArchiveW(WCHAR *lpstrZipFile,char *lpPassword,int dwPasswordLen,bool bZipInMem=false,int dwFileSize=0);
HZIP OpenArchiveA(char *lpstrZipFile,char *lpPassword,int dwPasswordLen,bool bZipInMem=false,int dwFileSize=0);

bool ArchExtractFileW(HZIP hZip,WCHAR *pstrPath,WCHAR *lpstrFile);
bool ArchExtractFileA(HZIP hZip,char *pstrPath,char *lpstrFile);

bool ArchExtractFilesW(HZIP hZip,WCHAR *pstrPath);
bool ArchExtractFilesA(HZIP hZip,char *pstrPath);

bool ArchGetFileW(HZIP hZip,WCHAR *pstrFile,byte **lpMem,int *dwSize);
bool ArchGetFileA(HZIP hZip,char *pstrFile,byte **lpMem,int *dwSize);

bool ArchEnumFilesW(HZIP hZip,ARCHENUMNAMESCALLBACKW *lpCallback);
bool ArchEnumFilesA(HZIP hZip,ARCHENUMNAMESCALLBACKA *lpCallback);


#ifdef UNICODE
#define OpenArchive      OpenArchiveW
#define ArchExtractFile  ArchExtractFileW
#define ArchExtractFiles ArchExtractFilesW
#define ArchGetFile      ArchGetFileW
#define ArchEnumFiles    ArchEnumFilesW
#define ARCHENUMNAMESCALLBACK ARCHENUMNAMESCALLBACKW
#else
#define OpenArchive      OpenArchiveA
#define ArchExtractFiles ArchExtractFilesA
#define ArchExtractFile  ArchExtractFileA
#define ArchGetFile      ArchGetFileA
#define ArchEnumFiles    ArchEnumFilesA
#define ARCHENUMNAMESCALLBACK ARCHENUMNAMESCALLBACKA
#endif

void ArchClose(HZIP hZip);
int ArchGetLastError();

#define ARCH_ZIP_IS_ENCRYPTED   2
#define ARCH_ZIP_NOT_FOUND      3
#define ARCH_FILE_NOT_FOUND     4
#define ARCH_INVALID_PARAMETER  5
#define ARCH_NO_MEM             6
#define ARCH_FILE_TOO_BIG       7

#ifdef __cplusplus
 }
#endif

#endif /* MSCAB_H */
