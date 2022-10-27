
#include <stdio.h>

struct Date
{
	int jour,mois,annee;
};

struct Identite
{
	char prenom[15];
	char nom[30];
	int age;
	struct Date naissance;

};

int main()
{
	int lenght = 3;
	struct Identite personnes[lenght];
	
	
	for(int i=0; i < lenght;  i++)
	{
		printf("\n___Personne  #%d___\n",i+1);
		
		printf("Donnez le prénom suivi du nom avec un espace: ");
		scanf(" %s",personnes[i].prenom);
		scanf(" %s",personnes[i].nom);
		
		printf("\nDonnez l'age de %s: ",personnes[i].prenom);
		scanf(" %d",&personnes[i].age);
		
		printf("Pour finir donnez la date de naissance (jj mm aaaa): ");
		scanf(" %d",&personnes[i].naissance.jour);
		scanf(" %d",&personnes[i].naissance.mois);
		scanf(" %d",&personnes[i].naissance.annee);
		
		
		printf("\nPersonne: %s %s , age: %d (%d/%d/%d)\n",personnes[i].prenom, personnes[i].nom,personnes[i].age,personnes[i].naissance.jour,personnes[i].naissance.mois,personnes[i].naissance.annee);
	}
	
	
	return 0;
}
