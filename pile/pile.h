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
 *  \file pile.h
 *
 *  Fichier d'ent�te contenant la structure de donn�e 'pile'.
 *  Une Pile est une liste ayant comme principe que le
 *  dernier �l�ment ajout� est aussi le premier retir�.
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
 *  \brief Cr�er une nouvelle pile.
 *
 *  \return La pile
 */
pile* creer_pile(void);

/**
 *  \brief Cr�er une nouvelle pile depuis un fichier.
 *
 *  Cr�er une nouvelle pile et charge le contenue du fichier
 *  'nom_fichier' dans la pile. Si le fichier n'est pas valide, indique
 *  l'erreur dans 'pile'->'erreur'.
 *
 *  \param nom_fichier : Le nom du fichier contenant la pile
 *
 *  \return La pile
 */
pile* charger_pile(char *nom_fichier);

/**
 *  \brief Effectue la d�sallocation d'une pile.
 *
 *  \param pile : La pile � d�sallou�.
 */
void detruire_pile(pile* pile);

/**
 *  \brief Sauvegarder la pile dans un fichier.
 *
 *  Sauvegarde le contenue de la 'pile' dans le fichier 'nom_fichier'.
 *  Si le fichier n'est pas valide, indique l'erreur dans 'pile'->'erreur'.
 *
 *  \param pile : La pile � sauvegarder un �l�ment
 *  \param nom_fichier : Le nom du fichier � sauvegarder la pile.
 *
 *  \note 'pile' ne doit pas �tre NULL.
 */
void sauvegarder_pile(pile* pile, char *nom_fichier);

/**
 *  \brief Renvoie la taille de la 'pile'.
 *
 *  \return La taille de la 'pile'.
 *
 *  \note 'pile' ne doit pas �tre NULL.
 */
int taille_pile(pile* pile);

/**
 *  \brief Ajouter un nouvel �l�ment � une pile.
 *
 *  Ajoute � la 'pile' l''element' re�u en argument.
 *  La taille de la 'pile' est augment� de 1.
 *
 *  \param pile : La pile � ajouter l'�l�ment
 *  \param element : L'�l�ment � ajouter � la 'pile'
 *
 *  \note 'liste' ne doit pas �tre NULL.
 */
void ajouter_pile(pile* pile, int element);

/**
 *  \brief Renvoie l'�l�ment qui est sur le dessus de la 'pile'.
 *
 *  Retourne l'�l�ment stock� sur le dessus de la 'pile'
 *  Sinon, indique l'erreur dans 'pile'->'erreur'.
 *  Dans ce dernier cas, la valeur 0 est retourn�.
 *
 *  \param pile : La pile contenant l'�l�ment.
 *
 *  \return L'�l�ment � la position 'index' dans la 'pile'
 *
 *  \note 'pile' ne doit pas �tre NULL.
 */
int element_pile(pile* pile);

/**
 *  \brief Retire l'�l�ment sur le dessus de la 'pile'.
 *
 *  \param pile : La pile � retirer un �l�ment.
 *
 *  \note 'pile' ne doit pas �tre NULL.
 */
void retirer_pile(pile* pile);

/**
 *  \brief Remplacer l'�l�ment sur le dessus de la 'pile' par 'element'.
 *
 *  Remplace l'�l�ment contenue sur le dessus de la 'pile'
 *  par un nouveau 'element'.
 *
 *  \param pile : La pile � remplacer un 'element'.
 *  \param element : L'�l�ment � placer dans la 'pile'.
 *
 *  \note 'pile' ne doit pas �tre NULL.
 */
void remplacer_pile(pile* pile, int element);

/**
 *  \brief Indique si la 'pile' contient une erreur.
 *
 *  \return Vrai si la 'pile' contient une erreur, Faux sinon.
 *
 *  \note 'pile' ne doit pas �tre NULL.
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
 *  \note 'pile' ne doit pas �tre NULL.
 */
char* erreur_pile(pile* pile);

/**
 *  \brief Inscrit l'erreur dans la 'pile'.
 *
 *  \param erreur : Le texte de l'erreur.
 *
 *  \note 'pile' ne doit pas �tre NULL.
 */
void inscrire_erreur_pile(pile* pile, const char* erreur);

/**
 *  \brief Retire tout erreur dans la 'pile'.
 *
 *  \note 'pile' ne doit pas �tre NULL.
 */
void retirer_erreur_pile(pile* pile);

#endif // _pile_h

/* vi: set ts=4 sw=4 expandtab: */
