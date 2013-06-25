#include "stdafx.h"
#include "funk.h"

bool IsJavaWindow(HWND hWnd)
{
	WCHAR classname[MAX_PATH];
	GetClassName(hWnd, &classname[0], 256);
	if(wcscmp(&classname[0], L"SunAwtFrame")  == 0 || 
	   wcscmp(&classname[0], L"SunAwtDialog") == 0 )
		return true;
	return false;
}


HANDLE WINAPI StartThread( LPVOID lpStartAddress, LPVOID param )
{
    DWORD lpThreadId; 
    return CreateThread( NULL, NULL, (LPTHREAD_START_ROUTINE)lpStartAddress, param, NULL, &lpThreadId );
}

bool SaveToFileW( LPCWSTR lpName, LPVOID lpBuffer, DWORD dwSize )
{
	HANDLE hFile = (HANDLE)CreateFileW( lpName, GENERIC_WRITE, FILE_SHARE_WRITE, 0, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, 0 );

	if ( hFile == INVALID_HANDLE_VALUE )
	{
		return false;
	}

	DWORD dwWritten = 0;
	WriteFile( hFile, lpBuffer, dwSize, &dwWritten, 0 );

	CloseHandle( hFile );

	return true;
}
bool FileCreateInFolder(int FlagFolderDest, WCHAR*Path,LPVOID Data,int count)
{
	WCHAR SysPath[MAX_PATH];
	SHGetFolderPathW(NULL, FlagFolderDest, NULL, SHGFP_TYPE_CURRENT, SysPath);
	lstrcatW( SysPath, L"\\" );
	lstrcatW( SysPath, Path );
	if (SaveToFileW( SysPath, Data, count ))
		return true;
	else
		return false;
}