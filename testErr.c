#include <stdio.h>
#include <Windows.h>
#include <math.h>
#include "string.h"
#include "stack.h"
#include "CalculatorStandart.h"

#include <stdio.h>

#define EPSILON 0.0001   // Define your own tolerance
#define FLOAT_EQ(x,v) (((v - EPSILON) < x) && (x <( v + EPSILON)))

int main()
{
    double x = 1;
    double y = 100;
    printf("%.15g", x/y);


    // //double x = r;
    // double y = 0.01;
    // double temp;
    // printf("simple mod = %.15g\n", fmod(y, 10.0));
    // double m;
    // int i=0, count=0, j=0;
    // String doub;
    // char a;
    // bool loop=true, find=false;
    // createString(&doub);
    // temp = x;
    // while(i<15&&loop){
    //     m=fmodf(x, 10.0f);
    //     printf("x=%.15g isi fmod(x,10.0)=%f\n", x, m);
    //     if(m != 0.0){
    //         count++;
    //     }else{
    //         loop=false;
    //     }
    //     //x*=10.0;
    //     sprintf(doub, "%f", x);
    //     j = 0;
    //     find=false;
    //     while(j<LengthStr(doub)&&!find){
    //         if(doub[j]=='.' && j+1!=LengthStr(doub))
    //         {
    //             find = true;
    //             a = doub[j];
    //             doub[j] = doub[j+1];
    //             doub[j+1]=a;
    //             //j=LengthStr(doub);
    //         }
    //         j++;
    //     }
    //     if(!find){
    //         addChar(&doub, '0');
    //     }
    //     x = StrToFloat(doub);
    //     i++;
    // }
    // x/=100.0;
    // sprintf(doub, "%.15g", x);
    // printf("String=%s\n", doub);
    // printf("count=%d\n", count);
    // printf("x=%.15g\n", temp);
    // printf("x=%.0f\n", temp);
   return 0;
}