#include <stdlib.h>
#include <stdout.h>
#include "fonctions.h"

int multijoueur(struct Joueur * joueurs) // retourne le numéro du joueur gagnant (joueur 0 ou joueur 1)
{
  /*
    afficher menu choix combinaison joueur 1
    afficher menu choix combinaison joueur 2

    faire:
	joueur suivant
	effacer ecran
        afficher jeu joueur
        attendre saisie
	comparer combi à trouver
	afficher jeu joueur
	attendre appui sur entrée
    tant que personne n'a gagné
    
    return joueur gagnant
  */

  printf("%s va te cacher, %s choisis ta combinaison : \n", joueurs[1]->nom, joueurs[0]->nom);
  saisie_combi(joueurs[1]->combi_a_trouver);
  CLEAR_SCREEN;
  printf("%s va te cacher, %s choisis ta combinaison : \n", joueurs[0]->nom, joueurs[1]->nom);
  saisie_combi(joueurs[0]->combi_a_trouver);
  CLEAR_SCREEN;

  printf("quand vous êtes prêts, appuyez sur entrée...");
  getc();

  int i=1; // variable correspondant au joueur. on commence à 1 parce qu'on passe à l'autre joueur au début de la boucle
  
  do{
    i = i?0:1; // passe à l'autre joueur
    CLEAR_SCREEN;
    afficher_jeu(joueurs[i]); // affichage des essais passés et des resultats passés
    saisie_combi(combi_saisie);
    res[i] = comparer(combi_saisie, joueurs[i]); // retourne 1 si le joueur a gagné
    CLEAR_SCREEN;
    afficher_jeu(joueurs[i]); // affiche le resultat de l'essai immédiat
    tempo(5); // secondes
      
  } while (!res[i] && joueurs[i]->nb_coups < NB_COUPS_MAX);
  
  if(res[0] || joueurs[1]->nb_coups >= NB_COUPS_MAX)
    return 0;
  return 1;
}

int monojoueur(struct Joueur * joueur) // retourne 1 si gagné, 0 si perdu
{
  /*
    générer combinaison
    
    faire
        afficher interface
	attendre saisie
	incrementer nb_coups
	comparer saisie à combi à trouver
	afficher resultat
    tant que pas gagné et nb_coups < nb_coups_max:
		
  */

  printf("Génération de la combinaison... ");
  combi_rand(joueur);
  printf("Combinaison générée!\n");

  printf("Quand vous êtes prêts, appuyez sur entrée.");
  getc();
  int combi_saisie[NB_PIONS];
  do{
    CLEAR_SCREEN;
    afficher_jeu(joueurs[i]);
    saisie_combi(combi_saisie);
    res = comparer(joueurs[i], combi_saisie);
    afficher_jeu(joueurs[i]);
      scanf("Appuyez sur entrée pour passer au joueur suivant.\n");
    if(i)
      i=0;
    else
      i=1;
  } while (!res && joueurs[0]->nb_coups <= NB_COUPS_MAX && joueurs[1]->nb_coups <= NB_COUPS_MAX);
  if(res)
    return 1;
  return 0;
}

void afficher_jeu(struct Joueur * joueur)
{
  /*
    affiche toutes les combinaisons passées du joueur et chaque resultat
    affiche le score du joueur
   */
  for(int i = 1; i < joueur->nb_coups; i++)
    {
      for(int j = 0; j < NB_PIONS; j++)
	{
	  printf("%d ", joueur->combinaisons_passees[i][j]);
	}
      printf("\t");
      for(int j = 0;  j < 2 ; j++)
	{
	  printf("bien placés : %d ; mal placés : %d", joueurs->resultats_passes[i][0], joueurs->resultats_passes[i][1]);
	}
      printf("\n");
    }
}

void saisie_combi(int * combi)
{
  
  int l = 0, i = 0;
  char saisie[30];

  printf("Veuillez rentrer votre combinaison sous la forme \" x1x2x3x4 \" où xi représente la couleur.\n");

  do{
    l=0;i=0;
    scanf("%s", saisie);

    do
      {
	if(saisie[i]>='0' && saisie[i]<='9')
	  {
	    combi[l] = saisie[i] - '0';
	    l++;
	  }
	else
	  printf("'%c' n'est pas une couleur. Ce caractère sera ignoré.\n", saisie[i]);
      }while(saisie[++i] && l<NB_PIONS);
    if(l<NB_PIONS)
      printf("vous n'avez pas placé assez de pions...\n");
  } while(l<NB_PIONS);

}
