#include <stdio.h>
#include <windows.h>
#include <time.h>
#define yukari 72
#define asagi 80
#define sol 75
#define sag 77


void xy(int, int);
void tablo(int);
void basla();
int bosyon(int, int);
void yonlen(int, int, int);
void hayalet(int);
void hamle(char);
void ol();



int matris[31][28] = { 0,1,1,1,1,1,1,1,1,1,1,1,1,2,0,1,1,1,1,1,1,1,1,1,1,1,1,2,5,9,9,9,9,9,9,9,9,9,9,9,9,5,5,9,9,9,9,9,9,9,9,9,9,9,9,5,5,9,0,1,2,9,0,1,1,1,1,2,9,5,5,9,0,1,1,1,1,2,9,0,1,2,9,5,5,9,5,6,5,9,5,6,6,6,6,5,9,5,5,9,5,6,6,6,6,5,9,5,6,5,9,5,5,9,3,1,4,9,3,1,1,1,1,4,9,3,4,9,3,1,1,1,1,4,9,3,1,4,9,5,5,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,5,5,9,0,1,2,9,0,1,2,9,0,1,1,1,1,1,1,2,9,0,1,2,9,0,1,2,9,5,5,9,3,1,4,9,5,6,5,9,3,1,1,2,0,1,1,4,9,5,6,5,9,3,1,4,9,5,5,9,9,9,9,9,5,6,5,9,9,9,9,5,5,9,9,9,9,5,6,5,9,9,9,9,9,5,5,9,0,1,2,9,5,6,3,1,1,2,9,5,5,9,0,1,1,4,6,5,9,0,1,2,9,5,5,9,5,6,5,9,5,6,0,1,1,4,9,5,5,9,3,1,1,2,6,5,9,5,6,5,9,5,5,9,5,6,5,9,5,6,5,9,9,9,9,5,5,9,9,9,9,5,6,5,9,5,6,5,9,5,5,9,5,6,5,9,5,6,5,9,0,2,9,5,5,9,0,2,9,5,6,5,9,5,6,5,9,5,5,9,5,6,5,9,3,1,4,9,5,5,9,3,4,9,5,5,9,3,1,4,9,5,6,5,9,5,5,9,5,6,5,9,6,6,6,9,5,5,9,9,9,9,5,5,9,9,9,9,9,5,6,5,9,5,5,9,5,6,5,9,0,1,2,9,5,3,1,1,1,1,4,5,9,0,1,2,9,5,6,5,9,5,5,9,3,1,4,9,3,1,4,9,3,1,1,1,1,1,1,4,9,3,1,4,9,3,1,4,9,5,5,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,5,5,9,0,1,2,9,0,1,2,9,0,1,1,1,1,1,1,2,9,0,1,2,9,0,1,2,9,5,5,9,5,6,5,9,5,6,5,9,3,1,1,2,0,1,1,4,9,5,6,5,9,5,6,5,9,5,5,9,5,6,5,9,5,6,5,9,9,9,9,5,5,9,9,9,9,5,6,5,9,5,6,5,9,5,5,9,5,6,5,9,5,6,5,9,0,2,9,5,5,9,0,2,9,5,6,5,9,5,6,5,9,5,5,9,5,6,5,9,3,1,4,9,3,4,9,3,4,9,3,4,9,3,1,4,9,5,6,5,9,5,5,9,5,6,5,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,5,6,5,9,5,5,9,5,6,3,2,9,0,2,9,0,1,1,1,1,1,1,2,9,0,2,9,0,4,6,5,9,5,5,9,3,1,1,4,9,5,5,9,3,1,1,2,0,1,1,4,9,5,5,9,3,1,1,4,9,5,5,9,9,9,9,9,9,5,5,9,9,9,9,5,5,9,9,9,9,5,5,9,9,9,9,9,9,5,5,9,0,1,1,1,1,4,3,1,1,2,9,5,5,9,0,1,1,4,3,1,1,1,1,2,9,5,5,9,3,1,1,1,1,1,1,1,1,4,9,3,4,9,3,1,1,1,1,1,1,1,1,4,9,5,5,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,5,3,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,4 };
int hayalet1[] = { 1,2 };
int hayalet2[] = { 1,10 };
int hayalet3[] = { 17,3 };
int hayalet4[] = { 17,8 };
int hayalet5[] = { 17,13 };
int oyuncu[] = { 29,15 };
int kx, ky, hml, eskiyon = 0;
int durum = 1;

