#ifndef CALCULATORSTANDART_H
#define CALCULATORSTANDART_H

#include "stack.h"
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
int modulus(float a, float b);
//hasil dari perhitungan postfix expression
float calculate(stack postfix);
//getter
//cek apakah a operand atau bukan
bool isOperand(char a);
bool isOperator(char ch);
//predenci atau level derajat setiap operator
int Prec(char ch);
//Convert infix to postfix expression
void InfixToPostfix(stack *postfix, String infix);
//convert postfix to prefix
void PostfixToPrefix(stack *prefix, stack postfix);
//run calculator standar program
void runCalculatorStandar();

/* Method UI */
//menahan layar meminta inputan 
//press any key to continue dan membersihkannya
void HoldCls();

#endif