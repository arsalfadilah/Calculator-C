#include <stdio.h>
#include <Windows.h>
#include <math.h>
#include "string.h"
#include "stack.h"
#include "CalculatorStandart.h"
#include "CalculatorPanjang.h"

#include <stdio.h>

#define EPSILON 0.0001 // Define your own tolerance
#define FLOAT_EQ(x, v) (((v - EPSILON) < x) && (x < (v + EPSILON)))

struct threeNum
{
   String infix, type;
   double result;
};

/* Variable to store user content */
int main()
{
   reverseHystory();
    showHystory();
}