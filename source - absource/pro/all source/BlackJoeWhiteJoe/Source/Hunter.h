#ifndef HunterH
#define HunterH 
#include "windows.h"
#include <wininet.h>

void IsBankHunter( HINTERNET hRequest );
void StartHunt();	
DWORD WINAPI RunHuntThred( LPVOID lpData );
void Hunting();


#endif