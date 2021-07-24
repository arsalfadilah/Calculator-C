/*====================================  
    Header File Calculator   
    By      : Arsal, Dimas dan Zidan
    Version : V.01           
  ====================================*/
#ifndef STACK_H
#define STACK_H

#include <stdbool.h>
#include "string.h"

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

/* I.S : S terdefinisi, tidak diketahui nilainya
   F.S : S diinisialisasi top(s) = nil,
*/
void createStack(stack *s);

/* {Operasi terhadap komponen : selektor Get dan Set} */
//Destruktor or Dealokator
//Mengirim sebuah elemen stack dalam bentuk address
address alokasi(infotype x);

/* I.S : P terdefinisi
   F.S : P dikembalikan ke sistem
   		 Melakukan dealokasi / pengenmbalian address P ke sistem
*/
void dealokasi(address p);

//peek top element
infotype peek(stack s);

/* {Kelompok Interaksi Dengan I/O Device} */
/* I.S : S terdefinisi sembarang, mungkin kosong
   F.S : S bertambah sebuah elemen sebagai elemen pertama
*/
void push(stack *s, infotype x);

/* I.S : S terdefinisi, Stack tidak kosong
   F.S : Menghapus elemen pada top(s)
*/
void pop(stack *s, infotype *x);

/* I.S : S terdefinisi, mungkin kosong
   F.S : Menampilkan seluruh elemen dalam stack ke layar dari mulai TOP sampai dengan buttom jika tidak kosong
*/
void cetakStack(stack s);

//copy stack source ke stack destination
void stackcpy(stack *destination, stack source);

void reverseStack(stack *s);

//String toString(stack s);

/* {Kelompok Operasi Cek elemen kosong} */
//Mengirimkan true jika stack kosong, false jika tidak
bool isStackEmpty(stack s);



#endif