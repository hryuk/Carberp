/*
 * Hacker Disassembler Engine 32
 * Copyright (c) 2006-2009, Vyacheslav Patkov.
 * All rights reserved.
 *
 * hde32.h: C/C++ header file
 *
 */

#ifndef _HDE32_H_
#define _HDE32_H_


#include <windows.h>

/* stdint.h - C99 standard header
 * http://en.wikipedia.org/wiki/stdint.h
 *
 * if your compiler doesn't contain "stdint.h" header (for
 * example, Microsoft Visual C++), you can download file:
 *   http://www.azillionmonkeys.com/qed/pstdint.h
 * and change next line to:
 *   #include "pstdint.h"
 */

#define F_MODRM         0x00000001
#define F_SIB           0x00000002
#define F_IMM8          0x00000004
#define F_IMM16         0x00000008
#define F_IMM32         0x00000010
#define F_DISP8         0x00000020
#define F_DISP16        0x00000040
#define F_DISP32        0x00000080
#define F_RELATIVE      0x00000100
#define F_2IMM16        0x00000800
#define F_ERROR         0x00001000
#define F_ERROR_OPCODE  0x00002000
#define F_ERROR_LENGTH  0x00004000
#define F_ERROR_LOCK    0x00008000
#define F_ERROR_OPERAND 0x00010000
#define F_PREFIX_REPNZ  0x01000000
#define F_PREFIX_REPX   0x02000000
#define F_PREFIX_REP    0x03000000
#define F_PREFIX_66     0x04000000
#define F_PREFIX_67     0x08000000
#define F_PREFIX_LOCK   0x10000000
#define F_PREFIX_SEG    0x20000000
#define F_PREFIX_ANY    0x3f000000

#define PREFIX_SEGMENT_CS   0x2e
#define PREFIX_SEGMENT_SS   0x36
#define PREFIX_SEGMENT_DS   0x3e
#define PREFIX_SEGMENT_ES   0x26
#define PREFIX_SEGMENT_FS   0x64
#define PREFIX_SEGMENT_GS   0x65
#define PREFIX_LOCK         0xf0
#define PREFIX_REPNZ        0xf2
#define PREFIX_REPX         0xf3
#define PREFIX_OPERAND_SIZE 0x66
#define PREFIX_ADDRESS_SIZE 0x67

#pragma pack(push,1)

typedef struct {
    BYTE len;
    BYTE p_rep;
    BYTE p_lock;
    BYTE p_seg;
    BYTE p_66;
    BYTE p_67;
    BYTE opcode;
    BYTE opcode2;
    BYTE modrm;
    BYTE modrm_mod;
    BYTE modrm_reg;
    BYTE modrm_rm;
    BYTE sib;
    BYTE sib_scale;
    BYTE sib_index;
    BYTE sib_base;
	union  {
        BYTE  imm8;
		WORD  imm16;
		DWORD imm_32; // имя imm32 объявлено в Builder C++
			 } imm;
	union {
		BYTE disp8;
		WORD disp16;
		DWORD disp32;
     } disp;
    DWORD flags;
} hde32s;

#pragma pack(pop)

#ifdef __cplusplus
extern "C" {
#endif

/* __cdecl */
unsigned int hde32_disasm(const void *code, hde32s *hs);

#ifdef __cplusplus
}
#endif

#endif /* _HDE32_H_ */
