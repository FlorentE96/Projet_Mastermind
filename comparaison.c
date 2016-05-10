#include <stdio.h>
#include <stdlib.h>
#define NB_PIONS 4
#define NB_COULEURS 8
#define MAX_COUPS 20


struct Joueur
{ char *nom;
  int nb_pts;
  int nb_coups;
  int combi_a_trouver[NB_PIONS];
  int combinaisons_passees[MAX_COUPS][NB_PIONS];
  int resultats_passes[MAX_COUPS][2];
};


void comparaison(struct Joueur joueur, int proposition[])
{
  int solution[] = {0,0,0,0};
  for(int g = 0; g< NB_PIONS; g++)
    { 
      solution[g] = joueur.combi_a_trouver[g];
    }
  for(int h = 0; h< NB_PIONS; h++)
    {
      joueur.combinaisons_passees[joueur.nb_coups][h] = proposition[h]; 
    }
  
  //les compteurs
  int bien_places = 0;
  int mal_places = 0;

  //comparaison terme à terme bien places
  for(int i = 0; i< NB_PIONS; i++)
  {
    if(proposition[i] == solution [i])
      {
	printf("bien placé %d \n", proposition[i]);
	bien_places ++;
	proposition[i] = -1;
	solution[i] = -1;	
      }
  }
  
  //comparaison double boucle mal_places
  for(int j = 0; j< NB_PIONS; j++) //boucle de proposition
    {
      for( int k = 0; k < NB_PIONS; k++) //boucle de solution
	{
	  if(j != k) //pas terme à terme, déjà fait avec bien_places
	    {
	      if( proposition[j] > 0 ) //on ne compare pas les -1 = déjà trouvé
		{
		  if(proposition[j] == solution[k]) 
		    {
		      printf("mal_places %d\n", proposition[j]);
		      mal_places ++;
		      proposition[j] = -1;
		      solution[k] = -1;
		    }
		}
	    }
	}
    }

  joueur.resultats_passes[joueur.nb_coups][0] = bien_places;
  joueur.resultats_passes[joueur.nb_coups][1] = mal_places;
  joueur.nb_coups += 1;

}//end



int main()
{ 
  struct Joueur joueur;
  joueur.nom = "Flo";
  joueur.nb_pts = 0;
  joueur.nb_coups = 0;
  joueur.combi_a_trouver[0] = 1;
  joueur.combi_a_trouver[1] = 2;
  joueur.combi_a_trouver[2] = 3;
  joueur.combi_a_trouver[3] = 4;
  // joueur.combinaisons_passes = { {1,2,3,4}, {2,3,4,1} }
  joueur.resultats_passes = {{1,2},{2,3}};
  int proposition[] = {1,2,4,3};

  comparaison( joueur, proposition);
 
  printf("nombre de coups = %d   bien places %d mal places %d\n", joueur.nb_coups, joueur.resultats_passes[0][0], joueur.resultats_passes[0][1]);
  return 0;
}










/* LA FONCTION DE TEST : MARCHE

 void comparaison(int proposition[], int solution[])
{
  //int solution = joueur.combi_a_trouver;
  //lire la proposition 
  //int proposition;

  //les compteurs
  int bien_places = 0;
  int mal_places = 0;

  //comparaison terme à terme bien places
  for(int i = 0; i< NB_PIONS; i++)
  {
    if(proposition[i] == solution [i])
      {
	printf("bien placé %d \n", proposition[i]);
	bien_places ++;
	proposition[i] = -1;
	solution[i] = -1;	
      }
  }
  
  //comparaison double boucle mal_places
  for(int j = 0; j< NB_PIONS; j++) //boucle de proposition
    {
      for( int k = 0; k < NB_PIONS; k++) //boucle de solution
	{
	  if(j != k) //pas terme à terme, déjà fait avec bien_places
	    {
	      if( proposition[j] > 0 ) //on ne compare pas les -1 = déjà trouvés
		{
		  if(proposition[j] == solution[k]) 
		    {
		      printf("mal_places %d\n", proposition[j]);
		      mal_places ++;
		      proposition[j] = -1;
		      solution[k] = -1;
		    }
		}
	    }
	}
    }

  printf("bien_places = %d   mal_places = %d\n", bien_places, mal_places);

}//end

int main()
{
  int proposition[] = {1,2,3,3};
  int solution[] = {4,3,2,1};
  comparaison(proposition, solution);
  return 0;
}

*/

