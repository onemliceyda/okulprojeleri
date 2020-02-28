
/****************************************************************************
**					                             SAKARYA ÜNİVERSİTESİ
**			                          BİLGİSAYAR VE BİLİŞİM BİLİMLERİ FAKÜLTESİ
**				                          BİLGİSAYAR MÜHENDİSLİĞİ BÖLÜMÜ
**				                            PROGRAMLAMAYA GİRİŞİ DERSİ
**
**   ÖDEV NUMARASI:PROJE ÖDEVİ
**   ÖĞRENCİ ADI: CEYDA ÖNEMLİ
**   ÖĞRENCİ NUMARASI.: G181210107
**	 DERS GRUBU: B GRUBU
****************************************************************************/

#include <iostream>
#include <Windows.h>
#include <time.h>

using namespace std;

struct Ucak {
	int x;
	int y;
	char karakter;
};

struct Mermi {
	int x;
	int y;
	char karakter;
};

struct Dusman {
	int x;
	int y;
	char karakter;
};

const int maxMermi = 2000;

const int maxDusman = 2000;

int mermiSayac = 0;

int dusmanSayac = 0;

const int genislik = 80;

const int yukseklik = 20;

char sahne[genislik][yukseklik];

char tuslar[256];

Ucak ucak;

Mermi mermi[maxMermi];

Dusman dusman[maxDusman];


void gotoxy(int x, int y) {
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void cursorGizle() {
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursorInfo;

	GetConsoleCursorInfo(out, &cursorInfo);
	cursorInfo.bVisible = false;
	SetConsoleCursorInfo(out, &cursorInfo);
}

void sahneTemizle() {
	for (int y = 0; y < yukseklik; y++) {

		for (int x = 0; x < genislik; x++) {
			sahne[x][y] = NULL;
		}

		cout << endl;
	}
}
void sahneCiz() {
	for (int y = 0; y < yukseklik; y++) {

		for (int x = 0; x < genislik; x++) {
			cout << sahne[x][y];
		}

		cout << endl;
	}
}
void talimatlar() {
	gotoxy(80, 1);
	cout << "Yukari:    'A'";
	gotoxy(80, 2);
	cout << "Asagi:     'S'";
	gotoxy(80, 3);
	cout << "Ates Etme: 'Space'";
}

void sinirOlustur() {
	for (int x = 0; x < genislik; x++) {
		sahne[x][0] = 176;
		sahne[x][yukseklik - 1] = 176;
	}
	for (int y = 0; y < yukseklik; y++) {
		sahne[0][y] = 176;
		sahne[genislik - 1][y] = 176;

	}
}

void ucakOlustur() {
	ucak.x = 3;
	ucak.y = 10;
	ucak.karakter = 176;
}
void ucakYerles() {
	int x = ucak.x;
	int y = ucak.y;
	sahne[x][y] = ucak.karakter;
	sahne[x - 1][y - 1] = ucak.karakter;
	sahne[x - 1][y + 1] = ucak.karakter;
	sahne[x - 2][y - 2] = ucak.karakter;
	sahne[x - 2][y + 2] = ucak.karakter;
}

void mermiOlustur() {
	mermi[mermiSayac].x = ucak.x + 1;
	mermi[mermiSayac].y = ucak.y;
	mermi[mermiSayac].karakter = 198;
	mermiSayac++;
}
void atesEt() {
	for (int i = 0; i < mermiSayac; i++) {
		if (mermi[i].y != 0) {
			int x = mermi[i].x;
			int y = mermi[i].y;
			sahne[x][y] = mermi[i].karakter;
		}
	}
}
void mermiHareket() {
	for (int i = 0; i < maxMermi; i++) {
		if (mermi[i].x < 78) {
			mermi[i].x++;
		}
		else {
			mermi[i].karakter = NULL;
		}
	}
}

void dusmanOlustur() {
	dusman[dusmanSayac].karakter = 177;
	dusman[dusmanSayac].x = 78;
	dusman[dusmanSayac].y = 3 + rand() % (16 - 3 + 1);
	dusmanSayac++;
}
void dusmanYerlestir() {
	for (int i = 0; i <= dusmanSayac; i++) {
		if (dusman[i].y != 0) {
			sahne[dusman[i].x][dusman[i].y] = dusman[i].karakter;
			sahne[dusman[i].x + 1][dusman[i].y] = dusman[i].karakter;
		}
	}
}
void dusmanHareket() {


	for (int i = 0; i <= dusmanSayac; i++) {
		int kontrol = dusman[i].x - 1;
		if (sahne[kontrol][dusman[i].y] == (char)198 || sahne[kontrol - 1][dusman[i].y] == (char)198) {
			dusman[i].karakter = NULL;
		}
		if (dusman[i].x > 2) {
			dusman[i].x--;
		}
		if (dusman[i].x <= 2) {
			dusman[i].karakter = NULL;
		}
	}
}

void kaybettiniz() {
	sahne[41][10] = 'K';
	sahne[42][10] = 'A';
	sahne[43][10] = 'Y';
	sahne[44][10] = 'B';
	sahne[45][10] = 'E';
	sahne[46][10] = 'T';
	sahne[47][10] = 'T';
	sahne[48][10] = 'I';
	sahne[49][10] = 'N';
	sahne[52][10] = '!';
	gotoxy(0, 0);
	sahneCiz();
	system("pause");
}

void klavyeOku(char tuslar[]) {
	for (int x = 0; x < 256; x++) {
		tuslar[x] = (char)(GetAsyncKeyState(x) >> 8);
	}
}
void klavyeKontrol() {
	klavyeOku(tuslar);
	if (tuslar['A'] != 0 && ucak.y != 3) {
		ucak.y--;
	}
	else if (tuslar['S'] != 0 && ucak.y != 16) {
		ucak.y++;
	}
	if (tuslar[32] != 0) {
		mermiOlustur();
	}
}


int main() {
	int sayac = 0;
	ucakOlustur();
	while (true) {
		cursorGizle();
		talimatlar();
		sahneTemizle();
		gotoxy(0, 0);
		sinirOlustur();
		mermiHareket();
		if (sayac % 18 == 0) {
			dusmanOlustur();
		}
		sayac++;
		atesEt();
		dusmanHareket();
		dusmanYerlestir();
		ucakYerles();
		klavyeKontrol();
		sahneCiz();
		int x = ucak.x;
		int y = ucak.y;
		if (sahne[x + 1][y] == char(177) || sahne[x][y - 1] == char(177) || sahne[x][y + 1] == char(177) || sahne[x][y - 2] == char(177) || sahne[x][y + 2] == char(177)) {
			kaybettiniz();
			break;
		}
	}
}