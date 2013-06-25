#pragma once

DWORD Crypt( char* lpPassword, LPBYTE lpResult, DWORD dwSize );
LPVOID DownloadPlugin( char *Url, DWORD *dwLen );
bool DownloadInMem( char *Url, LPBYTE *lpMem, LPDWORD dwSize );
