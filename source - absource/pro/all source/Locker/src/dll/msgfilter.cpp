#include <windows.h>
#include <time.h>
#include <stdio.h>
#include <process.h>
#include <hash_map>
#include <list>
#include <shlwapi.h>

#include "dprint.h"
#include "threading.h"
#include "msgfilter.h"


MsgFilter& MsgFilter::Instance()
{
  static MsgFilter instance;
  return instance;
}

LRESULT CALLBACK 
MsgFilter::FilterFunction(
  HWND    hwnd, 
  UINT    msg, 
  WPARAM  wp, 
  LPARAM  lp
  )
{
  return MsgFilter::Instance().FilterWndProcMsg(hwnd, msg, wp, lp);
}

bool KeyboardMustBeFiltered()
{
  const WORD kKeyState_DownFlag = 0x8000;

  if ((GetKeyState(VK_CONTROL)  & kKeyState_DownFlag) || 
      (GetKeyState(VK_LCONTROL) & kKeyState_DownFlag) || 
      (GetKeyState(VK_RCONTROL) & kKeyState_DownFlag) ||
      (GetKeyState(VK_MENU)     & kKeyState_DownFlag) || 
      (GetKeyState(VK_LMENU)    & kKeyState_DownFlag) || 
      (GetKeyState(VK_RMENU)    & kKeyState_DownFlag))
  {
    WORD c  = GetKeyState(VK_CONTROL);
    WORD cl = GetKeyState(VK_LCONTROL);
    WORD cr = GetKeyState(VK_RCONTROL);
    WORD a  = GetKeyState(VK_MENU);
    WORD al = GetKeyState(VK_LMENU);
    WORD ar = GetKeyState(VK_RMENU);
    
    PP_DPRINTF(
      L"KeyboardMustBeFiltered: pid=%d "
      L"VK_CONTROL=0x%X VK_LCONTROL=0x%X VK_RCONTROL=0x%X "
      L"VK_MENU=0x%X VK_LMENU=0x%X VK_RMENU=0x%X",
      GetCurrentProcessId(),
      c, cl, cr,
      a, al, ar
      );

    return true;
  }
  return false;
}

LRESULT MsgFilter::FilterWndProcMsg(
  HWND hwnd, UINT msg, WPARAM wp, LPARAM lp)
{
  if (msg == WM_HOTKEY)
  {
    bool ctrl_alt_pressed = ((lp & (MOD_CONTROL | MOD_ALT)) != 0);

    PP_DPRINTF(
      L"MsgFilter::FilterWndProcMsg: filtered WM_HOTKEY pid=%d hwnd=0x%X ctrl_alt_pressed=%d lp=0x%X",
      GetCurrentProcessId(),
      hwnd,
      ctrl_alt_pressed,
      lp
      );
    return 0;
  }

  if (KeyboardMustBeFiltered())
  {
    return 0;
  }

  WNDPROC proc = LookupWndProc(hwnd);
  if (proc != NULL)
  {
    return CallWindowProc(proc, hwnd, msg, wp, lp);
  }
  return 0;
}

LRESULT CALLBACK MsgFilter::KbdHookFunction(int code,WPARAM wp,LPARAM lp)
{
  return MsgFilter::Instance().FilterKeyboardHook(code, wp, lp);
}

LRESULT CALLBACK MsgFilter::MouHookFunction(int code, WPARAM wp, LPARAM lp)
{
  return MsgFilter::Instance().FilterMouseHook(code, wp, lp);
}

LRESULT MsgFilter::FilterKeyboardHook(int code,WPARAM wParam,LPARAM lParam)
{
  DWORD th_id = GetCurrentThreadId();
  HHOOK hook  = LookupKeyboardHook(th_id);
  
  if (hook == NULL)
  {
    PP_DPRINTF(L"MsgFilter::FilterKeyboardHook: hook not found th_id=0x%X",
      th_id);
    return 1;
  }

  if (KeyboardMustBeFiltered())
  {
    return 1;
  }
  return CallNextHookEx(hook,code,wParam,lParam);
}

LRESULT MsgFilter::FilterMouseHook(int code,WPARAM wParam,LPARAM lParam)
{
  DWORD th_id = GetCurrentThreadId();
  HHOOK hook = MsgFilter::LookupMouseHook(th_id);
  
  if (hook == NULL)
  {
    PP_DPRINTF(L"MsgFilter::FilterMouseHook: hook not found th_id=0x%X",
      th_id);
    return 1;
  }

  if ((wParam == WM_RBUTTONUP) || (wParam == WM_RBUTTONDOWN))
  {
    PP_DPRINTF(L"MsgFilter::FilterMouseHook: hook OK.");
    return 1;
  }
  return CallNextHookEx(hook,code,wParam,lParam);
}

void MsgFilter::SetWndProcFilter(HWND hwnd)
{
  if (LookupWndProc(hwnd) != NULL) return;

  CriticalSection::Lock lock(m_lock_object);

  WNDPROC old_proc = (WNDPROC)SetWindowLong(hwnd, GWL_WNDPROC, 
    (LONG_PTR)MsgFilter::FilterFunction);  

  if (old_proc == NULL)
  {
    DWORD e = GetLastError();
    PP_DPRINTF(L"SetWndThreadHookFilter: ERROR: hwnd=0x%X old_proc=0x%p error=%d",
      hwnd, old_proc, e);

    return;
  }

  PP_DPRINTF(L"SetWndThreadHookFilter: hwnd=0x%X old_proc=0x%p",
    hwnd, old_proc);

  m_proc_table[hwnd] = old_proc;
}

void MsgFilter::SetWndThreadHookFilter(HWND hwnd)
{
  CriticalSection::Lock lock(m_lock_object);
  DWORD                 pid = 0;
  DWORD                 th_id = 0;

	th_id = GetWindowThreadProcessId(hwnd, &pid);

  if (m_hook_table.find(th_id) != m_hook_table.end())
  {
    return;
  }

  m_hook_table[th_id] = HookHandles();

  m_hook_table[th_id].kbrd_hook = SetWindowsHookEx(WH_KEYBOARD,
    MsgFilter::KbdHookFunction,NULL,th_id);

  m_hook_table[th_id].mouse_hook = SetWindowsHookEx(WH_MOUSE,
    MsgFilter::MouHookFunction,NULL,th_id);

  PP_DPRINTF(L"SetWndThreadHookFilter: hooked: hwnd=0x%X th_id=0x%X "
    L"kb_hook=0x%X mouse_hook=0x%X",
    hwnd, th_id, m_hook_table[th_id].kbrd_hook, 
    m_hook_table[th_id].mouse_hook);
}

HHOOK MsgFilter::LookupMouseHook(DWORD th_id)
{
  CriticalSection::Lock           lock(m_lock_object);
  Thread2HookMap::const_iterator  e = m_hook_table.find(th_id);

  if (e != m_hook_table.end())
  {
    return e->second.mouse_hook;
  }
  return NULL;
}

HHOOK MsgFilter::LookupKeyboardHook(DWORD th_id)
{
  CriticalSection::Lock          lock(m_lock_object);
  Thread2HookMap::const_iterator e = m_hook_table.find(th_id);

  if (e != m_hook_table.end())
  {
    return e->second.kbrd_hook;
  }
  return NULL;
}

WNDPROC MsgFilter::LookupWndProc(HWND hwnd)
{
  CriticalSection::Lock           lock(m_lock_object);
  Hwnd2WndProcMap::const_iterator e = m_proc_table.find(hwnd);

  if (e != m_proc_table.end())
  {
    return e->second;
  }
  return NULL;
}
