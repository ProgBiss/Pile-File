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
 *  \file liste_liee_module.c
 *
 *  Fichier d'implémentation du module Python permettant d'interfacer
 *  avec la librairie "liste_liee".
 *
 */


#include <Python.h>
#include "liste_liee.h"

/**
 * \brief "Wrapper" pour les erreurs du module
 */
static PyObject *liste_liee_erreur;

/**
 * \brief "Wrapper" pour la fonction 'creer_liste_liee'
 *
 * \param self L'objet python représentant le module
 * \param args Conteneur possédant les arguments envoyés à la fonction
 *
 * \return Objet Python contenant l'adresse de la liste créé
 */
static PyObject *liste_liee_creer(PyObject *a_self, PyObject *a_args)
{
	bool l_has_error = false;
	void* l_liste = NULL;
	PyObject * l_result;
	if (!PyArg_ParseTuple(a_args, "")){
		l_has_error = true;
	}
	if (l_has_error){
		l_result = NULL;
	} else {
		l_liste = creer_liste_liee();
		if (l_liste) {
			l_result = Py_BuildValue("i", l_liste);
		} else {
			PyErr_SetString(liste_liee_erreur, "Ne peut créer de liste liée.");
			l_result = NULL;
		}
	}
    return l_result;
}

/**
 * \brief "Wrapper" pour la fonction 'charger_liste_liee'
 *
 * \param self L'objet python représentant le module
 * \param args Conteneur possédant les arguments envoyés à la fonction
 *
 * \return Objet Python contenant l'adresse de la liste créé
 */
static PyObject *liste_liee_charger(PyObject *a_self, PyObject *a_args)
{
	bool l_has_error = false;
	void* l_liste = NULL;
	PyObject * l_result;
	char *l_nom_fichier;
	if (!PyArg_ParseTuple(a_args, "s", &l_nom_fichier)){
		l_has_error = true;
	}
	if (l_has_error){
		l_result = NULL;
	} else {
		l_liste = charger_liste_liee(l_nom_fichier);
		if (l_liste) {
			if (a_erreur_liste_liee(l_liste)){
				l_has_error = true;
				PyErr_SetString(liste_liee_erreur, erreur_liste_liee(l_liste));
				detruire_liste_liee(l_liste);
				l_result = NULL;
			} else {
				l_result = Py_BuildValue("i", l_liste);
			}
		} else {
			PyErr_SetString(liste_liee_erreur, "Ne peut créer de liste liée.");
			l_result = NULL;
		}
	}
    return l_result;
}


/**
 * \brief "Wrapper" pour la fonction 'detruire_liste_liee'
 *
 * \param self L'objet python représentant le module
 * \param args Conteneur possédant les arguments envoyés à la fonction
 *
 * \return Objet Python 'None' (type NULL de Python)
 */
static PyObject *liste_liee_detruire(PyObject *a_self, PyObject *a_args)
{
	bool l_has_error = false;
	void* l_liste = NULL;
	PyObject * l_result;
	if (PyArg_ParseTuple(a_args, "i", &l_liste)){
		if (l_liste) {
			detruire_liste_liee(l_liste);
		} else {
			l_has_error = true;
		}
	} else {
		l_has_error = true;
	}
	if (l_has_error){
		l_result = NULL;
	} else {
		Py_INCREF(Py_None);
		l_result = Py_None;
	}
    return l_result;
}

/**
 * \brief "Wrapper" pour la fonction 'ajouter_liste_liee'
 *
 * \param self L'objet python représentant le module
 * \param args Conteneur possédant les arguments envoyés à la fonction
 *
 * \return Objet Python 'None' (type NULL de Python)
 */
static PyObject *liste_liee_ajouter(PyObject *a_self, PyObject *a_args)
{
	bool l_has_error = false;
	void* l_liste = NULL;
	PyObject * l_result;
	int l_element;
	if (PyArg_ParseTuple(a_args, "ii", &l_liste, &l_element)){
		if (l_liste) {
			ajouter_liste_liee(l_liste, l_element);
			if (a_erreur_liste_liee(l_liste)){
				l_has_error = true;
				PyErr_SetString(liste_liee_erreur, erreur_liste_liee(l_liste));
			}
		} else {
			l_has_error = true;
		}
	} else {
		l_has_error = true;
	}
	if (l_has_error){
		l_result = NULL;
	} else {
		Py_INCREF(Py_None);
		l_result = Py_None;
	}
    return l_result;
}

