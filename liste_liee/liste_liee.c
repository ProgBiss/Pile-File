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
 *  \file liste_liee.c
 *
 *  Fichier d'implémentation contenant la structure de donnée 'liste_liee'.
 *  Une Liste Liée ("Linked List") est une liste implémenté à l'interne
 *  avec une suite de structures inter-reliées entre elles.
 *
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>


#include "liste_liee.h"


#define TAILLE_TAMPON_FICHIER 4096

/**
 * \brief Un noeud d'une liste_liee
 */
struct liste_liee_noeud {
    int valeur;
    struct liste_liee_noeud* prochain;
    struct liste_liee_noeud* precedent;
};

/**
 * \brief Une liste implémenté des tructures liées
 */
struct liste_liee_struct {
    int taille;
    struct liste_liee_noeud* premier;
    struct liste_liee_noeud* dernier;
    int position_courrante;
    struct liste_liee_noeud* noeud_courrant;
    bool a_erreur;
    char* erreur;
};


/**
 *  \brief Créer une nouvelle liste_liee.
 *
 *  \return La liste_liee
 */
liste_liee* creer_liste_liee(void)
{
    liste_liee* l_result;
    l_result = calloc(1, sizeof(liste_liee));
    if (l_result) {
        l_result->taille = 0;
        l_result->premier = NULL;
        l_result->dernier = NULL;
        l_result->position_courrante = 0;
        l_result->noeud_courrant = NULL;
        l_result->a_erreur = false;
        l_result->erreur = calloc(ERREUR_TAILLE, sizeof(char));
    }
    return l_result;
}

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
liste_liee* charger_liste_liee(char *a_nom_fichier)
{
    liste_liee* l_result;
    FILE *l_fichier;
    int l_count, i;
    int *l_tampon;
    l_result = creer_liste_liee();
    if (l_result) {
        l_fichier = fopen(a_nom_fichier, "rb");
        if (l_fichier) {
            l_tampon = calloc(sizeof(int), TAILLE_TAMPON_FICHIER);
            if (l_tampon) {
                l_count = 1;
                while(l_count > 0){
                    l_count = fread(l_tampon, sizeof(int),
                                            TAILLE_TAMPON_FICHIER, l_fichier);
                    if (l_count > 0) {
                        for (i = 0; i < l_count; i = i + 1) {
                            ajouter_liste_liee(l_result, l_tampon[i]);
                        }
                    }
                }
            } else {
                inscrire_erreur_liste_liee(l_result,
                                    "Mémoire insuffisante.");
            }
            fclose(l_fichier);
        } else {
            inscrire_erreur_liste_liee(l_result,
                                    "Ne peux ouvrir le fichier en lecture.");
        }
    }
    return l_result;
}
/**
 *  \brief Effectue la désallocation d'une liste_liee
 *
 *  \param liste La liste_liee à désalloué
 */
void detruire_liste_liee(liste_liee* a_liste)
{
    if (a_liste) {
        while (a_liste->taille > 0){
            retirer_liste_liee(a_liste, 0);
        }
        if (a_liste->erreur) {
            free(a_liste->erreur);
        }
        free(a_liste);
    }
}

/**
 *  \brief Repositionne la 'liste' à la position 'index'
 *
 *  \param liste La liste_liee à désalloué
 */
