#ifndef UUID_C90C4CF3313F421595DAE77DF1319F15
#define UUID_C90C4CF3313F421595DAE77DF1319F15

void *m_memset( void *szBuffer, DWORD dwSym, DWORD dwLen );
void *m_memcpy( void *dst, const void *src, int nLen );


DWORD  GetMemSize( LPVOID lpAddr );
VOID   MemFree( LPVOID lpAddr );
LPVOID MemAlloc( DWORD dwSize );
LPVOID MemRealloc( LPVOID lpAddr, DWORD dwSize );

DWORD WINAPI m_lstrcmp( const char *szStr1, const char *szStr2 );
void WINAPI m_lstrcat( char *szBuf, const char *szStr );

wchar_t *m_wcsncpy( wchar_t *dest, wchar_t *src, unsigned long n );
wchar_t *m_wcslwr( wchar_t *Str );
DWORD WINAPI m_wcslen( const wchar_t *String );

int m_atoi( const char *nptr );
long WINAPI m_atol( const char *nptr );



typedef struct
{
	PIMAGE_NT_HEADERS headers;
	unsigned char *codeBase;
	HMODULE *modules;
	int numModules;
	int initialized;
} MEMORYMODULE, *PMEMORYMODULE;

typedef void *HMEMORYMODULE;

int BuildImportTable(PMEMORYMODULE module);
bool BuildImport(PVOID ImageBase);


DWORD CalcHash(char *Str );
DWORD CalcHashW( PWSTR str );

namespace STR {

PCHAR Scan(PCHAR Str, char C);
bool IsEmpty(PCHAR Str);

}// end namespace STR

namespace HEAP
{
	LPVOID Alloc(DWORD Size);

	LPVOID ReAlloc(LPVOID Buf, DWORD Size);
	bool ReAlloc2(LPVOID &Buf, DWORD Size);

	void Free(LPVOID Buf);
	void Free2(LPVOID &Buf);

	DWORD Size(LPVOID Buf);
}


// заполн€ет переменную нул€ми
#define ClearStruct(S) m_memset(&S, 0, sizeof(S))

// ¬ыдел€ет пам€ть под переменную типа и возвращает указатель
#define CreateStruct(T) (T*)HEAP::Alloc(sizeof(T))

// ¬ыдел€ет пам€ть под переменную типа и возвращает указатель
#define FreeStruct(S) HEAP::Free(S);



#ifndef NT_SUCCESS
# define NT_SUCCESS(Status)				((LONG)(Status) >= 0) 
#endif

#ifndef STATUS_SUCCESS
# define STATUS_SUCCESS                          ((NTSTATUS)0x00000000L) // 
#endif

#endif // #ifndef UUID_C90C4CF3313F421595DAE77DF1319F15
