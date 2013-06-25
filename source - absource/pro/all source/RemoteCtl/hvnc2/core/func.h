#ifndef FUNC_H_INCLUDED
#define FUNC_H_INCLUDED

void *malloc(size_t dwSize);
void *realloc(void *lpMem,size_t dwSize);
void free(void *lpMem);

LPVOID memcpy(void *dst,const void *src,size_t count);

void RemoveFileA(char *lpFile);

#endif // FUNC_H_INCLUDED
