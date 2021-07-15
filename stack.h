/*====================================  
    Header File Calculator   
    By      : Arsal, Dimas dan Zidan
    Version : V.01           
  ====================================*/
#ifndef STACK_H
#define STACK_H

#include <stdbool.h>

typedef struct{
    float Operand;  // Angka
    char Operator;  /* +(penjumlahan), -(Pengurangan), x(Perkalian),
                       /(Pembagian), ^(Pangkat), %(Mod), &(akar)*/
} infotype;

typedef struct node* address;
typedef struct node{
    infotype info;
    address next;
}ElemStack;

typedef struct{
    address top;
}stack;

void createStack(stack *s);
/* I.S : S terdefinisi, tidak diketahui nilainya
   F.S : S diinisialisasi top(s) = nil,
*/

/* {Opeasi terhadap komponen : selektor Get dan Set} */
//Destruktor or Dealokator
address alokasi(infotype x);
//Mengirim sebuah elemen stack dalam bentuk address

void dealokasi(address p);
/* I.S : P terdefinisi
   F.S : P dikembalikan ke sistem
   		 Melakukan dealokasi / pengenmbalian address P ke sistem
*/

/* {Kelompok Interaksi Dengan I/O Device} */
void push(stack *s, infotype x);
/* I.S : S terdefinisi sembarang, mungkin kosong
   F.S : S bertambah sebuah elemen sebagai elemen pertama
*/

void pop(stack *s, infotype *x);
/* I.S : S terdefinisi, Stack tidak kosong
   F.S : Menghapus elemen pada top(s)
*/

void cetakStack(stack s);
/* I.S : S terdefinisi, mungkin kosong
   F.S : Menampilkan seluruh elemen dalam stack ke layar dari mulai TOP sampai dengan buttom jika tidak kosong
*/

/* {Kelompok Operasi Cek elemen kosong} */
bool isStackEmpty(stack s);
//Mengirimkan true jika stack kosong, false jika tidak

// urg edit didieu

#endif