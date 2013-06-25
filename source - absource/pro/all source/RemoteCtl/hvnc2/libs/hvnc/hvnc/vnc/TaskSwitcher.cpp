#include "..\includes.h"
#include "taskswitcher.h"
#include "vnc_func.h"
#include "windows.h"
#include "mou.h"

byte TaskSwitcherWnd[]=
{
	0x01,0x00,0xff,0xff,0x00,0x00,0x00,0x00,0x88,0x00,0x00,0x00,0x40,0x08,0x84,0x90,
	0x01,0x00,0xfa,0xff,0xfd,0xff,0xb4,0x00,0x39,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x08,0x00,0x00,0x00,0x00,0x00,0x4d,0x00,0x53,0x00,0x20,0x00,0x53,0x00,0x61,0x00,
	0x6e,0x00,0x73,0x00,0x20,0x00,0x53,0x00,0x65,0x00,0x72,0x00,0x69,0x00,0x66,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0c,0x02,0x80,0x50,
	0x06,0x00,0x27,0x00,0xa8,0x00,0x0c,0x00,0xe9,0x03,0x00,0x00,0xff,0xff,0x82,0x00,
	0x00,0x00,0x00,0x00
};

HICON GetAppIcon(DWORD dwPid)
{
    HANDLE hProcess=OpenProcess(PROCESS_QUERY_INFORMATION|PROCESS_VM_READ,FALSE,dwPid);
    TCHAR szFileName[MAX_PATH];
    GetModuleFileNameEx(hProcess,NULL,szFileName,MAX_PATH);
    SysCloseHandle(hProcess);
    HICON hIcon;
    ExtractIconEx(szFileName,0,&hIcon,NULL,1);
    return hIcon;
}

int GetTextWnd(HWND hWnd,TCHAR *lpStr,int dwSize)
{
    DWORD dwThreadID=GetWindowThreadProcessId(hWnd,NULL),
          dwCurThreadID=GetCurrentThreadId();
    AttachThreadInput(dwCurThreadID,dwThreadID,true);
    int ret_val=(int)SendMessage(hWnd,WM_GETTEXT,dwSize,(LPARAM)lpStr);
    AttachThreadInput(dwCurThreadID,dwThreadID,false);
    return ret_val;
}

void ResetStyle(HWND hWnd)
{
    SetClassLongPtr(hWnd,GCL_STYLE,GetClassLongPtr(hWnd,GCL_STYLE) & ~(CS_CLASSDC|CS_PARENTDC));
    return;
}

void SetStyle(HWND hWnd,bool bReset)
{
    if (!bReset)
        SetWindowLongPtr(hWnd,GWL_STYLE,GetWindowLongPtr(hWnd,GWL_STYLE) | WS_BORDER);
    else
        SetWindowLongPtr(hWnd,GWL_STYLE,GetWindowLongPtr(hWnd,GWL_STYLE) & ~WS_BORDER);
    SetWindowPos(hWnd,0,0,0,0,0,SWP_NOMOVE+SWP_NOSIZE+SWP_NOZORDER+SWP_FRAMECHANGED);
    return;
}

