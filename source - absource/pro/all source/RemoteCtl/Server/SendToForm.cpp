// SendToForm.cpp : implementation file
//

#include "stdafx.h"
#include "Server.h"
#include "SendToForm.h"
#include "Listener.h"
#include <map>



// SendToForm dialog

IMPLEMENT_DYNAMIC(SendToForm, CDialog)

SendToForm::SendToForm(CWnd* pParent /*=NULL*/)
	: CDialog(SendToForm::IDD, pParent)
	, m_str1(_T(""))
	, m_Count(0)
{

}

BOOL SendToForm::OnInitDialog()
{
	
	CDialog::OnInitDialog();
	OnLoadControl(0,0);
	SetDlgItemText(IDC_EDIT2,L"1");
	SetDlgItemText(IDC_EDIT3,L"1");
	SetDlgItemText(IDC_EDIT4,L"1");
	return TRUE;
}

HWND SendToForm::OnInit(list<WIN_INFO> _info)
{
	info=_info;
	
return m_hWnd;
}

SendToForm::~SendToForm()
{
}

void SendToForm::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_ControlName);
	//	DDX_Control(pDX, IDC_EDIT1, m_str);
	DDX_Control(pDX, IDC_CHECK1, n_bEnter);
	//	DDX_Control(pDX, IDC_CHECK2, n_b10errase);
	//	DDX_Text(pDX, IDC_EDIT1, m_str1);
	DDX_Control(pDX, IDC_TREE1, m_Tree);
}


void SendToForm::TreeOutput2(list<WIN_INFO>::iterator I, CTreeCtrl *m_Tree)
{
 std::map<DWORD_PTR,HTREEITEM> dict;
 //int counter = 0;
 for(;I != info.end(); I++)
 {
  //if(counter++ == I->m_dwLen) break;
  WCHAR *str = (WCHAR*)malloc(512);
  _itow((int)I->id,str,16);
  wcscat(str,L" | Title:");
  wcscat(str,( WCHAR *)I->title);
  wcscat(str,L" | Class:");
  wcscat(str,( WCHAR *)I->classname);
  HTREEITEM item;
  if(I->id_parent!=NULL) item = m_Tree->InsertItem(str, dict[I->id_parent]);//, ((HTREEITEM)(UINT_PTR)-65536),
  else  item = m_Tree->InsertItem(str);
  m_Tree->SetItemData(item, I->id);
  if(dict[I->id] == NULL)
  {
   dict[I->id]=item;
  }
 }
}


LRESULT SendToForm::OnLoadControl( WPARAM wp, LPARAM lp )
{
	
//	m_pClient->GetWindowList( info );

//	m_WindowList.ResetContent();
	list<WIN_INFO>::iterator I = info.begin();

	TreeOutput2(I, &m_Tree);
	for( ; I != info.end(); I++ )
	{
		//I->
		CString s1 = L"";
		if( I->placement.showCmd == SW_SHOWMAXIMIZED )
		{
			s1 = L",Maximized";
		}
		else if( I->placement.showCmd == SW_HIDE )
		{
			s1 = L",SW_HIDE";
		}
		else if( I->placement.showCmd == SW_SHOWNORMAL )
		{
			s1 = L",Normal";
		}

		CString s;
		s.Format( L"[%08X%s] - \"%s\" (%s)",
			I->id, LPCTSTR(s1), I->title, I->classname );
		int iItem = m_ControlName.InsertString( 0, s );
		m_ControlName.SetItemData( iItem, I->id );
	}

//	Log( L"Received list of windows." );
	return 0;
}

BEGIN_MESSAGE_MAP(SendToForm, CDialog)
//	ON_MESSAGE(PM_CONTROLS_SEND_COMAND,OnLoadControl)
	ON_BN_CLICKED(IDOK, &SendToForm::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON5, &SendToForm::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &SendToForm::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON2, &SendToForm::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON4, &SendToForm::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON7, &SendToForm::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON3, &SendToForm::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON1, &SendToForm::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON8, &SendToForm::OnBnClickedButton8)
END_MESSAGE_MAP()


// SendToForm message handlers

