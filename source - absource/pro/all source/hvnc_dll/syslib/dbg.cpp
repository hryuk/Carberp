#include <winsock2.h>
#include "system.h"
#include "mem.h"
#include <tchar.h>
#include <wininet.h>

TCHAR *GetTmpFileName();
bool IsUserAdmin();

#ifdef _DEBUG
static void PIDToProcName(DWORD dwPID,TCHAR *szOutBuff)
{
    HANDLE hSnap=CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS,0);
    PROCESSENTRY32 ppe;
    ppe.dwSize=sizeof(PROCESSENTRY32);
    Process32First(hSnap,&ppe);
    TCHAR *lpNewName=_T("unknown");

    do
    {
        if (ppe.th32ProcessID == dwPID)
        {
            lpNewName=ppe.szExeFile;
            break;
        }
    }
    while(Process32Next(hSnap,&ppe));
    SysCloseHandle(hSnap);

    lstrcpy(szOutBuff,lpNewName);

    return;
}
#endif

extern "C" void dprintf(TCHAR *msg, ...)
{
#ifdef _DEBUG
    TCHAR *buff=(TCHAR *)MemAlloc(1024*sizeof(TCHAR)),*obuff=(TCHAR *)MemAlloc(1024*sizeof(TCHAR));

    va_list mylist;

    va_start(mylist, msg);
    wvsprintf(buff, msg, mylist);
    va_end(mylist);

    TCHAR szProcName[50];
    PIDToProcName(GetCurrentProcessId(),szProcName);

#ifdef _X86_
    wsprintf(obuff,_T("[%s *32], %s"),szProcName,buff);
#else
    wsprintf(obuff,_T("[%s *64], %s"),szProcName,buff);
#endif

    OutputDebugString(obuff);

    MemFree(buff);
    MemFree(obuff);
#endif
    return;
}

extern "C" void dprintf_wnd(HWND hWnd,TCHAR *lpStr)
{
#ifdef _DEBUG
    TCHAR szClass[260],szTitle[260];
    DWORD dwStyle=0,dwExStyle=0;
    if (hWnd)
    {
        GetClassName(hWnd,szClass,260);
        if (!GetWindowText(hWnd,szTitle,260))
            lstrcpy(szTitle,_T("NULL"));
        dwStyle=GetWindowLongPtr(hWnd,GWL_STYLE);
        dwExStyle=GetWindowLongPtr(hWnd,GWL_EXSTYLE);
    }
    else
    {
        lstrcpy(szClass,_T("NULL"));
        lstrcpy(szTitle,_T("NULL"));
    }
    dprintf(_T("%s[%s] %X, %X, %s"),lpStr,szClass,dwStyle,dwExStyle,szTitle);
#endif
    return;
}

extern "C" void WebLog(TCHAR *lpHost,TCHAR *lpFile,int dwLine,bool bWSA,TCHAR *lpMsg)
{
#ifdef _DEBUG
    if (!lpHost)
        return;

	TCHAR szMessage[MAX_PATH],
          *lpTmpFile=GetTmpFileName(),
          szLastError[MAX_PATH];

    if (!bWSA)
        wsprintf(szLastError,_T("GetLastErorr=%X"),GetLastError());
    else
        wsprintf(szLastError,_T("WSAGetLastError=%X"),WSAGetLastError());

    wsprintf(szMessage,_T("%s=%s:%d;%s;%s;%s"),lpHost,lpFile,dwLine,szLastError,IsUserAdmin() ? _T("A") : _T("U"),lpMsg);
	DeleteUrlCacheEntry(szMessage);
	URLDownloadToFile(0,szMessage,lpTmpFile,0,0);
	DeleteFile(lpTmpFile);

    MemFree(lpTmpFile);
#endif
    return;
}

