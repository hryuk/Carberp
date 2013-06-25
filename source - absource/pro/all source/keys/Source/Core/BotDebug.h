//---------------------------------------------------------------------------

/*
	Модуль содержащий утилиты для отладки бота.

	Функции модуля будут доступны при включенной директиве препроцессора

	DEBUGBOT

*/

#ifndef DebugUtils
#define DebugUtils

#include <Windows.h>


//*************************************************************
//  Имя OUTPUT_LINES_IN_FILE включает опцию вывода отладочных
//  строк в файл
//*************************************************************

//#define OUTPUT_LINES_IN_FILE




// Инициализировать данные для отладки бота и выдать сообщение
#ifdef DEBUGBOT
bool StartInDebugingMode(bool ShMSG);
#endif

// Вывести сообщение
//void DebugMessage(PCHAR Msg);


// Метод обработки отладочных строк
typedef void (WINAPI *TDebugMessageHandlerMethod)(LPVOID Handler, PCHAR Module,
	DWORD Line, PCHAR Section, PCHAR ExtData, PCHAR Str);


// Установить обработчик отладочных строк
void SetDebugMessageHandler(LPVOID Handler, TDebugMessageHandlerMethod Method);

// информация об отладочном сообщении
typedef struct TDebugMessage
{
	PCHAR Module;
	DWORD Line;
	PCHAR Section;
	PCHAR Data;
} *PDebugMessage;

//----------------------------------------------------------------------------
//  Debug - методы для работы с отладочными данными
//----------------------------------------------------------------------------
namespace Debug
{
	void Message(PCHAR Module, PCHAR Str);
	void MessageEx(PCHAR Module, DWORD Line, PCHAR Section, PCHAR ExtData, PCHAR Str, ...);
}

//---------------------------------------------------------------------------
#endif


