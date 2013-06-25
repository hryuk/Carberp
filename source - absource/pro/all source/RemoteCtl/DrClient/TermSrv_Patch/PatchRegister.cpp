#include "stdafx.h"
#include "PatchRegister.h"

int SetRegValueDWORD(HKEY RootKey, LPTSTR SubKey, LPTSTR ValueName, DWORD Data)
{
	HKEY Key;
	if(RegOpenKeyEx(RootKey, SubKey, 0, KEY_WRITE, &Key) != ERROR_SUCCESS) return 1;
	if(RegSetValueEx(Key, ValueName, NULL, REG_DWORD, (BYTE*)&Data, sizeof(DWORD)) != ERROR_SUCCESS)
	{
		RegCloseKey(Key);
		return 2;
	}
	RegCloseKey(Key);
	return 0;	
}

int SetRegValueSZ(HKEY RootKey, LPTSTR SubKey, LPTSTR ValueName, LPTSTR Data, DWORD DataLen)
{
	HKEY Key;
	if(RegOpenKeyEx(RootKey, SubKey, 0, KEY_WRITE, &Key) != ERROR_SUCCESS) return 1;
	if(RegSetValueEx(Key, ValueName, NULL, REG_SZ, (BYTE*)Data, DataLen) != ERROR_SUCCESS)
	{
		RegCloseKey(Key);
		return 2;
	}
	RegCloseKey(Key);
	return 0;	
}

bool IsValueExist(HKEY RootKey, LPTSTR SubKey, LPTSTR ValueNameTarg, BYTE* Data, DWORD* DataLen, DWORD* Type)
{
	HKEY Key;
	if(RegOpenKeyEx(RootKey, SubKey, 0, KEY_READ, &Key) != ERROR_SUCCESS) return false;
	int ind = 0;
	WCHAR ValueName[256];
	DWORD ValueNameLen = 256;
	bool sw_find = 0;
	while(RegEnumValue(Key, ind, &ValueName[0], &ValueNameLen, NULL, Type, Data, DataLen) != ERROR_NO_MORE_ITEMS)
	{
		if(wcscmp(ValueNameTarg, &ValueName[0]) == 0)
		{
			sw_find = true;
			break;
		}
		ind++;
		ValueNameLen = 256;
	}
	RegCloseKey(Key);
	if(sw_find) return true;
	return false;
}

bool PatchVista()
{
	if(SetRegValueDWORD(HKEY_LOCAL_MACHINE, L"SYSTEM\\CurrentControlSet\\Control\\Terminal Server", L"fDenyTSConnections", 0) != 0) return false;
	if(SetRegValueDWORD(HKEY_LOCAL_MACHINE, L"SYSTEM\\CurrentControlSet\\Control\\Terminal Server", L"fSingleSessionPerUser", 0) != 0) return false;
	return true;
}

int PatchXP()
{
	if(SetRegValueDWORD(HKEY_LOCAL_MACHINE, L"SYSTEM\\ControlSet001\\Control\\Terminal Server", L"fDenyTSConnections", 0) != 0) return 1;
	if(SetRegValueDWORD(HKEY_LOCAL_MACHINE, L"SYSTEM\\ControlSet001\\Control\\Terminal Server", L"TSAdvertise", 1) != 0) return 2;
	if(SetRegValueDWORD(HKEY_LOCAL_MACHINE, L"SYSTEM\\ControlSet001\\Control\\Terminal Server", L"IdleWinStationPoolCount", 1) != 0) return 3;

	if(SetRegValueDWORD(HKEY_LOCAL_MACHINE, L"SYSTEM\\ControlSet001\\Control\\Terminal Server\\Licensing Core", L"EnableConcurrentSessions", 0) != 0) return 4;

	if(SetRegValueDWORD(HKEY_LOCAL_MACHINE, L"SYSTEM\\CurrentControlSet\\Control\\Terminal Server", L"fDenyTSConnections", 0) != 0) return 5;
	if(SetRegValueDWORD(HKEY_LOCAL_MACHINE, L"SYSTEM\\CurrentControlSet\\Control\\Terminal Server", L"TSAdvertise", 1) != 0) return 6;
	if(SetRegValueDWORD(HKEY_LOCAL_MACHINE, L"SYSTEM\\CurrentControlSet\\Control\\Terminal Server", L"IdleWinStationPoolCount", 1) != 0) return 7;

	if(SetRegValueDWORD(HKEY_LOCAL_MACHINE, L"SYSTEM\\CurrentControlSet\\Control\\Terminal Server\\Licensing Core", L"EnableConcurrentSessions", 0) != 0) return 8;


	//RegCreateKeyEx(
	HKEY hKey;
	DWORD res = 0;
	if(RegCreateKeyEx(HKEY_LOCAL_MACHINE, L"SYSTEM\\CurrentControlSet\\Services\\SharedAccess\\Parameters\\FirewallPolicy\\StandardProfile\\GloballyOpenPorts",NULL, NULL, REG_OPTION_NON_VOLATILE, KEY_ALL_ACCESS, NULL, &hKey, &res) == ERROR_SUCCESS) {
		RegCloseKey(hKey);
		if(RegCreateKeyEx(HKEY_LOCAL_MACHINE, L"SYSTEM\\CurrentControlSet\\Services\\SharedAccess\\Parameters\\FirewallPolicy\\StandardProfile\\GloballyOpenPorts\\list",NULL, NULL, REG_OPTION_NON_VOLATILE, KEY_ALL_ACCESS, NULL, &hKey, &res) == ERROR_SUCCESS) {
			RegCloseKey(hKey);
			if(SetRegValueSZ(HKEY_LOCAL_MACHINE, L"SYSTEM\\CurrentControlSet\\Services\\SharedAccess\\Parameters\\FirewallPolicy\\StandardProfile\\GloballyOpenPorts\\List", L"3389:TCP", L"3389:TCP:*:Enabled:@xpsp2res.dll,-22009", wcslen(L"3389:TCP:*:Enabled:@xpsp2res.dll,-22009")*sizeof(TCHAR)) != 0) return 9;
		}
	}
	return 0;
}
