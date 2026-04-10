/****************************************************************************************
**
**  ÝSTANBUL 29 MAYIS ÜNÝVERSÝTESÝ
**  BÝLÝÞÝM TEKNOLOJÝLERÝ MESLEK YÜKSEKOKULU
**  BÜYÜK VERÝ ANALÝSTLÝÐÝ PR.
**  PROGRAMLAMAYA GÝRÝÞ DERSÝ
**  2025-2026 GÜZ DÖNEMÝ
**
**  ÖDEV NUMARASI : SORU 9
**  ÖÐRENCÝ ADI SOYADI : Kerem PARALI
**  ÖÐRENCÝ NUMARASI : 300125024
**
****************************************************************************************/


/********************** KARE MATRÝS PROGRAMI *************************************/



#include <iostream>
#include <cstdlib>
using namespace std;

int main() {

    system("cls");
    // Ekraný temizlemek için kullandým

    int n;
    // Matrisin satýr ve sütun sayýsý (kare matris)

    cout << "...::: Matris Islemleri :::..." << endl;
    // Baþlýk ekrana yazdýrýlýr

    cout << "Matrisin satir sayisini giriniz (1-10 arasinda): ";
    cin >> n;
    // Kullanýcýdan matris boyutu alýnýr

    int matris[10][10];
    // En fazla 10x10 olacak þekilde matris tanýmladým

    int sayac = 1;
    // Matrisi doldurmak için sayaç tanýmladým

    for (int i = 0; i < n; i++) {
        // Satýrlar için döngü

        for (int j = 0; j < n; j++) {
            // Sütunlar için döngü

            matris[i][j] = sayac;
            // Matrise sýrayla deðer atadým

            cout << "[" << i + 1 << "," << j + 1 << "]=" << sayac << endl;
            // Girilen deðerleri ekrana gösterdim

            sayac++;
            // Sayacý artýrdým
        }
    }

    cout << endl;
    // Matris yazdýrýlmadan önce boþluk býrakýlýr

    for (int i = 0; i < n; i++) {
        // Matrisi ekrana yazdýrmak için

        for (int j = 0; j < n; j++) {
            cout << matris[i][j] << " ";
            // Matris elemanlarý ekrana yazdýrýlýr
        }
        cout << endl;
        // Satýr sonuna geçilir
    }

    return 0;
}

