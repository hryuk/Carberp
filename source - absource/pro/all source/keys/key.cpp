#include <stdio.h>
#include <string.h>

int main( int argc, char* argv[] )
{
 if( argc != 2 ) {
   printf( "error" );
   return 0;
 }
 int s[256];
 double fs[256];
 memset( s, 0, sizeof(s) );
 memset( fs, 0, sizeof(fs) );
 FILE* f = fopen( argv[1], "rb" );
 int c;
 int sz = 0;
 while( (c = fgetc(f)) >= 0 ) s[c]++, sz++;
 fclose(f);
 double sum = 0.0;
 int avg = sz / 256;
 int min = avg - avg / 2 - 1; if( min <= 0 ) min = 1;
 int max = avg + avg / 2 + 1;
 int m1 = 0, m2 = 0;
 for( int i = 0; i < 256; i++ ) {
   fs[i] = double(s[i]) / sz;
   printf( "%02x - %d\n", i, s[i], fs[i] );
   if( min <= s[i] && s[i] <= max ) 
     m1++;
   else
     m2++;
 }
 printf( "m1 = %d, m2 = %d\n", m1, m2 );
 return 0;
}
