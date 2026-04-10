/****************************************************************************************
**
**  ÝSTANBUL 29 MAYIS ÜNÝVERSÝTESÝ
**  BÝLÝÞÝM TEKNOLOJÝLERÝ MESLEK YÜKSEKOKULU
**  BÜYÜK VERÝ ANALÝSTLÝÐÝ PR.
**  PROGRAMLAMAYA GÝRÝÞ DERSÝ
**  2025-2026 GÜZ DÖNEMÝ
**
**  ÖDEV NUMARASI : SORU 5
**  ÖÐRENCÝ ADI SOYADI : Kerem PARALI
**  ÖÐRENCÝ NUMARASI : 300125024
**
****************************************************************************************/

/********************* SAYININ POZÝTÝF / NEGATÝF / SIFIR OLDUÐUNU BULAN PROGRAM ************/



#include <iostream>
using namespace std;

int main() {
    int sayi;
    // Kullanýcýdan alýnacak sayýyý tanýmladým

    cout << "Bir sayi giriniz: ";
    cin >> sayi;
    // Kullanýcýdan sayýyý aldým

    if (sayi > 0) {
        // Eðer sayý 0’dan büyükse
        cout << "Sayi pozitiftir." << endl;
        // Pozitif olduðunu ekrana yazdýrýr
    }
    else if (sayi < 0) {
        // Eðer sayý 0’dan küçükse
        cout << "Sayi negatiftir." << endl;
        // Negatif olduðunu ekrana yazdýrýr
    }
    else {
        // Sayý ne pozitif ne negatifse
        cout << "Sayi sifirdir." << endl;
        // Sayýnýn sýfýr olduðunu yazar
    }

    return 0;
}



