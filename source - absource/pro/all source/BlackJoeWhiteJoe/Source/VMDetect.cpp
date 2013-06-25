#include "VMDetect.h"

#include "Utils.h"
#include "Strings.h"

/*************************      Важно!!!      ************************/
/* Чтобы работали __try ... __except и при этом не линковался 
   стандартный CRT, необходимо отключить стандартные библиотеки 
   и указать линкеру зависимости от:
   exsup.lib (поддержка SEH из DDK) и libcmt.lib
   Через #pragma comment почему-то он их не находит, поэтому 
   приходится указывать в свойствах проекта
*/

//#pragma comment(lib, "..\sehlib\exsup.lib")
//#pragma comment(lib, "libcmt.lib")
//#pragma comment(linker, "/NODEFAULTLIB")


// Предопределение используемых локальных функций
static UINT GetSystemDir(char *szOutStr, UINT nSize);
//static bool DirectoryExists(const char *szDirName);
static bool CheckDir(const char *szRootDir, const char *szChildDir);
static bool CheckReg(const char *szSubKey, const char *szValue,
                     char *szOutBuf, int nBufSize);
//static bool _strstr(char *substr, char *str);


//*********************************************************************
// Детектит виртуалки и песочницы несколькими способами
bool DetectVM()
{
	#define BUF_SIZE 1024
	static char szBuf[BUF_SIZE] = {'\0'};
	if (!GetSystemDir(szBuf, MAX_PATH)) return true;

	if (CheckDir(szBuf, "prleth.sys")) return true;
	if (CheckDir(szBuf, "hgfs.sys")) return true;
	if (CheckDir(szBuf, "vmhgfs.sys")) return true;

	if (GetModuleHandle("dbghelp.dll")) return true;
	if (GetModuleHandle("sbiedll.dll")) return true;

	DWORD dwUsl = BUF_SIZE;
	if (!GetUserName(szBuf, &dwUsl)) return true;
	if (0 == lstrcmp(szBuf, "CurrentUser")) return true;
	if (0 == lstrcmp(szBuf, "Sandbox")) return true;

	dwUsl = BUF_SIZE;
	if (!GetComputerName(szBuf, &dwUsl)) return true;
	if (0 == lstrcmp(szBuf, "SANDBOX")) return true;

	if (!CheckReg("HARDWARE\\DESCRIPTION\\System",
								"SystemBiosVersion", szBuf, BUF_SIZE)) return true;
	if (STR::Pos("VBOX", szBuf)) return true;

	if (!CheckReg("HARDWARE\\DESCRIPTION\\System",
								"VideoBiosVersion", szBuf, BUF_SIZE)) return true;
	if (STR::Pos(szBuf, "VirtualBox") >= 0) return true;

	if (!CheckReg("SOFTWARE\\Microsoft\\Windows\\CurrentVersion",
								"SystemBiosVersion", szBuf, BUF_SIZE)) return true;
	if (STR::Pos(szBuf, "55274-640-2673064-23950") >= 0) return true;
	if (STR::Pos(szBuf, "76487-644-3177037-23510") >= 0) return true;
	if (STR::Pos(szBuf, "76487-337-8429955-22614") >= 0) return true;

	if (IsVPC()) return true;
	if (IsVMWare()) return true;
	
	return false;
}

//*********************************************************************
bool IsVMWare()
{
	bool res = true;

	__try {
		__asm
		{
			push   edx
			push   ecx
			push   ebx

			mov    eax, 'VMXh'
			mov    ebx, 0      // any value but not the MAGIC VALUE
			mov    ecx, 10     // get VMWare version
			mov    edx, 'VX'   // port number

			in     eax, dx     // read port
                         // on return EAX returns the VERSION
			cmp    ebx, 'VMXh' // is it a reply from VMWare?
			setz   [res]       // set return value

			pop    ebx
			pop    ecx
			pop    edx
		}
	} __except(EXCEPTION_EXECUTE_HANDLER) {
		res = false;
	}

	return res;
}

//*********************************************************************
// IsInsideVPC's exception filter
DWORD __forceinline IsInsideVPC_exceptionFilter(LPEXCEPTION_POINTERS ep)
{
  PCONTEXT ctx = ep->ContextRecord;

  ctx->Ebx = -1; // Not running VPC

  ctx->Eip += 4; // skip past the "call VPC" opcodes

  return EXCEPTION_CONTINUE_EXECUTION;
  // we can safely resume execution since we skipped faulty instruction
}

//*********************************************************************
bool IsVPC()
{
  bool res = false;

  __try
  {
    _asm push ebx
    _asm mov  ebx, 0 // It will stay ZERO if VPC is running

    _asm mov  eax, 1 // VPC function number


    // call VPC 

    _asm __emit 0Fh
    _asm __emit 3Fh
    _asm __emit 07h
    _asm __emit 0Bh

    _asm test ebx, ebx
    _asm setz [res]
    _asm pop ebx
  }
  // The except block shouldn't get triggered if VPC is running!!

  __except(IsInsideVPC_exceptionFilter(GetExceptionInformation()))
  {
  }

  return res;
}

/************************************************************************/
//bool directoryexists(const char *szdirname)
//{
//	int code = getfileattributes(szdirname);
//	return ((-1 != code) && (0 != (file_attribute_directory && code)));
//}

/************************************************************************/
UINT GetSystemDir(char *szOutStr, UINT nSize)
{
	UINT res = GetWindowsDirectory(szOutStr, nSize);
	if (res)
	{
		if (res > nSize)
		{
			res = 0;// Пришло символов больше, чем буфер  GSV - Возможно ли ???
		}
		else
		{
			int Idx = lstrlen(szOutStr);
			if ('\\' != szOutStr[Idx - 1])
			{
				lstrcat(szOutStr, "\\");
				res = lstrlen(szOutStr);
			}
		}
	}
	return res;
}

/************************************************************************/
bool CheckDir(const char *szRootDir, const char *szChildDir)
{
	static char szPath[MAX_PATH] = {'\0'};

	lstrcat(szPath, szRootDir);
	lstrcat(szPath, szChildDir);
	return DirExists(szPath);
}

/************************************************************************/
bool CheckReg(const char *szSubKey, const char *szValue,
              char *szOutBuf, int nBufSize)
{
	bool res = false;
	HKEY hkey = 0;

	if (ERROR_SUCCESS == RegCreateKey(HKEY_LOCAL_MACHINE, szSubKey, &hkey))
	{
		DWORD dwType = REG_SZ;
		DWORD dwSize = nBufSize;

		RegQueryValueEx(hkey, szValue, NULL, &dwType, (PBYTE)szOutBuf, &dwSize);
		RegCloseKey(hkey);
		res = true;
	}
	return res;
}

/************************************************************************/
//bool _strstr(char *substr, char *str)
//{
//	bool res = false;
//	int ln_sub = lstrlen(substr);
//	int ln_str = lstrlen(str);
//
//	for (int i = 0; i <= ln_str - ln_sub; i++)
//	{
//		int c = 0;
//		char *chk = &str[i];
//		for (int j = 0; j < ln_sub; j++)
//		{
//			if (substr[j] == chk[j])
//				c++;
//		}
//		if (c == ln_sub)
//			return true;
//	}
//	return res;
//}

