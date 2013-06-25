#include <windows.h>
#include <wincrypt.h>

#include "Crypt.h"
#include "GetApi.h"
#include "BotClasses.h"
#include "MD5.h"
#include "Memory.h"
#include "Strings.h"
#include "Utils.h"
#include "BotHTTP.h"
#include "Config.h"


char UIDPassword[RC2_DEFAULT_PASSWORD_SIZE + 1] = {0};

//*********************************************************
//  GetUIDPassword
//  Функция возвращает пароль сгенерированныйна основе UID
//  Пароль будет одинаков для всех процессов и запусков
//  на данной машине, но уникальный для каждой машины
//*********************************************************
PCHAR GetUIDPassword()
{
	if (UIDPassword[0] == 0)
	{
		m_memset(UIDPassword, '-', RC2_DEFAULT_PASSWORD_SIZE);

		PCHAR UID = MakeMachineID();

		DWORD CopySize = Min(STRA::Length(UID), RC2_DEFAULT_PASSWORD_SIZE);
		STR::Copy(UID, UIDPassword, 0, CopySize);
	}
	return UIDPassword;
}




//----------------------------------------------------------------------------

// Набор символов для BASE64 кодировки
char Base64Chars[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";


// Дополнительный вектор шифрования для UIDCrypt методов
char UIDCryptDefaultIV[] = {'l', 'f', 'g', 'r', 'f', 'J', 'D', '6',  0};

//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------

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
	DWORD a, b;
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

//---------------------------------------------------------
//  EncodeString  Функция кодирует строку. Максимальный
//                размер строки 255 байт
//  Фактически длина строки должна равняться длине исходной
//  строки. т.к вместо закрывающего нуля мы смещаем строку
//  на один байт и первым байтом записываем размер
//  исходной строки. Но для удобства размер результирующей
//  строки удет на один байт больше!!!!
//---------------------------------------------------------
string XORCrypt::EncodeString(const char* Password, const char* Str)
{
	string Result;
	DWORD Len = STRA::Length(Str);
	if (Len > 0 && Len <= 255)
	{
		Result.SetLength(Len + 1);
		PCHAR Buf = Result.t_str();

		// Первым байтом пишем размер строки
		*Buf = LOBYTE(Len);
		Buf++;

		// Копируем исходную строку в буыер и шифруем её
		m_memcpy(Buf, Str, Len);
		Crypt((PCHAR)Password, (LPBYTE)Buf, Len);
    }

	return Result;
}


//---------------------------------------------------------
//  DecodeString Функция дешифрует строку , что была
// зашифрована функцией EncodeString
//---------------------------------------------------------
string XORCrypt::DecodeString(const char* Password, const char* Str)
{
	string Result;
	if (STRA::IsEmpty(Str))
		return Result;

	// Получаем размер строки
	DWORD Len = *Str;
	Str++;

	// Копирем исходный буфер
	Result.SetLength(Len);
	m_memcpy(Result.t_str(), Str, Len);

	// Расшифровываем данные
	Crypt((PCHAR)Password, (LPBYTE)Result.t_str(), Len);


	return Result;
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


bool RC2Crypt::DecodeStr(PCHAR Password, PCHAR Str, DWORD &Size)
{
	// Функция декодирует строку и обновляет её размер
	if (STRA::IsEmpty(Str) || STRA::IsEmpty(Password))
		return false;
	if (Size == 0)
		Size = STRA::Length(Str);

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
		if (pCryptEncrypt(Key, 0, TRUE, 0, NULL, &NewBufSize, 0))
		{
			NewBuf = (LPBYTE)MemAlloc(NewBufSize);
			if (NewBuf != NULL)
			{
				m_memcpy(NewBuf, Buf, BufSize);
				pCryptEncrypt(Key, 0, TRUE, 0, NewBuf, &BufSize, NewBufSize);
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
		if (pCryptDecrypt(Key, 0, TRUE, 0, (BYTE*)Buf, &BufSize))
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


//****************************************************************************
//  Методы для шифрования данных файлов
//****************************************************************************


//----------------------------------------------------------
//  WriteFromBuffer
//  Функция зашифровывает содержимое
//  буфера и записывает его в буфер
//----------------------------------------------------------
bool CryptFile::WriteFromBuffer(PCHAR FileName, LPVOID Buffer, DWORD DataSize)
{

	if (!Buffer || !DataSize) return false;

	TBotFileStream File(FileName, fcmCreate);
	if (!File.Valid()) return false;

	TWinCrypt Crypt;
	Crypt.CreateRC4Key(GetUIDPassword());

	DWORD BlockSize = Min(DataSize, 1024);
	DWORD BufSize   = BlockSize;

	// Определяем размер буфера шифрования
	Crypt.Encrypt(NULL, BufSize, 0, true);

	TMemory Buf(BufSize);

	// Записываем хэш сумму данных
    TMD5 MD5;
	MD5FromBuf(Buffer, DataSize, MD5);
	File.Write(MD5.Data, MD5_HASH_SIZE);

	LPBYTE Tmp = (LPBYTE)Buffer;
	while (DataSize)
	{
		DWORD ToWrite = Min(BlockSize, DataSize);
		Buf.Write(Tmp, ToWrite);

		DataSize -= ToWrite;
		Tmp += ToWrite;

		// Шифруем данные
		Crypt.Encrypt(Buf.Buf(), ToWrite, BufSize, DataSize == 0);

		// Записываем данные
		if (File.Write(Buf.Buf(), ToWrite) != ToWrite)
		{
			// Ошибка записи файла
			File.Close();
			pDeleteFileA(FileName);
            return false;
		}

	}

    return true;
}

//----------------------------------------------------------
//  ReadToBuffer
//  Функция читает содержимое файла,
//	расшифровывает его и возвращает указатель
//----------------------------------------------------------
LPVOID CryptFile::ReadToBuffer(PCHAR FileName, LPDWORD BufferSize)
{
	if (BufferSize) *BufferSize = 0;

	TBotFileStream File(FileName, fcmRead);
	if (!File.Valid()) return NULL;

	DWORD Size = File.Size();
	if (Size <= MD5_HASH_SIZE) return 0;

    Size -= MD5_HASH_SIZE; // Игнорируем хэш

	LPBYTE FileData = (LPBYTE)MemAlloc(Size);
	if (!FileData) return 0;

	TBotMemoryStream Destination(FileData, Size);
		

	TWinCrypt Crypt;
	Crypt.CreateRC4Key(GetUIDPassword());

	DWORD BlockSize = 1024;

	TMemory Buf(BlockSize);

	// Читаем хэш сумму данных файла
	TMD5 DataMD5;
	File.Read(DataMD5.Data, MD5_HASH_SIZE);


	while (Size)
	{
		DWORD Readden = File.Read(Buf.Buf(), BlockSize);
		if (Readden == 0) break;
		Size -= Readden;
			

		// Расшифровываем данные
		if (!Crypt.Decrypt(Buf.Buf(), Readden, Size == 0))
			break;

		PCHAR Tmp = Buf.AsStr();

		// Записываем данные
		Destination.Write(Buf.Buf(), Readden);
	}

	DWORD DataSize = Destination.Position();

	// Сравниваем хэши
	TMD5 MD5;
	MD5FromBuf(FileData, DataSize, MD5);
	if (!MD5Compare(MD5.Data, DataMD5.Data))
	{
		MemFree(FileData);
		return NULL;
    }

	if (BufferSize)
		*BufferSize = DataSize;

    return FileData;
}

//****************************************************************************
//  Методы для шифрования данных идентификатором бота (UID) вместо пароля
//  Шифрование производится методами  RC2Crypt
//****************************************************************************


PCHAR UIDCrypt::Crypt(LPVOID Data, DWORD DataSize, PCHAR Vector)
{
	// Функция шифруем данные ключом на основе UID
	if (Data == NULL || DataSize == 0)
		return NULL;

    // Получаем пароль
	PCHAR Password = GetUIDPassword();

	PCHAR Result = NULL;

	// Шифруем данные
	if (Vector == NULL)
    	Vector = UIDCryptDefaultIV;

	LPBYTE Buf = RC2Crypt::WinEncode((LPBYTE)Data, DataSize, Password, Vector);

	// Преобразовываем в BASE64
	if (Buf != NULL)
	{
		Result = BASE64::Encode(Buf, DataSize);

		MemFree(Buf);
    }
	return Result;
}
//-----------------------------------------------------------------------------

PCHAR UIDCrypt::CryptFileName(const char* FileName, bool CryptExt)
{
	//  Функция криптует имя файла делая его уникальным для данного
	//  компьютера. Путь к файлу не шифруется

	if (STRA::IsEmpty(FileName))
    	return NULL;

	// Получаем имя файла
	PCHAR File = File::ExtractFileNameA((PCHAR)FileName, true);
	if (File == NULL)
    	return STR::New((PCHAR)FileName);

	// Сохраняем исхоный путь
	PCHAR Path = File::ExtractFilePathA((PCHAR)FileName);

	// Отделяем расширение файла
	PCHAR Ext = STR::ScanEnd(File, '.');
	if (Ext != NULL)
	{
		*Ext = 0;
		Ext++;
    }


	// Шифруем данные
	PCHAR NewFile = Crypt((LPVOID)File, StrCalcLength(File), NULL);


	// Нормализуем имена
	ConvertFileNameChars(NewFile);

	// Формируем результат

    PCHAR ExtDelimeter = (Ext)? (PCHAR)"." : NULL;

	PCHAR Result = STR::New(4, Path, NewFile, ExtDelimeter, Ext);


	// Освобождаем данные
	STR::Free(Path);
	STR::Free(File);
	STR::Free(NewFile);

    return Result;
}
//-----------------------------------------------------------------------------

void UIDCrypt::ConvertFileNameChars(PCHAR Name)
{
	// Функция преобразует недопустимые и редковстречающиеся символы
	// имени файла полученного путём шифрования
	if (STR::IsEmpty(Name))
		return;

	PCHAR Tmp = STR::End(Name);
	Tmp--;
	while (Tmp > Name && *Tmp == '=')
	{
		*Tmp =0;
		Tmp--;
	}

	for (Tmp = Name; *Tmp != 0; Tmp++)
	{
		if (*Tmp == '/')
			*Tmp = 'z';  // недопустимый символ
		else
		if (*Tmp == '+')
			*Tmp = 'v';  // Редко встречается в названиях, не мозолим глаза :))
	}
}



//*****************************************************************************
//  							TWinCrypt
//*****************************************************************************

TWinCrypt::TWinCrypt()
{
	// В конструкторе автоматически инициализируем провайдера
    InitializeProvider(0, 0, 0);
}


TWinCrypt::TWinCrypt(const char *Container, DWORD Flags)
{
	// В конструкторе автоматически инициализируем провайдера
    InitializeProvider(0, Container, Flags);
}

TWinCrypt::TWinCrypt(HCRYPTPROV Provider)
{
	InitializeProvider(Provider, 0, 0);
}

TWinCrypt::~TWinCrypt()
{
	// Освобождаем данные

	if (FKey)
    	pCryptDestroyKey(FKey);

	if (!FProviderAssigned && FProvider)
		pCryptReleaseContext(FProvider,0);
}


void TWinCrypt::DestroyKey()
{
	if (FKey)
	{
		pCryptDestroyKey(FKey);
        FKey = 0;
    }
}


void TWinCrypt::InitializeProvider(HCRYPTPROV Provider, const char* Container, DWORD Flags)
{
	FProvider         = Provider;
	FProviderAssigned = FProvider != 0;
	FKey              = NULL;
	if (!FProvider)
	{
		if (!Flags)
			Flags = CRYPT_VERIFYCONTEXT;
		pCryptAcquireContextA(&FProvider, Container, MS_ENHANCED_PROV_A, PROV_RSA_FULL, Flags);
    }
}


//--------------------------------------------------------
//  GenerateKey - Функция генерирует ключи с заданным
//                алгоритмом
//--------------------------------------------------------
bool TWinCrypt::GenerateKey(DWORD AlgId, DWORD Flags)
{
	DestroyKey();

	//DWORD Sz = 1024 << 16;
	return pCryptGenKey(FProvider, AlgId, Flags, &FKey) != FALSE;
}


//--------------------------------------------------------
//  Функция создаёт ключ RC4 на основе пароля.
//  Значение сохраняется в FKey;
//--------------------------------------------------------
bool TWinCrypt::CreateRC4Key(const char *Password)
{
	DestroyKey();

	if (FProvider && !STRA::IsEmpty(Password))
	{
		// Создаём хэш пароля
		HCRYPTHASH Hash = HashData(CALG_MD5, Password, STRA::Length(Password));
		pCryptDeriveKey(FProvider, CALG_RC4, Hash, 0, &FKey);
		pCryptDestroyHash(Hash);
	}

	return FKey != 0;
}


//---------------------------------------------------
//  Encrypt
//  Функция шифрует блок данных
//
//  Data
//    Буфер содержаший данные. Должен быть размером
//    достаточным для вмешения зашифрованных данных.
//
//  DataLen
//    Размер данных. После выполнения в этот параметр
//    будет записан результирующий размер данных
//
//  BufLen
//    Размер буфера. Должен быть достаточным для
//    вмещения зашифрованных данных
//    Узнать необходимы размер можно вызвав функйию
//    с нулевым буфером. Значение будет возвращено
//    в параметре DataLen
//
//  FinalBlock
//    Признак того, что это последний блок данных.
//    Необхдим для корректного завершения шифрования
//
//---------------------------------------------------
bool TWinCrypt::Encrypt(const void* Data, DWORD &DataLen, DWORD BufLen,  bool FinalBlock)
{
	if (FKey)
		return pCryptEncrypt(FKey, NULL, (BOOL)FinalBlock, (DWORD)0, (LPBYTE)Data, &DataLen, BufLen) != FALSE;
	else
		return false;
}

//---------------------------------------------------
//  Decrypt
//  Функция расшифровывает блок данных
//
//  Buf
//    Буфер содержаший данные. Должен быть размером
//    достаточным для вмешения зашифрованных данных.
//
//  DataLen
//    Размер данных. После выполнения в этот параметр
//    будет записан результирующий размер данных
//
//
//  FinalBlock
//    Признак того, что это последний блок данных.
//    Необхдим для корректного завершения шифрования
//
//---------------------------------------------------
bool TWinCrypt::Decrypt(const void* Data, DWORD &DataLen, bool FinalBlock)
{
	if (FKey)
		return pCryptDecrypt(FKey, (HCRYPTHASH)NULL, (BOOL)FinalBlock, (DWORD)0, (PCHAR)Data, &DataLen) != FALSE;
	else
        return FALSE;
}



//--------------------------------------------------------
//  Функция генерирует хэш указанных данных
//--------------------------------------------------------
HCRYPTHASH TWinCrypt::HashData(DWORD Algoritm, const void*  Data, DWORD DataLen)
{
	HCRYPTHASH Hash = 0;
	if (FProvider)
	{
		pCryptCreateHash(FProvider, Algoritm, NULL, 0, &Hash);
		if (Hash)
			pCryptHashData(Hash, (LPBYTE)Data, DataLen, 0);
	}

    return Hash;
}


//--------------------------------------------------------
//  DoExportKey - Функция экспортирует указанный ключ
//--------------------------------------------------------
//LPBYTE TWinCrypt::DoExportKey(HCRYPTKEY ExpKey, DWORD BlobType, DWORD *BufSize)
//{
//	DWORD  Size = 0;
//	LPBYTE Buf = NULL;
//
//	if (FKey)
//	{
//		// Лпределяем размер буфера
//		bool Ready = CryptExportKey(FKey, ExpKey, BlobType, 0, NULL, &Size) == TRUE;
//		if (Ready)
//		{
//			Buf = (LPBYTE)MemAlloc(Size);
//			CryptExportKey(FKey, ExpKey, BlobType, 0, Buf, &Size);
//        }
//	}
//
//	if (BufSize) *BufSize = Size;
//    return Buf;
//}

//--------------------------------------------------------
//  DoImportKey - Функция импортирует ключ
//--------------------------------------------------------
//bool TWinCrypt::DoImportKey(HCRYPTKEY ExpKey, DWORD BlobType, LPBYTE Buf, DWORD BufSize)
//{
//	if (!FProvider || !Buf || !BufSize)
//		return false;
//
//	DestroyKey();
//
//	return CryptImportKey(FProvider, Buf, BufSize, ExpKey, 0, &FKey) == TRUE;
//}



//--------------------------------------------------------
//  ExportPrivateKey - Функция экспортирует приватный ключ
//--------------------------------------------------------
//LPBYTE TWinCrypt::ExportPrivateKey(const char *ExpPassword, DWORD *BufSize)
//{
//	if (!FKey) return NULL;
//
//	TWinCrypt ExpKey(FProvider);
//	ExpKey.CreateRC4Key(ExpPassword);
//
//	return DoExportKey(ExpKey.Key(), PRIVATEKEYBLOB, BufSize);
//}


//--------------------------------------------------------
//  ExportPublicKey - Функция экспортирует публичный ключ
//--------------------------------------------------------
//LPBYTE TWinCrypt::ExportPublicKey(DWORD *BufSize)
//{
//	return DoExportKey(0, PUBLICKEYBLOB, BufSize);
//}


//--------------------------------------------------------
//  ImportPrivateKey - Функция импортирует приватный ключ
//--------------------------------------------------------
//bool TWinCrypt::ImportPrivateKey(const char *ExpPassword, LPBYTE Buf, DWORD BufSize)
//{
//	TWinCrypt ExpKey(FProvider);
//	ExpKey.CreateRC4Key(ExpPassword);
//
//	return DoImportKey(ExpKey.Key(), 0, Buf, BufSize);
//}


//--------------------------------------------------------
//  ImportPublicKey - Функция импортирует публичный ключ
//--------------------------------------------------------
//bool TWinCrypt::ImportPublicKey(LPBYTE Buf, DWORD BufSize)
//{
//	return DoImportKey(0, 0, Buf, BufSize);
//}



//--------------------------------------------------------
// Encode - Функция шифрует данные
// Data - Данные для шифрования
// DataSize - Размер данных.
// В случае успеха функция выделит память под шифрованный
// буфер и вернёт на него указатель. Размер буфера
// запишется в переменную DataSize
//--------------------------------------------------------
//LPBYTE TWinCrypt::Encode(LPBYTE Data, DWORD &DataSize)
//{
//	if (!FKey || !Data || !DataSize)
//		return NULL;
//
//	// Определяем размер результирующего буфера
//	DWORD NewSize = DataSize;
//	LPBYTE NewBuf = NULL;
//	BOOL Ready = (BOOL)pCryptEncrypt(FKey, NULL, TRUE, 0, NULL, &NewSize, NULL);
//	if (Ready)
//	{
//		NewBuf = (LPBYTE)MemAlloc(NewSize);
//		if (NewBuf)
//		{
//			m_memcpy(NewBuf, Data, DataSize);
//			Ready = (BOOL)CryptEncrypt(FKey, NULL, TRUE, 0, NewBuf, &DataSize, NewSize);
//			if (!Ready)
//			{
//				MemFree(NewBuf);
//				NewBuf = NULL;
//            }
//        }
//	}
//
//	DataSize = NewSize;
//    return NewBuf;
//}



//--------------------------------------------------------
//  Decode - функция расшифровывает данные.
//  Data - Указатель на блок шифрованных данных
//  DataSize - Размер буфера.
//  В случае успеха функция вернёт новый размер данных в
//  переменную DataSize
//--------------------------------------------------------
//bool TWinCrypt::Decode(LPBYTE Data, DWORD &DataSize)
//{
//	if (!FKey || !Data || !DataSize)
//		return false;
//    DWORD NewSize = DataSize;
//	bool Result = CryptDecrypt(FKey, NULL, TRUE, 0, Data, &NewSize) == TRUE;
//
//	if (Result)
//	{
//		if (NewSize < DataSize)
//            *(Data + NewSize) = 0;
//		DataSize = NewSize;
//
//    }
//
//    return Result;
//}



