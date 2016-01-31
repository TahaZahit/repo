#include <stdio.h>

//bunun daha kolay bir yolu olsa gerek


int aynimi(char a[],char b[]){
	int i=0;
	int boyut=(a<b)?sizeof(a):sizeof(b);
	for(i=0;i<boyut;i++){
		if(a[i]!=b[i]){
			return 0;
		}
		else{
			return 1;
		}
	}
}


int main() {
	char u[5]="user";
	char p[5]="pass";
	char k[255];
	char s[255];
	do{
		printf("Kullanici Adi:");
		scanf("%s",k);
		printf("Sifre:");
		scanf("%s",s);
		(aynimi(u,k)==0||aynimi(p,s)==0)?printf("\nYanlis Giris!!\n\n"):printf("Giris Basarili");
	}
	while(aynimi(u,k)==0||aynimi(p,s)==0);
}
