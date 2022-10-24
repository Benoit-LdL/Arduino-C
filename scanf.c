#include <stdio.h>

int main() {
	int a,b,c;
	
	printf("Donne la valeur de A:");
	scanf(" %d", &a); // space used to fix multi inputbuffer data
	
	printf("Ensuite donne la valeur de B:");
	scanf(" %d", &b);
	
	c = a * b;
	
	printf("Le resultat est: %d",c);
	
	return 0;
	}
