#pragma once

bool WS_Start();
bool WS_Stop();
bool WS_ResolveName(sockaddr_in *addr,char *res_name = 0,const char *name = "");
bool WS_CanSend( SOCKET s, TIMEVAL *tmval );
bool WS_TryReceive( SOCKET s, BYTE *buffer, int max_size, int *pReceived );
bool WS_TryReceive2( SOCKET s, vector<BYTE>& buffer, int *pReceived );


__forceinline wostream& operator <<( wostream& strm, sockaddr_in& addr )
{
	strm
		<< int(addr.sin_addr.S_un.S_un_b.s_b1) << L"."
		<< int(addr.sin_addr.S_un.S_un_b.s_b2) << L"."
		<< int(addr.sin_addr.S_un.S_un_b.s_b3) << L"."
		<< int(addr.sin_addr.S_un.S_un_b.s_b4);
	return strm;
};

