#pragma once

#include "Listener.h"
#include "afxwin.h"
// CKeysDialog dialog

class CKeysDialog : public CDialog
{
	DECLARE_DYNAMIC(CKeysDialog)

public:
	CKeysDialog(CWnd* pParent = NULL);   // standard constructor
	virtual ~CKeysDialog();

// Dialog Data
	enum { IDD = IDD_KEYS_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CClient *m_pClientTmp;
	DWORD_PTR id;
	POINT iCord;
	CString m_String;
public:
	BOOL m_bEnter;
public:
	BOOL m_bCtrlA;
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedCancel();
	afx_msg void OnBnClickedButton4();
	CButton m_updateWindow;
	CButton m_IsSend;
	CComboBox m_JavaFields;
	CComboBox m_JavaValues;
	afx_msg void OnShowWindow(BOOL bShow, UINT nStatus);
	afx_msg void OnCbnSelchangeJavafields();
	afx_msg void OnCbnSelchangeJavavalues();
	void LoadINI(WCHAR* filename);
	afx_msg void OnBnClickedPaymentOrderNo();
};