void SendToForm::OnBnClickedOk()
{
	if ((m_ControlName.GetCurSel())==LB_ERR)
		return;
	
	
	iCurItems = m_ControlName.GetCurSel( );
		
		
	//m_ControlName.GetText(iItem,sRstr);
	//m_ControlName.
	// TODO: Add your control notification handler code here
	OnOK();
}

void SendToForm::OnBnClickedButton5()
{
	HTREEITEM iCurItems = m_Tree.GetSelectedItem();
	DWORD_PTR id = m_Tree.GetItemData(iCurItems);

//	iCurItems = m_ControlName.GetCurSel();
//	DWORD_PTR id = m_ControlName.GetItemData(iCurItems);	
	CString tmp;
	GetDlgItemText(IDC_EDIT1,tmp);
	CString x,y;
	GetDlgItemText(IDC_EDIT3,x);
	GetDlgItemText(IDC_EDIT4,y);
	int iX,iY;
	iX= _wtoi(x.GetBuffer());
	iY= _wtoi(y.GetBuffer());
	
	bool bEnter,bSendM;
	CButton *pcb1 = (CButton *) (this->GetDlgItem(IDC_CHECK1));
 	if(pcb1->GetCheck() == 1)
 		bEnter=true;
 	else
 		bEnter=false;

	CButton *pcb2 = (CButton *) (this->GetDlgItem(IDC_CHECK2));
 	if(pcb2->GetCheck() == 1)
 		bSendM=true;
 	else
 		bSendM=false;

	m_pClientTmp->RequestKeysToForm( id_CurItem,id, iX, iY, tmp, bEnter,false,bSendM);

	//m_pClientTmp->RequestLClick( id, 0, 0, false );
	// TODO: Add your control notification handler code here
}

void SendToForm::OnBnClickedButton6()
{

	HTREEITEM iCurItems = m_Tree.GetSelectedItem();
	DWORD_PTR id = m_Tree.GetItemData(iCurItems);


	WCHAR cLeft=(WCHAR)0x00000025;
	WCHAR cDELETE=(WCHAR)0x00000014;
	CString tmp;
	int iCount;
	GetDlgItemText(IDC_EDIT2,tmp);
	iCount=_wtoi(tmp.GetBuffer());
	tmp.Delete(0,tmp.GetLength());
	for (int i=1;i<=iCount;i++)
	{
		tmp=tmp+(CString)cLeft;//(WCHAR)VK_LEFT+(WCHAR)VK_DELETE ;
		tmp=tmp+(CString)cDELETE;
	}
	bool bSendM;
	CButton *pcb2 = (CButton *) (this->GetDlgItem(IDC_CHECK2));
 	if(pcb2->GetCheck() == 1)
 		bSendM=true;
 	else
 		bSendM=false;
	m_pClientTmp->RequestKeysToForm( id_CurItem,id, 0, 0, tmp, false,false,bSendM);
	// TODO: Add your control notification handler code here
}

void SendToForm::OnBnClickedButton2()
{
	
	HTREEITEM iCurItems = m_Tree.GetSelectedItem();
	DWORD_PTR id = m_Tree.GetItemData(iCurItems);

	
	WCHAR cUP=(WCHAR)0x00000026;	
	CString tmp;
	int iCount;
	GetDlgItemText(IDC_EDIT2,tmp);
	iCount=_wtoi(tmp.GetBuffer());
	tmp=L"";
	for (int i=1;i<=iCount;i++)
	{
		tmp=tmp+(CString)cUP;		
	}
	bool bSendM;
	CButton *pcb2 = (CButton *) (this->GetDlgItem(IDC_CHECK2));
 	if(pcb2->GetCheck() == 1)
 		bSendM=true;
 	else
 		bSendM=false;
	m_pClientTmp->RequestKeysToForm( id_CurItem,id, 0, 0, tmp, false,false,bSendM);
	
}

