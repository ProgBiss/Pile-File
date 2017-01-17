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
 *  \file liste_liee.h
 *
 *  Fichier d'entête contenant la structure de donnée 'liste_liee'.
 *  Une Liste Liée ("Linked List") est une liste implémenté à l'interne
 *  avec une suite de structures inter-reliées entre elles.
 *
 */

#ifndef _liste_liee_h
#define _liste_liee_h

#include <stdbool.h>


#define ERREUR_TAILLE 255

/**
 * \brief Une liste implémenté de structures liées
 */
typedef struct liste_liee_struct liste_liee;

/**
 *  \brief Créer une nouvelle liste_liee.
 *
 *  \return La liste_liee
 */
liste_liee* creer_liste_liee(void);

/**
 *  \brief Créer une nouvelle liste_liee depuis un fichier.
 *
 *  Créer une nouvelle liste_liee et charge le contenue du fichier
 *  'nom_fichier' dans la liste. Si le fichier n'est pas valide, indique
 *  l'erreur dans 'liste'->'erreur'.
 *
 *  \param nom_fichier Le nom du fichier contenant la liste
 *
 *  \return La liste_liee
 */
liste_liee* charger_liste_liee(char *nom_fichier);

/**
 *  \brief Effectue la désallocation d'une liste_liee
 *
 *  \param liste La liste_liee à désalloué
 */
void detruire_liste_liee(liste_liee* liste);

/**
 *  \brief Ajouter un nouvel élément à une liste_liee.
 *
 *  Ajoute à la 'liste' l''element' reçu en argument.
 *  La taille de la 'liste' est augmenté de 1.
 *
 *  \param liste La liste_liee à ajouter l'élément
 *  \param element L'élément à ajouter à la 'liste'
 *
 *  \note 'liste' ne doit pas être NULL
 */
void ajouter_liste_liee(liste_liee* liste, int element);

/**
 *  \brief Renvoie l'élément à la position 'index' dans la 'liste'
 *
 *  Si l''index' est valide, retourne l'élément stocké
 *  dans la 'liste' à cet 'index'. Sinon, indique
 *  l'erreur dans 'liste'->'erreur'. Dans ce dernier cas
 *  la valeur 0 est retourné.
 *
 *  \param liste La liste_liee contenant l'élément
 *  \param index La position de l'élément dans la 'liste'
 *
 *  \return L'élément à la position 'index' dans la 'liste'
 *
 *  \note 'liste' ne doit pas être NULL
 */
int element_liste_liee(liste_liee* liste, int index);

/**
 *  \brief Renvoie la taille de la 'liste'
 *
 *  \return La taille de la 'liste'
 *
 *  \note 'liste' ne doit pas être NULL
 */
int taille_liste_liee(liste_liee* liste);

/**
 *  \brief Remplacer un élément dans la 'liste' par 'element'
 *
 *  Remplace l'élément contenue dans la 'liste' à la position 'index'
 *  par un nouveau 'element'. Si la position 'index' n'est pas valide,
 *  indique l'erreur dans 'liste'->'erreur'.
 *
 *  \param liste La liste_liee à remplacer un 'element'
 *  \param index La position dans la 'liste' à remplacer un 'element'
 *  \param element L'élément à placer dans la 'liste'
 *
 *  \note 'liste' ne doit pas être NULL
 */
void remplacer_liste_liee(liste_liee* liste, int index, int element);

/**
 *  \brief Insert un 'element' à la position 'index' dans la 'liste'
 *
 *  Si la position 'index' n'est pas valide, indique l'erreur dans
 *  'liste'->'erreur'.
 *
 *  \param liste La liste_liee à insérer un 'element'
 *  \param index La position dans la 'liste' à insérer un 'element'
 *  \param element L'élément à insérer dans la 'liste'
 *
 *  \note 'liste' ne doit pas être NULL
 */
void inserer_liste_liee(liste_liee* liste, int index, int element);

/**
 *  \brief Retire l'élément à la position 'index' de la 'liste'
 *
 *  Si la position 'index' n'est pas valide, indique l'erreur dans
 *  'liste'->'erreur'.
 *
 *  \param liste La liste_liee à retirer un élément
 *  \param index La position dans la 'liste' à retirer un élément
 *
 *  \note 'liste' ne doit pas être NULL
 */
void retirer_liste_liee(liste_liee* liste, int index);

/**
 *  \brief Sauvegarder la liste_liee dans un fichier
 *
 *  Sauvegarde le contenue de la 'liste' dans le fichier 'nom_fichier'.
 *  Si le fichier n'est pas valide, indique l'erreur dans 'liste'->'erreur'.
 *
 *  \param liste La liste_liee à retirer un élément
 *  \param nom_fichier Le nom du fichier à sauvegarder la liste
 *
 *  \note 'liste' ne doit pas être NULL
 */
void sauvegarder_liste_liee(liste_liee* liste, char * nom_fichier);

/**
 *  \brief Indique si la 'liste' contient une erreur
 *
 *  \return Vrai si la 'liste' contient une erreur, Faux sinon.
 *
 *  \note 'liste' ne doit pas être NULL
 */
bool a_erreur_liste_liee(liste_liee* liste);

/**
 *  \brief Indique le texte de l'erreur contenue dans 'liste'
 *
 *  Si 'a_erreur_liste_liee' indique que la 'liste' contient une erreur,
 *  retourne l'erreur qu'elle contient. Si 'a_erreur_liste_liee' est Faux,
 *  Retourne une chaine vide.
 *
 *  \return Le texte de l'erreur.
 *
 *  \note 'liste' ne doit pas être NULL
 */
char* erreur_liste_liee(liste_liee* liste);

/**
 *  \brief Inscrit l'erreur dans la 'liste'
 *
 *  \param erreur Le texte de l'erreur.
 *
 *  \note 'liste' ne doit pas être NULL
 */
void inscrire_erreur_liste_liee(liste_liee* liste, const char* erreur);

/**
 *  \brief Retire tout erreur dans la 'liste'
 *
 *  \note 'liste' ne doit pas être NULL
 */
void retirer_erreur_liste_liee(liste_liee* liste);

#endif /* _liste_liee_h */

/* vi: set ts=4 sw=4 expandtab: */
