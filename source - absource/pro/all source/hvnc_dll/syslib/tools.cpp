#include <winsock2.h>
#include <ws2tcpip.h>
#include <iphlpapi.h>
#include <windows.h>
#include "syslib.h"
#include <shlobj.h>
#include <shlwapi.h>
#include <intrin.h>

extern "C" void *MemAlloc(size_t dwSize);
extern "C" void *MemRealloc(void *lpMem,size_t dwSize);
extern "C" void MemFree(void *lpMem);

int CompareObjects(HANDLE hObj1,HANDLE hObj2)
{
    if ((!hObj1) || (!hObj2))
        return 1;

	TCHAR szName1[256],szName2[256];
	if ((!GetUserObjectInformation(hObj1,UOI_NAME,szName1,sizeof(szName1),NULL)) || (!GetUserObjectInformation(hObj2,UOI_NAME,szName2,sizeof(szName2),NULL)))
		return 1;
	return lstrcmpi(szName1,szName2);
}

extern unsigned long x=0x12345678;
unsigned long xor128(int val)
{
    static unsigned long y=362436069,
                         z=521288629,
                         w=88675123;
    if (x == 0x12345678)
        Init_xor128();
    unsigned long t;
    t=(x^(x<<11));
    x=y;
    y=z;
    z=w;
    w=(w^(w>>19))^(t^(t>>8));
    return (w%(val*100))/100;
}

#pragma intrinsic(__rdtsc)

void Init_xor128()
{
    x=(ULONG)__rdtsc();
    return;
}

void hex2str(u_int dwHex,char *lpStr)
{
    char *szTbl="1234567890ABCDEF",szTmpStr[8],*p=szTmpStr,*p2=lpStr,dwCount=0;

    while (dwHex)
    {
        char chr;
        chr=dwHex & 0xF;
        *p++=szTbl[chr];
        dwHex >>= 4;
        dwCount++;
    }
    p--;
    if (dwCount<8)
        for (int i=0; i<8-dwCount; i++)
            *p2++='0';

    for (int i=0; i<dwCount; i++)
        *p2++=*p--;

    *p2=0;
    return;
}

LPWSTR ParentDir(LPWSTR path)
{
    LPWSTR ret=0;
    int len=lstrlenW(path);
    LPWSTR ptr=path+len;
    if (*ptr == L'\\')
        --ptr;
    while (ptr > path)
    {
        if (*ptr == L'\\')
        {
            *ptr = 0;
            return path;
        }
        --ptr;
    }
    return 0;
}

void GetUserDirA(char *lpOut)
{
    WCHAR tmp[512];
    GetUserDirW(tmp);
    int size=lstrlenW(tmp)+1;
    int destSize=WideCharToMultiByte(CP_ACP,0,tmp,size,lpOut,0,NULL,NULL);
    if (destSize > 0)
        WideCharToMultiByte(CP_ACP,0,tmp,size,lpOut,destSize,NULL,NULL);
    return;
}

void GetUserDirW(WCHAR *lpOut)
{
    OSVERSIONINFO osvi={0};
    osvi.dwOSVersionInfoSize=sizeof(osvi);
    GetVersionEx(&osvi);
    SHGetFolderPathW(0,CSIDL_APPDATA,0,SHGFP_TYPE_CURRENT,lpOut);
    /**if (osvi.dwMajorVersion >= 6)
    {
        ParentDir(lpOut);
        PathAppendW(lpOut,L"LocalLow");
    }*/
    lstrcatW(lpOut,L"\\Microsoft\\Windows\\WSUS");
    return;
}

bool NetworkIsConnectionEstablished(char *lpAddress,WORD wPort)
{
    bool bRet=false;
    PMIB_TCPTABLE lpTcpTable=NULL;

    do
    {
        if ((!lpAddress) || (!wPort))
            break;

        DWORD dwAddr=inet_addr(lpAddress);
        if (!dwAddr)
            break;

        DWORD dwSize=0,dwError=GetTcpTable(NULL,&dwSize,TRUE);
        if (dwError == ERROR_INSUFFICIENT_BUFFER)
        {
            lpTcpTable=(PMIB_TCPTABLE)MemAlloc(dwSize);
            if (!lpTcpTable)
                break;

            dwError=GetTcpTable(lpTcpTable,&dwSize,TRUE);
        }

        if (!lpTcpTable)
            break;

        if ((dwError != NO_ERROR) || (!lpTcpTable->dwNumEntries))
        {
            bRet=true;
            break;
        }
        wPort=htons(wPort);
        for (DWORD i=0; i < lpTcpTable->dwNumEntries; i++)
        {
            if ((lpTcpTable->table[i].dwRemoteAddr == dwAddr) && (lpTcpTable->table[i].dwRemotePort == wPort) && (lpTcpTable->table[i].State == MIB_TCP_STATE_ESTAB))
            {
                bRet=true;
                break;
            }
        }
    }
    while (false);
    if (lpTcpTable)
        MemFree(lpTcpTable);

    return bRet;
}

TCHAR *GetTmpFileName()
{
    TCHAR *lpBuf=NULL,szTmpDir[MAX_PATH];
    if (GetTempPath(sizeof(szTmpDir)/sizeof(szTmpDir[0]),szTmpDir))
    {
        TCHAR szTmpFile[MAX_PATH];
        if (GetTempFileName(szTmpDir,TEXT("cab"),0,szTmpFile))
        {
            lpBuf=(TCHAR*)MemAlloc(lstrlen(szTmpFile)*sizeof(TCHAR));
            lstrcpy(lpBuf,szTmpFile);
        }
    }
    return lpBuf;
}

