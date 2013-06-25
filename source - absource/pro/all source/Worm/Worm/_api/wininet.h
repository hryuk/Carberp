
HANDLE _WININET = 0;

BOOL (WINAPI *_InternetReadFile)( HINTERNET hFile, LPVOID lpBuffer, DWORD dwNumberOfBytesToRead, LPDWORD lpdwNumberOfBytesRead );
HINTERNET (WINAPI *_InternetOpenA)( LPCTSTR lpszAgent, DWORD dwAccessType, LPCTSTR lpszProxy,  LPCTSTR lpszProxyBypass, DWORD dwFlags );
HINTERNET (WINAPI *_InternetConnectA)( HINTERNET hInternet, LPCTSTR lpszServerName, INTERNET_PORT nServerPort, LPCTSTR lpszUserName, LPCTSTR lpszPassword, DWORD dwService, DWORD dwFlags, DWORD dwContext );
HINTERNET (WINAPI *_HttpOpenRequestA)( HINTERNET hConnect, LPCTSTR lpszVerb, LPCTSTR lpszObjectName, LPCTSTR lpszVersion, LPCTSTR lpszReferrer, LPCTSTR* lplpszAcceptTypes, DWORD dwFlags, DWORD dwContext );
BOOL (WINAPI *_HttpAddRequestHeadersA)( HINTERNET hHttpRequest, LPCTSTR lpszHeaders, DWORD dwHeadersLength, DWORD dwModifiers );
BOOL (WINAPI *_HttpSendRequestA)( HINTERNET hRequest, LPCTSTR lpszHeaders, DWORD dwHeadersLength, LPVOID lpOptional, DWORD dwOptionalLength );
BOOL (WINAPI *_InternetCloseHandle)( HINTERNET hInternet );


void* padrWininet[] = { &_InternetReadFile, &_InternetOpenA, &_InternetConnectA, &_HttpOpenRequestA, &_HttpAddRequestHeadersA, &_HttpSendRequestA, &_InternetCloseHandle };

void InitWininet()
{
 _WININET = _GetModuleHandle("wininet.dll"); 
 if (/*@S==*/_WININET == NULL/*@E*/) _WININET = _LoadLibrary("wininet.dll");

 InitAPIbyStr(padrWininet,_WININET,"/*@S|*/00InternetReadFile|01InternetOpenA|02InternetConnectA|03HttpOpenRequestA|04HttpAddRequestHeadersA|05HttpSendRequestA|06InternetCloseHandle/*@E*/|");
}
