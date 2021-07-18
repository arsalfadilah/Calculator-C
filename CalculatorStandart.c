#include "CalculatorStandart.h"
#include "string.h"
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

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

//hasil dari perhitungan postfix expression
float calculate(stack postfix){
    //1. peek terlebih dahulu stack postfix
    //  1.1 jika operand masukan ke stack result
    //  1.2 jika operator
    //      1.2.1 jika '+'
    //          1.2.1.1 pop dari stack result dan simpan info operand ke variabel b
    //          1.2.1.2 pop dari stack result dan simpan info operand ke varibel a
    //          1.2.1.3 dapatkan hasil dari add(a, b) kemudian push kembali ke stack result
    //      1.2.2 lakukan hal yang sama jika operasi '-', '*', '/', '^'
    //      1.2.3 untuk operasi akar (misal : 5$ dibaca akar kuadrat dari 5)
    //          1.2.3.1 pop dari stack result dan simpan info operand ke var a
    //          1.2.3.2 dapatkan hasil dari radix(a) kemudian push ke stack result
    //2. lakukan hal 1 sampai stack posfix kosong
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
                return;
            }
            else
            {//tidak : keluarkan '(' dari stack operator
                pop(&operator, &info);
            }
        }
        else
        {// tidak : looping selama stack tidak kosong 
         // untuk menyimpan operator dengan urutan operasi matematik yang benar 
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

//convert postfix to prefix
void PostfixToPrefix(stack *prefix, stack postfix){
    infotype info;
    while (!isStackEmpty(postfix))
    {
        pop(&postfix, &info);
        push(&(*prefix), info);
    }
}

/* Method Tambahan */
//memulai kalkultor standar
void runCalculatorStandar()
{
    //tampil judul
    HoldCls();
    printf("============================\n");
    printf("CALCULATOR STANDART TEAM NINE\n");
    printf("============================\n");
    //buat stack postfix agar mudah langsung di calculate
    stack postfix, prefix, tempPostfix;
    createStack(&postfix);
    createStack(&prefix);
    //input user
    printf("Input Infix Expression :\n");
    String infix = input();
    //convert infix expression to posfix
    InfixToPostfix(&postfix, infix);
    //copy agar postfix bisa di print lagi
    stackcpy(&tempPostfix, postfix);
    //convert postfix to prefix : (reverser the postfix expression)
    PostfixToPrefix(&prefix, tempPostfix);
    //calculate
    // . . . (belum ada haha)
    //show a result
    printf("result Postfix :\n");
    cetakStack(postfix);
    printf("Result Prefix :\n");
    cetakStack(prefix);
    HoldCls();
    //dealokasi infix string after use
    DealokasiString(&infix);
}

/* Method UI */
void HoldCls(){
    printf("\n");
    system("pause");
    system("cls");
}