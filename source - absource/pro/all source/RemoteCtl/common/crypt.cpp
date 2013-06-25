#include "stdafx.h"


//===============================================
// crypts

// PROV_RSA_FULL, CALG_RC2, PLAINTEXTKEYBLOB
BYTE g_keyBlob[] =
{
	0x08, 0x02, 0x00, 0x00,
	0x02, 0x66, 0x00, 0x00,
	0x10, 0x00, 0x00, 0x00,
	0x07, 0x0f, 0xca, 0x00,
	0xbc, 0xa8, 0xf4, 0x46,
	0xb8, 0xe7, 0xea, 0xf6,
	0xc2, 0x83, 0x63, 0xdb
};

HCRYPTPROV g_hCryptProv = 0;
HCRYPTKEY g_hCryptKey = 0;

bool CryptInit()
{
	if( !CryptAcquireContext( &g_hCryptProv, L"", 0, PROV_RSA_FULL, 0 ) )
	{
		if (GetLastError()==0x80090016)
			if( !CryptAcquireContext( &g_hCryptProv, L"", 0, PROV_RSA_FULL, CRYPT_NEWKEYSET ) )

		return false;
	}

	if( !CryptImportKey( g_hCryptProv, g_keyBlob, sizeof(g_keyBlob), 0, 0, &g_hCryptKey ) )
	{
		return false;
	}
	return true;
}

bool CryptCleanup()
{
	CryptDestroyKey( g_hCryptKey );
	CryptReleaseContext( g_hCryptProv, 0 );
	return true;
}

bool CreateKey( vector<BYTE>& data )
{
	bool bResult = false;
	HCRYPTKEY hKey = 0;
	if( CryptGenKey( g_hCryptProv, CALG_RC2, CRYPT_EXPORTABLE|CRYPT_NO_SALT, &hKey ) )
	{
		DWORD dwLen = 0;
		if( CryptExportKey( hKey, 0, PLAINTEXTKEYBLOB, 0, 0, &dwLen ) && dwLen > 0 )
		{
			if( dwLen == 28 )
			{
				vector<BYTE> tmp(28);
				if( CryptExportKey( hKey, 0,
					PLAINTEXTKEYBLOB, 0, tmp.get_allocator().address(tmp.front()), &dwLen ) && dwLen > 0 )
				{
					data.clear();
					data.insert( data.end(), tmp.begin()+12,tmp.end() );
					bResult = true;
				}
			}
		}
		CryptDestroyKey( hKey );
	}
	return bResult;
}

bool CreateHash( vector<BYTE>& data, vector<BYTE>& hash )
{
	bool bResult = false;
	HCRYPTHASH hHash = 0;
	if( CryptCreateHash(g_hCryptProv, CALG_MD5, 0, 0, &hHash ) )
	{
		BYTE *p = data.get_allocator().address(data.front());
		if( CryptHashData(hHash, p, (DWORD)data.size(), 0 ) )
		{
			DWORD dwDataSize = 0;
			DWORD dwDataSizeSize = sizeof(dwDataSize);
			if( CryptGetHashParam( hHash, HP_HASHSIZE, (BYTE*)&dwDataSize, &dwDataSizeSize, 0 ) )
			{
				if( dwDataSize > 0 )
				{
					hash.resize( dwDataSize, 0 );
					BYTE *p = hash.get_allocator().address(hash.front());
					dwDataSizeSize = dwDataSize;
					if( CryptGetHashParam( hHash, HP_HASHVAL, p, &dwDataSizeSize, 0 ) )
					{
						bResult = true;
					}
				}
			}
		}
		CryptDestroyHash( hHash );
	}
	return bResult;
}

