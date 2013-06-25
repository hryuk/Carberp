#ifndef HunterH
#define HunterH
//----------------------------------------------------------------------------
#include <windows.h>

//void IsBankHunter( HINTERNET hRequest );
//void StartHunt();
//DWORD WINAPI RunHuntThred( LPVOID lpData );
//void Hunting();


// Максимальный размер буфера для хранения ссылок (включая нулевые символы)
#define HUNTER_PARAM_SIZE  2048
#define HUNTER_PARAM_NAME  "__URL__HUNTER__LINKS\0"
#define HUNTER_PARAM_ENCRYPTED true


namespace URLHunter
{
	// Инициализируем данные хантера
	void Initialize();

	// Запускаем клиент ожидание события охотника
	// Возможен запуск в другом процессе
    void StartClient();

	// Проверить совпадение ссылки с любой ссылкой из списка ссылок охотника
    void CheckURL(PCHAR URL);
}

//----------------------------------------------------------------------------
#endif