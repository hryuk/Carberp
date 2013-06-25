
//---------------------------------------------------------------------------
//  Модуль фильтрации данных формграбера
//  
//	ВАЖНО: Модуль будет подключен к проекту только если его вызов имеется
//         в модуле Modules.h
//---------------------------------------------------------------------------

#ifndef FgrFiltersH
#define FgrFiltersH
//---------------------------------------------------------------------------

#include <windows.h>



#define FGRFILTER_PARAM_SIZE_URLS     3000
#define FGRFILTER_PARAM_SIZE_DATAMASK 3000

#define FGRFILTER_PARAM_NAME_URLS       "FGR_URL_FILTERS\0"
#define FGRFILTER_PARAM_NAME_DATAMASK   "FGR_PARAMS_FILTERS\0"

#ifndef DEBUGCONFIG
	#define FGRFILTER_PARAM_ENCRYPTED_URLS     true
	#define FGRFILTER_PARAM_ENCRYPTED_DATAMASK true
#else
	#define FGRFILTER_PARAM_ENCRYPTED_URLS     false
	#define FGRFILTER_PARAM_ENCRYPTED_DATAMASK false
#endif


//-------------------------------------------------
//  Функция фильтрует пост данные и в случае
//  необходимости отправки их на сервер возвращает
//  истину
//-------------------------------------------------
bool FiltratePostData(const char* URL, const char* Data);


//-------------------------------------------------
//  FiltrateFormGrabberURL - Функция возвращает
//  	истину если ссылка поддерживается
//		формграбером
//-------------------------------------------------
//bool FiltrateFormGrabberURL(PCHAR URL);


//-------------------------------------------------
//  FiltrateFormGrabberData - функция возвращает
//  	истину если данные прошли фильтрацию
//-------------------------------------------------
//bool FiltrateFormGrabberData(const char* Data);


//---------------------------------------------------------------------------
#endif
