# include "stdafx.h"

//
// Глобальные переменные.
//

HANDLE ghThread = NULL;

//
// Печатает указанную строку и ID процесса.
//

void
PrintString (

	LPWSTR pwString)

{
	WCHAR buf [512];
	
	wsprintf (buf, L"[%u] %s\r\n",
		GetCurrentProcessId (),
		pwString);

	OutputDebugString (
		buf);
}

//
// Точка входа тестового потока.
//

DWORD
WINAPI
ThreadProc (
			
	LPVOID lpParam)
{
	PrintString (
		L"DLL thread created successfully.");

	ExitThread (
		0);
}

//
// Точка входа модуля.
// В настройках проекта C рантайм выключен.
//

BOOL
APIENTRY
DllMain (

	HMODULE hModule,
	DWORD uReason,
	LPVOID lpReserved)

{
	DWORD dwThreadId = 0;

	//
	// Проверяем сигнал.
	//

	switch (uReason)
	{
		//
		// Это единственный сигнал, который загруженная
		// таким образом DLL может поймать, другие не приходят.
		//

		case DLL_PROCESS_ATTACH:
		{
			PrintString (
				L"DLL injected successfully.");

			//
			// Проверка работоспособности:
			// создаём вспомогательный поток.
			//

			ghThread = CreateThread (
				NULL,
				0,
				ThreadProc,
				NULL,
				0,
				&dwThreadId);

			break;
		}
	}

	//
	// В данной версии буткита никакого механизма
	// выгрузки DLL не предусмотрено, поэтому всегда
	// возвращаем TRUE.
	//

	return TRUE;
}

