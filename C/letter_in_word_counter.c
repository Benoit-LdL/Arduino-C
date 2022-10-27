#include <stdio.h>


int Letter_counter(char word[],char* letter)
{
	int word_size = sizeof(word) / sizeof(char);
	int letter_counter=0;
	
	for (int i=0;i<=word_size;i++)
		if (word[i] == *letter) {letter_counter++;}
	
	return letter_counter;
}

int main()
{
	char word[15];
	char letter;
	
	printf("Donne le mot: ");
	scanf(" %s",word);
	
	printf("\nDonne la lettre: ");
	scanf(" %c",&letter);
	
	printf("\nLa lettre '%c' revient %d fois dans le mot '%s'.", letter, Letter_counter(word,&letter), word);
	
	return  0;
}
