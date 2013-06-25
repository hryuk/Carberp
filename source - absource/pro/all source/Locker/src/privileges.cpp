#include <windows.h>
#include "privileges.h"
#include "dprint.h"

//-----------------------------------------------------------------------------
bool SwitchDebugPrivileges(bool enabled)
{
  TOKEN_PRIVILEGES    privs = {0};
  HANDLE              token = NULL;
  bool                result = false;

  if (OpenProcessToken(
		  GetCurrentProcess(),
		  TOKEN_ADJUST_PRIVILEGES | TOKEN_QUERY,
		  &token))
  {
	  privs.PrivilegeCount           = 1;
	  privs.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;

    if (!enabled)
    {
      privs.Privileges[0].Attributes = 0;
    }

    BOOL  r = 0;
    DWORD last_error = 0;
	
	  r= LookupPrivilegeValue(NULL, SE_DEBUG_NAME,
			  &privs.Privileges[0].Luid);
	
	  r = AdjustTokenPrivileges(token, FALSE, &privs, 0, NULL, NULL);
    last_error = GetLastError();
    CloseHandle(token);

    PP_DPRINTF(L"SwitchDebugPrivileges: enabled=%d result=%d last_error=%d", 
      enabled, r, last_error);
    
    result = (last_error == ERROR_SUCCESS);
  }
  return result;
}
//-----------------------------------------------------------------------------
ScopedDebugPrivilege::ScopedDebugPrivilege()
{
  m_enabled = SwitchDebugPrivileges(true);
}
//-----------------------------------------------------------------------------
ScopedDebugPrivilege::~ScopedDebugPrivilege()
{
  SwitchDebugPrivileges(false);
}
//-----------------------------------------------------------------------------
bool ScopedDebugPrivilege::Enabled()
{
  return m_enabled;
}
