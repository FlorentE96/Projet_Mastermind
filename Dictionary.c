#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Dictionary.h"

// compte le nb de combinaisons dans le dictionnaire
int nb_combi_dict(FILE * dict)
{
  char line[100] = "";
  int nb_line = 0;
  while(!feof(dict))
    {
      fgets(line, 100, dict);
      if(line[0] != ' ' && line[0] != '#' && line[0] != 0) nb_line ++;
    }
  
  rewind(dict);
  return nb_line;
}

// prend en argument le nb de combi dans le dictionnaire et retourne en nombre aléatoire compris entre 0 et nb_combi_dict - 1
int random_number(FILE * dict)
{
    return rand() % nb_combi_dict(dict); //fnt dans stdlib.h
}
