#include <stdio.h>
#include <Windows.h>
#include "string.h"
int main()
{
   String str;
   //char ch = '12';
   createString(&str);
   printf("Test String\n");
   // /printf("char 2 digit : %c", ch);
   addStr(&str, 'a');
   addStr(&str, 'r');
   addStr(&str, 'z');
   addStr(&str, 'i');
   addStr(&str, 'i');
   addStr(&str, 'a');
   printf("INi STRING : %s\n", str);
   system("pause");
   return 0;
}