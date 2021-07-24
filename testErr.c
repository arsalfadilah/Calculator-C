#include <stdio.h>
#include <Windows.h>
#include "string.h"
int main()
{
   String str;
   printf("Test String\n");
   alokasiStr(&str, "a");
   //char *ch = "a";
   //strcpy(str, ch);

   // alokasiStr(&str, 'r');
   printf("ini : %s", str);


   return 0;
}