#ifndef STRING_H
#define STRING_H

//#include "stack.h"

typedef char* String;

/* Method Utama */
String input();
void DealokasiString(String *str);
int LengthStr(String str);
//menghasilkan satu numbe float
float StrToFloat(String floatStr);
//menghasilkan banyak angka float
//stack StrToFloatStack(String str);

#endif