#include<stdio.h>
#include<stdlib.h>

int main()
{
	int n,v[100],i,x;
	FILE *f;
	f=fopen("cautare_liniara.txt","r");
	if(f==NULL)
	{
		printf("\nEroare!\n");
		exit(0);
	}
	printf("\n---------CAUTARE LININARA---------\n");
	printf("\n");
	fscanf(f,"%d",&n);
	printf("n=%d\n",n);

	for(i=0;i<n;i++)
		fscanf(f,"%d",&v[i]);

	printf("v[n]=\n");
	for(i=0;i<n;i++)
		printf("%d ",v[i]);

	printf("\nDati numarul cautat: ");
	printf("\n>>>");
	scanf("%d",&x);

	i=0;
	while(i<n && x!=v[i])
		i++;
	if(x==v[i])
		printf("\nNumarul a fost gasit! El este pe pozitia %d!\n",i+1);
	else printf("\nNumarul nu a fost gasit!\n");
	fclose(f);
	printf("\n---------CAUTARE LINIARA---------\n");
	return 0;
}