/*7. Sa se scrie un program care verifica daca un numar citit de
la tastatura pâna în valoarea de 65535 este palindrom atât în
baza 2 cât si în baza 10. Verificarea ca numarul ar fi
palindrom sa se implementeze cu ajutorul unui stack.
A) Sa se implementeze citirea conditionata pâna la 65535.
B) Sa se realizeze transformarea din zecimal în binar.
C) Adaugarea fiecarui bit într-un stack
D) Adaugarea fiecarei cifre într-un alt stack.
E) Verificarea ca cele doua variante sunt palindrom sau nu.
585 = 1001 0 0 1001 (binary) – PALINDROM
Palindrom – O secventa de caractere care se citeste exact la
fel indiferent de directia de citire (stânga dreapta sau dreapta
– stânga)*/

#include<stdio.h>
#include<stdlib.h>
#define MAX_VALUE 100

typedef struct{
	int top;
	int data[MAX_VALUE];
}STIVA;

void Push(STIVA *st, int bit)
{
	if(st->top==MAX_VALUE-1)
		printf("Stiva e plina!\n");
	else
		st->data[++st->top]=bit;
}

int palindrom(STIVA *st)
{
	int j=0;
	for(int i=st->top;i>=0;i--)
	{
		if(st->data[i]==st->data[j])
			j++;
		else
			return 0;
	}
	return 1;
}

int main()
{
	STIVA st_bit,st_nr;
	st_bit.top=-1;
	st_nr.top=-1;
	int x,aux;
	printf("\nDati numarul (pana in 65535): ");
	scanf("%d",&x);
	while(x>65535)
	{
		printf("\nNumar invalid!");
		printf("\nDati numarul (pana in 65535): ");
		scanf("%d",&x);
	}

	aux=x;
	while(aux)
	{
		Push(&st_nr,aux%10);
		aux/=10;
	}

	while(x)
	{
		Push(&st_bit,x%2);
		x/=2;
	}

	if(palindrom(&st_nr)==1 && palindrom(&st_bit)==1)
		printf("\nNumarul este palindrom in binar si in zecimal!\n");

	return 0;
}