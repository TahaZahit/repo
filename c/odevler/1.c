#include <stdio.h>
#include <stdlib.h>
#include <time.h>

main()
{
	srand(time(NULL));
	int r=rand()%101,tahmin=-1;
	while(tahmin!=r){
		printf("tahmin ettiginiz SAYI: ");
		scanf("%d",&tahmin);
		(tahmin<r)?printf("Elini korkak alistirma\n"):((tahmin>r)?printf("Ufak at\n"):printf("helal olsun dogru bildin"));	
	}
}
