#include "chiffrage.h"

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    char cle[1024] = {'\0'};
    bool Vigenere = true;

    // Décodage des paramètres.
    // -c mot      obligatoire, utilise "mot" comme clé de déchiffrage. Longueur maximum 1023 caractères.
    // -P          Utilise la méthode Playfair de déchiffrement. Ne peut être combiné avec -V.
    // -V          Utilise la méthode Vigenère de déchiffrement. Ne peut être combiné avec -P.
    int opt;
    while((opt = getopt(argc, argv, "c:PV")) != -1)
    {
        switch(opt)
        {
            case 'c':
                strcpy(cle, optarg);
                break;
            case 'P':
                Vigenere = false;
                break;
            case 'V':
                Vigenere = true;
                break;
            default:
                fprintf(stderr, "Usage: %s [-P] [-V] -c clé\n", argv[0]);
                return EXIT_FAILURE;
        }
    }

    if(!cle[0]) // Paramètre "-c clé" manquant.
    {
        fprintf(stderr, "Usage: %s [-P] [-V] -c clé\n", argv[0]);
        return EXIT_FAILURE;
    }

    if(Vigenere)
    {
        dechiffre_Vigenere_flux_texte(stdout, stdin, cle);
    }
    else
    {
        dechiffre_Playfair_flux_texte(stdout, stdin, cle);
    }

    return EXIT_SUCCESS;
}
