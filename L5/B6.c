/*6. Se citeste de la tastatura un numar zecimal pâna în 255. Sa
se Înscrie într-o stiva reprezentarea sa binara. Sa se
genereze pe stack cea mai mare valoarea posibila.
A) Sa se implementeze citirea conditionata pâna la 255.
B) Sa se realizeze transformarea din zecimal în binar.
C) Adaugarea fiecarui bit într-o stiva
D) Sa se genereze valoarea maxima posibila din valorile de
pe stiva.
27 -> 0001 1011 (val binara) – Stack initial
1111 0000 – Valoarea maxima
5 -> 0000 0101 (val binara) – Stack initial
1100 0000 – Valoarea maxima*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX_VALUE 100

typedef struct{
	int top;
	int data[MAX_VALUE];
}STIVA;

void push(STIVA *st, int bit)
{
	if(st->top==MAX_VALUE-1)
		printf("Stiva e plina!\n");
	else
		st->data[++st->top]=bit;
}

void afisare(STIVA *st)
{
	for(int i=st->top;i>=0;i--)
		printf("%d",st->data[i]);
}

void valoare_maxima(STIVA *st)
{
	int c=0;
	for(int i=st->top;i>=0;i--)
		if(st->data[i]==1)
			c++;
	for(int i=st->top;i>=0;i--)
		if(c!=0)
		{
			printf("1");
			c--;
		}
		else printf("0");
}

int main()
{
	STIVA st;
	st.top=-1;
	int n,bit;
	printf("\nDati numarul(pana in 255): ");
	scanf("%d",&n);
	while(n>255)
	{
		printf("\nValoarea depaseste 255!!!\n");
		printf("\nDati numarul(pana in 255): ");
		scanf("%d",&n);
	}

	while(st.top<7)
	{
		push(&st,n%2);
		n/=2;
	}
	printf("\nNr in binar este: ");
	afisare(&st);

	printf("\nValoarea maxima este: ");
	valoare_maxima(&st);
	return 0;
}