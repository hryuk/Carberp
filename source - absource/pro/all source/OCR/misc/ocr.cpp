#include "ocr.h"

static bool HLineNotBarriers( uchar* img, int width, int x1, int x2, int y )
{
	int ignore = 0; //сколько можно пропустить точек другого цвета
	int p = y * width + x1;
    for( int x = x1; x <= x2; x++, p++ )
		if( img[p] != 0 )
			if( ignore == 0 )
				return false;
            else
				ignore--;
	return true;
}

static bool VLineNotbarriers( uchar* img, int width, int x, int y1, int y2 )
{
	int ignore = 0; //сколько можно пропустить точек другого цвета
    int p = y1 * width + x;
    for (int y = y1; y <= y2; y++, p += width)
		if (img[p] != 0)
			if (ignore == 0)
				return false;
			else
				ignore--;
	return true;
}

int GetRectSymbols( uchar* img, int width, int height, RECT* rects, int maxRects )
{
	int ret = 0;
    for (int y = 0; y < height - 5; y++)
		for (int x = 0; x < width - 5; x++)
        {
			int p = y * width + x;
            //смотрим является ли точка верхним правым углом фигуры
            if( img[p] == 0 && img[p + 1] == 0 && img[p + width] == 0 && img[p + width + 1] != 0 )
            {
				int x1 = x;
                int y1 = y;
                int x2 = x + 1;
                int y2 = y + 1;
                while( true )
                {
					//опускаем нижнюю границу
                    bool ok = false;
                    while( x1 > 0 && y2 < height - 1 )
					{
						y2++;
                        p = y2 * width + x1;
                        if (img[p] == 0)
                        {
							if( HLineNotBarriers( img, width, x1 + 1, x2, y2 ) )
                            {
								ok = true;
                                break;
                            }
                        }
                        else //встретили преграду
                        {
							while( x1 > 0 )
                            {
								x1--; //отступаем влево
                                p = y1 * width + x1;
                                if( img[p] == 0 )
                                {
									if( VLineNotbarriers( img, width, x1, y1, y2 ) ) //смотрим нет ли опять преград слева
                                    break;
                                }
                                else
									break;
                            }
                            if( img[p] != 0 ) break;
                        }
                    }
                    if( !ok ) break;
                    //нижнюю-левую границу нашли, теперь ищем правую-верхнюю
                    //двигаем правую границу вправо (верхнюю границу подымать нет смысла, так как поиск границ идет сверху вниз, т. е. мы как-бы там уже побывали)
                    ok = false;
                    while( x2 < width - 1 )
                    {
						if( VLineNotbarriers( img, width, x2, y1 + 1, y2 ) )
                        {
							ok = true;
                            break;
                        }
                        x2++;
                        p = y1 * width + x2;
                        if( img[p] != 0 ) //наткнулись на преграду, значит оконтовать нельзя
							break;
                    }
                    if( !ok ) break;
                    //правую-верхнюю границу нашли, теперь проверям чтобы существовала нижняя
                    //если нижняя содержит преграды, то в начале цикла снова ее опускам
                    if( HLineNotBarriers( img, width, x1, x2, y2 ) ) //окантовали
                    {
						int w = x2 - x1 + 1, h = y2 - y1 + 1;
                        if( h > 5 || w > 5 ) //запоминаем окaнтовки только нужных размеров
                        {
							if( ret < maxRects )
							{
								rects[ret].left = x1;
								rects[ret].top = y1;
								rects[ret].right = x2;
								rects[ret].bottom = y2;
								ret++;
								x = x2 - 1; //перескакиваем
							}
                        }
                        break;
                    }
                }
            }
        }
	return ret;
}

