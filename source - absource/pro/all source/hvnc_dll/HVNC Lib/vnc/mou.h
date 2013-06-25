#ifndef MOU_H_INCLUDED
#define MOU_H_INCLUDED

void ProcessMouMsg(PHVNC lpServer,DWORD dwFlags,LONG dwX,LONG dwY,DWORD dwData);
HWND ChangeMouseCapture(PHVNC lpServer,DWORD dwThreadID,HWND hNewWnd,WORD wNewArea,bool bPost);

#define MASK_POINTER_BUTTON_LEFT   0x01
#define MASK_POINTER_BUTTON_MIDDLE 0x02
#define MASK_POINTER_BUTTON_RIGHT  0x04
#define MASK_POINTER_WHEEL_UP      0x08
#define MASK_POINTER_WHEEL_DOWN    0x10

#define WHEEL_DELTA 120

extern DWORD dwDoubleClickTime;

#endif // MOU_H_INCLUDED
