/***************************************************************
**  İstanbul 29 Mayıs Üniversitesi
**  Bilgisayar ve Bilişim Bilimleri Fakültesi
**  Büyük Veri Analistliği Programı
**  Programlamaya Giriş Dersi Projesi
**
**  Öğrenci Adı     : Kerem Paralı
**  Öğrenci No      : 300125024
**
**  Bu program basit bir otel otomasyonu mantığıyla
**  oda, müşteri ve oda kayıt işlemlerini yapmaktadır.
***************************************************************/

#include <iostream>   // Ekrana yazdırma ve klavyeden veri alma
#include <fstream>    // Dosya işlemleri
#include <string>     // String veri tipi

using namespace std;

/* ODA bilgilerini tutan yapı */
struct Oda
{
    int odaNo;     // Odanın numarası
    int ucret;     // Odanın gecelik ücreti
    bool doluMu;   // Odanın dolu olup olmadığı
};

/* MUSTERI bilgilerini tutan yapı */
struct Musteri
{
    int musteriNo; // Müşteri numarası
    string ad;     // Müşteri adı
    string soyad;  // Müşteri soyadı
    string tc;     // TC kimlik numarası
};

/* Yeni oda kaydı alan fonksiyon */
void OdaEkle()
{
    Oda oda;
    ofstream dosya("odalar.txt", ios::app); // Dosya ekleme modunda açılır

    cout << "Oda Numarasi : ";
    cin >> oda.odaNo;

    cout << "Oda Ucreti   : ";
    cin >> oda.ucret;

    oda.doluMu = false; // Yeni eklenen oda boş kabul edilir

    // Oda bilgileri dosyaya yazılır
    dosya << oda.odaNo << " "
        << oda.ucret << " "
        << oda.doluMu << endl;

    dosya.close();
    cout << "Oda basariyla eklendi.\n";
}

/* Kayıtlı odaları ekranda listeleyen fonksiyon */
void OdalariListele()
{
    Oda oda;
    ifstream dosya("odalar.txt");

    cout << "\nOdaNo  Ucret  Durum\n";
    cout << "-------------------\n";

    // Dosyanin sonuna kadar tum kayitlari okumak icin while dongusu kullanildi
    while (dosya >> oda.odaNo >> oda.ucret >> oda.doluMu)
    {
        cout << oda.odaNo << "    "
            << oda.ucret << "    "
            << (oda.doluMu ? "Dolu" : "Bos") << endl;
    }

    dosya.close();
}

/* Yeni müşteri kaydı alan fonksiyon */
void MusteriEkle()
{
    Musteri m;
    ofstream dosya("musteriler.txt", ios::app);

    cout << "Musteri No : ";
    cin >> m.musteriNo;

    cout << "Ad         : ";
    cin >> m.ad;

    cout << "Soyad      : ";
    cin >> m.soyad;

    cout << "TC No      : ";
    cin >> m.tc;

    // Müşteri bilgileri dosyaya yazılır
    dosya << m.musteriNo << " "
        << m.ad << " "
        << m.soyad << " "
        << m.tc << endl;

    dosya.close();
    cout << "Musteri eklendi.\n";
}

/* Müşterileri listeleyen fonksiyon */
void MusterileriListele()
{
    // Dosyadan daha once kaydedilen bilgileri okumak icin ifstream kullaniyoruz
    Musteri m;
    ifstream dosya("musteriler.txt");

    cout << "\nNo  Ad  Soyad  TC\n";
    cout << "-----------------\n";

    while (dosya >> m.musteriNo >> m.ad >> m.soyad >> m.tc)
    {
        cout << m.musteriNo << "  "
            << m.ad << "  "
            << m.soyad << "  "
            << m.tc << endl;
    }

    dosya.close();
}

/* Odaya müşteri atama işlemi */
void OdaKaydiYap()
{
    int odaNo, musteriNo;
    ofstream dosya("kayitlar.txt", ios::app);

    cout << "Oda Numarasi     : ";
    cin >> odaNo;

    cout << "Musteri Numarasi : ";
    cin >> musteriNo;

    // Oda ve müşteri eşleştirmesi kaydedilir
    dosya << odaNo << " " << musteriNo << endl;

    dosya.close();
    cout << "Oda kaydi basariyla yapildi.\n";
}

/* Yapılan oda kayıtlarını listeleyen fonksiyon */
void KayitlariListele()
{
    int odaNo, musteriNo;
    ifstream dosya("kayitlar.txt");

    cout << "\nOdaNo  MusteriNo\n";
    cout << "----------------\n";

    while (dosya >> odaNo >> musteriNo)
    {
        cout << odaNo << "      " << musteriNo << endl;
    }

    dosya.close();
}

int main()
{
    int secim, altSecim;

    do
    {
        // Ana menü
        cout << "\nOtel Islemleri\n";
        cout << "------------------\n";
        cout << "1- Oda Islemleri\n";
        cout << "2- Musteri Islemleri\n";
        cout << "3- Oda Kayit Islemleri\n";
        cout << "99- Cikis\n";
        cout << "Seciminiz : ";
        cin >> secim;

        switch (secim)
        {
        case 1:
            cout << "\n1- Oda Ekle\n";
            cout << "2- Odalari Listele\n";
            cout << "99- Ust Menu\n";
            cin >> altSecim;

            if (altSecim == 1)
                OdaEkle();
            else if (altSecim == 2)
                OdalariListele();
            else if (altSecim != 99)
                cout << "Hatali Secim\n";
            break;

        case 2:
            cout << "\n1- Musteri Ekle\n";
            cout << "2- Musterileri Listele\n";
            cout << "99- Ust Menu\n";
            cin >> altSecim;

            if (altSecim == 1)
                MusteriEkle();
            else if (altSecim == 2)
                MusterileriListele();
            else if (altSecim != 99)
                cout << "Hatali Secim\n";
            break;

        case 3:
            cout << "\n1- Odaya Musteri Ata\n";
            cout << "2- Kayitlari Listele\n";
            cout << "99- Ust Menu\n";
            cin >> altSecim;

            if (altSecim == 1)
                OdaKaydiYap();
            else if (altSecim == 2)
                KayitlariListele();
            else if (altSecim != 99)
                cout << "Hatali Secim\n";
            break;

        case 99:
            cout << "Programdan cikiliyor...\n";
            break;

        default:
            cout << "Hatali Secim\n";
        }

    } while (secim != 99);

    return 0;
}
