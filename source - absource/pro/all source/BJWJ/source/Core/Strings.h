#include <windows.h>

#ifndef StringsH
#define StringsH
//-----------------------------------------------------------------------------

#include "Memory.h"
#include "GetApi.h"

//int WINAPI URLEncode( char *pszDestiny, char *pszSource );

int m_atoi(const char *nptr);

void   WINAPI m_lstrcat( char *szBuf, const char *szStr );
void   WINAPI m_lstrcpy( char *szBuf, const char *szStr );
void   WINAPI m_lstrlwr( char *str );


char * WINAPI m_strstr( const char * _Str, const char * _SubStr );
char * WINAPI m_strstrmask( const char * _Str, const char * _SubStr );
char * WINAPI m_strtok_s( char *String, const char *Control, char **Context );

//char * WINAPI ToAnsi( LPCWSTR String );
//char * WINAPI ToAnsiEx( LPCWSTR String, DWORD dwSize );

bool   WINAPI m_lstrncpy( char *pString_src, const char *pString_dst, DWORD len );
bool   WINAPI SearchByMask( char *mask, char *name );

int  WINAPI m_istrstr( const char * _Str, const char * _SubStr );
DWORD  WINAPI m_lstrcmp( const char *szStr1, const char *szStr2 );
int  WINAPI m_lstrncmp( const char *szstr1, const char *szstr2, int nlen );
DWORD  WINAPI m_lstrlen(const char *szPointer );

DWORD WINAPI m_wcslen(const wchar_t *String );

wchar_t *m_wcsncpy( wchar_t *dest, wchar_t *src, unsigned long n );
wchar_t *m_wcscpy( wchar_t *dest, int c_dest, wchar_t *src );
wchar_t *m_wcslwr( wchar_t *Str );
bool m_wcsncmp( WCHAR *s1, WCHAR *s2, size_t iMaxLen );
const wchar_t * WINAPI m_wcsstr( const wchar_t * _Str, const wchar_t * _SubStr );

bool WildCmp(const char *Buffer, const char *Mask, LPDWORD Start, LPDWORD End, LPDWORD Len );
bool WildCmp2(const char *Buffer, const char *Mask, LPDWORD StartPos, LPDWORD EndPos, LPDWORD SubStrLen);

bool WildCmp(const char* Buffer, const char* Mask);

bool CompareUrl(const char *MaskUrl, const char *Url );

WCHAR*   AnsiToUnicode( char *AnsiString, DWORD dwStrLen );
wchar_t* UTF8ToUnicode( const char* utf8String );
char*    UTF8ToAnsi( const char* utf8String );
//безопасное копирование строки, dst - куда копируем, szDst - размер памяти в dst, src - исходная строка
//возвращает dst
char* SafeCopyStr( char* dst, int szDst, const char* src );



//убирает в начале и конце символы c, возвращает указатель на s, только внутри уже обработанная строка
char* trimall( char* s, char c = ' ' );


// ----------------------------------------------------------------------------
//  Набор функция для работы со строками
//
//  Если использовать данные функции для работы со строками, то? в некоторых
//  случаях, можно достить большего быстродействия. Например, функция
//  StrLength многократно  превышает по быстродействию функции которые
//  просчитывают длину строки сканируя её до нулевого символа, и чем больше
//  строка тем больше разница в быстродействии
// ----------------------------------------------------------------------------


// Функция расчитывает длину строки сканируя ея в поисках завершаешего нуля
DWORD StrCalcLength(const char* Buf);
DWORD StrCalcLengthW(const wchar_t* Buf);


//  Функция StrConcat объеденяет две и более строки.
//  если размер буфера строки Str1 меньше необходимого,
//  то строка Str1 будет переопределена
//  Count определяет сколько строк будет добавлено к Str1
void StrConcat(PCHAR &Str1, PCHAR Str2);
void StrConcat(PCHAR &Str1, DWORD Count, PCHAR Str2...);

// функция копирует строку Source в строку Dest
// Флаг UpdateLen использовать только если Dest создана функциями
// StrAlloc, StrNew
// Возвращает истину если скопирован хотя-бы один байт
bool StrCopy(PCHAR Dest, PCHAR Source, bool UpdateLen = false);

