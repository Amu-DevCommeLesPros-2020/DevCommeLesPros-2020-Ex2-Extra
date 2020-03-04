#pragma once

#include <stdio.h>

// Déchiffre un flux de texte vers un autre flux suivant l'algorithme décrit ici: https://fr.wikipedia.org/wiki/Chiffre_de_Playfair.
// La clé doit être une chaîne de caractères compris entre 'a' et 'z'.
// Seuls les caractères de 'a' à 'z' et de 'A' à 'Z' de la chaîne seront chiffrés ou déchiffrés.
void dechiffre_Playfair_flux_texte(FILE* clair, FILE* chiffre, char const* cle);

// Analyse un fichier clair et ce même ficher chiffré par Playfair pour retrouver la clé qui à été utilisée.
// Retourne la clé.
char* analyse_Playfair_flux_texte(FILE* clair, FILE* chiffre);
