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
 *  Effectue les testes de la pile.
 *
 */

#include <stdio.h>
#include <stdlib.h>

#include "pile.h"
#include "liste_liee.h"

/**
 * \brief Teste de la pile
 */
int main()
{
    pile* pile1;
    pile* pile2;
    pile1 = creer_pile();
    if(pile1) {
        printf("Pile creee.\n");
        ajouter_pile(pile1, 42);
        ajouter_pile(pile1, 420);
        ajouter_pile(pile1, 1337);
        retirer_pile(pile1);
        remplacer_pile(pile1, 1);
        printf("La taille est %d\n", taille_pile(pile1));
        if (a_erreur_pile(pile1)) {
            printf("Ne peut remplacer l'element %s\n",
                                        erreur_pile(pile1));
        }
        sauvegarder_pile(pile1, "test_pile.bin");
        detruire_pile(pile1);
        pile2 = charger_pile("test_pile.bin");
        if (pile2) {
            if (a_erreur_pile(pile2)) {
                printf("Ne peut charger le fichier 'test_pile.bin': %s\n",
                                                erreur_pile(pile2));
            } else {
                if (a_erreur_pile(pile2)) {
                    printf("Erreur lors de la sauvegarde de la pile: %s\n",
                                                erreur_pile(pile2));
                }
                remplacer_pile(pile2, 2);
                if (a_erreur_pile(pile2)) {
                    printf("Ne peut remplacer l'element %s\n",
                                                erreur_pile(pile2));
                }
                printf("L'element sur le dessus de la pile est %d.\n",
                       element_pile(pile2));
            }
            detruire_pile(pile2);
        } else {
            printf("Une erreur s'est produite");
        }
    } else {
        printf("Une erreur s'est produite");
    }
    return 0;
}
