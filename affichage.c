#include <stdio.h>
#include <string.h>
#define TAILLE_MAX 10
#define NB_PIONS 4
#define MAX_COMBI 10
//nb pions : 4
//nb couleurs: 8

struct joueurs{
  char nom[TAILLE_MAX];
  int nb_pts;
  int nb_coups;
  int combi_a_trouver[NB_PIONS];
  int combi_passe[MAX_COMBI][NB_PIONS];
  int resultats[MAX_COMBI][2];  
}
  
  
  void MasterMind (void)
  {
    printf("Si vous voulez jouer à MasterMind, appuyer sur entrée");
    if (getchar()=='\n')
      {
	printf("\n Quel est le nombre de joueurs? 0 (mode ordinateur), 1 joueur ou 2?\n");
	if (getchar()=='1')
	  {
	    printf("nom du joueur?\n");
	    struct joueur Joueur1;
	    Joueur1.nom =; //getstring?
	    //initialise nb de coups et score
	    Joueur1.nb_coups = 0;
	    Joueur1.nb_pts = 0;
	    
	    printf("bonjour %s : mode 1joueur.\n", Joueur1.nom);
	    
	    char c = '1';
	    while (c==1)
	      {
		Gestion_Jeu_mono(Joueur1); //nom fonction à modifier
		
		//affiche RESULTATS
		printf("\n nom: %s \n nombre de coups: %d\n", Joueur1.nom, Joueur1.nb_coups );
		// Gagner ou pas ? dépend du return de gestion jeu mono
		
		Joueur1.nb_pts = Joueur1.nb_pts + Joueur1.nb_coups;//score
		Joueur1.nb_coups = 0; //réinitialise le nb de coups		
		printf("pour rejouer appuyer sur 1");
		c=getchar();
	      }
	  }
	if (getchar()=='2')
	  {
	    printf("nom des joueurs?\n Joueur 1:");
	    struct joueur Joueur1; //à modifier (tableau ?)
	    struct joueur Joueur2;
	    Joueur1.nom= ;//getstring
	    printf("\n Joueur 2:");
	    Joueur2.nom=;//getstring
	    //initialise nb de coups et score
	    Joueur1.nb_coups = 0;
	    Joueur1.nb_pts = 0;
	    Joueur2.nb_coups = 0;
	    Joueur2.nb_pts = 0;
	    
	    printf("\n bonjour %s et %s\n", Joueur1.nom, Joueur2.nom);
	    
	    char c = '1';
	    while (c==1)
	      {
		Gestion_Jeu_multi(Joueur1, Joueur2); //nom fonction à modifier	
		//affiche RÉSULTATS
		printf("\n nom: %s \n nombre de coups: %d\n", Joueur1.nom, Joueur1.nb_coups );
		print("\n nom: %s \n nombre de coups: %d \n", Joueur2.nom, Joueur2.nb_coups);
		// Qui a gagné? dépend du return de gestion jeu multi
		
		Joueur1.nb_pts = Joueur1.nb_pts + Joueur1.nb_coups; //modifie score
		Joueur1.nb_coups = 0; //réinitialise le nb de coups
		Joueur2.nb_pts = Joueur2.nb_pts + Joueur2.nb_coups;
		Joueur2.nb_coups = 0;		
		
		printf("pour rejouer appuyer sur 1");
		c=getchar();
		
	      }
	    if (getchar()=='0')
	      {
		printf("vous avez choisi le mode ordinateur\n");
		struct joueurs ordi;
		Gestion_Jeu_ordi(ordi); //nom fonction à modifier
		//à finir	
	      }
	  }
      }
