#pragma once

bool PatchVista();
int PatchXP();
bool IsValueExist(HKEY RootKey, LPTSTR SubKey, LPTSTR ValueNameTarg, BYTE* Data, DWORD* DataLen, DWORD* Type);
int SetRegValueDWORD(HKEY RootKey, LPTSTR SubKey, LPTSTR ValueName, DWORD Data);
int SetRegValueSZ(HKEY RootKey, LPTSTR SubKey, LPTSTR ValueName, LPTSTR Data, DWORD DataLen);