// Сравнить две строки
int StrCompare(const char* Str1, const char* Str2);

// Функции дл преобразования строк в числи и наоборот
int StrToInt(PCHAR Str);
PCHAR StrLongToString(DWORD num);

// Функция приводит строку к нижнему регистру
void StrLowerCase(PCHAR Str);

// Функция ищет позицию строки в массиве строк Сmo
int StrIndexOf(PCHAR Str, bool CaseSensetive, DWORD Count, PCHAR Cmp...);

// Функция сравнивает строку Str со строкой ToSame.
// CaseSensetive определяет чувствительность к регистру
// Если StrEndPosrition не равен нулю, то сравнение
// ограничивается StrEndPosrition символами
bool StrSame(PCHAR Str, PCHAR ToSame, bool CaseSensetive = true, DWORD StrEndPosition = 0);

// Функция возвращает текст находящиийся  между текстом Before и After
// после обработки указатель Buffer  будет указывать на конец текста After
// результат уничтожить функцией StrFree
PCHAR GetTextBetween(PCHAR &Buffer, PCHAR Before, PCHAR After );

//----------------------------------------------------------------------------
//  STR - Методы для работы со строками
//----------------------------------------------------------------------------
namespace STR
{
	// Создаёт в памяти пустую строку выделяя под неё буфер размером StrLen + 1
	PCHAR Alloc(DWORD StrLen);

	// Функция создаёт строку, копию Source.
	// Len - Количество копируемых символов
	//       если равно 0, то будет скопирована вся строка
	PCHAR New(PCHAR Source, DWORD Len = 0);

	// Функция создаёт строку объеденив несколько строк
	PCHAR New(DWORD Count, PCHAR Str...);

	// Уничтожить строку.
	// Важно!!! Строка должна быть создана с помощью функции StrNew
	void Free(PCHAR Str);
	void Free2(PCHAR &Str);

	// Функция возвращает длину строки.
	DWORD Length(PCHAR Str);

	// Обновляет значение длины строки в её заголовоке.
	// !!!!Только для строк созданных через STR::Alloc (STR::New)
	// Если значение RealLength не указано то новая длина
	// расчитывается до нулевого символа
	void UpdateLength(PCHAR Str, DWORD RealLength = 0);

	// Находит позицию строки SubStr  в строке Str
	// Если значение StrLen то поиск будет вестись до
	// нулевого символа
	int Pos(const char* Str, const char* SubStr, DWORD StrLen = 0, bool CaseSensetive = true);

	// Копирует с позиции Position строки Source Count символов в
	// строку Destination
    void Copy(PCHAR Source, PCHAR Destination, DWORD Position, DWORD Count);

	// Удаляет Count символов с позоции Position строки Str
	void Delete(PCHAR Str, DWORD Position, DWORD Count, DWORD StrLength = 0);

	//  Replace - Функция заменяет в строке Str строку SrcStr на
	//  строку DstStr.
	//  В случае успеха функция возвращает новую строку
	PCHAR Replace(PCHAR Str, PCHAR SrcStr, PCHAR DstStr, DWORD StrLen = 0);


	// Функция возвращает указатель на символ С
	PCHAR Scan(const char* Str, char C);

	// Функция возвращает указатель на последний символ С
	PCHAR ScanEnd(PCHAR Str, char C);

	// Функции возвращают текст слева, справа соответственно
	// относительно строки SubStr
	PCHAR GetLeftStr(PCHAR Str, PCHAR SubStr, bool IncludeSubStr = false);
	PCHAR GetRightStr(PCHAR Str, PCHAR SubStr, bool IncludeSubStr = false);


	// Функция игнорирует пробелы. Функция НЕ изменяет строку, она
	// возвращает указатель на нужный символ, либо на конец строки
	PCHAR IgnoreSpaces( const PCHAR Str );

	// Возвращает указатель на конец строки
	PCHAR End(PCHAR Str);

	// Функция форматирует строку на основе шаблона
//	PCHAR Format(PCHAR Str, ...);
	PCHAR Format(PCHAR Str, va_list Arguments);

