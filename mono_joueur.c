//mono_joueur.c Gary
#include <stdio.h>
#include <stdlib.h>

#define NB_COUPS 12
#define NB_COULEURS 8
#define NB_PIONS 4

#include "dictionnaire.h"

/*Mode Basique : 
- ordi choisit une combi
- nombre de coups à fixer*/

void mono_joueur(void)
{
  // lit la combinaison dictionnaire : stocké dans la variable tableau "solution" via read/fopen?

  
  int nb_coups = NB_COUPS;
  while(nb_coups > 0)
    {
  // le joueur propose une combinaison variable tableau "proposition" via scanf/gets/fgets?
  
 
  // comparaison avec "solution" terme à terme et notion de rang
      for(int i = 0; i < NB_PIONS; i++)
	{
	  int bien_placés = 0;
	  int mal_placés = 0;
	  for(int j = 0; j < NB_PIONS; j++)
	    {
	      // si un élément de proposition et de solution sont communs ET bien placé: incrémente le compteur "bien_placés"
	      if(proposition[i] == solution[i]) 
		{
		  bien_placés++;
		}
	      // si un élement de proposition et de solution sont communs MAIS mal placé: incrémente le compteur "mal_placés"
	      if(j!=i)  
		{
		  if(proposition[i] == solution [j])
		    {
		      mal_placés++;
		    }
		}//if j!=i
	    }// for j
	}//for i
      
      // si "bien_placés == NB_PIONS" affiche "Gagné!"
      if(bien_placés == NB_PIONS) 
	{
	  printf("Gagné!");
	  nb_coups = -1;
	}
      // affiche les compteurs "bien_placés" et "mal_placés"
      printf("bien placés: %d  mal placés: %d", bien_placés, mal_placés);
      // décrémente la variable "nb_coups = NB_COUPS"
      nb_coups -= 1;
      // si "nb_coups == 0" affiche "Perdu!"
      if(nb_coups == 0)
	{ 
	  printf("Perdu!");
	}
    }//while
}//END


sol 1 2 3 4
pro 3 1 2 4
