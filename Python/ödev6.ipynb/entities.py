""" 6. Odev - Araç Kiralama Sistemi
    KEREM PARALI
    300125024
    # Bu proje araç kiralama sistemidir.
    # Araç listeleme, kiralama ve gelir hesaplama işlemleri yapılmaktadır.
    # Proje OOP ve abstract class yapısıyla hazırlanmıştır.
    """


# entities.py

# abc modülü abstract class kullanmak için gerekli
from abc import ABC, abstractmethod


# Parent Class (Abstract Class)
class Arac(ABC):

    # Constructor metodu
    def __init__(self, plaka, marka, model, musait=True):
        self.plaka = plaka
        self.marka = marka
        self.model = model
        self.musait = musait

    # Her araç tipi kendi günlük ücretini belirleyecek
    @abstractmethod
    def gunluk_ucret(self):
        pass

    # Araç kiralama metodu
    def kirala(self):

        # Eğer araç müsaitse kiralanır
        if self.musait:
            self.musait = False
            print(f"{self.plaka} plakalı araç kiralandı.")
        else: # eğer değilse 
            print("Bu araç zaten kiralanmış.")

    # Araç bilgilerini ekrana yazdırır
    def bilgileri_goster(self):

        # Durum kontrolü
        durum = "Müsait" if self.musait else "Kiralanmış"

        print("----------------------------")
        print("Plaka:", self.plaka)
        print("Marka:", self.marka)
        print("Model:", self.model)
        print("Durum:", durum)
        print("Günlük Ücret:", self.gunluk_ucret(), "TL")
        print("----------------------------")


# Binek sınıfı
class Binek(Arac):

    # Parent constructor çağrılıyor
    def __init__(self, plaka, marka, model):
        super().__init__(plaka, marka, model)

    # Günlük ücret
    def gunluk_ucret(self):
        return 1000


# Ticari sınıfı
class Ticari(Arac):

    def __init__(self, plaka, marka, model):
        super().__init__(plaka, marka, model) # super init üst sınıftaki özellikleri almak için kullanılır.

    def gunluk_ucret(self):
        return 1500


# Lüks sınıfı
class Lux(Arac):

    def __init__(self, plaka, marka, model):
        super().__init__(plaka, marka, model)

    def gunluk_ucret(self):
        return 3000
    
    # self -> Sınıfın kendi değişkenlerine erişmek için kullanılır.
    # @abstractmethod -> Alt sınıflarda zorunlu metod oluşturur.
    # if -> Koşul kontrolü yapar.

