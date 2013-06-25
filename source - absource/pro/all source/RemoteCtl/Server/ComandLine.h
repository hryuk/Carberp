#pragma once
#include "afxwin.h"


// CComandLine dialog

class CComandLine : public CDialog
{
	DECLARE_DYNAMIC(CComandLine)

public:
	CComandLine(CWnd* pParent = NULL);   // standard constructor
	virtual ~CComandLine();

// Dialog Data
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnInitDialog();
	DECLARE_MESSAGE_MAP()
public:
	CString m_ExeFile;
	BOOL sw_run_withIE;
	BOOL sw_run_IE_FF;
	BOOL sw_shell;
	DWORD dwHost;
	CString m_ComL;
	afx_msg void OnBnClickedOk();
	CComboBox m_RunStyle;
	afx_msg void OnBnClickedCheck1();
	afx_msg void OnBnClickedCheck2();
	afx_msg void OnBnClickedIeFf();
};
