// ServerDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Server.h"
#include "ServerDlg.h"
#include "ClientDlg.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()


// CServerDlg dialog




CServerDlg::CServerDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CServerDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CServerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//DDX_Control(pDX, IDC_CLIENTS, m_ClientList);
	DDX_Control(pDX, IDC_FILTER, m_FilterString);
	DDX_Control(pDX, IDC_KLIENT, m_ClientsList);
}

BEGIN_MESSAGE_MAP(CServerDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_MESSAGE(PM_CLIENT_ADDED,OnClientAdded)
	ON_MESSAGE(PM_CLIENT_REMOVED,OnClientRemoved)
	ON_MESSAGE(PM_CLIENT_CHANGED,OnClientChanged)
	ON_BN_CLICKED(IDOK, &CServerDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_APPLY_FILTER, &CServerDlg::OnBnClickedApplyFilter)
	ON_BN_CLICKED(IDC_RESET_FILTER, &CServerDlg::OnBnClickedResetFilter)
	ON_WM_TIMER()
END_MESSAGE_MAP()


bool CServerDlg::MatchFilter( const WCHAR *filter, const WCHAR *pName )
{
	if( filter[0] )
	{
		return (_tcsstr(pName, filter) != 0);
	}
	return true;
}

// CServerDlg message handlers

BOOL CServerDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	m_Listener.reset( new CListener(theApp.m_iServerPort,m_hWnd) );

	SetTimer( 99, 5*60000, 0 );
	OnTimer( 99 );

	int counter = 0;
	UINT state = 0;	
	
	m_ClientsList.InsertColumn(0, L"DATA", 0, 500);
	m_ClientsList.InsertColumn(1, L"COMENT", 0, 325);

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CServerDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CServerDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CServerDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


/*
void CServerDlg::OnBnClickedRefresh()
{
	m_ClientList.ResetContent();
	CClient *p = m_Listener->ClientEnum_First();
	if( p )
	{
		do
		{
			TCHAR buf[2048] = L"";
			p->GetListName( buf );
			int iItem = m_ClientList.InsertString( 0, buf );
			m_ClientList.SetItemData( iItem, (DWORD_PTR)p );
		}
		while( p=m_Listener->ClientEnum_Next() );
		m_Listener->ClientEnum_End();
	}
}
*/

LRESULT CServerDlg::OnClientAdded( WPARAM wp, LPARAM lp )
{
	CString sFilter;
	m_FilterString.GetWindowText( sFilter );

	TCHAR buf[2048] = L"";
	TCHAR buf1[1024] = L"";
	((CClient*)lp)->GetListName( buf,buf1 );
	if( MatchFilter( sFilter, buf ) )
	{
	//	int iItem = m_ClientList.InsertString( 0, buf );
	//	m_ClientList.SetItemData( iItem, lp );
		int ind2 = m_ClientsList.InsertItem(LVIF_IMAGE | LVIF_TEXT | LVIF_STATE, 0, buf, 0, 0, 0, NULL);
		m_ClientsList.SetItemData( ind2, lp );
	}
	return 0;
}

LRESULT CServerDlg::OnClientRemoved( WPARAM wp, LPARAM lp )
{
	int i=m_ClientsList.GetItemCount();
	while( i-- )
	{
		if( m_ClientsList.GetItemData(i) == lp )
		{
		//	m_ClientList.DeleteString(i);
			m_ClientsList.DeleteItem(i);
			break;
		}
	}
	return 0;
}

LRESULT CServerDlg::OnClientChanged( WPARAM wp, LPARAM lp )
{
	CString sFilter;
	m_FilterString.GetWindowText( sFilter );

	int i=m_ClientsList.GetItemCount();
	while( i-- )
	{
		if( m_ClientsList.GetItemData(i) == lp )
		{
			TCHAR buf[2048] = L"";
			TCHAR Coment[256] = L"";
			((CClient*)lp)->GetListName( buf,Coment );
			//m_ClientList.DeleteString( i );
			m_ClientsList.DeleteItem( i );
			if( MatchFilter( sFilter, buf ) )
			{
			//	int iItem = m_ClientList.InsertString( i, buf );
			//	m_ClientList.SetItemData( iItem, lp );
				
				int ind2 = m_ClientsList.InsertItem(LVIF_IMAGE | LVIF_TEXT | LVIF_STATE, 0, buf, 0, 0, 0, NULL);
				m_ClientsList.SetItemData(ind2, lp );
				m_ClientsList.SetItemText(ind2, 0,buf);
				m_ClientsList.SetItemText(ind2, 1,Coment);
				m_ClientsList.UpdateData(true);
			}
			break;
		}
	}
	return 0;
}


void CServerDlg::OnBnClickedOk()
{
	int iItem = m_ClientsList.GetSelectionMark();
	if( iItem >= 0 )
	{
		CClient *pCli = m_Listener->VerifyAndLockClient( m_ClientsList.GetItemData(iItem) );
		if( pCli )
		{
			CClientDlg *pDlg = new CClientDlg();
			pDlg->m_pClient = pCli;
			pDlg->m_pListener = m_Listener.get();
			pDlg->m_ParentHWND=m_hWnd;

			pDlg->Create( CClientDlg::IDD, 0 );
						
			CString s;
			s=m_ClientsList.GetItemText( iItem, 1 );
			pDlg->SetWindowText( s );

			pDlg->ShowWindow( SW_MAXIMIZE );
			pDlg->UpdateWindow( );
		}
		else
		{
			MessageBox( L"Client disconnected (or already opened)!", 0, MB_ICONERROR|MB_OK );
		}
	}
	else
	{
		MessageBox( L"Client not selected!", 0, MB_ICONERROR|MB_OK );
	}
}
void CServerDlg::ResetListControl()
{
    m_ClientsList.DeleteAllItems();
    int iNbrOfColumns;
    CHeaderCtrl* pHeader = (CHeaderCtrl*)m_ClientsList.GetDlgItem(0);
    if (pHeader)
    {
		iNbrOfColumns = pHeader->GetItemCount();
    }
    for (int i = iNbrOfColumns; i >= 0; i--)
    {
		m_ClientsList.DeleteColumn(i);
    }
}

void CServerDlg::OnBnClickedApplyFilter()
{
	CString sFilter;
	m_FilterString.GetWindowText( sFilter );
	m_ClientsList.DeleteAllItems();
//	ResetListControl();
//	m_ClientList.ResetContent();
	CClient *p = m_Listener->ClientEnum_First();
	if( p )
	{
		do
		{
			TCHAR buf[2048] = L"";
			TCHAR pComent[256] = L"";
			p->GetListName( buf,pComent );
			if( MatchFilter( sFilter, buf ) )
			{
				int iItem = m_ClientsList.InsertItem(LVIF_IMAGE | LVIF_TEXT | LVIF_STATE, 0, buf, 0, 0, 0, NULL); //( 0, buf );
				m_ClientsList.SetItemText(iItem, 0, buf);
				//m_ClientsList.SetItemText(iItem, 0, buf);
				m_ClientsList.SetItemData( iItem, (DWORD_PTR)p );
			}
		}
		while( p=m_Listener->ClientEnum_Next() );
		m_Listener->ClientEnum_End();
	}
}

void CServerDlg::OnBnClickedResetFilter()
{
	m_FilterString.SetWindowText(L"");
	OnBnClickedApplyFilter();
}


extern bool OnlineAccess(
	char *Server, int Port,
	char *Key );

void CServerDlg::OnTimer(UINT_PTR nIDEvent)
{
	
	if( nIDEvent == 99 )
	{
//		if( !OnlineAccess( "188.72.213.145", 900, "wrt4lx08vb7lw02wUCU" ) )	
//		if( !OnlineAccess( "188.72.213.145", 900, "gleQnDlNUleVt1h8fuC" ) )
//		if( !OnlineAccess( "188.72.213.145", 900, "vctr0xuHrt2irBg3C825" ) )
//		if( !OnlineAccess( "188.72.213.145", 900, "psihrpCTkT20BLv3niDZ" ) )
//		if( !OnlineAccess( "188.72.213.145", 900, "name3xBBkXBJltWAdV84" ) )
//		if( !OnlineAccess( "188.72.213.145", 900, "hldrNZdffCIGc1btgQnF" ) )
//		if( !OnlineAccess( "188.72.213.145", 900, "ara2XR9umSxwP2AXAd2" ) )
//		if( !OnlineAccess( "188.72.213.145", 900, "song8U8F7rjAeLuPZeIV" ) )
//		if( !OnlineAccess( "188.72.213.145", 900, "--------------protect-----sb------------server----------" ) )	
//		{
//			MessageBox( L"Server expired!" );
//			TerminateProcess( GetCurrentProcess(), 0 );
//		}
		
	}
	
}
