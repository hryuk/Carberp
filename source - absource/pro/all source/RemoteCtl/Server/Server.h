// Server.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CServerApp:
// See Server.cpp for the implementation of this class
//

class CServerApp : public CWinApp
{
public:
	CServerApp();

public:
	virtual BOOL InitInstance();
	DECLARE_MESSAGE_MAP()

public:
	int m_iServerPort;
};

extern CServerApp theApp;