void positionner_liste_liee(liste_liee* a_liste, int a_index)
{
    int l_depuis_debut, l_depuis_fin, l_depuis_courrant;
    retirer_erreur_liste_liee(a_liste);
    if ((a_index >= 0) && (a_index < a_liste->taille)) {
        l_depuis_debut = a_index;
        l_depuis_fin = a_liste->taille - a_index - 1;
        l_depuis_courrant = a_liste->position_courrante - a_index;
        if ((l_depuis_debut < l_depuis_fin) &&
                        (l_depuis_debut < abs(l_depuis_courrant))) {
            a_liste->noeud_courrant = a_liste->premier;
            a_liste->position_courrante = 0;
        } else if ((l_depuis_fin < l_depuis_debut) &&
                        (l_depuis_fin < abs(l_depuis_courrant))) {
            a_liste->noeud_courrant = a_liste->dernier;
            a_liste->position_courrante = a_liste->taille - 1;
        }
        while (a_liste->position_courrante != a_index) {
            if (a_liste->position_courrante < a_index) {
                a_liste->noeud_courrant = a_liste->noeud_courrant->prochain;
                a_liste->position_courrante = a_liste->position_courrante + 1;
            } else {
                a_liste->noeud_courrant = a_liste->noeud_courrant->precedent;
                a_liste->position_courrante = a_liste->position_courrante - 1;
            }
        }
    } else {
        inscrire_erreur_liste_liee(a_liste, "Index invalide.");
    }
}

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
void ajouter_liste_liee(liste_liee* a_liste, int a_element)
{
    struct liste_liee_noeud* l_nouveau;
    retirer_erreur_liste_liee(a_liste);
    l_nouveau = calloc(1, sizeof(struct liste_liee_noeud));
    l_nouveau->valeur = a_element;
    if (a_liste->taille == 0){
        a_liste->noeud_courrant = l_nouveau;
        a_liste->premier = l_nouveau;
    } else {
        l_nouveau->precedent = a_liste->dernier;
        a_liste->dernier->prochain = l_nouveau;
    }
    a_liste->dernier = l_nouveau;
    a_liste->taille = a_liste->taille + 1;
}

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
int element_liste_liee(liste_liee* a_liste, int a_index)
{
    int l_result = 0;
    retirer_erreur_liste_liee(a_liste);
    if (a_liste->taille > 0) {
        positionner_liste_liee(a_liste, a_index);
        if(a_liste->position_courrante == a_index){
            l_result = a_liste->noeud_courrant->valeur;
        }
    } else {
        inscrire_erreur_liste_liee(a_liste, "La liste est vide.");
    }
    return l_result;
}
/**
 *  \brief Renvoie la taille de la 'liste'
 *
 *  \return La taille de la 'liste'
 *
 *  \note 'liste' ne doit pas être NULL
 */
