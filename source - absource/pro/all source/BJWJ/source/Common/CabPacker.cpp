
#include "CabPacker.h"
#include "Strings.h"
#include "Utils.h"
#include <fdi.h>

//#ifdef RuBnkH

typedef struct 
{
	ERF erf;
	CCAB cab;
	HFCI hfci;
} CABDATA, *PCABDATA;


#include "GetApi.h"
#include "Memory.h"
#include "Strings.h"
#include "BotUtils.h"
#include "Utils.h"
#include "Unhook.h"
#include "Splice.h"
#include "Loader.h"
#include "Unhook.h"
#include "BotConfig.h"
#include "ntdll.h"



//cab packing

LPVOID DIAMONDAPI FN_FCIALLOC( ULONG cb )
{
	return MemAlloc( cb );
}

void DIAMONDAPI FN_FCIFREE( void HUGE *lpMem )
{
	if( lpMem )
	{
		MemFree( lpMem );
	}
}

INT_PTR DIAMONDAPI FN_FCIOPEN( char FAR *pszFile, int oflag, int pmode, int FAR *err, void FAR *pv )
{
	HANDLE hFile = NULL;

    DWORD dwDesiredAccess		= 0; 
    DWORD dwCreationDisposition = 0;

    UNREFERENCED_PARAMETER(pv);
    UNREFERENCED_PARAMETER(pmode);

    if ( oflag & _O_RDWR )
    {
        dwDesiredAccess = GENERIC_READ | GENERIC_WRITE;
    }
    else if ( oflag & _O_WRONLY )
    {
        dwDesiredAccess = GENERIC_WRITE;
    }
    else
    {
        dwDesiredAccess = GENERIC_READ;
    }

    if ( oflag & _O_CREAT )
    {
        dwCreationDisposition = CREATE_ALWAYS;
    }
    else
    {
        dwCreationDisposition = OPEN_EXISTING;
    }

    hFile = (HANDLE)pCreateFileA(pszFile, 
                        dwDesiredAccess,
                        FILE_SHARE_READ,
                        NULL,
                        dwCreationDisposition,
                        FILE_ATTRIBUTE_NORMAL,
                        NULL);

    if ( hFile == INVALID_HANDLE_VALUE )
    {
        *err = pGetLastError();
    }

    return (INT_PTR)hFile;
}

INT_PTR DIAMONDAPI FN_FDIOPEN( char FAR *pszFile, int oflag, int pmode )
{
	int err;
	return FN_FCIOPEN( pszFile, oflag, pmode, &err, 0 );
}

UINT DIAMONDAPI FN_FCIREAD( INT_PTR hf, void FAR *memory, UINT cb, int FAR *err, void FAR *pv)
{
	DWORD dwBytesRead = 0;

    UNREFERENCED_PARAMETER(pv);

    if( (BOOL)pReadFile((HANDLE)hf, memory, cb, &dwBytesRead, NULL) == FALSE )
    {
        dwBytesRead = (DWORD)-1;
        *err = pGetLastError();
    }
		 
    return dwBytesRead;
}

UINT DIAMONDAPI FN_FDIREAD( INT_PTR hf, void FAR *memory, UINT cb )
{
	int err;
	return FN_FCIREAD( hf, memory, cb, &err, 0 );
}

UINT DIAMONDAPI FN_FCIWRITE( INT_PTR hf, void FAR *memory, UINT cb, int FAR *err, void FAR *pv )
{
	DWORD dwBytesWritten = 0;

    UNREFERENCED_PARAMETER(pv);

    if ( (BOOL)pWriteFile( (HANDLE)hf, memory, cb, &dwBytesWritten, NULL) == FALSE )
    {
        dwBytesWritten = (DWORD)-1;
        *err = pGetLastError();
    }

    return dwBytesWritten;
}

UINT DIAMONDAPI FN_FDIWRITE( INT_PTR hf, void FAR *memory, UINT cb )
{
	int err;
	return FN_FCIWRITE( hf, memory, cb, &err, 0 );
}

int DIAMONDAPI FN_FCICLOSE( INT_PTR hf, int FAR *err, void FAR *pv )
{
	INT iResult = 0; 

    UNREFERENCED_PARAMETER(pv);
    
    if ( pCloseHandle((HANDLE)hf) == FALSE)
    {
        *err = pGetLastError();
        iResult = -1;
    }

    return iResult;
}

