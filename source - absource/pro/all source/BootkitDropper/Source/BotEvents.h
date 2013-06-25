	//---------------------------------------------------------------------------

/*
	В модуле собраны основные события, которые могут возникать в боте.

*/

#ifndef BotEventsH
#define BotEventsH

#include <windows.h>

// Данные события
typedef struct TEventData
{
    PCHAR Application;  // Приложение вызвавшее событие
	bool Cancel;        // Прервать дальнейшую обработку события

} *PEventData;


//reserved
typedef void (*TBotEvent)(PEventData);


// Первый запуск бота в проводнике
bool ExplorerFirstStart(PEventData Data);

// Запущен проводника
bool ExplorerStart(PEventData Data);

// Запущена функция работающая в процессе svchost
bool SVChostStart(PEventData Data, bool &Cancel);

// Запущен Internet Explorer. Возникает после инжекта в процесс браузера
bool InternetExplorerStarted(PEventData Data);

// Запущен АшкуАщч. Возникает после инжекта в процесс браузера
bool FireFoxStarted(PEventData Data);

// Запущен известный браузер. Возникает после инжекта в процесс браузера
bool BrowserStarted(PEventData Data);

// Запущено неизвестное приложение
void ApplicationStarted(PEventData Data);


//---------------------------------------------------------------------------
#endif
