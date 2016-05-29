#ifndef ZERO_JOUEUR_H
#define ZERO_JOUEUR_H

void algo_1(struct Joueur * joueur, int * essai);

void algo_2(struct Joueur * joueur, int * sortie);

void test_algo_1(int * combinaison);

void test_algo_2(int * combinaison);

void get_gnuplot_trace_algo_1(void);

void get_average_value_algo_1(void);

void zero_joueur (struct Joueur * joueur);

void zero_joueur_detailed(struct Joueur * joueur, int * essai);

#endif
