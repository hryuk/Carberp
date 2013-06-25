#include <windows.h>

#ifndef StringsH
#define StringsH
//-----------------------------------------------------------------------------

//int WINAPI URLEncode( char *pszDestiny, char *pszSource );

void DbgMsg(char *file, int line, char *msg, ...);
void DbgMsgW(WCHAR *file, int line, WCHAR *msg, ...);

int m_atoi( const char *nptr );

void   WINAPI m_lstrcat( char *szBuf, const char *szStr );
void   WINAPI m_lstrcpy( char *szBuf, const char *szStr );
void   WINAPI m_lstrlwr( char *str );

void WINAPI m_lwcscat( WCHAR *szBuf, const WCHAR *szStr );

char * WINAPI m_strstr( const char * _Str, const char * _SubStr );
char * WINAPI m_strstrmask( const char * _Str, const char * _SubStr );
char * WINAPI m_strtok_s( char *String, const char *Control, char **Context );

char * WINAPI ToAnsi( LPCWSTR String );
char * WINAPI ToAnsiEx( LPCWSTR String, DWORD dwSize );

bool   WINAPI m_lstrncpy( char *pString_src, const char *pString_dst, DWORD len );
bool   WINAPI SearchByMask( char *mask, char *name );

int  WINAPI m_istrstr( const char * _Str, const char * _SubStr );
DWORD  WINAPI m_lstrcmp( const char *szStr1, const char *szStr2 );
DWORD  WINAPI m_lstrncmp( const char *szstr1, const char *szstr2, int nlen );
DWORD  WINAPI m_lstrlen( char *szPointer );

DWORD WINAPI m_wcslen( const wchar_t *String );

wchar_t *m_wcsncpy( wchar_t *dest, wchar_t *src, unsigned long n );
wchar_t *m_wcslwr( wchar_t *Str );
bool m_wcsncmp( WCHAR *s1, WCHAR *s2, size_t iMaxLen );


bool WildCmp( char *Buffer, char *Mask, LPDWORD dwStart, LPDWORD dwEnd, LPDWORD dwLen );
//bool WildCmp( PCHAR Buffer, PCHAR Mask);

bool CompareUrl( char *MaskUrl, char *Url );

WCHAR * AnsiToUnicode( char *AnsiString, DWORD dwStrLen );
void AlertError( LPTSTR lpszFunction ) ;



// ----------------------------------------------------------------------------
//  Набор функция для работы со строками
//
//  Если использовать данные функции для работы со строками, то? в некоторых
//  случаях, можно достить большего быстродействия. Например, функция
//  StrLength многократно  превышает по быстродействию функции которые
//  просчитывают длину строки сканируя её до нулевого символа, и чем больше
//  строка тем больше разница в быстродействии
// ----------------------------------------------------------------------------

// Изменить размер буфера строки
// Важно!!! Функция работает со строками которые созданы функцией StrNew
void StrSetLength(PCHAR &Str, DWORD NewLength);


// Функция расчитывает длину строки сканируя ея в поисках завершаешего нуля
DWORD StrCalcLength(PCHAR Source);

// Функция возвращает истину если на входе нулевой указатель либо
// пустая строка
bool StrIsEmpty(PCHAR Str);

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
int StrCompare(PCHAR Str1, PCHAR Str2);

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

	//  Создать новую строку на основе Source (создаёт дублика строки Source)
	//  Если CopySize = 0 то копируется вся строка
	PCHAR New(PCHAR Source, DWORD CopySize = 0);

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
	int Pos(PCHAR Str, PCHAR SubStr, DWORD StrLen = 0);

	// Копирует с позиции Position строки Source Count символов в
	// строку Destination
    void Copy(PCHAR Source, PCHAR Destination, DWORD Position, DWORD Count);

	// Удаляет Count символов с позоции Position строки Str
    void Delete(PCHAR Str, DWORD Position, DWORD Count, DWORD StrLength = 0);

	// Функция возвращает указатель на символ С
	PCHAR Scan(PCHAR Str, char C);

	// Функция возвращает указатель на последний символ С
	PCHAR ScanEnd(PCHAR Str, char C);

	// Функции возвращают текст слева, справа соответственно
	// относительно строки SubStr
	PCHAR GetLeftStr(PCHAR Str, PCHAR SubStr, bool IncludeSubStr = false);
	PCHAR GetRightStr(PCHAR Str, PCHAR SubStr, bool IncludeSubStr = false);


	// Функция игнорирует пробелы. Функция НЕ изменяет строку, она
	// возвращает указатель на нужный символ, либо на конец строки
	PCHAR IgnoreSpaces(PCHAR Str);

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

}



// ----------------------------------------------------------------------------
//  Strings - Набор функция для работы со списками строк
// ----------------------------------------------------------------------------

typedef LPVOID PStrings;

namespace Strings
{
	// Создать набор строк
	PStrings Create();

	// Уничтожить набор строк
	void Free(PStrings Strings);

	// Очистить набор строк
	void Clear(PStrings Strings);

	// Получить количество строк
	DWORD Count(PStrings Strings);

	// Добавить новую строку/
	// По умолчанию строка дублируется. Чтобы отключить эту опцию
	// установите Duplicate = false. Строка Str должна быть создана
	// функцциями StrNew либо StrAlloc
	// В этом случае строка будет помещена в список
	// и управление жьзнью строки будет передану списку строк!!!
	int Add(PStrings Strings, PCHAR Str, bool Duplicate = true);

	// Получит строку из позиции
	PCHAR GetItem(PStrings Strings, DWORD Index, bool DuplicateStr = true);

	// Объеденяет все строки в одну. Если не указан
	// разделитель то использован разделитель заданный в настройках
	PCHAR GetText(PStrings Strings, PCHAR LineDelimeter = NULL);

	// Функция разбирает текст на строки разделённые символами новой
	// строки и перевода каретки
	void SetText(PStrings Strings, PCHAR Text);

	// Удалить строку в позиции Index
	void Delete(PStrings Strings, DWORD Index);

	// Функция удаляет строку Str из списка
	int Remove(PStrings Strings, PCHAR Str);

	// Функция возвращает позицию строки Str в списке
	int IndexOf(PStrings Strings, PCHAR Str);

	// Добавить в список пару Имя=Значение.
	// Если не указан разделитель то будет взят из настроек списка (по умолчанию =)
	int AddValue(PStrings Strings, PCHAR Name, PCHAR Value, PCHAR Delimeter = NULL);

}


//----------------------------------------------------------------------------------------------------

#endif
