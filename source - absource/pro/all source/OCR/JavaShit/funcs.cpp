#include "funcs.h"
#include "../java/javashit.h"

void SendKeys( const char* nameWindow, const char* chars )
{
	DbgMsg( "Name Window: %s, String: %s", nameWindow, chars );
	HWND wnd = FindWindow( 0, nameWindow );
	if( wnd )
	{
		DbgMsg( "Window %s founded", nameWindow );
		SendString( wnd, (TCHAR*)chars );
	}
}

