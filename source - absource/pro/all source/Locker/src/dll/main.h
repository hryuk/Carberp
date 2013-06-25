#ifndef UUID_99358A7C5BC24EC9B802D249AC3343C5
#define UUID_99358A7C5BC24EC9B802D249AC3343C5

#include <tlhelp32.h>

bool ProcessFilter_IE(const PROCESSENTRY32* ppe);
bool ProcessFilter_NonIE(const PROCESSENTRY32* ppe);
bool ProcessFilter_Explorer(const PROCESSENTRY32* ppe);
bool ProcessFilter_Notepad(const PROCESSENTRY32* ppe);
bool ProcessFilter_Winlogon(const PROCESSENTRY32* ppe);

void* GetUrlsSection(DWORD* section_length);

#endif