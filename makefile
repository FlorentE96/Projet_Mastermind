mmind : affichage.o Dictionary.o fonctions.o gestion_jeu.o zero_joueur.o main.o
	gcc  affichage.o Dictionary.o fonctions.o gestion_jeu.o zero_joueur.o main.o -o mmind

affichage.o: affichage.c fonctions.h gestion_jeu.h zero_joueur.h affichage.h
	gcc -c -Wall -std=c99   affichage.c

Dictionary.o: Dictionary.c
	gcc -c -Wall -std=c99   Dictionary.c

fonctions.o: fonctions.c fonctions.h
	gcc -c -Wall -std=c99   fonctions.c

gestion_jeu.o: gestion_jeu.c fonctions.h gestion_jeu.h
	gcc -c -Wall -std=c99   gestion_jeu.c

main.o: main.c affichage.h fonctions.h
	gcc -c -Wall -std=c99   main.c

zero_joueur.o: zero_joueur.c fonctions.h zero_joueur.h
	gcc -c -Wall -std=c99   zero_joueur.c


clean :
	rm -f *.o
#supprime tous les .o générés seulement s'ils existent

cleanTempFiles :
	rm -f *# *~
# Supprime les fichiers temporaires s'ils existent
