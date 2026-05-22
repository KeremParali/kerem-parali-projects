import csv # CSV dosyası oluşturmak için gerekli kütüphane
import random # Rastgele veri üretmek için gerekli kütüphane 
from datetime import datetime, timedelta # Zaman damgası oluşturmak için kütüphane 

# Senaryomuza uygun klinik ve durum listeleri 
klinikler = ["Dahiliye", "Goz", "KBB", "Kardiyoloji", "Noroloji"] 
durumlar = ["Tamamlandi", "Iptal", "Hata"]

def veri_olustur():
    # 'hastane_verisi.csv' isimli dosyayı yazma modunda açıyoruz 
    with open('hastane_verisi.csv', 'w', newline='', encoding='utf-8') as dosya:
        yazici = csv.writer(dosya) # Dosyaya yazma işlemini başlatıyoruz
        # Sütun başlıklarını yazıyoruz: timestamp, patient_id, clinic, waiting_time, status 
        yazici.writerow(["timestamp", "patient_id", "clinic", "waiting_time", "status"])
        
        simdi = datetime.now() # Başlangıç zamanını alıyoruz
        for i in range(60): # Ödevde istenen 50 kayıt sınırını aşarak 60 satır üretiyoruz 
            zaman = (simdi + timedelta(minutes=i)).strftime("%H:%M:%S") # Her kayda farklı zaman veriyoruz 
            hasta_no = 100 + i # Her hastaya benzersiz bir ID veriyoruz 
            bolum = random.choice(klinikler) # Listeden rastgele bir klinik seçiyoruz 
            bekleme = random.randint(10, 90) # 10-90 arası rastgele bekleme süresi (dakika) 
            sonuc = random.choice(durumlar) # Randevu durumunu rastgele seçiyoruz 
            
            # Oluşturulan satırı dosyaya kaydediyoruz 
            yazici.writerow([zaman, hasta_no, bolum, bekleme, sonuc])

if __name__ == "__main__":
    veri_olustur() # Fonksiyonu çalıştırıyoruz
    print("Veri dosyasi basariyla olusturuldu.") # İşlem bittiğinde mesaj veriyoruz