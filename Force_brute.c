//trouve la combi en comparant 1 par 1 les pions placés
//suppr les define et include et struct une fois que le code sera fini et testé et le main aussi

#include <stdio.h>
#define NB_PIONS (4)
#define NB_COULEURS (8)
#define MAX_COMBI (10000)


struct joueurs {
    char nom;
    int nb_points;
    int nb_coups;
    int combi_a_trouver[NB_PIONS];
    int resultats[MAX_COMBI][2];
};


/*permutte deux valeurs dans un tableau*/
 void Permutation(int *tab, int i, int j)
{
    int temp = *tab[i];
    *tab[i] = *tab[j];
    *tab[j] = temp;
}


/*cet algo détecte la variation de l'indicateur "nombre de pions bien placés" en ne faisiant varier qu'un paramètre à la fois (un seul pion de test) jusqu'à qu'il trouve sa bonne valeur */
void  Algo_1(struct * joueurs Ordi, int *tab)
{
    int bien_place[NB_PIONS];
    //initialisation du tab à 0 (pion de couleur 0)
    for(int i =0, i < NB_PIONS, i++)
    {
        tab[i] = 0;
        bien_place[i] = 0;
    }
    // initialisation pour la premiere boucle
    int pion = 0;
    comparaison(Ordi->combi_a_trouver, tab);
    int couleur_bien_place = Ordi->resultats[NB_COUPS][0];
    int couleur_mal_place = Ordi->resultats[NB_COUPS][1];
    //parcours du nombre de pion
    while(pion < NB_PIONS && bien_place[pion] = 0)
    {
        if(Ordi->resultats[NB_COUPS][1] <= couleur_mal_place)
        {
            Algo_2 //a finir
            //on compare le pion "pion" en augmentant sa valeur
        }
        while (Ordi->resultats[NB_COUPS][0] <= couleur_bien_place)
        {
            tab[pion]++;
            //ne pas oublier de boucler
            if (tab[pion] > NB_COULEURS) tab[pion] = 0;
            comparaison(Ordi->combi_a_trouver, tab);
        }
        bien_place[pion] = 1;
        pion++;
    }
}


/*Algo_2 se charge de trouver la place d'une couleur mal placée, il se déclenche quand l'indicateur "nb_couleur_mal_placé" augmente. L'algo parcours jusuqu'a que l'indicateur "bien"placé" augmente*/
void Algo_2 (struct *joueurs Ordi)
{
    
}


void main()
{
    //init
    struct joueurs Ordi1;
    Ordi1.nb_coups=0;
}