/*
 * Il y a 8 exercices dans ce fichier. Les exercices doivent tous être fait pour avoir la note maximale.
 * Il n'est pas nécessaire de les faire dans l'ordre puisque tous les exercices sont indépendants.
 * Lorsque vous travaillez sur un exercice, vous devez sélectionner l'exercice grâce à la variable EXERCICE
 * définie juste après ce commentaire.
 *
 * Voici les différents exercices disponibles :
 *
 * - EXERCICE 1 : utilisation de printf et scanf
 * - EXERCICE 2 : appel de fonction
 * - EXERCICE 3 : tableau
 * - EXERCICE 4 : structure
 * - EXERCICE 5 : pointeur
 * - EXERCICE 6 : tableau de structure
 * - EXERCICE 7 : algorithme de tri
 * - EXERCICE 8 : multi-fonction
 *
 * Bonne chance !
 * */

#define EXERCICE 7   // Sélectionnez un exercice

#include <stdio.h>   // Printf et scanf
#include <stdlib.h>  // Allocation de memoire
#include <math.h>    // Mathématique


/* Dans ce premier exercice, vous devez créer un programme qui va calculer la surface d'un carre. Imaginons que la
 * longueur des côtés sont notées "a", vous devez calculer l'aire de ce carree.
 *
 * Comportement : vous devez entrer la longueur "a" au clavier puis afficher le résultat à l'écran.
 *
 * Contrainte : vous devez utiliser des "float" en tant que format de nombre. L'affichage et la saisie clavier se font grâce à %f.
 */

#if EXERCICE == 1

int main()
{
    printf("Exercice 1\n");
    float a,b;

    printf("\nDonnez la taille du cote A:");
    scanf(" %f",&a);
    
    printf("\nDonnez la taille du cote B:");
    scanf(" %f",&b);

    printf("\nl'aire du rectanghle est: %.2f",a*b);

}
#endif


/* Dans ce second exercice, vous devez créer une fonction. Cette fonction va devoir retourner le périmètre d'un
 * cercle dont le rayon est passé en paramètre. Par exemple, pour un rayon de 3, la fonction va me retourner 18.85.
 *
 * Comportement : vous devez entrer un nombre au clavier puis afficher le périmètre du cercle.
 *
 * Contrainte 1 : la saisie au clavier et l'affichage du résultat doit se faire dans le "main".
 * Contrainte 2 : vous devez écrire une fonction qui calcule le périmètre d'un cercle.
 * Contrainte 3 : vous devez passer le rayon en paramètre d'entrée.
 * Contrainte 4 : la fonction doit retourner le résultat.
 */

// formule de perimetre?

#if EXERCICE == 2



float Perim(float input)
{
    float pi = 2.14;
    return 2 * pi * input;
}

int main()
{
	printf("Exercice 2\n");
    float input;
    printf("\ndonnez le rayon: ");
    scanf(" %f",&input);

    printf("\n\nPerim de cercle: %f",Perim(input));

}
#endif


/* Dans ce troisième exercice, vous devez réaliser un compte à rebours grâce à un tableau. Vous allez créer un tableau de 5 cases.
 * La case 0 du tableau doit étre égale à 0, la case 1 du tableau doit être égale à 1 ...
 *
 * Comportement : vous devez générer automatiquement ce tableau puis l'afficher.
 *
 * Contrainte 1 : vous devez utiliser un tableau de 5 cases.
 * Contrainte 2 : vous devez parcourir le tableau avec une boucle for.
 */


#if EXERCICE == 3

int main()
{
	printf("Exercice 3\n");
    int tab[5];
    
    for (int i = 0; i<5; i++)
        tab[i] = i+1;

    for (int j = 0; j<5;j++)
        printf("\n valeur de tab[%d]: %d",j,tab[j]);


}
#endif


/* Dans ce quatrième programme, vous devez réaliser la fiche d'une voiture. Chaque fiche doit renseigner
 * la marque (peugeot, citroën, ford, honda ...), le modèle (208, ibiza, clio, civic ...) et la pollution.
 *
 * Comportement : vous devez entrer au clavier les différents champs de la fiche puis les afficher. Si la pollution de la voiture
 * est supérieure à 100, le message "malus écologique" doit s'écrire en bas de la fiche.
 *
 * Contrainte : vous devez créer une structure "Fiche" qui va intégrer les 3 champs demandés (marque, modèle, pollution).
 */

#if EXERCICE == 4

struct Fiche
    {
        char marque[20];
        char modele[20];
        int polution;
    };

int main()
{
	printf("Exercice 4\n");
    struct Fiche fiches[2];

    for (int i=0;i<2;i++)
    {
        printf("\n\n___remplir fiche n%d___",i+1);

        printf("\n marque: ");
        scanf("%s",fiches[i].marque);

        printf("\n modele: ");
        scanf("%s",fiches[i].modele);

        printf("\n polution: ");
        scanf("%d",&fiches[i].polution);
    }

    for (int j=0;j<2;j++)
    {
        printf("\n\n___afficher fiche n%d___",j+1);
        printf("\n marque: %s",fiches[j].marque);

        printf("\n modele: %s",fiches[j].modele);

        printf("\n polution: %d",fiches[j].polution);
        if (fiches[j].polution > 100)
            printf(" : malus écologique\n");
    }

}
#endif


