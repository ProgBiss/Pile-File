/*

    Copyright (c) 2015 Louis Marchand

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
 *  Effectue les testes de la liste liée.
 *
 */

#include <stdio.h>
#include <stdlib.h>

#include "liste_liee.h"

/**
 * \brief Teste de la liste liée
 */
int main()
{
    int i;
    liste_liee* l_liste1;
    liste_liee* l_liste2;
    l_liste1 = creer_liste_liee();
    if(l_liste1)
    {
		printf("Allo");
        printf("Liste créée.\n");
        ajouter_liste_liee(l_liste1, 9);
        ajouter_liste_liee(l_liste1, 8);
        ajouter_liste_liee(l_liste1, 7);
        inserer_liste_liee(l_liste1, 0, 1);
        inserer_liste_liee(l_liste1, 2, 2);
        retirer_liste_liee(l_liste1, 3);
        remplacer_liste_liee(l_liste1, 0, 3);
        if (a_erreur_liste_liee(l_liste1)) {
            printf("Ne peut remplacer l'élément à l'index 3: %s\n",
                                                erreur_liste_liee(l_liste1));
        }
        sauvegarder_liste_liee(l_liste1, "test.bin");
        detruire_liste_liee(l_liste1);
        l_liste2 = charger_liste_liee("test.bin");
        if (l_liste2) {
            if (a_erreur_liste_liee(l_liste2)) {
                printf("Ne peut charger le fichier 'test.bin': %s\n",
                                                erreur_liste_liee(l_liste2));
            } else {
                if (a_erreur_liste_liee(l_liste2)) {
                    printf("Erreur lors de la sauvegarde de la liste: %s\n",
                                                erreur_liste_liee(l_liste2));
                }
                remplacer_liste_liee(l_liste2, 4, 3);
                if (a_erreur_liste_liee(l_liste2)) {
                    printf("Ne peut remplacer l'élément à l'index 4: %s\n",
                                                erreur_liste_liee(l_liste2));
                }
                for(i = 0; i < taille_liste_liee(l_liste2); i = i + 1)
                {
                    printf("L'élément à l'index %d de la liste est %d.\n", i,
                                            element_liste_liee(l_liste2, i));
                }
            }
            detruire_liste_liee(l_liste2);
        } else {
            printf("Une erreur s'est produite");
        }
    }
    else
    {
        printf("Une erreur s'est produite");
    }
    return 0;
}
