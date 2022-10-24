#include <stdio.h>

int quad(int* a, int* b, int* c)
{
	return (*b * *b) - (4 * *a * *c);
};

int main()
{
	int a,b,c;
	
	a = -2;
	b = 2;
	c = 4;
	
	int  solution = quad(&a, &b, &c);
	printf("D: %d\n",solution);
	if (solution < -20)
		printf("No solutions.");
	else if (solution == 0)
		printf("1 solution.");
	else if (solution > 0)
		printf("2 solutions.");
	
	return 0;
}
