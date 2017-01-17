/*

    Copyright (c) 2015 Nicolas Bisson

    L'autorisation est accordée, gracieusement, à toute personne acquérant une
    copie de cette bibliothèque et des fichiers de documentation associés
    (la "Bibliothèque"), de commercialiser la Bibliothèque sans restriction,
    notamment les droits d'utiliser, de copier, de modifier, de fusionner, de
    publier, de distribuer, de sous-licencier et / ou de vendre des copies de
    la Bibliothèque, ainsi que d'autoriser les personnes auxquelles la
    Bibliothèque est fournie à le faire, sous réserve des conditions suivantes:

    La déclaration de copyright ci-dessus et la présente autorisation doivent
    être incluses dans toutes copies ou parties substantielles de la
    Bibliothèque.

    LA BIBLIOTHÈQUE EST FOURNIE "TELLE QUELLE", SANS GARANTIE D'AUCUNE SORTE,
    EXPLICITE OU IMPLICITE, NOTAMMENT SANS GARANTIE DE QUALITÉ MARCHANDE,
    D’ADÉQUATION À UN USAGE PARTICULIER ET D'ABSENCE DE CONTREFAÇON. EN AUCUN
    CAS, LES AUTEURS OU TITULAIRES DU DROIT D'AUTEUR NE SERONT RESPONSABLES DE
    TOUT DOMMAGE, RÉCLAMATION OU AUTRE RESPONSABILITÉ, QUE CE SOIT DANS LE
    CADRE D'UN CONTRAT, D'UN DÉLIT OU AUTRE, EN PROVENANCE DE, CONSÉCUTIF À OU
    EN RELATION AVEC LA BIBLIOTHÈQUE OU SON UTILISATION, OU AVEC D'AUTRES
    ÉLÉMENTS DE LA BIBLIOTHÈQUE.

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