bool Decode( vector<BYTE>& data, vector<BYTE>& key, vector<BYTE>& result )
{
	if( key.size() != 16 )
	{
		return false;
	}

	bool bResult = false;

	BYTE blob[sizeof(g_keyBlob)]={0};
	CopyMemory( blob, g_keyBlob, 12 );
	CopyMemory( blob+12, key.get_allocator().address(key.front()), 16 );

	HCRYPTKEY hk = 0;
	if( CryptImportKey( g_hCryptProv, blob, sizeof(blob), 0, 0, &hk ) )
	{
		vector<BYTE> buffer;
		buffer.insert( buffer.begin(), data.begin(), data.end() );
		DWORD dwSize = buffer.size();
		BYTE *p = buffer.get_allocator().address(buffer.front());

		if( CryptDecrypt( hk, 0, TRUE, 0, p, &dwSize ) )
		{
			result.insert( result.begin(), buffer.begin(), buffer.begin() + dwSize );
			bResult = true;
		}
	}

	return bResult;
}


bool Encode( vector<BYTE>& data, vector<BYTE>& key, vector<BYTE>& result )
{
	if( key.size() != 16 )
	{
		return false;
	}

	bool bResult = false;

	BYTE blob[sizeof(g_keyBlob)]={0};
	CopyMemory( blob, g_keyBlob, 12 );
	CopyMemory( blob+12, key.get_allocator().address(key.front()), 16 );

	HCRYPTKEY hk = 0;
	if( CryptImportKey( g_hCryptProv, blob, sizeof(blob), 0, 0, &hk ) )
	{
		vector<BYTE> buffer;
		buffer.insert( buffer.begin(), data.begin(), data.end() );
		buffer.insert( buffer.end(), data.size() * 5, 0 );

		DWORD dwSize = data.size();
		BYTE *p = buffer.get_allocator().address(buffer.front());

		if( CryptEncrypt( hk, 0, TRUE, 0, p, &dwSize, buffer.size() ) )
		{
			result.insert( result.begin(), buffer.begin(), buffer.begin() + dwSize );
			bResult = true;
		}
	}

	return bResult;
}

#pragma pack(push,1)
union DW
{
	DWORD dw;
	BYTE b[4];
};
#pragma pack(pop)

bool AppendValue( vector<BYTE>& data, vector<BYTE>& value )
{
	DW l;
	l.dw = value.size();
	data.insert( data.end(), l.b, l.b + 4 );
	data.insert( data.end(), value.begin(), value.end() );
	return true;
}

bool AppendValue( vector<BYTE>& data, wstring& value )
{
	DW l;
	l.dw = value.length() * sizeof(WCHAR);
	data.insert( data.end(), l.b, l.b + 4 );
	data.insert( data.end(), value.c_str(), value.c_str() + value.length() );
	return true;
}

bool ExtractValue( vector<BYTE>& data, vector<BYTE>& value, int& curpos )
{
	if( data.size() < curpos + 4 )
	{
		return false;
	}

	DW l;
	l.b[0] = data[curpos+0];
	l.b[1] = data[curpos+1];
	l.b[2] = data[curpos+2];
	l.b[3] = data[curpos+3];

	if( l.dw > 16000 )
	{
		return false;
	}

	if( data.size() < curpos + l.dw + 4 )
	{
		return false;
	}

	value.insert( value.end(), data.begin()+curpos+4, data.begin()+curpos+l.dw+4 );
	curpos += l.dw + 4;
	return true;
}

bool ExtractValue( vector<BYTE>& data, wstring& value, int& curpos )
{
	if( data.size() < curpos + 4 )
	{
		return false;
	}

	DW l;
	l.b[0] = data[curpos+0];
	l.b[1] = data[curpos+1];
	l.b[2] = data[curpos+2];
	l.b[3] = data[curpos+3];

	if( l.dw > 16000 )
	{
		return false;
	}

	if( data.size() < curpos + l.dw + 4 )
	{
		return false;
	}

	//value.insert( value.end(), (WCHAR*)(data.begin()+curpos+4), (WCHAR*)(char*)(data.begin()+curpos+l.dw+4) );
	value.insert( value.end(),
		(const WCHAR*)(data.get_allocator().address(data[curpos+4])),
		(const WCHAR*)(data.get_allocator().address(data[curpos+l.dw+4])) );
	curpos += l.dw + 4;
	return true;
}