void SendToForm::OnBnClickedButton4()
{
	HTREEITEM iCurItems = m_Tree.GetSelectedItem();
	DWORD_PTR id = m_Tree.GetItemData(iCurItems);

	
	WCHAR cDown=(WCHAR)0x00000028;	
	CString tmp;
	int iCount;
	GetDlgItemText(IDC_EDIT2,tmp);
	iCount=_wtoi(tmp.GetBuffer());
	tmp.Delete(0,tmp.GetLength());
	for (int i=1;i<=iCount;i++)
	{
		tmp=tmp+(CString)cDown;		
	}
	bool bSendM;
	CButton *pcb2 = (CButton *) (this->GetDlgItem(IDC_CHECK2));
 	if(pcb2->GetCheck() == 1)
 		bSendM=true;
 	else
 		bSendM=false;
	m_pClientTmp->RequestKeysToForm( id_CurItem,id, 0, 0, tmp, false,false,bSendM);
	
}

void SendToForm::OnBnClickedButton7()
{
	HTREEITEM iCurItems = m_Tree.GetSelectedItem();
	DWORD_PTR id = m_Tree.GetItemData(iCurItems);
	int iX,iY;
	CString x,y;
	GetDlgItemText(IDC_EDIT3,x);
	GetDlgItemText(IDC_EDIT4,y);
	iX= _wtoi(x.GetBuffer());
	iY= _wtoi(y.GetBuffer());
	m_pClientTmp->RequestRightMouseDown( id_CurItem,id, iX, iY);
	// TODO: Add your control notification handler code here
}

void SendToForm::OnBnClickedButton3()
{
	HTREEITEM iCurItems = m_Tree.GetSelectedItem();
	DWORD_PTR id = m_Tree.GetItemData(iCurItems);

	
	WCHAR cTab=(WCHAR)0x00000009;	
	CString tmp;
	int iCount;
	GetDlgItemText(IDC_EDIT2,tmp);
	iCount=_wtoi(tmp.GetBuffer());
	tmp.Delete(0,tmp.GetLength());
	for (int i=0;i<iCount;i++)
	{
		tmp=tmp+(CString)cTab;		
	}
	bool bSendM;
	CButton *pcb2 = (CButton *) (this->GetDlgItem(IDC_CHECK2));
 	if(pcb2->GetCheck() == 1)
 		bSendM=true;
 	else
 		bSendM=false;
	m_pClientTmp->RequestKeysToForm( id_CurItem,id, 0, 0, tmp, false,false,bSendM);
}

void SendToForm::OnBnClickedButton1()
{
	HTREEITEM iCurItems = m_Tree.GetSelectedItem();
	DWORD_PTR id = m_Tree.GetItemData(iCurItems);
	int iX,iY;
	CString x,y;
	GetDlgItemText(IDC_EDIT3,x);
	GetDlgItemText(IDC_EDIT4,y);
	iX= _wtoi(x.GetBuffer());
	iY= _wtoi(y.GetBuffer());
	m_pClientTmp->RequestLeftMouseDown( id_CurItem,id, iX, iY);




	/*int iItem = m_WindowList.GetCurSel( );
	if( iItem >= 0 )
	{
		DWORD_PTR id = m_WindowList.GetItemData( iItem );
		m_pClient->RequestLClick( id, (int)wp, (int)lp, m_DoubleClicks.GetCheck() == BST_CHECKED );
	//	Log( L"Sending L-click (%dx%d) to [%08X]...", wp, lp, id );
	}*/
	// TODO: Add your control notification handler code here
}

void SendToForm::OnBnClickedButton8()
{
	HTREEITEM iCurItems = m_Tree.GetSelectedItem();
	DWORD_PTR id = m_Tree.GetItemData(iCurItems);


	WCHAR cTab=(WCHAR)0x00000115;	
	CString tmp;
	int iCount;
	GetDlgItemText(IDC_EDIT2,tmp);
	iCount=_wtoi(tmp.GetBuffer());
	tmp.Delete(0,tmp.GetLength());
	for (int i=0;i<iCount;i++)
	{
		tmp=tmp+(CString)cTab;		
	}
	bool bSendM;
	CButton *pcb2 = (CButton *) (this->GetDlgItem(IDC_CHECK2));
 	if(pcb2->GetCheck() == 1)
 		bSendM=true;
 	else
 		bSendM=false;
	m_pClientTmp->RequestKeysToForm( id_CurItem,id, 0, 0, tmp, false,false,bSendM);

	// TODO: Add your control notification handler code here
}
