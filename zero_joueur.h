#include "fonctions.h"

void algo_1_V3 (struct Joueur * joueur, int * essai)
{
    int pos = 0;
    int pos_2 = 0;
    int trouve[4];
    init_tab(trouve, 0, 4);
    init_tab(essai, -1, 4);
    
    do
    {
        if(trouve[pos] != -1)
        {
            essai[pos] ++;
//            print_array_4(essai);
//            print_array_4(trouve);
            comparaison(joueur, essai);
            
            if(joueur->resultats_passes[joueur->nb_coups][0] > joueur->resultats_passes[joueur->nb_coups - 1][0])
            {
                trouve[pos] = -1;
                init_combi_val(essai, trouve, pos + 1, essai[pos] - 1);
                if(joueur->resultats_passes[joueur->nb_coups][1] == 0)
                    pos ++;
            }
        }
        
        if(trouve[pos] == -1)
            pos ++;
        
        
        if(joueur->resultats_passes[joueur->nb_coups][1] > 0)
        {
            pos_2 = pos + 1;
            
            while(pos_2 < NB_PIONS && joueur->resultats_passes[joueur->nb_coups][1] > 0)
            {
                if(trouve[pos_2] == -1)
                {
                    pos_2 ++;
                }
                
                else
                {
                    essai[pos_2] = essai[pos];
//                    print_array_4(essai);
//                    print_array_4(trouve);
                    comparaison(joueur, essai);
                    
                    if(joueur->resultats_passes[joueur->nb_coups][0] > joueur->resultats_passes[joueur->nb_coups - 1][0])
                    {
                        trouve[pos_2] = -1;
                        pos_2 ++;
                    }
                    
                    else
                        pos_2 ++;
                }
            }
            init_combi_val(essai, trouve, pos + 1, essai[pos]);
        }
        
    }while(joueur->resultats_passes[joueur->nb_coups][0] != 4);
}


void get_gnuplot_trace_algo_1_V3(void)
{
    int tableau_retourne[NB_PIONS];
    double moyenne = 0;
    struct Joueur joueur;
    joueur.nom = "Flo";
    joueur.nb_pts = 0;
    joueur.nb_coups = 0;
    int somme = 0;
    int num_exp = 0;
    
    for(int i = 0; i < 10; i ++)
    {
        for(int j = 0; j < 10; j ++)
        {
            for(int k = 0; k < 10; k ++)
            {
                for(int l = 0; l < 10; l ++)
                {
                    for(int m = 0; m < MAX_COUPS; m++)
                    {
                        joueur.resultats_passes[m][0] = 0;
                        joueur.resultats_passes[m][1] = 0;
                        joueur.combinaisons_passees[m][0] = 0;
                        joueur.combinaisons_passees[m][1] = 0;
                        joueur.combinaisons_passees[m][2] = 0;
                        joueur.combinaisons_passees[m][3] = 0;
                    }
                    num_exp = l + 10*k +100*j + 1000*i;
                    
                    joueur.combi_a_trouver[0] = i;
                    joueur.combi_a_trouver[1] = j;
                    joueur.combi_a_trouver[2] = k;
                    joueur.combi_a_trouver[3] = l;
                    
                    algo_1_V3(&joueur, tableau_retourne);
                    //printf("la combinaison est : "); print_array_4(tableau_retourne);
                    
                    printf("%d ", num_exp);
                    printf("%d\n", joueur.nb_coups);
                    somme += joueur.nb_coups;
                    joueur.nb_coups = 0;
                }
            }
        }
    }
}

void get_average_value_algo_1_V3(void)
{
    int tableau_retourne[NB_PIONS];
    double moyenne = 0;
    struct Joueur joueur;
    joueur.nom = "Flo";
    joueur.nb_pts = 0;
    joueur.nb_coups = 0;
    int somme = 0;
    //int num_exp = 0;
    
    for(int i = 0; i < 10; i ++)
    {
        for(int j = 0; j < 10; j ++)
        {
            for(int k = 0; k < 10; k ++)
            {
                for(int l = 0; l < 10; l ++)
                {
                    for(int m = 0; m < MAX_COUPS; m++)
                    {
                        joueur.resultats_passes[m][0] = 0;
                        joueur.resultats_passes[m][1] = 0;
                        joueur.combinaisons_passees[m][0] = 0;
                        joueur.combinaisons_passees[m][1] = 0;
                        joueur.combinaisons_passees[m][2] = 0;
                        joueur.combinaisons_passees[m][3] = 0;
                    }
                    //num_exp = l + 10*k +100*j + 1000*i;
                    
                    joueur.combi_a_trouver[0] = i;
                    joueur.combi_a_trouver[1] = j;
                    joueur.combi_a_trouver[2] = k;
                    joueur.combi_a_trouver[3] = l;
                    
                    algo_1_V3(&joueur, tableau_retourne);
                    //printf("la combinaison est : "); print_array_4(tableau_retourne);
                    
                    //printf("%d ", num_exp);
                    somme += joueur.nb_coups;
                    joueur.nb_coups = 0;
                    
                }
            }
        }
    }
    
    moyenne = somme/10000;
    printf("Moyenne du nombre de coup nécessaires : %.0f\n", moyenne);
}