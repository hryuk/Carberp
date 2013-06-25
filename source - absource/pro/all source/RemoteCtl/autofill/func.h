#ifndef FUNC_H_INCLUDED
#define FUNC_H_INCLUDED

int CalcFuncCRC32i(byte *data);
int CalcFuncCRC32(byte *data);
bool WildCmp(WCHAR *lpMask,WCHAR *lpStr,int *dwDataSize);
#define PAGE_SIZE 1024*4

#endif // FUNC_H_INCLUDED
