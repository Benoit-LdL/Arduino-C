#include <stdio.h>
struct menu
{
	char entree[8];
	char plat [8];
	char dessert [8];
	char boisson [8];
};

void affichage_menu (int plat);
void initialisation_menu (void);

struct menu menu_du_jour [3];

int main()
{	
	int nb_table = 3;
	char reponse;
	struct menu Client [nb_table];
	initialisation_menu();
	
	for(int i = 0 ; i < nb_table ; i++)
	{
		affichage_menu(0);
		printf("\nQue désirez vous en entrée ?\n");
		scanf(" %s", Client[i].entree);
		affichage_menu(1);
		printf("\nQue désirez vous en plat de resistance ?\n");
		scanf(" %s", Client[i].plat);
		affichage_menu(2);
		printf("\nQue désirez vous en dessert ?\n");
		scanf(" %s", Client[i].dessert);
		printf("\nDes boissons ?\n");
		scanf(" %c",&reponse);
		if(reponse == 'o')
		{
			affichage_menu(3);
			printf("\nQue désirez vous boire ?\n");
			scanf(" %s", Client[i].boisson);
		}
		else
		{
			Client[i].boisson[0] = '0';
		}
	}
	printf("Robot 1 prépare les entrees : \n");
	for(int j = 0 ; j < nb_table ; j++)
	{
		printf("	%s\n",Client[j].entree);
	}
	printf("Robot 2 prépare les plats : \n");
	for(int j = 0 ; j < nb_table ; j++)
	{
		printf("	%s\n",Client[j].plat);
	}
	printf("Robot 3 prépare les dessert : \n");
	for(int j = 0 ; j < nb_table ; j++)
	{
		printf("	%s\n",Client[j].dessert);
	}
	
	for(int j = 0 ; j < nb_table ; j++)
	{
		if (Client[j].boisson[0] != '0')
		printf("Je vais servir un %s a la table %d.",Client[j].boisson,j+1);
	}

}

void affichage_menu (int plat)
{
	switch (plat)
	{
		case (0):
			printf("Entrees possibles : \n");
			for(int j = 0 ; j < 3 ; j++)
				printf("%s\n",menu_du_jour[j].entree);
		break;
		case (1):
			printf("Plats possibles : \n");
			for(int j = 0 ; j < 3 ; j++)
				printf("%s\n",menu_du_jour[j].plat);
		break;
		case (2):
			printf("Desserts possibles : \n");
			for(int j = 0 ; j < 3 ; j++)
				printf("%s\n",menu_du_jour[j].dessert);
		break;
		case (3):
			printf("Boissons possibles : \n");
			for(int j = 0 ; j < 3 ; j++)
				printf("%s\n",menu_du_jour[j].boisson);
		break;
	}
}

void initialisation_menu (void)
{
	printf("Entrez les entrees possibles.\n");
	for (int k = 0 ; k < 3 ; k++)
		scanf(" %s",menu_du_jour[k].entree);
		
	printf("Entrez les plats possibles.\n");
	for (int k = 0 ; k < 3 ; k++)
		scanf(" %s",menu_du_jour[k].plat);
		
	printf("Entrez les desserts possibles.\n");
	for (int k = 0 ; k < 3 ; k++)
		scanf(" %s",menu_du_jour[k].dessert);
		
	printf("Entrez les boissons possibles.\n");
	for (int k = 0 ; k < 3 ; k++)
		scanf(" %s",menu_du_jour[k].boisson);
		
}
