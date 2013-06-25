#include <windows.h>
#include "dprint.h"



#define BOTAPI_ENABLED


#ifdef DPRINTF_ENABLED
	PP_COMPILER_MESSAGE("DPRINTF_ENABLED is defined.");
#else
	PP_COMPILER_MESSAGE("DPRINTF_ENABLED is NOT defined.");
#endif

#ifdef BOTAPI_ENABLED
	PP_COMPILER_MESSAGE("BOTAPI_ENABLED is defined.");
#else
	PP_COMPILER_MESSAGE("ENABLE_DPRINTF is NOT defined.");
#endif



#ifdef DPRINTF_ENABLED
#ifndef BOTAPI_ENABLED

#include <time.h>
#include <stdio.h>

void logoutputv(const char* src_file, int src_line, const wchar_t *message, va_list ptr)
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
#else

#include "GetApi.h"
#include "Strings.h"
#include "Memory.h"

void User32Sprintf(WCHAR* buffer, const WCHAR* format, ...)
{
  va_list ptr;
  va_start(ptr, format);
  pwvsprintfW(buffer, format, ptr);
  va_end(ptr);
}

void OutputDebugStringToFile(const WCHAR* buffer)
{
  SECURITY_ATTRIBUTES sa;
  SECURITY_DESCRIPTOR sd;

	pInitializeSecurityDescriptor(&sd, SECURITY_DESCRIPTOR_REVISION);
  pSetSecurityDescriptorDacl(&sd, TRUE, NULL, FALSE);
  
  sa.nLength = sizeof (SECURITY_ATTRIBUTES);
  sa.lpSecurityDescriptor = &sd;
  sa.bInheritHandle = FALSE;

	HANDLE      mutex = ::CreateMutexA(&sa, FALSE, "Global\\{450A06EC-D49F-40F9-A3AC-1DE7488DCF09}");
	const CHAR* path  = "c:\\{F7B8F938-44CA-4AF5-82D5-8EFB5A7FD6B0}.log";

	pWaitForSingleObject(mutex, INFINITE);

	HANDLE f = CreateFileA(path, GENERIC_WRITE, 0, &sa, OPEN_ALWAYS, 0, NULL);
	if (f != INVALID_HANDLE_VALUE)
	{
		pSetFilePointer(f, 0, 0, FILE_END);
		DWORD length = (DWORD)plstrlenW(buffer);
		DWORD written = 0;
		pWriteFile(f, buffer, length * sizeof(WCHAR), &written, NULL);
		pCloseHandle(f);
	}

	pReleaseMutex(mutex);
	pCloseHandle(mutex);
}

void logoutputv(const char* src_file, int src_line, const WCHAR *message, va_list ptr)
{
  SYSTEMTIME       current_time;  
  wchar_t          buffer[1024];
  size_t           buffer_length = ARRAYSIZE(buffer);
  
  m_memset(buffer, 0, sizeof(buffer));

  // checks the level and log opening
	pGetLocalTime(&current_time);

	User32Sprintf(buffer, L"%02u%02u-%02u%02u%02u:%u:\t", 
		current_time.wMonth, 
		current_time.wDay, 
		current_time.wHour, 
		current_time.wMinute, 
		current_time.wSecond,
		pGetCurrentProcessId()
		);

	DWORD   message_length = (DWORD)plstrlenW(buffer);
	WCHAR*  message_placement = &buffer[0] + message_length;

	buffer_length -= message_length;

	DWORD written = (DWORD)pwvsprintfW(message_placement, message, ptr);

	if (written < (buffer_length - 3))
	{
		message_placement[written++] = L'\r';
		message_placement[written++] = L'\n';
		message_placement[written] = L'\0';
	}

	pOutputDebugStringW(buffer);
	//OutputDebugStringToFile(buffer);
}

#endif // #ifndef BOTAPI_ENABLED

//------------------------------------------------------------------------------
void LogOutput(const char* src_file, int src_line, 
	const wchar_t * message, ...)
{
	va_list ptr;
	va_start(ptr, message);
	logoutputv(src_file, src_line, message, ptr);
	va_end(ptr);
}
#endif // #ifdef  DPRINTF_ENABLED
