#include <stdio.h>

int main()
{
	int length = 20;
	char tab[length];
	
	for (int i=0; i <  length;  i++)
	{
		printf("char %d: ",i+1);
		scanf(" %c",&yutab[i]);
		printf("\n");
	}
	
	printf("%c",tab[0]);
	
	for(int j=1;j<length;j++)
	{
		printf(", %c",tab[j]);
	}
	
return 0;
}
