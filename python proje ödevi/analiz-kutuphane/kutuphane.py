"""
PYTHON DÖNEM PROJESİ
Nesneye Yönelik Veri Ön İşleme Aracı
KEREM PARALI
NO:300125024
Bu projede Titanic veri seti kullanılarak,
veri temizleme ve analiz işlemleri OOP mantığıyla yapılmıştır.
(kutuphane.py)
(OPP =Nesne Yönelimli Programlama)
"""
# Pandas veri işlemleri için kullanılır
import pandas as pd

# Grafik çizmek için kullanılır
import matplotlib.pyplot as plt


# Veri ön işleme sınıfı
class DataPreprocessor:

    # Constructor metodu
    # CSV dosyasını okuyup private değişkende saklar
    def __init__(self, dosya_yolu):

        # CSV dosyasını oku
        self.__veri = pd.read_csv(dosya_yolu)

    # Veri setinin genel özetini gösterir
    def veri_ozeti(self):

        # İlk 5 satırı göstermesini istiyoruz
        print("İlk 5 Satır:")
        print(self.__veri.head())

        # Veri tipi ve sütun bilgileri
        print("\nBilgiler:")
        self.__veri.info()

        # Sayısal sütunların istatistiksel özeti
        print("\nİstatistiksel Özet:")
        print(self.__veri.describe())

    # Eksik verileri kontrol eder
    def eksik_veri_kontrolu(self):

        # Hangi sütunda kaç eksik veri olduğunu gösterir
        print("\nEksik Veri Sayıları:")
        print(self.__veri.isnull().sum())

    # Eksik verileri mean veya median ile doldurur
    def eksikleri_doldur(self, strateji='mean'):

        # Sayısal sütunları seç
        sayisal_sutunlar = self.__veri.select_dtypes(include='number').columns

        # Her sütun için işlem yap
        for sutun in sayisal_sutunlar:

            # Ortalama ile doldurma
            if strateji == 'mean':
                deger = self.__veri[sutun].mean()

            # Medyan ile doldurma kısmı
            elif strateji == 'median':
                deger = self.__veri[sutun].median()

            # Eksik verileri doldur
            self.__veri[sutun].fillna(deger, inplace=True)

        print("\nEksik veriler dolduruldu.")

    # İstenilen sütunu siler
    def sutun_sil(self, sutun_adi):

        # Sütunu veri setinden kaldır
        self.__veri.drop(columns=[sutun_adi], inplace=True)

        print(f"{sutun_adi} sütunu silindi.")

    # Histogram grafiği çizer
    def dagilim_ciz(self, sutun_adi):

        # Histogram oluştur
        self.__veri[sutun_adi].hist()

        # Grafik başlığı
        plt.title(f"{sutun_adi} Dağılımı")

        # X ekseni adı
        plt.xlabel(sutun_adi)

        # Y ekseni adı
        plt.ylabel("Frekans")

        # Grafiği göster
        plt.show()

    # Temizlenmiş veriyi CSV olarak kaydeder
    def veriyi_kaydet(self, dosya_adi):

        # CSV dosyasına kaydet
        self.__veri.to_csv(dosya_adi, index=False)

        print("Veri kaydedildi.")