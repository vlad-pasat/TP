/*3. Se citesc de la tastatura tastatura &quot;N&quot; numere intregi. Sa
se verifice folosind DOAR stive daca numerele respective
sunt palindroame, iar numere care sunt palindroame vor fi
introduce intr-o stiva. La sfarsit se va afisa continutul stivei
respective. Cerinta de implementare: Se va implementa o
singura metoda de Push/Pop/Peek, se va stii pe care
stiva se lucreaza transmitand parametrii prin referinta.*/

#include<stdio.h>
#include<stdlib.h>
#define MAX_VALUE 100
typedef struct{
	int top;
	int data[MAX_VALUE];
}STIVA;

int palindrom(int x)
{
	int aux=x,inv=0,c;
	while(x)
	{
		c=x%10;
		inv=inv*10+c;
		x/=10;
	}
	if(aux==inv)
		return 1;
	return 0;
}

void Push(STIVA *st, int x)
{
	if(st->top==MAX_VALUE-1)
		printf("\nStiva este plina!");
	else
		st->data[++st->top]=x;
}

void Pop(STIVA *st)
{
	if(st->top==-1)
		printf("Stiva e goala!\n");
	else
		--st->top;
}

void afisare(STIVA *st)
{
	if(st->top==-1)
		printf("Stiva e goala!\n");
	else
		for(int i=0;i<=st->top;i++)
			printf("%d ",st->data[i]);
}

int main()
{
	STIVA st_init,st_palindroame;
	int n,x;
	st_init.top=-1;
	st_palindroame.top=-1;
	printf("\nCate numere se citesc?\n");
	scanf("%d",&n);
	printf("\nDati numerele:");
	for(int i=0;i<n;i++)
	{
		scanf("%d",&x);
		Push(&st_init,x);
	}
	while(st_init.top!=-1)
	{
		if(palindrom(st_init.data[st_init.top])==1)
			Push(&st_palindroame,st_init.data[st_init.top]);
		Pop(&st_init);
	}
	printf("\nStiva care contine nr palindroame este:");
	afisare(&st_palindroame);
	return 0;
}