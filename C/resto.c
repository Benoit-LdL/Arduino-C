#include <stdio.h>
/*
 * 
 * scanf("%[^\n]s", var); // scanf until \n so great for reading full sentence with spaces
 * 
 * */


struct Menu
{
	char entree[10];
	char plat[10];
	char dessert[10];
};

struct Choix_client
{
	int menu;
};

void Display(struct  Menu menus[], int menu_id)
{
	printf("Menu %d\n",menu_id+1);
	printf("Entree: 	%s\n",menus[menu_id].entree);
	printf("Plat:		%s\n",menus[menu_id].plat);
	printf("Dessert:	%s\n",menus[menu_id].dessert);
}

int main()
{
	int menu_amount 	= 3;
	int client_amount 	= 3;
	
	struct Menu menus[menu_amount];
	struct Choix_client clients[client_amount];
	printf("\n__Système Menu__\n");
	
	for (int i=0;i<menu_amount;i++)
	{
		printf("Inserez menu #%d (entree plat dessert): ",i+1);
		scanf("%s",menus[i].entree);
		scanf("%s",menus[i].plat);
		scanf("%s",menus[i].dessert);
	}
	
	printf("\n\n__Système Client__\n");
	printf("Voici les different menus:\n");
	
	for (int j=0;j<menu_amount;j++)
	{
		printf("===============================\n");
		Display(menus,j);
	}
	
	for (int k=0;k<client_amount;k++)
	{
		printf("================================================\n");
		printf("Client %d, choisissez votre menu (1, 2 ou 3): ",k+1);
		scanf("%d",&clients[k].menu);
		clients[k].menu--;
		printf("Vous avez choisi ");
		Display(menus,clients[k].menu);
	}
	
	return 0;
}
