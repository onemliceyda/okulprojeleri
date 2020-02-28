
/****************************************************************************
**					SAKARYA ÜNİVERSİTESİ
**			         BİLGİSAYAR VE BİLİŞİM BİLİMLERİ FAKÜLTESİ
**				    BİLGİSAYAR MÜHENDİSLİĞİ BÖLÜMÜ
**				          PROGRAMLAMAYA GİRİŞİ DERSİ
**
**				ÖDEV NUMARASI…...: 3
**				ÖĞRENCİ ADI...............: CEYDA ÖNEMLİ
**				ÖĞRENCİ NUMARASI.: G181210107
**				DERS GRUBU…………: B GRUBU
****************************************************************************/

#include <iostream>
using namespace std;

struct Islem
{
	int cekirdekMatrisi[5][5];
	int cekirdekBoyut;
	int kaymaMiktari;
	int sonucMatrisi[100][100];
	int giris[5][5] = { 3,2,5,1,4,
						6,2,1,0,7,
						3,0,0,2,0,
						1,1,3,2,2,
						0,3,1,0,0 };
} carpim;

int girisSatir = sizeof(carpim.giris) / sizeof(carpim.giris[0]);
int girisSutun = sizeof(carpim.giris[0]) / sizeof(carpim.giris[0][0]);

void matrisYazdir(int, int);

int main()
{
	cout << "cekirdek boyutu giriniz = ";
	cin >> carpim.cekirdekBoyut;


	cout << "kayma miktari giriniz = ";
	cin >> carpim.kaymaMiktari;

	//kayma miktarı kontrol ediliyor.
	while (carpim.kaymaMiktari == 0)
	{
		cout << "kayma miktarı 0 olamaz. yeniden girin:";
		cin >> carpim.kaymaMiktari;
	}

	// kayma miktarı kontrol ediliyor.
	if ((girisSutun % carpim.kaymaMiktari) != 0 || girisSutun == carpim.kaymaMiktari || carpim.cekirdekBoyut > girisSatir)
	{
		cout << "bu islem yapilamaz!";
	}
	else
	{
		int cekirdekBoyutu = carpim.cekirdekBoyut;
		int kaymaMiktari = carpim.kaymaMiktari;

		// çekirdek matrisinin degerleri isteniyor.
		for (int i = 0; i < cekirdekBoyutu; i++)
		{
			for (int j = 0; j < cekirdekBoyutu; j++)
			{
				cout << "cekirdek[" << i << "][" << j << "] = ";
				cin >> carpim.cekirdekMatrisi[i][j];
			}
		}

		int sonucSatir = ((girisSatir - cekirdekBoyutu) / kaymaMiktari) + 1;
		int sonucSutun = ((girisSutun - cekirdekBoyutu) / kaymaMiktari) + 1;

		int x = 0; int y = 0;

		//sonuc matrisi olusturuluyor.
		for (int i = 0; i < sonucSatir; i++)
		{
			for (int j = 0; j < sonucSutun; j++)
			{
				for (int a = 0; a < cekirdekBoyutu; a++)
				{
					for (int b = 0; b < cekirdekBoyutu; b++)
					{
						//giris matrisi ile cekirdek matrisinin uygun degerleri çarpılıp sonuc matrisine aktarılıyor.
						carpim.sonucMatrisi[i][j] += (carpim.giris[a + x][b + y] * carpim.cekirdekMatrisi[a][b]);
					}
				}
				x += kaymaMiktari;
				//sütun sona ulaştığında bir satır aşağı geçiyor.
				if (x + cekirdekBoyutu > girisSutun) {
					x = 0;
					y++;
				}
			}
		}

		matrisYazdir(sonucSatir, sonucSutun);
	}
	system("pause");
	return 0;
}

void matrisYazdir(int sonucSatir, int sonucSutun) {

	// sonuc matrisi ekrana yazdırılıyor.
	for (int i = 0; i < sonucSatir; i++)
	{
		for (int j = 0; j < sonucSutun; j++)
		{
			cout << carpim.sonucMatrisi[i][j] << "\t";
		}
		cout << endl;
	}
}