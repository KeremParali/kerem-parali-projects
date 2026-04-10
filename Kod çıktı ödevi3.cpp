/****************************************************************************************
**
**  İSTANBUL 29 MAYIS ÜNİVERSİTESİ
**  BİLİŞİM TEKNOLOJİLERİ MESLEK YÜKSEKOKULU
**  BÜYÜK VERİ ANALİSTLİĞİ PR.
**  PROGRAMLAMAYA GİRİŞ DERSİ
**  2025-2026 GÜZ DÖNEMİ
**
**  ÖDEV NUMARASI : SORU 3
**  ÖĞRENCİ ADI SOYADI : Kerem PARALI
**  ÖĞRENCİ NUMARASI : 300125024
**
****************************************************************************************/

/********************* C++ KODUNUN ÇIKTISI NEDİR? *************************************/


#include <iostream>
using namespace std;

int main() {

    int sayi = 3;
    // Hesaplamada kullanılacak sabit sayı

    for (int i = 0; i < 4; i++) {
        // Döngü 4 defa çalışacaktır
        // İ değeri ile hesaplanan sonuç ekrana yazdırılır

        cout << "i=" << i << ", sonuc=" << (sayi + i * 2) << endl;
        // Her turda i*2 hesaplanır ve sayi ile toplanarak ekrana yazdırılır
    }

    return 0;
    // Program bitirilir
}
