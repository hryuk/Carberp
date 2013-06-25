#include "..\includes.h"
#include <math.h>
#include "cpu_limit.h"
#include "events.h"

bool bCpuSleep=false,
     bSlowPC=false;

int GetMemSize()
{
    _MEMORYSTATUS mem;
    mem.dwLength=sizeof(MEMORYSTATUS);
    GlobalMemoryStatus(&mem);

    int dwMemSize=(int)mem.dwTotalPhys;
    dwMemSize=dwMemSize/(1024*1024);
    return dwMemSize;
}

int dwMemUsage;
DWORD dwProcessorsCount,dwProcessorSpeed;
int GetMemUsage()
{
    MEMORYSTATUSEX statex;
    statex.dwLength=sizeof(statex);
    GlobalMemoryStatusEx(&statex);
    return statex.dwMemoryLoad;
}

void CheckPCPerfomance()
{
    SYSTEM_INFO SysInfo;
    GetSystemInfo(&SysInfo);
    dwProcessorsCount=SysInfo.dwNumberOfProcessors;

    HKEY hKey;
    if (RegOpenKeyEx(HKEY_LOCAL_MACHINE,_T("HARDWARE\\DESCRIPTION\\System\\CentralProcessor\\0"),0,KEY_READ+KEY_WOW64_64KEY,&hKey) == ERROR_SUCCESS)
    {
        DWORD dwLen=sizeof(DWORD);
        RegQueryValueEx(hKey,_T("~MHz"),NULL,NULL,(byte*)&dwProcessorSpeed,&dwLen);
        RegCloseKey(hKey);
    }
    if ((dwProcessorsCount <= 2) && (dwProcessorSpeed <= 2000) && (GetMemSize() < 600))
        bSlowPC=true;
    return;
}

#ifndef _INJLIB
DWORD GetUserIdleTime()
{
    DWORD dwTickCount=GetTickCount();
    LASTINPUTINFO liiInfo;
    liiInfo.cbSize=sizeof(LASTINPUTINFO);
    GetLastInputInfo(&liiInfo);
    return (dwTickCount-liiInfo.dwTime)/1000;
}

DWORD dwIdleTime,dwPeriodBegin;
void WINAPI CpuLimitThread(LPVOID)
{
    LARGE_INTEGER liOldIdleTime={0},liOldSystemTime={0};
    SYSTEM_PERFORMANCE_INFORMATION spi;
    SYSTEM_TIME_INFORMATION sti;
    if ((!NtQuerySystemInformation(SystemPerformanceInformation,&spi,sizeof(spi),NULL)) && (!NtQuerySystemInformation(SystemTimeOfDayInformation,&sti,sizeof(sti),NULL)))
    {
        if (liOldIdleTime.QuadPart)
        {
            double dbIdleTime=Li2Double(spi.IdleTime)-Li2Double(liOldIdleTime),
            dbSystemTime=Li2Double(sti.nKeSystemTime)-Li2Double(liOldSystemTime);
            dbIdleTime=dbIdleTime/dbSystemTime;
            dbIdleTime=100.0-dbIdleTime*100.0*(double)dwProcessorsCount+0.5;
            dwIdleTime=(DWORD)dbIdleTime;

            if ((dwIdleTime >= MAX_CPU_TIME_LIMIT) && (GetUserIdleTime() < MAX_IDLE_TIME))
            {
                if (bCpuSleep)
                {
                    bCpuSleep=false;
                    dwPeriodBegin=0;
                }
                else
                {
                    DWORD dwPeriodEnd=GetTickCount();
                    if (dwPeriodEnd-dwPeriodBegin >= MAX_CPU_LOAD_DURATION)
                        bCpuSleep=true;
                    dwPeriodBegin=dwPeriodEnd;
                }
            }
            else
            {
                bCpuSleep=false;
                dwPeriodBegin=0;
            }
        }
        liOldIdleTime.QuadPart=spi.IdleTime.QuadPart;
        liOldSystemTime.QuadPart=sti.nKeSystemTime.QuadPart;
    }
    dwMemUsage=GetMemUsage();
    Sleep(1000);
    return;
}
#endif

