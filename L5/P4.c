#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 100
/*
4. Sa se realizeze o implementare de stiva FARA a ne folosii
variabile globale iar TOATE variabilele trebuiesc sa fie
pointeri. Stiva este de numere intregi. Se va introduce in
stiva 7 numere de tip intreg. - Sunt necesare toate metodele
(de verificat plin / gol / peek / push / pop)
*/

typedef struct{
	int *data;
}STIVA;

int plin(int *top)
{
	if(*top==MAX_SIZE-1)
		return 1;
	return 0;
}

int gol(int *top)
{
	if(*top==-1)
		return 1;
	return 0;
}

void peek(STIVA *st, int *top)
{
	if(gol(top)==1)
		printf("Stiva este goala!\n");
	else printf("%d", (st+*top)->data);

}
void push(STIVA *st, int *valoare, int *top)
{
	if(plin(top)==1)
		printf("\nStiva este plina!\n");
	else
		++(*top);
		(st+*top)->data=*valoare;
}


void pop(STIVA *st, int *top)
{
	if(gol(top)==1)
		printf("\nStiva este goala!\n");
	else{
		free((st+*top)->data);
		--(*top);
	}
}


int main()
{
	int *valoare,*opt,*top;
	valoare=(int*)malloc(sizeof(int));
	opt=(int*)malloc(sizeof(int));
	top=(int*)malloc(sizeof(int));
	*top=-1;
	STIVA *st[MAX_SIZE];
	if(st=='\0')
	{
		printf("Eroare!\n");
		exit(0);
	}
	do{
		printf("\n1.Plin\n");
		printf("2.Gol\n");
		printf("3.Peek\n");
		printf("4.Push\n");
		printf("5.Pop\n");
		printf("0.Iesire\n");
		printf(">>> ");
		scanf("%d",opt);
		switch(*opt)
		{
			case 0:
				exit(0);
				break;
			case 1:
				if(plin(top)==1)
					printf("Stiva este plina!\n");
				else printf("\nStiva NU este plina si se poate folosi!\n");
				break;
			case 2:
				if(gol(top)==1)
					printf("\nStiva este goala!\n");
				else printf("\nStiva NU este goala!\n");
				break;
			case 3:
				peek(st,top);
				break;
			case 4:
				printf("\nDati valoarea: ");
				scanf("%d",valoare);
				push(st,valoare,top);
				break;
			case 5:
				pop(st,top);
				break;
			default:
				printf("Alegeti o optiune valida!\n");
				break;
		}
	}while(1);
	return 0;
}