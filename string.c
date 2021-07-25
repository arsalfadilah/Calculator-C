#include "string.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include "stack.h"

String input()
{
    String str;
    char c;
    int i = 0;
    str = (String)malloc(1 * sizeof(char));
    fflush(stdin);
    while (c = getc(stdin), c != '\n')
    {
        str[i] = c;
        i++;
        realloc(str, i * sizeof(char));
    }
    str[i] = '\0';
    return str;
}

//menghasilkan satu number float
float StrToFloat(String floatStr){
    float FloatNum = atof(floatStr);
    return FloatNum;
}

void DealokasiString(String *str)
{
    (*str) = NULL;
    free((*str));
}

int LengthStr(String str)
{
    if(str[0]=='\0')
        return 0;
    return strlen(str);
}