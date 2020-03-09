#include<stdio.h>
#include<stdlib.h>
#include<time.h>
/*
Sa se verifice daca operatia BINARA de "SAU" ("OR") aplicata pe un sir "N" de
numere intregi citit de la tastatura rezulta un numar par sau impar
NU aveti voie sa folositi "%", impartire cu rest/modulo.
Help:  se consulta tabelul de adevar in cadrul operatiilor de tip binary.

A B A+B
0 0 0
0 1 1
1 0 1
1 1 1

luam vectorul v[n]={14 2 5 7}
14=1110
2=0010
5=0101
7=0111

1110
0010
0101
0111
-----OR
1111

1111=15

Acum cum determinam daca 15 e par sau nu fara %?

Daca ultima cifra a numarului in binar este 1, atunci este nr impar, in caz contrar este 0.
*/
int main()
{
	int x=0,n,i,v[10];
	FILE *f;
	f=fopen("tema_lab3.txt","r");

	if(f==NULL)
	{
		printf("\nEroare la deschiderea fisierului!\n");
		exit(0);
	}

	printf("\nVectorul va fi citit din fisierul tema_lab3.txt.\n");
	sleep(0.75);
	fscanf(f,"%d",&n);
	printf("\nn=%d",n);

	for(i=0;i<n;i++)
		fscanf(f,"%d",&v[i]);

	printf("\nv=");
	for(i=0;i<n;i++)
		printf("%d ",v[i]);
	printf("\n");

	x=v[0];
	for(i=1;i<n;i++)
		x=(x|v[i]);
	printf("\nx=%d\n",x);

	if(1==1&(x>>0))
		printf("\nNumarul este impar.\n");
	else printf("\nNumarul este par.\n");
	return 0;
}