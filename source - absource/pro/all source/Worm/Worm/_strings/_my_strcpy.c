
///////////////////////////////////////////////////////////////
// my strcpy function ////////////////////////////////////////

//algo here is not optimal, becouse this code often used by mcafee as signature

void my_strcpy(char *s1,char *s2) 
{

 DWORD q=0;

 loop:;
  s1[q]=s2[q];
 if (/*@S!=*/s2[q]!=0/*@E*/) { q++; goto loop; }

}
