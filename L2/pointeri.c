#include<stdio.h>
#include<stdlib.h>

void Swap1(int p, int q)
{
	int k;
	k=p; p=q; q=k;
}

void Swap2(int *p, int *q)
{
	int k;
	k=*p; *p=*q; *q=k; 
}

void XORSWAP(int *p, int *q)
{
	if(p!=q)
	{
		*p ^=*q;
		*q ^=*p;
		*p ^=*q;
	}
}

int main()
{
	int a=2,b=5,x=2,y=5;
	Swap1(a,b); printf("Swap1 -> %d %d\n",a,b);
	Swap2(&a,&b); printf("Swap3 -> %d %d\n",a, b);

	XORSWAP(&x,&y); printf("XORSWAP -> %d %d\n",x,y);
	return 0;
}