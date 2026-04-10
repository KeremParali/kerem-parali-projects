/****************************************************************************************
**
**  İSTANBUL 29 MAYIS ÜNİVERSİTESİ
**  BİLİŞİM TEKNOLOJİLERİ MESLEK YÜKSEKOKULU
**  BÜYÜK VERİ ANALİSTLİĞİ PR.
**  PROGRAMLAMAYA GİRİŞ DERSİ
**  2025-2026 GÜZ DÖNEMİ
**
**  ÖDEV NUMARASI : SORU 7
**  ÖĞRENCİ ADI SOYADI : Kerem PARALI
**  ÖĞRENCİ NUMARASI : 300125024
**
****************************************************************************************/


/*********************** BASİT ÇARPIM TABLOSU **************************************/



#include <iostream>
using namespace std;

int main() {

    for (int i = 1; i <= 10; i++) {
        // Satırları kontrol eden döngü

        for (int j = 1; j <= 10; j++) {
            // Sütunları kontrol eden döngü

            cout << i * j << "\t";
            // i ile j çarpılıp yan yana yazdırılır
        }

        cout << endl;
        // Her satırdan sonra alt satıra geçilir
    }

    return 0;
}

