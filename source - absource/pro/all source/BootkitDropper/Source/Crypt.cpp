#include <windows.h>
#include <wincrypt.h>

#include "Crypt.h"
#include "GetApi.h"
#include "Memory.h"
#include "Strings.h"
#include "Utils.h"
#include "BotHTTP.h"


char szTempBuf[100];

PCHAR WINAPI Decrypt(PCHAR String, PCHAR OutString)
{
	if (STR::IsEmpty(String))
		return NULL;

	PCHAR Res;
	if (OutString != NULL)
		Res = OutString;
	else
	{
		m_memset( szTempBuf, 0, 100);
		Res = szTempBuf;
    }

	__asm
	{
		pushad
		mov		esi,[String]
		//mov		edi,offset szTempBuf
        mov		edi, Res
	__again:
			lodsb
			test	al,al
			jz		__to_exit
			sub		al, 10h
			xor		al, 5h
			add		al, 10h
			stosb
			jmp		__again

	__to_exit:
		stosb
		popad
	} 

	return Res;
}

//----------------------------------------------------------------------------

static const char Base64Chars[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

PCHAR BASE64::Encode(LPBYTE Buf, DWORD BufSize)
{
	if (Buf == NULL || BufSize == 0)
		return NULL;



  PCHAR Result = STR::Alloc((BufSize + 2) / 3 * 4 + 1);
  if (Result == NULL)
	return NULL;


    PCHAR P = Result;
    BYTE Cur[3];

    while(BufSize > 0)
    {
      DWORD Len = 0;
      for(DWORD i = 0; i < 3; i++)
      {
        if(BufSize > 0)
        {
          BufSize--;
          Len++;
          Cur[i] = Buf[i];
        }
        else Cur[i] = 0;
      }

      Buf += 3;

	  P[0] = Base64Chars[Cur[0] >> 2];
	  P[1] = Base64Chars[((Cur[0] & 0x03) << 4) | ((Cur[1] & 0xF0) >> 4)];
	  P[2] = (BYTE)(Len > 1 ? Base64Chars[((Cur[1] & 0x0F) << 2) | ((Cur[2] & 0xC0) >> 6) ] : '=');
	  P[3] = (BYTE)(Len > 2 ? Base64Chars[Cur[2] & 0x3F] : '=');

      P += 4;
    }

	*P = 0;
	STR::UpdateLength(Result, P - Result);
    return Result;
}


PCHAR BASE64::Decode(PCHAR Buf, DWORD *ResultSize)
{
	// Раcшифровать данные из формата BASE64
	// Размер итогового буфера можно узнать функцией STR::Length,
	// Либо передать указатель на переменную, куда его записатиь
	if (ResultSize != NULL)
		*ResultSize = 0;
	if (STR::IsEmpty(Buf))
	return NULL;

	char C;
	short int x;
	WORD c4;
	short int StoredC4[4];

	PCHAR Result = STR::Alloc(StrCalcLength(Buf));
	DWORD Len = 0;
	PCHAR R = Result;
	c4 = 0;

	while (*Buf != 0)
	{
		while (*Buf != 0 && c4 < 4)
		{
			C = *Buf;
			if (C == '=') x = -1;
			else
			if (C == '+') x = 62;
			else
			if (C == '/') x = 63;
			else
			if (C >= '0' && C <= '9') x = C - ('0' - 52);
			else
			if (C >= 'A' && C <= 'Z') x = C - 'A';
			else
			if (C >= 'a' && C <= 'z') x = C - ('a' - 26);
			else
				return Result;

			StoredC4[c4] = x;
			c4++;
			Buf++;
		}

		if (c4 == 4)
		{
			c4 = 0;
			*R = (StoredC4[0] << 2) | (StoredC4[1] >> 4);
			R++;
			Len++;

			if (StoredC4[2] == -1) break;
			*R = (StoredC4[1] << 4) | (StoredC4[2] >> 2);
			R++;
			Len++;

			if (StoredC4[3] == -1) break;
			*R = (StoredC4[2] << 6) | StoredC4[3];
			R++;
			Len++;
		}
	}
	STR::UpdateLength(Result, Len);
	if (ResultSize != NULL)
		*ResultSize = Len;
	return Result;
}


//----------------------------------------------------------------------------
DWORD XORCrypt::Crypt(PCHAR Password, LPBYTE Buffer, DWORD Size)
{
    DWORD a = 0, b = 0;
    a = 0;

	while (a < Size)
    {
        b = 0;

		while (Password[b])
        {
            Buffer[a] ^= (Password[b] + (a * b));
            b++;
        }
        a++;
    }

	return a;
}

// Для соответствия TCryptMethod
bool XORCrypt::Crypt(LPVOID Password, LPBYTE Buffer, DWORD Size, PDWORD OutSize)
{
	if (Buffer == NULL || Size == 0)
		return false;
   *OutSize = Crypt((PCHAR)Password, Buffer, Size);
   return *OutSize != 0;
}



LPBYTE XORCrypt::DecodeBuffer(PCHAR  Signature, LPVOID Buffer, DWORD &Size)
{
	// Функция расшифровывает буфер содержащий пароль

	if (Buffer == NULL || Size == 0)
		return NULL;

	PCHAR Buf = (PCHAR)Buffer;
	PCHAR Start = Buf;

	// Сравниваем сигнатуру
	if (!STR::IsEmpty(Signature))
	{
		DWORD SignLen = StrCalcLength(Signature);
		if (SignLen >= Size || !StrSame(Buf, Signature, true, SignLen))
			return NULL;
		Buf += SignLen;
    }

	// Jghtltkztv gfhjkm
	DWORD PassSize = *(PDWORD)Buf;
	Buf += sizeof(DWORD);

	PCHAR Password = STR::New(Buf, PassSize);
	if (Password == NULL)
		return NULL;
	Buf += PassSize;


	// Определяем новый размер буфера
	int NewSize = Buf - Start;
	if ((DWORD)NewSize > Size)
		return NULL;
	Size -= NewSize;
	// Расшифровываем данные
	NewSize = XORCrypt::Crypt(Password, (LPBYTE)Buf, Size);
	STR::Free(Password);
	if (NewSize <= 0)
		return NULL;

	Size = NewSize;
    return (LPBYTE)Buf;
}



//****************************************************************************
//  Методы для шифрования методами WIN Crypt
//  буфер собран по следующему алгоритму (Б - байт)
//
//  (4Б перваля половина IV)(BASE64 данные)(4Б вторая половина IV)(окончание BASE64 ==)
//****************************************************************************

PCHAR RC2Crypt::ExtractIV(PCHAR Buf, DWORD StrLen)
{
	// Функция извлекает вектор инициализации ключа из буфера
	if (STR::IsEmpty(Buf))
		return NULL;

	if (StrLen == 0)
		StrLen = StrCalcLength(Buf);
	if (StrLen < 8) return NULL;

	PCHAR V = STR::Alloc(8);

	// Получаем первуб часть вектора
	STR::Copy(Buf, V, 0, 4);
	STR::Delete(Buf, 0, 4);
	StrLen -= 4;

	// Получаем вторую часть
	PCHAR Ptr = Buf + StrLen - 1;
	while (Ptr > Buf && *Ptr == '=') Ptr--;
    Ptr -= 3;
    STR::Copy(Ptr, V + 4, 0, 4);
	STR::Delete(Ptr, 0, 4);

	return V;
}

// Генерировать случайный вектор
PCHAR RC2Crypt::GenerateIV()
{
	PCHAR V = STR::Alloc(8);

	PCHAR T = V;
	DWORD Max = sizeof(Base64Chars) - 2;
	for (DWORD i = 0; i < 8; i++)
    {
		DWORD Index = Random::Generate(0, Max);
		*T = Base64Chars[Index];
		T++;
	}
	return V;
}

PCHAR RC2Crypt_PackEncodedBuffer(PCHAR Buf, DWORD BufSize, PCHAR IV)
{
	// Запаковываем в буфер зашифрованные данные и вектор ключа
	PCHAR Result = STR::Alloc(BufSize + 8);
	if (Result == NULL)
		return NULL;

    PCHAR P = Result;
	// Вставляем первые 4 байта ключа
	STR::Copy(IV, P, 0, 4);
    P += 4;
	// Определяем границу до которой нужно копировать тело Base64
	PCHAR End = Buf + BufSize;
	while (End > Buf && *(End - 1) == '=') End--;

	STR::Copy(Buf, P, 0, End - Buf);
	P += End - Buf;

	// Копируем вторую часть вектора
	STR::Copy(IV, P, 4, 4);
	P += 4;

	// копируем оставшуюся часть буфера
	STR::Copy(End, P, 0, BufSize - (End - Buf));

    return Result;
}

PCHAR RC2Crypt::Encode(LPBYTE Buf, DWORD BufSize,  PCHAR Password)
{
	// кодировать буфер
	if (Buf == NULL || BufSize == 0 || STR::IsEmpty(Password))
		return NULL;

	PCHAR IV = GenerateIV();
	if (IV == NULL)
		return NULL;


	DWORD EncBufSize = BufSize;
	LPBYTE NewBuf = WinEncode(Buf, EncBufSize, Password, IV);


    PCHAR Result = NULL;

	if (NewBuf != NULL)
	{
		// Кодируем в BASE64
		PCHAR B64 = BASE64::Encode(NewBuf, EncBufSize);
		// Запаковываем буфер с вектором
        Result = RC2Crypt_PackEncodedBuffer(B64, STR::Length(B64), IV);

        STR::Free(B64);
        MemFree(NewBuf);
	}

	STR::Free(IV);
    return Result;

}


bool RC2Crypt::Decode(PCHAR Password, PCHAR Buf, DWORD &BufSize)
{
	// Декодировать буфер
	// на входе строка BASE64 символов с вшитым в них ыектором IV
	// BufSize - Размер передаваемого буфера.
	// Если содержит нулевое значение, то размер буфера
	// будет просчитан до нулевого символа.
	// После отработки метода BufSize будет указывать на размер
	// расшифрованного буфера

	if (STR::IsEmpty(Buf))
		return false;

	if (BufSize == 0)
		BufSize = StrCalcLength(Buf);

    DWORD OriginalSize = BufSize;

	PCHAR V = ExtractIV(Buf, BufSize);
	if (V == NULL) 	return false;
	BufSize -= 8; // Уменьшаем на размер вектора

	// BASE64 расшифровка
	PCHAR B64 = BASE64::Decode(Buf);

	BufSize = STR::Length(B64);
	STR::Copy(B64, Buf, 0, BufSize);
	if (BufSize < OriginalSize)
		*(Buf + BufSize) = 0;
	STR::Free(B64);

	// Расшифровываем данные
	WinDecode(Buf, BufSize, Password, V);
	STR::Free(V);

    return true;
}


bool RC2Crypt::DecodeStr(PCHAR Password, PCHAR Str)
{
	// Функция декодирует строку и обновляет её размер
	if (STR::IsEmpty(Str) || STR::IsEmpty(Password))
		return false;
	DWORD Size = STR::Length(Str);
	if (Decode(Password, Str, Size))
	{
		STR::UpdateLength(Str, Size);
		return true;
	}

	return false;
}


LPBYTE RC2Crypt::WinEncode(LPBYTE Buf, DWORD &BufSize, PCHAR Password, PCHAR IV)
{
	// Шифровать буфер используя Win Crypto API
	// Функция выделяет необходимый объём памяти методом MemAlloc()
	if (Buf == NULL || BufSize == 0 || STR::IsEmpty(Password) || STR::IsEmpty(IV))
		return NULL;

	HCRYPTPROV Provider;
	HCRYPTKEY Key;
	LPBYTE NewBuf = NULL;
	if (GenerateKey(Password, IV, Provider, Key))
	{
		// Лпределяем нужный размер буфера
		DWORD NewBufSize = BufSize;
		if (pCryptEncrypt(Key, 0, true, 0, NULL, &NewBufSize, 0))
		{
			NewBuf = (LPBYTE)MemAlloc(NewBufSize);
			if (NewBuf != NULL)
			{
				m_memcpy(NewBuf, Buf, BufSize);
				pCryptEncrypt(Key, 0, true, 0, NewBuf, &BufSize, NewBufSize);
            }
        }

		pCryptDestroyKey(Key);
		pCryptReleaseContext(Provider, 0);
	}

	return NewBuf;
}


PCHAR RC2Crypt::WinDecode(PCHAR Buf, DWORD &BufSize, PCHAR Password, PCHAR IV)
{
	// Декодировать буфер используя Win Crypto API
	HCRYPTPROV Provider;
	HCRYPTKEY Key;
	if (GenerateKey(Password, IV, Provider, Key))
	{
		if (pCryptDecrypt(Key, 0, true, 0, Buf, &BufSize))
			*(Buf + BufSize) = 0;

		pCryptDestroyKey(Key);
		pCryptReleaseContext(Provider, 0);
	}
	return Buf;
}


typedef struct TKeyBlob
{
	BLOBHEADER KeyHeader;
    DWORD KeySize;
	BYTE KeyData[64];
} *PKeyBlob;

bool RC2Crypt::GenerateKey(PCHAR Password, PCHAR IV, HCRYPTPROV &Provider, HCRYPTKEY &Key)
{
	// Генерировать ключ криптования на основе пароля и вектора инициализации IV

	Provider = NULL;
	Key = NULL;

	if (STR::IsEmpty(Password) || STR::IsEmpty(IV))
		return false;

	TKeyBlob KeyBlob;

	DWORD CryptMode;
	DWORD PadMode;

	// Поключаемся к провайдеру
	if (!pCryptAcquireContextA(&Provider, NULL, NULL, PROV_RSA_FULL, CRYPT_VERIFYCONTEXT))
		return false;

    // импортируем ключ
	ClearStruct(KeyBlob);
	KeyBlob.KeyHeader.bType    = PLAINTEXTKEYBLOB;
	KeyBlob.KeyHeader.bVersion = CUR_BLOB_VERSION;
	KeyBlob.KeyHeader.aiKeyAlg = CALG_RC2;

	KeyBlob.KeySize = StrCalcLength(Password);
    STR::Copy(Password, (PCHAR)KeyBlob.KeyData, 0, KeyBlob.KeySize);


	if (!pCryptImportKey(Provider, (LPBYTE)&KeyBlob, sizeof(KeyBlob), 0, 0, &Key))
	{
		pCryptReleaseContext(Provider, 0);
		Provider = NULL;
        return false;
    }

	// Настраиваем ключ
	bool ValidKey = true;
	if (!pCryptSetKeyParam(Key, KP_IV, (LPBYTE)IV, 0))
		ValidKey = false;

    CryptMode = CRYPT_MODE_CBC;

	if (!pCryptSetKeyParam(Key, KP_MODE, (LPBYTE)&CryptMode, 0))
        ValidKey = false;

	PadMode = PKCS5_PADDING;
	if (!pCryptSetKeyParam(Key, KP_PADDING, (LPBYTE)&PadMode, 0))
	   ValidKey = false;

	if (!ValidKey)
	{
		pCryptDestroyKey(Key);
		pCryptReleaseContext(Provider, 0);
		Key = NULL;
		Provider = NULL;
	}
    return ValidKey;

}

