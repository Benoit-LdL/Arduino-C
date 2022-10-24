#include <stdio.h>

struct joueur
{
	int sante, force, vitesse,attaque;
};

int main()
{
	struct joueur a;
	struct joueur b;
	
	a.sante = 100;
	a.force = 12;
	a.vitesse = 2; //max 10
	a.attaque = 0;
	
	b.sante = 100;
	b.force = 8;
	b.vitesse = 5; //max 10
	b.attaque = 0;
	
	int timer = 0;
	
	while  (a.sante > 0 && b.sante > 0)
	{
		timer++;
		
		if (timer % (10 - a.vitesse) == 0)	// when a attacks
		{	
			b.sante =  b.sante - a.force;
			a.attaque++;
			printf("Time:%d | A attaque B: santé B = %d \n",timer,b.sante);
		}
		if (timer % (10 - b.vitesse) == 0) // when b attacks
		{
			a.sante = a.sante - b.force;
			b.attaque++;
			printf("Time:%d | B attaque A: santé A = %d \n",timer,a.sante);
		}
		
	//DEBUG
	//printf(" timer: %d || a sante: %d || b  sante: %d \n",timer, a.sante, b.sante);
	}
	
	printf("______________________________________\n");
	
	printf("A a attaqué %d fois || B a attaqué %d fois. \n",a.attaque,b.attaque);
	
	if (a.sante <= 0)
		printf("A is dead.\n");
	
	if (b.sante <= 0)
		printf("B is dead\n.");
	
	printf("______________________________________\n");
	
	return 0;
}

