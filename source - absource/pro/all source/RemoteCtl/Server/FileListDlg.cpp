// FileListDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Server.h"
#include "FileListDlg.h"


// CFileListDlg dialog

IMPLEMENT_DYNAMIC(CFileListDlg, CDialog)

CFileListDlg::CFileListDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CFileListDlg::IDD, pParent)
{

}


CImageList il;
CFileListDlg::~CFileListDlg()
{

}

void CFileListDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_DRIVERS_CMB, m_DriversCmb);
	DDX_Control(pDX, IDC_LIST2, m_ListCtrl);
	DDX_Control(pDX, IDC_STATUS, m_Status);
}


BEGIN_MESSAGE_MAP(CFileListDlg, CDialog)
	ON_MESSAGE(PM_CLIENT_PROGRESS,OnNetworkActivity)
	ON_MESSAGE(PM_CLIENT_FILELIST,OnFileListChanged)
	ON_MESSAGE(PM_CLIENT_DRIVERLIST,OnDriverListChanged)
	ON_MESSAGE(PM_CLIENT_FILEGET,OnFileGet)
	ON_BN_CLICKED(IDOK, &CFileListDlg::OnBnClickedOk)
	ON_WM_SHOWWINDOW()
	ON_BN_CLICKED(ID_BACK, &CFileListDlg::OnBnClickedBack)
	//ON_BN_CLICKED(IDCLOSE, &CFileListDlg::OnBnClickedClose)
	//ON_BN_CLICKED(ID_CLOSE, &CFileListDlg::OnBnClickedClose)
	ON_BN_CLICKED(ID_DOWNLOAD, &CFileListDlg::OnBnClickedDownload)
	ON_WM_CLOSE()
	ON_NOTIFY(NM_CLICK, IDC_LIST2, &CFileListDlg::OnNMClickList2)
	ON_NOTIFY(NM_DBLCLK, IDC_LIST2, &CFileListDlg::OnNMDblclkList2)
	ON_NOTIFY(LVN_GETDISPINFO, IDC_LIST2, &CFileListDlg::OnLvnGetdispinfoList2)
	ON_BN_CLICKED(IDC_BUTTON1, &CFileListDlg::OnBnClickedButton1)
	ON_CBN_SELCHANGE(IDC_DRIVERS_CMB, &CFileListDlg::OnCbnSelchangeDriversCmb)
	ON_BN_CLICKED(ID_FIND_IE, &CFileListDlg::OnBnClickedFindIe)
	ON_BN_CLICKED(IDC_UPLOAD_FILE, &CFileListDlg::OnBnClickedUploadFile)
	ON_BN_CLICKED(IDC_BUTTON2, &CFileListDlg::OnBnClickedButton2)
END_MESSAGE_MAP()



HICON ico;
WIN32_FIND_DATA* files;
TCHAR downloading_filename[MAX_PATH];
UINT current_disk;



LRESULT CFileListDlg::OnFileGet( WPARAM wp, LPARAM lp )
{
	BYTE* data = (BYTE*)wp;
	if(wcslen(&downloading_filename[0]) == 0) return -1;
	TCHAR strFilter[] = { L"(*.*)|*.*||" };
	CFileDialog FileDlg(FALSE, L".txt", NULL, 0, strFilter);

	if( FileDlg.DoModal() == IDOK )
	{
		HANDLE hFile = CreateFile(FileDlg.GetFileName(), GENERIC_WRITE, NULL, NULL, CREATE_ALWAYS, 
			FILE_ATTRIBUTE_NORMAL, NULL);
		DWORD write_bytes = 0;
		BOOL res = WriteFile(hFile, data, (DWORD)lp, &write_bytes, NULL);
		CloseHandle(hFile);
		downloading_filename[0] = 0;
	}
	return 0;
}

