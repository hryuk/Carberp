// ServerOptionsDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Server.h"
#include "ServerOptionsDlg.h"


// CServerOptionsDlg dialog

IMPLEMENT_DYNAMIC(CServerOptionsDlg, CDialog)

CServerOptionsDlg::CServerOptionsDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CServerOptionsDlg::IDD, pParent)
	, m_iPort(0)
{

}

CServerOptionsDlg::~CServerOptionsDlg()
{
}

void CServerOptionsDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_PORT_NUMBER, m_iPort);
	DDV_MinMaxInt(pDX, m_iPort, 1, 65535);
}


BEGIN_MESSAGE_MAP(CServerOptionsDlg, CDialog)
	ON_BN_CLICKED(IDCANCEL, &CServerOptionsDlg::OnBnClickedCancel)
END_MESSAGE_MAP()


// CServerOptionsDlg message handlers

void CServerOptionsDlg::OnBnClickedCancel()
{
	// TODO: Add your control notification handler code here
	OnCancel();
}
