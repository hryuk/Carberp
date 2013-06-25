// URLInput.cpp : implementation file
//

#include "stdafx.h"
#include "Server.h"
#include "URLInput.h"


// URLInput dialog

IMPLEMENT_DYNAMIC(URLInput, CDialog)

URLInput::URLInput(CWnd* pParent /*=NULL*/)
	: CDialog(URLInput::IDD, pParent)
{

}

URLInput::~URLInput()
{
}

void URLInput::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(URLInput, CDialog)
	ON_BN_CLICKED(IDOK, &URLInput::OnBnClickedOk)
END_MESSAGE_MAP()


// URLInput message handlers

void URLInput::ToAnsi(PWCHAR Str, DWORD Len)
{
	// Функция преобразовывает WideString в ANSI String
	if (Str==NULL) return ;

	if (Len == 0)
		Len = lstrlenW(Str);
	if (Len == 0)
		return ;

    // Определяем размер результирующей строки
	int ResLen = (int)WideCharToMultiByte(CP_ACP, 0, Str, Len, 0, 0, NULL, NULL);

	// Преобразовываем строку
	
	WideCharToMultiByte(1251, 0, Str, Len, URL, ResLen, NULL, NULL);

	
}

void URLInput::OnBnClickedOk()
{
	ZeroMemory(URL,256);
	WCHAR DAT[256]={0};
	ZeroMemory(DAT,256*2);
	this->GetDlgItemTextW(IDC_EDIT1, &DAT[0], 256);
	
	ToAnsi(DAT, 0);
	// TODO: Add your control notification handler code here
	OnOK();
}
