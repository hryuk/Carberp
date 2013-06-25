#pragma once

#ifdef DEBUG

void DbgMsg(const char *format, ...);

#else

inline void DbgMsg(const char *format, ...)
{
}

#endif //DEBUG

#ifdef DEBUG_SMALL

void DbgMsg2(const char *format, ...);

#else

inline void DbgMsg2(const char *format, ...)
{
}

#endif //DEBUG_SMALL
