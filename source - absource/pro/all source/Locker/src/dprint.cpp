#include <windows.h>
#include <time.h>
#include <stdio.h>

#include "dprint.h"


#ifdef ENABLE_DPRINTF

//------------------------------------------------------------------------------
void logoutputv(const wchar_t *message, va_list ptr)
{
  time_t           curTime = 0;  
  wchar_t          logTextBuffer[4096];
  size_t           bufferLength = ARRAYSIZE(logTextBuffer);
  
  memset(logTextBuffer, 0, sizeof(logTextBuffer));

  // checks the level and log opening
    
  time(&curTime);
  _wctime_s(logTextBuffer, bufferLength, &curTime);

  logTextBuffer[24] = ' '; // replace \n symbol for the space symbol

  WCHAR pid_buffer[20];
  _itow_s(GetCurrentProcessId(), pid_buffer, 10);

  wcscat_s(logTextBuffer, bufferLength, L": ");
  wcscat_s(logTextBuffer, bufferLength, pid_buffer);
  

#ifdef DPRINTF_MODULE_NAME
  wcscat_s(logTextBuffer, bufferLength, DPRINTF_MODULE_NAME);
#else
  PP_COMPILER_MESSAGE("DPRINTF_MODULE_NAME unicode string not defined.");
  wcscat_s(logTextBuffer, bufferLength, L"(none)");
#endif

  wcscat_s(logTextBuffer, bufferLength, L":\t");

  size_t    messageLength = wcslen(logTextBuffer);
  wchar_t*  messagePlacement = &logTextBuffer[0] + messageLength;
  
  bufferLength -= (messageLength);

  size_t len = _vsnwprintf_s(messagePlacement, bufferLength, 
    bufferLength - 4,  message, ptr);

  if (len > 0)
  {
    messagePlacement[len++] = L'\r';
    messagePlacement[len++] = L'\n';
    messagePlacement[len] = L'\0';
  }

  OutputDebugStringW(logTextBuffer);
}
//------------------------------------------------------------------------------
void LogOutput(const wchar_t * message, ...)
{
  va_list ptr;
  va_start(ptr, message);
  logoutputv(message, ptr);  
  va_end(ptr);
}
//------------------------------------------------------------------------------
#endif

