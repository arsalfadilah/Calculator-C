#include "CalculatorStandart.h"
#include "string.h"
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <math.h>

/* Method Utama Kalkulator Standar */
//penjumlahan a + b
double add(double a, double b)
{
    return a + b;
}
//pengurangan a - b
double substract(double a, double b)
{
    return a - b;
}
//perkalian a * b
double multiply(double a, double b)
{
    return a * b;
}
//pembagian a / b
double divide(double a, double b)
{
    if (b == 0)
    {
        printf("can't divide by zero return 0\n");
        return 0;
    }
    return a / b;
}
//perpangkatan a pangkat b (a^b)
double power(double a, double b)
{
    double result = a;
    int i = 1;
    if (b == 0)
    {
        return 1;
    }
    if (b < 0)
    {
        while (i - 2 > b)
        {
            result = result * a;
            i--;
        }
        result = 1 / result;
    }
    else
    {
        while (i < b)
        {
            result = result * a;
            i++;
        }
    }

    return result;
}

//modulo
double mod(double a, double b)
{
    return fmodf(a, b);
}

//pengakaran akar kuadrat dari a (a$)
double radix(double a)
{
    return sqrt(a);
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

//hasil dari perhitungan Prefix expression
double calculate(stack Postfix)
{
    //kamus
    stack result;
    createStack(&result);
    infotype forPeek;
    double a, b, res;
    //algoritma
    //Selama stack Postfix tidak kosong
    while (!isStackEmpty(Postfix))
    { //pop stack Postfix masukan ke forpeek
        pop(&Postfix, &forPeek);
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
                else if (forPeek.Operator == '%')
                {
                    res = mod(a, b);
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
void InfixToPostfix(stack *Postfix, stack infixed)
{
    //create stack
    stack operator, infix;
    createStack(&operator);
    stackcpy(&infix, infixed);
    //sebagai penampung operand atau operator
    infotype info, forPeek;
    String floatStr;
    double operand;
    int i = 0, tempIdx = 0, idxFloatStr = 0;
    //scan semua character di String infix
    while (!isStackEmpty(infix))
    {
        pop(&infix, &forPeek);
        //apakah forpeek.operator char kosong ?
        if (forPeek.Operator == '\0')
        { //iya, push kedalam stack postfix
            setOperand(&info, forPeek.Operand);
            push(&(*Postfix), info);
        }
        //tidak , apakah forpeek.operator adalah '(' ?
        else if (forPeek.Operator == '(')
        { //iya : push operator '(' ke stack operator
            setOperator(&info, forPeek.Operator);
            push(&operator, info);
        }
        //tidak, apakah forpeek.operator adalah ')' ?
        else if (forPeek.Operator == ')')
        { //iya : pop semua yang ada dalam tanda '( )'. misal : '(+-)'
            while (!isStackEmpty(operator) && peek(operator).Operator != '(')
            {
                pop(&operator, & info);
                push(&(*Postfix), info);
            }
            //apakah stack belum kosong namun top dari stack operator bukan '('
            if (!isStackEmpty(operator) && peek(operator).Operator != '(')
            { //iya : show error inputStr operator dan kembalikan NULL
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
            while (!isStackEmpty(operator) && Prec(forPeek.Operator) <= Prec(peek(operator).Operator))
            {
                pop(&operator, & info);
                push(&(*Postfix), info);
            }
            setOperator(&info, forPeek.Operator);
            push(&operator, info);
        }
    }
    //pop semua elem dari stack operator dan tempatkan di stack Postfix
    while (!isStackEmpty(operator))
    {
        pop(&operator, & info);
        push(&(*Postfix), info);
    }
    //reverse for acces in bottom
    reverseStack(&(*Postfix));
}

void InfixToPrefix(stack *Prefix, stack infix)
{
    stack temp, temp2;
    createStack(&temp2);
    infotype info;
    //copy dulu
    stackcpy(&temp, infix);
    //create reverse stack temp with
    //Replace ( with ) and vice versa
    while (!isStackEmpty(temp))
    {
        pop(&temp, &info);
        if (info.Operator == '(')
        {
            setOperator(&info, ')');
        }
        else if (info.Operand == ')')
        {
            setOperator(&info, '(');
        }
        push(&temp2, info);
    }
    //use infix to postfix make prefix
    InfixToPostfix(&(*Prefix), temp2);
    //reverse that for print bottom to top
    reverseStack(&(*Prefix));
}

/* Method Tambahan */
//memulai kalkultor standar
void runCalculatorStandar()
{
    //kamus
    char loop = 'y';
    double result;
    String infixStr;
    stack infix, Prefix, Postfix;
    createStack(&Prefix);
    createStack(&Postfix);
    createStack(&infix);
    //algoritma
    HoldCls();
    //keep calculator live untill user want to back
    while (loop == 'y' || loop == 'Y')
    {
        //tampil judul
        showTitleCalculatorStandar();
        //inputStr user
        printf("Input Operasi Matematika :\n");
        infixStr = inputStr();
        //Memeriksa apakah inputan benar
        if (isInfix(infixStr))
        {
            //tokenization string to stack
            infix = TokenizationCS(infixStr);
            //convert infix expression to Postfix
            InfixToPostfix(&Postfix, infix);
            //convert infix to prefix
            InfixToPrefix(&Prefix, infix);
            //calculate dari Postfix
            result = calculate(Postfix);
            //show result (rsult, Prefix and Postfix expression)
            showResult(result, infixStr, Prefix, Postfix);
        }
        else
        { // Jika inputan salah
            printf("Inputan salah! Mohon masukkan hanya angka dengan operatornya (+, -, *, dll.) tanpa spasi");
        }
        //request for reset
        printf("\n\nReset (y/t) ? ");
        scanf("%c", &loop);
        HoldCls();
        //before reset save terlebih dahulu
        saveCS(infixStr, result);
        //reset
        reset(&infixStr, &Postfix, &Prefix);
    }
}

void saveCS(String infix, double result)
{
    history hs;
    strcpy(hs.infix, infix);
    hs.result = result;
    strcpy(hs.type, "CS");
    reverseHystory();
    save(hs);
    reverseHystory();
}

void reset(String *infix, stack *posfix, stack *prefix)
{
    //dealokasi infix string after use
    DealokasiStr(&(*infix));
    //remove all stack
    removeAllStack(&(*posfix));
    removeAllStack(&(*prefix));
}

bool isNegatifOperandStr(String str, int tempIdx)
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
    printf("||               modulo :(%%)              ||\n");
    printf("|| 3. Tanpa spasi dan tab                 ||\n");
    printf("|| 4. Jika memasukan angka negatif        ||\n");
    printf("||    ('-angka/operand') seperti (-10)    ||\n");
    printf("============================================\n");
    printf("   Contoh : 1+2*(-3)-(8/4)^2$\n");
    printf("============================================\n\n");
}

void showResult(double result, String infix, stack Prefix, stack Postfix)
{
    //result from calculate
    printf("Result :\n");
    printf("%g\n", result);
    //show a result postfix and prefix
    printf("\nResult Infix :\n");
    printf("%s", infix);
    printf("\nResult Postfix :\n");
    cetakStack(Postfix);
    printf("\nResult Prefix :\n");
    cetakStack(Prefix);
}

/*        FILE HANDLING CALCULATOR        */
//menyimpan history ke dalam file
void save(history hs)
{
    FILE *file;
    if ((file = fopen("history.dat", "ab")) == NULL)
    {
        printf("Error opening file!\n");
        return;
    }
    fwrite(&hs, sizeof(history), 1, file);
    fclose(file);
}

//menampilkan semua history dari file
void showHystory()
{
    FILE *file;
    history hs;
    int i = 1, maxShow = 5, max = maxShow;
    char next = 'y';

    if ((file = fopen("history.dat", "rb")) == NULL)
    {
        printf("Error opening file!\n");
        return;
    }
    showTitleHistory();
   
    while (((fread(&hs, sizeof(history), 1, file)) == 1) && i <= maxShow)
    {
        printf("===(%s)===\n", hs.type);
        printf("| %d |\n", i);
        printf("Infix :\n");
        if(strcmp(hs.type, "CS")==0)
            printf("%s = %g\n", hs.infix, hs.result);
        else
            printf("%s = %g meter\n", hs.infix, hs.result);
        printf("==========\n");
        if (i == maxShow)
        {
            printf("Next (y/t) ? ");
            fflush(stdin);
            scanf("%c", &next);
            if (next == 'y' || next == 'Y')
            {
                maxShow += max;
                showTitleHistory();
            }
        }
        i++;
    }
    fclose(file);
}

void reverseHystory()
{
    FILE *file, *temp;
    history hs;
    history his[100];
    int i = 0, maxShow = 5, max =maxShow;
    char next = 'y';
    //buka dulu history.dat untuk memasukan ke dalam array history
    if ((file = fopen("history.dat", "rb")) == NULL)
    {
        printf("Error opening file history.dat!\n");
        return;
    }
    //masukan seluh data ke array histori
    while (((fread(&his[i], sizeof(history), 1, file)) == 1))
    {
        i++;
    }
    i--;
    //tutup file history.dat dan hapus content tersebut
    fclose(file = fopen("history.dat", "wb"));
    //buka temp.dat
    if((temp = fopen("temp.dat", "ab"))==NULL){
        printf("Error opening file history.dat!");
        return;
    }
    //masukan history dari idx terakhir array histori ke file temp.dat
    while(i>=0){
        fwrite(&his[i], sizeof(history), 1, temp);
        i--;
    }
    //tutup temp.dat
    fclose(temp);

    //copy file temp.dat ke histori.dat
    if ((temp = fopen("temp.dat", "rb")) == NULL)
    {
        printf("Error opening file history.dat!\n");
        return;
    }
    while (((fread(&hs, sizeof(history), 1, temp)) == 1))
    {
        save(hs);
    }
    //hapus temp.dat
    fclose(temp = fopen("temp.dat", "wb"));
}

void showTitleHistory()
{
    HoldCls();
    printf("============================================\n");
    printf("/** ====           HISTORY           === **/\n");
    printf(" Urutan : terbaru sampai terlama/\n");
    printf(" CS = Calculator Standar/Biasa\n");
    printf(" CM = Calculator Metric/Panjang\n");
    printf("============================================\n");
}