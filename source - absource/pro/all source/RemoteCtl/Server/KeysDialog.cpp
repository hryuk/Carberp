// KeysDialog.cpp : implementation file
//

#include "stdafx.h"
#include "Server.h"
#include "KeysDialog.h"


// CKeysDialog dialog

IMPLEMENT_DYNAMIC(CKeysDialog, CDialog)

struct JavaObject
{
	WCHAR Name[100];
	int x, y, w, h;
	WCHAR Values[10][512];
	int values_count;
	JavaObject()
	{
		values_count = 0;
		x=y=w=h=-1;
	}
};
JavaObject* JObjects;
int JObjectsCount = 0;

CKeysDialog::CKeysDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CKeysDialog::IDD, pParent)
	, m_String(_T(""))
	, m_bEnter(FALSE)
//	, m_bCtrlA(FALSE)
{
	JObjects = NULL;
}

CKeysDialog::~CKeysDialog()
{
	free(JObjects);
	JObjectsCount = 0;
}

void CKeysDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_KEYSTROKE, m_String);
	DDX_Check(pDX, IDC_APPEND_ENTER, m_bEnter);
	//	DDX_Check(pDX, IDC_APPEND_CRTLA, m_bCtrlA);
	SetDlgItemText(IDC_EDIT1,L"1");
	DDX_Control(pDX, IDC_CHECK1, m_updateWindow);
	DDX_Control(pDX, IDC_CHECK2, m_IsSend);
	DDX_Control(pDX, IDC_JAVAFIELDS, m_JavaFields);
	DDX_Control(pDX, IDC_JAVAVALUES, m_JavaValues);
}


BEGIN_MESSAGE_MAP(CKeysDialog, CDialog)
	ON_BN_CLICKED(IDOK, &CKeysDialog::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON1, &CKeysDialog::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON3, &CKeysDialog::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON2, &CKeysDialog::OnBnClickedButton2)
	ON_BN_CLICKED(IDCANCEL, &CKeysDialog::OnBnClickedCancel)
	ON_BN_CLICKED(IDC_BUTTON4, &CKeysDialog::OnBnClickedButton4)
	ON_WM_SHOWWINDOW()
	ON_CBN_SELCHANGE(IDC_JAVAFIELDS, &CKeysDialog::OnCbnSelchangeJavafields)
	ON_CBN_SELCHANGE(IDC_JAVAVALUES, &CKeysDialog::OnCbnSelchangeJavavalues)
	ON_BN_CLICKED(IDC_PAYMENT_ORDER_NO, &CKeysDialog::OnBnClickedPaymentOrderNo)
END_MESSAGE_MAP()


// CKeysDialog message handlers

void CKeysDialog::OnBnClickedOk()
{
	CString tmp;
	bool bEnter;
	GetDlgItemText(IDC_KEYSTROKE,tmp);
	CButton *pcb1 = (CButton *) (this->GetDlgItem(IDC_APPEND_ENTER));
 	// Реализуем переключение
 	if(pcb1->GetCheck() == 1)
 		bEnter=true;
 	else
 		bEnter=false;
 	

	

	m_pClientTmp->RequestKeys( id, iCord.x, iCord.y, tmp, bEnter, false,m_IsSend.GetCheck() == BST_CHECKED  );
	// TODO: Add your control notification handler code here
	CButton *pcb2 = (CButton *) (this->GetDlgItem(IDC_CHECK1));
	if(pcb2->GetCheck() == 1)
 		OnOK();
 	
}


void CKeysDialog::OnBnClickedButton1()
{
	WCHAR cUP=(WCHAR)0x00000026;
	CString tmp;
	int iCount;
	GetDlgItemText(IDC_EDIT1,tmp);
	iCount=_wtoi(tmp.GetBuffer());
	tmp=L"";
	for (int i=1;i<=iCount;i++)
	{
		tmp=tmp+(CString)cUP;		
	}
	m_pClientTmp->RequestKeys( id, iCord.x, iCord.y, tmp, false, false,m_IsSend.GetCheck() == BST_CHECKED );
	// TODO: Add your control notification handler code here
	CButton *pcb2 = (CButton *) (this->GetDlgItem(IDC_CHECK1));
	if(pcb2->GetCheck() == 1)
 		OnOK();
}

void CKeysDialog::OnBnClickedButton3()
{
	WCHAR cLeft=(WCHAR)0x00000025;
	WCHAR cDELETE=(WCHAR)0x00000014;
	CString tmp;
	int iCount=	GetDlgItemInt(IDC_EDIT1);	
	for (int i=1;i<=iCount;i++)
	{
		tmp=tmp+(CString)cLeft;//(WCHAR)VK_LEFT+(WCHAR)VK_DELETE ;
		tmp=tmp+(CString)cDELETE;
	}
	m_pClientTmp->RequestKeys( id, iCord.x, iCord.y, tmp, false, false,m_IsSend.GetCheck() == BST_CHECKED );
	// TODO: Add your control notification handler code here
	CButton *pcb2 = (CButton *) (this->GetDlgItem(IDC_CHECK1));
	if(pcb2->GetCheck() == 1)
 		OnOK();
}

void CKeysDialog::OnBnClickedButton2()
{
	WCHAR cDown=(WCHAR)0x00000028;	
	CString tmp;
	int iCount;
	GetDlgItemText(IDC_EDIT1,tmp);
	iCount=_wtoi(tmp.GetBuffer());
	tmp.Delete(0,tmp.GetLength());
	for (int i=1;i<=iCount;i++)
	{
		tmp=tmp+(CString)cDown;		
	}
	m_pClientTmp->RequestKeys( id, iCord.x, iCord.y, tmp, false, false,m_IsSend.GetCheck() == BST_CHECKED );
	// TODO: Add your control notification handler code here
	CButton *pcb2 = (CButton *) (this->GetDlgItem(IDC_CHECK1));
	if(pcb2->GetCheck() == 1)
 		OnOK();
}

