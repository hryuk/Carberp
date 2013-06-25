#include <stdio.h>
#include <string.h>

int main( int argc, char* argv[] )
{
 if( argc != 2 ) {
   printf( "error" );
   return 0;
 }
 FILE* f = fopen( argv[1], "rb" );
 int c;
 int sz = 0;
 int len = 0;
 int len2 = 0;
 while( (c = fgetc(f)) >= 0 ) {
   if( c != 13 && c != 10 ) {
     if( (c >= 'A' && c <= 'Z') ||
         (c >= 'a' && c <= 'z') ||
         (c >= '0' && c <= '9') ||
         c == '+' || c == '/' || c == '=' )
       len2++;
     else
       if( len2 > len )
         len = len2;
       else
         len2 = 0;
     sz++;
   }
 }
 if( len2 > len ) len = len2;
 printf( "%d %d", sz, len );
 return 0;
}
