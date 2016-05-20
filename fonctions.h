#ifndef FONCTION_HEADER
#define FONCTION_HEADER

#define NB_PIONS (4)
#define NB_COULEURS (8)
#define MAX_COMBI (10000)
#define MAX_COUPS (100)
#define MAX_NAME (30)

struct Joueur;

void init_tab(int * tab, int valeur, int nb_case);

void init_combi_val(int *tab, const int *ref, int from, int val);

void copy_tab(int * source, int * destination, int taille);

void print_array_n (int *tableau, int taille);

void comparaison(struct Joueur *joueur, int proposition[]);

void init_player_keep_score(struct Joueur *joueur);

#endif