/**
 * \brief "Wrapper" pour la fonction 'element_liste_liee'
 *
 * \param self L'objet python représentant le module
 * \param args Conteneur possédant les arguments envoyés à la fonction
 *
 * \return Objet Python contenant l'élément reçu
 */
static PyObject *liste_liee_element(PyObject *a_self, PyObject *a_args)
{
	bool l_has_error = false;
	void* l_liste = NULL;
	PyObject * l_result;
	int l_element = 0;
	int l_index;
	if (PyArg_ParseTuple(a_args, "ii", &l_liste, &l_index)){
		if (l_liste) {
			l_element = element_liste_liee(l_liste, l_index);
			if (a_erreur_liste_liee(l_liste)){
				l_has_error = true;
				PyErr_SetString(liste_liee_erreur, erreur_liste_liee(l_liste));
			}
		} else {
			l_has_error = true;
		}
	} else {
		l_has_error = true;
	}
	if (l_has_error){
		l_result = NULL;
	} else {
		l_result = Py_BuildValue("i", l_element);
	}
    return l_result;
}

/**
 * \brief "Wrapper" pour la fonction 'taille_liste_liee'
 *
 * \param self L'objet python représentant le module
 * \param args Conteneur possédant les arguments envoyés à la fonction
 *
 * \return Objet Python contenant la taille de la liste
 */
static PyObject *liste_liee_taille(PyObject *a_self, PyObject *a_args)
{
	bool l_has_error = false;
	void* l_liste = NULL;
	PyObject * l_result;
	int l_taille = 0;
	if (PyArg_ParseTuple(a_args, "i", &l_liste)){
		if (l_liste) {
			l_taille = taille_liste_liee(l_liste);
			if (a_erreur_liste_liee(l_liste)){
				l_has_error = true;
				PyErr_SetString(liste_liee_erreur, erreur_liste_liee(l_liste));
			}
		} else {
			l_has_error = true;
		}
	} else {
		l_has_error = true;
	}
	if (l_has_error){
		l_result = NULL;
	} else {
		l_result = Py_BuildValue("i", l_taille);
	}
    return l_result;
}

/**
 * \brief "Wrapper" pour la fonction 'remplacer_liste_liee'
 *
 * \param self L'objet python représentant le module
 * \param args Conteneur possédant les arguments envoyés à la fonction
 *
 * \return Objet Python 'None' (type NULL de Python)
 */
static PyObject *liste_liee_remplacer(PyObject *a_self, PyObject *a_args)
{
	bool l_has_error = false;
	void* l_liste = NULL;
	PyObject * l_result;
	int l_element, l_index;
	if (PyArg_ParseTuple(a_args, "iii", &l_liste, &l_index, &l_element)){
		if (l_liste) {
			remplacer_liste_liee(l_liste, l_index, l_element);
			if (a_erreur_liste_liee(l_liste)){
				l_has_error = true;
				PyErr_SetString(liste_liee_erreur, erreur_liste_liee(l_liste));
			}
		} else {
			l_has_error = true;
		}
	} else {
		l_has_error = true;
	}
	if (l_has_error){
		l_result = NULL;
	} else {
		Py_INCREF(Py_None);
		l_result = Py_None;
	}
    return l_result;
}

/**
 * \brief "Wrapper" pour la fonction 'inserer_liste_liee'
 *
 * \param self L'objet python représentant le module
 * \param args Conteneur possédant les arguments envoyés à la fonction
 *
 * \return Objet Python 'None' (type NULL de Python)
 */
static PyObject *liste_liee_inserer(PyObject *a_self, PyObject *a_args)
{
	bool l_has_error = false;
	void* l_liste = NULL;
	PyObject * l_result;
	int l_element, l_index;
	if (PyArg_ParseTuple(a_args, "iii", &l_liste, &l_index, &l_element)){
		if (l_liste) {
			inserer_liste_liee(l_liste, l_index, l_element);
			if (a_erreur_liste_liee(l_liste)){
				l_has_error = true;
				PyErr_SetString(liste_liee_erreur, erreur_liste_liee(l_liste));
			}
		} else {
			l_has_error = true;
		}
	} else {
		l_has_error = true;
	}
	if (l_has_error){
		l_result = NULL;
	} else {
		Py_INCREF(Py_None);
		l_result = Py_None;
	}
    return l_result;
}

/**
 * \brief "Wrapper" pour la fonction 'retirer_liste_liee'
 *
 * \param self L'objet python représentant le module
 * \param args Conteneur possédant les arguments envoyés à la fonction
 *
 * \return Objet Python 'None' (type NULL de Python)
 */
