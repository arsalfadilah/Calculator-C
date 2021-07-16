#ifndef CALCULATORSTANDART_H
#define CALCULATORSTANDART_H

#include "stack.h"

    //  4.1 jika kalkulator standar 
    //      4.1.1 tampil header menu
    //      4.1.2 tampil form input
    //      4.1.3 user menginputkan
    //      4.1.4 tampil hasil
    //      4.1.5 memilih reset atau tidak
    //          4.1.5.1 jika y kembali ke 4.1.1
    //          4.1.5.2 jika t kembali ke menu utama

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
void runCalculatorStandar();
#endif