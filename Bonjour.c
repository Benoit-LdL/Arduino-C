#include <stdio.h>
#include <stdlib.h>
#include <time.h>
struct date
{
	int jour;
	int mois;
	int annee;
};
struct id
{
	int age;
	char genre;
	char statut;
	struct date Anniversaire;
	struct date Mort;
};

struct joueur
{
	int sante;
	int force;
};

int main()
{
	struct joueur Poutine;
	struct joueur Elisabeth;
	Poutine.sante = 100;
	Elisabeth.sante = 100;

	
	while ((Poutine.sante >= 0)&&(Elisabeth.sante >= 0))
	{
		srand(time(0));
		Poutine.force = rand()%10;
		Elisabeth.force = rand()%10;
		printf("Poutine mets un coup de latte à Elisabeth II !\nElisabeth II perd %d point de vie.\n",Poutine.force);
		Elisabeth.sante -= Poutine.force;
		if (Elisabeth.sante <= 0)
		printf("Elisabeth est décédé... Encore une fois...\n");
		else
		{
			printf("Il reste %d de point de vie à Elisabeth\n",Elisabeth.sante);
			printf("Elisabeth II mets un coup de tatane à Poutine !\nPoutine perd %d point de vie.\n",Elisabeth.force);
			Poutine.sante -= Elisabeth.force;
		} 
		if (Poutine.sante <= 0)
		printf("Poutine a canner, l'Ukraine est sauvé!\n");
		else
		printf("Il reste %d point de vie à tonton Poutine",Poutine.sante);
		
		printf("\n\n");
	}
}
