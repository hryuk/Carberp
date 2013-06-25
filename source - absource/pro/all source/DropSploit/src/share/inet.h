#ifndef _INET_H_
#define _INET_H_

#include "xstring.h"

VOID InitInetLoad();
VOID SetUserAgent(LPSTR lpUserAgent);

typedef struct _INET_LOAD_URL
{
	LPCSTR lpUrl;
	LPCSTR lpMethod;
	LPCSTR lpHeaders;
	LPCSTR lpContentType;
	LPCVOID lpPostData;
	DWORD cbPostData;
	DWORD dwHttpStatus;
} INET_LOAD_URL,*PINET_LOAD_URL;

XString *InetLoadUrl(PINET_LOAD_URL lpLoad);

#endif