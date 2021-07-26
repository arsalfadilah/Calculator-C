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
//cek apakah ch operator atau bukan
bool isOperator(char ch);
//predenci atau level derajat setiap operator
int Prec(char ch);
//setting operand = x, operator = '\0'
void setOperand(infotype *info, float x);
//setting operator = operator, operand = 0
void setOperator(infotype *info, char operator);
//get operand from stack s with pop
void getOperandWithPop(stack *s, float *x);
//get two operand from stack s with pop
void getTwoOperandWithPop(stack *s, float *a, float *b);

//modul tambahan
//Convert infix to postfix expression
void InfixToPostfix(stack *prefix, String infix);
//convert infix to prefix with algo Infix to postfix
void InfixToPrefix(stack *Prefix, String infix);
//run calculator standar program
void runCalculatorStandar();

/* Method UI */
//menahan layar meminta inputan 
//press any key to continue dan membersihkannya
void HoldCls();
//show tittle calculator standar
void showTitleCalculatorStandar();
//show result (rsult, postfix and prefix expression)
void showResult(float result, stack Prefix, stack Postfix);
// mengecek inputan
bool isInfix(String infix);

#endif