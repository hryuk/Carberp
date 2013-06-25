#ifndef VNCCLIPBOARD_H_INCLUDED
#define VNCCLIPBOARD_H_INCLUDED

#define CB_CONTAINS_TEXT	1
#define CB_CONTAINS_OEM		2
#define CB_CONTAINS_UNICODE	4

DWORD GetRealClipboardTextFormats();

typedef BOOL WINAPI __CloseClipboard(VOID);
BOOL WINAPI CloseClipboard_handler(VOID);

typedef int WINAPI __CountClipboardFormats(VOID);
int WINAPI CountClipboardFormats_handler(VOID);

typedef BOOL WINAPI __EmptyClipboard(VOID);
BOOL WINAPI EmptyClipboard_handler(VOID);

typedef UINT WINAPI __EnumClipboardFormats(UINT format);
UINT WINAPI EnumClipboardFormats_handler(UINT format);

typedef HANDLE WINAPI __GetClipboardData(UINT uFormat);
HANDLE WINAPI GetClipboardData_handler(UINT uFormat);

typedef int WINAPI __GetPriorityClipboardFormat(UINT *paFormatPriorityList,int cFormats);
int WINAPI GetPriorityClipboardFormat_handler(UINT *paFormatPriorityList,int cFormats);

typedef BOOL WINAPI __GetUpdatedClipboardFormats(PUINT lpuiFormats,UINT cFormats,PUINT pcFormatsOut);
BOOL WINAPI GetUpdatedClipboardFormats_handler(PUINT lpuiFormats,UINT cFormats,PUINT pcFormatsOut);

typedef BOOL WINAPI __IsClipboardFormatAvailable(UINT format);
BOOL WINAPI IsClipboardFormatAvailable_handler(UINT format);

typedef BOOL WINAPI __OpenClipboard(HWND hWndNewOwner);
BOOL WINAPI OpenClipboard_handler(HWND hWndNewOwner);

typedef HANDLE WINAPI __SetClipboardData(UINT uFormat,HANDLE hMem);
HANDLE WINAPI SetClipboardData_handler(UINT uFormat,HANDLE hMem);

EXTERN_HOOK(CloseClipboard)
EXTERN_HOOK(CountClipboardFormats)
EXTERN_HOOK(EmptyClipboard);
EXTERN_HOOK(EnumClipboardFormats)
EXTERN_HOOK(GetClipboardData)
EXTERN_HOOK(GetPriorityClipboardFormat)
EXTERN_HOOK(GetUpdatedClipboardFormats)
EXTERN_HOOK(IsClipboardFormatAvailable)
EXTERN_HOOK(OpenClipboard)
EXTERN_HOOK(SetClipboardData)

#endif // VNCCLIPBOARD_H_INCLUDED
