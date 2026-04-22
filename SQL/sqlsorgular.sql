-- =====================================================
-- SQL TEMEL KOMUTLAR - KEREM PARALI
-- Veritabanı Teknolojileri Dersi Çalışmaları
-- =====================================================


-- =========================================
-- 1. SELECT
-- Veritabanından veri çekmek için kullanılır
-- =========================================
SELECT FirstName, LastName
FROM Person.Person;


-- =========================================
-- 2. WHERE
-- Verileri filtrelemek için kullanılır
-- =========================================
SELECT *
FROM Production.Product
WHERE Color = 'Red';


-- =========================================
-- 3. ORDER BY
-- Sonuçları sıralamak için kullanılır
-- =========================================
SELECT Name, ListPrice
FROM Production.Product
ORDER BY ListPrice DESC;


-- =========================================
-- 4. GROUP BY
-- Verileri gruplayarak özet çıkarır
-- =========================================
SELECT Color, COUNT(*) AS Adet
FROM Production.Product
GROUP BY Color;


-- =========================================
-- 5. HAVING
-- Grupları filtrelemek için kullanılır
-- =========================================
SELECT Color, COUNT(*) AS Adet
FROM Production.Product
GROUP BY Color
HAVING COUNT(*) > 5;


-- =========================================
-- 6. LIKE
-- Metin içinde arama yapar
-- =========================================
SELECT *
FROM Person.Person
WHERE FirstName LIKE 'A%';


-- =========================================
-- 7. TOP
-- İlk N kaydı getirir
-- =========================================
SELECT TOP 5 *
FROM Production.Product;


-- =========================================
-- 8. JOIN (INNER JOIN)
-- İki tabloyu birleştirir
-- =========================================
SELECT p.FirstName, e.JobTitle
FROM Person.Person p
INNER JOIN HumanResources.Employee e
ON p.BusinessEntityID = e.BusinessEntityID;


-- =========================================
-- 9. MIN / MAX
-- En küçük ve en büyük değerleri bulur
-- =========================================
SELECT 
    MIN(ListPrice) AS EnUcuz,
    MAX(ListPrice) AS EnPahali
FROM Production.Product;


-- =========================================
-- 10. ROUND
-- Sayıyı yuvarlar
-- =========================================
SELECT ROUND(123.4567, 2) AS YuvarlanmisSayi;


-- =========================================
-- 11. LEN
-- Metnin uzunluğunu verir
-- =========================================
SELECT LEN(FirstName) AS IsimUzunlugu
FROM Person.Person;


-- =========================================
-- 12. UPPER / LOWER
-- Metni büyük/küçük harfe çevirir
-- =========================================
SELECT 
    UPPER(FirstName) AS BuyukHarf,
    LOWER(LastName) AS KucukHarf
FROM Person.Person;


-- =========================================
-- 13. CAST
-- Veri tipini dönüştürür
-- =========================================
SELECT CAST(ListPrice AS INT) AS TamSayiFiyat
FROM Production.Product;


-- =========================================
-- 14. EXISTS
-- Alt sorguda veri varsa sonuç döner
-- =========================================
SELECT Name
FROM Production.Product p
WHERE EXISTS (
    SELECT *
    FROM Sales.SalesOrderDetail s
    WHERE p.ProductID = s.ProductID
);


-- =========================================
-- 15. NOT IN
-- Belirli değerler dışındakileri getirir
-- =========================================
SELECT *
FROM Production.Product
WHERE Color NOT IN ('Red', 'Black');


-- =========================================
-- 16. UNION
-- İki sorguyu birleştirir (tekrarsız)
-- =========================================
SELECT FirstName FROM Person.Person
UNION
SELECT FirstName FROM Person.Person;


-- =========================================
-- 17. UNION ALL
-- Tekrarlı verileri de getirir
-- =========================================
SELECT FirstName FROM Person.Person
UNION ALL
SELECT FirstName FROM Person.Person;


-- =========================================
-- 18. CASE WHEN
-- Koşullu çıktı üretir
-- =========================================
SELECT 
    Name,
    ListPrice,
    CASE 
        WHEN ListPrice > 1000 THEN 'Pahalı'
        WHEN ListPrice > 500 THEN 'Orta'
        ELSE 'Ucuz'
    END AS FiyatDurumu
FROM Production.Product;


-- =========================================
-- 19. DATEDIFF
-- İki tarih arasındaki farkı hesaplar
-- =========================================
SELECT DATEDIFF(DAY, OrderDate, ShipDate) AS GunFarki
FROM Sales.SalesOrderHeader;


-- =========================================
-- 20. STRING FONKSİYONLARI
-- =========================================
SELECT 
    CONCAT(FirstName, ' ', LastName) AS TamIsim,
    SUBSTRING(FirstName, 1, 3) AS IlkUcHarf,
    REPLACE(FirstName, 'a', 'A') AS Degistirilmis,
    TRIM(FirstName) AS Temizlenmis
FROM Person.Person;