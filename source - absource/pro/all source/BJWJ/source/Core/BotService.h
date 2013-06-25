
//---------------------------------------------------------------------------
//  Модуль обеспечивает работу бота как сервиса
//
//
//  Версия:        1.0
//  Модифицирован: Октябрь 2012
//---------------------------------------------------------------------------

#ifndef BotServiceH
#define BotServiceH
//---------------------------------------------------------------------------



#include "Windows.h"
#include "GetApi.h"
#include "strings.h"

class TService: public TBotObject
{
private:
	SC_HANDLE FManager;
	SC_HANDLE FService;
public:
	string Name;        // Имя сервиса
	string DisplayName; // Отображаемое имя сервиса
	DWORD  OpenFlags;   // Флаги открытия скрвиса
	TService();
	~TService();

	bool Install(const char* ExeName); // Функция инсталирует сервис в системе
	bool Uninstall(); // Функция деинсталирует сервис
	bool Open();   // Функция открывает сервис с именем Name
    void Close();  // Функция закрывает сервис

	bool Start();  // Функция запускает сервис
	bool Stop(DWORD Timeout = 2000);   // Функция останавливает сервис

	SC_HANDLE inline Manager() { return FManager; }
	SC_HANDLE inline Service() { return FService; }
};



#define BOT_SERVICE_TYPE SERVICE_WIN32_OWN_PROCESS





//---------------------------------------------------------------------------
#endif
