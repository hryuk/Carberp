extern "C"
{
bool SendString(HWND hWnd,TCHAR *lpString);
bool ClickMouse(HWND hWnd,DWORD dwX,DWORD dwY,bool bRBtn=false);
bool KeySend(HWND hWnd,bool bE);
};

