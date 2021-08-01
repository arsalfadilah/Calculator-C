#ifndef STRING_H
#define STRING_H

#include "stack.h"
#include <stdbool.h>

/*         ATTRIBUT DATA         */

/*String merupakan kumpulan dari karakter bersifat dinamis*/
typedef char* String;

/*=============================================*/
/*==============   CONSTRUCTOR  ===============*/
/*=============================================*/

/* 
   Keterangan : 
   I.S : 
   F.S : 
*/
void createString(String *str);

/* 
   Keterangan : Memasukkan tiap char ke string dengan melakukan alokasi sebanyak char yang diinputkan oleh user kemudian mengembalikan string
   I.S : String masih kosong atau dalam keadaan null belum dialokasikan dan user masih belum menginputkan apa-apa
   F.S : String telah terbentuk dengan value sesuai yang user inputkan
*/
String inputStr();

/*=============================================*/
/*==============   DESSTRUCTOR  ===============*/
/*=============================================*/

/* 
   Keterangan : Mengembalikan memori yang dipakai oleh string ke sistem
   I.S : Memori untuk String masih teralokasi
   F.S : Memori yang dipakai dibebaskan dan dikembalikan ke sistem
*/
void DealokasiStr(String *str);

/*=============================================*/
/*==============     SETTER     ===============*/
/*=============================================*/

/* 
   Keterangan : Menambahkan satu karakter ke sebuah string
   I.S : string masih belum ditambahkan dengan satu karakter
   F.S : karakter telah ditambahkan ke dalam sebuah string
*/
void addChar(String *destination, char ch);

/*=============================================*/
/*==============     GETTER     ===============*/
/*=============================================*/

/* 
   Keterangan : Memeriksa satu karakter apakah satuan yang sah ('m', 'c', 'k') atau tidak, true bila iya dan false bila tidak
   I.S : karakter terinisialisasi
   F.S : Mengembalikan true atau false
*/
bool isSatuan(char inputan);

/* 
   Keterangan : Memeriksa apakah dalam suatu string terdapat angka negatif, true bila iya dan false jika tidak
   I.S : string tidak kosong dan index string terinisiliasi
   F.S : mengembalikan true atau false
*/
bool isStrNegatifOperand(String str, int tempIdx);

/*=============================================*/
/*============== MODUL PENDUKUNG ==============*/
/*=============================================*/

/* 
   Keterangan : Menghitung jumlah char suatu string
   I.S : Jumlah char suatu string belum diketahui
   F.S : Mengembalikan jumlah char dalam suatu string
*/
int LengthStr(String str);

/* 
   Keterangan : Mengubah tipe data dari String ke double
   I.S : String masih berbentuk kumpulan karakter
   F.S : Mengembalikan tipe data double yang memiliki value dari parameter string
*/
double StrToDouble(String floatStr);

/* 
   Keterangan : Menduplikasi satu string ke string yang lain
   I.S : string source tidak kosong dan string destination kosong
   F.S : string destination memiliki value yang sama dengan string souce
*/
void strcopy(String *destination, String Source);

/* 
   Keterangan : Membagi sebuah kalimat menjadi token-token ke dalam sebuah stack. Token-token di ini dapat berupa operand atau operator. Digunakan pada calculator metric/panjang
   I.S : String atau kalimat telah terinisialisasi
   F.S : mengembalikan stack yang beirsi token-token dari string
*/
stack TokenizationCP(String infixStr);

/* 
   Keterangan : Membagi sebuah kalimat menjadi token-token ke dalam sebuah stack. Token-token di ini dapat berupa operand atau operator. Digunakan pada calculator Standar/biasa
   I.S : String atau kalimat telah terinisialisasi
   F.S : mengembalikan stack yang berisi token-token dari string
*/
stack TokenizationCS(String infixStr);

/*=============================================*/
/*================= MODUL UI ==================*/
/*=============================================*/

#endif