#ifndef _SPLICE_H_
#define _SPLICE_H_

#define JMP_SIZE		5
#define	OLD_BYTES_SIZE	20

VOID Splice(PVOID pvAddr,PVOID pvNew,PVOID pvOldAddr);
VOID Unsplice(PVOID pvAddr,PVOID pvOldAddr);

#endif
