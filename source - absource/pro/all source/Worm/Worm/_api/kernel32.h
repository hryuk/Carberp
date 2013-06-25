#include <windows.h>

//@S
HANDLE _KERNEL32=0;

///////////////////////////////////////
//this part is filled directly

FARPROC (WINAPI *_GetProcAddress)(HMODULE hModule,LPCSTR lpProcName);
HANDLE  (WINAPI *_CreateThread)(LPSECURITY_ATTRIBUTES lpThreadAttributes,DWORD dwStackSize,LPTHREAD_START_ROUTINE lpStartAddress,LPVOID lpParameter,DWORD dwCreationFlags,LPDWORD lpThreadId);
VOID    (WINAPI *_EnterCriticalSection)(LPCRITICAL_SECTION lpCriticalSection);
VOID    (WINAPI *_InitializeCriticalSection)(LPCRITICAL_SECTION lpCriticalSection);
VOID    (WINAPI *_LeaveCriticalSection)(LPCRITICAL_SECTION lpCriticalSection);	
VOID    (WINAPI *_Sleep)(DWORD dwMilliseconds);
BOOL    (WINAPI *_VirtualProtect)(LPVOID lpAddress,SIZE_T dwSize,DWORD flNewProtect,PDWORD lpflOldProtect);
//direct fill part end
///////////////////////////////////////

