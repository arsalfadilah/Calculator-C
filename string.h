#ifndef STRING_H
#define STRING_H

//#include "stack.h"

typedef char* String;

/* Method Utama */
// memasukan nilai string
/* I.S String masih kosong
    I.F String sudah berisi nilai
*/
String input();

void DealokasiString(String *str);

int LengthStr(String str);

//menghasilkan satu numbe float
float StrToFloat(String floatStr);

#endif