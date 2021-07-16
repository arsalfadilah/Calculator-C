#ifndef STRING_H
#define STRING_H

#include "stack.h"

typedef char* String;

/* Method Utama */
String input();
void DealokasiString(String *str);
int LengthStr(String str);
stack StrToInt(String str);

#endif