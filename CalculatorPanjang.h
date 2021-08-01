#ifndef CALCULATORPANJANG_H
#define CALCULATORPANJANG_H

#include "stack.h"
#include "string.h"
#include "CalculatorStandart.h"

/*=============================================*/
/*==============  ATTRIBUT DATA  ==============*/
/*=============================================*/

// Menamai kembali variabel double dengan 8 macam satuan baku panjang.
typedef double meter, kilometer, centimeter, dekameter, hektometer, desimeter, milimeter;

/*=============================================*/
/*==============   CONSTRUCTOR  ===============*/
/*=============================================*/
/* 
   Keterangan : Mengubah nilai dari meter ke centimeter
   I.S : Sebuah nilai yang belum diubah dari meter ke centimeter
   F.S : Sebuah nilai yang sudah diubah dari meter ke centimeter
*/
centimeter MeterToCentimeter(meter m);

/* 
   Keterangan : Mengubah nilai dari meter ke kilometer
   I.S : Sebuah nilai yang belum diubah dari meter ke Kilometer
   F.S : Sebuah nilai yang sudah diubah dari meter ke Kilometer
*/
kilometer MeterToKilometer(meter m);

/* 
   Keterangan : Mengubah nilai dari cenrimeter ke meter
   I.S : Sebuah nilai yang belum diubah dari centimeter ke meter
   F.S : Sebuah nilai yang sudah diubah dari centimeter ke meter
*/
meter CentimeterToMeter(centimeter cm);

/* 
   Keterangan : Mengubah nilai dari kilometer ke meter
   I.S : Sebuah nilai yang belum diubah dari kilometer ke meter
   F.S : Sebuah nilai yang sudah diubah dari kilometer ke meter
*/
meter KilometerToMeter(kilometer km);

/* 
   Keterangan : Mengubah nilai dari meter ke hektometer
   I.S : Sebuah nilai yang belum diubah dari meter ke hektometer
   F.S : Sebuah nilai yang sudah diubah dari meter ke hektometer
*/
hektometer MeterToHektometer(meter m);

/* 
   Keterangan : Mengubah nilai dari meter ke dekameter
   I.S : Sebuah nilai yang belum diubah dari meter ke dekameter
   F.S : Sebuah nilai yang sudah diubah dari meter ke dekameter
*/
dekameter MeterToDekameter(meter m);

/* 
   Keterangan : Mengubah nilai dari meter ke desimeter
   I.S : Sebuah nilai yang belum diubah dari meter ke desimeter
   F.S : Sebuah nilai yang sudah diubah dari meter ke desimeter
*/
desimeter MeterToDesimeter(meter m);

/* 
   Keterangan : Mengubah nilai dari meter ke milimeter
   I.S : Sebuah nilai yang belum diubah dari meter ke milimeter
   F.S : Sebuah nilai yang sudah diubah dari meter ke milimeter
*/
milimeter MeterToMilimeter(meter m);

/* 
   Keterangan : Untuk menyimpan operasi matematis yang pernah diinputkan pengguna ke fitur history
   I.S : Operasi matematis pengguna tidak masuk ke dalam history
   F.S : Operasi matematis pengguna tercatat ke dalam history
*/
void saveCP(String infix, double result);

/*=============================================*/
/*==============   DESSTRUCTOR  ===============*/
/*=============================================*/



/*=============================================*/
/*==============     GETTER     ===============*/
/*=============================================*/
/* 
   Keterangan : Untuk Mengecek apakah notasi yang dimasukkan valid sesuai dengan aturan
   I.S : String yang dimasukan oleh pengguna belum valid
   F.S : String yang dimasukan oleh pengguna sudah tervalidasi
*/
bool isInfixCP(String infix);

/*=============================================*/
/*================= MODUL UI ==================*/
/*=============================================*/
/* 
   Keterangan : Menjalankan mode calculator panjang (memanggil modul lainnya)
   I.S : Mode calculator panjang belum dijalankan
   F.S : mode calculator panjang dijalankan
*/
void runCalculatorPanjang();

/* 
   Keterangan : Menampilkan tampilan menu Calculator Panjang beserta aturan pakainya
   I.S : Tampilan mode Calculator Panjang tidak tertampilkan
   F.S : Tampilan mode Calculator Panjang tertampilkan
*/
void showTitleCalculatorPanjang();

/* 
   Keterangan : Menampilkan format hasil operasi calculator
   I.S : Format hasil tidak tertampilkan
   F.S : Format hasil tertampilkan
*/
void showResultCP(double result, stack postfix, stack prefix);

/* 
   Keterangan : Mengembalikan pilihan pengguna ingin mengonversikan hasil dari operasi Calculator Panjang dari satuan meter ke satuan lainnya
   I.S : Menampilkan pilihan konversi
   F.S : Inputan pengguna sebagai pilihan konversi ke satuan panjang apa.
*/
int convertSatuan();

#endif