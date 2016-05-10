#include <stdlib.h>
#include <stdout.h>


/*
       joueur : structure,
       	      char * nom
	      int nb_pts
	      int nb_coups
	      tableau combi_a_trouver
	      matrice combinaisons passées
	      matrice resultats passés : {{nombre pions bien placé ; nombre bonnes couleurs mal placées},...}

comparer : prend en paramètre une structure joueur, met à jour les champs "combinaisons passées" et "resultats passés"


       Mode 2 joueurs :
       	Duel : 1 combi chacun choisie par joueur, premier qui trouve gagne. On entrelace les coups. tempo?
	Tournoi : 1 combi chacun choisie par ordi, règles survivant / survivant extrême.
	Mode ordinateur

*/

int multijoueur(struct Joueur * joueurs)
{
  /*
    afficher menu choix combinaison joueur 1
    afficher menu choix combinaison joueur 2

    tant que personne n'a gagné : 
	effacer ecran
        afficher joueur i
        attendre saisie
	incrementer nb_coups
	comparer combi à trouver autre joueur
	afficher resultat
	tempo
	joueur ++
    
    return joueur gagnant
  */
  printf("%s va te cacher, %s choisis ta combinaison : \n", joueurs[1]->nom, joueurs[0]->nom);
  saisie_combi(joueurs[0]->combi_a_trouver);
  CLEAR_SCREEN;
  printf("%s va te cacher, %s choisis ta combinaison : \n", joueurs[0]->nom, joueurs[1]->nom);
  saisie_combi(joueurs[1]->combi_a_trouver);
  CLEAR_SCREEN;

  printf("quand vous êtes prêts, appuyez sur entrée...");
  getc();

  int i=1; // variable correspondant au joueur. on commence à 1 parce qu'on passe à l'autre joueur au début de la boucle
  
  do{
    i = i?0,1; // passe à l'autre joueur
    CLEAR_SCREEN;
    afficher_jeu(joueurs[i]);
    saisie_combi(combi_saisie);
    joueurs[i]->nb_coups++;
    res[i] = comparer(combi_saisie, joueurs[i]);
    afficher_jeu(joueurs[i]);
    tempo(5); // secondes
  } while (!res[i] && joueurs[i]->nb_coups < NB_COUPS_MAX);
  
  if(res[0] || joueurs[1]->nb_coups >= NB_COUPS_MAX)
    return 0;
  return 1;
}

int monojoueur(struct Joueur * joueur)
{
  /*
    calc_combinaison
    choisir nombre de coups max
    
    tant que pas gagné et nb_coups < nb_coups_max:
        afficher interface
	attendre saisie
	incrementer nb_coups
	comparer saisie à combi à trouver
	afficher resultat
		
  */

  printf("quand vous êtes prêts, appuyez sur entrée...");
  getc();
  
  do{
    CLEAR_SCREEN;
    afficher_jeu(joueurs[i]);
    saisie_combi(combi_saisie);
    res = comparer(combi_saisie, joueurs[i]);
    afficher_jeu(joueurs[i]);
    tempo(5); // secondes
    if(i)
      i=0;
    else
      i=1;
  } while (!res && joueurs[0]->nb_coups <= NB_COUPS_MAX && joueurs[1]->nb_coups <= NB_COUPS_MAX);
}
