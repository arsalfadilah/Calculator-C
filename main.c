#include <stdio.h>
#include "stack.h"
#include "CalculatorPanjang.h"
#include "CalculatorStandart.h"

int chooseMainMenu(){
    printf("WELCOME TO APP\n");
    printf("1. Kalkulator Standar\n");
    printf("2. Kalkulator Panjang\n");
    int pilih;
    printf("Pilih : "); scanf("%d", &pilih);
    return pilih;
}

int main(){
    //inisialisasi
    int menu = -1;
    //Algoritma
    //1. mulai aplikasi (aktif selama user tidak memilih exit)
    while(menu!=0){
        //2. tampil menu utama
        //3. pemilihan menu
        switch (menu = chooseMainMenu())
        {
            //4. masuk ke setiap menu
        case 1:
            runCalculatorStandar();
            break;
        case 2:
            runCalculatorPanjang();
            break;
        case 0:
            printf("\nthank you! Have a nice day\n");
            break;
        default:
            printf("\nsorry menu is not available\n");
            break;
        }
    }
    //  4.1 jika kalkulator standar 
    //      4.1.1 tampil header menu
    //      4.1.2 tampil form input
    //      4.1.3 user menginputkan
    //      4.1.4 tampil hasil
    //      4.1.5 memilih reset atau tidak
    //          4.1.5.1 jika y kembali ke 4.1.1
    //          4.1.5.2 jika t kembali ke menu utama
    //  4.2 jika kalkulator panjang
    //      4.2.1 tampil header menu
    //      4.2.2 tampil form input
    //      4.2.3 user menginputkan
    //      4.2.4 tampil hasil
    //      4.2.5 memilih convert atau tidak
    //          4.2.5.1 jika y maka memilih satuan cm, m, km
    //          4.2.5.2 jika t maka lanjut ke 4.2.6
    //      4.2.6 memilih reset atau tidak
    //          4.2.6.1 jika y maka kembali ke 4.2.1
    //          4.2.6.2 jika t maka kembali ke menu utama
    //  4.3 jika memilih keluar maka program keluar atau aplikasi selesai

    return 0;
}