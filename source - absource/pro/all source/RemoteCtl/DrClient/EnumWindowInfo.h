#pragma once
#include "../common/protocol.h"



class CEnumWindowInfo
{
public:

	WIN_INFO *m_pWindows;
//	WIN_INFO_CONTROL *m_pWindows;
	int m_dwAllocated;
	int m_dwLen;
	bool m_bShowAllWind;
	WCHAR m_WinHederName[25];
	WCHAR m_ProccessName[25];
	WCHAR m_ClassName[50];
public:

	CEnumWindowInfo();
	~CEnumWindowInfo();
	
	bool Enum_From( HWND hWnd );
	bool Enum(bool ShowAllWind ,WCHAR *WinHederName,WCHAR *ProccessName, WCHAR*ClassName);
	void Add( WIN_INFO *item );
protected:

	
	static BOOL CALLBACK MyEnumChildProc(HWND hw, LPARAM p);
	static BOOL CALLBACK CheckWindow(HWND hw, LPARAM p);
};
