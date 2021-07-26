#include "CalculatorStandart.h"
#include "string.h"
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <math.h>

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
    return sqrt(a);
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

bool isInfix(String infix)
{
    int i = 0;
    // inisialisasi charOfInfix untuk menyimpan banyak karakter pada infix
    int charOfInfix = LengthStr(infix);
    if (charOfInfix == 0)
        return false;
    // iterasi untuk pengecekan tiap index
    while (i < charOfInfix)
    {
        if (infix[i] == ' ')
            return false;
        else if (((infix[i] >= 'a') && (infix[i] <= 'z')) || ((infix[i] >= 'A') && (infix[i] <= 'Z')))
            return false;
        else if ((!isOperand(infix[i])) && (!isOperator(infix[i])))
            return false;

        i++;
    }
    return true;
}

void setOperand(infotype *info, float x)
{
    (*info).Operand = x;
    (*info).Operator = '\0';
}

void setOperator(infotype *info, char operator)
{
    (*info).Operand = 0;
    (*info).Operator = operator;
}

void getOperandWithPop(stack *s, float *x)
{
    infotype info;
    pop(&(*s), &info);
    *x = info.Operand;
}

void getTwoOperandWithPop(stack *s, float *a, float *b)
{
    getOperandWithPop(&(*s), &(*b));
    getOperandWithPop(&(*s), &(*a));
}

//hasil dari perhitungan Prefix expression
float calculate(stack Prefix)
{
    //kamus
    stack result;
    createStack(&result);
    infotype forPeek;
    float a, b, res;
    //algoritma
    //Selama stack Prefix tidak kosong
    while (!isStackEmpty(Prefix))
    { //pop stack Prefix masukan ke forpeek
        pop(&Prefix, &forPeek);
        //apakah bukan operator ?
        if (!isOperator(forPeek.Operator))
        { //jika ya, (berarti operand) maka push operand ke dalam stack result
            push(&result, forPeek);
        }
        //jika tidak
        else
        { //apakah forpeek baian operator bukan tanda akar ($)
            if (forPeek.Operator != '$')
            { //jika ya, dapatkan 2 operand dengan pop stack result dua kali
                getTwoOperandWithPop(&result, &a, &b);
                //pemilihan operator yang sesuai agar dapat dilakukan operasi
                if (forPeek.Operator == '+')
                {
                    res = add(a, b);
                }
                else if (forPeek.Operator == '-')
                {
                    res = substract(a, b);
                }
                else if (forPeek.Operator == '*')
                {
                    res = multiply(a, b);
                }
                else if (forPeek.Operator == '/')
                {
                    res = divide(a, b);
                }
                else if (forPeek.Operator == '^')
                {
                    res = power(a, b);
                }
                else
                {
                    printf("Ilegal Argument");
                    return 0;
                }
            }
            else
            { //jika tanda akar maka get operand dengan satu kali pop stack result, kemudian hitung
                getOperandWithPop(&result, &a);
                res = radix(a);
            }
            //set default infotype bagian operand diisi oleh res dan operator '\0'
            setOperand(&forPeek, res);
            //push ke stack result
            push(&result, forPeek);
        }
    }
    //element terakhir di stack result akan menjadi hasil dari perhitungan
    pop(&result, &forPeek);
    return (forPeek.Operand);
}

int Prec(char ch)
{ //memilih tingkat derajat prioritas operasi
    switch (ch)
    {
    case '+':
    case '-':
        return 1;

    case '*':
    case '/':
    case '%':
        return 2;

    case '^':
    case '$':
        return 3;
    }
    return -1;
}

