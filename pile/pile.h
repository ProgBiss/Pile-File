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
 *  \file pile.h
 *
 *  Fichier d'entête contenant la structure de donnée 'pile'.
 *  Une Pile est une liste ayant comme principe que le
 *  dernier élément ajouté est aussi le premier retiré.
 *
 */

#ifndef _pile_h
#define _pile_h


#include "liste_liee.h"
#include <stdbool.h>

/**
 * \brief Une liste de type Pile.
 */
typedef liste_liee pile;


/**
 *  \brief Créer une nouvelle pile.
 *
 *  \return La pile
 */
pile* creer_pile(void);

/**
 *  \brief Créer une nouvelle pile depuis un fichier.
 *
 *  Créer une nouvelle pile et charge le contenue du fichier
 *  'nom_fichier' dans la pile. Si le fichier n'est pas valide, indique
 *  l'erreur dans 'pile'->'erreur'.
 *
 *  \param nom_fichier : Le nom du fichier contenant la pile
 *
 *  \return La pile
 */
pile* charger_pile(char *nom_fichier);

/**
 *  \brief Effectue la désallocation d'une pile.
 *
 *  \param pile : La pile à désalloué.
 */
void detruire_pile(pile* pile);

/**
 *  \brief Sauvegarder la pile dans un fichier.
 *
 *  Sauvegarde le contenue de la 'pile' dans le fichier 'nom_fichier'.
 *  Si le fichier n'est pas valide, indique l'erreur dans 'pile'->'erreur'.
 *
 *  \param pile : La pile à sauvegarder un élément
 *  \param nom_fichier : Le nom du fichier à sauvegarder la pile.
 *
 *  \note 'pile' ne doit pas être NULL.
 */
void sauvegarder_pile(pile* pile, char *nom_fichier);

/**
 *  \brief Renvoie la taille de la 'pile'.
 *
 *  \return La taille de la 'pile'.
 *
 *  \note 'pile' ne doit pas être NULL.
 */
int taille_pile(pile* pile);

/**
 *  \brief Ajouter un nouvel élément à une pile.
 *
 *  Ajoute à la 'pile' l''element' reçu en argument.
 *  La taille de la 'pile' est augmenté de 1.
 *
 *  \param pile : La pile à ajouter l'élément
 *  \param element : L'élément à ajouter à la 'pile'
 *
 *  \note 'liste' ne doit pas être NULL.
 */
void ajouter_pile(pile* pile, int element);

/**
 *  \brief Renvoie l'élément qui est sur le dessus de la 'pile'.
 *
 *  Retourne l'élément stocké sur le dessus de la 'pile'
 *  Sinon, indique l'erreur dans 'pile'->'erreur'.
 *  Dans ce dernier cas, la valeur 0 est retourné.
 *
 *  \param pile : La pile contenant l'élément.
 *
 *  \return L'élément à la position 'index' dans la 'pile'
 *
 *  \note 'pile' ne doit pas être NULL.
 */
int element_pile(pile* pile);

/**
 *  \brief Retire l'élément sur le dessus de la 'pile'.
 *
 *  \param pile : La pile à retirer un élément.
 *
 *  \note 'pile' ne doit pas être NULL.
 */
void retirer_pile(pile* pile);

/**
 *  \brief Remplacer l'élément sur le dessus de la 'pile' par 'element'.
 *
 *  Remplace l'élément contenue sur le dessus de la 'pile'
 *  par un nouveau 'element'.
 *
 *  \param pile : La pile à remplacer un 'element'.
 *  \param element : L'élément à placer dans la 'pile'.
 *
 *  \note 'pile' ne doit pas être NULL.
 */
void remplacer_pile(pile* pile, int element);

/**
 *  \brief Indique si la 'pile' contient une erreur.
 *
 *  \return Vrai si la 'pile' contient une erreur, Faux sinon.
 *
 *  \note 'pile' ne doit pas être NULL.
 */
bool a_erreur_pile(pile* pile);

/**
 *  \brief Indique le texte de l'erreur contenue dans 'pile'.
 *
 *  Si 'a_erreur_pile' indique que la 'pile' contient une erreur,
 *  retourne l'erreur qu'elle contient. Si 'a_erreur_pile' est Faux,
 *  retourne une chaine vide.
 *
 *  \return Le texte de l'erreur.
 *
 *  \note 'pile' ne doit pas être NULL.
 */
char* erreur_pile(pile* pile);

/**
 *  \brief Inscrit l'erreur dans la 'pile'.
 *
 *  \param erreur : Le texte de l'erreur.
 *
 *  \note 'pile' ne doit pas être NULL.
 */
void inscrire_erreur_pile(pile* pile, const char* erreur);

/**
 *  \brief Retire tout erreur dans la 'pile'.
 *
 *  \note 'pile' ne doit pas être NULL.
 */
void retirer_erreur_pile(pile* pile);

#endif // _pile_h

/* vi: set ts=4 sw=4 expandtab: */