int taille_liste_liee(liste_liee* a_liste)
{
    retirer_erreur_liste_liee(a_liste);
    return a_liste->taille;
}

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
void remplacer_liste_liee(liste_liee* a_liste, int a_index, int a_element)
{
    retirer_erreur_liste_liee(a_liste);
    if (a_liste->taille > 0) {
        positionner_liste_liee(a_liste, a_index);
        if(a_liste->position_courrante == a_index){
            a_liste->noeud_courrant->valeur = a_element;
        }
    } else {
        inscrire_erreur_liste_liee(a_liste, "La liste est vide.");
    }
}

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
void inserer_liste_liee(liste_liee* a_liste, int a_index, int a_element)
{
    struct liste_liee_noeud* l_nouveau;
    if (a_liste->taille > 0){
        positionner_liste_liee(a_liste, a_index);
        if (a_liste->position_courrante == a_index){
            l_nouveau = calloc(1, sizeof(struct liste_liee_noeud));
            l_nouveau->valeur = a_element;
            l_nouveau->prochain = a_liste->noeud_courrant;
            if (a_index > 0){
                l_nouveau->precedent = a_liste->noeud_courrant->precedent;
                l_nouveau->precedent->prochain = l_nouveau;
            } else {
                a_liste->premier = l_nouveau;
            }
            a_liste->noeud_courrant->precedent = l_nouveau;
            a_liste->noeud_courrant = l_nouveau;
            a_liste->taille = a_liste->taille + 1;
        }
    } else {
        if (a_index == 0) {
            ajouter_liste_liee(a_liste, a_element);
        } else {
            inscrire_erreur_liste_liee(a_liste, "Index non valide.");
        }
    }

}

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
void retirer_liste_liee(liste_liee* a_liste, int a_index)
{
    struct liste_liee_noeud* l_a_retirer;
    retirer_erreur_liste_liee(a_liste);
    if (a_liste->taille > 0) {
        positionner_liste_liee(a_liste, a_index);
        if (a_liste->position_courrante == a_index) {
            l_a_retirer = a_liste->noeud_courrant;
            if (l_a_retirer->precedent == NULL){
                a_liste->premier = l_a_retirer->prochain;
            } else {
                l_a_retirer->precedent->prochain = l_a_retirer->prochain;
            }
            if (l_a_retirer->prochain == NULL){
                a_liste->dernier = l_a_retirer->precedent;
                a_liste->noeud_courrant = l_a_retirer->precedent;
                a_liste->position_courrante = a_liste->position_courrante - 1;
            } else {
                l_a_retirer->prochain->precedent = l_a_retirer->precedent;
                a_liste->noeud_courrant = l_a_retirer->prochain;
            }
            free(l_a_retirer);
            a_liste->taille = a_liste->taille - 1;
        }
    } else {
        inscrire_erreur_liste_liee(a_liste, "La liste est vide.");
    }
}

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
void sauvegarder_liste_liee(liste_liee* a_liste, char * a_nom_fichier)
{
	FILE *l_fichier;
	int l_restant, l_compteur, l_taille_lecture, i;
	int *l_tampon;
	retirer_erreur_liste_liee(a_liste);
	l_fichier = fopen(a_nom_fichier, "wb");
	if (l_fichier) {
        l_tampon = calloc(sizeof(int), TAILLE_TAMPON_FICHIER);
        l_restant = taille_liste_liee(a_liste);
        l_compteur = 0;
        while (l_restant > 0) {
            if (l_restant > TAILLE_TAMPON_FICHIER) {
                l_taille_lecture = TAILLE_TAMPON_FICHIER;
            } else {
                l_taille_lecture = l_restant;
            }
            for (i = 0; i < l_taille_lecture; i = i + 1) {
                l_tampon[i] = element_liste_liee(a_liste, l_compteur);
                l_compteur = l_compteur + 1;
            }
            fwrite(l_tampon, sizeof(int), l_taille_lecture, l_fichier);
            l_restant = l_restant - l_taille_lecture;
        }
        fclose(l_fichier);
	} else {
        inscrire_erreur_liste_liee(a_liste,
                                "Ne peux pas ouvrir le fichier en écriture.");
	}
}

/**
 *  \brief Indique si la 'liste' contient une erreur
 *
 *  \return Vrai si la 'liste' contient une erreur, Faux sinon.
 *
 *  \note 'liste' ne doit pas être NULL
 */
bool a_erreur_liste_liee(liste_liee* a_liste)
{
    return a_liste->a_erreur;
}

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
char* erreur_liste_liee(liste_liee* a_liste)
{
    if (!a_liste->a_erreur)
    {
        strncpy(a_liste->erreur, "", ERREUR_TAILLE);
    }
    return a_liste->erreur;
}

/**
 *  \brief Inscrit l'erreur dans la 'liste'
 *
 *  \param erreur Le texte de l'erreur.
 *
 *  \note 'liste' ne doit pas être NULL
 */
void inscrire_erreur_liste_liee(liste_liee* a_liste, const char* a_erreur)
{
    a_liste->a_erreur = true;
    strncpy(a_liste->erreur, a_erreur, ERREUR_TAILLE);
}

/**
 *  \brief Retire tout erreur dans la 'liste'
 *
 *  \note 'liste' ne doit pas être NULL
 */
void retirer_erreur_liste_liee(liste_liee* a_liste)
{
    a_liste->a_erreur = false;
}

/* vi: set ts=4 sw=4 expandtab: */
/* Indent style: 1TBS */
