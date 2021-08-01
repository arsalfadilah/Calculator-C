#include "string.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include "stack.h"

String inputStr()
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

void strcopy(String *destination, String Source)
{
    int i = 0;
    createString(&(*destination));
    while (Source[i] != '\0')
    {
        addChar(&(*destination), Source[i]);
        i++;
    }
}

//menghasilkan satu number double
double StrToDouble(String floatStr)
{
    //double FloatNum = atof(floatStr);
    //double FloatNum;
    //sscanf(floatStr, "%f", &FloatNum);
    return atof(floatStr);
}

void DealokasiStr(String *str)
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

stack TokenizationCS(String infixStr)
{
    stack infix;
    String operandStr;
    infotype info;
    double operand;
    int idx = 0, lengthInfix = LengthStr(infixStr);
    createStack(&infix);
    while (idx < lengthInfix)
    {
        createString(&operandStr);
        if (isOperand(infixStr[idx]))
        {
            while (isOperand(infixStr[idx]))
            {
                addChar(&operandStr, infixStr[idx]);
                idx++;
            }
            idx--;
            operand = StrToDouble(operandStr);
            setOperand(&info, operand);
        }
        else
        {
            if (isStrNegatifOperand(infixStr, idx))
            {
                idx += 2; //buang (-
                while (isOperand(infixStr[idx]))
                {
                    addChar(&operandStr, infixStr[idx]);
                    idx++;
                }
                //buang )
                operand = StrToDouble(operandStr);
                operand = operand * -1;
                setOperand(&info, operand);
            }
            else
            {
                setOperator(&info, infixStr[idx]);
            }
        }
        DealokasiStr(&operandStr);
        push(&infix, info);
        idx++;
    }
    //reverse for acces in bottom
    reverseStack(&infix);

    return infix;
}

stack TokenizationCP(String infixStr)
{
    stack infix, err;
    String operandStr;
    infotype info;
    double operand;
    int idx = 0, lengthInfix = LengthStr(infixStr);
    createStack(&infix);
    createStack(&err);
    while (idx < lengthInfix)
    {
        createString(&operandStr);
        if (isOperand(infixStr[idx]))
        {
            while (isOperand(infixStr[idx]))
            {
                addChar(&operandStr, infixStr[idx]);
                idx++;
            }
            if (!isSatuan(infixStr[idx]))
            {
                printf("Harap masukan satuannya, return 0");
                setOperand(&info, 0.0);
                push(&err, info);
                return err;
            }
            operand = StrToDouble(operandStr);
            setOperandCP(&info, operand, infixStr[idx]);
        }
        else if (isStrNegatifOperand(infixStr, idx))
        {
            idx += 2; //buang (-
            while (isOperand(infixStr[idx]))
            {
                addChar(&operandStr, infixStr[idx]);
                idx++;
            }
            //buang )
            if (!isSatuan(infixStr[idx]))
            {
                printf("Harap masukan satuannya, return 0");
                setOperand(&info, 0.0);
                push(&err, info);
                return err;
            }
            operand = StrToDouble(operandStr);
            operand = operand * -1;
            setOperandCP(&info, operand, infixStr[idx]);
        }
        else
        {
            setOperator(&info, infixStr[idx]);
        }
        DealokasiStr(&operandStr);
        push(&infix, info);
        idx++;
    }
    //reverse for acces in bottom
    reverseStack(&infix);

    return infix;
}

bool isSatuan(char inputan)
{
    if ((inputan == 'c') || (inputan == 'm') || (inputan == 'k'))
    {
        return true;
    }
    else
        return false;
}

bool isStrNegatifOperand(String str, int tempIdx)
{
    int lenghtStr = LengthStr(str);
    if (str[tempIdx] == '(')
    {
        tempIdx++;
        if (tempIdx < lenghtStr)
        {
            if (str[tempIdx] == '-')
            {
                tempIdx++;
                while (tempIdx < lenghtStr)
                {
                    if (isOperator(str[tempIdx]))
                    {
                        if (str[tempIdx] == ')')
                        {
                            return true;
                        }
                        return false;
                    }
                    tempIdx++;
                }
            }
        }
    }
    return false;
}