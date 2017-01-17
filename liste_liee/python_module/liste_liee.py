# coding=UTF-8

# =============================================================================
# titre           :liste_liee.py
# description     :Classe Liste_liee.
# author          :Louis Marchand
# date            :20150730
# version         :1.0
# usage           :from liste_liee import Liste_liee
# notes           :
# license         :MIT
# python_version  :3.4.0
# =============================================================================

import liste_liee_externe

class Liste_liee(object):

    def __init__(self, a_nom_fichier = None):
        if isinstance(a_nom_fichier, str):
            self.__internal_pointer = liste_liee_externe.charger(a_nom_fichier)
        else:
            self.__internal_pointer = liste_liee_externe.creer()

    def ajouter(self, a_element):
        liste_liee_externe.ajouter(self.__internal_pointer, a_element)

    def element(self, a_index):
        return liste_liee_externe.element(self.__internal_pointer, a_index)

    def taille(self):
        return liste_liee_externe.taille(self.__internal_pointer)

    def remplacer(self, a_index, a_element):
        liste_liee_externe.remplacer(self.__internal_pointer, 
                a_index, a_element)

    def inserer(self, a_index, a_element):
        liste_liee_externe.inserer(self.__internal_pointer, 
                a_index, a_element)

    def retirer(self, a_index):
        liste_liee_externe.retirer(self.__internal_pointer, a_index)

    def sauvegarder(self, a_nom_fichier):
        liste_liee_externe.sauvegarder(self.__internal_pointer, a_nom_fichier)

    def __del__(self):
        liste_liee_externe.detruire(self.__internal_pointer)

