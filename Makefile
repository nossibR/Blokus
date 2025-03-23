# SAE11_2024 : fichier Makefile

# CHAPITRE 1 : BUT FINAL

but : blocus

# CHAPITRE 2 : VARIABLES

OFILES = grille.o\
	 menu.o\
	 fin.o\
	 PvP.o\
	 PvBot.o\
	 definirposition.o\
	 main.o

CC = gcc

CFLAGS = -Wall -ansi -pedantic -g

# CHAPITRE 3 : DEPENDANCES (REGLES IMPLICITES)

main.o : grille.h menu.h PvP.h PvBot.h fin.h

grille.o : grille.h

menu.o : menu.h 

fin.o : fin.h

PvP.o : PvP.h grille.h definirposition.h

PvBot.o : PvBot.h grille.h definirposition.h

definirposition.o : definirposition.h

#CHAPITRE 4 : DEPENDANCES AVEC COMMANDES

blocus : $(OFILES)
	$(CC) $(CFLAGS) -o blocus $(OFILES) -lgraph

#CHAPITRE 5 : NETTOYAGE DES FICHIERS GENERES

clean :
	-rm -f $(OFILES) blocus

#CHAPITRE 6 : BUTS FACTICES

.PHONY : but clean

run :
	./blocus
