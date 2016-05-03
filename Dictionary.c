int nb_combi_dict(FILE * dict) 
// compte le nb de combinaisons dans le dictionnaire
{
  char line[100] = "";
  int nb_line = 0;
  while(!feof(dict))
    {
      fgets(line, 100, dict);
      if(line[0] != ' ' && line[0] != '#' && line[0] != '') nb_line ++;
    }
  
  rewind(dict);
  return nb_line;
}


int random_number(FILE * dict)
// prend en argument le nb de combi dans le dictionnaire et retourne en nombre aléatoire compris entre 0 et nb_combi_dict - 1
{
  int rand_numb = rand() % nb_combi_dict(dict); //fnt dans stdlib.h
  return rand_numb;
}


void get_combi_dict(FILE * dict, int * combi)
{
  char line[100] = "";
  int line_count = 0;
  while(line_count != random_number(dict) + 1)
    {
      if(line[0] != ' ' && line[0] != '#' && line[0] != '') line_count++;    
      fgets(line, 100, dict);
    }
  
  
}
