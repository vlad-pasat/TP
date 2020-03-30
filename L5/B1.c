/*1. Sa se scrie un program care citeste de la tastura "N"
numere naturale. Pentru fiecare numar se va determina forma
lui binara, se va calcula inversul binar ,iar mai apoi se
introduce intr-o stiva forma binara inversata.
Ex:
Input : 27
Forma binara : 0001 1011
Forma binara stiva output: 1110 0100
*/

#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 100
typedef struct{
	int top;
	int data[MAX_SIZE];
}STIVA;

int convesie_in_binar(int inv)
{
	int binar=0,p=1;
	while(inv)
	{
		binar+=(inv%2)*p;
		p*=10;
		inv/=2;
	}
	return binar;
}

void push(STIVA *st, int x)
{
	if(st->top == MAX_SIZE-1)
		printf("Stiva este plina!\n");
	else{
		st->top++;
		st->data[st->top]=x;
	}
}

void afisare_stiva(STIVA st)
{
	if(st.top==-1)
		printf("Stiva este goala!\n");
	else{
		for(int i=st.top;i>=0;i--)
			printf("\n%d",st.data[i]);
	}
}

int main()
{
	STIVA st;
	st.top=-1;
	int n,i,x,inv=0;
	printf("\nCate numere se vor citi? n=");
	scanf("%d",&n);

	for(i=0;i<n;i++)
	{
		if(i==0)
			printf("\nDati primul numar: ");
		else 
			printf("\nDati cel de-al %d-lea numar: ", i+1);

		scanf("%d",&x);
		inv=~x;
		inv=convesie_in_binar(inv);
		printf("%d",inv );
		push(&st,inv);
	}
	afisare_stiva(st);
}