int main() {
	srand(time(NULL));
	system("mode 31, 34");
	basla();
	tablo(0);
	while (durum)
	{
		Sleep(100);//hız ayarı
		if (kbhit()) {
			hml = getch();
		}
		hamle(hml);
		hayalet(1);
		hayalet(2);
		hayalet(3);
		hayalet(4);
		hayalet(5);
	}

	getch();

}

void xy(int x, int y) //imleci x,y koordinatına götürür
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void tablo(int islem)
{
	int i, j;
	if (islem == 0)
	{
		int i, j;
		for (i = 0; i < 31; i++)
		{
			for (j = 0; j < 28; j++)
			{
				if (matris[i][j] == 0) { printf("%c", 201); }
				else if (matris[i][j] == 1) { printf("%c", 205); }
				else if (matris[i][j] == 2) { printf("%c", 187); }
				else if (matris[i][j] == 3) { printf("%c", 200); }
				else if (matris[i][j] == 4) { printf("%c", 188); }
				else if (matris[i][j] == 5) { printf("%c", 186); }
				else if (matris[i][j] == 6) { printf("%c", 32); }
				else if (matris[i][j] == 7) { printf("%c", 254); }
				else if (matris[i][j] == 8) { printf("%c", 178); }
				else if (matris[i][j] == 9) { printf("*"); }

			}
			printf("\n");
		}
	}
}
void basla() {
	matris[hayalet1[0]][hayalet1[1]] = 8;
	matris[hayalet2[0]][hayalet2[1]] = 8;
	matris[hayalet3[0]][hayalet3[1]] = 8;
	matris[hayalet4[0]][hayalet4[1]] = 8;
	matris[hayalet5[0]][hayalet5[1]] = 8;
	matris[oyuncu[0]][oyuncu[1]] = 7;

}

void yonlen(int yon, int x, int y) {
	int temp = matris[y][x];
	int yeni;

	if (yon == 0) {//sol
		yeni = matris[y][x - 1];
		if (yeni == 9 || yeni == 6)
		{
			xy(x, y);
			if (temp == 8) {
				printf("*");
				matris[y][x] = 9;
				eskiyon = 0;
			}
			else {
				printf("%c", 32);
				matris[y][x] = 6;
			}
			xy(x - 1, y);
			if (temp == 8) {
				printf("%c", 178);
				matris[y][x - 1] = 8;
			}
			else {
				printf("%c", 254);
				matris[y][x - 1] = 7;
			}
			kx = x - 1;
			ky = y;
		}
		else if (yeni == 7) { ol(); }
		else if (temp == 8) {
			yonlen(bosyon(x, y), x, y);

		}
		else { kx = x; ky = y; return; }


	}
	else if (yon == 1) {//sag
		yeni = matris[y][x + 1];
		if (yeni == 9 || yeni == 6)
		{
			xy(x, y);
			if (temp == 8) {
				printf("*");
				matris[y][x] = 9;
				eskiyon = 1;
			}
			else {
				printf("%c", 32);
				matris[y][x] = 6;

			}
			xy(x + 1, y);
			if (temp == 8) {
				printf("%c", 178);
				matris[y][x + 1] = 8;
			}
			else { printf("%c", 254); }
			kx = x + 1;
			ky = y;
		}
		else if (yeni == 7) { ol(); }
		else if (temp == 8) {
			yonlen(bosyon(x, y), x, y);

		}
		else { kx = x; ky = y; return; }

	}
	else if (yon == 2) {//yukari
		yeni = matris[y - 1][x];
		if (yeni == 9 || yeni == 6)
		{
			xy(x, y);
			if (temp == 8) {
				printf("*");
				matris[y][x] = 9;
				eskiyon = 2;
			}
			else {
				printf("%c", 32);
				matris[y][x] = 6;
			}
			xy(x, y - 1);
			if (temp == 8) {
				printf("%c", 178);
				matris[y - 1][x] = 8;
			}
			else {
				printf("%c", 254);
				matris[y - 1][x] = 7;
			}
			kx = x;
			ky = y - 1;
		}
		else if (yeni == 7) { ol(); }

		else if (temp == 8) {
			yonlen(bosyon(x, y), x, y);

		}
		else { kx = x; ky = y; return; }


	}
	else if (yon == 3) {//asagi
		yeni = matris[y + 1][x];
		if (yeni == 9 || yeni == 6)
		{
			xy(x, y);
			if (temp == 8) {
				printf("*");
				matris[y][x] = 9;
				eskiyon = 3;
			}
			else {
				printf("%c", 32);
				matris[y][x] = 6;
			}
			xy(x, y + 1);
			if (temp == 8) {
				printf("%c", 178);
				matris[y + 1][x] = 8;
			}
			else {
				printf("%c", 254);
				matris[y + 1][x] = 7;
			}
			kx = x;
			ky = y + 1;
		}
		else if (yeni == 7) { ol(); }
		else if (temp == 8) {
			yonlen(bosyon(x, y), x, y);

		}
		else { kx = x; ky = y; return; }

	}
	else { kx = x; ky = y; return; }
}

