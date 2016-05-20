#include <stdio.h>
#include <string.h>
#define TAILLE_MAX 10
#define NB_PIONS 4
#define MAX_COUPS 10
//nb pions : 4
//nb couleurs: 8

struct Joueur{
  char nom[TAILLE_MAX];
  int nb_pts;
  int nb_coups;
  int combi_a_trouver[NB_PIONS];
  int combinaisons_passees[MAX_COUPS][NB_PIONS];
  int resultats_passes[MAX_COUPS][2];  
};

void affichage_1();
void affichage_2();
void Mastermind();


void Mastermind (void)
{ 
  printf("Si vous voulez jouer à MasterMind, appuyer sur entrée\n");
  fflush(stdin);
  if (getchar()=='\n')
    {
      printf("\n Quel est le nombre de joueurs? 0 (mode ordinateur), 1 joueur ou 2?\n");
      char nb_joueurs = getchar();
      if (nb_joueurs == '1')
	{
	  affichage_1();
	}
      if (nb_joueurs =='2')
	{
	  affichage_2();
	}
	 
      /* if (nb_joueurs=='0')
	     {
	     printf("vous avez choisi le mode ordinateur\n");
	     struct joueurs ordi;
	     //Gestion_Jeu_ordi(ordi); //nom fonction à modifier
	     //à finir	
	     }*/
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
 
  char c = getchar();
  while (c=='\n')
    {
      // mono(Joueur1); //nom fonction à modifier
      
      //affiche RESULTATS
      printf("\n nom: %s \n nombre de coups: %d\n", Joueur1.nom, Joueur1.nb_coups );
      // Gagner ou pas ? dépend du return de gestion jeu mono
      
      Joueur1.nb_pts = Joueur1.nb_pts + Joueur1.nb_coups;//score
      Joueur1.nb_coups = 0; //réinitialise le nb de coups		
      printf("pour rejouer appuyer sur entrée. Appuyer sur 1 pour changer de mode\n");
      c=getchar();
      if (c =='1'){
	Mastermind();
      }
    }
}


void affichage_2(void)
{
  printf("nom des joueurs?\n Joueur 1:");
  struct Joueur Joueur1; //à modifier (tableau ?)
  struct Joueur Joueur2;
  scanf("%s",Joueur1.nom);
  printf("\n Joueur 2:");
  scanf("%s",Joueur2.nom);
  fflush(stdin);
  //initialise nb de coups et score
  Joueur1.nb_coups = 0;
  Joueur1.nb_pts = 0;
  Joueur2.nb_coups = 0;
  Joueur2.nb_pts = 0;
  
  printf("\n bonjour %s et %s\n", Joueur1.nom, Joueur2.nom);
  printf("\n pour commencer le jeu appuyer sur entrée\n");
  
  char  c=getchar();
  while (c=='\n')
    {
      //multi(Joueur1, Joueur2); //nom fonction à modifier
      
      //affiche RÉSULTATS
      printf("\n nom: %s \n nombre de coups: %d\n", Joueur1.nom, Joueur1.nb_coups );
      printf("\n nom: %s \n nombre de coups: %d \n", Joueur2.nom, Joueur2.nb_coups);
      // Qui a gagné? dépend du return de gestion jeu multi
      
      Joueur1.nb_pts = Joueur1.nb_pts + Joueur1.nb_coups; //modifie score
      Joueur1.nb_coups = 0; //réinitialise le nb de coups
      Joueur2.nb_pts = Joueur2.nb_pts + Joueur2.nb_coups;
      Joueur2.nb_coups = 0;		
      
      printf("pour rejouer appuyer sur entrée, pour changer de mode appuyer sur 1\n");
      c=getchar();
      if (c =='1'){
	Mastermind();
      }
    }
}


int main (int argc, char *argv[])
{
  Mastermind();
  return 0;
}
