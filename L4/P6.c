#include<stdio.h>
#include<stdlib.h>

/*
Sa se realizeze un program care realizeaza suma a doua
numerelor intr-o metoda separate de metoda main, iar aceea
metoda returneaza un pointer.
*/

void Suma(int *a, int *b,int *s)
{
	*s=*a+*b;
}

int main()
{
	int *s,*a,*b;
	s=(int*)malloc(sizeof(int));
	a=(int*)malloc(sizeof(int));
	b=(int*)malloc(sizeof(int));
	printf("\na="); scanf("%d",a);
	printf("\nb="); scanf("%d",b);
	Suma(a,b,s);
	printf("\nsuma=%d\n",*s);
	return 0;
}