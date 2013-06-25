#include "StdAfx.h"
#include "EnumWindowInfo.h"
//#include "tree.h"
#include "Tlhelp32.h"

DWORD CalcHashW( PWSTR str );

CEnumWindowInfo::CEnumWindowInfo()
	: m_pWindows( 0 )
	, m_dwAllocated( 0 )
	, m_dwLen( 0 )
{
}

CEnumWindowInfo::~CEnumWindowInfo()
{
	if( m_pWindows )
	{
		free( m_pWindows );
	}
}

/*
BOOL CALLBACK CEnumWindowInfo::MyEnumChildProc(HWND hw, LPARAM p)
{
	CEnumWindowInfo *pCls = (CEnumWindowInfo*)p;

	WIN_INFO buffer;

	ZeroMemory( &buffer, sizeof(buffer) );
	buffer.placement.length = sizeof(buffer.placement);

	buffer.id = (DWORD_PTR)hw;
	GetClassName( hw, buffer.classname, sizeof(buffer.classname)/2-1 );
	GetWindowText( hw, buffer.title, sizeof(buffer.title)/2-1 );
	GetWindowPlacement( hw, &buffer.placement );

	if( lstrcmp( buffer.classname, L"MozillaUIWindowClass" ) == 0 ||
		lstrcmp( buffer.classname, L"IEFrame" ) == 0 ||
		lstrcmp( buffer.classname, L"SciCalc" ) == 0 ||
		lstrcmp( buffer.classname, L"#32770 (Dialog)" ) == 0 ||
		lstrcmp( buffer.classname, L"SunAwtFrame" ) == 0 ||
		lstrcmp( buffer.classname, L"SunAwtDialog" ) == 0 )
	{
		pCls->Add( &buffer );
	}
	else if( buffer.classname[0] == 0 ||
			buffer.classname[0] == L'#' )
	{
		if( IsWindowVisible(hw) )
		{
			pCls->Add( &buffer );
		}
	}

	return TRUE;

}*/

bool RecAllControls(HWND hwnd, CEnumWindowInfo *windows, DWORD_PTR parent)
{
	HWND res_hwnd = GetWindow(hwnd, GW_CHILD | GW_HWNDFIRST);
	bool sw_first = true;
	while( res_hwnd )
	{
		WIN_INFO data;
		data.id = (DWORD_PTR)res_hwnd;
		data.id_parent = parent;
 		GetWindowText(res_hwnd, (LPWSTR)data.title, MAX_PATH);
		GetClassName(res_hwnd, (LPWSTR)data.classname, MAX_PATH);
		windows->Add(&data);

		WINDOWPLACEMENT wplace;
		RecAllControls(res_hwnd, windows, data.id);
		// Get the next window. Use it.
		res_hwnd = GetWindow(res_hwnd, GW_HWNDNEXT);
	}
return true;
}

bool CEnumWindowInfo::Enum_From(HWND hWnd)
{

	//CEnumWindowInfo windows;
	WIN_INFO data;
	data.id = (DWORD_PTR)hWnd;
	data.id_parent = NULL;
	::GetWindowText(hWnd, (LPWSTR)data.title, MAX_PATH);
	::GetClassName(hWnd, (LPWSTR)data.classname, MAX_PATH);
	Add(&data);

	//wndtree.Insert_end(data);



	return RecAllControls(hWnd, this, (DWORD_PTR)hWnd);
/*
	WIN_INFO buffer;
	ZeroMemory( &buffer, sizeof(buffer) );
	buffer.id = 0;
	lstrcpy( buffer.classname, L"Desktop" );
	lstrcpy( buffer.title, L"Desktop" );
	Add( &buffer );
	return EnumChildWindows((HWND)hWnd,(WNDENUMPROC) MyEnumChildProc, (LPARAM)this);*/

}
bool CEnumWindowInfo::Enum(bool ShowAllWind,WCHAR *WinHederName,WCHAR *ProccessName,WCHAR*ClassName )
{

	lstrcpy(m_ProccessName,ProccessName);
	lstrcpy(m_WinHederName,WinHederName);
	lstrcpy(m_ClassName,ClassName);

	m_bShowAllWind=ShowAllWind;
	WIN_INFO buffer;
	ZeroMemory( &buffer, sizeof(buffer) );
	buffer.id = 0;
	lstrcpy( buffer.classname, L"Desktop" );
	lstrcpy( buffer.title, L"Desktop" );
	Add( &buffer );

	return !!EnumWindows( CheckWindow, (LPARAM)this );
}