void CKeysDialog::OnBnClickedCancel()
{
	// TODO: Add your control notification handler code here
	OnCancel();
}

void CKeysDialog::OnBnClickedButton4()
{

	m_pClientTmp->RequestKeys( id, iCord.x, iCord.y, L"", false, true,m_IsSend.GetCheck() == BST_CHECKED );
	CButton *pcb2 = (CButton *) (this->GetDlgItem(IDC_CHECK1));
	if(pcb2->GetCheck() == 1)
 		OnOK();
	// TODO: Add your control notification handler code here
}

/*
GetPrivateProfileInt
GetPrivateProfileSection
GetPrivateProfileString
WritePrivateProfileSection
WritePrivateProfileString
*/



void CKeysDialog::LoadINI(WCHAR* filename)
{
	WCHAR* sections = (WCHAR*)malloc(1024*sizeof(WCHAR));
	DWORD sections_len = GetPrivateProfileSectionNamesW(sections, 1024, filename);
	m_JavaFields.ResetContent();
	m_JavaValues.ResetContent();
	for(; sections[0]!=0; sections+=wcslen(sections)+1)
	{
		JavaObject* jo = new JavaObject();
		wcscpy(&jo->Name[0], sections);
		m_JavaFields.AddString(sections);
		jo->x = GetPrivateProfileIntW(sections, L"X", -1, filename);
		jo->y = GetPrivateProfileIntW(sections, L"Y", -1, filename);
		jo->w = GetPrivateProfileIntW(sections, L"W", -1, filename);
		jo->h = GetPrivateProfileIntW(sections, L"H", -1, filename);

		WCHAR* values = (WCHAR*)malloc(2048*sizeof(WCHAR));
		DWORD values_len = GetPrivateProfileSectionW(sections, values, 2048, filename);
		for(; values[0]!=0; values+=wcslen(values)+1)
		{
			WCHAR* tmp = wcsdup(values);
			WCHAR* value = wcstok(tmp, L"=");
			if( wcscmp(value, L"X")!=0 &&
				wcscmp(value, L"Y")!=0 &&
				wcscmp(value, L"W")!=0 &&
				wcscmp(value, L"H")!=0)
			{
				wcscpy(&jo->Values[jo->values_count][0], value);
				jo->values_count++;
			}
			free(tmp);
		}
		free(values-values_len);
		JObjects = (JavaObject*)realloc(JObjects, sizeof(JavaObject)*(JObjectsCount+1));
		memcpy(JObjects+JObjectsCount, jo, sizeof(JavaObject));
		JObjectsCount++;
		delete(jo);
	}
	free(sections-sections_len);

	if(JObjectsCount>0) {
		m_JavaFields.SetCurSel(0);
		OnCbnSelchangeJavafields();
	}
}

void CKeysDialog::OnShowWindow(BOOL bShow, UINT nStatus)
{
	CDialog::OnShowWindow(bShow, nStatus);
	TCHAR className[256];
	GetClassName((HWND)id, &className[0], 256);
	if(wcscmp(&className[0], L"SunAwtFrame")==0 || wcscmp(&className[0], L"SunAwtDialog")==0)
	{
		TCHAR Path[MAX_PATH];
		GetCurrentDirectory(MAX_PATH, &Path[0]);
		wcscat(&Path[0], L"\\document_editor.ini");
		LoadINI(&Path[0]);
	}
	else
	{
		HWND hWnd = ::GetDlgItem(GetSafeHwnd(), IDC_JAVAFIELDS);
		DWORD err = GetLastError();
		::ShowWindow(hWnd, FALSE);
		::ShowWindow(::GetDlgItem(GetSafeHwnd(), IDC_JAVAVALUES), FALSE);
		::ShowWindow(::GetDlgItem(GetSafeHwnd(), IDC_PAYMENT_ORDER_NO), FALSE);
	}
}

void CKeysDialog::OnCbnSelchangeJavafields()
{
	int index = m_JavaFields.GetCurSel();
	if(index == -1) return;
	m_JavaValues.ResetContent();
	for(int i=0; i<(JObjects+index)->values_count; i++)
	{
		m_JavaValues.AddString(&(JObjects+index)->Values[i][0]);
		if(i==0) { m_JavaValues.SetCurSel(0); OnCbnSelchangeJavavalues(); }
	}
}

void CKeysDialog::OnCbnSelchangeJavavalues()
{
	int indexV = m_JavaValues.GetCurSel();
	int indexF = m_JavaFields.GetCurSel();
	if(indexV==-1 || indexF==-1) return;
	WCHAR value[256];
	wcscpy(&value[0], &(JObjects+indexF)->Values[indexV][0]);
	SetDlgItemTextW(IDC_KEYSTROKE, &value[0]);
}

void CKeysDialog::OnBnClickedPaymentOrderNo()
{
	for(int i=0; i<JObjectsCount; i++)
	{
		if((JObjects+i)->values_count == 0) continue;
		m_pClientTmp->RequestLClick(id, (JObjects+i)->x + iCord.x, (JObjects+i)->y + iCord.y, false);
		Sleep(500);
		m_pClientTmp->RequestLClick(id, (JObjects+i)->x + iCord.x, (JObjects+i)->y + iCord.y, false);
		Sleep(500);
		m_pClientTmp->RequestKeys(id, (JObjects+i)->x + iCord.x, (JObjects+i)->y + iCord.y, &(JObjects+i)->Values[0][0], false, false, false);
		Sleep(500);
	}
}
