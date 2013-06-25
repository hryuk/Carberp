
#ifndef StealthBrowserH
#define StealthBrowserH
//----------------------------------------------------------------------------

#include <windows.h>



DWORD WINAPI SBThread( LPVOID lpData );

bool ExecuteSBCommand(LPVOID Manager, PCHAR Command, PCHAR Args);
void SetHooksForSB();
DWORD WINAPI RunIeSB( LPVOID lpData );

//----------------------------------------------------------------------------
#endif