	// Функция возвращает текущую линию в строке.
	// Линия ограничивается символами 10, 13 либо концом строки
	// Конец строки ограничивается нулевым символом либо размером ЫекЫшяу
	PCHAR GetLine(PCHAR Str, DWORD StrSize = 0);

	// Функция возвращает указатель на первый символ следующей линии в строке
	// либо на конец строки
	PCHAR GotoNextLine(PCHAR Str, DWORD StrSize = 0);

    // Функция преобразовывает шестнадцатиричное число в десятиричное
	DWORD HexToDWORD(PCHAR Str);
	//преобрзовывает строку в неотрицательное число
	DWORD ToDWORD( const char* s );


	// Функция возвращает истину если на входе нулевой указатель либо
	// пустая строка
	bool IsEmpty( const PCHAR Str);

	// Функция расчитывает хэш строки
	// Str - исходная строка
	// Len - Длина строки, если равно 0, то расчитывается до конечного нуля
	// LowerCase - приводить символы в нижний регистр перед созданием хэша
	DWORD GetHash(PCHAR Str, DWORD Len, bool LowerCase);

	// Функция расчитывает длину строки состоящей из нескольких строк
	// отделённых друг от другу нулевым символом в конце которых стоит
	// двойной нулевой символ
	// Например: str0str0str00
	DWORD CalcDoubleZeroStrLength(PCHAR Str);

	// Функция приводит символы в нижний регистр. Функция не чувствительна
	// к кодировке символов
	void AnsiLowerCase(PCHAR Str);

    // Функция возвращает истину ели строка в Линукс формате
    bool IsLinuxStr(PCHAR S);

	// Функция приводит строку к формату Linux
	PCHAR ConvertToLinuxFormat(PCHAR S);
}

namespace WSTR
{
	// Выделить память по строку длиной StrLen
	PWCHAR Alloc(DWORD StrLen);

	// Функция создаёт строку, копию Source.
	// Len - Количество копируемых символов
	//       если равно 0, то будет скопирована вся строка
    PWCHAR New(PWCHAR Source, DWORD Len = 0);

	// Освободить память выделенную под строку
	void Free(PWCHAR Str);

	// Функция расчитывает длину строки
	DWORD CalcLength(PWCHAR Str);

	// Функция возвращает истину если строка пустая
	bool IsEmpty(PWCHAR Str);

	// Расчитать длину строки
	DWORD CalcLength(PWCHAR Str);

	// Функция преобразовывает WideString в ANSI String
	PCHAR ToAnsi(LPCWSTR Str, DWORD Len);

	// Возвращает указатель на конец строки
	PWCHAR End(PWCHAR Str);

	// Функция возвращает указатель на последний символ С
	PWCHAR ScanEnd(PWCHAR Str, WCHAR C);

	// Функция расчитывает хэш строки
	// Str - исходная строка
	// Len - Длина строки, если равно 0, то расчитывается до конечного нуля
	// LowerCase - приводить символы в нижний регистр перед созданием хэша
	DWORD GetHash(const PWCHAR Str, DWORD Len, bool LowerCase);
}


#define CalcHash(Str) (STR::GetHash(Str, 0, false))
#define CalcHashA(Str) (STR::GetHash(Str, 0, false))
#define CalcHashW(Str) (WSTR::GetHash(Str, 0, false))



#define CharIsDigit(C)  ((C >= '0') && (C <= '9'))
#define LowerChar(C) if (C >= 'A' && C <= 'Z') {C = C + ('a'-'A');}


//*********************************************************************
//  Шаблонный клас с набором методов для работы со строковыми массивами
//  Для того что-бы не писать множество шаблонных функций для
//  однотипной
//
//  ВАЖНО:
//  Данные в случае если методы вносят изменения в строку они
//  расчитывабт на то, что размер буфера удовлетворяет необходимым
//  требованиям
//*********************************************************************
template <class TChar>
class STRUTILS : TBotObject
{
public:
	// Функция возвращает истину если строка пустая
	static bool  IsEmpty(const TChar* Str);

	// Функция расчитывает длину строки
	static DWORD  Length(const TChar* Str);

	// Функция ищет вхождение подстроки в строке
	static int Pos(const TChar* Str, const TChar *SubStr);

