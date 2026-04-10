/****************************************************************************************
**
**  İSTANBUL 29 MAYIS ÜNİVERSİTESİ
**  BİLİŞİM TEKNOLOJİLERİ MESLEK YÜKSEKOKULU
**  BÜYÜK VERİ ANALİSTLİĞİ PR.
**  PROGRAMLAMAYA GİRİŞ DERSİ
**  2025-2026 GÜZ DÖNEMİ
**
**  ÖDEV NUMARASI : SORU 2
**  ÖĞRENCİ ADI SOYADI : Kerem PARALI
**  ÖĞRENCİ NUMARASI : 300125024
**
****************************************************************************************/


/********************* C++ KODUNUN ÇIKTISI NEDİR? *************************************/



#include <iostream>
using namespace std;

int main() {
    int arr[] = { 2, 4, 6, 8, 10 };
    // İçinde 5 tane sayı olan bir dizi tanımladım

    int toplam = 0;
    // Sonucu tutmak için toplam değişkenini 0 yaptım

    for (int i = 0; i < 5; i++) {
        // Dizinin tüm elemanlarını tek tek kontrol ediyorum

        if (arr[i] % 4 == 0) {
            // Eğer sayı 4’e tam bölünüyorsa

            toplam += arr[i];
            // O sayıyı toplama ekliyorum
        }
    }

    cout << "Sonuc: " << toplam << endl;
    // 4’e bölünen sayılar 4 ve 8 olduğu için sonuç 12 olur

    return 0;
}

