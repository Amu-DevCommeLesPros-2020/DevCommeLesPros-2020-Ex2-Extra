# La cible par défault sera la cible pour tout construire.
.DEFAULT_GOAL := all

.PHONY: clean


# Liste des cibles.

# Efface tous les fichiers temporaires et les produits finaux.
clean:
	rm -rf build

# Crée le répertoire qui acceuille les fichiers temporaires et les produits finaux (Vigenere.o, Playfair.o, test, etc.).
build:
	mkdir -p build

# Bibliothèque d'analyse et de déchiffrage.
build/Vigenere.o: lib/Vigenere.c | build
	gcc -Wall -pedantic -g -c lib/Vigenere.c -I ./lib -o build/Vigenere.o

build/Playfair.o: lib/Playfair.c | build
	gcc -Wall -pedantic -g -c lib/Playfair.c -I ./lib -o build/Playfair.o

build/libchiffrage.a: build/Vigenere.o build/Playfair.o | build
	ar crs build/libchiffrage.a build/Vigenere.o build/Playfair.o

# Programme de déchiffrage. Trois cibles, une pour compiler le code en fichier objet, une pour lier le fichier objet avec la
# bibliothèque statique de chiffrage et une dernière de "commodité" pour faire plus court à l'invite de commandes.
build/dechiffre.o: bin/dechiffre.c | build
	gcc -Wall -pedantic -g -c bin/dechiffre.c -I ./lib -o build/dechiffre.o

build/dechiffre: build/dechiffre.o build/libchiffrage.a | build
	gcc build/dechiffre.o -Lbuild -lchiffrage -o build/dechiffre

dechiffre: build/dechiffre

# Programme d'analyse. Trois cibles, une pour compiler le code en fichier objet, une pour lier le fichier objet avec la
# bibliothèque statique de chiffrage et une dernière de "commodité" pour faire plus court à l'invite de commandes.
build/analyse.o: bin/analyse.c | build
	gcc -Wall -pedantic -g -c bin/analyse.c -I ./lib -o build/analyse.o

build/analyse: build/analyse.o build/libchiffrage.a | build
	gcc build/analyse.o -Lbuild -lchiffrage -o build/analyse

analyse: build/analyse

# Cible pour construire tout les programmes.
all: dechiffre analyse
