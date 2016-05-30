#include <stdio.h>
#include <getopt.h>
#include <string.h>
#include "affichage.h"
#include "fonctions.h"

int main (int argc, char * argv[])
{
//    get_gnuplot_trace_algo_1();
//    get_average_value_algo_1();
    
//    struct Joueur joueur_1;
//    srand(time(NULL));
//
//    for(int i = 0; i < 10; i ++)
//    {
//        combi_rand(&joueur_1);
//        printf("la combi est : ");
//        print_array_n(joueur_1.combi_a_trouver, NB_PIONS);
//    }

    
//    int combinaison[4] = {1, 2, 1, 4};
//    test_algo_1(combinaison);
    
//    struct Joueur ordi;
//    init_player_keep_score(&ordi);
//    zero_joueur(&ordi);
  int opt, menu=0, nb_joueurs, dict_mode=0;
  if (argc<=1)
    menu = 1;
  while((opt = getopt(argc, argv, "012dh:")) != -1)
    {
      switch(opt)
	{
	case '0':
	  nb_joueurs = 0;
	  break;
	case '1':
	  nb_joueurs = 1;
	  break;
	case '2':
	  nb_joueurs = 2;
	  break;
	case 'd':
	  dict_mode = 1;
	  break;
	case 'h':
	  help();
	  break;
	}
	  
    }
  Mastermind(menu, nb_joueurs, dict_mode);
  return 0;
}
