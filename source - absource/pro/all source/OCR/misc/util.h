#pragma once
#include "windows.h"
#include "types.h"

const char* u_strstr(const char* s, const char* sub);
const char* u_istrstr(const char* s, const char* sub);
bool u_SaveToFile( const char* nameFile, void* data, int c_data);
char* u_alloc(int sz, bool zero = false);
void u_free(void* mem);
HANDLE u_CreateFile(const char* nameFile, bool read = false, bool add = false);
int u_WriteFile(HANDLE file, void* data, int c_data);
int u_ReadFile(HANDLE file, void* data, int c_data);
void u_CloseFile(HANDLE file);
void u_SaveHexData( const char* nameFile, unsigned char* data, int c_data );
int u_atoi( const char* s );
int u_GetNameProcess( DWORD pid, HWND hwnd, char* );
void u_memcpy( char* dst, char* src, int c);
int u_ReadAllBytes( const char* nameFile, uchar** data );
int u_WriteAllBytes( const char* nameFile, uchar* data, int c_data );
char* ToAnsi(const WCHAR* s);