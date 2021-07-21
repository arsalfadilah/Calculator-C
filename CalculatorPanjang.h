#ifndef CALCULATORPANJANG_H
#define CALCULATORPANJANG_H

#include "stack.h"
#include "string.h"

typedef float meter;
typedef float kilometer;
typedef float centimeter;

//  4.2 jika kalkulator panjang
    //      4.2.1 tampil header menu
    //      4.2.2 tampil form input
    //      4.2.3 user menginputkan
    //      4.2.4 tampil hasil
    //      4.2.5 memilih convert atau tidak
    //          4.2.5.1 jika y maka memilih satuan cm, m, km
    //          4.2.5.2 jika t maka lanjut ke 4.2.6
    //      4.2.6 memilih reset atau tidak
    //          4.2.6.1 jika y maka kembali ke 4.2.1
    //          4.2.6.2 jika t maka kembali ke menu utama
    //  4.3 jika memilih keluar maka program keluar atau aplikasi selesai

/* Method Utama kalkulator panjang */
// convert meter to centimeter 
meter MeterToCentimeter(centimeter cm);
// convert meter to kilometer
meter MeterToKilometer (kilometer km);
// convert centimenter to kilomoter
centimeter CentimeterToKilometer (kilometer km);
// convert centimeter to kilometer
float CentimeterToMeter(float m);
// convert kilometer to centimeter
kilometer KilometerToCentimeter(centimeter cm);
// convet kilometer to meter
float KilometerToMeter(float m);

void InfixToPostfixCP(stack *postfix, String infix);

void runCalculatorPanjang();

#endif