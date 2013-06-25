#pragma once

#include "..\misc\types.h"
#include "..\misc\util.h"
#include "..\misc\debug.h"

const int MaxWidthSymbol = 32;
const int MaxHeightSymbol = 16;

//символ
struct Symbol
{
	char s; //код символа
	int width, height;
	uint bits[MaxHeightSymbol]; //биты символов, максимальный размер символа 16x32
};

struct Font
{
	Symbol* chars; 
	int count;
};

//распознное слово
struct Word
{
	RECT r; //координаты слова
	char w[128]; //само слово не более 128 символов вместе с конечным нулем
};

int GetRectSymbols( uchar* img, int width, int height, RECT* rects, int maxRects );
Font* InitFont( const char* nameFont, int size, const char syms[][2] );
void ReleaseFont( Font* font );
void RectToBits( uchar* img, int w, int h, RECT& r, uint bits[MaxHeightSymbol] );
//ищет самый похожий символ в шрифте
char OCRChar( Font* font, uint bits[MaxHeightSymbol] );
//объединяет символы в слова
int UnionChars( RECT* rects, char* chars, int c_rects, Word* words );
