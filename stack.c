#include "stack.h"
#include <stdlib.h>
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
        return NULL;
    }
}

void dealokasi(address p)
{
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
    int out;

    //Algoritma
    pTOP = (*s).top;
    *x = pTOP->info;
    if (pTOP->next == NULL)
    { // hanya ada 1 elemen
        (*s).top = NULL;
    }
    else
    { // lebih dari satu elemen
        (*s).top = pTOP->next;
        pTOP->next = NULL;
    }
}

void cetakStack(stack s)
{
    ElemStack *p, *q;
    infotype temp = s.top->info;

    //Algoritma
    printf("isi stack dari mulai TOP s.d. BOTTOM : \n");
    if (!isStackEmpty(s))
    {
        p = s.top;
        printf("[ operator : %c | operand : %.2f ]\n", p->info.Operator, p->info.Operand);
        p = p->next;
        while (p != NULL)
        {
            printf("[ operator : %c | operand : %.2f ]\n", p->info.Operator, p->info.Operand);
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
    //printf("isi stack dari mulai TOP s.d. BOTTOM : \n");
    if (!isStackEmpty(source))
    {
        p = source.top;
        //printf("[ operator : %c | operand : %.2f ]\n", p->info.Operator, p->info.Operand);
        push(&tempStack, p->info);
        p = p->next;
        while (p != NULL)
        {
            //printf("[ operator : %c | operand : %.2f ]\n", p->info.Operator, p->info.Operand);
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