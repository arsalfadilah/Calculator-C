#include "CalculatorPanjang.h"
#include "CalculatorStandart.h"
#include "string.h"
#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

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
hektometer MeterToHektometer(meter m){
    return m * 0.01;
}
// convert meter to dekameter
dekameter MeterToDekameter(meter m){
    return m * 0.1;
}
// convert meter to deimeter
desimeter MeterToDesimeter(meter m){
    return m*10;
}
//convert meter to milimeter
milimeter MeterToMilimeter(meter m){
    return m*1000;
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

void InfixToPrefixCP(stack *prefix, String infix)
{
    //create stack
    stack operator;
    createStack(&operator);
    //sebagai penampung operand atau operator
    infotype info;
    String floatStr;
    float m, cm, km;
    int panjangStr = LengthStr(infix);
    int i = 0, tempIdx = 0, idxFloatStr = 0;
    //scan semua character di String infix
    while (i < LengthStr(infix))
    {
        //apakah infix[i] adalah operand (0-9 atau '.') ?
        if (isOperand(infix[i]) || isSatuan(infix[i]))
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
            if (isSatuan(infix[i]))
            {
                if (infix[i] == 'c')
                {
                    //convet str to float
                    cm = StrToFloat(floatStr);
                    //convet centimeter to meter
                    m = CentimeterToMeter(cm);
                }
                else if (infix[i] == 'k')
                {
                    //convet str to float
                    km = StrToFloat(floatStr);
                    //convet centimeter to meter
                    m = KilometerToMeter(km);
                }
                else
                {
                    m = StrToFloat(floatStr);
                }
            }
            else
            {
                printf("Mohon libatkan satuannya\n");
                return;
            }
            idxFloatStr = 0;
            //push setiap operand dan jadikan operator \0
            info.Operator = '\0';
            info.Operand = m;
            push(&(*prefix), info);
            //dealoksi string setelah dipakai
            DealokasiString(&floatStr);
        }
        //apakah infix ke i adalah '(' ?
        else if (infix[i] == '(')
        { //iya : push operator '(' ke stack operator
            info.Operator = infix[i];
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
            // untuk menyimpan operator dengan urutan operasi matematik yang benar
            // (lihat prec untuk mengetahui level setiap operator)
            while (!isStackEmpty(operator) && Prec(infix[i]) <= Prec(peek(operator).Operator))
            {
                pop(&operator, & info);
                push(&(*prefix), info);
            }
            info.Operand = 0;
            info.Operator = infix[i];
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

/* Method Tambahan */
void runCalculatorPanjang()
{
    char loop = 'y';
    HoldCls();
    //keep calculator live untill user want to back
    while (loop == 'y' || loop == 'Y')
    {
        //tampil judul
        showTitleCalculatorPanjang();
        //buat stack postfix agar mudah langsung di calculate
        stack postfix, prefix;
        createStack(&postfix);
        createStack(&prefix);
        //input user
        printf("Input Infix Expression :\n");
        String infix = input();
        
        if(isInfixCP(infix)){
            //convert infix expression to prefix
        InfixToPrefixCP(&prefix, infix);
        //copykan
        stackcpy(&postfix, prefix);
        //reverse stack agar terbaca postfix
        reverseStack(&postfix);
        //calculate dari prefix
        float result = calculate(postfix);
        //show result
        showResultCP(result, postfix, prefix);
        }
        // Jika inputan salah
        else printf("Inputan salah! Mohon masukkan hanya angka dengan operatornya (+, -, *, dll.) tanpa spasi");

        //request for reset
        fflush(stdin);
        printf("\nreset (y/t) ? ");
        scanf("%c", &loop);
        HoldCls();
        //dealokasi infix string after use
        DealokasiString(&infix);
    }
}

void showTitleCalculatorPanjang()
{
    printf("============================\n");
    printf("CALCULATOR METRIC TEAM NINE\n");
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
    printf("4. Setiap angka diikuti satuannya,\n   satuan yang sah adalah :\n");
    printf("\tcentimeter : c\n");
    printf("\tmeter      : m\n");
    printf("\tkilometer  : k\n");
    printf("============================\n");
    printf("Contoh : 1c+1k+1m\n");
    printf("============================\n\n");
}

void showResultCP(float result, stack postfix, stack prefix)
{
    char convert;
    printf("Result :\n");
    printf("%.2f meter\n", result);
    //show a result
    printf("\nResult Postfix :\n");
    cetakStack(postfix);
    printf("\nResult Prefix :\n");
    cetakStack(prefix);

    //ask for convet metric
    printf("\n\nConvert (y/t) ? ");
    scanf("%c", &convert);
    if (convert == 'y' || convert == 'Y')
    {
        int pilih;
        while (pilih != 0)
        {
            switch (pilih = convertSatuan())
            {
            case 1:
                printf("%.6f kilometer\n", MeterToKilometer(result));
                break;
            case 2:
                printf("%.6f hektometer\n", MeterToHektometer(result));
                break;
            case 3:
                printf("%.6f dekameter\n", MeterToDekameter(result));
                break;
            case 4:
                printf("%.6f desimeter\n", MeterToDesimeter(result));
                break;
            case 5:
                printf("%.6f centimeter\n", MeterToCentimeter(result));
                break;
            case 6:
                printf("%.6f milimeter\n", MeterToMilimeter(result));
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
    printf("\nConvert to : (1)kilometer (2)hektometer (3)dekameter\n");
    printf("             (4)desimeter (5)centimeter (6)milimeter (0)back\n");
    printf("Choose : ");
    scanf("%d", &choose);
    return choose;
}

bool isInfixCP(String infix){
    int i = 0;
    // inisialisasi charOfInfix untuk menyimpan banyak karakter pada infix
    int charOfInfix = LengthStr(infix);
    
    // iterasi untuk pengecekan tiap index
        while (i < charOfInfix){
            if ((infix[i] == ' ')  || 
            (((infix[i] != 'c') && (infix[i] != 'm') && (infix[i] != 'k')) 
            && 
            ((!isOperand(infix[i])) && (!isOperator(infix[i]))))) return false;

        i++;
        }
        return true;
}