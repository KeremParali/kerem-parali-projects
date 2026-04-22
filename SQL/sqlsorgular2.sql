use AdventureWorks2022 ;
go 

SELECT CONCAT(FirstNAME, ' ', LastName) AS AdSoyad --isim soyad birleştirme için concat 
FROM Person.Person;
go

SELECT UPPER(LastName),LOWER(FirstName) -- upper bütün harfleri büyük yapar lowerda küçük yapar
FROM Person.Person;
go

SELECT FirstName , LEN(FirstName) ---- len karakter sayısını sayıyor
FROM Person.Person;
go

SELECT LastName
FROM Person.Person      ----karakter sayısı 5 den büyük olanları istiyoruz
Where LEN(LastName) > 5 ;
go

SELECT LEFT(FirstName,3),RIGHT(LastName,2)---metinlerin sağından ve solundan karakter alıyoruz
FROM Person.Person;
go

SELECT HireDate,YEAR(HireDate) , MONTH(HireDate) --İşe giriş yılı ve ayı 
FROM HumanResources.Employee;
GO

SELECT HireDate	,					--------kaç yıllır çalıştığını bulmak için 
DATEDIFF(YEAR,HireDate, GETDATE())	AS Çalışma_yılı
FROM HumanResources.Employee;			------ datedıff zaman istediğimiz için
go

SELECT * 
FROM HumanResources.Employee
WHERE DATEDIFF(YEAR,HireDate, GETDATE()) > 10 ; ----- 10 YILDAN FAZLA ÇALIŞANLARIN LİSTESİ
GO

SELECT *
FROM HumanResources.EmployeeDepartmentHistory ----- BOŞ OLAN VERİLERİ BULUYORUZ
WHERE EndDate IS NULL ;
GO

SELECT *
FROM HumanResources.EmployeeDepartmentHistory ----- BİTİŞ TARİHİ DOLU OLAN VERİLERİ BULUYORUZ
WHERE EndDate IS NOT NULL ; 
GO

SELECT ISNULL(CAST(EndDate as varchar ) , 'AKTİF ÇALIŞAN') -----boş veriyi anlamlı hale getirdik
FROM HumanResources.EmployeeDepartmentHistory;
GO

SELECT Rate 
FROM HumanResources.EmployeePayHistory  ----SUBQUERY İÇE İÇE SORGU ORTALAMANIN ÜZERİNDEKİ MAAAŞLAR
WHERE Rate > (
SELECT AVG(Rate)
FROM HumanResources.EmployeePayHistory);
GO


select 
concat(p.FirstName, ' ', p.LastName) as Ad_Soyad, 
e.JobTitle, 
datediff(year, e.HireDate, getdate()) as Çalışma_Yılı,
case 
when eph.Rate < 30 then 'Düşük'
when eph.Rate between 30 and 50 then 'Orta'
else 'Yüksek'
end as Ücret_Seviyesi
from Person.Person p 
join HumanResources.Employee e
on p.BusinessEntityID = e.BusinessEntityID
join HumanResources.EmployeePayHistory eph
on e.BusinessEntityID = eph.BusinessEntityID;
go

