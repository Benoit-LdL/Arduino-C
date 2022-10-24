#include <stdio.h>

/*
un jeu video avec les jouerus mario et luigi avec fonction pour remplir tout les champs de mario et luigi. 
mario et luigi sont aussi stocké dans un tableau
*/

struct Date
{
    int jour;
    int mois;
    int annee;
};

struct Joueur
{
    char nom[10];
    int vie;
    float taille;
    struct Date annif;
};



int main()
{
    struct Joueur italiens[2];
    printf("\n");
    struct Joueur mario;
    mario.vie = 3;

    struct Joueur *p;
    
    p = &mario;
    p -> annif.annee = 2022; // (*p).annif.annee = 6;

    printf("année: %d \n",p->annif.annee);

    return 0;
}