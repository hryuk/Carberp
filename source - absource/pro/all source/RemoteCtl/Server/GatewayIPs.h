#pragma once
#include "afxcmn.h"


// CGatewayIPs dialog

#include"../common/protocol.h"
#include "Listener.h"

class CGatewayIPs : public CDialog
{
	DECLARE_DYNAMIC(CGatewayIPs)

public:
	CGatewayIPs(CWnd* pParent = NULL);   // standard constructor
	virtual ~CGatewayIPs();

// Dialog Data
	enum { IDD = IDD_GATEWAY_IPS_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_GatewayList;
	CClient *m_pClient;

	afx_msg void OnBnClickedOk();
	afx_msg void OnShowWindow(BOOL bShow, UINT nStatus);
	afx_msg LRESULT OnGatewayIPsChanged( WPARAM wp, LPARAM lp );
	afx_msg void OnNMClickGateways(NMHDR *pNMHDR, LRESULT *pResult);
};