int DIAMONDAPI FN_FDICLOSE( INT_PTR hf )
{
	int err;
	return FN_FCICLOSE( hf, &err, 0 );
}

long DIAMONDAPI FN_FCISEEK( INT_PTR hf, long dist, int seektype, int FAR *err, void FAR *pv )
{
	INT iResult = 0;

    UNREFERENCED_PARAMETER(pv);

    iResult = (INT)pSetFilePointer((HANDLE)hf, dist, NULL, seektype);

    if ( iResult == -1 )
    {
        *err = pGetLastError();
    }

    return iResult;
}

long DIAMONDAPI FN_FDISEEK( INT_PTR hf, long dist, int seektype )
{
	int err;
	return FN_FCISEEK( hf, dist, seektype, &err, 0 );
}

int DIAMONDAPI FN_FCIDELETE( char FAR *pszFile, int FAR *err, void FAR *pv )
{
	INT iResult = 0;

    UNREFERENCED_PARAMETER(pv);

    if ( (BOOL)pDeleteFileA(pszFile) == FALSE)
    {
        *err = pGetLastError();
        iResult = -1;
    }

    return iResult;
}


long DIAMONDAPI FN_FCISTATUS( UINT typeStatus, ULONG  cb1, ULONG  cb2, void FAR *pv )
{
	return 0;
}

int DIAMONDAPI FN_FCIFILEPLACED( PCCAB pccab, char *pszFile, long  cbFile, BOOL  fContinuation, void FAR *pv )
{
	return 0;
}


INT_PTR DIAMONDAPI FN_FCIGETOPENINFO( char *pszName, USHORT *pdate, USHORT *ptime, USHORT *pattribs, int FAR *err, void FAR *pv )
{
	HANDLE hFile;
    FILETIME fileTime;
    BY_HANDLE_FILE_INFORMATION fileInfo;

    hFile = (HANDLE)FN_FCIOPEN(pszName, _O_RDONLY, 0, err, pv);

    if ( hFile != (HANDLE)-1 )
    {
        if( pGetFileInformationByHandle(hFile, &fileInfo) 
        &&  pFileTimeToLocalFileTime(&fileInfo.ftCreationTime, &fileTime)
        &&  pFileTimeToDosDateTime(&fileTime, pdate, ptime) )
        {
            *pattribs = (USHORT)fileInfo.dwFileAttributes;
            *pattribs &= ( _A_RDONLY | _A_HIDDEN | _A_SYSTEM | _A_ARCH );
        }
        else
        {
            FN_FCICLOSE((INT_PTR)hFile, err, pv);
            hFile = (HANDLE)-1;
        }
    }

    return (INT_PTR)hFile;
}


BOOL DIAMONDAPI FN_FCIGETTEMPFILE( char *pszTempName, int cbTempName, void FAR *pv )
{
	BOOL bSucceeded = FALSE;
    CHAR pszTempPath[MAX_PATH];

    UNREFERENCED_PARAMETER(pv);
    UNREFERENCED_PARAMETER(cbTempName);

    if( (DWORD)pGetTempPathA(MAX_PATH, pszTempPath) != 0 )
    {
        if( (DWORD)pGetTempFileNameA(pszTempPath, "CABINET", 0, pszTempName) != 0 )
        {
            bSucceeded = TRUE;
        }
    }

    return bSucceeded;
}

BOOL DIAMONDAPI FN_FCIGETNEXTCABINET(
	PCCAB  pccab,
	ULONG  cbPrevCab,
	void FAR *pv)
{
	return FALSE;
}




