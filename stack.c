#include "stack.h"
#include "string.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

address alokasi(infotype x)
{
    ElemStack *p;

    //Algoritma
    p = (ElemStack *)malloc(sizeof(ElemStack));
    if (p != NULL)
    {
        p->info = x;
        p->next = NULL;
        return p;
    }
    else
    {
        printf("gagal alokasi stack");
        return NULL;
    }
}

void dealokasi(address p)
{
    p = NULL;
    free(p);
}

void push(stack *s, infotype x)
{
    address p, q;

    p = alokasi(x);
    if (isStackEmpty(*s))
    {
        (*s).top = p;
    }
    else
    { // Stack tidak kosong
        p->next = (*s).top;
        (*s).top = p;
    }
}

void pop(stack *s, infotype *x)
{
    //Kamus
    address pTOP, tmp2;
    //Algoritma
    if (!isStackEmpty(*s))
    {
        pTOP = (*s).top;
        *x = pTOP->info;
        if (pTOP->next == NULL)
        { // hanya ada 1 elemen
            (*s).top = NULL;
        }
        else
        { // lebih dari satu elemen
            (*s).top = pTOP->next;
        }
        dealokasi(pTOP->next);
    }else{
        //default
        (*x).Operand = 0;
        (*x).Operator ='\0';
    }
}

void removeAllStack(stack *s){
   infotype temp;
    while (!isStackEmpty(*s))
    {
        pop(&(*s), &temp);
    }
}

void cetakStack(stack s)
{
    address p;
    infotype temp = s.top->info;

    //Algoritma
    if (!isStackEmpty(s))
    {
        p = s.top;
        while (p != NULL)
        {
            //print info disini
            if (p->info.Operator == '\0')
            {
                printf("%g ", p->info.Operand);
            }
            else
            {
               printf("%c ", p->info.Operator);
            }
            p = p->next;
        }
    }
    else
    {
        printf("[ Empty ]");
    }
}

bool isStackEmpty(stack s)
{
    if (s.top == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void createStack(stack *s)
{
    (*s).top = NULL;
}

void stackcpy(stack *destination, stack source)
{
    ElemStack *p, *q;
    infotype tempInfo = source.top->info;
    stack tempStack;
    createStack(&tempStack);
    createStack(&(*destination));
    //Algoritma
    if (!isStackEmpty(source))
    {
        p = source.top;
        push(&tempStack, p->info);
        p = p->next;
        while (p != NULL)
        {
            push(&tempStack, p->info);
            p = p->next;
        }
        while (!isStackEmpty(tempStack))
        {
            pop(&tempStack, &tempInfo);
            push(&(*destination), tempInfo);
        }
    }
    else
    {
        printf("[ Empty ]");
    }
}

//peek top element
infotype peek(stack s)
{
    return s.top->info;
}

void reverseStack(stack *s)
{
    stack temp;
    infotype info;
    stackcpy(&temp, *s);
    while (!isStackEmpty(*s))
    {
        pop(&(*s), &info);
    }
    while (!isStackEmpty(temp))
    {
        pop(&temp, &info);
        push(&(*s), info);
    }
}

void setOperator(infotype *info, char operator)
{
    (*info).Operand = 0;
    (*info).Operator = operator;
}

bool isOperator(char ch)
{
    switch (ch)
    {
    case '+':
    case '-':
    case '*':
    case '/':
    case '^':
    case '$':
    case '%':
    case '(':
    case ')':
        return true;
    }
    return false;
}

//cek apakah ch operand atau bukan
bool isOperand(char ch)
{
    return ((ch >= '0' && ch <= '9') || ch == '.');
}

void setOperand(infotype *info, double x)
{
    (*info).Operand = x;
    (*info).Operator = '\0';
}

void getOperandWithPop(stack *s, double *x)
{
    infotype info;
    pop(&(*s), &info);
    *x = info.Operand;
}

void getTwoOperandWithPop(stack *s, double *a, double *b)
{
    getOperandWithPop(&(*s), &(*b));
    getOperandWithPop(&(*s), &(*a));
}

void setOperandCP(infotype *info, double operand, char satuan)
{
    switch (satuan)
    {
    case 'c':
        operand = operand/100;
        break;
    case 'm':
        break;
    case 'k':
        operand = operand*1000;
        break;
    default:
        printf("Something wrong!\n");
        break;
    }
    setOperand(&(*info), operand);
}
