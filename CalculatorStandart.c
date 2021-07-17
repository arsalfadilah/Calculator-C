#include "CalculatorStandart.h"
#include <stdio.h>
#include <stdlib.h>
#include "string.h"

/* Method Utama Kalkulator Standar */
//penjumlahan a + b
float add(float a, float b)
{
    return a + b;
}
//pengurangan a - b
float substract(float a, float b)
{
    return a - b;
}
//perkalian a * b
float multiply(float a, float b)
{
    return a * b;
}
//pembagian a / b
float divide(float a, float b)
{
    return a / b;
}
//perpangkatan a pangkat b (a^b)
float power(float a, float b)
{
    float result = a;
    int i = 1;
    while (i < b)
    {
        result = result * a;
        i++;
    }

    if (b == 0)
    {
        return 1;
    }

    return result;
}
//pengakaran akar kuadrat dari a (a$)
float radix(float a)
{
}
// sisa bagi dari a bagi b (a%b)
float modulus(float a, float b)
{
    //int a, b;
}

//cek apakah ch operand atau bukan
bool isOperand(char ch)
{
    return ((ch >= '0' && ch <= '9') || ch == '.');
}

int Prec(char ch)
{
    switch (ch)
    {
    case '+':
    case '-':
        return 1;

    case '*':
    case '/':
        return 2;

    case '^':
    case '$':
        return 3;
    }
    return -1;
}

// Convert infix to postfix
void InfixToPostfix(stack *postfix, String infix)
{
    //create stack
    stack operator;
    //createStack(&(*postfix));
    createStack(&operator);
    //sebagai penampung operand atau operator
    infotype info;
    String floatStr;
    int i=0, tempIdx = 0, idxFloatStr = 0;
    //scan semua character di String infix
    while (i < LengthStr(infix))
    {
        //apakah infix[i] adalah operand (0-9 atau '.') ?
        if (isOperand(infix[i]))
        {   //iya : alokasi string untuk convert string number ke float number
            floatStr = (String) malloc(1 * sizeof(char));
            //looping sampai ketemu bukan operand menandakan angka berakhir
            while (isOperand(infix[i]))
            {
                floatStr[idxFloatStr] = infix[i];
                idxFloatStr++;
                i++;
                realloc(floatStr, idxFloatStr * sizeof(char));
            }
            i--;
            idxFloatStr = 0;
            //push setiap operand dan jadikan operator \0
            info.Operator = '\0';
            info.Operand = StrToFloat(floatStr);
            push(&(*postfix), info);
            //dealoksi string setelah dipakai
            DealokasiString(&floatStr);
        }
        //apakah infix ke i adalah '(' ?
        else if (infix[i] == '(')
        {//iya : push operator '(' ke stack operator
            info.Operator = infix[i];
            push(&operator, info);
        }
        //apakah infix yang ke i adalah ')' ?
        else if (infix[i] == ')')
        {//iya : pop semua yang ada dalam tanda '( )'. misal : '(+-)'
            while (!isStackEmpty(operator) && peek(operator).Operator != '(')
            {
                pop(&operator, & info);
                push(&(*postfix), info);
            }
            //apakah stack belum kosong namun top dari stack operator bukan '('
            if (!isStackEmpty(operator) && peek(operator).Operator != '(')
            {//iya : show error input operator dan kembalikan NULL
                printf("Wrong Input Operators\n");
                //return;
            }
            else
            {//tidak : keluarkan '(' dari stack operator
                pop(&operator, &info);
            }
        }
        else
        {// tidak : looping selama stack tidak kosong 
         // untuk menyimpan operator dengan urutan operasi matematics yang benar 
         // (lihat prec untuk mengetahui level setiap operator)
            while (!isStackEmpty(operator) && Prec(infix[i]) <= Prec(peek(operator).Operator))
            {
                pop(&operator, &info);
                push(&(*postfix), info);
            }
            info.Operand = 0;
            info.Operator = infix[i];
            push(&operator, info);
        }
        i++;
    }
    //pop semua elem dari stack operator dan tempatkan di stack postfix
    while (!isStackEmpty(operator))
    {
        pop(&operator, &info);
        push(&(*postfix), info);
    }
    //dealokasi stack operator
    dealokasi(operator.top);
}

/* Method Tambahan */
//memulai kalkultor standar
void runCalculatorStandar()
{
    //tampil judul
    stack postfix;
    createStack(&postfix);
    printf("============================\n");
    printf("CALCULATOR STANDAR TEAM NINE\n");
    printf("============================\n");
    //input user
    printf("Input :\n");
    String infix = input();
    //convert infix expression to posfix
    InfixToPostfix(&postfix, infix);
    //convert postfix to prefix : (reverser the postfix expression)

    //calculate

    //show a result
    printf("result Postfix : \n");
    cetakStack(postfix);
    //dealokasi infix string after use
    DealokasiString(&infix);
}