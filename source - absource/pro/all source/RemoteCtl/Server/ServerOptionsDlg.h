#pragma once


// CServerOptionsDlg dialog

class CServerOptionsDlg : public CDialog
{
	DECLARE_DYNAMIC(CServerOptionsDlg)

public:
	CServerOptionsDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~CServerOptionsDlg();

// Dialog Data
	enum { IDD = IDD_SERVER_OPTIONS_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	int m_iPort;
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
};
