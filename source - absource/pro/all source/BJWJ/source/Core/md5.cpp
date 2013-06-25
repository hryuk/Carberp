//---------------------------------------------------------------------------

#pragma hdrstop

#include "GetApi.h"
#include "Memory.h"
#include "MD5.h"
//---------------------------------------------------------------------------




void MD5Init2(PMD5Context Context)
{

	ClearStruct(*Context);
	pMD5Init(Context);
}

void MD5Update2(PMD5Context Context, LPVOID Buf, DWORD BufSize)
{
	// Функция принимает блоки максимальным размером
	// 64 байта. По этому разделим апдейт на такие блоки

	LPBYTE Tmp = (LPBYTE)Buf;
	while (BufSize)
	{
		DWORD ToAdd = Min(BufSize, 64);
		pMD5Update(Context, Tmp, ToAdd);

		BufSize -= ToAdd;
		Tmp     += ToAdd;
	}
}


void MD5Final2(PMD5Context Context)
{
	pMD5Final(Context);
}


void GetMD5Result(PMD5Context Context, TMD5 &Hash)
{
	ClearStruct(Hash);
	if (Context)
		m_memcpy(Hash.Data, Context->digest, MD5_HASH_SIZE);
}

//-------------------------------------------------
//  MD5FromBuf - Функция расчитывает MD5 хэш буфера
//-------------------------------------------------
void MD5FromBuf(LPVOID Buf, DWORD BufSize, TMD5 &Hash)
{
	TMD5Context Context;

	MD5Init2(&Context);
	MD5Update2(&Context, Buf, BufSize);
	MD5Final2(&Context);

	GetMD5Result(&Context, Hash);
}


//-------------------------------------------------
// MD5FromHandle - Функция расчитывает нэш данных
//                 идентификатора
//-------------------------------------------------
bool MD5FromHandle(HANDLE Handle, TMD5 &Hash, bool ACloseHandle)
{
	ClearStruct(Hash);
	if (Handle == INVALID_HANDLE_VALUE) return false;

	TMD5Context Context;
	MD5Init2(&Context);

	const DWORD BufSize = 64 * 10;
	BYTE Buf[BufSize];
	while (true)
	{
		DWORD Readed = 0;
		pReadFile(Handle, Buf, BufSize, &Readed, NULL);
		if (!Readed)	break;
		MD5Update2(&Context, Buf, Readed);
	}
	if (ACloseHandle) pCloseHandle(Handle);

	MD5Final2(&Context);
	GetMD5Result(&Context, Hash);

	return true;
}


//-------------------------------------------------
// MD5FromFile - Функция расчитывает md5 хэш файла
//-------------------------------------------------
bool MD5FromFileA(const char* FileName, TMD5 &Hash)
{
	HANDLE File = pCreateFileA(FileName, GENERIC_READ, FILE_SHARE_READ, 0,
							   OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);
    return MD5FromHandle(File, Hash, true);
}


bool MD5FromFileW(const wchar_t* FileName, TMD5 &Hash)
{
	HANDLE File = pCreateFileW(FileName, GENERIC_READ, FILE_SHARE_READ, 0,
						       OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);
	return MD5FromHandle(File, Hash, true);
}


//-------------------------------------------------
//  Дополнительные функции возвращающие MD5 хэш в
//  виде cnhjrb
//-------------------------------------------------
string MD5StrFromBuf(LPVOID Buf, DWORD BufSize)
{
	TMD5 MD5;
    MD5FromBuf(Buf, BufSize, MD5);
	return MD5ToStr(MD5);
}

string MD5StrFromFileA(const char* FileName)
{
	TMD5 MD5;
	MD5FromFileA(FileName, MD5);
	return MD5ToStr(MD5);
}

string MD5StrFromFileW(const wchar_t* FileName)
{
	TMD5 MD5;
    MD5FromFileW(FileName, MD5);
	return MD5ToStr(MD5);
}


//-------------------------------------------------
//  DoMD5ToStr - Функция конвертирует мд5 буфер
//               в строку
//-------------------------------------------------
string DoMD5ToStr(LPBYTE MD5)
{
	string Result;
	if (MD5)
	{
		Result.SetLength(32);
		PCHAR Tmp = Result.t_str();
		const static char hexval[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};
		for (int i = 0; i < MD5_HASH_SIZE; i++)
		{
			Tmp[i*2]       = hexval[((MD5[i] >> 4) & 0x0F)];
			Tmp[(i*2) + 1] = hexval[(MD5[i]) & 0x0F];
		}
	}
	return Result;
}


//-------------------------------------------------
// MD5ToStr - Функция конвертирует MD5 хэн в строку
//-------------------------------------------------
string MD5ToStr(TMD5 &Hash)
{
    return DoMD5ToStr(Hash.Data);
}

string MD5ToStr(TMD5Context &Content)
{
	return DoMD5ToStr(Content.digest);
}


//-------------------------------------------------
// Функции сравнения бинарных хэшей
//-------------------------------------------------
bool MD5Compare(LPBYTE Hash1, LPBYTE Hash52)
{
	return m_memcmp(Hash1, Hash52, MD5_HASH_SIZE) == 0;
}
