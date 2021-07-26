#include "string.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include "stack.h"

String input()
{
    String str, newAlloc;
    char c;
    int i = 0;
    fflush(stdin);
    newAlloc = (String)malloc(1 * sizeof(char));
    if (newAlloc != NULL)
    {
        str = newAlloc;
    }
    else
    {
        printf("gagal alokasi :(");
    }
    while (c = getc(stdin), c != '\n')
    {
        str[i] = c;
        i++;
        newAlloc = realloc(str, (i + 1) * sizeof(char));
        if (newAlloc != NULL)
        {
            str = newAlloc;
        }
        else
        {
            printf("\nTak dapat realloc\n");
        }
    }
    str[i] = '\0';
    return str;
}

void createString(String *str)
{
    String new = (String)malloc(sizeof(char));
    if (new != NULL)
    {
        (*str) = new;
        (*str)[0] = '\0';
    }
    else
    {
        printf("Gagal alokasi");
    }
}

void addChar(String *destination, char ch)
{
    int idx = LengthStr(*destination);
    String new;
    (*destination)[idx] = ch;
    idx++;
    new = realloc((*destination), (idx + 1) * sizeof(char));
    if (new != NULL)
    {
        (*destination) = new;
        (*destination)[idx] = '\0';
    }
    else
    {
        printf("Gagal realokasi :(");
    }
}

void strcopy(String *destination, String Source){
    int i=0;
    createString(&(*destination));
    while (Source[i]!='\0')
    {
        addChar(&(*destination), Source[i]);
        i++;
    }
}

//menghasilkan satu number float
float StrToFloat(String floatStr)
{
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
    if (str[0] == '\0')
        return 0;
    return strlen(str);
}