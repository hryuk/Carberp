#pragma once
#include "afxcmn.h"
#include "ClientDlg.h"


// CProcessDlg dialog

class CProcessDlg : public CDialog
{
	DECLARE_DYNAMIC(CProcessDlg)

public:
	CClient *m_pClient;
	CProcessDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~CProcessDlg();

// Dialog Data
	enum { IDD = IDD_PROCESS_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_ListCtrl;
	afx_msg void OnBnClickedOk();
	afx_msg void OnShowWindow(BOOL bShow, UINT nStatus);
	afx_msg LRESULT OnProcessListChanged( WPARAM wp, LPARAM lp );
	afx_msg void OnBnClickedKillproc();
	afx_msg void OnBnClickedKillIeFfOpera();
};
