#include <stdio.h>


void Change_letters(char* word, int word_length, char old_letter, char new_letter)
{
    char ** temp = &word;
    for (int i=0; i<word_length; i++)
    {
        if (**temp == old_letter)
            **temp = new_letter;
        *temp += 1;
    }
}

int main()
{
    char word[] = "Mississipi";

    printf("%s \n",word);
    Change_letters(word,sizeof(word), 'i', 'e');
    printf("%s \n",word);

    Change_letters(word,sizeof(word), 's', 'p');
    printf("%s \n",word);

    Change_letters(word,sizeof(word), 'e', 'a');
    printf("%s \n",word);

}