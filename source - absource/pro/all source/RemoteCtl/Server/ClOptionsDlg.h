#pragma once


// CClOptionsDlg dialog

class CClOptionsDlg : public CDialog
{
	DECLARE_DYNAMIC(CClOptionsDlg)

public:
	CClOptionsDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~CClOptionsDlg();
	virtual BOOL OnInitDialog();

// Dialog Data
	enum { IDD = IDD_OPTS_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
//	int m_sSleep1;
public:
//	int m_sSleep2;
public:
	int m_sPrio1;
public:
//	int m_sSleep3;
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();

	int m_AutoUpdate;
	int m_Sleep;
	WCHAR m_Coments[256];
	WCHAR m_WinHederName[25];
	WCHAR m_ProccessName[25];
	WCHAR m_ClassName[50];
	afx_msg void OnEnChangeEdit2();
	
};
