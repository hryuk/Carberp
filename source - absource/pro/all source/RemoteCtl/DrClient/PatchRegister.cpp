//#include "stdafx.h"
#include "./PatchRegister.h"

int SetRegValueDWORD(HKEY RootKey, LPTSTR SubKey, LPTSTR ValueName, DWORD Data)
{
	HKEY Key;
	if(RegOpenKeyEx(RootKey, SubKey, 0, KEY_WRITE, &Key) != ERROR_SUCCESS) return 1;
	if(RegSetValueEx(Key, ValueName, NULL, REG_DWORD, (BYTE*)&Data, sizeof(DWORD)) != ERROR_SUCCESS) return 2;
	return 0;	
}

bool PatchVista()
{
	if(SetRegValueDWORD(HKEY_LOCAL_MACHINE, L"SYSTEM\\CurrentControlSet\\Control\\Terminal Server", L"fDenyTSConnections", 0) != 0) return false;
	if(SetRegValueDWORD(HKEY_LOCAL_MACHINE, L"SYSTEM\\CurrentControlSet\\Control\\Terminal Server", L"fSingleSessionPerUser", 0) != 0) return false;
	return true;
}

bool PatchXP()
{
	if(SetRegValueDWORD(HKEY_LOCAL_MACHINE, L"SYSTEM\\CurrentControlSet\\Control\\Terminal Server", L"fDenyTSConnections", 0) != 0) return false;
	if(SetRegValueDWORD(HKEY_LOCAL_MACHINE, L"SYSTEM\\CurrentControlSet\\Control\\Terminal Server", L"fSingleSessionPerUser", 0) != 0) return false;

	if(SetRegValueDWORD(HKEY_LOCAL_MACHINE, L"SYSTEM\\CurrentControlSet\\Control\\Terminal Server\\Licensing Core", L"EnableConcurrentSessions", 1) != 0) return false;

	if(SetRegValueDWORD(HKEY_LOCAL_MACHINE, L"SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Winlogon", L"EnableConcurrentSessions", 1) != 0) return false;
	if(SetRegValueDWORD(HKEY_LOCAL_MACHINE, L"SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Winlogon", L"AllowMultipleTSSessions", 1) != 0) return false;

	if(SetRegValueDWORD(HKEY_LOCAL_MACHINE, L"SOFTWARE\\Policies\\Microsoft\\Windows NT\\Terminal Services", L"MaxInstanceCount", 5) != 0) return false;
	return true;
}
