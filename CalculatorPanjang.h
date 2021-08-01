#ifndef CALCULATORPANJANG_H
#define CALCULATORPANJANG_H

#include "stack.h"
#include "string.h"
#include "CalculatorStandart.h"

typedef double meter, kilometer, centimeter, dekameter, hektometer, desimeter, milimeter;

/* Method Utama kalkulator panjang */
/* convert meter to centimeter*/
centimeter MeterToCentimeter(meter m);
// convert meter to kilometer
kilometer MeterToKilometer(meter m);
// convert centimeter to kilometer
meter CentimeterToMeter(centimeter cm);
// convet kilometer to meter
meter KilometerToMeter(kilometer km);
// convert meter to hektometer
hektometer MeterToHektometer(meter m);
// convert meter to dekameter 
dekameter MeterToDekameter(meter m);
//convert meter to desimeter
desimeter MeterToDesimeter(meter m);
//convert meter to milimeter
milimeter MeterToMilimeter(meter m);

void InfixToPrefixCP(stack *prefix, String infix);

void runCalculatorPanjang();

void showTitleCalculatorPanjang();

void showResultCP(double result, stack postfix, stack prefix);

int convertSatuan();

bool isInfixCP(String infix);

stack tokenStrToStackCP(String infixStr);

void saveCP(String infix, double result);

#endif