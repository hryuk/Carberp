#include <windows.h>
#include <shlobj.h>

#include "res.h"

//#include <time.h>
//#include <stdio.h>
//#include "Strsafe.h"
#include <string>
#include "dprint.h"


HWND hDoneBtn;
TCHAR szFile[MAX_PATH * 2];
WCHAR *lpBuf;


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

  if (directory_length > (buffer_char_length - 1)) return;

  memmove(buffer, path, directory_length * sizeof(WCHAR));
  buffer[directory_length] = L'\0';
  *returned_char_length = directory_length;
}

std::wstring GetCurrentFileDir()
{
  WCHAR buffer[2 * MAX_PATH];
  DWORD buffer_char_length = ARRAYSIZE(buffer);
  DWORD returned_char_length = 0;

  DWORD path_length = GetModuleFileName(NULL, buffer, buffer_char_length);
  
  PP_RETURNIF2(path_length == buffer_char_length, L"");

  GetPathDirectory(buffer, path_length, buffer, buffer_char_length, 
    &returned_char_length);
  
  PP_RETURNIF2(returned_char_length == 0, L"");

  std::wstring result;

  result.append(buffer, returned_char_length);
  return result;
}

std::wstring AddSuffixToUrls(
  const WCHAR* urls, 
  DWORD  urls_char_length,
  const WCHAR* urls_suffix
  )
{
  std::wstring result;
  std::wstring src;

  src.append(urls, urls_char_length);
  while (src.length() > 0)
  {
    size_t       space_char_pos = src.find(L' ');
    std::wstring url = src.substr(0, space_char_pos);

    if (url.length() > 0)
    {
      result += url;
      result += urls_suffix;
      result += L" ";
    }

    src.erase(0, url.length() + 1);
  }

  result.erase(result.length() - 1, 1);

  return result;
}

void InjectToPeURLsSection(
  const WCHAR* target_path,
  const WCHAR* urls,
  DWORD        urls_char_length,
  const WCHAR* url_suffix
  )
{
  std::wstring suffix = url_suffix;
  if (suffix.find(L' ') != std::wstring::npos)
  {
    ::MessageBox(NULL, 
      L"Suffix contain invalid space characters.\r\n"
      L"Remove them and try again.",
      NULL, MB_OK);
    return;
  }

  std::wstring  urls_path;
  std::wstring  tool_path;
  std::wstring  new_urls = AddSuffixToUrls(urls, urls_char_length, url_suffix);

  urls_path = target_path;
  urls_path += L".urls";
  
  tool_path = GetCurrentFileDir();
  tool_path += L"WhiteJoeBuild.exe";  

  DWORD attr = GetFileAttributes(tool_path.c_str());
  if (attr == INVALID_FILE_ATTRIBUTES)
  {
    ::MessageBox(NULL, 
      L"WhiteJoeBuild.exe tool is not found!.\r\n"
      L"Please put it near the current tool.",
      NULL, MB_OK);
    return;
  }
  
  HANDLE h = ::CreateFile(urls_path.c_str(), GENERIC_WRITE, 0, 0, CREATE_ALWAYS, 0, NULL);
  if (h == INVALID_HANDLE_VALUE)
  {
    ::MessageBox(NULL, L"Cant create temp file for URLs.\r\n"
      L"Try to put destination file into directory with read-write accesss.",
      NULL, MB_OK);
    return;
  }
  
  DWORD data_size = ((new_urls.length() + 1) * sizeof(WCHAR));
  DWORD written = 0;
  WriteFile(h, new_urls.c_str(), data_size, &written, NULL);
  CloseHandle(h);

  if (written != data_size)
  {
    ::MessageBox(NULL, 
      L"Writing operation is failed. Try to check free space on disk.",
      NULL, MB_OK);
    return;
  }
  
  std::wstring command_line;

  //command_line += L"\"";
  //command_line += tool_path;
  //command_line += L"\"";  

  command_line += L" -AddFile URLs ";
  command_line += L"\"";
  command_line += urls_path;
  command_line += L"\"";

  command_line += L" -BuildExe ";
  command_line += L"\"";
  command_line += target_path;
  command_line += L"\"";

  command_line += L" ";
  command_line += L"\"";
  command_line += target_path;
  command_line += L".wjb_out";
  command_line += L"\"";

  
  PP_DPRINTF(L"BuilderExe: '%s' '%s'", tool_path.c_str(), command_line.c_str());
  DWORD result = (DWORD)::ShellExecute(NULL, L"open", tool_path.c_str(), command_line.c_str(), NULL, SW_HIDE);
  bool  run_ok = (result > 32);

  if (!run_ok) 
  {
    PP_DPRINTF(L"ShellExecute failed. tool='%s' param='%s'", tool_path.c_str(), command_line.c_str());
  };
}


