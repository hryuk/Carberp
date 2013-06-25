#ifndef HOOK_API_H_INCLUDED
#define HOOK_API_H_INCLUDED

#include <winsock.h>

#include "stdint.h"

#ifdef _AMD64_
#include "hde64\hde64.h"
#define hdes hde64s
#else
#include "hde32\hde32.h"
#define hdes hde32s
#endif

#define MAX_HOOKS 500

typedef struct _HOOK_INFO
{
    LPVOID lpRealFunc;
    LPVOID lpHandler;
    LPVOID lpBridge;
    LPVOID lpBackup;
#ifdef _AMD64_
    LPVOID lpRelay;
    LPVOID lpTable;
#endif
    SIZE_T dwCodeSize;
} HOOK_INFO, *PHOOK_INFO;

void InitAPIHook();
void *HookAPI(LPVOID lpFunc,LPVOID lpHandler);
PHOOK_INFO GetHookInfo(LPVOID lpFunc);
void UnhookAPI(LPVOID lpFunc);
void UnhookAll();
LPVOID GetRealFunc(LPVOID lpHandler);
void *CreateBridge(LPVOID lpFunc,LPVOID lpBackup,ULONG_PTR *lpTable);

#ifdef _X86_
#define SizeOfCode(x) hde32_disasm(x,&hs)
#else
#define SizeOfCode(x) hde64_disasm(x,&hs)
#endif

extern CRITICAL_SECTION csHookApi;

extern int NumOfHooks;
extern HOOK_INFO hooks[MAX_HOOKS+1];

#pragma pack(push, 1)
struct JMP_REL
{
    byte  opcode;
    DWORD operand;
};
typedef JMP_REL CALL_REL;

struct JMP_ABS
{
    WORD  opcode;
    DWORD operand;
};
typedef JMP_ABS CALL_ABS,JCC_REL;

struct JCC_ABS
{
    byte  opcode;
    byte  dummy0;
    byte  dummy1;
    byte  dummy2;
    WORD  dummy3;
    DWORD operand;
};
#pragma pack(pop)

struct TEMP_ADDR
{
    LPVOID lpAddress;
    SIZE_T dwPosition;
    SIZE_T dwPc;
};

#define JUMP_SIZE sizeof(JMP_REL)

#define MAX_JUMPS 20

#define LODWORD(l) ((DWORD)((DWORDLONG)(l)))
#define HIDWORD(l) ((DWORD)(((DWORDLONG)(l)>>32)&0xFFFFFFFF))
#define MAKEDWORDLONG(a,b) ((DWORDLONG)(((DWORD)(a))|(((DWORDLONG)((DWORD)(b)))<<32)))

#endif // HOOK_API_H_INCLUDED
