#include "util.h"
#include <Psapi.h>

const char* u_strstr(const char* s, const char* sub)
{
	int c_s = lstrlen(s);
	int c_sub = lstrlen(sub);
	if( c_s < c_sub ) return 0;
	for( int i = 0; i <= c_s - c_sub; i++ )
	{
		bool match = true;
		for( int j = 0; j < c_sub; j++ )
			if( s[i + j] != sub[j] )
			{
				match = false;
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
	int c_s = lstrlen(s);
	int c_sub = lstrlen(sub);
	if( c_s < c_sub ) return 0;
	for( int i = 0; i <= c_s - c_sub; i++ )
	{
		bool match = true;
		for( int j = 0; j < c_sub; j++ )
			if( u_icmpchar( s[i + j], sub[j] ) != 0 )
			{
				match = false;
				break;
			}
		if( match )
			return s + i;
	}
	return 0;
}

bool u_SaveToFile( const char* nameFile, void* data, int c_data)
{
	HANDLE fout = u_CreateFile(nameFile);
    if( fout == 0 ) return false;
    u_WriteFile( fout, data, c_data );
    u_CloseFile(fout);
}

char* u_alloc(int sz, bool zero)
{
	return (char*)LocalAlloc( (zero ? LPTR : LMEM_FIXED), sz );
}

void u_free(void* mem)
{
	LocalFree(mem);
}

HANDLE u_CreateFile(const char* nameFile, bool read, bool add)
{
	HANDLE fout = CreateFile( nameFile, (read ? GENERIC_READ : GENERIC_WRITE), FILE_SHARE_READ | FILE_SHARE_WRITE, 0, (read || add ? OPEN_EXISTING : CREATE_ALWAYS), 0, 0 );
    if( fout == INVALID_HANDLE_VALUE ) return 0;
	if( add ) SetFilePointer( fout, 0, 0, FILE_END );
	return fout;
}

int u_WriteFile(HANDLE file, void* data, int c_data)
{
	DWORD rl = 0;
	WriteFile( file, data, c_data, &rl, 0 );
	return rl;
}

int u_ReadFile(HANDLE file, void* data, int c_data)
{
	DWORD rl = 0;
	ReadFile( file, data, c_data, &rl, 0 );
	return rl;
}

void u_CloseFile(HANDLE file)
{
	CloseHandle(file);
}

void u_SaveHexData( const char* nameFile, unsigned char* data, int c_data )
{
	char buf[16];
	HANDLE fout = u_CreateFile(nameFile);
	for( int i = 0; i < c_data; i++ )
	{
		if( i > 0 && (i % 16) == 0 ) 
			u_WriteFile( fout, "\r\n", 2 );
		if( (i % 16) == 0 )
		{
			wsprintf( buf, "%09d ", i );
			u_WriteFile( fout, buf, 10 );
		}
		wsprintf( buf, "%02x ", (int)data[i] );
		u_WriteFile( fout, buf, 3 );
	}
	u_CloseFile(fout);
}

int u_atoi( const char* s )
{
	int v = 0;
	while( *s )
	{
		if( *s >= '0' && *s <= '9' )
		{
			v = v * 10 + *s - '0';
			s++;
		}
		else
			break;
	}
	return v;
}

int u_GetNameProcess( DWORD pid, HWND hwnd, char* path )
{
	if( pid == 0 )
	{
		GetWindowThreadProcessId( hwnd, &pid );
	}
	HANDLE  hProc;
	HMODULE ahMod[10];
	DWORD dwNeeded;
	int ret = 0;

	hProc = OpenProcess( PROCESS_QUERY_INFORMATION | PROCESS_VM_READ, FALSE, pid );
	if (hProc)
	{
		ret = GetModuleFileNameEx( hProc, 0, path, MAX_PATH );
		CloseHandle(hProc);
	}
	return ret;
}

void u_memcpy( char* dst, char* src, int c)
{
	if( c > 0 )
		while( c-- ) *dst++ = *src++;
}

int u_ReadAllBytes( const char* nameFile, uchar** data )
{
 *data = 0;
 HANDLE file = u_CreateFile( nameFile, 1 );
 if( file == 0 ) return 0;
 int sz = GetFileSize( file, 0 );
 *data = (uchar*)u_alloc(sz);
 u_ReadFile( file, *data, sz );
 u_CloseFile(file);
 return sz;
}

int u_WriteAllBytes( const char* nameFile, uchar* data, int c_data )
{
 HANDLE file = u_CreateFile(nameFile);
 if( file == 0 ) return 0;
 int sz = u_WriteFile( file, data, c_data );
 u_CloseFile(file);
 return sz; 
}

char* ToAnsi(const WCHAR* s)
{
	int len = lstrlenW(s);
	char* ret = u_alloc(len + 1);
	WideCharToMultiByte(1251, 0, s, len, ret, len + 1, NULL, NULL);
	return ret;
}
