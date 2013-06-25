#ifndef TASKSWITCHER_H_INCLUDED
#define TASKSWITCHER_H_INCLUDED

#define _WIN32_WINNT 0x0501
#include <shellapi.h>
#include <psapi.h>

#define TS_DEFAULT_WIDTH    278
#define TS_DEFAULT_HEIGHT   101

#define TS_ICON_FIRSTX      9
#define TS_ICON_FIRSTY      10
#define TS_ICON_WIDTH       35
#define TS_ICON_HEIGHT      39

#define TS_TEXT_X           9
#define TS_TEXT_Y           63
#define TS_TEXT_WIDTH       252
#define TS_TEXT_HEIGHT      20

#define TS_MAX_ICONS_X      (TS_TEXT_WIDTH-TS_ICON_FIRSTX)/TS_ICON_WIDTH

#define WND_TABSWITCH       1000
#define IDC_WNDNAME         1001

#define WM_NEXTAPP          WM_USER+0xDEAD

void ShowTaskSwitcherWnd(PHVNC lpServer);
void DestroyTaskSwitcherWnd(PHVNC lpServer,bool bActivate);
void NextTask(PHVNC lpServer);

struct APPSWITCH_ITEM
{
    HWND hWnd;
    HICON hIcon;
    TCHAR szText[1];
};

#endif // TASKSWITCHER_H_INCLUDED
