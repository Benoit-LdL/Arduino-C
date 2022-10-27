#include <stdio.h>
#include <string.h>


/*
un jeu video avec les jouerus mario et luigi avec fonction pour remplir tout les champs de mario et luigi. 
mario et luigi sont aussi stocké dans un tableau
*/

struct Date
{
    int day;
    int month;
    int year;
};

struct Player
{
    char name[10];
    int lifes;
    float height;
    struct Date birthday;
};

void Fill_data(struct Player * in)
{
    printf("\nGive the name of player:");
    scanf("%s",in->name);

    printf("\nGive the # of lifes:");
    scanf("%d",&in->lifes);

    printf("\nGive the height:");
    scanf("%d",&in->height);

    printf("\nGive the birthdate (dd mm yyyy)");

    scanf("%d",&in->birthday.day);
    scanf("%d",&in->birthday.month);
    scanf("%d",&in->birthday.year);
}

void Show_Data(struct Player * in)
{
    printf("______________________________\n");
    printf("Showing data from %s\n",in->name);
    printf("------------------------------\n");
    printf("lifes: %d \n",          in->lifes);
    printf("Height: %d \n",         in->height);
    printf("Birthdate: %d/%d/%d \n",in->birthday.day,in->birthday.month,in->birthday.year);
}


int main()
{
    int player_count = 2;
    struct Player players[player_count];

    for (int i = 0; i< player_count; i++)
        Fill_data(&players[i]);

    for (int j=0;j<player_count;j++)
        Show_Data(&players[j]);





    return 0;
}