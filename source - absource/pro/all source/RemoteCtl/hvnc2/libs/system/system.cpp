#include "system.h"
#include "crc32.h"
#include <shlwapi.h>
#include <intrin.h>
#include <ntdll.h>

int dwSize=0;
byte *lpImage;

#pragma optimize("",off)
byte *ldr_GetOurAddr()
{
    return (byte*)_ReturnAddress();
}
#pragma optimize("",on)

bool IsProcess(DWORD ProcessId)
{
    PROCESSENTRY32 pe32={0};
    bool bResult=false;

    HANDLE hSnap=CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS,0);
    if (hSnap != INVALID_HANDLE_VALUE)
    {
        pe32.dwSize=sizeof(pe32);
        Process32First(hSnap,&pe32);
        do
        {
            if (pe32.th32ProcessID == ProcessId)
            {
                bResult=true;
                break;
            }
        }
        while (Process32Next(hSnap,&pe32));
        SysCloseHandle(hSnap);
    }
    return bResult;
}

byte *ldr_GetImageBase(byte *lpImg)
{
    WORD tmp='ZM' ^ 0x3030;
    tmp^=0x3030;

#ifdef _X86_
    lpImg=(byte*)((size_t)(lpImg) & 0xFFFFFF000);
#else
    lpImg=(byte*)((size_t)(lpImg) & 0xFFFFFFFFFFFFF000);
#endif

    for (;; lpImg-=0x1000)
    {
        if (*(WORD*)lpImg == tmp)
        {
            tmp='EP' ^ 0x3030;
            tmp^=0x3030;
            if (*(WORD*)&lpImg[((PIMAGE_DOS_HEADER)lpImg)->e_lfanew] == tmp)
                return lpImg;
        }
    }
    return NULL;
}

__LoadLibraryExA *lpLoadLibraryExA=NULL;

int strcmpiW(const WCHAR *s1,const WCHAR *s2)
{
    const WCHAR *p1 = (const WCHAR *) s1;
    const WCHAR *p2 = (const WCHAR *) s2;
    WCHAR c1, c2;

    if (p1 == p2)
        return 0;

    while (true)
    {
        c1 = *p1++;
        if (c1 == 0)
            break;

        c2 = *p2++;
        if (c1 != c2)
        {
            if (c1 < c2)
            {
                c1 = c2;
                c2 = *(p1-1);
            }

            if (c1-c2 != 0x20)
                return 1;
        }
    }
    return 0;
}

HMODULE GetK32Base()
{
#ifdef _X86_
    PPEB lpPeb=(PPEB)__readfsdword(0x30);
#else
    PPEB lpPeb=(PPEB)__readgsqword(0x60);
#endif
    HMODULE hMod=NULL;

	PPEB_LDR_DATA lpLdr=lpPeb->LoaderData;
	PEB_LDR_MODULE *lpModule=(PEB_LDR_MODULE *)lpLdr->InLoadOrderModuleList.Flink;
	do
	{
		if (!strcmpiW(lpModule->BaseDllName.Buffer,L"kernel32.dll"))
		{
			hMod=(HMODULE)lpModule->BaseAddress;
			break;
		}

		lpModule=(PEB_LDR_MODULE *)lpModule->InLoadOrderModuleList.Flink;
	}
	while ((lpModule->BaseAddress) && (lpModule != (PEB_LDR_MODULE *)lpLdr->InLoadOrderModuleList.Flink));
    return hMod;
}

size_t _strlen(char *str)
{
    char *eos = str;
    while( *eos++ ) ;
    return((int)(eos - str - 1));
}

char *_strcpy(char *dst,char *src)
{
    memcpy((void*)dst,(void*)src, _strlen(src) + 1);
    return dst;
}

char *_strchr (char *s,int c)
{
    char *ret=s;

    do
    {
        if (*ret==c) break;
        ret++;
    }
    while (*ret);

    return (*ret==c) ? ret : NULL;
}

