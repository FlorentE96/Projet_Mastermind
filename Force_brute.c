//suppr les define et include et struct une fois que le code sera fini et testé et le main aussi
//changer le nom du fichier puisque la fonction n'est pas de la force brute
//faire des stat pour savoir enc cb de coup moyen ça trouve

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


/*permutte deux valeurs dans un tableau
void Permutation(int *tab, int i, int j)
{
    int temp = *tab[i];
    *tab[i] = *tab[j];
    *tab[j] = temp;
}
*/


/*cet algo détecte la variation de l'indicateur "nombre de pions bien placés" en ne faisiant varier qu'un paramètre à la fois (un seul pion de test) jusqu'à qu'il trouve sa bonne valeur */
void  Algo_1 (struct joueurs * Ordi, int *tab)
{
    int trouve[NB_PIONS];
    //initialisation du tab à 0 (pion de couleur 0)
    for(int i = 0; i < NB_PIONS; i++)
    {
        tab[i] = 0;
        trouve[i] = 0;
    }
    // initialisation pour la premiere boucle
    int pion = 0;
    comparaison(Ordi->combi_a_trouver, tab); //gérer ici el cas 0 ?
    int couleur_bien_place = Ordi->resultats[Ordi->nb_coups][0];
    int couleur_mal_place = Ordi->resultats[Ordi->nb_coups][1];
    //parcours du nombre de pion
    while(pion < NB_PIONS)
    {
        if (trouve[pion])
        {
            while (Ordi->resultats[Ordi->nb_coups][0] = couleur_bien_place)
            {
                if (Ordi->resultats[Ordi->nb_coups][1] > couleur_mal_place)
                    //faire faire l'algo_2
                if (Ordi->resultats[Ordi->nb_coups][1] < couleur_mal_place)
                    //gérer le cas ou 0 est détecté avec Algo_2
                if (tab[pion] > NB_COULEURS)
                    tab[pion] = 0;
                comparaison(Ordi->combi_a_trouver, tab);
                tab[pion]++;
            }
        trouve[pion] = 1;
        }
        pion++;
    }
}


/*Algo_2 se charge de trouver la place d'une couleur mal placée, il se déclenche quand l'indicateur "nb_couleur_mal_placé" augmente. L'algo parcours jusuqu'a que l'indicateur "bien"placé" augmente*/

int pos = pion + 1;
int val = tab[pion];
int decalage = 0; //lol toujours plus
int bien_place = Ordi->resultats[Ordi->nb_coups][0];
int mal_place = Ordi->resultats[Ordi->nb_coups][1];

do
{
    if(trouve[pos])
    {
        tab[pos] = tab[pion];
        if ((pos - 1 - decalage) != pion)
            tab[pos - 1 - decalage] = 0;
        comparaison(Ordi->combi_a_trouver, tab);
    }
    else
        decalage ++;
    pos ++;
}
while ((pos < NB_PIONS) && (Ordi->resultats[nb_coups][0] = bien_place));



int main()
{
    //init
    struct joueur Ordi;
    Ordi.nom = "Flo";
    Ordi.nb_pts = 0;
    Ordi.nb_coups = 0;
    Ordi.combi_a_trouver[0] = 1;
    Ordi.combi_a_trouver[1] = 2;
    Ordi.combi_a_trouver[2] = 3;
    Ordi.combi_a_trouver[3] = 4;

}