// IPDialog.cpp : implementation file
//

#include "stdafx.h"
#include "Server.h"
#include "IPDialog.h"


// CIPDialog dialog

IMPLEMENT_DYNAMIC(CIPDialog, CDialog)

CIPDialog::CIPDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CIPDialog::IDD, pParent)
{
	memset(&IP[0], 0, 16*sizeof(WCHAR));
}

CIPDialog::~CIPDialog()
{
}

void CIPDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CIPDialog, CDialog)
	ON_BN_CLICKED(IDOK, &CIPDialog::OnBnClickedOk)
	ON_WM_SHOWWINDOW()
END_MESSAGE_MAP()


// CIPDialog message handlers

void CIPDialog::OnBnClickedOk()
{
	GetDlgItemTextW(IDC_IP, &IP[0], 16);
	OnOK();
}

void CIPDialog::OnShowWindow(BOOL bShow, UINT nStatus)
{
	CDialog::OnShowWindow(bShow, nStatus);

	SetDlgItemTextW(IDC_IP, L"95.168.173.155");
}
