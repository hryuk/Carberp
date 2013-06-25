#include <windows.h>

PVOID HookApi( DWORD DllNum, DWORD FuncHash, LPVOID ReplacementFunc );
PVOID HookApi( DWORD DllNum, DWORD FuncHash, LPVOID ReplacementFunc, PVOID FuncReal );
PVOID HookApi( const char* DllName, DWORD FuncHash, LPVOID ReplacementFunc, PVOID FuncReal );
PVOID HookApi2( DWORD Dll, DWORD FuncVA, DWORD ReplacementFunc );
//установка хука в нужной DllName модуля Module, т. е. модуль подгрузил DllName и прямо в таблице импорта
//делается подмена
bool PathIAT(PVOID Module,PCHAR DllName,PCHAR FuncName,PVOID NewHandler,PVOID *OldHandler);



//--------------------------------------------------------
// HookFunction
// Функция устанавливает хук на указанную функцию
//
// FunctionAddr - адрес функции, которую необходимо 
//                подменить
// NewFunctionAddr - адрес новой функции
// OriginalFunctionAddr - указатель на переменную, куда
// будет записан адрес сохранённой, оригинальной, функции
//--------------------------------------------------------
bool HookFunction(LPVOID FunctionAddr, LPVOID NewFunctionAddr, LPVOID *OriginalFunctionAddr);

//--------------------------------------------------------
//  HookApiEx 
//  Функция устанавливает хук на функцию
// 
//  DllNum           - Номер бибиотеки. см. GetApi.h
//  FuncHash         - Хэш имени функции
//  NewFunction      - Адрес новой функции
//  OriginalFunction - Переменная, куда будет записан 
//                     адрес оригинаьной функции
//--------------------------------------------------------
bool HookApiEx(DWORD DllNum, DWORD FuncHash, LPVOID NewFunction, LPVOID &OriginalFunction);