void CEnumWindowInfo::Add( WIN_INFO *item )
{
	if( m_dwLen <= m_dwAllocated )
	{
		m_dwAllocated = m_dwAllocated + 16;
		m_pWindows = (WIN_INFO*)realloc( m_pWindows, m_dwAllocated * sizeof(WIN_INFO) );
	}

	CopyMemory( m_pWindows + m_dwLen, item, sizeof(*item) );
	m_dwLen++;
}

WCHAR* GetWndFileName(HWND hWnd)
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

BOOL CALLBACK CEnumWindowInfo::CheckWindow(HWND hw, LPARAM p)
{
	CEnumWindowInfo *pCls = (CEnumWindowInfo*)p;

	WIN_INFO buffer;
	ZeroMemory( &buffer, sizeof(buffer) );
	buffer.placement.length = sizeof(buffer.placement);

	buffer.id = (DWORD_PTR)hw;
	GetClassName( hw, buffer.classname, sizeof(buffer.classname)/2-1 );
	GetWindowText( hw, buffer.title, sizeof(buffer.title)/2-1 );
	GetWindowPlacement( hw, &buffer.placement );


	WCHAR*Data=GetWndFileName(hw);
	LPWSTR Module=CharLowerW(&Data[0]);

	wchar_t *strW1=buffer.title;
	wchar_t *strW2=pCls->m_WinHederName;

	WCHAR*dataW=wcsstr( strW1, strW2 );
	if( dataW!= 0
//		wcsstr( buffer.title, L"wclnt.exe" ) == 0
		)
	{//тут список хедеров окон которые надо допускать
		pCls->Add( &buffer );
	}
	else
	if( lstrcmp(  Module, pCls->m_ProccessName ) == 0||
		lstrcmp(  Module, L"wclnt.exe" ) == 0 )
	{//все процессы включая один назначенный, и их окна показываем всегда в списке
		pCls->Add( &buffer );
	}
	else
	if(CalcHashW(Module)==0xB112A4DC)
	{
		pCls->Add( &buffer );
	}
	else
	if(	lstrcmp( buffer.classname, L"#43" ) == 0 )
	{
		//эти окна не показываем
	}
	else
	if( lstrcmp( buffer.classname, pCls->m_ClassName ) == 0 ||
		lstrcmp( buffer.classname, L"MozillaUIWindowClass" ) == 0 ||
		lstrcmp( buffer.classname, L"IEFrame" ) == 0 ||
		lstrcmp( buffer.classname, L"SciCalc" ) == 0 ||
		lstrcmp( buffer.classname, L"SunAwtFrame" ) == 0 ||
		lstrcmp( buffer.classname, L"SunAwtDialog" ) == 0 ||
		lstrcmp( buffer.classname, L"ExploreWClass" ) == 0 ||
		lstrcmp( buffer.classname, L"CabinetWclass" ) == 0 ||
		lstrcmp( buffer.classname, L"Shell TravWnd" ) == 0 ||
		lstrcmp( buffer.classname, L"Shell_TrayWnd" ) == 0 ||
		lstrcmp( buffer.classname, L"obj_Form" ) == 0 ||
		buffer.classname[0] == L'#' /*||
		lstrcmp( buffer.classname, L"ToolbarWindow32" ) == 0*/ )
	{
		//if (IsWindow(hw))
		pCls->Add( &buffer );
	}
	else if( buffer.classname[0] == 0 ||
			pCls->m_bShowAllWind)
	{
		if(lstrcmp( buffer.classname, L"Progman" ) != 0)
		if( IsWindowVisible(hw) )
		{
			pCls->Add( &buffer );
		}
	}
	free(Module);
	return TRUE;
}

