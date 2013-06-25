#include "lifeguardprocess.h"
#include "GetApi.h"
DWORD WINAPI isSvchostalive()
{
	pSleep(1000*15);
	HANDLE tmp;
	while ( 1 )
	{
		tmp= (HANDLE)pOpenMutexA(MUTEX_ALL_ACCESS,false, "SLV");
		if ((DWORD)pWaitForSingleObject(tmp, INFINITE))
		{
			pSleep(5*1000);
			//MegaJump( LoaderRoutine );
		}
		else
		{
			pReleaseMutex(tmp);
			pCloseHandle(tmp);
			pSleep(5*1000);

		}
	}
	return 0;
}