INT_PTR CALLBACK DialogProc(HWND hWnd,UINT uMsg,WPARAM wParam,LPARAM lParam)
{
    PHVNC lpServer=(PHVNC)GetWindowLong(hWnd,GWLP_USERDATA);
    switch (uMsg)
    {
        case WM_CLOSE:
        {
            if (wParam == 1)
            {
                if (lpServer->TaskSwitcherInfo.dwCurWnd >= 0)
                {
                    if (lpServer->TaskSwitcherInfo.bNewCountDown)
                        lpServer->TaskSwitcherInfo.dwCurWnd=lpServer->TaskSwitcherInfo.dwWindowsCount;
                    else if (!lpServer->TaskSwitcherInfo.dwCurWnd)
                        lpServer->TaskSwitcherInfo.dwCurWnd=1;

                    APPSWITCH_ITEM *lpAppSwitch=(APPSWITCH_ITEM*)GetWindowLongPtr(GetDlgItem(hWnd,lpServer->TaskSwitcherInfo.dwCurWnd-1),GWLP_USERDATA);
                    if (lpAppSwitch)
                    {
                        SetForegroundWnd(lpServer,lpAppSwitch->hWnd);
                        lpServer->TaskSwitcherInfo.hFrgWnd=lpAppSwitch->hWnd;
                    }
                }
            }
            for (int i=0; i <= lpServer->TaskSwitcherInfo.dwWindowsCount; i++)
            {
                HWND hIconWnd=GetDlgItem(hWnd,i);
                if (hIconWnd)
                {
                    APPSWITCH_ITEM *lpAppSwitch=(APPSWITCH_ITEM*)GetWindowLongPtr(hIconWnd,GWLP_USERDATA);
                    if (lpAppSwitch)
                    {
                        DeleteObject(lpAppSwitch->hIcon);
                        MemFree(lpAppSwitch);
                        DestroyWindow(hIconWnd);
                    }
                }
            }
            EndDialog(hWnd,NULL);
            break;
        }
        case WM_INITDIALOG:
        {
            lpServer=(PHVNC)lParam;
            SetWindowLong(hWnd,GWLP_USERDATA,lParam);
            lpServer->TaskSwitcherInfo.hTaskSwitcherWnd=hWnd;
            lpServer->TaskSwitcherInfo.hTitle=GetDlgItem(hWnd,IDC_WNDNAME);
            ResetStyle(lpServer->TaskSwitcherInfo.hTitle);
            lpServer->TaskSwitcherInfo.hFont=(HFONT)SendMessage(lpServer->TaskSwitcherInfo.hTitle,WM_GETFONT,0,0);
            LOGFONT lf;
            GetObject(lpServer->TaskSwitcherInfo.hFont,sizeof(lf),&lf);
            lf.lfWeight=FW_BOLD;
            lpServer->TaskSwitcherInfo.hFont=CreateFontIndirect(&lf);
            SendMessage(lpServer->TaskSwitcherInfo.hTitle,WM_SETFONT,(WPARAM)lpServer->TaskSwitcherInfo.hFont,0);

            DWORD dwX=TS_ICON_FIRSTX+4,dwY=TS_ICON_FIRSTY;
            lpServer->TaskSwitcherInfo.dwCurWnd=-1;
            lpServer->TaskSwitcherInfo.dwWindowsCount=0;

            int i=0;
            HWND hPrevWnd=NULL;
            Z_ORDER_LIST_ITEM *lpWnd=GetWndFromList(lpServer,lpServer->lpGlobalVNCData->hForegroundWnd);
            if (lpWnd)
            {
                do
                {
                    HWND hCurWnd=lpWnd->hWnd;
                    if (!IsWindowEx(lpServer,hCurWnd))
                    {
                        DeleteWndFromList(lpServer,hCurWnd);
                        continue;
                    }
                    else if (lpWnd->bAltTabItem)
                    {
                        if (i == TS_MAX_ICONS_X)
                        {
                            dwY+=TS_ICON_HEIGHT;
                            dwX=TS_ICON_FIRSTX+4;
                            i=0;

                            RECT rect;
                            GetWindowRect(hWnd,&rect);
                            DWORD dwNewHeight=(rect.bottom-rect.top)+TS_ICON_HEIGHT,
                                  dwNewTop=rect.top-TS_ICON_HEIGHT;
                            SetWindowPos(hWnd,NULL,rect.left,dwNewTop,TS_DEFAULT_WIDTH,dwNewHeight,SWP_NOREPOSITION);

                            GetClientRect(hWnd,&rect);

                            MoveWindow(lpServer->TaskSwitcherInfo.hTitle,TS_TEXT_X,dwY+TS_ICON_HEIGHT+10,TS_TEXT_WIDTH,TS_TEXT_HEIGHT,true);
                        }

                        HWND hIconWnd=CreateWindow(_T("static"),NULL,SS_ICON+WS_CHILD+WS_VISIBLE,dwX,dwY,TS_ICON_WIDTH,TS_ICON_HEIGHT,hWnd,NULL,(HINSTANCE)GetModuleHandle(0),NULL);
                        SetWindowLongPtr(hIconWnd,GWLP_ID,lpServer->TaskSwitcherInfo.dwWindowsCount);
                        ResetStyle(hIconWnd);

                        DWORD dwLen=GetWindowTextLength(hCurWnd);
                        APPSWITCH_ITEM *lpAppSwitch=(APPSWITCH_ITEM *)MemAlloc(sizeof(APPSWITCH_ITEM)+dwLen*sizeof(TCHAR));
                        if (lpAppSwitch)
                        {
                            if (dwLen)
                                GetTextWnd(hCurWnd,lpAppSwitch->szText,dwLen*sizeof(TCHAR)+1);
                            lpAppSwitch->hWnd=hCurWnd;
                            SetWindowLongPtr(hIconWnd,GWLP_USERDATA,(LONG)lpAppSwitch);
                        }

                        HICON hIcon=(HICON)SendMessage(hCurWnd,WM_GETICON,ICON_BIG,0);
                        if (!hIcon)
                        {
                            DWORD dwPid;
                            GetWindowThreadProcessId(hCurWnd,&dwPid);
                            hIcon=GetAppIcon(dwPid);
                            if (!hIcon)
                            {
                                hIcon=(HICON)GetClassLong(hCurWnd,GCLP_HICONSM);
                                if (!hIcon)
                                {
                                    hIcon=(HICON)GetClassLong(hCurWnd,GCLP_HICON);
                                    if (!hIcon)
                                        hIcon=LoadIcon(NULL,MAKEINTRESOURCE(IDI_APPLICATION));
                                }
                            }
                        }
                        if (lpAppSwitch)
                            lpAppSwitch->hIcon=hIcon;
                        SendMessage(hIconWnd,STM_SETIMAGE,IMAGE_ICON,(LPARAM)hIcon);
                        if (hCurWnd == lpServer->lpGlobalVNCData->hForegroundWnd)
                        {
                            lpServer->TaskSwitcherInfo.hLastWnd=hIconWnd;
                            lpServer->TaskSwitcherInfo.dwCurWnd=lpServer->TaskSwitcherInfo.dwWindowsCount+1;
                            SetStyle(lpServer->TaskSwitcherInfo.hLastWnd,false);
                        }
                        i++;
                        dwX+=TS_ICON_WIDTH+4;
                        lpServer->TaskSwitcherInfo.dwWindowsCount++;
                        hPrevWnd=hCurWnd;
                    }
                }
                while (lpWnd=lpWnd->lpPrev);
            }

            if (lpServer->TaskSwitcherInfo.dwWindowsCount <= 1)
            {
                if (IsIconic(hPrevWnd))
                    ShowWindow(hPrevWnd,SW_SHOWNORMAL);

                SetForegroundWnd(lpServer,hPrevWnd);

                PostMessage(hWnd,WM_CLOSE,0,0);
                break;
            }
            else
            {
                if (!lpServer->TaskSwitcherInfo.hLastWnd)
                    lpServer->TaskSwitcherInfo.dwCurWnd=0;
            }
        }
        case WM_NEXTAPP:
        {
            if (lpServer->TaskSwitcherInfo.dwCurWnd >= lpServer->TaskSwitcherInfo.dwWindowsCount)
                lpServer->TaskSwitcherInfo.dwCurWnd=0;

            if (lpServer->TaskSwitcherInfo.hLastWnd)
                SetStyle(lpServer->TaskSwitcherInfo.hLastWnd,true);

            HWND hIconWnd=GetDlgItem(hWnd,lpServer->TaskSwitcherInfo.dwCurWnd++);
            if (hIconWnd)
            {
                APPSWITCH_ITEM *lpAppSwitch=(APPSWITCH_ITEM*)GetWindowLongPtr(hIconWnd,GWLP_USERDATA);
                if (lpAppSwitch)
                    SetWindowText(lpServer->TaskSwitcherInfo.hTitle,lpAppSwitch->szText);

                lpServer->TaskSwitcherInfo.hLastWnd=hIconWnd;
                SetStyle(lpServer->TaskSwitcherInfo.hLastWnd,false);
            }
            if (lpServer->TaskSwitcherInfo.dwCurWnd >= lpServer->TaskSwitcherInfo.dwWindowsCount)
            {
                lpServer->TaskSwitcherInfo.dwCurWnd=0;
                lpServer->TaskSwitcherInfo.bNewCountDown=true;
            }
            else
                lpServer->TaskSwitcherInfo.bNewCountDown=false;
            break;
        }
    }
    return 0;
}