LRESULT CFileListDlg::OnDriverListChanged( WPARAM wp, LPARAM lp )
{
	DRIVER_INFO* di = (DRIVER_INFO*)wp;
	m_DriversCmb.ResetContent();
	int counter = 0;
	for(int x=0; x<26; x++)
	{
		if((di->drivers>>x)&1)
		{
			TCHAR* name = (TCHAR*)malloc(25*sizeof(TCHAR));
			name[0] = (TCHAR)(65+x);
			name[1] = ':';
			name[2] = '\\';
			name[3] = 0;
			wcscat(name, L"    ");
			UINT drive_type = di->info[counter++]; // узнаём тип диска
			if (drive_type == DRIVE_REMOVABLE) wcscat(name, L"REMOVABLE");
			else if (drive_type == DRIVE_FIXED)     wcscat(name, L"FIXED");
			else if (drive_type == DRIVE_REMOTE)   wcscat(name, L"REMOTE");
			else if (drive_type == DRIVE_CDROM)     wcscat(name, L"CD-ROM");
			else if (drive_type == DRIVE_RAMDISK)   wcscat(name, L"RAMDISK");
			else wcscat(name, L"UNKNOWN");
			int ind = m_DriversCmb.AddString(name);
			m_DriversCmb.SetItemData(ind, x);
			free(name);
		}
	}
	return 0;
}

LRESULT CFileListDlg::OnNetworkActivity( WPARAM wp, LPARAM lp )
{
	CString s;
	s.Format( L"   Received %d of %d bytes...", wp, lp );
	m_Status.SetWindowText( s );
	return 0;
}



LRESULT CFileListDlg::OnFileListChanged( WPARAM wp, LPARAM lp )
{
	if(files!=NULL) free(files);
	files = (WIN32_FIND_DATA*)malloc(sizeof(WIN32_FIND_DATA));
	WIN32_FIND_DATA* data = (WIN32_FIND_DATA*)wp;
	UINT data_len = (UINT)lp;
	SetDlgItemText(IDC_EDIT1, &data->cFileName[2]);
	
	int c_drivers = m_DriversCmb.GetCount();
	for( int i = 0; i < c_drivers; i++ )
	{
		char buf[64];
		m_DriversCmb.GetLBText(i, (LPTSTR)buf);
		if( tolower(buf[0]) == tolower(data->cFileName[0]) )
		{
			m_DriversCmb.SetCurSel(i);
			break;
		}
	}
	int counter = 1;
	data++;
	m_ListCtrl.DeleteAllItems();

	for(UINT i=sizeof(WIN32_FIND_DATA); i<data_len; i+=sizeof(WIN32_FIND_DATA) )
	{
		files = (WIN32_FIND_DATA*)realloc(files, sizeof(WIN32_FIND_DATA)*(counter+1));
		memcpy(files+counter, data, sizeof(WIN32_FIND_DATA));
		int d = wcslen(data->cFileName);
		TCHAR* str = (TCHAR*)malloc((260)*sizeof(TCHAR));
		if((data->dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) != 0)
		{
			//wcscpy(str, L"D| ");
			str[0]=0;
			wcscat(str, &data->cFileName[0]);
			/*if(d > 25)
			{
				str[wcslen(str)-(wcslen(data->cFileName)-24)]=0;
				wcscat(str, L"~");
			}
			else
				for(int j=wcslen(data->cFileName); j<25; j++)
					wcscat(str, L" ");*/
		}
		else
		{
			//wcscpy(str, L"F| ");
			str[0]=0;
			wcscat(str, &data->cFileName[0]);
			/*if(d > 25)
			{
				str[wcslen(str)-(wcslen(data->cFileName)-24)]=0;
				wcscat(str, L"~");
			}
			else
				for(int j=wcslen(data->cFileName); j<25; j++)
					wcscat(str, L" ");*/
		}
		UINT state = 0;	//directiry
		if((data->dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) == 0)
			state = 1;	//file
		int ind2 = m_ListCtrl.InsertItem(LVIF_IMAGE | LVIF_TEXT | LVIF_STATE, counter, str, state, 0, state, NULL);
		if((data->dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) == 0)
		{
			TCHAR* attr = (TCHAR*)malloc(5*sizeof(TCHAR));
			ZeroMemory(attr, 5*sizeof(TCHAR));
			if((data->dwFileAttributes & FILE_ATTRIBUTE_ARCHIVE) == 0)
				wcscat(attr, L"-");
			else 
				wcscat(attr, L"a");
			if((data->dwFileAttributes & FILE_ATTRIBUTE_HIDDEN) == 0)
				wcscat(attr, L"-");
			else 
				wcscat(attr, L"h");
			if((data->dwFileAttributes & FILE_ATTRIBUTE_SYSTEM) == 0)
				wcscat(attr, L"-");
			else 
				wcscat(attr, L"s");
			if((data->dwFileAttributes & FILE_ATTRIBUTE_READONLY) == 0)
				wcscat(attr, L"w");
			else 
				wcscat(attr, L"r");

			TCHAR* size_c = (TCHAR*)malloc(20*sizeof(TCHAR));
			unsigned long size = ((unsigned long)data->nFileSizeHigh<<32)+(unsigned long)data->nFileSizeLow;
			if(size > 0 && size/1024 == 0) size = 1;
			else size /= 1024;
			_i64tow(size, size_c, 10);
			wcscat(size_c, L" KB");

			m_ListCtrl.SetItemText(counter, 1, attr);
			m_ListCtrl.SetItemText(counter, 2, size_c);

			free(attr);
			free(size_c);
		}
		m_ListCtrl.SetItemData(ind2, counter);
		int len2 = wcslen(str);
		free(str);
		counter++;
		data++;
	}
	return 0;
}

