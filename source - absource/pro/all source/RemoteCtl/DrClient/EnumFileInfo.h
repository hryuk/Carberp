#pragma once
#include "../common/protocol.h"



class CEnumFileInfo
{
public:

	WIN32_FIND_DATA *m_pFiles;
	int m_dwAllocated;
	int m_dwLen;

public:

	CEnumFileInfo();
	~CEnumFileInfo();
	
	bool GetList(TCHAR* filepath);
	bool Enum();
	void Add(WIN32_FIND_DATA *item);

protected:

	static BOOL CALLBACK MyEnumChildProc(HWND hw, LPARAM p);
	static BOOL CALLBACK CheckWindow(HWND hw, LPARAM p);
};