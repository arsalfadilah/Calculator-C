#include "CalculatorPanjang.h"
#include "CalculatorStandart.h"
#include "string.h"
#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// convert meter to centimeter
centimeter MeterToCentimeter(meter m)
{
    return m * 100;
}
// convert meter to kilometer
kilometer MeterToKilometer(meter m)
{
    return m / 1000;
}
// convert centimeter to kilometer
meter CentimeterToMeter(centimeter cm)
{
    return cm / 100;
}
// convet kilometer to meter
meter KilometerToMeter(kilometer km)
{
    return km * 1000;
}
// convert meter to hektometer
hektometer MeterToHektometer(meter m)
{
    return m * 0.01;
}
// convert meter to dekameter
dekameter MeterToDekameter(meter m)
{
    return m * 0.1;
}
// convert meter to deimeter
desimeter MeterToDesimeter(meter m)
{
    return m * 10;
}
//convert meter to milimeter
milimeter MeterToMilimeter(meter m)
{
    return m * 1000;
}

/* Method Tambahan */
void runCalculatorPanjang()
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
        showTitleCalculatorPanjang();
        //inputStr user
        printf("Input Infix Expression :\n");
        infixStr = inputStr();
        //Memeriksa apakah inputan benar
        if (isInfixCP(infixStr))
        {
            //tokenization string to stack
            infix = TokenizationCP(infixStr);
            //convert infix expression to Postfix
            InfixToPostfix(&Postfix, infix);
            //convert infix to prefix
            InfixToPrefix(&Prefix, infix);
            //calculate dari Postfix
            result = calculate(Postfix);
            //show result (rsult, Prefix and Postfix expression)
            showResultCP(result, Postfix, Prefix);
        }
        else
        { // Jika inputan salah
            printf("Inputan salah! Mohon masukkan hanya angka beserta satuannya dengan operatornya (+, -, *, dll.) tanpa spasi");
        }
        //request for reset
        fflush(stdin);
        printf("\nReset (y/t) ? ");
        scanf("%c", &loop);
        HoldCls();
        //before reset we save to file
        saveCP(infixStr, result);
        //reset for use back
        reset(&infixStr, &Postfix, &Prefix);
    }
}

void saveCP(String infix, double result)
{
    history hs;
    strcpy(hs.infix, infix);
    hs.result = result;
    strcpy(hs.type, "CM");
    save(hs);
}

void showTitleCalculatorPanjang()
{
    printf("||    ||    ||    ||    ||    ||    ||    ||\n");
    printf("============================================\n");
    printf("||            CALCULATOR METRIC           ||\n");
    printf("||        By TEAM NINE Made With Love     ||\n");
    printf("============================================\n");
    printf("||              ATURAN PAKAI              ||\n");
    printf("|| 1. Setiap angka diikuti satuannya      ||\n");
    printf("||    satuan yang sah adalah :            ||\n");
    printf("||     centimeter(c)|meter(m)|kilometer(k)||\n");
    printf("||    alfabet selain itu, tidak sah       ||\n");
    printf("|| 2. Memakai Operator yang ada           ||\n");
    printf("||     tambah(+)|kali(*)   |kurang(-)     ||\n");
    printf("||     bagi(/)  |pangkat(^)|akar($)       ||\n");
    printf("||               modulo(%%)                ||\n");
    printf("|| 3. Tanpa spasi atau tab                ||\n");
    printf("|| 4. Jika memasukan angka negatif        ||\n");
    printf("||    ('-angka/operand') seperti (-10)    ||\n");
    printf("============================================\n");
    printf("   Contoh : (-1m)+2c*3m-(8c/4c)^2k$         \n");
    printf("============================================\n\n");
}

void showResultCP(double result, stack postfix, stack prefix)
{
    char convert;
    int pilih = -1;
    printf("Result :\n");
    printf("%g meter\n", result);
    //show a result
    printf("\nResult Postfix (meter) :\n");
    cetakStack(postfix);
    printf("\nResult Prefix (meter) :\n");
    cetakStack(prefix);

    //ask for convet metric
    fflush(stdin);
    printf("\n\nConvert (y/t) ? ");
    scanf("%c", &convert);
    if (convert == 'y' || convert == 'Y')
    {
        while (pilih != 0)
        {
            switch (pilih = convertSatuan())
            {
            case 1:
                printf("%g kilometer\n", MeterToKilometer(result));
                break;
            case 2:
                printf("%g hektometer\n", MeterToHektometer(result));
                break;
            case 3:
                printf("%g dekameter\n", MeterToDekameter(result));
                break;
            case 4:
                printf("%g desimeter\n", MeterToDesimeter(result));
                break;
            case 5:
                printf("%g centimeter\n", MeterToCentimeter(result));
                break;
            case 6:
                printf("%g milimeter\n", MeterToMilimeter(result));
                break;
            default:
                break;
            }
        }
    }
}

int convertSatuan()
{
    int choose;
    printf("\nConvert to :\n");
    printf("(1)kilometer (2)hektometer (3)dekameter\n");
    printf("(4)desimeter (5)centimeter (6)milimeter\n(0)back\n");
    printf("Choose : ");
    while (scanf("%d", &choose) != 1 && getchar() != '\n')
    {
        printf("! ONLY INTEGER ! ==> ");
    }
    return choose;
}

bool isInfixCP(String infix)
{
    int i = 0;
    // inisialisasi charOfInfix untuk menyimpan banyak karakter pada infix
    int charOfInfix = LengthStr(infix);

    // iterasi untuk pengecekan tiap index
    while (i < charOfInfix)
    {
        if ((infix[i] == ' ') ||
            (((infix[i] != 'c') && (infix[i] != 'm') && (infix[i] != 'k')) &&
             ((!isOperand(infix[i])) && (!isOperator(infix[i])))))
            return false;

        i++;
    }
    return true;
}