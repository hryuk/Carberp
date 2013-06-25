#pragma once

unsigned char* LoadImage( const char* nameFile, int& width, int& height );
bool SaveToBmp(const char* nameFile, unsigned char* image, int width, int height);

