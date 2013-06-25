#include <windows.h>

int WINAPI UrlEncode( char *pszDestiny, char *pszSource );

void DbgMsg(char *file, int line, char *msg, ...);
void DbgMsgW(WCHAR *file, int line, WCHAR *msg, ...);

int m_atoi( const char *nptr );

void   WINAPI m_lstrcat( char *szBuf, const char *szStr );
void   WINAPI m_lstrcpy( char *szBuf, const char *szStr );
void   WINAPI m_lstrlwr( char *str );

void WINAPI m_lwcscat( WCHAR *szBuf, const WCHAR *szStr );

char * WINAPI m_strstr( const char * _Str, const char * _SubStr );
char * WINAPI m_strstrmask( const char * _Str, const char * _SubStr );
char * WINAPI m_strtok_s( char *String, const char *Control, char **Context );

char * WINAPI ToAnsi( LPCWSTR String );
char * WINAPI ToAnsiEx( LPCWSTR String, DWORD dwSize );

bool   WINAPI m_lstrncpy( char *pString_src, const char *pString_dst, DWORD len );
bool   WINAPI SearchByMask( char *mask, char *name );

int  WINAPI m_istrstr( const char * _Str, const char * _SubStr );
DWORD  WINAPI m_lstrcmp( const char *szStr1, const char *szStr2 );
DWORD  WINAPI m_lstrncmp( const char *szstr1, const char *szstr2, int nlen );
DWORD  WINAPI m_lstrlen( char *szPointer );

DWORD WINAPI m_wcslen( const wchar_t *String );

wchar_t *m_wcsncpy( wchar_t *dest, wchar_t *src, unsigned long n );
wchar_t *m_wcslwr( wchar_t *Str );
bool m_wcsncmp( WCHAR *s1, WCHAR *s2, size_t iMaxLen );


bool WildCmp( char *Buffer, char *Mask, LPDWORD dwStart, LPDWORD dwEnd, LPDWORD dwLen );
bool CompareUrl( char *MaskUrl, char *Url );

WCHAR * AnsiToUnicode( char *AnsiString, DWORD dwStrLen );
void AlertError( LPTSTR lpszFunction ) ;


// ----------------------------------------------------------------------------
//  Набор функция для работы со строками
//
//  Если использовать данные функции для работы со строками, то? в некоторых
//  случаях, можно достить большего быстродействия. Например, функция
//  StrLength многократно  превышает по быстродействию функции которые
//  просчитывают длину строки сканируя её до нулевого символа, и чем больше
//  строка тем больше разница в быстродействии
// ----------------------------------------------------------------------------


//  Создать строку размером Len, Если указана строка источник Source то из неё
//  будет скопировано Len символов
PCHAR StrNew(DWORD Len, PCHAR Source);
PCHAR StrNew(DWORD Count, PCHAR Str...);

// Изменить размер строки
// Важно!!! Функция работает со строками которые созданы функцией StrNew
void StrSetLength(PCHAR &Str, DWORD NewLength);

// Уничтожить строку.
// Важно!!! Строка должна быть создана с помощью функции StrNew
void StrFree(PCHAR Str);

// Функция возвращает длину строки.
DWORD StrLength(PCHAR Str);

// Функция возвращает истину если на входе нулевой указатель либо
// пустая строка
bool StrIsEmpty(PCHAR Str);