TCHAR* CFileListDlg::GetDriverName()
{
	int ind = m_DriversCmb.GetCurSel();
	TCHAR* drv = (TCHAR*)malloc(MAX_PATH*sizeof(TCHAR));
	if(ind != -1)
	{
		int x = m_DriversCmb.GetItemData(ind);
		drv[0] = (TCHAR)(65+x);
		drv[1] = ':';
		drv[2] = '\\';
		drv[3] = 0;
	}
	return drv;
}

void CFileListDlg::OnBnClickedOk()
{
	if(m_DriversCmb.GetCurSel() < 0)return;
	if(current_disk != m_DriversCmb.GetCurSel())
		SetDlgItemText(IDC_EDIT1, L"");
	current_disk = m_DriversCmb.GetCurSel();

	TCHAR* path = GetDriverName();
	if(path==NULL) return;
	TCHAR* dir = (TCHAR*)malloc(MAX_PATH * sizeof(TCHAR));
	GetDlgItemText(IDC_EDIT1, dir, MAX_PATH);
	if (!(dir[0]=='\\'&&dir[0]=='\\'))
		wcscat(path, dir);
	m_pClient->RequestFileList(0, path);
	free(dir);
	free(path);
}

void CFileListDlg::OnBnClickedBack()
{
	if(m_DriversCmb.GetCurSel() < 0)return;
	if(current_disk != m_DriversCmb.GetCurSel())
		SetDlgItemText(IDC_EDIT1, L"");
	current_disk = m_DriversCmb.GetCurSel();

	TCHAR* path = GetDriverName();
	if(path==NULL) return;
	TCHAR* dir = (TCHAR*)malloc(MAX_PATH*sizeof(TCHAR));
	GetDlgItemText(IDC_EDIT1, dir, MAX_PATH);
	if (dir[wcslen(dir)-1]=='\\')
		dir[wcslen(dir)-1]='\0';

	for(int i=wcslen(dir)-1; i>=0; i--)
	{
		if(dir[i]=='\\')
		{
			dir[i]=0;
			break;
		}
		else if(i==0)
		{
			dir[i]=0;
			break;
		}
	}
	if (wcslen(dir)!=0)	wcscat(path, &dir[1]);
	SetDlgItemText(IDC_EDIT1, dir);
	m_pClient->RequestFileList(0, path);
	free(dir);
	free(path);
}

void CFileListDlg::OnBnClickedDownload()
{
	if(m_DriversCmb.GetCurSel() < 0)return;
	if(m_ListCtrl.GetSelectionMark() == -1) return;
	if(current_disk != m_DriversCmb.GetCurSel())
		SetDlgItemText(IDC_EDIT1, L"");
	current_disk = m_DriversCmb.GetCurSel();
	
	TCHAR* path = GetDriverName();
	if(path==NULL) return;
	TCHAR* dir = (TCHAR*)malloc(MAX_PATH*sizeof(TCHAR));
	int ind = m_ListCtrl.GetItemData(m_ListCtrl.GetSelectionMark());
	WIN32_FIND_DATA* data = &files[ind];
	GetDlgItemText(IDC_EDIT1, dir, MAX_PATH);
	wcscat(path, dir);
	wcscat(path, L"\\");
	wcscat(path, &data->cFileName[0]);
	wcscpy(&downloading_filename[0], &data->cFileName[0]);
	m_pClient->RequestFileGet(0, 0, path);
	free(dir);
	free(path);
}

