#ifndef UUID_7CA562F7029D4E4196489C3B16DA134D
#define UUID_7CA562F7029D4E4196489C3B16DA134D

class MsgFilter
{
  struct HookHandles
  {
    HHOOK kbrd_hook;
    HHOOK mouse_hook;
  };

  typedef stdext::hash_map<HWND, WNDPROC>  Hwnd2WndProcMap;
  typedef stdext::hash_map<DWORD, HookHandles> Thread2HookMap;

public:
  static MsgFilter& Instance();
  
  void SetWndThreadHookFilter(HWND hwnd);
  void SetWndProcFilter(HWND hwnd);

private:
  static LRESULT CALLBACK FilterFunction(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp);
  static LRESULT CALLBACK KbdHookFunction(int code,WPARAM wParam,LPARAM lParam);
  static LRESULT CALLBACK MouHookFunction(int code,WPARAM wParam,LPARAM lParam);

  WNDPROC LookupWndProc(HWND hwnd);
  HHOOK   LookupMouseHook(DWORD th_id);
  HHOOK   LookupKeyboardHook(DWORD th_id);

  LRESULT FilterWndProcMsg(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp);
  LRESULT FilterKeyboardHook(int code,WPARAM wParam,LPARAM lParam);
  LRESULT FilterMouseHook(int code,WPARAM wParam,LPARAM lParam);  

  CriticalSection m_lock_object;
  Hwnd2WndProcMap m_proc_table;
  Thread2HookMap  m_hook_table;
};


#endif // #ifndef UUID_7CA562F7029D4E4196489C3B16DA134D