HANDLE    (WINAPI *_CreateToolhelp32Snapshot)(DWORD dwFlags,DWORD th32ProcessID);
BOOL      (WINAPI *_Process32First)(HANDLE hSnapshot,LPPROCESSENTRY32 lppe);
BOOL      (WINAPI *_Process32Next)(HANDLE hSnapshot,LPPROCESSENTRY32 lppe);
BOOL      (WINAPI *_IsBadStringPtrW)(LPCTSTR lpsz,UINT_PTR ucchMax);
VOID      (WINAPI *_ExitThread)(DWORD dwExitCode);
HMODULE   (WINAPI *_GetModuleHandle)(LPCTSTR lpModuleName);
HINSTANCE (WINAPI *_LoadLibrary)(LPCTSTR lpLibFileName);
HANDLE    (WINAPI *_CreateFile)(LPCTSTR lpFileName,DWORD dwDesiredAccess,DWORD dwShareMode,LPSECURITY_ATTRIBUTES lpSecurityAttributes,DWORD dwCreationDistribution,DWORD dwFlagsAndAttributes,HANDLE hTemplateFile);
BOOL      (WINAPI *_DeleteFile)(LPCTSTR lpFileName);
DWORD     (WINAPI *_SetFilePointer)(HANDLE hFile,LONG lDistanceToMove,PLONG lpDistanceToMoveHigh,DWORD dwMoveMethod);
BOOL      (WINAPI *_WriteFile)(HANDLE hFile,LPCVOID lpBuffer,DWORD nNumberOfBytesToWrite,LPDWORD lpNumberOfBytesWritten,LPOVERLAPPED lpOverlapped);
BOOL      (WINAPI *_CloseHandle)(HANDLE hObject);
DWORD     (WINAPI *_GetFileSize)(HANDLE hFile,LPDWORD lpFileSizeHigh);
VOID      (WINAPI *_GetSystemTime)(LPSYSTEMTIME lpSystemTime);
DWORD     (WINAPI *_GetTempPath)(DWORD nBufferLength,LPTSTR lpBuffer);
HLOCAL    (WINAPI *_LocalAlloc)(UINT uFlags,UINT uBytes);
HLOCAL    (WINAPI *_LocalFree)(HLOCAL hMem);	
int       (WINAPI *_MultiByteToWideChar)(UINT CodePage,DWORD dwFlags,LPCSTR lpMultiByteStr,int cchMultiByte,LPWSTR lpWideCharStr,int cchWideChar);
BOOL      (WINAPI *_ReadFile)(HANDLE hFile,LPVOID lpBuffer,DWORD nNumberOfBytesToRead,LPDWORD lpNumberOfBytesRead,LPOVERLAPPED lpOverlapped);	
LPVOID    (WINAPI *_VirtualAlloc)(LPVOID lpAddress,DWORD dwSize,DWORD flAllocationType,DWORD flProtect); 
BOOL      (WINAPI *_VirtualFree)(LPVOID lpAddress,DWORD dwSize,DWORD dwFreeType);
int       (WINAPI *_WideCharToMultiByte)(UINT CodePage,DWORD dwFlags,LPCWSTR lpWideCharStr,int cchWideChar,LPSTR lpMultiByteStr,int cchMultiByte,LPCSTR lpDefaultChar,LPBOOL lpUsedDefaultChar);
UINT      (WINAPI *_WinExec)(LPCSTR lpCmdLine,UINT uCmdShow);
VOID      (WINAPI *_ZeroMemory)(PVOID Destination,DWORD Length);
int       (WINAPI *_lstrlenW)(LPCWSTR lpszString);
int       (WINAPI *_lstrlen)(LPCSTR lpszString);
DWORD     (WINAPI *_GetTickCount)(VOID);
HANDLE    (WINAPI *_FindFirstFile)(LPCTSTR lpFileName,LPWIN32_FIND_DATA lpFindFileData);
BOOL      (WINAPI *_FindNextFile)(HANDLE hFindFile,LPWIN32_FIND_DATA lpFindFileData);
UINT      (WINAPI *_GetDriveType)(LPCTSTR lpRootPathName);
BOOL      (WINAPI *_GetExitCodeThread)(HANDLE hThread,LPDWORD lpExitCode);
UINT      (WINAPI *_SetErrorMode)(UINT uMode);
BOOL      (WINAPI *_GetDiskFreeSpace)(LPCTSTR lpRootPathName,LPDWORD lpSectorsPerCluster,LPDWORD lpBytesPerSector,LPDWORD lpNumberOfFreeClusters,LPDWORD lpTotalNumberOfClusters);
BOOL      (WINAPI *_CopyFile)(LPCTSTR lpExistingFileName,LPCTSTR lpNewFileName,BOOL bFailIfExists);
HANDLE    (WINAPI *_CreateMutex)(LPSECURITY_ATTRIBUTES lpMutexAttributes,BOOL bInitialOwner,LPCTSTR lpName);
HANDLE    (WINAPI *_OpenMutex)(DWORD dwDesiredAccess,BOOL bInheritHandle,LPCTSTR lpName);
DWORD     (WINAPI *_GetModuleFileName)(HMODULE hModule,LPTSTR lpFilename,DWORD nSize);
UINT      (WINAPI *_GetSystemDirectory)(LPTSTR lpBuffer,UINT uSize);
/* XXX : MSVS has _Interlocked_XXX macro */
LONG      (WINAPI *__InterlockedIncrement)(LONG volatile* lpAddend);
LONG      (WINAPI *__InterlockedDecrement)(LONG volatile* lpAddend);
BOOL      (WINAPI *_GetVolumeInformation)(LPCTSTR lpRootPathName,LPTSTR lpVolumeNameBuffer,DWORD nVolumeNameSize,LPDWORD lpVolumeSerialNumber,LPDWORD lpMaximumComponentLength,LPDWORD lpFileSystemFlags,LPTSTR lpFileSystemNameBuffer,DWORD nFileSystemNameSize);
LONG      (WINAPI *_CompareFileTime)(const FILETIME* lpFileTime1,const FILETIME* lpFileTime2);
BOOL      (WINAPI *_FileTimeToSystemTime)(const FILETIME* lpFileTime,LPSYSTEMTIME lpSystemTime);
BOOL      (WINAPI *_FindClose)(HANDLE hFindFile);
BOOL      (WINAPI *_GetVersionEx)(LPOSVERSIONINFO lpVersionInformation);
int       (WINAPI *_GetLocaleInfo)(LCID Locale,LCTYPE LCType,LPTSTR lpLCData,int cchData);
HANDLE    (WINAPI *_OpenProcess)(DWORD dwDesiredAccess,BOOL bInheritHandle,DWORD dwProcessId);
DWORD     (WINAPI *_GetCurrentProcessId)(VOID);
DWORD     (WINAPI *_GetCurrentThreadId)(VOID);
DWORD     (WINAPI *_WaitForSingleObject)(HANDLE hHandle,DWORD dwMilliseconds);
BOOL      (WINAPI *_FreeLibrary)(HMODULE hModule);
BOOL      (WINAPI *_FreeEnvironmentStrings)(LPTCH lpszEnvironmentBlock);
LPTCH     (WINAPI *_GetEnvironmentStrings)(void);
BOOL      (WINAPI *_GetComputerName)(LPTSTR lpBuffer,LPDWORD lpnSize);
BOOL      (WINAPI *_CreateDirectory)(LPCTSTR,LPSECURITY_ATTRIBUTES);
BOOL      (WINAPI *_PeekNamedPipe)(HANDLE hNamedPipe,LPVOID lpBuffer,DWORD nBufferSize,LPDWORD lpBytesRead,LPDWORD lpTotalBytesAvail,LPDWORD lpBytesLeftThisMessage);
BOOL      (WINAPI *_CreatePipe)(PHANDLE hReadPipe,PHANDLE hWritePipe,LPSECURITY_ATTRIBUTES lpPipeAttributes,DWORD nSize);
BOOL      (WINAPI *_CreateProcess)(LPCTSTR lpApplicationName,LPTSTR lpCommandLine,LPSECURITY_ATTRIBUTES lpProcessAttributes,LPSECURITY_ATTRIBUTES lpThreadAttributes,BOOL bInheritHandles,DWORD dwCreationFlags,LPVOID lpEnvironment,LPCTSTR lpCurrentDirectory,LPSTARTUPINFO lpStartupInfo,LPPROCESS_INFORMATION lpProcessInformation);
BOOL      (WINAPI *_GetExitCodeProcess)(HANDLE hProcess,LPDWORD lpExitCode);
BOOL      (WINAPI *_TerminateThread)(HANDLE hThread,DWORD dwExitCode);
BOOL      (WINAPI *_TerminateProcess)(HANDLE hProcess,UINT uExitCode);
BOOL      (WINAPI *_IsBadReadPtr)( const void* lp, UINT ucb); 
void      (WINAPI *_OutputDebugStringA)( LPCSTR lpOutputString );
LPTSTR    (WINAPI *_lstrcatA)( LPTSTR lpString1, LPTSTR lpString2 );
//@E

