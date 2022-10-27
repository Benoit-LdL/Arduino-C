#include <stdio.h>


void rebours(int a)
{
	//action
	printf("%d\n",a);

	// condition d'arret
	if (a == 0) {return;}
		
	// condition recursive
	rebours(a-1);
}

int main()
{
	while (1)
		rebours(99999);
	return 0;
}
