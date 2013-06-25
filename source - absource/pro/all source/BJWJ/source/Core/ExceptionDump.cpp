#include "windows.h"

#include "windows.h"
#include "memory.h"
#include "Strings.h"
#include "inject.h"
#include "ExceptionDump.h"

namespace DUMP {

// Заглушки для форматированного выхода из ф-ции
// В оригинале они должны выдавать отладочный вывод причину (expression)
// выхода из ф-ции, файл и строку, в которой это произошло.
// Тут просто выполняют выход по условию и возврат значения при
// необходимости.

// Выход, если выполняется условие expression
#ifndef PP_RETURNIF1
#define PP_RETURNIF1(expression)                                  \
        { if (expression) {                                       \
            return;                                               \
        }};
#endif

// Выход, если выполняется условие expression и возврат значения
// return_exp
#ifndef PP_RETURNIF2
#define PP_RETURNIF2(expression, return_exp)                        \
        { if (expression) {                                         \
            return (return_exp);                                    \
        }};
#endif


// Ф-ции инициализации форматированного потока.
void InitWriter(OUT Writer* NtlvWriter,IN WriteStream* Stream)
{
	NtlvWriter->Stream = Stream;
}

void InitReader(OUT Reader* NtlvReader, ReadStream* Stream)
{
	NtlvReader->Stream = Stream;
}

// Внутренняя ф-ция форматированного вывода.
// Именно здесь происходит запись структуры.
void NtlvWrite(Writer* NtlvWriter, DumpValueType Type, const char* Name,
	const void* Value, DWORD ValueLength)
{
	WriteStream * Stream = NtlvWriter->Stream;

	DWORD written;
	BYTE  Signature[] = "FEAD";
	BYTE  NameLength = (BYTE)m_lstrlen(Name);
	BYTE  ByteType = (BYTE)Type;

	PP_RETURNIF1(!Stream->Write(Stream, Signature, 4, &written));
	PP_RETURNIF1(!Stream->Write(Stream, &ByteType, 1, &written));
	PP_RETURNIF1(!Stream->Write(Stream, &NameLength, 1, &written));
	PP_RETURNIF1(!Stream->Write(Stream, &ValueLength, 4, &written));

	PP_RETURNIF1(!Stream->Write(Stream, Name, NameLength, &written));
	PP_RETURNIF1(!Stream->Write(Stream, Value, ValueLength, &written));
}


// Структуры NTLV читаются из потока, проводятся базовые проверки и 
// прочитанные данные передаются в callback
void BulkReadWithCallback(Reader* NtlvReader, ReadCallbackFunction callback,
	void* ctx)
{
	DWORD NameBufferLength = 2 * 0xFF;
	DWORD ValueBufferLength = 2 * 4096;

	char * NameBuffer = (char *)HEAP::Alloc(NameBufferLength);
	BYTE*  ValueBuffer = (BYTE*)HEAP::Alloc(ValueBufferLength);

	ReadStream * Stream =	NtlvReader->Stream;

	while (true)
	{
		BYTE  Sig[4];
		DWORD ReadSizeSignature = 0;

		BYTE  Type = 0;
		DWORD ReadSizeType = 0;

		BYTE  NameLength = 0;
		DWORD ReadSizeNameLength = 0;

		DWORD ValueLength = 0;
		DWORD ReadSizeValueLength = 0;

		DWORD ReadSizeName = 0;
		DWORD ReadSizeValue = 0;

		m_memset(NameBuffer, 0, NameBufferLength);
		m_memset(ValueBuffer, 0, ValueBufferLength);
		
		Stream->Read(Stream, &Sig[0], 4, &ReadSizeSignature);
		PP_RETURNIF1(ReadSizeSignature != 4);
		PP_RETURNIF1(m_memcmp(Sig, "FEAD",4) != 0);

		Stream->Read(Stream, &Type, 1, &ReadSizeType);
		PP_RETURNIF1(ReadSizeType != 1);
		
		Stream->Read(Stream, &NameLength, 1, &ReadSizeNameLength);
		PP_RETURNIF1(ReadSizeNameLength != 1);

		Stream->Read(Stream, &ValueLength, 4, &ReadSizeValueLength);
		PP_RETURNIF1(ReadSizeNameLength != 1);

		Stream->Read(Stream, &NameBuffer[0], NameLength, &ReadSizeName);
		PP_RETURNIF1(ReadSizeName != NameLength);

		PP_RETURNIF1(ValueLength > ValueBufferLength);

		Stream->Read(Stream, &ValueBuffer[0], ValueLength, &ReadSizeValue);
		PP_RETURNIF1(ReadSizeValue != ValueLength);

		callback(ctx, Type, NameBuffer, ValueBuffer, ValueLength);
	}
}

void WriteUint32(Writer* NtlvWriter, const char* Name,DWORD Value)
{
	NtlvWrite(NtlvWriter, DumpValueType_Uint32, Name, &Value, 4);
}

void WriteStringW(Writer* NtlvWriter, const char* Name, const WCHAR* Value)
{
	DWORD ValueLength = m_wcslen(Value) * sizeof(WCHAR);
	NtlvWrite(NtlvWriter, DumpValueType_StringW, Name, Value, ValueLength);
}

void WriteStringW(Writer* NtlvWriter,const char* Name,const WCHAR* Value,
	DWORD ValueCharLength)
{
	DWORD ValueLength = ValueCharLength * sizeof(WCHAR);
	NtlvWrite(NtlvWriter, DumpValueType_StringW, Name, Value, ValueLength);
}

void WriteStringA(Writer* NtlvWriter,const char* Name, const char* Value)
{
	DWORD ValueLength = m_lstrlen(Value);
	NtlvWrite(NtlvWriter, DumpValueType_StringA, Name, Value, ValueLength);
}

void WriteStringA(Writer* NtlvWriter,const char* Name,const char* Value,
	DWORD ValueCharLength)
{
	DWORD ValueLength = ValueCharLength;
	NtlvWrite(NtlvWriter, DumpValueType_StringA, Name, Value, ValueLength);
}

void WriteByteArray(Writer* NtlvWriter,const char* Name,const void* Value,
	DWORD ValueLength)
{
	NtlvWrite(NtlvWriter, DumpValueType_ByteArray, Name, Value, ValueLength);
}

void WriteList(Writer* NtlvWriter, const char* Name, DWORD ListElementCount)
{
	NtlvWrite(NtlvWriter, DumpValueType_List, Name, &ListElementCount, 4);
}

}

