#include <stdio.h>
#include <Windows.h>

struct data
{
	int id;
	char detail[16];
	char username[16];
	char password[16];
}temp;

char sifre[16];

void sifrele(char a[], char *sifre);
void sifrecoz(char a[], char *sifre);
int getid(FILE *f);
void ekle(FILE *f);
void goster(FILE *f);
void duzenle(FILE *f);



int main() {
	FILE *f = NULL;
	printf("password:");
	scanf("%s", sifre);
	
	int s=0;
	if (!fopen("db", "r")) {
		printf("please insert a data\n");
		ekle(f);
	}
	

	while (s != 3)
	{
		goster(f);
		printf("1- ekle	\n");
		printf("2- duzenle	\n");
		printf("3- exit	\n");

		scanf("%d", &s);
		switch (s)
		{
		case 1:
			ekle(f);
			break;
		case 2:
			duzenle(f);
			break;
		case 3:
			break;
		default:
			printf("hatali secim");
			break;
		}
	}
}


void sifrele(char a[], char *sifre) {
	int x = 5;
	for (size_t i = 0; sifre[i] != '\0'; i++)
	{
		x += (int)sifre[i];
	}
	for (size_t i = 0; a[i] != '\0'; i++)
	{
		a[i] = (~(int)a[i]) + (x*i) % 100;
	}
}

void sifrecoz(char a[], char *sifre) {
	int x = 5;
	for (size_t i = 0; sifre[i] != '\0'; i++)
	{
		x += (int)sifre[i];
	}
	for (size_t i = 0; a[i] != '\0'; i++)
	{
		a[i] = ~(a[i] - (x*i) % 100);
	}
}



int getid(FILE *f) {
	if (fopen("db", "r"))
	{
		int i = 0;
		f = fopen("db", "r");
		while (feof(f) == 0)
		{
			fread(&temp, sizeof(struct data), 1, f);
			i++;
		}
		fclose(f);
		return i - 1;
	}
	else return 0;
}

void ekle(FILE *f) {
	temp.id = getid(f);
	f = fopen("db", "a+");
	printf("detail:");
	scanf("%s", temp.detail);
	printf("username:");
	scanf("%s", temp.username);
	printf("password:");
	scanf("%s", temp.password);
	sifrele(temp.detail, sifre);
	sifrele(temp.username, sifre);
	sifrele(temp.password, sifre);
	fwrite(&temp, sizeof(struct data), 1, f);
	fclose(f);
}

void goster(FILE *f) {
	system("CLS");
	printf("------------------------------------------------\n");
	printf("ID\tDTL\tUSR\tPASS\n");
	f = fopen("db", "r");
	while (feof(f) == 0)
	{
		fread(&temp, sizeof(struct data), 1, f);
		if (feof(f) == 0) {
			sifrecoz(temp.detail, sifre);
			sifrecoz(temp.username, sifre);
			sifrecoz(temp.password, sifre);
			printf("%d\t%s\t%s\t%s\n", temp.id, temp.detail, temp.username, temp.password);
		}
	}
	fclose(f);
	printf("------------------------------------------------\n");

}

void duzenle(FILE *f) {
	f = fopen("db", "r+");
	int id;
	printf("id: ");
	scanf("%d", &id);
	do
	{
		fread(&temp, sizeof(struct data), 1, f);
	} while (temp.id != id);

	printf("detail:");
	scanf("%s", temp.detail);
	printf("username:");
	scanf("%s", temp.username);
	printf("password:");
	scanf("%s", temp.password);
	fseek(f, id*sizeof(struct data), SEEK_SET);
	sifrele(temp.detail, sifre);
	sifrele(temp.username, sifre);
	sifrele(temp.password, sifre);
	fwrite(&temp, sizeof(struct data), 1, f);
	fclose(f);
}


