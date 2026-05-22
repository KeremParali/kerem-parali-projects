using System;

class Program
{
	static void Main()
	{
		// Örnek dizi
		int[] sayilar = { 64, 25, 12, 22, 11 };

		Console.WriteLine("Sıralamadan önce:");
		Yazdir(sayilar);

		// Selection Sort işlemi
		for (int i = 0; i < sayilar.Length - 1; i++)
		{
			int minIndex = i; // en küçük elemanın index'i

			for (int j = i + 1; j < sayilar.Length; j++)
			{
				// daha küçük bir eleman bulunursa index güncellenir
				if (sayilar[j] < sayilar[minIndex])
				{
					minIndex = j;
				}
			}

			// yer değiştirme işlemi
			int temp = sayilar[i];
			sayilar[i] = sayilar[minIndex];
			sayilar[minIndex] = temp;
		}

		Console.WriteLine("\nSıralamadan sonra:");
		Yazdir(sayilar);
	}

	// diziyi ekrana yazdırma metodu
	static void Yazdir(int[] dizi)
	{
		foreach (int sayi in dizi)
		{
			Console.Write(sayi + " ");
		}
		Console.WriteLine();
	}
}