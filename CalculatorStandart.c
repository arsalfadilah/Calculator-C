#include "CalculatorStandart.h"
#include <stdio.h>
#include "string.h"

/* Method Utama Kalkulator Standar */
//penjumlahan a + b
float add(float a, float b);
//pengurangan a - b
float substract(float a, float b);
//perkalian a * b
float multiply(float a, float b);
//pembagian a / b
float divide(float a, float b);
//perpangkatan a pangkat b (a^b)
float power(float a, float b);
//pengakaran akar kuadrat dari a ($a)
float radix(float a);
// sisa bagi dari a bagi b (a%b)
float modulus(float a, float b);

/* Method Tambahan */
//memulai kalkultor standar
void runCalculatorStandar(){
    //tampil judul
    String str;
    printf("============================\nCALCULATOR STANDAR TEAM NINE\n============================\n");
    //input user
    printf("Input :\n");
    str = input();
    //lets some logic in here :

    //end proses calculate logic
    printf("result :\n");
    //dealokas string after use
    DealokasiString(&str);
}