HCAB CreateCab( const char *szCabName )
{
	if (STRA::IsEmpty(szCabName))
		return NULL;

	PCABDATA pC = (PCABDATA)MemAlloc( sizeof( CABDATA ) );
	plstrcpyA( pC->cab.szCab, szCabName );
	pC->cab.cb = 0x7FFFFFFF;

	typedef HFCI (*PFCICreate )( PERF perf, PFNFCIFILEPLACED pfnfiledest, PFNFCIALLOC pfnalloc,
											 PFNFCIFREE pfnfree, PFNFCIOPEN pfnopen, PFNFCIREAD pfnread, PFNFCIWRITE pfnwrite,
											 PFNFCICLOSE pfnclose, PFNFCISEEK pfnseek, PFNFCIDELETE pfndelete, PFNFCIGETTEMPFILE pfnfcigtf,
											 PCCAB pccab, void FAR *pv );

	PFCICreate pFCICreate = (PFCICreate)GetProcAddressEx( NULL, 13, 0x6A3F5C7A );

	pC->hfci = pFCICreate(
		&(pC->erf),
		FN_FCIFILEPLACED, 
		FN_FCIALLOC,
		FN_FCIFREE,
		FN_FCIOPEN,
		FN_FCIREAD,
		FN_FCIWRITE,
		FN_FCICLOSE,
		FN_FCISEEK,
		FN_FCIDELETE,
		FN_FCIGETTEMPFILE,
		&(pC->cab),
		0 );

	if( pC->hfci == NULL )
	{
		MemFree( pC );
		return 0;
	}

	return pC;
}


bool AddFileToCab( HCAB handle, const char *szFileName, const char *szInternalName )
{
	if( handle == NULL )
		return false;

	if (STRA::IsEmpty(szInternalName))
		szInternalName = szFileName;

	CABDATA *pC = (CABDATA*)handle;

	typedef BOOL (*PFCIAddFile )( HFCI hfci, LPSTR pszSourceFile, LPSTR pszFileName, BOOL fExecute, PFNFCIGETNEXTCABINET GetNextCab,
								  PFNFCISTATUS pfnProgress, PFNFCIGETOPENINFO pfnOpenInfo, TCOMP typeCompress );

	PFCIAddFile pFCIAddFile = (PFCIAddFile)GetProcAddressEx( NULL, 13, 0xB497160 );

	if( pFCIAddFile( pC->hfci, (char*)szFileName, (char*)szInternalName, FALSE, FN_FCIGETNEXTCABINET, FN_FCISTATUS, FN_FCIGETOPENINFO, tcompTYPE_MSZIP ))
	{
		return true;
	}

	return false;
}



void CloseCab( HCAB handle )
{
	if( handle == NULL )
	{
		return;
	}

	CABDATA *pC = (CABDATA*)handle;

	typedef BOOL (*PFCIDestroy)( HFCI hfci );
	typedef BOOL (*FCIFlushCabinet)( HFCI hfci, BOOL fGetNextCab, PFNFCIGETNEXTCABINET GetNextCab, PFNFCISTATUS pfnProgress );

	PFCIDestroy pFCIDestroy			 = (PFCIDestroy)GetProcAddressEx( NULL, 13, 0x7D0FA4F5 );
	FCIFlushCabinet	pFCIFlushCabinet = (FCIFlushCabinet)GetProcAddressEx( NULL, 13, 0xC27267DA );


	pFCIFlushCabinet(
		pC->hfci,
		FALSE,
		FN_FCIGETNEXTCABINET,
		FN_FCISTATUS );

	pFCIDestroy( pC->hfci );

	MemFree( pC );
}


struct FILEENTRY
{
	char szName[MAX_PATH];
	char szIName[MAX_PATH];
	FILEENTRY *pNext;
};

void FreeList(
	FILEENTRY **ppFiles )
{
	while( *ppFiles )
	{
		FILEENTRY *toDelete = *ppFiles;
		*ppFiles = (*ppFiles)->pNext;

		MemFree( toDelete );
	}
}

