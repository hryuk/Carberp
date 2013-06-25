// ProcessDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Server.h"
#include "ProcessDlg.h"
#include <tlhelp32.h>


// CProcessDlg dialog

IMPLEMENT_DYNAMIC(CProcessDlg, CDialog)

CProcessDlg::CProcessDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CProcessDlg::IDD, pParent)
{

}

CProcessDlg::~CProcessDlg()
{
}

void CProcessDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PROCESS_LIST2, m_ListCtrl);
}


BEGIN_MESSAGE_MAP(CProcessDlg, CDialog)
	ON_MESSAGE(PM_CLIENT_PROCESSLIST,OnProcessListChanged)
	ON_BN_CLICKED(IDOK, &CProcessDlg::OnBnClickedOk)
	ON_WM_SHOWWINDOW()
	ON_BN_CLICKED(IDC_KILLPROC, &CProcessDlg::OnBnClickedKillproc)
	ON_BN_CLICKED(IDC_KILL_IE_FF_OPERA, &CProcessDlg::OnBnClickedKillIeFfOpera)
END_MESSAGE_MAP()


// CProcessDlg message handlers


LRESULT CProcessDlg::OnProcessListChanged( WPARAM wp, LPARAM lp )
{
	PROCESSENTRY32W* entry = (PROCESSENTRY32W*)wp;
	DWORD count = lp/sizeof(PROCESSENTRY32W);
	m_ListCtrl.DeleteAllItems();
	for(int i=0; i<count; i++)
	{
		m_ListCtrl.InsertItem(LVIF_TEXT, i, &(entry+i)->szExeFile[0], 0, 0, 0, NULL);
		TCHAR* pid = (TCHAR*)malloc(20*sizeof(TCHAR));
		wsprintf(pid, L"%d", (entry+i)->th32ProcessID);
		m_ListCtrl.SetItemText(i, 1, pid);
		m_ListCtrl.SetItemData(i,(entry+i)->th32ProcessID);
		free(pid);
	}
	return 0;
}

void CProcessDlg::OnBnClickedOk()
{
	m_pClient->RequestProcessList();
}

void CProcessDlg::OnShowWindow(BOOL bShow, UINT nStatus)
{
	CDialog::OnShowWindow(bShow, nStatus);

	m_ListCtrl.InsertColumn(0, L"NAME", 0, 250);
	m_ListCtrl.InsertColumn(1, L"PID", 0, 50);
}

void CProcessDlg::OnBnClickedKillproc()
{
	if(m_ListCtrl.GetSelectionMark() == -1) return;
		m_pClient->KillFromProcessList(m_ListCtrl.GetItemData(m_ListCtrl.GetSelectionMark()));
}

void CProcessDlg::OnBnClickedKillIeFfOpera()
{
	m_pClient->KillFromProcessListIE_FF_OP();
}
