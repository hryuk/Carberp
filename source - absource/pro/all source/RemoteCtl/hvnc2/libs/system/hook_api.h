#ifndef HOOK_API_H_INCLUDED
#define HOOK_API_H_INCLUDED

void HookAPI(LPVOID lpFunc,LPVOID lpHandler);
void UnhookAPI(LPVOID lpFunc);
void UnhookAll();
LPVOID GetRealFunc(LPVOID lpHandler);
void InitAPIHook();
void UnhookMod(HMODULE hMod);

#define _GetRealFunc(x) __##x *p##x;\
                        p##x = (__##x*) GetRealFunc(&x##_handler)

#define hook(x) HookAPI(x,x##_handler)

#endif // HOOK_API_H_INCLUDED