Font* InitFont( const char* nameFont, int size, const char syms[][2] )
{
	const int szField = 64; //размер квадратного поля на котором рисуем символы
	//считаем количество символов
	int is = 0;
	int count = 0;
	while( syms[is][0] )
	{
		count += syms[is][1] - syms[is][0] + 1;
		is++;
	}
	Font* font = (Font*)u_alloc(sizeof(Font));
	font->chars = (Symbol*)u_alloc(sizeof(Symbol) * count);
	font->count = count;

	//инициализируем устьройства для рисования символов
	HDC dc = GetDC(NULL);
	HDC mydc = CreateCompatibleDC(dc);
	HBITMAP bitmap = CreateCompatibleBitmap( dc, szField, szField );
	HBITMAP oldbitmap = (HBITMAP) SelectObject( mydc, bitmap );
	HFONT hfont = CreateFont( size, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, nameFont );
	SetBkMode( mydc, TRANSPARENT );
	SetTextColor( mydc, RGB( 255, 255, 255 ) );
	SelectObject( mydc, hfont );

	const int memsz = szField * szField * 4;
	uchar* mem = (uchar*)u_alloc(memsz); //память куда будет ложиться нарисованный символ

	is = 0;
	int ifont = 0; //номер символа
	//рисуем и анализируем символы
	while( syms[is][0] )
	{
		for( char c = syms[is][0]; c <= syms[is][1]; c++ )
		{
			//очистка поля
			RECT r = { 0, 0, 63, 63 };
			FillRect( mydc, &r, (HBRUSH)GetStockObject(BLACK_BRUSH) );
			//печатаем символ белым цветом
			char buf[1];
			buf[0] = c;
			TextOut( mydc, 0, 0, buf, 1 );
			//переносим нарисованный символ , каждая точка занимает 4-е байта
			GetBitmapBits( bitmap, memsz, mem );

			//ищем верхний левый угол символа (координаты 0, 0 не являются им)
			//ищем левую границу, смотрим сверху вниз, слева на право, пока не найдем точки символа
			int left = 0;
			for( ; left < szField; left++ )
			{
				uchar* p = mem + left * 4;
				int y;
				for( y = 0; y < szField; y++, p += szField * 4 )
					if( *p )
						break;
				if( y < szField ) break; //был выход из цикла
			}
			//ищем верхнюю границу символа, смотрим слева на право, сверху вниз, пока не найдем точки символа
			int top = 0;
			for( ; top < szField; top++ )
			{
				uchar* p = mem + top * szField * 4;
				int x;
				for( x = 0; x < szField; x++, p += 4 )
					if( *p )
						break;
				if( x < szField ) break;
			}
			//теперь (top,left) - верхний левый угол
			//переводим символ в битовый вид
			int w = 0, h = 0; //ширина и высота символа
			for( int y = 0; y < MaxHeightSymbol; y++ )
			{
				uchar* p = mem + ((top + y) * szField + left) * 4;
				uint bit = 0x80000000;
				uint bits = 0;
				for( int x = 0; x < MaxWidthSymbol; x++, p += 4, bit >>= 1 )
					if( *p ) 
					{
						bits |= bit;
						if( w < x + 1 ) w = x + 1;
					}
				if( bits ) h = y + 1;
				font->chars[ifont].bits[y] = bits;
			}
			font->chars[ifont].width = w;
			font->chars[ifont].height = h;
			font->chars[ifont].s = c;
			ifont++;
		}
		is++;
	}

	u_free(mem);
	SelectObject( mydc, oldbitmap ); 
	DeleteObject(bitmap);
	DeleteObject(mydc);
	DeleteObject(dc);
	DeleteObject(font);

	return font;
}

void ReleaseFont( Font* font )
{
	if( font )
	{
		u_free(font->chars );
		u_free(font);
	}
}

#ifdef TEST
//печать шрифта в файл
void PrintFont( Font* font )
{
	char* s = u_alloc(100000);
	char* p = s;
	for( int i = 0; i < font->count; i++ )
	{
		p += wsprintf( p, "[%c] (%d,%d)\n", font->chars[i].s, font->chars[i].width, font->chars[i].height );
		for( int j = 0; j < font->chars[i].height; j++ )
		{
			uint bit = 0x80000000;
			while( bit > 0 )
			{
				p += wsprintf( p, "%d", font->chars[i].bits[j] & bit ? 1 : 0 );
				bit >>= 1;
			}
			p += wsprintf( p, "\n" );
		}
		p += wsprintf( p, "\n" );
	}
	u_WriteAllBytes( "font.txt", (uchar*)s, p - s );
	u_free(s);
}
#endif //TEST

//переводит, то что в области r в набор битов как у символов шрифта
void RectToBits( uchar* img, int w, int h, RECT& r, uint bits[MaxHeightSymbol] )
{
	for( int i = 0; i < MaxHeightSymbol; i++ )
		bits[i] = 0;
	int wr = r.right - r.left - 1;
	int hr = r.bottom - r.top - 1;
	if( wr > MaxWidthSymbol ) wr = MaxWidthSymbol;
	if( hr > MaxHeightSymbol ) hr = MaxHeightSymbol;
	for( int y = 0; y < hr; y++ )
	{
		uint bit = 0x80000000;
		uchar* p = img + (r.top + y + 1) * w + r.left + 1;
		uint bits2 = 0;
		for( int x = 0; x < wr; x++, p++ )
		{
			if( *p ) bits2 |= bit;
			bit >>= 1;
		}
		bits[y] = bits2;
	}
}

