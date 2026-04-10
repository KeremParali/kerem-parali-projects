/****************************************************************************************
**
**  İSTANBUL 29 MAYIS ÜNİVERSİTESİ
**  BİLİŞİM TEKNOLOJİLERİ MESLEK YÜKSEKOKULU
**  BÜYÜK VERİ ANALİSTLİĞİ PR.
**  PROGRAMLAMAYA GİRİŞ DERSİ
**  2025-2026 GÜZ DÖNEMİ
**
**  ÖDEV NUMARASI : SORU 5
**  ÖĞRENCİ ADI SOYADI : Kerem PARALI
**  ÖĞRENCİ NUMARASI : 300125024
**
****************************************************************************************/

/********************* SAYININ POZİTİF / NEGATİF / SIFIR OLDUĞUNU BULAN PROGRAM ************/



#include <iostream>
using namespace std;

int main() {
    int sayi;
    // Kullanıcıdan alınacak sayıyı tanımladım

    cout << "Bir sayi giriniz: ";
    cin >> sayi;
    // Kullanıcıdan sayıyı aldım

    if (sayi > 0) {
        // Eğer sayı 0’dan büyükse
        cout << "Sayi pozitiftir." << endl;
        // Pozitif olduğunu ekrana yazdırır
    }
    else if (sayi < 0) {
        // Eğer sayı 0’dan küçükse
        cout << "Sayi negatiftir." << endl;
        // Negatif olduğunu ekrana yazdırır
    }
    else {
        // Sayı ne pozitif ne negatifse
        cout << "Sayi sifirdir." << endl;
        // Sayının sıfır olduğunu yazar
    }

    return 0;
}



