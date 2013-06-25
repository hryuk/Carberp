
//****************************************************************************
//  Шаблоны для упрощения работы с монитором работоспособности
//****************************************************************************

#include "windows.h"

#ifdef BOTMONITOR
	#include "BotMonitorConsts.h"
#endif



// Макрос получаеня константы монитора
#ifdef BOTMONITOR
	#define BMCONST(ConstName) BotMonitor::ConstName
#else
	#define BMCONST(ConstName) NULL
#endif



// Шаблоны вызова сообшений
template <class MESSAGE, class DATA>
inline void OutMonitorMessage(MESSAGE Message, DATA Data)
{
	#ifdef BOTMONITOR
		BotMonitor::SendMessage((PCHAR)Message, (PCHAR)Data, 0);
	#endif
}

// Шаблоны вызова сообшений
template <class MESSAGE, class ARG1, class DELIMETER, class ARG2>
inline void OutMonitorDelimetedMessage(MESSAGE Message, ARG1 Arg1, DELIMETER Delimeter, ARG2 Arg2)
{
	#ifdef BOTMONITOR
		PCHAR S = STR::New(3, (PCHAR)Arg1, (PCHAR)Delimeter, (PCHAR)Arg2);
		BotMonitor::SendMessage((PCHAR)Message, S, 0);
		STR::Free(S);
	#endif
}

// Макросы вывода сообщений монитору работоспособности
#define MONITOR_MSG OutMonitorMessage<>
#define MONITOR_DELIMETED_MSG OutMonitorDelimetedMessage<>


