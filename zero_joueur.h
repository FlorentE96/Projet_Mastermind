#include "fonctions.h"

void init_tab();
void init_combi_val();
void copy_tab();
void print_array_4();
void print_array_n();
void comparaison();

void algo_1(struct Joueur * joueur, int * essai)
{
    int pos = 0;
    int pos_2 = 0;
    int trouve[NB_PIONS];
    init_tab(trouve, 0, NB_PIONS);
    init_tab(essai, -1, NB_PIONS);
    
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
        
    }while(joueur->resultats_passes[joueur->nb_coups][0] != NB_PIONS);
}


void algo_2(struct Joueur * joueur, int * sortie)
{
    int trouve[NB_PIONS];
    int essai[NB_PIONS];
    init_tab(trouve, 0, NB_PIONS);
    init_tab(essai, 0, NB_PIONS);
    init_tab(sortie, 0, NB_PIONS);
    int compteur = 1;
    int nb_bons = 0;
    
    do
    {
        init_combi_val(essai, trouve, 0, compteur);
        comparaison(joueur, essai);
        
        if(joueur->resultats_passes[joueur->nb_coups][0] > 0)
        {
            int pos = 0;
            
            while(joueur->resultats_passes[joueur->nb_coups][0] != nb_bons - 1 && nb_bons < 4)
            {
                init_combi_val(essai, trouve, NB_PIONS - pos -1, 0);
                comparaison(joueur, essai);
                
                //rajouter if(cpos = 4) alors on a trouvé le nb)
                
                if(joueur->resultats_passes[joueur->nb_coups][0] > joueur->resultats_passes[joueur->nb_coups - 1][0])
                {
                    nb_bons ++;
                    trouve[NB_PIONS - pos -1] = -1;
                    nb_bons ++;
                    sortie[NB_PIONS - pos -1] = 0;
                    pos ++;
                }
                
                if(trouve[NB_PIONS - pos - 1] == -1) //avant ou après le 1er if ... ?
                    pos ++;
                
                if(joueur->resultats_passes[joueur->nb_coups][0] < joueur->resultats_passes[joueur->nb_coups - 1][0])
                {
                    trouve[NB_PIONS - pos -1] = -1;
                    nb_bons ++;
                    sortie[NB_PIONS - pos -1] = compteur;
                    pos ++;
                }
                
                else
                    pos ++;
            }
            compteur ++;
            copy_tab(sortie, essai, NB_PIONS);
        }
        else
            compteur ++;
        
    } while(joueur->resultats_passes[joueur->nb_coups][0] != NB_PIONS);
}

void test_algo_1(int * combinaison)
{
    int sortie[NB_PIONS];
    struct Joueur joueur;
    joueur.nb_coups = 0;
    for(int m = 0; m < MAX_COUPS; m++)
    {
        joueur.resultats_passes[m][0] = 0;
        joueur.resultats_passes[m][1] = 0;
        joueur.combinaisons_passees[m][0] = 0;
        joueur.combinaisons_passees[m][1] = 0;
        joueur.combinaisons_passees[m][2] = 0;
        joueur.combinaisons_passees[m][3] = 0;
    }
    copy_tab(combinaison, joueur.combi_a_trouver, NB_PIONS);
    
    algo_1(&joueur, sortie);
    printf("La combinaison était : ");
    print_array_n(sortie, NB_PIONS);
}

void test_algo_2(int * combinaison)
{
    int sortie[NB_PIONS];
    struct Joueur joueur;
    joueur.nb_coups = 0;
    for(int m = 0; m < MAX_COUPS; m++)
    {
        joueur.resultats_passes[m][0] = 0;
        joueur.resultats_passes[m][1] = 0;
        joueur.combinaisons_passees[m][0] = 0;
        joueur.combinaisons_passees[m][1] = 0;
        joueur.combinaisons_passees[m][2] = 0;
        joueur.combinaisons_passees[m][3] = 0;
    }
    copy_tab(combinaison, joueur.combi_a_trouver, NB_PIONS);
    
    algo_2(&joueur, sortie);
    printf("La combinaison était : ");
    print_array_n(sortie, NB_PIONS);
}

void get_gnuplot_trace_algo_1(void)
{
    int tableau_retourne[NB_PIONS];
    double moyenne = 0;
    struct Joueur joueur;
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
                    
                    algo_1(&joueur, tableau_retourne);
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

void get_average_value_algo_1(void)
{
    int tableau_retourne[NB_PIONS];
    double moyenne = 0;
    struct Joueur joueur;
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
                    
                    algo_1(&joueur, tableau_retourne);
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