// Convert infix to Postfix
void InfixToPostfix(stack *Postfix, String infix)
{
    //create stack
    stack operator;
    createStack(&operator);
    //sebagai penampung operand atau operator
    infotype info;
    String floatStr;
    //char floatStr[20];
    float operand;
    int i = 0, tempIdx = 0, idxFloatStr = 0;
    //scan semua character di String infix
    while (i < LengthStr(infix))
    {
        //apakah infix[i] adalah operand (0-9 atau '.') ?
        if (isOperand(infix[i]))
        { //iya : alokasi string untuk convert string number ke float number
            createString(&floatStr);
            //looping sampai ketemu bukan operand menandakan angka berakhir
            while (isOperand(infix[i]))
            {
                addChar(&floatStr, infix[i]);
                i++;
            }
            i--;
            //convert string to float number
            operand = StrToFloat(floatStr);
            setOperand(&info, operand);
            push(&(*Postfix), info);
            //dealoksi string setelah dipakai
            DealokasiString(&floatStr);
        }
        //apakah infix ke i adalah '(' ?
        else if (infix[i] == '(')
        { //iya : push operator '(' ke stack operator
            setOperator(&info, infix[i]);
            push(&operator, info);
        }
        //apakah infix yang ke i adalah ')' ?
        else if (infix[i] == ')')
        { //iya : pop semua yang ada dalam tanda '( )'. misal : '(+-)'
            while (!isStackEmpty(operator) && peek(operator).Operator != '(')
            {
                pop(&operator, & info);
                push(&(*Postfix), info);
            }
            //apakah stack belum kosong namun top dari stack operator bukan '('
            if (!isStackEmpty(operator) && peek(operator).Operator != '(')
            { //iya : show error input operator dan kembalikan NULL
                printf("Wrong Input Operators\n");
                return;
            }
            else
            { //tidak : keluarkan '(' dari stack operator
                pop(&operator, & info);
            }
        }
        else
        { // tidak : looping selama stack tidak kosong
            // untuk menyimpan operator dengan urutan operasi matematik yang benar (lihat prec untuk mengetahui level setiap operator)
            while (!isStackEmpty(operator) && Prec(infix[i]) <= Prec(peek(operator).Operator))
            {
                pop(&operator, & info);
                push(&(*Postfix), info);
            }
            setOperator(&info, infix[i]);
            push(&operator, info);
        }
        i++;
    }
    //pop semua elem dari stack operator dan tempatkan di stack Postfix
    while (!isStackEmpty(operator))
    {
        pop(&operator, & info);
        push(&(*Postfix), info);
    }
    //dealokasi stack operator
    dealokasi(operator.top);
}

void InfixToPrefix(stack *Prefix, String infix)
{
    String temp;
    //copy dulu
    strcopy(&temp, infix);
    //reverse temp infix
    strrev(temp);
    //add char
    addChar(&temp, ')');
    //use infix to postfix for make prefix
    InfixToPostfix(&(*Prefix), temp);
    DealokasiString(&temp);
}

/* Method Tambahan */
//memulai kalkultor standar
void runCalculatorStandar()
{
    //kamus
    char loop = 'y';
    float result;
    String infix;
    stack Prefix, Postfix;
    createStack(&Prefix);
    createStack(&Postfix);
    //algoritma
    HoldCls();
    //keep calculator live untill user want to back
    while (loop == 'y' || loop == 'Y')
    {
        //tampil judul
        showTitleCalculatorStandar();
        //input user
        printf("Input Infix Expression :\n");
        infix = input();
        //Memeriksa apakah inputan benar
        if (isInfix(infix))
        {
            //convert infix expression to Postfix
            InfixToPostfix(&Postfix, infix);
            //convert infix to prefix
            InfixToPrefix(&Prefix, infix);
            //reverse stack postfix aga bisa dibaca dari bottom
            reverseStack(&Postfix);
            //calculate dari Postfix
            result = calculate(Postfix);
            //show result (rsult, Prefix and Postfix expression)
            showResult(result, Prefix, Postfix);
        }
        else
        { // Jika inputan salah
            printf("Inputan salah! Mohon masukkan hanya angka dengan operatornya (+, -, *, dll.) tanpa spasi");
        }
        //request for reset
        printf("\n\nreset (y/t) ? ");
        scanf("%c", &loop);
        HoldCls();
        //dealokasi infix string after use
        DealokasiString(&infix);
        //remove all stack
        removeAllStack(&Postfix);
        removeAllStack(&Prefix);
    }
}

/* Method UI Calculator */
void HoldCls()
{
    printf("\n");
    system("pause");
    system("cls");
}

void showTitleCalculatorStandar()
{
    printf("||    ||    ||    ||    ||    ||    ||    ||\n");
    printf("============================================\n");
    printf("||            CALCULATOR STANDAR          ||\n");
    printf("||        By TEAM NINE Made With Love     ||\n");
    printf("============================================\n");
    printf("||              ATURAN PAKAI              ||\n");
    printf("|| 1. Tidak menggunakan alfabet           ||\n");
    printf("|| 2. Memakai Operator yang ada           ||\n");
    printf("||    tambah:(+)|kurang :(-)|kali:(*)     ||\n");
    printf("||    bagi  :(/)|pangkat:(^)|akar:($)     ||\n");
    printf("|| 3. Tanpa spasi dan tab                 ||\n");
    printf("============================================\n");
    printf("   Contoh : 1+2*3-(8/4)^2$\n");
    printf("============================================\n\n");
}

void showResult(float result, stack Prefix, stack Postfix)
{
    printf("Result :\n");
    printf("%.2f\n", result);
    //show a result
    printf("\nResult Postfix :\n");
    cetakStack(Postfix);
    printf("\nResult Prefix :\n");
    cetakStack(Prefix);
}