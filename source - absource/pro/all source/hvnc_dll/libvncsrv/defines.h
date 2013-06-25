#ifndef _DEFINES_H_
#define _DEFINES_H_

#include <windows.h>
#include <intrin.h>

typedef unsigned __int64 u64;
typedef unsigned long    u32;
typedef unsigned short   u16;
typedef unsigned char    u8;

typedef __int64 s64;
typedef long    s32;
typedef short   s16;
typedef char    s8;

#define d8(_x)  ((u8)(_x))
#define d16(_x) ((u16)(_x))
#define d32(_x) ((u32)(_x))
#define d64(_x) ((u64)(_x))
#define dSZ(_x) ((size_t)(_x))

#define p8(_x)   ((u8*)(_x))
#define p16(_x)  ((u16*)(_x))
#define p32(_x)  ((u32*)(_x))
#define p64(_x)  ((u64*)(_x))
#define pv(_x)   ((void*)(_x))
#define ppv(_x)  ((void**)(_x))

#define sizeof_w(x)  ( sizeof(x) / sizeof(wchar_t) ) /* return number of wide characters in array */
#define array_num(x) ( sizeof(x) / sizeof((x)[0]) )  /* return number of elements in array */

#define zeromem(m,s) memset(m, 0, s)

/* size optimized intrinsics */
#define mincpy(a,b,c) __movsb(pv(a), pv(b), (size_t)(c))
#define memset(a,b,c) __stosb(pv(a), (char)(b), (size_t)(c))

/* zeromem for 4byte aligned blocks */
#define zerofast(m,s) __stosd(pv(m),0,(size_t)(s) / 4)

/* fast intrinsics for memory copying and zeroing */
#ifdef _M_IX86
 #define fastcpy(a,b,c) __movsd(pv(a), pv(b), (size_t)(c) / 4)

 #define autocpy(a,b,c) { \
    if (!((c) % 4)) { __movsd(pv(a), pv(b), (size_t)(c) / 4); } else \
    if (!((c) % 2)) { __movsw(pv(a), pv(b), (size_t)(c) / 2); } else \
    { __movsb(pv(a), pv(b), (size_t)(c)); } }

 #define zeroauto(m,s) { \
    if (!((s) % 4)) { __stosd(pv(m), 0, (size_t)(s) / 4); } else \
    if (!((s) % 2)) { __stosw(pv(m), 0, (size_t)(s) / 2); } else \
	{ __stosb(pv(m), 0, (size_t)(s)); } }

 #define _disable() { __asm { cli }; }
 #define _enable()  { __asm { sti }; }
#else
 #define fastcpy(a,b,c) __movsq(pv(a), pv(b), (size_t)(c) / 8)

 #define autocpy(a,b,c) { \
    if (!((c) % 8)) { __movsq(pv(a), pv(b), (size_t)(c) / 8); } else \
    if (!((c) % 4)) { __movsd(pv(a), pv(b), (size_t)(c) / 4); } else \
    if (!((c) % 2)) { __movsw(pv(a), pv(b), (size_t)(c) / 2); } else \
    { __movsb(pv(a), pv(b), (size_t)(c)); } }

 #define zeroauto(m,s) { \
    if (!((s) % 8)) { __stosq(pv(m), 0, (size_t)(s) / 8); } else \
    if (!((s) % 4)) { __stosd(pv(m), 0, (size_t)(s) / 4); } else \
    if (!((s) % 2)) { __stosw(pv(m), 0, (size_t)(s) / 2); } else \
	{ __stosb(pv(m), 0, (size_t)(s)); } }
#endif

#define lock_inc(_x)          ( _InterlockedIncrement(_x) )
#define lock_dec(_x)          ( _InterlockedDecrement(_x) )
#define lock_xchg(_p, _v)     ( _InterlockedExchange(_p, _v) )
#define lock_xchg_add(_p, _v) ( _InterlockedExchangeAdd(_p, _v) )

///#define malloc(size) (size ? (HeapAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY, (SIZE_T)(size))//) : 0)
///#define realloc(mem, size) (size ? (mem ? HeapReAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY, (void *)(mem), size) : malloc(size)) : 0)
///#define free(mem) (mem ? (HeapValidate(GetProcessHeap(), 0, mem) ? (HeapFree(GetProcessHeap(), 0, (void *)(mem)), mem = 0) : 0) : 0)

void *MemAlloc(size_t dwSize);
void *MemRealloc(void *lpMem,size_t dwSize);
void MemFree(void *lpMem);

#pragma warning(disable:4995)
#pragma intrinsic(memcpy,memset,memcmp)
#pragma intrinsic(strcpy,strcmp,strlen)
#pragma intrinsic(strcat)
#pragma warning(default:4995)


#endif