void ScanFiles(
	const char *szDirName, const char *szInternalName,
	FILEENTRY **ppFiles )
{
	char findmask[MAX_PATH];
	m_memset( findmask, 0, MAX_PATH );

	plstrcpyA( findmask, szDirName );
	plstrcatA( findmask, "\\*.*" );

	WIN32_FIND_DATA fdata;
	m_memset( &fdata, 0, sizeof( WIN32_FIND_DATA ) );

	HANDLE hFind = pFindFirstFileA( findmask, &fdata );
	if( hFind != INVALID_HANDLE_VALUE )
	{
		do
		{
			if( fdata.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY )
			{
				if( plstrcmpA(fdata.cFileName,".") != 0 &&
					plstrcmpA(fdata.cFileName,"..") != 0 )
				{
					char findmask2[MAX_PATH];
					m_memset( findmask2, 0, MAX_PATH );

					plstrcpyA( findmask2, szDirName );
					plstrcatA( findmask2, "\\" );
					plstrcatA( findmask2, fdata.cFileName );

					char findmask3[MAX_PATH];
					m_memset( findmask3, 0, MAX_PATH );

					plstrcpyA( findmask3, szInternalName );
					plstrcatA( findmask3, "\\" );
					plstrcatA( findmask3, fdata.cFileName );

					ScanFiles( findmask2, findmask3, ppFiles );
				}
			}
			else
			{
				char fullname[MAX_PATH];
				m_memset( fullname, 0, MAX_PATH );

				plstrcpyA( fullname, szDirName );
				plstrcatA( fullname, "\\" );
				plstrcatA( fullname, fdata.cFileName );

				char iname[MAX_PATH];
				m_memset( iname, 0, MAX_PATH );

				plstrcpyA( iname, szInternalName );
				plstrcatA( iname, "\\" );
				plstrcatA( iname, fdata.cFileName );

				if( *ppFiles == NULL )
				{
					*ppFiles = (FILEENTRY*)MemAlloc( sizeof( FILEENTRY ) );
					(*ppFiles)->pNext = 0;
				}
				else
				{
					FILEENTRY *p = (FILEENTRY*)MemAlloc( sizeof( FILEENTRY ) );
					p->pNext = *ppFiles;
					*ppFiles = p;
				}

				plstrcpyA( (*ppFiles)->szName, fullname );
				plstrcpyA( (*ppFiles)->szIName, iname );
			}
		}
		while( pFindNextFileA( hFind, &fdata ) );

		pFindClose( hFind );
	}
}

bool AddDirToCab( HCAB handle, const char *szDirName, const char *szInternalName )
{
	FILEENTRY *pFiles = 0;
	ScanFiles( szDirName, szInternalName, &pFiles );

	bool Result = false;
	if( pFiles )
	{
		for( FILEENTRY *p = pFiles; p != NULL; p=p->pNext )
		{			
			if(AddFileToCab( handle, p->szName, p->szIName))
				Result = true;
			else
			{
				FreeList( &pFiles );
				return false;
			}		
		}
	}

	FreeList( &pFiles );
	return Result;
}


bool AddBlobToCab(HCAB Handle, LPVOID Data, DWORD DataSize, PCHAR InternalName)
{
	// Функция добавляет данные из памяти в каб архив
	if (Handle == NULL || Data == NULL) return false;

	// Записываем данные во временный файл
	PCHAR FileName = File::GetTempNameA();

	File::WriteBufferA(FileName, Data, DataSize);

	// Добавляем файл в архив
	bool Result = AddFileToCab(Handle, FileName, InternalName);

    // Удаляем временный файл
    pDeleteFileA(FileName);

	STR::Free(FileName);

	return Result;
}

typedef	HFDI ( DIAMONDAPI *typeFDICreate )( PFNALLOC pfnalloc,PFNFREE pfnfree,PFNOPEN pfnopen,PFNREAD pfnread,PFNWRITE pfnwrite,PFNCLOSE pfnclose,PFNSEEK pfnseek,int cpuType,PERF perf );
typedef BOOL ( DIAMONDAPI *typeFDIIsCabinet )( HFDI hfdi,INT_PTR hf,PFDICABINETINFO pfdici );
typedef BOOL ( DIAMONDAPI *typeFDICopy )( HFDI hfdi,char *pszCabinet,char *pszCabPath,int flags,PFNFDINOTIFY pfnfdin,PFNFDIDECRYPT pfnfdid,void *pvUser );
typedef BOOL ( DIAMONDAPI *typeFDIDestroy )( HFDI hfdi );

struct ExtractInfo
{
	const char* path;
	const char** renames;
};

