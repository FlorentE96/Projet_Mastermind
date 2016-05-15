#include "fonctions.h"

//#define NB_PIONS (4)
//#define NB_COULEURS (8)
//#define MAX_COMBI (10000)
//#define MAX_COUPS (10000)

void comparaison();
void print_array();
void init_tab();

void algo_1_V2 (struct Joueur * joueur, int tab[])
{
    int mem_bon = 0;
    int mem_mal = 0;
    int trouve[NB_PIONS];
    init_tab(tab, -1, NB_PIONS);
    init_tab(trouve, 0, NB_PIONS);
    int pos = 0;
    printf("tableau initial : "); print_array(tab);
    
    comparaison(joueur, tab);
    printf("Première comp : nombre de coups = %d\nbien places %d\nmal places %d\n", joueur->nb_coups, joueur->resultats_passes[joueur->nb_coups -1][0], joueur->resultats_passes[joueur->nb_coups -1][1]);
    
    
    while(pos < NB_PIONS)
    {
        if(trouve[pos] = 0)
        {
            do
            {
                tab[pos] ++;
                mem_bon = joueur->resultats_passes[joueur->nb_coups - 1][0];
                mem_mal = joueur->resultats_passes[joueur->nb_coups - 1][1];
                comparaison(joueur, tab);
                printf("nombre de coups = %d\nbien places %d\nmal places %d\n", joueur->nb_coups, joueur->resultats_passes[joueur->nb_coups -1][0], joueur->resultats_passes[joueur->nb_coups -1][1]);
                
                if(joueur->resultats_passes[joueur->nb_coups - 1][1] > 0)
                {
                    
                }
                
            }while(joueur->resultats_passes[joueur->nb_coups - 1][0] == mem_bon);
            trouve[pos] = 1;
            pos++;
        }
        else
            pos++;
    }
}


int main ()
{
    int tableau_retourne[NB_PIONS];
    
    struct Joueur joueur;
    joueur.nom = "Flo";
    joueur.nb_pts = 0;
    joueur.nb_coups = 0;
    joueur.combi_a_trouver[0] = 1;
    joueur.combi_a_trouver[1] = 2;
    joueur.combi_a_trouver[2] = 3;
    joueur.combi_a_trouver[3] = 4;
    for(int i =0; i < MAX_COUPS; i++)
    {
        joueur.resultats_passes[i][0] = 0;
        joueur.resultats_passes[i][1] = 0;
        joueur.combinaisons_passees[i][0] = 0;
        joueur.combinaisons_passees[i][1] = 0;
        joueur.combinaisons_passees[i][2] = 0;
        joueur.combinaisons_passees[i][3] = 0;
    }
    
    algo_1_V2(&joueur, tableau_retourne);
    printf("la combinaison est : "); print_array_4(tableau_retourne);
    
//    int proposition[] = {1,0,0,0};
//    comparaison(&joueur, proposition);
//    printf("nombre de coups = %d\nbien places %d\nmal places %d\n", joueur.nb_coups, joueur.resultats_passes[joueur.nb_coups -1][0], joueur.resultats_passes[joueur.nb_coups -1][1]);
//    
//    int proposition2[] = {1,2,4,3};
//    comparaison(&joueur, proposition2);
//    printf("nombre de coups = %d\nbien places %d\nmal places %d\n", joueur.nb_coups, joueur.resultats_passes[joueur.nb_coups -1][0], joueur.resultats_passes[joueur.nb_coups -1][1]);
//    
//    int proposition3[] = {2,1,4,3};
//    comparaison(&joueur, proposition3);
//    printf("nombre de coups = %d\nbien places %d\nmal places %d\n", joueur.nb_coups, joueur.resultats_passes[joueur.nb_coups -1][0], joueur.resultats_passes[joueur.nb_coups -1][1]);
    
    
    return 0;
}

