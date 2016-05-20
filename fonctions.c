#include <stdio.h>
#include <stdlib.h>
#include "fonction.h"

struct Joueur
{ char *nom;
  int nb_pts;
  int nb_coups;
  int combi_a_trouver[NB_PIONS];
  int combinaisons_passees[MAX_COUPS][NB_PIONS];
  int resultats_passes[MAX_COUPS][2];
};

void init_tab(int * tab, int valeur, int nb_case)
{
    for(int i = 0; i < nb_case; i++)
        tab[i] = valeur;
}

void init_combi_val(int *tab, const int *ref, int from, int val)
{
    int i = from;
    while(i < NB_PIONS)
    {
        if(ref[i] == -1)
            i ++;
        else
        {
            tab[i] = val;
            i ++;
        }
    }
}

void copy_tab(int * source, int * destination, int taille)
{
    for(int i = 0; i < taille; i ++)
    {
        destination[i] = source[i];
    }
}

void print_array_n (int *tableau, int taille)
{
    for (int i =0; i<taille; i++)
    {
        printf("%d ", tableau[i]);
    }
    printf("\n");
}

void comparaison(struct Joueur *joueur, int proposition[])
{
    joueur->nb_coups ++;
    int combi[NB_PIONS];
    copy_tab(joueur->combi_a_trouver, combi, NB_PIONS);
    
    for (int i = 0; i < NB_PIONS; i ++)
    {
        if(combi[i] == proposition[i])
        {
            combi[i] = -1;
            joueur->resultats_passes[joueur->nb_coups][0] ++;
        }
    }
    
    for (int i = 0; i < NB_PIONS; i ++)
    {
        for (int j = 0; j < NB_PIONS; j ++)
        {
            if(j != i && combi[j] != -1 && combi[j] == proposition[i])
            {
                joueur->resultats_passes[joueur->nb_coups][1] ++;
                combi[j] = -1;
                break;
            }
        }
    }
}

void init_player_keep_score(struct Joueur *joueur)
{
    joueur->nb_coups = 0;
    
    for(int m = 0; m < MAX_COUPS; m++)
    {
        joueur->resultats_passes[m][0] = 0;
        joueur->resultats_passes[m][1] = 0;
        joueur->combinaisons_passees[m][0] = 0;
        joueur->combinaisons_passees[m][1] = 0;
        joueur->combinaisons_passees[m][2] = 0;
        joueur->combinaisons_passees[m][3] = 0;
    }
}

