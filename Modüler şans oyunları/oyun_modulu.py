"""
5. Odev - Modüler Şans Oyunları
KEREM PARALI - 300125024
Ödev toplamda 3 tane dosyadan oluşmaktadır
dosyayı terminalden python main.py yazarak çalıştırdım sonrasında skorlar.csv dosyasına yazdırdım
"""


import random # koddaki oyunlarda rastgele değerler oluşturacağı için random kullandık
import csv # dosyaya veri yazma dosyadan veri okumayı sağlar 

# ------------ SAYI TAHMİN OYUNU --------------
def sayi_tahmin(): 
    sayi = random.randint(1, 100) # 1 ile 100 aralığı verdik
    hak = 7 # 7 tane deneme hakkı verdik

    for i in range(hak): 
        try:
            tahmin = int(input("1-100 arası tahmin gir: ")) # kullanıcıya gösterilen mesaj
        except ValueError: # hata kontrolü
            print("Hatalı giriş! Sayı girmen lazım.") # yazı girilirse sayı girilmesini istiyoruz
            continue

        if tahmin == sayi: # yapılan sayı tahmini seçilen rastgele sayıyla aynıysa 
            print("Doğru bildin! +50 puan") # yazısı yazdırılıp 50 puan eklendi
            return 50
        elif tahmin < sayi: # istenilene uzaklık yakınlık gösteren kod
            print("Daha büyük") # yazdığı sayı seçilen sayıdan büyükse yazdırılan mesaj
        else:
            print("Daha küçük") # eğer küçükse yazdırılan mesaj

    print("Bilemedin! Doğru sayı:", sayi) # doğru sayı random belirleniyor
    return 0


# -----------------YAZI TuRA oyunu ------------
def yazi_tura(): 
    secim = input("Yazı mı Tura mı? ").lower() # kullanıcıya gösterilen mesaj 
    sonuc = random.choice(["yazı", "tura"]) # iki seçenek ile seçim yaptırıyoruz

    print("Sonuç:", sonuc) # yazımı turamı belli oluyor

    if secim == sonuc: # seçim doğruysa
        print("Kazandın! +20 puan") # mesajı yazdırıldı ve +20 puan skorlar.csv dosyasına yazdırılıyor
        return 20 
    else: # doğru değilse kaybettin yazdırdık
        print("Kaybettin!")
        return 0


# ---------- Skor kaydetme kısmı 3. maddde -----------------
def skor_kaydet(oyuncu, oyun, puan): # 3 tane başlık oluşturduk 
    try:
        with open("skorlar.csv", "a", newline="") as file: # skorlar.csv adında dosyayı oluşturdu bunun içine skorlar yazılacak
            writer = csv.writer(file) # writer nesnesini oluşturduk
            writer.writerow([oyuncu, oyun, puan]) # aynı sırayla skorlara yazdırılır
    except FileNotFoundError: # dosya bulamazsa burası çalışacaktır (ezcept = hata yakalama)
        with open("skorlar.csv", "w", newline="") as file: # yazma modunda dosya oluşturduk (bu dosyaya yaz diyoruz)
            writer = csv.writer(file) # writer oluşturduk  
            writer.writerow(["oyuncu", "oyun", "puan"]) # başlık satırlarımız 
            writer.writerow([oyuncu, oyun, puan]) # hangi kişinin hangi oyundan kaç puan aldığını gösteriyor


# ----- SKOR GÖSTER -----
def skor_goster(): # skorları dosyadan okuyup kullanıcının önüne yazdırıyoruz 
    try: # hata kontrolü 
        with open("skorlar.csv", "r") as file: # dosyayı okuma modunda açtık (r = reading)
            reader = csv.reader(file) # dosyayı okumak için reader nesnesini oluşturduk 
            print("\n- SKORLAR -") # başlık
            for row in reader: # her satırı geziyor
                print(row) # satırı ekrana yazdırdık
    except FileNotFoundError: # eğer dosyayı bulamazsa yazdıracağı mesaj
        print("Henüz skor yok.")