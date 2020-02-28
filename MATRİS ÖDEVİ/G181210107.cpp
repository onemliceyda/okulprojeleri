/****************************************************************************
**
**				ÖĞRENCİ ADI:CEYDA ÖNEMLİ	
**				ÖĞRENCİ NUMARASI:G181210107
**				DERS GRUBU:2C
****************************************************************************/


#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <conio.h>

using namespace std;


int boyut = 0;
int matris[25][25]; //25'e 25'lik bir matris olusturdum.bu sayede bellekte de yer acilmis oldu.

void matrisOlustur() //Matris olusturabilmek icin deger dondurmeyen bir fonksiyon olusturdum.Farkli farkli matrisler olusturmak istedigimde bu fonskiyon ile cagirmis oluyorum.
{
	for (int i = 0; i < boyut; i++)
	{
		for (int j = 0; j < boyut; j++)
		{
			matris[i][j] = 1 + rand() % 9; //9 olmasinin sebebi 9'a kadar sinirlama verilmis olmasi
		}
	}
}

void matrisYazdir() //olusturdugum matrisi yazdirmak icin farkli bir fonk.tanimladim cunku matrisOlustur icinde yazsaydim her defasinda farkli matrisi yazardi,ancak ben islemleri ayni matris icinde yurutuyorum.-Matris degistirilmesi istenmediği surece-
{
	for (int i = 0; i < boyut; i++)
	{
		for (int j = 0; j < boyut; j++)
		{
			cout << " " << matris[i][j];
		}
		cout << endl;
	}
}

void satirToSutun(int satir, int sutun) //1.secenek icin tanimlandi.Satir ve sutun degerlerini gecici degiskene atayip buradan tekrar matrise yazdirma islemi saglaniyor.
{
	satir--;
	sutun--;
	int gecici[25];
	int gecici2[25];
	for (int i = 0; i < boyut; i++)
	{
		gecici[i] = matris[satir][i];
		gecici2[i] = matris[i][sutun];
	}
	for (int i = 0; i < boyut; i++)
	{
		matris[satir][i] = gecici2[i];
		matris[i][sutun] = gecici[i];
	}
	matris[satir][sutun] = gecici[sutun] + gecici2[sutun];
}

void satirTekBasaAl(int satir) //Tek veya cift oldugu kontrol edilen sayilar,tekrardan gecici degiskenlere atanip buradan matrise yazdiriliyor.Bu islemler satir icin gerceklesiyor.
{
	satir--;
	int gecici = 0;
	for (int i = 0; i < boyut; i++)
	{
		if (matris[satir][i] % 2 == 1 && satir != 0)
		{
			gecici = matris[satir][i - 1];
			matris[satir][i - 1] = matris[satir][i];
			matris[satir][i] = gecici;
			i = 0;

		}
	}
}

void sutunTersCevir(int sutun) //Sutunlari ters cevirmek icin gecici degisken uzerinden tersten yazdirarak gerceklestirdim
{
	sutun--;
	int gecici[25] = { 0 };
	int j = 0;
	for (int i = 0; i < boyut; i++)
	{
		gecici[i] = matris[i][sutun];
	}
	for (int i = boyut - 1; i >= 0; i--)
	{
		matris[j][sutun] = gecici[i];
		j++;
	}
}

void toplamlariYazdir() //burada onemli olan sey satir ve sutunun gosterdigi elemani toplamdan cikartıip yazmamizdi.Fonksiyon tum eleman toplamlarini bulup,o elemani cikartiyor.
{
	int toplam = 0;
	for (int i = 0; i < boyut; i++)
	{
		for (int j = 0; j < boyut; j++)
		{
			toplam += matris[i][j];
		}
	}
	for (int i = 0; i < boyut; i++)
	{
		for (int j = 0; j < boyut; j++)
		{
			toplam -= matris[i][j];
			matris[i][j] = toplam;
		}
	}
}
int main()
{
	setlocale(LC_ALL, "Turkish");
	srand(time(NULL)); 
	int secim = 0;
	while (1)
	{
		cout << "Lutfen matris boyutunu giriniz:";
		cin >> boyut;
		if (boyut < 5 || boyut > 25)
		{
			cout << "Matris boyutu 5 ve 25 dahil bu aralikta olmalidir.Seciminizi tekrarlayiniz." << endl;
		}
		else
		{
			break;
		}
	}
	matrisOlustur();
	while (1)
	{
		matrisYazdir();
		cout << "1.Sutun-Satir Degistir:" << endl;
		cout << "2.Tekleri Basa Al(Satir)" << endl;
		cout << "3.Ters Cevir(Sutun)" << endl;
		cout << "4.Toplamlari yazdir" << endl;
		cin >> secim;

		if (secim == 1) //switch case yapisi yerine her biri icin ayri kosul olusturdum.Kosullar saglandikca islemler icin gerekli olan fonksiyonlari cagirdim.
		{
			int satir;
			int sutun;
			cout << "Satir:"; cin >> satir;
			cout << "Sutun:"; cin >> sutun;
			if (sutun > boyut || satir > boyut)
			{
				cout << "Satir ve sutun matris boyutundan buyuk olmamalidir.Tekrar deneyiniz." << endl;
				continue;
			}
			satirToSutun(satir, sutun);
			continue;
		}
		if (secim == 2)
		{
			int satir;
			cout << "Satir:"; cin >> satir;
			if (satir > boyut)
			{
				cout << "Satir matris boyutundan buyuk olmamali.Lutfen tekrar deneyiniz." << endl;
				continue;
			}
			satirTekBasaAl(satir);
			continue;
		}
		if (secim == 3)
		{
			int sutun;
			cout << "Sutun:"; cin >> sutun;
			if (sutun > boyut)
			{
				cout << "Sutun matris boyutundan buyuk olmamali.Lutfen tekrar deneyiniz." << endl;
				continue;
			}
			sutunTersCevir(sutun);
			continue;
		}
		if (secim == 4)
		{
			toplamlariYazdir();
			continue;
		} 

	}
	return 0;
}