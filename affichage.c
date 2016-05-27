#include <stdio.h>
#include <string.h>
#include "fonctions.h"
#include "gestion_jeu.h"
#include "zero_joueur.h"
void affichage_0();
void affichage_1();
void affichage_2();
void Mastermind();

void MasterMind (void)
{
  printf("Si vous voulez jouer à MasterMind, appuyez sur entrée");
  if (getchar()=='\n')
    {
      printf("\n Quel est le nombre de joueurs? 0 (mode ordinateur), 1 joueur ou 2?\n");
      if (getchar()=='1')
	{
	  affichage_1();
	}
      if (getchar()=='2')
	{
	  affichage_2();
	}
      if (getchar()=='0')
	{
	  affichage_0();	
	}
    }
}

void affichage_0(void)
{
  printf("vous avez choisi le mode ordinateur\n");
  struct Joueur ordi;
  //initialise nb de coups et score
  ordi.nb_coups = 0;
  ordi.nb_pts = 0;
  printf("\n pour commencer le jeu appuyer sur entrée\n");
  char c;
  scanf("%c", &c);
  while(c=='\n')
    { 
      zero_joueur(ordi); // à modifier
      //affiche RESULTATS
      printf("\n nom: %s \n nombre de coups: %d\n", ordi.nom, ordi.nb_coups);
      // Gagner ou pas ? dépend du return de gestion jeu mono
      
      ordi.nb_pts = ordi.nb_pts + ordi.nb_coups;//score
      ordi.nb_coups = 0; //réinitialise le nb de coups
      printf("pour rejouer appuyer sur entrée. Appuyer sur 1 pour changer de mode\n");
      scanf("%c",&c);
      if (c =='1')
	{
	  Mastermind();
	}
    }
}

void affichage_1(void)
{
  printf("nom du joueur?\n");
  struct Joueur Joueur1;
  scanf("%s",Joueur1.nom);
  fflush(stdin);
  //initialise nb de coups et score
  Joueur1.nb_coups = 0;
  Joueur1.nb_pts = 0;
  
  printf("bonjour %s : mode 1joueur.\n", Joueur1.nom);
  printf("\n pour commencer le jeu appuyer sur entrée\n");
  
  char c;
  scanf("%c",&c);
  while (c=='\n')
    {
      monojoueur(&Joueur1); //nom fonction à modifier
      
      //affiche RESULTATS
      printf("\n nom: %s \n nombre de coups: %d\n", Joueur1.nom, Joueur1.nb_coups);
      // Gagner ou pas ? dépend du return de gestion jeu mono
      
      Joueur1.nb_pts = Joueur1.nb_pts + Joueur1.nb_coups;//score
      Joueur1.nb_coups = 0; //réinitialise le nb de coups
      printf("pour rejouer appuyer sur entrée. Appuyer sur 1 pour changer de mode\n");
      scanf("%c",&c);
      if (c =='1')
	{
	  Mastermind();
	}
    }
}


void affichage_2(void)
{
  printf("nom des joueurs?\n Joueur 1:");
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
  printf("\n pour commencer le jeu appuyer sur entrée\n");
  
  char  c;
  scanf("%c",&c);
  while (c=='\n')
    {
      multijoueur(joueurs); //nom fonction à modifier
      
      //affiche RÉSULTATS
      printf("\n nom: %s \n nombre de coups: %d\n", joueurs[0].nom, joueurs[0].nb_coups );
      printf("\n nom: %s \n nombre de coups: %d \n", joueurs[1].nom, joueurs[1].nb_coups);
      // Qui a gagné? dépend du return de gestion jeu multi
      
      joueurs[0].nb_pts = joueurs[0].nb_pts + joueurs[0].nb_coups; //modifie score
      joueurs[0].nb_coups = 0; //réinitialise le nb de coups
      joueurs[1].nb_pts = joueurs[1].nb_pts + joueurs[1].nb_coups;
      joueurs[1].nb_coups = 0;
      
      printf("pour rejouer appuyer sur entrée, pour changer de mode appuyer sur 1\n");
      scanf("%c",&c);
      if (c =='1')
        {
	  Mastermind();
        }
    }
}

/*
  int main (int argc, char *argv[])
  {
  Mastermind();
  return 0;
  }*/
