# DevCommeLesPros-2020-Ex2-Extra

Modèle de départ pour exercices bonus compétitifs 4 et 5.

## Instructions de départ

Ces intructions présupposent que vous avez déjà suivi les instructions de l'[exercice précédent](https://github.com/thierryseegers/DevCommeLesPros-2020-Ex1#instructions-de-d%C3%A9part) pour la création de compte et l'installation des programmes et extensions nécéssaires.

1. Créez votre dépôt sur github.com en utilisant ce dépôt-ci (https://github.com/thierryseegers/DevCommeLesPros-2020-Ex2-Extra) comme modèle.
    - Suivez ces instructions: https://help.github.com/en/github/creating-cloning-and-archiving-repositories/creating-a-repository-from-a-template.
    - Choisissez l'option `Private` à l'étape 5.
1. Ajoutez le professeur comme collaborateur à votre dépôt.
    - Suivez ces instructions: https://help.github.com/en/github/setting-up-and-managing-your-github-user-account/inviting-collaborators-to-a-personal-repository
        - Nom d'utilisateur à ajouter: `thierryseegers`.
1. Clonez votre dépôt vers votre espace de travail local.
    - Suivez ces instructions: https://help.github.com/en/github/creating-cloning-and-archiving-repositories/cloning-a-repository
    - Attention à ne pas cloner https://github.com/thierryseegers/DevCommeLesPros-2020-Ex2-Extra mais bien votre dépôt nouvellement créé.
1. Lancez Visual Studio Code.
    - À l'invite de commandes:
        - `> cd [nom de votre dépôt]`
        - `> code .`

## Objectif bonus 4 (compétitif)

Coup de chance ! Vous avez intercepté un message clair et son équivalent chiffré par la méthode Vigenère.
Avec ces deux messages en main, vous pouvez procéder à une [attaque à texte clair connu](https://fr.wikipedia.org/wiki/Attaque_%C3%A0_texte_clair_connu) 
pour récupérer la clé utilisée lors du chiffrement et pouvoir déchiffrer d'autres messages chiffrés avec la même clé.

Attention : analyser les messages à la main pour en récupérer la clé est faisable mais ce n'est le but de l'exercice.
Il faut que ce soit votre programme qui puisse révéler la clé.

1. Implémenter les fonctions `analyse_Vigenere_flux_texte` et `dechiffre_Vigenere_flux_texte`.
1. Analysez les messages `message_Vigenere_clair_connu.txt` et `message_Vigenere_chiffre_connu.txt` pour récupérer la clé de chiffrement. La clé est un mot français sans accent.
    - `> ./build/analyse -V -l message_Vigenere_clair_connu.txt -h message_Vigenere_chiffre_connu.txt`
    - Le programme doit afficher la clé.
1. Déchiffer le message `message_Vigenere_chiffre_secret.txt` avec la clé obtenue précédemment.
    - `> ./build/dechiffre -V -c [clé] < message_Vigenere_chiffre_secret.txt`.
    - Le programme doit afficher le texte en clair.
1. Publiez votre code à votre dépôt sur github.com.
1. Envoyez un e-mail au professeur (thierry.seegers@yahoo.com) avec la clé et l'auteur du texte dans le message secret.

Ce bonus est sans limite de temps.

Programme de (dé)chiffrement par Vigenère en ligne : https://planetcalc.com/2468/

## Objectif bonus 5 (compétitif)

Coup de chance ! Vous avez intercepté un message clair et son équivalent chiffré par la méthode [Playfair](https://fr.wikipedia.org/wiki/Chiffre_de_Playfair).
Avec ces deux messages en main, vous pouvez procéder à une [attaque à texte clair connu](https://fr.wikipedia.org/wiki/Attaque_%C3%A0_texte_clair_connu) 
pour récupérer la clé utilisée lors du chiffrement et pouvoir déchiffrer d'autres messages chiffrés avec la même clé.

Attention : analyser les messages à la main pour en récupérer la clé est faisable mais ce n'est le but de l'exercice.
Il faut que ce soit votre programme qui puisse révéler la clé.

1. Implémenter les fonctions `analyse_Playfair_flux_texte` et `dechiffre_Playfair_flux_texte`.
1. Analysez les messages `message_Playfair_clair_connu.txt` et `message_Playfair_chiffre_connu.txt` pour récupérer la clé de chiffrement. La clé est un mot français sans accent.
    - `> ./build/analyse -V -l message_Playfair_clair_connu.txt -h message_Playfair_chiffre_connu.txt`
    - Le programme doit afficher la clé.
1. Déchiffer le message `message_Playfair_chiffre_secret.txt` avec la clé obtenue précédemment.
    - `> ./build/dechiffre -V -c [clé] < message_Playfair_chiffre_secret.txt`.
    - Le programme doit afficher le texte en clair.
1. Publiez votre code à votre dépôt sur github.com.
1. Envoyez un e-mail au professeur (thierry.seegers@yahoo.com) avec la clé et l'auteur du texte dans le message secret.

Ce bonus est sans limite de temps.

Programme de (dé)chiffrement par Playfair en ligne : https://planetcalc.com/7751/

## Évaluation

Seul le code de la branche `master` de votre dépôt sur http://github.com compte !
