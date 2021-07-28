#ifndef CALCULATORSTANDART_H
#define CALCULATORSTANDART_H

#include "stack.h"
#include "string.h"

/*             BEHAVIOR MAIN            */
//penjumlahan a + b
double add(double a, double b);
//pengurangan a - b
double substract(double a, double b);
//perkalian a * b
double multiply(double a, double b);
//pembagian a / b
double divide(double a, double b);
//perpangkatan a pangkat b (a^b)
double power(double a, double b);
//pengakaran akar kuadrat dari a ($a)
double radix(double a);
// sisa bagi dari a bagi b (a%b)
double mod(double a, double b);
//hasil dari perhitungan postfix expression
double calculate(stack Postfix);

/*             BEHAVIOR ADD               */
//Convert infix to postfix expression
void InfixToPostfix(stack *Postfix, stack infixed);
//convert infix to prefix with algo Infix to postfix
void InfixToPrefix(stack *Prefix, stack infix);
//run calculator standar program
void runCalculatorStandar();
//tokenization
stack tokenStrToStack(String infixStr);

/*                GETTER                 */
//cek apakah a operand atau bukan
bool isOperand(char a);
//cek apakah ch operator atau bukan
bool isOperator(char ch);
//cek apakah negatif number atau bukan
bool isNegatifOperandStr(String str, int tempIdx);
//predenci atau level derajat setiap operator
int Prec(char ch);
// mengecek inputan
bool isInfix(String infix);

/*                SETTER                 */
//setting operand = x, operator = '\0'
void setOperand(infotype *info, double x);
//setting operator = operator, operand = 0
void setOperator(infotype *info, char operator);
//get operand from stack s with pop
void getOperandWithPop(stack *s, double *x);
//get two operand from stack s with pop
void getTwoOperandWithPop(stack *s, double *a, double *b);

/*                  UI                    */
//menahan layar meminta inputan 
//press any key to continue dan membersihkannya
void HoldCls();
//show tittle calculator standar
void showTitleCalculatorStandar();
//show result include (result, postfix and prefix expression)
void showResult(double result, stack Prefix, stack Postfix);

#endif