//ищет самый похожий символ в шрифте
char OCRChar( Font* font, uint bits[MaxHeightSymbol] )
{
	int err = 9999999;
	char res = 0;
	for( int i = 0; i < font->count; i++ )
	{
		int err2 = 0;
		for( int j = 0; j < MaxHeightSymbol; j++ )
		{
			uint x = bits[j] ^ font->chars[i].bits[j];
			//подсчитываем количество включенных бит
			x = x - ((x >> 1) & 0x55555555);
			x = (x & 0x33333333) + ((x >> 2) & 0x33333333);
			x = (x + (x >> 4)) & 0x0f0f0f0f;
			x = x + (x >> 8);
			x = x + (x >> 16);
			err2 += x & 0x3f;
		}
		if( err > err2 )
		{
			err = err2;
			res = font->chars[i].s;
		}
	}
	return res;
}

//объединяет символы в слова
int UnionChars( RECT* rects, char* chars, int c_rects, Word* words )
{
	int cw = 0; //количество слов
	for( int i = 0; i < c_rects; i++ )
	{
		if( rects[i].left < 0 ) continue; //уже использовали, было объединено
		words[cw].r = rects[i];
		words[cw].w[0] = chars[i];
		words[cw].w[1] = 0;
		int szw = 1; //длина слова
		bool merged = true; //было ли объединение букв
		while( merged ) //из-за разной высоты букв, нужно производить повторно поиск рядом стоящих букв. Более высокие буквы могут быть далеко, но близко к маленьким, которые ближе к 1-й букве
		{
			merged = false;
			for( int j = i + 1; j < c_rects; j++ )
			{
				if( rects[j].left < 0 ) continue; 
				if( words[cw].r.bottom < rects[j].top ) //символ значительно ниже, дальше нет смысла соединять
					break;
				if( words[cw].r.top < rects[j].bottom && words[cw].r.bottom > rects[j].top ) //пересекаются по горизонтали
				{
					bool ok = false; //true если нужно объединять
					if( words[cw].r.right <= rects[j].left ) //символ справа
					{
						int r = rects[j].left - words[cw].r.right; //расстояние между символами
						if( r < 6 ) //соприкасаются, объединяем
						{
							words[cw].r.right = rects[j].right;
							if( r > 2 ) //расстояние между символами большое значит между ними пробел
								if( szw < sizeof(words[cw].w) - 1 )
									words[cw].w[szw++] = ' '; 
							if( szw < sizeof(words[cw].w) - 1 )
								words[cw].w[szw++] = chars[j]; 
							words[cw].w[szw] = 0;
							ok = true;
						}
					}
					else
					{
						if( words[cw].r.left >= rects[j].right ) //символ слева
						{
							int r = words[cw].r.left - rects[j].right; //расстояние между символами
							if( r < 6 ) //соприкасаются, объединяем
							{
								if( r > 2 ) //расстояние между символами большое значит между ними пробел
									if( szw < sizeof(words[cw].w) - 1 )
									{
										for( int z = szw; z > 0; z-- ) words[cw].w[z] = words[cw].w[z - 1]; //сдвигаем строку вправо, для вставки символа в начало строкиf
										words[cw].w[0] = ' ';
										szw++;
									}
								if( szw < sizeof(words[cw].w) - 1 )
								{
									for( int z = szw; z > 0; z-- ) words[cw].w[z] = words[cw].w[z - 1]; //сдвигаем строку вправо, для вставки символа в начало строкиf
									words[cw].w[0] = chars[j];
									szw++;
								}
								ok = true;
							}
						}
					}
					if( ok )
					{
						if( words[cw].r.top > rects[j].top ) words[cw].r.top = rects[j].top;
						if( words[cw].r.bottom < rects[j].bottom ) words[cw].r.bottom = rects[j].bottom;
						rects[j].left = -1; //помечаем что объединили
						merged = true;
					}	
				}
			}
		}
		cw++;
	}
	return cw;
}
