#include <iostream>
#include <iomanip>
#include <conio.h>
using namespace std;
int main()
{
	int sayacA = 0;
	int sayacE = 0;
	int sayacI = 0;
	int sayacO = 0;
	int sayacU = 0;
	int max = 0;
	char karakter = 'z';

	cout << "Bir Karakter Giriniz : ";
	while (karakter != '\n')
	{
		karakter = getchar();
		if (karakter == 'a' || karakter == 'A') //Eger girilen karakter a ise sayacA arttırılır.//
		{
			sayacA++;
		}

		if (karakter == 'e' || karakter == 'E') //Eger girilen karakter e ise sayacE arttırılır.//
		{
			sayacE++;
		}

		if (karakter == 'i' || karakter == 'I') //Eger girilen karakter I ise sayacI arttırılır.//
		{
			sayacI++;
		}

		if (karakter == 'o' || karakter == 'O') //Eger girilen karakter o ise sayacO artıırılır.//
		{
			sayacO++;
		}

		if (karakter == 'u' || karakter == 'U') //Eger girilen karakter U ise sayacU arttırılır.//
		{
			sayacU++;
		}
	}
	if (sayacA > sayacE&& sayacA > sayacI&& sayacA > sayacO&& sayacA > sayacU) //Sayaclar kıyaslanır hangi sayac daha buyuk degere sahipse max degeri alir.//
	{
		max = sayacA;
	}
	else if (sayacE > sayacA&& sayacE > sayacI&& sayacE > sayacO&& sayacE > sayacU) //Sayaclar kıyaslanır hangi sayac daha buyuk degere sahipse max degeri alir.//
	{
		max = sayacE;
	}
	else if (sayacI > sayacE&& sayacI > sayacA&& sayacI > sayacO&& sayacI > sayacU) //Sayaclar kıyaslanır hangi sayac daha buyuk degere sahipse max degeri alir.//
	{
		max = sayacI;
	}
	else if (sayacO > sayacE&& sayacO > sayacI&& sayacO > sayacA&& sayacO > sayacU) //Sayaclar kıyaslanır hangi sayac daha buyuk degere sahipse max degeri alir.//
	{
		max = sayacO;
	}
	else if (sayacU > sayacE&& sayacU > sayacI&& sayacU > sayacO&& sayacU > sayacA) //Sayaclar kıyaslanır hangi sayac daha buyuk degere sahipse max degeri alir.//
	{
		max = sayacU;

	}
	else
	{
		max = sayacA;
	}

	cout << "H" << "\t" << "T" << "\t";    //Harfleri ve Tekrar sayisini tutabilmesi için karakter yazdiriyoruz.//
	for (int i = 1; i <= max; i++)
	{
		cout << i << "\t";
	}
	cout << "\n" << "A" << "\t" << sayacA << "\t"; // Eger girilen karakter a ise a yazdırılır,girilen degisken bir arttırılır.//
	for (int i = 0; i < sayacA; i++)
	{
		cout << 'a' << "\t";
	}
	cout << "\n" << "E" << "\t" << sayacE << "\t"; // Eger girilen karakter e ise e yazdırılır,girilen degisken bir arttırılır.//
	for (int i = 0; i < sayacE; i++)
	{
		cout << 'e' << "\t";
	}
	cout << "\n" << "I" << "\t" << sayacI << "\t";  // Eger girilen karakter i ise i yazdırılır,girilen degisken bir arttırılır.//
	for (int i = 0; i < sayacI; i++)
	{
		cout << 'i' << "\t";
	}
	cout << "\n" << "O" << "\t" << sayacO << "\t";  // Eger girilen karakter o ise o yazdırılır,girilen degisken bir arttırılır.//
	for (int i = 0; i < sayacO; i++)
	{
		cout << 'o' << "\t";
	}
	cout << "\n" << "U" << "\t" << sayacU << "\t"; // Eger girilen karakter u ise u yazdırılır,girilen degisken bir arttırılır.//
	for (int i = 0; i < sayacU; i++)
	{
		cout << 'u' << "\t";
	}

	cin.get();

}