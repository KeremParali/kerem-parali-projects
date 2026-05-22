import random
import csv


# ------------ SAYI TAHMİN OYUNU --------------
def sayi_tahmin():
    sayi = random.randint(1, 100)
    hak = 7

    for i in range(hak):
        try:
            tahmin = int(input("1-100 arası tahmin gir: "))
        except ValueError:
            print("Hatalı giriş! Sayı girmen lazım.")
            continue

        if tahmin == sayi:
            print("Doğru bildin! +50 puan")
            return 50
        elif tahmin < sayi:
            print("Daha büyük")
        else:
            print("Daha küçük")

    print("Bilemedin! Doğru sayı:", sayi)
    return 0


# ----------------- YAZI TURA OYUNU -----------------
def yazi_tura():
    secim = input("Yazı mı Tura mı? ").lower()
    sonuc = random.choice(["yazı", "tura"])

    print("Sonuç:", sonuc)

    if secim == sonuc:
        print("Kazandın! +20 puan")
        return 20
    else:
        print("Kaybettin!")
        return 0


# ---------- SKOR KAYDETME ----------
def skor_kaydet(oyuncu, oyun, puan):
    try:
        with open("skorlar.csv", "a", newline="") as file:
            writer = csv.writer(file)
            writer.writerow([oyuncu, oyun, puan])

    except FileNotFoundError:
        with open("skorlar.csv", "w", newline="") as file:
            writer = csv.writer(file)
            writer.writerow(["oyuncu", "oyun", "puan"])
            writer.writerow([oyuncu, oyun, puan])


# ---------- SKOR GÖSTERME ----------
def skor_goster():
    try:
        with open("skorlar.csv", "r") as file:
            reader = csv.reader(file)

            print("\n- SKORLAR -")

            for row in reader:
                print(row)

    except FileNotFoundError:
        print("Henüz skor yok.")