// ServerDlg.h : header file
//

#pragma once
#include "Listener.h"
#include "afxwin.h"
#include "afxcmn.h"


// CServerDlg dialog
class CServerDlg : public CDialog
{
// Construction
public:
	CServerDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_SERVER_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support

	bool MatchFilter( const WCHAR *filter, const WCHAR *pName );

// Implementation
protected:
	HICON m_hIcon;
	auto_ptr<CListener> m_Listener;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void ResetListControl();
	DECLARE_MESSAGE_MAP()
public:
	//CListBox m_ClientList;
public:
	afx_msg LRESULT OnClientAdded( WPARAM wp, LPARAM lp );
	afx_msg LRESULT OnClientRemoved( WPARAM wp, LPARAM lp );
	afx_msg LRESULT OnClientChanged( WPARAM wp, LPARAM lp );
public:
	afx_msg void OnBnClickedOk();
public:
	afx_msg void OnBnClickedApplyFilter();
public:
	CEdit m_FilterString;
public:
	afx_msg void OnBnClickedResetFilter();
public:
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	CListCtrl m_ClientsList;
};
