#include "CalculatorStandart.h"
#include <stdio.h>
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

    if(b==0){
        return 1;
    }

    return result;
}
//pengakaran akar kuadrat dari a ($a)
float radix(float a)
{
}
// sisa bagi dari a bagi b (a%b)
float modulus(float a, float b)
{
    //int a, b;
}

/* Method Tambahan */
//memulai kalkultor standar
void runCalculatorStandar()
{
    //tampil judul
    String str;
    printf("============================\nCALCULATOR STANDAR TEAM NINE\n============================\n");
    //input user
    printf("Input :\n");
    str = input();
    //lets some logic in here :

    //end proses calculate logic
    printf("result : \n");
    cetakStack(StrToInt(str));
    //dealokas string after use
    DealokasiString(&str);
}