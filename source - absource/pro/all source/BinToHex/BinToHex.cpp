#include <stdio.h>


int main( int argc, char* argv[] )
{
 FILE* fin = fopen( argv[1], "rb" );
 if( argc < 3 ) {
   printf( "BinToHex.exe 'in file' 'out file' 'name array' 'add head _DLL_DATA_ (0 or 1)' " );
   return 0;
 }
 if( fin == 0 ) {
   printf( "not open file %s", argv[1] );
   return 0;
 }
 FILE* fout = fopen( argv[2], "w" );
 if( fout == 0 ) {
   printf( "not create file %s", argv[2] );
   return 0;
 }
 const char* nameVar = "data";
 if( argc > 3 )
   nameVar = argv[3];
 bool addHead = false;
 if( argc > 4 )
   if( argv[4][0] == '1' ) addHead = true;

 int c;
 fprintf( fout, "unsigned char %s[] =\n{", nameVar );
 if( addHead ) {
   const char* head = "_DLL_DATA_";
   int i = 0;
   fprintf( fout, "\n\t", fout );
   while( head[i] ) {
     fprintf( fout, "0x%02x, ", head[i] );
     i++;
   }
   fprintf( fout, "// _DLL_DATA_" );
   fseek( fin, 0, SEEK_END );  
   int size = ftell(fin);  
   fseek( fin, 0, SEEK_SET );
   fprintf( fout, "\n\t", fout );
   for( int i = 0; i < 4; i++ )
     fprintf( fout, "0x%02x, ", ((char*)&size)[i] );
   fprintf( fout, "// размер данных" );
 }
 int n = 0;
 while( (c = fgetc(fin)) >= 0 ) {
   if( n > 0 )
     fprintf( fout, ", " );
   if( (n % 16) == 0 ) {
     fprintf( fout, "\n\t" );
   }
   fprintf( fout, "0x%02x", c );
   n++;
 }
 fprintf( fout, "\n};\n" );
}
