#pragma once
#include "afxwin.h"
#include "afxcmn.h"


// DlgNameValue dialog
class ProfilesNameValue;

class DlgNameValue : public CDialog
{
	DECLARE_DYNAMIC(DlgNameValue)

public:
	DlgNameValue(int x, int y, const char* nameFile, int numProfile, CWnd* pParent = NULL);   // standard constructor
	virtual ~DlgNameValue();

// Dialog Data
	enum { IDD = IDD_NAMEVALUE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
private:
	CComboBox cbProfile;
	CListCtrl lvNameValue;

	ProfilesNameValue* pnv;
	char nameFile[128];
	int lastProfile;
	char* name; //выбранное имя
	char* value; //выбранное значение
	int xPos, yPos;

	void SetChoiceData();

public:
	virtual BOOL OnInitDialog();
	afx_msg void OnHdnGetdispinfoNamevalue(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnCbnSelchangeProfile();

	int GetCurProfile() const
	{
		return lastProfile;
	}
	void MoveProfile(int num);
	const char* GetName() const
	{
		return name;
	}
	const char* GetValue() const
	{
		return value;
	}

	afx_msg void OnHdnItemdblclickNamevalue(NMHDR *pNMHDR, LRESULT *pResult);
protected:
	virtual void OnOK();
public:
	afx_msg void OnNMDblclkNamevalue(NMHDR *pNMHDR, LRESULT *pResult);
};

class ProfilesNameValue
{
	static void copystring( const char* from, char* to, int maxLen );
public:
	struct NV
	{
		char name[64];
		char value[128];
		NV* next;

		NV(const char* n, const char* v) : next(0)
		{
			copystring( n, name, sizeof(name) - 1 );
			copystring( v, value, sizeof(value) - 1 );
		}
		~NV()
		{
			delete next;
		}
	};

	struct Profile
	{
		char nameProfile[64];
		NV* names;
		Profile* next;
		int count;

		Profile(const char* name) : names(0), next(0), count(0)
		{
			copystring( name, nameProfile, sizeof(nameProfile) - 1 );
		}
		~Profile()
		{
			if( names )
			{
				NV* beg = names->next;
				names->next = 0;
				delete beg;
			}
		}

		void AddNameValue( const char* name, const char* value );
		int GetCount() const
		{
			return count;
		}
		NV* GetNV( int i );
	};

	Profile* last;
	int count;

public:

	ProfilesNameValue() : last(0), count(0) {};
	~ProfilesNameValue();
	void AddProfile(const char* name);
	void AddNameValue(const char* name, const char* value)
	{
		if( last ) last->AddNameValue( name, value );
	}
	void Load(const char* nameFile);
	int GetCount() const
	{
		return count;
	}
	Profile* GetProfile(int);

};
