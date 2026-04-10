/****************************************************************************************
**
**  İSTANBUL 29 MAYIS ÜNİVERSİTESİ
**  BİLİŞİM TEKNOLOJİLERİ MESLEK YÜKSEKOKULU
**  BÜYÜK VERİ ANALİSTLİĞİ PR.
**  PROGRAMLAMAYA GİRİŞ DERSİ
**  2025-2026 GÜZ DÖNEMİ
**
**  ÖDEV NUMARASI : SORU 8
**  ÖĞRENCİ ADI SOYADI : Kerem PARALI
**  ÖĞRENCİ NUMARASI : 300125024
**
****************************************************************************************/


/***************************** ŞİFRE DOĞRULAMA PROGRAMI *********************************/



#include <iostream>
using namespace std;

int main() {

    int dogruSifre = 2025;
    // Doğru şifreyi belirledim

    int girilenSifre;
    // Kullanıcının gireceği şifre

    bool girisBasarili = false;
    // Şifrenin doğru olup olmadığını tutmak için değişken

    for (int hak = 5; hak > 0; hak--) {
        // Kullanıcıya 5 hak tanıyorum

        cout << "Sifreyi giriniz: ";
        cin >> girilenSifre;
        // Kullanıcıdan şifre alıyorum

        if (girilenSifre == dogruSifre) {
            // Girilen şifre doğruysa
            cout << "Giris basarili" << endl;
            // Başarılı giriş mesajı
            girisBasarili = true;
            // Giriş başarılı olarak işaretlenir
            break;
            // Döngüden çıkılır
        }
        else {
            // Şifre yanlışsa
            cout << "Hatali sifre. Kalan hak: " << hak - 1 << endl;
            // Kalan hak ekrana yazdırılır
        }
    }

    if (!girisBasarili) {
        // Eğer giriş başarılı olmadıysa
        cout << "Hesap kilitlendi" << endl;
        // Hesabın kilitlendiği yazdırılır
    }

    return 0;
}


