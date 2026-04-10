/****************************************************************************************
**
**  ÝSTANBUL 29 MAYIS ÜNÝVERSÝTESÝ
**  BÝLÝÞÝM TEKNOLOJÝLERÝ MESLEK YÜKSEKOKULU
**  BÜYÜK VERÝ ANALÝSTLÝÐÝ PR.
**  PROGRAMLAMAYA GÝRÝÞ DERSÝ
**  2025-2026 GÜZ DÖNEMÝ
**
**  ÖDEV NUMARASI : SORU 4
**  ÖÐRENCÝ ADI SOYADI : Kerem PARALI
**  ÖÐRENCÝ NUMARASI : 300125024
**
****************************************************************************************/



#include <iostream>
using namespace std;

int main() {

int x = 8, y = 2;
// x ve y deðiþkenlerini baþlangýç deðerleriyle tanýmladým

x *= y + 1;
// Önce y+1 hesaplanýr (3)
// x = 8 * 3 olur ve x 24’e eþitlenir

cout << x / y << endl;
// 24 / 2 iþlemi yapýlýr ve 12 ekrana yazdýrýlýr

cout << ++x << endl;
// x önce 1 artýrýlýr, sonra ekrana yazdýrýlýr (25)

cout << x << endl;
// x’in güncel deðeri tekrar yazdýrýlýr (25)


return 0;
}

