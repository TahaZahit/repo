#include <stdio.h>
#include <conio.h>
#include <windows.h>
#define BOYUT 20 //tablo boyutu
#define yukari 72
#define asagi 80
#define sol 75
#define sag 77

//Fonksiyonlar
void xy(int, int); //imleci x,y koordinatına götürür
void tablo(int); //tablo 0oluşturma, 2çizme ve 1doldurma işlemleri 
void yonlendir(char);
void deger_azalt();
void yem();

//Globaller
int tablo_matris[BOYUT + 2][BOYUT + 2] = { 0 }; //tablo boyutunu matris yapar
int kafa = 3;//yılanın başı burda
int dead;
int yem_x = 3, yem_y = 3;
int puan = 0;
int zorluk = 1;
int y_c = BOYUT / 2, x_c = BOYUT / 2;
char yon, yon2, acaba;

int main()
{
	tablo(0);//tablo çevresini çiziyoruz
	tablo(1);//tablo yu matrise dolduruyoruz
	tablo_matris[BOYUT / 2][BOYUT / 2] = kafa;//yılanın başını merkeze koyuyoruz
	tablo(2);//yemi ve yılanı çizdiriyoruz

	dead = 0;
	do
	{
		if (kbhit())
		{
			yon2 = yon;
			acaba = getch();
			if (acaba == -32)
			{
				yon = getch();
			}
		}
		if ((yon2 == yukari || yon2 == asagi) && (yon == sol || yon == sag))
			yonlendir(yon);//Yilanin yonunu belirlemek icin
		else if ((yon2 == sag || yon2 == sol) && (yon == yukari || yon == asagi))
			yonlendir(yon);//Yilanin yonunu belirlemek icin
		else
		{
			yonlendir(yon2);//Yilanin yonunu belirlemek icin
			yon == yon2;
		}

		if (tablo_matris[y_c][x_c] == 0 || tablo_matris[y_c][x_c] == -1 || tablo_matris[y_c][x_c] == -2 || tablo_matris[y_c][x_c] == kafa - 1 || tablo_matris[y_c][x_c] == kafa - 2 || tablo_matris[y_c][x_c] == kafa)
		{
			tablo_matris[y_c][x_c] = kafa;
		}
		else//bir yere çarparsa
		{
			system("CLS");
			printf("kaza yaptın\n");
			getch();
			break;
		}
		tablo(2);
		if (tablo_matris[yem_x][yem_y] == -1)
		{
			deger_azalt();
		}
		else
		{
			yem();
			xy(60, 15);
			printf("Puan:%d", puan);
			kafa++;
			dead = 0;
		}

		Sleep(500 / zorluk);
	} while (1);
}
void yem()
{

	do
	{
		yem_x = rand() % 20 + 1;
		yem_y = rand() % 20 + 1;
	} while (tablo_matris[yem_x][yem_y] != 0);
	tablo_matris[yem_x][yem_y] = -1;
	puan += zorluk;
}
void xy(int x, int y) //imleci x,y koordinatına götürür
{
	COORD c;
	c.X = x;
	c.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void tablo(int s) //tablo işlemleri burada
{
	int x, y;
	//tabloin çevresini cizer
	if (s == 0) {
		for (int i = 0; i < BOYUT + 3; ++i)
		{
			xy(0, i);
			printf("%c", 219);
			xy(2 * (BOYUT + 2), i);
			printf("%c", 219);
		}
		for (int i = 0; i < 2 * (BOYUT + 2); ++i)
		{
			xy(i, BOYUT + 2);
			printf("%c", 219);
			xy(i, 0);
			printf("%c", 219);
		}
	}

	else if (s == 1) {
		for (x = 0; x < BOYUT + 2; ++x)
		{
			y = 0;
			tablo_matris[x][y] = -8;
			y = BOYUT + 1;
			tablo_matris[x][y] = -8;
		}
		for (y = 0; y < BOYUT + 2; ++y)
		{
			x = 0;
			tablo_matris[x][y] = -8;
			x = BOYUT + 1;
			tablo_matris[x][y] = -8;
		}
	}
	//tabloyu çizer
	else {
		for (x = 0; x < BOYUT + 2; ++x)
		{
			for (y = 0; y < BOYUT + 2; ++y)
			{
				//yem koyma
				if (tablo_matris[x][y] == -1)
				{
					xy(y * 2 + 1, x + 1);
					printf("*" );
				}
				//kuyruk silme
				if (tablo_matris[x][y] == 1)
				{
					xy(y * 2 + 1, x + 1);
					printf(" ");
				}
				//yılanı çizme
				else if (tablo_matris[x][y] == kafa - 1)
				{
					xy(y * 2 + 1, x + 1);
					printf("o");
				}

				if (tablo_matris[x][y] == kafa)
				{
					xy(y * 2 + 1, x + 1);
					printf("%c", 9679);
				}
			}
		}
	}

}

void yonlendir(char yon)//yönlendirme kısmı
{
	switch (yon)
	{
	case yukari://Yukari
		y_c--;
		break;
	case sol://Sol
		x_c--;
		break;
	case sag://Sag
		x_c++;
		break;
	case asagi://Asagi
		y_c++;
		break;
	}
}
//yılanin boyunun ayni kalmasi
void deger_azalt()
{
	int satir, sutun;
	for (satir = 0; satir <= 21; satir++)
	{
		for (sutun = 0; sutun <= 21; sutun++)
		{
			if (tablo_matris[satir][sutun] > 0)
				tablo_matris[satir][sutun]--;
		}
	}
}
