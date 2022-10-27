#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#define EXERCICE 1


void ex1()
{
    float a,b;

    printf("\nDonnez la taille du cote A:");
    scanf(" %f",&a);
    
    printf("\nDonnez la taille du cote B:");
    scanf(" %f",&b);

    printf("\nl'aire du rectanghle est: %.2f",a*b);
}

float ex2(float in)
{
    return in*3;
}

void ex3()
{
    int size = 5;
    int tab[size];

    for (int i=0;i<size;i++)
    {
        printf("\nDonnez num %d: ",i+1);
        scanf(" %d",&tab[i]);
    }

    int max_val = tab[0];
    for (int j=1;j<size;j++)
    {
        if (max_val < tab[j])
            max_val = tab[j];
    }

    printf("The biggest value is: %d",max_val);
}

void ex4()
{
    struct Programme 
    {
        char plat_pricipal[20];
        char accompagnement[20];
        int calories;
    };

    int nombre_fiches = 3;
    struct Programme fiches[nombre_fiches];

    for (int i=0;i<nombre_fiches;i++)
    {
        printf("\nNom du plat principal: ");
        scanf(" %s",fiches[i].plat_pricipal);

        printf("\nNom de l'accompagnement: ");
        scanf(" %s",fiches[i].accompagnement);

        printf("Nombvre de calories: ");
        scanf(" %d", &fiches[i].calories);
    }
    
    for (int j=0;j<nombre_fiches;j++)
    {
        printf("\n\n___FICHE %d___\n",j);
        printf("Plat principal: %s\n",fiches[j].plat_pricipal);
        printf("Accompagnement: %s\n",fiches[j].accompagnement);
        if (fiches[j].calories < 300)
            printf("-- Menu dietetique --\n"); 
    }



}

int ex5(char phrase[])
{
    char ** temp = &phrase;

    int out = 0;

    while (**temp != '0')
    {
        if (**temp == 'a' || **temp == 'A')
            out++;
        *temp += 1;
    }
    return out;
}

void ex6()
{
    struct Client
    {
        int boissons;
        int sandwichs;
    };

    int nombre_clients = 2;
    int price_drink = 1;
    int price_food = 4;
    int total = 0;
    struct Client clients[nombre_clients];

    for (int i = 0;i<nombre_clients;i++)
    {
        printf("\n\n -- client n%d --\n",i);
        
        printf("# boissons: ");
        scanf(" %d",&clients[i].boissons);

        printf("\n# sandwichs: ");
        scanf(" %d",&clients[i].sandwichs);
    }

    for (int j=0;j<nombre_clients;j++)
        total += (clients[j].boissons * price_drink) + (clients[j].sandwichs * price_food);

    printf("\n--> Chiffre d'affaire total: %d\n",total);

}

void ex7()
{
    
}



int main()
{
    // ex1();

    // ex2
    // printf("\ngive number:");
    // float temp;
    // scanf(" %f",&temp);
    // printf("\nValeur x3: %.2f",ex2(temp));
    // return 0;

    // ex3();
    // ex4();

    // ex5
    // char phrase[] = "Hallo ik ben aan het drinken maar bob niet.0";
    // printf("Nombre de 'A' dans la pharse: %d",ex5(phrase));

    ex6();

    // ex7();
}