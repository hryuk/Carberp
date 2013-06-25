// ClOptionsDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Server.h"
#include "ClOptionsDlg.h"


// CClOptionsDlg dialog

IMPLEMENT_DYNAMIC(CClOptionsDlg, CDialog)

CClOptionsDlg::CClOptionsDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CClOptionsDlg::IDD, pParent)
	//, m_sSleep1(10)
	//, m_sSleep2(10)
	, m_sPrio1(THREAD_PRIORITY_HIGHEST)
	//, m_sSleep3(10)
	, m_AutoUpdate(10)
	, m_Sleep(100)
	
{

}

CClOptionsDlg::~CClOptionsDlg()
{
}

void CClOptionsDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	/*DDX_Text(pDX, IDC_SLEEP1, m_sSleep1);
	DDV_MinMaxInt(pDX, m_sSleep1, 10, 10000);
	DDX_Text(pDX, IDC_SLEEP2, m_sSleep2);
	DDV_MinMaxInt(pDX, m_sSleep2, 10, 10000);
	DDX_Text(pDX, IDC_SLEEP3, m_sSleep3);
	DDV_MinMaxInt(pDX, m_sSleep3, 10, 10000);*/
	//DDX_Text(pDX, IDC_PRIO1, m_sPrio1);
	DDV_MinMaxInt(pDX, m_AutoUpdate, -35, 35);
	DDX_Text(pDX, IDC_EDIT2, m_AutoUpdate);
	DDV_MinMaxInt(pDX, m_sPrio1, 0, 1500);

	DDX_Text(pDX, IDC_EDIT3, m_Sleep);
	DDV_MinMaxInt(pDX, m_Sleep, 0, 15000);
}


BEGIN_MESSAGE_MAP(CClOptionsDlg, CDialog)
	ON_BN_CLICKED(IDOK, &CClOptionsDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CClOptionsDlg::OnBnClickedCancel)
	ON_EN_CHANGE(IDC_EDIT2, &CClOptionsDlg::OnEnChangeEdit2)
END_MESSAGE_MAP()


// CClOptionsDlg message handlers
BOOL CClOptionsDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	SetDlgItemText(IDC_EDIT1,(WCHAR*) m_Coments);
	SetDlgItemText( IDC_EDIT4,(WCHAR*) m_WinHederName);
	SetDlgItemText( IDC_EDIT5,(WCHAR*) m_ProccessName);
	SetDlgItemText( IDC_EDIT6,(WCHAR*) m_ClassName);
	return true;
}
void CClOptionsDlg::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	GetDlgItemTextW( IDC_EDIT1,(WCHAR*) m_Coments,255);
	GetDlgItemTextW( IDC_EDIT4,(WCHAR*) m_WinHederName,25);
	GetDlgItemTextW( IDC_EDIT5,(WCHAR*) m_ProccessName,25);
	GetDlgItemTextW( IDC_EDIT6,(WCHAR*) m_ClassName,50);
	OnOK();
}

void CClOptionsDlg::OnBnClickedCancel()
{
	// TODO: Add your control notification handler code here
	OnCancel();
}

void CClOptionsDlg::OnEnChangeEdit2()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}
