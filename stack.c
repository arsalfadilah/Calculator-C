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
    /* I.S : S terdefinisi, Stack tidak kosong
   F.S : Menghapus elemen pada top(s)
*/

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
        printf("[ %.2f ]", p->info.Operand);
        p = p->next;
        while (p != NULL)
        {
            printf(" - [ %.2f ]", p->info.Operand);
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
    //Mengirimkan true jika stack kosong, false jika tidak

    //Kamus

    //ALgoritma
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
    /* I.S : S terdefinisi, tidak diketahui nilainya
   F.S : S diinisialisasi top(s) = nil,
*/

    //Kamus

    //Algoritma
    (*s).top = NULL;
}