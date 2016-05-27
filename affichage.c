#include <stdio.h>
#include <string.h>
#include "fonctions.h"
#include "gestion_jeu.h"


//nb pions : 4
//nb couleurs: 8

struct Joueur
{
    char nom[MAX_NAME];
    int nb_pts;
    int nb_coups;
    int combi_a_trouver[NB_PIONS];
    int combi_passe[MAX_COUPS][NB_PIONS];
    int resultats[MAX_COUPS][2];
};


void Gestion_Jeu_mono();
void Gestion_Jeu_multi();
void Gestion_Jeu_ordi();


void MasterMind (void)
{
    
    printf("Si vous voulez jouer à MasterMind, appuyer sur entrée");
    
    if (getchar()=='\n')
    {
        printf("\n Quel est le nombre de joueurs? 0 (mode ordinateur), 1 joueur ou 2?\n");
        if (getchar()=='1')
        {
            printf("nom du joueur?\n");
            struct Joueur Joueur1;
            scanf("%s",Joueur1.nom);
            //initialise nb de coups et score
            
            Joueur1.nb_pts = 0;
            
            printf("bonjour %s : mode 1joueur.\n", Joueur1.nom);
            char c = '1';
            while (c==1)
            {
                Gestion_Jeu_mono(Joueur1); //nom fonction à modifier
                
                //affiche RESULTATS
                printf("\n nom: %s \n nombre de coups: %d\n", Joueur1.nom, Joueur1.nb_coups);
                // Gagner ou pas ? dépend du return de gestion jeu mono
                
                Joueur1.nb_pts = Joueur1.nb_pts + Joueur1.nb_coups;//score
                Joueur1.nb_coups = 0; //réinitialise le nb de coups
                printf("pour rejouer appuyer sur 1");
                c = getchar();
            }
        }
        
        
        if (getchar()=='2')
        {
            printf("nom des joueurs?\n Joueur 1:");
            struct Joueur Joueur1; //à modifier (tableau ?)
            struct Joueur Joueur2;
            scanf("%s",Joueur1.nom);
            printf("\n Joueur 2:");
            scanf("%s",Joueur2.nom);
            //initialise nb de coups et score
            Joueur1.nb_coups = 0;
            Joueur1.nb_pts = 0;
            Joueur2.nb_coups = 0;
            Joueur2.nb_pts = 0;
            
            printf("\n bonjour %s et %s\n", Joueur1.nom, Joueur2.nom);
            
            char c = '1';
            while (c == 1)
            {
                Gestion_Jeu_multi(Joueur1, Joueur2); //nom fonction à modifier
                //affiche RÉSULTATS
                printf("\n nom: %s \n nombre de coups: %d\n", Joueur1.nom, Joueur1.nb_coups );
                printf("\n nom: %s \n nombre de coups: %d \n", Joueur2.nom, Joueur2.nb_coups);
                // Qui a gagné? dépend du return de gestion jeu multi
                
                Joueur1.nb_pts = Joueur1.nb_pts + Joueur1.nb_coups; //modifie score
                Joueur1.nb_coups = 0; //réinitialise le nb de coups
                Joueur2.nb_pts = Joueur2.nb_pts + Joueur2.nb_coups;
                Joueur2.nb_coups = 0;
                
                printf("pour rejouer appuyer sur 1");
                c = getchar();
            }
        }
        
        if (getchar()=='0')
        {
            printf("vous avez choisi le mode ordinateur\n");
            struct Joueur ordi;
            Gestion_Jeu_ordi(ordi); //nom fonction à modifier
            //à finir	
        }
    }
}
