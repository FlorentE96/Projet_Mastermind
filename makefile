main : fonctions.o zero_joueur.o main.o
	gcc fonctions.o main.o zero_joueur.o -o main

fonctions.o: fonctions.c fonctions.h
	gcc -c -Wall -std=c99   fonctions.c

main.o: main.c fonctions.h zero_joueur.h
	gcc -c -Wall -std=c99   main.c

zero_joueur.o: zero_joueur.c fonctions.h zero_joueur.h
	gcc -c -Wall -std=c99   zero_joueur.c

clean :
	rm *.o