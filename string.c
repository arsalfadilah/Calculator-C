#include "string.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

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

int StrToInt(String str)
{
    int temp = 0, i = 0, idx = 0;
    int arrtemp = 0;
    bool flag = false;
    while (i < LengthStr(str) && !flag)
    {
        temp = str[i] - 48;
        arrtemp += temp;
        flag = (temp >= 0 && temp <= 9);
    }
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