using System;

class Program
{
	static void Main()
	{
		// Örnek dizi
		int[] sayilar = { 5, 3, 8, 4, 2 };

		Console.WriteLine("Sıralamadan önce:");
		Yazdir(sayilar);

		// Bubble Sort işlemi
		for (int i = 0; i < sayilar.Length - 1; i++)
		{
			for (int j = 0; j < sayilar.Length - 1 - i; j++)
			{
				// Eğer soldaki eleman sağdakinden büyükse yer değiştir
				if (sayilar[j] > sayilar[j + 1])
				{
					int temp = sayilar[j];
					sayilar[j] = sayilar[j + 1];
					sayilar[j + 1] = temp;
				}
			}
		}

		Console.WriteLine("\nSıralamadan sonra:");
		Yazdir(sayilar);
	}

	// Diziyi ekrana yazdıran metot
	static void Yazdir(int[] dizi)
	{
		foreach (int sayi in dizi)
		{
			Console.Write(sayi + " ");
		}
		Console.WriteLine();
	}
}