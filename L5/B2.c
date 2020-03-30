/*
2. Se citeste de la tastatura un numar C cu valori posibile
intre 0-7. Dupa citirea numarului &quot;C&quot; se vor citi de la tastatura
&quot;N&quot; numere iar acele numere care au reprezentarea lor
binara, bitul de pe pozitia &quot;C&quot; cu valoare 1, vor fi introduse
intr-o stiva. Sa se afiseze in final tot continutul stivei
(indiferent de ordine)
Ex:
C = 2
N = 5
- Acum se citesc 5 numere:
1 2 3 4 5
- Se afiseaza la sfarsit
4 5
Deoarece 4 = 100 si 5 = 101, bitul de pe pozitia &quot;2&quot; este &quot;1&quot;
*/

#include<stdio.h>
#include<stdlib.h>
#define MAX_VALUE 100
typedef struct{
	int top;
	int data[MAX_VALUE];
}STIVA;

int GetFlag(int x, int c)
{
	return (1 & (x>>c));
}

void push(STIVA *st, int x)
{
	if(st->top==MAX_VALUE-1)
		printf("\nStiva este plina!");
	else
		st->data[++st->top]=x;
}
void afisare(STIVA *st)
{
	if(st->top==-1)
		printf("\nStiva este goala!\n");
	else
		for(int i=0;i<=st->top;i++)
			printf("%d ",st->data[i]);
}

int main()
{
	STIVA st;
	st.top=-1;
	int c,n,x;
	printf("\nDati C(apartine [0,7]): ");
	scanf("%d",&c);
	while(c<0 || c>7)
	{
		printf("\nNumar invalid!\nC trebuie sa apartina [0,7]: ");
		scanf("%d",&c);
	}
	printf("\nCate numere sa se citeasca? ");
	scanf("%d",&n);
	printf("\nDati numerele:");
	for(int i=0;i<n;i++)
	{
		scanf("%d",&x);
		if(GetFlag(x,c)==1)
			push(&st,x);
	}
	printf("\nNumerele din stiva sunt: ");
	afisare(&st);
	return 0;
}