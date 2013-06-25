#include "util.h"

char* u_alloc( int sz, int zero )
{
 return (char*)_LocalAlloc( (zero ? LPTR : LMEM_FIXED), sz );
}

void u_free(void* mem)
{
 _LocalFree(mem);
}

void u_memcpy( char* dst, const char* src, int c)
{
 if( c > 0 )
   while( c-- ) *dst++ = *src++;
}

void u_memset( void* dst, char c, int count )
{
	char* p = (char*)dst;
	while( count-- )
		*p++ = c;
}

HANDLE u_CreateFile(const char* nameFile, int read, int add)
{
	HANDLE fout = _CreateFile( nameFile, (read ? GENERIC_READ : GENERIC_WRITE), FILE_SHARE_READ | FILE_SHARE_WRITE, 0, (read || add ? OPEN_EXISTING : CREATE_ALWAYS), 0, 0 );
    if( fout == INVALID_HANDLE_VALUE ) return 0;
	if( add ) _SetFilePointer( fout, 0, 0, FILE_END );
	return fout;
}

int u_WriteFile(HANDLE file, void* data, int c_data)
{
	DWORD rl = 0;
	_WriteFile( file, data, c_data, &rl, 0 );
	return rl;
}

int u_ReadFile(HANDLE file, void* data, int c_data)
{
	DWORD rl = 0;
	_ReadFile( file, data, c_data, &rl, 0 );
	return rl;
}

void u_CloseFile(HANDLE file)
{
	_CloseHandle(file);
}

int u_SaveToFile( const char* nameFile, void* data, int c_data)
{
	HANDLE fout = u_CreateFile( nameFile, 0, 0 );
    if( fout == 0 ) return 0;
    u_WriteFile( fout, data, c_data );
    u_CloseFile(fout);
	return 1;
}

const char* u_strstr(const char* s, const char* sub)
{
	int c_s = lstrlen(s);
	int c_sub = lstrlen(sub);
	if( c_s < c_sub ) return 0;
	for( int i = 0; i <= c_s - c_sub; i++ )
	{
		int match = 1;
		for( int j = 0; j < c_sub; j++ )
			if( s[i + j] != sub[j] )
			{
				match = 0;
				break;
			}
		if( match )
			return s + i;
	}
	return 0;
}

//сравнение символов без учета регистра
int u_icmpchar(char c1, char c2)
{
	if( c1 >= 'a' && c1 <= 'z' )
		c1 ^= 0x20;
	if( c2 >= 'a' && c2 <= 'z' )
		c2 ^= 0x20;
	return c1 - c2;
}

//поиск подстроки в строке без учета регистра и только для английских букв
const char* u_istrstr(const char* s, const char* sub)
{
	int c_s = _lstrlen(s);
	int c_sub = _lstrlen(sub);
	if( c_s < c_sub ) return 0;
	for( int i = 0; i <= c_s - c_sub; i++ )
	{
		int match = 1;
		for( int j = 0; j < c_sub; j++ )
			if( u_icmpchar( s[i + j], sub[j] ) != 0 )
			{
				match = 0;
				break;
			}
		if( match )
			return s + i;
	}
	return 0;
}

const char* u_strchr( const char* s, char c )
{
 if( s == 0 ) return 0;
 while( *s ) 
   if( *s == c )
     return s;
   else
     s++;
 return 0;
}

//генерирует число в пределах от 0 до 65535
int u_rand(void)
{
 static unsigned int curr = 0; //текущее случайное число
 if( curr == 0 ) curr = _GetTickCount() & 0xffff;
 curr = (curr * 60539 + 4481) & 0xffff;
 return curr;
}

int u_rand_range( int min, int max )
{
 int r = u_rand();
 return (r % (max - min + 1)) + min;
}
