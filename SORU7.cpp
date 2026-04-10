/****************************************************************************************
**
**  ÝSTANBUL 29 MAYIS ÜNÝVERSÝTESÝ
**  BÝLÝÞÝM TEKNOLOJÝLERÝ MESLEK YÜKSEKOKULU
**  BÜYÜK VERÝ ANALÝSTLÝÐÝ PR.
**  PROGRAMLAMAYA GÝRÝÞ DERSÝ
**  2025-2026 GÜZ DÖNEMÝ
**
**  ÖDEV NUMARASI : SORU 7
**  ÖÐRENCÝ ADI SOYADI : Kerem PARALI
**  ÖÐRENCÝ NUMARASI : 300125024
**
****************************************************************************************/


/*********************** BASÝT ÇARPIM TABLOSU **************************************/



#include <iostream>
using namespace std;

int main() {

    for (int i = 1; i <= 10; i++) {
        // Satýrlarý kontrol eden döngü

        for (int j = 1; j <= 10; j++) {
            // Sütunlarý kontrol eden döngü

            cout << i * j << "\t";
            // i ile j çarpýlýp yan yana yazdýrýlýr
        }

        cout << endl;
        // Her satýrdan sonra alt satýra geçilir
    }

    return 0;
}

