/****************************************************************************************
**
**  ÝSTANBUL 29 MAYIS ÜNÝVERSÝTESÝ
**  BÝLÝÞÝM TEKNOLOJÝLERÝ MESLEK YÜKSEKOKULU
**  BÜYÜK VERÝ ANALÝSTLÝÐÝ PR.
**  PROGRAMLAMAYA GÝRÝÞ DERSÝ
**  2025-2026 GÜZ DÖNEMÝ
**
**  ÖDEV NUMARASI : SORU 8
**  ÖÐRENCÝ ADI SOYADI : Kerem PARALI
**  ÖÐRENCÝ NUMARASI : 300125024
**
****************************************************************************************/


/***************************** ÞÝFRE DOÐRULAMA PROGRAMI *********************************/



#include <iostream>
using namespace std;

int main() {

    int dogruSifre = 2025;
    // Doðru þifreyi belirledim

    int girilenSifre;
    // Kullanýcýnýn gireceði þifre

    bool girisBasarili = false;
    // Þifrenin doðru olup olmadýðýný tutmak için deðiþken

    for (int hak = 5; hak > 0; hak--) {
        // Kullanýcýya 5 hak tanýyorum

        cout << "Sifreyi giriniz: ";
        cin >> girilenSifre;
        // Kullanýcýdan þifre alýyorum

        if (girilenSifre == dogruSifre) {
            // Girilen þifre doðruysa
            cout << "Giris basarili" << endl;
            // Baþarýlý giriþ mesajý
            girisBasarili = true;
            // Giriþ baþarýlý olarak iþaretlenir
            break;
            // Döngüden çýkýlýr
        }
        else {
            // Þifre yanlýþsa
            cout << "Hatali sifre. Kalan hak: " << hak - 1 << endl;
            // Kalan hak ekrana yazdýrýlýr
        }
    }

    if (!girisBasarili) {
        // Eðer giriþ baþarýlý olmadýysa
        cout << "Hesap kilitlendi" << endl;
        // Hesabýn kilitlendiði yazdýrýlýr
    }

    return 0;
}