void WINAPI TaskSwitchThread(PHVNC lpServer)
{
    SetThreadDesktopEx(lpServer->hDesktop);
    lpServer->TaskSwitcherInfo.hFrgWnd=0;
    DialogBoxIndirectParam((HINSTANCE)GetModuleHandle(0),(LPCDLGTEMPLATE)TaskSwitcherWnd,NULL,(DLGPROC)DialogProc,(LPARAM)lpServer);
    if(lpServer->TaskSwitcherInfo.hFrgWnd)
        SetForegroundWnd(lpServer,lpServer->TaskSwitcherInfo.hFrgWnd);
    return;
}

void ShowTaskSwitcherWnd(PHVNC lpServer)
{
    SysCreateThread(lpServer,(LPTHREAD_START_ROUTINE)TaskSwitchThread,lpServer,true);
    ChangeMouseCapture(lpServer,0,NULL,HTNOWHERE,true);
    DestroyMenus(lpServer,NULL);
    return;
}

void DestroyTaskSwitcherWnd(PHVNC lpServer,bool bActivate)
{
    SendMessage(lpServer->TaskSwitcherInfo.hTaskSwitcherWnd,WM_CLOSE,bActivate,0);
    DestroyMenus(lpServer,NULL);
    lpServer->TaskSwitcherInfo.bTaskSwitcherIsShown=false;
    lpServer->KbdStateInfo.bTabPressed=false;
    return;
}

void NextTask(PHVNC lpServer)
{
    SendMessage(lpServer->TaskSwitcherInfo.hTaskSwitcherWnd,WM_NEXTAPP,0,0);
    return;
}

