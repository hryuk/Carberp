#include <windows.h>

#include "Memory.h"
#include "GetApi.h"
#include "zdisasm.h"
#include "strings.h"


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

// изменено при добавлении оперы(на сколько я понял), вынесено обращение к библиотеке, чтобы потом добавить смецение с целью вызова не экспортируемых функций
/************************************************************************/

PVOID __HookApi(DWORD FuncAddr, DWORD ReplacementFunc )
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


//--------------------------------------------------------
// HookFunction
// Функция устанавливает хук на указанную функцию
//
// FunctionAddr - адрес функции, которую необходимо 
//                подменить
// NewFunctionAddr - адрес новой функции
// OriginalFunctionAddr - указатель на переменную, куда
// будет записан адрес сохранённой, оригинальной, функции
//--------------------------------------------------------
bool HookFunction(LPVOID FunctionAddr, LPVOID NewFunctionAddr, LPVOID *OriginalFunctionAddr)
{
	LPVOID Original = NULL;

	if (FunctionAddr && NewFunctionAddr)
		Original = __HookApi((DWORD)FunctionAddr, (DWORD)NewFunctionAddr);
	if (OriginalFunctionAddr)
		*OriginalFunctionAddr = Original;

	return Original != NULL;
}



//--------------------------------------------------------
//  HookApiEx 
//  Функция устанавливает хук на функцию
// 
//  DllNum           - Номер бибиотеки. см. GetApi.h
//  FuncHash         - Хэш имени функции
//  NewFunction      - Адрес новой функции
//  OriginalFunction - Переменная, куда будет записан 
//                     адрес оригинаьной функции
//--------------------------------------------------------
bool HookApiEx(DWORD DllNum, DWORD FuncHash, LPVOID NewFunction, LPVOID &OriginalFunction)
{
	DWORD FuncAddr = (DWORD)GetProcAddressEx(NULL, DllNum, FuncHash );
	OriginalFunction = __HookApi(FuncAddr, (DWORD)NewFunction);
	return OriginalFunction != NULL;
}


/************************************************************************/
//* Перехватывает экспортируемую функцию из dll,                       *//
//  определяя её адрес по хешу


PVOID HookApi( DWORD Dll, DWORD FuncHash, LPVOID ReplacementFunc )
{
	DWORD FuncAddr = (DWORD)GetProcAddressEx(NULL, Dll, FuncHash );
	return __HookApi(FuncAddr, (DWORD)ReplacementFunc);
}

PVOID HookApi( DWORD Dll, DWORD FuncHash, LPVOID ReplacementFunc, PVOID FuncReal )
{
	DWORD FuncAddr = (DWORD)GetProcAddressEx(NULL, Dll, FuncHash );
	*((DWORD*)FuncReal) = (DWORD)__HookApi(FuncAddr, (DWORD)ReplacementFunc);
	return *((PVOID*)FuncReal);
}

PVOID HookApi( const char* DllName, DWORD FuncHash, LPVOID ReplacementFunc, PVOID FuncReal )
{
	DWORD FuncAddr = (DWORD)GetProcAddressEx( (char*)DllName, 0, FuncHash );
	*((DWORD*)FuncReal) = (DWORD)__HookApi(FuncAddr, (DWORD)ReplacementFunc);
	return *((PVOID*)FuncReal);
}

/************************************************************************/
//* Перехватывает НЕэкспортируемую функцию из dll по её VA адресу,     *//
PVOID HookApi2( DWORD Dll, DWORD FuncVA, DWORD ReplacementFunc )
{
	// Передаём в ф-ю 0, вместо хеша, это заставит её вернуть
	// адрес загрузки самой dll
	DWORD FuncAddr = (DWORD)GetProcAddressEx( NULL, Dll, 0 );
	if (FuncAddr)
	{
		return __HookApi(FuncAddr + FuncVA, ReplacementFunc);
	}
	else
		return NULL;
}

static PIMAGE_NT_HEADERS GetNtHeaders(PVOID Image)
{
  PIMAGE_NT_HEADERS pNtHeader = (PIMAGE_NT_HEADERS)(  ((PIMAGE_DOS_HEADER)Image)->e_lfanew +  (PCHAR)Image );
  if ( 	((PIMAGE_DOS_HEADER)Image)->e_magic != IMAGE_DOS_SIGNATURE )
	  return NULL;
  if ( pNtHeader->Signature != IMAGE_NT_SIGNATURE )
	  return NULL;
  return pNtHeader;
};

bool PathIAT(PVOID Module,PCHAR DllName,PCHAR FuncName,PVOID NewHandler,PVOID *OldHandler)
{

	PIMAGE_NT_HEADERS		pNtHeader;
	PIMAGE_DATA_DIRECTORY	pData;
	CHAR buf1[MAX_PATH];

	if ( Module == NULL )
		return false;

	pNtHeader = GetNtHeaders(Module);
	if ( pNtHeader == NULL )
		return false;

	pData = &pNtHeader->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_IMPORT];
	if ( pData->Size == 0 )
		return false;
	
	m_lstrcpy(buf1,DllName);
	pCharUpperBuffA(buf1,sizeof(buf1)-1);

	PIMAGE_IMPORT_DESCRIPTOR	pimg_import_desc = (PIMAGE_IMPORT_DESCRIPTOR)((PCHAR)Module + pData->VirtualAddress);

	for ( int i =0; pimg_import_desc[i].Name != 0; ++i)
	{
		CHAR buf2[MAX_PATH];
		PCHAR ImortDll = (PCHAR)Module + pimg_import_desc[i].Name;
		m_lstrcpy(buf2,ImortDll);
		pCharUpperBuffA(buf2,sizeof(buf2)-1);
		if ( m_lstrcmp(buf1,buf2) != 0 )
			continue;

		DWORD  VAToThunk   = pimg_import_desc[i].FirstThunk;
		PDWORD FirstThunk  = (PDWORD)((PCHAR)Module + pimg_import_desc[i].FirstThunk);  /*VA to function*/
		PDWORD OriginalFirstThunk  =(PDWORD)((PCHAR)Module + pimg_import_desc[i].OriginalFirstThunk); /*VA to name function*/
		while ( *FirstThunk  && *OriginalFirstThunk )
		{
			PCHAR Name  = (PCHAR)((PCHAR)Module +*OriginalFirstThunk ); 
			Name+=2;

			if ( m_lstrcmp(Name,FuncName) == 0)
			{
				DWORD Protect;
				*OldHandler = (PVOID)*FirstThunk;
				pVirtualProtect(FirstThunk,sizeof(PVOID),PAGE_READWRITE,&Protect);
				*FirstThunk = (DWORD)NewHandler;
				pVirtualProtect(FirstThunk,sizeof(PVOID),Protect,&Protect);
				return true;
			}

			FirstThunk++;	OriginalFirstThunk++;
			VAToThunk += sizeof(VAToThunk);
		}
	}
	return false;
}
