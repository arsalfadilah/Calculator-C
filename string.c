#include "string.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include "stack.h"
#include "CalculatorStandart.h"

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

stack StrToInt(String str)
{
    stack integer;
    infotype info;
    createStack(&integer);
    int temp = 0;
    int i = 0, idx = 0;
    float result = 0;
    bool flag = true;
    while (i < LengthStr(str))
    {
        temp = str[i] - 48;
        printf("\n%d", temp);
        flag = (temp >= 0 && temp <= 9);
        if(flag){
            result = (temp) + power(10.0, idx) * result;
            idx++;
            printf("\n%.2f\n", result);
        }
        else{
            info.Operand = result;
            push(&integer, info);
            idx = 0;
        }
        i++;
    }

    info.Operand = result;
    push(&integer, info);

    return integer;
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