	// Функция возвращает истину если строки идентичны
	static bool Equal(const TChar* Str1, const TChar* Str2);

	// Функция сравнивает две строки
	static int Compare(const TChar* Str1, const TChar* Str2);
	static int CompareEx(const TChar* Str1, const TChar* Str2, DWORD Str1Len);

	// Функция расширяет строку Str с позиции Position на
	// Count символов
	static void Expand(const TChar *Str, DWORD Position, int Count);

	//  Функция вставляет подстроку в строку
	static void Insert(const TChar *Str, const TChar *SubStr, DWORD Position);

	// Вункция заменяет все строки SubStr в строке Str на строку NewStr
	static void Replace(const TChar *Str, const TChar *SubStr, const TChar *NewStr);

	// Функция расчитывает хэш строки
	static DWORD Hash(const TChar* Str, DWORD Len, bool LowerCase);
	static DWORD Hash(const TChar* Str);

	// Функции ищет первое вхождение символа в строке
	static TChar* Scan(const TChar *Str, TChar Char);

	// Функция вщзвращает указатель на конец строки
	static TChar* End(const TChar *Str);

	// Функция преобразует целое число в строку.
	// Функция не создаёт строки.
	// в переменой n возвращает количество символов
	// Если вызвать функцию с нулевым буфером то функция
	// расчитает необходимый размер строки
	static void LongToString(DWORD num, TChar* Str, int &n);
};


typedef STRUTILS<char> STRA, AnsiStr;
typedef STRUTILS<wchar_t> STRW, UnicodeStr;



//*********************************************************************
//  Методы для работы со специализированным буфером строк
//  при создании строки выделяется дополнительный, служебный
//  заголовок TStrRec. Заголовок находится по отрицательному
//  смещению Str - sizeof(TStrRec)
//*********************************************************************

// Объявление этого имени включает блочное выравнивание памяти строк
// Память будет выделяться кратно STRING_BLOCK_SIZE

#define USE_BLOCKS_STRINGS

// Размер блоков строки
#define STRING_BLOCK_SIZE 32


// Объявление шаблонной функции
#define STRBUFAPI(Result_Type) template<class TChar> Result_Type

namespace STRBUF
{
	// Заголовок строки
	struct TStrRec
	{
		DWORD Size;      // Размер буфера (символов)
		DWORD Length;    // Реальный размер данных
		DWORD RefCount;  // Количество ссылок
    };


	// Функция создаёт строку размером Size символов
	// длина строки устанавливается нулевой
	STRBUFAPI(TChar*) Alloc(DWORD Size);

	// Функция уменьшает счётчик ссылок и, при необходимости, уничтожает строку
	STRBUFAPI(void) Release(TChar* &Str);

	// Функция увеличивает счётчик ссылок строки и возвращает указатель на неё
	STRBUFAPI(TChar*) AddRef(TChar* Str);

	// Функция уникализирует строку
	STRBUFAPI(void) Unique(TChar* &Str);

	// Функция возвращает переменную зоголовок строки
	STRBUFAPI(TStrRec&) GetRec(TChar* Str);

	// Функция возвращает длину строки
	STRBUFAPI(DWORD) Length(TChar *Str);

	// Функция создаёт строку размера ResultStrSize и копирует из неё StrLen символов
	// размер и длина, при необходимости, будут подогнаны под необходимые размеры
	STRBUFAPI(TChar*) CreateFromStr(const TChar* Str, DWORD StrLen, DWORD ResultStrSize);

	// Функция добавляет к строке Dst строку Src
	STRBUFAPI(void) Append(TChar* &Dst, const TChar* Src, DWORD SrcLen);

	// Функция копирует количество символов Count с позиции Pos
	STRBUFAPI(void) Copy(TChar* &Dst, const TChar* Src, DWORD Pos, DWORD Count);

	// Функция вставляет строку Str в буфер
	STRBUFAPI(void) Insert(TChar* &Buf, const TChar* Str, DWORD Position, DWORD StrLen);

	// Функция заменяет подстроки в строке
	STRBUFAPI(void) Replace(TChar* &Str, const TChar* SubStr, DWORD SBLen, const TChar* NewStr, DWORD NSLen);
}


