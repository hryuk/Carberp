#include <stdio.h>
#include <windows.h>

int main()
{
 char fncname[]="VirtualProtect";

 DWORD lf=strlen(fncname); //@S
 DWORD summ=0;
 DWORD humm=0;             //@E

 for (DWORD w=0;w<lf;w++) { /*@S;*/summ+=fncname[w]; humm+=fncname[w/2]/*@E*/; }

 if (lf > 41) return;                                          //@S
 DWORD hash = /*@S+*/lf*100000000 + summ*10000 + humm/*@E*/;   //@E

 printf("hash:%u func|lf:%u *100000000|summ:%u *10000|humm:%u|%s|",hash,lf,summ,humm,fncname);
}