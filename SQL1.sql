"SQL TABLO OLUŞTURMA ÖRNEĞİ"

CREATE TABLE yazar(
    yazar_id INT PRIMARY KEY IDENTITY(1,1),
    ad_soyad VARCHAR(80) NOT NULL,
    ulke VARCHAR(50),
    dogum_yili INT,
    biyografi VARCHAR(255)
);
