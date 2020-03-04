#include "chiffrage.h"

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    char chemin_clair[1024] = {'\0'};
    char chemin_chiffre[1024] = {'\0'};
    bool Vigenere = true;

    // Décodage des paramètres.
    // -l chemin_clair      obligatoire, chemin du ficher en clair.
    // -h chemin_chiffré    obligatoire, chemin du ficher chiffré.
    // -P                   optionel, utilise la méthode Playfair de déchiffrement. Ne peut être combinée avec -V.
    // -V                   optionel, utilise la méthode Vigenère de déchiffrement. Ne peut être combinée avec -P.
    int opt;
    while((opt = getopt(argc, argv, "l:h:PV")) != -1)
    {
        switch(opt)
        {
            case 'l':
                strcpy(chemin_clair, optarg);
                break;
            case 'h':
                strcpy(chemin_chiffre, optarg);
                break;
            case 'P':
                Vigenere = false;
                break;
            case 'V':
                Vigenere = true;
                break;
            default:
                fprintf(stderr, "Usage: %s [-P] [-V] -l chemin_clair -h chemin_chiffre\n", argv[0]);
                return EXIT_FAILURE;
        }
    }

    if(!chemin_clair[0] || !chemin_chiffre[0]) // Paramètre "-l chemin_clair" ou "-h chemin_chiffre" manquant.
    {
        fprintf(stderr, "Usage: %s [-P] [-V] -l chemin_clair -h chemin_chiffre\n", argv[0]);
        return EXIT_FAILURE;
    }

    if(Vigenere)
    {
        FILE *clair = fopen(chemin_clair, "r");
        FILE *chiffre = fopen(chemin_chiffre, "r");
        printf("%s\n", analyse_Vigenere_flux_texte(clair, chiffre));
        fclose(chiffre);
        fclose(clair);
    }
    else
    {
        FILE *clair = fopen(chemin_clair, "r");
        FILE *chiffre = fopen(chemin_chiffre, "r");
        printf("%s\n", analyse_Playfair_flux_texte(clair, chiffre));
        fclose(chiffre);
        fclose(clair);
    }

    return EXIT_SUCCESS;
}
