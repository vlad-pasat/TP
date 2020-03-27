#include<stdio.h>
#include<stdlib.h>
/*
Sa se scrie un program care calculeaza suma elementelor unui
vector folosindu-ne doar de variabile de tip pointer.
*/

int main()
{
	int v[10],n,i,*s,*ptr;
	s=(int*)malloc(sizeof(int));
	*s=0;

	printf("\nDati marimea vectorului: ");
	scanf("%d",&n);

	printf("\nDati vectorul:\n");
	for(i=0;i<n;i++)
		scanf("%d",&v[i]);

	ptr=v;

	for(i=0;i<n;i++)
	{
		*s+=*ptr;
		ptr++;
	}

	printf("\nSuma elemenetlor este: %d\n",*s);
	return 0;
} 