#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fonctions.h"
#include "gestion_jeu.h"
#include "zero_joueur.h"
#include "affichage.h"

void Mastermind ()
{
  CLEAR_SCREEN;
  char c=0;
  printf(COLOR_GREEN);
  printf("\t***************************************\n");
  printf("\t* "); printf(COLOR_BLUE); printf("Bienvenue dans le jeu de Mastermind"); printf(COLOR_GREEN); printf(" *\n");
  printf("\t***************************************\n\n");
  printf(COLOR_STD);
  printf("Veuillez choisir le mode de jeu ('0' (mode ordinateur), '1' joueur ou '2' joueurs).\nEntrez n'importe quel autre caractère pour quitter.\n");
  c = getchar();
  switch(c)
    {
    case '1':
      affichage_1();
      break;
    case '2':
      affichage_2();
      break;
    case '3':
      affichage_0();
      break;
    default:
      break;
    }
}

void affichage_0(void)
{
  CLEAR_SCREEN;
  printf("Vous avez choisi le mode ordinateur\n");
  struct Joueur ordi;
  //initialise nb de coups et score
  ordi.nb_coups = 0;
  ordi.nb_pts = 0;
  char c;
  scanf("%c", &c);
  while(c=='\n')
    { 
      zero_joueur(&ordi);
      //affiche RESULTATS
      printf("\n Nom: %s \n Nombre de coups: %d\n", ordi.nom, ordi.nb_coups);
      // Gagner ou pas ? dépend du return de gestion jeu mono
      
      ordi.nb_pts = ordi.nb_pts + MAX_COUPS-ordi.nb_coups;//score
      ordi.nb_coups = 0; //réinitialise le nb de coups
      printf("Pour rejouer appuyez sur entrée. Appuyez sur 1 pour changer de mode.\n");
      flush();
      c = getchar();
      flush();
    }
  if (c =='1')
    {
      Mastermind();
    }
  
}

void affichage_1(void)
{
  CLEAR_SCREEN;
  printf("Nom du joueur?\n");
  struct Joueur Joueur1;
  scanf("%s",Joueur1.nom);
  //initialise nb de coups et score
  Joueur1.nb_coups = 0;
  Joueur1.nb_pts = 0;
  
  printf("\nBonjour %s ! Mode 1 joueur.\n", Joueur1.nom);
  
  char c;
  scanf("%c",&c);
  while (c=='\n')
    {
      int res = monojoueur(&Joueur1); 
      
      //affiche RESULTATS
      printf("\n Nom: %s \n Nombre de coups: %d\n", Joueur1.nom, Joueur1.nb_coups);
      // Gagner ou pas ? Retourne 1 si joueur à gagner, 0 sinon
      if (res==1)
	printf("Bravo vous avez Gagné!\n");
      else
	{
	  printf("C'est dommage, la combinaison mystère était:\n");
	  print_array_n(Joueur1.combi_a_trouver,NB_PIONS);
	}
      Joueur1.nb_pts = Joueur1.nb_pts + MAX_COUPS-Joueur1.nb_coups;//score
      Joueur1.nb_coups = 0; //réinitialise le nb de coups
      printf("Pour rejouer appuyez sur entrée. Appuyez sur 1 pour changer de mode\n");
      flush();
      scanf("%c",&c);
      flush();
    }
  if (c =='1')
    {
      Mastermind();
    }
}


void affichage_2(void)
{
  CLEAR_SCREEN;
  printf("Nom des joueurs?\n Joueur 1:");
  struct Joueur joueurs [2];
  
  scanf("%s",joueurs[0].nom);
  printf("\n Joueur 2:");
  scanf("%s",joueurs[1].nom);
  //initialise nb de coups et score
  joueurs[0].nb_coups = 0;
  joueurs[0].nb_pts = 0;
  joueurs[1].nb_coups = 0;
  joueurs[1].nb_pts = 0;
  
  printf("\n bonjour %s et %s\n", joueurs[0].nom, joueurs[1].nom);
  
  char  c;
  scanf("%c",&c);
  while (c=='\n')
    {
      int res = multijoueur(joueurs);
      
      //affiche RÉSULTATS
      // Qui a gagné? Retourne 0 si c'est le joueur 1 qui a gagné, 1 si c'est le joueur 2,
      if (res == 0)
	{
	  printf("Bravo %s vous avez trouvé la solution en %d coups\n", joueurs[0].nom,joueurs[0].nb_coups);
	  printf("C'est dommage %s, la combinaison mystère était:\n", joueurs[1].nom);
	  print_array_n(joueurs[1].combi_a_trouver,NB_PIONS);
	}
      if (res == 1)
	{
	  printf("Bravo %s vous avez trouvé la solution en %d coups\n", joueurs[1].nom,joueurs[1].nb_coups);
	  printf("C'est dommage %s, la combinaison mystère était:\n", joueurs[0].nom);
	  print_array_n(joueurs[0].combi_a_trouver,NB_PIONS);
	}

      /*else {
	printf("C'est dommage %s, la combinaison mystère était:", joueurs[0].nom);
	print_array_n(joueurs[0].combi_a_trouver,NB_PIONS);
	printf("C'est dommage %s, la combinaison mystère était:", joueurs[1].nom);
	print_array_n(joueurs[1].combi_a_trouver,NB_PIONS);
	
      */

      
      joueurs[0].nb_pts = joueurs[0].nb_pts + MAX_COUPS-joueurs[0].nb_coups; //modifie score
      joueurs[0].nb_coups = 0; //réinitialise le nb de coups
      joueurs[1].nb_pts = joueurs[1].nb_pts + MAX_COUPS-joueurs[1].nb_coups;
      joueurs[1].nb_coups = 0;
      
      printf("Pour rejouer appuyer sur entrée, pour changer de mode appuyer sur 1\n");
      flush();
      scanf("%c",&c);
      flush();
    }
  if (c =='1')
    {
      Mastermind();
    }
}

void help()
{
  printf("Bienvenue dans l'aide du mastermind!\n\n");
  printf("Syntaxe de la commande : ");
  printf(STYLE_BOLD);
  printf("./mmind {[-0|-1|-2] [-d <dictionnaire>] [-h]\n");
  printf(STYLE_NOBOLD);
  printf(COLOR_RED);
  printf("\t-0|-1|-2 : ");
  printf(COLOR_STD);
  printf("permet de choisir le nombre de joueurs.\n");
  printf(COLOR_RED);
  printf("\t-d <dictionnaire> : ");
  printf(COLOR_STD);
  printf("permet d'utiliser le dictionnaire, dont le chemin est spécifié par <dictionnaire>\n\n");
  printf("Les paramètres de la ligne de commande sont en option.\nSi vous ne mettez aucun paramètre, un menu vous permettra de choisir les modes de jeu.\n\n");
  printf("Appuyez sur entrée pour continuer et lancer le jeu en mode menu\n");
  getchar();
}
