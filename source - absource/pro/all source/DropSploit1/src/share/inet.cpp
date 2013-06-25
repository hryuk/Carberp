#include <windows.h>
#include <wininet.h>
#include <stdio.h>

#include "ntdll.h"
#include "inet.h"
#include "utils.h"
#include "xstring.h"

XString *InetLoadUrl(PINET_LOAD_URL lpLoad)
{
	XString *Buffer = NULL;
	CHAR szHeaders[1024];
	URL_COMPONENTS UrlComp;
	CHAR szServerName[128];
	CHAR szObjectName[1048];
	CHAR szScheme[64];
	HINTERNET hConnect;
	HINTERNET hRequest;
	HINTERNET hInternet;

	hInternet = InternetOpen("Mozilla/4.0 (compatible; MSIE 6.0; Windows NT 5.1; SV1)",INTERNET_OPEN_TYPE_PRECONFIG,NULL,NULL,0);
	if (hInternet)
	{
		ZeroMemory(&UrlComp,sizeof(UrlComp));
		UrlComp.dwStructSize = sizeof(UrlComp);
		UrlComp.lpszHostName = szServerName;
		UrlComp.dwHostNameLength = sizeof(szServerName);
		UrlComp.lpszUrlPath = szObjectName;
		UrlComp.dwUrlPathLength = sizeof(szObjectName);
		UrlComp.lpszScheme = szScheme;
		UrlComp.dwSchemeLength = sizeof(szScheme);

		if (InternetCrackUrl(lpLoad->lpUrl,NULL,ICU_ESCAPE,&UrlComp))
		{
			if (hConnect = InternetConnect(hInternet,UrlComp.lpszHostName,UrlComp.nPort,NULL,NULL,INTERNET_SERVICE_HTTP,0,NULL))
			{
				DWORD dwFlags = INTERNET_FLAG_NO_COOKIES|INTERNET_FLAG_RELOAD|INTERNET_FLAG_NO_CACHE_WRITE|INTERNET_FLAG_PRAGMA_NOCACHE;

				if (!_stricmp(szScheme,"https"))
				{
					dwFlags |= INTERNET_FLAG_SECURE|INTERNET_FLAG_IGNORE_CERT_CN_INVALID|INTERNET_FLAG_IGNORE_CERT_DATE_INVALID;
				}

				if (hRequest = HttpOpenRequest(hConnect,lpLoad->lpMethod,UrlComp.lpszUrlPath,NULL,NULL,NULL,dwFlags,NULL))
				{
					DWORD dwSecFlags = SECURITY_FLAG_IGNORE_UNKNOWN_CA|SECURITY_FLAG_IGNORE_REVOCATION|SECURITY_FLAG_IGNORE_WRONG_USAGE|
						SECURITY_FLAG_IGNORE_REDIRECT_TO_HTTPS;

					InternetSetOption(hRequest,INTERNET_OPTION_SECURITY_FLAGS,&dwSecFlags,sizeof(dwSecFlags));
					
					szHeaders[0] = '\0';

					if (lpLoad->lpContentType)
					{
						_snprintf(szHeaders,sizeof(szHeaders)-1,"Content-Type: %s\r\n",lpLoad->lpContentType);
					}
					else
					{
						if (lpLoad->lpHeaders) _snprintf(szHeaders,sizeof(szHeaders),"%s",lpLoad->lpHeaders);
					}

					if (HttpSendRequest(hRequest,szHeaders,-1,(LPVOID)lpLoad->lpPostData,lpLoad->cbPostData))
					{
						DWORD dwStatusCodeSize = sizeof(DWORD);

						if (!HttpQueryInfo(hRequest,HTTP_QUERY_STATUS_CODE|HTTP_QUERY_FLAG_NUMBER,&lpLoad->dwHttpStatus,&dwStatusCodeSize,NULL))
						{
							DbgPrint(__FUNCTION__"(): HttpQueryInfo failed error %d\n",GetLastError());

							lpLoad->dwHttpStatus = -1;
						}
							
						UCHAR Tmp[1024*4];
						DWORD dwRead;

						for (;;)
						{
							if (InternetReadFile(hRequest,Tmp,sizeof(Tmp),&dwRead) && dwRead)
							{
								if (!Buffer)
								{
									Buffer = new XString((PUCHAR)Tmp,dwRead);
								}
								else
								{
									Buffer->Append((PUCHAR)Tmp,dwRead);
								}
							}
							else
							{
								break;
							}
						}
					}	
					else
					{
						DbgPrint(__FUNCTION__"(): HttpSendRequest failed error %d\n",GetLastError());
					}

					InternetCloseHandle(hRequest);
				}
				else
				{
					DbgPrint(__FUNCTION__"(): HttpOpenRequest failed error %d\n",GetLastError());
				}
					
				InternetCloseHandle(hConnect);
			}
			else
			{
				DbgPrint(__FUNCTION__"(): InternetConnect failed error %d\n",GetLastError());
			}
		}
		else
		{
			DbgPrint(__FUNCTION__"(): InternetCrackUrl failed error %d\n",GetLastError());
		}

		InternetCloseHandle(hInternet);
	}
	else
	{
		DbgPrint(__FUNCTION__"(): InternetOpen failed error %d\n",GetLastError());
	}

	return Buffer;
}