/*====================================  
    Header Stack For Calculator APP   
    By      : Arsal, Dimas dan Zidan
    Version : V.01           
  ====================================*/
#ifndef STACK_H
#define STACK_H

#include <stdbool.h>

/*=============================================*/
/*==============  ATTRIBUT DATA  ==============*/
/*=============================================*/

/* infotype adalah tipe data bentukan yang berisi opereand:double dan operator:char */
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


/* 
   Keterangan : 
   I.S : S terdefinisi sembarang, mungkin kosong
   F.S : S bertambah sebuah elemen sebagai elemen pertama
*/
void push(stack *s, infotype x);

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

/* 
   Keterangan : Menghapus element paling atas (top) pada stack s dan menyimpan value yang dihapus ke infotype x
   I.S : stack s teridentifikasi dan tidak kosong
   F.S : menghapus element paling atas(top) pada stack
*/
void pop(stack *s, infotype *x);

/* 
   Keterangan : Menghapus semua element pada stack s
   I.S : stack s tidak kosong
   F.S : stack s kosong yang ditandai stack bagian top = NULL
*/
void removeAllStack(stack *s);

/*=============================================*/
/*==============     SETTER     ===============*/
/*=============================================*/

/* 
   Keterangan : Mengatur nilai infotype info.operand diisi oleh angka (operand)
   I.S : double x terinisialisasi
   F.S : infotype memiliki value info.operand = x dan info.operator = '\0'
*/
void setOperand(infotype *info, double x);

/* 
   Keterangan : Mengatur nilai infotype info.operator diisi oleh karakter operator
   I.S : operator tidak kosong atau terinisialisasi
   F.S : infotype memiliki value infotype.operator = operator dan infotype.operand = 0
*/
void setOperator(infotype *info, char operator);

/* 
   Keterangan : Mengatur nilai infotype info.operand diisi oleh angka (operand) yang mempunyai satuan meter
   I.S : operand belum terkonversi ke satuan meter
   F.S : infotype info.operand = operand yang telah terkonversi ke satuan meter dan info.operator = '\0'
*/
void setOperandCP(infotype *info, double operand, char satuan);

/*=============================================*/
/*==============     GETTER     ===============*/
/*=============================================*/

/* 
   Keterangan : Mendapatkan operand dari pop element stack
   I.S : Operand belum terinisialisasi
   F.S : Operand berhasil didapatkan atau terinisialisasi
*/
void getOperandWithPop(stack *s, double *x);

/* 
   Keterangan : Mendapatkan operand a dan b dengan dua kali pop
   I.S : stack s tidak kosong dan operand a, b belum terinisialisasi
   F.S : operand a dan b sudah terinisialisasi
*/
void getTwoOperandWithPop(stack *s, double *a, double *b);

/* 
   Keterangan : Mengembalikan nilai elemen stack paling atas (top) suatu stack.
   I.S : stack s dapat kosong atau tidak
   F.S : Mengembailkan nilai info dari elemen stack paling atas dari stack tersebut.
*/
infotype peek(stack s);

/* 
   Keterangan : Memeriksa apakah suatu stack kosong, true bila kosong dan false bila tidak
   I.S : Tidak diketahui apakah suatu stack kosong
   F.S : Mengembalikan nilai true atau false
*/
bool isStackEmpty(stack s);

/* 
   Keterangan : Memeriksa suatu karakter a adalah karakter yang berupa operand/angka (0-9 atau titik ‘.’), true bila iya dan false bila tidak
   I.S : a telah terdefinisi
   F.S : Mengembalikan nilai true atau false
*/
bool isOperand(char a);

/* 
   Keterangan : Memeriksa apakah karakter ch adalah operator (+, -, *, /, $, ^, %), true bila karakter ch adalah karakter operator dan false bila tidak
   I.S : Karakter ch telah terinisialiasi
   F.S : Mengembalikan atau false
*/
bool isOperator(char ch);


/*=============================================*/
/*============== MODUL PENDUKUNG ==============*/
/*=============================================*/

/* 
   Keterangan : Menduplikasi stack source ke stack destination
   I.S : stack source telah terisi, mungkin kosong
   F.S : stack destination sama dengan stack source
*/
void stackcpy(stack *destination, stack source);

/* 
   Keterangan : Membalikkan suatu stack
   I.S : stack tidak kosong
   F.S : stack s menjadi terbalik ditandai dengan top menjadi bottom
*/
void reverseStack(stack *s);

/*=============================================*/
/*================= MODUL UI ==================*/
/*=============================================*/

/* 
   Keterangan : Menampilkan seluruh element pada stack ke layar, apabila kosong menampilkan [empty] ke layar
   I.S : S terdefinisi, mungkin kosong
   F.S : Menampilkan seluruh elemen dalam stack ke layar dari mulai TOP sampai dengan buttom jika tidak kosong
*/
void cetakStack(stack s);

#endif