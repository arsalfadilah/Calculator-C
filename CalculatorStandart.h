#ifndef CALCULATORSTANDART_H
#define CALCULATORSTANDART_H

#include "stack.h"
#include "string.h"

typedef struct HISTORY *addrHs;

typedef struct HISTORY
{
    char infix [1000], type [3];
    double result;
}history;

/*              BEHAVIOR MAIN             */
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
//reset all variables
void reset(String *infix, stack *posfix, stack *prefix);

/*                GETTER                  */
//predenci atau level derajat setiap operator
int Prec(char ch);
// mengecek inputan
bool isInfix(String infix);

/*                  UI                    */
//menahan layar meminta inputan 
//press any key to continue dan membersihkannya
void HoldCls();
//show tittle calculator standar
void showTitleCalculatorStandar();
//show result include (result, postfix and prefix expression)
void showResult(double result, stack Prefix, stack Postfix);
//menampilkan header/judul menu history
void showTitleHistory();

/*        FILE HANDLING CALCULATOR        */
//menyimpan history ke dalam file
void save(history hs);
//menampilkan semua history dari file
void showHystory();
//save in CS mode
void saveCS(String infix, double result);


#endif