BOOL CALLBACK DialogProc(HWND hWnd,UINT uMsg,WPARAM wParam,LPARAM lParam)
{
  switch (uMsg)
  {
    case WM_INITDIALOG:
    {
      hDoneBtn=GetDlgItem(hWnd,IDOK);

      if (wcslen(szFile) != 0) 
      {
        SetDlgItemText(hWnd,IDC_FILENAME,szFile);
        EnableWindow(hDoneBtn,TRUE);
      }
      return TRUE;
    }
    case WM_CLOSE:
    {
      EndDialog(hWnd,0);
      break;
    }
    case WM_COMMAND:
    {
      switch (wParam)
      {
        case IDCANCEL:
        {
          PostMessage(hWnd,WM_CLOSE,0,0);
          break;
        }
        case IDOK:
        {
          WCHAR suffix[200];
          DWORD suffix_length = 0;

          ZeroMemory(suffix, sizeof(suffix));
          suffix_length = GetDlgItemTextW(hWnd,IDC_URLS_SUFFIX,
            suffix,ARRAYSIZE(suffix) - 1);

          int dwSize=GetDlgItemTextW(hWnd,IDC_URLS,lpBuf,1024*1024);
          if (dwSize != 0)
          {
            InjectToPeURLsSection(szFile, lpBuf, dwSize, suffix);
          }
          //HANDLE hRes=BeginUpdateResource(szFile,FALSE);
          //UpdateResource(hRes,RT_RCDATA, MAKEINTRESOURCE(100), 0,lpBuf,(dwSize+1)*sizeof(WCHAR));
          //EndUpdateResource(hRes,FALSE);
        }
        break;

        case IDC_BROWSE:
        {
          TCHAR szFileName[MAX_PATH];
          szFileName[0]=0;
          OPENFILENAME ofn;

          memset(&ofn, 0, sizeof(ofn));

          ofn.lStructSize=sizeof(OPENFILENAME);
          ofn.hwndOwner=hWnd;
          ofn.lpstrFilter=TEXT("Библиотеки (*.dll)\0*.dll\0Программы (*.exe)\0*.exe\0Все файлы (*.*)\0*.*\0");
          ofn.Flags=OFN_HIDEREADONLY+OFN_PATHMUSTEXIST+OFN_FILEMUSTEXIST;
          ofn.nMaxFile=MAX_PATH;
          ofn.nFilterIndex=1;
          ofn.lpstrFile=szFileName;
          if (GetOpenFileName(&ofn))
          {
            SetDlgItemText(hWnd,IDC_FILENAME,szFileName);
            EnableWindow(hDoneBtn,TRUE);
            ZeroMemory(szFile, sizeof(szFile));
            lstrcpy(szFile,szFileName);
          }
          break;
        }
      }
      break;
    }
    break;
  }
  return FALSE;
}

int CALLBACK WinMain(
  __in  HINSTANCE hInstance,
  __in  HINSTANCE hPrevInstance,
  __in  LPSTR lpCmdLine,
  __in  int nCmdShow
)
{
  ZeroMemory(szFile, sizeof(szFile));

  int     argc=0;
  LPWSTR* argv=CommandLineToArgvW(GetCommandLineW(),&argc);

  if (argc > 1)
  {
    wcscat(szFile, argv[1]);
  }

  CoInitializeEx(NULL, COINIT_APARTMENTTHREADED | COINIT_DISABLE_OLE1DDE);

  lpBuf=(WCHAR *)malloc(1024*1024*sizeof(WCHAR));
  DialogBox(GetModuleHandle(NULL),MAKEINTRESOURCE(IDD_BUILDER),NULL,(DLGPROC)DialogProc);
  ExitProcess(0);
}

