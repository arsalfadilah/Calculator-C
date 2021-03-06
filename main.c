#include <stdio.h>
#include <math.h>
#include "stack.h"
#include "CalculatorPanjang.h"
#include "CalculatorStandart.h"
#include <Windows.h>

int chooseMainMenu()
{
    int pilih;
    system("color 0E");
    printf("||    ||    ||    ||    ||    ||    ||    ||\n");
    printf("============================================\n");
    printf("||         WELCOME TO CALCULATOR APP      ||\n");
    printf("||        By TEAM NINE Made With Love     ||\n");
    printf("============================================\n");
    printf("||  1. Kalkulator Standar                 ||\n");
    printf("||  2. Kalkulator Panjang                 ||\n");
    printf("||  3. History                            ||\n");
    printf("||  0. Exit                               ||\n\n");
    printf("    Pilih : ");
    while (scanf("%d", &pilih) != 1 && getchar() != '\n')
    {
        printf("! ONLY INTEGER ! ==> ");
    }
    return pilih;
}

int main()
{
    //inisialisasi
    int menu = -1;
    HoldCls();
    //Algoritma
    //1. mulai aplikasi (aktif selama user tidak memilih exit)
    while (menu != 0)
    {
        //2. tampil menu utama dan pemilihan menu
        switch (menu = chooseMainMenu())
        {
            //3. masuk ke setiap menu
        case 1:
            runCalculatorStandar();
            break;
        case 2:
            runCalculatorPanjang();
            break;
        case 3:
            showHystory();
            printf("\n");
            HoldCls();
            break;
        case 0:
            printf("\nThank you! Have a nice day\n");
            HoldCls();
            break;
        default:
            printf("\nSorry menu is not available\n");
            HoldCls();
            break;
        }
    }
    return 0;
}