#ifndef CALCULATORPANJANG_H
#define CALCULATORPANJANG_H

#include "stack.h"
#include "string.h"

typedef float meter;
typedef float kilometer;
typedef float centimeter;

/* Method Utama kalkulator panjang */
// convert meter to centimeter
centimeter MeterToCentimeter(meter m);
// convert meter to kilometer
kilometer MeterToKilometer(meter m);
// convert centimeter to kilometer
meter CentimeterToMeter(centimeter cm);
// convet kilometer to meter
meter KilometerToMeter(kilometer km);

void InfixToPrefixCP(stack *prefix, String infix);

void runCalculatorPanjang();

void showTitleCalculatorPanjang();

void showResultCP(float result, stack postfix, stack prefix);

int convertSatuan();

#endif