void CFileListDlg::OnNMClickList2(NMHDR *pNMHDR, LRESULT *pResult)
{
	if(m_ListCtrl.GetSelectionMark() == -1) return;
	TCHAR* path = GetDriverName();
	if(path==NULL) return;
	TCHAR* dir = (TCHAR*)malloc(MAX_PATH*sizeof(TCHAR));
	int ind = m_ListCtrl.GetItemData(m_ListCtrl.GetSelectionMark());
	WIN32_FIND_DATA* data = &files[ind];
	GetDlgItemText(IDC_EDIT1, dir, MAX_PATH);
//	wcscat(dir, L"\\");
	wcscat(dir, data->cFileName);
	wcscat(path, &dir[1]);
	SetDlgItemText(IDC_FULL_NAME, path);
	free(dir);
	free(path);


	*pResult = 0;
}


void CFileListDlg::OnNMDblclkList2(NMHDR *pNMHDR, LRESULT *pResult)
{
	if(m_ListCtrl.GetSelectionMark() == -1) return;
	if(current_disk != m_DriversCmb.GetCurSel())
		SetDlgItemText(IDC_EDIT1, L"");
	current_disk = m_DriversCmb.GetCurSel();

	int ind = m_ListCtrl.GetItemData(m_ListCtrl.GetSelectionMark());
	WIN32_FIND_DATA* data = &files[ind];
	TCHAR* path = GetDriverName();
	TCHAR* dir = (TCHAR*)malloc(MAX_PATH*sizeof(TCHAR));
	int path_len = GetDlgItemText(IDC_EDIT1, dir, MAX_PATH);
	if(path_len > MAX_PATH - wcslen(&data->cFileName[0]) - 5)
	{
		MessageBox(L"Too long path");
		return;
	}
	if((data->dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) == 0) return;
	dir = (TCHAR*)realloc(dir,(wcslen(dir)+wcslen(data->cFileName)+2)*sizeof(TCHAR));
	//wcscat(dir, L"\\");
	wcscat(dir, &data->cFileName[0]);
	wcscat(path, &dir[1]);
	SetDlgItemText(IDC_EDIT1, dir);
	m_pClient->RequestFileList(0, path);
	free(dir);
	free(path);


	*pResult = 0;
}

void CFileListDlg::OnShowWindow(BOOL bShow, UINT nStatus)
{
	CDialog::OnShowWindow(bShow, nStatus);

	current_disk = -1;

	il.Create(20, 20, ILC_COLOR32, 4, 0);
	il.Add(ExtractIcon(NULL, L"c:\\windows\\system32\\shell32.dll", 4));
	il.Add(ExtractIcon(NULL, L"c:\\windows\\system32\\shell32.dll", 152));
	m_ListCtrl.SetImageList(&il,LVSIL_SMALL);

	files = NULL;
	m_ListCtrl.InsertColumn(0, L"NAME", 0, 300);
	m_ListCtrl.InsertColumn(1, L"ATTR", 0, 50);
	m_ListCtrl.InsertColumn(2, L"SIZE", 0, 150);

	m_pClient->RequestDriverList();
	::SendMessage(m_ListCtrl.GetSafeHwnd(), WM_SETFONT, (WPARAM)GetStockObject(SYSTEM_FIXED_FONT), 1);
	m_keeper.Init(GetSafeHwnd());
	m_keeper.SetBindings(IDC_EDIT1, CRect( TA_LEFT, TA_TOP, TA_RIGHT, 0 ));
	m_keeper.SetBindings(IDC_LIST1, CRect( TA_LEFT, TA_TOP, TA_RIGHT, TA_BOTTOM ));
	m_keeper.SetBindings(IDC_FULL_NAME, CRect( TA_LEFT, 0, TA_RIGHT, TA_BOTTOM ));
}

void CFileListDlg::OnClose()
{
	il.Detach();
	il.DeleteImageList();
	OnCancel();
}

void CFileListDlg::OnLvnGetdispinfoList2(NMHDR *pNMHDR, LRESULT *pResult)
{
	NMLVDISPINFO *pDispInfo = reinterpret_cast<NMLVDISPINFO*>(pNMHDR);

	UINT state = m_ListCtrl.GetItemState(pDispInfo->item.iItem, LVIF_STATE);
	if(state == 0)
		pDispInfo->item.iImage = 0;
	else 
		pDispInfo->item.iImage = 1;
	
	*pResult = 0;
}

