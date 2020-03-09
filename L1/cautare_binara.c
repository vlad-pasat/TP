#include<stdio.h>
#include<stdlib.h>

int main()
{
	int n,v[100],i,x,li=0,lf,k,OK=0;
	FILE *f;
	f=fopen("cautare_binara.txt","r");
	if(f==NULL)
	{
		printf("\nEroare!\n");	
		exit(0);
	}
	printf("\n---------CAUTARE BINARA---------\n");
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

	lf=n-1;
	while(li<=lf)
	{
		k=(li+lf)/2;
		if(x==v[k])
		{
			printf("\nNumarul a fost gasit! El se afla pe pozitia %d!\n",k+1);
			OK=1;
			break;
		}
		else
		{
			if(x<v[k]) lf=k-1;
			else li=k+1;
		}
	}
	if(OK==0) printf("\nNumarul nu a fost gasit!\n");
	fclose(f);
	printf("\n---------CAUTARE BINARA--------\n");
	return 0;
}