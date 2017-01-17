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
 *  \file file.h
 *
 *  Fichier d'entête contenant la structure de donnée 'file'.
 *  Une File est une liste ayant comme principe que le
 *  premier élément ajouté est aussi le premier retiré.
 *
 */

#ifndef _file_h
#define _file_h

#include "liste_liee.h"
#include <stdbool.h>

/**
 * \brief Une liste de type File.
 */
typedef liste_liee file;


/**
 *  \brief Créer une nouvelle file.
 *
 *  \return La file
 */
file* creer_file(void);

/**
 *  \brief Créer une nouvelle file depuis un fichier.
 *
 *  Créer une nouvelle file et charge le contenue du fichier
 *  'nom_fichier' dans la file. Si le fichier n'est pas valide, indique
 *  l'erreur dans 'file'->'erreur'.
 *
 *  \param nom_fichier : Le nom du fichier contenant la file
 *
 *  \return La file
 */
file* charger_file(char *nom_fichier);

/**
 *  \brief Effectue la désallocation d'une file.
 *
 *  \param file : La file à désalloué.
 */
void detruire_file(file* file);

/**
 *  \brief Sauvegarder la file dans un fichier.
 *
 *  Sauvegarde le contenue de la 'file' dans le fichier 'nom_fichier'.
 *  Si le fichier n'est pas valide, indique l'erreur dans 'file'->'erreur'.
 *
 *  \param file : La file à sauvegarder un élément
 *  \param nom_fichier : Le nom du fichier à sauvegarder la file.
 *
 *  \note 'file' ne doit pas être NULL.
 */
void sauvegarder_file(file* file, char *nom_fichier);

/**
 *  \brief Renvoie la taille de la 'file'.
 *
 *  \return La taille de la 'file'.
 *
 *  \note 'file' ne doit pas être NULL.
 */
int taille_file(file* file);

/**
 *  \brief Ajouter un nouvel élément à une file.
 *
 *  Ajoute à la 'file' l''element' reçu en argument.
 *  La taille de la 'file' est augmenté de 1.
 *
 *  \param file : La file à ajouter l'élément
 *  \param element : L'élément à ajouter à la 'file'
 *
 *  \note 'file' ne doit pas être NULL.
 */
void ajouter_file(file* file, int element);

/**
 *  \brief Renvoie l'élément qui est sur le dessus de la 'file'.
 *
 *  Retourne l'élément stocké sur le dessus de la 'file'
 *  Sinon, indique l'erreur dans 'file'->'erreur'.
 *  Dans ce dernier cas, la valeur 0 est retourné.
 *
 *  \param file : La file contenant l'élément.
 *
 *  \return L'élément à la position 'index' dans la 'file'
 *
 *  \note 'file' ne doit pas être NULL.
 */
int element_file(file* file);

/**
 *  \brief Retire l'élément sur le dessus de la 'file'.
 *
 *  \param file : La file à retirer un élément.
 *
 *  \note 'file' ne doit pas être NULL.
 */
void retirer_file(file* file);

/**
 *  \brief Remplacer l'élément sur le dessus de la 'file' par 'element'.
 *
 *  Remplace l'élément contenue sur le dessus de la 'file'
 *  par un nouveau 'element'.
 *
 *  \param file : La file à remplacer un 'element'.
 *  \param element : L'élément à placer dans la 'file'.
 *
 *  \note 'file' ne doit pas être NULL.
 */
void remplacer_file(file* file, int element);

/**
 *  \brief Indique si la 'file' contient une erreur.
 *
 *  \return Vrai si la 'file' contient une erreur, Faux sinon.
 *
 *  \note 'file' ne doit pas être NULL.
 */
bool a_erreur_file(file* file);

/**
 *  \brief Indique le texte de l'erreur contenue dans 'file'.
 *
 *  Si 'a_erreur_file' indique que la 'file' contient une erreur,
 *  retourne l'erreur qu'elle contient. Si 'a_erreur_file' est Faux,
 *  retourne une chaine vide.
 *
 *  \return Le texte de l'erreur.
 *
 *  \note 'file' ne doit pas être NULL.
 */
char* erreur_file(file* file);

/**
 *  \brief Inscrit l'erreur dans la 'file'.
 *
 *  \param erreur : Le texte de l'erreur.
 *
 *  \note 'file' ne doit pas être NULL.
 */
void inscrire_erreur_file(file* file, const char* erreur);

/**
 *  \brief Retire tout erreur dans la 'file'.
 *
 *  \note 'file' ne doit pas être NULL.
 */
void retirer_erreur_file(file* file);

#endif // _file_h

/* vi: set ts=4 sw=4 expandtab: */