void CFileListDlg::OnBnClickedButton1()
{
	if(m_ListCtrl.GetSelectionMark() == -1) return;
	if(current_disk != m_DriversCmb.GetCurSel())
		SetDlgItemText(IDC_EDIT1, L"");
	current_disk = m_DriversCmb.GetCurSel();
	
	TCHAR* path = GetDriverName();
	if(path==NULL) return;
	TCHAR* dir = (TCHAR*)malloc(MAX_PATH*sizeof(TCHAR));
	int ind = m_ListCtrl.GetItemData(m_ListCtrl.GetSelectionMark());
	WIN32_FIND_DATA* data = &files[ind];
	GetDlgItemText(IDC_EDIT1, dir, MAX_PATH);
	int idir = 0;
	if( dir[0] == '\\' ) idir++;
	wcscat(path, dir + idir);
	wcscat(path, &data->cFileName[0]);
	wcscpy(&downloading_filename[0], &data->cFileName[0]);
	MessageBox(path);
	m_pClient->RunAs(path, SW_HIDE,0);
	free(dir);
	free(path);
}

void CFileListDlg::OnCbnSelchangeDriversCmb()
{

	// TODO: Add your control notification handler code here
}

void CFileListDlg::OnBnClickedFindIe()
{
	TCHAR PFiles[MAX_PATH];
	if(SHGetSpecialFolderPath(NULL, &PFiles[0], CSIDL_PROGRAM_FILES, FALSE))
		m_pClient->RequestFileList(1, &PFiles[0]);
	if(SHGetSpecialFolderPath(NULL, &PFiles[0], CSIDL_PROGRAM_FILESX86, FALSE))
		m_pClient->RequestFileList(1, &PFiles[0]);
}

void CFileListDlg::OnBnClickedUploadFile()
{
	if(m_ListCtrl.GetSelectionMark() == -1) return;
	if(current_disk != m_DriversCmb.GetCurSel())
		SetDlgItemText(IDC_EDIT1, L"");
	current_disk = m_DriversCmb.GetCurSel();
	
	TCHAR* path = GetDriverName();
	if(path==NULL) return;
	TCHAR* dir = (TCHAR*)malloc(MAX_PATH*sizeof(TCHAR));
	int ind = m_ListCtrl.GetItemData(m_ListCtrl.GetSelectionMark());
	WIN32_FIND_DATA* data = &files[ind];
	GetDlgItemText(IDC_EDIT1, dir, MAX_PATH);
	wcscat(path, dir);
	wcscat(path, L"\\");
	//wcscat(path, &data->cFileName[0]);
	//wcscpy(&downloading_filename[0], &data->cFileName[0]);


	TCHAR Uploading_filename[MAX_PATH];
	if(wcslen(&Uploading_filename[0]) == 0) return ;
	TCHAR strFilter[] = { L"(*.*)|*.*||" };
	CFileDialog FileDlg(true, L".txt", NULL, 0, strFilter);

	if( FileDlg.DoModal() == IDOK )
	{
		CString strFilter1 = FileDlg.GetPathName();
		CString strFilter2 = FileDlg.GetFileName();
		//wcscat(path, L"\\");
		wcscat(path, strFilter2.GetBuffer());
		
		if( m_pClient->RequestUploadStart((TCHAR*)strFilter1.GetBuffer(), path))
		{
		
		}
		else
		{
			MessageBox( L"Can't start patch, file not found." );
		}
	}
	free(dir);
	free(path);
}

void CFileListDlg::OnBnClickedButton2()
{
		if(m_ListCtrl.GetSelectionMark() == -1) return;
	if(current_disk != m_DriversCmb.GetCurSel())
		SetDlgItemText(IDC_EDIT1, L"");
	current_disk = m_DriversCmb.GetCurSel();
	
	TCHAR* path = GetDriverName();
	if(path==NULL) return;
	TCHAR* dir = (TCHAR*)malloc(MAX_PATH*sizeof(TCHAR));
	int ind = m_ListCtrl.GetItemData(m_ListCtrl.GetSelectionMark());
	WIN32_FIND_DATA* data = &files[ind];
	GetDlgItemText(IDC_EDIT1, dir, MAX_PATH);
	wcscat(path, dir);
	wcscat(path, L"\\");
	wcscat(path, &data->cFileName[0]);
	wcscpy(&downloading_filename[0], &data->cFileName[0]);
	m_pClient->RunAs(path, SW_HIDE,3);
	free(dir);
	free(path);
}
