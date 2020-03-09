#include<stdio.h>
#include<stdlib.h>

int main()
{
	int x=0,k;

	printf("\nEste permisa citirea? 0-nu 1-da "); scanf("%d",&k);
	if(k==1)
		x=x|(1<<0);
	printf("\nEste permisa scrierea? 0-nu 1-da "); scanf("%d",&k);
	if(k==1)
		x=x|(1<<1);
	printf("\nEste permisa stergerea? 0-nu 1-da "); scanf("%d",&k);
	if(k==1)
		x=x|(1<<2);
	printf("\nEste permisa redenumirea? 0-nu 1-da "); scanf("%d",&k);
	if(k==1)
		x=x|(1<<3);
	printf("\nEste permisa copierea? 0-nu 1-da "); scanf("%d",&k);
	if(k==1)
		x=x|(1<<4);
	if(1==1&(x>>0))
		printf("\nCitirea este permisa");
	if(1==1&(x>>1))
		printf("\nScrierea este permisa");
	if(1==1&(x>>2))
		printf("\nStergerea este permisa");
	if(1==1&(x>>3))
		printf("\nRedenumirea este permisa");
	if(1==1&(x>>4))
		printf("\nCopierea este permisa");
	return 0;
}