#include <iostream>
using namespace std;
int main()
{
	int i, j; // i=yildiz sayisi,j=satirsayisi,space=bosluk olarak tanimlanmistir.//
	int space = 1;
	int MAX = 5;


	for (i = MAX; i > 0; i--) //yildiz sayisi max degere esitlenip,sifirdan büyük oldugu durumlarda birer azaltilmistir.//
	{

		for (j = 0; j < i; j++) //satir sayisi yildiz sayisindan kücük oldugunda satir sayisi birer arttirilmistir.Bu durumda yildiz ciktisi alınır//
		{
			cout << "* ";
		}
		for (j = 0; j < space; j++) //satir sayisi bosluktan kücükse satir sayisi attirilip bosluk ciktisi alinmistir.//
		{
			cout << " ";
		}

		for (j = 0; j < i; j++)
		{
			std::cout << " *";
		}

		cout << "\n";
		space += 4;
	}
	for (i = 0; i <= MAX; i++)
	{

		for (j = 0; j < i; j++)
		{
			std::cout << "* ";
		}
		for (j = 0; j < space; j++)
		{
			std::cout << " ";
		}

		for (j = 0; j < i; j++)
		{
			std::cout << " *";
		}

		std::cout << "\n";
		space -= 4;
	}
	system("pause");

}

