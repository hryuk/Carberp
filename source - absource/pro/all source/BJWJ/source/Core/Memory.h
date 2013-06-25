#ifndef MemoryH
#define MemoryH

#include <windows.h>
//-----------------------------------------------------------------------------

void m_memset(const void*  Buffer, BYTE Sym, size_t Len);
void *m_memcpy(void *szBuf, const void *szStr, int nLen);
int   m_memcmp(const void *buf1, const void *buf2, size_t count);
void* m_memmem( const void* mem1, int szMem1, const void* mem2, int szMem2 );


/*---------------------------------------------------------------------------*/
// Следующие функции для выделения памяти используют VirtualAlloc
// Главный нюанс данной функции в том, что память выделяется постранично,
// что приводит к излишним затратам памяти при инициализации небольших
// структур, либо маленьких блоков памяти.
//
// Для оперирования маленькими блоками памяти используйте функции выделяющие
// память из КУЧИ процесса. Функции начинаются с MemHeap...
/*---------------------------------------------------------------------------*/

// Узнать размер выделенной памяти
DWORD  GetMemSize(LPVOID lpAddr);

// Освободить память
VOID   MemFree(LPVOID lpAddr);

// Выделить памать указанного размера
LPVOID MemAlloc(DWORD dwSize);

// Выделить и очистить память указанного размера
LPVOID MemAllocAndClear(size_t Size);

// Перевыделить память
LPVOID MemRealloc(LPVOID lpAddr, DWORD dwSize );


/*---------------------------------------------------------------------------*/
//  Функции для работы с памятью из КУЧИ процесса
//  Данные функции являются оболочкой над WINAPI функциями для работы
//  с памятью кучи.
//  Функции выделения, перевыделения памяти работают с флагом автоматической
//  очистки выделяемой памяти
/*---------------------------------------------------------------------------*/

namespace HEAP
{
	LPVOID Alloc(DWORD Size);

	LPVOID ReAlloc(LPVOID Buf, DWORD Size);
	bool ReAlloc2(LPVOID &Buf, DWORD Size);

	void Free(LPVOID Buf);
	void Free2(LPVOID &Buf);

	DWORD Size(LPVOID Buf);
}

/*---------------------------------------------------------------------------*/
//  Набор макросов облегчающих жизнь
/*---------------------------------------------------------------------------*/

// заполняет переменную нулями
#define ClearStruct(S) m_memset(&S, 0, sizeof(S))

// Выделяет память под переменную типа и возвращает указатель
#define CreateStruct(T) (T*)HEAP::Alloc(sizeof(T))

// Выделяет память под переменную типа и возвращает указатель
#define FreeStruct(S) HEAP::Free(S)

// Функция копирует структуру Source в структуру Destination
#define CopyStruct(Source, Destination) m_memcpy(Destination, Source, sizeof(*Destination))

//автоматическое выделение и освобождение памяти 
template<int SZ>
class MemPtr
{
		void* ptr;

	public:
		
		MemPtr()
		{
			ptr = MemAlloc(SZ);
		}
		~MemPtr()
		{
			MemFree(ptr);
		}
		operator char*()
		{
			return (char*)ptr;
		}

		char* str()
		{
			return (char*)ptr;
		}

		int size() const
		{
			return SZ;
		}
};


// Использование не шаблонного классса даст нам
// возмоность выделять память когда заранее не известен размер
// Фактически это динамический массив
class TMemory
{
private:
	void* FBuf;
	DWORD FSize;
public:
	TMemory(DWORD Size)
	{
		FSize = Size;
        FBuf  = MemAlloc(Size);
	}

	~TMemory()
	{
        MemFree(FBuf);
	}

	DWORD Write(const void* Data, DWORD Size)
	{
		DWORD M = (FSize < Size) ? FSize : Size;
		m_memcpy(FBuf, Data, M);
		return M;
    }

	inline LPVOID Buf()  { return FBuf; }
	inline DWORD  Size() { return FSize; }

    inline PCHAR AsStr() { return (PCHAR)FBuf; }

	inline operator char*()  { return (char*)FBuf; }
	inline operator LPBYTE() { return (LPBYTE)FBuf; }
};

//-----------------------------------------------------------------------------
#endif //MemoryH

