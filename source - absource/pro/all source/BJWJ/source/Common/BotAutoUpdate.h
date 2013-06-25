//---------------------------------------------------------------------------

#ifndef BotAutoUpdateH
#define BotAutoUpdateH
//---------------------------------------------------------------------------


#include "Strings.h"
#include "BotClasses.h"


//************************************************************
//	TBotUpdater - Класс автоматического обновления бота
//************************************************************
class TBotUpdater : public TBotThread
{
private:
	void Update(DWORD &UpdateInterval);
	void DownloadAndSetup(const string &FileURL, const string &MD5);
protected:
    void DoExecute();
public:
	DWORD Interval;
    TBotUpdater();

};


//--------------------------------------------------
//  StartAutoUpdate - функция запускает
//  автоматическое обновление бота
//--------------------------------------------------
void StartAutoUpdate();



//---------------------------------------------------------------------------
#endif
