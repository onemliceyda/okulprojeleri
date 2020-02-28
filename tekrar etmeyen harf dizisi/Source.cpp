/***********************************************************
**                                                       SAKARYA ÜNİVERSİTESİ 
**                                           BİLGİSAYAR VE BİLİŞİM BİLİMLERİ FAKÜLTESİ
**                                                BİLGİSAYAR MÜHENDİSLİĞİ BÖLÜMÜ
**                                                     PROGRAMLAMAYA GİRİŞ DERSİ
**
**                                                     ÖDEV NUMARASI    : 2
**                                                     ÖĞRENCİ ADI      : Ceyda Önemli
**                                                     ÖĞRENCİ NUMARASI : G181210107
**                                                     DERS GRUBU       : B
*************************************************************/


#include <iostream>
#include <time.h>

using namespace std;

int main() {
	
	//Tek boyutlu bir matris tanımlayıp ürettiğimiz harfi bu matris içine atıyoruz//
	// 1 Büyük harfleri 0 küçük harfleri temsil eder

	int matris[50]; 
	int HrfSira = 1; 
	int index;
	int k = 0;
	bool kontrol = false; 
	srand(time(NULL));

	int hrf;
	char Harf[5][10] = { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
						 ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
						 ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
						 ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
						 ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' };
	

	
	cout << "Rastegele ve tekrar etmeyen bir harf dizisi "<<endl;

	for (int i = 0; i < 5; i++) 
		//Tekrarsız ve rastgele harfleri oluşturmak için for döngüsü tanımladık.İçerisine de do while döngüsü koyup kontrol  sağlandı//
	{
		for (int j = 0; j < 10; j++) {
			//Harfin tekrar edip etmediğini do while ile kontrol ederiz.//
			
			do {                                 
				//Bir küçük harf bir büyük harf üretiyoruz.//
				if (kontrol == false)     
				{
					if (HrfSira == 1) {
						HrfSira = 0;  // kucuk harf
						index = 65;
					}
					else {
						HrfSira=1;  // buyuk harf
						index = 97;
					}
				}
				kontrol = false;
				//rastgele harf oluşturuluyor.26harf sayısı oldugundan 26'dan başladık//
				//harfin önceden matris matrisine kayıt edilip edilmediğini kontrol eden döngü//
				hrf = rand() % 26 + index;  
				for (int z = 0; z < 50; z++) {
					if (matris[z] == hrf) {
						kontrol = true;
					}
				}
			} while (kontrol == true);
			//oluşturulan harfi matris matrisine kaydeder
			matris[k] = hrf; 
			k++;
			cout << (char) hrf << Harf[i][j] << "   ";
		}
		cout << endl;
	}

	//oluşturduğumuz matris matrisindeki değerleri küçükten büyüğe sıralama döngüsü//
	int yerdegis;
	for (int i = 0; i < 50; i++)
	{
		for (int j = i + 1; j < 50; j++)
		{
			if (matris[j] < matris[i])
			{
				//buradaki int değiştir değişkeni matris[i] nin kaybolmaması için açılmış geçici bir değişken olarak tanımlanmıştır//
				yerdegis= matris[i];
				matris[i] = matris[j];
				matris[j] = yerdegis;
			}
		}
	}

	cout << endl<<endl;

	//Sıralı ve tekrarsiz dizinin oluşturulması bu döngü ile sağlanmaktadır//
	   //buradaki int sira matris tek boyutlu matrisindeki değerleri tek tek yazmak için oluşturuldu
	cout << "\nSiralanan Dizi\n\n";
	int a = 0;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 10; j++) {
			cout << (char)matris[a] << Harf[i][j] << "   ";
			a++;
		}
		cout <<endl ;
	}

	system("pause");
}