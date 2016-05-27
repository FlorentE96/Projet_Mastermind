

zero_joueur : affichage.o Dictionary.o fonctions.o gestion_jeu.o main.o tests.o zero_joueur.o
	gcc  affichage.o Dictionary.o fonctions.o gestion_jeu.o main.o tests.o zero_joueur.o -o zero_joueur


affichage.o: affichage.c
	gcc -c -Wall -std=c99   affichage.c

Dictionary.o: Dictionary.c
	gcc -c -Wall -std=c99   Dictionary.c

fonctions.o: fonctions.c fonctions.h
	gcc -c -Wall -std=c99   fonctions.c

gestion_jeu.o: gestion_jeu.c fonctions.h
	gcc -c -Wall -std=c99   gestion_jeu.c

main.o: main.c fonctions.h zero_joueur.h
	gcc -c -Wall -std=c99   main.c

tests.o: tests.c
	gcc -c -Wall -std=c99   tests.c

zero_joueur.o: zero_joueur.c fonctions.h zero_joueur.h
	gcc -c -Wall -std=c99   zero_joueur.c


clean :
	rm *.o

