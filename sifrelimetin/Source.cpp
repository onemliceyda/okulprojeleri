

                          /***************************************************************************
**                                                   SAKARYA ÜNİVERSİTESİ
**                                       BİLGİSAYAR VE BİLİŞİM BİLİMLERİ FAKÜLTESİ
**                                           BİLGİSAYAR MÜHENDİSLİĞİ BÖLÜMÜ
**                                               PROGRAMLAMAYA GİRİŞ DERSİ
**
**                                                   ÖDEV NUMARASI:4
**                                              ÖĞRENCİ ADI: CEYDA ÖNEMLİ
**                                             ÖĞRENCİ NUMARASI: G181210107
**                                                   DERS GRUBU: B
                           ****************************************************************************/

#include <iostream>

using namespace std;
int alfabeBoyutu = 0;
int sifreBoyutu = 0;
int metinBoyutu = 0;
class Sifre
{
	char *alfabe = new char[alfabeBoyutu];
	char *sifreKelimesi = new char[sifreBoyutu];
public:
	Sifre()
	{
		for (int i = 0; i < 26; i++)
		{
			*(alfabe + i) = 'A' + i;
		}
	}
	Sifre(char *alfabe, char *sifre) 
	{
		for (int i = 0; i < 26; i++)
		{
			*(this->alfabe + i) = *(alfabe + i);
		}
		for (int i = 0; i < sifreBoyutu; i++)
		{
			*(sifreKelimesi + i) = *(sifre + i);
		}
	}
	char* sifrele(char *metin)
	{
		int f = 0;
		for (int i = 0; i < metinBoyutu; i++)
		{
			*(metin + i) = *(metin + i) + *(sifreKelimesi + f) - 65 + 1;
			if (*(metin + i) > 90)
			{
				*(metin + i) -= 26;
			}
			f++;
			if (*(sifreKelimesi + f) > 90 || *(sifreKelimesi + f) < 65)
			{
				f = 0;
			}
		}
		return metin;
	}
	char* sifrecoz(char *sifrelimetin)
	{
		int f = 0;
		for (int i = 0; i < metinBoyutu; i++)
		{
			*(sifrelimetin + i) = *(sifrelimetin + i) - *(sifreKelimesi + f) + 65 - 1;
			if (*(sifrelimetin + i) < 65)
			{
				*(sifrelimetin + i) += 26;
			}
			f++;
			if (*(sifreKelimesi + f) > 90 || *(sifreKelimesi + f) < 65)
			{
				f = 0;
			}
		}
		return sifrelimetin;
	}
	void sifreKelimesiAta(char *sifre)
	{
		for (int i = 0; i < sifreBoyutu; i++)
		{
			*(sifreKelimesi + i) = *(sifre + i);
		}
	}
};

int main()
{
	int i = 0;
	char metinDizisi[150];
	char sifreDizisi[150];
	char alfabeDizisi[26];
	cout << "ALFABE :"; cin >> alfabeDizisi; //alfabe olarak kullanmak istedigimiz metni giriyoruz
	while (alfabeDizisi[i] != '\0')
	{
		alfabeBoyutu++;
		i++;
	}
	i = 0;
	char *alfabe = new char[alfabeBoyutu];
	for (int i = 0; i < alfabeBoyutu; i++) //aldığımız alfabenin her elemanını pointerlı alfabeye aktarıyoruz bunun için de for kullandık.
	{
		*(alfabe + i) = alfabeDizisi[i];
	}
	cout << "SIFRE :"; cin >> sifreDizisi; // sıfre olmasını istedigimiz metni yazdırıyoruz
	while (sifreDizisi[i] != '\0')
	{
		sifreBoyutu++;
		i++;
	}
	i = 0;
	char *sifre = new char[sifreBoyutu];
	for (int i = 0; i < sifreBoyutu; i++)//for'u aldığımız sifrenin her harfini pointerlı sifrenin elemanlarına aktarmak için kullanıyoruz.
	{
		*(sifre + i) = sifreDizisi[i];
	}
	Sifre a(alfabe, sifre); // Nesne olusturdum
	cout << "METIN :"; cin >> metinDizisi;
	while (metinDizisi[i] != '\0')
	{
		metinBoyutu++;
		i++;
	}

	char *metin = new char[metinBoyutu];
	char *sifrelenmisMetin = new char[metinBoyutu];
	char *desifreMetin = new char[metinBoyutu];
	for (int i = 0; i < metinBoyutu; i++)//Aldığımız metinin her harfini pointerlı metinin elemanlarına aktarmak için for kullandık.
	{
		*(metin + i) = metinDizisi[i];
	}
	sifrelenmisMetin = a.sifrele(metin); // alınan metin sifreli metin fonksiyonuna yönlendirildi
	cout << "SIFRELENMIS METIN :";
	for (int i = 0; i < metinBoyutu; i++) // sifreli metni yazdırmak için for kullandık
	{
		cout << *(sifrelenmisMetin + i);
	}
	cout << endl;
	cout << "DESIFRE METIN :";
	desifreMetin = a.sifrecoz(sifrelenmisMetin); // Sifreli metni cözmek icin fonksiyona yolladık
	for (int i = 0; i < metinBoyutu; i++) // Desifre olan metni yazdırdık
	{
		cout << *(desifreMetin + i);
	}
	cout << endl;
	system("pause");
	return 0;
}