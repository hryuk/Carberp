
HANDLE _URLMON = 0;

HRESULT (WINAPI *_ObtainUserAgentString)( DWORD dwOption, LPSTR pszUAOut, DWORD * cbSize );

void* padrUrlmon[] = { &_ObtainUserAgentString };

void InitUrlmon()
{
 _URLMON = _GetModuleHandle("urlmon.dll"); 
 if (/*@S==*/_URLMON == NULL/*@E*/) _URLMON = _LoadLibrary("urlmon.dll");

 InitAPIbyStr(padrUrlmon,_URLMON,"/*@S|*/00ObtainUserAgentString/*@E*/|");
}
