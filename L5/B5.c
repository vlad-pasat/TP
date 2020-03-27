#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define MAX_SIZE 200

/*5. Sa se introduca într-o stiva toate numerele naturale pâna la
50. Din prima stiva se vor elimina numerele prime si se vor
adauga într-o a doua stiva sub forma binara.
A) Sa se adauge în stiva toate numerele naturale pâna la 50.
B) Sa se scoata din prima stiva numerele prime.
C) Transformarea numerelor prime în baza 2. (sub forma
finala)
D) Sa se populeze a doua stiva cu forma binara.
! Atentie la refacerea primei stive !*/

typedef struct{
	int data;
}STIVA;

void push_st1(STIVA *st1, int *top1, int valoare)
{
	if(*top1==MAX_SIZE-1)
		printf("Stiva este plina!\n");
	else{
		++(*top1);
		(st1+*top1)->data=valoare;
	}
}

void push_st2(STIVA *st2, int *top2, int valoare)
{
	if(*top2==MAX_SIZE-1)
		printf("Stiva este plina!\n");
	else{
		valoare=transf_in_binar(valoare);
		++(*top2);
		(st2+*top2)->data=valoare;
	}
}

int prim(int valoare)
{
	for(int d=2;d<=sqrt(valoare);d++)
		if(valoare%d==0)
			return 0;
	return 1;
}

int transf_in_binar(int valoare)
{
	int binar=0,p=1;
	while(valoare)
	{
		binar+=(valoare%2)*p;
		p*=10;
		valoare/=2;
	}
	return binar;
}

void stergere(STIVA *st1,int *top1)
{
	for(int i=0;i<=*top1;i++)
	{
		if(prim((st1+i)->data)==1)
		{
			for(int j=i;j<*top1;j++)
				(st1+j)->data=(st1+j+1)->data;
			--(*top1);
			--i;
		}
	}
}

int main()
{
	STIVA st1[MAX_SIZE], st2[MAX_SIZE];
	int top1=-1,top2=-1,i,n;

	for(i=1;i<=50;i++)
		push_st1(st1,&top1,i);

	for(i=0;i<=top1;i++)	
		if(prim((st1+i)->data)==1)
			push_st2(st2,&top2,(st1+i)->data);
	
	for(i=0;i<=top2;i++)
		printf("%d ",(st2+i)->data);
	
	return 0;
}