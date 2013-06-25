// NameOfRunQuest.cpp : implementation file
//

#include "stdafx.h"
#include "Server.h"
#include "NameOfRunQuest.h"


// NameOfRunQuest dialog

IMPLEMENT_DYNAMIC(NameOfRunQuest, CDialog)

NameOfRunQuest::NameOfRunQuest(CWnd* pParent /*=NULL*/)
	: CDialog(NameOfRunQuest::IDD, pParent)
{

}

NameOfRunQuest::~NameOfRunQuest()
{
}

void NameOfRunQuest::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(NameOfRunQuest, CDialog)
	ON_BN_CLICKED(IDC_CHECK1, &NameOfRunQuest::OnBnClickedCheck1)
END_MESSAGE_MAP()


// NameOfRunQuest message handlers

void NameOfRunQuest::OnBnClickedCheck1()
{

	// TODO: Add your control notification handler code here
}
