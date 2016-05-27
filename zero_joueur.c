#include <stdio.h>
#include <math.h>
#include "fonctions.h"
#include "zero_joueur.h"


/*trouve la combinaison stockée dans le joueur "joueur"
 le tableuau "essai" est un tableau de sortie qu'il faut creer avant et de taille NB_PION", il stocke la combinaison trouvée
 */
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


/*cet algo à la particularité de ne pas encore fonctionner
 */
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

/*affiche la combinaison trouvée par l'algorythme 1 lorsque l'on met en entrée la combi "combinaison"
 */
void test_algo_1(int * combinaison)
{
    int sortie[NB_PIONS];
    struct Joueur joueur;
    init_player_keep_score(&joueur);
    copy_tab(combinaison, joueur.combi_a_trouver, NB_PIONS);
    
    algo_1(&joueur, sortie);
    printf("La combinaison était : ");
    printf("je l'ai trouvée en %d coups\n", joueur.nb_coups);
    print_array_n(sortie, NB_PIONS);
}

/*la même chose pour l'algorythme 2
 */
void test_algo_2(int * combinaison)
{
    int sortie[NB_PIONS];
    struct Joueur joueur;
    init_player_keep_score(&joueur);
    copy_tab(combinaison, joueur.combi_a_trouver, NB_PIONS);
    
    algo_2(&joueur, sortie);
    printf("La combinaison était : ");
    print_array_n(sortie, NB_PIONS);
}

/*ce truc affiche tous les couples (combinaison, nb essai) de algo 1 pour faire des stats
 pour visualisser le résultats : 
 - make
 - ./main>graph
 - gnuplot
 - plot "graph" with line
 */
void get_gnuplot_trace_algo_1(void)
{
    int tableau_retourne[NB_PIONS];
    struct Joueur joueur;
    joueur.nb_coups = 0;
    int somme = 0;
    int num_exp = 0;
    
    for(int i = 0; i < NB_COULEURS; i ++)
    {
        for(int j = 0; j < NB_COULEURS; j ++)
        {
            for(int k = 0; k < NB_COULEURS; k ++)
            {
                for(int l = 0; l < NB_COULEURS; l ++)
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
                    
                    printf("%d ", num_exp);
                    printf("%d\n", joueur.nb_coups);
                    somme += joueur.nb_coups;
                    joueur.nb_coups = 0;
                }
            }
        }
    }
}

/*renvoie l'espérence du nombre de coup pour que le 1er algo trouve la combinaison
 en pratique toutes les combi sont testées et la moyenne est faite
 */
void get_average_value_algo_1(void)
{
    int tableau_retourne[NB_PIONS];
    double moyenne = 0;
    struct Joueur joueur;
    joueur.nb_coups = 0;
    int somme = 0;
    //int num_exp = 0;
    
    for(int i = 0; i < NB_COULEURS; i ++)
    {
        for(int j = 0; j < NB_COULEURS; j ++)
        {
            for(int k = 0; k < NB_COULEURS; k ++)
            {
                for(int l = 0; l < NB_COULEURS; l ++)
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
                    
                    joueur.combi_a_trouver[0] = i;
                    joueur.combi_a_trouver[1] = j;
                    joueur.combi_a_trouver[2] = k;
                    joueur.combi_a_trouver[3] = l;
                    
                    algo_1(&joueur, tableau_retourne);

                    somme += joueur.nb_coups;
                    joueur.nb_coups = 0;
                    
                }
            }
        }
    }
    
    moyenne = somme/(pow(NB_COULEURS, NB_PIONS));
    printf("Moyenne du nombre de coup nécessaires : %.0f\n", moyenne);
}


void zero_joueur(struct Joueur *joueur)
{
    int tableau[NB_PIONS];
    combi_rand(joueur);
    algo_1(joueur, tableau);
    
    printf("hmmmm je choisi une combinaison au hazarre...\n");
    printf("je choisi la combinaison : ");
    print_array_n(joueur->combi_a_trouver, NB_PIONS);
    printf("Oups je l'ai oubliée ! Attend je la trouve ...\n");
    printf("nombres de coups : %d\n", joueur->nb_coups);
    printf("j'ai trouvé : ");
    print_array_n(tableau, NB_PIONS);
    printf("soupèse mon swag\n");
}


void zero_joueur_detailed(struct Joueur * joueur, int * essai)
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
            comparaison(joueur, essai);
            
            if(joueur->resultats_passes[joueur->nb_coups][0] > joueur->resultats_passes[joueur->nb_coups - 1][0])
            {
                trouve[pos] = -1;
                print_array_n(joueur->resultats_passes[joueur->nb_coups], NB_PIONS);
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
                    comparaison(joueur, essai);
                    
                    if(joueur->resultats_passes[joueur->nb_coups][0] > joueur->resultats_passes[joueur->nb_coups - 1][0])
                    {
                        trouve[pos_2] = -1;
                        print_array_n(joueur->resultats_passes[joueur->nb_coups], NB_PIONS);
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