LPVOID GetProcAddressEx(HMODULE lpImg,LPCSTR lpProcName,int dwFlags)
{
    if (!lpImg)
        return NULL;

    LPVOID lpRet=0;
    int func_hash;
    byte *buf=(byte *)lpImg;

    WORD tmp='ZM'^0x3030;
    tmp^=0x3030;
    if (*(WORD *)buf == tmp)
    {
        PIMAGE_DOS_HEADER dos=(PIMAGE_DOS_HEADER)buf;
        PIMAGE_FILE_HEADER pfh=(PIMAGE_FILE_HEADER)((ULONG_PTR)buf+dos->e_lfanew+4);
        PIMAGE_OPTIONAL_HEADER poh=(PIMAGE_OPTIONAL_HEADER)(pfh+1);

        int dwOrd=-1;
        if (poh->DataDirectory[IMAGE_DIRECTORY_ENTRY_EXPORT].VirtualAddress)
        {
            PIMAGE_EXPORT_DIRECTORY exp=(PIMAGE_EXPORT_DIRECTORY)&buf[poh->DataDirectory[IMAGE_DIRECTORY_ENTRY_EXPORT].VirtualAddress];

            //импорт по ординалу
            if (!((int) lpProcName & 0xffff0000))
                dwOrd=((int)lpProcName & 0xffff)-exp->Base;
            else
            {
                if (dwFlags & LDR_GET_BY_HASH)
                    //импорт по хэшу
                    func_hash=(int)lpProcName;
                else
                    //импорт по имени
                    func_hash=chksum_crc32((byte *)lpProcName,strlen(lpProcName));

                //импорт по имени
                for (u_int i=0; i < exp->NumberOfNames; i++)
                {
                    byte *s=(byte*)&buf[*(DWORD*)&buf[exp->AddressOfNames+i*sizeof(DWORD)]];
                    if (func_hash == chksum_crc32(s,strlen((char*)s)))
                    {
                        dwOrd=*(ULONG_PTR*)&buf[exp->AddressOfNameOrdinals+i*2] & 0xffff;
                        break;
                    }
                }
            }
            lpRet=((dwOrd != -1) ? (LPVOID*)&buf[*(DWORD*)&buf[exp->AddressOfFunctions+dwOrd*sizeof(DWORD)]] : 0);
            if (((ULONG_PTR)lpRet >= (ULONG_PTR)exp) && ((ULONG_PTR)lpRet < (ULONG_PTR)exp+poh->DataDirectory[IMAGE_DIRECTORY_ENTRY_EXPORT].Size))
            {
                //в экспорте форвард на другую библиотеку...
                char FwName[128];
                _strcpy(FwName,(char*)lpRet);
                lpRet=0;

                char *p=_strchr(FwName,'.');
                if (p)
                {
                    *p=0;
                    if (HMODULE hMod=lpLoadLibraryExA(FwName,NULL,0))
                        lpRet=GetProcAddressEx(hMod,p+1,0);
                }
            }
        }
    }
    return lpRet;
}

void ldr_RebasePE()
{
    byte *lpImg=ldr_GetImageBase(ldr_GetOurAddr());

    PIMAGE_DOS_HEADER dos=(PIMAGE_DOS_HEADER) (lpImg);
    PIMAGE_FILE_HEADER pfh=(PIMAGE_FILE_HEADER)((ULONG_PTR)lpImg+dos->e_lfanew+4);
    PIMAGE_OPTIONAL_HEADER poh=(PIMAGE_OPTIONAL_HEADER)(pfh+1);

    ULONG_PTR hInst=poh->ImageBase;
    if ((ULONG_PTR)lpImg != hInst)
    {
        if (poh->DataDirectory[IMAGE_DIRECTORY_ENTRY_BASERELOC].VirtualAddress)
        {
            PIMAGE_BASE_RELOCATION Reloc=(PIMAGE_BASE_RELOCATION) RVATOVA(poh->DataDirectory[IMAGE_DIRECTORY_ENTRY_BASERELOC].VirtualAddress,lpImg);

            u_int i=0;
            while (i < poh->DataDirectory[IMAGE_DIRECTORY_ENTRY_BASERELOC].Size)
            {
                for (PIMAGE_FIXUP_ENTRY Fixup=(PIMAGE_FIXUP_ENTRY)((ULONG_PTR)Reloc+sizeof(IMAGE_BASE_RELOCATION)); (ULONG_PTR)Fixup < (ULONG_PTR)Reloc+Reloc->SizeOfBlock; Fixup++)
                {
                    if (Fixup->Type == IMAGE_REL_BASED_HIGHLOW)
                    {
                        DWORD32 *pFixup=(DWORD32 *)RVATOVA(Reloc->VirtualAddress+Fixup->Offset,lpImg);
                        *pFixup=*pFixup-hInst+(DWORD32)lpImg;
                    }
                    else if (Fixup->Type == IMAGE_REL_BASED_DIR64)
                    {
                        DWORD64 *pFixup=(DWORD64 *)RVATOVA(Reloc->VirtualAddress+Fixup->Offset,lpImg);
                        *pFixup=*pFixup-hInst+(DWORD64)lpImg;
                    }
                }
                i+=Reloc->SizeOfBlock;
                *(ULONG_PTR*)&Reloc+=Reloc->SizeOfBlock;
            }
        }
        poh->ImageBase=(ULONG_PTR)lpImg;

        HMODULE hKernel32=GetK32Base();
        lpLoadLibraryExA=(__LoadLibraryExA*)GetProcAddressEx(hKernel32,(LPCSTR)0x9B102E2D,LDR_GET_BY_HASH);
        if (lpLoadLibraryExA)
        {
            if (poh->DataDirectory[IMAGE_DIRECTORY_ENTRY_IMPORT].VirtualAddress)
            {
                PIMAGE_IMPORT_DESCRIPTOR imp=(PIMAGE_IMPORT_DESCRIPTOR)&lpImg[poh->DataDirectory[IMAGE_DIRECTORY_ENTRY_IMPORT].VirtualAddress];
                for (; imp->Name; imp++)
                {
                    if (HMODULE hDll=lpLoadLibraryExA((LPCSTR)&lpImg[imp->Name],NULL,0))
                    {
                        ULONG_PTR *addr=(ULONG_PTR*)(&lpImg[imp->FirstThunk]);

                        for (PIMAGE_THUNK_DATA Thunk=(PIMAGE_THUNK_DATA)&lpImg[imp->OriginalFirstThunk]; Thunk->u1.Ordinal; Thunk++)
                        {
                            ULONG_PTR func=(ULONG_PTR)GetProcAddressEx(hDll,Thunk->u1.Ordinal & 0xf0000000 ? ((char*) (WORD)Thunk->u1.Ordinal):((char*) ((PIMAGE_IMPORT_BY_NAME) &lpImg[(ULONG_PTR)Thunk->u1.AddressOfData])->Name),0);
                            if (!func)
                                break;
                            *addr++=func;
                        }
                    }
                    ///else
                    ///    break;
                }
            }
        }
    }
    lpImage=lpImg;

    ldr_GetImageSize();
    return;
}

