#include "CalculatorPanjang.h"
#include <stdio.h>


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
centimeter CentimeterToMeter(meter m){
    return m/100;
}
// convert kilometer to centimeter
kilometer KilometerToCentimeter(centimeter cm){
    return cm*100000;
}
// convet kilometer to meter
kilometer KilometerToMeter(meter m){
    return m*1000;
}

/* Method Tambahan */
void runCalculatorPanjang(){
    //tampil judul 
    // 1m+2km
    // 2001 meter
    printf("===========================\n");
    printf("CALCULATOR PANJANG TEAM NINE\n");
    printf("===========================\n");
    printf("input : \n");
}