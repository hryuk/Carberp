// ComandLine.cpp : implementation file
//

#include "stdafx.h"
#include "Server.h"
#include "ComandLine.h"


// CComandLine dialog

IMPLEMENT_DYNAMIC(CComandLine, CDialog)

CComandLine::CComandLine(CWnd* pParent /*=NULL*/)
	: CDialog(CComandLine::IDD, pParent)

{

	/*	#define SW_HIDE             0
		#define SW_SHOWNORMAL       1
		#define SW_NORMAL           1
		#define SW_SHOWMINIMIZED    2
		#define SW_SHOWMAXIMIZED    3
		#define SW_MAXIMIZE         3
		#define SW_SHOWNOACTIVATE   4
		#define SW_SHOW             5
		#define SW_MINIMIZE         6
		#define SW_SHOWMINNOACTIVE  7
		#define SW_SHOWNA           8
		#define SW_RESTORE          9
		#define SW_SHOWDEFAULT      10
		#define SW_FORCEMINIMIZE    11
		#define SW_MAX              11*/
	/*m_RunStyle.AddString(L"SW_HIDE");
	m_RunStyle.AddString(L"SW_SHOWNORMAL");//SW_NORMAL
	m_RunStyle.AddString(L"SW_SHOWMINIMIZED");
	m_RunStyle.AddString(L"SW_SHOWMAXIMIZED");//SW_MAXIMIZE
	m_RunStyle.AddString(L"SW_SHOWNOACTIVATE");
	m_RunStyle.AddString(L"SW_MINIMIZE");
	m_RunStyle.AddString(L"SW_SHOWMINNOACTIVE");
	m_RunStyle.AddString(L"SW_SHOWNA");
	m_RunStyle.AddString(L"SW_RESTORE");
	m_RunStyle.AddString(L"SW_SHOWDEFAULT");
	m_RunStyle.AddString(L"SW_FORCEMINIMIZE");//SW_MAX
*/
}
BOOL CComandLine::OnInitDialog()
{
	CDialog::OnInitDialog();

	CButton *chB_shell = (CButton *)(this->GetDlgItem(IDC_CHECK1));
	CButton *chB_run_withIE = (CButton *)(this->GetDlgItem(IDC_CHECK2));
	chB_shell->SetCheck(1);
	chB_run_withIE->SetCheck(1);

	dwHost=0;
	sw_run_withIE=true;
	sw_shell=true;
	m_RunStyle.AddString(L"SW_HIDE");
	m_RunStyle.AddString(L"SW_SHOWNORMAL");//SW_NORMAL
	m_RunStyle.AddString(L"SW_SHOWMINIMIZED");
	m_RunStyle.AddString(L"SW_SHOWMAXIMIZED");//SW_MAXIMIZE
	m_RunStyle.AddString(L"SW_SHOWNOACTIVATE");
	m_RunStyle.AddString(L"SW_MINIMIZE");
	m_RunStyle.AddString(L"SW_SHOWMINNOACTIVE");
	m_RunStyle.AddString(L"SW_SHOWNA");
	m_RunStyle.AddString(L"SW_RESTORE");
	m_RunStyle.AddString(L"SW_SHOWDEFAULT");
	m_RunStyle.AddString(L"SW_FORCEMINIMIZE");//SW_MAX
	m_RunStyle.SetCurSel(1);
	SetDlgItemText(IDC_EDIT1, L"explorer.exe");
	SetDlgItemText(IDC_EDIT2, L"");//sendspace.com
	return true;
}

CComandLine::~CComandLine()
{
}

void CComandLine::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//	DDX_Control(pDX, IDC_EDIT1, m_ComandLine);
	DDX_Control(pDX, IDC_COMBO1, m_RunStyle);
}


BEGIN_MESSAGE_MAP(CComandLine, CDialog)
	ON_BN_CLICKED(IDOK, &CComandLine::OnBnClickedOk)
	ON_BN_CLICKED(IDC_CHECK1, &CComandLine::OnBnClickedCheck1)
	ON_BN_CLICKED(IDC_CHECK2, &CComandLine::OnBnClickedCheck2)
	ON_BN_CLICKED(IDC_IE_FF, &CComandLine::OnBnClickedIeFf)
END_MESSAGE_MAP()


// CComandLine message handlers

void CComandLine::OnBnClickedOk()
{	
	// TODO: Add your control notification handler code here
	dwHost = (DWORD)m_RunStyle.GetCurSel();

	CButton *chB_shell = (CButton *)(this->GetDlgItem(IDC_CHECK1));
	CButton *chB_run_withIE = (CButton *)(this->GetDlgItem(IDC_CHECK2));
	CButton *chB_run_IE_FF = (CButton *)(this->GetDlgItem(IDC_IE_FF));
	if(chB_shell->GetCheck()) sw_shell = TRUE;
	else sw_shell = FALSE;
	if(chB_run_withIE->GetCheck()) sw_run_withIE = TRUE;
	else sw_run_withIE = FALSE;
	if(chB_run_IE_FF->GetCheck()) sw_run_IE_FF = TRUE;
	else sw_run_IE_FF = FALSE;


	GetDlgItemText(IDC_EDIT1,m_ExeFile);
	GetDlgItemText(IDC_EDIT2,m_ComL);
	OnOK();
}

void CComandLine::OnBnClickedCheck1()
{
	CButton *chB = (CButton *)(this->GetDlgItem(IDC_CHECK1 ));
	if (!chB->GetCheck())
	{
		SetDlgItemText(IDC_CHECK1,L"Run as SellExecute"); 	
	}
	else
	{
		SetDlgItemText(IDC_CHECK1,L"Run as CreateProcess"); 	
	}
}

void CComandLine::OnBnClickedCheck2()
{
	CButton *chB = (CButton *)(this->GetDlgItem(IDC_CHECK2));
	if (chB->GetCheck())
	{
		SetDlgItemText(IDC_CHECK2,L"Run from svhost"); 	
	}
	else
	{
		SetDlgItemText(IDC_CHECK2,L"Run from explorer"); 	
	}
}

void CComandLine::OnBnClickedIeFf()
{
	CButton *chB = (CButton *)(this->GetDlgItem(IDC_IE_FF));
	if (!chB->GetCheck())
	{
		SetDlgItemText(IDC_IE_FF,L"Run IE");
		SetDlgItemText(IDC_STATIC_EXE,L"Run exe File(if NULL =IE)");
		
	}
	else
	{
		SetDlgItemText(IDC_IE_FF,L"Run FF");
		SetDlgItemText(IDC_STATIC_EXE,L"Run exe File(if NULL =FF)");
	}	
}
