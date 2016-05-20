#include <stdio.h>
#include <stdlib.h>
#include "fonctions.h"


/* initialise la tableau de taille nb_case" pointé à la valeur "valeur"
*/
void init_tab(int * tab, int valeur, int nb_case)
{
    for(int i = 0; i < nb_case; i++)
        tab[i] = valeur;
}

/* ce truc prend en entrée un tableau de taille NB_PION et initialise ce tableau à partir de la case "from" jusqu'à la fin sauf les cases ou il ya un "-1" dans le tableau "ref"
*/
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

/* copie le tableau source dans le tableau destination sachant que leur taille est égale à taille 
*/
void copy_tab(int * source, int * destination, int taille)
{
    for(int i = 0; i < taille; i ++)
    {
        destination[i] = source[i];
    }
}

void print_array_n (int *tableau, int taille)
{
    for (int i = 0; i<taille; i++)
    {
        printf("%d ", tableau[i]);
    }
    printf("\n");
}

/* compare la combinaison à trouver stockée dans le joueur "joueur" mis en entrée (pointeur), met à jour l'historique du joueur (combinaison passée, le résutat de la combinaison etc ) et incrémente le nombre de coups du joueur
 attention : ce truc ne fait pas de remise à 0, c'est "init_player_keep_score" qui le fait 
 Ce truc ne retourne rien
 
 Avec tableau = {1, 2, 3, 4}
 exemple : comparaison(&joueur_1, tableau)
  */
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


/* initalise à 0 les combinaison et les résultats du joueur pointé ainsi que son nombre de coups
 Ne remet pas à 0 son nombre de points
 */
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

