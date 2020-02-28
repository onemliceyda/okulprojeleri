/****************************************************************************
**
**				ÖĞRENCİ ADI..................:Ceyda Önemli
**				ÖĞRENCİ NUMARASI.............:G181210107
**				DERS GRUBU...................:2-C
****************************************************************************/

#include<iostream>
#include<iomanip>
#include<Windows.h>//Sleep fonksiyonu için gerekli
using namespace std;
int main()
{
	//Kullanıcının girecegi degiskenleri int veri tipinde tanımladım.
	int satir, sutun;

	cout << "Satir Degeri :";
	cin >> satir;
	/*While dongusu icerisindeki deger false olana kadar degeri dondurecektir.Bu nedenle kosulda istenilen durumun tam tersini yazıp
	dongunun disina cikmasini sagladim*/
	while (satir < 5 || satir > 15)
	{

		cout << "Satir degeri kosulunu saglamadiniz.Lutfen dogru aralikta sayi giriniz." << endl;
		cout << "Satir degeri :";
		//Kullanıcıdan satır değerini tekrar istedim.
		cin >> satir;
	}



	cout << "Sutun degeri: ";

	cin >> sutun;
	/*Yukaridaki dongude oldugu gibi dongunun icindeki false yapacak degerlerin kosulunu sagladim.Bu sayede kosul saglanmayinca donguden kurtulmus oluruz ve istenilen durumu elde ederiz.*/
	while (sutun < 5 || sutun > 40)
	{

		cout << "Sutun degeri kosulunu saglamadiniz.Lutfen dogru aralikta sayi giriniz." << endl;
		cout << "Sutun :";

		cin >> sutun;
	}

	while (satir < 5 || satir > 15 || sutun < 5 || sutun > 40 || sutun != satir * 2) //bizden satir degerinin sutun degerinin yarisi degerinde olmasi isteniyor.Bu yuzden bu kosulu da yukardaki mantik ile while dongusunune yazariz.
	{

		if (satir < 5 || satir > 15)
		{
			cout << "Satir degeri hatali.Lutfen dogru aralikta sayi giriniz." << endl;
		}

		if (sutun < 5 || sutun > 40)
		{
			cout << "Sutun degerini hatali girniz.Lutfen dogru aralikta sayi giriniz." << endl;
		}

		cout << "Sutun degeri satir degerinin iki kati olmaliydi.Tekrar deneyiniz." << endl;

		cout << "Satir degeri :";

		cin >> satir;

		cout << "Sutun degeri :";

		cin >> sutun;
	}
	/*Tum kosullar saglandi.Donguden cikabilir hale gelmistir.*/



	cout << endl;

	int ortaBoslukArtan = 3;
	int ikiTarafliBoslukAzalan = satir - 2;
	//Kullanıcıdan alınan sütun sayısı kadar yıldızı ekrana bastırdım.
	for (int duzSatirYildiz = 0; duzSatirYildiz < sutun; duzSatirYildiz++)
	{
		cout << "*";
	}
	//Diğer döngü başladığında alt satıra geçmeli
	cout << endl;
	for (int i = 0; i < satir - 2; i++)
	{
		//Satırları bastırmak için.
		cout << "*" << setw(ikiTarafliBoslukAzalan) << "*" << setw(ortaBoslukArtan) << "*" << setw(ikiTarafliBoslukAzalan) << "*";

		Sleep(100);

		cout << endl;

		ortaBoslukArtan += 2;

		ikiTarafliBoslukAzalan--;
	}

	for (int duzSatirYildiz = 0; duzSatirYildiz < sutun; duzSatirYildiz++)
	{
		cout << "*";
	}
	cout << endl << endl;

	for (int duzSatirYildiz = 0; duzSatirYildiz < sutun; duzSatirYildiz++)
	{
		cout << "*";
	}

	cout << endl;

	int ortaBoslukAzalan = sutun - 3;
	int ikiTarafliBoslukArtan = 1;
	for (int j = 0; j < satir - 2; j++)
	{
		cout << "*" << setw(ikiTarafliBoslukArtan) << "*" << setw(ortaBoslukAzalan) << "*" << setw(ikiTarafliBoslukArtan) << "*";

		Sleep(100);
		cout << endl;
		ortaBoslukAzalan -= 2;
		ikiTarafliBoslukArtan++;
	}
	for (int duzSatirYildiz = 0; duzSatirYildiz < sutun; duzSatirYildiz++)
	{
		cout << "*";
	}
	return 0;
}