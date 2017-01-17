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
 *  \file file.h
 *
 *  Fichier d'ent�te contenant la structure de donn�e 'file'.
 *  Une File est une liste ayant comme principe que le
 *  premier �l�ment ajout� est aussi le premier retir�.
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
 *  \brief Cr�er une nouvelle file.
 *
 *  \return La file
 */
file* creer_file(void);

/**
 *  \brief Cr�er une nouvelle file depuis un fichier.
 *
 *  Cr�er une nouvelle file et charge le contenue du fichier
 *  'nom_fichier' dans la file. Si le fichier n'est pas valide, indique
 *  l'erreur dans 'file'->'erreur'.
 *
 *  \param nom_fichier : Le nom du fichier contenant la file
 *
 *  \return La file
 */
file* charger_file(char *nom_fichier);

/**
 *  \brief Effectue la d�sallocation d'une file.
 *
 *  \param file : La file � d�sallou�.
 */
void detruire_file(file* file);

/**
 *  \brief Sauvegarder la file dans un fichier.
 *
 *  Sauvegarde le contenue de la 'file' dans le fichier 'nom_fichier'.
 *  Si le fichier n'est pas valide, indique l'erreur dans 'file'->'erreur'.
 *
 *  \param file : La file � sauvegarder un �l�ment
 *  \param nom_fichier : Le nom du fichier � sauvegarder la file.
 *
 *  \note 'file' ne doit pas �tre NULL.
 */
void sauvegarder_file(file* file, char *nom_fichier);

/**
 *  \brief Renvoie la taille de la 'file'.
 *
 *  \return La taille de la 'file'.
 *
 *  \note 'file' ne doit pas �tre NULL.
 */
int taille_file(file* file);

/**
 *  \brief Ajouter un nouvel �l�ment � une file.
 *
 *  Ajoute � la 'file' l''element' re�u en argument.
 *  La taille de la 'file' est augment� de 1.
 *
 *  \param file : La file � ajouter l'�l�ment
 *  \param element : L'�l�ment � ajouter � la 'file'
 *
 *  \note 'file' ne doit pas �tre NULL.
 */
void ajouter_file(file* file, int element);

/**
 *  \brief Renvoie l'�l�ment qui est sur le dessus de la 'file'.
 *
 *  Retourne l'�l�ment stock� sur le dessus de la 'file'
 *  Sinon, indique l'erreur dans 'file'->'erreur'.
 *  Dans ce dernier cas, la valeur 0 est retourn�.
 *
 *  \param file : La file contenant l'�l�ment.
 *
 *  \return L'�l�ment � la position 'index' dans la 'file'
 *
 *  \note 'file' ne doit pas �tre NULL.
 */
int element_file(file* file);

/**
 *  \brief Retire l'�l�ment sur le dessus de la 'file'.
 *
 *  \param file : La file � retirer un �l�ment.
 *
 *  \note 'file' ne doit pas �tre NULL.
 */
void retirer_file(file* file);

/**
 *  \brief Remplacer l'�l�ment sur le dessus de la 'file' par 'element'.
 *
 *  Remplace l'�l�ment contenue sur le dessus de la 'file'
 *  par un nouveau 'element'.
 *
 *  \param file : La file � remplacer un 'element'.
 *  \param element : L'�l�ment � placer dans la 'file'.
 *
 *  \note 'file' ne doit pas �tre NULL.
 */
void remplacer_file(file* file, int element);

/**
 *  \brief Indique si la 'file' contient une erreur.
 *
 *  \return Vrai si la 'file' contient une erreur, Faux sinon.
 *
 *  \note 'file' ne doit pas �tre NULL.
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
 *  \note 'file' ne doit pas �tre NULL.
 */
char* erreur_file(file* file);

/**
 *  \brief Inscrit l'erreur dans la 'file'.
 *
 *  \param erreur : Le texte de l'erreur.
 *
 *  \note 'file' ne doit pas �tre NULL.
 */
void inscrire_erreur_file(file* file, const char* erreur);

/**
 *  \brief Retire tout erreur dans la 'file'.
 *
 *  \note 'file' ne doit pas �tre NULL.
 */
void retirer_erreur_file(file* file);

#endif // _file_h

/* vi: set ts=4 sw=4 expandtab: */
