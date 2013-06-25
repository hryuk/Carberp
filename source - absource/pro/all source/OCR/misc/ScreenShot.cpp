#include "util.h"
#include "image.h"
#include "ScreenShot.h"

HWND FindWindowForScreenshot(const char* caption)
{
	HWND desk = GetDesktopWindow();
	HWND first = GetWindow( desk, GW_CHILD	 );
	HWND wnd = first;
	char buf[256];
	bool find = false;
	do 
	{
		GetWindowText( wnd, buf, sizeof(buf) );
		if( u_strstr( buf, caption ) ) 
		{
			find = true;
			break;
		}
		wnd = GetWindow( wnd, GW_HWNDNEXT );
	} while( wnd != 0 && wnd != first );
	if( find )
	{
		for(;;)
		{
			HWND parent = GetParent(wnd);
			if( parent == 0 ) break;
			wnd = parent;
		}
		return wnd;
	}
	return 0;
}


ScreenShot* MakeScreenShot(HWND hWnd)
{
	HDC dc = GetWindowDC(hWnd);
    HDC mydc = CreateCompatibleDC(dc);
    RECT r;
    GetWindowRect( hWnd, &r );
    int w = r.right - r.left + 1;
    int h = r.bottom - r.top + 1;
    HBITMAP bitmap = CreateCompatibleBitmap( dc, w, h );
    HBITMAP oldbitmap = (HBITMAP) SelectObject( mydc, bitmap );
    BitBlt( mydc, 0, 0, w, h, dc, 0, 0, SRCCOPY );

    BITMAPINFO info;
    info.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
    info.bmiHeader.biBitCount = 0;
    GetDIBits( mydc, bitmap, 0, 0, 0, &info, DIB_RGB_COLORS );
    info.bmiHeader.biCompression = BI_RGB;
    info.bmiHeader.biBitCount = 24;
    int memsz = (info.bmiHeader.biWidth * 3 + 3) * info.bmiHeader.biHeight;
    unsigned char* mem = (unsigned char*)u_alloc(memsz);
    GetDIBits( mydc, bitmap, 0, info.bmiHeader.biHeight, mem, &info, DIB_RGB_COLORS );
	ScreenShot* ret = (ScreenShot*) u_alloc( info.bmiHeader.biWidth * info.bmiHeader.biHeight + sizeof(ScreenShot) );
	ret->width = info.bmiHeader.biWidth;
	ret->height = info.bmiHeader.biHeight;
	ret->bits = 8;
	unsigned char* to = ret->image;
	//переводим в черно белое
	int lenRow = (ret->width * 3 + 3) & ~3; //количество байт должно быть кратно 4
	for( int i = ret->height - 1; i >= 0; i-- )
	{
		unsigned char* p = mem + i * lenRow;
		for( int j = 0; j < ret->width; j++, p += 3 )
			*to++ = (2125 * p[0] + 7154 * p[1] + 721 * p[2]) / 10000; //0 - red, 1 - green, 2 - blue
	}

	SelectObject( mydc, oldbitmap );
	DeleteObject(bitmap);
	DeleteDC(mydc);
	DeleteDC(dc);
	u_free(mem);

	return ret;	
}

#ifdef TEST

bool SaveToBmp(const char* nameFile, ScreenShot* ss)
{
	SaveToBmp( nameFile, ss->image, ss->width, ss->height );
}

#endif //TEST


