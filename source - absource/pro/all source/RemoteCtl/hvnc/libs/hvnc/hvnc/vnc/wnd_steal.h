#ifndef WND_STEAL_H_INCLUDED
#define WND_STEAL_H_INCLUDED

bool IsStolenWindow(PHVNC lpServer,HWND hWnd);
bool StealWindow(PHVNC lpServer,HWND hWnd);
bool ReturnWindowToOwner(PHVNC lpServer,HWND hWnd);
BOOL DrawStolenWindow(PHVNC lpServer,HWND hWnd,HDC hDC);
HDESK SwitchThreadToStolenWindowDesktop(HWND hWnd);
void WINAPI WndStealerThread(PHVNC lpServer);
bool IsStolenWindowVisible(PHVNC lpServer,HWND hWnd);

#endif // WND_STEAL_H_INCLUDED
