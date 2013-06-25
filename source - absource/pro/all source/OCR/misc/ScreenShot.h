#pragma once

struct ScreenShot
{
	int width;
	int height;
	int bits; //сколько бит на одну точку
	unsigned char image[];
};

HWND FindWindowForScreenshot(const char* caption);
ScreenShot* MakeScreenShot(HWND hWnd);
bool SaveToBmp(const char* nameFile, ScreenShot* ss);
void LowerBits(ScreenShot* ss, int bits);
void UpperBits(ScreenShot* ss);
void CalcDiffFrame( ScreenShot* last, ScreenShot* curr, ScreenShot* diff );
int RLEFrameColor2Bits( unsigned char* in, int c_in, unsigned char* out, int c_out );