//BOOL WINAPI    (*_Beep)(DWORD dwFreq,DWORD dwDuration);
//VOID WINAPI    (*_GlobalMemoryStatus)(LPMEMORYSTATUS lpBuffer);

//DWORD _GPAecoK32(char *fname) // Economy Code
//{
// DWORD a=(DWORD)_GetProcAddress(_KERNEL32,fname);
// return a;
//}

DWORD  *padrK32a[] =                    {(DWORD*)&_GetModuleHandle, (DWORD*)&_LoadLibrary}; // &_GetTickCount,

void InitKernel32a()
{
 InitAPIbyStr(padrK32a,_KERNEL32,"/*@S|*/00GetModuleHandleA|01LoadLibraryA/*@E*/|"); // 01GetTickCount|

// _GetModuleHandle = (DWORD *)_GPAecoK32("GetModuleHandleA"); //@S
// _GetTickCount    = (DWORD *)_GPAecoK32("GetTickCount");
// _LoadLibrary     = (DWORD *)_GPAecoK32("LoadLibraryA");     //@E
}

void  *padrK32[] =                    {&_OpenMutex, &_CloseHandle,&_ExitThread,&_CreateFile, &_DeleteFile, &_SetFilePointer,&_WriteFile,&_GetFileSize,&_lstrlenW,&_WinExec,&_WideCharToMultiByte,&_MultiByteToWideChar,&_GetTempPath, &_ReadFile,&_VirtualAlloc,&_VirtualFree,&_LocalAlloc,&_LocalFree,&_GetSystemTime,&_ZeroMemory,   &_FindFirstFile, &_FindNextFile, &_FindClose,&_GetDriveType, &_GetExitCodeThread,&_SetErrorMode,&_GetDiskFreeSpace, &_CopyFile, &_CreateMutex, &_GetModuleFileName, &_GetSystemDirectory, &__InterlockedIncrement, &__InterlockedDecrement, &_GetVolumeInformation, &_CompareFileTime, &_FileTimeToSystemTime, &_GetVersionEx, &_GetLocaleInfo, &_OpenProcess,&_GetCurrentProcessId,&_GetCurrentThreadId,&_FreeEnvironmentStrings, &_GetEnvironmentStrings, &_GetComputerName, &_WaitForSingleObject,&_FreeLibrary,&_CreateDirectory, &_PeekNamedPipe,&_CreatePipe,&_CreateProcess, &_GetExitCodeProcess,&_IsBadStringPtrW,&_TerminateThread,&_CreateToolhelp32Snapshot,&_Process32First,&_Process32Next,&_TerminateProcess,&_lstrlen,&_IsBadReadPtr,&_OutputDebugStringA,&_lstrcatA};

