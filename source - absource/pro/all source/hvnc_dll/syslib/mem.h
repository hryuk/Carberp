#ifndef MEM_H_INCLUDED
#define MEM_H_INCLUDED

extern "C" void *MemAlloc(size_t dwSize);
extern "C" void *MemRealloc(void *lpMem,size_t dwSize);
extern "C" void MemFree(void *lpMem);

void MemInit();
void MemCleanup();

#define BLOCK_ALLOCED 0xABBABABA
#define BLOCK_FREED   0xDEADBEEF

#define HEAP_LFH 2

#endif // MEM_H_INCLUDED
