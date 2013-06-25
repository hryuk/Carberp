#pragma once

#undef WINVER
#define WINVER 0x0501
#undef _WIN32_WINNT
#define _WIN32_WINNT 0x0501

#include <winsock2.h>
#include <windows.h>
#include <mmsystem.h>

#include <ShObjIdl.h>
#include <shlobj.h>
#include <Psapi.h>

#include <gdiplus.h>
#include <gdiplusinit.h>
#include <gdiplusimagecodec.h>
using namespace Gdiplus;


// memory allocation
///#pragma comment( linker, "/nodefaultlib:libcmt")




__forceinline LPVOID ncrt_malloc( size_t size )
{
	return VirtualAlloc( 0, size, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE );
}

__forceinline void ncrt_free( LPVOID lpAddr )
{
	if ( lpAddr != NULL )
	{
		VirtualFree( lpAddr, 0, MEM_RELEASE );
	}
}

__forceinline LPVOID ncrt_realloc( LPVOID lpAddr, size_t size )
{
	if( lpAddr )
	{
		MEMORY_BASIC_INFORMATION MemInfo;
		VirtualQuery( lpAddr, &MemInfo, sizeof( MEMORY_BASIC_INFORMATION ) );
		if( MemInfo.RegionSize < size )
		{
			LPVOID lpAddrNew = ncrt_malloc( size );
			CopyMemory( lpAddrNew, lpAddr, MemInfo.RegionSize );
			ncrt_free( lpAddr );
			lpAddr = lpAddrNew;
		}
	}
	else
	{
		lpAddr = ncrt_malloc( size );
	}
	return lpAddr;
}

__forceinline WCHAR *ncrt_strstr( WCHAR *s, WCHAR *needle )
{
	for( int i=0; s[i]; i++ )
	{
		if( s[i] == needle[0] )
		{
			bool bMatch = true;
			int j;

			for( j=0; s[i+j] && needle[j]; j++ )
			{
				if( s[i+j] != needle[j] )
				{
					bMatch = false;
					break;
				}
			}
			if (wcslen(s+i)<wcslen(&needle[j]) || wcslen(&needle[j]) != 0)
			{
				bMatch = false;
			}
			if( bMatch )
			{
				return s+i;
			}
		}
	}
	return 0;
}

#define malloc ncrt_malloc
#define free ncrt_free
#define realloc ncrt_realloc
#define wcsstr ncrt_strstr


__forceinline LPVOID __cdecl ncrt_memset( LPVOID dest, BYTE value, size_t size )
{
	BYTE *pMem = (BYTE*)dest;
	for( size_t i=0; i<size; i++ )
	{
		pMem[i] = value;
	}
	return dest;
}

#undef ZeroMemory
#define ZeroMemory(a,b) ncrt_memset(a,0,b)
#define memset ncrt_memset



#pragma warning(disable:4101)
#pragma warning(disable:4996)
#pragma warning(disable:4995)
#pragma warning(disable:4995)
#pragma warning(disable:4244)
#pragma warning(disable:4800)
#pragma warning(disable:4806)
#pragma warning(disable:4715)
#pragma warning(disable:4018)
#pragma warning(disable:4129)
#pragma warning(disable:4091)