void InitKernel32()
{
 InitAPIbyStr(padrK32,_KERNEL32,"/*@S|*/00OpenMutexA|01CloseHandle|02ExitThread|03CreateFileA|04DeleteFileA|05SetFilePointer|06WriteFile|07GetFileSize|08lstrlenW|09WinExec|10WideCharToMultiByte|11MultiByteToWideChar|12GetTempPathA|13ReadFile|14VirtualAlloc|15VirtualFree|16LocalAlloc|17LocalFree|18GetSystemTime|19RtlZeroMemory|20FindFirstFileA|21FindNextFileA|22FindClose|23GetDriveTypeA|24GetExitCodeThread|25SetErrorMode|26GetDiskFreeSpaceA|27CopyFileA|28CreateMutexA|29GetModuleFileNameA|30GetSystemDirectoryA|31InterlockedIncrement|32InterlockedDecrement|33GetVolumeInformationA|34CompareFileTime|35FileTimeToSystemTime|36GetVersionExA|37GetLocaleInfoA|38OpenProcess|39GetCurrentProcessId|40GetCurrentThreadId|41FreeEnvironmentStringsA|42GetEnvironmentStringsA|43GetComputerNameA|44WaitForSingleObject|45FreeLibrary|46CreateDirectoryA|47PeekNamedPipe|48CreatePipe|49CreateProcessA|50GetExitCodeProcess|51IsBadStringPtrW|52TerminateThread|53CreateToolhelp32Snapshot|54Process32First|55Process32Next|56TerminateProcess|57lstrlenA|58IsBadReadPtr|59OutputDebugStringA|60lstrcatA/*@E*/|");
 
/*
//@S
 _OpenMutex       = (DWORD *)_GPAecoK32("OpenMutexA");
 _CloseHandle     = (DWORD *)_GPAecoK32("CloseHandle"); 
 _ExitThread      = (DWORD *)_GPAecoK32("ExitThread");
 _CreateFile      = (DWORD *)_GPAecoK32("CreateFileA");
 _DeleteFile      = (DWORD *)_GPAecoK32("DeleteFileA");
 _SetFilePointer  = (DWORD *)_GPAecoK32("SetFilePointer");
 _WriteFile       = (DWORD *)_GPAecoK32("WriteFile");
 _GetFileSize     = (DWORD *)_GPAecoK32("GetFileSize");
 _lstrlenW        = (DWORD *)_GPAecoK32("lstrlenW");
 _WinExec         = (DWORD *)_GPAecoK32("WinExec");
 _WideCharToMultiByte = (DWORD *)_GPAecoK32("WideCharToMultiByte");
 _MultiByteToWideChar = (DWORD *)_GPAecoK32("MultiByteToWideChar");
 _GetTempPath     = (DWORD *)_GPAecoK32("GetTempPathA");
 _ReadFile        = (DWORD *)_GPAecoK32("ReadFile");
 _VirtualAlloc    = (DWORD *)_GPAecoK32("VirtualAlloc");
 _VirtualFree     = (DWORD *)_GPAecoK32("VirtualFree");
 _LocalAlloc      = (DWORD *)_GPAecoK32("LocalAlloc");
 _LocalFree       = (DWORD *)_GPAecoK32("LocalFree");
 _GetSystemTime   = (DWORD *)_GPAecoK32("GetSystemTime");
 _ZeroMemory      = (DWORD *)_GPAecoK32("RtlZeroMemory");
 _FindFirstFile   = (DWORD *)_GPAecoK32("FindFirstFileA");
 _FindNextFile    = (DWORD *)_GPAecoK32("FindNextFileA");
 _FindClose       = (DWORD *)_GPAecoK32("FindClose");
 _GetDriveType    = (DWORD *)_GPAecoK32("GetDriveTypeA");
 _GetExitCodeThread = (DWORD *)_GPAecoK32("GetExitCodeThread");
 _SetErrorMode      = (DWORD *)_GPAecoK32("SetErrorMode");
 _GetDiskFreeSpace  = (DWORD *)_GPAecoK32("GetDiskFreeSpaceA");
 _CopyFile        = (DWORD *)_GPAecoK32("CopyFileA");
 _CreateMutex     = (DWORD *)_GPAecoK32("CreateMutexA");
 _GetModuleFileName  = (DWORD *)_GPAecoK32("GetModuleFileNameA"); 
 _GetSystemDirectory = (DWORD *)_GPAecoK32("GetSystemDirectoryA"); 
 _InterlockedIncrement = (DWORD *)_GPAecoK32("InterlockedIncrement");
 _InterlockedDecrement = (DWORD *)_GPAecoK32("InterlockedDecrement");
 _GetVolumeInformation = (DWORD *)_GPAecoK32("GetVolumeInformationA");
 _CompareFileTime      = (DWORD *)_GPAecoK32("CompareFileTime");
 _FileTimeToSystemTime = (DWORD *)_GPAecoK32("FileTimeToSystemTime");
 _GetVersionEx  = (DWORD *)_GPAecoK32("GetVersionExA");
 _GetLocaleInfo = (DWORD *)_GPAecoK32("GetLocaleInfoA");
 _OpenProcess   = (DWORD *)_GPAecoK32("OpenProcess");
 _GetCurrentProcessId = (DWORD *)_GPAecoK32("GetCurrentProcessId");
 _GetCurrentThreadId = (DWORD *)_GPAecoK32("GetCurrentThreadId");
 _FreeEnvironmentStrings = (DWORD *)_GPAecoK32("FreeEnvironmentStringsA");
 _GetEnvironmentStrings  = (DWORD *)_GPAecoK32("GetEnvironmentStringsA");
 _GetComputerName        = (DWORD *)_GPAecoK32("GetComputerNameA");
 _WaitForSingleObject    = (DWORD *)_GPAecoK32("WaitForSingleObject");
 _FreeLibrary            = (DWORD *)_GPAecoK32("FreeLibrary");
//@E
*/
// _GlobalMemoryStatus  = (DWORD *)_GPAecoK32("GLobalMemoryStatus");
// _Beep            = (DWORD *)_GPAecoK32("Beep");
}
