#pragma once

#include <stdio.h>

// Déchiffre un flux de texte vers un autre flux suivant l'algorithme décrit ici: https://fr.wikipedia.org/wiki/Chiffre_de_Vigen%C3%A8re.
// La clé doit être une chaîne de caractères compris entre 'a' et 'z'.
// Seuls les caractères de 'a' à 'z' et de 'A' à 'Z' de la chaîne seront chiffrés ou déchiffrés.
void dechiffre_Vigenere_flux_texte(FILE* clair, FILE* chiffre, char const* cle);

// Analyse un fichier clair et ce même ficher chiffré par Vigenère pour retrouver la clé qui à été utilisée.
// Retourne la clé.
char* analyse_Vigenere_flux_texte(FILE* clair, FILE* chiffre);
