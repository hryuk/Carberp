#include "stdafx.h"
#include "processes.h"


PROCESSENTRY32W* GetProcesses(DWORD* COUNT)
{
    HANDLE hSnapshot;
    PROCESSENTRY32W Entry;
    PROCESSENTRY32W* Entries = NULL;

    // создаем моментальный снимок
    hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    if (hSnapshot == INVALID_HANDLE_VALUE)
        return NULL;

    // получаем информацию о первом процессе
    Entry.dwSize = sizeof(Entry);
    if (!Process32First(hSnapshot, &Entry))
        return NULL;

    // перечисляем остальные процессы
	int count = 0;
    do
    {
		Entries = (PROCESSENTRY32W*)realloc(Entries, (++count) * sizeof(PROCESSENTRY32W));
		memcpy(Entries+(count-1), &Entry, sizeof(PROCESSENTRY32W));

        Entry.dwSize = sizeof(Entry);
    }
    while (Process32Next(hSnapshot, &Entry));
    CloseHandle(hSnapshot);
	
	*COUNT = count;
	return Entries;
}