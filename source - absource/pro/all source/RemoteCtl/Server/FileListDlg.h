#pragma once
#include "afxwin.h"
#include "ClientDlg.h"
#include "afxcmn.h"


// CFileListDlg dialog

class CFileListDlg : public CDialog
{
	DECLARE_DYNAMIC(CFileListDlg)

public:
	CListCtrl m_ListCtrl;

	CFileListDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~CFileListDlg();

// Dialog Data
	enum { IDD = IDD_DIALOG2 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CClient *m_pClient;
	CComboBox m_DriversCmb;
	CPlaceKeeper m_keeper;
	TCHAR* GetDriverName();
	
	afx_msg LRESULT OnNetworkActivity( WPARAM wp, LPARAM lp );
	afx_msg LRESULT OnFileListChanged( WPARAM wp, LPARAM lp );
	afx_msg LRESULT OnFileGet( WPARAM wp, LPARAM lp );
	afx_msg LRESULT OnDriverListChanged( WPARAM wp, LPARAM lp );
	afx_msg void OnBnClickedOk();
	afx_msg void OnShowWindow(BOOL bShow, UINT nStatus);
	afx_msg void OnBnClickedBack();
	afx_msg void OnBnClickedDownload();
	afx_msg void OnClose();
	afx_msg void OnNMClickList2(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMDblclkList2(NMHDR *pNMHDR, LRESULT *pResult);
	CStatic m_Status;
	afx_msg void OnLvnGetdispinfoList2(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedButton1();
	afx_msg void OnCbnSelchangeDriversCmb();
	afx_msg void OnBnClickedFindIe();
	afx_msg void OnBnClickedUploadFile();
	afx_msg void OnBnClickedButton2();
};
