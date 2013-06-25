#pragma once


// CIPDialog dialog

class CIPDialog : public CDialog
{
	DECLARE_DYNAMIC(CIPDialog)

public:
	CIPDialog(CWnd* pParent = NULL);   // standard constructor
	virtual ~CIPDialog();

// Dialog Data
	enum { IDD = IDD_IP_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	WCHAR IP[16];
	afx_msg void OnShowWindow(BOOL bShow, UINT nStatus);
};
