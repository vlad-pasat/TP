#include<stdio.h>
#include<stdlib.h>
/*
Sa se scrie un program care calculeaza suma elementelor unui
vector folosindu-ne doar de variabile de tip pointer.
*/

int main()
{
	FILE *f;
	f=fopen("problema1.txt","r");
	if(f==NULL)
	{
		printf("Nu s-a putut deschide fisierul.\n");
		exit(0);
	}
	int v[100],n,i,*s;
	fscanf(f,"%d",&n);
	for(i=0;i<n;i++)
		fscanf(f,"%d",&v[i]);
	s=&v;
	for(i=1;i<n;i++)
		*s+=v[i];
	printf("\nSuma elementelor este %d\n",*s);
	return 0;
}
