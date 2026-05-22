""" 6. Odev - Araç Kiralama Sistemi
    KEREM PARALI
    300125024
    # Bu proje araç kiralama sistemidir.
    # Araç listeleme, kiralama ve gelir hesaplama işlemleri yapılmaktadır.
    # Proje OOP ve abstract class yapısıyla hazırlanmıştır.
    """
# main.py

# entities.py içindeki classları içe aktarıyoruxz
from entities import Binek, Ticari, Lux


# Araç listesi oluşturuldu
araclar = [

    Binek("34ABC123", "Toyota", "Corolla"),
    Binek("34XYZ456", "Honda", "Civic"),

    Ticari("06TCR789", "Ford", "Transit"),
    Ticari("35TCR111", "Mercedes", "Sprinter"),

    Lux("34LUX999", "AUDİ", "RS6"),
    Lux("34VIP888", "Mercedes", "S500")
]


# Menü sürekli dönsün diye while kullanıldı
while True:

    print("\n===== ARAÇ KİRALAMA SİSTEMİ =====")
    print("1. Kiralanabilir araçları listele")
    print("2. Araç kirala")
    print("3. Toplam günlük gelir hesapla")
    print("4. Çıkış")

    secim = input("Seçiminizi girin: ")

    # 1. seçenek
    if secim == "1":

        print("\n--- Müsait Araçlar ---")

        bulundu = False

        # Araçları dolaşıyoruz
        for arac in araclar:

            # Sadece müsait olanlar gösterilecek
            if arac.musait:
                arac.bilgileri_goster()
                bulundu = True

        # Eğer hiç araç yoksa bulunamadı yazdır 
        if not bulundu:
            print("Müsait araç bulunamadı.")


    # 2. seçenek
    elif secim == "2":

        plaka = input("Kiralamak istediğiniz aracın plakasını girin: ")

        arac_bulundu = False

        # Listedeki araçlarda arama yapılıyor
        for arac in araclar:

            # Büyük küçük harf sorunu olmaması için upper kullanıldı
            if arac.plaka.upper() == plaka.upper():

                arac.kirala()
                arac_bulundu = True
                break

        if not arac_bulundu:
            print("Bu plakaya ait araç bulunamadı.")


    # 3. seçenek
    elif secim == "3":

        toplam_gelir = 0

        # Kiralanan araçların ücretleri toplanıyor
        for arac in araclar:

            # musait False ise kiralanmış demektir
            if arac.musait == False:
                toplam_gelir += arac.gunluk_ucret()

        print("Toplam günlük gelir:", toplam_gelir, "TL")


    # 4. seçenek
    elif secim == "4":

        print("Programdan çıkılıyor...")
        break


    # Hatalı giriş kontrolü
    else:
        print("Hatalı seçim yaptınız. Tekrar deneyin.")
