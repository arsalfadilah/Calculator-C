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

stack StrToFloatStack(String str)
{
    stack integer;
    String tempStr = (String)malloc(1 * sizeof(char));
    infotype info;
    createStack(&integer);
    int temp = 0, i = 0, idx = 0;
    float result = 0;
    bool flag = true;
    while (i < LengthStr(str))
    {
        temp = str[i] - 48;
        flag = ((temp >= 0 && temp <= 9) || temp == -2);
        if (flag)
        {
            tempStr[idx] = str[i];
            idx++;
            realloc(tempStr, idx * sizeof(char));
        }
        else
        {
            info.Operand = atof(tempStr);
            push(&integer, info);
            DealokasiString(&tempStr);
            idx = 0;
            tempStr = (String)malloc(1 * sizeof(char));
        }
        i++;
    }
    info.Operand = atof(tempStr);
    push(&integer, info);
    DealokasiString(&tempStr);

    return integer;
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
    return strlen(str);
}