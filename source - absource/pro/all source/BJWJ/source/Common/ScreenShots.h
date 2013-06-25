//---------------------------------------------------------------------------

#ifndef ScreenShotsH
#define ScreenShotsH
//---------------------------------------------------------------------------

#include <windows.h>

//****************************************************************************
// ScreenShot - Методы создания скриншотов
//****************************************************************************

#define COLOR_RED  RGB(255,0,0)
#define COLOR_BLUE RGB(0,0,255)

typedef struct TDrawCursorInfo
{
	DWORD Mode;        // Зарезервировано
	int X;             // Позиция курсора X
	int Y;             // Позиция курсора Y
	DWORD PointWidth;  // Размер точки
	DWORD Color;       // Цвет точки
} *PDrawCursorInfo;

namespace ScreenShot
{
	//------------------------------------------------------
	//  Make - Создать скриншот и записать его в файл.
	//         Снимки сохраняются в формате PNG
	//
	//    Wnd - Окно с которого необходимо сделать
	//			скриншот. NULL если необходим скрин экрана
	//
	//    X, Y, Width, Height - координаты и размер снимка
	//          Если указать отрицательные координаты, то
	//          будет захвачена область за пределами окна
	//
	//    DrawCursor - Информация для отрисовки курсора мыши
	//
	//    FileName - Имя файла куда будет записан снимок
	//------------------------------------------------------
	bool Make(HWND Wnd, int X, int Y, DWORD Width, DWORD Height,
			  PDrawCursorInfo DrawCursor, PWCHAR FileName);

	bool Make(HWND Wnd, int X, int Y, DWORD Width, DWORD Height,
			  PDrawCursorInfo DrawCursor, PCHAR FileName);

	//------------------------------------------------------
	//  CaptureScreen - Функция делает скриншот экрана
	//------------------------------------------------------
	bool CaptureScreenA(PCHAR  FileName);
	bool CaptureScreenW(PWCHAR FileName);

	//------------------------------------------------------
	//  MakeToMem - Функция делает снимок экрана и помещает
	//				его в память
	//
	//  Параметры аналогичны функции Make
	//
	//  OutData - Функция выделит память под снимок и вернёт
	//			  указатель на неё в эту переменную
	//
	//  OutDataSize - Размер выделенной памяти
    //
    //------------------------------------------------------

	bool MakeToMem(HWND Wnd, int X, int Y, DWORD Width, DWORD Height,
		PDrawCursorInfo DrawCursor, LPBYTE &OutData, DWORD &OutDataSize);

	//скриншот скрытого окна
	bool DrawWindow( HWND Wnd, PWCHAR FileName );
	bool DrawWindow( HWND Wnd, LPBYTE &OutData, DWORD &OutDataSize );

	bool DrawWindow2( HWND Wnd, PWCHAR FileName );
	bool DrawWindow2( HWND Wnd, LPBYTE &OutData, DWORD &OutDataSize );
};



//---------------------------------------------------------------------------
#endif
