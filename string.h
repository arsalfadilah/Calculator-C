#ifndef STRING_H
#define STRING_H

#include "stack.h"
#include <stdbool.h>

typedef char* String;

/* Method Utama */
// memasukan nilai string
/* I.S String masih kosong
    I.F String sudah berisi nilai
*/
void createString(String *str);

String input();

void DealokasiString(String *str);

int LengthStr(String str);

//menghasilkan satu numbe double
double StrToFloat(String floatStr);

void addChar(String *destination, char ch);

void strcopy(String *destination, String Source);

stack TokenizationCP(String infixStr);

stack TokenizationCS(String infixStr);

bool isStrNegatifOperand(String str, int tempIdx);

bool isSatuan(char inputan);

#endif