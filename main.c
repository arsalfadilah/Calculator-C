#include <stdio.h>
#include "stack.h"

int main(){

    infotype infoTest;
    infoTest.Operand = 9;

    infotype infoTest1;
    infoTest1.Operand = 10;

    infotype infoTest2;
    infoTest2.Operand = 12;

    stack stackTest;
    createStack(&stackTest);
    push(&stackTest,infoTest);
    push(&stackTest,infoTest1);
    push(&stackTest,infoTest2);

    cetakStack(stackTest);
    printf("\nmari kita pop\n");

    pop(&stackTest, &infoTest);
    pop(&stackTest, &infoTest);

    cetakStack(stackTest);

    return 0;
}