#ifndef GESTION_JEU_H
#define GESTION_JEU_H

void saisie_combi(int * combi);
void afficher_jeu(struct Joueur joueur);
int multijoueur(struct Joueur * joueurs); // retourne le numéro du joueur gagnant (joueur 0 ou joueur 1)
int monojoueur(struct Joueur * joueur); // retourne 1 si gagné, 0 si perdu

#endif