//*********************************************************************
//  Шаблонный клас строки
//*********************************************************************
template <class TChar>
class TString : public TBotObject
{
public:
	TString() : Data(0) {};
	TString(unsigned long StrBufSize);
	TString(const TString& src);
	TString(const TChar* src);
	TString(const TChar* src, DWORD copylen);

	~TString();

	DWORD Length() const;
	DWORD CalcLength();
	void  SetLength(DWORD NewLength);
	bool  IsEmpty() const;
	void  Clear();

	void Copy(const TChar* Source, DWORD Position, DWORD Count);
	void Copy(const TString &Source, DWORD Position, DWORD Count);
	void Insert(const TChar* Str, DWORD Position);
	void Insert(const TString &Str, DWORD Position);
	void Replace(const TChar *Str, const TChar *NewStr);
	void Replace(const TString &Str, const TString &NewStr);

	int Pos(const TChar* SubStr) const;
	int Pos(const TString &SubStr) const;

	TString& Format(const TChar *FormatLine, ...); // return this

	TString& LongToStr(DWORD num); // return this

	TString& LowerCase();
	TString& UpperCase();

	DWORD Hash();
	DWORD Hash(DWORD Len, bool LowerChar);

	void Unique();

	void ConvertToLinuxFormat();

	TChar* t_str() const;

	TString& operator =(const TString &Source);
	TString& operator =(const TChar* Source);
	TString& operator +=(const TString &Source);
	TString& operator +=(const TChar* Source);
	TString operator +(const TString &Source);
	TString operator +(const TChar* Source);
	bool operator ==(const TString &Str);
	bool operator ==(const TChar* Str);
	bool operator !=(const TString &Str);
	bool operator !=(const TChar* Str);
	TChar operator [](const DWORD Index) const;
	TChar& operator [](const DWORD Index);

//	operator const TChar* () const { return t_str() }


private:
    TChar* Data;
};




typedef TString<char> string;
typedef TString<wchar_t> wstring;


#include "StrImplementation.cpp"



// Доп функции
string LongToStr(DWORD num);

// Функция преобразует многобайтную строку в однобайтную
string UnicodeToAnsi(const wchar_t *Str, DWORD Len = 0);


//****************************************************
//  Макрос объявлен для устранения неоднозначности
//  компиляции:
//
//  if (true)
//		return NULL;
//
//  неоднозначность компиляции решается уточнением
//  типа
//
//  if (true)
//		return (DWORD)NULL;
//  либо
//  if (true)
//		return string();
//
//  Для сокращения записи определяем макрос
//  возможо это не самое лучшее решение, но в
//  данный момент другого не придумал
//****************************************************
#define NULLSTR (char*)NULL
#define NULLWSTR (wchar_t*)NULL



//----------------------------------------------------------
//  DecryptStr - Функция шифрует/расшифровывает строку
//            Используя простейший алгоритм XOR шифрования
//----------------------------------------------------------
PCHAR WINAPI DecryptStr(PCHAR String, PCHAR OutString);





//****************************************************
//  Класс перебора массива строк следующих  друг за
//  другом, разделённые нулевым символом и заканчиваю-
//  щиеся пустой строкой
//  строка_1 \0 строка_2 \0 строка_3 \0\0
//****************************************************
class TStrEnum : public TBotObject
{
private:
	PCHAR  FBuf;
	bool   FEncrypted;
	PCHAR  FCurrent;
	string FLine;
	void Initialize(const char *Buffer, bool Encrypted, DWORD EmptyBufHash);
public:
	//---------------------------------------------------
	//  Параметры конструктора:
	//  Buffer - Указатель на исходный буфер
	//  Encrypted - Указание того, что строки защифрованы
	//  EmptyBufHash - Хэш "пустой" строки. Если указать
	//				   не нулевое значение и хэш строки
	//		           будет совпадать с указанным, то
	//                 класс будет считать, что строка
	//				   пустая
	//---------------------------------------------------
	TStrEnum(const char *Buffer, bool Encrypted, DWORD EmptyBufHash);
	TStrEnum(const char *Buffer);
	bool Next();
	inline string& Line() { return FLine; }
	bool IsEmpty();
};




//----------------------------------------------------------------------------
#endif
