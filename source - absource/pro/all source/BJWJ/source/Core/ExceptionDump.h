#ifndef UUID_6140C07EBBDC4FC18600498BA2A18935
#define UUID_6140C07EBBDC4FC18600498BA2A18935


/*
	Формат файла на диске:
	последовательность структур. 
	NameTypeLengthValue(Ntlv)
	
	NtlvRecord
	{
		BYTE[4]  Signature;
		BYTE     Type;
		BYTE     NameLength;
		DWORD    ValueLength;
		BYTE[]   Name;
		BYTE[]   Value;
	}
	
	Основной момент, который делает этот формат расширяемым:
	тип может быть либо простым типом, либо списком.
	
	Список - это особый элемент,Value которого является 4 байтным беззнаковым целым,
	указывающим кол-во элементов списка. При этом список может содержать элементом 
	список, у которого будет своё кол-во элементов.

	Чтение и запись такого файла является простым по следующим причинам:
	- всё в динамике - нет фиксированного порядка структур, читатель 
	  работает с именами и типами.
	- зафиксированы основные типы и возможно привязать базовый верификатор
	  правильности чтения
	- процесс чтение чрезвычайно прост - до конца файла читаются простые структурки.
	- базовый формат зафиксирован и не меняется. Меняется только обработчик 
	  считанного списка.
	- обработка вложенности отделена от базового чтения.
	  То есть очень просто дебажить - просто выводить считанный список структур
	
	Такая структура организации данных подсмотрена в LISP и протоколе ICQ.
*/

namespace DUMP {

// Для независимости от ф-ции записи создаем слой для абстракции записи 
// Сделаем для файла, а можно будет для памяти, для отсылки в сеть и тд.
// В любом случае слой логики хранения отделяется от деталей создания  
// структуры дампа.

// Потоки создают через так называемые инициаторы потоков.
// Они выполняют роль конструкторов для конкретных реализаций потоков.
// Пример: в конце файла есть инициатор File_InitDumpWriteStream
// Это инициатор для вывода в файл. Он настраивает ф-ции в структуре и 
// указатель stream_ctx на прозрачную для пользователя стуктуру контекста,
// в которой хранит хендл файла.
struct WriteStream
{
	bool (*Write)(WriteStream* Stream, const void* Data, DWORD DataLength,
		DWORD* Written);

	void (*Finish)(WriteStream* Session);

	void* stream_ctx;
};

struct ReadStream
{
	bool (*Read)(ReadStream* Stream, void* Buffer, DWORD BufferLength,
		DWORD* ReadBytes);

	void* stream_ctx;
};

// Текущие поддерживаемые типы данных, которые можно выводить в дамп.
// Записи не пишутся напрямую, только через ф-ции форматированного вывода для 
// соответствующего типа.
// При необходимости нового типа :
//   добавляется новый тип в этой таблице
//   добавляется соответствующая ф-ция Write<Type>

enum DumpValueType
{
	// Беззнаковое 4-байтное целое.
	DumpValueType_Uint32    = 0x01,
	
	// Массив WCHAR без итогового нулевого символа
	DumpValueType_StringW   = 0x02,
	
	// Массив байт. Для передачи простого дампа памяти.
	DumpValueType_ByteArray = 0x03,

	// Массив CHAR без итогового нулевого символа
	DumpValueType_StringA   = 0x04,
	
	// Список. 
	// В значении имеет 4 байтное целое с кол-вом элементов списка.
	DumpValueType_List      = 0xF0
};


// Структуры форматированного вывода и ввода.
// Именно здесь отделяются слои форматированного и голого вывода.
typedef struct {
	WriteStream* Stream;
} Writer;

typedef struct {
	ReadStream* Stream;
} Reader;


// Инициализация форматированного вывода.
// При необходимости можно ставить watermark начала нового потока или
// другие действия.
void InitReader(Reader* NtlvReader, ReadStream* Stream);
void InitWriter(OUT Writer* NtlvWriter, IN WriteStream* Stream);


// Функции форматированного вывода в поток.
void WriteUint32(Writer* NtlvWriter, const char* Name, DWORD Value);

void WriteStringW(Writer* NtlvWriter, const char* Name, const WCHAR* Value);

void WriteStringW(Writer* NtlvWriter, const char* Name, const WCHAR* Value,
	DWORD ValueCharLength);

void WriteStringA(Writer* NtlvWriter, const char* Name, const char* Value);

void WriteStringA(Writer* NtlvWriter, const char* Name, const char* Value,
	DWORD ValueCharLength);

void WriteByteArray(Writer* NtlvWriter,const char* Name,const void* Value,
	DWORD ValueLength);

void WriteList(Writer* NtlvWriter,const char* ListName,DWORD ListElementCount);


// Функция чтения дампа с обратным вызовом.
// Это позволяет переложить на пользователя то, что он хочет делать с
// полученными структурами NTLV - просто вывести на экран или сохранить
typedef void (*ReadCallbackFunction)(void* ctx,BYTE Type,const char* Name,
	const void* Value,DWORD ValueLength);

void BulkReadWithCallback(Reader* NtlvReader, ReadCallbackFunction Callback,void* ctx);

}

// Инициализатор файлового потока I/O
bool File_InitDumpWriteStream(DUMP::WriteStream* stream,const WCHAR* file_path);

#endif //#ifndef UUID_6140C07EBBDC4FC18600498BA2A18935