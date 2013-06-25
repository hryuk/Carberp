#include <windows.h>
#include <stdio.h>
#pragma warning(push)
#pragma warning(disable:4005)
#include "ntdll.h"
#pragma warning(pop)

#include "splice.h"
#include "zdisasm.h"
#include "utils.h"

VOID CreateJump(PVOID pvFrom,PVOID pvTo,PBYTE pbJmp)
{
	pbJmp[0] = (UCHAR)0xE9;

	*(PDWORD)((DWORD)pbJmp + 1) = (DWORD)pvTo - (DWORD)pvFrom - 5;
}

VOID Splice(PVOID pvAddr,PVOID pvNew,PVOID pvOldAddr)
{
	BYTE bBuffer[JMP_SIZE];
	DWORD dwSum = 0;
	DWORD dwLen = 0;
	DWORD Bytes;

	VirtualProtect(pvOldAddr,OLD_BYTES_SIZE,PAGE_EXECUTE_READWRITE,&Bytes);

	while (dwSum < JMP_SIZE)
	{
		GetInstLength((PDWORD)((DWORD)pvAddr + dwSum),&dwLen);

		RtlCopyMemory((PVOID)((DWORD)pvOldAddr + dwSum),(PVOID)((DWORD)pvAddr + dwSum),dwLen);

		if (*(PBYTE)((DWORD)pvOldAddr + dwSum) == 0xE8 || *(PBYTE)((DWORD)pvOldAddr + dwSum) == 0xE9)
		{
			*(PDWORD)((DWORD)pvOldAddr + dwSum + 1) -= ((DWORD)pvOldAddr + dwSum) - ((DWORD)pvAddr + dwSum);
		}

		USHORT w = MAKEWORD(*(PBYTE)((DWORD)pvOldAddr + dwSum + 1),*(PBYTE)((DWORD)pvOldAddr + dwSum));

		if ((w & 0xFFF0) == 0xF80)
		{
			*(PDWORD)((DWORD)pvOldAddr + dwSum + 2) -= ((DWORD)pvOldAddr + dwSum) - ((DWORD)pvAddr + dwSum);
		}

		dwSum += dwLen;
	}

	CreateJump((PVOID)((DWORD)pvOldAddr + dwSum),(PVOID)((DWORD)pvAddr + dwSum),(PBYTE)((DWORD)pvOldAddr + dwSum));

	CreateJump(pvAddr,pvNew,bBuffer);

	if (!WriteProcessMemory(NtCurrentProcess(),pvAddr,bBuffer,JMP_SIZE,&Bytes))
	{
		DbgPrint(__FUNCTION__"(): WriteProcessMemory failed with error %lx\n",GetLastError());
	}
}

VOID Unsplice(PVOID pvAddr,PVOID pvOldAddr)
{
	if (*(PBYTE)((DWORD)pvOldAddr) == 0xE8 || *(PBYTE)((DWORD)pvOldAddr) == 0xE9)
	{
		*(PDWORD)((DWORD)pvOldAddr + 1) += ((DWORD)pvOldAddr) - ((DWORD)pvAddr);
	}

	USHORT w = MAKEWORD(*(PBYTE)((DWORD)pvOldAddr + 1),*(PBYTE)((DWORD)pvOldAddr));

	if ((w & 0xFFF0) == 0xF80)
	{
		*(PDWORD)((DWORD)pvOldAddr + 2) += ((DWORD)pvOldAddr) - ((DWORD)pvAddr);
	}

	DWORD Bytes;

	if (!WriteProcessMemory(NtCurrentProcess(),pvAddr,pvOldAddr,JMP_SIZE,&Bytes))
	{
		DbgPrint(__FUNCTION__"(): WriteProcessMemory failed with error %lx\n",GetLastError());
	}
}