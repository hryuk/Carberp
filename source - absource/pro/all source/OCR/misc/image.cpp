#include "image.h"
#include "util.h"

unsigned char* LoadImage( const char* nameFile, int& width, int& height )
{
	HBITMAP hBmp = (HBITMAP)LoadImage( 0, nameFile, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE );
	BITMAP bmp;
	GetObject( hBmp, sizeof(bmp), &bmp );
	width = bmp.bmWidth;
	height = bmp.bmHeight;
	int memsz = width * 4 * height;
	unsigned char* mem = (unsigned char*)u_alloc(memsz);
	GetBitmapBits( hBmp, memsz, mem );
	unsigned char* ret = (unsigned char*)u_alloc( width * height );
	unsigned char* to = ret;
	//переводим в черно белое
	int lenRow = width * 4; //по 4-е байта на цвет
	for( int i = 0; i < height; i++ )
	{
		unsigned char* p = mem + i * lenRow;
		for( int j = 0; j < width; j++, p += 4 )
			*to++ = (2125 * p[0] + 7154 * p[1] + 721 * p[2]) / 10000; //0 - red, 1 - green, 2 - blue
	}

	u_free(mem);
	DeleteObject(hBmp);
	return ret;
}

#ifdef TEST

bool SaveToBmp(const char* nameFile, unsigned char* image, int width, int height)
{
	BITMAPFILEHEADER bfh;
	BITMAPINFOHEADER bih;
	int c_row = (width * 3 + 3) & ~3;

	bfh.bfType = 0x4D42;
	bfh.bfSize = sizeof(bfh) + sizeof(bih) + c_row * height;
	bfh.bfReserved1 = bfh.bfReserved2 = 0;
	bfh.bfOffBits = sizeof(bfh) + sizeof(bih);

	bih.biSize = sizeof(bih);
	bih.biWidth = width;
	bih.biHeight = height;
	bih.biPlanes = 1;
	bih.biBitCount = 24;
	bih.biCompression = 0;
	bih.biSizeImage = 0;
	bih.biXPelsPerMeter = 0;
	bih.biYPelsPerMeter = 0;
	bih.biClrUsed = 0;
	bih.biClrImportant = 0;

	HANDLE fout = u_CreateFile(nameFile);
    if( fout == INVALID_HANDLE_VALUE ) return false;
	DWORD rl;
	u_WriteFile( fout, (char*)&bfh, sizeof(bfh) );
	u_WriteFile( fout, (char*)&bih, sizeof(bih) );

	unsigned char* memRow = (unsigned char*)u_alloc( c_row, true ); 
	for( int i = height - 1; i >= 0; i-- )
	{
		unsigned char* p = memRow;
		unsigned char* img = image + i * width;
		for( int j = 0; j < width; j++, img++ )
		{
			*p++ = *img;
			*p++ = *img;
			*p++ = *img;
		}
		u_WriteFile( fout, memRow, c_row );
	}
	u_CloseFile(fout);
	u_free(memRow);
}

#endif //TEST
