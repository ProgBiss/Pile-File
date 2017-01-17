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
 *  \file file.c
 *
 *  Fichier d'implémentation contenant la structure de donnée 'file'.
 *  Une File est une liste ayant comme principe que le
 *  premier élément ajouté est aussi le premier retiré.
 *
 */

#include "file.h"

/**
 *  \brief Créer une nouvelle file.
 *
 *  \return La file
 */
file* creer_file(void)
{
    return creer_liste_liee();
}

/**
 *  \brief Créer une nouvelle file depuis un fichier.
 *
 *  Créer une nouvelle file et charge le contenue du fichier
 *  'nom_fichier' dans la file. Si le fichier n'est pas valide, indique
 *  l'erreur dans 'file'->'erreur'.
 *
 *  \param nom_fichier : Le nom du fichier contenant la file.
 *
 *  \return La file
 */
file* charger_file(char *nom_fichier)
{
    return charger_liste_liee(nom_fichier);
}

/**
 *  \brief Effectue la désallocation d'une file.
 *
 *  \param file : La file à désalloué.
 */
void detruire_file(file* file)
{
    detruire_liste_liee(file);
}

/**
 *  \brief Sauvegarder la file dans un fichier.
 *
 *  Sauvegarde le contenue de la 'file' dans le fichier 'nom_fichier'.
 *  Si le fichier n'est pas valide, indique l'erreur dans 'file'->'erreur'.
 *
 *  \param file : La file à sauvegarder un élément.
 *  \param nom_fichier : Le nom du fichier à sauvegarder la file.
 *
 *  \note 'file' ne doit pas être NULL.
 */
void sauvegarder_file(file* file, char *nom_fichier)
{
    sauvegarder_liste_liee(file, nom_fichier);
}

/**
 *  \brief Renvoie la taille de la 'file'.
 *
 *  \return La taille de la 'file'.
 *
 *  \note 'file' ne doit pas être NULL.
 */
int taille_file(file* file)
{
    return taille_liste_liee(file);
}

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
void ajouter_file(file* file, int element)
{
    ajouter_liste_liee(file, element);
}

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
int element_file(file* file)
{
    int element = 0;
    if (taille_file(file) > 0) {
        int sommet_file = 0;
        element = element_liste_liee(file, sommet_file);
    } else {
        inscrire_erreur_file(file, "La file est vide.");
    }
    return element;
}

/**
 *  \brief Retire l'élément sur le dessus de la 'file'.
 *
 *  \param file : La file à retirer un élément.
 *
 *  \note 'file' ne doit pas être NULL.
 */
void retirer_file(file* file)
{
    if (taille_file(file) > 0) {
        int sommet_file = 0;
        retirer_liste_liee(file, sommet_file);
    } else {
        inscrire_erreur_file(file, "La file est vide.");
    }
}

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
void remplacer_file(file* file, int element)
{
    if (taille_file(file) > 0) {
        int sommet_file = 0;
        remplacer_liste_liee(file, sommet_file, element);
    } else {
        inscrire_erreur_file(file, "La file est vide.");
    }
}

/**
 *  \brief Indique si la 'file' contient une erreur.
 *
 *  \return Vrai si la 'file' contient une erreur, Faux sinon.
 *
 *  \note 'file' ne doit pas être NULL.
 */
bool a_erreur_file(file* file)
{
    return a_erreur_liste_liee(file);
}

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
char* erreur_file(file* file)
{
    return erreur_liste_liee(file);
}

/**
 *  \brief Inscrit l'erreur dans la 'file'.
 *
 *  \param erreur : Le texte de l'erreur.
 *
 *  \note 'file' ne doit pas être NULL.
 */
void inscrire_erreur_file(file* file, const char* erreur)
{
    inscrire_erreur_liste_liee(file, erreur);
}

/**
 *  \brief Retire tout erreur dans la 'file'.
 *
 *  \note 'file' ne doit pas être NULL.
 */
void retirer_erreur_file(file* file)
{
    retirer_erreur_liste_liee(file);
}

/* vi: set ts=4 sw=4 expandtab: */
/* Indent style: 1TBS */
