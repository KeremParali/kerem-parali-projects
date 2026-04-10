"SQL TABLO OLUŞTURMA ÖRNEKLERİ"

"-----------------------"

CREATE TABLE yazar(
    yazar_id INT PRIMARY KEY IDENTITY(1,1),"----------> id yi benzersiz yaptık"
    ad_soyad VARCHAR(80) NOT NULL, "------------> NOT NULL isim yazmayı zorunlu kıldık"
    ulke VARCHAR(50), "---------> 50 karakter uzunluğunda olsun"
    dogum_yili INT, "--------------------> INT Tam sayı kullanımı"
    biyografi VARCHAR(255) "---------------> 255 karakter uzunluğunda olsun"
);

"-----------------------"

CREATE TABLE film(  "-----------------------> Film tablosu oluştur"

film_id INT PRIMARY KEY IDENTITY(1,1), "---------------> benzersiz kimlik tanımladık"

film_adi VARCHAR(100), "---------------> 100 karakter uzunluğunda olsun"

tur VARCHAR(50), "-------------> 50 karakter uzunluğunda olsun"

sure_dakika INT, "---------------------> INT tam sayı kullanımı"

puan FLOAT, "-----------------> FLOAT buçuklu sayı kullanımı"

yonetmen_id INT "--------------------> INT tam sayı"

);

"---------------------------"


CREATE TABLE gosterim( "---------------> Gösterim tablosu oluştur"

gosterim_id INT PRIMARY KEY IDENTITY(1,1), "---------------> Benzersiz kimlik"

film_id INT, "-----------------> INT Tam sayı kullanımı"

salon_id INT, "-------------> INT Tam sayı kullanımı"

gosterim_tarihi DATE, "----------> Tarih yazdırmak için DATE"

seans VARCHAR(20), "------------------> Seans uzunluğu 20 karakter"

bilet_fiyati INT "------------> Tam sayı kullanımı"

);
