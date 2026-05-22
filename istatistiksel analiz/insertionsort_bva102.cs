using System;

class Program
{
	static void Main()
	{
		// Örnek dizi
		int[] sayilar = { 9, 5, 1, 4, 3 };

		Console.WriteLine("Sıralamadan önce:");
		Yazdir(sayilar);

		// Insertion Sort işlemi
		for (int i = 1; i < sayilar.Length; i++)
		{
			int anaEleman = sayilar[i]; // sıralanacak eleman
			int j = i - 1;

			// sola kaydırma işlemi
			while (j >= 0 && sayilar[j] > anaEleman)
			{
				sayilar[j + 1] = sayilar[j];
				j--;
			}

			// doğru yere yerleştirme
			sayilar[j + 1] = anaEleman;
		}

		Console.WriteLine("\nSıralamadan sonra:");
		Yazdir(sayilar);
	}

	// diziyi yazdırma metodu
	static void Yazdir(int[] dizi)
	{
		foreach (int sayi in dizi)
		{
			Console.Write(sayi + " ");
		}
		Console.WriteLine();
	}
}