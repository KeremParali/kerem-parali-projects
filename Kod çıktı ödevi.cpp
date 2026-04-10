/****************************************************************************************
**
**  İSTANBUL 29 MAYIS ÜNİVERSİTESİ
**  BİLİŞİM TEKNOLOJİLERİ MESLEK YÜKSEKOKULU
**  BÜYÜK VERİ ANALİSTLİĞİ PR.
**  PROGRAMLAMAYA GİRİŞ DERSİ
**  2025-2026 GÜZ DÖNEMİ
**
**  ÖDEV NUMARASI : SORU 1
**  ÖĞRENCİ ADI SOYADI : Kerem PARALI
**  ÖĞRENCİ NUMARASI : 300125024
**
****************************************************************************************/

/********************* C++ KODUNUN ÇIKTISI NEDİR? *************************************/


#include <iostream>
using namespace std;

int main() {

    int sayi1 = 20;     // Birinci tam sayı
    int sayi2 = 7;      // İkinci tam sayı
    int sayi3 = 3;      // Üçüncü tam sayı

    // İki tam sayı bölündüğü için sonuç tam sayı olur, küsürat kısmı atılır.
    float sonuc1 = sayi1 / sayi2;

    // sayi1 float'a çevrilir, ondalıklı bölme yapılır.
    float sonuc2 = (float)sayi1 / sayi3;

    // Hesaplanan sonuçlar ekrana yazdırılır
    cout << sonuc1 << endl;
    cout << sonuc2 << endl;

    return 0;           // Program başarıyla sonlandırılır.
}