/* Dans ce cinquième exercice, vous allez compter le nombre de fois que la lettre "e" apparaît dans un mot. Par exemple,
 * pour le mot "enveloppe", le programme doit dire qu'il y a 3 "e".
 *
 * Comportement : vous devez entrer au clavier le mot à analyser. Une fois fini, vous devez afficher le nombre de lettre "e".
 *
 * Contrainte 1 : vous devez créer une fonction qui prend en entrée une chaine de caractère DEJA REMPLIE. Cette fonction
 * doit alors compter le nombre de "e" dans cette chaine de caractère.
 * Contrainte 2 : l'affichage du résultat doit se faire dans la fonction mais dans le main.
 * Contrainte 3 : la fonction doit retourner le nombre de "e" présent dans le mot.
 *
 * Remarque : le caractère de fin de mot est égale à 0.
 */

#if EXERCICE == 5

int ex5(char phrase[])
{
    char ** temp = &phrase;

    int out = 0;

    while (**temp != '0')
    {
        if (**temp == 'e' || **temp == 'E')
            out++;
        *temp += 1;
    }
    return out;
}

int main()
{
	printf("Exercice 5\n");
    char phrase[] = "Hallo ik ben aan het drinken maar bob niet.0";
    printf("Phrase selectionée: %s\n",phrase);
    printf("Nombre de 'e' ou 'E' dans la pharse: %d\n",ex5(phrase));
}
#endif


/* Dans ce sixième exercice, vous allez calculer le chiffre d'affaire réalisé par une société d'autoroute qui vend des sandwichs
 * et des boissons. Chaque client arrivant dans la boutique achète un ou plusieurs sandwichs et une ou plusieurs boissons.
 * Les boissons coutent 2 euros tandis que les sandwichs coutent 5 euros. Chaque client peut ainsi être représenté par une structure
 * contenant le nombre de sandwich et le nombre de boissons achetés.
 * Remarque : Le nombre de client est libre, c'est à vous de choisir.
 *
 * Comportement : vous devez entrer au clavier les achats (nombre de sandwich et nombre de boisson) de chaque client. Puis, vous
 * devez afficher le chiffre d'affaire réalisé par la société.
 *
 * Contrainte 1 : chaque client doit être défini par une structure avec à l'intérieure, le nombre de sandwich et le nombre de boisson.
 * Contrainte 2 : les clients sont tous regroupés dans un tableau. Il faut utiliser un tableau de clients donc !
 * Contrainte 3 : vous devez utiliser la boucle for pour parcourrir le tableau de clients.
 */

#if EXERCICE == 6

struct Client
    {
        int boissons;
        int sandwichs;
    };

int main()
{
	printf("Exercice 6\n");

    int nombre_clients = 2;
    int price_drink = 2;
    int price_food = 5;
    int total = 0;
    struct Client clients[nombre_clients];

    for (int i = 0;i<nombre_clients;i++)
    {
        printf("\n\n -- client n%d --\n",i+1);
        
        printf("# boissons: ");
        scanf(" %d",&clients[i].boissons);

        printf("\n# sandwichs: ");
        scanf(" %d",&clients[i].sandwichs);
    }

    for (int j=0;j<nombre_clients;j++)
        total += (clients[j].boissons * price_drink) + (clients[j].sandwichs * price_food);

    printf("\n--> Chiffre d'affaire total: %d\n",total);
    
}
#endif


/* Dans ce septième exercice, vous devez entrez un mot et recenser l'ensemble de ces lettres. Par exemple, pour le mot "banane",
 * vous devez dire qu'il contient une lettre "b", deux lettres "a", deux lettres "n" et une lettre "e".
 *
 * Comportement : vous devez saisir au clavier le mot à analyser. L'analyse doit se faire dans une fonction. Vous devez ensuite trier les
 * lettres en fonction de leur nombre d'apparition. Enfin, vous devez afficher le résultat de l'analyse.
 *
 * Contrainte 1 : vous devez utiliser les pointeurs
 * Contrainte 2 : vous devez trier les lettres en fonction de leurs nombres d'occurence. Les lettres qui apparaissent le plus souvent
 * doivent se trouver dans les premières cases du tableau tandis que les lettres qui apparaîssent le moins souvent doivent se trouver
 * à la fin du tableau
 * Contrainte 3 : le tri du tableau doit se faire dans une fonction qui n'est pas la même fonction que la fonction qui permet d'analyser les lettres.
 */

#if EXERCICE == 7

// WORK IN PROGRESS

void Analyse(char mot[])
{
    char ** temp = &mot;
    char alphabet[] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    char alphabetCount[25] = {0};
    while (**temp != '0')
    {
        printf("\n %c",**temp);
        for (int i=0;i<25;i++)
        {
            if (**temp == alphabet[i])
            {
                //printf("\nfound %c\n",alphabet[i]);
                alphabetCount[i] += 1;
            }

            
        }
        *temp += 1;
    }
}

int main()
{
	printf("Exercice 7\n");
    char mot[20];
    printf("\n\n Donnez un mot terminant par 0: ");
    scanf(" %s",mot);
    Analyse(mot);

}
#endif


/* Dans ce huitième exercice, vous devez réaliser une fonction qui permet de calculer les solutions d'une équation du second degré. Une équation
 * du second degré est de la forme ax^2 + bx + c = 0.
 * 
 * Comportement : vous devez entrer au clavier les coefficient "a", "b" et "c". Vous cherchez ensuite les solutions de l'équation. En fonction
 * du nombre de solution (0, 1 ou 2), vous devez afficher le resultat sous une forme différente.
 * 
 * Contrainte 1 : Le "scanf" doit se faire dans une fonction appelée "saisie_clavier".
 * Contrainte 2 : Le calcul des solutions doit se faire dans une fonction appelée "calcul_solution".
 * Contrainte 3 : L'affichage doit se faire dans une fonction appelée "affichage".
 * Contrainte 4 : Vous devez utiliser des pointeurs pour échanger entre les différentes fonctions.
 */
 
 #if EXERCICE == 8
 
 int main()
{
	printf("Exercice 7\n");
    
}
#endif