// OCRIBank.cpp : Defines the exported functions for the DLL application.
//

#include "OCRIBank.h"
#include "..\misc\image.h"
#include "..\misc\ocr.h"

//определяет цвет основного текста
static int GetColor1( uchar* img, int w, int h )
{
	int c = w * h;
	int colors[256]; //количество цветов
	for( int i = 0; i < 256; i++ ) colors[i] = 0;
	//подсчитываем количество каждого цвета
	for( int i = 0; i < c; i++ )
		colors[img[i]]++;
	int th = c / 100; //нужного цвета не менее 1%
	//ищем самый первый цвет выше th
	for( int i = 0; i < 256; i++ )
		if( colors[i] > th )
			return i;
	return -1;
}

//ищем цвет + который рисуется в дереве (tree)
static int GetColor2( uchar* img, int w, int h )
{
	//ищем в левой части картинки символ +
	for( int y = 0; y < h - 10; y++ )
	{
		uchar* p = img +  y * w;
		int wx = w / 10; //сколько точек слева смотреть
		//ищем знак +
		for( int x = 1; x < wx; x++, p++ )
		{
			if( p[0] != p[-1] && p[-1] == p[1] &&
				p[w - 1] == p[-1] && p[w] == p[0] && p[w + 1] == p[-1] &&
				p[2 * w - 1] == p[0] && p[2 * w] == p[0] && p[2 * w + 1] == p[0] &&
				p[3 * w - 1] == p[-1] && p[3 * w] == p[0] && p[3 * w + 1] == p[-1] )
			{
				return p[0];
			}
		}
	}
	return -1;
}

//анализирует картинку и возвращает в массиве colors цвета текстовой информации
static int GetColorText( uchar* img, int w, int h, int* colors )
{
	int ret = 0;
	colors[ret] = GetColor1( img, w, h );
	if( colors[ret] >= 0 ) ret++;
	colors[ret] = GetColor2( img, w, h );
	if( colors[ret] >= 0 ) ret++;
	return ret;
}


void ParseImage( const char* nameFile )
{
	int width, height;
	const char syms[][2] = 
	{ 
		{ 'a', 'z' },
		{ 'A', 'Z' },
		{ 'а', 'я' },
		{ 'А', 'Я' },
		{ '0', '9' },
		{ '+', '+' },
		{ '-', '-' },
		{ 0, 0 }
	};
	Font* font = InitFont( "Arial", 15, syms );
	uchar* img = LoadImage( nameFile, width, height );
	//DbgMsg( "%d %d", width, height );
	//for( int i = 0; i < 256; i++ )
	//	DbgMsg( "%d - %d", i, colors[i] );
	int colors[2];
	int c_color = GetColorText( img, width, height, colors );
	//оставляем только нужные цвета
	int sz = width * height;
	for( int i = 0; i < sz; i++ )
	{
		int c = 0;
		for( int j = 0; j < c_color; j++ )
			if( img[i] == colors[j] )
			{
				c = 255;
				break;
			}
		img[i] = c;
	}
	const int maxRects = 1000;
	RECT* rects = (RECT*)u_alloc( sizeof(RECT) * maxRects );
	int c_rects = GetRectSymbols( img, width, height, rects, maxRects );

	/*
	for( int i = 0; i < c_rects; i++ )
	{
		//DbgMsg( "%d %d %d %d", rects[i].left, rects[i].top, rects[i].right, rects[i].bottom );
		int p1 = rects[i].top * width + rects[i].left;
		int p2 = rects[i].bottom * width + rects[i].left;
		for( int x = rects[i].left; x <= rects[i].right; x++, p1++, p2++ )
		{
			img[p1] = 128;
			img[p2] = 128;
		}
		p1 = rects[i].top * width + rects[i].left;
		p2 = rects[i].top * width + rects[i].right;
		for( int y = rects[i].top; y <= rects[i].bottom; y++, p1 += width, p2 += width )
		{
			img[p1] = 128;
			img[p2] = 128;
		}
	}		
	SaveToBmp( "1_1.bmp", img, width, height );
	*/
	char* chars = u_alloc(c_rects);
	for( int i = 0; i < c_rects; i++ )
	{
		uint bits[MaxHeightSymbol];
		RectToBits( img, width, height, rects[i], bits );
		chars[i] = OCRChar( font, bits );
		//DbgMsg( "[%c] %d,%d %d,%d", s, rects[i].left, rects[i].top, rects[i].right, rects[i].bottom );
	}
	//объединяем символы в слова
	Word* words = (Word*)u_alloc( sizeof(Word) * c_rects );
	int c_words = UnionChars( rects, chars, c_rects, words );
	for( int i = 0; i < c_words; i++ )
		DbgMsg( "[%s] %d,%d %d,%d", words[i].w, words[i].r.left, words[i].r.top, words[i].r.right, words[i].r.bottom );
	u_free(words);
	u_free(chars);
	u_free(rects);
	u_free(img);
	ReleaseFont(font);
}

