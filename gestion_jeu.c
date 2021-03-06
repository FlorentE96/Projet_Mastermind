#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "fonctions.h"
#include "gestion_jeu.h"
#include "Dictionary.h"

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

  printf("%s va te cacher, %s choisis ta combinaison : \n", joueurs[1].nom, joueurs[0].nom);
  saisie_combi(joueurs[1].combi_a_trouver);
  CLEAR_SCREEN;
  printf("%s va te cacher, %s choisis ta combinaison : \n", joueurs[0].nom, joueurs[1].nom);
  saisie_combi(joueurs[0].combi_a_trouver);
  CLEAR_SCREEN;

  printf("quand vous êtes prêts, appuyez sur entrée...");
  flush();
  getchar();

  int i=1; // variable correspondant au joueur. on commence à 1 parce qu'on passe à l'autre joueur au début de la boucle
  int combi_saisie[NB_PIONS];
  int res[2] = {0,};
  init_player_keep_score(&joueurs[0]);
  init_player_keep_score(&joueurs[1]);
  do{
    i = i?0:1; // passe à l'autre joueur
    CLEAR_SCREEN;
    afficher_jeu(joueurs[i]); // affichage des essais passés et des resultats passés
    saisie_combi(combi_saisie);
    res[i] = comparaison(&joueurs[i], combi_saisie); // retourne 1 si le joueur a gagné
    CLEAR_SCREEN;
    afficher_jeu(joueurs[i]); // affiche le resultat de l'essai immédiat
    printf("\nappuyez sur \"entrée\" pour passer au joueur suivant\n");
    flush();
    getchar();
      
  } while (!res[i] && joueurs[i].nb_coups < MAX_COUPS); // tant qu'aucun des joueurs n'a gagné et qu'aucun n'a perdu
  
  if(res[0] || joueurs[1].nb_coups >= MAX_COUPS)
    return 0;
  return 1;
}

int monojoueur(struct Joueur * joueur, int dico_mode, FILE * dico) // retourne 1 si gagné, 0 si perdu
{
  /*
    générer combinaison
    
    faire
        effacer ecran
        afficher interface
	attendre saisie
	incrementer nb_coups
	comparer saisie à combi à trouver
	afficher resultat
    tant que pas gagné et nb_coups < nb_coups_max:
    
    retourner resultat
  */
  time_t t;
  srand((unsigned) time(&t)); // initialisation de l'aléatoire

  if(dico_mode)
    {
      combi_dico(dico, joueur);
      for(int i = 0; i<NB_PIONS; i++)
	printf("%d ", joueur->combi_a_trouver[i]);
    }
  else
    {      
      printf("Génération de la combinaison... ");
      combi_rand(joueur); // génère une combinaison aléatoire
      printf("Combinaison générée!\n ");
    }
  
  printf("Quand vous êtes prêts, appuyez sur entrée.");
  getchar();
  int combi_saisie[NB_PIONS];
  int res=0;
  init_player_keep_score(joueur);
  do{
    CLEAR_SCREEN;
    afficher_jeu(*joueur);
    saisie_combi(combi_saisie);
    res = comparaison(joueur, combi_saisie);
  } while (!res && joueur->nb_coups < MAX_COUPS);

  return res; // retourne gagné ou pas gagné.
}

void afficher_jeu(struct Joueur joueur)
{
  /*
    affiche toutes les combinaisons passées du joueur et chaque resultat
    affiche le score du joueur
   */
  printf("Joueur : %s.\tNombre de coups restant : %d.\n\n", joueur.nom, MAX_COUPS - joueur.nb_coups);
  for(int i = 1; i <= joueur.nb_coups; i++)
    {
      printf("\t");
      for(int j = 0; j < NB_PIONS; j++)
	{
	  printf("%d ", joueur.combinaisons_passees[i][j]);
	}
      printf("\t");
      printf("bien placés : %d ; mal placés : %d\n", joueur.resultats_passes[i][0], joueur.resultats_passes[i][1]);
    }
}


/* permet la saisie d'une combinaison de NB_COUPS couleurs*/
void saisie_combi(int * combi)
{
  
  int l = 0, i = 0;
  char saisie[30];

  printf("Veuillez rentrer votre combinaison sous la forme \" x1x2x3x4 \" où xi représente la couleur.\n");

  do{
    l=0;i=0;
    scanf("%s", saisie); // lit la combinaison en tant que chaine de caractères

    do
      {
	if(saisie[i]>='0' && saisie[i]<='9') // si le caractère entré est un chiffre
	  {
	    combi[l] = saisie[i] - '0'; // convertit le caractère en int
	    l++;
	  }
	else
	  printf("'%c' n'est pas une couleur. Ce caractère sera ignoré.\n", saisie[i]);
      } while(saisie[++i] && l<NB_PIONS); // tant qu'il reste des caractères, et qu'on a pas encore ecrit tous les pions
    
    if(l<NB_PIONS) // si pas assez de pions saisis
      printf("Vous n'avez pas placé assez de pions... Veuillez recommencer.\n");
    else if(strlen(saisie) > NB_PIONS) // si trop de pions saisis
      {
	printf("Vous avez entré trop de couleurs. Seules les %d premières seront retenues. Appuyez sur entrée pour continuer\n", NB_PIONS);
	flush();
	getchar();
      }
  } while(l<NB_PIONS);

}

void combi_dico(FILE * dico, struct Joueur * joueur)
{
  
  char line[100] = "";
  int line_count = 0;
  int rand_line = random_number(dico);
  while(line_count != rand_line)
    {
      fgets(line, 100, dico);
      if(line[0] != ' ' && line[0] != '#' && line[0] != 0) line_count++;
    }
  
  for(int i = 0; i<NB_PIONS; i++)
    joueur->combi_a_trouver[i] = line[i] - '0';
}
