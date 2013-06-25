#pragma once
#include "../common/protocol.h"

class CFileLoader
{
protected:

	PATCH_START m_Info;

	DWORD m_dwReceivedSize;
	BYTE *m_pData;
	bool m_bPatched;

public:

	CFileLoader( );
	~CFileLoader( );

	bool StartDownload( SOCKET s, PATCH_START *info );
	void ProcessData( SOCKET s, PATCH_DATA_ANSWER *info );

	DWORD GetReceivedBytes( );
	DWORD GetExpecetedBytes( );
	bool IsCompleted( );
};
