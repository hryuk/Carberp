//----------------------------------------------------------------------------
//#ifndef DbgTemplatesH
//#define DbgTemplatesH

//****************************************************************************
//  Набор макросов вывода отладочных строк.
//
//  Макросы вызывают функции из модуля BotDebug
//  Выведены с целью облегчить код и не заграмождать его директивами
//  условной компиляции
//****************************************************************************

template <class MODULE, class LINE, class SECTION, class DATA, class STR>
inline void DBGOutMessageEX(MODULE Module, LINE Line, SECTION Section, DATA Data, STR Str)
{
	#ifdef DebugUtils 
		Debug::MessageEx((PCHAR)Module, Line, (PCHAR)Section, (PCHAR)Data, (PCHAR)Str);
	#endif
}

template <class MODULE, class LINE, class SECTION, class DATA, class STR, class ARG1>
inline void DBGOutMessageEX(MODULE Module, LINE Line, SECTION Section, DATA Data, STR Str, ARG1 Arg1)
{
	#ifdef DebugUtils
		Debug::MessageEx((PCHAR)Module, Line, (PCHAR)Section, (PCHAR)Data, (PCHAR)Str, Arg1);
	#endif
}

template <class MODULE, class LINE, class SECTION, class DATA, class STR, class ARG1, class ARG2>
inline void DBGOutMessageEX(MODULE Module, LINE Line, SECTION Section, DATA Data, STR Str, ARG1 Arg1, ARG2 Arg2)
{
	#ifdef DebugUtils
		Debug::MessageEx((PCHAR)Module, Line, (PCHAR)Section, (PCHAR)Data, (PCHAR)Str, Arg1, Arg2);
	#endif
}

template <class MODULE, class LINE, class SECTION, class DATA, class STR, class ARG1, class ARG2, class ARG3>
inline void DBGOutMessageEX(MODULE Module, LINE Line, SECTION Section, DATA Data, STR Str, ARG1 Arg1, ARG2 Arg2, ARG3 Arg3)
{
	#ifdef DebugUtils
		Debug::MessageEx((PCHAR)Module, Line, (PCHAR)Section, (PCHAR)Data, (PCHAR)Str, Arg1, Arg2, Arg3);
	#endif
}



template <class MODULE, class STR>
inline void DBGOutMessage(MODULE Module, STR Str)
{
	#ifdef DebugUtils
		Debug::MessageEx((PCHAR)Module, 0, NULL, NULL, (PCHAR)Str);
	#endif
}

template <class MODULE, class STR, class ARG1>
inline void DBGOutMessage(MODULE Module, STR Str, ARG1 Arg1)
{
	#ifdef DebugUtils
		Debug::MessageEx((PCHAR)Module, 0, NULL, NULL, (PCHAR)Str, Arg1);
	#endif
}

template <class MODULE, class STR, class ARG1, class ARG2>
inline void DBGOutMessage(MODULE Module, STR Str, ARG1 Arg1, ARG2 Arg2)
{
	#ifdef DebugUtils
		Debug::MessageEx((PCHAR)Module, 0, NULL, NULL, (PCHAR)Str, Arg1, Arg2);
	#endif
}

template <class MODULE, class STR, class ARG1, class ARG2, class ARG3>
inline void DBGOutMessage(MODULE Module, STR Str, ARG1 Arg1, ARG2 Arg2, ARG3 Arg3)
{
	#ifdef DebugUtils
		Debug::MessageEx((PCHAR)Module, 0, NULL, NULL, (PCHAR)Str, Arg1, Arg2, Arg3);
	#endif
}


#define DBGEX DBGOutMessageEX<>
#define DBG   DBGOutMessage<>



//----------------------------------------------------------------------------
//#endif
