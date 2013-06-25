
//---------------------------------------------------------------------------
//  Всомогательы модуль для логировани результатов HTML инжектов
//  Модуль подключается через систему Modules.h
//---------------------------------------------------------------------------

#if defined(DEBUGCONFIG) && !defined(HTMLInjectLogH)
#define HTMLInjectLogH
//---------------------------------------------------------------------------

#include <Windows.h>
#include "GetApi.h"
#include "BotClasses.h"


#define HTMLINJECTLOG_WORKPATH "c:\\HtmlInjectLog\\"


class THTMLInjectLog : public TBotObject
{
private:
	string FURL;
	string FDocument;
	string FExt;
	TBotMemoryStream* FSource;
public:
   THTMLInjectLog(const string& URL, LPVOID Document, DWORD DocumentSize);
   void Close(LPVOID NewDocument, DWORD NewDocumentSize);
   ~THTMLInjectLog();
};

#endif
