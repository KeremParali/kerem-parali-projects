-- VERİTABANI TEKNOLOJİLERİ LAB
-- AdventureWorks SQL Çalışmaları
-- Derste işlenen sorgular

USE AdventureWorks2022;
GO


--------------------------------------------------
-- 1) Ürün tablosunu görüntüleme
--------------------------------------------------
SELECT TOP 10 * 
FROM Production.Product;
GO


--------------------------------------------------
-- 2) Belirli sütunları çekme
--------------------------------------------------
SELECT Name, ProductNumber, ListPrice
FROM Production.Product;
GO


--------------------------------------------------
-- 3) Fiyatı 1000'den büyük ürünler
--------------------------------------------------
SELECT Name, ListPrice
FROM Production.Product
WHERE ListPrice > 1000;
GO


--------------------------------------------------
-- 4) Siyah ürünler
--------------------------------------------------
SELECT Name, Color, ListPrice
FROM Production.Product
WHERE Color = 'Black';
GO


--------------------------------------------------
-- 5) En pahalı ürünler (sıralama)
--------------------------------------------------
SELECT Name, ListPrice
FROM Production.Product
ORDER BY ListPrice DESC;
GO


--------------------------------------------------
-- 6) En pahalı ilk 5 ürün
--------------------------------------------------
SELECT TOP 5 Name, ListPrice
FROM Production.Product
ORDER BY ListPrice DESC;
GO


--------------------------------------------------
-- 7) Farklı renkler
--------------------------------------------------
SELECT DISTINCT Color
FROM Production.Product;
GO


--------------------------------------------------
-- 8) Toplam ürün sayısı
--------------------------------------------------
SELECT COUNT(*) AS toplam_urun
FROM Production.Product;
GO


--------------------------------------------------
-- 9) Ortalama, min, max fiyat
--------------------------------------------------
SELECT 
    AVG(ListPrice) AS ortalama,
    MIN(ListPrice) AS en_dusuk,
    MAX(ListPrice) AS en_yuksek
FROM Production.Product;
GO


--------------------------------------------------
-- 10) Renge göre ürün sayısı
--------------------------------------------------
SELECT Color, COUNT(*) AS adet
FROM Production.Product
GROUP BY Color;
GO


--------------------------------------------------
-- 11) Birden fazla ürünü olan renkler
--------------------------------------------------
SELECT Color, COUNT(*) AS adet
FROM Production.Product
GROUP BY Color
HAVING COUNT(*) > 1;
GO


--------------------------------------------------
-- 12) Adında 'Road' geçen ürünler
--------------------------------------------------
SELECT Name
FROM Production.Product
WHERE Name LIKE '%Road%';
GO


--------------------------------------------------
-- 13) 1000 - 2000 arası fiyatlar
--------------------------------------------------
SELECT Name, ListPrice
FROM Production.Product
WHERE ListPrice BETWEEN 1000 AND 2000;
GO


--------------------------------------------------
-- 14) Siyah veya kırmızı ürünler
--------------------------------------------------
SELECT Name, Color
FROM Production.Product
WHERE Color IN ('Black', 'Red');
GO


--------------------------------------------------
-- 15) Müşteri ve siparişleri (JOIN)
--------------------------------------------------
SELECT c.CustomerID, soh.SalesOrderID, soh.TotalDue
FROM Sales.Customer c
JOIN Sales.SalesOrderHeader soh
ON c.CustomerID = soh.CustomerID;
GO


--------------------------------------------------
-- 16) Müşteri + ürün + sipariş
--------------------------------------------------
SELECT 
    c.CustomerID,
    p.Name AS urun,
    sod.LineTotal
FROM Sales.Customer c
JOIN Sales.SalesOrderHeader soh
    ON c.CustomerID = soh.CustomerID
JOIN Sales.SalesOrderDetail sod
    ON soh.SalesOrderID = sod.SalesOrderID
JOIN Production.Product p
    ON sod.ProductID = p.ProductID;
GO


--------------------------------------------------
-- 17) Siparişi olmayan müşteriler
--------------------------------------------------
SELECT c.CustomerID
FROM Sales.Customer c
LEFT JOIN Sales.SalesOrderHeader soh
ON c.CustomerID = soh.CustomerID
WHERE soh.SalesOrderID IS NULL;
GO


--------------------------------------------------
-- 18) Her müşterinin sipariş sayısı
--------------------------------------------------
SELECT 
    c.CustomerID,
    COUNT(soh.SalesOrderID) AS siparis_sayisi
FROM Sales.Customer c
LEFT JOIN Sales.SalesOrderHeader soh
ON c.CustomerID = soh.CustomerID
GROUP BY c.CustomerID
ORDER BY siparis_sayisi DESC;
GO


--------------------------------------------------
-- 19) Ürün bazında toplam satış
--------------------------------------------------
SELECT 
    p.Name,
    SUM(sod.LineTotal) AS toplam_satis
FROM Production.Product p
JOIN Sales.SalesOrderDetail sod
ON p.ProductID = sod.ProductID
GROUP BY p.Name
ORDER BY toplam_satis DESC;
GO


--------------------------------------------------
-- 20) En çok kazandıran ilk 5 ürün
--------------------------------------------------
SELECT TOP 5
    p.Name,
    SUM(sod.LineTotal) AS toplam_satis
FROM Production.Product p
JOIN Sales.SalesOrderDetail sod
ON p.ProductID = sod.ProductID
GROUP BY p.Name
ORDER BY toplam_satis DESC;
GO


--------------------------------------------------
-- 21) Fiyata göre sınıflandırma
--------------------------------------------------
SELECT 
    Name,
    ListPrice,
    CASE 
        WHEN ListPrice < 500 THEN 'Dusuk'
        WHEN ListPrice BETWEEN 500 AND 1500 THEN 'Orta'
        ELSE 'Yuksek'
    END AS seviye
FROM Production.Product;
GO


--------------------------------------------------
-- 22) 2005 sonrası ürünler
--------------------------------------------------
SELECT Name, SellStartDate
FROM Production.Product
WHERE SellStartDate > '2005-01-01';
GO


--------------------------------------------------
-- 23) Ortalama sipariş tutarı
--------------------------------------------------
SELECT AVG(TotalDue) AS ortalama
FROM Sales.SalesOrderHeader;
GO