/*

    Copyright (c) 2015 Nicolas Bisson

    L'autorisation est accord�e, gracieusement, � toute personne acqu�rant une
    copie de cette biblioth�que et des fichiers de documentation associ�s
    (la "Biblioth�que"), de commercialiser la Biblioth�que sans restriction,
    notamment les droits d'utiliser, de copier, de modifier, de fusionner, de
    publier, de distribuer, de sous-licencier et / ou de vendre des copies de
    la Biblioth�que, ainsi que d'autoriser les personnes auxquelles la
    Biblioth�que est fournie � le faire, sous r�serve des conditions suivantes:

    La d�claration de copyright ci-dessus et la pr�sente autorisation doivent
    �tre incluses dans toutes copies ou parties substantielles de la
    Biblioth�que.

    LA BIBLIOTH�QUE EST FOURNIE "TELLE QUELLE", SANS GARANTIE D'AUCUNE SORTE,
    EXPLICITE OU IMPLICITE, NOTAMMENT SANS GARANTIE DE QUALIT� MARCHANDE,
    D�AD�QUATION � UN USAGE PARTICULIER ET D'ABSENCE DE CONTREFA�ON. EN AUCUN
    CAS, LES AUTEURS OU TITULAIRES DU DROIT D'AUTEUR NE SERONT RESPONSABLES DE
    TOUT DOMMAGE, R�CLAMATION OU AUTRE RESPONSABILIT�, QUE CE SOIT DANS LE
    CADRE D'UN CONTRAT, D'UN D�LIT OU AUTRE, EN PROVENANCE DE, CONS�CUTIF � OU
    EN RELATION AVEC LA BIBLIOTH�QUE OU SON UTILISATION, OU AVEC D'AUTRES
    �L�MENTS DE LA BIBLIOTH�QUE.

*/

/**
 *  \file main.c
 *
 *  Effectue les testes de la file.
 *
 */

#include <stdio.h>
#include <stdlib.h>

#include "file.h"
#include "liste_liee.h"

/**
 * \brief Teste de la file
 */
int main()
{
    file* file1;
    file* file2;
    file1 = creer_file();
    if(file1) {
        printf("File creee.\n");
        ajouter_file(file1, 42);
        ajouter_file(file1, 420);
        ajouter_file(file1, 1337);
        retirer_file(file1);
        remplacer_file(file1, 1);
        printf("La taille est %d\n", taille_file(file1));
        if (a_erreur_file(file1)) {
            printf("Ne peut remplacer l'element %s\n",
                                        erreur_file(file1));
        }
        sauvegarder_file(file1, "test_file.bin");
        detruire_file(file1);
        file2 = charger_file("test_file.bin");
        if (file2) {
            if (a_erreur_file(file2)) {
                printf("Ne peut charger le fichier 'test_file.bin': %s\n",
                                                erreur_file(file2));
            } else {
                if (a_erreur_file(file2)) {
                    printf("Erreur lors de la sauvegarde de la file: %s\n",
                                                erreur_file(file2));
                }
                remplacer_file(file2, 2);
                if (a_erreur_file(file2)) {
                    printf("Ne peut remplacer l'element %s\n",
                                                erreur_file(file2));
                }
                printf("L'element sur le dessus de la file est %d.\n",
                       element_file(file2));
            }
            detruire_file(file2);
        } else {
            printf("Une erreur s'est produite");
        }
    } else {
        printf("Une erreur s'est produite");
    }
    return 0;
}
