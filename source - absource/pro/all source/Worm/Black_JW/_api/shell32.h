
//@S
HANDLE _SHELL32=0;

HRESULT (WINAPI *_SHGetFolderPath)(HWND hwndOwner,int nFolder,HANDLE hToken,DWORD dwFlags,LPTSTR pszPath);
//@E

void InitShell32()
{
 _SHELL32 = _GetModuleHandle("shell32.dll"); //fix strange "POP ECX"
 if (/*@S==*/_SHELL32 == NULL/*@E*/) _SHELL32 = _LoadLibrary("shell32.dll");

 _SHGetFolderPath = (DWORD *)_GetProcAddress(_SHELL32,"SHGetFolderPathA");
}
