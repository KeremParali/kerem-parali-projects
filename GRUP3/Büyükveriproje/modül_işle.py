import csv # CSV okumak için kütüphane
import time # Akış simülasyonu (bekleme) için kütüphane 

def veri_isle():
    toplam_kayit = 0 # Toplam işlem sayısı metriği 
    geciken_hasta = 0 # Gecikme metriği 
    
    print("--- Canli Veri Akisi Basladi ---") # Akışın başladığını belirtiyoruz 
    
    # Oluşturduğumuz veri dosyasını okuma modunda açıyoruz 
    with open('hastane_verisi.csv', 'r', encoding='utf-8') as dosya:
        okuyucu = csv.DictReader(dosya) # Verileri sözlük formatında okuyoruz
        
        for satir in okuyucu: # Her bir satırı (olayı) tek tek dönüyoruz
            time.sleep(0.6) # Verinin 'akıyor' gibi görünmesi için yarım saniye bekliyoruz 
            toplam_kayit += 1 # Her satırda toplam kaydı 1 artırıyoruz 
            
            bekleme_suresi = int(satir['waiting_time']) # Bekleme süresini sayıya çeviriyoruz
            
            # ANLIK ÇIKTI: Terminale o anki veriyi basıyoruz 
            print(f"Zaman: {satir['timestamp']} | Hasta: {satir['patient_id']} | Bolum: {satir['clinic']} | Sure: {bekleme_suresi} dk")
            
            # ALERT (UYARI): Bekleme süresi 60 dk'yı aşarsa uyarı veriyoruz 
            if bekleme_suresi > 60: 
                geciken_hasta += 1 # Geciken hasta sayısını artırıyoruz
                print(f"  >>> [UYARI] {satir['clinic']} bolumunde kritik bekleme suresi asildi!") # Uyarı mesajı 

    # BATCH REPORT: Tüm akış bittiğinde özet rapor sunuyoruz 
    print("\n" + "="*30)
    print("--- GUNLUK ANALIZ RAPORU ---") # Rapor başlığı 
    print(f"Toplam Islenen Kayit: {toplam_kayit}") # Toplam kayıt sayısı 
    print(f"Kritik Gecikme Sayisi: {geciken_hasta}") # Gecikme analizi sonucu 
    print(f"Gecikme Orani: %{(geciken_hasta/toplam_kayit)*100:.2f}") # Oransal analiz 
    print("="*30)

if __name__ == "__main__":
    veri_isle() # Analiz fonksiyonunu başlatıyoruz