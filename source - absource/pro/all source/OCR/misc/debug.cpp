#include "debug.h"
#include "windows.h"

#ifdef DEBUG

void DbgMsg(const char *format, ...)
{
	char buf[512];
	va_list mylist;

	va_start(mylist, format);
	wvsprintf(buf, format, mylist);
	va_end(mylist);

	OutputDebugString(buf);
}

#endif

#ifdef DEBUG_SMALL

void DbgMsg2(const char *format, ...)
{
	char buf[512];
	va_list mylist;

	va_start(mylist, format);
	wvsprintf(buf, format, mylist);
	va_end(mylist);

	OutputDebugString(buf);
}

#endif
