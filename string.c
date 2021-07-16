#include "string.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

void DealokasiString(String *str)
{
    (*str) = NULL;
    free((*str));
}