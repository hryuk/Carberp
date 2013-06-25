#ifndef _dprint_h_
#define _dprint_h_

#ifndef NDEBUG

void LogOutput(const wchar_t * message, ...);

#define DbgMsg LogOutput

#else
#define DbgMsg __noop
#endif

#endif _dprint_h_
