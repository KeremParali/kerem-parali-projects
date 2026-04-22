/****************************************************************************************
**
**  ÝSTANBUL 29 MAYIS ÜNÝVERSÝTESÝ
**  BÝLÝÞÝM TEKNOLOJÝLERÝ MESLEK YÜKSEKOKULU
**  BÜYÜK VERÝ ANALÝSTLÝÐÝ PR.
**  PROGRAMLAMAYA GÝRÝÞ DERSÝ
**  2025-2026 GÜZ DÖNEMÝ
**
**  ÖDEV NUMARASI : SORU 10
**  ÖÐRENCÝ ADI SOYADI : Kerem PARALI
**  ÖÐRENCÝ NUMARASI : 300125024
**
****************************************************************************************/

/******************************** 10.SORU **********************************************
5 öðrencinin Vize, Kýsa Sýnav ve Final notlarýný klavyeden C++ programýný yazýnýz.Program:
1. Her öðrencinin aðýrlýklý ortalamasýný hesaplamalý(Vize % 30, Kýsa Sýnav % 10, Final
    % 60)
    2. Sýnýf ortalamasýný bulmalý
    3. En baþarýlý öðrenciyi ve ortalamasýný göstermeli
**************************************************************************************/



#include <iostream>
using namespace std;

int main() {

    const int ogrenciSayisi = 5;
    // Toplam öðrenci sayýsýný belirledim

    double vize, kisa, final;
    // Notlarý tutmak için deðiþkenler

    double ortalama;
    // Her öðrencinin aðýrlýklý ortalamasý

    double sinifToplam = 0;
    // Sýnýf ortalamasýný hesaplamak için toplam

    double enYuksekOrt = 0;
    // En yüksek ortalamayý tutmak için

    int enBasariliOgrenci = 0;
    // En baþarýlý öðrencinin numarasýný tutar

    cout << "=== OGRENCI NOT SISTEMI ===" << endl;
    cout << "Not Hesaplama: Vize (%30) + Kisa Sinav (%10) + Final (%60)" << endl << endl;
    // Program baþlýðý ve açýklama yazdýrýlýr

    for (int i = 1; i <= ogrenciSayisi; i++) {
        // 5 öðrenci için döngü baþlatýlýr

        cout << i << ". Ogrencinin notlarini giriniz:" << endl;

        cout << "Vize notu: ";
        cin >> vize;
        // Vize notu alýnýr

        cout << "Kisa Sinav notu: ";
        cin >> kisa;
        // Kýsa sýnav notu alýnýr

        cout << "Final notu: ";
        cin >> final;
        // Final notu alýnýr

        ortalama = vize * 0.30 + kisa * 0.10 + final * 0.60;
        // Aðýrlýklý ortalama hesaplanýr

        cout << "Agirlikli Ortalama: " << ortalama << endl << endl;
        // Öðrencinin ortalamasý ekrana yazdýrýlýr

        sinifToplam += ortalama;
        // Sýnýf toplamýna eklenir

        if (ortalama > enYuksekOrt) {
            // Eðer bu öðrenci daha baþarýlýysa
            enYuksekOrt = ortalama;
            // En yüksek ortalama güncellenir
            enBasariliOgrenci = i;
            // Öðrenci numarasý saklanýr
        }
    }

    double sinifOrt = sinifToplam / ogrenciSayisi;
    // Sýnýf ortalamasý hesaplanýr

    cout << "=== SONUCLAR ===" << endl;
    cout << "Sinif Ortalamasi: " << sinifOrt << endl;
    // Sýnýf ortalamasý yazdýrýlýr

    cout << "En Basarili Ogrenci: " << enBasariliOgrenci
        << ". Ogrenci (Ortalama: " << enYuksekOrt << ")" << endl;
    // En baþarýlý öðrenci bilgisi yazdýrýlýr

    return 0;
}
