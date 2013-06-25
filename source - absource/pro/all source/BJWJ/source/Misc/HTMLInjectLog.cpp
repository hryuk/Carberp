
#ifndef HTMLInjectLogH
	#error Exclude module from project
#endif

//---------------------------------------------------------------------------

#pragma hdrstop

#include "HTMLInjectLog.h"
#include "BotHTTP.h"
#include "Utils.h"
//---------------------------------------------------------------------------


THTMLInjectLog::THTMLInjectLog(const string& URL, LPVOID Document, DWORD DocumentSize)
{
	FSource = NULL;
	FURL = URL;
	if (Document && DocumentSize)
	{
		FSource = new TBotMemoryStream();
		FSource->Write(Document, DocumentSize);
    }

}

THTMLInjectLog::~THTMLInjectLog()
{
	if (FSource)
		delete FSource;
}


//---------------------------------------------------
//  Close
//  Функция закрывает лог Записывая оба варианта
//  файла на диск
//---------------------------------------------------
void THTMLInjectLog::Close(LPVOID NewDocument, DWORD NewDocumentSize)
{
	string Path = HTMLINJECTLOG_WORKPATH;
	CreateDirectoryA(Path.t_str(), NULL);

	TURL URL(FURL.t_str());
	FDocument = URL.Document;
	if (FDocument.IsEmpty())
		FDocument = "Document";
	PCHAR Ext = STRA::Scan(FDocument.t_str(), '.');
	FExt = Ext;
	if (Ext) *Ext = 0;
	FDocument.CalcLength();

	// Создаём директорию
	string WorkPath = Path + FDocument + FExt;
	int Nomber = 1;
	while (DirExists(WorkPath.t_str()))
	{
		string N;
		N.LongToStr(Nomber);
		WorkPath = Path + FDocument;
		WorkPath += "[";
		WorkPath += N;
		WorkPath += "]";
		WorkPath += FExt;
        Nomber++;
    }
	CreateDirectoryA(WorkPath.t_str(), NULL);

	// записываем
	string URLFile  = CombineFileName(WorkPath.t_str(), "URL.txt");
	string Original = CombineFileName(WorkPath.t_str(), "Original.txt");
	string Injected = CombineFileName(WorkPath.t_str(), "Injected.txt");

	File::WriteBufferA(URLFile.t_str(), FURL.t_str(), FURL.Length());
	File::WriteBufferA(Original.t_str(), FSource->Memory(), FSource->Size());
	File::WriteBufferA(Injected.t_str(), NewDocument, NewDocumentSize);

	delete FSource;
	FSource = NULL;
}
