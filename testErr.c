#include <stdio.h>
#include <Windows.h>
#include "string.h"
#include "stack.h"
#include "CalculatorStandart.h"
int main()
{
   stack postfix;
   float res;
   String apa_saja;
   createString(&apa_saja);
   addChar(&apa_saja, 'a');
   addChar(&apa_saja, 'r');
   addChar(&apa_saja, 's');
   addChar(&apa_saja, 'a');
   addChar(&apa_saja, 'l');
   addChar(&apa_saja, ' ');
   addChar(&apa_saja, 'f');
   addChar(&apa_saja, 'a');
   addChar(&apa_saja, 'd');
   addChar(&apa_saja, 'i');
   addChar(&apa_saja, 'l');
   addChar(&apa_saja, 'a');
   addChar(&apa_saja, 'h');
   addChar(&apa_saja, ' ');
   addChar(&apa_saja, 'g');
   addChar(&apa_saja, 'a');
   addChar(&apa_saja, 'n');
   addChar(&apa_saja, 't');
   addChar(&apa_saja, 'e');
   addChar(&apa_saja, 'n');
   addChar(&apa_saja, 'g');
   printf("hasilnya : %s\n", apa_saja);
   
   system("pause");
   return 0;
}