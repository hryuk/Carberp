
#ifndef CryptH
#define CryptH

//-----------------------------------------------------------------------------
#include <windows.h>
#include <wincrypt.h>

#include "Strings.h"


PCHAR WINAPI Decrypt(PCHAR String, PCHAR OutString = NULL);


//****************************************************************************
//  BASE64 - Методы кодирования/декодирования BASE64
//****************************************************************************

namespace BASE64
{
	// Зашифровать данные в строку формата BASE64
	PCHAR Encode(LPBYTE Buf, DWORD BufSize);

	// Раcшифровать данные из формата BASE64
	// Размер итогового буфера можно узнать функцией STR::Length,
	// Либо передать указатель на переменную, куда его записатиь
	// Результат уничтожить функцией STR::Free()
	PCHAR Decode(PCHAR Buf, DWORD *ResultSize = NULL);
}



// Метод криптования
typedef bool (*TCryptMethod)(LPVOID Key, LPBYTE Buffer, DWORD BufferSize, PDWORD ResultBufferSize);


//****************************************************************************
//  Методы для шифрования XOR алгоритмом
//  Шифрование и расшифровка выполняются одними и теме-же методами
//****************************************************************************

namespace XORCrypt
{
	// Шифрование XOR алгоритмом
	DWORD Crypt(PCHAR Password, LPBYTE Buffer, DWORD Size);

	// Для соответствия TCryptMethod
	bool Crypt(LPVOID Password, LPBYTE Buffer, DWORD Size, PDWORD OutSize);


	//----------------------------------------------------------------
	//   DecodeBuffer - Функция декодирует буфер содержащий в себе
	//                   пароль
	//   Формат буфера
	//   [Сигнатура](DWORD Размер пароля)(Пароль)(Данные)
	//
	//
	//  Signature - Сигнатура буфера. NULL если отсутствует
	//
	//  Buffer - Буфер зашифрованных данных
	//
	//   Size - Размер буфера. После работы функции будет содержать
	//			размер расшифрованных данных
	//
	//  Результат - Функция возвращает указатель на первый символ
	//              декодированного буфера.
	//  Память под результат НЕ выделяется!
	//----------------------------------------------------------------
	LPBYTE DecodeBuffer(PCHAR Signature, LPVOID Buffer, DWORD &Size);


}


//****************************************************************************
//  Методы для шифрования методами WIN Crypt
//  буфер собран по следующему алгоритму (Б - байт):
//
//  (4Б перваля половина IV)(BASE64 данные)(4Б вторая половина IV)(окончание BASE64 ==)
//
//****************************************************************************

namespace RC2Crypt
{
	// Функция извлекает вектор инициализации ключа из буфера
	PCHAR ExtractIV(PCHAR Buf, DWORD StrLen);

	// Генерировать случайный вектор
	PCHAR GenerateIV();

	// кодировать буфер
    PCHAR Encode(LPBYTE Buf, DWORD BufSize,  PCHAR Password);

	// Декодировать буфер
	// на входе строка BASE64 символов с вшитым в них ыектором IV
	// BufSize - Размер передаваемого буфера.
	// Если содержит нулевое значение, то размер буфера
	// будет просчитан до нулевого символа.
	// После отработки метода BufSize будет указывать на размер
	// расшифрованного буфера
	bool Decode(PCHAR Password, PCHAR Buf, DWORD &BufSize);

	// Функция декодирует строку и обновляет её размер
    bool DecodeStr(PCHAR Password, PCHAR Str);

	// Шифровать буфер используя Win Crypto API
    // Функция выделяет необходимый объём памяти методом MemAlloc()
	LPBYTE WinEncode(LPBYTE Buf, DWORD &BufSize, PCHAR Password, PCHAR IV);

	// Декодировать буфер используя Win Crypto API
	PCHAR WinDecode(PCHAR Buf, DWORD &BufSize, PCHAR Password, PCHAR IV);

	// Генерировать ключ криптования на основе пароля и вектора инициализации IV
	bool GenerateKey(PCHAR Password, PCHAR IV, HCRYPTPROV &Provider, HCRYPTKEY &Key);
}


//-----------------------------------------------------------------------------
#endif