#include "stdafx.h"
#include "../common/crypt.h"
#include "../common/keyfile.h"


ClientKey::ClientKey( LPCTSTR _name, bool bCreateBackHash )
	: name( _name )
{
	if( !CreateKey( backhash ) )
	{
		// fallback to simple way
		srand(timeGetTime());
		for( int i=0; i<16; i++ )
		{
			backhash.push_back(BYTE(rand()&0xFF));
		}
	}
}

bool ClientKey::Load()
{
	HANDLE hFile = CreateFile( name.c_str(), GENERIC_READ, 0, 0, OPEN_EXISTING, 0, 0 );
	if( hFile == INVALID_HANDLE_VALUE )
	{
		return false;
	}

	content.resize(GetFileSize(hFile,0));

	BYTE *p = content.get_allocator().address(content.front());
	DWORD dwRead = 0;
	if( !ReadFile( hFile, p, content.size(), &dwRead, 0 ) )
	{
		CloseHandle( hFile );
		return false;
	}

	CloseHandle( hFile );

	if( !CreateHash( content, hash ) )
	{
		return false;
	}

	return true;
}

bool ClientKey::InitFromString( LPCSTR s )
{
	content.clear();
	hash.clear();

	content.insert(
		content.end(),
		(BYTE*)s, (BYTE*)(s + strlen(s)) );

	if( !CreateHash( content, hash ) )
	{
		return false;
	}

	return true;
}
