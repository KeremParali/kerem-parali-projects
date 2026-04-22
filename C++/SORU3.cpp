/****************************************************************************************
**
**  ÝSTANBUL 29 MAYIS ÜNÝVERSÝTESÝ
**  BÝLÝÞÝM TEKNOLOJÝLERÝ MESLEK YÜKSEKOKULU
**  BÜYÜK VERÝ ANALÝSTLÝÐÝ PR.
**  PROGRAMLAMAYA GÝRÝÞ DERSÝ
**  2025-2026 GÜZ DÖNEMÝ
**
**  ÖDEV NUMARASI : SORU 3
**  ÖÐRENCÝ ADI SOYADI : Kerem PARALI
**  ÖÐRENCÝ NUMARASI : 300125024
**
****************************************************************************************/

/********************* C++ KODUNUN ÇIKTISI NEDÝR? *************************************/


#include <iostream>
using namespace std;

int main() {

    int sayi = 3;
    // Hesaplamada kullanýlacak sabit sayý

    for (int i = 0; i < 4; i++) {
        // Döngü 4 defa çalýþacaktýr
        // Ý deðeri ile hesaplanan sonuç ekrana yazdýrýlýr

        cout << "i=" << i << ", sonuc=" << (sayi + i * 2) << endl;
        // Her turda i*2 hesaplanýr ve sayi ile toplanarak ekrana yazdýrýlýr
    }

    return 0;
    // Program bitirilir
}