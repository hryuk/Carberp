#include <windows.h>
#include <stdio.h>

/*
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
*/

HMODULE GetKernelBase()
{
 unsigned int adr = 0x07c900000;
 while( adr < 0x080000000 ) {
   unsigned short* adr2 = (unsigned short*)adr;
   if( *adr2 == 0x5A4D )
     break;
   adr += 0x10000;
 }
 return (HMODULE)adr;
}

int main()
{
 HMODULE dll = GetModuleHandle("kernel32.dll");
 HMODULE dll2 = GetKernelBase();
 HMODULE dll3 = GetModuleHandle("ntdll.dll");
 printf( "%08x %08x %08x", dll, dll2, dll3 );
}
