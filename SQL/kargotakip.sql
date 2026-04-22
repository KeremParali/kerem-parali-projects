-- VERİTABANI TEKNOLOJİLERİ LAB
-- Kargo ve Teslimat Takip Sistemi
-- Derste yapılan çalışma

--------------------------------------------------
-- 1) Veritabanı oluşturma
--------------------------------------------------
CREATE DATABASE KargoTakip;

USE KargoTakip;


--------------------------------------------------
-- 2) Musteri tablosu
-- Müşterilerin bilgileri tutulur
--------------------------------------------------
CREATE TABLE musteri(
    musteri_id INT PRIMARY KEY IDENTITY(1,1),
    ad_soyad VARCHAR(80),
    sehir VARCHAR(50),
    telefon VARCHAR(20)
);


--------------------------------------------------
-- 3) Kurye tablosu
-- Kuryelerin bilgileri tutulur
--------------------------------------------------
CREATE TABLE kurye(
    kurye_id INT PRIMARY KEY IDENTITY(1,1),
    ad_soyad VARCHAR(80),
    bolge VARCHAR(50),
    deneyim_yili INT
);


--------------------------------------------------
-- 4) Gonderi tablosu
-- Gönderiler burada tutulur
--------------------------------------------------
CREATE TABLE gonderi(
    gonderi_id INT PRIMARY KEY IDENTITY(1,1),
    musteri_id INT,
    gonderi_turu VARCHAR(50),
    ucret INT,
    cikis_tarihi DATE,

    FOREIGN KEY (musteri_id) REFERENCES musteri(musteri_id)
);


--------------------------------------------------
-- 5) Teslimat tablosu
-- Hangi gönderiyi hangi kurye teslim etti
--------------------------------------------------
CREATE TABLE teslimat(
    teslimat_id INT PRIMARY KEY IDENTITY(1,1),
    gonderi_id INT,
    kurye_id INT,
    teslim_durumu VARCHAR(50),
    teslim_tarihi DATE,

    FOREIGN KEY (gonderi_id) REFERENCES gonderi(gonderi_id),
    FOREIGN KEY (kurye_id) REFERENCES kurye(kurye_id)
);


--------------------------------------------------
-- 6) Veri ekleme
--------------------------------------------------

-- Musteriler
INSERT INTO musteri(ad_soyad, sehir, telefon) VALUES
('Ayşe Yılmaz', 'İstanbul', '05001112233'),
('Ali Demir', 'Ankara', '05002223344'),
('Zeynep Kaya', 'İzmir', '05003334455');


-- Kuryeler
INSERT INTO kurye(ad_soyad, bolge, deneyim_yili) VALUES
('Mehmet Çelik', 'İstanbul', 5),
('Ahmet Kaya', 'Ankara', 3),
('Can Yıldız', 'İzmir', 4);


-- Gönderiler
INSERT INTO gonderi(musteri_id, gonderi_turu, ucret, cikis_tarihi) VALUES
(1, 'Standart', 100, '2026-03-10'),
(2, 'Express', 200, '2026-03-11'),
(3, 'Standart', 150, '2026-03-12');


-- Teslimatlar
INSERT INTO teslimat(gonderi_id, kurye_id, teslim_durumu, teslim_tarihi) VALUES
(1, 1, 'Teslim Edildi', '2026-03-12'),
(2, 2, 'Yolda', NULL),
(3, 3, 'Teslim Edildi', '2026-03-13');


--------------------------------------------------
-- 7) Deneme sorguları (derste bakmak için)
--------------------------------------------------

-- Tüm müşteriler
SELECT * FROM musteri;

-- Gönderi + müşteri bilgisi
SELECT m.ad_soyad, g.gonderi_turu, g.ucret
FROM gonderi g
JOIN musteri m ON g.musteri_id = m.musteri_id;

-- Teslim edilenler
SELECT *
FROM teslimat
WHERE teslim_durumu = 'Teslim Edildi';

-- Toplam ücret
SELECT SUM(ucret) AS toplam
FROM gonderi;

-- Şehre göre müşteri sayısı
SELECT sehir, COUNT(*) 
FROM musteri
GROUP BY sehir;