DWORD ldr_GetImageSize()
{
    return dwSize=((PIMAGE_OPTIONAL_HEADER)((lpImage)+((PIMAGE_DOS_HEADER)(lpImage))->e_lfanew+sizeof(DWORD)+sizeof(IMAGE_FILE_HEADER)))->SizeOfImage;
}

extern "C" bool SysCloseHandle(HANDLE hHandle)
{
    DWORD dwFlags=0;

    if (hHandle)
    {
        if (GetHandleInformation(hHandle,&dwFlags))
        {
            if (!(dwFlags & HANDLE_FLAG_PROTECT_FROM_CLOSE))
                return CloseHandle(hHandle);
        }
    }
	return false;
}

DWORD FindProcess(TCHAR *lpFileName)
{
    DWORD r=0;
    HANDLE hSnap=CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS,NULL);
    if (hSnap != INVALID_HANDLE_VALUE)
    {
        PROCESSENTRY32 ppe= {0};
        ppe.dwSize=sizeof(PROCESSENTRY32);
        if (Process32First(hSnap,&ppe))
        {
            do
            {
                if (StrStrI(ppe.szExeFile,lpFileName))
                {
                    r=ppe.th32ProcessID;
                    break;
                }
            }
            while (Process32Next(hSnap,&ppe));
        }
        SysCloseHandle(hSnap);
    }
    return r;
}

bool SysCheckProcessGroup(DWORD dwProcessId)
{
    bool bRet=false;
	HANDLE hProc=OpenProcess(PROCESS_QUERY_INFORMATION,false,dwProcessId);
	if (hProc)
	{
	    HANDLE hToken;
		bool bState=OpenProcessToken(hProc,TOKEN_QUERY+TOKEN_QUERY_SOURCE,&hToken);
		if (bState)
		{
            TOKEN_SOURCE tsToken;
            DWORD dwIO;
			bState=GetTokenInformation(hToken,TokenSource,&tsToken,sizeof(TOKEN_SOURCE),&dwIO);
			if (bState)
			{
			    CharUpperA(tsToken.SourceName);
				if ((memcmp(tsToken.SourceName,"*SYSTEM*",sizeof("*SYSTEM*"))) && (memcmp(tsToken.SourceName,"ADVAPI",sizeof("ADVAPI"))))
					bRet=true;
			}
			SysCloseHandle(hToken);
		}
		SysCloseHandle(hProc);
	}

	return bRet;
}

bool IsUserAdmin()
{
	SID_IDENTIFIER_AUTHORITY siaNTAuthority=SECURITY_NT_AUTHORITY;
	PSID lpAdministratorsGroup;
	BOOL bRet=AllocateAndInitializeSid(&siaNTAuthority,2,SECURITY_BUILTIN_DOMAIN_RID,DOMAIN_ALIAS_RID_ADMINS,0,0,0,0,0,0,&lpAdministratorsGroup);
	if (bRet)
	{
		if (!CheckTokenMembership(NULL,lpAdministratorsGroup,&bRet))
			bRet=false;
		FreeSid(lpAdministratorsGroup);
	}
	return (bool)bRet;
}

