// SkypeSMS.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#import "Skype4COM.dll" 

int _tmain(int argc, _TCHAR* argv[])
{
  if( argc != 3 )
  {
	  printf("1\nNeeded two params: phone and text message");
	  return 0;
  }
  CoInitialize(NULL); 
  
   // Создаем Skype объект 
   SKYPE4COMLib::ISkypePtr pSkype(__uuidof(SKYPE4COMLib::Skype)); 
   if( !pSkype->Client->IsRunning )
   {
	   pSkype->Client->Start(1, 1);
	   while(!pSkype->Client->IsRunning)
		   Sleep(1000);
   }
   pSkype->Attach(6,VARIANT_TRUE); 
   try
   {
	   SKYPE4COMLib::ISmsMessagePtr sms = pSkype->SendSms(argv[1], argv[2], "");
       int res = sms->GetStatus();
       while(res == SKYPE4COMLib::smsTargetStatusDeliveryPending) Sleep(1000);
	   if( res == SKYPE4COMLib::smsTargetStatusDeliverySuccessful )
	       printf("0");
	   else
           printf("1\n%d", (int)res);
       sms = NULL;
   }
   catch(_com_error& e)
   {
	   printf("1\n");
	   printf(e.Description());
   }
   // Удаляем соединения со скайп 
   pSkype = NULL; 

   CoUninitialize(); 
   return 0;
}

