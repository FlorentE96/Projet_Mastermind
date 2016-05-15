#include <stdio.h>
#include <stdlib.h>

#define NB_PIONS (4)
#define NB_COULEURS (8)
#define MAX_COMBI (10000)
#define MAX_COUPS (10000)

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

void print_array_4 (int * tab)
{
    for (int i =0; i<4; i++)
    {
        printf("%d ", tab[i]);
    }
    printf("\n");
}

void comparaison (struct Joueur *joueur, int proposition[])
{
    int deja_comp[NB_PIONS];
    
    for(int i =0; i < NB_PIONS; i++)
    {
        joueur->combinaisons_passees[joueur->nb_coups][i] = proposition[i];
        deja_comp[i] = 0;
        if(joueur->combi_a_trouver[i] == proposition[i])
            joueur->resultats_passes[joueur->nb_coups][0] += 1;
        deja_comp[i] = 1;
    }
    
    
    for(int j = 0; j < NB_PIONS; j++)
    {
        for(int k = 0; k < NB_PIONS; k++)
        {
            if(j != k && deja_comp[j] && proposition[j] == joueur->combi_a_trouver[k])
            {
                joueur->resultats_passes[joueur->nb_coups][1] += 1;
                deja_comp[j] = 1;
            }
        }
    }
    joueur->nb_coups ++;
}
