#ifndef _UTILS_H
#define _UTILS_H

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

PCHAR FindChar(PCHAR Str, char C);

PCHAR MakeMachineID();

DWORD GetImageBase();

// заполн€ет переменную нул€ми
#define ClearStruct(S) m_memset(&S, 0, sizeof(S))

// ¬ыдел€ет пам€ть под переменную типа и возвращает указатель
#define CreateStruct(T) (T*)HEAP::Alloc(sizeof(T))

// ¬ыдел€ет пам€ть под переменную типа и возвращает указатель
#define FreeStruct(S) HEAP::Free(S);
DWORD CalcHash(char *Str );
DWORD CalcHashW( PWSTR str );
wchar_t *m_wcsncpy( wchar_t *dest, wchar_t *src, unsigned long n );
wchar_t *m_wcslwr( wchar_t *Str );

#ifndef NT_SUCCESS
# define NT_SUCCESS(Status)				((LONG)(Status) >= 0) 
#endif

#ifndef STATUS_SUCCESS
# define STATUS_SUCCESS                          ((NTSTATUS)0x00000000L) // 
#endif

#endif // _UTILS_H
