#include <stdio.h>

int main()
{
	int height = 5;
	printf("what size of pyramid do you want? \n \n");
	scanf("%d",&height);
	for (int i = 1; i <= height;  i++)
	{
		for (int k = 0; k < (height - i); k++)
			printf(" ");
		
		if (height % 2 == 0)
		{
			for (int j = 1; j <= i*2;  j++)
				printf("#");
		}
		
		else
		{
			for (int j = 1; j <= (i*2)-1;  j++)
				printf("#");
		}
		
		printf("\n");
	}
	return 0;
}
