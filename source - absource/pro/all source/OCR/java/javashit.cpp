#include <windows.h>

extern "C" __declspec(dllexport) bool SendString(HWND hWnd,TCHAR *lpString)
{
    bool bRet=false;
    if (IsWindow(hWnd))
    {
        DWORD dwPID,
              dwTID=GetWindowThreadProcessId(hWnd,&dwPID),
              dwCurThreadID=GetCurrentThreadId();
        HANDLE hProc=OpenProcess(PROCESS_QUERY_INFORMATION+SYNCHRONIZE,false,dwPID);
        if (hProc)
        {
            AttachThreadInput(dwCurThreadID,dwTID,true);

            TCHAR *p=lpString;
            while (*p)
            {
                PostMessage(hWnd,WM_KEYDOWN,*p,(MapVirtualKey(*p,0) << 16) | 1);
                WaitForInputIdle(hProc,INFINITE);

                PostMessage(hWnd,WM_KEYUP,*p,(1 << 31) | (1 << 30) | (MapVirtualKey(*p,0) << 16) | 1);
                WaitForInputIdle(hProc,INFINITE);

                p++;
            }

            AttachThreadInput(dwCurThreadID,dwTID,false);
            bRet=true;
        }
    }
    return bRet;
}

extern "C" __declspec(dllexport) bool ClickMouse(HWND hWnd,DWORD dwX,DWORD dwY,bool bRBtn=false)
{
    bool bRet=false;
    if (IsWindow(hWnd))
    {
        DWORD dwPID,
              dwTID=GetWindowThreadProcessId(hWnd,&dwPID),
              dwCurThreadID=GetCurrentThreadId();
        HANDLE hProc=OpenProcess(PROCESS_QUERY_INFORMATION+SYNCHRONIZE,false,dwPID);
        if (hProc)
        {
            AttachThreadInput(dwCurThreadID,dwTID,true);

            PostMessage(hWnd,(bRBtn) ? WM_RBUTTONDOWN : WM_LBUTTONDOWN,(bRBtn) ? MK_RBUTTON : MK_LBUTTON,MAKELPARAM(dwX,dwY));
            WaitForInputIdle(hProc,INFINITE);

            PostMessage(hWnd,(bRBtn) ? WM_RBUTTONUP : WM_LBUTTONUP,NULL,MAKELPARAM(dwX,dwY));
            WaitForInputIdle(hProc,INFINITE);

            AttachThreadInput(dwCurThreadID,dwTID,false);
            bRet=true;
        }
        CloseHandle(hProc);
    }
    return bRet;
}

extern "C" __declspec(dllexport) bool KeySend(HWND hWnd,bool bE)
{
    bool bRet=false;
    if (IsWindow(hWnd))
    {
        byte bKey=(bE) ? 'E' : 'S';
        DWORD dwKey1lParam1=(MapVirtualKey(VK_CONTROL,0) << 16) | 1,
              dwKey1lParam2=(1 << 31) | (1 << 30) | (MapVirtualKey(VK_CONTROL,0) << 16) | 1,
              dwKey2lParam1=(MapVirtualKey(bKey,0) << 16) | 1,
              dwKey2lParam2=(1 << 31) | (1 << 30) | (MapVirtualKey(bKey,0) << 16) | 1;

        DWORD dwPID,
              dwTID=GetWindowThreadProcessId(hWnd,&dwPID),
              dwCurThreadID=GetCurrentThreadId();
        HANDLE hProc=OpenProcess(PROCESS_QUERY_INFORMATION+SYNCHRONIZE,false,dwPID);
        if (hProc)
        {
            AttachThreadInput(dwCurThreadID,dwTID,true);

            PostMessage(hWnd,WM_KEYDOWN,VK_CONTROL,dwKey1lParam1);
            WaitForInputIdle(hProc,INFINITE);

            BYTE bState[256];
            GetKeyboardState(bState);
            bState[VK_CONTROL]=0x80;
            SetKeyboardState(bState);

            PostMessage(hWnd,WM_KEYDOWN,bKey,dwKey2lParam1);
            WaitForInputIdle(hProc,INFINITE);

            PostMessage(hWnd,WM_KEYUP,bKey,dwKey2lParam2);
            WaitForInputIdle(hProc,INFINITE);

            PostMessage(hWnd,WM_KEYUP,VK_CONTROL,dwKey1lParam2);
            WaitForInputIdle(hProc,INFINITE);

            AttachThreadInput(dwCurThreadID,dwTID,false);
            bRet=true;
        }
        CloseHandle(hProc);
    }
    return bRet;
}
