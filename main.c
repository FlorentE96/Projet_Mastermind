#include <stdio.h>
#include <getopt.h>
#include <string.h>
#include "affichage.h"
#include "fonctions.h"

int main (int argc, char * argv[])
{
  int opt, menu=0, nb_joueurs, dict_mode=0;
  FILE * dico;
  if (argc<=1)
    menu = 1;
  while((opt = getopt(argc, argv, "012d:h")) != -1)
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
	  dico = fopen(optarg, "r");
	  if(dico == NULL){
	    printf("impossible d'ouvrir le dictionnaire. Le jeu sera lancé en mode normal. Continuer.\n");
	    flush();
	    getchar();
	    dict_mode = 0;
	  }
	  break;
	case 'h':
	  help();
	  break;
	}
	  
    }
  Mastermind(menu, nb_joueurs, dict_mode, dico);
  if(dict_mode == 1)
    fclose(dico);
}
