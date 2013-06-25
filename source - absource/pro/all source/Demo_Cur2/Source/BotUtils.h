#include <windows.h>

DWORD GetNameHash( WCHAR *Path );
DWORD GetBotHash();

WCHAR *GetNameFromPath( WCHAR *Path );
WCHAR *GetShellFoldersKey( DWORD dwParam );

WCHAR *GetTempName();