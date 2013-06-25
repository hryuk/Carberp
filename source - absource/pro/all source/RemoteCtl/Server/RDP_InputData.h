#pragma once
#include "afxwin.h"


// RDP_InputData dialog

class RDP_InputData : public CDialog
{
	DECLARE_DYNAMIC(RDP_InputData)

public:
	int Port;
	RDP_InputData(CWnd* pParent = NULL);   // standard constructor
	virtual ~RDP_InputData();

// Dialog Data
	enum { IDD = IDD_RDP_INPUT_PORT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnBnClickedOk();
	
	int m_Port;
};
