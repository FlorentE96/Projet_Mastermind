#include <stdio.h>
#define NB_PIONS (4)
#define NB_COULEURS (8)
#define MAX_COMBI (10000)
#define MAX_COUPS (10)


struct joueur
{ char *nom;
    int nb_pts;
    int nb_coups;
    int combi_a_trouver[NB_PIONS];
    int combinaisons_passees[MAX_COUPS][NB_PIONS];
    int resultats[MAX_COUPS][2];
};

void algo_1_V2 (struct joueur * joueur, int *essai)
{
    int trouve[NB_PIONS];
    int pion = 0;
    int cpt = 0;
    
    //init
    for(int i = 0; i < NB_PIONS; i++)
    {
        essai[i] = 0;
        trouve[i] = 0;
    }
    
    //comp initiale avec 0000
    comparaison(joueur->combi_a_trouver, essai);
    
    //algo
    while (pion < NB_PIONS)
    {
        //sauvegarde de l'état des indicateurs
        int couleur_bien_place = Ordi->resultats[Ordi->nb_coups][0];
        int couleur_mal_place = Ordi->resultats[Ordi->nb_coups][1];
        
        if(trouve[pion])
        {
            do
            {
                essai[pion]++;
                comparaison(joueur->combi_a_trouver, essai);
            } while (joueur->resultats[nb_coups][0] = couleur_bien_place);
            trouve[pion] = 1;
        }
        pion ++;
    }
}



void main ()
{
    
}

