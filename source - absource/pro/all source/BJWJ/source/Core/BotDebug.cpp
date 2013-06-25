//---------------------------------------------------------------------------
#include <windows.h>

#include "GetApi.h"
#include "Strings.h"
#include "Memory.h"
#include "Utils.h"


#include "BotDebug.h"

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


	void OutputDebugStringInFileA(PCHAR Section, PCHAR Line)
	{
		// Функция выводит отладочную строку в файл
		string FileName = BotDebugPath;

		#ifdef SPLIT_LOG_ON_MODULES
			if (!DirExists((PCHAR)BotDebugPath))
				pCreateDirectoryA(BotDebugPath, NULL);
			FileName += "\\";
			FileName += (!STRA::IsEmpty(Section)) ? Section : "Default";
		#endif

		FileName += ".log";

		HANDLE File = OpenDebugFile(FileName.t_str());
		if (File == NULL)
			return;

		pSetFilePointer(File, 0, 0, FILE_END);


		DWORD Writed = NULL;
		pWriteFile(File, Line, StrCalcLength(Line), &Writed, NULL);
		pWriteFile(File, "\r\n", 2, &Writed, NULL);


        pCloseHandle(File);
	}

#endif


#ifdef DebugUtils
	PP_COMPILER_MESSAGE("Debug output enabled.('DebugUtils' defined)");
#else
	PP_COMPILER_MESSAGE("Debug output disabled.('DebugUtils' NOT defined.)");
#endif


void Debug::MessageEx(PCHAR Module, DWORD Line, PCHAR Section, PCHAR ExtData, PCHAR Str, ...)
{
	// Вызвать отладочное сообщение
#ifdef DebugUtils
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


	char StrFmt[]      = {'%', 's',  0};
	char NomberLine[]  = {'(', '%', 's', ')',  0};
	char SectionLine[] = {' ', '[', ' ', '%', 's', ' ', ']',  0};
    char MsgLine[]     = {' ', ':', ' ', ' ', '%', 's',  0};

	// Определяем маску строки
	PCHAR NL = (Line != 0)? NomberLine : StrFmt;
	PCHAR SL = (!STR::IsEmpty(Section))? SectionLine : StrFmt;

	PCHAR SourceLine = STR::New(5, StrFmt, NL, SL, MsgLine, "\r\n");
	// "%s(%d) [ %s ] : %s"

	// Собираем строку
	PCHAR LineStr = (Line != 0) ? StrLongToString(Line) : NULL;

	_wsprintfA(ExtLine, SourceLine, Module, LineStr, Section, FullLine);

	STR::Free(SourceLine);
	STR::Free(LineStr);

	#ifdef OUTPUT_LINES_IN_FILE
		OutputDebugStringInFileA(Module, ExtLine);
	#else
		pOutputDebugStringA(ExtLine);
	#endif
	STR::Free(FullLine);
	STR::Free(ExtLine);
#endif
}

void Debug::Message(PCHAR Module, PCHAR Str)
{
	MessageEx(Module, 0, NULL, NULL, Str);
}

#ifdef DebugUtils

void logoutputv( const char* src_file, int src_line, const char* message, va_list ptr )
{
	char buffer[1024];
	(DWORD)pwvsprintfA( buffer, message, ptr );
	pOutputDebugStringA(buffer);
}

void LogOutput( const char* src_file, int src_line, const char* message, ... )
{
	va_list ptr;
	va_start( ptr, message );
	logoutputv( src_file, src_line, message, ptr );
	va_end(ptr);
}

#endif