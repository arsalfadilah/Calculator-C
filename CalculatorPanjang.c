#include "CalculatorPanjang.h"
#include "CalculatorStandart.h"
#include "string.h"
#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

// convert meter to centimeter 
meter MeterToCentimeter(centimeter cm){
    return cm*100;
}
// convert meter to kilometer
meter MeterToKilometer (kilometer km){
    return km/100;
}
// convert centimenter to kilomoter
centimeter CentimeterToKilometer (kilometer km){
return km/100000;
}
// convert centimeter to kilometer
float CentimeterToMeter(float m){
    return m/100;
}
// convert kilometer to centimeter
kilometer KilometerToCentimeter(centimeter cm){
    return cm*100000;
}
// convet kilometer to meter
float KilometerToMeter(float m){
    return m*1000;
}

bool isSatuan(char inputan){
    if ((inputan == 'c') || (inputan == 'm') || (inputan == 'k')){
        return true;
    }
    else return false;
}

void InfixToPostfixCP(stack *postfix, String infix)
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
            if(isSatuan(infix[i])){
                printf("ya satuannya adalah : %c", infix[i]);
                if(infix[i]=='c'){
                    //convet str to float
                    cm = StrToFloat(floatStr);
                    //convet centimeter to meter
                    m = CentimeterToMeter(cm);
                } 
                else if(infix[i]=='k'){
                    //convet str to float
                    km = StrToFloat(floatStr);
                    //convet centimeter to meter
                    m = KilometerToMeter(km);
                }
                else{
                    m = StrToFloat(floatStr);
                }
            } else {
                printf("Mohon libatkan satuannya\n");
                return;
            }
            idxFloatStr = 0;
            //push setiap operand dan jadikan operator \0
            info.Operator = '\0';
            info.Operand = m;
            push(&(*postfix), info);
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
                push(&(*postfix), info);
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
        {   // tidak : looping selama stack tidak kosong
            // untuk menyimpan operator dengan urutan operasi matematik yang benar
            // (lihat prec untuk mengetahui level setiap operator)
            while (!isStackEmpty(operator) && Prec(infix[i]) <= Prec(peek(operator).Operator))
            {
                pop(&operator, & info);
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
        pop(&operator, & info);
        push(&(*postfix), info);
    }
    //dealokasi stack operator
    dealokasi(operator.top);
}

/* Method Tambahan */
void runCalculatorPanjang(){
    //tampil judul 
    printf("===========================\n");
    printf("CALCULATOR PANJANG TEAM NINE\n");
    printf("===========================\n");
    printf("input : \n");
    //buat stack postfix agar mudah langsung di calculate
    stack postfix, prefix, tempPostfix;
    createStack(&postfix);
    createStack(&prefix);
    //input user
    printf("Input Infix Expression :\n");
    String infix = input();
    //convert infix expression to posfix
    InfixToPostfixCP(&postfix, infix);
    //copy agar postfix bisa di print lagi
    stackcpy(&tempPostfix, postfix);
    //convert postfix to prefix : (reverser the postfix expression)
    PostfixToPrefix(&prefix, tempPostfix);
    //calculate
    float result = calculate(prefix);
    printf("Result :\n");
    printf("%.2f m\n", result);
    //show a result
    printf("result Postfix :\n");
    cetakStack(postfix);
    printf("\nResult Prefix :\n");
    cetakStack(prefix);
    HoldCls();
    //dealokasi infix string after use
    DealokasiString(&infix);

}