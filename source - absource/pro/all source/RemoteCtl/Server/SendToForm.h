#pragma once
#include "afxwin.h"
#include"../common/protocol.h"
#include "Listener.h"
#include "afxcmn.h"

// SendToForm dialog

class SendToForm : public CDialog
{
	DECLARE_DYNAMIC(SendToForm)

public:
	SendToForm(CWnd* pParent = NULL);   // standard constructor
	virtual ~SendToForm();

// Dialog Data
	enum { IDD = IDD_DIALOG_SEND_TO_FORM };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	int iCurItems;
	CClient *m_pClientTmp;
	DWORD_PTR id_CurItem;
	

	void TreeOutput2(list<WIN_INFO>::iterator I, CTreeCtrl *m_Tree);
	HWND OnInit(list<WIN_INFO> _info);
	list<WIN_INFO> info;
	afx_msg LRESULT OnLoadControl( WPARAM wp, LPARAM lp );
	afx_msg void OnBnClickedOk();
	CListBox m_ControlName;
	afx_msg void OnBnClickedButton5();
	CEdit m_str;
	CButton n_bEnter;
	CButton n_b10errase;
	CString m_str1;
	afx_msg void OnBnClickedButton6();
	int m_Count;
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton7();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton8();
	CTreeCtrl m_Tree;
};