void hayalet(int a) {
	if (a == 1) {
		int random;
		xy(hayalet1[1], hayalet1[0]);
		random = rand() % 4;
		yonlen(random, hayalet1[1], hayalet1[0]);
		hayalet1[1] = kx;
		hayalet1[0] = ky;
	}
	else if (a == 2) {
		int random;
		xy(hayalet2[1], hayalet2[0]);
		random = rand() % 4;
		yonlen(random, hayalet2[1], hayalet2[0]);
		hayalet2[1] = kx;
		hayalet2[0] = ky;
	}
	else if (a == 3) {
		int random;
		xy(hayalet3[1], hayalet3[0]);
		random = rand() % 4;
		yonlen(random, hayalet3[1], hayalet3[0]);
		hayalet3[1] = kx;
		hayalet3[0] = ky;
	}
	else if (a == 4) {
		int random;
		xy(hayalet4[1], hayalet4[0]);
		random = rand() % 4;
		yonlen(random, hayalet4[1], hayalet4[0]);
		hayalet4[1] = kx;
		hayalet4[0] = ky;
	}
	else if (a == 5) {
		int random;
		xy(hayalet5[1], hayalet5[0]);
		random = rand() % 4;
		yonlen(random, hayalet5[1], hayalet5[0]);
		hayalet5[1] = kx;
		hayalet5[0] = ky;
	}
}

void hamle(char yon) {
	switch (yon)
	{
	case sol:
		yonlen(0, oyuncu[1], oyuncu[0]);
		oyuncu[0] = ky; oyuncu[1] = kx;
		break;
	case sag:
		yonlen(1, oyuncu[1], oyuncu[0]);
		oyuncu[0] = ky; oyuncu[1] = kx;
		break;
	case yukari:
		yonlen(2, oyuncu[1], oyuncu[0]);
		oyuncu[0] = ky; oyuncu[1] = kx;
		break;
	case asagi:
		yonlen(3, oyuncu[1], oyuncu[0]);
		oyuncu[0] = ky; oyuncu[1] = kx;
		break;
	default:
		break;
	}
}

int bosyon(int x, int y) {
	int yonler[4] = { 5 };
	int rnd;
	if (matris[y][x + 1] == 6 || matris[y][x + 1] == 9) { yonler[0] = 0; }
	if (matris[y][x + 1] == 6 || matris[y][x + 1] == 9) { yonler[1] = 1; }
	if (matris[y][x + 1] == 6 || matris[y][x + 1] == 9) { yonler[2] = 2; }
	if (matris[y][x + 1] == 6 || matris[y][x + 1] == 9) { yonler[3] = 3; }
	do
	{
		rnd = rand() % 4;
	} while (yonler[rnd] == 5);
	{
		rnd = rand() % 4;
	}
	return yonler[rnd];
}
void ol() {
	system("CLS");
	printf("Kaybettiniz\n");
	system("PAUSE");
	durum = 0;
}
