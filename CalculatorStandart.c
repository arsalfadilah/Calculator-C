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

//hasil dari perhitungan postfix expression
float calculate(stack postfix)
{
    //1. peek terlebih dahulu stack postfix
    stack result;
    createStack(&result);
    infotype forPeek;
    float a, b, res;

    //  1.1 jika operand masukan ke stack result
    while (!isStackEmpty(postfix))
    {
        pop(&postfix, &forPeek);
        if (!isOperator(forPeek.Operator))
        {
            push(&result, forPeek);
        }
        //  1.2 jika operator
        else
        {
            if (forPeek.Operator != '$')
            {
                getTwoOperandWithPop(&result, &a, &b);
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
            {
                getOperandWithPop(&result, &a);
                res = radix(a);
            }
            setOperand(&forPeek, res);
            push(&result, forPeek);
        }
    }
    pop(&result, &forPeek);
    return (forPeek.Operand);
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
    case '%':
        return 2;

    case '^':
    case '$':
        return 3;
    }
    return -1;
}

// Convert infix to prefix
void InfixToPrefix(stack *prefix, String infix)
{
    //create stack
    stack operator;
    createStack(&operator);
    //sebagai penampung operand atau operator
    infotype info;
    String floatStr;
    float operand;
    int i = 0, tempIdx = 0, idxFloatStr = 0;
    //scan semua character di String infix
    while (i < LengthStr(infix))
    {
        //apakah infix[i] adalah operand (0-9 atau '.') ?
        if (isOperand(infix[i]))
        { //iya : alokasi string untuk convert string number ke float number
            floatStr = (String)malloc(1 * sizeof(char));
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
            //convert string to float number
            operand = StrToFloat(floatStr);
            setOperand(&info, operand);
            push(&(*prefix), info);
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
                push(&(*prefix), info);
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
                push(&(*prefix), info);
            }
            setOperator(&info, infix[i]);
            push(&operator, info);
        }
        i++;
    }
    //pop semua elem dari stack operator dan tempatkan di stack prefix
    while (!isStackEmpty(operator))
    {
        pop(&operator, & info);
        push(&(*prefix), info);
    }
    //dealokasi stack operator
    dealokasi(operator.top);
}

//convert postfix to prefix
void PostfixToPrefix(stack *prefix, stack postfix)
{
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
    char loop = 'y';
    HoldCls();
    
    //keep calculator live untill user want to back
    while (loop == 'y' || loop == 'Y')
    {
        //tampil judul
        showTitleCalculatorStandar();
        //buat stack postfix agar mudah langsung di calculate
        stack postfix, prefix;
        createStack(&postfix);
        createStack(&prefix);
        
        //input user
        printf("Input Infix Expression :\n");
        String infix = input();

        //Memeriksa apakah inputan benar
        if (isInfix(infix)){
            //convert infix expression to prefix
        InfixToPrefix(&prefix, infix);
        //copykan
        stackcpy(&postfix, prefix);
        //reverse stack agar terbaca postfix
        reverseStack(&postfix);
        //calculate dari prefix
        float result = calculate(postfix);
        //show result (rsult, postfix and prefix expression)
        showResult(result, postfix, prefix);
        }

        // Jika inputan salah
        else printf("Inputan salah! Mohon masukkan hanya angka dengan operatornya (+, -, *, dll.) tanpa spasi");

        
        //request for reset
        printf("\n\nreset (y/t) ? ");
        scanf("%c", &loop);
        HoldCls();
        //dealokasi infix string after use
        DealokasiString(&infix);
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
    printf("============================\n");
    printf("CALCULATOR STANDAR TEAM NINE\n");
    printf("============================\n");
    printf("        ATURAN PAKAI\n");
    printf("1. Tidak menggunakan alfabet\n");
    printf("2. Memakai Operator yang ada\n");
    printf("\ttambah\t : +\n");
    printf("\tkali\t : *\n");
    printf("\tkurang\t : -\n");
    printf("\tbagi\t : /\n");
    printf("\tpangkat\t : ^\n");
    printf("\takar\t : $\n");
    printf("3. Tanpa spasi dan tab\n");
    printf("============================\n");
    printf("Contoh : 1+2*3-(8/4)^2$\n");
    printf("============================\n\n");
}

void showResult(float result, stack postfix, stack prefix)
{
    printf("Result :\n");
    printf("%.2f\n", result);
    //show a result
    printf("\nResult Postfix :\n");
    cetakStack(postfix);
    printf("\nResult Prefix :\n");
    cetakStack(prefix);
}

bool isInfix(String infix){
    int i = 0;
    // inisialisasi charOfInfix untuk menyimpan banyak karakter pada infix
    int charOfInfix = LengthStr(infix);
    if (charOfInfix == 0) return false;
    // iterasi untuk pengecekan tiap index
        while (i < charOfInfix){
            if (infix[i] == ' ') return false;
            else if (((infix[i] >= 'a') && (infix[i] <= 'z')) || ((infix[i] >= 'A') && (infix[i] <= 'Z'))) return false;
            else if ((!isOperand(infix[i])) && (!isOperator(infix[i]))) return false;
            
        i++;
        }
        return true;
}