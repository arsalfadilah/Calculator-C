/*====================================  
    Header Stack For Calculator APP   
    By      : Arsal, Dimas dan Zidan
    Version : V.01           
  ====================================*/
#ifndef STACK_H
#define STACK_H

#include <stdbool.h>
<<<<<<< HEAD

/*=============================================*/
/*==============  ATTRIBUT DATA  ==============*/
/*=============================================*/

/* infotype adalah tipe data bentukan yang berisi opereand:double dan operator:char */
=======
#include "string.h"
// Atribut Data 
>>>>>>> parent of 404c976 (refactor modul token)
typedef struct{
    double Operand;  // Angka
    char Operator;  /* +(penjumlahan), -(Pengurangan), x(Perkalian),
                       /(Pembagian), ^(Pangkat), %(Mod), &(akar)*/
} infotype;

/* address adalah tipe data bentukan yang berguna untuk menunjuk ke sebuah alamat dari node */
typedef struct node* address;

/* ElemStack adalah tipe data bentukan yang mempunyai 2 bagian yaitu info:infotype dan next:address */
typedef struct node{
    infotype info;
    address next;
}ElemStack;

/* stack adalah tipe data bentukan yang mempunyai bagian penanda yaitu top:address sebagai element top pada stack */
typedef struct{
    address top;
}stack;

/*=============================================*/
/*==============   CONSTRUCTOR  ===============*/
/*=============================================*/

/* 
   Keterangan : Membuat stack kosong ditandai dengan elemen top bernilai NULL
   I.S : stack s terdefinisi tetapi tidak diketahui nilainya
   F.S : stack s bagian top = NULL
*/
void createStack(stack *s);

/* 
   Keterangan : Mengembalikan alamat sebuah memori yang sudah dipesan sebesar tipe data Elemen Stack dengan isinya adalah x:infotype 
   I.S  : infotype x sudah sudah bernilai
   F.S  : mengembalikan sebuah addrress yang memiliki value infotype x
*/
address alokasi(infotype x);

/*=============================================*/
/*==============   DESSTRUCTOR  ===============*/
/*=============================================*/

/* 
   Keterangan : Melakukan pembebasan memori yang telah dipesan oleh sebuah address
   I.S : P terdefinisi
   F.S : P dikembalikan ke sistem
   		 Melakukan dealokasi / pengembalian address P ke sistem
*/
void dealokasi(address p);

/*=============================================*/
/*==============     SETTER     ===============*/
/*=============================================*/

/* 
   Keterangan : 
   I.S : 
   F.S : 
*/
void setOperand(infotype *info, double x);

/* 
   Keterangan : 
   I.S : 
   F.S : 
*/
void setOperator(infotype *info, char operator);

/* 
   Keterangan : 
   I.S : 
   F.S : 
*/
void setOperandCP(infotype *info, double operand, char satuan);
/* 
   Keterangan : 
   I.S : 
   F.S : 
*/
void pop(stack *s, infotype *x);
/* 
   Keterangan : 
   I.S : 
   F.S : 
*/
void removeAllStack(stack *s);
/* I.S : S terdefinisi, mungkin kosong
   F.S : Menampilkan seluruh elemen dalam stack ke layar dari mulai TOP sampai dengan buttom jika tidak kosong
*/

/* {Kelompok Interaksi Dengan I/O Device} */
/* I.S : S terdefinisi sembarang, mungkin kosong
   F.S : S bertambah sebuah elemen sebagai elemen pertama
*/
void push(stack *s, infotype x);

/*=============================================*/
/*==============     GETTER     ===============*/
/*=============================================*/
void getOperandWithPop(stack *s, double *x);
/* 
   Keterangan : 
   I.S : 
   F.S : 
*/
void getTwoOperandWithPop(stack *s, double *a, double *b);
/* 
   Keterangan : 
   I.S : 
   F.S : 
*/

//peek top element
infotype peek(stack s);

/* {Kelompok Operasi Cek elemen kosong} */
//Mengirimkan true jika stack kosong, false jika tidak
bool isStackEmpty(stack s);

<<<<<<< HEAD
//ini perlu di modif:
//cek apakah a operand atau bukan
bool isOperand(char a);
//cek apakah ch operator atau bukan
bool isOperator(char ch);

/*=============================================*/


/*============== MODUL TAMBAHAN ================*/
void cetakStack(stack s);

//copy stack source ke stack destination
void stackcpy(stack *destination, stack source);
//Untuk membalikan stack (mengembalikan element bottom ke top)
void reverseStack(stack *s);
/*** Modul ***/


/* {Operasi terhadap komponen : selektor Get dan Set} */
//Destruktor or Dealokator
//Mengirim sebuah elemen stack dalam bentuk address








/* I.S : S terdefinisi, Stack tidak kosong
   F.S : Menghapus elemen pada top(s)
*/



//String toString(stack s);



/*                SETTER                  */
=======
>>>>>>> parent of 404c976 (refactor modul token)


#endif