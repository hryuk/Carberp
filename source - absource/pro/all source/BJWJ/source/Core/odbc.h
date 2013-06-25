#include <windows.h>
#include <sql.h>
#include <sqlext.h>
#include "GetApi.h"

class ODBC : public TBotObject
{
    	SQLHENV henv;
	    SQLHDBC hdbc;

	    SQLHSTMT CreateQuery( const char* sql );

	public:

		ODBC() : henv(0), hdbc(0)
		{
		}

		~ODBC()
		{
			Close();
		}

		bool Connect( const char* strconnect );
		void Close();

// строка format содержит информацию о получаемых или передаваемых параметрах
// запроса. Каждый параметр описывается как: n0th, где n может быть равно i - передаваемый
// параметр, o - получаемый параметр, ! - игнорируемый параметр, 0 - только для n = o, 
// дополнительно для получаемого
// параметра передаем указатель SQLLEN* в котором должна возратится длина
// получаемых данных, если длина = -1, то значит значение равно NULL;
// t - тип параметра и может иметь следующие
// значения: c - char, b - byte, i - int, u - unsigned int, d - double, f - float, 
//           s - char*, h - short, uh - unsigned short, t - TIMESTAMP_STRUCT, r - бинарные данные
// h - длина принимаемых данных для строк (включая null терминатор)
		SQLHSTMT ExecuteSql( const char* sqltext, const char* format, ... );

	    void CloseQuery( SQLHSTMT );
	    bool NextRow( SQLHSTMT );
};