static INT_PTR DIAMONDAPI ExtractCabNotify( FDINOTIFICATIONTYPE fdint, PFDINOTIFICATION pfdin )
{
	INT_PTR ret = 0;
	char nameFile[MAX_PATH], folder[MAX_PATH];
	ExtractInfo* ei = (ExtractInfo*)pfdin->pv;
	switch( fdint )
	{
		case fdintCABINET_INFO:
			break;
		case fdintPARTIAL_FILE:
			break;
		case fdintCOPY_FILE:
			{
				const char* nf = pfdin->psz1;
				int i = 0;
				if( ei->renames ) //ищем нужно ли файл переименовывать
					while( ei->renames[i] )
					{
						if( StrSame( (char*)nf, (char*)ei->renames[i], false ) )
						{
							nf = ei->renames[i + 1];
							break;
						}
						i += 2;
					}
				if( nf == 0 ) //файл не нужно распаковывать
					ret = 0;
				else
				{
					pPathCombineA( nameFile, ei->path, nf );
					plstrcpyA( folder, nameFile );
					//создаем папку, если таковой нет
					pPathRemoveFileSpecA(folder);
					pSHCreateDirectoryExA( 0, folder, 0 );
					ret = FN_FDIOPEN( nameFile, _O_CREAT | _O_WRONLY, 0 );
					if( ret == (INT_PTR)INVALID_HANDLE_VALUE ) ret = 0;
				}
			}
			break;
		case fdintCLOSE_FILE_INFO:
			FN_FDICLOSE( pfdin->hf );
			ret = TRUE;
			break;
		case fdintNEXT_CABINET:
			break;
		case fdintENUMERATE:
			break;	
	}
	return ret;
}

bool ExtractCab( const char* nameCab, const char* path, const char** renames )
{
	bool ret = false;
	//HMODULE cabinet = LoadLibrary( "cabinet.dll" );
	//if( cabinet == 0 ) return false;
	//typeFDICreate FDICreate = (typeFDICreate)GetProcAddress( cabinet, "FDICreate" );
	typeFDICreate FDICreate = (typeFDICreate)GetProcAddressEx( 0, DLL_CABINET, 0x6A315C7A );
	//typeFDIIsCabinet FDIIsCabinet = (typeFDIIsCabinet)GetProcAddress( cabinet, "FDIIsCabinet" );
	typeFDIIsCabinet FDIIsCabinet = (typeFDIIsCabinet)GetProcAddressEx( 0, DLL_CABINET, 0xE4D46CDE );
	//typeFDICopy FDICopy = (typeFDICopy)GetProcAddress( cabinet, "FDICopy" );
	typeFDICopy FDICopy = (typeFDICopy)GetProcAddressEx( 0, DLL_CABINET, 0x987AE25D );
	//typeFDIDestroy FDIDestroy = (typeFDIDestroy)GetProcAddress( cabinet, "FDIDestroy" );
	typeFDIDestroy FDIDestroy = (typeFDIDestroy)GetProcAddressEx( 0, DLL_CABINET, 0x7A0FA4F5 );

	ERF erf;
	HFDI hfdi = FDICreate( FN_FCIALLOC, FN_FCIFREE, FN_FDIOPEN,	FN_FDIREAD,	FN_FDIWRITE, FN_FDICLOSE, FN_FDISEEK, 1, &erf );
	int err = 0;
	INT_PTR file = FN_FCIOPEN( (char*)nameCab, _O_RDONLY, 0, &err, 0 );
	FDICABINETINFO cabInfo;
	BOOL isCab = FDIIsCabinet( hfdi, file, &cabInfo );
	FN_FDICLOSE(file);
	if( isCab )
	{
		char pathCab[MAX_PATH];
		m_lstrcpy( pathCab, nameCab );
		pPathRemoveFileSpecA(pathCab);
		char* nameFile = (char*)pPathFindFileNameA(nameCab);
		//в pathCab обязательно должен стоять '\'
		int l = m_lstrlen(pathCab);
		pathCab[l] = '\\';
		pathCab[l+1] = 0;
		ExtractInfo ei;
		ei.path = path;
		ei.renames = renames;
		FDICopy( hfdi, nameFile, pathCab, 0, ExtractCabNotify, 0, (void*)&ei );
		FDIDestroy(hfdi);
		ret = true;
	}
	//FreeLibrary(cabinet);
	return ret;
}


//void Test()
//{
//	HCAB h = CreateCab( "h:\\my.cab" );
//	AddDirToCab( h, "H:\\Folder", "Folder" );
//	CloseCab( h );
//
//	return;
//}

//#endif