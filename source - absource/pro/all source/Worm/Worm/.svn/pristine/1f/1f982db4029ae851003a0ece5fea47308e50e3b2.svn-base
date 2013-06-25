#ifndef _UTIL_H_
#define _UTIL_H_

#include <windows.h>

char* u_alloc( int sz, int zero = 0 );
void u_free( void* mem);
void u_memcpy( char* dst, const char* src, int c);
void u_memset( void* dst, char c, int count );
HANDLE u_CreateFile( const char* nameFile, int read = 0, int add = 0 );
int u_WriteFile(HANDLE file, void* data, int c_data);
int u_ReadFile(HANDLE file, void* data, int c_data);
void u_CloseFile(HANDLE file);
int u_SaveToFile( const char* nameFile, void* data, int c_data);
const char* u_strstr(const char* s, const char* sub);
int u_icmpchar(char c1, char c2);
const char* u_istrstr(const char* s, const char* sub);
const char* u_strchr( const char* s, char c );
//генерирует число в пределах от 0 до 65535
int u_rand(void);
int u_rand_range( int min, int max );

#endif //_UTIL_H_