// Реализация файлового потока вывода.
struct FileStreamCtx
{
	HANDLE file;
};

bool File_DumpWriteStreamWrite(DUMP::WriteStream* stream,
	const void* Data, DWORD DataLength, DWORD* Written)
{
	FileStreamCtx* file_ctx = (FileStreamCtx*)stream->stream_ctx;
	return (TRUE == (BOOL)pWriteFile(file_ctx->file, Data, DataLength, Written, NULL));
}

void File_DumpWriteStreamFinish(DUMP::WriteStream* stream)
{
	FileStreamCtx* file_ctx = (FileStreamCtx*)stream->stream_ctx;
	pCloseHandle(file_ctx->file);
	HEAP::Free(file_ctx);
}

// Инициатор потока (конструктор)
// Такой себе ООП на С.
// Настраивает ф-ции на свои и создает контекст для себя.
bool File_InitDumpWriteStream(DUMP::WriteStream* stream,const WCHAR* file_path)
{
	stream->stream_ctx = NULL;

	FileStreamCtx* file_ctx = (FileStreamCtx*)HEAP::Alloc(sizeof(FileStreamCtx));
	PP_RETURNIF2(file_ctx == NULL, false);
	
	HANDLE h = pCreateFileW(file_path, GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, 0, NULL);
	PP_RETURNIF2(h == INVALID_HANDLE_VALUE, false);

	file_ctx->file = h;
	stream->stream_ctx = file_ctx;
	stream->Write = File_DumpWriteStreamWrite;
	stream->Finish = File_DumpWriteStreamFinish;

	return true;
}
