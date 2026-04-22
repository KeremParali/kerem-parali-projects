-- =========================================================
-- FİLM ARŞİVİ ve GÖSTERİM TAKİP SİSTEMİ
-- Amaç: Film, yönetmen, salon ve gösterim bilgilerini tutmak
-- =========================================================

-- 1. Veritabanı oluşturma
CREATE DATABASE sinema;

-- 2. Veritabanını aktif hale getirme
USE sinema;

-- =========================================================
-- 3. Yönetmen tablosunu oluşturma
-- yonetmen_id otomatik artan benzersiz id alanıdır
-- =========================================================
CREATE TABLE yonetmen(
    yonetmen_id INT PRIMARY KEY IDENTITY(1,1),
    ad_soyad VARCHAR(80),
    ulke VARCHAR(50),
    dogum_yili INT
);

-- =========================================================
-- 4. Film tablosunu oluşturma
-- yonetmen_id alanı filmi çeken yönetmeni belirtir
-- =========================================================
CREATE TABLE film(
    film_id INT PRIMARY KEY IDENTITY(1,1),
    film_adi VARCHAR(100),
    tur VARCHAR(50),
    sure_dakika INT,
    puan FLOAT,
    yonetmen_id INT
);

-- =========================================================
-- 5. Salon tablosunu oluşturma
-- kapasite salonun kişi sayısını belirtir
-- =========================================================
CREATE TABLE salon(
    salon_id INT PRIMARY KEY IDENTITY(1,1),
    salon_adi VARCHAR(50),
    kapasite INT,
    kat INT
);

-- =========================================================
-- 6. Gösterim tablosunu oluşturma
-- film_id ve salon_id ilgili tabloya bağlanır
-- =========================================================
CREATE TABLE gosterim(
    gosterim_id INT PRIMARY KEY IDENTITY(1,1),
    film_id INT,
    salon_id INT,
    gosterim_tarihi DATE,
    seans VARCHAR(20),
    bilet_fiyati INT
);

-- =========================================================
-- 7. Yönetmen verileri ekleme
-- =========================================================
INSERT INTO yonetmen(ad_soyad, ulke, dogum_yili) VALUES
('Christopher Nolan','İngiltere',1970),
('Nuri Bilge Ceylan','Türkiye',1959),
('Greta Gerwig','ABD',1983),
('Bong Joon-ho','Güney Kore',1969);

-- =========================================================
-- 8. Film verileri ekleme
-- =========================================================
INSERT INTO film(film_adi, tur, sure_dakika, puan, yonetmen_id) VALUES
('Inception','Bilim Kurgu',148,8.8,1),
('Interstellar','Bilim Kurgu',169,8.7,1),
('Kış Uykusu','Dram',196,8.1,2),
('Jay Kelly','Komedi',114,7.1,3),
('Parazit','Gerilim',132,8.5,4),
('Ahlat Ağacı','Dram',188,8.0,2);

-- =========================================================
-- 9. Salon verileri ekleme
-- =========================================================
INSERT INTO salon(salon_adi, kapasite, kat) VALUES
('Salon A',120,1),
('Salon B',90,1),
('Salon C',150,2),
('Salon D',80,2);

-- =========================================================
-- 10. Gösterim verileri ekleme
-- =========================================================
INSERT INTO gosterim(film_id, salon_id, gosterim_tarihi, seans, bilet_fiyati) VALUES
(1,1,'2026-05-10','Akşam',220),
(2,3,'2026-05-10','Akşam',250),
(3,2,'2026-05-11','Öğle',180),
(4,4,'2026-05-11','Akşam',200),
(5,1,'2026-05-12','Akşam',230),
(6,3,'2026-05-12','Sabah',170);

-- =========================================================
-- 11. Tabloları kontrol etme
-- SELECT * tüm verileri getirir
-- =========================================================
SELECT * FROM yonetmen;
SELECT * FROM film;
SELECT * FROM salon;
SELECT * FROM gosterim;

-- =========================================================
-- 12. Film adı, türü ve puanını listeleme
-- =========================================================
SELECT film_adi, tur, puan
FROM film;

-- =========================================================
-- 13. Türü Dram olan filmleri listeleme
-- WHERE şart koymak için kullanılır
-- =========================================================
SELECT *
FROM film
WHERE tur = 'Dram';

-- =========================================================
-- 14. Filmleri puana göre büyükten küçüğe sıralama
-- ORDER BY sıralama yapar
-- DESC azalan sıralama yapar
-- =========================================================
SELECT film_adi, puan
FROM film
ORDER BY puan DESC;

-- =========================================================
-- 15. En yüksek puanlı ilk 3 filmi getirme
-- TOP 3 sadece ilk 3 kaydı getirir
-- =========================================================
SELECT TOP 3 film_adi, puan
FROM film
ORDER BY puan DESC;

-- =========================================================
-- 16. Tekrarsız film türlerini listeleme
-- DISTINCT tekrar eden kayıtları kaldırır
-- =========================================================
SELECT DISTINCT tur
FROM film;

-- =========================================================
-- 17. Film puanları ile ilgili istatistikler
-- COUNT toplam kayıt sayısı
-- AVG ortalama
-- MIN en düşük değer
-- MAX en yüksek değer
-- =========================================================
SELECT COUNT(*) AS toplam_film,
       AVG(puan) AS ortalama_puan,
       MIN(puan) AS en_dusuk_puan,
       MAX(puan) AS en_yuksek_puan
FROM film;

-- =========================================================
-- 18. Türlere göre film sayısı
-- GROUP BY aynı türleri gruplar
-- =========================================================
SELECT tur, COUNT(*) AS film_sayisi
FROM film
GROUP BY tur;

-- =========================================================
-- 19. 1'den fazla filme sahip türleri listeleme
-- HAVING gruplarda şart koymak için kullanılır
-- =========================================================
SELECT tur, COUNT(*) AS film_sayisi
FROM film
GROUP BY tur
HAVING COUNT(*) > 1;

-- =========================================================
-- 20. Film ve yönetmen bilgilerini birleştirme
-- INNER JOIN tabloları ortak alana göre birleştirir
-- =========================================================
SELECT film.film_adi, yonetmen.ad_soyad
FROM film
INNER JOIN yonetmen
ON film.yonetmen_id = yonetmen.yonetmen_id;

-- =========================================================
-- 21. Film, salon ve seans bilgilerini birleştirme
-- =========================================================
SELECT film.film_adi, salon.salon_adi, gosterim.seans
FROM gosterim
INNER JOIN film
ON gosterim.film_id = film.film_id
INNER JOIN salon
ON gosterim.salon_id = salon.salon_id;

-- =========================================================
-- NOT:
-- JOIN ve INNER JOIN aynı işlemi yapar
-- JOIN kısa yazımıdır
-- =========================================================