"""
5. Odev - Modüler Şans Oyunları menü kısmı
KEREM PARALI - 300125024
"""


import oyun_modulu as oyun # oyun_modulu dosyaya bağlı

def menu(): # menü kısmı
    print("\n--- ŞANS OYUNLARI ---")
    print("1. Sayı Tahmin Oyunu")
    print("2. Yazı-Tura Oyunu")
    print("3. Skor Listesi")
    print("4. Çıkış")


oyuncu = input("İsmini gir: ") # kullanıcdan isim istedik

while True: 
    menu()
    secim = input("Seçim yap: ") # sayılarla hangi oyunu oynayacağını seçtirdik
 
    if secim == "1": # 1i seçerse sayı tahmin
        puan = oyun.sayi_tahmin()
        oyun.skor_kaydet(oyuncu, "Sayi Tahmin", puan)

    elif secim == "2": # 2 yazı tura
        puan = oyun.yazi_tura()
        oyun.skor_kaydet(oyuncu, "Yazi Tura", puan)

    elif secim == "3": # 3 skor listesi
        oyun.skor_goster()

    elif secim == "4": # programdan çıkış yapıyor
        print("Çıkılıyor...") 
        break

    else: # 1-4 den farklı sayı yazarsa yazıcak mesaj
        print("Hatalı seçim!")