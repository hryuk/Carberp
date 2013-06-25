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


/*
PVOID HookApi( DWORD Dll, DWORD FuncHash, DWORD ReplacementFunc )
{
    FARPROC pFunc;
	PVOID pvMem = 0;

	pFunc = (FARPROC)GetProcAddressEx( NULL, Dll, FuncHash );

	if (pFunc == NULL)
		return NULL;

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

*/

// изменено при добавлении оперы(на сколько € пон€л), вынесено обращение к библиотеке, чтобы потом добавить смецение с целью вызова не экспортируемых функций
/************************************************************************/

PVOID __HookApi( DWORD Dll, DWORD FuncAddr, DWORD ReplacementFunc )
{
	FARPROC pFunc;
	PVOID pvMem = 0;

    pFunc = (FARPROC)FuncAddr;

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



/************************************************************************/
//* ѕерехватывает экспортируемую функцию из dll,                       *//
//  определ€€ еЄ адрес по хешу


PVOID HookApi( DWORD Dll, DWORD FuncHash, DWORD ReplacementFunc )
{
	DWORD FuncAddr = (DWORD)GetProcAddressEx(NULL, Dll, FuncHash );
	return __HookApi(Dll, FuncAddr, ReplacementFunc);
}

/************************************************************************/
//* ѕерехватывает Ќ≈экспортируемую функцию из dll по еЄ VA адресу,     *//
PVOID HookApi2( DWORD Dll, DWORD FuncVA, DWORD ReplacementFunc )
{
	// ѕередаЄм в ф-ю 0, вместо хеша, это заставит еЄ вернуть
	// адрес загрузки самой dll
	DWORD FuncAddr = (DWORD)GetProcAddressEx( NULL, Dll, 0 );
	if (FuncAddr)
	{
		return __HookApi(Dll, FuncAddr + FuncVA, ReplacementFunc);
	}
	else
		return NULL;
}
