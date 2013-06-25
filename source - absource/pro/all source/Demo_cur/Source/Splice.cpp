#include <windows.h>

#include "Memory.h"
#include "GetApi.h"
#include "zdisasm.h"


void GetInstLenght(DWORD* myiptr0, DWORD* osizeptr);

#define mFillMemory(pb,cb,b)         m_memset( (pb),(b),(cb) )
#define mCopyMemory(pbDst,pbSrc,cb) do                              \
                                    {                               \
                                       size_t _cb = (size_t)(cb);  \
                                       if (_cb)                    \
                                          m_memcpy(pbDst,pbSrc,_cb);\
                                    } while ( FALSE )

#define SIZEOFJUMP	5
#define ASMNOP		0x90

void InsertByte( DWORD Addr, unsigned char Byte )
{
	if ( !pIsBadReadPtr((void *)Addr, (UINT)sizeof( byte ) ) )
	{
		*((byte *)((DWORD *)Addr)) = Byte;
	}
}


void InsertDword(DWORD Addr, DWORD dWord)
{
	if ( !pIsBadReadPtr( (void* )Addr, (UINT)sizeof( DWORD ) ) )
	{
		*((DWORD *)Addr) = dWord;
	}
}


void GenJmp(DWORD To, DWORD From)
{
	InsertByte ( From + 0, 0xe9 );
	InsertDword( From + 1, To - From - 5 );
}

PVOID HookApi( DWORD Dll, DWORD FuncHash, DWORD ReplacementFunc )
{
    FARPROC pFunc;
	PVOID pvMem = 0;

    pFunc = (FARPROC)GetProcAddressEx( NULL, Dll, FuncHash );

    DWORD pAddr		  = (DWORD)pFunc; 
    DWORD pAddrToJump = ReplacementFunc;

    DWORD dSize = 0,
		  i = 0,
		  CollectedSpace = 0,
		  OldProtect = 0;

    BYTE* pInstruction;

    DWORD CallGateSize = 0;

    pInstruction = (BYTE*)pAddr;

    while ( CollectedSpace < SIZEOFJUMP )
    {
		GetInstLenght( (DWORD*)pInstruction, &dSize );
		pInstruction   += dSize;
		CollectedSpace += dSize;
    }

    CallGateSize = ( CollectedSpace + SIZEOFJUMP ) * sizeof( byte );

	pvMem = pVirtualAlloc( NULL, CallGateSize * sizeof( byte ), MEM_RESERVE | MEM_COMMIT, PAGE_EXECUTE_READWRITE );

	if( pvMem == NULL )
	{
		return NULL;
	}

	byte *pbBuff = (byte *)pvMem;

	mFillMemory( pbBuff, CallGateSize, ASMNOP );	
    mCopyMemory( pbBuff, (void *)pAddr, CollectedSpace );

	GenJmp( (DWORD)pAddr + (DWORD)SIZEOFJUMP, (DWORD)pbBuff + (DWORD)CollectedSpace );

    pVirtualProtect( (void *)pAddr, CollectedSpace + SIZEOFJUMP, PAGE_EXECUTE_READWRITE, &OldProtect );

    mFillMemory( (void *)pAddr, CollectedSpace, ASMNOP );
    GenJmp( pAddrToJump, pAddr );

    pVirtualProtect( (void *)pAddr, CollectedSpace + SIZEOFJUMP, OldProtect, &OldProtect );

    return pvMem;
}