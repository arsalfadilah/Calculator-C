#ifndef CALCULATORSTANDART_H
#define CALCULATORSTANDART_H

#include "stack.h"
#include "string.h"

/*         ATTRIBUT DATA         */

/*history adalah sebuah tipe data bentukan yang menyimpan data dari operasi matematika dalam bentuk notasi infix, kode fitur kalkulator dan hasil dari perhitungan operasi matematika ke dalam sebuah file*/
typedef struct HISTORY
{
    char infix [1000], type [3];
    double result;
}history;

/*              BEHAVIOR MAIN             */

/* 
   Keterangan : Menghasilkan hasil penjumlahan dari dua buah angka
   I.S : a dan b merupakan angka real
   F.S : mengembalikan hasil penjumlahan angka real
*/
double add(double a, double b);

/* 
   Keterangan : Menghasilkan hasil dari pengurangan dari dua buah angka
   I.S : a dan b merupakan angka real
   F.S : Mengembalikan hasil penjumlahan angka real
*/
double substract(double a, double b);

/* 
   Keterangan : Menghasilkan hasil perkalian dari dua buah angka
   I.S : a dan b merupakan angka real
   F.S : Mengembalikan hasil perkalian angka real
*/
double multiply(double a, double b);

/* 
   Keterangan : Menghasilkan hasil pembagian dari dua buah angka
   I.S : a dan b merupakan angka real
   F.S : Mengembalikan hasil pembagian angka real
*/
double divide(double a, double b);

/* 
   Keterangan : Menghasilkan hasil pangkat dari a pangkat b
   I.S : a dan b merupakan angka real
   F.S : Mengembalikan hasil perpangkatan angka real
*/
double power(double a, double b);

/* 
   Keterangan : Menghasilkan hasil dari pengakaran sebuah angka
   I.S : a adalah angka real 
   F.S : mengembalikan hasil akar dari a
*/
double radix(double a);

/* 
   Keterangan : Menghasilkan hasil sisa bagi dari a dibagi b
   I.S : a dan b adalah anagka real
   F.S : mengembalikan hasil dari a modulus b
*/
double mod(double a, double b);

/* 
   Keterangan : Menghasilkan hasil perhitungan dari stack dengan ekspresi matematika dalam bentuk postfix
   I.S : ekspresi matematika dalam bentuk postfix berupa stack
   F.S : Mengembalikan hasil dari perhitungan stack postfix
*/
double calculate(stack Postfix);

/*          BEHAVIOR ADDIIONAL              */

/* 
   Keterangan : Mengubah ekspresi matematik dalam bentuk infix ke postfix dengan menggunakan stack
   I.S : ekspresi matematik infix terdefinisi pada sebuah stack
   F.S : ekspresi postfix sudah terbentuk pada stack
*/
void InfixToPostfix(stack *Postfix, stack infixed);

/* 
   Keterangan : Mengubah ekspresi matematik dalam bentuk infix ke prefix dengan menggunakan stack
   I.S : ekspresi matematik infix terdefinisi pada sebuah stack
   F.S : ekspresi prefix sudah terbentuk padas sebuah stack
*/
void InfixToPrefix(stack *Prefix, stack infix);

/* 
   Keterangan : Mengatur jalannya alur program dari kalkulator standar
   I.S : Fitur kalkulator standar belum berjalan
   F.S : Segala rangkaian yang berkaitan dengan calculator standar dijalankan
*/
void runCalculatorStandar();

/* 
   Keterangan : Mengembalikan keadaan string, stack postfi dan prefix ke keadaan semula ditandai dengan value masing-masing adalah NULL. Proses ini mendealokasi setiap alokasi yang telah digunakan pada string infix, stack postfix dan prefix.
   I.S : String infix, stack postfix dan prefix telah terdefinisi, dan tidak kosong
   F.S : Keadaan string dan stack menjadi kosong
*/
void reset(String *infix, stack *posfix, stack *prefix);

/*                GETTER                  */

/* 
   Keterangan : Menghasilkan derajat dari suatu operator. Derajat operator menentukan bagian mana terlebih dahulu untuk dilakukan perhitungan. Untuk + dan - bernilai 1, untuk *, / dan % bernilai 2, kemudian untuk $ dan ^ bernilai 3. 
   I.S : karakter ch adalah sebuah operator
   F.S : mengembalikan derajat dari suatu operator
*/
int Prec(char ch);

/* 
   Keterangan : Memeriksan apakah string atau kalimat yang dimasukan oleh user valid atau tidak. Valid jika di dalam string tidak terdapat bukan operand dan bukan operator. 
   I.S : sebuah string telah terdefinisi
   F.S : mengembalikan true jika valid atau false jika tidak valid
*/
bool isInfix(String infix);

/*                  UI                    */

/* 
   Keterangan : Menahan layar dengan mengharuskan menginputkan sembarang inputan oleh user kemudian menghapus segala sesuatu dari layar
   I.S : Di layar terdapat teks telah terpakai atau mungkin layar kosong
   F.S : layar kembali kosong
*/
void HoldCls();

/* 
   Keterangan : Menampilkan format judul dari fitur kalkulator standar
   I.S : Judul belum ditampilkan ke layar
   F.S : Judul sudah ditampilkan ke layar
*/
void showTitleCalculatorStandar();

/* 
   Keterangan : Menampilkan format hasil dari perhitungan operasi matematika. Kemudian menampilkan ekspresi matematika dalam bentuk postfix dan infix.
   I.S : hasil dari perhitungan, ekpresi prefix dan postfix telah terdefinisi
   F.S : Muncul hasil perhitungan, prefix dan postfix ke layar
*/
void showResult(double result, String infix, stack Prefix, stack Postfix);

/* 
   Keterangan : Menampilkan format judul fitur history
   I.S : Judul belum ditampilkan ke layar
   F.S : Judul sudah ditampilkan ke layar
*/
void showTitleHistory();

/*        FILE HANDLING CALCULATOR        */

/* 
   Keterangan : Menyimpan data dari string infix dan hasil dari perhitungan sebuah operasi matematis ke dalam file. File akan bertambah datanya
   I.S : data belum tersimpan
   F.S : data sudah tersimpan
*/
void save(history hs);

/* 
   Keterangan : menampilkan riwayat data yang telah tersimpan di dalam file ke layar.
   I.S : riwayat/history belum ditampilkan ke layar
   F.S : riwayat/history sudah ditampilkan ke layar
*/
void showHystory();

/* 
   Keterangan : membalikan record file history dari akhir ke awal
   I.S : riwayat/history terdefinisi
   F.S : riwayat/history telah terbalik
*/
void reverseHystory();

/* 
   Keterangan : Menyimpan data ke file dengan kode fitur CS atau Calculator Standar/biasa.
   I.S : data belum tersimpan
   F.S : data sudah tersimpan dengan kode fitur CS
*/
void saveCS(String infix, double result);

#endif