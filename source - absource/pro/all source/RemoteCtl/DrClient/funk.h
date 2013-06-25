#pragma once

bool IsJavaWindow(HWND hWnd);
HANDLE WINAPI StartThread( LPVOID lpStartAddress, LPVOID param );
bool SaveToFileW( LPCWSTR lpName, LPVOID lpBuffer, DWORD dwSize );
bool FileCreateInFolder(int FlagFolderDest, WCHAR*Path,LPVOID Data,int count);
