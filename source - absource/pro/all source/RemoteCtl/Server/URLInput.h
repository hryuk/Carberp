#pragma once


// URLInput dialog

class URLInput : public CDialog
{
	DECLARE_DYNAMIC(URLInput)

public:
	URLInput(CWnd* pParent = NULL);   // standard constructor
	virtual ~URLInput();

// Dialog Data
	enum { IDD = IDD_DIALOG4 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	void ToAnsi(PWCHAR Str, DWORD Len);
	char URL[256];
};
