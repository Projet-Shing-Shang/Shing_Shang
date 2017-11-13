# Definitions des cibles particulieres
.PHONY: clean, remove
# Desactivations des regles implicites
.SUFFIXES:

# Creation executable
all: main.o utilitaire.o plateau.o case_plateau.o pion.o joueur.o shing_shang.o
	gcc bin/main.o bin/utilitaire.o bin/plateau.o bin/case_plateau.o bin/pion.o bin/joueur.o bin/shing_shang.o -o bin/Shing-Shang

# Regles edition des liens
main.o: src/main.c
		gcc -I include/ -c src/main.c -o bin/main.o

utilitaire.o: src/utilitaire.c include/utilitaire.h
	gcc -I include/ -c src/utilitaire.c -o bin/utilitaire.o

plateau.o: src/plateau.c include/plateau.h
	gcc -I include/ -c src/plateau.c -o bin/plateau.o

case_plateau.o: src/case_plateau.c include/case_plateau.h
	gcc -I include/ -c src/case_plateau.c -o bin/case_plateau.o

pion.o: src/pion.c include/pion.h
	gcc -I include/ -c src/pion.c -o bin/pion.o

joueur.o: src/joueur.c include/joueur.h
	gcc -I include/ -c src/joueur.c -o bin/joueur.o

shing_shang.o: src/shing_shang.c include/shing_shang.h
	gcc -I include/ -c src/shing_shang.c -o bin/shing_shang.o

# Regles de nettoyages
clean:
	rm -rf bin/*.bak rm -rf bin/*.o

remove:
	rm -rf bin/*
