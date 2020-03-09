#include <stdio.h>
#include <stdlib.h>

#define tip char
tip *vPtr, *vPtr2;

int main()
{
	vPtr=(tip *) malloc(sizeof(tip));
	vPtr2=(tip *) malloc(sizeof(tip));

	printf("%p\n",vPtr);
	printf("%p\n",vPtr2);
	printf("%p\n",vPtr2+1);

	printf("%d\n",(vPtr2-vPtr));
	return 0;
}