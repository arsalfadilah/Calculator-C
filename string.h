#ifndef STRING_H
#define STRING_H

typedef char* String;

/* Method Utama */
String input();
void DealokasiString(String *str);
int LengthStr(String str);
int StrToInt(String str);

#endif