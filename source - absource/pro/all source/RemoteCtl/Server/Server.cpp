// Server.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "Server.h"
#include "ServerDlg.h"
#include "ClientViewCtrl.h"
#include "ServerOptionsDlg.h"
#include "../common/protocol.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CServerApp

BEGIN_MESSAGE_MAP(CServerApp, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()


// CServerApp construction

CServerApp::CServerApp()
	: m_iServerPort( DEFAULT_SERVER_PORT )
{
}


CServerApp theApp;


BOOL CServerApp::InitInstance()
{
    GdiplusStartupInput input;
    GdiplusStartupOutput output;
    ULONG dwToken = 0;
	if( GdiplusStartup( &dwToken, &input, &output ) != Gdiplus::Ok )
	{
		MessageBox( 0,
			L"Failed to initialize GDI+",
			L"Error",
			MB_OK|MB_ICONERROR );
		return FALSE;
	}

	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);

	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinApp::InitInstance();

	if (!AfxSocketInit())
	{
		AfxMessageBox(IDP_SOCKETS_INIT_FAILED);
		return FALSE;
	}

	AfxEnableControlContainer();

	SetRegistryKey(_T("Local AppWizard-Generated Applications"));

	CServerOptionsDlg opts;
	opts.m_iPort = m_iServerPort;
	if( opts.DoModal() == IDOK )
	{
		m_iServerPort = opts.m_iPort;

		CServerDlg dlg;
		m_pMainWnd = &dlg;
		dlg.DoModal();
	}

	return FALSE;
}
