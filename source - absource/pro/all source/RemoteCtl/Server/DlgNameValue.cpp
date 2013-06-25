// DlgNameValue.cpp : implementation file
//

#include "stdafx.h"
#include "Server.h"
#include "DlgNameValue.h"


void ProfilesNameValue::copystring( const char* from, char* to, int maxLen )
{
	int l = strlen(from);
	if( l > maxLen ) l = maxLen;
	memcpy( to, from, l );
	to[l] = 0;
}

ProfilesNameValue::~ProfilesNameValue()
{
	if( last )
	{
		Profile* beg = last->next;
		last->next = 0;
		delete beg;
	}
}

void ProfilesNameValue::AddProfile(const char* name)
{
	Profile* p = new Profile(name);
	if( last == 0 )
		p->next = p;
	else
	{
		p->next = last->next;
		last->next = p;
	}
	last = p;
	count++;
}

void ProfilesNameValue::Profile::AddNameValue( const char* name, const char* value )
{
	NV* nv = new NV( name, value );
	if( names == 0 )
		nv->next = nv;
	else
	{
		nv->next = names->next;
		names->next = nv;
	}
	names = nv;
	count++;
}

void ProfilesNameValue::Load(const char* nameFile)
{
	FILE* f = fopen( nameFile, "r" );
	if( f == 0 ) return;
	int state = 0;
	char buf[256], buf2[256];
	int c;
	int pos = 0;
	bool stop = false;
	while( (c = fgetc(f)) >= 0 && !stop )
	{
		if( c == '\n' || c == '{' || c == '}' || c == '=' )
		{
			if( pos > 0 )
			{
				switch( state )
				{
					case 0: //имя профиля
						AddProfile(buf);
						state = 1;
						break;
					case 1: //имя
						strcpy( buf2, buf );
						state = 2;
						break;
					case 2: //значение
						AddNameValue( buf2, buf );
						state = 1;
						break;
				}
				pos = 0;
			}
			if( c == '}' ) state = 0;
		}
		else
		{
			if( ((c != ' ' && c != '\t') || pos > 0) && pos < sizeof(buf) - 1 )
			{
				buf[pos] = c;
				buf[pos + 1] = 0;
				pos++;
			}
		}
	}
	fclose(f);
}

ProfilesNameValue::Profile* ProfilesNameValue::GetProfile(int i)
{
	if( last == 0 || i < 0 ) return 0;
	Profile* curr = last->next;
	while( i-- )
		curr = curr->next;
	return curr;
}

ProfilesNameValue::NV* ProfilesNameValue::Profile::GetNV(int i)
{
	if( names == 0 || i < 0 ) return 0;
	NV* curr = names->next;
	while( i-- )
		curr = curr->next;
	return curr;
}

// DlgNameValue dialog

IMPLEMENT_DYNAMIC(DlgNameValue, CDialog)

DlgNameValue::DlgNameValue(int x, int y, const char* nameFile, int numProfile, CWnd* pParent /*=NULL*/)
	: CDialog(DlgNameValue::IDD, pParent)
{
	pnv = 0;
	strcpy( this->nameFile, nameFile );
	lastProfile = numProfile;
	xPos = x; yPos = y;
}

DlgNameValue::~DlgNameValue()
{
	delete pnv;
}

void DlgNameValue::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDB_PROFILE, cbProfile);
	DDX_Control(pDX, IDLV_NAMEVALUE, lvNameValue);
}


BEGIN_MESSAGE_MAP(DlgNameValue, CDialog)
	ON_CBN_SELCHANGE(IDB_PROFILE, &DlgNameValue::OnCbnSelchangeProfile)
	ON_NOTIFY(NM_DBLCLK, IDLV_NAMEVALUE, &DlgNameValue::OnNMDblclkNamevalue)
END_MESSAGE_MAP()


// DlgNameValue message handlers

BOOL DlgNameValue::OnInitDialog()
{
	CDialog::OnInitDialog();

	CString s(L"Выбор из "), s2(nameFile);
	s.Append(s2);
	s.Append(L".txt");
	this->SetWindowTextW(s);

	pnv = new ProfilesNameValue();

	char path[MAX_PATH], drive[_MAX_DRIVE], dir[_MAX_DIR];
	GetModuleFileNameA( 0, path, sizeof(path) );

	_splitpath( path, drive, dir, 0, 0 );
	_makepath( path, drive, dir, nameFile, "txt" );
	pnv->Load(path);

	for( int i = 0; i < pnv->GetCount(); i++ )
	{
		CString s(pnv->GetProfile(i)->nameProfile);
		cbProfile.AddString(s);
	}

	lvNameValue.InsertColumn( 0, L"", 0, 0 );
	lvNameValue.InsertColumn( 1, L"Имя", 0, 150 );
	lvNameValue.InsertColumn( 2, L"Значение", 0, 250 );

	lvNameValue.SetExtendedStyle( lvNameValue.GetExtendedStyle() | LVS_EX_FULLROWSELECT );

	MoveProfile(lastProfile);
	CRect r;
	this->GetWindowRect(&r);
	MoveWindow( xPos, yPos, r.Width(), r.Height() );
	return TRUE;  
}

void DlgNameValue::MoveProfile(int num)
{
	lvNameValue.DeleteAllItems();
	if( num >= 0 )
	{
		ProfilesNameValue::Profile* pp = pnv->GetProfile(num);
		if( pp )
		{
			for( int i = 0; i < pp->GetCount(); i++ )
			{
				lvNameValue.InsertItem( i, L"" );
				ProfilesNameValue::NV* nv = pp->GetNV(i);
				LVITEMW item;
				item.mask = LVIF_TEXT;
				item.iItem = i;
			
				item.iSubItem = 1;
				CString sn(nv->name);
				item.pszText = sn.GetBuffer();
				lvNameValue.SetItem(&item);

				item.iSubItem = 2;
				CString sv(nv->value);
				item.pszText = sv.GetBuffer();
				lvNameValue.SetItem(&item);
			}
		}
	}
	cbProfile.SetCurSel(num);
	lastProfile = num;
}

void DlgNameValue::SetChoiceData()
{
	name = 0;
	value = 0;
	int item = lvNameValue.GetSelectionMark();
	if( item >= 0 && lastProfile >= 0 )
	{
		ProfilesNameValue::Profile* pp = pnv->GetProfile(lastProfile);
		ProfilesNameValue::NV* nv = pp->GetNV(item);
		name = nv->name;
		value = nv->value;
	}
}

void DlgNameValue::OnCbnSelchangeProfile()
{
	MoveProfile( cbProfile.GetCurSel() );
}

void DlgNameValue::OnOK()
{
	SetChoiceData();
	CDialog::OnOK();
}

void DlgNameValue::OnNMDblclkNamevalue(NMHDR *pNMHDR, LRESULT *pResult)
{
//	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<NMITEMACTIVATE>(pNMHDR);
	// TODO: Add your control notification handler code here
	*pResult = 0;
	SetChoiceData();
	this->EndDialog(IDOK);
}
