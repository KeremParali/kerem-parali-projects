/****************************************************************************************
**
**  ÝSTANBUL 29 MAYIS ÜNÝVERSÝTESÝ
**  BÝLÝÞÝM TEKNOLOJÝLERÝ MESLEK YÜKSEKOKULU
**  BÜYÜK VERÝ ANALÝSTLÝÐÝ PR.
**  PROGRAMLAMAYA GÝRÝÞ DERSÝ
**  2025-2026 GÜZ DÖNEMÝ
**
**  ÖDEV NUMARASI : SORU 2
**  ÖÐRENCÝ ADI SOYADI : Kerem PARALI
**  ÖÐRENCÝ NUMARASI : 300125024
**
****************************************************************************************/


/********************* C++ KODUNUN ÇIKTISI NEDÝR? *************************************/



#include <iostream>
using namespace std;

int main() {
    int arr[] = { 2, 4, 6, 8, 10 };
    // Ýçinde 5 tane sayý olan bir dizi tanýmladým

    int toplam = 0;
    // Sonucu tutmak için toplam deðiþkenini 0 yaptým

    for (int i = 0; i < 5; i++) {
        // Dizinin tüm elemanlarýný tek tek kontrol ediyorum

        if (arr[i] % 4 == 0) {
            // Eðer sayý 4’e tam bölünüyorsa

            toplam += arr[i];
            // O sayýyý toplama ekliyorum
        }
    }

    cout << "Sonuc: " << toplam << endl;
    // 4’e bölünen sayýlar 4 ve 8 olduðu için sonuç 12 olur

    return 0;
}