static PyObject *liste_liee_retirer(PyObject *a_self, PyObject *a_args)
{
	bool l_has_error = false;
	void* l_liste = NULL;
	PyObject * l_result;
	int l_index;
	if (PyArg_ParseTuple(a_args, "ii", &l_liste, &l_index)){
		if (l_liste) {
			retirer_liste_liee(l_liste, l_index);
			if (a_erreur_liste_liee(l_liste)){
				l_has_error = true;
				PyErr_SetString(liste_liee_erreur, erreur_liste_liee(l_liste));
			}
		} else {
			l_has_error = true;
		}
	} else {
		l_has_error = true;
	}
	if (l_has_error){
		l_result = NULL;
	} else {
		Py_INCREF(Py_None);
		l_result = Py_None;
	}
    return l_result;
}

/**
 * \brief "Wrapper" pour la fonction 'sauvegarder_liste_liee'
 *
 * \param self L'objet python représentant le module
 * \param args Conteneur possédant les arguments envoyés à la fonction
 *
 * \return Objet Python 'None' (type NULL de Python)
 */
static PyObject *liste_liee_sauvegarder(PyObject *a_self, PyObject *a_args)
{
	bool l_has_error = false;
	void* l_liste = NULL;
	PyObject * l_result;
	char *l_nom_fichier;
	if (PyArg_ParseTuple(a_args, "is", &l_liste, &l_nom_fichier)){
		if (l_liste) {
			sauvegarder_liste_liee(l_liste, l_nom_fichier);
			if (a_erreur_liste_liee(l_liste)){
				l_has_error = true;
				PyErr_SetString(liste_liee_erreur, erreur_liste_liee(l_liste));
			}
		} else {
			l_has_error = true;
		}
	} else {
		l_has_error = true;
	}
	if (l_has_error){
		l_result = NULL;
	} else {
		Py_INCREF(Py_None);
		l_result = Py_None;
	}
    return l_result;
}


/**
 * \brief Liste toutes les fonctions du module
 */
static PyMethodDef liste_liee_methods[] = {
    {"creer",  liste_liee_creer, METH_VARARGS,
     "Créer une liste implémenté avec des structures liées"},
    {"charger",  liste_liee_charger, METH_VARARGS,
     "Charger une liste liée à partir du contenue d'un fichier"},
    {"detruire",  liste_liee_detruire, METH_VARARGS,
     "Désalloue la liste liée"},
    {"ajouter",  liste_liee_ajouter, METH_VARARGS,
     "Ajouter une valeur à la fin de la liste"},
    {"element",  liste_liee_element, METH_VARARGS,
     "L'élément à l'index `a_index' dans la `a_liste'"},
    {"taille",  liste_liee_taille, METH_VARARGS,
     "Le nombre d'élément dans la `a_liste'"},
    {"remplacer",  liste_liee_remplacer, METH_VARARGS,
     "Remplace l'élément à la position `a_index' de la `a_liste'"},
    {"inserer",  liste_liee_inserer, METH_VARARGS,
     "Insère `a_element' dans la `a_liste' à la position `a_index'"},
    {"retirer",  liste_liee_retirer, METH_VARARGS,
     "Retire l'élément à la position `a_index' dans la `a_liste'"},
    {"sauvegarder",  liste_liee_sauvegarder, METH_VARARGS,
     "Sauvegarder le contenue de la liste dans un fichier"},
    {NULL, NULL, 0, NULL}        /* Sentinel */
};

/**
 * \brief Information sur le module
 */
static struct PyModuleDef liste_liee_module = {
   PyModuleDef_HEAD_INIT,
   "liste_liee_externe",   /* nom du module */
		/* documentation du module, NULL si aucun */
   "Liste implémenté grâce à plusieurs structures liée entre elles.",
   -1,       /*  Taille de l'état "per-interpreter" du module,
                ou -1 si le module ce situe en variable globale. */
   liste_liee_methods /* La liste des fonctions du module */
};

/**
 * \brief Initialization du module
 */
PyMODINIT_FUNC PyInit_liste_liee_externe(void)
{
	PyObject *l_module;
	l_module = PyModule_Create(&liste_liee_module); /* Créer le module */
	if (l_module) {
		/* Ajouter un gestionnaire d'exception dans le module */
		liste_liee_erreur = PyErr_NewException("liste_liee_externe.erreur", NULL, NULL);
		Py_INCREF(liste_liee_erreur);
		PyModule_AddObject(l_module, "erreur", liste_liee_erreur);
	}
    return l_module;
}
