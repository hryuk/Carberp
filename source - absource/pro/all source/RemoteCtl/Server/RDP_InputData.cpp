// RDP_InputData.cpp : implementation file
//

#include "stdafx.h"
#include "Server.h"
#include "RDP_InputData.h"


// RDP_InputData dialog

IMPLEMENT_DYNAMIC(RDP_InputData, CDialog)

RDP_InputData::RDP_InputData(CWnd* pParent /*=NULL*/)
	: CDialog(RDP_InputData::IDD, pParent)
	, m_Port(0)
{

}

RDP_InputData::~RDP_InputData()
{
}

void RDP_InputData::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//DDX_Control(pDX, IDC_EDIT1, m_Port);
}


BEGIN_MESSAGE_MAP(RDP_InputData, CDialog)
	ON_EN_CHANGE(IDC_EDIT1, &RDP_InputData::OnEnChangeEdit1)
	ON_BN_CLICKED(IDOK, &RDP_InputData::OnBnClickedOk)
END_MESSAGE_MAP()


// RDP_InputData message handlers

void RDP_InputData::OnEnChangeEdit1()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}

void RDP_InputData::OnBnClickedOk()
{
	BOOL Uint;
	Port= GetDlgItemInt( IDC_EDIT1,&Uint,1);
//	UpdateData(true);
	
	// TODO: Add your control notification handler code here
	OnOK();
}
